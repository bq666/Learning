// This file was modified for -*- C++ -*-
// using $RCSfile: yacctoC.bison,v $ $Revision: 1.11 $
extern void vslerror(char *s);
extern int vsllex();


/*  A Bison parser, made from ./vsl-gramma.Y
 by  GNU Bison version 1.27
  */

#define YYBISON 1  /* Identify Bison output.  */

#define	IDENTIFIER	257
#define	STRING	258
#define	INTEGER	259
#define	ARROW	260
#define	IF	261
#define	THEN	262
#define	ELSE	263
#define	ELSIF	264
#define	FI	265
#define	OR	266
#define	AND	267
#define	NOT	268
#define	LET	269
#define	IN	270
#define	WHERE	271
#define	OVERRIDE	272
#define	REPLACE	273
#define	EQ	274
#define	NE	275
#define	GT	276
#define	GE	277
#define	LT	278
#define	LE	279
#define	HALIGN	280
#define	VALIGN	281
#define	UALIGN	282
#define	TALIGN	283
#define	APPEND	284
#define	CONS	285
#define	THREEDOTS	286

#line 4 "./vsl-gramma.Y"


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


// Some declarations and utilities

char VSL_yacc_rcsid[] = 
    "$Id: vsl-gramma.Y,v 1.15 1999/08/19 11:29:02 andreas Exp $";


// Function calls

// Return appropriate node for function call
VSLNode *VSLLib::_call(const string& func_name, VSLNode *arg)
{
    // Find definition list
    VSLDefList* def = deflist(func_name);
    if (def == 0)
    {
	VSLLib::parse_error("'" + func_name + "(...)' undefined");
	delete arg;
	arg = 0;
    }

    // Return calling node
    if (def && arg)
	return new DefCallNode(def, arg);

    return 0;
}

VSLNode *VSLLib::call(const string& name)
{
    return _call(name, new EmptyListNode);
}

VSLNode *VSLLib::call(const string& name, VSLNode *arg)
{
    if (arg)
	return _call(name, new FixListNode(arg));

    return 0;
}

VSLNode *VSLLib::call(const string& name, VSLNode *arg1, VSLNode *arg2)
{
    if (arg1 && arg2)
	return _call(name, new FixListNode(arg1, arg2));

    return 0;
}

VSLNode *VSLLib::call(const string& name, 
		      VSLNode *arg1, VSLNode *arg2, VSLNode *arg3)
{
    if (arg1 && arg2 && arg3)
	return _call(name, new FixListNode(arg1, arg2, arg3));

    return 0;
}

// Some settings
#define YYERROR_VERBOSE

#ifdef YYERROR_VERBOSE
#define YYDEBUG 1
#endif

#line 143 "./vsl-gramma.Y"
typedef struct _YYSTYPE  {
    // Our special yacctoC program makes this a struct -- 
    // thus we use an anonymous union (does not harm in other cases)
    union {
	VSLNode *node;
	string *str;
	int num;
	double fnum;
	VSLFunctionHeader function_header;
	VSLVarDefinition  var_definition;
    };
} YYSTYPE;
#include <stdio.h>

#ifndef __cplusplus
#ifndef __STDC__
#define const
#endif
#endif



#define	YYFINAL		189
#define	YYFLAG		-32768
#define	YYNTBASE	44

#define YYTRANSLATE(x) ((unsigned)(x) <= 286 ? vsltranslate[x] : 82)

static const char vsltranslate[] = {     0,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,    37,     2,     2,    39,
    40,    35,    33,    41,    34,     2,    36,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,    38,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
    42,     2,    43,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     1,     3,     4,     5,     6,
     7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
    17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
    27,    28,    29,    30,    31,    32
};

#if YYDEBUG != 0
static const short vslprhs[] = {     0,
     0,     2,     3,     6,     9,    12,    14,    16,    18,    21,
    23,    26,    28,    30,    34,    38,    42,    46,    50,    54,
    58,    62,    66,    70,    74,    78,    82,    86,    90,    94,
    98,   100,   102,   104,   107,   110,   113,   116,   118,   120,
   124,   127,   131,   133,   135,   139,   143,   147,   151,   153,
   155,   157,   159,   161,   163,   165,   168,   172,   175,   179,
   181,   183,   187,   191,   194,   196,   198,   200,   202,   205,
   207,   210,   213,   216,   219,   223,   227,   231,   235,   239,
   243,   247,   251,   255,   259,   263,   267,   271,   275,   279,
   283,   287,   291,   298,   304,   307,   309,   313,   315,   318,
   320,   324,   326,   329,   331,   335
};

static const short vslrhs[] = {    45,
     0,     0,    45,    46,     0,    47,    38,     0,    51,    38,
     0,    76,     0,    79,     0,    38,     0,     1,    38,     0,
    48,     0,    49,    74,     0,    49,     0,    50,     0,    39,
    20,    40,     0,    39,    21,    40,     0,    39,    22,    40,
     0,    39,    23,    40,     0,    39,    24,    40,     0,    39,
    25,    40,     0,    39,    26,    40,     0,    39,    27,    40,
     0,    39,    28,    40,     0,    39,    29,    40,     0,    39,
    33,    40,     0,    39,    34,    40,     0,    39,    35,    40,
     0,    39,    36,    40,     0,    39,    37,    40,     0,    39,
    31,    40,     0,    39,    14,    40,     0,     3,     0,    52,
     0,    54,     0,    53,    56,     0,    48,    20,     0,    55,
    56,     0,    48,     6,     0,    57,     0,    59,     0,    15,
    61,    58,     0,    16,    57,     0,    41,    61,    58,     0,
    62,     0,    60,     0,    59,    17,    61,     0,    60,    41,
    61,     0,    62,    20,    62,     0,    39,    57,    40,     0,
    63,     0,    66,     0,    71,     0,    70,     0,    72,     0,
    69,     0,    75,     0,    42,    43,     0,    42,    64,    43,
     0,    39,    40,     0,    39,    65,    40,     0,    57,     0,
    65,     0,    62,    30,    62,     0,    62,    41,    64,     0,
    62,    32,     0,    32,     0,    67,     0,    68,     0,     4,
     0,    67,     4,     0,     5,     0,    49,    74,     0,    14,
    62,     0,    33,    62,     0,    34,    62,     0,    62,    20,
    62,     0,    62,    21,    62,     0,    62,    22,    62,     0,
    62,    23,    62,     0,    62,    24,    62,     0,    62,    25,
    62,     0,    62,    26,    62,     0,    62,    27,    62,     0,
    62,    28,    62,     0,    62,    29,    62,     0,    62,    33,
    62,     0,    62,    34,    62,     0,    62,    35,    62,     0,
    62,    36,    62,     0,    62,    37,    62,     0,    62,    31,
    62,     0,    62,    12,    62,     0,    62,    13,    62,     0,
     7,    62,     8,    57,    73,    11,     0,    10,    62,     8,
    57,    73,     0,     9,    57,     0,    63,     0,    39,    57,
    40,     0,    50,     0,    18,    77,     0,    78,     0,    77,
    41,    78,     0,    49,     0,    19,    80,     0,    81,     0,
    80,    41,    81,     0,    49,     0
};

#endif

#if YYDEBUG != 0
static const short vslrline[] = { 0,
   173,   175,   176,   178,   179,   180,   181,   182,   183,   187,
   202,   212,   224,   226,   228,   230,   232,   234,   236,   238,
   240,   242,   244,   246,   248,   250,   252,   254,   256,   258,
   261,   264,   265,   267,   285,   304,   322,   337,   346,   350,
   364,   368,   383,   385,   388,   402,   418,   430,   432,   434,
   436,   438,   440,   442,   444,   447,   452,   457,   462,   468,
   475,   480,   488,   496,   500,   506,   518,   524,   529,   539,
   544,   554,   560,   564,   576,   583,   590,   597,   604,   611,
   618,   625,   632,   639,   646,   653,   660,   667,   674,   681,
   688,   698,   709,   723,   735,   740,   744,   752,   778,   780,
   781,   783,   797,   799,   800,   802
};
#endif


#if YYDEBUG != 0 || defined (YYERROR_VERBOSE)

static const char * const vsltname[] = {   "$","error","$undefined.","IDENTIFIER",
"STRING","INTEGER","ARROW","IF","THEN","ELSE","ELSIF","FI","OR","AND","NOT",
"LET","IN","WHERE","OVERRIDE","REPLACE","EQ","NE","GT","GE","LT","LE","HALIGN",
"VALIGN","UALIGN","TALIGN","APPEND","CONS","THREEDOTS","'+'","'-'","'*'","'/'",
"'%'","';'","'('","')'","','","'['","']'","file","item_list","item","function_declaration",
"function_header","function_identifier","identifier","function_definition","local_definition",
"local_header","global_definition","global_header","function_body","box_expression_with_defs",
"in_box_expression","box_expression_with_wheres","box_expression_with_where",
"var_definition","box_expression","list_expression","box_expression_list","multiple_box_expression_list",
"const_expression","string_constant","numeric_constant","function_call","unary_expression",
"binary_expression","cond_expression","else_expression","function_argument",
"argument_or_function","override_declaration","override_list","override_identifier",
"replace_declaration","replace_list","replace_identifier", NULL
};
#endif

