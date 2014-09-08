/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_CEXP_CEXP_TAB_H_INCLUDED
# define YY_CEXP_CEXP_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int cexpdebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    NUMBER = 258,
    STR_CONST = 259,
    FUNC = 260,
    VAR = 261,
    UVAR = 262,
    IDENT = 263,
    KW_CHAR = 264,
    KW_SHORT = 265,
    KW_INT = 266,
    KW_LONG = 267,
    KW_FLOAT = 268,
    KW_DOUBLE = 269,
    MODOP = 270,
    REDIR = 271,
    REDIRBOTH = 272,
    REDIRAPPEND = 273,
    REDIRAPPENDBOTH = 274,
    NONE = 275,
    OR = 276,
    AND = 277,
    EQ = 278,
    NE = 279,
    LE = 280,
    GE = 281,
    SHL = 282,
    SHR = 283,
    CAST = 284,
    VARCAST = 285,
    DEREF = 286,
    ADDR = 287,
    PREFIX = 288,
    MM = 289,
    PP = 290,
    NEG = 291,
    CALL = 292
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 163 "cexp.y" /* yacc.c:1909  */

	CexpTypedValRec				val;
	CexpTypedAddrRec			lval;
	CexpTypedAddr				varp;
	CexpSym						sym;	/* a symbol table entry */
	CexpType					typ;
	CexpBinOp					binop;
	char						*lstr;	/* string in the line string table */
	struct			{
		CexpTypedAddrRec	lval;
		CexpBinOp			op;
	}							fixexp;
	struct			{
		CexpSym				sym;
		char				*mname;		/* string kept in the line string table */
	}							method;
	unsigned long				ul;
	char                        *chrp;

#line 112 "cexp.tab.h" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif



int cexpparse (CexpParserCtx ctx);

#endif /* !YY_CEXP_CEXP_TAB_H_INCLUDED  */
