// $Id: hash.h,v 1.7 1999/08/19 11:28:37 andreas Exp $ -*- C++ -*-
// Hash functions

// Copyright (C) 1995 Technische Universitaet Braunschweig, Germany.
// Written by Andreas Zeller <zeller@gnu.org>.
// 
// This file is part of the ICE Library.
// 
// The ICE Library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Library General Public
// License as published by the Free Software Foundation; either
// version 2 of the License, or (at your option) any later version.
// 
// The ICE Library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
// See the GNU Library General Public License for more details.
// 
// You should have received a copy of the GNU Library General Public
// License along with the ICE Library -- see the file COPYING.LIB.
// If not, write to the Free Software Foundation, Inc.,
// 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
// 
// ICE is the incremental configuration environment.
// For details, see the ICE World-Wide-Web page, 
// `http://www.cs.tu-bs.de/softech/ice/',
// or send a mail to the ICE developers <ice@ips.cs.tu-bs.de>.

#ifndef _ICE_hash_h
#define _ICE_hash_h

#ifdef __GNUG__
#pragma interface
#endif

unsigned int hashpjw(const char*);

inline unsigned int multiplicativehash(int x)
{
    // uses a const close to golden ratio * pow(2,32)
    return ((unsigned)x) * 2654435767UL;
}

unsigned int foldhash(double);

#endif // _ICE_hash_h
// DON'T ADD ANYTHING BEHIND THIS #endif
