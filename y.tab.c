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
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "final_grammar.y" /* yacc.c:339  */

	#include <bits/stdc++.h>
	#include<string.h>
	#include <string>
	#include <stdio.h>
	#include <stdlib.h>
	#include <map>
	#include <vector>
	#include <fstream>
	#include<stack>
	using namespace std;
	#define YYSTYPE holder_union
	extern int yyparse(void);
	extern int yylex();
	extern int mylineno ;
	extern char* yytext ;
	extern int yyleng;
	ofstream fp;
	
	void yyerror(string);
	int flag=0;
	struct node_struct {
		string code_node;
		vector<node_struct*> v_node;
		string id_node;
		string dtype_node;
	};
	union holder_union {
		node_struct* node_holder;
		char* s_holder;
	};
	vector< map<string,string> > symbol_table(3000);

	map<string,string> symbol_global;
	int scope_var = 0;

	int global_scope_var=2000;
	bool semant_error = false;
	bool syntacticError = false;
	int counter_par=0;
	int get_scope(string id)
	{
		for(int i=scope_var;i>=0;i--)
		{
			if(symbol_table[i].find(id) != symbol_table[i].end()  )	return i;
			

		}
		if(symbol_global.find(id)!=symbol_global.end())
		{
			return 2000;
		}
		return -1;
	}
	node_struct* root_node_struct=NULL;	

#line 123 "y.tab.c" /* yacc.c:339  */

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
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    INT = 258,
    FLOAT = 259,
    BOOL = 260,
    VOID = 261,
    INT_NUM = 262,
    FLOAT_NUM = 263,
    TRUE = 264,
    FALSE = 265,
    IDENTIFIER = 266,
    SEMI = 267,
    LP = 268,
    RP = 269,
    COMMA = 270,
    LCB = 271,
    RCB = 272,
    MAIN = 273,
    INPUT = 274,
    OUTPUT = 275,
    WHILE = 276,
    FOR = 277,
    IF = 278,
    IFX = 279,
    ELSE = 280,
    BREAK = 281,
    RETURN = 282,
    EQUALS = 283,
    DOUBLE_EQ = 284,
    GREATER = 285,
    GREATER_EQ = 286,
    LESS = 287,
    LESS_EQ = 288,
    NOT_EQ = 289,
    MULT = 290,
    DIV = 291,
    INCR = 292,
    DECR = 293,
    AND = 294,
    OR = 295,
    NOT = 296,
    PLUS = 297,
    MINUS = 298,
    NEGATION = 299
  };
#endif
/* Tokens.  */
#define INT 258
#define FLOAT 259
#define BOOL 260
#define VOID 261
#define INT_NUM 262
#define FLOAT_NUM 263
#define TRUE 264
#define FALSE 265
#define IDENTIFIER 266
#define SEMI 267
#define LP 268
#define RP 269
#define COMMA 270
#define LCB 271
#define RCB 272
#define MAIN 273
#define INPUT 274
#define OUTPUT 275
#define WHILE 276
#define FOR 277
#define IF 278
#define IFX 279
#define ELSE 280
#define BREAK 281
#define RETURN 282
#define EQUALS 283
#define DOUBLE_EQ 284
#define GREATER 285
#define GREATER_EQ 286
#define LESS 287
#define LESS_EQ 288
#define NOT_EQ 289
#define MULT 290
#define DIV 291
#define INCR 292
#define DECR 293
#define AND 294
#define OR 295
#define NOT 296
#define PLUS 297
#define MINUS 298
#define NEGATION 299

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 262 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  18
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   354

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  37
/* YYNRULES -- Number of rules.  */
#define YYNRULES  89
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  167

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   299

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      45,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    72,    72,    85,    94,   102,   109,   117,   126,   133,
     140,   152,   178,   201,   204,   214,   222,   230,   239,   242,
     251,   260,   271,   284,   292,   300,   307,   317,   326,   333,
     340,   347,   355,   362,   369,   376,   383,   390,   402,   410,
     413,   421,   429,   436,   447,   458,   457,   478,   487,   494,
     503,   504,   505,   516,   521,   530,   540,   541,   542,   543,
     550,   574,   593,   612,   632,   651,   661,   670,   679,   689,
     697,   704,   722,   735,   745,   757,   769,   781,   793,   805,
     869,   880,   893,   900,   903,   912,   920,   921,   928,   931
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT", "FLOAT", "BOOL", "VOID",
  "INT_NUM", "FLOAT_NUM", "TRUE", "FALSE", "IDENTIFIER", "SEMI", "LP",
  "RP", "COMMA", "LCB", "RCB", "MAIN", "INPUT", "OUTPUT", "WHILE", "FOR",
  "IF", "IFX", "ELSE", "BREAK", "RETURN", "EQUALS", "DOUBLE_EQ", "GREATER",
  "GREATER_EQ", "LESS", "LESS_EQ", "NOT_EQ", "MULT", "DIV", "INCR", "DECR",
  "AND", "OR", "NOT", "PLUS", "MINUS", "NEGATION", "'\\n'", "$accept",
  "START_CODE", "main", "global", "declaration_list", "declaration",
  "global_variable_declaration", "variable_declaration", "identifier",
  "type_specifier", "int", "float", "bool", "function_declaration",
  "parameters_list", "parameters", "Statement_list", "Statements",
  "Function_call_statements", "Identifier_list", "Output_statements",
  "Input_statements", "Compound_statements", "$@1", "local_declaration",
  "Loop_statements", "Condition_statements", "Expression_statements",
  "equals", "incr", "decr", "expression", "number", "Break_statement",
  "break", "Return_statement", "return", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,    10
};
# endif

#define YYPACT_NINF -85

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-85)))

