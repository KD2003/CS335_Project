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
#include <stdio.h>
#include <string>
#include <fstream>
using namespace std;

FILE* dotfile;
extern FILE* yyin;
extern int yyrestart(FILE*);

bool gotinputfile, gotoutputfile, verbosemode;

int yylex();
int yyerror(const char *str);


#line 89 "parser.tab.c"

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
  YYSYMBOL_45_ = 45,                       /* '*'  */
  YYSYMBOL_46_ = 46,                       /* '='  */
  YYSYMBOL_47_ = 47,                       /* ';'  */
  YYSYMBOL_48_ = 48,                       /* '.'  */
  YYSYMBOL_49_ = 49,                       /* '['  */
  YYSYMBOL_50_ = 50,                       /* ']'  */
  YYSYMBOL_51_ = 51,                       /* '('  */
  YYSYMBOL_52_ = 52,                       /* ')'  */
  YYSYMBOL_53_ = 53,                       /* ','  */
  YYSYMBOL_54_ = 54,                       /* '?'  */
  YYSYMBOL_55_ = 55,                       /* ':'  */
  YYSYMBOL_56_ = 56,                       /* '&'  */
  YYSYMBOL_57_ = 57,                       /* '^'  */
  YYSYMBOL_58_ = 58,                       /* '|'  */
  YYSYMBOL_59_ = 59,                       /* '{'  */
  YYSYMBOL_60_ = 60,                       /* '}'  */
  YYSYMBOL_YYACCEPT = 61,                  /* $accept  */
  YYSYMBOL_Start = 62,                     /* Start  */
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
#define YYLAST   827

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  61
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  83
/* YYNRULES -- Number of rules.  */
#define YYNRULES  212
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  425

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
      51,    52,    45,     2,    53,     2,    48,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    55,    47,
       2,    46,     2,    54,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    49,     2,    50,    57,     2,     2,     2,     2,     2,
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
       0,    39,    39,    48,    54,    60,    66,    72,    77,    83,
      89,    99,   102,   105,   111,   115,   119,   126,   133,   140,
     143,   146,   152,   157,   160,   165,   166,   175,   178,   184,
     188,   191,   197,   200,   203,   206,   209,   215,   222,   231,
     234,   240,   248,   254,   265,   271,   280,   288,   299,   310,
     322,   328,   334,   340,   346,   352,   361,   367,   375,   381,
     384,   390,   397,   406,   409,   421,   424,   433,   436,   445,
     448,   457,   460,   469,   472,   481,   484,   494,   497,   507,
     510,   520,   523,   533,   536,   543,   552,   558,   564,   567,
     573,   576,   585,   594,   597,   600,   613,   619,   625,   631,
     634,   640,   649,   652,   658,   661,   669,   675,   683,   689,
     695,   698,   706,   714,   720,   726,   729,   732,   735,   738,
     741,   744,   749,   754,   759,   768,   771,   774,   780,   791,
     794,   797,   803,   808,   818,   824,   827,   833,   839,   845,
     852,   859,   871,   877,   884,   891,   902,   905,   908,   914,
     920,   929,   934,   942,   951,   960,   972,   979,   988,   994,
    1000,  1005,  1011,  1016,  1023,  1026,  1029,  1032,  1039,  1045,
    1051,  1057,  1060,  1066,  1069,  1073,  1077,  1084,  1092,  1104,
    1111,  1119,  1128,  1138,  1149,  1162,  1177,  1187,  1199,  1216,
    1222,  1228,  1234,  1240,  1246,  1252,  1258,  1264,  1270,  1280,
    1286,  1294,  1297,  1303,  1310,  1318,  1324,  1330,  1336,  1348,
    1351,  1357,  1363
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
  "KEY_import", "'*'", "'='", "';'", "'.'", "'['", "']'", "'('", "')'",
  "','", "'?'", "':'", "'&'", "'^'", "'|'", "'{'", "'}'", "$accept",
  "Start", "ImportList", "ClassDeclarationList", "Imports", "Type",
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

#define YYPACT_NINF (-309)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-132)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -309,    23,    -7,  -309,    32,    54,  -309,  -309,  -309,   145,
    -309,    35,   152,  -309,    92,  -309,  -309,  -309,  -309,   191,
    -309,    13,    90,  -309,    20,  -309,    40,    35,    35,  -309,
     -16,    82,  -309,    89,  -309,   111,   111,  -309,   -19,    82,
    -309,  -309,  -309,   141,   154,  -309,  -309,  -309,  -309,  -309,
    -309,  -309,   491,  -309,    35,   577,   127,  -309,  -309,  -309,
     207,   213,   170,   170,  -309,   -13,   135,   111,   167,  -309,
     776,  -309,   776,   776,   776,     9,    12,   685,   173,   175,
     202,   204,   215,  -309,   188,  -309,   776,  -309,  -309,   107,
     224,   225,  -309,    34,    37,   138,  -309,  -309,   263,  -309,
    -309,   245,   272,  -309,  -309,   247,    69,  -309,  -309,  -309,
      11,   127,  -309,   170,   155,   136,  -309,  -309,  -309,  -309,
     255,   259,   259,  -309,  -309,  -309,  -309,   518,   776,   776,
     776,   660,   210,  -309,  -309,  -309,  -309,  -309,  -309,   296,
     203,   -17,  -309,  -309,  -309,    10,   304,   264,   265,   268,
     310,   314,   318,   313,     8,  -309,   287,   288,   291,  -309,
     293,  -309,  -309,   295,   776,   679,   776,   776,   339,   297,
     229,   299,    95,   776,   776,   341,   776,   331,  -309,    97,
     301,  -309,   776,   776,  -309,    25,   190,  -309,   259,   776,
     776,  -309,   272,  -309,   306,  -309,  -309,  -309,  -309,   305,
    -309,  -309,   776,   776,   776,   776,   776,   776,   776,   776,
     776,   776,   776,   776,   776,  -309,  -309,  -309,  -309,  -309,
     308,  -309,  -309,   320,   316,   319,   322,   325,   776,   321,
     776,   321,  -309,   329,  -309,   330,   336,   337,  -309,   340,
     332,  -309,  -309,   344,   390,  -309,  -309,   188,  -309,  -309,
     346,  -309,  -309,   776,   350,   304,   353,   268,   310,   264,
     265,   314,   318,   313,     8,  -309,  -309,   626,   708,   396,
     518,   135,   776,   349,   733,   259,   358,   259,   401,  -309,
    -309,   776,   776,  -309,   776,  -309,  -309,   125,  -309,  -309,
     776,   356,   364,   365,   366,  -309,   393,   394,  -309,    77,
     376,  -309,  -309,  -309,   378,  -309,   383,    82,   386,  -309,
     382,   388,    44,   776,  -309,   626,   776,   679,   776,   518,
     518,   195,    86,  -309,  -309,  -309,   776,  -309,   391,   280,
     776,  -309,   389,  -309,   392,   395,   397,  -309,  -309,   518,
     518,   230,   398,   776,   399,  -309,    -8,   159,   626,   742,
     626,  -309,  -309,   518,  -309,   402,   776,   776,  -309,    83,
     776,   413,   129,   404,  -309,  -309,   405,   407,  -309,   280,
     384,  -309,   408,   626,   626,   244,   205,   776,   384,   410,
    -309,   108,   400,  -309,  -309,   626,   626,   258,   411,  -309,
     776,   384,  -309,   104,  -309,  -309,   626,  -309,   414,  -309,
     280,   409,  -309,  -309,   417,   418,  -309,   117,   776,   776,
     409,  -309,   419,   420,  -309,   409,   424,  -309,   776,   425,
     427,   776,   439,   415,  -309
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,   212,     1,     0,   212,     3,     6,   151,     0,
      18,     0,     0,     5,     0,    19,    21,    20,   211,     0,
       7,     0,     0,     8,     0,    17,     0,     0,     0,   162,
       0,     0,   152,     0,     9,   159,    22,   156,   212,     0,
     153,   154,    10,     0,   157,   165,    98,   160,   166,   164,
     161,   168,     0,   155,     0,     0,    18,    14,    15,    16,
       0,     0,    11,    13,    12,     0,     0,   158,    18,    29,
       0,   103,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    30,     0,   116,     0,    96,   102,   129,
      93,    27,    33,    34,    35,    36,    28,   125,     0,   115,
      97,     0,     0,   100,   104,     0,     0,   118,   119,   109,
       0,     0,   200,   202,   175,     0,   170,   171,   172,   199,
       0,    23,    24,   210,   209,   198,   167,     0,     0,     0,
       0,     0,    94,    34,    35,    36,   127,    88,    89,    90,
      94,     0,    58,    60,    59,    63,    65,    71,    73,    67,
      69,    75,    77,    79,    81,    83,     0,     0,     0,   135,
       0,   137,   120,     0,     0,   148,     0,     0,     0,     0,
       0,     0,     0,     0,    40,     0,     0,   128,    99,   175,
     101,   117,     0,     0,   204,     0,     0,   206,   201,     0,
     174,   163,     0,    25,     0,   105,    87,    86,    91,     0,
      95,   132,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   122,   123,   134,   136,   121,
       0,   147,   150,     0,   146,     0,     0,    42,     0,    53,
      40,    55,    32,     0,    31,     0,     0,    39,    51,    41,
       0,    61,    62,   175,     0,   207,   203,     0,   179,   173,
       0,   169,    26,     0,     0,    66,     0,    68,    70,    72,
      74,    76,    78,    80,    82,    84,    85,     0,     0,     0,
       0,     0,    40,     0,     0,    52,     0,    54,     0,    44,
      46,     0,    40,    45,   174,   208,   205,   176,    92,   133,
       0,    18,     0,     0,     0,   106,     0,   104,   114,     0,
       0,   149,   108,   124,     0,    57,     0,    38,    43,    50,
       0,     0,     0,   174,    64,     0,     0,   148,     0,     0,
       0,     0,     0,    48,    56,    37,    40,    47,   176,     0,
       0,   180,     0,   111,     0,     0,     0,   107,   138,     0,
       0,     0,     0,   174,     0,   191,     0,   177,     0,     0,
       0,   140,   139,     0,    49,     0,   174,     0,   189,     0,
     174,     0,     0,     0,   113,   141,   177,     0,   190,     0,
       0,   181,     0,     0,     0,     0,     0,   174,   186,     0,
     194,     0,   178,   112,   142,     0,     0,     0,     0,   183,
     174,     0,   192,     0,   144,   143,     0,   178,     0,   193,
       0,     0,   182,   145,     0,     0,   197,     0,   174,   174,
       0,   195,     0,     0,   196,   187,     0,   184,   174,     0,
       0,   174,     0,   188,   185
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -309,  -309,  -309,  -309,  -309,   -44,   -83,    22,  -309,   432,
    -309,   -56,  -309,  -309,  -309,  -221,   274,   298,   -55,  -309,
    -309,   275,   289,  -309,   -49,   200,  -309,   294,   285,   286,
     309,   290,   307,   292,   302,   303,   -60,  -309,  -309,    33,
     -34,  -309,  -309,   463,  -309,    39,  -288,    45,  -160,  -309,
    -309,  -309,  -309,  -309,   208,  -287,    17,  -309,  -309,   490,
    -309,   -28,  -309,  -309,   422,   334,  -242,   348,  -309,  -251,
    -309,  -308,  -309,    98,  -309,  -309,  -309,   470,   483,  -309,
     312,  -309,   499
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,     2,     5,     6,    88,    62,   140,    18,    63,
      64,   121,    90,    91,    92,   236,    93,    94,   135,   237,
      96,   229,   249,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   137,   138,   139,
      99,    55,   100,   221,   102,   195,   296,   297,   105,   106,
     107,   108,   109,   298,   223,   224,     7,     8,    30,    31,
      44,    32,    38,    50,   115,   116,   250,   117,   118,   331,
     346,   371,   381,   402,   407,    51,    65,   112,   113,   186,
     187,   125,     9
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      95,   169,    40,    41,    48,   222,    97,   122,    61,   276,
     136,    53,   321,   158,    27,    10,   160,    25,    57,    58,
      59,   203,    13,     3,    25,   213,    12,   333,    45,   243,
     201,   124,   126,    19,   123,   341,    10,     4,   202,    10,
      46,    47,   311,    29,  -130,   357,    46,  -131,   199,    35,
      36,   304,   358,   214,    -2,    49,   159,   188,    26,   161,
     361,   310,   364,   184,   204,    33,   185,   244,   196,   197,
     198,   332,    95,    11,    36,   375,    67,    89,    97,   182,
    -130,    10,    69,  -131,   329,   383,   384,    34,    98,   387,
      10,    69,   132,   406,   103,    70,    22,   394,   395,    25,
     104,   355,   414,   330,    70,   342,   170,   417,   403,   301,
      95,   -22,    82,    83,   367,   183,    97,    84,   372,   380,
      27,    82,    83,   369,    28,   -94,    84,   389,    86,   320,
     233,   234,    36,    10,    69,   388,    42,    86,   340,   222,
     399,    29,   370,   189,   400,    25,   190,    70,   398,    29,
     132,   132,   132,   265,   266,   172,   173,   222,   174,    43,
      98,   391,   222,   401,    82,    83,   412,   413,   392,    84,
     410,   312,   104,   275,   313,   277,   419,   411,   110,   422,
      86,   374,    14,   191,    15,  -126,    16,    89,    17,   192,
    -126,  -126,    10,   288,    46,    57,    58,    59,    98,    20,
      21,   189,   222,   185,   190,   359,   110,    54,   360,    10,
      69,   111,    95,  -129,    95,    95,   222,   114,    97,   120,
      97,    97,   127,    70,   164,   132,   165,   132,   132,   132,
     132,   132,   132,   132,   132,   132,   132,   303,    23,    24,
      82,    83,   246,   247,    95,    84,   344,   339,   269,  -129,
      97,   172,   173,   166,   174,   167,    86,   386,   172,   173,
      95,   174,    95,   168,    95,    95,    97,    95,    97,    36,
      97,    97,   175,    97,   176,   132,   179,    43,   228,   325,
     230,   177,   353,   269,    95,    95,   379,    57,    58,    59,
      97,    97,   178,    95,   181,    95,   385,   269,    95,    97,
      98,    97,    98,    98,    97,   193,   295,    95,   194,   302,
     396,   269,   132,    97,   200,   104,   205,   405,    95,    95,
     206,    95,   207,   209,    97,    97,   208,    97,   210,   212,
      95,    95,    98,   211,   215,   216,    97,    97,   217,    89,
     218,    95,   219,   227,   133,   239,   228,    97,    98,   -95,
      98,   232,    98,    98,   192,    98,   252,   253,   337,   338,
     267,   141,   156,   157,   104,   104,   163,   268,   134,   269,
     274,   270,    98,    98,   271,   171,   272,   278,   351,   352,
     279,    98,   283,    98,   104,   104,    98,   295,   280,   302,
     281,   282,   365,   284,   285,    98,   287,   289,   104,   305,
      10,    69,   133,   133,   133,   308,    98,    98,   290,    98,
     307,   315,   337,   338,    70,   316,   317,   318,    98,    98,
     171,   319,  -110,   322,   351,   352,   134,   134,   134,    98,
     323,    82,    83,   324,   327,   365,    84,   326,   328,   347,
     343,   373,   349,   330,   348,   231,   393,    86,   356,   350,
     354,   376,   366,   220,   377,   225,   226,   378,   382,   390,
      37,   397,   235,   238,   404,   240,   408,   409,   370,   415,
     416,   241,   242,   418,   401,   420,   421,   133,   248,   133,
     133,   133,   133,   133,   133,   133,   133,   133,   133,   423,
     314,   254,   259,   256,   260,    56,   258,   255,    57,    58,
      59,   134,   262,   134,   134,   134,   134,   134,   134,   134,
     134,   134,   134,   263,   257,   264,   261,   273,   101,   238,
      39,   424,    68,    69,   180,   335,   251,   133,    14,    60,
      15,   119,    16,   245,    17,    66,    70,    52,     0,    72,
      73,    74,    75,    76,    77,    78,     0,    79,     0,    80,
      81,   134,     0,    82,    83,     0,     0,   300,    84,   286,
       0,   238,     0,   306,   133,    85,     0,     0,     0,    86,
     309,   238,     0,     0,     0,     0,     0,    46,     0,     0,
       0,    68,    69,     0,    57,    58,    59,     0,   134,     0,
       0,     0,     0,     0,     0,    70,     0,    71,    72,    73,
      74,    75,    76,    77,    78,   334,    79,   336,    80,    81,
       0,     0,    82,    83,     0,   238,     0,    84,     0,   345,
       0,     0,     0,     0,    85,     0,     0,     0,    86,     0,
     291,    69,     0,     0,     0,     0,    46,    87,   363,     0,
       0,     0,     0,     0,    70,     0,   368,    72,    73,    74,
      75,    76,    77,   292,     0,   293,     0,   294,    81,     0,
       0,    82,    83,     0,    10,    69,    84,    57,    58,    59,
       0,     0,     0,    85,     0,     0,   128,    86,   129,   130,
       0,     0,     0,    10,    69,    46,    57,    58,    59,    10,
      69,     0,     0,     0,     0,    82,    83,    70,     0,    71,
      84,   128,     0,   129,   130,     0,     0,     0,     0,     0,
       0,   131,    10,    69,    82,    83,     0,     0,     0,    84,
      82,    83,     0,     0,   128,    84,   129,   130,     0,     0,
      86,     0,   162,     0,     0,     0,   131,    10,    69,     0,
       0,     0,     0,    82,    83,     0,    10,    69,    84,   128,
       0,   129,   130,     0,     0,   299,     0,     0,   128,   131,
     129,   130,     0,     0,     0,     0,     0,     0,    82,    83,
       0,     0,     0,    84,     0,     0,     0,    82,    83,     0,
      10,    69,    84,   193,   131,     0,     0,     0,     0,   362,
       0,     0,   128,   131,   129,   130,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    82,    83,     0,     0,     0,    84,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   131
};

