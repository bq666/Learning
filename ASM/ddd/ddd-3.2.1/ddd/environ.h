// $Id: environ.h,v 1.5 1999/08/19 11:28:31 andreas Exp $ -*- C++ -*-
// Environment commands

// Copyright (C) 1997 Technische Universitaet Braunschweig, Germany.
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

#ifndef _DDD_environ_h
#define _DDD_environ_h

#ifdef __GNUG__
#pragma interface
#endif

#include "strclass.h"

// Put NAME=VALUE into the environment
extern void put_environment(string name, string value);

// Return NAME1=VALUE1 NAME2=VALUE2 for each name defined by PUT_ENVIRONMENT
extern string set_environment_command();

#endif // _DDD_environ_h
// DON'T ADD ANYTHING BEHIND THIS #endif