static const short vslr1[] = {     0,
    44,    45,    45,    46,    46,    46,    46,    46,    46,    47,
    48,    48,    49,    49,    49,    49,    49,    49,    49,    49,
    49,    49,    49,    49,    49,    49,    49,    49,    49,    49,
    50,    51,    51,    52,    53,    54,    55,    56,    57,    57,
    58,    58,    59,    59,    60,    60,    61,    62,    62,    62,
    62,    62,    62,    62,    62,    63,    63,    63,    63,    64,
    64,    65,    65,    65,    65,    66,    66,    67,    67,    68,
    69,    70,    70,    70,    71,    71,    71,    71,    71,    71,
    71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
    71,    71,    72,    73,    73,    74,    74,    75,    76,    77,
    77,    78,    79,    80,    80,    81
};

static const short vslr2[] = {     0,
     1,     0,     2,     2,     2,     1,     1,     1,     2,     1,
     2,     1,     1,     3,     3,     3,     3,     3,     3,     3,
     3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
     1,     1,     1,     2,     2,     2,     2,     1,     1,     3,
     2,     3,     1,     1,     3,     3,     3,     3,     1,     1,
     1,     1,     1,     1,     1,     2,     3,     2,     3,     1,
     1,     3,     3,     2,     1,     1,     1,     1,     2,     1,
     2,     2,     2,     2,     3,     3,     3,     3,     3,     3,
     3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
     3,     3,     6,     5,     2,     1,     3,     1,     2,     1,
     3,     1,     2,     1,     3,     1
};

static const short vsldefact[] = {     2,
     0,     0,    31,     0,     0,     8,     0,     3,     0,    10,
    12,    13,     0,    32,     0,    33,     0,     6,     7,     9,
   102,    99,   100,   106,   103,   104,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     4,    37,    35,     0,     0,    96,    11,
     5,    68,    70,     0,     0,     0,     0,     0,     0,     0,
    98,    34,    38,    39,    44,    43,    49,    50,    66,    67,
    54,    52,    51,    53,    55,    36,     0,     0,    30,    14,
    15,    16,    17,    18,    19,    20,    21,    22,    23,    29,
    24,    25,    26,    27,    28,    65,    58,     0,    43,     0,
    56,    60,     0,    61,     0,    72,     0,     0,    73,    74,
     0,     0,     0,     0,    71,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,    69,   101,   105,    97,     0,
    64,     0,    59,    57,     0,     0,     0,    40,     0,    48,
    45,    46,    91,    92,    75,    76,    77,    78,    79,    80,
    81,    82,    83,    84,    90,    85,    86,    87,    88,    89,
    62,    63,     0,    41,     0,    47,     0,     0,     0,    42,
    95,     0,    93,     0,     0,    94,     0,     0,     0
};

static const short vsldefgoto[] = {   187,
     1,     8,     9,    10,    60,    61,    13,    14,    15,    16,
    17,    62,    63,   148,    64,    65,   107,    66,    67,   103,
   100,    68,    69,    70,    71,    72,    73,    74,   179,    50,
    75,    18,    22,    23,    19,    25,    26
};

static const short vslpact[] = {-32768,
    16,    -5,-32768,    22,    22,-32768,   498,-32768,     1,     8,
   -24,-32768,    14,-32768,   223,-32768,   223,-32768,-32768,-32768,
-32768,   -14,-32768,-32768,    -1,-32768,    18,    30,    32,    38,
    47,    49,    63,    64,    88,    92,    93,    94,    95,   103,
   105,   114,   115,-32768,-32768,-32768,   177,    17,-32768,-32768,
-32768,-32768,-32768,   300,   300,   300,   300,   300,   137,   -24,
   -16,-32768,-32768,    25,    56,   409,-32768,-32768,    53,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,    22,    22,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,   116,   323,   135,
-32768,-32768,   110,-32768,   353,-32768,    -3,   435,    90,    90,
   236,   276,   288,   138,-32768,   300,   300,   300,   300,   300,
   300,   300,   300,   300,   300,   300,   300,   300,   300,   300,
   300,   300,   300,   300,   300,-32768,-32768,-32768,-32768,   300,
-32768,   190,-32768,-32768,   223,   223,   300,-32768,   300,-32768,
-32768,-32768,   480,   516,    40,    40,    57,    57,    57,    57,
   152,   218,   528,   113,    57,    90,    90,-32768,-32768,-32768,
   409,-32768,    20,-32768,    -3,   461,   223,   300,   172,-32768,
-32768,   383,-32768,   223,    20,-32768,   196,   198,-32768
};

static const short vslpgoto[] = {-32768,
-32768,-32768,-32768,-32768,     2,     4,-32768,-32768,-32768,-32768,
-32768,   173,   -47,    24,-32768,-32768,  -106,   -11,    -7,    58,
   -46,-32768,-32768,-32768,-32768,-32768,-32768,-32768,    21,   141,
-32768,-32768,-32768,   125,-32768,-32768,   129
};


#define	YYLAST		565


static const short vsltable[] = {    98,
   102,   104,    11,    49,    12,    21,    24,    12,    12,   151,
   152,   114,   146,    45,    47,    -1,     2,    48,     3,     3,
    52,    53,   -13,    54,     3,   -13,    77,    46,   177,   178,
    55,    56,    20,     4,     5,    99,    99,   147,    44,    78,
   175,   116,   105,   106,   108,   109,   110,    99,    96,    57,
    58,    51,    49,     6,     7,    59,   136,    79,    48,   101,
     7,   122,   123,   124,   125,   126,   127,   128,   129,    80,
   130,    81,   131,   132,   133,   134,   135,    82,    21,    24,
    12,    12,   126,   127,   128,   129,    83,   130,    84,   131,
   132,   133,   134,   135,   102,   104,   117,   173,   174,   106,
   109,   110,    85,    86,   108,   108,   153,   154,   155,   156,
   157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
   167,   168,   169,   170,   133,   134,   135,    87,   171,   181,
    99,    88,    89,    90,    91,   108,   185,   176,   126,     3,
    52,    53,    92,    54,    93,   131,   132,   133,   134,   135,
   111,    56,   144,    94,    95,   139,    28,    29,    30,    31,
    32,    33,    34,    35,    36,    37,   182,    38,    96,   112,
   113,    41,    42,    43,   143,    59,    97,   150,    48,     3,
    52,    53,   183,    54,   131,   132,   133,   134,   135,    76,
    55,    56,     3,    52,    53,   188,    54,   189,   180,   172,
   115,   137,     0,    55,    56,   186,   138,     0,    96,    57,
    58,     0,     0,     0,     0,    59,    97,     0,    48,     0,
     0,    96,    57,    58,     0,     3,    52,    53,    59,    54,
     0,    48,     0,     0,     0,     0,    55,    56,     3,    52,
    53,     0,    54,   126,     0,   128,   129,     0,     0,    55,
   131,   132,   133,   134,   135,    57,    58,     0,     0,     0,
     0,    59,     0,     0,    48,     0,     0,     0,    57,    58,
     0,     0,     0,     0,    59,    79,     0,    48,     3,    52,
    53,     0,    54,     0,     0,     0,     0,     0,     0,    55,
     3,    52,    53,     0,    54,     0,     0,     0,     0,     0,
     0,    55,     3,    52,    53,     0,    54,     0,    57,    58,
     0,     0,     0,    55,    59,    91,     0,    48,     0,     0,
    57,    58,     0,     0,     0,     0,    59,    92,     0,    48,
     0,     0,    57,    58,   118,   119,     0,     0,    59,     0,
     0,    48,   120,   121,   122,   123,   124,   125,   126,   127,
   128,   129,   140,   130,   141,   131,   132,   133,   134,   135,
   145,     0,     0,   142,   118,   119,     0,     0,     0,     0,
     0,     0,   120,   121,   122,   123,   124,   125,   126,   127,
   128,   129,     0,   130,     0,   131,   132,   133,   134,   135,
   184,     0,     0,     0,   118,   119,     0,     0,     0,     0,
     0,     0,   120,   121,   122,   123,   124,   125,   126,   127,
   128,   129,     0,   130,     0,   131,   132,   133,   134,   135,
   118,   119,     0,     0,     0,     0,     0,     0,   120,   121,
   122,   123,   124,   125,   126,   127,   128,   129,     0,   130,
     0,   131,   132,   133,   134,   135,   118,   119,     0,     0,
     0,     0,     0,     0,   149,   121,   122,   123,   124,   125,
   126,   127,   128,   129,     0,   130,     0,   131,   132,   133,
   134,   135,   -75,   -75,     0,     0,     0,     0,     0,     0,
   -75,   -75,   122,   123,   124,   125,   126,   127,   128,   129,
     0,   130,   119,   131,   132,   133,   134,   135,     0,   120,
   121,   122,   123,   124,   125,   126,   127,   128,   129,     0,
   130,    27,   131,   132,   133,   134,   135,    28,    29,    30,
    31,    32,    33,    34,    35,    36,    37,     0,    38,     0,
    39,    40,    41,    42,    43,   120,   121,   122,   123,   124,
   125,   126,   127,   128,   129,     0,   130,     0,   131,   132,
   133,   134,   135,   126,     0,     0,   129,     0,     0,     0,
   131,   132,   133,   134,   135
};