static const yytype_int16 yycheck[] =
{
      55,    84,    30,    31,    38,   165,    55,    63,    52,   230,
      70,    39,   299,     4,    30,     4,     4,     4,     7,     8,
       9,    11,     5,     0,     4,    17,     4,   315,    47,     4,
      47,    65,    66,    11,    47,   322,     4,    44,    55,     4,
      59,    60,   284,    59,    10,    53,    59,    10,   131,    27,
      28,   272,    60,    45,     0,    38,    47,   113,    45,    47,
     348,   282,   350,    52,    54,    45,   110,    42,   128,   129,
     130,   313,   127,    41,    52,   362,    54,    55,   127,    10,
      46,     4,     5,    46,    40,   373,   374,    47,    55,   376,
       4,     5,    70,   401,    55,    18,     4,   385,   386,     4,
      55,   343,   410,    59,    18,   326,    84,   415,   396,   269,
     165,     4,    35,    36,   356,    46,   165,    40,   360,   370,
      30,    35,    36,    40,    34,    18,    40,   378,    51,    52,
      35,    36,   110,     4,     5,   377,    47,    51,    52,   299,
     391,    59,    59,    46,    40,     4,    49,    18,   390,    59,
     128,   129,   130,   213,   214,    48,    49,   317,    51,    48,
     127,    53,   322,    59,    35,    36,   408,   409,    60,    40,
      53,    46,   127,   229,    49,   231,   418,    60,    51,   421,
      51,    52,    37,    47,    39,    47,    41,   165,    43,    53,
      52,    53,     4,   253,    59,     7,     8,     9,   165,    47,
      48,    46,   362,   247,    49,    46,    51,    53,    49,     4,
       5,     4,   267,    10,   269,   270,   376,     4,   267,    49,
     269,   270,    55,    18,    51,   203,    51,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   271,    47,    48,
      35,    36,    52,    53,   299,    40,   329,    52,    53,    46,
     299,    48,    49,    51,    51,    51,    51,    52,    48,    49,
     315,    51,   317,    48,   319,   320,   315,   322,   317,   247,
     319,   320,    48,   322,    49,   253,     4,    48,    49,   307,
      51,    18,    52,    53,   339,   340,   369,     7,     8,     9,
     339,   340,    47,   348,    47,   350,    52,    53,   353,   348,
     267,   350,   269,   270,   353,    50,   267,   362,    49,   270,
      52,    53,   290,   362,    18,   270,    12,   400,   373,   374,
      56,   376,    57,    13,   373,   374,    58,   376,    14,    16,
     385,   386,   299,    15,    47,    47,   385,   386,    47,   317,
      47,   396,    47,     4,    70,     4,    49,   396,   315,    18,
     317,    52,   319,   320,    53,   322,    50,    52,   319,   320,
      52,    72,    73,    74,   319,   320,    77,    47,    70,    53,
      49,    52,   339,   340,    52,    86,    51,    48,   339,   340,
      50,   348,    50,   350,   339,   340,   353,   348,    52,   350,
      53,    51,   353,    49,     4,   362,    50,    47,   353,    50,
       4,     5,   128,   129,   130,     4,   373,   374,    55,   376,
      52,    55,   373,   374,    18,    51,    51,    51,   385,   386,
     131,    28,    28,    47,   385,   386,   128,   129,   130,   396,
      52,    35,    36,    50,    52,   396,    40,    51,    50,    50,
      49,    28,    47,    59,    52,   170,    46,    51,    49,    52,
      52,    47,    50,   164,    49,   166,   167,    50,    50,    49,
      28,    50,   173,   174,    50,   176,    49,    49,    59,    50,
      50,   182,   183,    49,    59,    50,    49,   203,   189,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,    50,
     290,   202,   207,   204,   208,     4,   206,   203,     7,     8,
       9,   203,   210,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   211,   205,   212,   209,   228,    55,   230,
      30,   423,     4,     5,   102,   317,   192,   253,    37,    38,
      39,    61,    41,   185,    43,    52,    18,    38,    -1,    21,
      22,    23,    24,    25,    26,    27,    -1,    29,    -1,    31,
      32,   253,    -1,    35,    36,    -1,    -1,   268,    40,   247,
      -1,   272,    -1,   274,   290,    47,    -1,    -1,    -1,    51,
     281,   282,    -1,    -1,    -1,    -1,    -1,    59,    -1,    -1,
      -1,     4,     5,    -1,     7,     8,     9,    -1,   290,    -1,
      -1,    -1,    -1,    -1,    -1,    18,    -1,    20,    21,    22,
      23,    24,    25,    26,    27,   316,    29,   318,    31,    32,
      -1,    -1,    35,    36,    -1,   326,    -1,    40,    -1,   330,
      -1,    -1,    -1,    -1,    47,    -1,    -1,    -1,    51,    -1,
       4,     5,    -1,    -1,    -1,    -1,    59,    60,   349,    -1,
      -1,    -1,    -1,    -1,    18,    -1,   357,    21,    22,    23,
      24,    25,    26,    27,    -1,    29,    -1,    31,    32,    -1,
      -1,    35,    36,    -1,     4,     5,    40,     7,     8,     9,
      -1,    -1,    -1,    47,    -1,    -1,    16,    51,    18,    19,
      -1,    -1,    -1,     4,     5,    59,     7,     8,     9,     4,
       5,    -1,    -1,    -1,    -1,    35,    36,    18,    -1,    20,
      40,    16,    -1,    18,    19,    -1,    -1,    -1,    -1,    -1,
      -1,    51,     4,     5,    35,    36,    -1,    -1,    -1,    40,
      35,    36,    -1,    -1,    16,    40,    18,    19,    -1,    -1,
      51,    -1,    47,    -1,    -1,    -1,    51,     4,     5,    -1,
      -1,    -1,    -1,    35,    36,    -1,     4,     5,    40,    16,
      -1,    18,    19,    -1,    -1,    47,    -1,    -1,    16,    51,
      18,    19,    -1,    -1,    -1,    -1,    -1,    -1,    35,    36,
      -1,    -1,    -1,    40,    -1,    -1,    -1,    35,    36,    -1,
       4,     5,    40,    50,    51,    -1,    -1,    -1,    -1,    47,
      -1,    -1,    16,    51,    18,    19,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    35,    36,    -1,    -1,    -1,    40,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    51
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    62,    63,     0,    44,    64,    65,   117,   118,   143,
       4,    41,    68,   117,    37,    39,    41,    43,    69,    68,
      47,    48,     4,    47,    48,     4,    45,    30,    34,    59,
     119,   120,   122,    45,    47,    68,    68,    70,   123,   120,
     122,   122,    47,    48,   121,    47,    59,    60,   101,   117,
     124,   136,   143,   122,    53,   102,     4,     7,     8,     9,
      38,    66,    67,    70,    71,   137,   139,    68,     4,     5,
      18,    20,    21,    22,    23,    24,    25,    26,    27,    29,
      31,    32,    35,    36,    40,    47,    51,    60,    66,    68,
      73,    74,    75,    77,    78,    79,    81,    85,   100,   101,
     103,   104,   105,   106,   108,   109,   110,   111,   112,   113,
      51,     4,   138,   139,     4,   125,   126,   128,   129,   138,
      49,    72,    72,    47,   101,   142,   101,    55,    16,    18,
      19,    51,    68,    77,    78,    79,    97,    98,    99,   100,
      68,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    83,    83,     4,    47,
       4,    47,    47,    83,    51,    51,    51,    51,    48,    67,
      68,    83,    48,    49,    51,    48,    49,    18,    47,     4,
     125,    47,    10,    46,    52,    66,   140,   141,    72,    46,
      49,    47,    53,    50,    49,   106,    97,    97,    97,    67,
      18,    47,    55,    11,    54,    12,    56,    57,    58,    13,
      14,    15,    16,    17,    45,    47,    47,    47,    47,    47,
      83,   104,   109,   115,   116,    83,    83,     4,    49,    82,
      51,    82,    52,    35,    36,    83,    76,    80,    83,     4,
      83,    83,    83,     4,    42,   128,    52,    53,    83,    83,
     127,   126,    50,    52,    83,    88,    83,    91,    92,    89,
      90,    93,    94,    95,    96,    97,    97,    52,    47,    53,
      52,    52,    51,    83,    49,    72,    76,    72,    48,    50,
      52,    53,    51,    50,    49,     4,   141,    50,    97,    47,
      55,     4,    27,    29,    31,   106,   107,   108,   114,    47,
      83,   109,   106,   101,    76,    50,    83,    52,     4,    83,
      76,   127,    46,    49,    86,    55,    51,    51,    51,    28,
      52,   116,    47,    52,    50,   122,    51,    52,    50,    40,
      59,   130,   127,   107,    83,   115,    83,   106,   106,    52,
      52,   116,    76,    49,    67,    83,   131,    50,    52,    47,
      52,   106,   106,    52,    52,   127,    49,    53,    60,    46,
      49,   107,    47,    83,   107,   106,    50,   127,    83,    40,
      59,   132,   127,    28,    52,   116,    47,    49,    50,    67,
     130,   133,    50,   107,   107,    52,    52,   116,   127,   130,
      49,    53,    60,    46,   107,   107,    52,    50,   127,   130,
      40,    59,   134,   107,    50,    67,   132,   135,    49,    49,
      53,    60,   127,   127,   132,    50,    50,   132,    49,   127,
      50,    49,   127,    50,   134
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
      94,    95,    95,    96,    96,    96,    97,    97,    97,    97,
      98,    98,    99,   100,   100,   100,   101,   102,   102,   103,
     103,   104,   105,   105,   106,   106,   106,   106,   106,   106,
     107,   107,   107,   107,   107,   108,   108,   108,   108,   108,
     108,   108,   108,   108,   108,   109,   109,   109,   109,   110,
     110,   110,   111,   111,   112,   112,   112,   112,   113,   113,
     113,   113,   114,   114,   114,   114,   115,   115,   115,   116,
     116,   117,   118,   118,   118,   118,   119,   120,   121,   121,
     122,   123,   123,   124,   124,   124,   124,   124,   124,   125,
     125,   126,   126,   127,   127,   128,   128,   128,   128,   129,
     129,   129,   129,   129,   129,   129,   129,   129,   129,   130,
     131,   131,   132,   133,   133,   134,   135,   135,   136,   137,
     137,   138,   138,   139,   139,   140,   140,   141,   141,   142,
     142,   143,   143
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
       3,     1,     3,     1,     3,     3,     2,     2,     1,     1,
       1,     2,     4,     1,     1,     2,     3,     2,     0,     2,
       1,     2,     1,     1,     1,     3,     5,     7,     5,     1,
       1,     3,     7,     5,     1,     1,     1,     2,     1,     1,
       2,     3,     3,     3,     5,     1,     1,     2,     2,     1,
       1,     1,     3,     5,     3,     2,     3,     2,     7,     8,
       8,     9,     7,     8,     8,     9,     1,     1,     0,     3,
       1,     1,     4,     5,     5,     6,     2,     3,     3,     0,
       3,     2,     0,     4,     1,     1,     1,     3,     1,     3,
       1,     1,     1,     1,     0,     1,     4,     7,    10,     3,
       6,     9,    12,    11,    17,    23,    10,    16,    22,     3,
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
  case 2: /* Start: ImportList ClassDeclarationList  */
#line 39 "parser.y"
                                                {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-1].ptr));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode("Start", s);
        }
