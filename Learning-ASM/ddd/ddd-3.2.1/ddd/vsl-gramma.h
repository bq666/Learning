// This file was modified for -*- C++ -*-
// using $RCSfile: yacctoC.h,v $ $Revision: 1.8 $

typedef struct _IGNORED_YYSTYPE  {
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
} IGNORED_YYSTYPE;
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


extern IGNORED_YYSTYPE IGNORED_vsllval;