#define YYTABLE_NINF -29

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     321,   -85,   -85,   -85,   -85,   -85,     7,    -6,   330,   -85,
     -85,   -85,    11,     4,   -85,   -85,   -85,   -85,   -85,   -85,
      20,   -85,   339,    18,   339,     4,    69,   -85,   -85,   -85,
     -85,   102,    77,   -85,     5,    84,   -85,   -85,    33,     5,
     -85,   -85,   -85,   -85,   -85,   -85,    95,   -85,     4,   175,
      30,    28,   -85,     4,     4,    34,    44,    57,    82,   -85,
     -85,   -85,   -85,    91,   117,   -85,   -85,   -85,   -85,   -85,
     -85,   -85,   -85,     4,     4,   188,   -85,   -85,    59,   -85,
      15,   -85,   233,    85,   101,   136,   127,   149,   162,    28,
       4,    28,   108,   111,   119,   124,   -85,    28,    28,    28,
      28,    28,    28,    28,   -85,   -85,   -85,   -85,     8,   -85,
     -85,   -85,   115,   250,   128,   130,    28,   132,   259,   137,
     276,   285,   -85,   112,   209,   -85,   -85,   -85,   -85,   -85,
     -85,   -85,    32,    32,   242,   242,   -85,   -85,   -85,     2,
     -85,   224,   -85,    16,   -85,     5,   -85,    81,     4,   -85,
      96,   -85,   196,   -85,   -85,     9,   -85,   -85,   -85,   -85,
     139,   142,     5,     5,   -85,   -85,   -85
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    18,    19,    20,    21,    14,     0,     0,     0,     7,
      10,     8,     0,     0,    15,    16,    17,     9,     1,     3,
       0,     6,     0,     0,     0,     0,     0,    24,    13,    12,
      66,     0,     0,    26,     0,     0,    80,    81,     0,     0,
      45,    22,    23,    11,     2,    48,     0,    47,     0,     0,
       0,     0,    46,     0,     0,     0,     0,     0,     0,    84,
      89,    67,    68,     0,    71,    27,    31,    29,    30,    32,
      33,    34,    35,     0,     0,     0,    70,    36,     0,    37,
       0,    71,     0,     0,     0,     0,     0,     0,     0,     0,
      42,     0,     0,     0,     0,     0,    65,     0,     0,     0,
       0,     0,     0,     0,    83,    82,    88,    87,     0,    69,
      44,    43,     0,     0,     0,    71,     0,     0,     0,     0,
       0,     0,    41,     0,     0,    61,    62,    63,    64,    78,
      77,    76,    74,    75,    72,    73,    86,    85,    50,     0,
      53,     0,    56,     0,    58,     0,    79,     0,     0,    60,
       0,    49,     0,    57,    54,     0,    39,    38,    40,    51,
       0,     0,     0,     0,    59,    55,    52
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -85,   -85,   -85,   -85,   -85,   153,   -85,   120,     0,     6,
     -85,   -85,   -85,   -85,   148,   141,   -85,   -85,   -85,   -85,
     -85,   -85,   -38,   -85,   -85,   -85,   -85,   -84,   151,   -60,
     -59,   -22,   146,   -85,   -85,   -85,   -85
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     6,    20,     7,     8,     9,    10,    11,    81,    25,
      14,    15,    16,    17,    26,    27,    49,    65,    66,   123,
      67,    68,    41,    45,    46,    70,    71,    72,    91,    73,
      74,    75,    76,    77,    78,    79,    80
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      12,    44,   116,   150,    92,    93,    13,    18,    12,   136,
     161,    69,    19,    23,    13,     5,   106,   153,    40,    28,
     137,    40,    36,    37,    22,    33,     5,   107,    51,    82,
      29,    28,    40,    24,   162,    36,    37,    97,    98,     5,
      99,    51,    29,   100,   101,    43,    30,    85,    50,    64,
     102,   103,    48,    83,    84,    92,    93,    86,   108,    63,
     104,    97,    98,   113,    99,   118,   120,   121,   160,   124,
      87,   105,    63,    94,    95,   129,   130,   131,   132,   133,
     134,   135,   156,    34,    35,     1,   115,     2,     3,     4,
     122,    39,    35,   157,   141,    88,     1,   110,     2,     3,
       4,   151,   -28,   -28,    89,   154,   -28,   155,   -28,    36,
      37,   -28,   -28,   111,   -28,   -28,   -28,   -28,   -28,   -28,
     125,   -28,   -28,   126,   165,   166,   147,   148,   114,   138,
      90,   127,   -28,   -28,    36,    37,   128,   112,     5,   -28,
      51,   159,   140,    36,    37,    30,   142,     5,   158,    51,
     117,   144,   115,   163,    61,    62,    36,    37,    30,   164,
       5,    21,    51,   119,    61,    62,    47,    61,    62,    36,
      37,    63,    32,     5,    31,    51,    42,    38,     0,     0,
      63,     0,    36,    37,     0,     0,     5,     0,    51,     0,
       0,    40,    52,    63,    53,    54,    55,    56,    57,    58,
      96,    59,    60,    36,    37,     0,    63,     5,     0,    51,
       0,     0,    61,    62,     0,     0,     0,    97,    98,    63,
      99,   149,     0,   100,   101,     0,     0,     0,     0,     0,
     102,   103,     0,    61,    62,     0,   152,     0,    97,    98,
      63,    99,     0,     0,   100,   101,     0,   109,     0,     0,
       0,   102,   103,    97,    98,     0,    99,     0,     0,   100,
     101,     0,    97,    98,   139,    99,   102,   103,   100,   101,
       0,    97,    98,   143,    99,   102,   103,   100,   101,    97,
      98,     0,    99,     0,     0,   100,   101,     0,    97,    98,
     145,    99,   102,   103,   100,   101,     0,     0,     0,   146,
       0,   102,   103,     0,     0,    97,    98,     0,    99,     0,
       0,   100,   101,     0,    97,    98,     0,    99,   102,   103,
     100,   101,     1,     0,     2,     3,     4,   102,   103,     0,
       0,     1,     5,     2,     3,     4,     0,     0,     0,    -5,
       1,     5,     2,     3,     4,     0,     0,     0,    -4,     0,
       0,     0,     0,   -25,   -25
};