static const short vslcheck[] = {    47,
    48,    48,     1,    11,     1,     4,     5,     4,     5,   116,
   117,    59,    16,     6,    39,     0,     1,    42,     3,     3,
     4,     5,    39,     7,     3,    42,    41,    20,     9,    10,
    14,    15,    38,    18,    19,    47,    48,    41,    38,    41,
   147,    17,    54,    55,    56,    57,    58,    59,    32,    33,
    34,    38,    60,    38,    39,    39,     4,    40,    42,    43,
    39,    22,    23,    24,    25,    26,    27,    28,    29,    40,
    31,    40,    33,    34,    35,    36,    37,    40,    77,    78,
    77,    78,    26,    27,    28,    29,    40,    31,    40,    33,
    34,    35,    36,    37,   142,   142,    41,   145,   146,   111,
   112,   113,    40,    40,   116,   117,   118,   119,   120,   121,
   122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
   132,   133,   134,   135,    35,    36,    37,    40,   140,   177,
   142,    40,    40,    40,    40,   147,   184,   149,    26,     3,
     4,     5,    40,     7,    40,    33,    34,    35,    36,    37,
    14,    15,    43,    40,    40,    40,    20,    21,    22,    23,
    24,    25,    26,    27,    28,    29,   178,    31,    32,    33,
    34,    35,    36,    37,    40,    39,    40,    40,    42,     3,
     4,     5,    11,     7,    33,    34,    35,    36,    37,    17,
    14,    15,     3,     4,     5,     0,     7,     0,   175,   142,
    60,    77,    -1,    14,    15,   185,    78,    -1,    32,    33,
    34,    -1,    -1,    -1,    -1,    39,    40,    -1,    42,    -1,
    -1,    32,    33,    34,    -1,     3,     4,     5,    39,     7,
    -1,    42,    -1,    -1,    -1,    -1,    14,    15,     3,     4,
     5,    -1,     7,    26,    -1,    28,    29,    -1,    -1,    14,
    33,    34,    35,    36,    37,    33,    34,    -1,    -1,    -1,
    -1,    39,    -1,    -1,    42,    -1,    -1,    -1,    33,    34,
    -1,    -1,    -1,    -1,    39,    40,    -1,    42,     3,     4,
     5,    -1,     7,    -1,    -1,    -1,    -1,    -1,    -1,    14,
     3,     4,     5,    -1,     7,    -1,    -1,    -1,    -1,    -1,
    -1,    14,     3,     4,     5,    -1,     7,    -1,    33,    34,
    -1,    -1,    -1,    14,    39,    40,    -1,    42,    -1,    -1,
    33,    34,    -1,    -1,    -1,    -1,    39,    40,    -1,    42,
    -1,    -1,    33,    34,    12,    13,    -1,    -1,    39,    -1,
    -1,    42,    20,    21,    22,    23,    24,    25,    26,    27,
    28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
     8,    -1,    -1,    41,    12,    13,    -1,    -1,    -1,    -1,
    -1,    -1,    20,    21,    22,    23,    24,    25,    26,    27,
    28,    29,    -1,    31,    -1,    33,    34,    35,    36,    37,
     8,    -1,    -1,    -1,    12,    13,    -1,    -1,    -1,    -1,
    -1,    -1,    20,    21,    22,    23,    24,    25,    26,    27,
    28,    29,    -1,    31,    -1,    33,    34,    35,    36,    37,
    12,    13,    -1,    -1,    -1,    -1,    -1,    -1,    20,    21,
    22,    23,    24,    25,    26,    27,    28,    29,    -1,    31,
    -1,    33,    34,    35,    36,    37,    12,    13,    -1,    -1,
    -1,    -1,    -1,    -1,    20,    21,    22,    23,    24,    25,
    26,    27,    28,    29,    -1,    31,    -1,    33,    34,    35,
    36,    37,    12,    13,    -1,    -1,    -1,    -1,    -1,    -1,
    20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
    -1,    31,    13,    33,    34,    35,    36,    37,    -1,    20,
    21,    22,    23,    24,    25,    26,    27,    28,    29,    -1,
    31,    14,    33,    34,    35,    36,    37,    20,    21,    22,
    23,    24,    25,    26,    27,    28,    29,    -1,    31,    -1,
    33,    34,    35,    36,    37,    20,    21,    22,    23,    24,
    25,    26,    27,    28,    29,    -1,    31,    -1,    33,    34,
    35,    36,    37,    26,    -1,    -1,    29,    -1,    -1,    -1,
    33,    34,    35,    36,    37
};
/* -*-C-*-  Note some compilers choke on comments on `#line' lines.  */
#line 3 "/usr/lib/bison.simple"
/* This file comes from bison-1.27.  */

/* Skeleton output parser for bison,
   Copyright (C) 1984, 1989, 1990 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

/* This is the parser code that is written into each bison parser
  when the %semantic_parser declaration is not specified in the grammar.
  It was written by Richard Stallman by simplifying the hairy parser
  used when %semantic_parser is specified.  */

#ifndef YYSTACK_USE_ALLOCA
#ifdef alloca
#define YYSTACK_USE_ALLOCA
#else /* alloca not defined */
#ifdef __GNUC__
#define YYSTACK_USE_ALLOCA
#define alloca __builtin_alloca
#else /* not GNU C.  */
#if (!defined (__STDC__) && defined (sparc)) || defined (__sparc__) || defined (__sparc) || defined (__sgi) || (defined (__sun) && defined (__i386))
#define YYSTACK_USE_ALLOCA
#include <alloca.h>
#else /* not sparc */
/* We think this test detects Watcom and Microsoft C.  */
/* This used to test MSDOS, but that is a bad idea
   since that symbol is in the user namespace.  */
#if (defined (_MSDOS) || defined (_MSDOS_)) && !defined (__TURBOC__)
#if 0 /* No need for malloc.h, which pollutes the namespace;
	 instead, just don't use alloca.  */
#include <stdlib.h>
#endif
#else /* not MSDOS, or __TURBOC__ */
#if defined(_AIX)
/* I don't know what this was needed for, but it pollutes the namespace.
   So I turned it off.   rms, 2 May 1997.  */
/* #include <stdlib.h>  */
 #pragma alloca
#define YYSTACK_USE_ALLOCA
#else /* not MSDOS, or __TURBOC__, or _AIX */
#if 0
#ifdef __hpux /* haible@ilog.fr says this works for HPUX 9.05 and up,
		 and on HPUX 10.  Eventually we can turn this on.  */
#define YYSTACK_USE_ALLOCA
#define alloca __builtin_alloca
#endif /* __hpux */
#endif
#endif /* not _AIX */
#endif /* not MSDOS, or __TURBOC__ */
#endif /* not sparc */
#endif /* not GNU C */
#endif /* alloca not defined */
#endif /* YYSTACK_USE_ALLOCA not defined */

#ifdef YYSTACK_USE_ALLOCA
#define YYSTACK_ALLOC alloca
#else
#define YYSTACK_ALLOC malloc
#endif

/* Note: there must be only one dollar sign in this file.
   It is replaced by the list of actions, each action
   as one case of the switch.  */

#define vslerrok		(vslerrstatus = 0)
#define vslclearin	(vslchar = YYEMPTY)
#define YYEMPTY		-2
#define YYEOF		0
#define YYACCEPT	goto vslacceptlab
#define YYABORT 	goto vslabortlab
#define YYERROR		goto vslerrlab1
/* Like YYERROR except do call vslerror.
   This remains here temporarily to ease the
   transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */
#define YYFAIL		goto vslerrlab
#define YYRECOVERING()  (!!vslerrstatus)
#define YYBACKUP(token, value) \
do								\
  if (vslchar == YYEMPTY && vsllen == 1)				\
    { vslchar = (token), vsllval = (value);			\
      vslchar1 = YYTRANSLATE (vslchar);				\
      YYPOPSTACK;						\
      goto vslbackup;						\
    }								\
  else								\
    { vslerror ("syntax error: cannot back up"); YYERROR; }	\
while (0)

#define YYTERROR	1
#define YYERRCODE	256

// This deletes the "kill" array upon destruction.
// Will be used as automatic variable in vslparse().
// Added by $RCSfile: yacctoC.bison,v $
struct YYMEMHANDLER {
    YYSTYPE *kill;

    YYMEMHANDLER():
	kill(0)
    {}
    ~YYMEMHANDLER()
    {
	if (kill != 0)
    	delete[] kill;
        kill = 0;
    }
};


#ifndef YYPURE
#define YYLEX		vsllex()
#endif

#ifdef YYPURE
#ifdef YYLSP_NEEDED
#ifdef YYLEX_PARAM
#define YYLEX		vsllex(&vsllval, &vsllloc, YYLEX_PARAM)
#else
#define YYLEX		vsllex(&vsllval, &vsllloc)
#endif
#else /* not YYLSP_NEEDED */
#ifdef YYLEX_PARAM
#define YYLEX		vsllex(&vsllval, YYLEX_PARAM)
#else
#define YYLEX		vsllex(&vsllval)
#endif
#endif /* not YYLSP_NEEDED */
#endif

/* If nonreentrant, generate the variables here */

#ifndef YYPURE

int	vslchar;			/*  the lookahead symbol		*/
YYSTYPE	vsllval;			/*  the semantic value of the		*/
				/*  lookahead symbol			*/

#ifdef YYLSP_NEEDED
YYLTYPE vsllloc;			/*  location data for the lookahead	*/
				/*  symbol				*/