#line 1732 "parser.tab.c"
    break;

  case 3: /* ImportList: ImportList Imports  */
#line 48 "parser.y"
                        {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-1].ptr));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode("ImportList", s);
    }
#line 1743 "parser.tab.c"
    break;

  case 4: /* ImportList: %empty  */
#line 54 "parser.y"
        {
        (yyval.ptr)=NULL;
    }
#line 1751 "parser.tab.c"
    break;

  case 5: /* ClassDeclarationList: ClassDeclarationList ClassDeclaration  */
#line 60 "parser.y"
                                                {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-1].ptr));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode("ClassDeclarationList", s);
    }
#line 1762 "parser.tab.c"
    break;

  case 6: /* ClassDeclarationList: ClassDeclaration  */
#line 66 "parser.y"
                            {
        (yyval.ptr)=(yyvsp[0].ptr);
    }
#line 1770 "parser.tab.c"
    break;

  case 7: /* Imports: KEY_import IDENdotIDEN ';'  */
#line 72 "parser.y"
                                    {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-1].ptr));
        (yyval.ptr) = makeNode("import", s);
    }
#line 1780 "parser.tab.c"
    break;

  case 8: /* Imports: KEY_import KEY_static IDENdotIDEN ';'  */
#line 77 "parser.y"
                                                {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("static"));
        s.push_back((yyvsp[-1].ptr));
        (yyval.ptr) = makeNode("import", s);
    }
#line 1791 "parser.tab.c"
    break;

  case 9: /* Imports: KEY_import IDENdotIDEN '.' '*' ';'  */
#line 83 "parser.y"
                                                {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-3].ptr));
        s.push_back(makeLeaf("*"));
        (yyval.ptr) = makeNode("import", s);   
    }
#line 1802 "parser.tab.c"
    break;

  case 10: /* Imports: KEY_import KEY_static IDENdotIDEN '.' '*' ';'  */
#line 89 "parser.y"
                                                        {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("static"));
        s.push_back((yyvsp[-3].ptr));
        (yyval.ptr) = makeNode("import", s);
    }
#line 1813 "parser.tab.c"
    break;

  case 11: /* Type: PrimitiveType  */
#line 99 "parser.y"
                    {
        (yyval.ptr)=(yyvsp[0].ptr);
    }
#line 1821 "parser.tab.c"
    break;

  case 12: /* Type: ArrayType  */
#line 102 "parser.y"
                    {
        (yyval.ptr)=(yyvsp[0].ptr);
    }
#line 1829 "parser.tab.c"
    break;

  case 13: /* Type: ClassType  */
#line 105 "parser.y"
                    {
        (yyval.ptr)=(yyvsp[0].ptr);
    }
#line 1837 "parser.tab.c"
    break;

  case 14: /* PrimitiveType: INTTYPE  */
#line 111 "parser.y"
                {
        (yyval.ptr) = makeLeaf(*(yyvsp[0].st));
        delete (yyvsp[0].st);
    }
#line 1846 "parser.tab.c"
    break;

  case 15: /* PrimitiveType: FPTYPE  */
#line 115 "parser.y"
                   {
        (yyval.ptr) = makeLeaf(*(yyvsp[0].st));
        delete (yyvsp[0].st);
    }
#line 1855 "parser.tab.c"
    break;

  case 16: /* PrimitiveType: BOOLTYPE  */
#line 119 "parser.y"
                    {
        (yyval.ptr) = makeLeaf(*(yyvsp[0].st));
        delete (yyvsp[0].st);
    }
#line 1864 "parser.tab.c"
    break;

  case 17: /* IDENdotIDEN: IDENdotIDEN '.' IDENTIFIER  */
#line 126 "parser.y"
                                    {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-2].ptr));
        s.push_back(makeLeaf("ID (" + *(yyvsp[0].st) + ")"));
        delete (yyvsp[0].st);
        (yyval.ptr) = makeNode(".", s);
    }
#line 1876 "parser.tab.c"
    break;

  case 18: /* IDENdotIDEN: IDENTIFIER  */
#line 133 "parser.y"
                    {
        (yyval.ptr) = makeLeaf("ID (" + *(yyvsp[0].st) + ")");
        delete (yyvsp[0].st);
    }
#line 1885 "parser.tab.c"
    break;

  case 19: /* PublicPrivateStatic: KEY_public  */
#line 140 "parser.y"
                    {
        (yyval.ptr) = makeLeaf("public");
    }
#line 1893 "parser.tab.c"
    break;

  case 20: /* PublicPrivateStatic: KEY_private  */
#line 143 "parser.y"
                        {
        (yyval.ptr) = makeLeaf("private");
    }
#line 1901 "parser.tab.c"
    break;

  case 21: /* PublicPrivateStatic: KEY_static  */
#line 146 "parser.y"
                        {
        (yyval.ptr) = makeLeaf("static");
    }
#line 1909 "parser.tab.c"
    break;

  case 22: /* ClassType: IDENdotIDEN  */
#line 152 "parser.y"
                    {
        (yyval.ptr)=(yyvsp[0].ptr);
    }
#line 1917 "parser.tab.c"
    break;

  case 23: /* ArrayType: PrimitiveType Dims  */
