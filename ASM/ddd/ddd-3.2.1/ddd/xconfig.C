// $Id: xconfig.C,v 1.25 1999/08/19 11:29:04 andreas Exp $ -*- C++ -*-
// Setup X defaults and determine common problem causes.

// Copyright (C) 1995 Technische Universitaet Braunschweig, Germany.
// Written by Andreas Zeller <zeller@gnu.org>.
// 
// This file is part of DDD.
// 
// DDD is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public
// License as published by the Free Software Foundation; either
// version 2 of the License, or (at your option) any later version.
// 
// DDD is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
// See the GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public
// License along with DDD -- see the file COPYING.
// If not, write to the Free Software Foundation, Inc.,
// 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
// 
// DDD is the data display debugger.
// For details, see the DDD World-Wide-Web page, 
// `http://www.gnu.org/software/ddd/',
// or send a mail to the DDD developers <ddd@gnu.org>.

char xconfig_rcsid[] = 
    "$Id: xconfig.C,v 1.25 1999/08/19 11:29:04 andreas Exp $";

#ifdef __GNUG__
#pragma implementation
#endif

#include "xconfig.h"
#include "strclass.h"
#include "bool.h"
#include "cook.h"
#include "filetype.h"
#include "shell.h"

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include <limits.h>
#ifndef PATH_MAX
#define PATH_MAX 4096
#endif

#include <Xm/VirtKeys.h>
#include <Xm/SelectioB.h>

#if !HAVE_POPEN_DECL
extern "C" FILE *popen(const char *command, const char *mode);
#endif
#if !HAVE_PCLOSE_DECL
extern "C" int pclose(FILE *stream);
#endif


//-----------------------------------------------------------------------------
// Determine X project root
//-----------------------------------------------------------------------------

static bool is_file(const string& file)
{
    FILE *fp = fopen(file, "r");
    if (fp == 0)
	return false;

    fclose(fp);
    return true;
}

// Fetch the X library directory, using xmkmf(1)
static String xlibdir(Display *display, bool verbose = false)
{
    static bool tried = false;
    static String dir = 0;

    if (tried)
	return dir;
    tried = true;

    if (!is_cmd_file(cmd_file("xmkmf")))
	return dir;		// No `xmkmf' in PATH
    if (!is_cmd_file(cmd_file("make")))
	return dir;		// No `make' in PATH

    static const char shell_command[] =
	""
#include "xlibdir.C"
	"";

    String me, my_class;
    XtGetApplicationNameAndClass(display, &me, &my_class);

    if (verbose)
    {
	cout << "Checking for X11 library directory... ";
	cout.flush();
    }

    FILE *fp = popen("/bin/sh -c " + sh_quote(shell_command), "r");
    if (fp == 0)
    {
	if (verbose)
	{
	    cout << strerror(errno) << "\n";
	    cout.flush();
	}
	return dir;
    }

    char buffer[PATH_MAX];
    buffer[0] = '\0';
    fgets(buffer, sizeof(buffer), fp);
    pclose(fp);

    int len = strlen(buffer);
    if (len > 0 && buffer[len - 1] == '\n')
	buffer[len - 1] = '\0';

    if (buffer[0] == '/')	// Sanity check
	dir = (String)XtNewString(buffer);

    if (verbose)
    {
	if (dir)
	    cout << dir << "\n";
	else
	    cout << "(not found)\n";
	cout.flush();
    }

    return dir;
}

static int check_xkeysymdb(Display *display, bool verbose)
{
    if (verbose)
    {
	(void) xlibdir(display, verbose);
    }

    if (verbose)
    {
	cout << "Checking for XKeysymDB... ";
	cout.flush();
    }

    String me, my_class;
    XtGetApplicationNameAndClass(display, &me, &my_class);

    String xkeysymdb = 0;

    if (xkeysymdb == 0)
	xkeysymdb = getenv("XKEYSYMDB");
    if (xkeysymdb == 0)
	xkeysymdb = XtResolvePathname(display, "", "XKeysymDB", "",
				      NULL, NULL, 0, NULL);

    if (xkeysymdb)
    {
	if (verbose)
	{
	    cout << xkeysymdb << "\n";
	    cout.flush();
	}

	// Fix it now
	static string env;
	env = "XKEYSYMDB=" + string(xkeysymdb);
	putenv(env);
	return 0;			// Okay
    }
    

    if (xlibdir(display) != 0)
    {
	string path = string(xlibdir(display)) + "/XKeysymDB";
	if (is_file(path))
	{
	    if (verbose)
	    {
		cout << path << "\n"
		     << "Note: this is not the default path compiled into " 
		     << me << ".\n"
		     << "    To avoid having " << me 
		     << " determine this setting each time it is started,\n"
		     << "    please set the XKEYSYMDB "
		     << "environment variable to\n"
		     << "    " << quote(path) << ".\n";
		cout.flush();
	    }

	    // Fix it
	    static string env;
	    env = "XKEYSYMDB=" + path;
	    putenv(env);
	    return 0;
	}
    }

    cout << "(none)\n";
    cout.flush();

    if (verbose)
    {
	cout << "Warning: The `XKeysymDB' file is not in the "
	     << "default X file search path.\n"
	     << "    If " << me << " was not compiled on this machine, " 
	     << me << "\n" 
	     << "    may not run properly "
	     << "(lots of warnings for unknown keysym names).\n"
	     << "    Please get the `XKeysymDB' file from\n"
	     << "    `ftp://ftp.ips.cs.tu-bs.de/pub/local/softech/ddd/bin/'\n";

	if (xlibdir(display) != 0)
	    cout << "    and install it into `" << xlibdir(display, verbose) 
	     << "'\n";
	else
	    cout << "    and install it into your X project root "
		 << "(typically `/usr/lib/X11')\n";

	cout << "    or have the XKEYSYMDB environment variable "
	     << "point at it.\n";

	cout.flush();
    }

    return 1;
}

