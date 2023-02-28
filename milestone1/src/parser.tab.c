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

#include"AST.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

FILE* dotfile;

int yylex();
int yyerror(const char *str);


#line 85 "parser.tab.c"

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
  YYSYMBOL_KEY_yield = 22,                 /* KEY_yield  */
  YYSYMBOL_KEY_throw = 23,                 /* KEY_throw  */
  YYSYMBOL_KEY_break = 24,                 /* KEY_break  */
  YYSYMBOL_KEY_continue = 25,              /* KEY_continue  */
  YYSYMBOL_KEY_return = 26,                /* KEY_return  */
  YYSYMBOL_KEY_if = 27,                    /* KEY_if  */
  YYSYMBOL_KEY_else = 28,                  /* KEY_else  */
  YYSYMBOL_KEY_for = 29,                   /* KEY_for  */
  YYSYMBOL_KEY_permits = 30,               /* KEY_permits  */
  YYSYMBOL_KEY_while = 31,                 /* KEY_while  */
  YYSYMBOL_KEY_sync = 32,                  /* KEY_sync  */
  YYSYMBOL_KEY_final = 33,                 /* KEY_final  */
  YYSYMBOL_KEY_extends = 34,               /* KEY_extends  */
  YYSYMBOL_KEY_super = 35,                 /* KEY_super  */
  YYSYMBOL_KEY_this = 36,                  /* KEY_this  */
  YYSYMBOL_KEY_class = 37,                 /* KEY_class  */
  YYSYMBOL_KEY_void = 38,                  /* KEY_void  */
  YYSYMBOL_KEY_public = 39,                /* KEY_public  */
  YYSYMBOL_KEY_new = 40,                   /* KEY_new  */
  YYSYMBOL_KEY_static = 41,                /* KEY_static  */
  YYSYMBOL_DOT3 = 42,                      /* DOT3  */
  YYSYMBOL_KEY_private = 43,               /* KEY_private  */
  YYSYMBOL_KEY_import = 44,                /* KEY_import  */
  YYSYMBOL_45_ = 45,                       /* ';'  */
  YYSYMBOL_46_ = 46,                       /* '.'  */
  YYSYMBOL_47_ = 47,                       /* '*'  */
  YYSYMBOL_48_ = 48,                       /* '['  */
  YYSYMBOL_49_ = 49,                       /* ']'  */
  YYSYMBOL_50_ = 50,                       /* '('  */
  YYSYMBOL_51_ = 51,                       /* ')'  */
  YYSYMBOL_52_ = 52,                       /* ','  */
  YYSYMBOL_53_ = 53,                       /* '='  */
  YYSYMBOL_54_ = 54,                       /* '?'  */
  YYSYMBOL_55_ = 55,                       /* ':'  */
  YYSYMBOL_56_ = 56,                       /* '&'  */
  YYSYMBOL_57_ = 57,                       /* '^'  */
  YYSYMBOL_58_ = 58,                       /* '|'  */
  YYSYMBOL_59_ = 59,                       /* '{'  */
  YYSYMBOL_60_ = 60,                       /* '}'  */
  YYSYMBOL_YYACCEPT = 61,                  /* $accept  */
  YYSYMBOL_prog = 62,                      /* prog  */
  YYSYMBOL_ImportList = 63,                /* ImportList  */
  YYSYMBOL_ClassDeclarationList = 64,      /* ClassDeclarationList  */
  YYSYMBOL_Imports = 65,                   /* Imports  */
  YYSYMBOL_Type = 66,                      /* Type  */
  YYSYMBOL_PrimitiveType = 67,             /* PrimitiveType  */
  YYSYMBOL_IDENdotIDEN = 68,               /* IDENdotIDEN  */
  YYSYMBOL_PublicPrivateStatic = 69,       /* PublicPrivateStatic  */
  YYSYMBOL_ClassType = 70,                 /* ClassType  */
  YYSYMBOL_ArrayType = 71,                 /* ArrayType  */
  YYSYMBOL_Dims = 72,                      /* Dims  */
  YYSYMBOL_Primary = 73,                   /* Primary  */
  YYSYMBOL_PrimaryNoNewArray = 74,         /* PrimaryNoNewArray  */
  YYSYMBOL_ClassInstanceCreationExpression = 75, /* ClassInstanceCreationExpression  */
  YYSYMBOL_Zeroorone_ArgumentList = 76,    /* Zeroorone_ArgumentList  */
  YYSYMBOL_FieldAccess = 77,               /* FieldAccess  */
  YYSYMBOL_ArrayAccess = 78,               /* ArrayAccess  */
  YYSYMBOL_MethodInvocation = 79,          /* MethodInvocation  */
  YYSYMBOL_ArgumentList = 80,              /* ArgumentList  */
  YYSYMBOL_ArrayCreationExpression = 81,   /* ArrayCreationExpression  */
  YYSYMBOL_DimExpr = 82,                   /* DimExpr  */
  YYSYMBOL_Expression = 83,                /* Expression  */
  YYSYMBOL_AssignmentExpression = 84,      /* AssignmentExpression  */
  YYSYMBOL_Assignment = 85,                /* Assignment  */
  YYSYMBOL_ConditionalExpression = 86,     /* ConditionalExpression  */
  YYSYMBOL_ConditionalOrExpression = 87,   /* ConditionalOrExpression  */
  YYSYMBOL_ConditionalAndExpression = 88,  /* ConditionalAndExpression  */
  YYSYMBOL_AndExpression = 89,             /* AndExpression  */
  YYSYMBOL_ExclusiveOrExpression = 90,     /* ExclusiveOrExpression  */
  YYSYMBOL_InclusiveOrExpression = 91,     /* InclusiveOrExpression  */
  YYSYMBOL_EqualityExpression = 92,        /* EqualityExpression  */
  YYSYMBOL_RelationalExpression = 93,      /* RelationalExpression  */
  YYSYMBOL_ShiftExpression = 94,           /* ShiftExpression  */
  YYSYMBOL_AdditiveExpression = 95,        /* AdditiveExpression  */
  YYSYMBOL_MultiplicativeExpression = 96,  /* MultiplicativeExpression  */
  YYSYMBOL_UnaryExpression = 97,           /* UnaryExpression  */
  YYSYMBOL_UnaryExpressionNotPlusMinus = 98, /* UnaryExpressionNotPlusMinus  */
  YYSYMBOL_CastExpression = 99,            /* CastExpression  */
  YYSYMBOL_PostfixExpression = 100,        /* PostfixExpression  */
  YYSYMBOL_Block = 101,                    /* Block  */
  YYSYMBOL_BlockStatements = 102,          /* BlockStatements  */
  YYSYMBOL_BlockStatement = 103,           /* BlockStatement  */
  YYSYMBOL_LocalVariableDeclaration = 104, /* LocalVariableDeclaration  */
  YYSYMBOL_LocalVariableType = 105,        /* LocalVariableType  */
  YYSYMBOL_Statement = 106,                /* Statement  */
  YYSYMBOL_StatementNoShortIf = 107,       /* StatementNoShortIf  */
  YYSYMBOL_StatementWithoutTrailingSubstatement = 108, /* StatementWithoutTrailingSubstatement  */
  YYSYMBOL_StatementExpression = 109,      /* StatementExpression  */
  YYSYMBOL_LeftHandSide = 110,             /* LeftHandSide  */
  YYSYMBOL_AssertStatement = 111,          /* AssertStatement  */
  YYSYMBOL_BreakContinueStatement = 112,   /* BreakContinueStatement  */
  YYSYMBOL_ForStatement = 113,             /* ForStatement  */
  YYSYMBOL_ForStatementNoShortIf = 114,    /* ForStatementNoShortIf  */
  YYSYMBOL_ForInit = 115,                  /* ForInit  */
  YYSYMBOL_StatementExpressionList = 116,  /* StatementExpressionList  */
  YYSYMBOL_ClassDeclaration = 117,         /* ClassDeclaration  */
  YYSYMBOL_NormalClassDeclaration = 118,   /* NormalClassDeclaration  */
  YYSYMBOL_ClassExtends = 119,             /* ClassExtends  */
  YYSYMBOL_ClassPermits = 120,             /* ClassPermits  */
  YYSYMBOL_cTypeName = 121,                /* cTypeName  */
  YYSYMBOL_ClassBody = 122,                /* ClassBody  */
  YYSYMBOL_ClassBodyDeclarations = 123,    /* ClassBodyDeclarations  */
  YYSYMBOL_ClassBodyDeclaration = 124,     /* ClassBodyDeclaration  */
  YYSYMBOL_VariableDeclaratorList = 125,   /* VariableDeclaratorList  */
  YYSYMBOL_VariableDeclarator = 126,       /* VariableDeclarator  */
  YYSYMBOL_zerooroneExpression = 127,      /* zerooroneExpression  */
  YYSYMBOL_VariableDeclarator1 = 128,      /* VariableDeclarator1  */
  YYSYMBOL_VariableDeclarator2 = 129,      /* VariableDeclarator2  */
  YYSYMBOL_List1 = 130,                    /* List1  */
  YYSYMBOL_ArrEle1 = 131,                  /* ArrEle1  */
  YYSYMBOL_List2 = 132,                    /* List2  */
  YYSYMBOL_ArrEle2 = 133,                  /* ArrEle2  */
  YYSYMBOL_List3 = 134,                    /* List3  */
  YYSYMBOL_ArrEle3 = 135,                  /* ArrEle3  */
  YYSYMBOL_MethodDeclaration = 136,        /* MethodDeclaration  */
  YYSYMBOL_MethodHeader = 137,             /* MethodHeader  */
  YYSYMBOL_Methodeclarator = 138,          /* Methodeclarator  */
  YYSYMBOL_IdenPara = 139,                 /* IdenPara  */
  YYSYMBOL_formalparameters = 140,         /* formalparameters  */
  YYSYMBOL_formalparameter = 141,          /* formalparameter  */
  YYSYMBOL_MethodBody = 142,               /* MethodBody  */
  YYSYMBOL_Modifiers = 143                 /* Modifiers  */
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
#define YYLAST   772

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  61
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  83
/* YYNRULES -- Number of rules.  */
#define YYNRULES  205
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  396

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   299


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
       2,     2,     2,     2,     2,     2,     2,     2,    56,     2,
      50,    51,    47,     2,    52,     2,    46,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    55,    45,
       2,    53,     2,    54,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    48,     2,    49,    57,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    59,    58,    60,     2,     2,     2,     2,
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
static const yytype_int16 yyrline[] =
{
       0,    32,    32,    41,    47,    53,    59,    65,    71,    78,
      86,    98,   101,   104,   110,   116,   122,   131,   138,   147,
     152,   157,   165,   170,   173,   178,   179,   188,   191,   197,
     203,   208,   215,   218,   221,   224,   227,   233,   241,   251,
     254,   260,   268,   275,   287,   293,   302,   310,   321,   332,
     344,   352,   358,   369,   378,   389,   402,   410,   419,   425,
     428,   434,   444,   456,   459,   474,   477,   490,   493,   506,
     509,   521,   524,   536,   539,   551,   554,   567,   570,   583,
     586,   599,   602,   615,   618,   631,   639,   647,   650,   659,
     662,   673,   684,   687,   690,   704,   710,   716,   722,   725,
     731,   740,   743,   751,   754,   762,   769,   778,   785,   791,
     794,   802,   811,   818,   824,   827,   830,   833,   836,   839,
     844,   850,   856,   862,   872,   875,   878,   884,   895,   898,
     901,   907,   913,   924,   931,   936,   943,   951,   958,   966,
     974,   986,   993,  1001,  1009,  1022,  1027,  1032,  1038,  1044,
    1072,  1077,  1086,  1096,  1106,  1119,  1127,  1137,  1143,  1149,
    1154,  1160,  1165,  1172,  1175,  1178,  1181,  1188,  1194,  1200,
    1206,  1209,  1215,  1218,  1222,  1228,  1235,  1243,  1255,  1263,
    1272,  1282,  1296,  1302,  1308,  1314,  1320,  1326,  1332,  1338,
    1344,  1350,  1360,  1366,  1375,  1378,  1384,  1391,  1399,  1405,
    1411,  1417,  1429,  1432,  1438,  1444
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
  "KEY_yield", "KEY_throw", "KEY_break", "KEY_continue", "KEY_return",
  "KEY_if", "KEY_else", "KEY_for", "KEY_permits", "KEY_while", "KEY_sync",
  "KEY_final", "KEY_extends", "KEY_super", "KEY_this", "KEY_class",
  "KEY_void", "KEY_public", "KEY_new", "KEY_static", "DOT3", "KEY_private",
  "KEY_import", "';'", "'.'", "'*'", "'['", "']'", "'('", "')'", "','",
  "'='", "'?'", "':'", "'&'", "'^'", "'|'", "'{'", "'}'", "$accept",
  "prog", "ImportList", "ClassDeclarationList", "Imports", "Type",
  "PrimitiveType", "IDENdotIDEN", "PublicPrivateStatic", "ClassType",
  "ArrayType", "Dims", "Primary", "PrimaryNoNewArray",
  "ClassInstanceCreationExpression", "Zeroorone_ArgumentList",
  "FieldAccess", "ArrayAccess", "MethodInvocation", "ArgumentList",
  "ArrayCreationExpression", "DimExpr", "Expression",
  "AssignmentExpression", "Assignment", "ConditionalExpression",
  "ConditionalOrExpression", "ConditionalAndExpression", "AndExpression",
  "ExclusiveOrExpression", "InclusiveOrExpression", "EqualityExpression",
  "RelationalExpression", "ShiftExpression", "AdditiveExpression",
  "MultiplicativeExpression", "UnaryExpression",
  "UnaryExpressionNotPlusMinus", "CastExpression", "PostfixExpression",
  "Block", "BlockStatements", "BlockStatement", "LocalVariableDeclaration",
  "LocalVariableType", "Statement", "StatementNoShortIf",
  "StatementWithoutTrailingSubstatement", "StatementExpression",
  "LeftHandSide", "AssertStatement", "BreakContinueStatement",
  "ForStatement", "ForStatementNoShortIf", "ForInit",
  "StatementExpressionList", "ClassDeclaration", "NormalClassDeclaration",
  "ClassExtends", "ClassPermits", "cTypeName", "ClassBody",
  "ClassBodyDeclarations", "ClassBodyDeclaration",
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

#define YYPACT_NINF (-344)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-131)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -344,    27,    46,  -344,    88,    30,  -344,  -344,  -344,   151,
    -344,    48,   -20,  -344,    89,  -344,  -344,  -344,  -344,   160,
    -344,     7,   102,  -344,    24,  -344,    66,    48,    48,  -344,
      91,    54,  -344,    78,  -344,    87,    87,  -344,   -23,    54,
    -344,  -344,  -344,   122,    97,  -344,  -344,  -344,  -344,  -344,
    -344,  -344,   216,  -344,    48,   477,   103,  -344,  -344,  -344,
     173,   177,   112,   112,  -344,   -14,   128,    87,   130,  -344,
     722,  -344,   722,   722,   722,     1,     8,   654,   157,   164,
     167,   171,   183,  -344,   191,  -344,   722,  -344,  -344,    31,
     186,   195,  -344,    23,    41,    83,  -344,  -344,   243,  -344,
    -344,   222,   266,  -344,  -344,   233,    47,  -344,  -344,  -344,
      10,   103,  -344,   112,   126,    56,  -344,  -344,  -344,  -344,
     223,   231,   231,  -344,  -344,  -344,  -344,   549,   722,   722,
     722,   433,   180,  -344,  -344,  -344,  -344,  -344,  -344,   267,
      74,   -21,  -344,  -344,  -344,    49,   274,   234,   235,   238,
     280,   284,   294,   283,   296,  -344,   270,   278,   281,  -344,
     286,  -344,  -344,   287,   722,   631,   722,   722,   315,   292,
     227,   290,    95,   722,   722,   325,   722,   316,  -344,   136,
     293,  -344,   722,   722,  -344,    17,   145,  -344,   231,   722,
     722,  -344,   266,  -344,   295,  -344,  -344,  -344,  -344,   291,
    -344,  -344,   722,   722,   722,   722,   722,   722,   722,   722,
     722,   722,   722,   722,  -344,  -344,  -344,  -344,  -344,   297,
    -344,  -344,   301,   298,   304,   306,   285,   722,   299,   722,
     299,  -344,   312,  -344,   318,   313,   319,  -344,   326,   328,
    -344,  -344,   317,   364,  -344,  -344,   191,  -344,   332,  -344,
    -344,  -344,   722,   338,   274,   335,   238,   280,   234,   235,
     284,   294,   283,   296,  -344,   597,   660,   334,   549,   128,
     722,   340,   693,   231,   336,   231,   388,  -344,  -344,   722,
     722,  -344,   722,  -344,  -344,   155,  -344,  -344,   722,   339,
     345,   346,   349,  -344,   376,   378,  -344,   393,   362,  -344,
    -344,  -344,   359,  -344,   366,    54,   367,  -344,   365,   373,
     722,   371,  -344,   597,   722,   631,   722,   549,   549,   194,
     396,  -344,  -344,  -344,   722,  -344,   375,   377,   722,  -344,
    -344,   374,   379,   383,  -344,  -344,   549,   549,   198,   384,
     722,   156,  -344,    57,   597,   716,   597,  -344,  -344,   549,
    -344,   390,   722,   386,   722,  -344,   420,   506,   405,  -344,
    -344,   406,   408,   371,  -344,  -344,   597,   597,   200,   547,
     722,   407,  -344,    99,  -344,  -344,   597,   597,   232,   409,
     400,   371,  -344,  -344,  -344,   597,  -344,   386,  -344,  -344,
    -344,  -344,   123,   386,  -344,  -344
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,   205,     1,     0,   205,     3,     6,   150,     0,
      18,     0,     0,     5,     0,    19,    21,    20,   204,     0,
       7,     0,     0,     8,     0,    17,     0,     0,     0,   161,
       0,     0,   151,     0,     9,   158,    22,   155,   205,     0,
     152,   153,    10,     0,   156,   164,    97,   159,   165,   163,
     160,   167,     0,   154,     0,     0,    18,    14,    15,    16,
       0,     0,    11,    13,    12,     0,     0,   157,    18,    29,
       0,   102,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    30,     0,   115,     0,    95,   101,   128,
      92,    27,    33,    34,    35,    36,    28,   124,     0,   114,
      96,     0,     0,    99,   103,     0,     0,   117,   118,   108,
       0,     0,   193,   195,   174,     0,   169,   170,   171,   192,
       0,    23,    24,   203,   202,   191,   166,     0,     0,     0,
       0,     0,    93,    34,    35,    36,   126,    87,    88,    89,
      93,     0,    58,    60,    59,    63,    65,    71,    73,    67,
      69,    75,    77,    79,    81,    83,     0,     0,     0,   134,
       0,   136,   119,     0,     0,   147,     0,     0,     0,     0,
       0,     0,     0,     0,    40,     0,     0,   127,    98,   174,
     100,   116,     0,     0,   197,     0,     0,   199,   194,   173,
       0,   162,     0,    25,     0,   104,    86,    85,    90,     0,
      94,   131,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   121,   122,   133,   135,   120,     0,
     146,   149,     0,   145,     0,     0,    42,     0,    53,    40,
      55,    32,     0,    31,     0,     0,    39,    51,    41,     0,
      61,    62,   174,     0,   200,   196,     0,   172,     0,   178,
     168,    26,     0,     0,    66,     0,    68,    70,    72,    74,
      76,    78,    80,    82,    84,     0,     0,     0,     0,     0,
      40,     0,     0,    52,     0,    54,     0,    44,    46,     0,
      40,    45,   173,   201,   198,   175,    91,   132,     0,    18,
       0,     0,     0,   105,     0,   103,   113,     0,     0,   148,
     107,   123,     0,    57,     0,    38,    43,    50,     0,     0,
     173,     0,    64,     0,     0,   147,     0,     0,     0,     0,
       0,    48,    56,    37,    40,    47,   175,     0,     0,   179,
     110,     0,     0,     0,   106,   137,     0,     0,     0,     0,
     173,   176,   184,     0,     0,     0,     0,   139,   138,     0,
      49,     0,   173,     0,     0,   182,     0,     0,     0,   112,
     140,   176,     0,     0,   180,   183,     0,     0,     0,     0,
     173,   177,   187,     0,   111,   141,     0,     0,     0,     0,
       0,     0,   185,   143,   142,     0,   177,     0,   181,   186,
     144,   190,     0,     0,   188,   189
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -344,  -344,  -344,  -344,  -344,   -44,   -81,    28,  -344,   436,
    -344,   -48,  -344,  -344,  -344,  -222,   -66,   -41,   -55,  -344,
    -344,   300,   289,  -344,   -49,   178,  -344,   258,   260,   268,
     269,   271,   279,   265,   276,   277,   -61,  -344,  -344,    36,
     -25,  -344,  -344,   423,  -344,    42,  -271,   -12,  -142,  -344,
    -344,  -344,  -344,  -344,   165,  -250,    80,  -344,  -344,   460,
    -344,   -29,  -344,  -344,   392,   322,  -266,   307,  -344,  -343,
    -344,  -239,  -344,  -344,  -344,  -344,  -344,   435,   453,  -344,
     261,  -344,   481
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,     2,     5,     6,    88,    62,   140,    18,    63,
      64,   121,    90,    91,    92,   235,    93,    94,   135,   236,
      96,   228,   247,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   137,   138,   139,
      99,    55,   100,   220,   102,   195,   294,   295,   105,   106,
     107,   108,   109,   296,   222,   223,     7,     8,    30,    31,
      44,    32,    38,    50,   115,   116,   248,   117,   118,   329,
     343,   364,   373,   388,   392,    51,    65,   112,   113,   186,
     187,   125,     9
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      95,    40,    41,   169,   133,   158,    97,   274,    61,   136,
      53,    25,   160,    48,    10,   122,   309,    57,    58,    59,
     372,   242,    45,   221,   201,    20,    21,     3,    25,   134,
      -2,   123,    12,  -129,   202,   -22,    46,    47,   389,    19,
     124,   126,   330,   104,   327,    46,   159,   319,   302,   -93,
     199,  -130,    10,   161,    26,    35,    36,   182,   308,   243,
     203,   184,   133,   133,   133,   188,   185,   196,   197,   198,
     338,    33,    95,   356,   351,   359,  -129,   172,    97,   173,
      36,   174,    67,    89,  -128,    13,   362,   134,   134,   134,
       4,    98,    10,    22,  -130,   374,   375,   103,   132,    25,
     183,   191,   339,   204,   379,   383,   384,   368,   192,   354,
      95,    34,   170,    29,   390,   104,    97,   355,    49,   378,
     172,    27,   173,    42,   174,   299,    25,  -128,  -125,    11,
     232,   233,    27,    43,  -125,  -125,    28,   133,    36,   133,
     133,   133,   133,   133,   133,   133,   133,   133,   391,    54,
      29,   381,   264,   110,   395,   221,   132,   132,   132,   382,
     120,    29,   134,    98,   134,   134,   134,   134,   134,   134,
     134,   134,   134,   221,   189,   393,   110,   111,   221,   190,
     273,   114,   275,   394,   189,   127,   133,    46,    14,   190,
      15,   286,    16,    89,    17,    10,   245,   246,    57,    58,
      59,    98,   185,   310,   352,    23,    24,   164,   311,   353,
      95,   134,    95,    95,   165,   221,    97,   166,    97,    97,
      56,   167,   133,    57,    58,    59,   172,   221,   173,   168,
     174,   132,   175,   132,   132,   132,   132,   132,   132,   132,
     132,   132,    95,   176,   301,   336,   267,   134,    97,   349,
     267,   376,   267,    14,    60,    15,   104,    16,    95,    17,
      95,   177,    95,    95,    97,    95,    97,   178,    97,    97,
     179,    97,   193,    43,    36,   227,   323,   229,   181,   194,
     132,    95,    95,   385,   267,   200,   205,    97,    97,    95,
     206,    95,   207,   209,    95,    97,   208,    97,   210,   212,
      97,    98,    95,    98,    98,   104,   104,   293,    97,   211,
     300,    95,    95,   213,    95,   214,   132,    97,    97,   226,
      97,    95,    95,   215,   104,   104,   216,    97,    97,   238,
      95,   217,   218,    98,   -94,   270,    97,   104,    10,    69,
     227,   231,   252,    89,   251,   192,   266,   272,   265,    98,
     267,    98,    70,    98,    98,   268,    98,   269,   276,   334,
     335,   141,   156,   157,   278,   282,   163,   277,   283,    82,
      83,   279,    98,    98,    84,   171,   280,   281,   347,   348,
      98,   285,    98,   287,    86,    98,   293,   305,   300,   303,
     288,   360,   306,    98,   313,   314,   315,    10,    69,   316,
      10,    69,    98,    98,   317,    98,  -109,   320,   334,   335,
     321,    70,    98,    98,    70,   322,   325,   324,   347,   348,
     171,    98,   326,   340,   345,   344,   341,   360,    82,    83,
     328,    82,    83,    84,   346,   350,    84,    10,    69,   361,
      57,    58,    59,    86,   318,   363,    86,   337,   366,   128,
     369,   129,   130,   219,   370,   224,   225,   371,   386,   387,
     380,   254,   234,   237,    37,   239,   312,   258,    82,    83,
     230,   240,   241,    84,   256,   261,   259,   257,   101,   249,
     332,    68,    69,   131,    57,    58,    59,   262,   260,   263,
      39,   253,   244,   255,   180,    70,   119,    71,    72,    73,
      74,    75,    76,    77,    78,    66,    79,   284,    80,    81,
      10,    69,    82,    83,   250,     0,   271,    84,   237,    52,
       0,     0,    85,     0,    70,     0,     0,    86,     0,     0,
       0,     0,     0,     0,     0,     0,    46,    87,     0,     0,
       0,    82,    83,     0,     0,     0,    84,     0,     0,     0,
       0,    10,    69,    68,    69,   298,    86,   367,     0,   237,
       0,   304,     0,     0,     0,    70,     0,    70,   307,   237,
      72,    73,    74,    75,    76,    77,    78,     0,    79,     0,
      80,    81,    82,    83,    82,    83,     0,    84,     0,    84,
       0,     0,     0,     0,    85,     0,     0,    86,   377,    86,
       0,   289,    69,   331,     0,   333,     0,     0,    46,     0,
       0,     0,     0,   237,     0,    70,     0,   342,    72,    73,
      74,    75,    76,    77,   290,     0,   291,     0,   292,    81,
       0,     0,    82,    83,   358,    10,    69,    84,    57,    58,
      59,     0,    85,   365,     0,     0,     0,    86,     0,    70,
       0,    71,     0,     0,     0,     0,    46,     0,    10,    69,
       0,     0,     0,     0,    10,    69,    82,    83,     0,     0,
     128,    84,   129,   130,     0,     0,   128,     0,   129,   130,
       0,    86,     0,     0,     0,     0,     0,     0,     0,    82,
      83,     0,     0,     0,    84,    82,    83,    10,    69,   162,
      84,     0,     0,     0,   131,   297,     0,     0,     0,   128,
     131,   129,   130,     0,     0,     0,     0,     0,     0,     0,
      10,    69,     0,     0,     0,     0,    10,    69,    82,    83,
       0,     0,   128,    84,   129,   130,     0,     0,   128,     0,
     129,   130,   193,   131,     0,     0,     0,     0,     0,     0,
       0,    82,    83,     0,     0,     0,    84,    82,    83,     0,
       0,   357,    84,     0,     0,     0,   131,     0,     0,     0,
       0,     0,   131
};

