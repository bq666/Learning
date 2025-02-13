// $Id: vsl.C,v 1.14 1999/08/19 11:29:03 andreas Exp $ 
// Read and evaluate VSL library

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

char vsl_rcsid[] = 
    "$Id: vsl.C,v 1.14 1999/08/19 11:29:03 andreas Exp $";

#include "assert.h"
#include <iostream.h>
#include "strclass.h"
#include <stdlib.h>
#include <sys/types.h>
#include <time.h>

#include <X11/Intrinsic.h>      // X Toolkit
#include <X11/Xlib.h>           // X Library
#include <X11/Xaw/Viewport.h>   // Viewport Widget
#include <X11/StringDefs.h>     // String Definitions
#include <X11/Xaw/Cardinals.h>  // Definition ZERO
#include "DocSpace.h"           // DocSpace Widget

#include "bool.h"
#include "VSLLib.h"
#include "VSLDef.h"
#include "VSEFlags.h"

#include "Box.h"
#include "StringBox.h"
#include "ListBox.h"

#ifndef EXIT_SUCCESS
#define EXIT_SUCCESS 0
#endif

#ifndef EXIT_FAILURE
#define EXIT_FAILURE 1
#endif



// Graphics functions
void Flush(Widget w)
{
    Display *display = XtDisplay(w);
    
    XFlush(display);
}

// Standard resources
String fallback_resources[] = 
    { "*Viewport.width:    400", "*Viewport.height: 400", NULL };

// These should be part of ExposeCB...
static Box *thebox = 0;

// clock() function
#if !HAVE_CLOCK_DECL
extern "C" clock_t clock();
#endif

#ifndef CLOCKS_PER_SEC
#define CLOCKS_PER_SEC 1000000
#endif

// Redraw
void redraw(Widget w, BoxRegion r, BoxRegion exposed)
{
    if (VSEFlags::verbose)
    {
	cout << "Redraw: " << exposed;
	cout.flush();
    }

    clock_t starttime = clock();
    thebox->draw(w, r, exposed);
    clock_t endtime = clock();

    if (VSEFlags::show_eval_time)
	cout << " (" << (endtime - starttime) * 1000 / CLOCKS_PER_SEC
	     << " ms)\n";

    Flush(w);
}

// Expose Callback
void ExposeCB(Widget w, XtPointer, XtPointer call_data)
{
    // Set size
    Arg arglist[10];
    int a = 0;
    XtSetArg(arglist[a], XtNwidth,  thebox->size(X)); a++;
    XtSetArg(arglist[a], XtNheight, thebox->size(Y)); a++;
    XtSetValues(w, arglist, a);

    // Get region
    XExposeEvent* event = (XExposeEvent *)call_data;
    BoxPoint expose_origin = BoxPoint(event->x, event->y);
    BoxSize  expose_space  = BoxSize(event->width, event->height);
    BoxRegion exposed(expose_origin, expose_space);

    redraw(w, BoxRegion(BoxPoint(0,0), thebox->size()), exposed);
}

// When selecting: redraw all (for statistics)
void SelectCB(Widget w, XtPointer, XtPointer)
{
    XClearArea(XtDisplay(w), XtWindow(w), 0, 0, 0, 0, false);

    redraw(w, 
	BoxRegion(BoxPoint(0,0), thebox->size()), 
	BoxRegion(BoxPoint(0,0), BoxSize(1000000, 1000000)));
}


XtAppContext app_con;

// Callback when done
void QuitCB(Widget, XtPointer, XtPointer)
{
    if (VSEFlags::verbose)
    {
	cout << "Quit!\n";
	cout.flush();
    }
    XtDestroyApplicationContext(app_con);

    // Clear box
    if (thebox) 
	thebox->unlink();

    // Check if we really deleted everything
    if (UniqueId::inUse() > 0)
	cerr << "Warning: " << UniqueId::inUse() << " IDs still in use\n";

    exit(EXIT_SUCCESS);
}