static const yytype_int16 yycheck[] =
{
       0,    39,    86,     1,    64,    64,     0,     0,     8,     1,
       1,    49,    18,    13,     8,    11,     1,     1,    16,     1,
      12,    16,     7,     8,    13,    25,    11,    12,    13,    51,
      12,     1,    16,    13,    25,     7,     8,    29,    30,    11,
      32,    13,    12,    35,    36,    12,    28,    13,    48,    49,
      42,    43,    46,    53,    54,   115,   115,    13,    80,    44,
       1,    29,    30,    85,    32,    87,    88,    89,   152,    91,
      13,    12,    44,    73,    74,    97,    98,    99,   100,   101,
     102,   103,     1,    14,    15,     1,    86,     3,     4,     5,
      90,    14,    15,    12,   116,    13,     1,    12,     3,     4,
       5,   139,     7,     8,    13,   143,    11,   145,    13,     7,
       8,    16,    17,    12,    19,    20,    21,    22,    23,    24,
      12,    26,    27,    12,   162,   163,    14,    15,     1,    14,
      13,    12,    37,    38,     7,     8,    12,     1,    11,    44,
      13,    45,    14,     7,     8,    28,    14,    11,   148,    13,
       1,    14,   152,    14,    37,    38,     7,     8,    28,    17,
      11,     8,    13,     1,    37,    38,    46,    37,    38,     7,
       8,    44,    24,    11,    23,    13,    35,    31,    -1,    -1,
      44,    -1,     7,     8,    -1,    -1,    11,    -1,    13,    -1,
      -1,    16,    17,    44,    19,    20,    21,    22,    23,    24,
      12,    26,    27,     7,     8,    -1,    44,    11,    -1,    13,
      -1,    -1,    37,    38,    -1,    -1,    -1,    29,    30,    44,
      32,    12,    -1,    35,    36,    -1,    -1,    -1,    -1,    -1,
      42,    43,    -1,    37,    38,    -1,    12,    -1,    29,    30,
      44,    32,    -1,    -1,    35,    36,    -1,    14,    -1,    -1,
      -1,    42,    43,    29,    30,    -1,    32,    -1,    -1,    35,
      36,    -1,    29,    30,    14,    32,    42,    43,    35,    36,
      -1,    29,    30,    14,    32,    42,    43,    35,    36,    29,
      30,    -1,    32,    -1,    -1,    35,    36,    -1,    29,    30,
      14,    32,    42,    43,    35,    36,    -1,    -1,    -1,    14,
      -1,    42,    43,    -1,    -1,    29,    30,    -1,    32,    -1,
      -1,    35,    36,    -1,    29,    30,    -1,    32,    42,    43,
      35,    36,     1,    -1,     3,     4,     5,    42,    43,    -1,
      -1,     1,    11,     3,     4,     5,    -1,    -1,    -1,    18,
       1,    11,     3,     4,     5,    -1,    -1,    -1,    18,    -1,
      -1,    -1,    -1,    14,    15
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     3,     4,     5,    11,    47,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,     0,    18,
      48,    51,    13,    54,    13,    55,    60,    61,     1,    12,
      28,    74,    60,    54,    14,    15,     7,     8,    78,    14,
      16,    68,    61,    12,    68,    69,    70,    53,    55,    62,
      54,    13,    17,    19,    20,    21,    22,    23,    24,    26,
      27,    37,    38,    44,    54,    63,    64,    66,    67,    68,
      71,    72,    73,    75,    76,    77,    78,    79,    80,    81,
      82,    54,    77,    54,    54,    13,    13,    13,    13,    13,
      13,    74,    75,    76,    54,    54,    12,    29,    30,    32,
      35,    36,    42,    43,     1,    12,     1,    12,    77,    14,
      12,    12,     1,    77,     1,    54,    73,     1,    77,     1,
      77,    77,    54,    65,    77,    12,    12,    12,    12,    77,
      77,    77,    77,    77,    77,    77,     1,    12,    14,    14,
      14,    77,    14,    14,    14,    14,    14,    14,    15,    12,
       1,    68,    12,     1,    68,    68,     1,    12,    54,    45,
      73,     1,    25,    14,    17,    68,    68
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    46,    47,    48,    49,    49,    50,    50,    51,    51,
      51,    52,    53,    53,    54,    55,    55,    55,    55,    56,
      57,    58,    59,    60,    60,    60,    61,    62,    62,    63,
      63,    63,    63,    63,    63,    63,    63,    63,    64,    64,
      65,    65,    65,    66,    67,    69,    68,    70,    70,    71,
      71,    71,    71,    71,    72,    72,    72,    72,    72,    72,
      73,    73,    73,    73,    73,    73,    74,    75,    76,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      78,    78,    79,    79,    80,    81,    81,    81,    81,    82
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     6,     1,     1,     0,     2,     1,     1,     1,
       1,     5,     3,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     5,     3,     1,     0,     2,     2,     0,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     5,     5,
       3,     1,     0,     3,     3,     0,     5,     2,     0,     5,
       4,     6,     8,     4,     5,     7,     4,     5,     4,     7,
       4,     3,     3,     3,     3,     2,     1,     1,     1,     3,
       1,     1,     3,     3,     3,     3,     3,     3,     3,     4,
       1,     1,     2,     2,     1,     3,     3,     2,     2,     1
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
      yyerror (YY_("syntax error: cannot back up")); \
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
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
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
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
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
      yychar = yylex ();
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
#line 73 "final_grammar.y" /* yacc.c:1646  */
    {
					node_struct* new_node_struct = new node_struct;
					new_node_struct->code_node = "START_CODE";
					root_node_struct = new_node_struct;
					(new_node_struct->v_node).push_back((yyvsp[-5]).node_holder);
					(new_node_struct->v_node).push_back((yyvsp[-4]).node_holder);
					(new_node_struct->v_node).push_back((yyvsp[-2]).node_holder);
					(new_node_struct->v_node).push_back((yyvsp[0]).node_holder);
					(yyval).node_holder = new_node_struct;
				}
#line 1505 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 86 "final_grammar.y" /* yacc.c:1646  */
    {
				node_struct *new_node_struct = new node_struct;
				new_node_struct->code_node = "main";
				new_node_struct->id_node = string(yytext,yyleng);
				(yyval).node_holder = new_node_struct;
			}
#line 1516 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 95 "final_grammar.y" /* yacc.c:1646  */
    {
					node_struct* new_node_struct = new node_struct;
					new_node_struct->code_node = "global_declaration_list";
					(new_node_struct->v_node).push_back((yyvsp[0]).node_holder);
					(yyval).node_holder = new_node_struct;
				}
#line 1527 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 102 "final_grammar.y" /* yacc.c:1646  */
    {
					node_struct* new_node_struct = new node_struct;
					new_node_struct->code_node = "global_empty";
					(yyval).node_holder = new_node_struct;
				}
#line 1537 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 110 "final_grammar.y" /* yacc.c:1646  */
    {
					node_struct* new_node_struct = new node_struct;
					new_node_struct->code_node = "declaration_list";
					(new_node_struct->v_node).push_back((yyvsp[-1]).node_holder);
					(new_node_struct->v_node).push_back((yyvsp[0]).node_holder);
					(yyval).node_holder = new_node_struct;
				}
#line 1549 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 118 "final_grammar.y" /* yacc.c:1646  */
    {
					node_struct* new_node_struct = new node_struct;
					new_node_struct->code_node = "declaration";
					(new_node_struct->v_node).push_back((yyvsp[0]).node_holder);
					(yyval).node_holder = new_node_struct;
				}
#line 1560 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 127 "final_grammar.y" /* yacc.c:1646  */
    {
					node_struct* new_node_struct = new node_struct;
					new_node_struct->code_node = "declaration_variable";
					(new_node_struct->v_node).push_back((yyvsp[0]).node_holder);
					(yyval).node_holder = new_node_struct;
				}
#line 1571 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 134 "final_grammar.y" /* yacc.c:1646  */
    {
					node_struct* new_node_struct = new node_struct;
					new_node_struct->code_node = "declaration_function";
					(new_node_struct->v_node).push_back((yyvsp[0]).node_holder);
					(yyval).node_holder = new_node_struct;
				}
#line 1582 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 141 "final_grammar.y" /* yacc.c:1646  */
    {
					node_struct* new_node_struct = new node_struct;
					new_node_struct->code_node = "declaration_variable";

					(new_node_struct->v_node).push_back((yyvsp[0]).node_holder);
					(yyval).node_holder = new_node_struct;


				}
#line 1596 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 153 "final_grammar.y" /* yacc.c:1646  */
    {
					node_struct* new_node_struct = new node_struct;
					new_node_struct->code_node = "global_variable";

					if(symbol_global.find(((yyvsp[-3]).node_holder)->id_node)==symbol_global.end())
					{
						symbol_global[((yyvsp[-3]).node_holder)->id_node] = ((yyvsp[-4]).node_holder)->id_node;

					}
					else
					{
						semant_error = true;
						
					cout<<((yyvsp[-3]).node_holder)->id_node<<" "<<"multiple times declared"<<"at line no."<<mylineno<<endl;
					}	

					(new_node_struct->v_node).push_back((yyvsp[-3]).node_holder);
					(new_node_struct->v_node).push_back((yyvsp[-1]).node_holder);
					(yyval).node_holder = new_node_struct;
				}
#line 1621 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 179 "final_grammar.y" /* yacc.c:1646  */
    {
					node_struct* new_node_struct = new node_struct;
					new_node_struct->code_node = "variable declaration";
				

					if(symbol_table[scope_var].find(((yyvsp[-1]).node_holder)->id_node)==symbol_table[scope_var].end())
					{
						symbol_table[scope_var][((yyvsp[-1]).node_holder)->id_node] = ((yyvsp[-2]).node_holder)->id_node;
					}
				else
				{
				semant_error = true;
				cout<<((yyvsp[-1]).node_holder)->id_node<<" "<<"multiple times declared "<<"at line no. "<<mylineno<<endl;
					
				}	
				
					(new_node_struct->v_node).push_back((yyvsp[-2]).node_holder);
					(new_node_struct->v_node).push_back((yyvsp[-1]).node_holder);
					(yyval).node_holder = new_node_struct;


				}
#line 1648 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 201 "final_grammar.y" /* yacc.c:1646  */
    {flag=1;}
#line 1654 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 205 "final_grammar.y" /* yacc.c:1646  */
    {
				node_struct *new_node_struct = new node_struct;
				new_node_struct->code_node = "identifier";
				
				new_node_struct->id_node = string(yytext,strlen(yytext)) ;
				(yyval).node_holder = new_node_struct;
			}
#line 1666 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 215 "final_grammar.y" /* yacc.c:1646  */
    {
					node_struct *new_node_struct = new node_struct;
					new_node_struct->code_node = "dtype_node_int";
					new_node_struct->id_node = string(yytext,yyleng);
					(new_node_struct->v_node).push_back((yyvsp[0]).node_holder);
					(yyval).node_holder = new_node_struct;
				}
#line 1678 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 223 "final_grammar.y" /* yacc.c:1646  */
    {
					node_struct *new_node_struct = new node_struct;
					new_node_struct->code_node = "dtype_node_float";
					new_node_struct->id_node = string(yytext,yyleng);
					(new_node_struct->v_node).push_back((yyvsp[0]).node_holder);
					(yyval).node_holder = new_node_struct;
				}
#line 1690 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 231 "final_grammar.y" /* yacc.c:1646  */
    {
					node_struct *new_node_struct = new node_struct;
					new_node_struct->code_node = "dtype_node_bool";
					new_node_struct->id_node = string(yytext,yyleng);
					(new_node_struct->v_node).push_back((yyvsp[0]).node_holder);
					(yyval).node_holder = new_node_struct;
				}
#line 1702 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 239 "final_grammar.y" /* yacc.c:1646  */
    {flag=1;}
#line 1708 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 243 "final_grammar.y" /* yacc.c:1646  */
    {
				node_struct *new_node_struct = new node_struct;
				new_node_struct->code_node = "INT";
				new_node_struct->id_node = string(yytext,strlen(yytext));
				(yyval).node_holder = new_node_struct;
			}
#line 1719 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 252 "final_grammar.y" /* yacc.c:1646  */
    {
				node_struct *new_node_struct = new node_struct;
				new_node_struct->code_node = "FLOAT";
				new_node_struct->id_node = string(yytext,strlen(yytext));
				(yyval).node_holder = new_node_struct;
			}
#line 1730 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 261 "final_grammar.y" /* yacc.c:1646  */
    {
				node_struct *new_node_struct = new node_struct;
				new_node_struct->code_node = "BOOL";
				new_node_struct->id_node = string(yytext,strlen(yytext));
				(yyval).node_holder = new_node_struct;
			}
#line 1741 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 272 "final_grammar.y" /* yacc.c:1646  */
    {
					node_struct* new_node_struct = new node_struct;
					new_node_struct->code_node = "function_declaration";
					(new_node_struct->v_node).push_back((yyvsp[-4]).node_holder);
					(new_node_struct->v_node).push_back((yyvsp[-2]).node_holder);
					(new_node_struct->v_node).push_back((yyvsp[0]).node_holder);
					
					(yyval).node_holder = new_node_struct;
				}
#line 1755 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 285 "final_grammar.y" /* yacc.c:1646  */
    {
					node_struct* new_node_struct = new node_struct;
					new_node_struct->code_node = "param_list";
					(new_node_struct->v_node).push_back((yyvsp[-2]).node_holder);
					(new_node_struct->v_node).push_back((yyvsp[0]).node_holder);
					(yyval).node_holder = new_node_struct;
				}
#line 1767 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 293 "final_grammar.y" /* yacc.c:1646  */
    {
					node_struct* new_node_struct = new node_struct;
					new_node_struct->code_node = "param";
					(new_node_struct->v_node).push_back((yyvsp[0]).node_holder);
					(yyval).node_holder = new_node_struct;
				}
#line 1778 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 300 "final_grammar.y" /* yacc.c:1646  */
    {
					node_struct* new_node_struct = new node_struct;
					new_node_struct->code_node = "empty_param";
					(yyval).node_holder = new_node_struct;
				}
#line 1788 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 308 "final_grammar.y" /* yacc.c:1646  */
    {
					node_struct* new_node_struct = new node_struct;
					new_node_struct->code_node = "parameters";
					(new_node_struct->v_node).push_back((yyvsp[-1]).node_holder);
					(new_node_struct->v_node).push_back((yyvsp[0]).node_holder);
					(yyval).node_holder = new_node_struct;
				}
#line 1800 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 318 "final_grammar.y" /* yacc.c:1646  */
    {
					node_struct *new_node_struct = new node_struct;
					new_node_struct->code_node = "Statements list";
					(new_node_struct->v_node).push_back((yyvsp[-1]).node_holder);
					(new_node_struct->v_node).push_back((yyvsp[0]).node_holder);
					(yyval).node_holder = new_node_struct;
				}
#line 1812 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 326 "final_grammar.y" /* yacc.c:1646  */
    {
					node_struct* new_node_struct = new node_struct;
					new_node_struct->code_node = "emptyStatement_list";
					(yyval).node_holder = new_node_struct;
				}
#line 1822 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 334 "final_grammar.y" /* yacc.c:1646  */
    {
					node_struct *new_node_struct = new node_struct;
					new_node_struct->code_node = "Output Statements";
					(new_node_struct->v_node).push_back((yyvsp[0]).node_holder);
					(yyval).node_holder = new_node_struct;
				}
#line 1833 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 341 "final_grammar.y" /* yacc.c:1646  */
    {
					node_struct *new_node_struct = new node_struct;
					new_node_struct->code_node = "input Statements";
					(new_node_struct->v_node).push_back((yyvsp[0]).node_holder);
					(yyval).node_holder = new_node_struct;
				}
#line 1844 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 348 "final_grammar.y" /* yacc.c:1646  */
    {
					node_struct *new_node_struct = new node_struct;
					new_node_struct->code_node = "function Statements";
					(new_node_struct->v_node).push_back((yyvsp[0]).node_holder);
					(yyval).node_holder = new_node_struct;
				}
#line 1855 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 356 "final_grammar.y" /* yacc.c:1646  */
    {
					node_struct *new_node_struct = new node_struct;
					new_node_struct->code_node = "Compound Statements";
					(new_node_struct->v_node).push_back((yyvsp[0]).node_holder);
					(yyval).node_holder = new_node_struct;
				}
#line 1866 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 363 "final_grammar.y" /* yacc.c:1646  */
    {
					node_struct *new_node_struct = new node_struct;
					new_node_struct->code_node = "Loop Statements";
					(new_node_struct->v_node).push_back((yyvsp[0]).node_holder);
					(yyval).node_holder = new_node_struct;
				}
#line 1877 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 370 "final_grammar.y" /* yacc.c:1646  */
    {
					node_struct *new_node_struct = new node_struct;
					new_node_struct->code_node = "Condition Statements";
					(new_node_struct->v_node).push_back((yyvsp[0]).node_holder);
					(yyval).node_holder = new_node_struct;
				}
#line 1888 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 377 "final_grammar.y" /* yacc.c:1646  */
    {
					node_struct *new_node_struct = new node_struct;
					new_node_struct->code_node = "expr Statements";
					(new_node_struct->v_node).push_back((yyvsp[0]).node_holder);
					(yyval).node_holder = new_node_struct;
				}
#line 1899 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 384 "final_grammar.y" /* yacc.c:1646  */
    {
					node_struct *new_node_struct = new node_struct;
					new_node_struct->code_node = "break Statements";
					(new_node_struct->v_node).push_back((yyvsp[0]).node_holder);
					(yyval).node_holder = new_node_struct;
				}
#line 1910 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 391 "final_grammar.y" /* yacc.c:1646  */
    {
					node_struct *new_node_struct = new node_struct;
					new_node_struct->code_node = "return Statements";
					(new_node_struct->v_node).push_back((yyvsp[0]).node_holder);
					(yyval).node_holder = new_node_struct;
				}
#line 1921 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 403 "final_grammar.y" /* yacc.c:1646  */
    {
						node_struct *new_node_struct = new node_struct;
						new_node_struct->code_node = "Function_Statements2";
						(new_node_struct->v_node).push_back((yyvsp[-4]).node_holder);
						(new_node_struct->v_node).push_back((yyvsp[-2]).node_holder);
						(yyval).node_holder = new_node_struct;
					}
#line 1933 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 410 "final_grammar.y" /* yacc.c:1646  */
    {flag=1;}
#line 1939 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 414 "final_grammar.y" /* yacc.c:1646  */
    {
					node_struct *new_node_struct = new node_struct;
					new_node_struct->code_node = "Identifier_list";
					(new_node_struct->v_node).push_back((yyvsp[-2]).node_holder);
					(new_node_struct->v_node).push_back((yyvsp[0]).node_holder);
					(yyval).node_holder = new_node_struct;
				}
#line 1951 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 422 "final_grammar.y" /* yacc.c:1646  */
    {
					node_struct *new_node_struct = new node_struct;
					new_node_struct->code_node = "Identifier_list_single";
					(new_node_struct->v_node).push_back((yyvsp[0]).node_holder);
					(yyval).node_holder = new_node_struct;
				}
#line 1962 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 429 "final_grammar.y" /* yacc.c:1646  */
    {
					node_struct *new_node_struct = new node_struct;
					new_node_struct->code_node = "Identifier_list_empty";
					(yyval).node_holder = new_node_struct;
				}
#line 1972 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 437 "final_grammar.y" /* yacc.c:1646  */
    {
					node_struct *new_node_struct = new node_struct;
					new_node_struct->code_node = "Print_statement";
					(new_node_struct->v_node).push_back((yyvsp[-1]).node_holder);
					
					(yyval).node_holder = new_node_struct;
				}
#line 1984 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 448 "final_grammar.y" /* yacc.c:1646  */
    {
					node_struct *new_node_struct = new node_struct;
					new_node_struct->code_node = "Input_statement";
					(new_node_struct->v_node).push_back((yyvsp[-1]).node_holder);
					(yyval).node_holder = new_node_struct;
				}
#line 1995 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 458 "final_grammar.y" /* yacc.c:1646  */
    {
						map <string,string>	temp;
						symbol_table.push_back(temp);
						scope_var++;
					}
#line 2005 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 464 "final_grammar.y" /* yacc.c:1646  */
    {
					

						node_struct *new_node_struct = new node_struct;
						new_node_struct->code_node = "Compound_Statements";
						(new_node_struct->v_node).push_back((yyvsp[-2]).node_holder);
						(new_node_struct->v_node).push_back((yyvsp[-1]).node_holder);
						(yyval).node_holder = new_node_struct;
						symbol_table.pop_back();
						scope_var--;
					
					}
#line 2022 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 479 "final_grammar.y" /* yacc.c:1646  */
    {
					node_struct* new_node_struct = new node_struct;
					new_node_struct->code_node = "Local declaration";
					(new_node_struct->v_node).push_back((yyvsp[-1]).node_holder);
					(new_node_struct->v_node).push_back((yyvsp[0]).node_holder);
					(yyval).node_holder = new_node_struct;
				}
#line 2034 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 487 "final_grammar.y" /* yacc.c:1646  */
    {
					node_struct* new_node_struct = new node_struct;
					new_node_struct->code_node = "local empty";
					(yyval).node_holder = new_node_struct;
				}
#line 2044 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 495 "final_grammar.y" /* yacc.c:1646  */
    {
					node_struct* new_node_struct = new node_struct;
					new_node_struct->code_node = "while_LOOP";
					
					(new_node_struct->v_node).push_back((yyvsp[-2]).node_holder);
					(new_node_struct->v_node).push_back((yyvsp[0]).node_holder);
					(yyval).node_holder = new_node_struct;
				}
#line 2057 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 503 "final_grammar.y" /* yacc.c:1646  */
    {flag=1;}
#line 2063 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 504 "final_grammar.y" /* yacc.c:1646  */
    {flag=1;}
#line 2069 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 506 "final_grammar.y" /* yacc.c:1646  */
    {
					node_struct* new_node_struct = new node_struct;
					new_node_struct->code_node = "for_LOOP";
					(new_node_struct->v_node).push_back((yyvsp[-7]).node_holder);
					(new_node_struct->v_node).push_back((yyvsp[-5]).node_holder);
					(new_node_struct->v_node).push_back((yyvsp[-4]).node_holder);
					(new_node_struct->v_node).push_back((yyvsp[-2]).node_holder);
					(new_node_struct->v_node).push_back((yyvsp[0]).node_holder);
					(yyval).node_holder = new_node_struct;
				}
#line 2084 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 516 "final_grammar.y" /* yacc.c:1646  */
    {flag=1;}
#line 2090 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 522 "final_grammar.y" /* yacc.c:1646  */
    {
					node_struct* new_node_struct = new node_struct;
					new_node_struct->code_node = "if";
					
					(new_node_struct->v_node).push_back((yyvsp[-2]).node_holder);
					(new_node_struct->v_node).push_back((yyvsp[0]).node_holder);
					(yyval).node_holder = new_node_struct;
				}
#line 2103 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 531 "final_grammar.y" /* yacc.c:1646  */
    {
					node_struct* new_node_struct = new node_struct;
					new_node_struct->code_node = "ifx";
					
					(new_node_struct->v_node).push_back((yyvsp[-4]).node_holder);
					(new_node_struct->v_node).push_back((yyvsp[-2]).node_holder);
					(new_node_struct->v_node).push_back((yyvsp[0]).node_holder);
					(yyval).node_holder = new_node_struct;
				}
#line 2117 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 540 "final_grammar.y" /* yacc.c:1646  */
    {flag=1;}
#line 2123 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 541 "final_grammar.y" /* yacc.c:1646  */
    {flag=1;}
#line 2129 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 542 "final_grammar.y" /* yacc.c:1646  */
    {flag=1;}
#line 2135 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 543 "final_grammar.y" /* yacc.c:1646  */
    {flag=1;}
#line 2141 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 551 "final_grammar.y" /* yacc.c:1646  */
    {
					node_struct* new_node_struct = new node_struct;
					new_node_struct->code_node = "expr1";
					(new_node_struct->v_node).push_back((yyvsp[-3]).node_holder);
					int scope_2 = get_scope(((yyvsp[-3]).node_holder)->id_node);
					
					if(scope_2 == -1)
					{
						semant_error = true;
							
						cout<<((yyvsp[-3]).node_holder)->id_node<<" "<<"Undeclared at "<<"line no. "<<mylineno<<endl;
					}
					else
					{
						((yyval).node_holder)->dtype_node = symbol_table[scope_2][((yyvsp[-3]).node_holder)->id_node];
						
					} 
					(new_node_struct->v_node).push_back((yyvsp[-2]).node_holder);
					(new_node_struct->v_node).push_back((yyvsp[-1]).node_holder);
					(yyval).node_holder = new_node_struct;

				}
#line 2168 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 575 "final_grammar.y" /* yacc.c:1646  */
    {
					node_struct* new_node_struct = new node_struct;
					new_node_struct->code_node = "post incr";
					(new_node_struct->v_node).push_back((yyvsp[-2]).node_holder);
					int scope_2 = get_scope(((yyvsp[-2]).node_holder)->id_node);
					if(scope_2 == -1)
					{
						semant_error = true;
						cout<<((yyvsp[-2]).node_holder)->id_node<<" "<<"Undeclared at "<<"line no. "<<mylineno<<endl;	
					}
					else
					{
						((yyval).node_holder)->dtype_node = symbol_table[scope_2][((yyvsp[-2]).node_holder)->id_node];
					} 
					(new_node_struct->v_node).push_back((yyvsp[-1]).node_holder);
					(yyval).node_holder = new_node_struct;
				}
#line 2190 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 594 "final_grammar.y" /* yacc.c:1646  */
    {
					node_struct* new_node_struct = new node_struct;
					new_node_struct->code_node = "post decr";
					(new_node_struct->v_node).push_back((yyvsp[-2]).node_holder);
					int scope_2 = get_scope(((yyvsp[-2]).node_holder)->id_node);
					if(scope_2 == -1)
					{
						semant_error = true;
						cout<<((yyvsp[-2]).node_holder)->id_node<<" "<<"Undeclared at "<<"line no. "<<mylineno<<endl;	
					}
					else
					{
						((yyval).node_holder)->dtype_node = symbol_table[scope_2][((yyvsp[-2]).node_holder)->id_node];
					} 
					(new_node_struct->v_node).push_back((yyvsp[-1]).node_holder);
					(yyval).node_holder = new_node_struct;
				}
#line 2212 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 613 "final_grammar.y" /* yacc.c:1646  */
    {
					node_struct* new_node_struct = new node_struct;
					new_node_struct->code_node = "pre incr";
					(new_node_struct->v_node).push_back((yyvsp[-2]).node_holder);

					(new_node_struct->v_node).push_back((yyvsp[-1]).node_holder);
					int scope_2 = get_scope(((yyvsp[-1]).node_holder)->id_node);
					if(scope_2 == -1)
					{
						semant_error = true;
						cout<<((yyvsp[-1]).node_holder)->id_node<<" "<<"Undeclared at "<<"line no. "<<mylineno<<endl;
					}
					else
					{
						((yyval).node_holder)->dtype_node = symbol_table[scope_2][((yyvsp[-2]).node_holder)->id_node];
					} 
					(yyval).node_holder = new_node_struct;
				}
#line 2235 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 633 "final_grammar.y" /* yacc.c:1646  */
    {
					node_struct* new_node_struct = new node_struct;
					new_node_struct->code_node = "pre decr";
					(new_node_struct->v_node).push_back((yyvsp[-2]).node_holder);
					(new_node_struct->v_node).push_back((yyvsp[-1]).node_holder);
					int scope_2 = get_scope(((yyvsp[-2]).node_holder)->id_node);
					if(scope_2 == -1)
					{
						semant_error = true;
						cout<<((yyvsp[-1]).node_holder)->id_node<<" "<<"Undeclared at "<<"line no. "<<mylineno<<endl;
					}
					else
					{
						((yyval).node_holder)->dtype_node = symbol_table[scope_2][((yyvsp[-1]).node_holder)->id_node];
					} 
					(yyval).node_holder = new_node_struct;
				}
#line 2257 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 652 "final_grammar.y" /* yacc.c:1646  */
    {
					node_struct* new_node_struct = new node_struct;
					new_node_struct->code_node = "exprstmt expr";
					(new_node_struct->v_node).push_back((yyvsp[-1]).node_holder);
					(yyval).node_holder = new_node_struct;
				}
#line 2268 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 662 "final_grammar.y" /* yacc.c:1646  */
    {
			node_struct *new_node_struct = new node_struct;
			new_node_struct->code_node = "EQUALS";
			new_node_struct->id_node = string(yytext,yyleng);
			(yyval).node_holder = new_node_struct;
		}
#line 2279 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 671 "final_grammar.y" /* yacc.c:1646  */
    {
			node_struct *new_node_struct = new node_struct;
			new_node_struct->code_node = "INCR";
			new_node_struct->id_node = string(yytext,yyleng);
			(yyval).node_holder = new_node_struct;
		}
#line 2290 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 680 "final_grammar.y" /* yacc.c:1646  */
    {
			node_struct *new_node_struct = new node_struct;
			new_node_struct->code_node = "DECR";
			new_node_struct->id_node = string(yytext,yyleng);
			(yyval).node_holder = new_node_struct;
		}
#line 2301 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 690 "final_grammar.y" /* yacc.c:1646  */
    {
						node_struct* new_node_struct = new node_struct;
						new_node_struct->code_node = "expression";
						(new_node_struct->v_node).push_back((yyvsp[-1]).node_holder);
						(yyval).node_holder = (yyvsp[-1]).node_holder;

					}
#line 2313 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 698 "final_grammar.y" /* yacc.c:1646  */
    {
						node_struct* new_node_struct = new node_struct;
						new_node_struct->code_node = "expression";
						(new_node_struct->v_node).push_back((yyvsp[0]).node_holder);
						(yyval).node_holder = (yyvsp[0]).node_holder;
					}
#line 2324 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 705 "final_grammar.y" /* yacc.c:1646  */
    {
					node_struct* new_node_struct = new node_struct;
					new_node_struct->code_node = "expression";

					int scope_2 = get_scope(((yyvsp[0]).node_holder)->id_node);
					
					if(scope_2 == -1)
					{
						semant_error = true;
						cout << "Undeclared variable " << ((yyvsp[0]).node_holder)->id_node << " line no. " << mylineno+1 << endl;	
					}
					else
					{
						((yyval).node_holder)->dtype_node = symbol_table[scope_2][((yyvsp[0]).node_holder)->id_node];
					} 
					(yyval).node_holder = (yyvsp[0]).node_holder;
				}
#line 2346 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 723 "final_grammar.y" /* yacc.c:1646  */
    {
					node_struct* new_node_struct = new node_struct;
					new_node_struct->code_node = "PLUS";
				
					(new_node_struct->v_node).push_back((yyvsp[-2]).node_holder);
					(new_node_struct->v_node).push_back((yyvsp[0]).node_holder);
					
					
					new_node_struct->dtype_node = ((yyvsp[0]).node_holder)->dtype_node;
					
					(yyval).node_holder = new_node_struct;
				}
#line 2363 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 736 "final_grammar.y" /* yacc.c:1646  */
    {
					node_struct* new_node_struct = new node_struct;
					new_node_struct->code_node = "MINUS";
					(new_node_struct->v_node).push_back((yyvsp[-2]).node_holder);
					(new_node_struct->v_node).push_back((yyvsp[0]).node_holder);

				
					(yyval).node_holder = new_node_struct;
				}
#line 2377 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 746 "final_grammar.y" /* yacc.c:1646  */
    {
					node_struct* new_node_struct = new node_struct;
					new_node_struct->code_node = "MULT";
					(new_node_struct->v_node).push_back((yyvsp[-2]).node_holder);
					(new_node_struct->v_node).push_back((yyvsp[0]).node_holder);
					
					
					new_node_struct->dtype_node = ((yyvsp[0]).node_holder)->dtype_node;
					
					(yyval).node_holder = new_node_struct;
				}
#line 2393 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 758 "final_grammar.y" /* yacc.c:1646  */
    {
					node_struct* new_node_struct = new node_struct;
					new_node_struct->code_node = "DIV";
					(new_node_struct->v_node).push_back((yyvsp[-2]).node_holder);
					(new_node_struct->v_node).push_back((yyvsp[0]).node_holder);
					
					
					new_node_struct->dtype_node = ((yyvsp[0]).node_holder)->dtype_node;
					
					(yyval).node_holder = new_node_struct;
				}
#line 2409 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 770 "final_grammar.y" /* yacc.c:1646  */
    {
					node_struct* new_node_struct = new node_struct;
					new_node_struct->code_node = "LESS";
					(new_node_struct->v_node).push_back((yyvsp[-2]).node_holder);
					(new_node_struct->v_node).push_back((yyvsp[0]).node_holder);
					
					
					new_node_struct->dtype_node = ((yyvsp[0]).node_holder)->dtype_node;
					
					(yyval).node_holder = new_node_struct;
				}
#line 2425 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 782 "final_grammar.y" /* yacc.c:1646  */
    {
					node_struct* new_node_struct = new node_struct;
					new_node_struct->code_node = "GREATER";
					(new_node_struct->v_node).push_back((yyvsp[-2]).node_holder);
					(new_node_struct->v_node).push_back((yyvsp[0]).node_holder);
					
					
					new_node_struct->dtype_node = ((yyvsp[0]).node_holder)->dtype_node;
					
					(yyval).node_holder = new_node_struct;
				}
#line 2441 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 794 "final_grammar.y" /* yacc.c:1646  */
    {
					node_struct* new_node_struct = new node_struct;
					new_node_struct->code_node = "DOUBLE_EQ";
					(new_node_struct->v_node).push_back((yyvsp[-2]).node_holder);
					(new_node_struct->v_node).push_back((yyvsp[0]).node_holder);
					
					
					new_node_struct->dtype_node = ((yyvsp[0]).node_holder)->dtype_node;
					
					(yyval).node_holder = new_node_struct;
				}
#line 2457 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 806 "final_grammar.y" /* yacc.c:1646  */
    {
					node_struct* new_node_struct = new node_struct;
					new_node_struct->code_node = "NEGATION";
					(new_node_struct->v_node).push_back((yyvsp[-1]).node_holder);
					(yyval).node_holder = new_node_struct;
				}
#line 2468 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 870 "final_grammar.y" /* yacc.c:1646  */
    {
						node_struct* new_node_struct = new node_struct;
						new_node_struct->code_node = "NUMBER";

						new_node_struct->id_node = string(yytext,yyleng);
							
						(yyval).node_holder = new_node_struct;

					}
#line 2482 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 881 "final_grammar.y" /* yacc.c:1646  */
    {
						node_struct* new_node_struct = new node_struct;
						new_node_struct->code_node = "NUMBER";

						new_node_struct->id_node = string(yytext,yyleng);	
						(yyval).node_holder = new_node_struct;


					}
#line 2496 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 894 "final_grammar.y" /* yacc.c:1646  */
    {
					node_struct* new_node_struct = new node_struct;
					new_node_struct->code_node = "break only";
					(new_node_struct->v_node).push_back((yyvsp[-1]).node_holder);
					(yyval).node_holder = new_node_struct;
				}
#line 2507 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 900 "final_grammar.y" /* yacc.c:1646  */
    {flag=1;}
#line 2513 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 904 "final_grammar.y" /* yacc.c:1646  */
    {
				node_struct *new_node_struct = new node_struct;
				new_node_struct->code_node = "BREAK";
				new_node_struct->id_node = string(yytext,yyleng);
				(yyval).node_holder = new_node_struct;
			}
#line 2524 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 913 "final_grammar.y" /* yacc.c:1646  */
    {
					node_struct* new_node_struct = new node_struct;
					new_node_struct->code_node = "return expr only";
					(new_node_struct->v_node).push_back((yyvsp[-2]).node_holder);
					(new_node_struct->v_node).push_back((yyvsp[-1]).node_holder);
					(yyval).node_holder = new_node_struct;
				}
#line 2536 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 920 "final_grammar.y" /* yacc.c:1646  */
    {flag=1;}
#line 2542 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 922 "final_grammar.y" /* yacc.c:1646  */
    {
					node_struct* new_node_struct = new node_struct;
					new_node_struct->code_node = "return only";
					(new_node_struct->v_node).push_back((yyvsp[-1]).node_holder);
					(yyval).node_holder = new_node_struct;
				}
#line 2553 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 928 "final_grammar.y" /* yacc.c:1646  */
    {flag=1;}
#line 2559 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 932 "final_grammar.y" /* yacc.c:1646  */
    {
				node_struct *new_node_struct = new node_struct;
				new_node_struct->code_node = "RETURN";
				new_node_struct->id_node = string(yytext,yyleng);
				(yyval).node_holder = new_node_struct;
			}
#line 2570 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2574 "y.tab.c" /* yacc.c:1646  */
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
                  yystos[yystate], yyvsp);
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
  /* Do not reclaim the symbols of the rule whose action triggered
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
  return yyresult;
}
#line 944 "final_grammar.y" /* yacc.c:1906  */