static const yytype_int16 yycheck[] =
{
      55,    30,    31,    84,    70,     4,    55,   229,    52,    70,
      39,     4,     4,    38,     4,    63,   282,     7,     8,     9,
     363,     4,    45,   165,    45,    45,    46,     0,     4,    70,
       0,    45,     4,    10,    55,     4,    59,    60,   381,    11,
      65,    66,   313,    55,   310,    59,    45,   297,   270,    18,
     131,    10,     4,    45,    47,    27,    28,    10,   280,    42,
      11,    51,   128,   129,   130,   113,   110,   128,   129,   130,
     320,    47,   127,   344,   340,   346,    53,    46,   127,    48,
      52,    50,    54,    55,    10,     5,   352,   128,   129,   130,
      44,    55,     4,     4,    53,   366,   367,    55,    70,     4,
      53,    45,   324,    54,   370,   376,   377,   357,    52,    52,
     165,    45,    84,    59,   385,   127,   165,    60,    38,   369,
      46,    30,    48,    45,    50,   267,     4,    53,    45,    41,
      35,    36,    30,    46,    51,    52,    34,   203,   110,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   387,    52,
      59,    52,   213,    50,   393,   297,   128,   129,   130,    60,
      48,    59,   203,   127,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   315,    48,    52,    50,     4,   320,    53,
     228,     4,   230,    60,    48,    55,   252,    59,    37,    53,
      39,   252,    41,   165,    43,     4,    51,    52,     7,     8,
       9,   165,   246,    48,    48,    45,    46,    50,    53,    53,
     265,   252,   267,   268,    50,   357,   265,    50,   267,   268,
       4,    50,   288,     7,     8,     9,    46,   369,    48,    46,
      50,   203,    46,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   297,    48,   269,    51,    52,   288,   297,    51,
      52,    51,    52,    37,    38,    39,   268,    41,   313,    43,
     315,    18,   317,   318,   313,   320,   315,    45,   317,   318,
       4,   320,    49,    46,   246,    48,   305,    50,    45,    48,
     252,   336,   337,    51,    52,    18,    12,   336,   337,   344,
      56,   346,    57,    13,   349,   344,    58,   346,    14,    16,
     349,   265,   357,   267,   268,   317,   318,   265,   357,    15,
     268,   366,   367,    17,   369,    45,   288,   366,   367,     4,
     369,   376,   377,    45,   336,   337,    45,   376,   377,     4,
     385,    45,    45,   297,    18,    50,   385,   349,     4,     5,
      48,    51,    51,   315,    49,    52,    45,    48,    51,   313,
      52,   315,    18,   317,   318,    51,   320,    51,    46,   317,
     318,    72,    73,    74,    51,    48,    77,    49,     4,    35,
      36,    52,   336,   337,    40,    86,    50,    49,   336,   337,
     344,    49,   346,    45,    50,   349,   344,    51,   346,    49,
      55,   349,     4,   357,    55,    50,    50,     4,     5,    50,
       4,     5,   366,   367,    28,   369,    28,    45,   366,   367,
      51,    18,   376,   377,    18,    49,    51,    50,   376,   377,
     131,   385,    49,    48,    45,    51,    49,   385,    35,    36,
      59,    35,    36,    40,    51,    51,    40,     4,     5,    49,
       7,     8,     9,    50,    51,    59,    50,    51,    28,    16,
      45,    18,    19,   164,    48,   166,   167,    49,    49,    59,
      53,   203,   173,   174,    28,   176,   288,   207,    35,    36,
     170,   182,   183,    40,   205,   210,   208,   206,    55,   190,
     315,     4,     5,    50,     7,     8,     9,   211,   209,   212,
      30,   202,   185,   204,   102,    18,    61,    20,    21,    22,
      23,    24,    25,    26,    27,    52,    29,   246,    31,    32,
       4,     5,    35,    36,   192,    -1,   227,    40,   229,    38,
      -1,    -1,    45,    -1,    18,    -1,    -1,    50,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    59,    60,    -1,    -1,
      -1,    35,    36,    -1,    -1,    -1,    40,    -1,    -1,    -1,
      -1,     4,     5,     4,     5,   266,    50,    51,    -1,   270,
      -1,   272,    -1,    -1,    -1,    18,    -1,    18,   279,   280,
      21,    22,    23,    24,    25,    26,    27,    -1,    29,    -1,
      31,    32,    35,    36,    35,    36,    -1,    40,    -1,    40,
      -1,    -1,    -1,    -1,    45,    -1,    -1,    50,    51,    50,
      -1,     4,     5,   314,    -1,   316,    -1,    -1,    59,    -1,
      -1,    -1,    -1,   324,    -1,    18,    -1,   328,    21,    22,
      23,    24,    25,    26,    27,    -1,    29,    -1,    31,    32,
      -1,    -1,    35,    36,   345,     4,     5,    40,     7,     8,
       9,    -1,    45,   354,    -1,    -1,    -1,    50,    -1,    18,
      -1,    20,    -1,    -1,    -1,    -1,    59,    -1,     4,     5,
      -1,    -1,    -1,    -1,     4,     5,    35,    36,    -1,    -1,
      16,    40,    18,    19,    -1,    -1,    16,    -1,    18,    19,
      -1,    50,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,
      36,    -1,    -1,    -1,    40,    35,    36,     4,     5,    45,
      40,    -1,    -1,    -1,    50,    45,    -1,    -1,    -1,    16,
      50,    18,    19,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       4,     5,    -1,    -1,    -1,    -1,     4,     5,    35,    36,
      -1,    -1,    16,    40,    18,    19,    -1,    -1,    16,    -1,
      18,    19,    49,    50,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    35,    36,    -1,    -1,    -1,    40,    35,    36,    -1,
      -1,    45,    40,    -1,    -1,    -1,    50,    -1,    -1,    -1,
      -1,    -1,    50
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    62,    63,     0,    44,    64,    65,   117,   118,   143,
       4,    41,    68,   117,    37,    39,    41,    43,    69,    68,
      45,    46,     4,    45,    46,     4,    47,    30,    34,    59,
     119,   120,   122,    47,    45,    68,    68,    70,   123,   120,
     122,   122,    45,    46,   121,    45,    59,    60,   101,   117,
     124,   136,   143,   122,    52,   102,     4,     7,     8,     9,
      38,    66,    67,    70,    71,   137,   139,    68,     4,     5,
      18,    20,    21,    22,    23,    24,    25,    26,    27,    29,
      31,    32,    35,    36,    40,    45,    50,    60,    66,    68,
      73,    74,    75,    77,    78,    79,    81,    85,   100,   101,
     103,   104,   105,   106,   108,   109,   110,   111,   112,   113,
      50,     4,   138,   139,     4,   125,   126,   128,   129,   138,
      48,    72,    72,    45,   101,   142,   101,    55,    16,    18,
      19,    50,    68,    77,    78,    79,    97,    98,    99,   100,
      68,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    83,    83,     4,    45,
       4,    45,    45,    83,    50,    50,    50,    50,    46,    67,
      68,    83,    46,    48,    50,    46,    48,    18,    45,     4,
     125,    45,    10,    53,    51,    66,   140,   141,    72,    48,
      53,    45,    52,    49,    48,   106,    97,    97,    97,    67,
      18,    45,    55,    11,    54,    12,    56,    57,    58,    13,
      14,    15,    16,    17,    45,    45,    45,    45,    45,    83,
     104,   109,   115,   116,    83,    83,     4,    48,    82,    50,
      82,    51,    35,    36,    83,    76,    80,    83,     4,    83,
      83,    83,     4,    42,   128,    51,    52,    83,   127,    83,
     126,    49,    51,    83,    88,    83,    91,    92,    89,    90,
      93,    94,    95,    96,    97,    51,    45,    52,    51,    51,
      50,    83,    48,    72,    76,    72,    46,    49,    51,    52,
      50,    49,    48,     4,   141,    49,    97,    45,    55,     4,
      27,    29,    31,   106,   107,   108,   114,    45,    83,   109,
     106,   101,    76,    49,    83,    51,     4,    83,    76,   127,
      48,    53,    86,    55,    50,    50,    50,    28,    51,   116,
      45,    51,    49,   122,    50,    51,    49,   127,    59,   130,
     107,    83,   115,    83,   106,   106,    51,    51,   116,    76,
      48,    49,    83,   131,    51,    45,    51,   106,   106,    51,
      51,   127,    48,    53,    52,    60,   107,    45,    83,   107,
     106,    49,   127,    59,   132,    83,    28,    51,   116,    45,
      48,    49,   130,   133,   107,   107,    51,    51,   116,   127,
      53,    52,    60,   107,   107,    51,    49,    59,   134,   130,
     107,   132,   135,    52,    60,   132
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    61,    62,    63,    63,    64,    64,    65,    65,    65,
      65,    66,    66,    66,    67,    67,    67,    68,    68,    69,
      69,    69,    70,    71,    71,    72,    72,    73,    73,    74,
      74,    74,    74,    74,    74,    74,    74,    75,    75,    76,
      76,    77,    77,    77,    78,    78,    79,    79,    79,    79,
      80,    80,    81,    81,    81,    81,    82,    82,    83,    84,
      84,    85,    85,    86,    86,    87,    87,    88,    88,    89,
      89,    90,    90,    91,    91,    92,    92,    93,    93,    94,
      94,    95,    95,    96,    96,    97,    97,    97,    97,    98,
      98,    99,   100,   100,   100,   101,   102,   102,   103,   103,
     104,   105,   105,   106,   106,   106,   106,   106,   106,   107,
     107,   107,   107,   107,   108,   108,   108,   108,   108,   108,
     108,   108,   108,   108,   109,   109,   109,   109,   110,   110,
     110,   111,   111,   112,   112,   112,   112,   113,   113,   113,
     113,   114,   114,   114,   114,   115,   115,   115,   116,   116,
     117,   118,   118,   118,   118,   119,   120,   121,   121,   122,
     123,   123,   124,   124,   124,   124,   124,   124,   125,   125,
     126,   126,   127,   127,   128,   128,   128,   128,   129,   129,
     129,   129,   130,   131,   131,   132,   133,   133,   134,   135,
     135,   136,   137,   137,   138,   138,   139,   139,   140,   140,
     141,   141,   142,   142,   143,   143
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
       3,     3,     3,     5,     1,     1,     2,     2,     1,     1,
       1,     3,     5,     3,     2,     3,     2,     7,     8,     8,
       9,     7,     8,     8,     9,     1,     1,     0,     3,     1,
       1,     4,     5,     5,     6,     2,     3,     3,     0,     3,
       2,     0,     4,     1,     1,     1,     3,     1,     3,     1,
       1,     1,     1,     0,     1,     4,     7,    10,     3,     6,
       9,    12,     3,     3,     1,     3,     3,     1,     3,     3,
       1,     3,     2,     2,     2,     1,     4,     3,     3,     1,
       2,     3,     1,     1,     2,     0
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
#line 32 "parser.y"
                                                {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-1].ptr));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode("prog", s);
        }
