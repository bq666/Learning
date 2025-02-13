// $Id: BoxRegion.C,v 1.10 1999/08/19 11:27:08 andreas Exp $  -*- C++ -*-
// BoxRegion class

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

char BoxRegion_rcsid[] = 
    "$Id: BoxRegion.C,v 1.10 1999/08/19 11:27:08 andreas Exp $";

#ifdef __GNUG__
#pragma implementation
#endif

#include "BoxRegion.h"

// Compute intersection of two regions
BoxRegion BoxRegion::operator & (const BoxRegion& r) const
{
    if (!origin().isValid())
	return r;
    if (!r.origin().isValid())
	return *this;

    BoxPoint nw_corner(max(origin(X), r.origin(X)),
		    max(origin(Y), r.origin(Y)));
    BoxPoint se_corner(min(origin(X) + space(X), r.origin(X) + r.space(X)),
		    min(origin(Y) + space(Y), r.origin(Y) + r.space(Y)));

    return BoxRegion(nw_corner, BoxSize(se_corner - nw_corner));
}

// Compute union of two regions
BoxRegion BoxRegion::operator | (const BoxRegion& r) const
{
    if (!origin().isValid())
	return r;
    if (!r.origin().isValid())
	return *this;

    BoxPoint nw_corner(min(origin(X), r.origin(X)),
		    min(origin(Y), r.origin(Y)));
    BoxPoint se_corner(max(origin(X) + space(X), r.origin(X) + r.space(X)),
		    max(origin(Y) + space(Y), r.origin(Y) + r.space(Y)));

    return BoxRegion(nw_corner, BoxSize(se_corner - nw_corner));
}

// Dump
ostream& operator << (ostream& s, const BoxRegion& r)
{
    return s << r.origin() << r.space();
}
