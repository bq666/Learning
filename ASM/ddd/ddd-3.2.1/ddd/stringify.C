// $Id: stringify.C,v 1.7 2000/01/03 12:12:16 andreas Exp $ -*- C++ -*-
// C-encode standard input

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

char stringify_rcsid[] = 
    "$Id: stringify.C,v 1.7 2000/01/03 12:12:16 andreas Exp $";

#include <stdio.h>
#include <stdlib.h>

#ifndef EXIT_SUCCESS
#define EXIT_SUCCESS 0
#endif

#ifndef EXIT_FAILURE
#define EXIT_FAILURE 1
#endif

int main()
{
    printf("\"");

    int p = 0;

    int c;
    while ((c = getchar()) != EOF)
    {
	if (p > 0 && p % 16 == 0)
	    printf("\"\n\"");

	printf("\\%03o", c);

	p++;
    }

    printf("\"\n");

    return EXIT_SUCCESS;
}