void tree_traversal(node_struct *n,int cnt)
{
	//for easy node_struct recognition

	
	
	for(int i=0;i<cnt;i++) cout<<"-";
	if(n==NULL){
		cout<<"No CHILD NODE!\n";
		return;
	}
	cout <<"Code: "<<n->code_node<<"; Children: "<<(n->v_node).size()<<"; ID, if any: "<<n->id_node<<endl;
	for (int i = 1; i <= (n->v_node).size(); ++i)
		tree_traversal((n->v_node)[i-1],cnt+1);
}

string new_register()
{
	static int counter=0;
	stringstream ss;
	ss<<++counter;
	fp<<"reg"+ss.str()<<endl;
	return string("reg"+ss.str());
}

string new_label()
{
	static int labeler=0;
	stringstream ss;
	ss<<++labeler;
	return string("label"+ss.str()+":");
}

string code_generation(node_struct *n)
{
	if(n==NULL) 
	{
		return "";
	}
	if(n->code_node == "Compound_Statements")
	{
		scope_var++;
		map<string,string> temp_var;
		symbol_table.push_back(temp_var);
		
		for(int j=0;j<(n->v_node).size();j++)
		{
			code_generation((n->v_node)[j]);

		}

		scope_var--;
		symbol_table.pop_back();
		return "";
	}

	if(n->code_node == "if")
	{
		string reg1=code_generation((n->v_node)[0]);
		string label_1 = new_label();
		string label_2 = new_label();
		cout<<"if"<<reg1<<" goto "<<label_1<<endl;
		
		cout<<"goto "<<label_2<<endl;
		cout<<label_1<<endl;
		code_generation((n->v_node)[1]);
		string newReg=new_register();

		cout<<label_2<<endl;
		return "";
	}
	if(n->code_node == "expr1")
	{
		cout<<code_generation((n->v_node)[0])<<" = "<<code_generation((n->v_node)[2])<<endl;
		return "";

	}
	if(n->code_node == "NUMBER")
	{
		
		return n->id_node;
	}
	if(n->code_node=="identifier")
	{
			int z=get_scope(n->id_node);
			stringstream ss;
			
			ss<<z;
			string sl=n->id_node +ss.str();
			fp<<sl<<endl;
			if(ss.str()!="-1" && ss.str()!="2000")
			{
				return n->id_node +ss.str();
			}
			else
			if(ss.str()=="2000")
			{
				return n->id_node +"2000";
			}
			else
			{
				return n->id_node;
			}

		
	}
	if(n->code_node=="Print_statement")
	{
			cout<<"output"<<" "<<code_generation((n->v_node)[0])<<endl;
	}
	if(n->code_node=="PLUS")
	{
		string reg1=code_generation((n->v_node)[0]);
		string reg2=code_generation((n->v_node)[1]);
		string newRegister_1=new_register();
		
		cout<<newRegister_1<<" = "<<reg1<<" + "<<reg2<<endl;
		
		return newRegister_1;
	}
	if(n->code_node=="MINUS")
	{
		string reg1=code_generation((n->v_node)[0]);
		string reg2=code_generation((n->v_node)[1]);
		string newRegister_1=new_register();
		
		cout<<newRegister_1<<" = "<<reg1<<" - "<<reg2<<endl;
		
		return newRegister_1;
	}
	if(n->code_node=="MULT")
	{
		string reg1=code_generation((n->v_node)[0]);
		string reg2=code_generation((n->v_node)[1]);
		string newRegister_1=new_register();
		
		cout<<newRegister_1<<" = "<<reg1<<" * "<<reg2<<endl;
		
		return newRegister_1;
	}
	if(n->code_node=="DIV")
	{
		string reg1=code_generation((n->v_node)[0]);
		string reg2=code_generation((n->v_node)[1]);
		string newRegister_1=new_register();
		
		cout<<newRegister_1<<" = "<<reg1<<" / "<<reg2<<endl;
		
		return newRegister_1;
	}
	if(n->code_node=="LESS")
	{
		string reg1=code_generation((n->v_node)[0]);
		string reg2=code_generation((n->v_node)[1]);
		string newRegister_1=new_register();
		
		cout<<newRegister_1<<" = "<<reg1<<" < "<<reg2<<endl;
		
		return newRegister_1;
	}
	if(n->code_node == "DOUBLE_EQ")
	{
		string reg1=code_generation((n->v_node)[0]);
		string reg2=code_generation((n->v_node)[1]);
		string newRegister_1=new_register();
	
		cout<<newRegister_1<<" = "<<reg1<<" == "<<reg2<<endl;
		

		return newRegister_1;
	}
	if(n->code_node=="NEGATION")
	{
		string reg1=code_generation((n->v_node)[0]);
		string newRegister_1=new_register();
		
		cout<<newRegister_1<<" = "<<"-1"<<" "<<"*"<<" "<<reg1<<endl;
		return newRegister_1;
	}
	if(n->code_node=="while_LOOP")
	{
		string mylabel1= new_label();
		cout<<mylabel1<<endl;
		string reg1=code_generation((n->v_node)[0]);
		string mylabel2 = new_label();
		string mylabel3 = new_label();
		cout<<"if "<<reg1<<" goto "<<mylabel2<<endl;
		cout<<"goto "<<mylabel3<<endl;
		
		cout<<mylabel2<<endl;
		code_generation((n->v_node)[1]);
		cout<<"goto "<<mylabel1<<endl;
		cout<<mylabel3<<endl;
		return "";


	}
	if(n->code_node=="function_declaration")
	{
		string z=code_generation((n->v_node)[0]);
		int le =z.length();
		
		cout<<z<<":"<<" "<<endl;
		code_generation((n->v_node)[2]);
		return "";
	}
	if(n->code_node=="Identifier_list_single")
	{

		cout<<"param"<<" "<<code_generation((n->v_node)[0])<<endl;
		counter_par++;
		return "";

	}
	if(n->code_node=="Identifier_list")
	{

		cout<<"param"<<" "<<code_generation((n->v_node)[1])<<endl;
		counter_par++;
		code_generation((n->v_node)[0]);
		return "";

	}
	if(n->code_node=="Function_Statements2")
	{
		
		
		code_generation((n->v_node)[1]);
		cout<<"call"<<code_generation((n->v_node)[0])<<":"<<endl;
		counter_par=0;
		return "";
		

	}
	if(n->code_node=="global_variable")
	{
		cout<<code_generation((n->v_node)[0])<<"="<<code_generation((n->v_node)[1])<<endl;
		return "";

	}
	else
	{
		for (int k = 0; k < (n->v_node).size(); ++k)
		{
			code_generation((n->v_node)[k]);
		}
		return "";
	}


}

int main()
{
	yyparse();
	/*if(flag==1)
	{
		cout<<"TREE NOT FORMED BECUASE OF ERRORS\n";
	}
	else
	{
	tree_traversal(root_node_struct,0);
	}*/
	fp.open ("new.txt");
	if(semant_error==false && flag!=1)
	{
		code_generation(root_node_struct);
	}
	 fp.close();
}
void yyerror (string s_holder) { printf("Error in line: %d, text: %s_holder \n", mylineno, yytext);}



 					