#if XlibSpecificationRelease == 5 && !__hpux__
static string dirname(const string& file)
{
    if (file.contains('/'))
	return file.before('/', -1);
    else
	return ".";
}

static String resolve_dirname(Display *display, String type, String name)
{
    String ret = XtResolvePathname(display, type, name, "", 
				   NULL, NULL, 0, NULL);

    if (ret != 0)
    {
	static string dir;
	dir = dirname(ret);
	ret = (char *)dir.chars();
    }

    return ret;
}
#endif

static int check_xnlspath(Display *display, bool verbose)
{
#if XlibSpecificationRelease == 5
    if (verbose)
    {
	(void) xlibdir(display, verbose);
    }

    if (verbose)
    {
	cout << "Checking for nls directory... ";
	cout.flush();
    }

    String me, my_class;
    XtGetApplicationNameAndClass(display, &me, &my_class);

    String xnlspath = 0;

    if (xnlspath == 0)
	xnlspath = getenv("XNLSPATH");

#if __hpux__
    // On HP-UX, checking for nonexistent files (notably,
    // `nls/nls.dir') causes `illegal instruction' crashes.  The
    // following call, however, works on HP-UX.  Reported by
    // Tobias Mangold <mangold@hft.e-technik.tu-muenchen.de>.
    if (xnlspath == 0)
	xnlspath = XtResolvePathname(display, "nls", "", "", 
				     NULL, NULL, 0, NULL);
#else
    // Check for `nls/C' or `nls/nls.dir'
    if (xnlspath == 0)
	xnlspath = resolve_dirname(display, "nls", "C");
    if (xnlspath == 0)
	xnlspath = resolve_dirname(display, "nls", "nls.dir");
#endif

    if (xnlspath)
    {
	if (verbose)
	{
	    cout << xnlspath << "\n";
	    cout.flush();
	}

	// Fix it now
	static string env;
	env = string("XNLSPATH=") + xnlspath;
	putenv(env);
	return 0;		// Okay
    }

    if (xlibdir(display, verbose) != 0)
    {
	string path = string(xlibdir(display, verbose)) + "/nls";
	if (!is_directory(path))
	{
	    if (verbose)
	    {
		cout << path << "\n"
		     << "Note: this is not the default path compiled into " 
		     << me << ".\n"
		     << "    To avoid having " << me 
		     << " determine this setting each time it is started,\n"
		     << "    please set the XNLSPATH "
		     << "environment variable to\n"
		     << "    " << quote(path) << ".\n\n";
		cout.flush();
	    }

	    // Fix it now
	    static string env;
	    env = "XNLSPATH=" + path;
	    putenv(env);
	    return 0;
	}
    }

    if (verbose)
    {
	cout << "Warning: cannot locate the X11 `nls' directory!\n"
	     << "    If " << me << " was not compiled on this machine, " 
	     << me << "\n" 
	     << "    may not run properly (`cut and paste' fails).\n"
	     << "    Please get the `nls' directory from\n"
	     << "    `ftp://ftp.ips.cs.tu-bs.de/pub/local/softech/ddd/bin/'\n";

	if (xlibdir(display) != 0)
	    cout << "    and install it into `" << xlibdir(display) << "'\n";
	else
	    cout << "    and install it into your X project root "
		 << "(typically `/usr/lib/X11')\n";
	cout << "    or have the XNLSPATH environment variable "
	     << "point at it.\n\n";
	cout.flush();
    }

    return 1;
#else // XlibSpecificationRelease != 5

    (void) display;		// Use it
    (void) verbose;

    // In X11R4, there was no nls directory; X11R6 has a `locale' dir instead.
    return 0;

#endif // XlibSpecificationRelease != 5
}


// Set up the X11 library directory
int check_x_configuration(Widget toplevel, bool verbose)
{
    Display *display = XtDisplay(toplevel);

    int ret = 0;

    // This is required for all Motif programs.
    ret = check_xkeysymdb(display, verbose) || ret;

    // This is required for executables linked against X11R5 or later.
    ret = check_xnlspath(display, verbose) || ret;

    if (verbose)
    {
	if (ret == 0)
	{
	    cout << "No configuration problems found.\n";
	    cout.flush();
	}
    }

    return ret;
}
