/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1





# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_SRC_PARSER_TAB_HPP_INCLUDED
# define YY_YY_SRC_PARSER_TAB_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 1 "src/parser.y"


    #include "ast.hpp"

    extern node *g_root;
    extern FILE *yyin;


    int yylex(void);
    void yyerror(const char *);

#line 123 "src/parser.tab.cpp"

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    IDENTIFIER = 258,
    FLOAT_LITERAL = 259,
    INT_LITERAL = 260,
    STRING_LITERAL = 261,
    DOUBLE_LITERAL = 262,
    SIZEOF = 263,
    PTR_OP = 264,
    INC_OP = 265,
    DEC_OP = 266,
    LEFT_OP = 267,
    RIGHT_OP = 268,
    LE_OP = 269,
    GE_OP = 270,
    EQ_OP = 271,
    NE_OP = 272,
    AND_OP = 273,
    OR_OP = 274,
    MUL_ASSIGN = 275,
    DIV_ASSIGN = 276,
    MOD_ASSIGN = 277,
    ADD_ASSIGN = 278,
    SUB_ASSIGN = 279,
    LEFT_ASSIGN = 280,
    RIGHT_ASSIGN = 281,
    AND_ASSIGN = 282,
    XOR_ASSIGN = 283,
    OR_ASSIGN = 284,
    TYPE_NAME = 285,
    TYPEDEF = 286,
    EXTERN = 287,
    STATIC = 288,
    AUTO = 289,
    REGISTER = 290,
    CHAR = 291,
    SHORT = 292,
    INT = 293,
    LONG = 294,
    SIGNED = 295,
    UNSIGNED = 296,
    FLOAT = 297,
    DOUBLE = 298,
    CONST = 299,
    VOLATILE = 300,
    VOID = 301,
    STRUCT = 302,
    UNION = 303,
    ENUM = 304,
    ELLIPSIS = 305,
    CASE = 306,
    DEFAULT = 307,
    IF = 308,
    ELSE = 309,
    SWITCH = 310,
    WHILE = 311,
    DO = 312,
    FOR = 313,
    GOTO = 314,
    CONTINUE = 315,
    BREAK = 316,
    RETURN = 317
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 13 "src/parser.y"

	yytokentype token;
    std::string* string;
    int number;
    float f_number;
	node_ptr expr;
	node_vector_ptr exprlist;

#line 206 "src/parser.tab.cpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SRC_PARSER_TAB_HPP_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

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
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  50
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1242

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  87
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  65
/* YYNRULES -- Number of rules.  */
#define YYNRULES  212
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  348

#define YYUNDEFTOK  2
#define YYMAXUTOK   317


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    74,     2,     2,     2,    76,    69,     2,
      63,    64,    70,    71,    68,    72,    67,    75,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    82,    84,
      77,    83,    78,    81,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    65,     2,    66,    79,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    85,    80,    86,    73,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    71,    71,    72,    73,    74,    75,    79,    80,    81,
      82,    83,    84,    85,    86,    90,    91,    95,    96,    97,
      98,    99,   100,   104,   105,   106,   107,   108,   109,   113,
     114,   118,   119,   120,   121,   125,   126,   127,   131,   132,
     133,   137,   138,   139,   140,   141,   145,   146,   147,   151,
     152,   156,   157,   161,   162,   166,   167,   171,   172,   176,
     177,   181,   182,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   200,   201,   205,   209,   210,   214,
     215,   216,   217,   218,   219,   223,   224,   228,   229,   233,
     234,   235,   236,   237,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   256,   257,   258,   262,
     263,   267,   268,   272,   276,   277,   278,   279,   283,   284,
     288,   289,   290,   294,   295,   296,   300,   301,   305,   306,
     310,   311,   315,   316,   320,   321,   322,   323,   324,   325,
     326,   330,   331,   332,   333,   337,   338,   343,   344,   348,
     349,   353,   354,   355,   359,   360,   364,   365,   369,   370,
     371,   375,   376,   377,   378,   379,   380,   381,   382,   383,
     387,   388,   389,   393,   394,   398,   399,   400,   401,   402,
     403,   407,   408,   409,   413,   414,   415,   416,   420,   421,
     425,   426,   430,   431,   435,   436,   437,   441,   442,   443,
     444,   448,   449,   450,   451,   452,   456,   457,   462,   463,
     467,   472,   480
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "FLOAT_LITERAL",
  "INT_LITERAL", "STRING_LITERAL", "DOUBLE_LITERAL", "SIZEOF", "PTR_OP",
  "INC_OP", "DEC_OP", "LEFT_OP", "RIGHT_OP", "LE_OP", "GE_OP", "EQ_OP",
  "NE_OP", "AND_OP", "OR_OP", "MUL_ASSIGN", "DIV_ASSIGN", "MOD_ASSIGN",
  "ADD_ASSIGN", "SUB_ASSIGN", "LEFT_ASSIGN", "RIGHT_ASSIGN", "AND_ASSIGN",
  "XOR_ASSIGN", "OR_ASSIGN", "TYPE_NAME", "TYPEDEF", "EXTERN", "STATIC",
  "AUTO", "REGISTER", "CHAR", "SHORT", "INT", "LONG", "SIGNED", "UNSIGNED",
  "FLOAT", "DOUBLE", "CONST", "VOLATILE", "VOID", "STRUCT", "UNION",
  "ENUM", "ELLIPSIS", "CASE", "DEFAULT", "IF", "ELSE", "SWITCH", "WHILE",
  "DO", "FOR", "GOTO", "CONTINUE", "BREAK", "RETURN", "'('", "')'", "'['",
  "']'", "'.'", "','", "'&'", "'*'", "'+'", "'-'", "'~'", "'!'", "'/'",
  "'%'", "'<'", "'>'", "'^'", "'|'", "'?'", "':'", "'='", "';'", "'{'",
  "'}'", "$accept", "primary_expression", "postfix_expression",
  "argument_expression_list", "unary_expression", "unary_operator",
  "cast_expression", "multiplicative_expression", "additive_expression",
  "shift_expression", "relational_expression", "equality_expression",
  "and_expression", "exclusive_or_expression", "inclusive_or_expression",
  "logical_and_expression", "logical_or_expression",
  "conditional_expression", "assignment_expression", "assignment_operator",
  "expression", "constant_expression", "declaration",
  "declaration_specifiers", "init_declarator_list", "init_declarator",
  "storage_class_specifier", "type_specifier", "struct_or_union_specifier",
  "struct_or_union", "struct_declaration_list", "struct_declaration",
  "specifier_qualifier_list", "struct_declarator_list",
  "struct_declarator", "enum_specifier", "enumerator_list", "enumerator",
  "type_qualifier", "declarator", "direct_declarator", "pointer",
  "type_qualifier_list", "parameter_type_list", "parameter_list",
  "parameter_declaration", "identifier_list", "type_name",
  "abstract_declarator", "direct_abstract_declarator", "initializer",
  "initializer_list", "statement", "labeled_statement",
  "compound_statement", "declaration_list", "statement_list",
  "expression_statement", "selection_statement", "iteration_statement",
  "jump_statement", "translation_unit", "external_declaration",
  "function_definition", "ROOT", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,    40,    41,    91,    93,    46,    44,    38,
      42,    43,    45,   126,    33,    47,    37,    60,    62,    94,
     124,    63,    58,    61,    59,   123,   125
};
# endif