#line 157 "parser.y"
                            {
        (yyval.ptr)=(yyvsp[-1].ptr);
    }
#line 1925 "parser.tab.c"
    break;

  case 24: /* ArrayType: ClassType Dims  */
#line 160 "parser.y"
                            {
        (yyval.ptr)=(yyvsp[-1].ptr);
    }
#line 1933 "parser.tab.c"
    break;

  case 25: /* Dims: '[' ']'  */
#line 165 "parser.y"
                {(yyval.ptr)=NULL;}
#line 1939 "parser.tab.c"
    break;

  case 26: /* Dims: Dims '[' ']'  */
#line 166 "parser.y"
                    {
        (yyval.ptr)=NULL;
    }
#line 1947 "parser.tab.c"
    break;

  case 27: /* Primary: PrimaryNoNewArray  */
#line 175 "parser.y"
                        {
        (yyval.ptr) = (yyvsp[0].ptr);
    }
#line 1955 "parser.tab.c"
    break;

  case 28: /* Primary: ArrayCreationExpression  */
#line 178 "parser.y"
                                    {
        (yyval.ptr) = (yyvsp[0].ptr);
    }
#line 1963 "parser.tab.c"
    break;

  case 29: /* PrimaryNoNewArray: LITERAL  */
#line 184 "parser.y"
                {
        (yyval.ptr) = makeLeaf("Literal");
    }
#line 1971 "parser.tab.c"
    break;

  case 30: /* PrimaryNoNewArray: KEY_this  */
#line 188 "parser.y"
                    {
        (yyval.ptr) = makeLeaf("this");
    }
#line 1979 "parser.tab.c"
    break;

  case 31: /* PrimaryNoNewArray: IDENdotIDEN '.' KEY_this  */
#line 191 "parser.y"
                                    {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-2].ptr));
        s.push_back(makeLeaf("this"));
        (yyval.ptr) = makeNode("PrimaryNoNewArray", s);
    }
#line 1990 "parser.tab.c"
    break;

  case 32: /* PrimaryNoNewArray: '(' Expression ')'  */
#line 197 "parser.y"
                                {
        (yyval.ptr) = (yyvsp[-1].ptr);
    }
#line 1998 "parser.tab.c"
    break;

  case 33: /* PrimaryNoNewArray: ClassInstanceCreationExpression  */
#line 200 "parser.y"
                                            {
        (yyval.ptr) = (yyvsp[0].ptr);
    }
#line 2006 "parser.tab.c"
    break;

  case 34: /* PrimaryNoNewArray: FieldAccess  */
#line 203 "parser.y"
                        {
        (yyval.ptr) = (yyvsp[0].ptr);
    }
#line 2014 "parser.tab.c"
    break;

  case 35: /* PrimaryNoNewArray: ArrayAccess  */
#line 206 "parser.y"
                        {
        (yyval.ptr) = (yyvsp[0].ptr);
    }
#line 2022 "parser.tab.c"
    break;

  case 36: /* PrimaryNoNewArray: MethodInvocation  */
#line 209 "parser.y"
                            {
        (yyval.ptr) = (yyvsp[0].ptr);
    }
#line 2030 "parser.tab.c"
    break;

  case 37: /* ClassInstanceCreationExpression: KEY_new IDENdotIDEN '(' Zeroorone_ArgumentList ')' ClassBody  */
#line 215 "parser.y"
                                                                        {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-4].ptr));
        s.push_back((yyvsp[-2].ptr));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode("new", s);
    }
#line 2042 "parser.tab.c"
    break;

  case 38: /* ClassInstanceCreationExpression: KEY_new IDENdotIDEN '(' Zeroorone_ArgumentList ')'  */
#line 222 "parser.y"
                                                                {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-3].ptr));
        s.push_back((yyvsp[-1].ptr));
        (yyval.ptr) = makeNode("new", s);
    }
#line 2053 "parser.tab.c"
    break;

  case 39: /* Zeroorone_ArgumentList: ArgumentList  */
#line 231 "parser.y"
                        {
        (yyval.ptr) = (yyvsp[0].ptr);
    }
#line 2061 "parser.tab.c"
    break;

  case 40: /* Zeroorone_ArgumentList: %empty  */
#line 234 "parser.y"
        {
        (yyval.ptr)=NULL;
    }
#line 2069 "parser.tab.c"
    break;

  case 41: /* FieldAccess: Primary '.' IDENTIFIER  */
#line 240 "parser.y"
                                {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-2].ptr));
        s.push_back(makeLeaf("ID (" + *(yyvsp[0].st) + ")"));
        delete (yyvsp[0].st);
        
        (yyval.ptr) = makeNode("FieldAccess", s);
    }
#line 2082 "parser.tab.c"
    break;

  case 42: /* FieldAccess: KEY_super '.' IDENTIFIER  */
#line 248 "parser.y"
                                    {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("ID (" + *(yyvsp[0].st) + ")"));
        delete (yyvsp[0].st);
        (yyval.ptr) = makeNode("super", s);
    }
#line 2093 "parser.tab.c"
    break;

  case 43: /* FieldAccess: IDENdotIDEN '.' KEY_super '.' IDENTIFIER  */
#line 254 "parser.y"
                                                    {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-4].ptr));
        s.push_back(makeLeaf("super"));
        s.push_back(makeLeaf("ID (" + *(yyvsp[0].st) + ")"));
        delete (yyvsp[0].st);
        (yyval.ptr) = makeNode("FieldAccess", s);
    }
#line 2106 "parser.tab.c"
    break;

  case 44: /* ArrayAccess: IDENdotIDEN '[' Expression ']'  */
#line 265 "parser.y"
                                        {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-3].ptr));
        s.push_back((yyvsp[-1].ptr));
        (yyval.ptr) = makeNode("ArrayAccess", s);
    }
#line 2117 "parser.tab.c"
    break;

  case 45: /* ArrayAccess: PrimaryNoNewArray '[' Expression ']'  */
#line 271 "parser.y"
                                                {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-3].ptr));
        s.push_back((yyvsp[-1].ptr));
        (yyval.ptr) = makeNode("ArrayAccess", s);
    }
#line 2128 "parser.tab.c"
    break;

  case 46: /* MethodInvocation: IDENdotIDEN '(' Zeroorone_ArgumentList ')'  */
#line 280 "parser.y"
                                                        {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-3].ptr));
        s.push_back((yyvsp[-1].ptr));
        
        
        (yyval.ptr) = makeNode("MethodInvocation", s);
    }
#line 2141 "parser.tab.c"
    break;

  case 47: /* MethodInvocation: Primary '.' IDENTIFIER '(' Zeroorone_ArgumentList ')'  */
#line 288 "parser.y"
                                                                {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-5].ptr));
        s.push_back(makeLeaf("ID (" + *(yyvsp[-3].st) + ")"));
        delete (yyvsp[-3].st);
        s.push_back((yyvsp[-1].ptr));
        
        
        
        (yyval.ptr) = makeNode("MethodInvocation", s);
    }
#line 2157 "parser.tab.c"
    break;

  case 48: /* MethodInvocation: KEY_super '.' IDENTIFIER '(' Zeroorone_ArgumentList ')'  */
#line 299 "parser.y"
                                                                    {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("super"));
        s.push_back(makeLeaf("ID (" + *(yyvsp[-3].st) + ")"));
        delete (yyvsp[-3].st);
        s.push_back((yyvsp[-1].ptr));
        
        
        
        (yyval.ptr) = makeNode("MethodInvocation", s);
    }
#line 2173 "parser.tab.c"
    break;

  case 49: /* MethodInvocation: IDENdotIDEN '.' KEY_super '.' IDENTIFIER '(' Zeroorone_ArgumentList ')'  */
#line 310 "parser.y"
                                                                                   {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-7].ptr));
        s.push_back(makeLeaf("super"));
        s.push_back(makeLeaf("ID (" + *(yyvsp[-3].st) + ")"));
        delete (yyvsp[-3].st);
        s.push_back((yyvsp[-1].ptr));
        (yyval.ptr) = makeNode("MethodInvocation", s);   
    }
#line 2187 "parser.tab.c"
    break;

  case 50: /* ArgumentList: ArgumentList ',' Expression  */
#line 322 "parser.y"
                                    {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-2].ptr));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode(",", s);
    }
#line 2198 "parser.tab.c"
    break;

  case 51: /* ArgumentList: Expression  */
#line 328 "parser.y"
                        {
        (yyval.ptr) = (yyvsp[0].ptr);
    }
#line 2206 "parser.tab.c"
    break;

  case 52: /* ArrayCreationExpression: KEY_new PrimitiveType DimExpr Dims  */
#line 334 "parser.y"
                                            {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-2].ptr));
        s.push_back((yyvsp[-1].ptr));
        (yyval.ptr) = makeNode("new", s);
    }
#line 2217 "parser.tab.c"
    break;

  case 53: /* ArrayCreationExpression: KEY_new PrimitiveType DimExpr  */
#line 340 "parser.y"
                                        {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-1].ptr));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode("new", s);
    }
#line 2228 "parser.tab.c"
    break;

  case 54: /* ArrayCreationExpression: KEY_new IDENdotIDEN DimExpr Dims  */
#line 346 "parser.y"
                                            {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-2].ptr));
        s.push_back((yyvsp[-1].ptr));
        (yyval.ptr) = makeNode("new", s);
    }
#line 2239 "parser.tab.c"
    break;

  case 55: /* ArrayCreationExpression: KEY_new IDENdotIDEN DimExpr  */
#line 352 "parser.y"
                                        {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-1].ptr));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode("new", s);
    }
#line 2250 "parser.tab.c"
    break;

  case 56: /* DimExpr: DimExpr '[' Expression ']'  */
#line 361 "parser.y"
                                {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-3].ptr));
        s.push_back((yyvsp[-1].ptr));
        (yyval.ptr) = makeNode("DimExpr", s);
    }
#line 2261 "parser.tab.c"
    break;

  case 57: /* DimExpr: '[' Expression ']'  */
#line 367 "parser.y"
                                {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-1].ptr));
        (yyval.ptr) = makeNode("DimExpr", s);
    }
#line 2271 "parser.tab.c"
    break;

  case 58: /* Expression: AssignmentExpression  */
#line 375 "parser.y"
                            {
        (yyval.ptr) = (yyvsp[0].ptr);
    }
#line 2279 "parser.tab.c"
    break;

  case 59: /* AssignmentExpression: ConditionalExpression  */
#line 381 "parser.y"
                                {
        (yyval.ptr) = (yyvsp[0].ptr);
    }
#line 2287 "parser.tab.c"
    break;

  case 60: /* AssignmentExpression: Assignment  */
#line 384 "parser.y"
                        {
        (yyval.ptr) = (yyvsp[0].ptr);
    }
#line 2295 "parser.tab.c"
    break;

  case 61: /* Assignment: LeftHandSide ASSIGNOP Expression  */
#line 390 "parser.y"
                                            {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-2].ptr));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode(*(yyvsp[-1].st), s);
        delete (yyvsp[-1].st);
    }
#line 2307 "parser.tab.c"
    break;

  case 62: /* Assignment: LeftHandSide '=' Expression  */
#line 397 "parser.y"
                                        {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-2].ptr));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode("=", s);
    }
#line 2318 "parser.tab.c"
    break;

  case 63: /* ConditionalExpression: ConditionalOrExpression  */
#line 406 "parser.y"
                                {
        (yyval.ptr) = (yyvsp[0].ptr);
    }
