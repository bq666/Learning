// $Id: selection.h,v 1.2 1999/08/19 11:28:52 andreas Exp $ -*- C++ -*-
// Return current clipboard selection

// Copyright (C) 1998 Technische Universitaet Braunschweig, Germany.
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

#ifndef _DDD_selection_h
#define _DDD_selection_h

#ifdef __GNUG__
#pragma interface
#endif

#include <Xm/Xm.h>
#include "strclass.h"

// Return the current clipboard selection
extern string current_clipboard(Widget w);

// Return the current primary selection
extern string current_primary(Widget w);

// Return the current cut buffer selection
extern string current_cut_buffer(Widget w);

// Return the current selection: first primary, then cut buffer, then clipboard
extern string current_selection(Widget w);

#endif // _DDD_selection_h
// DON'T ADD ANYTHING BEHIND THIS #endif
