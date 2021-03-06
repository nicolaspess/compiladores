/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.5"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 268 of yacc.c  */
#line 1 "parser.y"

#include <stdio.h>
#include <stdlib.h>
#include "ast.h"
extern int getLineNumber();


/* Line 268 of yacc.c  */
#line 79 "y.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     KW_CHAR = 256,
     KW_INT = 257,
     KW_FLOAT = 259,
     KW_IF = 261,
     KW_THEN = 262,
     KW_ELSE = 263,
     KW_WHILE = 264,
     KW_FOR = 265,
     KW_READ = 266,
     KW_PRINT = 267,
     KW_RETURN = 268,
     KW_TO = 269,
     OPERATOR_LE = 270,
     OPERATOR_GE = 271,
     OPERATOR_EQ = 272,
     OPERATOR_NE = 273,
     OPERATOR_AND = 274,
     OPERATOR_OR = 275,
     TK_IDENTIFIER = 280,
     LIT_INTEGER = 281,
     LIT_REAL = 282,
     LIT_CHAR = 283,
     LIT_STRING = 284,
     TOKEN_ERROR = 290
   };
#endif
/* Tokens.  */
#define KW_CHAR 256
#define KW_INT 257
#define KW_FLOAT 259
#define KW_IF 261
#define KW_THEN 262
#define KW_ELSE 263
#define KW_WHILE 264
#define KW_FOR 265
#define KW_READ 266
#define KW_PRINT 267
#define KW_RETURN 268
#define KW_TO 269
#define OPERATOR_LE 270
#define OPERATOR_GE 271
#define OPERATOR_EQ 272
#define OPERATOR_NE 273
#define OPERATOR_AND 274
#define OPERATOR_OR 275
#define TK_IDENTIFIER 280
#define LIT_INTEGER 281
#define LIT_REAL 282
#define LIT_CHAR 283
#define LIT_STRING 284
#define TOKEN_ERROR 290




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 293 of yacc.c  */
#line 8 "parser.y"
 
    hash_Node *symbol;
    AST *ast;