#line 2326 "parser.tab.c"
    break;

  case 64: /* ConditionalExpression: ConditionalOrExpression '?' Expression ':' ConditionalExpression  */
#line 409 "parser.y"
                                                                            {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-4].ptr));
        s.push_back(makeLeaf("?"));
        s.push_back((yyvsp[-2].ptr));
        s.push_back(makeLeaf(":"));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode("ConditionalExpression", s);
    }
#line 2340 "parser.tab.c"
    break;

  case 65: /* ConditionalOrExpression: ConditionalAndExpression  */
#line 421 "parser.y"
                                    {
        (yyval.ptr) = (yyvsp[0].ptr);
    }
#line 2348 "parser.tab.c"
    break;

  case 66: /* ConditionalOrExpression: ConditionalOrExpression CONDOR ConditionalAndExpression  */
#line 424 "parser.y"
                                                                    {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-2].ptr));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode("||", s);
    }
#line 2359 "parser.tab.c"
    break;

  case 67: /* ConditionalAndExpression: InclusiveOrExpression  */
#line 433 "parser.y"
                            {
        (yyval.ptr) = (yyvsp[0].ptr);
    }
#line 2367 "parser.tab.c"
    break;

  case 68: /* ConditionalAndExpression: ConditionalAndExpression CONDAND InclusiveOrExpression  */
#line 436 "parser.y"
                                                                    {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-2].ptr));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode("&&", s);
    }
#line 2378 "parser.tab.c"
    break;

  case 69: /* AndExpression: EqualityExpression  */
#line 445 "parser.y"
                            {
        (yyval.ptr) = (yyvsp[0].ptr);
    }
#line 2386 "parser.tab.c"
    break;

  case 70: /* AndExpression: AndExpression '&' EqualityExpression  */
#line 448 "parser.y"
                                                {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-2].ptr));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode("&", s);
    }
#line 2397 "parser.tab.c"
    break;

  case 71: /* ExclusiveOrExpression: AndExpression  */
#line 457 "parser.y"
                        {
        (yyval.ptr) = (yyvsp[0].ptr);
    }
#line 2405 "parser.tab.c"
    break;

  case 72: /* ExclusiveOrExpression: ExclusiveOrExpression '^' AndExpression  */
#line 460 "parser.y"
                                                    {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-2].ptr));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode("^", s);
    }
#line 2416 "parser.tab.c"
    break;

  case 73: /* InclusiveOrExpression: ExclusiveOrExpression  */
#line 469 "parser.y"
                                {
        (yyval.ptr) = (yyvsp[0].ptr);
    }
#line 2424 "parser.tab.c"
    break;

  case 74: /* InclusiveOrExpression: InclusiveOrExpression '|' ExclusiveOrExpression  */
#line 472 "parser.y"
                                                            {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-2].ptr));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode("|", s);
    }
#line 2435 "parser.tab.c"
    break;

  case 75: /* EqualityExpression: RelationalExpression  */
#line 481 "parser.y"
                            {
        (yyval.ptr) = (yyvsp[0].ptr);
    }
#line 2443 "parser.tab.c"
    break;

  case 76: /* EqualityExpression: EqualityExpression EQALITYOP RelationalExpression  */
#line 484 "parser.y"
                                                        {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-2].ptr));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode(*(yyvsp[-1].st), s);
        delete (yyvsp[-1].st);
    }
#line 2455 "parser.tab.c"
    break;

  case 77: /* RelationalExpression: ShiftExpression  */
#line 494 "parser.y"
                        {
        (yyval.ptr) = (yyvsp[0].ptr);
    }
#line 2463 "parser.tab.c"
    break;

  case 78: /* RelationalExpression: RelationalExpression RELATIONOP ShiftExpression  */
#line 497 "parser.y"
                                                            {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-2].ptr));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode(*(yyvsp[-1].st), s);
        delete (yyvsp[-1].st);
    }
#line 2475 "parser.tab.c"
    break;

  case 79: /* ShiftExpression: AdditiveExpression  */
#line 507 "parser.y"
                            {
        (yyval.ptr) = (yyvsp[0].ptr);
    }
#line 2483 "parser.tab.c"
    break;

  case 80: /* ShiftExpression: ShiftExpression SHIFTOP AdditiveExpression  */
#line 510 "parser.y"
                                                    {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-2].ptr));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode(*(yyvsp[-1].st), s);
        delete (yyvsp[-1].st);
    }
#line 2495 "parser.tab.c"
    break;

  case 81: /* AdditiveExpression: MultiplicativeExpression  */
#line 520 "parser.y"
                                    {
        (yyval.ptr) = (yyvsp[0].ptr);
    }
#line 2503 "parser.tab.c"
    break;

  case 82: /* AdditiveExpression: AdditiveExpression ADDOP MultiplicativeExpression  */
#line 523 "parser.y"
                                                            {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-2].ptr));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode(*(yyvsp[-1].st), s);
        delete (yyvsp[-1].st);
    }
#line 2515 "parser.tab.c"
    break;

  case 83: /* MultiplicativeExpression: UnaryExpression  */
#line 533 "parser.y"
                        {
        (yyval.ptr) = (yyvsp[0].ptr);      
    }
#line 2523 "parser.tab.c"
    break;

  case 84: /* MultiplicativeExpression: MultiplicativeExpression MULTOP UnaryExpression  */
#line 536 "parser.y"
                                                            {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-2].ptr));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode(*(yyvsp[-1].st), s);
        delete (yyvsp[-1].st);
    }
#line 2535 "parser.tab.c"
    break;

  case 85: /* MultiplicativeExpression: MultiplicativeExpression '*' UnaryExpression  */
#line 543 "parser.y"
                                                         {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-2].ptr));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode("*", s);
    }
#line 2546 "parser.tab.c"
    break;

  case 86: /* UnaryExpression: ADDOP2 UnaryExpression  */
#line 552 "parser.y"
                                {
        vector<ASTNode*> s;
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode(*(yyvsp[-1].st), s);
        delete (yyvsp[-1].st);
    }
#line 2557 "parser.tab.c"
    break;

  case 87: /* UnaryExpression: ADDOP UnaryExpression  */
#line 558 "parser.y"
                                {
        vector<ASTNode*> s;
        s.push_back((yyvsp[0].ptr));        
        (yyval.ptr) = makeNode(*(yyvsp[-1].st), s);
        delete (yyvsp[-1].st);
    }
#line 2568 "parser.tab.c"
    break;

  case 88: /* UnaryExpression: UnaryExpressionNotPlusMinus  */
#line 564 "parser.y"
                                    {
        (yyval.ptr) = (yyvsp[0].ptr);
    }
#line 2576 "parser.tab.c"
    break;

  case 89: /* UnaryExpression: CastExpression  */
#line 567 "parser.y"
                            {
        (yyval.ptr)=(yyvsp[0].ptr);
    }
#line 2584 "parser.tab.c"
    break;

  case 90: /* UnaryExpressionNotPlusMinus: PostfixExpression  */
#line 573 "parser.y"
                        {
        (yyval.ptr) = (yyvsp[0].ptr);
    }
#line 2592 "parser.tab.c"
    break;

  case 91: /* UnaryExpressionNotPlusMinus: UNARYOP UnaryExpression  */
#line 576 "parser.y"
                                {
        vector<ASTNode*> s;
        s.push_back((yyvsp[0].ptr));        
        (yyval.ptr) = makeNode(*(yyvsp[-1].st), s);
        delete (yyvsp[-1].st);
    }
#line 2603 "parser.tab.c"
    break;

  case 92: /* CastExpression: '(' PrimitiveType ')' UnaryExpression  */
#line 585 "parser.y"
                                            {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-2].ptr));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode("CastExpression", s);
    }
#line 2614 "parser.tab.c"
    break;

  case 93: /* PostfixExpression: Primary  */
#line 594 "parser.y"
            {
        (yyval.ptr) = (yyvsp[0].ptr);
    }
#line 2622 "parser.tab.c"
    break;

  case 94: /* PostfixExpression: IDENdotIDEN  */
#line 597 "parser.y"
                        {
        (yyval.ptr) = (yyvsp[0].ptr);
    }
#line 2630 "parser.tab.c"
    break;

  case 95: /* PostfixExpression: PostfixExpression ADDOP2  */
#line 600 "parser.y"
                                    {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-1].ptr));
        s.push_back(makeLeaf(*(yyvsp[0].st)));
        (yyval.ptr) = makeNode("Postfix Expression", s);
        delete (yyvsp[0].st);
    }
#line 2642 "parser.tab.c"
    break;

  case 96: /* Block: '{' BlockStatements '}'  */
#line 613 "parser.y"
                            {
        (yyval.ptr)=(yyvsp[-1].ptr);
    }
#line 2650 "parser.tab.c"
    break;

  case 97: /* BlockStatements: BlockStatements BlockStatement  */
#line 619 "parser.y"
                                   {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-1].ptr));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode("BlockStatements", s);
    }
#line 2661 "parser.tab.c"
    break;

  case 98: /* BlockStatements: %empty  */
#line 625 "parser.y"
            {
        (yyval.ptr)=NULL;
    }
#line 2669 "parser.tab.c"
    break;

  case 99: /* BlockStatement: LocalVariableDeclaration ';'  */
#line 631 "parser.y"
                                 {
        (yyval.ptr)=(yyvsp[-1].ptr);
    }
#line 2677 "parser.tab.c"
    break;

  case 100: /* BlockStatement: Statement  */
#line 634 "parser.y"
                {
        (yyval.ptr)=(yyvsp[0].ptr);
    }
#line 2685 "parser.tab.c"
    break;

  case 101: /* LocalVariableDeclaration: LocalVariableType VariableDeclaratorList  */
#line 640 "parser.y"
                                             {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-1].ptr));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode("LocalVariableDeclaration", s);
    }
#line 2696 "parser.tab.c"
    break;

  case 102: /* LocalVariableType: Type  */
#line 649 "parser.y"
         {
        (yyval.ptr)=(yyvsp[0].ptr);
    }
#line 2704 "parser.tab.c"
    break;

  case 103: /* LocalVariableType: KEY_VAR  */
#line 652 "parser.y"
              {
        (yyval.ptr) = makeLeaf("var");
    }
#line 2712 "parser.tab.c"
    break;

  case 104: /* Statement: StatementWithoutTrailingSubstatement  */
#line 658 "parser.y"
                                         {
        (yyval.ptr)=(yyvsp[0].ptr);
    }
#line 2720 "parser.tab.c"
    break;

  case 105: /* Statement: IDENTIFIER ':' Statement  */
#line 661 "parser.y"
                               {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("ID (" + *(yyvsp[-2].st)+")" ));
        s.push_back(makeLeaf(":"));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode("Statement", s);
        delete (yyvsp[-2].st);
    }
#line 2733 "parser.tab.c"
    break;

  case 106: /* Statement: KEY_if '(' Expression ')' Statement  */
#line 669 "parser.y"
                                          {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-2].ptr));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode("if", s);
    }
#line 2744 "parser.tab.c"
    break;

  case 107: /* Statement: KEY_if '(' Expression ')' StatementNoShortIf KEY_else Statement  */
#line 675 "parser.y"
                                                                      {
        vector<ASTNode*> s,s1;
        s1.push_back((yyvsp[0].ptr));
        s.push_back((yyvsp[-4].ptr));
        s.push_back((yyvsp[-2].ptr));
        s.push_back(makeNode("else", s1));
        (yyval.ptr) = makeNode("if", s);
    }
#line 2757 "parser.tab.c"
    break;

  case 108: /* Statement: KEY_while '(' Expression ')' Statement  */