#define YYPACT_NINF (-193)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    1193,  -193,  -193,  -193,  -193,  -193,  -193,  -193,  -193,  -193,
    -193,  -193,  -193,  -193,  -193,  -193,  -193,  -193,  -193,  -193,
       9,  -193,    20,  1193,  1193,  -193,    10,  -193,  1193,  1193,
    -193,  -193,    43,   -32,    60,  -193,    55,    -5,  -193,   -12,
    -193,  1020,     5,    22,  -193,  -193,    29,   994,  -193,  -193,
    -193,    60,    36,   -35,  -193,    38,  -193,  -193,    -5,    55,
    -193,   525,   273,  -193,    20,  -193,  1040,   914,   601,     5,
     994,   994,   943,  -193,    33,   994,    -6,   770,    60,  -193,
    -193,  -193,  -193,  -193,    41,  -193,  -193,  -193,  -193,   795,
     818,   818,   651,  -193,  -193,  -193,  -193,  -193,  -193,   525,
    -193,   180,   244,   770,  -193,   137,   106,   222,    52,   223,
      64,    78,    85,   174,   -10,  -193,  -193,  -193,   113,   770,
     121,   148,   161,   165,   489,   168,   233,   157,   160,   561,
    -193,  -193,  -193,    -8,  -193,  -193,  -193,   345,   417,  -193,
    -193,  -193,  -193,  -193,  -193,  -193,  -193,    58,   182,   185,
    -193,    13,  -193,  -193,  -193,   190,   963,  -193,  -193,  -193,
     770,    95,  -193,   179,  -193,  -193,  -193,  -193,   651,  -193,
     770,  -193,  -193,    63,   145,   216,  -193,    86,   279,  -193,
    -193,   674,   770,   282,  -193,  -193,  -193,  -193,  -193,  -193,
    -193,  -193,  -193,  -193,  -193,   770,  -193,   770,   770,   770,
     770,   770,   770,   770,   770,   770,   770,   770,   770,   770,
     770,   770,   770,   770,   770,   770,   489,   204,   489,   770,
     770,   770,   231,   579,   205,  -193,  -193,  -193,   102,   770,
    -193,  -193,   453,  -193,  -193,   867,   698,  -193,    19,  -193,
      93,  -193,  1172,  -193,   285,  -193,  -193,  -193,    33,  -193,
     770,   227,  -193,  1096,   164,  -193,   770,   363,  -193,  -193,
    -193,   107,  -193,   -42,  -193,  -193,  -193,  -193,  -193,   137,
     137,   106,   106,   222,   222,   222,   222,    52,    52,   223,
      64,    78,    85,   174,   -34,  -193,   489,  -193,   116,   129,
     152,   229,   579,  -193,  -193,  -193,  -193,  -193,   230,   232,
    -193,   234,    93,  1137,   723,  -193,  -193,  -193,  -193,  -193,
    -193,  -193,  -193,  -193,  -193,   770,  -193,   770,  -193,   489,
     489,   489,   770,   746,  -193,  -193,  -193,  -193,   235,  -193,
     257,  -193,  -193,   239,  -193,  -193,   153,   489,   155,  -193,
    -193,   489,   211,  -193,   489,  -193,  -193,  -193
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,   105,    89,    90,    91,    92,    93,    95,    96,    97,
      98,   101,   102,    99,   100,   130,   131,    94,   109,   110,
       0,   209,     0,    79,    81,   103,     0,   104,    83,   212,
     206,   208,     0,   125,     0,   134,     0,   141,    77,     0,
      85,    87,   133,     0,    80,    82,   108,     0,    84,   207,
       1,     0,   128,     0,   126,     0,   145,   143,   142,     0,
      78,     0,     0,   188,     0,   211,     0,     0,     0,   132,
       0,   115,     0,   111,     0,   117,     0,     0,     0,   123,
     135,   146,   144,    86,    87,     2,     3,     4,     5,     0,
       0,     0,     0,    23,    24,    25,    26,    27,    28,     0,
       7,    17,    29,     0,    31,    35,    38,    41,    46,    49,
      51,    53,    55,    57,    59,    61,   170,    88,     2,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     192,   184,    74,     0,   190,   175,   176,     0,     0,   177,
     178,   179,   180,   189,   210,   154,   140,   153,     0,   147,
     149,     0,   137,    29,    76,     0,     0,   114,   107,   112,
       0,     0,   118,   120,   116,   124,   129,   127,     0,    21,
       0,    18,    19,     0,   156,     0,   173,     0,     0,    13,
      14,     0,     0,     0,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    63,     0,    20,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   202,   203,   204,     0,     0,
     193,   186,     0,   185,   191,     0,     0,   151,   158,   152,
     159,   138,     0,   139,     0,   136,   106,   121,     0,   113,
       0,     0,     6,     0,   158,   157,     0,     0,   171,    12,
       9,     0,    15,     0,    11,    62,    32,    33,    34,    36,
      37,    39,    40,    44,    45,    42,    43,    47,    48,    50,
      52,    54,    56,    58,     0,   181,     0,   183,     0,     0,
       0,     0,     0,   201,   205,    75,   187,   166,     0,     0,
     162,     0,   160,     0,     0,   148,   150,   155,   119,   122,
      22,    30,   172,   174,    10,     0,     8,     0,   182,     0,
       0,     0,     0,     0,   167,   161,   163,   168,     0,   164,
       0,    16,    60,   194,   196,   197,     0,     0,     0,   169,
     165,     0,     0,   199,     0,   195,   198,   200
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -193,  -193,  -193,  -193,   -62,  -193,   -92,    48,    49,    53,
      66,    87,    90,   125,   126,    84,  -193,   -67,   -61,  -193,
     -60,   -74,   -20,    50,  -193,   281,  -193,   134,  -193,  -193,
     268,   -55,   -57,  -193,   104,  -193,   290,   276,    17,   -15,
     -39,   -21,  -193,   -65,  -193,   118,  -193,   193,  -127,   -56,
     -91,  -193,  -119,  -193,   -11,   300,   226,  -192,  -193,  -193,
    -193,  -193,   335,  -193,  -193
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,   100,   101,   261,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   132,   195,
     133,   155,    21,   147,    39,    40,    23,    24,    25,    26,
      72,    73,    74,   161,   162,    27,    53,    54,    28,    55,
      42,    43,    58,   298,   149,   150,   151,   175,   299,   240,
     117,   177,   134,   135,   136,    66,   138,   139,   140,   141,
     142,    29,    30,    31,    32
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     116,   154,   148,   166,    69,   222,   153,    41,   176,   214,
     154,   196,    33,    46,   157,   153,    57,   159,   164,   234,
     239,    63,    35,    35,   316,    35,   229,   169,   171,   172,
      65,   292,   173,    78,   229,   174,    35,    82,   116,    15,
      16,   153,    63,    50,    84,   217,   143,   255,   317,    84,
      22,    79,   154,    51,    56,   144,    59,   153,    35,   163,
     229,    35,    78,    52,    75,    37,   204,   205,    67,   228,
      68,   215,    60,    44,    45,    81,   230,   243,    48,    22,
     165,   244,   235,    36,   236,    36,   247,    75,    75,    75,
      37,    64,    75,   154,    34,    47,    36,   285,   153,   287,
     323,   159,    80,    37,    38,   266,   267,   268,   173,    75,
     173,   174,    64,   234,    70,   160,    64,   143,    36,    77,
     262,   235,   263,   236,    61,    37,   238,   252,    37,   206,
     207,   229,   237,   210,   265,   153,   153,   153,   153,   153,
     153,   153,   153,   153,   153,   153,   153,   153,   153,   153,
     153,   153,   153,   254,   257,   284,   303,   211,   304,   288,
     289,   290,   301,   248,   311,   212,   313,   318,   295,   154,
     229,   314,   258,    75,   153,   315,   309,   200,   201,   249,
     319,    71,   302,   154,   229,    75,   294,    64,   153,   178,
     179,   180,   213,   320,   153,   216,   116,   229,   302,    69,
     333,   334,   335,   218,    71,    71,    71,   197,   253,    71,
     236,   219,   198,   199,   238,    37,   321,   342,   343,   344,
     229,   229,   345,   229,   220,   347,    71,   253,   221,   236,
     330,   223,   254,   163,   202,   203,   224,   154,   328,   208,
     209,   225,   153,   181,   226,   182,   241,   183,   269,   270,
     332,   271,   272,   242,   331,   153,   245,   273,   274,   275,
     276,   250,   336,   338,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   277,   278,   118,    86,    87,    88,
     256,    89,   259,    90,    91,   264,   286,   291,   307,   293,
      71,   310,   322,   341,   324,   346,   325,   279,   283,   339,
     326,   280,    71,     1,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,   340,   119,   120,   121,   194,   122,   123,
     124,   125,   126,   127,   128,   129,    92,   281,   156,   282,
      83,    76,    93,    94,    95,    96,    97,    98,   118,    86,
      87,    88,   308,    89,   167,    90,    91,   130,    62,   131,
     306,   251,   137,   232,    49,     0,    85,    86,    87,    88,
       0,    89,     0,    90,    91,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,     0,   119,   120,   121,     0,
     122,   123,   124,   125,   126,   127,   128,   129,    92,     0,
       0,     0,     0,     0,    93,    94,    95,    96,    97,    98,
     118,    86,    87,    88,     0,    89,    92,    90,    91,   130,
      62,   231,    93,    94,    95,    96,    97,    98,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    99,   312,
       0,     0,     0,     0,     0,     0,   118,    86,    87,    88,
       0,    89,     0,    90,    91,     0,     0,     0,   119,   120,
     121,     0,   122,   123,   124,   125,   126,   127,   128,   129,
      92,     0,     0,     0,     0,     0,    93,    94,    95,    96,
      97,    98,   118,    86,    87,    88,     0,    89,     0,    90,
      91,   130,    62,   233,   119,   120,   121,     0,   122,   123,
     124,   125,   126,   127,   128,   129,    92,     0,     0,     0,
       0,     0,    93,    94,    95,    96,    97,    98,    85,    86,
      87,    88,     0,    89,     0,    90,    91,   130,    62,   296,
     119,   120,   121,     0,   122,   123,   124,   125,   126,   127,
     128,   129,    92,     0,     0,     0,     0,     0,    93,    94,
      95,    96,    97,    98,    85,    86,    87,    88,     0,    89,
       0,    90,    91,   130,    62,     0,     0,     0,     0,     0,
       0,     0,    85,    86,    87,    88,     0,    89,    92,    90,
      91,     0,     0,     0,    93,    94,    95,    96,    97,    98,
       0,     0,     0,     0,    85,    86,    87,    88,     0,    89,
      99,    90,    91,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    92,     0,     0,     0,     0,     0,
      93,    94,    95,    96,    97,    98,     0,     0,     0,     0,
       0,     0,    92,     0,     0,   227,     0,     0,    93,    94,
      95,    96,    97,    98,    85,    86,    87,    88,     0,    89,
       0,    90,    91,   130,    92,     0,     0,   152,     0,     0,
      93,    94,    95,    96,    97,    98,     0,    85,    86,    87,
      88,     1,    89,     0,    90,    91,     0,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    85,    86,    87,    88,     0,    89,     0,    90,    91,
       0,     0,     0,     0,    92,     0,     0,     0,     0,     0,
      93,    94,    95,    96,    97,    98,    85,    86,    87,    88,
       0,    89,     0,    90,    91,     0,     0,    92,   260,     0,
       0,     0,     0,    93,    94,    95,    96,    97,    98,    85,
      86,    87,    88,     0,    89,     0,    90,    91,     0,     0,
       0,    92,     0,     0,   300,     0,     0,    93,    94,    95,
      96,    97,    98,    85,    86,    87,    88,     0,    89,     0,
      90,    91,     0,     0,     0,     0,    92,     0,     0,   329,
       0,     0,    93,    94,    95,    96,    97,    98,    85,    86,
      87,    88,     0,    89,     0,    90,    91,     0,     0,    92,
     337,     0,     0,     0,     0,    93,    94,    95,    96,    97,
      98,    85,    86,    87,    88,     0,    89,     0,    90,    91,
       0,     0,     0,    92,     0,     0,     0,     0,     0,    93,
      94,    95,    96,    97,    98,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   168,     0,
       0,     0,     0,     0,    93,    94,    95,    96,    97,    98,
      35,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   170,     0,     0,     0,     0,     0,    93,    94,    95,
      96,    97,    98,     0,     0,     0,     0,     1,     2,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,   145,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     235,   297,   236,     0,     0,     0,     0,    37,     0,     0,
       0,     0,     0,     0,     1,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     1,     0,     0,     0,     0,   146,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,     1,     0,     0,     0,     0,     0,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     1,     0,     0,     0,     0,   158,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,     0,     0,     0,     0,     0,   246,
       1,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
       1,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    61,     0,    62,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    62,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   253,
     297,   236,     0,     0,     0,     0,    37,     1,     2,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   327,     1,     2,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,   305,     1,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20
};