#line 1706 "parser.tab.c"
    break;

  case 3: /* ImportList: ImportList Imports  */
#line 41 "parser.y"
                        {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-1].ptr));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode("ImportList", s);
    }
#line 1717 "parser.tab.c"
    break;

  case 4: /* ImportList: %empty  */
#line 47 "parser.y"
        {
        (yyval.ptr)=NULL;
    }
#line 1725 "parser.tab.c"
    break;

  case 5: /* ClassDeclarationList: ClassDeclarationList ClassDeclaration  */
#line 53 "parser.y"
                                                {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-1].ptr));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode("ClassDeclarationList", s);
    }
#line 1736 "parser.tab.c"
    break;

  case 6: /* ClassDeclarationList: ClassDeclaration  */
#line 59 "parser.y"
                            {
        (yyval.ptr)=(yyvsp[0].ptr);
    }
#line 1744 "parser.tab.c"
    break;

  case 7: /* Imports: KEY_import IDENdotIDEN ';'  */
#line 65 "parser.y"
                                    {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("import"));
        s.push_back((yyvsp[-1].ptr));
        (yyval.ptr) = makeNode("Imports", s);
    }
#line 1755 "parser.tab.c"
    break;

  case 8: /* Imports: KEY_import KEY_static IDENdotIDEN ';'  */