/* Line 293 of yacc.c  */
#line 174 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 343 of yacc.c  */
#line 186 "y.tab.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  8
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   294

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  23
/* YYNRULES -- Number of rules.  */
#define YYNRULES  73
/* YYNRULES -- Number of states.  */
#define YYNSTATES  150

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   292

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    32,     2,    37,     2,    31,    46,     2,
      40,    41,    29,    27,    43,    28,     2,    30,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    42,    36,
      33,    35,    34,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    38,     2,    39,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    44,     2,    45,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     3,     4,     2,     5,
       2,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,     2,     2,     2,     2,
      21,    22,    23,    24,    25,     2,     2,     2,     2,     2,
      26,     1,     2
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     8,     9,    15,    20,    27,    35,
      42,    44,    46,    48,    50,    52,    54,    56,    59,    60,
      63,    64,    67,    71,    72,    75,    76,    80,    83,    87,
      88,    90,    93,    96,    99,   101,   103,   104,   111,   117,
     125,   134,   138,   143,   148,   155,   158,   161,   162,   164,
     167,   170,   175,   179,   181,   185,   189,   193,   197,   201,
     205,   209,   212,   216,   220,   224,   228,   232,   236,   241,
     244,   248,   249,   251
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      48,     0,    -1,    49,    -1,    50,    49,    -1,    -1,    51,
      21,    35,    52,    36,    -1,    51,    37,    21,    36,    -1,
      51,    37,    21,    35,    52,    36,    -1,    51,    21,    38,
      52,    39,    53,    36,    -1,    51,    21,    40,    55,    41,
      58,    -1,     3,    -1,     4,    -1,     5,    -1,    24,    -1,
      22,    -1,    23,    -1,    25,    -1,    42,    54,    -1,    -1,
      52,    54,    -1,    -1,    57,    56,    -1,    43,    57,    56,
      -1,    -1,    51,    21,    -1,    -1,    44,    59,    45,    -1,
      61,    60,    -1,    36,    61,    60,    -1,    -1,    58,    -1,
      11,    21,    -1,    12,    64,    -1,    13,    66,    -1,    63,
      -1,    62,    -1,    -1,     6,    40,    66,    41,     7,    61,
      -1,     9,    40,    66,    41,    61,    -1,    10,    40,    63,
      14,    66,    41,    61,    -1,     6,    40,    66,    41,     7,
      61,     8,    61,    -1,    21,    35,    66,    -1,    37,    21,
      35,    66,    -1,    46,    21,    35,    66,    -1,    21,    38,
      66,    39,    35,    66,    -1,    66,    65,    -1,    66,    65,
      -1,    -1,    21,    -1,    37,    21,    -1,    46,    21,    -1,
      21,    38,    66,    39,    -1,    40,    66,    41,    -1,    52,
      -1,    66,    27,    66,    -1,    66,    28,    66,    -1,    66,
      29,    66,    -1,    66,    30,    66,    -1,    66,    31,    66,
      -1,    66,    34,    66,    -1,    66,    33,    66,    -1,    32,
      66,    -1,    66,    15,    66,    -1,    66,    16,    66,    -1,
      66,    17,    66,    -1,    66,    18,    66,    -1,    66,    19,
      66,    -1,    66,    20,    66,    -1,    21,    40,    67,    41,
      -1,    69,    68,    -1,    43,    69,    68,    -1,    -1,    66,
      -1,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    71,    71,    74,    75,    78,    79,    80,    81,    82,
      85,    86,    87,    90,    91,    92,    93,    96,    97,   100,
     101,   104,   107,   108,   111,   112,   115,   118,   121,   122,
     125,   126,   127,   128,   129,   130,   131,   134,   135,   136,
     137,   140,   141,   142,   143,   146,   149,   150,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   176,
     179,   180,   183,   184
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "KW_CHAR", "KW_INT", "KW_FLOAT", "KW_IF",
  "KW_THEN", "KW_ELSE", "KW_WHILE", "KW_FOR", "KW_READ", "KW_PRINT",
  "KW_RETURN", "KW_TO", "OPERATOR_LE", "OPERATOR_GE", "OPERATOR_EQ",
  "OPERATOR_NE", "OPERATOR_AND", "OPERATOR_OR", "TK_IDENTIFIER",
  "LIT_INTEGER", "LIT_REAL", "LIT_CHAR", "LIT_STRING", "TOKEN_ERROR",
  "'+'", "'-'", "'*'", "'/'", "'%'", "'!'", "'<'", "'>'", "'='", "';'",
  "'#'", "'['", "']'", "'('", "')'", "':'", "','", "'{'", "'}'", "'&'",
  "$accept", "programa", "listaDeDeclaracoes", "declaracoes", "tipo",
  "literal", "inicializacao", "inicializacao2", "listaDeParametros",
  "fimDeParametros", "parametro", "bloco", "blocoDeComandos",
  "fimDeComando", "comando", "controleFluxo", "atribuicao", "argprint",
  "argprint2", "expressao", "listaDeArgumentos", "fimDeArgumentos",
  "argfunc", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   291,   292,   256,   257,   259,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   280,   281,   282,   283,   284,   290,    43,    45,    42,
      47,    37,    33,    60,    62,    61,    59,    35,    91,    93,
      40,    41,    58,    44,   123,   125,    38
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    47,    48,    49,    49,    50,    50,    50,    50,    50,
      51,    51,    51,    52,    52,    52,    52,    53,    53,    54,
      54,    55,    56,    56,    57,    57,    58,    59,    60,    60,
      61,    61,    61,    61,    61,    61,    61,    62,    62,    62,
      62,    63,    63,    63,    63,    64,    65,    65,    66,    66,
      66,    66,    66,    66,    66,    66,    66,    66,    66,    66,
      66,    66,    66,    66,    66,    66,    66,    66,    66,    67,
      68,    68,    69,    69
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     5,     4,     6,     7,     6,
       1,     1,     1,     1,     1,     1,     1,     2,     0,     2,
       0,     2,     3,     0,     2,     0,     3,     2,     3,     0,
       1,     2,     2,     2,     1,     1,     0,     6,     5,     7,
       8,     3,     4,     4,     6,     2,     2,     0,     1,     2,
       2,     4,     3,     1,     3,     3,     3,     3,     3,     3,
       3,     2,     3,     3,     3,     3,     3,     3,     4,     2,
       3,     0,     1,     0
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,    10,    11,    12,     0,     2,     4,     0,     1,     3,
       0,     0,     0,     0,    25,     0,    14,    15,    13,    16,
       0,     0,     0,     0,    23,     0,     6,     5,    18,    24,
       0,    25,    21,     0,    20,     0,    36,     9,    23,     7,
      20,    17,     8,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    30,     0,    29,    35,    34,    22,    19,     0,
       0,     0,    31,    48,     0,     0,     0,     0,    53,    32,
      47,    33,     0,     0,     0,     0,    26,    36,    27,     0,
       0,     0,     0,    73,    61,    49,     0,    50,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    45,    47,    41,     0,     0,     0,    29,     0,    36,
       0,     0,    72,     0,    71,    52,    62,    63,    64,    65,
      66,    67,    54,    55,    56,    57,    58,    60,    59,    46,
       0,    42,    43,    28,    36,    38,     0,    51,    68,    73,
      69,     0,    37,    36,    71,    44,    36,    39,    70,    40
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     4,     5,     6,     7,    68,    35,    41,    23,    32,
      24,    52,    53,    78,    54,    55,    56,    69,   101,   102,
     113,   140,   114
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -73
static const yytype_int16 yypact[] =
{
      35,   -73,   -73,   -73,    18,   -73,    35,    -5,   -73,   -73,
      -7,     6,   -15,   -15,    35,   -14,   -73,   -73,   -73,   -73,
      -2,    21,    34,    20,    14,   -15,   -73,   -73,    28,   -73,
      29,    35,   -73,    50,   -15,    52,    66,   -73,    14,   -73,
     -15,   -73,   -73,    45,    53,    55,    68,    59,    59,   -24,
      69,    76,   -73,    56,    62,   -73,   -73,   -73,   -73,    59,
      59,   -17,   -73,    16,    59,    79,    59,    81,   -73,   -73,
      98,   260,    59,    59,    71,    72,   -73,    66,   -73,   130,
     150,    90,    59,    59,    49,   -73,   170,   -73,    59,    59,
      59,    59,    59,    59,    59,    59,    59,    59,    59,    59,
      59,   -73,    98,   260,   210,    59,    59,    62,   101,    66,
      59,   235,   260,    70,    91,   -73,   -73,   -73,   -73,   -73,
     -73,   -73,    49,    49,    49,    49,    49,    49,    49,   -73,
      74,   260,   260,   -73,    66,   -73,   190,   -73,   -73,    59,
     -73,    59,   116,    66,    91,   260,    66,   -73,   -73,   -73
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -73,   -73,   127,   -73,    -8,   -10,   -73,    96,   -73,    99,
     108,   110,   -73,    36,   -72,   -73,    80,   -73,    40,   -47,
     -73,     7,    13
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      70,    71,    20,    21,    49,   107,    22,    16,    17,    18,
      19,    72,    79,    80,    73,    33,    10,    84,     8,    86,
      50,    25,    26,    22,    40,   103,   104,    15,    12,    51,
      40,    13,    11,    14,    27,   111,   112,   135,     1,     2,
       3,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,    82,    29,    83,    31,   131,   132,
      28,    30,   142,   136,    88,    89,    90,    91,    92,    93,
      34,   147,    43,    36,   149,    44,    45,    46,    47,    48,
      63,    16,    17,    18,    19,    59,    39,    49,    42,    62,
      74,    64,   112,    60,   145,    61,    65,    75,    77,    66,
      85,    76,    87,    50,   110,    67,   105,   106,   134,   141,
      36,   138,    51,    88,    89,    90,    91,    92,    93,    63,
      16,    17,    18,    19,   146,    94,    95,    96,    97,    98,
      64,    99,   100,     9,   139,    65,    58,    57,    66,    38,
      37,    81,   129,   133,    67,    88,    89,    90,    91,    92,
      93,   148,   144,     0,     0,     0,     0,    94,    95,    96,
      97,    98,     0,    99,   100,    88,    89,    90,    91,    92,
      93,   108,     0,     0,     0,     0,     0,    94,    95,    96,
      97,    98,     0,    99,   100,    88,    89,    90,    91,    92,
      93,   109,     0,     0,     0,     0,     0,    94,    95,    96,
      97,    98,     0,    99,   100,    88,    89,    90,    91,    92,
      93,   115,     0,     0,     0,     0,     0,    94,    95,    96,
      97,    98,     0,    99,   100,    88,    89,    90,    91,    92,
      93,   143,     0,     0,     0,     0,     0,    94,    95,    96,
      97,    98,     0,    99,   100,     0,     0,     0,     0,   130,
      88,    89,    90,    91,    92,    93,     0,     0,     0,     0,
       0,     0,    94,    95,    96,    97,    98,     0,    99,   100,
       0,     0,     0,     0,   137,    88,    89,    90,    91,    92,
      93,     0,     0,     0,     0,     0,     0,    94,    95,    96,
      97,    98,     0,    99,   100
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-73))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      47,    48,    12,    13,    21,    77,    14,    22,    23,    24,
      25,    35,    59,    60,    38,    25,    21,    64,     0,    66,
      37,    35,    36,    31,    34,    72,    73,    21,    35,    46,
      40,    38,    37,    40,    36,    82,    83,   109,     3,     4,
       5,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,    38,    21,    40,    43,   105,   106,
      39,    41,   134,   110,    15,    16,    17,    18,    19,    20,
      42,   143,     6,    44,   146,     9,    10,    11,    12,    13,
      21,    22,    23,    24,    25,    40,    36,    21,    36,    21,
      21,    32,   139,    40,   141,    40,    37,    21,    36,    40,
      21,    45,    21,    37,    14,    46,    35,    35,     7,    35,
      44,    41,    46,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,     8,    27,    28,    29,    30,    31,
      32,    33,    34,     6,    43,    37,    40,    38,    40,    31,
      30,    61,   102,   107,    46,    15,    16,    17,    18,    19,
      20,   144,   139,    -1,    -1,    -1,    -1,    27,    28,    29,
      30,    31,    -1,    33,    34,    15,    16,    17,    18,    19,
      20,    41,    -1,    -1,    -1,    -1,    -1,    27,    28,    29,
      30,    31,    -1,    33,    34,    15,    16,    17,    18,    19,
      20,    41,    -1,    -1,    -1,    -1,    -1,    27,    28,    29,
      30,    31,    -1,    33,    34,    15,    16,    17,    18,    19,
      20,    41,    -1,    -1,    -1,    -1,    -1,    27,    28,    29,
      30,    31,    -1,    33,    34,    15,    16,    17,    18,    19,
      20,    41,    -1,    -1,    -1,    -1,    -1,    27,    28,    29,
      30,    31,    -1,    33,    34,    -1,    -1,    -1,    -1,    39,
      15,    16,    17,    18,    19,    20,    -1,    -1,    -1,    -1,
      -1,    -1,    27,    28,    29,    30,    31,    -1,    33,    34,
      -1,    -1,    -1,    -1,    39,    15,    16,    17,    18,    19,
      20,    -1,    -1,    -1,    -1,    -1,    -1,    27,    28,    29,
      30,    31,    -1,    33,    34
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,    48,    49,    50,    51,     0,    49,
      21,    37,    35,    38,    40,    21,    22,    23,    24,    25,
      52,    52,    51,    55,    57,    35,    36,    36,    39,    21,
      41,    43,    56,    52,    42,    53,    44,    58,    57,    36,
      52,    54,    36,     6,     9,    10,    11,    12,    13,    21,
      37,    46,    58,    59,    61,    62,    63,    56,    54,    40,
      40,    40,    21,    21,    32,    37,    40,    46,    52,    64,
      66,    66,    35,    38,    21,    21,    45,    36,    60,    66,
      66,    63,    38,    40,    66,    21,    66,    21,    15,    16,
      17,    18,    19,    20,    27,    28,    29,    30,    31,    33,
      34,    65,    66,    66,    66,    35,    35,    61,    41,    41,
      14,    66,    66,    67,    69,    41,    66,    66,    66,    66,
      66,    66,    66,    66,    66,    66,    66,    66,    66,    65,
      39,    66,    66,    60,     7,    61,    66,    39,    41,    43,
      68,    35,    61,    41,    69,    66,     8,    61,    68,    61
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* This macro is provided for backward compatibility. */