static const yytype_int16 yycheck[] =
{
      61,    68,    67,    77,    43,   124,    68,    22,    99,    19,
      77,   103,     3,     3,    71,    77,    37,    72,    75,   138,
     147,    41,     3,     3,    66,     3,    68,    89,    90,    91,
      41,   223,    92,    68,    68,    92,     3,    58,    99,    44,
      45,   103,    62,     0,    59,   119,    66,   174,    82,    64,
       0,    86,   119,    85,    37,    66,    68,   119,     3,    74,
      68,     3,    68,     3,    47,    70,    14,    15,    63,   129,
      65,    81,    84,    23,    24,    58,    84,    64,    28,    29,
      86,    68,    63,    63,    65,    63,   160,    70,    71,    72,
      70,    41,    75,   160,    85,    85,    63,   216,   160,   218,
     292,   156,    64,    70,    84,   197,   198,   199,   168,    92,
     170,   168,    62,   232,    85,    82,    66,   137,    63,    83,
     181,    63,   182,    65,    83,    70,   147,    64,    70,    77,
      78,    68,   147,    69,   195,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   174,    68,   215,    63,    79,    65,   219,
     220,   221,   236,    68,   256,    80,   257,   286,   229,   236,
      68,    64,    86,   156,   236,    68,   250,    71,    72,    84,
      64,    47,   238,   250,    68,   168,    84,   137,   250,     9,
      10,    11,    18,    64,   256,    82,   257,    68,   254,   238,
     319,   320,   321,    82,    70,    71,    72,    70,    63,    75,
      65,    63,    75,    76,   235,    70,    64,    64,   337,    64,
      68,    68,   341,    68,    63,   344,    92,    63,    63,    65,
     304,    63,   253,   248,    12,    13,     3,   304,   303,    16,
      17,    84,   304,    63,    84,    65,    64,    67,   200,   201,
     317,   202,   203,    68,   315,   317,    66,   204,   205,   206,
     207,    82,   322,   323,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,   208,   209,     3,     4,     5,     6,
      64,     8,     3,    10,    11,     3,    82,    56,     3,    84,
     156,    64,    63,    54,    64,    84,    64,   210,   214,    64,
      66,   211,   168,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    66,    51,    52,    53,    83,    55,    56,
      57,    58,    59,    60,    61,    62,    63,   212,    70,   213,
      59,    51,    69,    70,    71,    72,    73,    74,     3,     4,
       5,     6,   248,     8,    78,    10,    11,    84,    85,    86,
     242,   168,    62,   137,    29,    -1,     3,     4,     5,     6,
      -1,     8,    -1,    10,    11,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    -1,    51,    52,    53,    -1,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    -1,
      -1,    -1,    -1,    -1,    69,    70,    71,    72,    73,    74,
       3,     4,     5,     6,    -1,     8,    63,    10,    11,    84,
      85,    86,    69,    70,    71,    72,    73,    74,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    85,    86,
      -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,
      -1,     8,    -1,    10,    11,    -1,    -1,    -1,    51,    52,
      53,    -1,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    -1,    -1,    -1,    -1,    -1,    69,    70,    71,    72,
      73,    74,     3,     4,     5,     6,    -1,     8,    -1,    10,
      11,    84,    85,    86,    51,    52,    53,    -1,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    -1,    -1,    -1,
      -1,    -1,    69,    70,    71,    72,    73,    74,     3,     4,
       5,     6,    -1,     8,    -1,    10,    11,    84,    85,    86,
      51,    52,    53,    -1,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    -1,    -1,    -1,    -1,    -1,    69,    70,
      71,    72,    73,    74,     3,     4,     5,     6,    -1,     8,
      -1,    10,    11,    84,    85,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     3,     4,     5,     6,    -1,     8,    63,    10,
      11,    -1,    -1,    -1,    69,    70,    71,    72,    73,    74,
      -1,    -1,    -1,    -1,     3,     4,     5,     6,    -1,     8,
      85,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    63,    -1,    -1,    -1,    -1,    -1,
      69,    70,    71,    72,    73,    74,    -1,    -1,    -1,    -1,
      -1,    -1,    63,    -1,    -1,    84,    -1,    -1,    69,    70,
      71,    72,    73,    74,     3,     4,     5,     6,    -1,     8,
      -1,    10,    11,    84,    63,    -1,    -1,    66,    -1,    -1,
      69,    70,    71,    72,    73,    74,    -1,     3,     4,     5,
       6,    30,     8,    -1,    10,    11,    -1,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,     3,     4,     5,     6,    -1,     8,    -1,    10,    11,
      -1,    -1,    -1,    -1,    63,    -1,    -1,    -1,    -1,    -1,
      69,    70,    71,    72,    73,    74,     3,     4,     5,     6,
      -1,     8,    -1,    10,    11,    -1,    -1,    63,    64,    -1,
      -1,    -1,    -1,    69,    70,    71,    72,    73,    74,     3,
       4,     5,     6,    -1,     8,    -1,    10,    11,    -1,    -1,
      -1,    63,    -1,    -1,    66,    -1,    -1,    69,    70,    71,
      72,    73,    74,     3,     4,     5,     6,    -1,     8,    -1,
      10,    11,    -1,    -1,    -1,    -1,    63,    -1,    -1,    66,
      -1,    -1,    69,    70,    71,    72,    73,    74,     3,     4,
       5,     6,    -1,     8,    -1,    10,    11,    -1,    -1,    63,
      64,    -1,    -1,    -1,    -1,    69,    70,    71,    72,    73,
      74,     3,     4,     5,     6,    -1,     8,    -1,    10,    11,
      -1,    -1,    -1,    63,    -1,    -1,    -1,    -1,    -1,    69,
      70,    71,    72,    73,    74,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,    -1,
      -1,    -1,    -1,    -1,    69,    70,    71,    72,    73,    74,
       3,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    63,    -1,    -1,    -1,    -1,    -1,    69,    70,    71,
      72,    73,    74,    -1,    -1,    -1,    -1,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,     3,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      63,    64,    65,    -1,    -1,    -1,    -1,    70,    -1,    -1,
      -1,    -1,    -1,    -1,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    30,    -1,    -1,    -1,    -1,    64,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    30,    -1,    -1,    -1,    -1,    -1,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    30,    -1,    -1,    -1,    -1,    86,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    -1,    -1,    -1,    -1,    -1,    86,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    83,    -1,    85,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    85,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,
      64,    65,    -1,    -1,    -1,    -1,    70,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    64,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,   109,   110,   113,   114,   115,   116,   122,   125,   148,
     149,   150,   151,     3,    85,     3,    63,    70,    84,   111,
     112,   126,   127,   128,   110,   110,     3,    85,   110,   149,
       0,    85,     3,   123,   124,   126,   125,   128,   129,    68,
      84,    83,    85,   109,   110,   141,   142,    63,    65,   127,
      85,   114,   117,   118,   119,   125,   123,    83,    68,    86,
      64,   125,   128,   112,   126,     3,     4,     5,     6,     8,
      10,    11,    63,    69,    70,    71,    72,    73,    74,    85,
      88,    89,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   137,     3,    51,
      52,    53,    55,    56,    57,    58,    59,    60,    61,    62,
      84,    86,   105,   107,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   109,   141,     3,    64,   110,   130,   131,
     132,   133,    66,    91,   104,   108,   117,   119,    86,   118,
      82,   120,   121,   126,   119,    86,   108,   124,    63,    91,
      63,    91,    91,   107,   119,   134,   137,   138,     9,    10,
      11,    63,    65,    67,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    83,   106,    93,    70,    75,    76,
      71,    72,    12,    13,    14,    15,    77,    78,    16,    17,
      69,    79,    80,    18,    19,    81,    82,   108,    82,    63,
      63,    63,   139,    63,     3,    84,    84,    84,   107,    68,
      84,    86,   143,    86,   139,    63,    65,   126,   128,   135,
     136,    64,    68,    64,    68,    66,    86,   108,    68,    84,
      82,   134,    64,    63,   128,   135,    64,    68,    86,     3,
      64,    90,   105,   107,     3,   105,    93,    93,    93,    94,
      94,    95,    95,    96,    96,    96,    96,    97,    97,    98,
      99,   100,   101,   102,   107,   139,    82,   139,   107,   107,
     107,    56,   144,    84,    84,   105,    86,    64,   130,   135,
      66,   108,   136,    63,    65,    50,   132,     3,   121,   108,
      64,    93,    86,   137,    64,    68,    66,    82,   139,    64,
      64,    64,    63,   144,    64,    64,    66,    64,   130,    66,
     108,   105,   104,   139,   139,   139,   107,    64,   107,    64,
      66,    54,    64,   139,    64,   139,    84,   139
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    87,    88,    88,    88,    88,    88,    89,    89,    89,
      89,    89,    89,    89,    89,    90,    90,    91,    91,    91,
      91,    91,    91,    92,    92,    92,    92,    92,    92,    93,
      93,    94,    94,    94,    94,    95,    95,    95,    96,    96,
      96,    97,    97,    97,    97,    97,    98,    98,    98,    99,
      99,   100,   100,   101,   101,   102,   102,   103,   103,   104,
     104,   105,   105,   106,   106,   106,   106,   106,   106,   106,
     106,   106,   106,   106,   107,   107,   108,   109,   109,   110,
     110,   110,   110,   110,   110,   111,   111,   112,   112,   113,
     113,   113,   113,   113,   114,   114,   114,   114,   114,   114,
     114,   114,   114,   114,   114,   114,   115,   115,   115,   116,
     116,   117,   117,   118,   119,   119,   119,   119,   120,   120,
     121,   121,   121,   122,   122,   122,   123,   123,   124,   124,
     125,   125,   126,   126,   127,   127,   127,   127,   127,   127,
     127,   128,   128,   128,   128,   129,   129,   130,   130,   131,
     131,   132,   132,   132,   133,   133,   134,   134,   135,   135,
     135,   136,   136,   136,   136,   136,   136,   136,   136,   136,
     137,   137,   137,   138,   138,   139,   139,   139,   139,   139,
     139,   140,   140,   140,   141,   141,   141,   141,   142,   142,
     143,   143,   144,   144,   145,   145,   145,   146,   146,   146,
     146,   147,   147,   147,   147,   147,   148,   148,   149,   149,
     150,   150,   151
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     3,     1,     4,     3,
       4,     3,     3,     2,     2,     1,     3,     1,     2,     2,
       2,     2,     4,     1,     1,     1,     1,     1,     1,     1,
       4,     1,     3,     3,     3,     1,     3,     3,     1,     3,
       3,     1,     3,     3,     3,     3,     1,     3,     3,     1,
       3,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       5,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     1,     2,     3,     1,
       2,     1,     2,     1,     2,     1,     3,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     5,     4,     2,     1,
       1,     1,     2,     3,     2,     1,     2,     1,     1,     3,
       1,     2,     3,     4,     5,     2,     1,     3,     1,     3,
       1,     1,     2,     1,     1,     3,     4,     3,     4,     4,
       3,     1,     2,     2,     3,     1,     2,     1,     3,     1,
       3,     2,     2,     1,     1,     3,     1,     2,     1,     1,
       2,     3,     2,     3,     3,     4,     2,     3,     3,     4,
       1,     3,     4,     1,     3,     1,     1,     1,     1,     1,
       1,     3,     4,     3,     2,     3,     3,     4,     1,     2,
       1,     2,     1,     2,     5,     7,     5,     5,     7,     6,
       7,     3,     2,     2,     2,     3,     1,     2,     1,     1,
       4,     3,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
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
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

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
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
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
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
          ++yyp;
          ++yyformat;
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

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
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
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
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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
#line 71 "src/parser.y"
                     {(yyval.expr) = new identifier((yyvsp[0].string));}
#line 1839 "src/parser.tab.cpp"
    break;

  case 3:
#line 72 "src/parser.y"
                        {(yyval.expr) = new float_literal((yyvsp[0].f_number));}
#line 1845 "src/parser.tab.cpp"
    break;

  case 4:
#line 73 "src/parser.y"
                      {(yyval.expr) = new int_literal((yyvsp[0].number));}
#line 1851 "src/parser.tab.cpp"
    break;

  case 5:
#line 74 "src/parser.y"
                         {(yyval.expr) = new string_literal(*(yyvsp[0].string));}
#line 1857 "src/parser.tab.cpp"
    break;

  case 6:
#line 75 "src/parser.y"
                             {(yyval.expr) = (yyvsp[-1].expr);}
#line 1863 "src/parser.tab.cpp"
    break;

  case 7:
#line 79 "src/parser.y"
                             {(yyval.expr) = (yyvsp[0].expr);}
#line 1869 "src/parser.tab.cpp"
    break;

  case 17:
#line 95 "src/parser.y"
                             {(yyval.expr) = (yyvsp[0].expr);}
#line 1875 "src/parser.tab.cpp"
    break;

  case 29:
#line 113 "src/parser.y"
                           {(yyval.expr) = (yyvsp[0].expr);}
#line 1881 "src/parser.tab.cpp"
    break;

  case 31:
#line 118 "src/parser.y"
                          {(yyval.expr) = (yyvsp[0].expr);}
#line 1887 "src/parser.tab.cpp"
    break;

  case 35:
#line 125 "src/parser.y"
                                    {(yyval.expr) = (yyvsp[0].expr);}
#line 1893 "src/parser.tab.cpp"
    break;

  case 38:
#line 131 "src/parser.y"
                              {(yyval.expr) = (yyvsp[0].expr);}
#line 1899 "src/parser.tab.cpp"
    break;

  case 41:
#line 137 "src/parser.y"
                           {(yyval.expr) = (yyvsp[0].expr);}
#line 1905 "src/parser.tab.cpp"
    break;

  case 46:
#line 145 "src/parser.y"
                                {(yyval.expr) = (yyvsp[0].expr);}
#line 1911 "src/parser.tab.cpp"
    break;

  case 49:
#line 151 "src/parser.y"
                              {(yyval.expr) = (yyvsp[0].expr);}
#line 1917 "src/parser.tab.cpp"
    break;

  case 51:
#line 156 "src/parser.y"
                         {(yyval.expr) = (yyvsp[0].expr);}
#line 1923 "src/parser.tab.cpp"
    break;

  case 53:
#line 161 "src/parser.y"
                                  {(yyval.expr) = (yyvsp[0].expr);}
#line 1929 "src/parser.tab.cpp"
    break;

  case 55:
#line 166 "src/parser.y"
                                  {(yyval.expr) = (yyvsp[0].expr);}
#line 1935 "src/parser.tab.cpp"
    break;

  case 57:
#line 171 "src/parser.y"
                                 {(yyval.expr) = (yyvsp[0].expr);}
#line 1941 "src/parser.tab.cpp"
    break;

  case 59:
#line 176 "src/parser.y"
                                {(yyval.expr) =(yyvsp[0].expr);}
#line 1947 "src/parser.tab.cpp"
    break;

  case 61:
#line 181 "src/parser.y"
                                 {(yyval.expr) = (yyvsp[0].expr);}
#line 1953 "src/parser.tab.cpp"
    break;

  case 62:
#line 182 "src/parser.y"
                                                                     {(yyval.expr) = new assignment((yyvsp[-2].expr), (yyvsp[0].expr));}
#line 1959 "src/parser.tab.cpp"
    break;

  case 77:
#line 209 "src/parser.y"
                                    {std::cerr << "declaration with no name" << std::endl;}
#line 1965 "src/parser.tab.cpp"
    break;

  case 78:
#line 210 "src/parser.y"
                                                          {(yyval.expr) = new declaration((yyvsp[-2].expr), (yyvsp[-1].exprlist));}
#line 1971 "src/parser.tab.cpp"
    break;

  case 81:
#line 216 "src/parser.y"
                         {(yyval.expr) = (yyvsp[0].expr);}
#line 1977 "src/parser.tab.cpp"
    break;

  case 85:
#line 223 "src/parser.y"
                          {(yyval.exprlist) = new_vector((yyvsp[0].expr));}
#line 1983 "src/parser.tab.cpp"
    break;

  case 86:
#line 224 "src/parser.y"
                                                  {(yyvsp[-2].exprlist)->push_back((yyvsp[0].expr)); (yyval.exprlist) = (yyvsp[-2].exprlist);}
#line 1989 "src/parser.tab.cpp"
    break;

  case 87:
#line 228 "src/parser.y"
                     {(yyval.expr) = (yyvsp[0].expr);}
#line 1995 "src/parser.tab.cpp"
    break;

  case 94:
#line 241 "src/parser.y"
               {}
#line 2001 "src/parser.tab.cpp"
    break;

  case 97:
#line 244 "src/parser.y"
              {(yyval.expr) = new specifier_type("int");}
#line 2007 "src/parser.tab.cpp"
    break;

  case 98:
#line 245 "src/parser.y"
               {(yyval.expr) = new specifier_type("long");}
#line 2013 "src/parser.tab.cpp"
    break;

  case 99:
#line 246 "src/parser.y"
                {(yyval.expr) = new specifier_type("float");}
#line 2019 "src/parser.tab.cpp"
    break;

  case 133:
#line 316 "src/parser.y"
                            {(yyval.expr) = (yyvsp[0].expr);}
#line 2025 "src/parser.tab.cpp"
    break;

  case 134:
#line 320 "src/parser.y"
                     {(yyval.expr) = new identifier((yyvsp[0].string));}
#line 2031 "src/parser.tab.cpp"
    break;

  case 175:
#line 398 "src/parser.y"
                            {(yyval.expr) = (yyvsp[0].expr);}
#line 2037 "src/parser.tab.cpp"
    break;

  case 176:
#line 399 "src/parser.y"
                             {(yyval.expr) = (yyvsp[0].expr);}
#line 2043 "src/parser.tab.cpp"
    break;

  case 177:
#line 400 "src/parser.y"
                               {(yyval.expr) = (yyvsp[0].expr);}
#line 2049 "src/parser.tab.cpp"
    break;

  case 178:
#line 401 "src/parser.y"
                              {(yyval.expr) = (yyvsp[0].expr);}
#line 2055 "src/parser.tab.cpp"
    break;

  case 179:
#line 402 "src/parser.y"
                              {(yyval.expr) = (yyvsp[0].expr);}
#line 2061 "src/parser.tab.cpp"
    break;

  case 180:
#line 403 "src/parser.y"
                         {(yyval.expr) = (yyvsp[0].expr);}
#line 2067 "src/parser.tab.cpp"
    break;

  case 184:
#line 413 "src/parser.y"
                  {(yyval.expr) = new statement_list();}
#line 2073 "src/parser.tab.cpp"
    break;

  case 186:
#line 415 "src/parser.y"
                                   {(yyval.expr) = new statement_list((yyvsp[-1].exprlist));}
#line 2079 "src/parser.tab.cpp"
    break;

  case 188:
#line 420 "src/parser.y"
                      {(yyval.exprlist) = new_vector((yyvsp[0].expr)); std::cout << "declaration" << std::endl;}
#line 2085 "src/parser.tab.cpp"
    break;

  case 189:
#line 421 "src/parser.y"
                                       {(yyvsp[-1].exprlist)->push_back((yyvsp[0].expr)); (yyval.exprlist) = (yyvsp[-1].exprlist);}
#line 2091 "src/parser.tab.cpp"
    break;

  case 190:
#line 425 "src/parser.y"
                    {(yyval.exprlist) = new_vector((yyvsp[0].expr));}
#line 2097 "src/parser.tab.cpp"
    break;

  case 191:
#line 426 "src/parser.y"
                                   {(yyvsp[-1].exprlist)->push_back((yyvsp[0].expr)); (yyval.exprlist) = (yyvsp[-1].exprlist);}
#line 2103 "src/parser.tab.cpp"
    break;

  case 206:
#line 456 "src/parser.y"
                               {(yyval.exprlist) = new_vector((yyvsp[0].expr));}
#line 2109 "src/parser.tab.cpp"
    break;

  case 207:
#line 457 "src/parser.y"
                                                {(yyvsp[-1].exprlist)->push_back((yyvsp[0].expr)); (yyval.exprlist) = (yyvsp[-1].exprlist);}
#line 2115 "src/parser.tab.cpp"
    break;

  case 208:
#line 462 "src/parser.y"
                              {(yyval.expr) = (yyvsp[0].expr);}
#line 2121 "src/parser.tab.cpp"
    break;

  case 209:
#line 463 "src/parser.y"
                      {(yyval.expr) = (yyvsp[0].expr);}
#line 2127 "src/parser.tab.cpp"
    break;

  case 211:
#line 472 "src/parser.y"
                                                               {(yyval.expr) = new function_def((yyvsp[-2].expr), (yyvsp[-1].expr), (yyvsp[0].expr));}
#line 2133 "src/parser.tab.cpp"
    break;

  case 212:
#line 480 "src/parser.y"
                          {g_root = new root((yyvsp[0].exprlist));}
#line 2139 "src/parser.tab.cpp"
    break;


#line 2143 "src/parser.tab.cpp"

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
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

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
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

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


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
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
                  yystos[+*yyssp], yyvsp);
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
#line 481 "src/parser.y"



// classic parser stuff - idk what it does [TO FIGURE OUT]
node *g_root;

node* parseAST(std::string filename)
{
  yyin = fopen(filename.c_str(), "r");
  if(yyin == NULL){
    std::cerr << "Couldn't open input file: " << filename << std::endl;
    exit(1);
  }
  g_root = NULL;
  yyparse();
  std::cout << "parsed" << std::endl;
  return g_root;
} 