#line 71 "parser.y"
                                                {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("import"));
        s.push_back(makeLeaf("static"));
        s.push_back((yyvsp[-1].ptr));
        (yyval.ptr) = makeNode("Imports", s);
    }
#line 1767 "parser.tab.c"
    break;

  case 9: /* Imports: KEY_import IDENdotIDEN '.' '*' ';'  */
#line 78 "parser.y"
                                                {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("import"));
        s.push_back((yyvsp[-3].ptr));
        s.push_back(makeLeaf("*"));
        
        (yyval.ptr) = makeNode("Imports", s);   
    }
#line 1780 "parser.tab.c"
    break;

  case 10: /* Imports: KEY_import KEY_static IDENdotIDEN '.' '*' ';'  */
#line 86 "parser.y"
                                                        {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("import"));
        s.push_back(makeLeaf("static"));
        s.push_back((yyvsp[-3].ptr));
        delete (yyvsp[-3].ptr);
        (yyval.ptr) = makeNode("Imports", s);
    }
#line 1793 "parser.tab.c"
    break;

  case 11: /* Type: PrimitiveType  */
#line 98 "parser.y"
                    {
        (yyval.ptr)=(yyvsp[0].ptr);
    }
#line 1801 "parser.tab.c"
    break;

  case 12: /* Type: ArrayType  */
#line 101 "parser.y"
                    {
        (yyval.ptr)=(yyvsp[0].ptr);
    }
#line 1809 "parser.tab.c"
    break;

  case 13: /* Type: ClassType  */
#line 104 "parser.y"
                    {
        (yyval.ptr)=(yyvsp[0].ptr);
    }
#line 1817 "parser.tab.c"
    break;

  case 14: /* PrimitiveType: INTTYPE  */
#line 110 "parser.y"
                {
        vector<ASTNode*> s;
        s.push_back(makeLeaf(*(yyvsp[0].st)));
        delete (yyvsp[0].st);
        (yyval.ptr) = makeNode("PrimitiveType", s);
    }
#line 1828 "parser.tab.c"
    break;

  case 15: /* PrimitiveType: FPTYPE  */
#line 116 "parser.y"
                   {
        vector<ASTNode*> s;
        s.push_back(makeLeaf(*(yyvsp[0].st)));
        delete (yyvsp[0].st);
        (yyval.ptr) = makeNode("PrimitiveType", s);
    }
#line 1839 "parser.tab.c"
    break;

  case 16: /* PrimitiveType: BOOLTYPE  */
#line 122 "parser.y"
                    {
        vector<ASTNode*> s;
        s.push_back(makeLeaf(*(yyvsp[0].st)));
        delete (yyvsp[0].st);
        (yyval.ptr) = makeNode("PrimitiveType", s);
    }
#line 1850 "parser.tab.c"
    break;

  case 17: /* IDENdotIDEN: IDENdotIDEN '.' IDENTIFIER  */
#line 131 "parser.y"
                                    {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-2].ptr));
        s.push_back(makeLeaf("IDENTIFIER (" + *(yyvsp[0].st) + ")"));
        delete (yyvsp[0].st);
        (yyval.ptr) = makeNode("IDENdotIDEN", s);
    }
#line 1862 "parser.tab.c"
    break;

  case 18: /* IDENdotIDEN: IDENTIFIER  */
#line 138 "parser.y"
                    {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("IDENTIFIER (" + *(yyvsp[0].st) + ")"));
        delete (yyvsp[0].st);
        (yyval.ptr) = makeNode("IDENdotIDEN", s);
    }
#line 1873 "parser.tab.c"
    break;

  case 19: /* PublicPrivateStatic: KEY_public  */
#line 147 "parser.y"
                    {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("public"));
        (yyval.ptr) = makeNode("PublicPrivateStatic", s);
    }
#line 1883 "parser.tab.c"
    break;

  case 20: /* PublicPrivateStatic: KEY_private  */
#line 152 "parser.y"
                        {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("private"));
        (yyval.ptr) = makeNode("PublicPrivateStatic", s);
    }
#line 1893 "parser.tab.c"
    break;

  case 21: /* PublicPrivateStatic: KEY_static  */
#line 157 "parser.y"
                        {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("static"));
        (yyval.ptr) = makeNode("PublicPrivateStatic", s);
    }
#line 1903 "parser.tab.c"
    break;

  case 22: /* ClassType: IDENdotIDEN  */
#line 165 "parser.y"
                    {
        (yyval.ptr)=(yyvsp[0].ptr);
    }
#line 1911 "parser.tab.c"
    break;

  case 23: /* ArrayType: PrimitiveType Dims  */
#line 170 "parser.y"
                            {
        (yyval.ptr)=(yyvsp[-1].ptr);
    }
#line 1919 "parser.tab.c"
    break;

  case 24: /* ArrayType: ClassType Dims  */
#line 173 "parser.y"
                            {
        (yyval.ptr)=(yyvsp[-1].ptr);
    }
#line 1927 "parser.tab.c"
    break;

  case 25: /* Dims: '[' ']'  */
#line 178 "parser.y"
                {(yyval.ptr)=NULL;}
#line 1933 "parser.tab.c"
    break;

  case 26: /* Dims: Dims '[' ']'  */
#line 179 "parser.y"
                    {
        (yyval.ptr)=NULL;
    }
#line 1941 "parser.tab.c"
    break;

  case 27: /* Primary: PrimaryNoNewArray  */
#line 188 "parser.y"
                        {
        (yyval.ptr) = (yyvsp[0].ptr);
    }
#line 1949 "parser.tab.c"
    break;

  case 28: /* Primary: ArrayCreationExpression  */
#line 191 "parser.y"
                                    {
        (yyval.ptr) = (yyvsp[0].ptr);
    }
#line 1957 "parser.tab.c"
    break;

  case 29: /* PrimaryNoNewArray: LITERAL  */
#line 197 "parser.y"
                {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("Literal"));
        (yyval.ptr) = makeNode("PrimaryNoNewArray", s);
    }
#line 1967 "parser.tab.c"
    break;

  case 30: /* PrimaryNoNewArray: KEY_this  */
#line 203 "parser.y"
                    {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("this"));
        (yyval.ptr) = makeNode("PrimaryNoNewArray", s);
    }
#line 1977 "parser.tab.c"
    break;

  case 31: /* PrimaryNoNewArray: IDENdotIDEN '.' KEY_this  */
#line 208 "parser.y"
                                    {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-2].ptr));
        s.push_back(makeLeaf("this"));
        
        (yyval.ptr) = makeNode("PrimaryNoNewArray", s);
    }
#line 1989 "parser.tab.c"
    break;

  case 32: /* PrimaryNoNewArray: '(' Expression ')'  */
#line 215 "parser.y"
                                {
        (yyval.ptr) = (yyvsp[-1].ptr);
    }
#line 1997 "parser.tab.c"
    break;

  case 33: /* PrimaryNoNewArray: ClassInstanceCreationExpression  */
#line 218 "parser.y"
                                            {
        (yyval.ptr) = (yyvsp[0].ptr);
    }
#line 2005 "parser.tab.c"
    break;

  case 34: /* PrimaryNoNewArray: FieldAccess  */
#line 221 "parser.y"
                        {
        (yyval.ptr) = (yyvsp[0].ptr);
    }
#line 2013 "parser.tab.c"
    break;

  case 35: /* PrimaryNoNewArray: ArrayAccess  */
#line 224 "parser.y"
                        {
        (yyval.ptr) = (yyvsp[0].ptr);
    }
#line 2021 "parser.tab.c"
    break;

  case 36: /* PrimaryNoNewArray: MethodInvocation  */
#line 227 "parser.y"
                            {
        (yyval.ptr) = (yyvsp[0].ptr);
    }
#line 2029 "parser.tab.c"
    break;

  case 37: /* ClassInstanceCreationExpression: KEY_new IDENdotIDEN '(' Zeroorone_ArgumentList ')' ClassBody  */
#line 233 "parser.y"
                                                                        {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("new"));
        s.push_back((yyvsp[-4].ptr));
        s.push_back((yyvsp[-2].ptr));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode("ClassInstanceCreationExpression", s);
    }
#line 2042 "parser.tab.c"
    break;

  case 38: /* ClassInstanceCreationExpression: KEY_new IDENdotIDEN '(' Zeroorone_ArgumentList ')'  */
#line 241 "parser.y"
                                                                {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("new"));
        s.push_back((yyvsp[-3].ptr));
        s.push_back((yyvsp[-1].ptr));
        (yyval.ptr) = makeNode("ClassInstanceCreationExpression", s);
    }
#line 2054 "parser.tab.c"
    break;

  case 39: /* Zeroorone_ArgumentList: ArgumentList  */
#line 251 "parser.y"
                        {
        (yyval.ptr) = (yyvsp[0].ptr);
    }
#line 2062 "parser.tab.c"
    break;

  case 40: /* Zeroorone_ArgumentList: %empty  */
#line 254 "parser.y"
        {
        (yyval.ptr)=NULL;
    }
#line 2070 "parser.tab.c"
    break;

  case 41: /* FieldAccess: Primary '.' IDENTIFIER  */
#line 260 "parser.y"
                                {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-2].ptr));
        s.push_back(makeLeaf("IDENTIFIER (" + *(yyvsp[0].st) + ")"));
        delete (yyvsp[0].st);
        
        (yyval.ptr) = makeNode("FieldAccess", s);
    }
#line 2083 "parser.tab.c"
    break;

  case 42: /* FieldAccess: KEY_super '.' IDENTIFIER  */
#line 268 "parser.y"
                                    {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("super"));
        s.push_back(makeLeaf("IDENTIFIER (" + *(yyvsp[0].st) + ")"));
        delete (yyvsp[0].st);
        (yyval.ptr) = makeNode("FieldAccess", s);
    }
#line 2095 "parser.tab.c"
    break;

  case 43: /* FieldAccess: IDENdotIDEN '.' KEY_super '.' IDENTIFIER  */
#line 275 "parser.y"
                                                    {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-4].ptr));
        s.push_back(makeLeaf("super"));
        s.push_back(makeLeaf("IDENTIFIER (" + *(yyvsp[0].st) + ")"));
        delete (yyvsp[0].st);
        
        (yyval.ptr) = makeNode("FieldAccess", s);
    }