// Create argument list
ListBox *vsl_args(int argc, char *argv[])
{
    ListBox *args = new ListBox;
    for (int i = 0; i < argc; i++)
    {
	Box *a = new StringBox(argv[i]);
	*args += a;
	a->unlink();
    }

    return args;
}

// Main VSL program
int main(int argc, char *argv[])
{
    // Set flags
    VSEFlags::parse(argc, argv, "vsllib");

    // Init toolkit
    Widget toplevel = XtAppInitialize(&app_con, "Vsl", NULL, ZERO, 
				      &argc, argv, fallback_resources, 
				      NULL, ZERO);

    // Create Viewport
    Arg arglist[10];        // Arguments
    int a = 0;              // Argument counter
    XtSetArg(arglist[a], XtNallowHoriz, true); a++;
    XtSetArg(arglist[a], XtNallowVert,  true); a++;
    Widget viewport = XtCreateManagedWidget("viewport", viewportWidgetClass, 
					    toplevel, arglist, a);

    // Create DocSpace
    a = 0;
    Widget docSpace = XtCreateManagedWidget("docSpace", docSpaceWidgetClass, 
					    viewport, arglist, a);
    XtAddCallback(docSpace, XtNcallback, SelectCB, 0);
    XtAddCallback(docSpace, XtNexposeCallback, ExposeCB, 0);
    XtAddCallback(docSpace, XtNquitCallback, QuitCB, 0);

    // Set font table
    StringBox::fontTable = new FontTable(XtDisplay(toplevel));

    // Fetch name
    string library_file = VSEFlags::library_file;
    if (argc > 1)
    {
	library_file = argv[1];
	if (library_file[0] == '-')
	{
	    cout << argv[0] << ": usage: " << argv[0] << " [options] "
		<< "vsllib\n\n" << VSEFlags::explain();

	    exit(EXIT_FAILURE);
	}
    }
	
    // Create pic in THEBOX
    {
	// Read library
	long starttime = clock();
	VSLLib lib(library_file, VSEFlags::optimize_mode());
	long endtime = clock();

	if (VSEFlags::show_optimizing_time)
	    cout << "\nRead & optimizing time: " 
		<< (endtime - starttime) / 1000 << " ms\n";

	if (VSEFlags::assert_library_ok)
	    assert(lib.OK());

	if (VSEFlags::dump_library)
	    cout << lib;

	if (VSEFlags::dump_tree)
	    lib.dumpTree(cout);

	if (VSEFlags::suppress_eval)
	    return EXIT_SUCCESS;

	// Fetch last function def (typically "main")
	VSLDef* def = lib.lastdef();

	if (def == 0)
	{
	    cerr << argv[0] << ": cannot find last definition (sorry)\n";
	    return EXIT_FAILURE;
	}

	// Eval function
	ListBox *arg = vsl_args(argc, argv);

	starttime = clock();
	for (int loop = 1; loop < VSEFlags::loops; loop++)
	{
	    Box *result = (Box *)def->eval(arg);
	    lib.output(result);
	    result->unlink();
	}
	Box *result = (Box *)def->eval(arg);
	lib.output(result);
	endtime = clock();
	arg->unlink();

	// Show eval time
	if (VSEFlags::show_eval_time)
	    cout << "\nEvaluation time: " 
		<< (endtime - starttime) / 1000 << " ms\n";

	if (result && VSEFlags::dump_picture)
	    cout << "#!" << argv[0] << "\n#include <std.vsl>\n\nmain() -> "
		<< *result << ";\n";

	thebox = result;

	// Stack and library are destroyed upon leaving this block
    }

    if (thebox && !thebox->size().isValid())
    {
	cerr << argv[0] << ": result has no size (maybe list?)\n";
	thebox->unlink();
	thebox = 0;
    }

    if (thebox == 0)
    {
	cerr << argv[0] << ": evaluation failed (sorry)\n";
	return EXIT_FAILURE;
    }

    // Realize Widget
    XtRealizeWidget(toplevel);

    // Process events
    XtAppMainLoop(app_con);

    // Never reached...
    return EXIT_SUCCESS;
}
