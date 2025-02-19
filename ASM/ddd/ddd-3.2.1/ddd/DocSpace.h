/* $Id: DocSpace.h,v 1.8 1999/08/19 11:27:25 andreas Exp $ */
/* DocSpace-Widget (Deklaration) */

/*
    Copyright (C) 1995 Technische Universitaet Braunschweig, Germany.
    Written by Andreas Zeller <zeller@gnu.org>.

    This file is part of DDD.

    DDD is free software; you can redistribute it and/or
    modify it under the terms of the GNU General Public
    License as published by the Free Software Foundation; either
    version 2 of the License, or (at your option) any later version.

    DDD is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
    See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public
    License along with DDD -- see the file COPYING.
    If not, write to the Free Software Foundation, Inc.,
    59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.

    DDD is the data display debugger.
    For details, see the DDD World-Wide-Web page, 
    `http://www.gnu.org/software/ddd/',
    or send a mail to the DDD developers <ddd@gnu.org>.
*/

#ifndef _DocSpace_h
#define _DocSpace_h

/****************************************************************
 *
 * DocSpace widget
 *
 ****************************************************************/

/* Resources:

 Name                Class              RepType         Default Value
 ----                -----              -------         -------------
 background          Background         Pixel           XtDefaultBackground
 border              BorderColor        Pixel           XtDefaultForeground
 borderWidth         BorderWidth        BoxDimension    1
 destroyCallback     Callback           Pointer         NULL
 height              Height             BoxDimension    0
 mappedWhenManaged   MappedWhenManaged  boolean         True
 sensitive           Sensitive          boolean         True
 width               Width              BoxDimension    0
 x                   Position           Position        0
 y                   Position           Position        0
 callback            Callback           Callback        NULL
 exposeCallback      Callback           Callback        NULL

*/

/* define any special resource names here that are not in <X11/StringDefs.h> */

#define XtNdocSpaceResource     "docSpaceResource"
#define XtNexposeCallback       "exposeCallback"
#define XtNquitCallback     "quitCallback"

#define XtCDocSpaceResource "DocSpaceResource"

/* declare specific DocSpaceWidget class and instance datatypes */

typedef struct _DocSpaceClassRec*   DocSpaceWidgetClass;
typedef struct _DocSpaceRec*        DocSpaceWidget;

/* declare the class constant */

extern WidgetClass docSpaceWidgetClass;

#endif /* _DocSpace_h */