#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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
  YYSIZE_T yysize0 = yytnamerr (0, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  YYSIZE_T yysize1;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = 0;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
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
                yysize1 = yysize + yytnamerr (0, yytname[yyx]);
                if (! (yysize <= yysize1
                       && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                  return 2;
                yysize = yysize1;
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

  yysize1 = yysize + yystrlen (yyformat);
  if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
    return 2;
  yysize = yysize1;

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

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
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
  int yytoken;
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

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

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
      yychar = YYLEX;
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
  *++yyvsp = yylval;

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
     `$$ = $1'.

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

/* Line 1806 of yacc.c  */
#line 71 "parser.y"
    { astPrint((yyvsp[(1) - (1)].ast), 0);  printSource((yyvsp[(1) - (1)].ast));}
    break;

  case 3:

/* Line 1806 of yacc.c  */
#line 74 "parser.y"
    { (yyval.ast) = astCreate(AST_LDEC, 0, (yyvsp[(1) - (2)].ast), (yyvsp[(2) - (2)].ast), 0, 0); }
    break;

  case 4:

/* Line 1806 of yacc.c  */
#line 75 "parser.y"
    { (yyval.ast) = 0; }
    break;

  case 5:

/* Line 1806 of yacc.c  */
#line 78 "parser.y"
    { (yyval.ast) = astCreate(AST_DEC, (yyvsp[(2) - (5)].symbol), (yyvsp[(1) - (5)].ast), (yyvsp[(4) - (5)].ast), 0, 0); }
    break;

  case 6:

/* Line 1806 of yacc.c  */
#line 79 "parser.y"
    { (yyval.ast) = astCreate(AST_DECPT, (yyvsp[(3) - (4)].symbol), (yyvsp[(1) - (4)].ast), 0, 0, 0); }
    break;

  case 7:

/* Line 1806 of yacc.c  */
#line 80 "parser.y"
    { (yyval.ast) = astCreate(AST_DECPTASS, (yyvsp[(3) - (6)].symbol), (yyvsp[(1) - (6)].ast), (yyvsp[(5) - (6)].ast), 0, 0); }
    break;

  case 8:

/* Line 1806 of yacc.c  */
#line 81 "parser.y"
    { (yyval.ast) = astCreate(AST_DECARR, (yyvsp[(2) - (7)].symbol), (yyvsp[(1) - (7)].ast), (yyvsp[(4) - (7)].ast), (yyvsp[(6) - (7)].ast), 0); }
    break;

  case 9:

/* Line 1806 of yacc.c  */
#line 82 "parser.y"
    { (yyval.ast) = astCreate(AST_DECFUN, (yyvsp[(2) - (6)].symbol), (yyvsp[(1) - (6)].ast), (yyvsp[(4) - (6)].ast), (yyvsp[(6) - (6)].ast), 0); }
    break;

  case 10:

/* Line 1806 of yacc.c  */
#line 85 "parser.y"
    { (yyval.ast) = astCreate(AST_KWCHAR, 0, 0, 0, 0, 0); }
    break;

  case 11:

/* Line 1806 of yacc.c  */
#line 86 "parser.y"
    { (yyval.ast) = astCreate(AST_KWINT, 0, 0, 0, 0, 0); }
    break;

  case 12:

/* Line 1806 of yacc.c  */
#line 87 "parser.y"
    { (yyval.ast) = astCreate(AST_KWFLOAT, 0, 0, 0, 0, 0); }
    break;

  case 13:

/* Line 1806 of yacc.c  */
#line 90 "parser.y"
    { (yyval.ast) = astCreate(AST_SYMBOL, (yyvsp[(1) - (1)].symbol), 0, 0, 0, 0); }
    break;

  case 14:

/* Line 1806 of yacc.c  */
#line 91 "parser.y"
    { (yyval.ast) = astCreate(AST_SYMBOL, (yyvsp[(1) - (1)].symbol), 0, 0, 0, 0); }
    break;

  case 15:

/* Line 1806 of yacc.c  */
#line 92 "parser.y"
    { (yyval.ast) = astCreate(AST_SYMBOL, (yyvsp[(1) - (1)].symbol), 0, 0, 0, 0); }
    break;

  case 16:

/* Line 1806 of yacc.c  */
#line 93 "parser.y"
    { (yyval.ast) = astCreate(AST_SYMBOL, (yyvsp[(1) - (1)].symbol), 0, 0, 0, 0); }
    break;

  case 17:

/* Line 1806 of yacc.c  */
#line 96 "parser.y"
    { (yyval.ast) = astCreate(AST_INI, 0, (yyvsp[(2) - (2)].ast), 0, 0, 0); }
    break;

  case 18:

/* Line 1806 of yacc.c  */
#line 97 "parser.y"
    { (yyval.ast) = 0; }
    break;

  case 19:

/* Line 1806 of yacc.c  */
#line 100 "parser.y"
    { (yyval.ast) = astCreate(AST_INI2, 0, (yyvsp[(1) - (2)].ast), (yyvsp[(2) - (2)].ast), 0, 0); }
    break;

  case 20:

/* Line 1806 of yacc.c  */
#line 101 "parser.y"
    { (yyval.ast) = 0; }
    break;

  case 21:

/* Line 1806 of yacc.c  */
#line 104 "parser.y"
    { (yyval.ast) = astCreate(AST_LPARAM, 0, (yyvsp[(1) - (2)].ast), (yyvsp[(2) - (2)].ast), 0, 0); }
    break;

  case 22:

/* Line 1806 of yacc.c  */
#line 107 "parser.y"
    { (yyval.ast) = astCreate(AST_FPARAM, 0, (yyvsp[(2) - (3)].ast), (yyvsp[(3) - (3)].ast), 0, 0); }
    break;

  case 23:

/* Line 1806 of yacc.c  */
#line 108 "parser.y"
    { (yyval.ast) = 0; }
    break;

  case 24:

/* Line 1806 of yacc.c  */
#line 111 "parser.y"
    { (yyval.ast) = astCreate(AST_PARAM, (yyvsp[(2) - (2)].symbol), (yyvsp[(1) - (2)].ast), 0, 0, 0); }
    break;

  case 25:

/* Line 1806 of yacc.c  */
#line 112 "parser.y"
    { (yyval.ast) = 0; }
    break;

  case 26:

/* Line 1806 of yacc.c  */
#line 115 "parser.y"
    { (yyval.ast) = astCreate(AST_BLOCO, 0, (yyvsp[(2) - (3)].ast), 0, 0, 0); }
    break;

  case 27:

/* Line 1806 of yacc.c  */
#line 118 "parser.y"
    { (yyval.ast) = astCreate(AST_BLOCOCMD, 0, (yyvsp[(1) - (2)].ast), (yyvsp[(2) - (2)].ast), 0, 0); }
    break;

  case 28:

/* Line 1806 of yacc.c  */
#line 121 "parser.y"
    { (yyval.ast) = astCreate(AST_FIMCMD, 0, (yyvsp[(2) - (3)].ast), (yyvsp[(3) - (3)].ast), 0, 0); }
    break;

  case 29:

/* Line 1806 of yacc.c  */
#line 122 "parser.y"
    { (yyval.ast) = 0; }
    break;

  case 30:

/* Line 1806 of yacc.c  */
#line 125 "parser.y"
    { (yyval.ast) = (yyvsp[(1) - (1)].ast) ;}
    break;

  case 31:

/* Line 1806 of yacc.c  */
#line 126 "parser.y"
    { (yyval.ast) = astCreate(AST_KWREAD, (yyvsp[(2) - (2)].symbol), 0, 0, 0, 0); }
    break;

  case 32:

/* Line 1806 of yacc.c  */
#line 127 "parser.y"
    { (yyval.ast) = astCreate(AST_KWPRINT, 0, (yyvsp[(2) - (2)].ast), 0, 0, 0); }
    break;

  case 33:

/* Line 1806 of yacc.c  */
#line 128 "parser.y"
    { (yyval.ast) = astCreate(AST_KWRETURN, 0, (yyvsp[(2) - (2)].ast), 0, 0, 0); }
    break;

  case 34:

/* Line 1806 of yacc.c  */
#line 129 "parser.y"
    { (yyval.ast) = (yyvsp[(1) - (1)].ast) ;}
    break;

  case 35:

/* Line 1806 of yacc.c  */
#line 130 "parser.y"
    { (yyval.ast) = (yyvsp[(1) - (1)].ast) ;}
    break;

  case 36:

/* Line 1806 of yacc.c  */
#line 131 "parser.y"
    { (yyval.ast) = 0; }
    break;

  case 37:

/* Line 1806 of yacc.c  */
#line 134 "parser.y"
    { (yyval.ast) = astCreate(AST_IFT, 0, (yyvsp[(3) - (6)].ast), (yyvsp[(6) - (6)].ast), 0, 0); }
    break;

  case 38:

/* Line 1806 of yacc.c  */
#line 135 "parser.y"
    { (yyval.ast) = astCreate(AST_WHILE, 0, (yyvsp[(3) - (5)].ast), (yyvsp[(5) - (5)].ast), 0, 0); }
    break;

  case 39:

/* Line 1806 of yacc.c  */
#line 136 "parser.y"
    { (yyval.ast) = astCreate(AST_FOR, 0, (yyvsp[(3) - (7)].ast), (yyvsp[(5) - (7)].ast), (yyvsp[(7) - (7)].ast), 0); }
    break;

  case 40:

/* Line 1806 of yacc.c  */
#line 137 "parser.y"
    { (yyval.ast) = astCreate(AST_IFTE, 0, (yyvsp[(3) - (8)].ast), (yyvsp[(6) - (8)].ast), (yyvsp[(8) - (8)].ast), 0); }
    break;

  case 41:

/* Line 1806 of yacc.c  */
#line 140 "parser.y"
    { (yyval.ast) = astCreate(AST_ASS, (yyvsp[(1) - (3)].symbol), (yyvsp[(3) - (3)].ast), 0, 0, 0); }
    break;

  case 42:

/* Line 1806 of yacc.c  */
#line 141 "parser.y"
    { (yyval.ast) = astCreate(AST_ASSPT1, (yyvsp[(2) - (4)].symbol), (yyvsp[(4) - (4)].ast), 0, 0, 0); }
    break;

  case 43:

/* Line 1806 of yacc.c  */
#line 142 "parser.y"
    { (yyval.ast) = astCreate(AST_ASSPT2, (yyvsp[(2) - (4)].symbol), (yyvsp[(4) - (4)].ast), 0, 0, 0); }
    break;

  case 44:

/* Line 1806 of yacc.c  */
#line 143 "parser.y"
    { (yyval.ast) = astCreate(AST_ASSARR, (yyvsp[(1) - (6)].symbol), (yyvsp[(3) - (6)].ast), (yyvsp[(6) - (6)].ast), 0, 0); }
    break;

  case 45:

/* Line 1806 of yacc.c  */
#line 146 "parser.y"
    { (yyval.ast) = astCreate(AST_PRINTARG, 0, (yyvsp[(1) - (2)].ast), (yyvsp[(2) - (2)].ast), 0, 0); }
    break;

  case 46:

/* Line 1806 of yacc.c  */
#line 149 "parser.y"
    { (yyval.ast) = astCreate(AST_PRINTARG, 0, (yyvsp[(1) - (2)].ast), (yyvsp[(2) - (2)].ast), 0, 0); }
    break;

  case 47:

/* Line 1806 of yacc.c  */
#line 150 "parser.y"
    { (yyval.ast) = 0; }
    break;

  case 48:

/* Line 1806 of yacc.c  */
#line 153 "parser.y"
    { (yyval.ast) = astCreate(AST_SYMBOL, (yyvsp[(1) - (1)].symbol), 0, 0, 0, 0); }
    break;

  case 49:

/* Line 1806 of yacc.c  */
#line 154 "parser.y"
    { (yyval.ast) = astCreate(AST_PT1, (yyvsp[(2) - (2)].symbol), 0, 0, 0, 0); }
    break;

  case 50:

/* Line 1806 of yacc.c  */
#line 155 "parser.y"
    { (yyval.ast) = astCreate(AST_PT2, (yyvsp[(2) - (2)].symbol), 0, 0, 0, 0); }
    break;

  case 51:

/* Line 1806 of yacc.c  */
#line 156 "parser.y"
    { (yyval.ast) = astCreate(AST_ARR, (yyvsp[(1) - (4)].symbol), (yyvsp[(3) - (4)].ast), 0, 0, 0); }
    break;

  case 52:

/* Line 1806 of yacc.c  */
#line 157 "parser.y"
    { (yyval.ast) = astCreate(AST_EXP, 0, (yyvsp[(2) - (3)].ast), 0, 0, 0); }
    break;

  case 53:

/* Line 1806 of yacc.c  */
#line 158 "parser.y"
    { (yyval.ast) = (yyvsp[(1) - (1)].ast) ;}
    break;

  case 54:

/* Line 1806 of yacc.c  */
#line 159 "parser.y"
    { (yyval.ast) = astCreate(AST_ADD, 0, (yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast), 0, 0); }
    break;

  case 55:

/* Line 1806 of yacc.c  */
#line 160 "parser.y"
    { (yyval.ast) = astCreate(AST_SUB, 0, (yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast), 0, 0); }
    break;

  case 56:

/* Line 1806 of yacc.c  */
#line 161 "parser.y"
    { (yyval.ast) = astCreate(AST_MUL, 0, (yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast), 0, 0); }
    break;

  case 57:

/* Line 1806 of yacc.c  */
#line 162 "parser.y"
    { (yyval.ast) = astCreate(AST_DIV, 0, (yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast), 0, 0); }
    break;

  case 58:

/* Line 1806 of yacc.c  */
#line 163 "parser.y"
    { (yyval.ast) = astCreate(AST_MOD, 0, (yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast), 0, 0); }
    break;

  case 59:

/* Line 1806 of yacc.c  */
#line 164 "parser.y"
    { (yyval.ast) = astCreate(AST_BIGGER, 0, (yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast), 0, 0); }
    break;

  case 60:

/* Line 1806 of yacc.c  */
#line 165 "parser.y"
    { (yyval.ast) = astCreate(AST_LESS, 0, (yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast), 0, 0); }
    break;

  case 61:

/* Line 1806 of yacc.c  */
#line 166 "parser.y"
    { (yyval.ast) = astCreate(AST_NOT, 0, (yyvsp[(2) - (2)].ast), 0, 0, 0); }
    break;

  case 62:

/* Line 1806 of yacc.c  */
#line 167 "parser.y"
    { (yyval.ast) = astCreate(AST_LE, 0, (yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast), 0, 0); }
    break;

  case 63:

/* Line 1806 of yacc.c  */
#line 168 "parser.y"
    { (yyval.ast) = astCreate(AST_GE, 0, (yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast), 0, 0); }
    break;

  case 64:

/* Line 1806 of yacc.c  */
#line 169 "parser.y"
    { (yyval.ast) = astCreate(AST_EQ, 0, (yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast), 0, 0); }
    break;

  case 65:

/* Line 1806 of yacc.c  */
#line 170 "parser.y"
    { (yyval.ast) = astCreate(AST_NE, 0, (yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast), 0, 0); }
    break;

  case 66:

/* Line 1806 of yacc.c  */
#line 171 "parser.y"
    { (yyval.ast) = astCreate(AST_AND, 0, (yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast), 0, 0); }
    break;

  case 67:

/* Line 1806 of yacc.c  */
#line 172 "parser.y"
    { (yyval.ast) = astCreate(AST_OR, 0, (yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast), 0, 0); }
    break;

  case 68:

/* Line 1806 of yacc.c  */
#line 173 "parser.y"
    { (yyval.ast) = astCreate(AST_FUNCALL, (yyvsp[(1) - (4)].symbol), (yyvsp[(3) - (4)].ast), 0, 0, 0); }
    break;

  case 69:

/* Line 1806 of yacc.c  */
#line 176 "parser.y"
    { (yyval.ast) = astCreate(AST_ARGFUN, 0, (yyvsp[(1) - (2)].ast), (yyvsp[(2) - (2)].ast), 0, 0);}
    break;

  case 70:

/* Line 1806 of yacc.c  */
#line 179 "parser.y"
    { (yyval.ast) = astCreate(AST_ARGFUNFIM, 0, (yyvsp[(2) - (3)].ast), (yyvsp[(3) - (3)].ast), 0, 0); }
    break;

  case 71:

/* Line 1806 of yacc.c  */
#line 180 "parser.y"
    { (yyval.ast) = 0; }
    break;

  case 72:

/* Line 1806 of yacc.c  */
#line 183 "parser.y"
    { (yyval.ast) = (yyvsp[(1) - (1)].ast) ;}
    break;

  case 73:

/* Line 1806 of yacc.c  */
#line 184 "parser.y"
    { (yyval.ast) = 0; }
    break;



/* Line 1806 of yacc.c  */
#line 2075 "y.tab.c"
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

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
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
        yyerror (yymsgp);
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
		      yytoken, &yylval);
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

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
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


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

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
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
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 2067 of yacc.c  */
#line 186 "parser.y"



int yyerror(char * err)
{
	printf("\nErro de sintaxe! Linha: %d \n", getLineNumber());
	exit(3);
}

