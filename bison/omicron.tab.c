/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "bison/omicron.y" /* yacc.c:339  */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void yyerror();
extern int yylex();
extern int linea;
extern int columna;
extern FILE * fout;


#line 79 "bison/omicron.tab.c" /* yacc.c:339  */

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
   by #include "omicron.tab.h".  */
#ifndef YY_YY_BISON_OMICRON_TAB_H_INCLUDED
# define YY_YY_BISON_OMICRON_TAB_H_INCLUDED
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
    TOK_NONE = 258,
    TOK_CLASS = 259,
    TOK_INHERITS = 260,
    TOK_INSTANCE_OF = 261,
    TOK_DISCARD = 262,
    TOK_ITSELF = 263,
    TOK_FLECHA = 264,
    TOK_HIDDEN = 265,
    TOK_SECRET = 266,
    TOK_EXPOSED = 267,
    TOK_UNIQUE = 268,
    TOK_FUNCTION = 269,
    TOK_RETURN = 270,
    TOK_MAIN = 271,
    TOK_INT = 272,
    TOK_BOOLEAN = 273,
    TOK_ARRAY = 274,
    TOK_IF = 275,
    TOK_ELSE = 276,
    TOK_WHILE = 277,
    TOK_SCANF = 278,
    TOK_PRINTF = 279,
    TOK_IDENTIFICADOR = 280,
    TOK_IGUAL = 281,
    TOK_DISTINTO = 282,
    TOK_MENORIGUAL = 283,
    TOK_MAYORIGUAL = 284,
    TOK_OR = 285,
    TOK_AND = 286,
    TOK_CONSTANTE_ENTERA = 287,
    TOK_FALSE = 288,
    TOK_TRUE = 289,
    TOK_ERROR = 290,
    TOK_FOR = 291,
    TOK_SWITCH = 292,
    TOK_CASE = 293,
    TOK_DEFAULT = 294,
    TOK_FLOAT = 295,
    TOK_MALLOC = 296,
    TOK_CPRINTF = 297,
    TOK_FREE = 298,
    TOK_SET = 299,
    TOK_OF = 300,
    TOK_UNION = 301,
    TOK_INTERSECTION = 302,
    TOK_ADD = 303,
    TOK_CLEAR = 304,
    TOK_SIZE = 305,
    TOK_CONTAINS = 306,
    TOK_CONSTANTE_REAL = 307,
    MENOSU = 308
  };
#endif
/* Tokens.  */
#define TOK_NONE 258
#define TOK_CLASS 259
#define TOK_INHERITS 260
#define TOK_INSTANCE_OF 261
#define TOK_DISCARD 262
#define TOK_ITSELF 263
#define TOK_FLECHA 264
#define TOK_HIDDEN 265
#define TOK_SECRET 266
#define TOK_EXPOSED 267
#define TOK_UNIQUE 268
#define TOK_FUNCTION 269
#define TOK_RETURN 270
#define TOK_MAIN 271
#define TOK_INT 272
#define TOK_BOOLEAN 273
#define TOK_ARRAY 274
#define TOK_IF 275
#define TOK_ELSE 276
#define TOK_WHILE 277
#define TOK_SCANF 278
#define TOK_PRINTF 279
#define TOK_IDENTIFICADOR 280
#define TOK_IGUAL 281
#define TOK_DISTINTO 282
#define TOK_MENORIGUAL 283
#define TOK_MAYORIGUAL 284
#define TOK_OR 285
#define TOK_AND 286
#define TOK_CONSTANTE_ENTERA 287
#define TOK_FALSE 288
#define TOK_TRUE 289
#define TOK_ERROR 290
#define TOK_FOR 291
#define TOK_SWITCH 292
#define TOK_CASE 293
#define TOK_DEFAULT 294
#define TOK_FLOAT 295
#define TOK_MALLOC 296
#define TOK_CPRINTF 297
#define TOK_FREE 298
#define TOK_SET 299
#define TOK_OF 300
#define TOK_UNION 301
#define TOK_INTERSECTION 302
#define TOK_ADD 303
#define TOK_CLEAR 304
#define TOK_SIZE 305
#define TOK_CONTAINS 306
#define TOK_CONSTANTE_REAL 307
#define MENOSU 308

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_BISON_OMICRON_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 236 "bison/omicron.tab.c" /* yacc.c:358  */

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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   302

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  71
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  40
/* YYNRULES -- Number of rules.  */
#define YYNRULES  105
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  213

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   308

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    58,     2,     2,     2,     2,     2,     2,
      65,    66,    55,    53,    64,    54,    67,    56,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    61,
      70,    68,    69,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    62,     2,    63,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    59,     2,    60,     2,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50,    51,    52,    57
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    78,    78,    83,    89,    94,   100,   105,   111,   116,
     121,   126,   131,   136,   141,   147,   152,   157,   162,   169,
     174,   179,   186,   191,   197,   202,   208,   214,   220,   225,
     231,   237,   242,   248,   253,   258,   264,   269,   275,   280,
     286,   291,   296,   303,   307,   313,   318,   324,   329,   335,
     340,   345,   350,   355,   360,   365,   371,   377,   382,   388,
     393,   398,   403,   408,   414,   420,   425,   431,   437,   442,
     448,   454,   459,   465,   470,   475,   480,   485,   490,   495,
     500,   505,   510,   515,   520,   525,   530,   535,   540,   547,
     552,   558,   564,   569,   575,   580,   585,   590,   595,   600,
     605,   611,   616,   622,   627,   633
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TOK_NONE", "TOK_CLASS", "TOK_INHERITS",
  "TOK_INSTANCE_OF", "TOK_DISCARD", "TOK_ITSELF", "TOK_FLECHA",
  "TOK_HIDDEN", "TOK_SECRET", "TOK_EXPOSED", "TOK_UNIQUE", "TOK_FUNCTION",
  "TOK_RETURN", "TOK_MAIN", "TOK_INT", "TOK_BOOLEAN", "TOK_ARRAY",
  "TOK_IF", "TOK_ELSE", "TOK_WHILE", "TOK_SCANF", "TOK_PRINTF",
  "TOK_IDENTIFICADOR", "TOK_IGUAL", "TOK_DISTINTO", "TOK_MENORIGUAL",
  "TOK_MAYORIGUAL", "TOK_OR", "TOK_AND", "TOK_CONSTANTE_ENTERA",
  "TOK_FALSE", "TOK_TRUE", "TOK_ERROR", "TOK_FOR", "TOK_SWITCH",
  "TOK_CASE", "TOK_DEFAULT", "TOK_FLOAT", "TOK_MALLOC", "TOK_CPRINTF",
  "TOK_FREE", "TOK_SET", "TOK_OF", "TOK_UNION", "TOK_INTERSECTION",
  "TOK_ADD", "TOK_CLEAR", "TOK_SIZE", "TOK_CONTAINS", "TOK_CONSTANTE_REAL",
  "'+'", "'-'", "'*'", "'/'", "MENOSU", "'!'", "'{'", "'}'", "';'", "'['",
  "']'", "','", "'('", "')'", "'.'", "'='", "'>'", "'<'", "$accept",
  "programa", "declaraciones", "declaracion", "modificadores_acceso",
  "clase", "declaracion_clase", "modificadores_clase", "clase_escalar",
  "tipo", "clase_objeto", "clase_vector", "identificadores", "funciones",
  "funcion", "tipo_retorno", "parametros_funcion",
  "resto_parametros_funcion", "parametro_funcion", "declaraciones_funcion",
  "sentencias", "sentencia", "sentencia_simple", "destruir_objeto",
  "bloque", "asignacion", "elemento_vector", "condicional", "bucle",
  "lectura", "escritura", "retorno_funcion", "exp", "identificador_clase",
  "lista_expresiones", "resto_lista_expresiones", "comparacion",
  "constante", "constante_logica", "constante_entera", YY_NULLPTR
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
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,    43,    45,    42,    47,   308,    33,   123,
     125,    59,    91,    93,    44,    40,    41,    46,    61,    62,
      60
};
# endif

