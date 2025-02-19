// $Id: DummyNode.h,v 1.11 1999/08/19 11:27:26 andreas Exp $
// A DummyNode returns a DummyBox

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

#ifndef _DDD_DummyNode_h
#define _DDD_DummyNode_h

#ifdef __GNUG__
#pragma interface
#endif


// A DummyNode returns a DummyBox at run-time.
// A DummyNode matches all other nodes if `DummyNode::matchesAll' is true.

#include "assert.h"
#include <iostream.h>

#include "VSLNode.h"
#include "Box.h"
#include "DummyBox.h"

// DummyNode

class DummyNode: public VSLNode {
public:
    DECLARE_TYPE_INFO

protected:
    DummyNode(const DummyNode& node):
	VSLNode(node)
    {}
    
    void dump(ostream& s) const
    {
	s << "_";
    }

    bool matches(const VSLNode& node) const
    {
	return matchesAll || VSLNode::matches(node);
    }

public:
    // Constructor
    DummyNode(char *type = "DummyNode")
	: VSLNode(type)
    {}

    // Copy
    VSLNode *dup() const
    {
	return new DummyNode(*this);
    }

    const Box *_eval(ListBox *) const    
    { 
	return new DummyBox; 
    }

    static bool matchesAll;

    bool isConst() const { return true; }
    bool isDummyNode() const { return true; }
};

#endif