#line 2109 "parser.tab.c"
    break;

  case 44: /* ArrayAccess: IDENdotIDEN '[' Expression ']'  */
#line 287 "parser.y"
                                        {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-3].ptr));
        s.push_back((yyvsp[-1].ptr));
        (yyval.ptr) = makeNode("ArrayAccess", s);
    }
#line 2120 "parser.tab.c"
    break;

  case 45: /* ArrayAccess: PrimaryNoNewArray '[' Expression ']'  */
#line 293 "parser.y"
                                                {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-3].ptr));
        s.push_back((yyvsp[-1].ptr));
        (yyval.ptr) = makeNode("ArrayAccess", s);
    }
#line 2131 "parser.tab.c"
    break;

  case 46: /* MethodInvocation: IDENdotIDEN '(' Zeroorone_ArgumentList ')'  */
#line 302 "parser.y"
                                                        {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-3].ptr));
        s.push_back((yyvsp[-1].ptr));
        
        
        (yyval.ptr) = makeNode("MethodInvocation", s);
    }
#line 2144 "parser.tab.c"
    break;

  case 47: /* MethodInvocation: Primary '.' IDENTIFIER '(' Zeroorone_ArgumentList ')'  */
#line 310 "parser.y"
                                                                {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-5].ptr));
        s.push_back(makeLeaf("IDENTIFIER (" + *(yyvsp[-3].st) + ")"));
        delete (yyvsp[-3].st);
        s.push_back((yyvsp[-1].ptr));
        
        
        
        (yyval.ptr) = makeNode("MethodInvocation", s);
    }
#line 2160 "parser.tab.c"
    break;

  case 48: /* MethodInvocation: KEY_super '.' IDENTIFIER '(' Zeroorone_ArgumentList ')'  */
#line 321 "parser.y"
                                                                    {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("super"));
        s.push_back(makeLeaf("IDENTIFIER (" + *(yyvsp[-3].st) + ")"));
        delete (yyvsp[-3].st);
        s.push_back((yyvsp[-1].ptr));
        
        
        
        (yyval.ptr) = makeNode("MethodInvocation", s);
    }
#line 2176 "parser.tab.c"
    break;

  case 49: /* MethodInvocation: IDENdotIDEN '.' KEY_super '.' IDENTIFIER '(' Zeroorone_ArgumentList ')'  */
#line 332 "parser.y"
                                                                                   {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-7].ptr));
        s.push_back(makeLeaf("super"));
        s.push_back(makeLeaf("IDENTIFIER (" + *(yyvsp[-3].st) + ")"));
        delete (yyvsp[-3].st);
        s.push_back((yyvsp[-1].ptr));
        (yyval.ptr) = makeNode("MethodInvocation", s);   
    }
#line 2190 "parser.tab.c"
    break;

  case 50: /* ArgumentList: ArgumentList ',' Expression  */
#line 344 "parser.y"
                                    {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-2].ptr));
        s.push_back((yyvsp[0].ptr));
        
        
        (yyval.ptr) = makeNode("ArguementList", s);
    }
#line 2203 "parser.tab.c"
    break;

  case 51: /* ArgumentList: Expression  */
#line 352 "parser.y"
                        {
        (yyval.ptr) = (yyvsp[0].ptr);
    }
#line 2211 "parser.tab.c"
    break;

  case 52: /* ArrayCreationExpression: KEY_new PrimitiveType DimExpr Dims  */
#line 358 "parser.y"
                                            {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("new"));
        s.push_back((yyvsp[-2].ptr));
        s.push_back((yyvsp[-1].ptr));
        s.push_back((yyvsp[0].ptr));
        
        
        
        (yyval.ptr) = makeNode("ArrayCreationExpression", s);
    }
#line 2227 "parser.tab.c"
    break;

  case 53: /* ArrayCreationExpression: KEY_new PrimitiveType DimExpr  */
#line 369 "parser.y"
                                        {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("new"));
        s.push_back((yyvsp[-1].ptr));
        s.push_back((yyvsp[0].ptr));
        
        
        (yyval.ptr) = makeNode("ArrayCreationExpression", s);
    }
#line 2241 "parser.tab.c"
    break;

  case 54: /* ArrayCreationExpression: KEY_new IDENdotIDEN DimExpr Dims  */
#line 378 "parser.y"
                                            {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("new"));
        s.push_back((yyvsp[-2].ptr));
        s.push_back((yyvsp[-1].ptr));
        s.push_back((yyvsp[0].ptr));
        
        
        
        (yyval.ptr) = makeNode("ArrayCreationExpression", s);
    }
#line 2257 "parser.tab.c"
    break;

  case 55: /* ArrayCreationExpression: KEY_new IDENdotIDEN DimExpr  */
#line 389 "parser.y"
                                        {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("new"));
        s.push_back((yyvsp[-1].ptr));
        s.push_back((yyvsp[0].ptr));
        
        
        (yyval.ptr) = makeNode("ArrayCreationExpression", s);
    }
#line 2271 "parser.tab.c"
    break;

  case 56: /* DimExpr: DimExpr '[' Expression ']'  */
#line 402 "parser.y"
                                {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-3].ptr));
        s.push_back((yyvsp[-1].ptr));
        
        
        (yyval.ptr) = makeNode("DimExpr", s);
    }
#line 2284 "parser.tab.c"
    break;

  case 57: /* DimExpr: '[' Expression ']'  */
#line 410 "parser.y"
                                {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-1].ptr));
        
        (yyval.ptr) = makeNode("DimExpr", s);
    }
#line 2295 "parser.tab.c"
    break;

  case 58: /* Expression: AssignmentExpression  */
#line 419 "parser.y"
                            {
        (yyval.ptr) = (yyvsp[0].ptr);
    }
#line 2303 "parser.tab.c"
    break;

  case 59: /* AssignmentExpression: ConditionalExpression  */
#line 425 "parser.y"
                                {
        (yyval.ptr) = (yyvsp[0].ptr);
    }
#line 2311 "parser.tab.c"
    break;

  case 60: /* AssignmentExpression: Assignment  */
#line 428 "parser.y"
                        {
        (yyval.ptr) = (yyvsp[0].ptr);
    }
#line 2319 "parser.tab.c"
    break;

  case 61: /* Assignment: LeftHandSide ASSIGNOP Expression  */
#line 434 "parser.y"
                                            {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-2].ptr));
        s.push_back(makeLeaf(*(yyvsp[-1].st)));
        s.push_back((yyvsp[0].ptr));
        delete (yyvsp[-1].st);
        
        
        (yyval.ptr) = makeNode("Assignment", s);
    }
#line 2334 "parser.tab.c"
    break;

  case 62: /* Assignment: LeftHandSide '=' Expression  */
#line 444 "parser.y"
                                        {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-2].ptr));
        s.push_back(makeLeaf("="));
        s.push_back((yyvsp[0].ptr));
        
        
        (yyval.ptr) = makeNode("Assignment", s);
    }
#line 2348 "parser.tab.c"
    break;

  case 63: /* ConditionalExpression: ConditionalOrExpression  */
#line 456 "parser.y"
                                {
        (yyval.ptr) = (yyvsp[0].ptr);
    }
#line 2356 "parser.tab.c"
    break;

  case 64: /* ConditionalExpression: ConditionalOrExpression '?' Expression ':' ConditionalExpression  */
#line 459 "parser.y"
                                                                            {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-4].ptr));
        s.push_back(makeLeaf("?"));
        s.push_back((yyvsp[-2].ptr));
        s.push_back(makeLeaf(":"));
        s.push_back((yyvsp[0].ptr));
        
        
        
        (yyval.ptr) = makeNode("ConditionalExpression", s);
    }
#line 2373 "parser.tab.c"
    break;

  case 65: /* ConditionalOrExpression: ConditionalAndExpression  */
#line 474 "parser.y"
                                    {
        (yyval.ptr) = (yyvsp[0].ptr);
    }
#line 2381 "parser.tab.c"
    break;

  case 66: /* ConditionalOrExpression: ConditionalOrExpression CONDOR ConditionalAndExpression  */
#line 477 "parser.y"
                                                                    {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-2].ptr));
        s.push_back(makeLeaf("||"));
        s.push_back((yyvsp[0].ptr));
        
        
        
        (yyval.ptr) = makeNode("ConditionalOrExpression", s);
    }
#line 2396 "parser.tab.c"
    break;

  case 67: /* ConditionalAndExpression: InclusiveOrExpression  */
#line 490 "parser.y"
                            {
        (yyval.ptr) = (yyvsp[0].ptr);
    }
#line 2404 "parser.tab.c"
    break;

  case 68: /* ConditionalAndExpression: ConditionalAndExpression CONDAND InclusiveOrExpression  */
#line 493 "parser.y"
                                                                    {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-2].ptr));
        s.push_back(makeLeaf("&&"));
        s.push_back((yyvsp[0].ptr));
        
        
        
        (yyval.ptr) = makeNode("ConditionalAndExpression", s);
    }
#line 2419 "parser.tab.c"
    break;

  case 69: /* AndExpression: EqualityExpression  */
#line 506 "parser.y"
                            {
        (yyval.ptr) = (yyvsp[0].ptr);
    }
#line 2427 "parser.tab.c"
    break;

  case 70: /* AndExpression: AndExpression '&' EqualityExpression  */
#line 509 "parser.y"
                                                {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-2].ptr));
        s.push_back(makeLeaf("&"));
        s.push_back((yyvsp[0].ptr));
        
        
        (yyval.ptr) = makeNode("AndExpression", s);
    }
#line 2441 "parser.tab.c"
    break;

  case 71: /* ExclusiveOrExpression: AndExpression  */
#line 521 "parser.y"
                        {
        (yyval.ptr) = (yyvsp[0].ptr);
    }
#line 2449 "parser.tab.c"
    break;

  case 72: /* ExclusiveOrExpression: ExclusiveOrExpression '^' AndExpression  */
#line 524 "parser.y"
                                                    {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-2].ptr));
        s.push_back(makeLeaf("^"));
        s.push_back((yyvsp[0].ptr));
        
        
        (yyval.ptr) = makeNode("ExclusiveOrExpression", s);
    }
#line 2463 "parser.tab.c"
    break;

  case 73: /* InclusiveOrExpression: ExclusiveOrExpression  */
#line 536 "parser.y"
                                {
        (yyval.ptr) = (yyvsp[0].ptr);
    }
#line 2471 "parser.tab.c"
    break;

  case 74: /* InclusiveOrExpression: InclusiveOrExpression '|' ExclusiveOrExpression  */
#line 539 "parser.y"
                                                            {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-2].ptr));
        s.push_back(makeLeaf("|"));
        s.push_back((yyvsp[0].ptr));
        
        
        (yyval.ptr) = makeNode("InclusiveOrExpression", s);
    }
#line 2485 "parser.tab.c"
    break;

  case 75: /* EqualityExpression: RelationalExpression  */
#line 551 "parser.y"
                            {
        (yyval.ptr) = (yyvsp[0].ptr);
    }
#line 2493 "parser.tab.c"
    break;

  case 76: /* EqualityExpression: EqualityExpression EQALITYOP RelationalExpression  */
#line 554 "parser.y"
                                                        {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-2].ptr));
        s.push_back(makeLeaf(*(yyvsp[-1].st)));
        s.push_back((yyvsp[0].ptr));
        delete (yyvsp[-1].st);
        
        
        (yyval.ptr) = makeNode("EqualityExpression", s);
    }
#line 2508 "parser.tab.c"
    break;

  case 77: /* RelationalExpression: ShiftExpression  */
#line 567 "parser.y"
                        {
        (yyval.ptr) = (yyvsp[0].ptr);
    }
#line 2516 "parser.tab.c"
    break;

  case 78: /* RelationalExpression: RelationalExpression RELATIONOP ShiftExpression  */
#line 570 "parser.y"
                                                            {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-2].ptr));
        s.push_back(makeLeaf(*(yyvsp[-1].st)));
        s.push_back((yyvsp[0].ptr));
        delete (yyvsp[-1].st);
        
        
        (yyval.ptr) = makeNode("RelationalExpression", s);
    }
#line 2531 "parser.tab.c"
    break;

  case 79: /* ShiftExpression: AdditiveExpression  */
#line 583 "parser.y"
                            {
        (yyval.ptr) = (yyvsp[0].ptr);
    }
#line 2539 "parser.tab.c"
    break;

  case 80: /* ShiftExpression: ShiftExpression SHIFTOP AdditiveExpression  */
