// $Id: SmartC.h,v 1.3 1999/08/19 11:27:51 andreas Exp $ -*- C++ -*-
// `smart' string comparison

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

#ifndef _DDD_SmartCompare_h
#define _DDD_SmartCompare_h

#ifdef __GNUG__
#pragma interface
#endif

#include "StringA.h"

// Compare S1 and S2, taking numerals into account
// returns < 0, > 0, or 0 iff S1 < S2, S1 > S2, or S1 == S2.
extern int smart_compare(const char *s1, const char *s2);

// Sort array S, using smart_compare
extern void smart_sort(StringArray& s);
extern void smart_sort(char *a[], int size);
extern void smart_sort(string *a, int size);

// Remove adjacent duplicates in A
extern void uniq(StringArray& a);

#endif // _DDD_SmartCompare_h
// DON'T ADD ANYTHING BEHIND THIS #endif