#define YYPACT_NINF -81

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-81)))

#define YYTABLE_NINF -90

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -3,   -44,    21,   189,   -81,    18,    42,    45,   -81,   134,
      46,   200,    20,   277,    46,   -81,   -81,   -81,     9,   277,
     -81,   -81,   -81,    81,    39,    49,   -27,    66,   -81,   -81,
     -81,   -81,    53,   -81,     8,    15,    23,    68,   105,   -33,
      35,   277,    50,   -81,   -81,   -81,    44,   -81,   -81,   -81,
     -81,   -81,    48,   -81,   -81,   -81,   -81,   101,    73,    67,
      75,    84,    71,   -81,   111,   -81,   -81,    54,   -81,   -81,
     -81,   105,   105,   105,   -81,   227,    82,   -81,   -81,   -81,
     105,   105,    92,   -81,   227,   105,   105,    11,   -81,   -81,
     -81,    69,   135,    96,   -81,   130,   -81,    49,   -81,     0,
     105,   -81,   -81,   196,    99,   105,   105,   105,   105,   105,
     105,   141,    87,   190,   184,   223,   103,   142,   227,   143,
     227,   -43,    72,   108,   -81,    49,   134,   106,   105,   105,
     105,   105,   -81,   105,   105,   -81,    41,   -81,    41,    41,
     -81,   -81,   109,   116,   117,   -81,   105,   -81,   -81,   112,
     114,   105,   105,   155,   156,   118,   121,   -81,   127,    46,
     -81,   227,   227,   227,   227,   227,   227,   105,   277,   277,
     223,   105,   105,   123,   227,   -81,   131,   136,    72,   -81,
      40,   137,   128,   145,   149,   -81,   150,   162,   -81,   200,
     204,   121,    46,   170,   -81,   -81,   210,   -81,   -81,   -81,
     -81,   277,   -81,   -81,   172,   -81,   174,   175,   -81,   277,
     -81,   176,   -81
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,    31,     1,    11,    12,    13,    14,    15,
      31,     4,    22,     0,    31,     8,     9,    10,     0,     0,
       5,    24,    25,     0,     0,     0,     0,     0,    16,    23,
      18,    17,     0,    90,     0,     0,     0,     0,     0,    89,
       0,    45,     0,    55,    48,    49,     0,    57,    58,    50,
      51,    52,     0,    30,    33,    34,    35,     0,     0,     0,
       0,    28,     0,     7,     0,    56,    72,    81,   105,   104,
     103,     0,     0,     0,    85,    71,     0,    82,   101,   102,
       0,     0,    68,    69,    70,     0,    92,     0,     3,    46,
      47,     0,     0,     0,     2,     0,    26,     0,     6,     0,
      92,    77,    80,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    94,     0,     0,    59,     0,
      60,     0,    38,     0,    29,     0,    15,     0,     0,     0,
       0,     0,    83,     0,     0,    84,    79,    78,    73,    74,
      76,    75,    88,     0,     0,    64,     0,    91,    54,     0,
       0,    92,     0,     0,     0,     0,    40,    27,     0,    31,
      86,    95,    96,    98,    97,    99,   100,    92,     0,     0,
      94,    92,    92,     0,    63,    41,    37,     0,     0,    36,
      15,     0,     0,     0,     0,    93,     0,     0,    53,    43,
       0,    40,    31,     0,    21,    87,    65,    67,    62,    61,
      44,     0,    42,    39,     0,    20,     0,     0,    19,     0,
      32,     0,    66
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -81,   -81,    -2,   -81,   225,   -81,   -81,   -81,   -81,   102,
     -14,   -81,   -79,    -7,   -81,   -81,   -81,    51,    63,   -81,
     -18,   -81,   -81,   -81,   -81,   -81,   -13,   -81,   -81,   -81,
     -81,   -81,   -24,   -11,   -80,    85,   -81,   -81,   -81,   -81
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    10,    11,    12,    25,    26,    27,    28,   153,
      30,    31,    62,    13,    14,    57,   155,   179,   156,   201,
      40,    41,    42,    43,    44,    45,    74,    47,    48,    49,
      50,    51,   115,    76,   116,   147,   104,    77,    78,    79
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      46,    58,    52,    19,    56,   125,    46,    53,    52,    20,
      75,    66,    54,     1,    84,     3,    33,   117,   124,    33,
     127,     4,   151,    89,    83,   152,    21,    22,    46,    85,
      52,    15,    86,    67,    63,    87,    67,    21,    22,    23,
      68,    69,    70,    68,    69,    70,   158,   101,   102,   103,
       5,     6,     7,     8,     9,    16,   112,   113,    17,   126,
       9,   114,    71,   118,    60,    71,    72,   120,    24,    72,
      64,   173,   106,    73,    61,   119,    73,    33,    65,    24,
      80,   136,   137,   138,   139,   140,   141,   182,    81,    21,
      22,   186,   187,    82,    67,    88,   109,   110,    21,    22,
     -31,    68,    69,    70,   161,   162,   163,   164,   154,   165,
     166,    90,    91,    33,    29,    92,    85,   105,   106,   100,
      55,   -89,   170,    71,   159,    59,    93,    72,   174,    95,
      67,    24,    98,    94,    73,    96,    99,    68,    69,    70,
     107,   108,   109,   110,     5,     6,     7,     8,    97,   111,
     183,   184,   181,   143,    85,    46,    46,    52,    52,    71,
     121,   122,   123,    72,   190,   135,   142,   149,   150,   148,
      73,   157,   160,   193,   167,   168,   169,   171,   192,   172,
     175,   176,   178,   207,   177,   204,   180,   200,    46,   188,
      52,   211,   -42,   -15,   195,   189,    46,   194,    52,     5,
       6,     7,     8,     9,   -15,   196,   -15,   -15,   -15,   197,
       5,     6,     7,     8,   105,   106,   198,   -15,   -15,   -15,
     105,   106,   128,   129,   130,   131,   105,   106,   199,   202,
     205,   206,   208,   209,    18,   210,   212,   107,   108,   109,
     110,   191,   203,   107,   108,   109,   110,   145,   -15,   107,
     108,   109,   110,   105,   106,   185,   144,   105,   106,   -15,
       0,     0,   132,     0,     0,   133,   134,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   107,   108,   109,   110,
     107,   108,   109,   110,    32,    33,     0,   146,     0,     0,
       0,     0,    34,     0,     0,     0,     0,    35,     0,    36,
      37,    38,    39
};