#line 683 "parser.y"
                                             {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-2].ptr));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode("while", s);
    }
#line 2768 "parser.tab.c"
    break;

  case 109: /* Statement: ForStatement  */
#line 689 "parser.y"
                   {
        (yyval.ptr)=(yyvsp[0].ptr);
    }
#line 2776 "parser.tab.c"
    break;

  case 110: /* StatementNoShortIf: StatementWithoutTrailingSubstatement  */
#line 695 "parser.y"
                                         {
        (yyval.ptr)=(yyvsp[0].ptr);
    }
#line 2784 "parser.tab.c"
    break;

  case 111: /* StatementNoShortIf: IDENTIFIER ':' StatementNoShortIf  */
#line 698 "parser.y"
                                        {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("ID (" + *(yyvsp[-2].st)+")" ));
        delete (yyvsp[-2].st);
        s.push_back(makeLeaf(":"));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode("StatementNoShortIf", s);
    }
#line 2797 "parser.tab.c"
    break;

  case 112: /* StatementNoShortIf: KEY_if '(' Expression ')' StatementNoShortIf KEY_else StatementNoShortIf  */
#line 706 "parser.y"
                                                                               {
        vector<ASTNode*> s,s1;
        s1.push_back((yyvsp[0].ptr));
        s.push_back((yyvsp[-4].ptr));
        s.push_back((yyvsp[-2].ptr));
        s.push_back(makeNode("else", s1));
        (yyval.ptr) = makeNode("if", s);
    }
#line 2810 "parser.tab.c"
    break;

  case 113: /* StatementNoShortIf: KEY_while '(' Expression ')' StatementNoShortIf  */
#line 714 "parser.y"
                                                      {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-2].ptr));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode("while", s);
    }
#line 2821 "parser.tab.c"
    break;

  case 114: /* StatementNoShortIf: ForStatementNoShortIf  */
#line 720 "parser.y"
                            {
        (yyval.ptr)=(yyvsp[0].ptr);
    }
#line 2829 "parser.tab.c"
    break;

  case 115: /* StatementWithoutTrailingSubstatement: Block  */
#line 726 "parser.y"
            {
        (yyval.ptr)=(yyvsp[0].ptr);
    }
#line 2837 "parser.tab.c"
    break;

  case 116: /* StatementWithoutTrailingSubstatement: ';'  */
#line 729 "parser.y"
          {
        (yyval.ptr)=NULL;
    }
#line 2845 "parser.tab.c"
    break;

  case 117: /* StatementWithoutTrailingSubstatement: StatementExpression ';'  */
#line 732 "parser.y"
                              {
        (yyval.ptr)=(yyvsp[-1].ptr);
    }
#line 2853 "parser.tab.c"
    break;

  case 118: /* StatementWithoutTrailingSubstatement: AssertStatement  */
#line 735 "parser.y"
                      {
        (yyval.ptr)=(yyvsp[0].ptr);
    }
#line 2861 "parser.tab.c"
    break;

  case 119: /* StatementWithoutTrailingSubstatement: BreakContinueStatement  */
#line 738 "parser.y"
                             {
        (yyval.ptr)=(yyvsp[0].ptr);
    }
#line 2869 "parser.tab.c"
    break;

  case 120: /* StatementWithoutTrailingSubstatement: KEY_return ';'  */
#line 741 "parser.y"
                     {
        (yyval.ptr) = makeLeaf("return");
    }
#line 2877 "parser.tab.c"
    break;

  case 121: /* StatementWithoutTrailingSubstatement: KEY_return Expression ';'  */
#line 744 "parser.y"
                                {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-1].ptr));
        (yyval.ptr) = makeNode("return", s);
    }
#line 2887 "parser.tab.c"
    break;

  case 122: /* StatementWithoutTrailingSubstatement: KEY_yield Expression ';'  */
#line 749 "parser.y"
                               {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-1].ptr));
        (yyval.ptr) = makeNode("yield", s);
    }
#line 2897 "parser.tab.c"
    break;

  case 123: /* StatementWithoutTrailingSubstatement: KEY_throw Expression ';'  */
#line 754 "parser.y"
                               {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-1].ptr));
        (yyval.ptr) = makeNode("throw", s);
    }
#line 2907 "parser.tab.c"
    break;

  case 124: /* StatementWithoutTrailingSubstatement: KEY_sync '(' Expression ')' Block  */
#line 759 "parser.y"
                                        {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-2].ptr));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode("sync", s);
    }
#line 2918 "parser.tab.c"
    break;

  case 125: /* StatementExpression: Assignment  */
#line 768 "parser.y"
               {
        (yyval.ptr)=(yyvsp[0].ptr);
    }
#line 2926 "parser.tab.c"
    break;

  case 126: /* StatementExpression: MethodInvocation  */
#line 771 "parser.y"
                       {
        (yyval.ptr)=(yyvsp[0].ptr);
    }
#line 2934 "parser.tab.c"
    break;

  case 127: /* StatementExpression: ADDOP2 UnaryExpression  */
#line 774 "parser.y"
                             {
        vector<ASTNode*> s;
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode(*(yyvsp[-1].st), s);
        delete (yyvsp[-1].st);
    }
#line 2945 "parser.tab.c"
    break;

  case 128: /* StatementExpression: PostfixExpression ADDOP2  */
#line 780 "parser.y"
                               {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-1].ptr));
        s.push_back(makeLeaf(*(yyvsp[0].st)));
        delete (yyvsp[0].st);
        (yyval.ptr) = makeNode("Statement Expression", s);
    }
#line 2957 "parser.tab.c"
    break;

  case 129: /* LeftHandSide: IDENdotIDEN  */
#line 791 "parser.y"
                {
        (yyval.ptr)=(yyvsp[0].ptr);
    }
#line 2965 "parser.tab.c"
    break;

  case 130: /* LeftHandSide: FieldAccess  */
#line 794 "parser.y"
                  {
        (yyval.ptr)=(yyvsp[0].ptr);
    }
#line 2973 "parser.tab.c"
    break;

  case 131: /* LeftHandSide: ArrayAccess  */
#line 797 "parser.y"
                  {
        (yyval.ptr)=(yyvsp[0].ptr);
    }
#line 2981 "parser.tab.c"
    break;

  case 132: /* AssertStatement: KEY_assert Expression ';'  */
#line 803 "parser.y"
                              {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-1].ptr));
        (yyval.ptr) = makeNode("assert", s);
    }
#line 2991 "parser.tab.c"
    break;

  case 133: /* AssertStatement: KEY_assert Expression ':' Expression ';'  */
#line 808 "parser.y"
                                               {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-3].ptr));
        s.push_back(makeLeaf(":"));
        s.push_back((yyvsp[-1].ptr));
        (yyval.ptr) = makeNode("assert", s);
    }
#line 3003 "parser.tab.c"
    break;

  case 134: /* BreakContinueStatement: KEY_break IDENTIFIER ';'  */
#line 818 "parser.y"
                             {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("ID (" + *(yyvsp[-1].st)+")" ));
        delete (yyvsp[-1].st);
        (yyval.ptr) = makeNode("break", s);
    }
#line 3014 "parser.tab.c"
    break;

  case 135: /* BreakContinueStatement: KEY_break ';'  */
#line 824 "parser.y"
                    {
        (yyval.ptr) = makeLeaf("break");
    }
#line 3022 "parser.tab.c"
    break;

  case 136: /* BreakContinueStatement: KEY_continue IDENTIFIER ';'  */
#line 827 "parser.y"
                                  {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("ID (" + *(yyvsp[-1].st)+")" ));
        delete (yyvsp[-1].st);
        (yyval.ptr) = makeNode("continue", s);
    }
#line 3033 "parser.tab.c"
    break;

  case 137: /* BreakContinueStatement: KEY_continue ';'  */
#line 833 "parser.y"
                       {
        (yyval.ptr) = makeLeaf("continue");
    }
#line 3041 "parser.tab.c"
    break;

  case 138: /* ForStatement: KEY_for '(' ForInit ';' ';' ')' Statement  */
#line 839 "parser.y"
                                              {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-4].ptr));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode("for", s);
    }
#line 3052 "parser.tab.c"
    break;

  case 139: /* ForStatement: KEY_for '(' ForInit ';' Expression ';' ')' Statement  */
#line 845 "parser.y"
                                                           {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-5].ptr));
        s.push_back((yyvsp[-3].ptr));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode("for", s);
    }
#line 3064 "parser.tab.c"
    break;

  case 140: /* ForStatement: KEY_for '(' ForInit ';' ';' StatementExpressionList ')' Statement  */
#line 852 "parser.y"
                                                                        {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-5].ptr));
        s.push_back((yyvsp[-2].ptr));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode("for", s);
    }
#line 3076 "parser.tab.c"
    break;

  case 141: /* ForStatement: KEY_for '(' ForInit ';' Expression ';' StatementExpressionList ')' Statement  */
#line 859 "parser.y"
                                                                                   {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-6].ptr));
        s.push_back((yyvsp[-4].ptr));
        s.push_back((yyvsp[-2].ptr));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode("for", s);
    }
#line 3089 "parser.tab.c"
    break;

  case 142: /* ForStatementNoShortIf: KEY_for '(' ForInit ';' ';' ')' StatementNoShortIf  */
#line 871 "parser.y"
                                                       {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-4].ptr));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode("for", s);
    }
#line 3100 "parser.tab.c"
    break;

  case 143: /* ForStatementNoShortIf: KEY_for '(' ForInit ';' Expression ';' ')' StatementNoShortIf  */
#line 877 "parser.y"
                                                                    {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-5].ptr));
        s.push_back((yyvsp[-3].ptr));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode("for", s);
    }
#line 3112 "parser.tab.c"
    break;

  case 144: /* ForStatementNoShortIf: KEY_for '(' ForInit ';' ';' StatementExpressionList ')' StatementNoShortIf  */
#line 884 "parser.y"
                                                                                 {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-5].ptr));
        s.push_back((yyvsp[-2].ptr));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode("for", s);
    }
#line 3124 "parser.tab.c"
    break;

  case 145: /* ForStatementNoShortIf: KEY_for '(' ForInit ';' Expression ';' StatementExpressionList ')' StatementNoShortIf  */
#line 891 "parser.y"
                                                                                            {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-6].ptr));
        s.push_back((yyvsp[-4].ptr));
        s.push_back((yyvsp[-2].ptr));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode("for", s);
    }
#line 3137 "parser.tab.c"
    break;

  case 146: /* ForInit: StatementExpressionList  */
#line 902 "parser.y"
                            {
        (yyval.ptr) = (yyvsp[0].ptr);
    }
#line 3145 "parser.tab.c"
    break;

  case 147: /* ForInit: LocalVariableDeclaration  */
#line 905 "parser.y"
                               {
        (yyval.ptr) = (yyvsp[0].ptr);
    }
#line 3153 "parser.tab.c"
    break;

  case 148: /* ForInit: %empty  */
#line 908 "parser.y"
        {
        (yyval.ptr)=NULL;
    }
#line 3161 "parser.tab.c"
    break;

  case 149: /* StatementExpressionList: StatementExpressionList ',' StatementExpression  */
#line 914 "parser.y"
                                                     {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-2].ptr));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode(",", s);
    }
#line 3172 "parser.tab.c"
    break;

  case 150: /* StatementExpressionList: StatementExpression  */
#line 920 "parser.y"
                          {
        (yyval.ptr)=(yyvsp[0].ptr);
    }
