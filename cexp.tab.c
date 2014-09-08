/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 1

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1


/* Substitute the variable and function names.  */
#define yyparse         cexpparse
#define yylex           cexplex
#define yyerror         cexperror
#define yydebug         cexpdebug
#define yynerrs         cexpnerrs


/* Copy the first part of user declarations.  */
#line 1 "cexp.y" /* yacc.c:339  */

/* $Id: cexp.y,v 1.53 2014/08/18 15:56:50 strauman Exp $ */
/* Grammar definition and lexical analyzer for Cexp */

/* SLAC Software Notices, Set 4 OTT.002a, 2004 FEB 03
 *
 * Authorship
 * ----------
 * This software (CEXP - C-expression interpreter and runtime
 * object loader/linker) was created by
 *
 *    Till Straumann <strauman@slac.stanford.edu>, 2002-2008,
 * 	  Stanford Linear Accelerator Center, Stanford University.
 *
 * Acknowledgement of sponsorship
 * ------------------------------
 * This software was produced by
 *     the Stanford Linear Accelerator Center, Stanford University,
 * 	   under Contract DE-AC03-76SFO0515 with the Department of Energy.
 * 
 * Government disclaimer of liability
 * ----------------------------------
 * Neither the United States nor the United States Department of Energy,
 * nor any of their employees, makes any warranty, express or implied, or
 * assumes any legal liability or responsibility for the accuracy,
 * completeness, or usefulness of any data, apparatus, product, or process
 * disclosed, or represents that its use would not infringe privately owned
 * rights.
 * 
 * Stanford disclaimer of liability
 * --------------------------------
 * Stanford University makes no representations or warranties, express or
 * implied, nor assumes any liability for the use of this software.
 * 
 * Stanford disclaimer of copyright
 * --------------------------------
 * Stanford University, owner of the copyright, hereby disclaims its
 * copyright and all other rights in this software.  Hence, anyone may
 * freely use it for any purpose without restriction.  
 * 
 * Maintenance of notices
 * ----------------------
 * In the interest of clarity regarding the origin and status of this
 * SLAC software, this and all the preceding Stanford University notices
 * are to remain affixed to any copy or derivative of this software made
 * or distributed by the recipient and are to be affixed to any copy of
 * software made or distributed by the recipient that contains a copy or
 * derivative of this software.
 * 
 * SLAC Software Notices, Set 4 OTT.002a, 2004 FEB 03
 */ 

#include <stdio.h>
#include <sys/errno.h>
#include <fcntl.h>
#include <assert.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "cexpsyms.h"
#include "cexpmod.h"
#include "vars.h"
#include <stdarg.h>

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

/* not letting them live makes not much sense */
#ifndef CONFIG_STRINGS_LIVE_FOREVER
#define CONFIG_STRINGS_LIVE_FOREVER
#endif

#define YYLEX_PARAM		ctx
#define YYERROR_VERBOSE

#define EVAL_INH	 ((ctx)->evalInhibit)
#define PSHEVAL(inh) do { EVAL_INH<<=1; if (inh) EVAL_INH++; } while(0)
#define POPEVAL      do { EVAL_INH>>=1; } while(0)
#define EVAL(stuff)  if (! EVAL_INH ) do { stuff; } while (0)

#define CHECK(cexpTfuncall) do { const char *e=(cexpTfuncall);\
					 if (e) { yyerror(ctx, e); YYERROR; } } while (0)

/* acceptable characters for identifiers - must not
 * overlap with operators
 */
#define ISIDENTCHAR(ch) ('_'==(ch) || '@'==(ch))

#define LEXERR	-1
/* ugly hack; helper for word completion */
#define LEXERR_INCOMPLETE_STRING	-100

       void yyerror(CexpParserCtx ctx, const char*msg);
static void errmsg(CexpParserCtx ctx, const char *msg, ...);
static void wrnmsg(CexpParserCtx ctx, const char *msg, ...);

int  yylex();

typedef char *LString;

struct CexpParserCtxRec_;

typedef void (*RedirCb)(struct CexpParserCtxRec_ *, void *);

typedef struct CexpParserCtxRec_ {
	const char		*chpt;
	LString			lineStrTbl[10];	/* allow for 10 strings on one line of input  */
	CexpSymRec		rval_sym;       /* return value and status of last evaluation */
	CexpValU		rval;
	int             status;         
	unsigned long	evalInhibit;
	FILE			*outf;			/* where to print evaluated value			  */
	FILE			*errf;			/* where to print error messages 			  */
	char            sbuf[1000];		/* scratch space for strings                  */
	FILE            *o_stdout;      /* redirection */
	FILE            *o_stderr;      /* redirection */
	FILE            *o_stdin;       /* redirection */
	FILE            *o_outf;
	FILE            *o_errf;
	RedirCb         redir_cb;
	void            *cb_arg;
} CexpParserCtxRec;

static CexpSym
varCreate(CexpParserCtx ctx, char *name, CexpType type)
{
CexpSym rval;
	if (!(rval=cexpVarLookup(name,1)/*allow creation*/)) {
		if ( ctx->errf )
			fprintf(ctx->errf, "unable to add new user variable");
		return 0;
	}
	rval->value.type = type;
	if (CEXP_TYPE_PTRQ(type))
		rval->value.ptv->p=0;
	else switch(type) {
		case TUChar:	rval->value.ptv->c=0;	break;
		case TUShort:	rval->value.ptv->s=0;	break;
		case TUInt:		rval->value.ptv->i=0;	break;
		case TULong:	rval->value.ptv->l=0;	break;
		case TFloat:	rval->value.ptv->f=0.0;	break;
		case TDouble:	rval->value.ptv->d=0.0;	break;
		default:
			assert(!"unknown type");
	}
	return rval;
}

static int
cexpRedir(CexpParserCtx ctx, unsigned long op, void *opath, void *ipath);

static void
cexpUnredir(CexpParserCtx ctx);

/* Redefine so that we can wrap */
#undef yyparse
#define yyparse __cexpparse


#line 233 "cexp.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "cexp.tab.h".  */
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
#line 163 "cexp.y" /* yacc.c:355  */

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

#line 331 "cexp.tab.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif



int cexpparse (CexpParserCtx ctx);

#endif /* !YY_CEXP_CEXP_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 345 "cexp.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  14
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   474

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  58
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  29
/* YYNRULES -- Number of rules.  */
#define YYNRULES  111
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  213

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   292

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      57,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    52,     2,     2,     2,    42,    29,     2,
      55,    56,    40,    39,    21,    38,    54,    41,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    23,     2,
      32,    24,    33,    22,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    28,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    27,     2,    51,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    25,    26,    30,    31,
      34,    35,    36,    37,    43,    44,    45,    46,    47,    48,
      49,    50,    53
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   250,   250,   253,   255,   257,   259,   263,   271,   277,
     278,   280,   282,   284,   288,   290,   292,   296,   301,   306,
     313,   313,   316,   317,   321,   323,   329,   330,   334,   371,
     372,   374,   381,   390,   391,   395,   399,   401,   403,   405,
     407,   409,   411,   413,   415,   417,   419,   421,   423,   425,
     427,   429,   433,   437,   441,   443,   448,   450,   452,   460,
     461,   465,   466,   468,   470,   476,   480,   482,   485,   487,
     491,   493,   508,   510,   512,   514,   516,   518,   522,   527,
     531,   550,   554,   556,   558,   570,   584,   585,   587,   589,
     594,   596,   598,   604,   605,   606,   608,   610,   612,   614,
     616,   618,   620,   622,   624,   626,   628,   630,   632,   634,
     636,   638
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NUMBER", "STR_CONST", "FUNC", "VAR",
  "UVAR", "IDENT", "KW_CHAR", "KW_SHORT", "KW_INT", "KW_LONG", "KW_FLOAT",
  "KW_DOUBLE", "MODOP", "REDIR", "REDIRBOTH", "REDIRAPPEND",
  "REDIRAPPENDBOTH", "NONE", "','", "'?'", "':'", "'='", "OR", "AND",
  "'|'", "'^'", "'&'", "EQ", "NE", "'<'", "'>'", "LE", "GE", "SHL", "SHR",
  "'-'", "'+'", "'*'", "'/'", "'%'", "CAST", "VARCAST", "DEREF", "ADDR",
  "PREFIX", "MM", "PP", "NEG", "'~'", "'!'", "CALL", "'.'", "'('", "')'",
  "'\\n'", "$accept", "input", "oredirop", "redirarg", "redir", "redef",
  "newdef", "def", "commaexp", "line", "exp", "binexp", "or", "and",
  "prefix", "postfix", "unexp", "nonfuncvar", "anyvar", "lval", "typeid",
  "cast", "pcast", "fptype", "fpcast", "funcp", "castexp", "symmethod",
  "call", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,    44,    63,    58,    61,   276,   277,   124,    94,    38,
     278,   279,    60,    62,   280,   281,   282,   283,    45,    43,
      42,    47,    37,   284,   285,   286,   287,   288,   289,   290,
     291,   126,    33,   292,    46,    40,    41,    10
};
# endif

