// $Id: FixBox.h,v 1.10 1999/08/19 11:27:28 andreas Exp $
// Fixed size boxes

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

#ifndef _DDD_FixBox_h
#define _DDD_FixBox_h

#ifdef __GNUG__
#pragma interface
#endif


// A HFixBox or VFixBox sets the extent of its child to zero.


#include "HatBox.h"



// FixBox

class FixBox: public HatBox {
public:
    DECLARE_TYPE_INFO

protected:
    FixBox(const FixBox& box): HatBox(box)
    {}

public:
    FixBox(Box *box, char *t = "FixBox"): HatBox(box, t)
    {}
    
    // Must be overloaded by subclasses
    virtual Box *resize() = 0;
};



// HFixBox

class HFixBox: public FixBox {
public:
    DECLARE_TYPE_INFO

protected:
    HFixBox(const HFixBox& box): FixBox(box)
    {}
    void dump(ostream& s) const;

public:
    HFixBox(Box *box, char *t = "HFixBox"): FixBox(box, t)
    { theextend().fix(X); }

    Box *resize()
    {
	HatBox::resize();
	theextend().fix(X);

	return this;
    }

    Box *dup() const { return new HFixBox(*this); }
};


// VFixBox

class VFixBox: public FixBox {
public:
    DECLARE_TYPE_INFO

protected:
    VFixBox(const VFixBox& box): FixBox(box)
    {}
    void dump(ostream& s) const;

public:
    VFixBox(Box *box, char *t = "VFixBox"): FixBox(box, t)
    { theextend().fix(Y); }

    Box *resize()
    {
	HatBox::resize();
	theextend().fix(Y);

	return this;
    }

    Box *dup() const { return new VFixBox(*this); }
};

#endif