#line 3180 "parser.tab.c"
    break;

  case 151: /* ClassDeclaration: NormalClassDeclaration  */
#line 929 "parser.y"
                           {
        (yyval.ptr)=(yyvsp[0].ptr);
    }
#line 3188 "parser.tab.c"
    break;

  case 152: /* NormalClassDeclaration: Modifiers KEY_class IDENTIFIER ClassBody  */
#line 934 "parser.y"
                                             {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-3].ptr));
        s.push_back(makeLeaf("ID (" + *(yyvsp[-1].st)+")" ));
        delete (yyvsp[-1].st);
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode("class", s);
    }
#line 3201 "parser.tab.c"
    break;

  case 153: /* NormalClassDeclaration: Modifiers KEY_class IDENTIFIER ClassExtends ClassBody  */
#line 942 "parser.y"
                                                            {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-4].ptr));
        s.push_back(makeLeaf("ID (" + *(yyvsp[-2].st)+")" ));
        delete (yyvsp[-2].st) ;
        s.push_back((yyvsp[-1].ptr));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode("class", s);
    }
#line 3215 "parser.tab.c"
    break;

  case 154: /* NormalClassDeclaration: Modifiers KEY_class IDENTIFIER ClassPermits ClassBody  */
#line 951 "parser.y"
                                                            {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-4].ptr));
        s.push_back(makeLeaf("ID (" + *(yyvsp[-2].st)+")" ));
        delete (yyvsp[-2].st);
        s.push_back((yyvsp[-1].ptr));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode("class", s);
    }
#line 3229 "parser.tab.c"
    break;

  case 155: /* NormalClassDeclaration: Modifiers KEY_class IDENTIFIER ClassExtends ClassPermits ClassBody  */
#line 960 "parser.y"
                                                                         {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-5].ptr));
        s.push_back(makeLeaf("ID (" + *(yyvsp[-3].st)+")" ));
        delete (yyvsp[-3].st);
        s.push_back((yyvsp[-2].ptr));
        s.push_back((yyvsp[-1].ptr));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode("class", s);
    }
#line 3244 "parser.tab.c"
    break;

  case 156: /* ClassExtends: KEY_extends ClassType  */
#line 972 "parser.y"
                          {
        vector<ASTNode*> s;
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode("extends", s);
    }
#line 3254 "parser.tab.c"
    break;

  case 157: /* ClassPermits: KEY_permits IDENdotIDEN cTypeName  */
#line 979 "parser.y"
                                      {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-1].ptr));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode("permits", s);
    }
#line 3265 "parser.tab.c"
    break;

  case 158: /* cTypeName: cTypeName ',' IDENdotIDEN  */
#line 988 "parser.y"
                              {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-2].ptr));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode(",", s);
    }
#line 3276 "parser.tab.c"
    break;

  case 159: /* cTypeName: %empty  */
#line 994 "parser.y"
        {
        (yyval.ptr)=NULL;
    }
#line 3284 "parser.tab.c"
    break;

  case 160: /* ClassBody: '{' ClassBodyDeclarations '}'  */
#line 1000 "parser.y"
                                  {
        (yyval.ptr)=(yyvsp[-1].ptr);
    }
#line 3292 "parser.tab.c"
    break;

  case 161: /* ClassBodyDeclarations: ClassBodyDeclarations ClassBodyDeclaration  */
#line 1005 "parser.y"
                                               {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-1].ptr));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode("ClassBodyDeclarations", s);
    }
#line 3303 "parser.tab.c"
    break;

  case 162: /* ClassBodyDeclarations: %empty  */
#line 1011 "parser.y"
        {
        (yyval.ptr)=NULL;
    }
#line 3311 "parser.tab.c"
    break;

  case 163: /* ClassBodyDeclaration: Modifiers Type VariableDeclaratorList ';'  */
#line 1016 "parser.y"
                                              {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-3].ptr));
        s.push_back((yyvsp[-2].ptr));
        s.push_back((yyvsp[-1].ptr));
        (yyval.ptr) = makeNode("ClassBodyDeclaration", s);
    }
#line 3323 "parser.tab.c"
    break;

  case 164: /* ClassBodyDeclaration: ClassDeclaration  */
#line 1023 "parser.y"
                       {
        (yyval.ptr)=(yyvsp[0].ptr);
    }
#line 3331 "parser.tab.c"
    break;

  case 165: /* ClassBodyDeclaration: ';'  */
#line 1026 "parser.y"
          {
        (yyval.ptr)=NULL;
    }
#line 3339 "parser.tab.c"
    break;

  case 166: /* ClassBodyDeclaration: Block  */
#line 1029 "parser.y"
            {
        (yyval.ptr)=(yyvsp[0].ptr);
    }
#line 3347 "parser.tab.c"
    break;

  case 167: /* ClassBodyDeclaration: Modifiers IdenPara Block  */
#line 1032 "parser.y"
                               {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-2].ptr));
        s.push_back((yyvsp[-1].ptr));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode("ClassBodyDeclaration", s);
    }
#line 3359 "parser.tab.c"
    break;

  case 168: /* ClassBodyDeclaration: MethodDeclaration  */
#line 1039 "parser.y"
                        {
        (yyval.ptr)=(yyvsp[0].ptr);
    }
#line 3367 "parser.tab.c"
    break;

  case 169: /* VariableDeclaratorList: VariableDeclaratorList ',' VariableDeclarator  */
#line 1045 "parser.y"
                                                  {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-2].ptr));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode(",", s);
    }
#line 3378 "parser.tab.c"
    break;

  case 170: /* VariableDeclaratorList: VariableDeclarator  */
#line 1051 "parser.y"
                         {
        (yyval.ptr)=(yyvsp[0].ptr);
    }
#line 3386 "parser.tab.c"
    break;

  case 171: /* VariableDeclarator: VariableDeclarator1  */
#line 1057 "parser.y"
                        {
        (yyval.ptr)=(yyvsp[0].ptr);
    }
#line 3394 "parser.tab.c"
    break;

  case 172: /* VariableDeclarator: VariableDeclarator2  */
#line 1060 "parser.y"
                          {
        (yyval.ptr)=(yyvsp[0].ptr);
    }
#line 3402 "parser.tab.c"
    break;

  case 173: /* zerooroneExpression: Expression  */
#line 1066 "parser.y"
               {
        (yyval.ptr)=(yyvsp[0].ptr);
    }
#line 3410 "parser.tab.c"
    break;

  case 174: /* zerooroneExpression: %empty  */
#line 1069 "parser.y"
        {(yyval.ptr)=NULL;}
#line 3416 "parser.tab.c"
    break;

  case 175: /* VariableDeclarator1: IDENTIFIER  */
#line 1073 "parser.y"
               {
       (yyval.ptr) = makeLeaf("ID (" + *(yyvsp[0].st) +")");
       delete (yyvsp[0].st);
    }
#line 3425 "parser.tab.c"
    break;

  case 176: /* VariableDeclarator1: IDENTIFIER '[' zerooroneExpression ']'  */
#line 1077 "parser.y"
                                             {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("ID (" + *(yyvsp[-3].st) +")" ));
        delete (yyvsp[-3].st);
        s.push_back((yyvsp[-1].ptr));
        (yyval.ptr) = makeNode("VariableDeclarator1", s);
    }
#line 3437 "parser.tab.c"
    break;

  case 177: /* VariableDeclarator1: IDENTIFIER '[' zerooroneExpression ']' '[' zerooroneExpression ']'  */
#line 1084 "parser.y"
                                                                         {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("ID (" + *(yyvsp[-6].st) +")" ));
        delete (yyvsp[-6].st);
        s.push_back((yyvsp[-4].ptr));
        s.push_back((yyvsp[-1].ptr));
        (yyval.ptr) = makeNode("VariableDeclarator1", s);
    }
#line 3450 "parser.tab.c"
    break;

  case 178: /* VariableDeclarator1: IDENTIFIER '[' zerooroneExpression ']' '[' zerooroneExpression ']' '[' zerooroneExpression ']'  */
#line 1092 "parser.y"
                                                                                                     {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("ID (" + *(yyvsp[-9].st)+")" ));
        delete (yyvsp[-9].st);
        s.push_back((yyvsp[-7].ptr));
        s.push_back((yyvsp[-4].ptr));
        s.push_back((yyvsp[-1].ptr));
        (yyval.ptr) = makeNode("VariableDeclarator1", s);
    }
#line 3464 "parser.tab.c"
    break;

  case 179: /* VariableDeclarator2: IDENTIFIER '=' Expression  */
#line 1104 "parser.y"
                              {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("ID (" + *(yyvsp[-2].st)+")" ));
        delete (yyvsp[-2].st);
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode("=",s);
    }
#line 3476 "parser.tab.c"
    break;

  case 180: /* VariableDeclarator2: IDENTIFIER '[' zerooroneExpression ']' '=' List1  */
#line 1111 "parser.y"
                                                       {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("ID (" + *(yyvsp[-5].st)+")" ));
        delete (yyvsp[-5].st);
        s.push_back((yyvsp[-3].ptr));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode("=", s);
    }
#line 3489 "parser.tab.c"
    break;

  case 181: /* VariableDeclarator2: IDENTIFIER '[' zerooroneExpression ']' '[' zerooroneExpression ']' '=' List2  */
#line 1119 "parser.y"
                                                                                   {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("ID (" + *(yyvsp[-8].st)+")" ));
        delete (yyvsp[-8].st);
        s.push_back((yyvsp[-6].ptr));
        s.push_back((yyvsp[-3].ptr));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode("=", s);
    }
#line 3503 "parser.tab.c"
    break;

  case 182: /* VariableDeclarator2: IDENTIFIER '[' zerooroneExpression ']' '[' zerooroneExpression ']' '[' zerooroneExpression ']' '=' List3  */
#line 1128 "parser.y"
                                                                                                               {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("ID (" + *(yyvsp[-11].st)+")" ));
        delete (yyvsp[-11].st);
        s.push_back((yyvsp[-9].ptr));
        s.push_back((yyvsp[-6].ptr));
        s.push_back((yyvsp[-3].ptr));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode("=", s);
    }
#line 3518 "parser.tab.c"
    break;

  case 183: /* VariableDeclarator2: IDENTIFIER '[' zerooroneExpression ']' '=' KEY_new PrimitiveType '[' zerooroneExpression ']' List1  */
#line 1138 "parser.y"
                                                                                                         {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("ID (" + *(yyvsp[-10].st)+")" ));
        delete (yyvsp[-10].st);
        s.push_back((yyvsp[-8].ptr));
        s.push_back(makeLeaf("new"));
        s.push_back((yyvsp[-4].ptr));
        s.push_back((yyvsp[-2].ptr));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode("=", s);
    }
#line 3534 "parser.tab.c"
    break;

  case 184: /* VariableDeclarator2: IDENTIFIER '[' zerooroneExpression ']' '[' zerooroneExpression ']' '=' KEY_new PrimitiveType '[' zerooroneExpression ']' '[' zerooroneExpression ']' List2  */
#line 1149 "parser.y"
                                                                                                                                                                 {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("ID (" + *(yyvsp[-16].st)+")" ));
        delete (yyvsp[-16].st);
        s.push_back((yyvsp[-14].ptr));
        s.push_back((yyvsp[-11].ptr));
        s.push_back(makeLeaf("new"));
        s.push_back((yyvsp[-7].ptr));
        s.push_back((yyvsp[-5].ptr));
        s.push_back((yyvsp[-2].ptr));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode("=", s);
    }