#line 586 "parser.y"
                                                    {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-2].ptr));
        s.push_back(makeLeaf(*(yyvsp[-1].st)));
        s.push_back((yyvsp[0].ptr));
        delete (yyvsp[-1].st);
        
        
        (yyval.ptr) = makeNode("ShiftExpression", s);
    }
#line 2554 "parser.tab.c"
    break;

  case 81: /* AdditiveExpression: MultiplicativeExpression  */
#line 599 "parser.y"
                                    {
        (yyval.ptr) = (yyvsp[0].ptr);
    }
#line 2562 "parser.tab.c"
    break;

  case 82: /* AdditiveExpression: AdditiveExpression ADDOP MultiplicativeExpression  */
#line 602 "parser.y"
                                                            {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-2].ptr));
        s.push_back(makeLeaf(*(yyvsp[-1].st)));
        s.push_back((yyvsp[0].ptr));
        delete (yyvsp[-1].st);
        
        
        (yyval.ptr) = makeNode("AdditiveExpression", s);
    }
#line 2577 "parser.tab.c"
    break;

  case 83: /* MultiplicativeExpression: UnaryExpression  */
#line 615 "parser.y"
                        {
        (yyval.ptr) = (yyvsp[0].ptr);      
    }
#line 2585 "parser.tab.c"
    break;

  case 84: /* MultiplicativeExpression: MultiplicativeExpression MULTOP UnaryExpression  */
#line 618 "parser.y"
                                                            {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-2].ptr));
        s.push_back(makeLeaf(*(yyvsp[-1].st)));
        s.push_back((yyvsp[0].ptr));
        delete (yyvsp[-1].st);
        
        
        (yyval.ptr) = makeNode("MultiplicativeExpression", s);
    }
#line 2600 "parser.tab.c"
    break;

  case 85: /* UnaryExpression: ADDOP2 UnaryExpression  */
#line 631 "parser.y"
                                {
        vector<ASTNode*> s;
        s.push_back(makeLeaf(*(yyvsp[-1].st)));
        s.push_back((yyvsp[0].ptr));
        delete (yyvsp[-1].st);
        
        (yyval.ptr) = makeNode("UnaryExpression", s);
    }
#line 2613 "parser.tab.c"
    break;

  case 86: /* UnaryExpression: ADDOP UnaryExpression  */
#line 639 "parser.y"
                                {
        vector<ASTNode*> s;
        s.push_back(makeLeaf(*(yyvsp[-1].st)));
        s.push_back((yyvsp[0].ptr));
        delete (yyvsp[-1].st);
        
        (yyval.ptr) = makeNode("UnaryExpression", s);
    }
#line 2626 "parser.tab.c"
    break;

  case 87: /* UnaryExpression: UnaryExpressionNotPlusMinus  */
#line 647 "parser.y"
                                    {
        (yyval.ptr) = (yyvsp[0].ptr);
    }
#line 2634 "parser.tab.c"
    break;

  case 88: /* UnaryExpression: CastExpression  */
#line 650 "parser.y"
                            {
        vector<ASTNode*> s;
        s.push_back((yyvsp[0].ptr));
        
        (yyval.ptr) = makeNode("UnaryExpression", s);
    }
#line 2645 "parser.tab.c"
    break;

  case 89: /* UnaryExpressionNotPlusMinus: PostfixExpression  */
#line 659 "parser.y"
                        {
        (yyval.ptr) = (yyvsp[0].ptr);
    }
#line 2653 "parser.tab.c"
    break;

  case 90: /* UnaryExpressionNotPlusMinus: UNARYOP UnaryExpression  */
#line 662 "parser.y"
                                {
        vector<ASTNode*> s;
        s.push_back(makeLeaf(*(yyvsp[-1].st)));
        s.push_back((yyvsp[0].ptr));
        delete (yyvsp[-1].st);
        
        (yyval.ptr) = makeNode("UnaryExpressionNotPlus", s);
    }
#line 2666 "parser.tab.c"
    break;

  case 91: /* CastExpression: '(' PrimitiveType ')' UnaryExpression  */
#line 673 "parser.y"
                                            {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-2].ptr));
        s.push_back((yyvsp[0].ptr));
        
        
        (yyval.ptr) = makeNode("CastExpression", s);
    }
#line 2679 "parser.tab.c"
    break;

  case 92: /* PostfixExpression: Primary  */
#line 684 "parser.y"
            {
        (yyval.ptr) = (yyvsp[0].ptr);
    }
#line 2687 "parser.tab.c"
    break;

  case 93: /* PostfixExpression: IDENdotIDEN  */
#line 687 "parser.y"
                        {
        (yyval.ptr) = (yyvsp[0].ptr);
    }
#line 2695 "parser.tab.c"
    break;

  case 94: /* PostfixExpression: PostfixExpression ADDOP2  */
#line 690 "parser.y"
                                    {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-1].ptr));
        s.push_back(makeLeaf(*(yyvsp[0].st)));
        delete (yyvsp[0].st);
        
        (yyval.ptr) = makeNode("PostfixExpression", s);
    }
#line 2708 "parser.tab.c"
    break;

  case 95: /* Block: '{' BlockStatements '}'  */
#line 704 "parser.y"
                            {
        (yyval.ptr)=(yyvsp[-1].ptr);
    }
#line 2716 "parser.tab.c"
    break;

  case 96: /* BlockStatements: BlockStatements BlockStatement  */
#line 710 "parser.y"
                                   {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-1].ptr));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode("BlockStatements", s);
    }
#line 2727 "parser.tab.c"
    break;

  case 97: /* BlockStatements: %empty  */
#line 716 "parser.y"
            {
        (yyval.ptr)=NULL;
    }
#line 2735 "parser.tab.c"
    break;

  case 98: /* BlockStatement: LocalVariableDeclaration ';'  */
#line 722 "parser.y"
                                 {
        (yyval.ptr)=(yyvsp[-1].ptr);
    }
#line 2743 "parser.tab.c"
    break;

  case 99: /* BlockStatement: Statement  */
#line 725 "parser.y"
                {
        (yyval.ptr)=(yyvsp[0].ptr);
    }
#line 2751 "parser.tab.c"
    break;

  case 100: /* LocalVariableDeclaration: LocalVariableType VariableDeclaratorList  */
#line 731 "parser.y"
                                             {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-1].ptr));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode("LocalVariableDeclaration", s);
    }
#line 2762 "parser.tab.c"
    break;

  case 101: /* LocalVariableType: Type  */
#line 740 "parser.y"
         {
        (yyval.ptr)=(yyvsp[0].ptr);
    }
#line 2770 "parser.tab.c"
    break;

  case 102: /* LocalVariableType: KEY_VAR  */
#line 743 "parser.y"
              {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("var"));
        (yyval.ptr) = makeNode("LocalVariableType", s);
    }
#line 2780 "parser.tab.c"
    break;

  case 103: /* Statement: StatementWithoutTrailingSubstatement  */
#line 751 "parser.y"
                                         {
        (yyval.ptr)=(yyvsp[0].ptr);
    }
#line 2788 "parser.tab.c"
    break;

  case 104: /* Statement: IDENTIFIER ':' Statement  */
#line 754 "parser.y"
                               {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("IDENTIFIER (" + *(yyvsp[-2].st)+")" ));
        delete (yyvsp[-2].st);
        s.push_back(makeLeaf(":"));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode("Statement", s);
    }
#line 2801 "parser.tab.c"
    break;

  case 105: /* Statement: KEY_if '(' Expression ')' Statement  */
#line 762 "parser.y"
                                          {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("if"));
        s.push_back((yyvsp[-2].ptr));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode("Statement", s);
    }
#line 2813 "parser.tab.c"
    break;

  case 106: /* Statement: KEY_if '(' Expression ')' StatementNoShortIf KEY_else Statement  */
#line 769 "parser.y"
                                                                      {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("if"));
        s.push_back((yyvsp[-4].ptr));
        s.push_back((yyvsp[-2].ptr));
        s.push_back(makeLeaf("else"));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode("Statement", s);
    }
#line 2827 "parser.tab.c"
    break;

  case 107: /* Statement: KEY_while '(' Expression ')' Statement  */
#line 778 "parser.y"
                                             {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("while"));
        s.push_back((yyvsp[-2].ptr));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode("Statement", s);
    }
#line 2839 "parser.tab.c"
    break;

  case 108: /* Statement: ForStatement  */
#line 785 "parser.y"
                   {
        (yyval.ptr)=(yyvsp[0].ptr);
    }
#line 2847 "parser.tab.c"
    break;

  case 109: /* StatementNoShortIf: StatementWithoutTrailingSubstatement  */
#line 791 "parser.y"
                                         {
        (yyval.ptr)=(yyvsp[0].ptr);
    }
#line 2855 "parser.tab.c"
    break;

  case 110: /* StatementNoShortIf: IDENTIFIER ':' StatementNoShortIf  */
#line 794 "parser.y"
                                        {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("IDENTIFIER (" + *(yyvsp[-2].st)+")" ));
        delete (yyvsp[-2].st);
        s.push_back(makeLeaf(":"));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode("StatementNoShortIf", s);
    }
#line 2868 "parser.tab.c"
    break;

  case 111: /* StatementNoShortIf: KEY_if '(' Expression ')' StatementNoShortIf KEY_else StatementNoShortIf  */
#line 802 "parser.y"
                                                                               {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("if"));
        s.push_back((yyvsp[-4].ptr));
        s.push_back((yyvsp[-2].ptr));
        s.push_back(makeLeaf("else"));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode("StatementNoShortIf", s);
    }
#line 2882 "parser.tab.c"
    break;

  case 112: /* StatementNoShortIf: KEY_while '(' Expression ')' StatementNoShortIf  */
#line 811 "parser.y"
                                                      {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("while"));
        s.push_back((yyvsp[-2].ptr));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode("StatementNoShortIf", s);
    }
#line 2894 "parser.tab.c"
    break;

  case 113: /* StatementNoShortIf: ForStatementNoShortIf  */
#line 818 "parser.y"
                            {
        (yyval.ptr)=(yyvsp[0].ptr);
    }
#line 2902 "parser.tab.c"
    break;

  case 114: /* StatementWithoutTrailingSubstatement: Block  */
#line 824 "parser.y"
            {
        (yyval.ptr)=(yyvsp[0].ptr);
    }
#line 2910 "parser.tab.c"
    break;

  case 115: /* StatementWithoutTrailingSubstatement: ';'  */
#line 827 "parser.y"
          {
        (yyval.ptr)=NULL;
    }
#line 2918 "parser.tab.c"
    break;

  case 116: /* StatementWithoutTrailingSubstatement: StatementExpression ';'  */
#line 830 "parser.y"
                              {
        (yyval.ptr)=(yyvsp[-1].ptr);
    }
#line 2926 "parser.tab.c"
    break;

  case 117: /* StatementWithoutTrailingSubstatement: AssertStatement  */
#line 833 "parser.y"
                      {
        (yyval.ptr)=(yyvsp[0].ptr);
    }
#line 2934 "parser.tab.c"
    break;

  case 118: /* StatementWithoutTrailingSubstatement: BreakContinueStatement  */
#line 836 "parser.y"
                             {
        (yyval.ptr)=(yyvsp[0].ptr);
    }
#line 2942 "parser.tab.c"
    break;

  case 119: /* StatementWithoutTrailingSubstatement: KEY_return ';'  */
#line 839 "parser.y"
                     {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("return"));
        (yyval.ptr) = makeNode("StatementWithoutTrailingSubstatement", s);
    }
#line 2952 "parser.tab.c"
    break;

  case 120: /* StatementWithoutTrailingSubstatement: KEY_return Expression ';'  */
#line 844 "parser.y"
                                {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("return"));
        s.push_back((yyvsp[-1].ptr));
        (yyval.ptr) = makeNode("StatementWithoutTrailingSubstatement", s);
    }
#line 2963 "parser.tab.c"
    break;

  case 121: /* StatementWithoutTrailingSubstatement: KEY_yield Expression ';'  */
#line 850 "parser.y"
                               {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("yield"));
        s.push_back((yyvsp[-1].ptr));
        (yyval.ptr) = makeNode("StatementWithoutTrailingSubstatement", s);
    }
#line 2974 "parser.tab.c"
    break;

  case 122: /* StatementWithoutTrailingSubstatement: KEY_throw Expression ';'  */
#line 856 "parser.y"
                               {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("throw"));
        s.push_back((yyvsp[-1].ptr));
        (yyval.ptr) = makeNode("StatementWithoutTrailingSubstatement", s);
    }
#line 2985 "parser.tab.c"
    break;

  case 123: /* StatementWithoutTrailingSubstatement: KEY_sync '(' Expression ')' Block  */
