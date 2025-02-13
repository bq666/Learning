// $Id: ScrolledGE.C,v 1.19 1999/08/19 11:27:50 andreas Exp $  -*- C++ -*-
// Scrolled Graph Editor

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

char ScrolledGraphEdit_rcsid[] = 
    "$Id: ScrolledGE.C,v 1.19 1999/08/19 11:27:50 andreas Exp $";

#ifdef __GNUG__
#pragma implementation
#endif

#include <iostream.h>
#include "ScrolleGEP.h"
#include "GraphEdit.h"
#include "verify.h"
#include "strclass.h"

// We have no special class for scrolling a graph editor, but use the
// Motif ScrolledWindow class instead.

WidgetClass scrolledGraphEditWidgetClass = xmScrolledWindowWidgetClass;

static void ResizeEH(Widget, XtPointer client_data, XEvent *, Boolean *)
{
    Widget graphEdit = Widget(client_data);
    graphEditSizeChanged(graphEdit);
}

Widget createScrolledGraphEdit(Widget parent, String name,
			       ArgList arglist, Cardinal argcount)
{
    Arg args[10];
    int arg = 0;

    XtSetArg(args[arg], XmNscrollingPolicy, XmAUTOMATIC); arg++;
    string swindow_name = string(name) + "_swindow";

    XtSetArg(args[arg], XmNborderWidth,     0); arg++;
    XtSetArg(args[arg], XmNspacing,         0); arg++;
    XtSetArg(args[arg], XmNshadowThickness, 0); arg++;

    Widget scrolledWindow = 
	verify(XtCreateManagedWidget((char *)swindow_name, 
				     scrolledGraphEditWidgetClass,
				     parent, args, arg));

    Widget graphEdit = 
	verify(XtCreateManagedWidget(name, graphEditWidgetClass,
				     scrolledWindow, arglist, argcount));

    XtAddEventHandler(scrolledWindow, StructureNotifyMask, False,
		      ResizeEH, XtPointer(graphEdit));

    // Propagate requested width and height of graph editor to scrolled window
    Dimension width, height;
    XtVaGetValues(graphEdit, 
		  XtNrequestedWidth, &width,
		  XtNrequestedHeight, &height,
		  NULL);

    if (width > 0)
	XtVaSetValues(scrolledWindow, XmNwidth, width, NULL);
    if (height > 0)
	XtVaSetValues(scrolledWindow, XmNheight, height, NULL);

    return graphEdit;
}

// For a given graph editor W, return its scroller
Widget scrollerOfGraphEdit(Widget w)
{
    XtCheckSubclass(w, GraphEditWidgetClass, "Bad widget class");

    Widget parent = w;
    while (parent != 0)
    {
	if (XtIsSubclass(parent, scrolledGraphEditWidgetClass))
	    break;
	parent = XtParent(parent);
    }
    return parent;
}