#line 3552 "parser.tab.c"
    break;

  case 185: /* VariableDeclarator2: IDENTIFIER '[' zerooroneExpression ']' '[' zerooroneExpression ']' '[' zerooroneExpression ']' '=' KEY_new PrimitiveType '[' zerooroneExpression ']' '[' zerooroneExpression ']' '[' zerooroneExpression ']' List3  */
#line 1162 "parser.y"
                                                                                                                                                                                                                         {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("ID (" + *(yyvsp[-22].st)+")" ));
        delete (yyvsp[-22].st);
        s.push_back((yyvsp[-20].ptr));
        s.push_back((yyvsp[-17].ptr));
        s.push_back((yyvsp[-14].ptr));
        s.push_back(makeLeaf("new"));
        s.push_back((yyvsp[-10].ptr));
        s.push_back((yyvsp[-8].ptr));
        s.push_back((yyvsp[-5].ptr));
        s.push_back((yyvsp[-2].ptr));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode("=", s);
    }
#line 3572 "parser.tab.c"
    break;

  case 186: /* VariableDeclarator2: IDENTIFIER '[' zerooroneExpression ']' '=' KEY_new PrimitiveType '[' zerooroneExpression ']'  */
#line 1177 "parser.y"
                                                                                                   {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("ID (" + *(yyvsp[-9].st)+")" ));
        delete (yyvsp[-9].st);
        s.push_back((yyvsp[-7].ptr));
        s.push_back(makeLeaf("new"));
        s.push_back((yyvsp[-3].ptr));
        s.push_back((yyvsp[-1].ptr));
        (yyval.ptr) = makeNode("=", s);
    }
#line 3587 "parser.tab.c"
    break;

  case 187: /* VariableDeclarator2: IDENTIFIER '[' zerooroneExpression ']' '[' zerooroneExpression ']' '=' KEY_new PrimitiveType '[' zerooroneExpression ']' '[' zerooroneExpression ']'  */
#line 1187 "parser.y"
                                                                                                                                                           {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("ID (" + *(yyvsp[-15].st)+")" ));
        delete (yyvsp[-15].st);
        s.push_back((yyvsp[-13].ptr));
        s.push_back((yyvsp[-10].ptr));
        s.push_back(makeLeaf("new"));
        s.push_back((yyvsp[-6].ptr));
        s.push_back((yyvsp[-4].ptr));
        s.push_back((yyvsp[-1].ptr));
        (yyval.ptr) = makeNode("=", s);
    }
#line 3604 "parser.tab.c"
    break;

  case 188: /* VariableDeclarator2: IDENTIFIER '[' zerooroneExpression ']' '[' zerooroneExpression ']' '[' zerooroneExpression ']' '=' KEY_new PrimitiveType '[' zerooroneExpression ']' '[' zerooroneExpression ']' '[' zerooroneExpression ']'  */
#line 1199 "parser.y"
                                                                                                                                                                                                                   {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("ID (" + *(yyvsp[-21].st)+")" ));
        delete (yyvsp[-21].st);
        s.push_back((yyvsp[-19].ptr));
        s.push_back((yyvsp[-16].ptr));
        s.push_back((yyvsp[-13].ptr));
        s.push_back(makeLeaf("new"));
        s.push_back((yyvsp[-9].ptr));
        s.push_back((yyvsp[-7].ptr));
        s.push_back((yyvsp[-4].ptr));
        s.push_back((yyvsp[-1].ptr));
        (yyval.ptr) = makeNode("=", s);
    }
#line 3623 "parser.tab.c"
    break;

  case 189: /* List1: '{' ArrEle1 '}'  */
#line 1216 "parser.y"
                    {
        (yyval.ptr)=(yyvsp[-1].ptr);
    }
#line 3631 "parser.tab.c"
    break;

  case 190: /* ArrEle1: ArrEle1 ',' Expression  */
#line 1222 "parser.y"
                           {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-2].ptr));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode(",", s);
    }
#line 3642 "parser.tab.c"
    break;

  case 191: /* ArrEle1: Expression  */
#line 1228 "parser.y"
                 {
       (yyval.ptr)=(yyvsp[0].ptr);
    }
#line 3650 "parser.tab.c"
    break;

  case 192: /* List2: '{' ArrEle2 '}'  */
#line 1234 "parser.y"
                    {
        (yyval.ptr)=(yyvsp[-1].ptr);
    }
#line 3658 "parser.tab.c"
    break;

  case 193: /* ArrEle2: ArrEle2 ',' List1  */
#line 1240 "parser.y"
                      {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-2].ptr));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode(",", s);
    }
#line 3669 "parser.tab.c"
    break;

  case 194: /* ArrEle2: List1  */
#line 1246 "parser.y"
            {
        (yyval.ptr)=(yyvsp[0].ptr);
    }
#line 3677 "parser.tab.c"
    break;

  case 195: /* List3: '{' ArrEle3 '}'  */
#line 1252 "parser.y"
                    {
        (yyval.ptr)=(yyvsp[-1].ptr);
    }
#line 3685 "parser.tab.c"
    break;

  case 196: /* ArrEle3: ArrEle3 ',' List2  */
#line 1258 "parser.y"
                      {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-2].ptr));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode(",", s);
    }
#line 3696 "parser.tab.c"
    break;

  case 197: /* ArrEle3: List2  */
#line 1264 "parser.y"
            {
        (yyval.ptr)=(yyvsp[0].ptr);
    }
#line 3704 "parser.tab.c"
    break;

  case 198: /* MethodDeclaration: Modifiers MethodHeader MethodBody  */
#line 1270 "parser.y"
                                      {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-2].ptr));
        s.push_back((yyvsp[-1].ptr));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode("MethodDeclaration", s);
    }
#line 3716 "parser.tab.c"
    break;

  case 199: /* MethodHeader: Type Methodeclarator  */
#line 1280 "parser.y"
                         {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-1].ptr));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode("MethodHeader", s);
    }
#line 3727 "parser.tab.c"
    break;

  case 200: /* MethodHeader: KEY_void Methodeclarator  */
#line 1286 "parser.y"
                               {
        vector<ASTNode*> s;
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode("void", s);
    }
#line 3737 "parser.tab.c"
    break;

  case 201: /* Methodeclarator: IdenPara Dims  */
#line 1294 "parser.y"
                  {
        (yyval.ptr)=(yyvsp[-1].ptr);
    }
#line 3745 "parser.tab.c"
    break;

  case 202: /* Methodeclarator: IdenPara  */
#line 1297 "parser.y"
               {
        (yyval.ptr)=(yyvsp[0].ptr);
    }
#line 3753 "parser.tab.c"
    break;

  case 203: /* IdenPara: IDENTIFIER '(' formalparameters ')'  */
#line 1303 "parser.y"
                                        {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("ID (" + *(yyvsp[-3].st)+")" ));
        delete (yyvsp[-3].st);
        s.push_back((yyvsp[-1].ptr));
        (yyval.ptr) = makeNode("IdenPara", s);
    }
#line 3765 "parser.tab.c"
    break;

  case 204: /* IdenPara: IDENTIFIER '(' ')'  */
#line 1310 "parser.y"
                         {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("ID (" + *(yyvsp[-2].st)+")" ));
        delete (yyvsp[-2].st);
        (yyval.ptr) = makeNode("IdenPara", s);
    }
#line 3776 "parser.tab.c"
    break;

  case 205: /* formalparameters: formalparameters ',' formalparameter  */
#line 1318 "parser.y"
                                         {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-2].ptr));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode(",", s);
    }
#line 3787 "parser.tab.c"
    break;

  case 206: /* formalparameters: formalparameter  */
#line 1324 "parser.y"
                      {
        (yyval.ptr)=(yyvsp[0].ptr);
    }
#line 3795 "parser.tab.c"
    break;

  case 207: /* formalparameter: Type VariableDeclarator1  */
#line 1330 "parser.y"
                             {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-1].ptr));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode("formalparameter", s);
    }
#line 3806 "parser.tab.c"
    break;

  case 208: /* formalparameter: Type DOT3 IDENTIFIER  */
#line 1336 "parser.y"
                           {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-2].ptr));
        s.push_back(makeLeaf(*(yyvsp[-1].st)));
        delete (yyvsp[-1].st);
        s.push_back(makeLeaf("ID (" + *(yyvsp[0].st)+")" ));
        delete (yyvsp[0].st);
        (yyval.ptr) = makeNode("formalparameter", s);
    }
#line 3820 "parser.tab.c"
    break;

  case 209: /* MethodBody: Block  */
#line 1348 "parser.y"
          {
        (yyval.ptr)=(yyvsp[0].ptr);
    }
#line 3828 "parser.tab.c"
    break;

  case 210: /* MethodBody: ';'  */
#line 1351 "parser.y"
          {
        (yyval.ptr)=NULL;
    }
#line 3836 "parser.tab.c"
    break;

  case 211: /* Modifiers: Modifiers PublicPrivateStatic  */
#line 1357 "parser.y"
                                  {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-1].ptr));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode("Modifiers", s);
    }
#line 3847 "parser.tab.c"
    break;

  case 212: /* Modifiers: %empty  */
#line 1363 "parser.y"
        {(yyval.ptr)=NULL;}
#line 3853 "parser.tab.c"
    break;


#line 3857 "parser.tab.c"

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

#line 1367 "parser.y"


void print_help(){
    printf(" options :::\n");
    printf(" --help           Display available options.\n");
    printf(" --input <file>   take <file> as input file.\n");
    printf(" --output <file>  will print the dot script in <file>.\n");
    printf(" --verbose        display the procedure in bit details.\n"); 
    return;                                                     
}

int main(int argc, char* argv[]){
    gotinputfile=false;
    gotoutputfile=false;
    verbosemode=false;

    for(int i=1;i<argc;i++){
        if(!strcmp(argv[i],"--input")){
            if(i==argc-1){
                printf("Error :: input file name not given.\n");
                return 0;
            }
            else if(gotinputfile){
                printf("Error :: multiple input file name detected.\n");
                return 0;
            }
            else{
                yyin = fopen(argv[i+1],"r");
                /* printf("%s\n", argv[i+1]); */
                if(yyin==NULL){
                    printf("%s can not be opened as an input file.\n", argv[i+1]);
                    return 0;
                } 
                i++;
                gotinputfile=true;
                continue;
            }
        }
        else if(!strcmp(argv[i],"--output")){
            if(i==argc-1){
                printf("Error :: output file name not given.\n");
                return 0;
            }
            else if(gotoutputfile){
                printf("Error :: multiple output file name detected.\n");
                return 0;
            }
            else{
                dotfile = fopen(argv[i+1], "w");
                i++;
                gotoutputfile=true;
                continue;
            }
        }
        else if(!strcmp(argv[i],"--help")){
            print_help();
            return 0;
        }
        else if(!strcmp(argv[i],"--verbose")){
            verbosemode=true;
        }
        else{
            printf("Argument: %s  not recognised.\n", argv[i]);return 0;
            
        }
    }
    if(!gotinputfile){
        printf("Inputfile name not mentioned.\n");
        return 0;
    }

    if(verbosemode){
        printf("Input file is opened");
        printf("....\n");
        printf("Starting the parser...\n");
    }

    if(!gotoutputfile) dotfile = fopen("temp.dot", "w");

    if(dotfile==NULL){
        printf("Dot file can not be opened.\n");
        return 0;
    }
    yyrestart(yyin);

    beginAST();
    if(yyparse()) return 0;
    endAST();
    
    if(verbosemode){
        printf("Parser work completed..\n");
        printf("Dot script has generated successfully");
        printf("....\n");
    }
}