#line 862 "parser.y"
                                        {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("sync"));
        s.push_back((yyvsp[-2].ptr));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode("StatementWithoutTrailingSubstatement", s);
    }
#line 2997 "parser.tab.c"
    break;

  case 124: /* StatementExpression: Assignment  */
#line 872 "parser.y"
               {
        (yyval.ptr)=(yyvsp[0].ptr);
    }
#line 3005 "parser.tab.c"
    break;

  case 125: /* StatementExpression: MethodInvocation  */
#line 875 "parser.y"
                       {
        (yyval.ptr)=(yyvsp[0].ptr);
    }
#line 3013 "parser.tab.c"
    break;

  case 126: /* StatementExpression: ADDOP2 UnaryExpression  */
#line 878 "parser.y"
                             {
        vector<ASTNode*> s;
        s.push_back(makeLeaf(*(yyvsp[-1].st)));
        delete (yyvsp[-1].st);
        (yyval.ptr) = makeNode("StatementExpression", s);
    }
#line 3024 "parser.tab.c"
    break;

  case 127: /* StatementExpression: PostfixExpression ADDOP2  */
#line 884 "parser.y"
                               {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-1].ptr));
        s.push_back(makeLeaf(*(yyvsp[0].st)));
        delete (yyvsp[0].st);
        (yyval.ptr) = makeNode("StatementExpression", s);
    }
#line 3036 "parser.tab.c"
    break;

  case 128: /* LeftHandSide: IDENdotIDEN  */
#line 895 "parser.y"
                {
        (yyval.ptr)=(yyvsp[0].ptr);
    }
#line 3044 "parser.tab.c"
    break;

  case 129: /* LeftHandSide: FieldAccess  */
#line 898 "parser.y"
                  {
        (yyval.ptr)=(yyvsp[0].ptr);
    }
#line 3052 "parser.tab.c"
    break;

  case 130: /* LeftHandSide: ArrayAccess  */
#line 901 "parser.y"
                  {
        (yyval.ptr)=(yyvsp[0].ptr);
    }
#line 3060 "parser.tab.c"
    break;

  case 131: /* AssertStatement: KEY_assert Expression ';'  */
#line 907 "parser.y"
                              {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("assert"));
        s.push_back((yyvsp[-1].ptr));
        (yyval.ptr) = makeNode("AssertStatement", s);
    }
#line 3071 "parser.tab.c"
    break;

  case 132: /* AssertStatement: KEY_assert Expression ':' Expression ';'  */
#line 913 "parser.y"
                                               {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("assert"));
        s.push_back((yyvsp[-3].ptr));
        s.push_back(makeLeaf(":"));
        s.push_back((yyvsp[-1].ptr));
        (yyval.ptr) = makeNode("AssertStatement", s);
    }
#line 3084 "parser.tab.c"
    break;

  case 133: /* BreakContinueStatement: KEY_break IDENTIFIER ';'  */
#line 924 "parser.y"
                             {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("break"));
        s.push_back(makeLeaf("IDENTIFIER (" + *(yyvsp[-1].st)+")" ));
        delete (yyvsp[-1].st);
        (yyval.ptr) = makeNode("BreakContinueStatement", s);
    }
#line 3096 "parser.tab.c"
    break;

  case 134: /* BreakContinueStatement: KEY_break ';'  */
#line 931 "parser.y"
                    {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("break"));
        (yyval.ptr) = makeNode("BreakContinueStatement", s);
    }
#line 3106 "parser.tab.c"
    break;

  case 135: /* BreakContinueStatement: KEY_continue IDENTIFIER ';'  */
#line 936 "parser.y"
                                  {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("continue"));
        s.push_back(makeLeaf("IDENTIFIER (" + *(yyvsp[-1].st)+")" ));
        delete (yyvsp[-1].st);
        (yyval.ptr) = makeNode("BreakContinueStatement", s);
    }
#line 3118 "parser.tab.c"
    break;

  case 136: /* BreakContinueStatement: KEY_continue ';'  */
#line 943 "parser.y"
                       {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("continue"));
        (yyval.ptr) = makeNode("BreakContinueStatement", s);
    }
#line 3128 "parser.tab.c"
    break;

  case 137: /* ForStatement: KEY_for '(' ForInit ';' ';' ')' Statement  */
#line 951 "parser.y"
                                              {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("for"));
        s.push_back((yyvsp[-4].ptr));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode("ForStatement", s);
    }
#line 3140 "parser.tab.c"
    break;

  case 138: /* ForStatement: KEY_for '(' ForInit ';' Expression ';' ')' Statement  */
#line 958 "parser.y"
                                                           {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("for"));
        s.push_back((yyvsp[-5].ptr));
        s.push_back((yyvsp[-3].ptr));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode("ForStatement", s);
    }
#line 3153 "parser.tab.c"
    break;

  case 139: /* ForStatement: KEY_for '(' ForInit ';' ';' StatementExpressionList ')' Statement  */
#line 966 "parser.y"
                                                                        {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("for"));
        s.push_back((yyvsp[-5].ptr));
        s.push_back((yyvsp[-2].ptr));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode("ForStatement", s);
    }
#line 3166 "parser.tab.c"
    break;

  case 140: /* ForStatement: KEY_for '(' ForInit ';' Expression ';' StatementExpressionList ')' Statement  */
#line 974 "parser.y"
                                                                                   {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("for"));
        s.push_back((yyvsp[-6].ptr));
        s.push_back((yyvsp[-2].ptr));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode("ForStatement", s);
    }
#line 3179 "parser.tab.c"
    break;

  case 141: /* ForStatementNoShortIf: KEY_for '(' ForInit ';' ';' ')' StatementNoShortIf  */
#line 986 "parser.y"
                                                       {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("for"));
        s.push_back((yyvsp[-4].ptr));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode("ForStatementNoShortIf", s);
    }
#line 3191 "parser.tab.c"
    break;

  case 142: /* ForStatementNoShortIf: KEY_for '(' ForInit ';' Expression ';' ')' StatementNoShortIf  */
#line 993 "parser.y"
                                                                    {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("for"));
        s.push_back((yyvsp[-5].ptr));
        s.push_back((yyvsp[-3].ptr));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode("ForStatementNoShortIf", s);
    }
#line 3204 "parser.tab.c"
    break;

  case 143: /* ForStatementNoShortIf: KEY_for '(' ForInit ';' ';' StatementExpressionList ')' StatementNoShortIf  */
#line 1001 "parser.y"
                                                                                 {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("for"));
        s.push_back((yyvsp[-5].ptr));
        s.push_back((yyvsp[-2].ptr));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode("ForStatementNoShortIf", s);
    }
#line 3217 "parser.tab.c"
    break;

  case 144: /* ForStatementNoShortIf: KEY_for '(' ForInit ';' Expression ';' StatementExpressionList ')' StatementNoShortIf  */
#line 1009 "parser.y"
                                                                                            {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("for"));
        s.push_back((yyvsp[-6].ptr));
        s.push_back((yyvsp[-4].ptr));
        s.push_back((yyvsp[-2].ptr));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode("ForStatementNoShortIf", s);
    }
#line 3231 "parser.tab.c"
    break;

  case 145: /* ForInit: StatementExpressionList  */
#line 1022 "parser.y"
                            {
        vector<ASTNode*> s;
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode("ForInit", s);
    }
#line 3241 "parser.tab.c"
    break;

  case 146: /* ForInit: LocalVariableDeclaration  */
#line 1027 "parser.y"
                               {
        vector<ASTNode*> s;
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode("ForInit", s);
    }
#line 3251 "parser.tab.c"
    break;

  case 147: /* ForInit: %empty  */
#line 1032 "parser.y"
        {
        (yyval.ptr)=NULL;
    }
#line 3259 "parser.tab.c"
    break;

  case 148: /* StatementExpressionList: StatementExpressionList ',' StatementExpression  */
#line 1038 "parser.y"
                                                     {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-2].ptr));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode("StatementExpressionList", s);
    }
#line 3270 "parser.tab.c"
    break;

  case 149: /* StatementExpressionList: StatementExpression  */
#line 1044 "parser.y"
                          {
        (yyval.ptr)=(yyvsp[0].ptr);
    }
#line 3278 "parser.tab.c"
    break;

  case 150: /* ClassDeclaration: NormalClassDeclaration  */
#line 1072 "parser.y"
                           {
        (yyval.ptr)=(yyvsp[0].ptr);
    }
#line 3286 "parser.tab.c"
    break;

  case 151: /* NormalClassDeclaration: Modifiers KEY_class IDENTIFIER ClassBody  */
#line 1077 "parser.y"
                                             {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-3].ptr));
        s.push_back(makeLeaf("class"));
        s.push_back(makeLeaf("IDENTIFIER (" + *(yyvsp[-1].st)+")" ));
        delete (yyvsp[-1].st);
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode("NormalClassDeclaration", s);
    }
#line 3300 "parser.tab.c"
    break;

  case 152: /* NormalClassDeclaration: Modifiers KEY_class IDENTIFIER ClassExtends ClassBody  */
#line 1086 "parser.y"
                                                            {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-4].ptr));
        s.push_back(makeLeaf("class"));
        s.push_back(makeLeaf("IDENTIFIER (" + *(yyvsp[-2].st)+")" ));
        delete (yyvsp[-2].st) ;
        s.push_back((yyvsp[-1].ptr));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode("NormalClassDeclaration", s);
    }
#line 3315 "parser.tab.c"
    break;

  case 153: /* NormalClassDeclaration: Modifiers KEY_class IDENTIFIER ClassPermits ClassBody  */
#line 1096 "parser.y"
                                                            {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-4].ptr));
        s.push_back(makeLeaf("class"));
        s.push_back(makeLeaf("IDENTIFIER (" + *(yyvsp[-2].st)+")" ));
        delete (yyvsp[-2].st);
        s.push_back((yyvsp[-1].ptr));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode("NormalClassDeclaration", s);
    }
#line 3330 "parser.tab.c"
    break;

  case 154: /* NormalClassDeclaration: Modifiers KEY_class IDENTIFIER ClassExtends ClassPermits ClassBody  */
#line 1106 "parser.y"
                                                                         {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-5].ptr));
        s.push_back(makeLeaf("class"));
        s.push_back(makeLeaf("IDENTIFIER (" + *(yyvsp[-3].st)+")" ));
        delete (yyvsp[-3].st);
        s.push_back((yyvsp[-2].ptr));
        s.push_back((yyvsp[-1].ptr));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode("NormalClassDeclaration", s);
    }
#line 3346 "parser.tab.c"
    break;

  case 155: /* ClassExtends: KEY_extends ClassType  */
#line 1119 "parser.y"
                          {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("extends"));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode("ClassExtends", s);
    }
#line 3357 "parser.tab.c"
    break;

  case 156: /* ClassPermits: KEY_permits IDENdotIDEN cTypeName  */
#line 1127 "parser.y"
                                      {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("permits"));
        s.push_back((yyvsp[-1].ptr));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode("ClassPermits", s);
    }
#line 3369 "parser.tab.c"
    break;

  case 157: /* cTypeName: cTypeName ',' IDENdotIDEN  */
#line 1137 "parser.y"
                              {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-2].ptr));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode("cTypeName", s);
    }
#line 3380 "parser.tab.c"
    break;

  case 158: /* cTypeName: %empty  */
#line 1143 "parser.y"
        {
        (yyval.ptr)=NULL;
    }
#line 3388 "parser.tab.c"
    break;

  case 159: /* ClassBody: '{' ClassBodyDeclarations '}'  */
#line 1149 "parser.y"
                                  {
        (yyval.ptr)=(yyvsp[-1].ptr);
    }
#line 3396 "parser.tab.c"
    break;

  case 160: /* ClassBodyDeclarations: ClassBodyDeclarations ClassBodyDeclaration  */
#line 1154 "parser.y"
                                               {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-1].ptr));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode("ClassBodyDeclarations", s);
    }
#line 3407 "parser.tab.c"
    break;

  case 161: /* ClassBodyDeclarations: %empty  */
#line 1160 "parser.y"
        {
        (yyval.ptr)=NULL;
    }
#line 3415 "parser.tab.c"
    break;

  case 162: /* ClassBodyDeclaration: Modifiers Type VariableDeclaratorList ';'  */
#line 1165 "parser.y"
                                              {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-3].ptr));
        s.push_back((yyvsp[-2].ptr));
        s.push_back((yyvsp[-1].ptr));
        (yyval.ptr) = makeNode("ClassBodyDeclaration", s);
    }
