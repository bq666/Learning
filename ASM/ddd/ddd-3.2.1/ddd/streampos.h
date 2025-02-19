// $Id: streampos.h,v 1.1 2000/01/17 14:53:42 andreas Exp $ -*- C++ -*-
// A typedef for stream positions

// Copyright (C) 2000 Universitaet Passau, Germany.
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

#ifndef _DDD_streampos_h
#define _DDD_streampos_h

#ifdef __GNUG__
#pragma interface
#endif

// Older C++ releases defined `streampos' as a type for stream positions;
// in the current C++ standard, this is implementation-defined.  We use
// a simple `long' as replacement.

#include "config.h"

#if !HAVE_STREAMPOS
typedef long streampos;
#endif

#endif // _DDD_streampos_h
// DON'T ADD ANYTHING BEHIND THIS #endif