#define YYPACT_NINF -113

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-113)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     130,   116,   -21,   -11,    23,   116,   201,    27,  -113,  -113,
      79,    30,  -113,  -113,  -113,    45,  -113,  -113,   -24,    24,
      42,    40,  -113,  -113,  -113,  -113,  -113,  -113,    41,   326,
     326,    69,    69,   326,   326,   310,  -113,   -37,  -113,    56,
     -17,  -113,  -113,   357,   326,   326,  -113,  -113,  -113,  -113,
      95,     5,   326,   326,    44,   326,  -113,  -113,    70,    71,
    -113,   116,  -113,   116,   120,   123,   124,   100,  -113,  -113,
    -113,    22,  -113,  -113,  -113,  -113,  -113,  -113,   110,   -14,
     -34,    80,  -113,  -113,  -113,   100,  -113,  -113,  -113,   326,
     326,   326,   326,   326,   326,   326,   326,   326,   326,   326,
     326,   326,   326,   326,   326,   374,   390,   100,   100,  -113,
    -113,  -113,  -113,   211,  -113,  -113,  -113,  -113,    97,  -113,
     217,   256,  -113,  -113,  -113,  -113,  -113,  -113,  -113,    85,
    -113,   106,  -113,   405,   419,   432,   242,   242,   195,   195,
     195,   195,   132,   132,   202,   202,  -113,  -113,  -113,  -113,
    -113,  -113,  -113,   221,  -113,    -7,  -113,    -5,  -113,    91,
      94,    98,   100,  -113,   100,  -113,   104,   111,   113,   119,
      -4,   121,   122,   125,  -113,   100,  -113,   133,  -113,  -113,
      -2,  -113,   100,  -113,     3,   100,  -113,     6,   100,  -113,
       7,   100,  -113,    10,   100,  -113,    12,   100,  -113,    13,
     100,  -113,    16,   100,  -113,    17,   100,  -113,    18,   100,
    -113,   134,  -113
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       9,     0,     3,     4,     0,     0,     0,     0,    66,    67,
      11,     0,     5,     6,     1,    10,    59,    60,    82,    66,
      67,     0,    72,    73,    74,    75,    76,    77,     0,     0,
       0,     0,     0,     0,     0,     0,    24,     0,    20,     0,
       0,     2,    22,    29,     0,     0,    85,    84,    86,    70,
      58,    80,     0,     0,     0,     0,    94,    33,     0,    61,
       8,     0,     7,     0,     0,     0,     0,     0,    25,    83,
      65,    58,    64,    71,    54,    55,    63,    62,     0,     0,
      80,     0,    21,    27,    26,     0,    28,    52,    53,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    34,    35,     0,     0,    56,
      57,    69,    17,     0,    68,    14,    87,    88,     0,    89,
       0,     0,    12,    13,    92,    90,    91,    32,    93,     0,
      78,     0,    23,    36,    37,    38,    40,    39,    42,    41,
      43,    44,    45,    46,    48,    47,    49,    50,    51,    31,
      30,    18,    15,     0,    95,     0,    98,     0,    79,     0,
       0,     0,     0,    96,     0,    99,     0,     0,     0,     0,
       0,     0,     0,     0,    97,     0,   100,     0,    19,    16,
       0,    81,     0,   101,     0,     0,   102,     0,     0,   103,
       0,     0,   104,     0,     0,   105,     0,     0,   106,     0,
       0,   107,     0,     0,   108,     0,     0,   109,     0,     0,
     110,     0,   111
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -113,  -113,   143,    -3,  -113,  -113,  -113,  -113,   145,  -113,
     -64,    -9,  -113,  -113,  -113,  -113,  -113,     4,  -112,    -6,
     152,  -113,  -113,   157,  -113,  -113,   131,  -113,  -113
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     4,     5,    10,     6,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,   115,    71,
      51,    52,    53,    54,    55,    56,    57,    58,    59
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      50,   152,    15,   127,    85,    11,   129,    85,    12,    11,
     111,     8,     9,   112,   162,    82,   164,   175,    13,   182,
      83,   132,   130,    14,   185,    74,    75,   188,   191,    50,
      64,   194,    70,   197,   200,   105,   106,   203,   206,   209,
      86,   161,   128,   149,   150,   113,    69,     8,     9,   163,
      60,   165,   176,    62,   183,   114,   155,   157,   122,   186,
     123,    50,   189,   192,    67,    11,   195,    11,   198,   201,
     109,   110,   204,   207,   210,     8,     9,    63,    65,    50,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,    66,    68,   169,   118,
     170,    50,    50,    16,    17,    18,    19,    20,    78,    30,
     107,   180,     2,    84,    50,    50,     3,   114,   184,   108,
       7,   187,     8,     9,   190,   120,   121,   193,   124,    28,
     196,   125,   126,   199,    67,   131,   202,   153,    29,   205,
      30,   158,   208,   109,   110,   211,   159,   166,    31,    32,
     167,    33,    34,    61,   168,    35,    50,   114,    50,   171,
      72,    73,     1,     2,    76,    77,   172,     3,   173,    50,
     100,   101,   102,   103,   104,   174,    50,   177,   178,    50,
      79,   179,    50,   116,   117,    50,   119,    80,    50,   181,
     212,    50,    81,     0,    50,     0,     0,    50,     0,     0,
      50,     0,     0,    50,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,   111,     8,     9,   151,
      16,    17,    18,    19,    20,    78,   111,     8,     9,   160,
      28,    98,    99,   100,   101,   102,   103,   104,     0,    29,
       0,    30,   102,   103,   104,     0,    28,     0,     0,    31,
      32,     0,    33,    34,     0,    29,    35,    30,    36,    16,
      17,    18,    19,    20,    78,    31,    32,     0,    33,    34,
       0,     0,    35,   154,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,    28,     0,     0,     0,     0,
       0,     0,     0,     0,    29,     0,    30,     0,     0,     0,
       0,     0,     0,     0,    31,    32,     0,    33,    34,     0,
       0,    35,   156,    16,    17,    18,    19,    20,    78,    22,
      23,    24,    25,    26,    27,     0,     0,     0,     0,    16,
      17,    18,    19,    20,     0,     0,     0,     0,     0,    28,
       0,     0,     0,     0,     0,     0,     0,     0,    29,     0,
      30,     0,     0,     0,     0,    28,     0,     0,    31,    32,
       0,    33,    34,     0,    29,    35,    30,     0,     0,     0,
       0,     0,     0,     0,    31,    32,     0,    33,    34,     0,
       0,    35,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104
};

