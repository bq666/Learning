// $Id: UniqueId.C,v 1.8 1999/08/19 11:28:03 andreas Exp $ 
// Unique identifiers

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

char UniqueId_rcsid[] =
    "$Id: UniqueId.C,v 1.8 1999/08/19 11:28:03 andreas Exp $";

#ifdef __GNUG__
#pragma implementation
#endif


#include "UniqueId.h"
#include "bool.h"

unsigned long UniqueId::tics = 1;
unsigned long UniqueId::ids  = 0;
bool UniqueId::debug      = false;

#ifndef NDEBUG
UniqueId::UniqueId(): _id(tics++)
{
    ids++;
    if (debug)
	clog << "+ " << _id << "\n";
}

UniqueId::~UniqueId()
{
    if (debug)
	clog << "- " << _id << "\n";
    ids--;
}
#endif
