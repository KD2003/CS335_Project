/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

#include <iostream>
#include <string>
using namespace std;

int yylex();
int yyerror(const char *str);


#line 81 "parser.tab.c"

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

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_KEYWORD = 3,                    /* KEYWORD  */
  YYSYMBOL_IDENTIFIER = 4,                 /* IDENTIFIER  */
  YYSYMBOL_LITERAL = 5,                    /* LITERAL  */
  YYSYMBOL_OPERATOR = 6,                   /* OPERATOR  */
  YYSYMBOL_INTTYPE = 7,                    /* INTTYPE  */
  YYSYMBOL_FPTYPE = 8,                     /* FPTYPE  */
  YYSYMBOL_BOOLTYPE = 9,                   /* BOOLTYPE  */
  YYSYMBOL_ASSIGNOP = 10,                  /* ASSIGNOP  */
  YYSYMBOL_CONDOR = 11,                    /* CONDOR  */
  YYSYMBOL_CONDAND = 12,                   /* CONDAND  */
  YYSYMBOL_EQALITYOP = 13,                 /* EQALITYOP  */
  YYSYMBOL_RELATIONOP = 14,                /* RELATIONOP  */
  YYSYMBOL_SHIFTOP = 15,                   /* SHIFTOP  */
  YYSYMBOL_ADDOP = 16,                     /* ADDOP  */
  YYSYMBOL_MULTOP = 17,                    /* MULTOP  */
  YYSYMBOL_ADDOP2 = 18,                    /* ADDOP2  */
  YYSYMBOL_UNARYOP = 19,                   /* UNARYOP  */
  YYSYMBOL_KEY_VAR = 20,                   /* KEY_VAR  */
  YYSYMBOL_KEY_assert = 21,                /* KEY_assert  */
  YYSYMBOL_KEY_yiethr = 22,                /* KEY_yiethr  */
  YYSYMBOL_KEY_brecon = 23,                /* KEY_brecon  */
  YYSYMBOL_KEY_return = 24,                /* KEY_return  */
  YYSYMBOL_KEY_if = 25,                    /* KEY_if  */
  YYSYMBOL_KEY_else = 26,                  /* KEY_else  */
  YYSYMBOL_KEY_for = 27,                   /* KEY_for  */
  YYSYMBOL_KEY_permits = 28,               /* KEY_permits  */
  YYSYMBOL_KEY_while = 29,                 /* KEY_while  */
  YYSYMBOL_KEY_sync = 30,                  /* KEY_sync  */
  YYSYMBOL_KEY_final = 31,                 /* KEY_final  */
  YYSYMBOL_KEY_extends = 32,               /* KEY_extends  */
  YYSYMBOL_KEY_super = 33,                 /* KEY_super  */
  YYSYMBOL_KEY_this = 34,                  /* KEY_this  */
  YYSYMBOL_KEY_class = 35,                 /* KEY_class  */
  YYSYMBOL_KEY_void = 36,                  /* KEY_void  */
  YYSYMBOL_KEY_public = 37,                /* KEY_public  */
  YYSYMBOL_KEY_new = 38,                   /* KEY_new  */
  YYSYMBOL_KEY_static = 39,                /* KEY_static  */
  YYSYMBOL_DOT3 = 40,                      /* DOT3  */
  YYSYMBOL_KEY_abstract = 41,              /* KEY_abstract  */
  YYSYMBOL_KEY_native = 42,                /* KEY_native  */
  YYSYMBOL_KEY_strictf = 43,               /* KEY_strictf  */
  YYSYMBOL_KEY_private = 44,               /* KEY_private  */
  YYSYMBOL_KEY_import = 45,                /* KEY_import  */
  YYSYMBOL_46_ = 46,                       /* ';'  */
  YYSYMBOL_47_ = 47,                       /* '.'  */
  YYSYMBOL_48_ = 48,                       /* '*'  */
  YYSYMBOL_49_ = 49,                       /* '['  */
  YYSYMBOL_50_ = 50,                       /* ']'  */
  YYSYMBOL_51_ = 51,                       /* '('  */
  YYSYMBOL_52_ = 52,                       /* ')'  */
  YYSYMBOL_53_ = 53,                       /* ','  */
  YYSYMBOL_54_ = 54,                       /* '='  */
  YYSYMBOL_55_ = 55,                       /* '?'  */
  YYSYMBOL_56_ = 56,                       /* ':'  */
  YYSYMBOL_57_ = 57,                       /* '&'  */
  YYSYMBOL_58_ = 58,                       /* '^'  */
  YYSYMBOL_59_ = 59,                       /* '|'  */
  YYSYMBOL_60_ = 60,                       /* '{'  */
  YYSYMBOL_61_ = 61,                       /* '}'  */
  YYSYMBOL_YYACCEPT = 62,                  /* $accept  */
  YYSYMBOL_prog = 63,                      /* prog  */
  YYSYMBOL_ImportList = 64,                /* ImportList  */
  YYSYMBOL_ClassDeclarationList = 65,      /* ClassDeclarationList  */
  YYSYMBOL_Imports = 66,                   /* Imports  */
  YYSYMBOL_Type = 67,                      /* Type  */
  YYSYMBOL_PrimitiveType = 68,             /* PrimitiveType  */
  YYSYMBOL_IDENdotIDEN = 69,               /* IDENdotIDEN  */
  YYSYMBOL_PublicPrivateStatic = 70,       /* PublicPrivateStatic  */
  YYSYMBOL_ClassType = 71,                 /* ClassType  */
  YYSYMBOL_ArrayType = 72,                 /* ArrayType  */
  YYSYMBOL_Dims = 73,                      /* Dims  */
  YYSYMBOL_Primary = 74,                   /* Primary  */
  YYSYMBOL_PrimaryNoNewArray = 75,         /* PrimaryNoNewArray  */
  YYSYMBOL_ClassInstanceCreationExpression = 76, /* ClassInstanceCreationExpression  */
  YYSYMBOL_Zeroorone_ArgumentList = 77,    /* Zeroorone_ArgumentList  */
  YYSYMBOL_FieldAccess = 78,               /* FieldAccess  */
  YYSYMBOL_ArrayAccess = 79,               /* ArrayAccess  */
  YYSYMBOL_MethodInvocation = 80,          /* MethodInvocation  */
  YYSYMBOL_ArgumentList = 81,              /* ArgumentList  */
  YYSYMBOL_ArrayCreationExpression = 82,   /* ArrayCreationExpression  */
  YYSYMBOL_DimExpr = 83,                   /* DimExpr  */
  YYSYMBOL_Expression = 84,                /* Expression  */
  YYSYMBOL_AssignmentExpression = 85,      /* AssignmentExpression  */
  YYSYMBOL_Assignment = 86,                /* Assignment  */
  YYSYMBOL_ConditionalExpression = 87,     /* ConditionalExpression  */
  YYSYMBOL_ConditionalOrExpression = 88,   /* ConditionalOrExpression  */
  YYSYMBOL_ConditionalAndExpression = 89,  /* ConditionalAndExpression  */
  YYSYMBOL_AndExpression = 90,             /* AndExpression  */
  YYSYMBOL_ExclusiveOrExpression = 91,     /* ExclusiveOrExpression  */
  YYSYMBOL_InclusiveOrExpression = 92,     /* InclusiveOrExpression  */
  YYSYMBOL_EqualityExpression = 93,        /* EqualityExpression  */
  YYSYMBOL_RelationalExpression = 94,      /* RelationalExpression  */
  YYSYMBOL_ShiftExpression = 95,           /* ShiftExpression  */
  YYSYMBOL_AdditiveExpression = 96,        /* AdditiveExpression  */
  YYSYMBOL_MultiplicativeExpression = 97,  /* MultiplicativeExpression  */
  YYSYMBOL_UnaryExpression = 98,           /* UnaryExpression  */
  YYSYMBOL_UnaryExpressionNotPlusMinus = 99, /* UnaryExpressionNotPlusMinus  */
  YYSYMBOL_CastExpression = 100,           /* CastExpression  */
  YYSYMBOL_PostfixExpression = 101,        /* PostfixExpression  */
  YYSYMBOL_Block = 102,                    /* Block  */
  YYSYMBOL_BlockStatements = 103,          /* BlockStatements  */
  YYSYMBOL_BlockStatement = 104,           /* BlockStatement  */
  YYSYMBOL_LocalVariableDeclaration = 105, /* LocalVariableDeclaration  */
  YYSYMBOL_LocalVariableType = 106,        /* LocalVariableType  */
  YYSYMBOL_Statement = 107,                /* Statement  */
  YYSYMBOL_StatementNoShortIf = 108,       /* StatementNoShortIf  */
  YYSYMBOL_StatementWithoutTrailingSubstatement = 109, /* StatementWithoutTrailingSubstatement  */
  YYSYMBOL_StatementExpression = 110,      /* StatementExpression  */
  YYSYMBOL_LeftHandSide = 111,             /* LeftHandSide  */
  YYSYMBOL_AssertStatement = 112,          /* AssertStatement  */
  YYSYMBOL_BreakContinueStatement = 113,   /* BreakContinueStatement  */
  YYSYMBOL_ForStatement = 114,             /* ForStatement  */
  YYSYMBOL_ForStatementNoShortIf = 115,    /* ForStatementNoShortIf  */
  YYSYMBOL_ForInit = 116,                  /* ForInit  */
  YYSYMBOL_StatementExpressionList = 117,  /* StatementExpressionList  */
  YYSYMBOL_ClassDeclaration = 118,         /* ClassDeclaration  */
  YYSYMBOL_NormalClassDeclaration = 119,   /* NormalClassDeclaration  */
  YYSYMBOL_ClassExtends = 120,             /* ClassExtends  */
  YYSYMBOL_ClassPermits = 121,             /* ClassPermits  */
  YYSYMBOL_cTypeName = 122,                /* cTypeName  */
  YYSYMBOL_ClassBody = 123,                /* ClassBody  */
  YYSYMBOL_ClassBodyDeclarations = 124,    /* ClassBodyDeclarations  */
  YYSYMBOL_ClassBodyDeclaration = 125,     /* ClassBodyDeclaration  */
  YYSYMBOL_VariableDeclaratorList = 126,   /* VariableDeclaratorList  */
  YYSYMBOL_VariableDeclarator = 127,       /* VariableDeclarator  */
  YYSYMBOL_zerooroneExpression = 128,      /* zerooroneExpression  */
  YYSYMBOL_VariableDeclarator1 = 129,      /* VariableDeclarator1  */
  YYSYMBOL_VariableDeclarator2 = 130,      /* VariableDeclarator2  */
  YYSYMBOL_List1 = 131,                    /* List1  */
  YYSYMBOL_ArrEle1 = 132,                  /* ArrEle1  */
  YYSYMBOL_List2 = 133,                    /* List2  */
  YYSYMBOL_ArrEle2 = 134,                  /* ArrEle2  */
  YYSYMBOL_List3 = 135,                    /* List3  */
  YYSYMBOL_ArrEle3 = 136,                  /* ArrEle3  */
  YYSYMBOL_MethodDeclaration = 137,        /* MethodDeclaration  */
  YYSYMBOL_MethodHeader = 138,             /* MethodHeader  */
  YYSYMBOL_Methodeclarator = 139,          /* Methodeclarator  */
  YYSYMBOL_IdenPara = 140,                 /* IdenPara  */
  YYSYMBOL_formalparameters = 141,         /* formalparameters  */
  YYSYMBOL_formalparameter = 142,          /* formalparameter  */
  YYSYMBOL_MethodBody = 143,               /* MethodBody  */
  YYSYMBOL_Modifiers = 144                 /* Modifiers  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




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

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
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
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   790

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  62
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  83
/* YYNRULES -- Number of rules.  */
#define YYNRULES  202
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  389

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   300


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    57,     2,
      51,    52,    48,     2,    53,     2,    47,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    56,    46,
       2,    54,     2,    55,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    49,     2,    50,    58,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    60,    59,    61,     2,     2,     2,     2,
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
      45
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    22,    22,    26,    27,    31,    32,    36,    37,    38,
      39,    44,    45,    46,    50,    51,    52,    56,    57,    61,
      61,    61,    65,    69,    70,    73,    74,    81,    82,    86,
      88,    89,    90,    91,    92,    93,    94,   109,   110,   114,
     114,   118,   119,   120,   124,   125,   129,   130,   131,   132,
     136,   137,   141,   142,   143,   144,   149,   150,   154,   158,
     159,   163,   164,   168,   169,   173,   174,   178,   179,   183,
     184,   188,   189,   193,   194,   198,   199,   203,   204,   208,
     209,   213,   214,   218,   219,   223,   224,   225,   226,   230,
     231,   235,   239,   240,   241,   248,   252,   252,   256,   257,
     261,   265,   266,   270,   271,   272,   273,   274,   275,   279,
     280,   281,   282,   283,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   299,   300,   301,   302,   307,   308,   309,
     313,   314,   318,   319,   323,   324,   325,   326,   331,   332,
     333,   334,   339,   340,   341,   345,   346,   376,   379,   380,
     381,   382,   385,   388,   392,   392,   396,   399,   400,   403,
     404,   405,   406,   407,   408,   412,   413,   417,   418,   422,
     422,   426,   427,   428,   429,   433,   434,   435,   436,   440,
     444,   445,   449,   453,   454,   458,   462,   463,   467,   479,
     480,   484,   485,   489,   490,   493,   494,   498,   499,   507,
     508,   512,   512
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "KEYWORD",
  "IDENTIFIER", "LITERAL", "OPERATOR", "INTTYPE", "FPTYPE", "BOOLTYPE",
  "ASSIGNOP", "CONDOR", "CONDAND", "EQALITYOP", "RELATIONOP", "SHIFTOP",
  "ADDOP", "MULTOP", "ADDOP2", "UNARYOP", "KEY_VAR", "KEY_assert",
  "KEY_yiethr", "KEY_brecon", "KEY_return", "KEY_if", "KEY_else",
  "KEY_for", "KEY_permits", "KEY_while", "KEY_sync", "KEY_final",
  "KEY_extends", "KEY_super", "KEY_this", "KEY_class", "KEY_void",
  "KEY_public", "KEY_new", "KEY_static", "DOT3", "KEY_abstract",
  "KEY_native", "KEY_strictf", "KEY_private", "KEY_import", "';'", "'.'",
  "'*'", "'['", "']'", "'('", "')'", "','", "'='", "'?'", "':'", "'&'",
  "'^'", "'|'", "'{'", "'}'", "$accept", "prog", "ImportList",
  "ClassDeclarationList", "Imports", "Type", "PrimitiveType",
  "IDENdotIDEN", "PublicPrivateStatic", "ClassType", "ArrayType", "Dims",
  "Primary", "PrimaryNoNewArray", "ClassInstanceCreationExpression",
  "Zeroorone_ArgumentList", "FieldAccess", "ArrayAccess",
  "MethodInvocation", "ArgumentList", "ArrayCreationExpression", "DimExpr",
  "Expression", "AssignmentExpression", "Assignment",
  "ConditionalExpression", "ConditionalOrExpression",
  "ConditionalAndExpression", "AndExpression", "ExclusiveOrExpression",
  "InclusiveOrExpression", "EqualityExpression", "RelationalExpression",
  "ShiftExpression", "AdditiveExpression", "MultiplicativeExpression",
  "UnaryExpression", "UnaryExpressionNotPlusMinus", "CastExpression",
  "PostfixExpression", "Block", "BlockStatements", "BlockStatement",
  "LocalVariableDeclaration", "LocalVariableType", "Statement",
  "StatementNoShortIf", "StatementWithoutTrailingSubstatement",
  "StatementExpression", "LeftHandSide", "AssertStatement",
  "BreakContinueStatement", "ForStatement", "ForStatementNoShortIf",
  "ForInit", "StatementExpressionList", "ClassDeclaration",
  "NormalClassDeclaration", "ClassExtends", "ClassPermits", "cTypeName",
  "ClassBody", "ClassBodyDeclarations", "ClassBodyDeclaration",
  "VariableDeclaratorList", "VariableDeclarator", "zerooroneExpression",
  "VariableDeclarator1", "VariableDeclarator2", "List1", "ArrEle1",
  "List2", "ArrEle2", "List3", "ArrEle3", "MethodDeclaration",
  "MethodHeader", "Methodeclarator", "IdenPara", "formalparameters",
  "formalparameter", "MethodBody", "Modifiers", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-329)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-130)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -329,    37,    -4,  -329,    40,    58,  -329,  -329,  -329,   129,
    -329,    12,    73,  -329,   102,  -329,  -329,  -329,  -329,    82,
    -329,    23,   -10,  -329,    30,  -329,    97,    12,    12,  -329,
      55,    99,  -329,   111,  -329,   131,   131,  -329,   -13,    99,
    -329,  -329,  -329,   185,   140,  -329,  -329,  -329,  -329,  -329,
    -329,  -329,   731,  -329,    12,   527,   149,  -329,  -329,  -329,
     198,   206,   170,   170,  -329,    43,   157,   131,   166,  -329,
     739,  -329,   739,   739,     9,   659,   172,   173,   174,   175,
     182,  -329,   167,  -329,   739,  -329,  -329,    41,   183,   184,
    -329,    26,    28,    70,  -329,  -329,   216,  -329,  -329,   192,
     235,  -329,  -329,   194,    32,  -329,  -329,  -329,    16,   149,
    -329,   170,   137,    56,  -329,  -329,  -329,  -329,   193,   195,
     195,  -329,  -329,  -329,  -329,   572,   739,   739,   739,   458,
     109,  -329,  -329,  -329,  -329,  -329,  -329,   224,    47,    54,
    -329,  -329,  -329,    38,   233,   189,   190,   188,   239,   240,
     245,   247,   250,  -329,   222,   225,  -329,  -329,   226,   739,
     651,   739,   739,   269,   227,   150,   234,    91,   739,   739,
     273,   739,   260,  -329,   123,   236,  -329,   739,   739,  -329,
      11,    78,  -329,   195,   739,   739,  -329,   235,  -329,   229,
    -329,  -329,  -329,  -329,   254,  -329,  -329,   739,   739,   739,
     739,   739,   739,   739,   739,   739,   739,   739,   739,  -329,
    -329,  -329,   264,  -329,  -329,   256,   238,   267,   270,   261,
     739,   275,   739,   275,  -329,   278,  -329,   277,   276,   279,
    -329,   280,   284,  -329,  -329,   288,   334,  -329,  -329,   167,
    -329,   289,  -329,  -329,  -329,   739,   297,   233,   292,   188,
     239,   189,   190,   240,   245,   247,   250,  -329,   616,   682,
     232,   572,   157,   739,   295,   703,   195,   298,   195,   351,
    -329,  -329,   739,   739,  -329,   739,  -329,  -329,   133,  -329,
    -329,   739,   300,   306,   307,   308,  -329,   335,   338,  -329,
     180,   314,  -329,  -329,  -329,   310,  -329,   317,    99,   325,
    -329,   316,   327,   739,   320,  -329,   616,   739,   651,   739,
     572,   572,   117,   336,  -329,  -329,  -329,   739,  -329,   333,
     340,   739,  -329,  -329,   331,   339,   341,  -329,  -329,   572,
     572,   128,   342,   739,   141,  -329,   -32,   616,   713,   616,
    -329,  -329,   572,  -329,   347,   739,   332,   739,  -329,   365,
     417,   353,  -329,  -329,   354,   350,   320,  -329,  -329,   616,
     616,   155,   419,   739,   356,  -329,   -21,  -329,  -329,   616,
     616,   168,   363,   355,   320,  -329,  -329,  -329,   616,  -329,
     332,  -329,  -329,  -329,  -329,    51,   332,  -329,  -329
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,   202,     1,     0,   202,     3,     6,   147,     0,
      18,     0,     0,     5,     0,    19,    21,    20,   201,     0,
       7,     0,     0,     8,     0,    17,     0,     0,     0,   158,
       0,     0,   148,     0,     9,   155,    22,   152,   202,     0,
     149,   150,    10,     0,   153,   161,    97,   156,   162,   160,
     157,   164,     0,   151,     0,     0,    18,    14,    15,    16,
       0,     0,    11,    13,    12,     0,     0,   154,    18,    29,
       0,   102,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    30,     0,   115,     0,    95,   101,   127,    92,    27,
      33,    34,    35,    36,    28,   123,     0,   114,    96,     0,
       0,    99,   103,     0,     0,   117,   118,   108,     0,     0,
     190,   192,   171,     0,   166,   167,   168,   189,     0,    23,
      24,   200,   199,   188,   163,     0,     0,     0,     0,     0,
      93,    34,    35,    36,   125,    87,    88,    89,    93,     0,
      58,    60,    59,    63,    65,    71,    73,    67,    69,    75,
      77,    79,    81,    83,     0,     0,   133,   119,     0,     0,
     144,     0,     0,     0,     0,     0,     0,     0,     0,    40,
       0,     0,   126,    98,   171,   100,   116,     0,     0,   194,
       0,     0,   196,   191,   170,     0,   159,     0,    25,     0,
     104,    86,    85,    90,     0,    94,   130,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   121,
     132,   120,     0,   143,   146,     0,   142,     0,     0,    42,
       0,    53,    40,    55,    32,     0,    31,     0,     0,    39,
      51,    41,     0,    61,    62,   171,     0,   197,   193,     0,
     169,     0,   175,   165,    26,     0,     0,    66,     0,    68,
      70,    72,    74,    76,    78,    80,    82,    84,     0,     0,
       0,     0,     0,    40,     0,     0,    52,     0,    54,     0,
      44,    46,     0,    40,    45,   170,   198,   195,   172,    91,
     131,     0,    18,     0,     0,     0,   105,     0,   103,   113,
       0,     0,   145,   107,   122,     0,    57,     0,    38,    43,
      50,     0,     0,   170,     0,    64,     0,     0,   144,     0,
       0,     0,     0,     0,    48,    56,    37,    40,    47,   172,
       0,     0,   176,   110,     0,     0,     0,   106,   134,     0,
       0,     0,     0,   170,   173,   181,     0,     0,     0,     0,
     136,   135,     0,    49,     0,   170,     0,     0,   179,     0,
       0,     0,   112,   137,   173,     0,     0,   177,   180,     0,
       0,     0,     0,   170,   174,   184,     0,   111,   138,     0,
       0,     0,     0,     0,     0,   182,   140,   139,     0,   174,
       0,   178,   183,   141,   187,     0,     0,   185,   186
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -329,  -329,  -329,  -329,  -329,   -45,   -73,   281,  -329,   376,
    -329,   -58,  -329,  -329,  -329,  -196,   -66,   -53,   -55,  -329,
    -329,   253,   344,  -329,   -49,   144,  -329,   228,   230,   231,
     242,   237,   223,   241,   243,   249,   -62,  -329,  -329,    36,
     -35,  -329,  -329,   374,  -329,    42,  -252,   -12,  -146,  -329,
    -329,  -329,  -329,  -329,   122,  -278,    14,  -329,  -329,   401,
    -329,   -29,  -329,  -329,   343,   246,  -264,   259,  -329,  -328,
    -329,  -253,  -329,  -329,  -329,  -329,  -329,   375,   388,  -329,
     205,  -329,   407
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,     2,     5,     6,    86,    62,   138,    18,    63,
      64,   119,    88,    89,    90,   228,    91,    92,   133,   229,
      94,   221,   240,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   135,   136,   137,
      97,    55,    98,   213,   100,   190,   287,   288,   103,   104,
     105,   106,   107,   289,   215,   216,     7,     8,    30,    31,
      44,    32,    38,    50,   113,   114,   241,   115,   116,   322,
     336,   357,   366,   381,   385,    51,    65,   110,   111,   181,
     182,   123,     9
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      93,    40,    41,    48,   131,   120,    95,    61,   134,   164,
      53,   302,   312,   155,   214,   235,    10,   132,    27,    13,
      10,   347,    28,    57,    58,    59,   267,    25,   365,   348,
     122,   124,   374,    45,    25,   331,  -128,     3,  -129,   320,
     375,     4,   177,   102,    10,   -22,   382,    46,    47,   198,
      29,   236,    49,   183,   323,   156,   194,  -127,    -2,   -93,
     131,   131,   131,   180,   191,   192,   193,   295,   179,   344,
      93,    26,   361,   132,   132,   132,    95,   301,    33,    11,
    -128,   355,  -129,    27,   371,   349,   178,   352,   167,   121,
     168,    96,   169,   199,   167,    25,   168,   101,   169,   372,
     196,  -127,   186,    46,   386,    93,    22,   367,   368,   187,
     197,    95,   387,   102,   292,    29,  -124,   376,   377,    20,
      21,   332,  -124,  -124,   225,   226,   383,   384,    23,    24,
     238,   239,   131,   388,   131,   131,   131,   131,   131,   131,
     131,   131,   131,    34,   214,   132,   257,   132,   132,   132,
     132,   132,   132,   132,   132,   132,   167,    42,   168,    29,
     169,    96,   214,   266,    14,   268,    15,   214,    16,   329,
     260,    10,   184,    17,    57,    58,    59,   185,    43,   131,
     342,   260,   303,   279,    10,    69,   184,   304,   108,    25,
     345,   185,   132,    54,   180,   346,    96,    43,    70,   220,
     108,   222,   109,    93,   214,    93,    93,   369,   260,    95,
     112,    95,    95,    80,    81,   131,   214,    46,    82,   118,
     378,   260,   125,   159,   160,   161,   162,   294,   132,   163,
     170,    84,   311,   171,   172,    93,    10,    69,   173,   174,
     176,    95,   195,   188,   189,   200,   201,   203,   202,   102,
      70,    93,   204,    93,   205,    93,    93,    95,    93,    95,
     206,    95,    95,   207,    95,    80,    81,   208,   209,   316,
      82,   210,   211,   219,    93,    93,   220,   231,   -94,   244,
      95,    95,    93,    84,    93,    12,   224,    93,    95,   187,
      95,   260,    19,    95,    96,    93,    96,    96,   102,   102,
     286,    95,   259,   293,    93,    93,   245,    93,    35,    36,
      95,    95,   263,    95,    93,    93,   258,   102,   102,   261,
      95,    95,   262,    93,   265,   269,    96,   270,   271,    95,
     102,   273,   272,    36,   274,    67,    87,   275,   276,   278,
      10,    69,    96,   280,    96,   296,    96,    96,   281,    96,
     298,   130,   327,   328,    70,   299,   306,   307,   308,   309,
     313,   310,   314,   165,  -109,    96,    96,   315,   318,    80,
      81,   340,   341,    96,    82,    96,   317,   319,    96,   286,
     321,   293,   333,   337,   353,   338,    96,    84,   330,    36,
     334,   359,   356,   339,   343,    96,    96,   354,    96,   362,
     364,   327,   328,   363,    37,    96,    96,   130,   130,   130,
     373,   340,   341,   379,    96,   380,   139,   154,   223,   158,
     353,    10,    69,    10,    69,   305,   247,   253,   166,    99,
     325,    39,   251,   243,   252,    70,   117,    70,   250,   237,
      66,    87,   249,   175,   277,    52,   254,     0,     0,   255,
      80,    81,    80,    81,     0,    82,   256,    82,     0,     0,
       0,     0,    10,    69,     0,    57,    58,    59,    84,   360,
      84,   370,     0,   166,   126,     0,   127,   128,     0,   130,
       0,   130,   130,   130,   130,   130,   130,   130,   130,   130,
       0,    80,    81,     0,     0,     0,    82,     0,     0,     0,
       0,     0,     0,   212,     0,   217,   218,     0,     0,   129,
       0,     0,   227,   230,     0,   232,     0,     0,     0,     0,
      36,   233,   234,     0,     0,     0,   130,     0,     0,   242,
       0,    68,    69,     0,    57,    58,    59,     0,     0,     0,
       0,   246,     0,   248,     0,    70,     0,    71,    72,    73,
      74,    75,    76,     0,    77,     0,    78,    79,     0,     0,
      80,    81,   130,     0,   264,    82,   230,     0,     0,     0,
       0,     0,     0,    83,     0,     0,    68,    69,    84,     0,
       0,     0,     0,     0,     0,     0,     0,    46,    85,    87,
      70,     0,     0,    72,    73,    74,    75,    76,     0,    77,
       0,    78,    79,   291,     0,    80,    81,   230,     0,   297,
      82,     0,     0,     0,     0,     0,   300,   230,    83,     0,
     282,    69,     0,    84,     0,     0,     0,     0,     0,     0,
       0,     0,    46,     0,    70,     0,     0,    72,    73,    74,
      75,   283,     0,   284,     0,   285,    79,     0,     0,    80,
      81,   324,     0,   326,    82,    10,    69,     0,    57,    58,
      59,   230,    83,    10,    69,   335,     0,    84,     0,    70,
       0,    71,     0,     0,     0,   126,    46,   127,   128,     0,
       0,     0,   351,     0,    80,    81,    10,    69,     0,    82,
       0,   358,    80,    81,     0,     0,     0,    82,   126,     0,
     127,   128,    84,     0,     0,   157,     0,    10,    69,     0,
     129,     0,     0,     0,     0,    80,    81,    10,    69,   126,
      82,   127,   128,     0,     0,     0,     0,     0,   290,   126,
       0,   127,   128,   129,     0,    56,    80,    81,    57,    58,
      59,    82,     0,    10,    69,     0,    80,    81,     0,     0,
       0,    82,     0,   188,   129,   126,     0,   127,   128,   350,
       0,     0,     0,     0,   129,     0,    14,    60,    15,     0,
      16,     0,    80,    81,     0,    17,     0,    82,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     129
};