#line 3427 "parser.tab.c"
    break;

  case 163: /* ClassBodyDeclaration: ClassDeclaration  */
#line 1172 "parser.y"
                       {
        (yyval.ptr)=(yyvsp[0].ptr);
    }
#line 3435 "parser.tab.c"
    break;

  case 164: /* ClassBodyDeclaration: ';'  */
#line 1175 "parser.y"
          {
        (yyval.ptr)=NULL;
    }
#line 3443 "parser.tab.c"
    break;

  case 165: /* ClassBodyDeclaration: Block  */
#line 1178 "parser.y"
            {
        (yyval.ptr)=(yyvsp[0].ptr);
    }
#line 3451 "parser.tab.c"
    break;

  case 166: /* ClassBodyDeclaration: Modifiers IdenPara Block  */
#line 1181 "parser.y"
                               {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-2].ptr));
        s.push_back((yyvsp[-1].ptr));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode("ClassBodyDeclaration", s);
    }
#line 3463 "parser.tab.c"
    break;

  case 167: /* ClassBodyDeclaration: MethodDeclaration  */
#line 1188 "parser.y"
                        {
        (yyval.ptr)=(yyvsp[0].ptr);
    }
#line 3471 "parser.tab.c"
    break;

  case 168: /* VariableDeclaratorList: VariableDeclaratorList ',' VariableDeclarator  */
#line 1194 "parser.y"
                                                  {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-2].ptr));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode("VariableDeclaratorList", s);
    }
#line 3482 "parser.tab.c"
    break;

  case 169: /* VariableDeclaratorList: VariableDeclarator  */
#line 1200 "parser.y"
                         {
        (yyval.ptr)=(yyvsp[0].ptr);
    }
#line 3490 "parser.tab.c"
    break;

  case 170: /* VariableDeclarator: VariableDeclarator1  */
#line 1206 "parser.y"
                        {
        (yyval.ptr)=(yyvsp[0].ptr);
    }
#line 3498 "parser.tab.c"
    break;

  case 171: /* VariableDeclarator: VariableDeclarator2  */
#line 1209 "parser.y"
                          {
        (yyval.ptr)=(yyvsp[0].ptr);
    }
#line 3506 "parser.tab.c"
    break;

  case 172: /* zerooroneExpression: Expression  */
#line 1215 "parser.y"
               {
        (yyval.ptr)=(yyvsp[0].ptr);
    }
#line 3514 "parser.tab.c"
    break;

  case 173: /* zerooroneExpression: %empty  */
#line 1218 "parser.y"
        {(yyval.ptr)=NULL;}
#line 3520 "parser.tab.c"
    break;

  case 174: /* VariableDeclarator1: IDENTIFIER  */
#line 1222 "parser.y"
               {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("IDENTIFIER (" + *(yyvsp[0].st) +")" ));
        delete (yyvsp[0].st);
        (yyval.ptr) = makeNode("VariableDeclarator1", s);
    }
#line 3531 "parser.tab.c"
    break;

  case 175: /* VariableDeclarator1: IDENTIFIER '[' zerooroneExpression ']'  */
#line 1228 "parser.y"
                                             {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("IDENTIFIER (" + *(yyvsp[-3].st) +")" ));
        delete (yyvsp[-3].st);
        s.push_back((yyvsp[-1].ptr));
        (yyval.ptr) = makeNode("VariableDeclarator1", s);
    }
#line 3543 "parser.tab.c"
    break;

  case 176: /* VariableDeclarator1: IDENTIFIER '[' zerooroneExpression ']' '[' zerooroneExpression ']'  */
#line 1235 "parser.y"
                                                                         {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("IDENTIFIER (" + *(yyvsp[-6].st) +")" ));
        delete (yyvsp[-6].st);
        s.push_back((yyvsp[-4].ptr));
        s.push_back((yyvsp[-1].ptr));
        (yyval.ptr) = makeNode("VariableDeclarator1", s);
    }
#line 3556 "parser.tab.c"
    break;

  case 177: /* VariableDeclarator1: IDENTIFIER '[' zerooroneExpression ']' '[' zerooroneExpression ']' '[' zerooroneExpression ']'  */
#line 1243 "parser.y"
                                                                                                     {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("IDENTIFIER (" + *(yyvsp[-9].st)+")" ));
        delete (yyvsp[-9].st);
        s.push_back((yyvsp[-7].ptr));
        s.push_back((yyvsp[-4].ptr));
        s.push_back((yyvsp[-1].ptr));
        (yyval.ptr) = makeNode("VariableDeclarator1", s);
    }
#line 3570 "parser.tab.c"
    break;

  case 178: /* VariableDeclarator2: IDENTIFIER '=' Expression  */
#line 1255 "parser.y"
                              {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("IDENTIFIER (" + *(yyvsp[-2].st)+")" ));
        delete (yyvsp[-2].st);
        s.push_back(makeLeaf("="));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode("VariableDeclarator2", s);
    }
#line 3583 "parser.tab.c"
    break;

  case 179: /* VariableDeclarator2: IDENTIFIER '[' zerooroneExpression ']' '=' List1  */
#line 1263 "parser.y"
                                                       {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("IDENTIFIER (" + *(yyvsp[-5].st)+")" ));
        delete (yyvsp[-5].st);
        s.push_back((yyvsp[-3].ptr));
        s.push_back(makeLeaf("="));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode("VariableDeclarator2", s);
    }
#line 3597 "parser.tab.c"
    break;

  case 180: /* VariableDeclarator2: IDENTIFIER '[' zerooroneExpression ']' '[' zerooroneExpression ']' '=' List2  */
#line 1272 "parser.y"
                                                                                   {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("IDENTIFIER (" + *(yyvsp[-8].st)+")" ));
        delete (yyvsp[-8].st);
        s.push_back((yyvsp[-6].ptr));
        s.push_back((yyvsp[-3].ptr));
        s.push_back(makeLeaf("="));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode("VariableDeclarator2", s);
    }
#line 3612 "parser.tab.c"
    break;

  case 181: /* VariableDeclarator2: IDENTIFIER '[' zerooroneExpression ']' '[' zerooroneExpression ']' '[' zerooroneExpression ']' '=' List3  */
#line 1282 "parser.y"
                                                                                                               {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("IDENTIFIER (" + *(yyvsp[-11].st)+")" ));
        delete (yyvsp[-11].st);
        s.push_back((yyvsp[-9].ptr));
        s.push_back((yyvsp[-6].ptr));
        s.push_back((yyvsp[-3].ptr));
        s.push_back(makeLeaf("="));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode("VariableDeclarator2", s);
    }
#line 3628 "parser.tab.c"
    break;

  case 182: /* List1: '{' ArrEle1 '}'  */
#line 1296 "parser.y"
                    {
        (yyval.ptr)=(yyvsp[-1].ptr);
    }
#line 3636 "parser.tab.c"
    break;

  case 183: /* ArrEle1: ArrEle1 ',' Expression  */
#line 1302 "parser.y"
                           {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-2].ptr));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode("ArrEle1", s);
    }
#line 3647 "parser.tab.c"
    break;

  case 184: /* ArrEle1: Expression  */
#line 1308 "parser.y"
                 {
       (yyval.ptr)=(yyvsp[0].ptr);
    }
#line 3655 "parser.tab.c"
    break;

  case 185: /* List2: '{' ArrEle2 '}'  */
#line 1314 "parser.y"
                    {
        (yyval.ptr)=(yyvsp[-1].ptr);
    }
#line 3663 "parser.tab.c"
    break;

  case 186: /* ArrEle2: ArrEle2 ',' List1  */
#line 1320 "parser.y"
                      {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-2].ptr));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode("ArrEle2", s);
    }
#line 3674 "parser.tab.c"
    break;

  case 187: /* ArrEle2: List1  */
#line 1326 "parser.y"
            {
        (yyval.ptr)=(yyvsp[0].ptr);
    }
#line 3682 "parser.tab.c"
    break;

  case 188: /* List3: '{' ArrEle3 '}'  */
#line 1332 "parser.y"
                    {
        (yyval.ptr)=(yyvsp[-1].ptr);
    }
#line 3690 "parser.tab.c"
    break;

  case 189: /* ArrEle3: ArrEle3 ',' List2  */
#line 1338 "parser.y"
                      {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-2].ptr));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode("ArrEle3", s);
    }
#line 3701 "parser.tab.c"
    break;

  case 190: /* ArrEle3: List2  */
#line 1344 "parser.y"
            {
        (yyval.ptr)=(yyvsp[0].ptr);
    }
#line 3709 "parser.tab.c"
    break;

  case 191: /* MethodDeclaration: Modifiers MethodHeader MethodBody  */
#line 1350 "parser.y"
                                      {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-2].ptr));
        s.push_back((yyvsp[-1].ptr));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode("MethodDeclaration", s);
    }
#line 3721 "parser.tab.c"
    break;

  case 192: /* MethodHeader: Type Methodeclarator  */
#line 1360 "parser.y"
                         {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-1].ptr));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode("MethodHeader", s);
    }
#line 3732 "parser.tab.c"
    break;

  case 193: /* MethodHeader: KEY_void Methodeclarator  */
#line 1366 "parser.y"
                               {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("void"));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode("MethodHeader", s);
    }
#line 3743 "parser.tab.c"
    break;

  case 194: /* Methodeclarator: IdenPara Dims  */
#line 1375 "parser.y"
                  {
        (yyval.ptr)=(yyvsp[-1].ptr);
    }
#line 3751 "parser.tab.c"
    break;

  case 195: /* Methodeclarator: IdenPara  */
#line 1378 "parser.y"
               {
        (yyval.ptr)=(yyvsp[0].ptr);
    }
#line 3759 "parser.tab.c"
    break;

  case 196: /* IdenPara: IDENTIFIER '(' formalparameters ')'  */
#line 1384 "parser.y"
                                        {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("IDENTIFIER (" + *(yyvsp[-3].st)+")" ));
        delete (yyvsp[-3].st);
        s.push_back((yyvsp[-1].ptr));
        (yyval.ptr) = makeNode("IdenPara", s);
    }
#line 3771 "parser.tab.c"
    break;

  case 197: /* IdenPara: IDENTIFIER '(' ')'  */
#line 1391 "parser.y"
                         {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("IDENTIFIER (" + *(yyvsp[-2].st)+")" ));
        delete (yyvsp[-2].st);
        (yyval.ptr) = makeNode("IdenPara", s);
    }
#line 3782 "parser.tab.c"
    break;

  case 198: /* formalparameters: formalparameters ',' formalparameter  */
#line 1399 "parser.y"
                                         {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-2].ptr));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode("formalparameters", s);
    }
#line 3793 "parser.tab.c"
    break;

  case 199: /* formalparameters: formalparameter  */
#line 1405 "parser.y"
                      {
        (yyval.ptr)=(yyvsp[0].ptr);
    }
#line 3801 "parser.tab.c"
    break;

  case 200: /* formalparameter: Type VariableDeclarator1  */
#line 1411 "parser.y"
                             {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-1].ptr));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode("formalparameter", s);
    }
#line 3812 "parser.tab.c"
    break;

  case 201: /* formalparameter: Type DOT3 IDENTIFIER  */
#line 1417 "parser.y"
                           {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-2].ptr));
        s.push_back(makeLeaf(*(yyvsp[-1].st)));
        delete (yyvsp[-1].st);
        s.push_back(makeLeaf("IDENTIFIER (" + *(yyvsp[0].st)+")" ));
        delete (yyvsp[0].st);
        (yyval.ptr) = makeNode("formalparameter", s);
    }
#line 3826 "parser.tab.c"
    break;

  case 202: /* MethodBody: Block  */
#line 1429 "parser.y"
          {
        (yyval.ptr)=(yyvsp[0].ptr);
    }
#line 3834 "parser.tab.c"
    break;

  case 203: /* MethodBody: ';'  */
#line 1432 "parser.y"
          {
        (yyval.ptr)=NULL;
    }
#line 3842 "parser.tab.c"
    break;

  case 204: /* Modifiers: Modifiers PublicPrivateStatic  */
#line 1438 "parser.y"
                                  {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-1].ptr));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode("Modifiers", s);
    }
#line 3853 "parser.tab.c"
    break;

  case 205: /* Modifiers: %empty  */
#line 1444 "parser.y"
        {(yyval.ptr)=NULL;}
#line 3859 "parser.tab.c"
    break;


#line 3863 "parser.tab.c"

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

#line 1448 "parser.y"


int main(){
    dotfile = fopen("graphtest.dot","w");
    beginAST();
    if(yyparse()) return 0;
    endAST();
    return 0;
}