static const yytype_int16 yycheck[] =
{
       6,   113,     5,    67,    21,     1,    40,    21,    29,     5,
       5,     6,     7,     8,    21,    52,    21,    21,    29,    21,
      57,    85,    56,     0,    21,    31,    32,    21,    21,    35,
      54,    21,    28,    21,    21,    44,    45,    21,    21,    21,
      57,   153,    56,   107,   108,    40,     5,     6,     7,    56,
      23,    56,    56,    23,    56,    51,   120,   121,    61,    56,
      63,    67,    56,    56,    24,    61,    56,    63,    56,    56,
      48,    49,    56,    56,    56,     6,     7,    32,    54,    85,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,    54,    57,   162,    55,
     164,   107,   108,     3,     4,     5,     6,     7,     8,    40,
      15,   175,    33,    57,   120,   121,    37,   113,   182,    24,
       4,   185,     6,     7,   188,    55,    55,   191,     8,    29,
     194,     8,     8,   197,    24,    55,   200,    40,    38,   203,
      40,    56,   206,    48,    49,   209,    40,    56,    48,    49,
      56,    51,    52,    10,    56,    55,   162,   153,   164,    55,
      29,    30,    32,    33,    33,    34,    55,    37,    55,   175,
      38,    39,    40,    41,    42,    56,   182,    56,    56,   185,
      35,    56,   188,    52,    53,   191,    55,    35,   194,    56,
      56,   197,    35,    -1,   200,    -1,    -1,   203,    -1,    -1,
     206,    -1,    -1,   209,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,     5,     6,     7,     8,
       3,     4,     5,     6,     7,     8,     5,     6,     7,     8,
      29,    36,    37,    38,    39,    40,    41,    42,    -1,    38,
      -1,    40,    40,    41,    42,    -1,    29,    -1,    -1,    48,
      49,    -1,    51,    52,    -1,    38,    55,    40,    57,     3,
       4,     5,     6,     7,     8,    48,    49,    -1,    51,    52,
      -1,    -1,    55,    56,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    29,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    38,    -1,    40,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    48,    49,    -1,    51,    52,    -1,
      -1,    55,    56,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    -1,    -1,    -1,    -1,     3,
       4,     5,     6,     7,    -1,    -1,    -1,    -1,    -1,    29,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,    -1,
      40,    -1,    -1,    -1,    -1,    29,    -1,    -1,    48,    49,
      -1,    51,    52,    -1,    38,    55,    40,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    48,    49,    -1,    51,    52,    -1,
      -1,    55,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    32,    33,    37,    59,    60,    62,     4,     6,     7,
      61,    75,    29,    29,     0,    61,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    29,    38,
      40,    48,    49,    51,    52,    55,    57,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      23,    60,    23,    32,    54,    54,    54,    24,    57,     5,
      75,    77,    84,    84,    77,    77,    84,    84,     8,    66,
      78,    81,    52,    57,    57,    21,    57,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    69,    69,    15,    24,    48,
      49,     5,     8,    40,    75,    76,    84,    84,    55,    84,
      55,    55,    61,    61,     8,     8,     8,    68,    56,    40,
      56,    55,    68,    69,    69,    69,    69,    69,    69,    69,
      69,    69,    69,    69,    69,    69,    69,    69,    69,    68,
      68,     8,    76,    40,    56,    68,    56,    68,    56,    40,
       8,    76,    21,    56,    21,    56,    56,    56,    56,    68,
      68,    55,    55,    55,    56,    21,    56,    56,    56,    56,
      68,    56,    21,    56,    68,    21,    56,    68,    21,    56,
      68,    21,    56,    68,    21,    56,    68,    21,    56,    68,
      21,    56,    68,    21,    56,    68,    21,    56,    68,    21,
      56,    68,    56
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    58,    59,    60,    60,    60,    60,    61,    61,    62,
      62,    62,    62,    62,    63,    63,    63,    64,    64,    64,
      65,    65,    66,    66,    67,    67,    67,    67,    67,    68,
      68,    68,    68,    69,    69,    69,    69,    69,    69,    69,
      69,    69,    69,    69,    69,    69,    69,    69,    69,    69,
      69,    69,    70,    71,    72,    72,    73,    73,    73,    74,
      74,    74,    74,    74,    74,    74,    75,    75,    76,    76,
      77,    77,    78,    78,    78,    78,    78,    78,    79,    80,
      81,    82,    83,    83,    83,    83,    84,    84,    84,    84,
      85,    85,    85,    86,    86,    86,    86,    86,    86,    86,
      86,    86,    86,    86,    86,    86,    86,    86,    86,    86,
      86,    86
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     1,     1,     2,     2,     2,     2,     0,
       2,     2,     4,     4,     2,     3,     7,     2,     3,     7,
       1,     2,     1,     3,     1,     2,     2,     2,     2,     1,
       3,     3,     3,     1,     2,     2,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     2,     2,     2,     2,     2,     2,     1,     1,
       1,     1,     2,     2,     2,     2,     1,     1,     1,     1,
       1,     2,     1,     1,     1,     1,     1,     1,     3,     4,
       1,     8,     1,     2,     1,     1,     1,     2,     2,     2,
       3,     3,     3,     3,     1,     3,     4,     6,     3,     4,
       6,     8,    10,    12,    14,    16,    18,    20,    22,    24,
      26,    28
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (ctx, YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, ctx); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, CexpParserCtx ctx)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (ctx);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, CexpParserCtx ctx)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep, ctx);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule, CexpParserCtx ctx)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              , ctx);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule, ctx); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, CexpParserCtx ctx)
{
  YYUSE (yyvaluep);
  YYUSE (ctx);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/*----------.
| yyparse.  |
`----------*/

int
yyparse (CexpParserCtx ctx)
{
/* The lookahead symbol.  */
int yychar;


/* The semantic value of the lookahead symbol.  */
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
YY_INITIAL_VALUE (static YYSTYPE yyval_default;)
YYSTYPE yylval YY_INITIAL_VALUE (= yyval_default);

    /* Number of syntax errors so far.  */
    int yynerrs;

    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex (&yylval);
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 250 "cexp.y" /* yacc.c:1646  */
    { if ( TVoid != (yyvsp[0].val).type ) { ctx->rval=(yyvsp[0].val).tv; ctx->rval_sym.value.type = (yyvsp[0].val).type; } ctx->status = 0; YYACCEPT; }
#line 1629 "cexp.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 254 "cexp.y" /* yacc.c:1646  */
    { (yyval.ul)=REDIR; }
#line 1635 "cexp.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 256 "cexp.y" /* yacc.c:1646  */
    { (yyval.ul)=REDIRAPPEND; }
#line 1641 "cexp.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 258 "cexp.y" /* yacc.c:1646  */
    { (yyval.ul)=REDIRBOTH; }
#line 1647 "cexp.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 260 "cexp.y" /* yacc.c:1646  */
    { (yyval.ul)=REDIRAPPENDBOTH; }
#line 1653 "cexp.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 264 "cexp.y" /* yacc.c:1646  */
    {
			if ( TUCharP != (yyvsp[-1].varp)->type ) {
				errmsg(ctx, "(bad type): redirector requires string argument\n");
				YYERROR;
			}
			(yyval.chrp) = (yyvsp[-1].varp)->ptv->p;
		}
#line 1665 "cexp.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 272 "cexp.y" /* yacc.c:1646  */
    {
			(yyval.chrp) = (yyvsp[-1].val).tv.p;
		}
#line 1673 "cexp.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 279 "cexp.y" /* yacc.c:1646  */
    { if ( cexpRedir( ctx, (yyvsp[-1].ul), (yyvsp[0].chrp),  0 ) ) YYERROR; }
#line 1679 "cexp.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 281 "cexp.y" /* yacc.c:1646  */
    { if ( cexpRedir( ctx,  0,  0, (yyvsp[0].chrp) ) ) YYERROR; }
#line 1685 "cexp.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 283 "cexp.y" /* yacc.c:1646  */
    { if ( cexpRedir( ctx, (yyvsp[-1].ul), (yyvsp[0].chrp), (yyvsp[-2].chrp) ) ) YYERROR; }
#line 1691 "cexp.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 285 "cexp.y" /* yacc.c:1646  */
    { if ( cexpRedir( ctx, (yyvsp[-3].ul), (yyvsp[-2].chrp), (yyvsp[0].chrp) ) ) YYERROR; }
#line 1697 "cexp.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 289 "cexp.y" /* yacc.c:1646  */
    { EVAL((yyvsp[0].varp)->type = (yyvsp[-1].typ);); CHECK(cexpTA2TV(&(yyval.val),(yyvsp[0].varp))); }
#line 1703 "cexp.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 291 "cexp.y" /* yacc.c:1646  */
    { EVAL((yyvsp[0].varp)->type = CEXP_TYPE_BASE2PTR((yyvsp[-2].typ));); CHECK(cexpTA2TV(&(yyval.val),(yyvsp[0].varp))); }
#line 1709 "cexp.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 293 "cexp.y" /* yacc.c:1646  */
    { EVAL((yyvsp[-3].varp)->type = (yyvsp[-6].typ)); CHECK(cexpTA2TV(&(yyval.val),(yyvsp[-3].varp))); }
#line 1715 "cexp.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 297 "cexp.y" /* yacc.c:1646  */
    { CexpSym found;
					  EVAL(if (!(found = varCreate(ctx, (yyvsp[0].lstr), (yyvsp[-1].typ)))) YYERROR; \
					  		CHECK(cexpTA2TV(&(yyval.val),&found->value)) );
					}
#line 1724 "cexp.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 302 "cexp.y" /* yacc.c:1646  */
    { CexpSym found;
					  EVAL(if (!(found = varCreate(ctx, (yyvsp[0].lstr), CEXP_TYPE_BASE2PTR((yyvsp[-2].typ))))) YYERROR; \
					  		CHECK(cexpTA2TV(&(yyval.val),&found->value)));
					}
#line 1733 "cexp.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 307 "cexp.y" /* yacc.c:1646  */
    { CexpSym found;
					  EVAL(if (!(found = varCreate(ctx, (yyvsp[-3].lstr), (yyvsp[-6].typ)))) YYERROR; \
					  		CHECK(cexpTA2TV(&(yyval.val),&found->value)));
					}
#line 1742 "cexp.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 318 "cexp.y" /* yacc.c:1646  */
    { (yyval.val)=(yyvsp[0].val); }
#line 1748 "cexp.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 322 "cexp.y" /* yacc.c:1646  */
    {	(yyval.val).type=TVoid; }
#line 1754 "cexp.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 324 "cexp.y" /* yacc.c:1646  */
    {
						(yyval.val).type=TVoid;
						yyerror(ctx, "unknown symbol/variable; '=' expected");
						YYERROR;
					}
#line 1764 "cexp.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 330 "cexp.y" /* yacc.c:1646  */
    {
						errmsg(ctx, ": symbol already defined; append '!' to enforce recast\n");
						YYERROR;
					}
#line 1773 "cexp.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 335 "cexp.y" /* yacc.c:1646  */
    {FILE *f=ctx->outf;
						(yyval.val)=(yyvsp[-1].val);
						if (CEXP_TYPE_FPQ((yyvsp[-1].val).type)) {
							CHECK(cexpTypeCast(&(yyvsp[-1].val),TDouble,0));
							if (f)
								fprintf(f,"%f\n",(yyvsp[-1].val).tv.d);
						}else {
							if (TUChar==(yyvsp[-1].val).type) {
								unsigned char c=(yyvsp[-1].val).tv.c,e=0;
								if (f) {
									fprintf(f,"0x%02x (%d)",c,c);
									switch (c) {
										case 0:	    e=1; c='0'; break;
										case '\t':	e=1; c='t'; break;
										case '\r':	e=1; c='r'; break;
										case '\n':	e=1; c='n'; break;
										case '\f':	e=1; c='f'; break;
										default: 	break;
									}
									if (isprint(c)) {
										fputc('\'',f);
										if (e) fputc('\\',f);
										fputc(c,f);
										fputc('\'',f);
									}
									fputc('\n',f);
								}
							} else {
								CHECK(cexpTypeCast(&(yyvsp[-1].val),TULong,0));
								if (f)
									fprintf(f,"0x%0*lx (%ld)\n",(int)(2*sizeof((yyvsp[-1].val).tv.l)), (yyvsp[-1].val).tv.l, (yyvsp[-1].val).tv.l);
							}
						}
					}
#line 1812 "cexp.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 373 "cexp.y" /* yacc.c:1646  */
    { (yyval.val)=(yyvsp[0].val); EVAL(CHECK(cexpTVAssign(&(yyvsp[-2].lval), &(yyvsp[0].val)))); }
#line 1818 "cexp.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 375 "cexp.y" /* yacc.c:1646  */
    { EVAL( \
						CHECK(cexpTA2TV(&(yyval.val),&(yyvsp[-2].lval))); \
						CHECK(cexpTVBinOp(&(yyval.val), &(yyval.val), &(yyvsp[0].val), (yyvsp[-1].binop))); \
						CHECK(cexpTVAssign(&(yyvsp[-2].lval),&(yyval.val))); \
					  );
					}
#line 1829 "cexp.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 382 "cexp.y" /* yacc.c:1646  */
    { CexpSym found;
					  (yyval.val)=(yyvsp[0].val); EVAL(if (!(found=varCreate(ctx, (yyvsp[-2].lstr), (yyvsp[0].val).type))) {	\
									YYERROR; 								\
								}\
								CHECK(cexpTVAssign(&found->value, &(yyvsp[0].val))); );
					}
#line 1840 "cexp.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 392 "cexp.y" /* yacc.c:1646  */
    { (yyval.val).tv.l = (yyvsp[-1].ul) || cexpTVTrueQ(&(yyvsp[0].val));
					  (yyval.val).type = TULong;
					  POPEVAL; }
#line 1848 "cexp.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 396 "cexp.y" /* yacc.c:1646  */
    { (yyval.val).tv.l = (yyvsp[-1].ul) && cexpTVTrueQ(&(yyvsp[0].val));
					  (yyval.val).type = TULong;
					  POPEVAL; }
#line 1856 "cexp.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 400 "cexp.y" /* yacc.c:1646  */
    { CHECK(cexpTVBinOp(&(yyval.val),&(yyvsp[-2].val),&(yyvsp[0].val),OOr)); }
#line 1862 "cexp.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 402 "cexp.y" /* yacc.c:1646  */
    { CHECK(cexpTVBinOp(&(yyval.val),&(yyvsp[-2].val),&(yyvsp[0].val),OXor)); }
#line 1868 "cexp.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 404 "cexp.y" /* yacc.c:1646  */
    { CHECK(cexpTVBinOp(&(yyval.val),&(yyvsp[-2].val),&(yyvsp[0].val),OAnd)); }
#line 1874 "cexp.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 406 "cexp.y" /* yacc.c:1646  */
    { CHECK(cexpTVBinOp(&(yyval.val),&(yyvsp[-2].val),&(yyvsp[0].val),ONe)); }
#line 1880 "cexp.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 408 "cexp.y" /* yacc.c:1646  */
    { CHECK(cexpTVBinOp(&(yyval.val),&(yyvsp[-2].val),&(yyvsp[0].val),OEq)); }
#line 1886 "cexp.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 410 "cexp.y" /* yacc.c:1646  */
    { CHECK(cexpTVBinOp(&(yyval.val),&(yyvsp[-2].val),&(yyvsp[0].val),OGt)); }
#line 1892 "cexp.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 412 "cexp.y" /* yacc.c:1646  */
    { CHECK(cexpTVBinOp(&(yyval.val),&(yyvsp[-2].val),&(yyvsp[0].val),OLt)); }
#line 1898 "cexp.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 414 "cexp.y" /* yacc.c:1646  */
    { CHECK(cexpTVBinOp(&(yyval.val),&(yyvsp[-2].val),&(yyvsp[0].val),OLe)); }
#line 1904 "cexp.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 416 "cexp.y" /* yacc.c:1646  */
    { CHECK(cexpTVBinOp(&(yyval.val),&(yyvsp[-2].val),&(yyvsp[0].val),OGe)); }
#line 1910 "cexp.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 418 "cexp.y" /* yacc.c:1646  */
    { CHECK(cexpTVBinOp(&(yyval.val),&(yyvsp[-2].val),&(yyvsp[0].val),OShL)); }
#line 1916 "cexp.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 420 "cexp.y" /* yacc.c:1646  */
    { CHECK(cexpTVBinOp(&(yyval.val),&(yyvsp[-2].val),&(yyvsp[0].val),OShR)); }
#line 1922 "cexp.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 422 "cexp.y" /* yacc.c:1646  */
    { CHECK(cexpTVBinOp(&(yyval.val),&(yyvsp[-2].val),&(yyvsp[0].val),OAdd)); }
#line 1928 "cexp.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 424 "cexp.y" /* yacc.c:1646  */
    { CHECK(cexpTVBinOp(&(yyval.val),&(yyvsp[-2].val),&(yyvsp[0].val),OSub)); }
#line 1934 "cexp.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 426 "cexp.y" /* yacc.c:1646  */
    { CHECK(cexpTVBinOp(&(yyval.val),&(yyvsp[-2].val),&(yyvsp[0].val),OMul)); }
#line 1940 "cexp.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 428 "cexp.y" /* yacc.c:1646  */
    { CHECK(cexpTVBinOp(&(yyval.val),&(yyvsp[-2].val),&(yyvsp[0].val),ODiv)); }
#line 1946 "cexp.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 430 "cexp.y" /* yacc.c:1646  */
    { CHECK(cexpTVBinOp(&(yyval.val),&(yyvsp[-2].val),&(yyvsp[0].val),OMod)); }
#line 1952 "cexp.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 434 "cexp.y" /* yacc.c:1646  */
    { (yyval.ul)=cexpTVTrueQ(&(yyvsp[-1].val)); PSHEVAL((yyval.ul)); }
#line 1958 "cexp.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 438 "cexp.y" /* yacc.c:1646  */
    { (yyval.ul)=cexpTVTrueQ(&(yyvsp[-1].val)); PSHEVAL( ! (yyval.ul)); }
#line 1964 "cexp.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 442 "cexp.y" /* yacc.c:1646  */
    { (yyval.fixexp).lval=(yyvsp[0].lval); (yyval.fixexp).op=OSub; }
#line 1970 "cexp.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 444 "cexp.y" /* yacc.c:1646  */
    { (yyval.fixexp).lval=(yyvsp[0].lval); (yyval.fixexp).op=OAdd; }
#line 1976 "cexp.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 449 "cexp.y" /* yacc.c:1646  */
    { (yyval.fixexp).lval=(yyvsp[-1].lval); (yyval.fixexp).op=OSub; }
#line 1982 "cexp.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 451 "cexp.y" /* yacc.c:1646  */
    { (yyval.fixexp).lval=(yyvsp[-1].lval); (yyval.fixexp).op=OAdd; }
#line 1988 "cexp.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 453 "cexp.y" /* yacc.c:1646  */
    { (yyval.fixexp).lval=(yyvsp[0].lval); (yyval.fixexp).op=ONoop; }
#line 1994 "cexp.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 467 "cexp.y" /* yacc.c:1646  */
    { (yyval.val).type=TULong; (yyval.val).tv.l = ! cexpTVTrueQ(&(yyvsp[0].val)); }
#line 2000 "cexp.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 469 "cexp.y" /* yacc.c:1646  */
    { CHECK(cexpTVUnOp(&(yyval.val),&(yyvsp[0].val),OCpl)); }
#line 2006 "cexp.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 471 "cexp.y" /* yacc.c:1646  */
    { CHECK(cexpTVUnOp(&(yyval.val),&(yyvsp[0].val),ONeg)); }
#line 2012 "cexp.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 477 "cexp.y" /* yacc.c:1646  */
    { CHECK(cexpTVPtr(&(yyval.val), (yyvsp[0].varp))); }
#line 2018 "cexp.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 481 "cexp.y" /* yacc.c:1646  */
    { (yyval.varp)=&(yyvsp[0].sym)->value; }
#line 2024 "cexp.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 483 "cexp.y" /* yacc.c:1646  */
    { (yyval.varp)=&(yyvsp[0].sym)->value; }
#line 2030 "cexp.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 486 "cexp.y" /* yacc.c:1646  */
    { (yyval.varp)=(yyvsp[0].varp); }
#line 2036 "cexp.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 488 "cexp.y" /* yacc.c:1646  */
    { (yyval.varp)=&(yyvsp[0].sym)->value; }
#line 2042 "cexp.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 492 "cexp.y" /* yacc.c:1646  */
    { (yyval.lval) = *(yyvsp[0].varp); }
#line 2048 "cexp.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 494 "cexp.y" /* yacc.c:1646  */
    { if (!CEXP_TYPE_PTRQ((yyvsp[0].val).type) || CEXP_TYPE_FUNQ((yyvsp[0].val).type)) {
						yyerror(ctx, "not a valid lval address");
						YYERROR;
					  }
					  (yyval.lval).type=CEXP_TYPE_PTR2BASE((yyvsp[0].val).type);
					  (yyval.lval).ptv=(CexpVal)(yyvsp[0].val).tv.p;
					}
#line 2060 "cexp.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 509 "cexp.y" /* yacc.c:1646  */
    { (yyval.typ)=TUChar; }
#line 2066 "cexp.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 511 "cexp.y" /* yacc.c:1646  */
    { (yyval.typ)=TUShort; }
#line 2072 "cexp.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 513 "cexp.y" /* yacc.c:1646  */
    { (yyval.typ)=TUInt; }
#line 2078 "cexp.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 515 "cexp.y" /* yacc.c:1646  */
    { (yyval.typ)=TULong; }
#line 2084 "cexp.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 517 "cexp.y" /* yacc.c:1646  */
    { (yyval.typ)=TFloat; }
#line 2090 "cexp.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 519 "cexp.y" /* yacc.c:1646  */
    { (yyval.typ)=TDouble; }
#line 2096 "cexp.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 523 "cexp.y" /* yacc.c:1646  */
    { (yyval.typ)=(yyvsp[-1].typ); }
#line 2102 "cexp.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 528 "cexp.y" /* yacc.c:1646  */
    { (yyval.typ)=CEXP_TYPE_BASE2PTR((yyvsp[-2].typ)); }
#line 2108 "cexp.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 532 "cexp.y" /* yacc.c:1646  */
    { switch ((yyvsp[0].typ)) {
						default:
							yyerror(ctx, "invalid type for function pointer cast");
						YYERROR;

						case TDouble:
							(yyval.typ)=TDFuncP;
						break;

						/* INTFIX */
						case TULong:
							(yyval.typ)=TFuncP;
						break;
					  }
					}
#line 2128 "cexp.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 551 "cexp.y" /* yacc.c:1646  */
    { (yyval.typ)=(yyvsp[-6].typ); }
#line 2134 "cexp.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 555 "cexp.y" /* yacc.c:1646  */
    { (yyval.val).type=(yyvsp[0].sym)->value.type; (yyval.val).tv.p=(void*)(yyvsp[0].sym)->value.ptv; }
#line 2140 "cexp.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 557 "cexp.y" /* yacc.c:1646  */
    { (yyval.val).type=(yyvsp[0].sym)->value.type; (yyval.val).tv.p=(void*)(yyvsp[0].sym)->value.ptv; }
#line 2146 "cexp.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 559 "cexp.y" /* yacc.c:1646  */
    { CexpTypedValRec tmp;
					  EVAL( \
						CHECK(cexpTA2TV(&(yyval.val),&(yyvsp[0].fixexp).lval)); \
						tmp.type=TUChar; \
						tmp.tv.c=1; \
						if (ONoop != (yyvsp[0].fixexp).op) { \
							CHECK(cexpTVBinOp(&tmp,&(yyval.val),&tmp,(yyvsp[0].fixexp).op)); \
							CHECK(cexpTVAssign(&(yyvsp[0].fixexp).lval,&tmp)); \
						} \
					  );
					}
#line 2162 "cexp.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 571 "cexp.y" /* yacc.c:1646  */
    { CexpTypedValRec tmp;
					  EVAL( \
						CHECK(cexpTA2TV(&(yyval.val),&(yyvsp[0].fixexp).lval)); \
						tmp.type=TUChar; \
						tmp.tv.c=1; \
						if (ONoop != (yyvsp[0].fixexp).op) { \
							CHECK(cexpTVBinOp(&(yyval.val),&(yyval.val),&tmp,(yyvsp[0].fixexp).op)); \
							CHECK(cexpTVAssign(&(yyvsp[0].fixexp).lval,&(yyval.val))); \
						} \
					  );
					}
#line 2178 "cexp.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 586 "cexp.y" /* yacc.c:1646  */
    { (yyval.val)=(yyvsp[0].val); CHECK(cexpTypeCast(&(yyval.val),(yyvsp[-1].typ),CNV_FORCE)); }
#line 2184 "cexp.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 588 "cexp.y" /* yacc.c:1646  */
    { (yyval.val)=(yyvsp[0].val); CHECK(cexpTypeCast(&(yyval.val),(yyvsp[-1].typ),CNV_FORCE)); }
#line 2190 "cexp.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 590 "cexp.y" /* yacc.c:1646  */
    { (yyval.val)=(yyvsp[0].val); CHECK(cexpTypeCast(&(yyval.val),(yyvsp[-1].typ),CNV_FORCE)); }
#line 2196 "cexp.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 594 "cexp.y" /* yacc.c:1646  */
    { (yyval.method).sym = (yyvsp[-2].sym); (yyval.method).mname=(yyvsp[0].lstr); }
#line 2202 "cexp.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 596 "cexp.y" /* yacc.c:1646  */
    { (yyval.method).sym = (yyvsp[-2].sym); (yyval.method).mname=(yyvsp[0].lstr); }
#line 2208 "cexp.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 598 "cexp.y" /* yacc.c:1646  */
    { (yyval.method).sym = (yyvsp[-2].sym); (yyval.method).mname=(yyvsp[0].lstr); }
#line 2214 "cexp.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 604 "cexp.y" /* yacc.c:1646  */
    { (yyval.val)=(yyvsp[-1].val); }
#line 2220 "cexp.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 607 "cexp.y" /* yacc.c:1646  */
    {	EVAL(CHECK(cexpSymMember(&(yyval.val), (yyvsp[-2].method).sym, (yyvsp[-2].method).mname, (void*)0))); }
#line 2226 "cexp.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 609 "cexp.y" /* yacc.c:1646  */
    {	EVAL(CHECK(cexpSymMember(&(yyval.val), (yyvsp[-3].method).sym, (yyvsp[-3].method).mname, &(yyvsp[-1].val), (void*)0))); }
#line 2232 "cexp.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 611 "cexp.y" /* yacc.c:1646  */
    {	EVAL(CHECK(cexpSymMember(&(yyval.val), (yyvsp[-5].method).sym, (yyvsp[-5].method).mname, &(yyvsp[-3].val), &(yyvsp[-1].val), (void*)0))); }
#line 2238 "cexp.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 613 "cexp.y" /* yacc.c:1646  */
    {	EVAL(CHECK(cexpTVFnCall(&(yyval.val),&(yyvsp[-2].val),(void*)0))); }
#line 2244 "cexp.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 615 "cexp.y" /* yacc.c:1646  */
    {	EVAL(CHECK(cexpTVFnCall(&(yyval.val),&(yyvsp[-3].val),&(yyvsp[-1].val),(void*)0))); }
#line 2250 "cexp.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 617 "cexp.y" /* yacc.c:1646  */
    {	EVAL(CHECK(cexpTVFnCall(&(yyval.val),&(yyvsp[-5].val),&(yyvsp[-3].val),&(yyvsp[-1].val),(void*)0))); }
#line 2256 "cexp.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 619 "cexp.y" /* yacc.c:1646  */
    {	EVAL(CHECK(cexpTVFnCall(&(yyval.val),&(yyvsp[-7].val),&(yyvsp[-5].val),&(yyvsp[-3].val),&(yyvsp[-1].val),(void*)0))); }
#line 2262 "cexp.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 621 "cexp.y" /* yacc.c:1646  */
    {	EVAL(CHECK(cexpTVFnCall(&(yyval.val),&(yyvsp[-9].val),&(yyvsp[-7].val),&(yyvsp[-5].val),&(yyvsp[-3].val),&(yyvsp[-1].val),(void*)0))); }
#line 2268 "cexp.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 623 "cexp.y" /* yacc.c:1646  */
    {	EVAL(CHECK(cexpTVFnCall(&(yyval.val),&(yyvsp[-11].val),&(yyvsp[-9].val),&(yyvsp[-7].val),&(yyvsp[-5].val),&(yyvsp[-3].val),&(yyvsp[-1].val),(void*)0))); }
#line 2274 "cexp.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 625 "cexp.y" /* yacc.c:1646  */
    {	EVAL(CHECK(cexpTVFnCall(&(yyval.val),&(yyvsp[-13].val),&(yyvsp[-11].val),&(yyvsp[-9].val),&(yyvsp[-7].val),&(yyvsp[-5].val),&(yyvsp[-3].val),&(yyvsp[-1].val),(void*)0))); }
#line 2280 "cexp.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 627 "cexp.y" /* yacc.c:1646  */
    {	EVAL(CHECK(cexpTVFnCall(&(yyval.val),&(yyvsp[-15].val),&(yyvsp[-13].val),&(yyvsp[-11].val),&(yyvsp[-9].val),&(yyvsp[-7].val),&(yyvsp[-5].val),&(yyvsp[-3].val),&(yyvsp[-1].val),(void*)0))); }
#line 2286 "cexp.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 629 "cexp.y" /* yacc.c:1646  */
    {	EVAL(CHECK(cexpTVFnCall(&(yyval.val),&(yyvsp[-17].val),&(yyvsp[-15].val),&(yyvsp[-13].val),&(yyvsp[-11].val),&(yyvsp[-9].val),&(yyvsp[-7].val),&(yyvsp[-5].val),&(yyvsp[-3].val),&(yyvsp[-1].val),(void*)0))); }
#line 2292 "cexp.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 631 "cexp.y" /* yacc.c:1646  */
    {	EVAL(CHECK(cexpTVFnCall(&(yyval.val),&(yyvsp[-19].val),&(yyvsp[-17].val),&(yyvsp[-15].val),&(yyvsp[-13].val),&(yyvsp[-11].val),&(yyvsp[-9].val),&(yyvsp[-7].val),&(yyvsp[-5].val),&(yyvsp[-3].val),&(yyvsp[-1].val),(void*)0))); }
#line 2298 "cexp.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 633 "cexp.y" /* yacc.c:1646  */
    {	EVAL(CHECK(cexpTVFnCall(&(yyval.val),&(yyvsp[-21].val),&(yyvsp[-19].val),&(yyvsp[-17].val),&(yyvsp[-15].val),&(yyvsp[-13].val),&(yyvsp[-11].val),&(yyvsp[-9].val),&(yyvsp[-7].val),&(yyvsp[-5].val),&(yyvsp[-3].val),&(yyvsp[-1].val),(void*)0))); }
#line 2304 "cexp.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 635 "cexp.y" /* yacc.c:1646  */
    {	EVAL(CHECK(cexpTVFnCall(&(yyval.val),&(yyvsp[-23].val),&(yyvsp[-21].val),&(yyvsp[-19].val),&(yyvsp[-17].val),&(yyvsp[-15].val),&(yyvsp[-13].val),&(yyvsp[-11].val),&(yyvsp[-9].val),&(yyvsp[-7].val),&(yyvsp[-5].val),&(yyvsp[-3].val),&(yyvsp[-1].val),(void*)0))); }
#line 2310 "cexp.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 637 "cexp.y" /* yacc.c:1646  */
    {	EVAL(CHECK(cexpTVFnCall(&(yyval.val),&(yyvsp[-25].val),&(yyvsp[-23].val),&(yyvsp[-21].val),&(yyvsp[-19].val),&(yyvsp[-17].val),&(yyvsp[-15].val),&(yyvsp[-13].val),&(yyvsp[-11].val),&(yyvsp[-9].val),&(yyvsp[-7].val),&(yyvsp[-5].val),&(yyvsp[-3].val),&(yyvsp[-1].val),(void*)0))); }
#line 2316 "cexp.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 639 "cexp.y" /* yacc.c:1646  */
    {	EVAL(CHECK(cexpTVFnCall(&(yyval.val),&(yyvsp[-27].val),&(yyvsp[-25].val),&(yyvsp[-23].val),&(yyvsp[-21].val),&(yyvsp[-19].val),&(yyvsp[-17].val),&(yyvsp[-15].val),&(yyvsp[-13].val),&(yyvsp[-11].val),&(yyvsp[-9].val),&(yyvsp[-7].val),&(yyvsp[-5].val),&(yyvsp[-3].val),&(yyvsp[-1].val),(void*)0))); }
#line 2322 "cexp.tab.c" /* yacc.c:1646  */
    break;


#line 2326 "cexp.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (ctx, YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (ctx, yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, ctx);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, ctx);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (ctx, YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, ctx);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp, ctx);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 643 "cexp.y" /* yacc.c:1906  */



/* add a string to the line string table returning its index
 * RETURNS a negative number on error
 */
LString
lstAddString(CexpParserCtx env, char *string)
{
LString			rval=0;
LString			*chppt;
int				i;
	for (i=0,chppt=env->lineStrTbl;
		 i<sizeof(env->lineStrTbl)/sizeof(env->lineStrTbl[0]);
		 i++,chppt++) {
		if (*chppt) {
			if  (strcmp(string,*chppt))			continue;
			else /* string exists already */	return *chppt;
		}
		/* string exists already */
		if ((rval=malloc(strlen(string)+1))) {
			*chppt=rval;
			strcpy(rval,string);
			return (LString) rval;
		}
	}
	if ( env->errf )
		fprintf(env->errf,"Cexp: Line String Table exhausted\n");
	return 0;
}

#define ch ((int)(*pa->chpt))
#define getch() do { (pa->chpt)++;} while(0)

/* helper to save typing */
static int
prerr(CexpParserCtx ctx)
{
	errmsg(ctx, "(yylex): buffer overflow\n");
	return LEXERR;
}

static int
scanfrac(char *buf, char *chpt, int size, YYSTYPE *rval, CexpParserCtx pa, int rejectLonely)
{
int hasE=0;
	/* first, we put ch to the buffer */
	*(chpt++)=(char)ch; size--; /* assume it's still safe */
	getch();
	if ( isdigit(ch) || 'E' == toupper(ch) ) {
		do {
			while(isdigit(ch) && size) {
				*(chpt++)=(char)ch; if (!--size) return prerr(pa);
				getch();
			}
			if (toupper(ch)=='E' && !hasE) {
				*(chpt++)=(char)'E'; if (!--size) return prerr(pa);
				getch();
				if ('-'==ch || '+'==ch) {
					*(chpt++)=(char)ch; if (!--size) return prerr(pa);
					getch();
				}
				hasE=1;
			} else {
		break; /* the loop */
			}
		} while (1);
	} else {
		if ( rejectLonely )
			return '.';
	}
	*chpt=0;
	rval->val.type=TDouble;
	rval->val.tv.d=strtod(buf,&chpt);
	return *chpt ? LEXERR : NUMBER;
}

int
yylex(YYSTYPE *rval, CexpParserCtx pa)
{
unsigned long num;
int           limit=sizeof(pa->sbuf)-1;
char          *chpt;

	while (' '==ch || '\t'==ch)
		getch();

	if (isdigit(ch) || '\''==ch) {
		/* a number */
		num=0;

		if ('\''==ch) {
			/* char constant */
			getch();
			num=ch;
			if ('\\'==ch) {
				getch();
				/* escape sequence */
				switch (ch) {
					case 't': num='\t'; break;
					case 'n': num='\n'; break;
					case 'r': num='\r'; break;
					case '0': num=0;	break;
					case 'f': num='\f';	break;
					case '\\': num='\\';break;
					case '\'': num='\'';break;
					default:
						wrnmsg(pa, ": unknown escape sequence, using unescaped char\n");
						num=ch;
					break;
				}
			}
			getch();
			if ('\''!=ch)
				wrnmsg(pa, ": missing closing '\n");
			else
				getch();
			rval->val.tv.c=(unsigned char)num;
			rval->val.type=TUChar;
			return NUMBER;
		}
		chpt=pa->sbuf;
		if ('0'==ch) {
			
			/* hex, octal or fractional */
			*(chpt++)=(char)ch; limit--;
			getch();
			if ('x'==ch) {
				/* a hex number */
				getch();
				while (isxdigit(ch)) {
					num<<=4;
					if (ch>='a')		num+=ch-'a'+10;
					else if (ch>='A')	num+=ch-'A'+10;
					else				num+=ch-'0';
					getch();
				}
			} else if ('.'==ch) {
				/* a decimal number */
				return scanfrac(pa->sbuf,chpt,limit,rval,pa,0);
			} else {
				/* OK, it's octal */
				while ('0'<=ch && ch<'8') {
					num<<=3;
					num+=ch-'0';
					getch();
				}
			}
		} else {
			/* so it must be base 10 */
			do {
				*(chpt++)=(char)ch; limit--;
				num=10*num+(ch-'0');
				getch();
			} while (isdigit(ch) && limit);
			if (!limit) {
				return prerr(pa);
			}
			if ('.'==ch) {
				/* it's a fractional number */
				return scanfrac(pa->sbuf,chpt,limit,rval,pa,0);
			}
		}
		rval->val.tv.l=num;
		rval->val.type=TULong;
		return NUMBER;
	} else if ('.'==ch) {
		/* perhaps also a fractional number */
		return
			scanfrac(pa->sbuf,pa->sbuf,limit,rval,pa,1);
	} else if (isalpha(ch) || ISIDENTCHAR(ch)) {
		/* slurp in an identifier */
		chpt=pa->sbuf;
		do {
			*(chpt++)=ch;
			getch();
		} while ((isalnum(ch)||ISIDENTCHAR(ch)) && (--limit > 0));
		*chpt=0;
		if (!limit)
			return prerr(pa);
		/* is it one of the type cast keywords? */
		if (!strcmp(pa->sbuf,"char"))
			return KW_CHAR;
		else if (!strcmp(pa->sbuf,"short"))
			return KW_SHORT;
		else if (!strcmp(pa->sbuf,"int"))
			return KW_INT;
		else if (!strcmp(pa->sbuf,"long"))
			return KW_LONG;
		else if (!strcmp(pa->sbuf,"float"))
			return KW_FLOAT;
		else if (!strcmp(pa->sbuf,"double"))
			return KW_DOUBLE;
		else if ((rval->sym=cexpSymLookup(pa->sbuf, 0)))
			return CEXP_TYPE_FUNQ(rval->sym->value.type) ? FUNC : VAR;
		else if ((rval->sym=cexpVarLookup(pa->sbuf,0))) {
			return UVAR;
		}

		/* it's a currently undefined symbol */
		return (rval->lstr=lstAddString(pa,pa->sbuf)) ? IDENT : LEXERR;
	} else if ('"'==ch) {
		/* generate a string constant */
		char *dst;
		const char *strStart;
		dst=pa->sbuf-1;
		strStart = pa->chpt+1;
		do {
		skipit:	
			dst++; limit--;
			getch();
			*dst=ch;
			if ('\\'==ch) {
				getch();
				switch (ch) {
					case 'n':	*dst='\n'; goto skipit;
					case 'r':	*dst='\r'; goto skipit;
					case 't':	*dst='\t'; goto skipit;
					case '"':	*dst='"';  goto skipit;
					case '\\':	           goto skipit;
					case '0':	*dst=0;    goto skipit;
					default:
						dst++; limit--; *dst=ch;
						break;
				}
			}
			if ('"'==ch) {
				*dst=0;
				getch();
				rval->val.type=TUCharP;
#ifdef CONFIG_STRINGS_LIVE_FOREVER
				rval->val.tv.p=cexpStrLookup(pa->sbuf,1);
#else
				rval->val.tv.p=lstAddString(pa,pa->sbuf);
#endif
				return rval->val.tv.p ? STR_CONST : LEXERR;
			}
		} while (ch && limit>2);
		return LEXERR_INCOMPLETE_STRING - (pa->chpt - strStart);
	} else {
		long rv=ch;
		if (rv) getch();

		/* comments? skip the rest of the line */
		if ('#'==rv || ('/'==ch && '/'==rv)) {
			while (ch && '\n'!=rv) {
				rv=ch;
				getch();
			}
			return '\n';
		}

		/* it's any kind of 'special' character such as
		 * an operator etc.
		 */

		/* check for 'double' character operators '&&' '||' '<<' '>>' '==' '!=' '<=' '>=' */
		switch (ch) { /* the second character */
			default: break;

			case '+': if ('+'==rv) rv=PP;  break;
			case '-': if ('-'==rv) rv=MM;  break;

			case '&': if ('&'==rv) rv=AND; break;
			case '|': if ('|'==rv) rv=OR;  break;

			case '<': if ('<'==rv) rv=SHL; break;
			case '>': if ('>'==rv) rv=SHR; break;


			case '=':
				switch (rv) {
					default: break;
					case '=': rv=EQ;	break;
					case '!': rv=NE;	break;
					case '<': rv=LE;	break;
					case '>': rv=GE;	break;
					case '+': rv=MODOP; rval->binop=OAdd;	break;
					case '-': rv=MODOP; rval->binop=OSub;	break;
					case '*': rv=MODOP; rval->binop=OMul;	break;
					case '/': rv=MODOP; rval->binop=ODiv;	break;
					case '%': rv=MODOP; rval->binop=OMod;	break;
					case '&': rv=MODOP; rval->binop=OAnd;	break;
					case '^': rv=MODOP; rval->binop=OXor;	break;
					case '|': rv=MODOP; rval->binop=OOr;	break;
				}
			break;
		}
		if (rv>255) getch(); /* skip second char */
		/* yyparse cannot deal with '\0' chars, so we translate it back to '\n'...*/
		if ((SHL==rv || SHR==rv) && '=' == ch) {
			getch();
			rval->binop = (SHL==rv ? OShL : OShR);
			rv=MODOP;
		}
		return rv ? rv : '\n';
	}
	return 0; /* seems to mean ERROR/EOF */
}

/* re-initialize a parser context to parse 'buf';
 * If called with a NULL argument, a new
 * context is created and initialized.
 *
 * RETURNS: initialized context
 */

static void
releaseStrings(CexpParserCtx ctx)
{
int			i;
char		**chppt;

	/* release the line string table */
	for (i=0,chppt=ctx->lineStrTbl;
		 i<sizeof(ctx->lineStrTbl)/sizeof(ctx->lineStrTbl[0]);
		 i++,chppt++) {
		if (*chppt) {
			free(*chppt);
			*chppt=0;
		}
	}
}

CexpParserCtx
cexpCreateParserCtx(FILE *outf, FILE *errf, RedirCb redir_cb, void *uarg)
{
CexpParserCtx	ctx=0;

	assert(ctx=(CexpParserCtx)malloc(sizeof(*ctx)));
	memset(ctx,0,sizeof(*ctx));
	ctx->rval_sym.value.type = TULong;
	ctx->rval.l              = 0;
	ctx->rval_sym.value.ptv  = &ctx->rval;
	ctx->rval_sym.name       = CEXP_LAST_RESULT_VAR_NAME;
	ctx->rval_sym.size       = sizeof(ctx->rval);
	ctx->rval_sym.flags      = 0;
	ctx->rval_sym.help       = "value of last evaluated expression";
	ctx->outf                = outf;
	ctx->errf                = errf;
	ctx->status              = -1;
	ctx->o_stdout            = 0;
	ctx->o_stderr            = 0;
	ctx->o_stdin             = 0;
	ctx->o_outf              = 0;
	ctx->o_errf              = 0;
	ctx->redir_cb            = redir_cb;
	ctx->cb_arg              = uarg;

	return ctx;
}

void
cexpResetParserCtx(CexpParserCtx ctx, const char *buf)
{
	ctx->chpt=buf;
	ctx->evalInhibit=0;
	ctx->status = -1;
	cexpUnredir(ctx);
	releaseStrings(ctx);
}

void
cexpFreeParserCtx(CexpParserCtx ctx)
{
	cexpUnredir(ctx);
	releaseStrings(ctx);
	free(ctx);
}

CexpSym
cexpParserCtxGetResult(CexpParserCtx ctx)
{
	return &ctx->rval_sym;
}

int
cexpParserCtxGetStatus(CexpParserCtx ctx)
{
	return ctx->status;
}

void
yyerror(CexpParserCtx ctx, const char*msg)
{
	if ( ctx->errf ) {
		fprintf(ctx->errf,"Cexp syntax error: %s\n", msg);
	}
}

/* Other errors that are not syntax errors */
static void
errmsg(CexpParserCtx ctx, const char *fmt, ...)
{
va_list ap;
	if ( ctx->errf ) {
		fprintf(ctx->errf,"Cexp error ");
		va_start(ap, fmt);
		vfprintf(ctx->errf, fmt, ap); 
		va_end(ap);
	}
}

static void
wrnmsg(CexpParserCtx ctx, const char *fmt, ...)
{
va_list ap;
	if ( ctx->errf ) {
		fprintf(ctx->errf,"Cexp warning ");
		va_start(ap, fmt);
		vfprintf(ctx->errf, fmt, ap); 
		va_end(ap);
	}
}


static int
cexpRedir(CexpParserCtx ctx, unsigned long op, void *oarg, void *iarg)
{
const char *opath = oarg;
const char *ipath = iarg;
FILE       *nof = 0, *nif = 0;
const char *mode;

	if ( !oarg && !iarg ) {
		errmsg(ctx, "(cexpRedir): NO PATH ARGUMENT ??\n");
		return -1;
	}

	if ( opath && (ctx->o_stdout || ctx->o_stderr) ) {
		errmsg(ctx, "(cexpRedir): OUTPUT ALREADY REDIRECTED ??\n");
		return -1;
	}

	if ( ipath && ctx->o_stdin ) {
		errmsg(ctx, "(cexpRedir): INPUT ALREADY REDIRECTED ??\n");
		return -1;
	}

	if ( ipath ) {
		if ( ! (nif = fopen(ipath, "r")) ) {
			if ( ctx->errf )
				fprintf(ctx->errf, "cexpRedir (IN) ERROR - unable to open file: %s\n", strerror(errno));
			return -1;
		}
		ctx->o_stdin = stdin;
		stdin        = nif;
	}

	if ( opath ) {
		if ( REDIRAPPEND == op || REDIRAPPENDBOTH == op )
			mode = "a";
		else
			mode = "w";

		if ( ! (nof = fopen(opath, mode)) ) {
			if ( ctx->errf )
				fprintf(ctx->errf, "cexpRedir (OUT) ERROR - unable to open file: %s\n", strerror(errno));
			if ( nif ) {
				stdin = ctx->o_stdin;
				fclose(nif);
			}
			return -1;
		}
		fflush(stdout);
		ctx->o_stdout = stdout;
		stdout = nof;

		if ( ctx->outf ) {
			fflush(ctx->outf);
			ctx->o_outf = ctx->outf;
			ctx->outf   = nof;
		}

		if ( REDIRBOTH == op || REDIRAPPENDBOTH == op ) {
			fflush(stderr);
			ctx->o_stderr = stderr;
			stderr = nof;

			if ( ctx->errf ) {
				fflush(ctx->errf);
				ctx->o_errf = ctx->errf;
				ctx->errf   = nof;
			}
		}
	}

	if ( ctx->redir_cb )
		ctx->redir_cb(ctx, ctx->cb_arg);

	return 0;
}

static void
cexpUnredir(CexpParserCtx ctx)
{
	if ( ctx->o_stdout ) {
		fclose(stdout);
		stdout = ctx->o_stdout;
		ctx->o_stdout = 0;
	}
	if ( ctx->o_outf ) {
		ctx->outf   = ctx->o_outf;
		ctx->o_outf = 0;
	}

	if ( ctx->o_stderr ) {
		stderr = ctx->o_stderr;
		ctx->o_stderr = 0;
	}
	if ( ctx->o_errf ) {
		ctx->errf   = ctx->o_errf;
		ctx->o_errf = 0;
	}

	if ( ctx->o_stdin ) {
		fclose(stdin);
		stdin = ctx->o_stdin;
		ctx->o_stdin = 0;
	}

	if ( ctx->redir_cb )
		ctx->redir_cb(ctx, ctx->cb_arg);
}

/* Trivial wrapper so that we can make sure
 * redirections are undone always and before
 * cexpparse() returns to the caller.
 */
int
cexpparse(CexpParserCtx ctx)
{
int rval;

	rval = __cexpparse(ctx);	
	cexpUnredir( ctx );

	return rval;
}