static const yytype_int16 yycheck[] =
{
      55,    30,    31,    38,    70,    63,    55,    52,    70,    82,
      39,   275,   290,     4,   160,     4,     4,    70,    28,     5,
       4,    53,    32,     7,     8,     9,   222,     4,   356,    61,
      65,    66,    53,    46,     4,   313,    10,     0,    10,   303,
      61,    45,    10,    55,     4,     4,   374,    60,    61,    11,
      60,    40,    38,   111,   306,    46,   129,    10,     0,    18,
     126,   127,   128,   108,   126,   127,   128,   263,    52,   333,
     125,    48,   350,   126,   127,   128,   125,   273,    48,    39,
      54,   345,    54,    28,   362,   337,    54,   339,    47,    46,
      49,    55,    51,    55,    47,     4,    49,    55,    51,   363,
      46,    54,    46,    60,    53,   160,     4,   359,   360,    53,
      56,   160,    61,   125,   260,    60,    46,   369,   370,    46,
      47,   317,    52,    53,    33,    34,   378,   380,    46,    47,
      52,    53,   198,   386,   200,   201,   202,   203,   204,   205,
     206,   207,   208,    46,   290,   198,   208,   200,   201,   202,
     203,   204,   205,   206,   207,   208,    47,    46,    49,    60,
      51,   125,   308,   221,    35,   223,    37,   313,    39,    52,
      53,     4,    49,    44,     7,     8,     9,    54,    47,   245,
      52,    53,    49,   245,     4,     5,    49,    54,    51,     4,
      49,    54,   245,    53,   239,    54,   160,    47,    18,    49,
      51,    51,     4,   258,   350,   260,   261,    52,    53,   258,
       4,   260,   261,    33,    34,   281,   362,    60,    38,    49,
      52,    53,    56,    51,    51,    51,    51,   262,   281,    47,
      47,    51,    52,    49,    18,   290,     4,     5,    46,     4,
      46,   290,    18,    50,    49,    12,    57,    59,    58,   261,
      18,   306,    13,   308,    14,   310,   311,   306,   313,   308,
      15,   310,   311,    16,   313,    33,    34,    17,    46,   298,
      38,    46,    46,     4,   329,   330,    49,     4,    18,    50,
     329,   330,   337,    51,   339,     4,    52,   342,   337,    53,
     339,    53,    11,   342,   258,   350,   260,   261,   310,   311,
     258,   350,    46,   261,   359,   360,    52,   362,    27,    28,
     359,   360,    51,   362,   369,   370,    52,   329,   330,    52,
     369,   370,    52,   378,    49,    47,   290,    50,    52,   378,
     342,    51,    53,    52,    50,    54,    55,    49,     4,    50,
       4,     5,   306,    46,   308,    50,   310,   311,    56,   313,
      52,    70,   310,   311,    18,     4,    56,    51,    51,    51,
      46,    26,    52,    82,    26,   329,   330,    50,    52,    33,
      34,   329,   330,   337,    38,   339,    51,    50,   342,   337,
      60,   339,    49,    52,   342,    46,   350,    51,    52,   108,
      50,    26,    60,    52,    52,   359,   360,    50,   362,    46,
      50,   359,   360,    49,    28,   369,   370,   126,   127,   128,
      54,   369,   370,    50,   378,    60,    72,    73,   165,    75,
     378,     4,     5,     4,     5,   281,   198,   204,    84,    55,
     308,    30,   202,   187,   203,    18,    61,    18,   201,   180,
      52,   160,   200,   100,   239,    38,   205,    -1,    -1,   206,
      33,    34,    33,    34,    -1,    38,   207,    38,    -1,    -1,
      -1,    -1,     4,     5,    -1,     7,     8,     9,    51,    52,
      51,    52,    -1,   129,    16,    -1,    18,    19,    -1,   198,
      -1,   200,   201,   202,   203,   204,   205,   206,   207,   208,
      -1,    33,    34,    -1,    -1,    -1,    38,    -1,    -1,    -1,
      -1,    -1,    -1,   159,    -1,   161,   162,    -1,    -1,    51,
      -1,    -1,   168,   169,    -1,   171,    -1,    -1,    -1,    -1,
     239,   177,   178,    -1,    -1,    -1,   245,    -1,    -1,   185,
      -1,     4,     5,    -1,     7,     8,     9,    -1,    -1,    -1,
      -1,   197,    -1,   199,    -1,    18,    -1,    20,    21,    22,
      23,    24,    25,    -1,    27,    -1,    29,    30,    -1,    -1,
      33,    34,   281,    -1,   220,    38,   222,    -1,    -1,    -1,
      -1,    -1,    -1,    46,    -1,    -1,     4,     5,    51,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,    61,   308,
      18,    -1,    -1,    21,    22,    23,    24,    25,    -1,    27,
      -1,    29,    30,   259,    -1,    33,    34,   263,    -1,   265,
      38,    -1,    -1,    -1,    -1,    -1,   272,   273,    46,    -1,
       4,     5,    -1,    51,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    60,    -1,    18,    -1,    -1,    21,    22,    23,
      24,    25,    -1,    27,    -1,    29,    30,    -1,    -1,    33,
      34,   307,    -1,   309,    38,     4,     5,    -1,     7,     8,
       9,   317,    46,     4,     5,   321,    -1,    51,    -1,    18,
      -1,    20,    -1,    -1,    -1,    16,    60,    18,    19,    -1,
      -1,    -1,   338,    -1,    33,    34,     4,     5,    -1,    38,
      -1,   347,    33,    34,    -1,    -1,    -1,    38,    16,    -1,
      18,    19,    51,    -1,    -1,    46,    -1,     4,     5,    -1,
      51,    -1,    -1,    -1,    -1,    33,    34,     4,     5,    16,
      38,    18,    19,    -1,    -1,    -1,    -1,    -1,    46,    16,
      -1,    18,    19,    51,    -1,     4,    33,    34,     7,     8,
       9,    38,    -1,     4,     5,    -1,    33,    34,    -1,    -1,
      -1,    38,    -1,    50,    51,    16,    -1,    18,    19,    46,
      -1,    -1,    -1,    -1,    51,    -1,    35,    36,    37,    -1,
      39,    -1,    33,    34,    -1,    44,    -1,    38,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      51
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    63,    64,     0,    45,    65,    66,   118,   119,   144,
       4,    39,    69,   118,    35,    37,    39,    44,    70,    69,
      46,    47,     4,    46,    47,     4,    48,    28,    32,    60,
     120,   121,   123,    48,    46,    69,    69,    71,   124,   121,
     123,   123,    46,    47,   122,    46,    60,    61,   102,   118,
     125,   137,   144,   123,    53,   103,     4,     7,     8,     9,
      36,    67,    68,    71,    72,   138,   140,    69,     4,     5,
      18,    20,    21,    22,    23,    24,    25,    27,    29,    30,
      33,    34,    38,    46,    51,    61,    67,    69,    74,    75,
      76,    78,    79,    80,    82,    86,   101,   102,   104,   105,
     106,   107,   109,   110,   111,   112,   113,   114,    51,     4,
     139,   140,     4,   126,   127,   129,   130,   139,    49,    73,
      73,    46,   102,   143,   102,    56,    16,    18,    19,    51,
      69,    78,    79,    80,    98,    99,   100,   101,    69,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    84,     4,    46,    46,    84,    51,
      51,    51,    51,    47,    68,    69,    84,    47,    49,    51,
      47,    49,    18,    46,     4,   126,    46,    10,    54,    52,
      67,   141,   142,    73,    49,    54,    46,    53,    50,    49,
     107,    98,    98,    98,    68,    18,    46,    56,    11,    55,
      12,    57,    58,    59,    13,    14,    15,    16,    17,    46,
      46,    46,    84,   105,   110,   116,   117,    84,    84,     4,
      49,    83,    51,    83,    52,    33,    34,    84,    77,    81,
      84,     4,    84,    84,    84,     4,    40,   129,    52,    53,
      84,   128,    84,   127,    50,    52,    84,    89,    84,    92,
      93,    90,    91,    94,    95,    96,    97,    98,    52,    46,
      53,    52,    52,    51,    84,    49,    73,    77,    73,    47,
      50,    52,    53,    51,    50,    49,     4,   142,    50,    98,
      46,    56,     4,    25,    27,    29,   107,   108,   109,   115,
      46,    84,   110,   107,   102,    77,    50,    84,    52,     4,
      84,    77,   128,    49,    54,    87,    56,    51,    51,    51,
      26,    52,   117,    46,    52,    50,   123,    51,    52,    50,
     128,    60,   131,   108,    84,   116,    84,   107,   107,    52,
      52,   117,    77,    49,    50,    84,   132,    52,    46,    52,
     107,   107,    52,    52,   128,    49,    54,    53,    61,   108,
      46,    84,   108,   107,    50,   128,    60,   133,    84,    26,
      52,   117,    46,    49,    50,   131,   134,   108,   108,    52,
      52,   117,   128,    54,    53,    61,   108,   108,    52,    50,
      60,   135,   131,   108,   133,   136,    53,    61,   133
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    62,    63,    64,    64,    65,    65,    66,    66,    66,
      66,    67,    67,    67,    68,    68,    68,    69,    69,    70,
      70,    70,    71,    72,    72,    73,    73,    74,    74,    75,
      75,    75,    75,    75,    75,    75,    75,    76,    76,    77,
      77,    78,    78,    78,    79,    79,    80,    80,    80,    80,
      81,    81,    82,    82,    82,    82,    83,    83,    84,    85,
      85,    86,    86,    87,    87,    88,    88,    89,    89,    90,
      90,    91,    91,    92,    92,    93,    93,    94,    94,    95,
      95,    96,    96,    97,    97,    98,    98,    98,    98,    99,
      99,   100,   101,   101,   101,   102,   103,   103,   104,   104,
     105,   106,   106,   107,   107,   107,   107,   107,   107,   108,
     108,   108,   108,   108,   109,   109,   109,   109,   109,   109,
     109,   109,   109,   110,   110,   110,   110,   111,   111,   111,
     112,   112,   113,   113,   114,   114,   114,   114,   115,   115,
     115,   115,   116,   116,   116,   117,   117,   118,   119,   119,
     119,   119,   120,   121,   122,   122,   123,   124,   124,   125,
     125,   125,   125,   125,   125,   126,   126,   127,   127,   128,
     128,   129,   129,   129,   129,   130,   130,   130,   130,   131,
     132,   132,   133,   134,   134,   135,   136,   136,   137,   138,
     138,   139,   139,   140,   140,   141,   141,   142,   142,   143,
     143,   144,   144
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     2,     0,     2,     1,     3,     4,     5,
       6,     1,     1,     1,     1,     1,     1,     3,     1,     1,
       1,     1,     1,     2,     2,     2,     3,     1,     1,     1,
       1,     3,     3,     1,     1,     1,     1,     6,     5,     1,
       0,     3,     3,     5,     4,     4,     4,     6,     6,     8,
       3,     1,     4,     3,     4,     3,     4,     3,     1,     1,
       1,     3,     3,     1,     5,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     3,     2,     2,     1,     1,     1,
       2,     4,     1,     1,     2,     3,     2,     0,     2,     1,
       2,     1,     1,     1,     3,     5,     7,     5,     1,     1,
       3,     7,     5,     1,     1,     1,     2,     1,     1,     2,
       3,     3,     5,     1,     1,     2,     2,     1,     1,     1,
       3,     5,     3,     2,     7,     8,     8,     9,     7,     8,
       8,     9,     1,     1,     0,     3,     1,     1,     4,     5,
       5,     6,     2,     3,     3,     0,     3,     2,     0,     4,
       1,     1,     1,     3,     1,     3,     1,     1,     1,     1,
       0,     1,     4,     7,    10,     3,     6,     9,    12,     3,
       3,     1,     3,     3,     1,     3,     3,     1,     3,     2,
       2,     2,     1,     4,     3,     3,     1,     2,     3,     1,
       1,     2,     0
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


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


/* YYLOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

# ifndef YYLOCATION_PRINT

#  if defined YY_LOCATION_PRINT

   /* Temporary convenience wrapper in case some people defined the
      undocumented and private YY_LOCATION_PRINT macros.  */
#   define YYLOCATION_PRINT(File, Loc)  YY_LOCATION_PRINT(File, *(Loc))

#  elif defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
}