#endif

int vslnerrs;			/*  number of parse errors so far       */
#endif  /* not YYPURE */

#if YYDEBUG != 0
int vsldebug;			/*  nonzero means print parse trace	*/
/* Since this is uninitialized, it does not stop multiple parsers
   from coexisting.  */
#endif

/*  YYINITDEPTH indicates the initial size of the parser's stacks	*/

#ifndef	YYINITDEPTH
#define YYINITDEPTH 200
#endif

/*  YYMAXDEPTH is the maximum size the stacks can grow to
    (effective only if the built-in stack extension method is used).  */

#if YYMAXDEPTH == 0
#undef YYMAXDEPTH
#endif

#ifndef YYMAXDEPTH
#define YYMAXDEPTH 10000
#endif

/* Define __vsl_memcpy.  Note that the size argument
   should be passed with type unsigned int, because that is what the non-GCC
   definitions require.  With GCC, __builtin_memcpy takes an arg
   of type size_t, but it can handle unsigned int.  */

#if __GNUC__ > 1		/* GNU C and GNU C++ define this.  */
#define __vsl_memcpy(TO,FROM,COUNT)	__builtin_memcpy(TO,FROM,COUNT)
#else				/* not GNU C or C++ */
#ifndef __cplusplus

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__vsl_memcpy (to, from, count)
     char *to;
     char *from;
     unsigned int count;
{
  register char *f = from;
  register char *t = to;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#else /* __cplusplus */

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__vsl_memcpy (char *to, char *from, unsigned int count)
{
  register char *t = to;
  register char *f = from;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#endif
#endif

#line 216 "/usr/lib/bison.simple"

/* The user can define YYPARSE_PARAM as the name of an argument to be passed
   into vslparse.  The argument should have type void *.
   It should actually point to an object.
   Grammar actions can access the variable by casting it
   to the proper pointer type.  */

#ifdef YYPARSE_PARAM
#ifdef __cplusplus
#define YYPARSE_PARAM_ARG void *YYPARSE_PARAM
#define YYPARSE_PARAM_DECL
#else /* not __cplusplus */
#define YYPARSE_PARAM_ARG YYPARSE_PARAM
#define YYPARSE_PARAM_DECL void *YYPARSE_PARAM;
#endif /* not __cplusplus */
#else /* not YYPARSE_PARAM */
#define YYPARSE_PARAM_ARG
#define YYPARSE_PARAM_DECL
#endif /* not YYPARSE_PARAM */

/* Prevent warning if -Wstrict-prototypes.  */
#ifdef __GNUC__
#ifdef YYPARSE_PARAM
int vslparse (void *);
#else
int vslparse (void);
#endif
#endif

int
vslparse(YYPARSE_PARAM_ARG)
     YYPARSE_PARAM_DECL
{
  register int vslstate;
  register int vsln;
  register short *vslssp;
  register YYSTYPE *vslvsp;
  int vslerrstatus;	/*  number of tokens to shift before error messages enabled */
  int vslchar1 = 0;		/*  lookahead token as an internal (translated) token number */

  short	vslssa[YYINITDEPTH];	/*  the state stack			*/
  YYSTYPE vslvsa[YYINITDEPTH];	/*  the semantic value stack		*/

  short *vslss = vslssa;		/*  refer to the stacks thru separate pointers */
  YYSTYPE *vslvs = vslvsa;	/*  to allow vsloverflow to reallocate them elsewhere */

#ifdef YYLSP_NEEDED
  YYLTYPE vsllsa[YYINITDEPTH];	/*  the location stack			*/
  YYLTYPE *vslls = vsllsa;
  YYLTYPE *vsllsp;

#define YYPOPSTACK   (vslvsp--, vslssp--, vsllsp--)
#else
#define YYPOPSTACK   (vslvsp--, vslssp--)
#endif

  int vslstacksize = YYINITDEPTH;
  YYMEMHANDLER vslmem; // Added by $RCSfile: yacctoC.bison,v $
  int vslfree_stacks = 0;

#ifdef YYPURE
  int vslchar;
  YYSTYPE vsllval;
  int vslnerrs;
#ifdef YYLSP_NEEDED
  YYLTYPE vsllloc;
#endif
#endif

  YYSTYPE vslval;		/*  the variable used to return		*/
				/*  semantic values from the action	*/
				/*  routines				*/

  int vsllen;

#if YYDEBUG != 0
  if (vsldebug)
    fprintf(stderr, "Starting parse\n");
#endif

  vslstate = 0;
  vslerrstatus = 0;
  vslnerrs = 0;
  vslchar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  vslssp = vslss - 1;
  vslvsp = vslvs;
#ifdef YYLSP_NEEDED
  vsllsp = vslls;
#endif

/* Push a new state, which is found in  vslstate  .  */
/* In all cases, when you get here, the value and location stacks
   have just been pushed. so pushing a state here evens the stacks.  */
vslnewstate:

  *++vslssp = vslstate;

  if (vslssp >= vslss + vslstacksize - 1)
    {
      /* Give user a chance to reallocate the stack */
      /* Use copies of these so that the &'s don't force the real ones into memory. */
      YYSTYPE *vslvs1 = vslvs;
      short *vslss1 = vslss;
#ifdef YYLSP_NEEDED
      YYLTYPE *vslls1 = vslls;
#endif

      /* Get the current used size of the three stacks, in elements.  */
      int size = vslssp - vslss + 1;

#ifdef vsloverflow
      /* Each stack pointer address is followed by the size of
	 the data in use in that stack, in bytes.  */
#ifdef YYLSP_NEEDED
      /* This used to be a conditional around just the two extra args,
	 but that might be undefined if vsloverflow is a macro.  */
      vsloverflow("parser stack overflow",
		 &vslss1, size * sizeof (*vslssp),
		 &vslvs1, size * sizeof (*vslvsp),
		 &vslls1, size * sizeof (*vsllsp),
		 &vslstacksize);
#else
      vsloverflow("parser stack overflow",
		 &vslss1, size * sizeof (*vslssp),
		 &vslvs1, size * sizeof (*vslvsp),
		 &vslstacksize);
#endif

      vslss = vslss1; vslvs = vslvs1;
#ifdef YYLSP_NEEDED
      vslls = vslls1;
#endif
#else /* no vsloverflow */
      /* Extend the stack our own way.  */
      if (vslstacksize >= YYMAXDEPTH)
	{
	  vslerror("parser stack overflow");
	  if (vslfree_stacks)
	    {
	      delete [] vslss;
	      delete [] vslvs;
#ifdef YYLSP_NEEDED
	      delete [] vslls;
#endif
	    }
	  return 2;
	}
      vslstacksize *= 2;
      if (vslstacksize > YYMAXDEPTH)
	vslstacksize = YYMAXDEPTH;
#ifndef YYSTACK_USE_ALLOCA
      vslfree_stacks = 1;
#endif
      vslss = (short *) YYSTACK_ALLOC (vslstacksize * sizeof (*vslssp));
      __vsl_memcpy ((char *)vslss, (char *)vslss1,
		   size * (unsigned int) sizeof (*vslssp));

      // Added by $RCSfile: yacctoC.bison,v $. 
      YYSTYPE *new_vslvs = new YYSTYPE [vslstacksize];
      if (new_vslvs == 0)
      {
          vslerror("parser stack overflow");
          return 2;
      }
      for (int vslcopy = 0; vslcopy < vslstacksize; vslcopy++)
      {
          new_vslvs[vslcopy] = vslvs[vslcopy];
      }
      delete[] vslvs; vslvs = new_vslvs;
      vslmem.kill = vslvs; // make sure vslvs is deleted upon return 

#ifdef YYLSP_NEEDED
      vslls = (YYLTYPE *) YYSTACK_ALLOC (vslstacksize * sizeof (*vsllsp));
      __vsl_memcpy ((char *)vslls, (char *)vslls1,
		   size * (unsigned int) sizeof (*vsllsp));
#endif
#endif /* no vsloverflow */

      vslssp = vslss + size - 1;
      vslvsp = vslvs + size - 1;
#ifdef YYLSP_NEEDED
      vsllsp = vslls + size - 1;
#endif

#if YYDEBUG != 0
      if (vsldebug)
	fprintf(stderr, "Stack size increased to %d\n", vslstacksize);
#endif

      if (vslssp >= vslss + vslstacksize - 1)
	YYABORT;
    }

#if YYDEBUG != 0
  if (vsldebug)
    fprintf(stderr, "Entering state %d\n", vslstate);
#endif

  goto vslbackup;
 vslbackup:

/* Do appropriate processing given the current state.  */
/* Read a lookahead token if we need one and don't already have one.  */
/* vslresume: */

  /* First try to decide what to do without reference to lookahead token.  */

  vsln = vslpact[vslstate];
  if (vsln == YYFLAG)
    goto vsldefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* vslchar is either YYEMPTY or YYEOF
     or a valid token in external form.  */

  if (vslchar == YYEMPTY)
    {
#if YYDEBUG != 0
      if (vsldebug)
	fprintf(stderr, "Reading a token: ");
#endif
      vslchar = YYLEX;
    }

  /* Convert token to internal form (in vslchar1) for indexing tables with */

  if (vslchar <= 0)		/* This means end of input. */
    {
      vslchar1 = 0;
      vslchar = YYEOF;		/* Don't call YYLEX any more */

#if YYDEBUG != 0
      if (vsldebug)
	fprintf(stderr, "Now at end of input.\n");
#endif
    }
  else
    {
      vslchar1 = YYTRANSLATE(vslchar);

#if YYDEBUG != 0
      if (vsldebug)
	{
	  fprintf (stderr, "Next token is %d (%s", vslchar, vsltname[vslchar1]);
	  /* Give the individual parser a way to print the precise meaning
	     of a token, for further debugging info.  */
#ifdef YYPRINT
	  YYPRINT (stderr, vslchar, vsllval);
#endif
	  fprintf (stderr, ")\n");
	}
#endif
    }

  vsln += vslchar1;
  if (vsln < 0 || vsln > YYLAST || vslcheck[vsln] != vslchar1)
    goto vsldefault;

  vsln = vsltable[vsln];

  /* vsln is what to do for this token type in this state.
     Negative => reduce, -vsln is rule number.
     Positive => shift, vsln is new state.
       New state is final state => don't bother to shift,
       just return success.
     0, or most negative number => error.  */

  if (vsln < 0)
    {
      if (vsln == YYFLAG)
	goto vslerrlab;
      vsln = -vsln;
      goto vslreduce;
    }
  else if (vsln == 0)
    goto vslerrlab;

  if (vsln == YYFINAL)
    YYACCEPT;

  /* Shift the lookahead token.  */

#if YYDEBUG != 0
  if (vsldebug)
    fprintf(stderr, "Shifting token %d (%s), ", vslchar, vsltname[vslchar1]);
#endif

  /* Discard the token being shifted unless it is eof.  */
  if (vslchar != YYEOF)
    vslchar = YYEMPTY;

  *++vslvsp = vsllval;
#ifdef YYLSP_NEEDED
  *++vsllsp = vsllloc;
#endif

  /* count tokens shifted since error; after three, turn off error status.  */
  if (vslerrstatus) vslerrstatus--;

  vslstate = vsln;
  goto vslnewstate;

/* Do the default action for the current state.  */
vsldefault:

  vsln = vsldefact[vslstate];
  if (vsln == 0)
    goto vslerrlab;

/* Do a reduction.  vsln is the number of a rule to reduce with.  */
vslreduce:
  vsllen = vslr2[vsln];
  if (vsllen > 0)
    vslval = vslvsp[1-vsllen]; /* implement default value of the action */

#if YYDEBUG != 0
  if (vsldebug)
    {
      int i;

      fprintf (stderr, "Reducing via rule %d (line %d), ",
	       vsln, vslrline[vsln]);

      /* Print the symbols being reduced, and their result.  */
      for (i = vslprhs[vsln]; vslrhs[i] > 0; i++)
	fprintf (stderr, "%s ", vsltname[vslrhs[i]]);
      fprintf (stderr, " -> %s\n", vsltname[vslr1[vsln]]);
    }
#endif


  switch (vsln) {

case 10:
#line 188 "./vsl-gramma.Y"
{
				    ASSERT(vslvsp[0].function_header.pattern == 0 || 
					   vslvsp[0].function_header.pattern->OK());

				    if (vslvsp[0].function_header.pattern)
				    {
					vsllib->add(*vslvsp[0].function_header.id,
						    vslvsp[0].function_header.pattern, 0, False,
						    *vslvsp[0].function_header.file, vslvsp[0].function_header.line);
				    }
				    delete vslvsp[0].function_header.id;
				    delete vslvsp[0].function_header.file;
				;
    break;}
case 11:
#line 203 "./vsl-gramma.Y"
{
				    ASSERT(vslvsp[-1].str->OK());
				    ASSERT(vslvsp[0].node == 0 || vslvsp[0].node->OK());

				    vslval.function_header.id      = vslvsp[-1].str;
				    vslval.function_header.pattern = vslvsp[0].node;
				    vslval.function_header.file    = new string(vslfilename);
				    vslval.function_header.line    = vsllinenumber;
				;
    break;}
case 12:
#line 213 "./vsl-gramma.Y"
{
				    ASSERT(vslvsp[0].str->OK());

				    vslval.function_header.id      = new string("#" + *vslvsp[0].str);
				    vslval.function_header.pattern = new EmptyListNode;
				    vslval.function_header.file    = new string(vslfilename);
				    vslval.function_header.line    = vsllinenumber;

				    delete vslvsp[0].str;
				;
    break;}
case 13:
#line 225 "./vsl-gramma.Y"
{ vslval.str = vslvsp[0].str; ;
    break;}
case 14:
#line 227 "./vsl-gramma.Y"
{ vslval.str = new string("(=)"); ;
    break;}
case 15:
#line 229 "./vsl-gramma.Y"
{ vslval.str = new string("(<>)"); ;
    break;}
case 16:
#line 231 "./vsl-gramma.Y"
{ vslval.str = new string("(>)"); ;
    break;}
case 17:
#line 233 "./vsl-gramma.Y"
{ vslval.str = new string("(>=)"); ;
    break;}
case 18:
#line 235 "./vsl-gramma.Y"
{ vslval.str = new string("(<)"); ;
    break;}
case 19:
#line 237 "./vsl-gramma.Y"
{ vslval.str = new string("(<=)"); ;
    break;}
case 20:
#line 239 "./vsl-gramma.Y"
{ vslval.str = new string("(&)"); ;
    break;}
case 21:
#line 241 "./vsl-gramma.Y"
{ vslval.str = new string("(|)"); ;
    break;}
case 22:
#line 243 "./vsl-gramma.Y"
{ vslval.str = new string("(^)"); ;
    break;}
case 23:
#line 245 "./vsl-gramma.Y"
{ vslval.str = new string("(~)"); ;
    break;}
case 24:
#line 247 "./vsl-gramma.Y"
{ vslval.str = new string("(+)"); ;
    break;}
case 25:
#line 249 "./vsl-gramma.Y"
{ vslval.str = new string("(-)"); ;
    break;}
case 26:
#line 251 "./vsl-gramma.Y"
{ vslval.str = new string("(*)"); ;
    break;}
case 27:
#line 253 "./vsl-gramma.Y"
{ vslval.str = new string("(/)"); ;
    break;}
case 28:
#line 255 "./vsl-gramma.Y"
{ vslval.str = new string("(%)"); ;
    break;}
case 29:
#line 257 "./vsl-gramma.Y"
{ vslval.str = new string("(::)"); ;
    break;}
case 30:
#line 259 "./vsl-gramma.Y"
{ vslval.str = new string("(not)"); ;
    break;}
case 31:
#line 262 "./vsl-gramma.Y"
{ vslval.str = new string((char *)vsltext); ;
    break;}
case 34:
#line 268 "./vsl-gramma.Y"
{ 
				    ASSERT(vslvsp[-1].function_header.pattern == 0 || 
					   vslvsp[-1].function_header.pattern->OK());
				    ASSERT(vslvsp[0].node == 0 || vslvsp[0].node->OK());

				    if (vslvsp[-1].function_header.pattern)
				    {
					// Define function
					vsllib->add(*vslvsp[-1].function_header.id,
						    vslvsp[-1].function_header.pattern, vslvsp[0].node, False,
						    *vslvsp[-1].function_header.file, vslvsp[-1].function_header.line);
				    }

				    delete vslvsp[-1].function_header.id;
				    delete vslvsp[-1].function_header.file;
				;
    break;}
case 35:
#line 286 "./vsl-gramma.Y"
{
				    ASSERT(vslvsp[-1].function_header.pattern == 0 || 
					   vslvsp[-1].function_header.pattern->OK());

				    if (vslvsp[-1].function_header.pattern)
				    {
					// Declare function now
					// (for recursive calls)
					vsllib->add(*vslvsp[-1].function_header.id,
						    vslvsp[-1].function_header.pattern->dup(), 0, 
						    False,
						    vslfilename, 
						    vsllinenumber);
				    }

				    vslval.function_header = vslvsp[-1].function_header;
				;
    break;}
case 36:
#line 305 "./vsl-gramma.Y"
{ 
				    ASSERT(vslvsp[-1].function_header.pattern == 0 || 
					   vslvsp[-1].function_header.pattern->OK());
				    ASSERT(vslvsp[0].node == 0 || vslvsp[0].node->OK());

				    if (vslvsp[-1].function_header.pattern)
				    {
					// Define function
					vsllib->add(*vslvsp[-1].function_header.id, 
						    vslvsp[-1].function_header.pattern, vslvsp[0].node, True,
						    *vslvsp[-1].function_header.file, vslvsp[-1].function_header.line);
				    }

				    delete vslvsp[-1].function_header.id;
				    delete vslvsp[-1].function_header.file;
				;
    break;}
case 37:
#line 323 "./vsl-gramma.Y"
{
				  if (vslvsp[-1].function_header.pattern)
				  {
				      ASSERT(vslvsp[-1].function_header.pattern->OK());

				      // Declare function now
				      // (for recursive calls)
				      vsllib->add(*vslvsp[-1].function_header.id,
						  vslvsp[-1].function_header.pattern->dup(), 0, True,
						  vslfilename, vsllinenumber);
				  }
				  vslval.function_header = vslvsp[-1].function_header;
				;
    break;}
case 38:
#line 338 "./vsl-gramma.Y"
{ vslval.node = vslvsp[0].node; ;
    break;}
case 39:
#line 347 "./vsl-gramma.Y"
{
				    vslval.node = vslvsp[0].node;
				;
    break;}
case 40:
#line 351 "./vsl-gramma.Y"
{ 
				    ASSERT(vslvsp[-1].var_definition.pattern == 0 || 
					   vslvsp[-1].var_definition.pattern->OK());
				    ASSERT(vslvsp[-1].var_definition.args == 0 || 
					   vslvsp[-1].var_definition.args->OK());
				    ASSERT(vslvsp[0].node == 0 || vslvsp[0].node->OK());

				    vslval.node = (vslvsp[-1].var_definition.pattern && vslvsp[-1].var_definition.args && vslvsp[0].node) ?
					new LetNode(vslvsp[-1].var_definition.pattern, vslvsp[-1].var_definition.args, vslvsp[0].node) :
					0;
				    ASSERT(vslval.node == 0 || vslval.node->OK());
				;
    break;}
case 41:
#line 365 "./vsl-gramma.Y"
{
				    vslval.node = vslvsp[0].node;
				;
    break;}
case 42:
#line 369 "./vsl-gramma.Y"
{ 
				    ASSERT(vslvsp[-1].var_definition.pattern == 0 || 
					   vslvsp[-1].var_definition.pattern->OK());
				    ASSERT(vslvsp[-1].var_definition.args == 0 || 
					   vslvsp[-1].var_definition.args->OK());
				    ASSERT(vslvsp[0].node == 0 || vslvsp[0].node->OK());

				    vslval.node = (vslvsp[-1].var_definition.pattern && vslvsp[-1].var_definition.args && vslvsp[0].node) ?
					new LetNode(vslvsp[-1].var_definition.pattern, vslvsp[-1].var_definition.args, vslvsp[0].node) :
					0;

				    ASSERT(vslval.node == 0 || vslval.node->OK());
				;
    break;}
case 43:
#line 384 "./vsl-gramma.Y"
{ vslval.node = vslvsp[0].node; ;
    break;}
case 44:
#line 386 "./vsl-gramma.Y"
{ vslval.node = vslvsp[0].node; ;
    break;}
case 45:
#line 390 "./vsl-gramma.Y"
{
				    ASSERT(vslvsp[-2].node == 0 || vslvsp[-2].node->OK());
				    ASSERT(vslvsp[0].var_definition.pattern == 0 || 
					   vslvsp[0].var_definition.pattern->OK());
				    ASSERT(vslvsp[0].var_definition.args == 0 || 
					   vslvsp[0].var_definition.args->OK());

				    vslval.node = (vslvsp[0].var_definition.pattern && vslvsp[0].var_definition.args && vslvsp[-2].node) ?
					new WhereNode(vslvsp[0].var_definition.pattern, vslvsp[0].var_definition.args, vslvsp[-2].node):
					0;
				    ASSERT(vslval.node == 0 || vslval.node->OK());
				;
    break;}
case 46:
#line 404 "./vsl-gramma.Y"
{
				    ASSERT(vslvsp[-2].node == 0 || vslvsp[-2].node->OK());
				    ASSERT(vslvsp[0].var_definition.pattern == 0 || 
					   vslvsp[0].var_definition.pattern->OK());
				    ASSERT(vslvsp[0].var_definition.args == 0 || 
					   vslvsp[0].var_definition.args->OK());

				    vslval.node = (vslvsp[0].var_definition.pattern && vslvsp[0].var_definition.args && vslvsp[-2].node) ?
					new WhereNode(vslvsp[0].var_definition.pattern, vslvsp[0].var_definition.args, vslvsp[-2].node):
					0;

				    ASSERT(vslval.node == 0 || vslval.node->OK());
				;
    break;}
case 47:
#line 419 "./vsl-gramma.Y"
{
				    ASSERT(vslvsp[-2].node == 0 || vslvsp[-2].node->OK());
				    ASSERT(vslvsp[0].node == 0 || vslvsp[0].node->OK());

				    vslval.var_definition.pattern = vslvsp[-2].node;
				    vslval.var_definition.args    = vslvsp[0].node;
				;
    break;}
case 48:
#line 431 "./vsl-gramma.Y"
{ vslval.node = vslvsp[-1].node; ;
    break;}
case 49:
#line 433 "./vsl-gramma.Y"
{ vslval.node = vslvsp[0].node; ;
    break;}
case 50:
#line 435 "./vsl-gramma.Y"
{ vslval.node = vslvsp[0].node; ;
    break;}
case 51:
#line 437 "./vsl-gramma.Y"
{ vslval.node = vslvsp[0].node; ;
    break;}
case 52:
#line 439 "./vsl-gramma.Y"
{ vslval.node = vslvsp[0].node; ;
    break;}
case 53:
#line 441 "./vsl-gramma.Y"
{ vslval.node = vslvsp[0].node; ;
    break;}
case 54:
#line 443 "./vsl-gramma.Y"
{ vslval.node = vslvsp[0].node; ;
    break;}
case 55:
#line 445 "./vsl-gramma.Y"
{ vslval.node = vslvsp[0].node; ;
    break;}
case 56:
#line 448 "./vsl-gramma.Y"
{
				    vslval.node = new EmptyListNode;
				    ASSERT(vslval.node->OK());
				;
    break;}
case 57:
#line 453 "./vsl-gramma.Y"
{
				    vslval.node = vslvsp[-1].node;
				    ASSERT(vslval.node == 0 || vslval.node->OK());
				;
    break;}
case 58:
#line 458 "./vsl-gramma.Y"
{
				    vslval.node = new EmptyListNode;
				    ASSERT(vslval.node->OK());
				;
    break;}
case 59:
#line 463 "./vsl-gramma.Y"
{
				    vslval.node = vslvsp[-1].node;
				    ASSERT(vslval.node == 0 || vslval.node->OK());
				;
    break;}
case 60:
#line 469 "./vsl-gramma.Y"
{ 
				    ASSERT(vslvsp[0].node == 0 || vslvsp[0].node->OK());

				    vslval.node = (vslvsp[0].node) ? new FixListNode(vslvsp[0].node) : 0;
				    ASSERT(vslval.node == 0 || vslval.node->OK());
				;
    break;}
case 61:
#line 476 "./vsl-gramma.Y"
{ 
				    vslval.node = vslvsp[0].node; 
				;
    break;}
case 62:
#line 481 "./vsl-gramma.Y"
{ 
				    ASSERT(vslvsp[-2].node == 0 || vslvsp[-2].node->OK());
				    ASSERT(vslvsp[0].node == 0 || vslvsp[0].node->OK());

				    vslval.node = (vslvsp[-2].node && vslvsp[0].node) ? new ListNode(vslvsp[-2].node, vslvsp[0].node) : 0;
				    ASSERT(vslval.node == 0 || vslval.node->OK());
				;
    break;}
case 63:
#line 489 "./vsl-gramma.Y"
{
				    ASSERT(vslvsp[-2].node == 0 || vslvsp[-2].node->OK());
				    ASSERT(vslvsp[0].node == 0 || vslvsp[0].node->OK());

				    vslval.node = (vslvsp[-2].node && vslvsp[0].node) ? new ListNode(vslvsp[-2].node, vslvsp[0].node) : 0;
				    ASSERT(vslval.node == 0 || vslval.node->OK());
				;
    break;}
case 64:
#line 497 "./vsl-gramma.Y"
{ 
				    vslval.node = vslvsp[-1].node; 
				;
    break;}
case 65:
#line 501 "./vsl-gramma.Y"
{
				    vslval.node = new NameNode("...");
				    ASSERT(vslval.node == 0 || vslval.node->OK());
				;
    break;}
case 66:
#line 507 "./vsl-gramma.Y"
{ 
				    ASSERT(vslvsp[0].str->OK());

				    // Bug workaround
				    char *buf = (char *)*vslvsp[0].str;
				    string name = buf;
				    vslval.node = new StringNode(name);
				    delete vslvsp[0].str;

				    ASSERT(vslval.node->OK());
				;
    break;}
case 67:
#line 519 "./vsl-gramma.Y"
{ 
				    vslval.node = new NumNode(vslvsp[0].num);
				    ASSERT(vslval.node->OK());
				;
    break;}
case 68:
#line 525 "./vsl-gramma.Y"
{
				    vslval.str = new string(unquote((char *)vsltext));
				    ASSERT(vslval.str->OK());
				;
    break;}
case 69:
#line 530 "./vsl-gramma.Y"
{ 
				    ASSERT(vslvsp[-1].str->OK());

				    vslval.str = vslvsp[-1].str;
				    *vslval.str += unquote((char *)vsltext);

				    ASSERT(vslval.str->OK());
				;
    break;}
case 70:
#line 540 "./vsl-gramma.Y"
{
				    vslval.num = atoi((char *)vsltext);
				;
    break;}
case 71:
#line 545 "./vsl-gramma.Y"
{
				    ASSERT(vslvsp[-1].str->OK());
				    ASSERT(vslvsp[0].node == 0 || vslvsp[0].node->OK());

				    vslval.node = (vslvsp[0].node) ? 
					vsllib->_call(*vslvsp[-1].str, vslvsp[0].node) : 0;
				    ASSERT(vslval.node == 0 || vslval.node->OK());
				;
    break;}
case 72:
#line 555 "./vsl-gramma.Y"
{
				    ASSERT(vslvsp[0].node == 0 || vslvsp[0].node->OK());
				    vslval.node = vsllib->call("(not)", vslvsp[0].node);
				    ASSERT(vslval.node == 0 || vslval.node->OK());
				;
    break;}
case 73:
#line 561 "./vsl-gramma.Y"
{
				    vslval.node = vslvsp[0].node;
				;
    break;}
case 74:
#line 565 "./vsl-gramma.Y"
{
				    // Simulate `-X' by `0-X'
				    ASSERT(vslvsp[0].node == 0 || vslvsp[0].node->OK());
				    vslval.node = (vslvsp[0].node) ? 
					vsllib->call("(-)", new NullNode, vslvsp[0].node) :
					0;
				    ASSERT(vslval.node == 0 || vslval.node->OK());
				;
    break;}
case 75:
#line 577 "./vsl-gramma.Y"
{ 
				    ASSERT(vslvsp[-2].node == 0 || vslvsp[-2].node->OK());
				    ASSERT(vslvsp[0].node == 0 || vslvsp[0].node->OK());
				    vslval.node = vsllib->call("(=)", vslvsp[-2].node, vslvsp[0].node); 
				    ASSERT(vslval.node == 0 || vslval.node->OK());
				;
    break;}
case 76:
#line 584 "./vsl-gramma.Y"
{ 
				    ASSERT(vslvsp[-2].node == 0 || vslvsp[-2].node->OK());
				    ASSERT(vslvsp[0].node == 0 || vslvsp[0].node->OK());
				    vslval.node = vsllib->call("(<>)", vslvsp[-2].node, vslvsp[0].node); 
				    ASSERT(vslval.node == 0 || vslval.node->OK());
				;
    break;}
case 77:
#line 591 "./vsl-gramma.Y"
{ 
				    ASSERT(vslvsp[-2].node == 0 || vslvsp[-2].node->OK());
				    ASSERT(vslvsp[0].node == 0 || vslvsp[0].node->OK());
				    vslval.node = vsllib->call("(>)", vslvsp[-2].node, vslvsp[0].node); 
				    ASSERT(vslval.node == 0 || vslval.node->OK());
				;
    break;}
case 78:
#line 598 "./vsl-gramma.Y"
{ 
				    ASSERT(vslvsp[-2].node == 0 || vslvsp[-2].node->OK());
				    ASSERT(vslvsp[0].node == 0 || vslvsp[0].node->OK());
				    vslval.node = vsllib->call("(>=)", vslvsp[-2].node, vslvsp[0].node); 
				    ASSERT(vslval.node == 0 || vslval.node->OK());
				;
    break;}
case 79:
#line 605 "./vsl-gramma.Y"
{ 
				    ASSERT(vslvsp[-2].node == 0 || vslvsp[-2].node->OK());
				    ASSERT(vslvsp[0].node == 0 || vslvsp[0].node->OK());
				    vslval.node = vsllib->call("(<)", vslvsp[-2].node, vslvsp[0].node); 
				    ASSERT(vslval.node == 0 || vslval.node->OK());
				;
    break;}
case 80:
#line 612 "./vsl-gramma.Y"
{ 
				    ASSERT(vslvsp[-2].node == 0 || vslvsp[-2].node->OK());
				    ASSERT(vslvsp[0].node == 0 || vslvsp[0].node->OK());
				    vslval.node = vsllib->call("(<=)", vslvsp[-2].node, vslvsp[0].node); 
				    ASSERT(vslval.node == 0 || vslval.node->OK());
				;
    break;}
case 81:
#line 619 "./vsl-gramma.Y"
{ 
				    ASSERT(vslvsp[-2].node == 0 || vslvsp[-2].node->OK());
				    ASSERT(vslvsp[0].node == 0 || vslvsp[0].node->OK());
				    vslval.node = vsllib->call("(&)", vslvsp[-2].node, vslvsp[0].node); 
				    ASSERT(vslval.node == 0 || vslval.node->OK());
				;
    break;}
case 82:
#line 626 "./vsl-gramma.Y"
{ 
				    ASSERT(vslvsp[-2].node == 0 || vslvsp[-2].node->OK());
				    ASSERT(vslvsp[0].node == 0 || vslvsp[0].node->OK());
				    vslval.node = vsllib->call("(|)", vslvsp[-2].node, vslvsp[0].node); 
				    ASSERT(vslval.node == 0 || vslval.node->OK());
				;
    break;}
case 83:
#line 633 "./vsl-gramma.Y"
{ 
				    ASSERT(vslvsp[-2].node == 0 || vslvsp[-2].node->OK());
				    ASSERT(vslvsp[0].node == 0 || vslvsp[0].node->OK());
				    vslval.node = vsllib->call("(^)", vslvsp[-2].node, vslvsp[0].node); 
				    ASSERT(vslval.node == 0 || vslval.node->OK());
				;
    break;}
case 84:
#line 640 "./vsl-gramma.Y"
{ 
				    ASSERT(vslvsp[-2].node == 0 || vslvsp[-2].node->OK());
				    ASSERT(vslvsp[0].node == 0 || vslvsp[0].node->OK());
				    vslval.node = vsllib->call("(~)", vslvsp[-2].node, vslvsp[0].node); 
				    ASSERT(vslval.node == 0 || vslval.node->OK());
				;
    break;}
case 85:
#line 647 "./vsl-gramma.Y"
{ 
				    ASSERT(vslvsp[-2].node == 0 || vslvsp[-2].node->OK());
				    ASSERT(vslvsp[0].node == 0 || vslvsp[0].node->OK());
				    vslval.node = vsllib->call("(+)", vslvsp[-2].node, vslvsp[0].node); 
				    ASSERT(vslval.node == 0 || vslval.node->OK());
				;
    break;}
case 86:
#line 654 "./vsl-gramma.Y"
{ 
				    ASSERT(vslvsp[-2].node == 0 || vslvsp[-2].node->OK());
				    ASSERT(vslvsp[0].node == 0 || vslvsp[0].node->OK());
				    vslval.node = vsllib->call("(-)", vslvsp[-2].node, vslvsp[0].node); 
				    ASSERT(vslval.node == 0 || vslval.node->OK());
				;
    break;}
case 87:
#line 661 "./vsl-gramma.Y"
{ 
				    ASSERT(vslvsp[-2].node == 0 || vslvsp[-2].node->OK());
				    ASSERT(vslvsp[0].node == 0 || vslvsp[0].node->OK());
				    vslval.node = vsllib->call("(*)", vslvsp[-2].node, vslvsp[0].node); 
				    ASSERT(vslval.node == 0 || vslval.node->OK());
				;
    break;}
case 88:
#line 668 "./vsl-gramma.Y"
{ 
				    ASSERT(vslvsp[-2].node == 0 || vslvsp[-2].node->OK());
				    ASSERT(vslvsp[0].node == 0 || vslvsp[0].node->OK());
				    vslval.node = vsllib->call("(/)", vslvsp[-2].node, vslvsp[0].node); 
				    ASSERT(vslval.node == 0 || vslval.node->OK());
				;
    break;}
case 89:
#line 675 "./vsl-gramma.Y"
{ 
				    ASSERT(vslvsp[-2].node == 0 || vslvsp[-2].node->OK());
				    ASSERT(vslvsp[0].node == 0 || vslvsp[0].node->OK());
				    vslval.node = vsllib->call("(%)", vslvsp[-2].node, vslvsp[0].node); 
				    ASSERT(vslval.node == 0 || vslval.node->OK());
				;
    break;}
case 90:
#line 682 "./vsl-gramma.Y"
{ 
				    ASSERT(vslvsp[-2].node == 0 || vslvsp[-2].node->OK());
				    ASSERT(vslvsp[0].node == 0 || vslvsp[0].node->OK());
				    vslval.node = vsllib->call("(::)", vslvsp[-2].node, vslvsp[0].node); 
				    ASSERT(vslval.node == 0 || vslval.node->OK());
				;
    break;}
case 91:
#line 689 "./vsl-gramma.Y"
{ 
				    ASSERT(vslvsp[-2].node == 0 || vslvsp[-2].node->OK());
				    ASSERT(vslvsp[0].node == 0 || vslvsp[0].node->OK());
				    // If EXPR-1 then true else EXPR-2
				    vslval.node = (vslvsp[-2].node && vslvsp[0].node) ? 
					new TestNode(vslvsp[-2].node, new TrueNode, vslvsp[0].node) : 
					0;
				  ASSERT(vslval.node == 0 || vslval.node->OK());
				;
    break;}
case 92:
#line 699 "./vsl-gramma.Y"
{ 
				    ASSERT(vslvsp[-2].node == 0 || vslvsp[-2].node->OK());
				    ASSERT(vslvsp[0].node == 0 || vslvsp[0].node->OK());
				    // If EXPR-1 then EXPR-2 else false
				    vslval.node = (vslvsp[-2].node && vslvsp[0].node) ? 
					new TestNode(vslvsp[-2].node, vslvsp[0].node, new FalseNode) : 
					0;
				    ASSERT(vslval.node == 0 || vslval.node->OK());
				;
    break;}
case 93:
#line 713 "./vsl-gramma.Y"
{ 
				    ASSERT(vslvsp[-4].node == 0 || vslvsp[-4].node->OK());
				    ASSERT(vslvsp[-2].node == 0 || vslvsp[-2].node->OK());
				    ASSERT(vslvsp[-1].node == 0 || vslvsp[-1].node->OK());

				    vslval.node = (vslvsp[-4].node && vslvsp[-2].node && vslvsp[-1].node) ?
					new TestNode(vslvsp[-4].node, vslvsp[-2].node, vslvsp[-1].node) : 0;
				    ASSERT(vslval.node == 0 || vslval.node->OK());
				;
    break;}
case 94:
#line 726 "./vsl-gramma.Y"
{ 
				    ASSERT(vslvsp[-3].node == 0 || vslvsp[-3].node->OK());
				    ASSERT(vslvsp[-1].node == 0 || vslvsp[-1].node->OK());
				    ASSERT(vslvsp[0].node == 0 || vslvsp[0].node->OK());

				    vslval.node = (vslvsp[-3].node && vslvsp[-1].node && vslvsp[0].node) ?
					new TestNode(vslvsp[-3].node, vslvsp[-1].node, vslvsp[0].node) : 0;
				    ASSERT(vslval.node == 0 || vslval.node->OK());
				;
    break;}
case 95:
#line 736 "./vsl-gramma.Y"
{
				    vslval.node = vslvsp[0].node;
				;
    break;}
case 96:
#line 741 "./vsl-gramma.Y"
{
				    vslval.node = vslvsp[0].node;
				;
    break;}
case 97:
#line 745 "./vsl-gramma.Y"
{ 
				    ASSERT(vslvsp[-1].node == 0 || vslvsp[-1].node->OK());

				    vslval.node = (vslvsp[-1].node) ? new FixListNode(vslvsp[-1].node) : 0; 
				    ASSERT(vslval.node == 0 || vslval.node->OK());
				;
    break;}
case 98:
#line 753 "./vsl-gramma.Y"
{
				    ASSERT(vslvsp[0].str->OK());

				    if (*vslvsp[0].str == "_")
				    {
					vslval.node = new DummyNode;
				    }
				    else
				    {
					// If function is declared, use it;
					// otherwise create placeholder var
					
					if (vsllib->deflist("#" + *vslvsp[0].str))
					    vslval.node = vsllib->call("#" + *vslvsp[0].str);
					else
					    vslval.node = new NameNode(*vslvsp[0].str);
				    }

				    ASSERT(vslval.node->OK());
				    delete vslvsp[0].str;
				;
    break;}
case 102:
#line 784 "./vsl-gramma.Y"
{
				    ASSERT(vslvsp[0].str->OK());

				    string func_name = *vslvsp[0].str;
				    if (vsllib->override(func_name)
					&& vsllib->override("#" + func_name))
				    {
					VSLLib::parse_error("'" + func_name + 
							    "(...)'"
							    " undefined");
				    }
				;
    break;}
case 106:
#line 803 "./vsl-gramma.Y"
{
				    ASSERT(vslvsp[0].str->OK());

				    string func_name = *vslvsp[0].str;
				    if (vsllib->replace(func_name)
					&& vsllib->replace("#" + func_name))
				    {
					VSLLib::parse_error("'" + func_name + 
							    "(...)'"
							    " undefined");
				    }
				;
    break;}
}
   /* the action file gets copied in in place of this dollarsign */
#line 542 "/usr/lib/bison.simple"

  vslvsp -= vsllen;
  vslssp -= vsllen;
#ifdef YYLSP_NEEDED
  vsllsp -= vsllen;
#endif

#if YYDEBUG != 0
  if (vsldebug)
    {
      short *ssp1 = vslss - 1;
      fprintf (stderr, "state stack now");
      while (ssp1 != vslssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

  *++vslvsp = vslval;

#ifdef YYLSP_NEEDED
  vsllsp++;
  if (vsllen == 0)
    {
      vsllsp->first_line = vsllloc.first_line;
      vsllsp->first_column = vsllloc.first_column;
      vsllsp->last_line = (vsllsp-1)->last_line;
      vsllsp->last_column = (vsllsp-1)->last_column;
      vsllsp->text = 0;
    }
  else
    {
      vsllsp->last_line = (vsllsp+vsllen-1)->last_line;
      vsllsp->last_column = (vsllsp+vsllen-1)->last_column;
    }
#endif

  /* Now "shift" the result of the reduction.
     Determine what state that goes to,
     based on the state we popped back to
     and the rule number reduced by.  */

  vsln = vslr1[vsln];

  vslstate = vslpgoto[vsln - YYNTBASE] + *vslssp;
  if (vslstate >= 0 && vslstate <= YYLAST && vslcheck[vslstate] == *vslssp)
    vslstate = vsltable[vslstate];
  else
    vslstate = vsldefgoto[vsln - YYNTBASE];

  goto vslnewstate;

vslerrlab:   /* here on detecting error */

  if (! vslerrstatus)
    /* If not already recovering from an error, report this error.  */
    {
      ++vslnerrs;

#ifdef YYERROR_VERBOSE
      vsln = vslpact[vslstate];

      if (vsln > YYFLAG && vsln < YYLAST)
	{
	  int size = 0;
	  char *msg;
	  int x, count;

	  count = 0;
	  /* Start X at -vsln if nec to avoid negative indexes in vslcheck.  */
	  for (x = (vsln < 0 ? -vsln : 0);
	       x < (sizeof(vsltname) / sizeof(char *)); x++)
	    if (vslcheck[x + vsln] == x)
	      size += strlen(vsltname[x]) + 15, count++;
	  msg = new char [size + 15];
	  if (msg != 0)
	    {
	      strcpy(msg, "parse error");

	      if (count < 5)
		{
		  count = 0;
		  for (x = (vsln < 0 ? -vsln : 0);
		       x < (sizeof(vsltname) / sizeof(char *)); x++)
		    if (vslcheck[x + vsln] == x)
		      {
			strcat(msg, count == 0 ? ", expecting `" : " or `");
			strcat(msg, vsltname[x]);
			strcat(msg, "'");
			count++;
		      }
		}
	      vslerror(msg);
	      delete [] msg;
	    }
	  else
	    vslerror ("parse error; also virtual memory exceeded");
	}
      else
#endif /* YYERROR_VERBOSE */
	vslerror("parse error");
    }

  goto vslerrlab1;
vslerrlab1:   /* here on error raised explicitly by an action */

  if (vslerrstatus == 3)
    {
      /* if just tried and failed to reuse lookahead token after an error, discard it.  */

      /* return failure if at end of input */
      if (vslchar == YYEOF)
	YYABORT;

#if YYDEBUG != 0
      if (vsldebug)
	fprintf(stderr, "Discarding token %d (%s).\n", vslchar, vsltname[vslchar1]);
#endif

      vslchar = YYEMPTY;
    }

  /* Else will try to reuse lookahead token
     after shifting the error token.  */

  vslerrstatus = 3;		/* Each real token shifted decrements this */

  goto vslerrhandle;

vslerrdefault:  /* current state does not do anything special for the error token. */

#if 0
  /* This is wrong; only states that explicitly want error tokens
     should shift them.  */
  vsln = vsldefact[vslstate];  /* If its default is to accept any token, ok.  Otherwise pop it.*/
  if (vsln) goto vsldefault;
#endif

vslerrpop:   /* pop the current state because it cannot handle the error token */

  if (vslssp == vslss) YYABORT;
  vslvsp--;
  vslstate = *--vslssp;
#ifdef YYLSP_NEEDED
  vsllsp--;
#endif

#if YYDEBUG != 0
  if (vsldebug)
    {
      short *ssp1 = vslss - 1;
      fprintf (stderr, "Error: state stack now");
      while (ssp1 != vslssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

vslerrhandle:

  vsln = vslpact[vslstate];
  if (vsln == YYFLAG)
    goto vslerrdefault;

  vsln += YYTERROR;
  if (vsln < 0 || vsln > YYLAST || vslcheck[vsln] != YYTERROR)
    goto vslerrdefault;

  vsln = vsltable[vsln];
  if (vsln < 0)
    {
      if (vsln == YYFLAG)
	goto vslerrpop;
      vsln = -vsln;
      goto vslreduce;
    }
  else if (vsln == 0)
    goto vslerrpop;

  if (vsln == YYFINAL)
    YYACCEPT;

#if YYDEBUG != 0
  if (vsldebug)
    fprintf(stderr, "Shifting error token, ");
#endif

  *++vslvsp = vsllval;
#ifdef YYLSP_NEEDED
  *++vsllsp = vsllloc;
#endif

  vslstate = vsln;
  goto vslnewstate;

 vslacceptlab:
  /* YYACCEPT comes here.  */
  if (vslfree_stacks)
    {
      delete [] vslss;
      delete [] vslvs;
#ifdef YYLSP_NEEDED
      delete [] vslls;
#endif
    }
  return 0;

 vslabortlab:
  /* YYABORT comes here.  */
  if (vslfree_stacks)
    {
      delete [] vslss;
      delete [] vslvs;
#ifdef YYLSP_NEEDED
      delete [] vslls;
#endif
    }
  return 1;
}
#line 816 "./vsl-gramma.Y"
 /* DO NOT REMOVE THIS COMMENT -- MUNCH-YACC DEPENDS ON IT */
