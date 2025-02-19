// $Id: resources.h,v 1.9 1999/08/19 11:28:50 andreas Exp $ -*- C++ -*-
// DDD application resources

// Copyright (C) 1996 Technische Universitaet Braunschweig, Germany.
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

#ifndef _DDD_resources_h
#define _DDD_resources_h

#ifdef __GNUG__
#pragma interface
#endif

#include <X11/Intrinsic.h>

// DDD resource definitions
extern XtResource ddd_resources[];
extern const int ddd_resources_size;

// Resources to use if `Ddd' app-defaults are not found
extern String ddd_fallback_resources[];

// Default resources
extern XrmDatabase app_defaults(Display *display);

#endif // _DDD_resources_h
// DON'T ADD ANYTHING BEHIND THIS #endif