#   define YYLOCATION_PRINT  yy_location_print_

    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT(File, Loc)  YYLOCATION_PRINT(File, &(Loc))

#  else

#   define YYLOCATION_PRINT(File, Loc) ((void) 0)
    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT  YYLOCATION_PRINT

#  endif
# endif /* !defined YYLOCATION_PRINT */


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (yylocationp);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  YYLOCATION_PRINT (yyo, yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yykind, yyvaluep, yylocationp);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp,
                 int yyrule)
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
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)],
                       &(yylsp[(yyi + 1) - (yynrhs)]));
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YY_USE (yyvaluep);
  YY_USE (yylocationp);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

    /* The location stack: array, bottom, top.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls = yylsa;
    YYLTYPE *yylsp = yyls;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[3];



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  yylsp[0] = yylloc;
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
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
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
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      yyerror_range[1] = yylloc;
      goto yyerrlab1;
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
  *++yylsp = yylloc;

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

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* prog: ImportList ClassDeclarationList  */
#line 22 "parser.y"
                                                {cout << "Program Completed\n";}
#line 1700 "parser.tab.c"
    break;

  case 100: /* LocalVariableDeclaration: LocalVariableType VariableDeclaratorList  */
#line 261 "parser.y"
                                               {cout << "local var dec";}
#line 1706 "parser.tab.c"
    break;

  case 101: /* LocalVariableType: Type  */
#line 265 "parser.y"
                {cout <<"type";}
#line 1712 "parser.tab.c"
    break;

  case 189: /* MethodHeader: Type Methodeclarator  */
#line 479 "parser.y"
                              {cout << "MethodHeader";}
#line 1718 "parser.tab.c"
    break;

  case 199: /* MethodBody: Block  */
#line 507 "parser.y"
                {cout <<"MEthodBlock";}
#line 1724 "parser.tab.c"
    break;

  case 200: /* MethodBody: ';'  */
#line 508 "parser.y"
                {cout << "MethodBody;";}
#line 1730 "parser.tab.c"
    break;


#line 1734 "parser.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;
  *++yylsp = yyloc;

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
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  yyerror_range[1] = yylloc;
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
                      yytoken, &yylval, &yylloc);
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
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  ++yylsp;
  YYLLOC_DEFAULT (*yylsp, yyerror_range, 2);

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 516 "parser.y"


int main(){
    if(yyparse()) return 0;
    
    return 0;
}