static const yytype_int16 yycheck[] =
{
      13,    19,    13,    10,    18,     5,    19,    14,    19,    11,
      34,     3,     3,    16,    38,    59,     8,     6,    97,     8,
     100,     0,    65,    41,    37,    68,    17,    18,    41,    62,
      41,    13,    65,    25,    61,    68,    25,    17,    18,    19,
      32,    33,    34,    32,    33,    34,   125,    71,    72,    73,
      10,    11,    12,    13,    14,    13,    80,    81,    13,    59,
      14,    85,    54,    87,    25,    54,    58,    91,    59,    58,
       4,   151,    31,    65,    25,     6,    65,     8,    25,    59,
      65,   105,   106,   107,   108,   109,   110,   167,    65,    17,
      18,   171,   172,    25,    25,    60,    55,    56,    17,    18,
      60,    32,    33,    34,   128,   129,   130,   131,   122,   133,
     134,    61,    68,     8,    12,    67,    62,    30,    31,    65,
      18,    67,   146,    54,   126,    23,    25,    58,   152,    62,
      25,    59,    61,    60,    65,    60,    25,    32,    33,    34,
      53,    54,    55,    56,    10,    11,    12,    13,    64,    67,
     168,   169,   159,    66,    62,   168,   169,   168,   169,    54,
      25,    65,    32,    58,   178,    66,    25,    25,    25,    66,
      65,    63,    66,   180,    65,    59,    59,    65,   180,    65,
      25,    25,    61,   201,    66,   192,    59,   189,   201,    66,
     201,   209,    61,     4,    66,    59,   209,    60,   209,    10,
      11,    12,    13,    14,     4,    60,    17,    18,    19,    60,
      10,    11,    12,    13,    30,    31,    66,    17,    18,    19,
      30,    31,    26,    27,    28,    29,    30,    31,    66,    25,
      60,    21,    60,    59,     9,    60,    60,    53,    54,    55,
      56,   178,   191,    53,    54,    55,    56,    63,    59,    53,
      54,    55,    56,    30,    31,   170,    66,    30,    31,    59,
      -1,    -1,    66,    -1,    -1,    69,    70,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    53,    54,    55,    56,
      53,    54,    55,    56,     7,     8,    -1,    64,    -1,    -1,
      -1,    -1,    15,    -1,    -1,    -1,    -1,    20,    -1,    22,
      23,    24,    25
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    16,    72,    59,     0,    10,    11,    12,    13,    14,
      73,    74,    75,    84,    85,    13,    13,    13,    75,    84,
      73,    17,    18,    19,    59,    76,    77,    78,    79,    80,
      81,    82,     7,     8,    15,    20,    22,    23,    24,    25,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   104,    84,     3,    80,    81,    86,    91,    80,
      25,    25,    83,    61,     4,    25,     3,    25,    32,    33,
      34,    54,    58,    65,    97,   103,   104,   108,   109,   110,
      65,    65,    25,    97,   103,    62,    65,    68,    60,    91,
      61,    68,    67,    25,    60,    62,    60,    64,    61,    25,
      65,   103,   103,   103,   107,    30,    31,    53,    54,    55,
      56,    67,   103,   103,   103,   103,   105,     6,   103,     6,
     103,    25,    65,    32,    83,     5,    59,   105,    26,    27,
      28,    29,    66,    69,    70,    66,   103,   103,   103,   103,
     103,   103,    25,    66,    66,    63,    64,   106,    66,    25,
      25,    65,    68,    80,    81,    87,    89,    63,    83,    73,
      66,   103,   103,   103,   103,   103,   103,    65,    59,    59,
     103,    65,    65,   105,   103,    25,    25,    66,    61,    88,
      59,    84,   105,    91,    91,   106,   105,   105,    66,    59,
      81,    89,    73,    84,    60,    66,    60,    60,    66,    66,
      73,    90,    25,    88,    84,    60,    21,    91,    60,    59,
      60,    91,    60
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    71,    72,    72,    73,    73,    74,    74,    75,    75,
      75,    75,    75,    75,    75,    75,    76,    76,    76,    77,
      77,    77,    78,    79,    80,    80,    81,    82,    83,    83,
      84,    84,    85,    86,    86,    86,    87,    87,    87,    88,
      88,    89,    89,    90,    90,    91,    91,    92,    92,    93,
      93,    93,    93,    93,    93,    93,    94,    95,    95,    96,
      96,    96,    96,    96,    97,    98,    98,    99,   100,   100,
     101,   102,   102,   103,   103,   103,   103,   103,   103,   103,
     103,   103,   103,   103,   103,   103,   103,   103,   103,   104,
     104,   105,   105,   106,   106,   107,   107,   107,   107,   107,
     107,   108,   108,   109,   109,   110
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     6,     5,     1,     2,     4,     3,     2,     2,
       2,     1,     1,     1,     1,     0,     1,     1,     1,     9,
       8,     7,     0,     1,     1,     1,     3,     5,     1,     3,
       2,     0,    11,     1,     1,     1,     2,     2,     0,     3,
       0,     2,     2,     0,     1,     1,     2,     2,     1,     1,
       1,     1,     1,     6,     4,     1,     2,     1,     1,     3,
       3,     7,     7,     5,     4,     7,    11,     7,     2,     2,
       2,     2,     2,     3,     3,     3,     3,     2,     3,     3,
       2,     1,     1,     3,     3,     1,     4,     6,     3,     1,
       1,     2,     0,     3,     0,     3,     3,     3,     3,     3,
       3,     1,     1,     1,     1,     1
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
#line 79 "bison/omicron.y" /* yacc.c:1646  */
    {
			fprintf(fout, ";R:\tprograma: TOK_MAIN '{' declaraciones funciones sentencias '}'\n");
		}
#line 1495 "bison/omicron.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 84 "bison/omicron.y" /* yacc.c:1646  */
    {
			fprintf(fout, ";R:\tprograma: TOK_MAIN '{' funciones sentencias '}'\n");
		}
#line 1503 "bison/omicron.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 90 "bison/omicron.y" /* yacc.c:1646  */
    {
			fprintf(fout, ";R:\tdeclaraciones: declaracion\n");
		}
#line 1511 "bison/omicron.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 95 "bison/omicron.y" /* yacc.c:1646  */
    {
			fprintf(fout, ";R:\tdeclaraciones: declaracion declaraciones\n");
		}
#line 1519 "bison/omicron.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 101 "bison/omicron.y" /* yacc.c:1646  */
    {
			fprintf(fout, ";R:\tdeclaracion: modificadores_acceso clase identificadores ';'\n");
		}
#line 1527 "bison/omicron.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 106 "bison/omicron.y" /* yacc.c:1646  */
    {
			fprintf(fout, ";R:\tdeclaracion: modificadores_acceso declaracion_clase ';'\n");
		}
#line 1535 "bison/omicron.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 112 "bison/omicron.y" /* yacc.c:1646  */
    {
			fprintf(fout, ";R:\tmodificadores_acceso:\tTOK_HIDDEN TOK_UNIQUE\n");
		}
#line 1543 "bison/omicron.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 117 "bison/omicron.y" /* yacc.c:1646  */
    {
			fprintf(fout, ";R:\tmodificadores_acceso:\tTOK_SECRET TOK_UNIQUE\n");
		}
#line 1551 "bison/omicron.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 122 "bison/omicron.y" /* yacc.c:1646  */
    {
			fprintf(fout, ";R:\tmodificadores_acceso:\tTOK_EXPOSED TOK_UNIQUE\n");
		}
#line 1559 "bison/omicron.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 127 "bison/omicron.y" /* yacc.c:1646  */
    {
			fprintf(fout, ";R:\tmodificadores_acceso:\tTOK_HIDDEN\n");
		}
#line 1567 "bison/omicron.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 132 "bison/omicron.y" /* yacc.c:1646  */
    {
			fprintf(fout, ";R:\tmodificadores_acceso:\tTOK_SECRET\n");
		}
#line 1575 "bison/omicron.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 137 "bison/omicron.y" /* yacc.c:1646  */
    {
			fprintf(fout, ";R\tmodificadores_acceso:\tTOK_EXPOSED\n");
		}
#line 1583 "bison/omicron.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 142 "bison/omicron.y" /* yacc.c:1646  */
    {
			fprintf(fout, ";R:\tmodificadores_acceso:\tTOK_UNIQUE\n");
		}
#line 1591 "bison/omicron.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 147 "bison/omicron.y" /* yacc.c:1646  */
    {
			fprintf(fout, ";R:\tmodificadores_acceso: \n");
		}
#line 1599 "bison/omicron.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 153 "bison/omicron.y" /* yacc.c:1646  */
    {
			fprintf(fout, ";R:\tclase: clase_escalar\n");
		}
#line 1607 "bison/omicron.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 158 "bison/omicron.y" /* yacc.c:1646  */
    {
			fprintf(fout, ";R:\tclase: clase_vector\n");
		}
#line 1615 "bison/omicron.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 163 "bison/omicron.y" /* yacc.c:1646  */
    {
			fprintf(fout, ";R:\tclase: clase_objeto\n");
		}
#line 1623 "bison/omicron.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 170 "bison/omicron.y" /* yacc.c:1646  */
    {
			fprintf(fout, ";R:\tdeclaracion_clase: modificadores_clase TOK_CLASS TOK_IDENTIFICADOR TOK_INHERITS identificadores '{' declaraciones funciones '}' \n");
		}
#line 1631 "bison/omicron.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 175 "bison/omicron.y" /* yacc.c:1646  */
    {
			fprintf(fout, ";R:\tdeclaracion_clase: modificadores_clase TOK_CLASS TOK_IDENTIFICADOR TOK_INHERITS identificadores '{' declaraciones funciones '}' \n");
		}
#line 1639 "bison/omicron.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 180 "bison/omicron.y" /* yacc.c:1646  */
    {
			fprintf(fout, ";R:\tdeclaracion_clase: modificadores_clase TOK_CLASS TOK_IDENTIFICADOR '{' declaraciones funciones '}'\n");
		}
#line 1647 "bison/omicron.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 186 "bison/omicron.y" /* yacc.c:1646  */
    {
			fprintf(fout, ";R:\tmodificadores_clase: \n");
		}
#line 1655 "bison/omicron.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 192 "bison/omicron.y" /* yacc.c:1646  */
    {
			fprintf(fout, ";R:\tclase_escalar: tipo\n");
		}
#line 1663 "bison/omicron.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 198 "bison/omicron.y" /* yacc.c:1646  */
    {
			fprintf(fout, ";R:\ttipo:\tTOK_INT\n");
		}
#line 1671 "bison/omicron.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 203 "bison/omicron.y" /* yacc.c:1646  */
    {
			fprintf(fout, ";R\ttipo:\tTOK_BOOLEAN\n");
		}
#line 1679 "bison/omicron.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 209 "bison/omicron.y" /* yacc.c:1646  */
    {
			fprintf(fout, ";R:\tclase_objeto: '{' TOK_IDENTIFICADOR '}'\n");
		}
#line 1687 "bison/omicron.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 215 "bison/omicron.y" /* yacc.c:1646  */
    {
			fprintf(fout, ";R:\tclase_vector: TOK_ARRAY tipo '[' TOK_CONSTANTE_ENTERA ']'\n");
		}
#line 1695 "bison/omicron.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 221 "bison/omicron.y" /* yacc.c:1646  */
    {
			fprintf(fout, ";R:\tidentificadores:\tTOK_IDENTIFICADOR\n");
		}
#line 1703 "bison/omicron.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 226 "bison/omicron.y" /* yacc.c:1646  */
    {
			fprintf(fout, ";R:\tidentificadores:\tTOK_IDENTIFICADOR ',' identificadores\n");
		}
#line 1711 "bison/omicron.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 232 "bison/omicron.y" /* yacc.c:1646  */
    {
			fprintf(fout, ";R:\tfunciones: funcion funciones\n");
		}
#line 1719 "bison/omicron.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 237 "bison/omicron.y" /* yacc.c:1646  */
    {
			fprintf(fout, ";R:\tfunciones:\n");
		}
#line 1727 "bison/omicron.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 243 "bison/omicron.y" /* yacc.c:1646  */
    {
			fprintf(fout, ";R:\tfuncion:\tTOK_FUNCTION modificadores_acceso tipo_retorno TOK_IDENTIFICADOR '(' parametros_funcion ')' '{' declaraciones_funcion sentencias '}'\n");
		}
#line 1735 "bison/omicron.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 249 "bison/omicron.y" /* yacc.c:1646  */
    {
			fprintf(fout, ";R:\ttipo_retorno:\tTOK_NONE\n");
		}
#line 1743 "bison/omicron.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 254 "bison/omicron.y" /* yacc.c:1646  */
    {
			fprintf(fout, ";R\ttipo_retorno:\ttipo\n");
		}
#line 1751 "bison/omicron.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 259 "bison/omicron.y" /* yacc.c:1646  */
    {
			fprintf(fout, ";R\ttipo_retorno:\tclase_objeto\n");
		}
#line 1759 "bison/omicron.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 265 "bison/omicron.y" /* yacc.c:1646  */
    {
			fprintf(fout, ";R:\tparametros_funcion: parametro_funcion resto_parametros_funcion\n");
		}
#line 1767 "bison/omicron.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 270 "bison/omicron.y" /* yacc.c:1646  */
    {
			fprintf(fout, ";R:\tparametros_funcion: clase_objeto TOK_IDENTIFICADOR\n");
		}
#line 1775 "bison/omicron.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 275 "bison/omicron.y" /* yacc.c:1646  */
    {
			fprintf(fout, ";R:\tparametros_funcion:\n");
		}
#line 1783 "bison/omicron.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 281 "bison/omicron.y" /* yacc.c:1646  */
    {
			fprintf(fout, ";R:\tresto_parametros_funcion: ';' parametro_funcion resto_parametros_funcion\n");
		}
#line 1791 "bison/omicron.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 286 "bison/omicron.y" /* yacc.c:1646  */
    {
			fprintf(fout, ";R:\tresto_parametros_funcion:\n");
		}
#line 1799 "bison/omicron.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 292 "bison/omicron.y" /* yacc.c:1646  */
    {
			fprintf(fout, ";R:\tparametro_funcion: tipo TOK_IDENTIFICADOR\n");
		}
#line 1807 "bison/omicron.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 297 "bison/omicron.y" /* yacc.c:1646  */
    {
			fprintf(fout, ";R:\tparametro_funcion: clase_objeto TOK_IDENTIFICADOR\n");
		}
#line 1815 "bison/omicron.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 303 "bison/omicron.y" /* yacc.c:1646  */
    {
			fprintf(fout, ";R:\tdeclaraciones_funcion: \n");
		}
#line 1823 "bison/omicron.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 308 "bison/omicron.y" /* yacc.c:1646  */
    {
			fprintf(fout, ";R:\tdeclaraciones_funcion: declaraciones\n");
		}
#line 1831 "bison/omicron.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 314 "bison/omicron.y" /* yacc.c:1646  */
    {
			fprintf(fout, ";R:\tsentencias: sentencia\n");
		}
#line 1839 "bison/omicron.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 319 "bison/omicron.y" /* yacc.c:1646  */
    {
			fprintf(fout, ";R:\tsentencias: sentencia sentencias\n");
		}
#line 1847 "bison/omicron.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 325 "bison/omicron.y" /* yacc.c:1646  */
    {
			fprintf(fout, ";R:\tsentencia:\tsentencia_simple ';'\n");
		}
#line 1855 "bison/omicron.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 330 "bison/omicron.y" /* yacc.c:1646  */
    {
			fprintf(fout, ";R:\tsentencia: bloque\n");
		}
#line 1863 "bison/omicron.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 336 "bison/omicron.y" /* yacc.c:1646  */
    {
			fprintf(fout, ";R:\tsentencia_simple:\tasignacion\n");
		}
#line 1871 "bison/omicron.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 341 "bison/omicron.y" /* yacc.c:1646  */
    {
			fprintf(fout, ";R:\tsentencia_simple:\tlectura\n");
		}
#line 1879 "bison/omicron.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 346 "bison/omicron.y" /* yacc.c:1646  */
    {
			fprintf(fout, ";R:\tsentencia_simple:\tescritura\n");
		}
#line 1887 "bison/omicron.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 351 "bison/omicron.y" /* yacc.c:1646  */
    {
			fprintf(fout, ";R\tsentencia_simple:\tretorno_funcion\n");
		}
#line 1895 "bison/omicron.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 356 "bison/omicron.y" /* yacc.c:1646  */
    {
			fprintf(fout, ";R:\tsentencia_simple:\tidentificador_clase '.' TOK_IDENTIFICADOR '(' lista_expresiones ')'\n");
		}
#line 1903 "bison/omicron.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 361 "bison/omicron.y" /* yacc.c:1646  */
    {
			fprintf(fout, ";R:\tsentencia_simple:\tTOK_IDENTIFICADOR '(' lista_expresiones ')'\n");
		}
#line 1911 "bison/omicron.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 366 "bison/omicron.y" /* yacc.c:1646  */
    {
			fprintf(fout, ";R:\tsentencia_simple:\tdestruir_objeto\n");
		}
#line 1919 "bison/omicron.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 372 "bison/omicron.y" /* yacc.c:1646  */
    {
			fprintf(fout, ";R:\tdestruir_objeto:\tTOK_DISCARD TOK_IDENTIFICADOR\n");
		}
#line 1927 "bison/omicron.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 378 "bison/omicron.y" /* yacc.c:1646  */
    {
			fprintf(fout, ";R:\tbloque:\tcondicional\n");
		}
#line 1935 "bison/omicron.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 383 "bison/omicron.y" /* yacc.c:1646  */
    {
			fprintf(fout, ";R:\tbloque:\tbucle\n");
		}
#line 1943 "bison/omicron.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 389 "bison/omicron.y" /* yacc.c:1646  */
    {
			fprintf(fout, ";R:\tasignacion:\tTOK_IDENTIFICADOR '=' exp\n");
		}
#line 1951 "bison/omicron.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 394 "bison/omicron.y" /* yacc.c:1646  */
    {
			fprintf(fout, ";R:\tasignacion:\telemento_vector '=' exp\n");
		}
#line 1959 "bison/omicron.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 399 "bison/omicron.y" /* yacc.c:1646  */
    {
			fprintf(fout, ";R:\tasignacion:\telemento_vector '=' TOK_INSTANCE_OF TOK_IDENTIFICADOR '(' lista_expresiones ')'\n");
		}
#line 1967 "bison/omicron.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 404 "bison/omicron.y" /* yacc.c:1646  */
    {
			fprintf(fout, ";R:\tasignacion:\tTOK_IDENTIFICADOR '=' TOK_INSTANCE_OF TOK_IDENTIFICADOR '(' lista_expresiones ')'\n");
		}
#line 1975 "bison/omicron.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 409 "bison/omicron.y" /* yacc.c:1646  */
    {
			fprintf(fout, ";R:\tasignacion:\tidentificador_clase '.' TOK_IDENTIFICADOR '=' exp\n");
		}
#line 1983 "bison/omicron.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 415 "bison/omicron.y" /* yacc.c:1646  */
    {
			fprintf(fout, ";R:\telemento_vector:\tTOK_IDENTIFICADOR '[' exp ']'\n");
		}
#line 1991 "bison/omicron.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 421 "bison/omicron.y" /* yacc.c:1646  */
    {
			fprintf(fout, ";R:\tcondicional:\tTOK_IF '(' exp ')' '{' sentencias '}'\n");
		}
#line 1999 "bison/omicron.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 426 "bison/omicron.y" /* yacc.c:1646  */
    {
			fprintf(fout, ";R:\tcondicional:\tTOK_IF '(' exp ')' '{' sentencias '}' TOK_ELSE '{' sentencias '}'\n");
		}
#line 2007 "bison/omicron.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 432 "bison/omicron.y" /* yacc.c:1646  */
    {
			fprintf(fout, ";R:\tbucle:\tTOK_WHILE '(' exp ')' '{' sentencias '}'\n");
		}
#line 2015 "bison/omicron.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 438 "bison/omicron.y" /* yacc.c:1646  */
    {
			fprintf(fout, ";R:\tlectura:\tTOK_SCANF TOK_IDENTIFICADOR\n");
		}
#line 2023 "bison/omicron.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 443 "bison/omicron.y" /* yacc.c:1646  */
    {
			fprintf(fout, ";R:\tlectura:\tTOK_SCANF elemento_vector\n");
		}
#line 2031 "bison/omicron.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 449 "bison/omicron.y" /* yacc.c:1646  */
    {
			fprintf(fout, ";R:\tescritura:\tTOK_PRINTF exp\n");
		}
#line 2039 "bison/omicron.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 455 "bison/omicron.y" /* yacc.c:1646  */
    {
			fprintf(fout, ";R:\tretorno_funcion:\tTOK_RETURN exp\n");
		}
#line 2047 "bison/omicron.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 460 "bison/omicron.y" /* yacc.c:1646  */
    {
			fprintf(fout, ";R:\tretorno_funcion:\tTOK_RETURN TOK_NONE\n");
		}
#line 2055 "bison/omicron.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 466 "bison/omicron.y" /* yacc.c:1646  */
    {
			fprintf(fout, ";R:\texp: exp '+' exp\n");
		}
#line 2063 "bison/omicron.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 471 "bison/omicron.y" /* yacc.c:1646  */
    {
			fprintf(fout, ";R:\texp: exp '-' exp\n");
		}
#line 2071 "bison/omicron.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 476 "bison/omicron.y" /* yacc.c:1646  */
    {
			fprintf(fout, ";R:\texp: exp '/' exp\n");
		}
#line 2079 "bison/omicron.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 481 "bison/omicron.y" /* yacc.c:1646  */
    {
			fprintf(fout, ";R:\texp: exp '*' exp\n");
		}
#line 2087 "bison/omicron.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 486 "bison/omicron.y" /* yacc.c:1646  */
    {
			fprintf(fout, ";R:\texp: '-' exp\n");
		}
#line 2095 "bison/omicron.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 491 "bison/omicron.y" /* yacc.c:1646  */
    {
			fprintf(fout, ";R:\texp TOK_AND exp\n");
		}
#line 2103 "bison/omicron.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 496 "bison/omicron.y" /* yacc.c:1646  */
    {
			fprintf(fout, ";R:\texp TOK_OR exp\n");
		}
#line 2111 "bison/omicron.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 501 "bison/omicron.y" /* yacc.c:1646  */
    {
			fprintf(fout, ";R:\texp: '!' exp\n");
		}
#line 2119 "bison/omicron.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 506 "bison/omicron.y" /* yacc.c:1646  */
    {
			fprintf(fout, ";R:\texp: TOK_IDENTIFICADOR\n");
		}
#line 2127 "bison/omicron.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 511 "bison/omicron.y" /* yacc.c:1646  */
    {
			fprintf(fout, ";R:\texp: constante\n");
		}
#line 2135 "bison/omicron.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 516 "bison/omicron.y" /* yacc.c:1646  */
    {
			fprintf(fout, ";R:\texp: '(' exp ')'\n");
		}
#line 2143 "bison/omicron.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 521 "bison/omicron.y" /* yacc.c:1646  */
    {
			fprintf(fout, ";R:\texp: '(' comparacion ')'\n");
		}
#line 2151 "bison/omicron.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 526 "bison/omicron.y" /* yacc.c:1646  */
    {
			fprintf(fout, ";R:\texp: elemento_vector\n");
		}
#line 2159 "bison/omicron.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 531 "bison/omicron.y" /* yacc.c:1646  */
    {
			fprintf(fout, ";R:\texp: TOK_IDENTIFICADOR '(' lista_expresiones ')'\n");
		}
#line 2167 "bison/omicron.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 536 "bison/omicron.y" /* yacc.c:1646  */
    {
			fprintf(fout, ";R:\texp: identificador_clase '.' TOK_IDENTIFICADOR '(' lista_expresiones ')'\n");
		}
#line 2175 "bison/omicron.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 541 "bison/omicron.y" /* yacc.c:1646  */
    {
			fprintf(fout, ";R:\texp: identificador_clase '.' TOK_IDENTIFICADOR\n");
		}
#line 2183 "bison/omicron.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 548 "bison/omicron.y" /* yacc.c:1646  */
    {
			fprintf(fout, ";R:\tidentificador_clase:\tTOK_IDENTIFICADOR\n");
		}
#line 2191 "bison/omicron.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 553 "bison/omicron.y" /* yacc.c:1646  */
    {
			fprintf(fout, ";R:\tidentificador_clase:\tTOK_ITSELF\n");
		}
#line 2199 "bison/omicron.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 559 "bison/omicron.y" /* yacc.c:1646  */
    {
			fprintf(fout, ";R:\tlista_expresiones: exp resto_lista_expresiones\n");
		}
#line 2207 "bison/omicron.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 564 "bison/omicron.y" /* yacc.c:1646  */
    {
			fprintf(fout, ";R:\tlista_expresiones: \n");
		}
#line 2215 "bison/omicron.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 570 "bison/omicron.y" /* yacc.c:1646  */
    {
			fprintf(fout, ";R:\tresto_lista_expresiones: ',' exp resto_lista_expresiones\n");
		}
#line 2223 "bison/omicron.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 575 "bison/omicron.y" /* yacc.c:1646  */
    {
			fprintf(fout, ";R:\tresto_lista_expresiones:\n");
		}
#line 2231 "bison/omicron.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 581 "bison/omicron.y" /* yacc.c:1646  */
    {
			fprintf(fout, ";R:\tcomparacion: exp TOK_IGUAL exp\n");
		}
#line 2239 "bison/omicron.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 586 "bison/omicron.y" /* yacc.c:1646  */
    {
			fprintf(fout, ";R:\tcomparacion: exp TOK_DISTINTO exp\n");
		}
#line 2247 "bison/omicron.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 591 "bison/omicron.y" /* yacc.c:1646  */
    {
			fprintf(fout, ";R:\tcomparacion: exp TOK_MAYORIGUAL exp\n");
		}
#line 2255 "bison/omicron.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 596 "bison/omicron.y" /* yacc.c:1646  */
    {
			fprintf(fout, ";R:\tcomparacion: exp TOK_MENORIGUAL exp\n");
		}
#line 2263 "bison/omicron.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 601 "bison/omicron.y" /* yacc.c:1646  */
    {
			fprintf(fout, ";R:\tcomparacion: exp '>' exp\n");
		}
#line 2271 "bison/omicron.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 606 "bison/omicron.y" /* yacc.c:1646  */
    {
			fprintf(fout, ";R:\tcomparacion: exp '<' exp\n");
		}
#line 2279 "bison/omicron.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 612 "bison/omicron.y" /* yacc.c:1646  */
    {
			fprintf(fout, ";R:\tconstante: constante_logica\n");
		}
#line 2287 "bison/omicron.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 617 "bison/omicron.y" /* yacc.c:1646  */
    {
			fprintf(fout, ";R:\tconstante:\tconstante_entera\n");
		}
#line 2295 "bison/omicron.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 623 "bison/omicron.y" /* yacc.c:1646  */
    {
			fprintf(fout, ";R:\tconstante_logica:\tTOK_TRUE\n");
		}
#line 2303 "bison/omicron.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 628 "bison/omicron.y" /* yacc.c:1646  */
    {
			fprintf(fout, ";R:\tconstante_logica:\tTOK_FALSE\n");
		}
#line 2311 "bison/omicron.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 634 "bison/omicron.y" /* yacc.c:1646  */
    {
			fprintf(fout, ";R:\tconstante_entera:\tTOK_CONSTANTE_ENTERA\n");
		}
#line 2319 "bison/omicron.tab.c" /* yacc.c:1646  */
    break;


#line 2323 "bison/omicron.tab.c" /* yacc.c:1646  */
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
#line 638 "bison/omicron.y" /* yacc.c:1906  */



void yyerror(const char * s) {
	printf("****Error sintactico en [lin %d, col %d]\n", linea, columna);
}
