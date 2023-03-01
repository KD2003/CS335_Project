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
#define YYLAST   762

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  61
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  83
/* YYNRULES -- Number of rules.  */
#define YYNRULES  208
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  417

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
       0,    36,    36,    45,    51,    57,    63,    69,    75,    82,
      90,   102,   105,   108,   114,   118,   122,   129,   136,   143,
     146,   149,   155,   160,   163,   168,   169,   178,   181,   187,
     191,   194,   200,   203,   206,   209,   212,   218,   226,   236,
     239,   245,   253,   260,   271,   277,   286,   294,   305,   316,
     328,   336,   342,   350,   357,   365,   375,   383,   392,   398,
     401,   407,   415,   427,   430,   442,   445,   454,   457,   466,
     469,   478,   481,   490,   493,   502,   505,   515,   518,   528,
     531,   541,   544,   554,   557,   567,   573,   579,   582,   588,
     591,   600,   609,   612,   615,   627,   633,   639,   645,   648,
     654,   663,   666,   674,   677,   685,   692,   701,   708,   714,
     717,   725,   734,   741,   747,   750,   753,   756,   759,   762,
     767,   773,   779,   785,   795,   798,   801,   807,   818,   821,
     824,   830,   836,   847,   854,   859,   866,   874,   881,   889,
     897,   910,   917,   925,   933,   946,   951,   956,   962,   968,
     977,   982,   991,  1001,  1011,  1024,  1032,  1042,  1048,  1054,
    1059,  1065,  1070,  1077,  1080,  1083,  1086,  1093,  1099,  1105,
    1111,  1114,  1120,  1123,  1127,  1131,  1138,  1146,  1158,  1165,
    1173,  1182,  1192,  1202,  1213,  1228,  1234,  1240,  1246,  1252,
    1258,  1264,  1270,  1276,  1282,  1292,  1298,  1307,  1310,  1316,
    1323,  1331,  1337,  1343,  1349,  1361,  1364,  1370,  1376
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

#define YYPACT_NINF (-347)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-131)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -347,    40,   -20,  -347,    18,    44,  -347,  -347,  -347,   300,
    -347,     9,   207,  -347,    22,  -347,  -347,  -347,  -347,   241,
    -347,    13,   155,  -347,    24,  -347,    84,     9,     9,  -347,
      62,    47,  -347,   112,  -347,   113,   113,  -347,    58,    47,
    -347,  -347,  -347,   166,   120,  -347,  -347,  -347,  -347,  -347,
    -347,  -347,   158,  -347,     9,   477,   133,  -347,  -347,  -347,
     189,   196,   173,   173,  -347,   -26,   147,   113,   182,  -347,
     712,  -347,   712,   712,   712,    82,   110,   557,   195,   228,
     230,   240,   246,  -347,   242,  -347,   712,  -347,  -347,    89,
     257,   258,  -347,    26,    27,    57,  -347,  -347,   292,  -347,
    -347,   270,   314,  -347,  -347,   279,    32,  -347,  -347,  -347,
      49,   133,  -347,   173,   231,   159,  -347,  -347,  -347,  -347,
     291,   294,   294,  -347,  -347,  -347,  -347,   520,   712,   712,
     712,   617,   211,  -347,  -347,  -347,  -347,  -347,  -347,   334,
      80,   -25,  -347,  -347,  -347,    20,   346,   309,   310,   308,
     355,   360,   354,   359,   361,  -347,   335,   337,   338,  -347,
     341,  -347,  -347,   343,   712,   623,   712,   712,   385,   344,
     299,   340,   128,   712,   712,   390,   712,   377,  -347,   108,
     345,  -347,   712,   712,  -347,    10,   261,  -347,   294,   712,
     712,  -347,   314,  -347,   347,  -347,  -347,  -347,  -347,   349,
    -347,  -347,   712,   712,   712,   712,   712,   712,   712,   712,
     712,   712,   712,   712,  -347,  -347,  -347,  -347,  -347,   350,
    -347,  -347,   358,   356,   362,   363,   365,   712,   371,   712,
     371,  -347,   375,  -347,   357,   373,   376,  -347,   381,   378,
    -347,  -347,   387,   405,  -347,  -347,   242,  -347,   384,  -347,
    -347,  -347,   712,   391,   346,   382,   308,   355,   309,   310,
     360,   354,   359,   361,  -347,   559,   646,   438,   520,   147,
     712,   389,   671,   294,   388,   294,   436,  -347,  -347,   712,
     712,  -347,   712,  -347,  -347,   188,  -347,  -347,   712,   386,
     396,   397,   398,  -347,   421,   422,  -347,    11,   407,  -347,
    -347,  -347,   404,  -347,   408,    47,   409,  -347,   411,   415,
     712,    61,  -347,   559,   712,   623,   712,   520,   520,   269,
     118,  -347,  -347,  -347,   712,  -347,   410,   417,   324,   712,
    -347,  -347,   416,   423,   420,  -347,  -347,   520,   520,   275,
     424,   712,   224,   428,  -347,    59,   559,   679,   559,  -347,
    -347,   520,  -347,   431,   712,   144,   434,   712,  -347,   444,
     204,   442,  -347,  -347,   445,   441,   324,   433,  -347,   433,
    -347,   559,   559,   303,   394,   712,   443,   446,  -347,   130,
    -347,  -347,  -347,   559,   559,   311,   456,   148,   458,   433,
    -347,  -347,  -347,   559,  -347,   324,   451,  -347,   463,  -347,
    -347,   467,  -347,   183,   469,   470,   451,  -347,   451,   472,
    -347,  -347,   474,   473,   479,   471,  -347
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,   208,     1,     0,   208,     3,     6,   150,     0,
      18,     0,     0,     5,     0,    19,    21,    20,   207,     0,
       7,     0,     0,     8,     0,    17,     0,     0,     0,   161,
       0,     0,   151,     0,     9,   158,    22,   155,   208,     0,
     152,   153,    10,     0,   156,   164,    97,   159,   165,   163,
     160,   167,     0,   154,     0,     0,    18,    14,    15,    16,
       0,     0,    11,    13,    12,     0,     0,   157,    18,    29,
       0,   102,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    30,     0,   115,     0,    95,   101,   128,
      92,    27,    33,    34,    35,    36,    28,   124,     0,   114,
      96,     0,     0,    99,   103,     0,     0,   117,   118,   108,
       0,     0,   196,   198,   174,     0,   169,   170,   171,   195,
       0,    23,    24,   206,   205,   194,   166,     0,     0,     0,
       0,     0,    93,    34,    35,    36,   126,    87,    88,    89,
      93,     0,    58,    60,    59,    63,    65,    71,    73,    67,
      69,    75,    77,    79,    81,    83,     0,     0,     0,   134,
       0,   136,   119,     0,     0,   147,     0,     0,     0,     0,
       0,     0,     0,     0,    40,     0,     0,   127,    98,   174,
     100,   116,     0,     0,   200,     0,     0,   202,   197,   173,
       0,   162,     0,    25,     0,   104,    86,    85,    90,     0,
      94,   131,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   121,   122,   133,   135,   120,     0,
     146,   149,     0,   145,     0,     0,    42,     0,    53,    40,
      55,    32,     0,    31,     0,     0,    39,    51,    41,     0,
      61,    62,   174,     0,   203,   199,     0,   172,     0,   178,
     168,    26,     0,     0,    66,     0,    68,    70,    72,    74,
      76,    78,    80,    82,    84,     0,     0,     0,     0,     0,
      40,     0,     0,    52,     0,    54,     0,    44,    46,     0,
      40,    45,   173,   204,   201,   175,    91,   132,     0,    18,
       0,     0,     0,   105,     0,   103,   113,     0,     0,   148,
     107,   123,     0,    57,     0,    38,    43,    50,     0,     0,
     173,     0,    64,     0,     0,   147,     0,     0,     0,     0,
       0,    48,    56,    37,    40,    47,   175,     0,     0,     0,
     179,   110,     0,     0,     0,   106,   137,     0,     0,     0,
       0,   173,   176,     0,   187,     0,     0,     0,     0,   139,
     138,     0,    49,     0,   173,     0,     0,     0,   185,     0,
       0,     0,   112,   140,   176,     0,     0,     0,   180,     0,
     186,     0,     0,     0,     0,   173,   177,     0,   190,     0,
     182,   111,   141,     0,     0,     0,     0,     0,     0,     0,
     188,   143,   142,     0,   177,     0,     0,   181,     0,   189,
     144,     0,   193,     0,     0,     0,     0,   191,     0,     0,
     192,   183,     0,     0,     0,     0,   184
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -347,  -347,  -347,  -347,  -347,   -44,   -81,    21,  -347,   498,
    -347,   -36,  -347,  -347,  -347,  -225,   -65,   -32,   -55,  -347,
    -347,   364,   287,  -347,   -49,   243,  -347,   326,   325,   327,
     328,   333,   331,   348,   339,   336,   -61,  -347,  -347,    33,
     -31,  -347,  -347,   499,  -347,    39,  -259,   -43,   105,  -347,
    -347,  -347,  -347,  -347,   253,  -279,    77,  -347,  -347,   539,
    -347,   -29,  -347,  -347,   476,   379,  -271,   402,  -347,  -346,
    -347,  -191,  -347,   157,  -347,  -347,  -347,   513,   537,  -347,
     352,  -347,   558
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
      44,    32,    38,    50,   115,   116,   248,   117,   118,   330,
     345,   368,   379,   397,   403,    51,    65,   112,   113,   186,
     187,   125,     9
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      95,    40,    41,   169,   274,   133,    97,    48,    61,   136,
      53,   309,   104,    10,   242,    10,    69,    25,   319,   123,
     201,   378,    10,   380,     4,    12,    22,   122,    25,    70,
     202,   203,    19,    46,   124,   126,  -129,  -130,   134,   327,
       3,   339,   182,   399,    -2,   302,    82,    83,    35,    36,
     199,    84,   243,    10,   331,   308,    57,    58,    59,    11,
      26,    86,   318,   133,   133,   133,   185,   196,   197,   198,
     353,    33,    95,    36,   204,    67,    89,   188,    97,  -129,
    -130,   373,    13,   365,   104,   183,   158,   359,    98,   362,
    -128,   132,    27,   -22,   103,   385,   134,   134,   134,   340,
     184,   328,  -125,    45,   386,   170,    29,   -93,  -125,  -125,
      95,   357,   381,   382,   160,    49,    97,    46,    47,   358,
     329,    29,    10,    69,   391,   392,   172,   159,   173,    34,
     174,    36,    25,  -128,   400,   172,    70,   173,   133,   174,
     133,   133,   133,   133,   133,   133,   133,   133,   133,   132,
     132,   132,   264,    82,    83,   161,   189,    42,    84,    43,
      98,   190,    56,   232,   233,    57,    58,    59,    86,   338,
      25,   134,    54,   134,   134,   134,   134,   134,   134,   134,
     134,   134,   389,   110,   366,    27,    89,   133,   395,    28,
     390,   286,   273,   111,   275,    14,    60,    15,    98,    16,
     114,    17,   185,   367,   191,   402,    46,   396,    10,    69,
      95,   192,    95,    95,    29,   410,    97,   411,    97,    97,
     134,   120,    70,   133,   132,   104,   132,   132,   132,   132,
     132,   132,   132,   132,   132,   406,   310,   127,   301,    82,
      83,   311,    95,   407,    84,   164,    10,   343,    97,    57,
      58,    59,    20,    21,    86,   372,   134,   172,    95,   173,
      95,   174,    95,    95,    97,    95,    97,    36,    97,    97,
     221,    97,   354,   132,   104,   104,   323,   355,   165,   189,
     166,   110,    95,    95,   190,   377,    23,    24,    97,    97,
     167,    95,   168,    95,   104,   104,    95,    97,    98,    97,
      98,    98,    97,   175,   293,    95,   176,   300,   104,   132,
     177,    97,   245,   246,   401,   178,    95,    95,   179,    95,
     337,   267,    97,    97,   181,    97,   351,   267,    95,    95,
      98,    57,    58,    59,    97,    97,    89,    14,    95,    15,
     193,    16,   194,    17,    97,    43,    98,   227,    98,   229,
      98,    98,   200,    98,   383,   267,   335,   336,   205,   141,
     156,   157,   393,   267,   163,   206,   208,   207,   209,   211,
      98,    98,   299,   171,   210,   212,   349,   350,   213,    98,
     214,    98,   215,   216,    98,   293,   217,   300,   218,   226,
     363,   231,   227,    98,   238,   -94,   251,   192,    10,    69,
     252,   265,   221,   266,    98,    98,   277,    98,   267,   283,
     335,   336,    70,   268,   269,   270,    98,    98,   171,   272,
     221,   276,   349,   350,   278,   221,    98,   281,   279,    82,
      83,   280,   363,   285,    84,   282,   287,   288,   303,   305,
     306,   313,    10,    69,    86,   384,   314,   315,   316,   317,
    -109,   219,   320,   224,   225,   321,    70,   322,   341,   324,
     234,   237,   325,   239,   326,   221,   342,   346,   347,   240,
     241,   348,   371,    82,    83,   352,   356,   249,    84,   221,
     364,    68,    69,   369,    57,    58,    59,   374,    86,   253,
     376,   255,   329,   375,   388,    70,   387,    71,    72,    73,
      74,    75,    76,    77,    78,   394,    79,   398,    80,    81,
     367,   404,    82,    83,   271,   405,   237,    84,   408,   409,
     412,   414,    85,   413,    68,    69,    37,    86,   415,   254,
     396,   312,   258,   256,   230,   259,    46,    87,    70,   257,
     260,    72,    73,    74,    75,    76,    77,    78,   263,    79,
     262,    80,    81,   298,   101,    82,    83,   237,   261,   304,
      84,    10,    69,   289,    69,    85,   307,   237,   333,    39,
      86,   250,   416,   128,   119,   129,   130,    70,   180,    46,
      72,    73,    74,    75,    76,    77,   290,   244,   291,    66,
     292,    81,    82,    83,    82,    83,    52,    84,   284,    84,
       0,   332,   162,   334,    85,     0,     0,   131,     0,    86,
       0,   237,     0,     0,     0,     0,   344,     0,    46,     0,
       0,    10,    69,     0,    57,    58,    59,    10,    69,     0,
      57,    58,    59,   128,   361,   129,   130,     0,     0,     0,
       0,    70,     0,    71,   370,     0,     0,     0,     0,     0,
      10,    69,    82,    83,     0,     0,     0,    84,    82,    83,
       0,     0,   128,    84,   129,   130,     0,   131,     0,     0,
       0,     0,     0,    86,     0,    10,    69,     0,     0,     0,
       0,    82,    83,    10,    69,     0,    84,   128,     0,   129,
     130,   297,     0,     0,     0,   128,   131,   129,   130,     0,
       0,     0,     0,     0,     0,     0,    82,    83,     0,     0,
       0,    84,     0,     0,    82,    83,    10,    69,     0,    84,
     193,   131,     0,     0,   360,     0,     0,     0,   128,   131,
     129,   130,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    82,    83,     0,
       0,     0,    84,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   131
};

static const yytype_int16 yycheck[] =
{
      55,    30,    31,    84,   229,    70,    55,    38,    52,    70,
      39,   282,    55,     4,     4,     4,     5,     4,   297,    45,
      45,   367,     4,   369,    44,     4,     4,    63,     4,    18,
      55,    11,    11,    59,    65,    66,    10,    10,    70,   310,
       0,   320,    10,   389,     0,   270,    35,    36,    27,    28,
     131,    40,    42,     4,   313,   280,     7,     8,     9,    41,
      47,    50,    51,   128,   129,   130,   110,   128,   129,   130,
     341,    47,   127,    52,    54,    54,    55,   113,   127,    53,
      53,   360,     5,   354,   127,    53,     4,   346,    55,   348,
      10,    70,    30,     4,    55,   374,   128,   129,   130,   324,
      51,    40,    45,    45,   375,    84,    59,    18,    51,    52,
     165,    52,   371,   372,     4,    38,   165,    59,    60,    60,
      59,    59,     4,     5,   383,   384,    46,    45,    48,    45,
      50,   110,     4,    53,   393,    46,    18,    48,   203,    50,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   128,
     129,   130,   213,    35,    36,    45,    48,    45,    40,    46,
     127,    53,     4,    35,    36,     7,     8,     9,    50,    51,
       4,   203,    52,   205,   206,   207,   208,   209,   210,   211,
     212,   213,    52,    50,    40,    30,   165,   252,    40,    34,
      60,   252,   228,     4,   230,    37,    38,    39,   165,    41,
       4,    43,   246,    59,    45,   396,    59,    59,     4,     5,
     265,    52,   267,   268,    59,   406,   265,   408,   267,   268,
     252,    48,    18,   288,   203,   268,   205,   206,   207,   208,
     209,   210,   211,   212,   213,    52,    48,    55,   269,    35,
      36,    53,   297,    60,    40,    50,     4,   328,   297,     7,
       8,     9,    45,    46,    50,    51,   288,    46,   313,    48,
     315,    50,   317,   318,   313,   320,   315,   246,   317,   318,
     165,   320,    48,   252,   317,   318,   305,    53,    50,    48,
      50,    50,   337,   338,    53,   366,    45,    46,   337,   338,
      50,   346,    46,   348,   337,   338,   351,   346,   265,   348,
     267,   268,   351,    46,   265,   360,    48,   268,   351,   288,
      18,   360,    51,    52,   395,    45,   371,   372,     4,   374,
      51,    52,   371,   372,    45,   374,    51,    52,   383,   384,
     297,     7,     8,     9,   383,   384,   315,    37,   393,    39,
      49,    41,    48,    43,   393,    46,   313,    48,   315,    50,
     317,   318,    18,   320,    51,    52,   317,   318,    12,    72,
      73,    74,    51,    52,    77,    56,    58,    57,    13,    15,
     337,   338,   267,    86,    14,    16,   337,   338,    17,   346,
      45,   348,    45,    45,   351,   346,    45,   348,    45,     4,
     351,    51,    48,   360,     4,    18,    49,    52,     4,     5,
      51,    51,   297,    45,   371,   372,    49,   374,    52,     4,
     371,   372,    18,    51,    51,    50,   383,   384,   131,    48,
     315,    46,   383,   384,    51,   320,   393,    49,    52,    35,
      36,    50,   393,    49,    40,    48,    45,    55,    49,    51,
       4,    55,     4,     5,    50,    51,    50,    50,    50,    28,
      28,   164,    45,   166,   167,    51,    18,    49,    48,    50,
     173,   174,    51,   176,    49,   360,    49,    51,    45,   182,
     183,    51,    28,    35,    36,    51,    48,   190,    40,   374,
      49,     4,     5,    49,     7,     8,     9,    45,    50,   202,
      49,   204,    59,    48,    48,    18,    53,    20,    21,    22,
      23,    24,    25,    26,    27,    49,    29,    49,    31,    32,
      59,    48,    35,    36,   227,    48,   229,    40,    49,    49,
      48,    48,    45,    49,     4,     5,    28,    50,    49,   203,
      59,   288,   207,   205,   170,   208,    59,    60,    18,   206,
     209,    21,    22,    23,    24,    25,    26,    27,   212,    29,
     211,    31,    32,   266,    55,    35,    36,   270,   210,   272,
      40,     4,     5,     4,     5,    45,   279,   280,   315,    30,
      50,   192,   415,    16,    61,    18,    19,    18,   102,    59,
      21,    22,    23,    24,    25,    26,    27,   185,    29,    52,
      31,    32,    35,    36,    35,    36,    38,    40,   246,    40,
      -1,   314,    45,   316,    45,    -1,    -1,    50,    -1,    50,
      -1,   324,    -1,    -1,    -1,    -1,   329,    -1,    59,    -1,
      -1,     4,     5,    -1,     7,     8,     9,     4,     5,    -1,
       7,     8,     9,    16,   347,    18,    19,    -1,    -1,    -1,
      -1,    18,    -1,    20,   357,    -1,    -1,    -1,    -1,    -1,
       4,     5,    35,    36,    -1,    -1,    -1,    40,    35,    36,
      -1,    -1,    16,    40,    18,    19,    -1,    50,    -1,    -1,
      -1,    -1,    -1,    50,    -1,     4,     5,    -1,    -1,    -1,
      -1,    35,    36,     4,     5,    -1,    40,    16,    -1,    18,
      19,    45,    -1,    -1,    -1,    16,    50,    18,    19,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    35,    36,    -1,    -1,
      -1,    40,    -1,    -1,    35,    36,     4,     5,    -1,    40,
      49,    50,    -1,    -1,    45,    -1,    -1,    -1,    16,    50,
      18,    19,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,    36,    -1,
      -1,    -1,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
      45,    51,    49,   122,    50,    51,    49,   127,    40,    59,
     130,   107,    83,   115,    83,   106,   106,    51,    51,   116,
      76,    48,    49,    67,    83,   131,    51,    45,    51,   106,
     106,    51,    51,   127,    48,    53,    48,    52,    60,   107,
      45,    83,   107,   106,    49,   127,    40,    59,   132,    49,
      83,    28,    51,   116,    45,    48,    49,    67,   130,   133,
     130,   107,   107,    51,    51,   116,   127,    53,    48,    52,
      60,   107,   107,    51,    49,    40,    59,   134,    49,   130,
     107,    67,   132,   135,    48,    48,    52,    60,    49,    49,
     132,   132,    48,    49,    48,    49,   134
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
     129,   129,   129,   129,   129,   130,   131,   131,   132,   133,
     133,   134,   135,   135,   136,   137,   137,   138,   138,   139,
     139,   140,   140,   141,   141,   142,   142,   143,   143
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
       9,    12,    10,    15,    20,     3,     3,     1,     3,     3,
       1,     3,     3,     1,     3,     2,     2,     2,     1,     4,
       3,     3,     1,     2,     3,     1,     1,     2,     0
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
#line 36 "parser.y"
                                                {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-1].ptr));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode("prog", s);
        }
#line 1714 "parser.tab.c"
    break;

  case 3: /* ImportList: ImportList Imports  */
#line 45 "parser.y"
                        {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-1].ptr));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode("ImportList", s);
    }
#line 1725 "parser.tab.c"
    break;

  case 4: /* ImportList: %empty  */
#line 51 "parser.y"
        {
        (yyval.ptr)=NULL;
    }
#line 1733 "parser.tab.c"
    break;

  case 5: /* ClassDeclarationList: ClassDeclarationList ClassDeclaration  */
#line 57 "parser.y"
                                                {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-1].ptr));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode("ClassDeclarationList", s);
    }
#line 1744 "parser.tab.c"
    break;

  case 6: /* ClassDeclarationList: ClassDeclaration  */
#line 63 "parser.y"
                            {
        (yyval.ptr)=(yyvsp[0].ptr);
    }
#line 1752 "parser.tab.c"
    break;

  case 7: /* Imports: KEY_import IDENdotIDEN ';'  */
#line 69 "parser.y"
                                    {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("import"));
        s.push_back((yyvsp[-1].ptr));
        (yyval.ptr) = makeNode("Imports", s);
    }
#line 1763 "parser.tab.c"
    break;

  case 8: /* Imports: KEY_import KEY_static IDENdotIDEN ';'  */
#line 75 "parser.y"
                                                {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("import"));
        s.push_back(makeLeaf("static"));
        s.push_back((yyvsp[-1].ptr));
        (yyval.ptr) = makeNode("Imports", s);
    }
#line 1775 "parser.tab.c"
    break;

  case 9: /* Imports: KEY_import IDENdotIDEN '.' '*' ';'  */
#line 82 "parser.y"
                                                {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("import"));
        s.push_back((yyvsp[-3].ptr));
        s.push_back(makeLeaf("*"));
        
        (yyval.ptr) = makeNode("Imports", s);   
    }
#line 1788 "parser.tab.c"
    break;

  case 10: /* Imports: KEY_import KEY_static IDENdotIDEN '.' '*' ';'  */
#line 90 "parser.y"
                                                        {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("import"));
        s.push_back(makeLeaf("static"));
        s.push_back((yyvsp[-3].ptr));
        delete (yyvsp[-3].ptr);
        (yyval.ptr) = makeNode("Imports", s);
    }
#line 1801 "parser.tab.c"
    break;

  case 11: /* Type: PrimitiveType  */
#line 102 "parser.y"
                    {
        (yyval.ptr)=(yyvsp[0].ptr);
    }
#line 1809 "parser.tab.c"
    break;

  case 12: /* Type: ArrayType  */
#line 105 "parser.y"
                    {
        (yyval.ptr)=(yyvsp[0].ptr);
    }
#line 1817 "parser.tab.c"
    break;

  case 13: /* Type: ClassType  */
#line 108 "parser.y"
                    {
        (yyval.ptr)=(yyvsp[0].ptr);
    }
#line 1825 "parser.tab.c"
    break;

  case 14: /* PrimitiveType: INTTYPE  */
#line 114 "parser.y"
                {
        (yyval.ptr) = makeLeaf(*(yyvsp[0].st));
        delete (yyvsp[0].st);
    }
#line 1834 "parser.tab.c"
    break;

  case 15: /* PrimitiveType: FPTYPE  */
#line 118 "parser.y"
                   {
        (yyval.ptr) = makeLeaf(*(yyvsp[0].st));
        delete (yyvsp[0].st);
    }
#line 1843 "parser.tab.c"
    break;

  case 16: /* PrimitiveType: BOOLTYPE  */
#line 122 "parser.y"
                    {
        (yyval.ptr) = makeLeaf(*(yyvsp[0].st));
        delete (yyvsp[0].st);
    }
#line 1852 "parser.tab.c"
    break;

  case 17: /* IDENdotIDEN: IDENdotIDEN '.' IDENTIFIER  */
#line 129 "parser.y"
                                    {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-2].ptr));
        s.push_back(makeLeaf("IDENTIFIER (" + *(yyvsp[0].st) + ")"));
        delete (yyvsp[0].st);
        (yyval.ptr) = makeNode("IDENdotIDEN", s);
    }
#line 1864 "parser.tab.c"
    break;

  case 18: /* IDENdotIDEN: IDENTIFIER  */
#line 136 "parser.y"
                    {
        (yyval.ptr) = makeLeaf("IDENTIFIER (" + *(yyvsp[0].st) + ")");
        delete (yyvsp[0].st);
    }
#line 1873 "parser.tab.c"
    break;

  case 19: /* PublicPrivateStatic: KEY_public  */
#line 143 "parser.y"
                    {
        (yyval.ptr) = makeLeaf("public");
    }
#line 1881 "parser.tab.c"
    break;

  case 20: /* PublicPrivateStatic: KEY_private  */
#line 146 "parser.y"
                        {
        (yyval.ptr) = makeLeaf("private");
    }
#line 1889 "parser.tab.c"
    break;

  case 21: /* PublicPrivateStatic: KEY_static  */
#line 149 "parser.y"
                        {
        (yyval.ptr) = makeLeaf("static");
    }
#line 1897 "parser.tab.c"
    break;

  case 22: /* ClassType: IDENdotIDEN  */
#line 155 "parser.y"
                    {
        (yyval.ptr)=(yyvsp[0].ptr);
    }
#line 1905 "parser.tab.c"
    break;

  case 23: /* ArrayType: PrimitiveType Dims  */
#line 160 "parser.y"
                            {
        (yyval.ptr)=(yyvsp[-1].ptr);
    }
#line 1913 "parser.tab.c"
    break;

  case 24: /* ArrayType: ClassType Dims  */
#line 163 "parser.y"
                            {
        (yyval.ptr)=(yyvsp[-1].ptr);
    }
#line 1921 "parser.tab.c"
    break;

  case 25: /* Dims: '[' ']'  */
#line 168 "parser.y"
                {(yyval.ptr)=NULL;}
#line 1927 "parser.tab.c"
    break;

  case 26: /* Dims: Dims '[' ']'  */
#line 169 "parser.y"
                    {
        (yyval.ptr)=NULL;
    }
#line 1935 "parser.tab.c"
    break;

  case 27: /* Primary: PrimaryNoNewArray  */
#line 178 "parser.y"
                        {
        (yyval.ptr) = (yyvsp[0].ptr);
    }
#line 1943 "parser.tab.c"
    break;

  case 28: /* Primary: ArrayCreationExpression  */
#line 181 "parser.y"
                                    {
        (yyval.ptr) = (yyvsp[0].ptr);
    }
#line 1951 "parser.tab.c"
    break;

  case 29: /* PrimaryNoNewArray: LITERAL  */
#line 187 "parser.y"
                {
        (yyval.ptr) = makeLeaf("Literal");
    }
#line 1959 "parser.tab.c"
    break;

  case 30: /* PrimaryNoNewArray: KEY_this  */
#line 191 "parser.y"
                    {
        (yyval.ptr) = makeLeaf("this");
    }
#line 1967 "parser.tab.c"
    break;

  case 31: /* PrimaryNoNewArray: IDENdotIDEN '.' KEY_this  */
#line 194 "parser.y"
                                    {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-2].ptr));
        s.push_back(makeLeaf("this"));
        (yyval.ptr) = makeNode("PrimaryNoNewArray", s);
    }
#line 1978 "parser.tab.c"
    break;

  case 32: /* PrimaryNoNewArray: '(' Expression ')'  */
#line 200 "parser.y"
                                {
        (yyval.ptr) = (yyvsp[-1].ptr);
    }
#line 1986 "parser.tab.c"
    break;

  case 33: /* PrimaryNoNewArray: ClassInstanceCreationExpression  */
#line 203 "parser.y"
                                            {
        (yyval.ptr) = (yyvsp[0].ptr);
    }
#line 1994 "parser.tab.c"
    break;

  case 34: /* PrimaryNoNewArray: FieldAccess  */
#line 206 "parser.y"
                        {
        (yyval.ptr) = (yyvsp[0].ptr);
    }
#line 2002 "parser.tab.c"
    break;

  case 35: /* PrimaryNoNewArray: ArrayAccess  */
#line 209 "parser.y"
                        {
        (yyval.ptr) = (yyvsp[0].ptr);
    }
#line 2010 "parser.tab.c"
    break;

  case 36: /* PrimaryNoNewArray: MethodInvocation  */
#line 212 "parser.y"
                            {
        (yyval.ptr) = (yyvsp[0].ptr);
    }
#line 2018 "parser.tab.c"
    break;

  case 37: /* ClassInstanceCreationExpression: KEY_new IDENdotIDEN '(' Zeroorone_ArgumentList ')' ClassBody  */
#line 218 "parser.y"
                                                                        {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("new"));
        s.push_back((yyvsp[-4].ptr));
        s.push_back((yyvsp[-2].ptr));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode("ClassInstanceCreationExpression", s);
    }
#line 2031 "parser.tab.c"
    break;

  case 38: /* ClassInstanceCreationExpression: KEY_new IDENdotIDEN '(' Zeroorone_ArgumentList ')'  */
#line 226 "parser.y"
                                                                {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("new"));
        s.push_back((yyvsp[-3].ptr));
        s.push_back((yyvsp[-1].ptr));
        (yyval.ptr) = makeNode("ClassInstanceCreationExpression", s);
    }
#line 2043 "parser.tab.c"
    break;

  case 39: /* Zeroorone_ArgumentList: ArgumentList  */
#line 236 "parser.y"
                        {
        (yyval.ptr) = (yyvsp[0].ptr);
    }
#line 2051 "parser.tab.c"
    break;

  case 40: /* Zeroorone_ArgumentList: %empty  */
#line 239 "parser.y"
        {
        (yyval.ptr)=NULL;
    }
#line 2059 "parser.tab.c"
    break;

  case 41: /* FieldAccess: Primary '.' IDENTIFIER  */
#line 245 "parser.y"
                                {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-2].ptr));
        s.push_back(makeLeaf("IDENTIFIER (" + *(yyvsp[0].st) + ")"));
        delete (yyvsp[0].st);
        
        (yyval.ptr) = makeNode("FieldAccess", s);
    }
#line 2072 "parser.tab.c"
    break;

  case 42: /* FieldAccess: KEY_super '.' IDENTIFIER  */
#line 253 "parser.y"
                                    {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("super"));
        s.push_back(makeLeaf("IDENTIFIER (" + *(yyvsp[0].st) + ")"));
        delete (yyvsp[0].st);
        (yyval.ptr) = makeNode("FieldAccess", s);
    }
#line 2084 "parser.tab.c"
    break;

  case 43: /* FieldAccess: IDENdotIDEN '.' KEY_super '.' IDENTIFIER  */
#line 260 "parser.y"
                                                    {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-4].ptr));
        s.push_back(makeLeaf("super"));
        s.push_back(makeLeaf("IDENTIFIER (" + *(yyvsp[0].st) + ")"));
        delete (yyvsp[0].st);
        (yyval.ptr) = makeNode("FieldAccess", s);
    }
#line 2097 "parser.tab.c"
    break;

  case 44: /* ArrayAccess: IDENdotIDEN '[' Expression ']'  */
#line 271 "parser.y"
                                        {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-3].ptr));
        s.push_back((yyvsp[-1].ptr));
        (yyval.ptr) = makeNode("ArrayAccess", s);
    }
#line 2108 "parser.tab.c"
    break;

  case 45: /* ArrayAccess: PrimaryNoNewArray '[' Expression ']'  */
#line 277 "parser.y"
                                                {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-3].ptr));
        s.push_back((yyvsp[-1].ptr));
        (yyval.ptr) = makeNode("ArrayAccess", s);
    }
#line 2119 "parser.tab.c"
    break;

  case 46: /* MethodInvocation: IDENdotIDEN '(' Zeroorone_ArgumentList ')'  */
#line 286 "parser.y"
                                                        {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-3].ptr));
        s.push_back((yyvsp[-1].ptr));
        
        
        (yyval.ptr) = makeNode("MethodInvocation", s);
    }
#line 2132 "parser.tab.c"
    break;

  case 47: /* MethodInvocation: Primary '.' IDENTIFIER '(' Zeroorone_ArgumentList ')'  */
#line 294 "parser.y"
                                                                {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-5].ptr));
        s.push_back(makeLeaf("IDENTIFIER (" + *(yyvsp[-3].st) + ")"));
        delete (yyvsp[-3].st);
        s.push_back((yyvsp[-1].ptr));
        
        
        
        (yyval.ptr) = makeNode("MethodInvocation", s);
    }
#line 2148 "parser.tab.c"
    break;

  case 48: /* MethodInvocation: KEY_super '.' IDENTIFIER '(' Zeroorone_ArgumentList ')'  */
#line 305 "parser.y"
                                                                    {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("super"));
        s.push_back(makeLeaf("IDENTIFIER (" + *(yyvsp[-3].st) + ")"));
        delete (yyvsp[-3].st);
        s.push_back((yyvsp[-1].ptr));
        
        
        
        (yyval.ptr) = makeNode("MethodInvocation", s);
    }
#line 2164 "parser.tab.c"
    break;

  case 49: /* MethodInvocation: IDENdotIDEN '.' KEY_super '.' IDENTIFIER '(' Zeroorone_ArgumentList ')'  */
#line 316 "parser.y"
                                                                                   {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-7].ptr));
        s.push_back(makeLeaf("super"));
        s.push_back(makeLeaf("IDENTIFIER (" + *(yyvsp[-3].st) + ")"));
        delete (yyvsp[-3].st);
        s.push_back((yyvsp[-1].ptr));
        (yyval.ptr) = makeNode("MethodInvocation", s);   
    }
#line 2178 "parser.tab.c"
    break;

  case 50: /* ArgumentList: ArgumentList ',' Expression  */
#line 328 "parser.y"
                                    {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-2].ptr));
        s.push_back((yyvsp[0].ptr));
        
        
        (yyval.ptr) = makeNode("ArguementList", s);
    }
#line 2191 "parser.tab.c"
    break;

  case 51: /* ArgumentList: Expression  */
#line 336 "parser.y"
                        {
        (yyval.ptr) = (yyvsp[0].ptr);
    }
#line 2199 "parser.tab.c"
    break;

  case 52: /* ArrayCreationExpression: KEY_new PrimitiveType DimExpr Dims  */
#line 342 "parser.y"
                                            {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("new"));
        s.push_back((yyvsp[-2].ptr));
        s.push_back((yyvsp[-1].ptr));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode("ArrayCreationExpression", s);
    }
#line 2212 "parser.tab.c"
    break;

  case 53: /* ArrayCreationExpression: KEY_new PrimitiveType DimExpr  */
#line 350 "parser.y"
                                        {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("new"));
        s.push_back((yyvsp[-1].ptr));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode("ArrayCreationExpression", s);
    }
#line 2224 "parser.tab.c"
    break;

  case 54: /* ArrayCreationExpression: KEY_new IDENdotIDEN DimExpr Dims  */
#line 357 "parser.y"
                                            {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("new"));
        s.push_back((yyvsp[-2].ptr));
        s.push_back((yyvsp[-1].ptr));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode("ArrayCreationExpression", s);
    }
#line 2237 "parser.tab.c"
    break;

  case 55: /* ArrayCreationExpression: KEY_new IDENdotIDEN DimExpr  */
#line 365 "parser.y"
                                        {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("new"));
        s.push_back((yyvsp[-1].ptr));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode("ArrayCreationExpression", s);
    }
#line 2249 "parser.tab.c"
    break;

  case 56: /* DimExpr: DimExpr '[' Expression ']'  */
#line 375 "parser.y"
                                {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-3].ptr));
        s.push_back((yyvsp[-1].ptr));
        
        
        (yyval.ptr) = makeNode("DimExpr", s);
    }
#line 2262 "parser.tab.c"
    break;

  case 57: /* DimExpr: '[' Expression ']'  */
#line 383 "parser.y"
                                {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-1].ptr));
        
        (yyval.ptr) = makeNode("DimExpr", s);
    }
#line 2273 "parser.tab.c"
    break;

  case 58: /* Expression: AssignmentExpression  */
#line 392 "parser.y"
                            {
        (yyval.ptr) = (yyvsp[0].ptr);
    }
#line 2281 "parser.tab.c"
    break;

  case 59: /* AssignmentExpression: ConditionalExpression  */
#line 398 "parser.y"
                                {
        (yyval.ptr) = (yyvsp[0].ptr);
    }
#line 2289 "parser.tab.c"
    break;

  case 60: /* AssignmentExpression: Assignment  */
#line 401 "parser.y"
                        {
        (yyval.ptr) = (yyvsp[0].ptr);
    }
#line 2297 "parser.tab.c"
    break;

  case 61: /* Assignment: LeftHandSide ASSIGNOP Expression  */
#line 407 "parser.y"
                                            {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-2].ptr));
        // s.push_back(makeLeaf(*$2));
        s.push_back((yyvsp[0].ptr));
        delete (yyvsp[-1].st);
        (yyval.ptr) = makeNode(*(yyvsp[-1].st), s);
    }
#line 2310 "parser.tab.c"
    break;

  case 62: /* Assignment: LeftHandSide '=' Expression  */
#line 415 "parser.y"
                                        {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-2].ptr));
        // s.push_back(makeLeaf("="));
        s.push_back((yyvsp[0].ptr));
        
        
        (yyval.ptr) = makeNode("=", s);
    }
#line 2324 "parser.tab.c"
    break;

  case 63: /* ConditionalExpression: ConditionalOrExpression  */
#line 427 "parser.y"
                                {
        (yyval.ptr) = (yyvsp[0].ptr);
    }
#line 2332 "parser.tab.c"
    break;

  case 64: /* ConditionalExpression: ConditionalOrExpression '?' Expression ':' ConditionalExpression  */
#line 430 "parser.y"
                                                                            {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-4].ptr));
        s.push_back(makeLeaf("?"));
        s.push_back((yyvsp[-2].ptr));
        s.push_back(makeLeaf(":"));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode("ConditionalExpression", s);
    }
#line 2346 "parser.tab.c"
    break;

  case 65: /* ConditionalOrExpression: ConditionalAndExpression  */
#line 442 "parser.y"
                                    {
        (yyval.ptr) = (yyvsp[0].ptr);
    }
#line 2354 "parser.tab.c"
    break;

  case 66: /* ConditionalOrExpression: ConditionalOrExpression CONDOR ConditionalAndExpression  */
#line 445 "parser.y"
                                                                    {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-2].ptr));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode("||", s);
    }
#line 2365 "parser.tab.c"
    break;

  case 67: /* ConditionalAndExpression: InclusiveOrExpression  */
#line 454 "parser.y"
                            {
        (yyval.ptr) = (yyvsp[0].ptr);
    }
#line 2373 "parser.tab.c"
    break;

  case 68: /* ConditionalAndExpression: ConditionalAndExpression CONDAND InclusiveOrExpression  */
#line 457 "parser.y"
                                                                    {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-2].ptr));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode("&&", s);
    }
#line 2384 "parser.tab.c"
    break;

  case 69: /* AndExpression: EqualityExpression  */
#line 466 "parser.y"
                            {
        (yyval.ptr) = (yyvsp[0].ptr);
    }
#line 2392 "parser.tab.c"
    break;

  case 70: /* AndExpression: AndExpression '&' EqualityExpression  */
#line 469 "parser.y"
                                                {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-2].ptr));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode("&", s);
    }
#line 2403 "parser.tab.c"
    break;

  case 71: /* ExclusiveOrExpression: AndExpression  */
#line 478 "parser.y"
                        {
        (yyval.ptr) = (yyvsp[0].ptr);
    }
#line 2411 "parser.tab.c"
    break;

  case 72: /* ExclusiveOrExpression: ExclusiveOrExpression '^' AndExpression  */
#line 481 "parser.y"
                                                    {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-2].ptr));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode("^", s);
    }
#line 2422 "parser.tab.c"
    break;

  case 73: /* InclusiveOrExpression: ExclusiveOrExpression  */
#line 490 "parser.y"
                                {
        (yyval.ptr) = (yyvsp[0].ptr);
    }
#line 2430 "parser.tab.c"
    break;

  case 74: /* InclusiveOrExpression: InclusiveOrExpression '|' ExclusiveOrExpression  */
#line 493 "parser.y"
                                                            {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-2].ptr));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode("|", s);
    }
#line 2441 "parser.tab.c"
    break;

  case 75: /* EqualityExpression: RelationalExpression  */
#line 502 "parser.y"
                            {
        (yyval.ptr) = (yyvsp[0].ptr);
    }
#line 2449 "parser.tab.c"
    break;

  case 76: /* EqualityExpression: EqualityExpression EQALITYOP RelationalExpression  */
#line 505 "parser.y"
                                                        {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-2].ptr));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode(*(yyvsp[-1].st), s);
        delete (yyvsp[-1].st);
    }
#line 2461 "parser.tab.c"
    break;

  case 77: /* RelationalExpression: ShiftExpression  */
#line 515 "parser.y"
                        {
        (yyval.ptr) = (yyvsp[0].ptr);
    }
#line 2469 "parser.tab.c"
    break;

  case 78: /* RelationalExpression: RelationalExpression RELATIONOP ShiftExpression  */
#line 518 "parser.y"
                                                            {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-2].ptr));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode(*(yyvsp[-1].st), s);
        delete (yyvsp[-1].st);
    }
#line 2481 "parser.tab.c"
    break;

  case 79: /* ShiftExpression: AdditiveExpression  */
#line 528 "parser.y"
                            {
        (yyval.ptr) = (yyvsp[0].ptr);
    }
#line 2489 "parser.tab.c"
    break;

  case 80: /* ShiftExpression: ShiftExpression SHIFTOP AdditiveExpression  */
#line 531 "parser.y"
                                                    {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-2].ptr));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode(*(yyvsp[-1].st), s);
        delete (yyvsp[-1].st);
    }
#line 2501 "parser.tab.c"
    break;

  case 81: /* AdditiveExpression: MultiplicativeExpression  */
#line 541 "parser.y"
                                    {
        (yyval.ptr) = (yyvsp[0].ptr);
    }
#line 2509 "parser.tab.c"
    break;

  case 82: /* AdditiveExpression: AdditiveExpression ADDOP MultiplicativeExpression  */
#line 544 "parser.y"
                                                            {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-2].ptr));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode(*(yyvsp[-1].st), s);
        delete (yyvsp[-1].st);
    }
#line 2521 "parser.tab.c"
    break;

  case 83: /* MultiplicativeExpression: UnaryExpression  */
#line 554 "parser.y"
                        {
        (yyval.ptr) = (yyvsp[0].ptr);      
    }
#line 2529 "parser.tab.c"
    break;

  case 84: /* MultiplicativeExpression: MultiplicativeExpression MULTOP UnaryExpression  */
#line 557 "parser.y"
                                                            {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-2].ptr));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode(*(yyvsp[-1].st), s);
        delete (yyvsp[-1].st);
    }
#line 2541 "parser.tab.c"
    break;

  case 85: /* UnaryExpression: ADDOP2 UnaryExpression  */
#line 567 "parser.y"
                                {
        vector<ASTNode*> s;
        s.push_back((yyvsp[0].ptr));        
        (yyval.ptr) = makeNode(*(yyvsp[-1].st), s);
        delete (yyvsp[-1].st);
    }
#line 2552 "parser.tab.c"
    break;

  case 86: /* UnaryExpression: ADDOP UnaryExpression  */
#line 573 "parser.y"
                                {
        vector<ASTNode*> s;
        s.push_back((yyvsp[0].ptr));        
        (yyval.ptr) = makeNode(*(yyvsp[-1].st), s);
        delete (yyvsp[-1].st);
    }
#line 2563 "parser.tab.c"
    break;

  case 87: /* UnaryExpression: UnaryExpressionNotPlusMinus  */
#line 579 "parser.y"
                                    {
        (yyval.ptr) = (yyvsp[0].ptr);
    }
#line 2571 "parser.tab.c"
    break;

  case 88: /* UnaryExpression: CastExpression  */
#line 582 "parser.y"
                            {
        (yyval.ptr)=(yyvsp[0].ptr);
    }
#line 2579 "parser.tab.c"
    break;

  case 89: /* UnaryExpressionNotPlusMinus: PostfixExpression  */
#line 588 "parser.y"
                        {
        (yyval.ptr) = (yyvsp[0].ptr);
    }
#line 2587 "parser.tab.c"
    break;

  case 90: /* UnaryExpressionNotPlusMinus: UNARYOP UnaryExpression  */
#line 591 "parser.y"
                                {
        vector<ASTNode*> s;
        s.push_back((yyvsp[0].ptr));        
        (yyval.ptr) = makeNode(*(yyvsp[-1].st), s);
        delete (yyvsp[-1].st);
    }
#line 2598 "parser.tab.c"
    break;

  case 91: /* CastExpression: '(' PrimitiveType ')' UnaryExpression  */
#line 600 "parser.y"
                                            {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-2].ptr));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode("CastExpression", s);
    }
#line 2609 "parser.tab.c"
    break;

  case 92: /* PostfixExpression: Primary  */
#line 609 "parser.y"
            {
        (yyval.ptr) = (yyvsp[0].ptr);
    }
#line 2617 "parser.tab.c"
    break;

  case 93: /* PostfixExpression: IDENdotIDEN  */
#line 612 "parser.y"
                        {
        (yyval.ptr) = (yyvsp[0].ptr);
    }
#line 2625 "parser.tab.c"
    break;

  case 94: /* PostfixExpression: PostfixExpression ADDOP2  */
#line 615 "parser.y"
                                    {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-1].ptr));
        (yyval.ptr) = makeNode(*(yyvsp[0].st), s);
        delete (yyvsp[0].st);
    }
#line 2636 "parser.tab.c"
    break;

  case 95: /* Block: '{' BlockStatements '}'  */
#line 627 "parser.y"
                            {
        (yyval.ptr)=(yyvsp[-1].ptr);
    }
#line 2644 "parser.tab.c"
    break;

  case 96: /* BlockStatements: BlockStatements BlockStatement  */
#line 633 "parser.y"
                                   {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-1].ptr));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode("BlockStatements", s);
    }
#line 2655 "parser.tab.c"
    break;

  case 97: /* BlockStatements: %empty  */
#line 639 "parser.y"
            {
        (yyval.ptr)=NULL;
    }
#line 2663 "parser.tab.c"
    break;

  case 98: /* BlockStatement: LocalVariableDeclaration ';'  */
#line 645 "parser.y"
                                 {
        (yyval.ptr)=(yyvsp[-1].ptr);
    }
#line 2671 "parser.tab.c"
    break;

  case 99: /* BlockStatement: Statement  */
#line 648 "parser.y"
                {
        (yyval.ptr)=(yyvsp[0].ptr);
    }
#line 2679 "parser.tab.c"
    break;

  case 100: /* LocalVariableDeclaration: LocalVariableType VariableDeclaratorList  */
#line 654 "parser.y"
                                             {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-1].ptr));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode("LocalVariableDeclaration", s);
    }
#line 2690 "parser.tab.c"
    break;

  case 101: /* LocalVariableType: Type  */
#line 663 "parser.y"
         {
        (yyval.ptr)=(yyvsp[0].ptr);
    }
#line 2698 "parser.tab.c"
    break;

  case 102: /* LocalVariableType: KEY_VAR  */
#line 666 "parser.y"
              {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("var"));
        (yyval.ptr) = makeNode("LocalVariableType", s);
    }
#line 2708 "parser.tab.c"
    break;

  case 103: /* Statement: StatementWithoutTrailingSubstatement  */
#line 674 "parser.y"
                                         {
        (yyval.ptr)=(yyvsp[0].ptr);
    }
#line 2716 "parser.tab.c"
    break;

  case 104: /* Statement: IDENTIFIER ':' Statement  */
#line 677 "parser.y"
                               {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("IDENTIFIER (" + *(yyvsp[-2].st)+")" ));
        delete (yyvsp[-2].st);
        s.push_back(makeLeaf(":"));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode("Statement", s);
    }
#line 2729 "parser.tab.c"
    break;

  case 105: /* Statement: KEY_if '(' Expression ')' Statement  */
#line 685 "parser.y"
                                          {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("if"));
        s.push_back((yyvsp[-2].ptr));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode("Statement", s);
    }
#line 2741 "parser.tab.c"
    break;

  case 106: /* Statement: KEY_if '(' Expression ')' StatementNoShortIf KEY_else Statement  */
#line 692 "parser.y"
                                                                      {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("if"));
        s.push_back((yyvsp[-4].ptr));
        s.push_back((yyvsp[-2].ptr));
        s.push_back(makeLeaf("else"));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode("Statement", s);
    }
#line 2755 "parser.tab.c"
    break;

  case 107: /* Statement: KEY_while '(' Expression ')' Statement  */
#line 701 "parser.y"
                                             {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("while"));
        s.push_back((yyvsp[-2].ptr));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode("Statement", s);
    }
#line 2767 "parser.tab.c"
    break;

  case 108: /* Statement: ForStatement  */
#line 708 "parser.y"
                   {
        (yyval.ptr)=(yyvsp[0].ptr);
    }
#line 2775 "parser.tab.c"
    break;

  case 109: /* StatementNoShortIf: StatementWithoutTrailingSubstatement  */
#line 714 "parser.y"
                                         {
        (yyval.ptr)=(yyvsp[0].ptr);
    }
#line 2783 "parser.tab.c"
    break;

  case 110: /* StatementNoShortIf: IDENTIFIER ':' StatementNoShortIf  */
#line 717 "parser.y"
                                        {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("IDENTIFIER (" + *(yyvsp[-2].st)+")" ));
        delete (yyvsp[-2].st);
        s.push_back(makeLeaf(":"));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode("StatementNoShortIf", s);
    }
#line 2796 "parser.tab.c"
    break;

  case 111: /* StatementNoShortIf: KEY_if '(' Expression ')' StatementNoShortIf KEY_else StatementNoShortIf  */
#line 725 "parser.y"
                                                                               {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("if"));
        s.push_back((yyvsp[-4].ptr));
        s.push_back((yyvsp[-2].ptr));
        s.push_back(makeLeaf("else"));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode("StatementNoShortIf", s);
    }
#line 2810 "parser.tab.c"
    break;

  case 112: /* StatementNoShortIf: KEY_while '(' Expression ')' StatementNoShortIf  */
#line 734 "parser.y"
                                                      {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("while"));
        s.push_back((yyvsp[-2].ptr));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode("StatementNoShortIf", s);
    }
#line 2822 "parser.tab.c"
    break;

  case 113: /* StatementNoShortIf: ForStatementNoShortIf  */
#line 741 "parser.y"
                            {
        (yyval.ptr)=(yyvsp[0].ptr);
    }
#line 2830 "parser.tab.c"
    break;

  case 114: /* StatementWithoutTrailingSubstatement: Block  */
#line 747 "parser.y"
            {
        (yyval.ptr)=(yyvsp[0].ptr);
    }
#line 2838 "parser.tab.c"
    break;

  case 115: /* StatementWithoutTrailingSubstatement: ';'  */
#line 750 "parser.y"
          {
        (yyval.ptr)=NULL;
    }
#line 2846 "parser.tab.c"
    break;

  case 116: /* StatementWithoutTrailingSubstatement: StatementExpression ';'  */
#line 753 "parser.y"
                              {
        (yyval.ptr)=(yyvsp[-1].ptr);
    }
#line 2854 "parser.tab.c"
    break;

  case 117: /* StatementWithoutTrailingSubstatement: AssertStatement  */
#line 756 "parser.y"
                      {
        (yyval.ptr)=(yyvsp[0].ptr);
    }
#line 2862 "parser.tab.c"
    break;

  case 118: /* StatementWithoutTrailingSubstatement: BreakContinueStatement  */
#line 759 "parser.y"
                             {
        (yyval.ptr)=(yyvsp[0].ptr);
    }
#line 2870 "parser.tab.c"
    break;

  case 119: /* StatementWithoutTrailingSubstatement: KEY_return ';'  */
#line 762 "parser.y"
                     {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("return"));
        (yyval.ptr) = makeNode("StatementWithoutTrailingSubstatement", s);
    }
#line 2880 "parser.tab.c"
    break;

  case 120: /* StatementWithoutTrailingSubstatement: KEY_return Expression ';'  */
#line 767 "parser.y"
                                {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("return"));
        s.push_back((yyvsp[-1].ptr));
        (yyval.ptr) = makeNode("StatementWithoutTrailingSubstatement", s);
    }
#line 2891 "parser.tab.c"
    break;

  case 121: /* StatementWithoutTrailingSubstatement: KEY_yield Expression ';'  */
#line 773 "parser.y"
                               {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("yield"));
        s.push_back((yyvsp[-1].ptr));
        (yyval.ptr) = makeNode("StatementWithoutTrailingSubstatement", s);
    }
#line 2902 "parser.tab.c"
    break;

  case 122: /* StatementWithoutTrailingSubstatement: KEY_throw Expression ';'  */
#line 779 "parser.y"
                               {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("throw"));
        s.push_back((yyvsp[-1].ptr));
        (yyval.ptr) = makeNode("StatementWithoutTrailingSubstatement", s);
    }
#line 2913 "parser.tab.c"
    break;

  case 123: /* StatementWithoutTrailingSubstatement: KEY_sync '(' Expression ')' Block  */
#line 785 "parser.y"
                                        {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("sync"));
        s.push_back((yyvsp[-2].ptr));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode("StatementWithoutTrailingSubstatement", s);
    }
#line 2925 "parser.tab.c"
    break;

  case 124: /* StatementExpression: Assignment  */
#line 795 "parser.y"
               {
        (yyval.ptr)=(yyvsp[0].ptr);
    }
#line 2933 "parser.tab.c"
    break;

  case 125: /* StatementExpression: MethodInvocation  */
#line 798 "parser.y"
                       {
        (yyval.ptr)=(yyvsp[0].ptr);
    }
#line 2941 "parser.tab.c"
    break;

  case 126: /* StatementExpression: ADDOP2 UnaryExpression  */
#line 801 "parser.y"
                             {
        vector<ASTNode*> s;
        s.push_back(makeLeaf(*(yyvsp[-1].st)));
        delete (yyvsp[-1].st);
        (yyval.ptr) = makeNode("StatementExpression", s);
    }
#line 2952 "parser.tab.c"
    break;

  case 127: /* StatementExpression: PostfixExpression ADDOP2  */
#line 807 "parser.y"
                               {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-1].ptr));
        s.push_back(makeLeaf(*(yyvsp[0].st)));
        delete (yyvsp[0].st);
        (yyval.ptr) = makeNode("StatementExpression", s);
    }
#line 2964 "parser.tab.c"
    break;

  case 128: /* LeftHandSide: IDENdotIDEN  */
#line 818 "parser.y"
                {
        (yyval.ptr)=(yyvsp[0].ptr);
    }
#line 2972 "parser.tab.c"
    break;

  case 129: /* LeftHandSide: FieldAccess  */
#line 821 "parser.y"
                  {
        (yyval.ptr)=(yyvsp[0].ptr);
    }
#line 2980 "parser.tab.c"
    break;

  case 130: /* LeftHandSide: ArrayAccess  */
#line 824 "parser.y"
                  {
        (yyval.ptr)=(yyvsp[0].ptr);
    }
#line 2988 "parser.tab.c"
    break;

  case 131: /* AssertStatement: KEY_assert Expression ';'  */
#line 830 "parser.y"
                              {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("assert"));
        s.push_back((yyvsp[-1].ptr));
        (yyval.ptr) = makeNode("AssertStatement", s);
    }
#line 2999 "parser.tab.c"
    break;

  case 132: /* AssertStatement: KEY_assert Expression ':' Expression ';'  */
#line 836 "parser.y"
                                               {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("assert"));
        s.push_back((yyvsp[-3].ptr));
        s.push_back(makeLeaf(":"));
        s.push_back((yyvsp[-1].ptr));
        (yyval.ptr) = makeNode("AssertStatement", s);
    }
#line 3012 "parser.tab.c"
    break;

  case 133: /* BreakContinueStatement: KEY_break IDENTIFIER ';'  */
#line 847 "parser.y"
                             {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("break"));
        s.push_back(makeLeaf("IDENTIFIER (" + *(yyvsp[-1].st)+")" ));
        delete (yyvsp[-1].st);
        (yyval.ptr) = makeNode("BreakContinueStatement", s);
    }
#line 3024 "parser.tab.c"
    break;

  case 134: /* BreakContinueStatement: KEY_break ';'  */
#line 854 "parser.y"
                    {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("break"));
        (yyval.ptr) = makeNode("BreakContinueStatement", s);
    }
#line 3034 "parser.tab.c"
    break;

  case 135: /* BreakContinueStatement: KEY_continue IDENTIFIER ';'  */
#line 859 "parser.y"
                                  {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("continue"));
        s.push_back(makeLeaf("IDENTIFIER (" + *(yyvsp[-1].st)+")" ));
        delete (yyvsp[-1].st);
        (yyval.ptr) = makeNode("BreakContinueStatement", s);
    }
#line 3046 "parser.tab.c"
    break;

  case 136: /* BreakContinueStatement: KEY_continue ';'  */
#line 866 "parser.y"
                       {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("continue"));
        (yyval.ptr) = makeNode("BreakContinueStatement", s);
    }
#line 3056 "parser.tab.c"
    break;

  case 137: /* ForStatement: KEY_for '(' ForInit ';' ';' ')' Statement  */
#line 874 "parser.y"
                                              {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("for"));
        s.push_back((yyvsp[-4].ptr));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode("ForStatement", s);
    }
#line 3068 "parser.tab.c"
    break;

  case 138: /* ForStatement: KEY_for '(' ForInit ';' Expression ';' ')' Statement  */
#line 881 "parser.y"
                                                           {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("for"));
        s.push_back((yyvsp[-5].ptr));
        s.push_back((yyvsp[-3].ptr));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode("ForStatement", s);
    }
#line 3081 "parser.tab.c"
    break;

  case 139: /* ForStatement: KEY_for '(' ForInit ';' ';' StatementExpressionList ')' Statement  */
#line 889 "parser.y"
                                                                        {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("for"));
        s.push_back((yyvsp[-5].ptr));
        s.push_back((yyvsp[-2].ptr));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode("ForStatement", s);
    }
#line 3094 "parser.tab.c"
    break;

  case 140: /* ForStatement: KEY_for '(' ForInit ';' Expression ';' StatementExpressionList ')' Statement  */
#line 897 "parser.y"
                                                                                   {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("for"));
        s.push_back((yyvsp[-6].ptr));
        s.push_back((yyvsp[-4].ptr));
        s.push_back((yyvsp[-2].ptr));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode("ForStatement", s);
    }
#line 3108 "parser.tab.c"
    break;

  case 141: /* ForStatementNoShortIf: KEY_for '(' ForInit ';' ';' ')' StatementNoShortIf  */
#line 910 "parser.y"
                                                       {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("for"));
        s.push_back((yyvsp[-4].ptr));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode("ForStatementNoShortIf", s);
    }
#line 3120 "parser.tab.c"
    break;

  case 142: /* ForStatementNoShortIf: KEY_for '(' ForInit ';' Expression ';' ')' StatementNoShortIf  */
#line 917 "parser.y"
                                                                    {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("for"));
        s.push_back((yyvsp[-5].ptr));
        s.push_back((yyvsp[-3].ptr));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode("ForStatementNoShortIf", s);
    }
#line 3133 "parser.tab.c"
    break;

  case 143: /* ForStatementNoShortIf: KEY_for '(' ForInit ';' ';' StatementExpressionList ')' StatementNoShortIf  */
#line 925 "parser.y"
                                                                                 {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("for"));
        s.push_back((yyvsp[-5].ptr));
        s.push_back((yyvsp[-2].ptr));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode("ForStatementNoShortIf", s);
    }
#line 3146 "parser.tab.c"
    break;

  case 144: /* ForStatementNoShortIf: KEY_for '(' ForInit ';' Expression ';' StatementExpressionList ')' StatementNoShortIf  */
#line 933 "parser.y"
                                                                                            {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("for"));
        s.push_back((yyvsp[-6].ptr));
        s.push_back((yyvsp[-4].ptr));
        s.push_back((yyvsp[-2].ptr));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode("ForStatementNoShortIf", s);
    }
#line 3160 "parser.tab.c"
    break;

  case 145: /* ForInit: StatementExpressionList  */
#line 946 "parser.y"
                            {
        vector<ASTNode*> s;
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode("ForInit", s);
    }
#line 3170 "parser.tab.c"
    break;

  case 146: /* ForInit: LocalVariableDeclaration  */
#line 951 "parser.y"
                               {
        vector<ASTNode*> s;
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode("ForInit", s);
    }
#line 3180 "parser.tab.c"
    break;

  case 147: /* ForInit: %empty  */
#line 956 "parser.y"
        {
        (yyval.ptr)=NULL;
    }
#line 3188 "parser.tab.c"
    break;

  case 148: /* StatementExpressionList: StatementExpressionList ',' StatementExpression  */
#line 962 "parser.y"
                                                     {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-2].ptr));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode("StatementExpressionList", s);
    }
#line 3199 "parser.tab.c"
    break;

  case 149: /* StatementExpressionList: StatementExpression  */
#line 968 "parser.y"
                          {
        (yyval.ptr)=(yyvsp[0].ptr);
    }
#line 3207 "parser.tab.c"
    break;

  case 150: /* ClassDeclaration: NormalClassDeclaration  */
#line 977 "parser.y"
                           {
        (yyval.ptr)=(yyvsp[0].ptr);
    }
#line 3215 "parser.tab.c"
    break;

  case 151: /* NormalClassDeclaration: Modifiers KEY_class IDENTIFIER ClassBody  */
#line 982 "parser.y"
                                             {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-3].ptr));
        s.push_back(makeLeaf("class"));
        s.push_back(makeLeaf("IDENTIFIER (" + *(yyvsp[-1].st)+")" ));
        delete (yyvsp[-1].st);
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode("NormalClassDeclaration", s);
    }
#line 3229 "parser.tab.c"
    break;

  case 152: /* NormalClassDeclaration: Modifiers KEY_class IDENTIFIER ClassExtends ClassBody  */
#line 991 "parser.y"
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
#line 3244 "parser.tab.c"
    break;

  case 153: /* NormalClassDeclaration: Modifiers KEY_class IDENTIFIER ClassPermits ClassBody  */
#line 1001 "parser.y"
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
#line 3259 "parser.tab.c"
    break;

  case 154: /* NormalClassDeclaration: Modifiers KEY_class IDENTIFIER ClassExtends ClassPermits ClassBody  */
#line 1011 "parser.y"
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
#line 3275 "parser.tab.c"
    break;

  case 155: /* ClassExtends: KEY_extends ClassType  */
#line 1024 "parser.y"
                          {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("extends"));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode("ClassExtends", s);
    }
#line 3286 "parser.tab.c"
    break;

  case 156: /* ClassPermits: KEY_permits IDENdotIDEN cTypeName  */
#line 1032 "parser.y"
                                      {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("permits"));
        s.push_back((yyvsp[-1].ptr));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode("ClassPermits", s);
    }
#line 3298 "parser.tab.c"
    break;

  case 157: /* cTypeName: cTypeName ',' IDENdotIDEN  */
#line 1042 "parser.y"
                              {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-2].ptr));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode("cTypeName", s);
    }
#line 3309 "parser.tab.c"
    break;

  case 158: /* cTypeName: %empty  */
#line 1048 "parser.y"
        {
        (yyval.ptr)=NULL;
    }
#line 3317 "parser.tab.c"
    break;

  case 159: /* ClassBody: '{' ClassBodyDeclarations '}'  */
#line 1054 "parser.y"
                                  {
        (yyval.ptr)=(yyvsp[-1].ptr);
    }
#line 3325 "parser.tab.c"
    break;

  case 160: /* ClassBodyDeclarations: ClassBodyDeclarations ClassBodyDeclaration  */
#line 1059 "parser.y"
                                               {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-1].ptr));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode("ClassBodyDeclarations", s);
    }
#line 3336 "parser.tab.c"
    break;

  case 161: /* ClassBodyDeclarations: %empty  */
#line 1065 "parser.y"
        {
        (yyval.ptr)=NULL;
    }
#line 3344 "parser.tab.c"
    break;

  case 162: /* ClassBodyDeclaration: Modifiers Type VariableDeclaratorList ';'  */
#line 1070 "parser.y"
                                              {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-3].ptr));
        s.push_back((yyvsp[-2].ptr));
        s.push_back((yyvsp[-1].ptr));
        (yyval.ptr) = makeNode("ClassBodyDeclaration", s);
    }
#line 3356 "parser.tab.c"
    break;

  case 163: /* ClassBodyDeclaration: ClassDeclaration  */
#line 1077 "parser.y"
                       {
        (yyval.ptr)=(yyvsp[0].ptr);
    }
#line 3364 "parser.tab.c"
    break;

  case 164: /* ClassBodyDeclaration: ';'  */
#line 1080 "parser.y"
          {
        (yyval.ptr)=NULL;
    }
#line 3372 "parser.tab.c"
    break;

  case 165: /* ClassBodyDeclaration: Block  */
#line 1083 "parser.y"
            {
        (yyval.ptr)=(yyvsp[0].ptr);
    }
#line 3380 "parser.tab.c"
    break;

  case 166: /* ClassBodyDeclaration: Modifiers IdenPara Block  */
#line 1086 "parser.y"
                               {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-2].ptr));
        s.push_back((yyvsp[-1].ptr));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode("ClassBodyDeclaration", s);
    }
#line 3392 "parser.tab.c"
    break;

  case 167: /* ClassBodyDeclaration: MethodDeclaration  */
#line 1093 "parser.y"
                        {
        (yyval.ptr)=(yyvsp[0].ptr);
    }
#line 3400 "parser.tab.c"
    break;

  case 168: /* VariableDeclaratorList: VariableDeclaratorList ',' VariableDeclarator  */
#line 1099 "parser.y"
                                                  {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-2].ptr));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode("VariableDeclaratorList", s);
    }
#line 3411 "parser.tab.c"
    break;

  case 169: /* VariableDeclaratorList: VariableDeclarator  */
#line 1105 "parser.y"
                         {
        (yyval.ptr)=(yyvsp[0].ptr);
    }
#line 3419 "parser.tab.c"
    break;

  case 170: /* VariableDeclarator: VariableDeclarator1  */
#line 1111 "parser.y"
                        {
        (yyval.ptr)=(yyvsp[0].ptr);
    }
#line 3427 "parser.tab.c"
    break;

  case 171: /* VariableDeclarator: VariableDeclarator2  */
#line 1114 "parser.y"
                          {
        (yyval.ptr)=(yyvsp[0].ptr);
    }
#line 3435 "parser.tab.c"
    break;

  case 172: /* zerooroneExpression: Expression  */
#line 1120 "parser.y"
               {
        (yyval.ptr)=(yyvsp[0].ptr);
    }
#line 3443 "parser.tab.c"
    break;

  case 173: /* zerooroneExpression: %empty  */
#line 1123 "parser.y"
        {(yyval.ptr)=NULL;}
#line 3449 "parser.tab.c"
    break;

  case 174: /* VariableDeclarator1: IDENTIFIER  */
#line 1127 "parser.y"
               {
       (yyval.ptr) = makeLeaf("IDENTIFIER (" + *(yyvsp[0].st) +")");
       delete (yyvsp[0].st);
    }
#line 3458 "parser.tab.c"
    break;

  case 175: /* VariableDeclarator1: IDENTIFIER '[' zerooroneExpression ']'  */
#line 1131 "parser.y"
                                             {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("IDENTIFIER (" + *(yyvsp[-3].st) +")" ));
        delete (yyvsp[-3].st);
        s.push_back((yyvsp[-1].ptr));
        (yyval.ptr) = makeNode("VariableDeclarator1", s);
    }
#line 3470 "parser.tab.c"
    break;

  case 176: /* VariableDeclarator1: IDENTIFIER '[' zerooroneExpression ']' '[' zerooroneExpression ']'  */
#line 1138 "parser.y"
                                                                         {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("IDENTIFIER (" + *(yyvsp[-6].st) +")" ));
        delete (yyvsp[-6].st);
        s.push_back((yyvsp[-4].ptr));
        s.push_back((yyvsp[-1].ptr));
        (yyval.ptr) = makeNode("VariableDeclarator1", s);
    }
#line 3483 "parser.tab.c"
    break;

  case 177: /* VariableDeclarator1: IDENTIFIER '[' zerooroneExpression ']' '[' zerooroneExpression ']' '[' zerooroneExpression ']'  */
#line 1146 "parser.y"
                                                                                                     {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("IDENTIFIER (" + *(yyvsp[-9].st)+")" ));
        delete (yyvsp[-9].st);
        s.push_back((yyvsp[-7].ptr));
        s.push_back((yyvsp[-4].ptr));
        s.push_back((yyvsp[-1].ptr));
        (yyval.ptr) = makeNode("VariableDeclarator1", s);
    }
#line 3497 "parser.tab.c"
    break;

  case 178: /* VariableDeclarator2: IDENTIFIER '=' Expression  */
#line 1158 "parser.y"
                              {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("IDENTIFIER (" + *(yyvsp[-2].st)+")" ));
        delete (yyvsp[-2].st);
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode("=",s);
    }
#line 3509 "parser.tab.c"
    break;

  case 179: /* VariableDeclarator2: IDENTIFIER '[' zerooroneExpression ']' '=' List1  */
#line 1165 "parser.y"
                                                       {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("IDENTIFIER (" + *(yyvsp[-5].st)+")" ));
        delete (yyvsp[-5].st);
        s.push_back((yyvsp[-3].ptr));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode("=", s);
    }
#line 3522 "parser.tab.c"
    break;

  case 180: /* VariableDeclarator2: IDENTIFIER '[' zerooroneExpression ']' '[' zerooroneExpression ']' '=' List2  */
#line 1173 "parser.y"
                                                                                   {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("IDENTIFIER (" + *(yyvsp[-8].st)+")" ));
        delete (yyvsp[-8].st);
        s.push_back((yyvsp[-6].ptr));
        s.push_back((yyvsp[-3].ptr));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode("=", s);
    }
#line 3536 "parser.tab.c"
    break;

  case 181: /* VariableDeclarator2: IDENTIFIER '[' zerooroneExpression ']' '[' zerooroneExpression ']' '[' zerooroneExpression ']' '=' List3  */
#line 1182 "parser.y"
                                                                                                               {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("IDENTIFIER (" + *(yyvsp[-11].st)+")" ));
        delete (yyvsp[-11].st);
        s.push_back((yyvsp[-9].ptr));
        s.push_back((yyvsp[-6].ptr));
        s.push_back((yyvsp[-3].ptr));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode("=", s);
    }
#line 3551 "parser.tab.c"
    break;

  case 182: /* VariableDeclarator2: IDENTIFIER '[' zerooroneExpression ']' '=' KEY_new PrimitiveType '[' ']' List1  */
#line 1192 "parser.y"
                                                                                     {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("IDENTIFIER (" + *(yyvsp[-9].st)+")" ));
        delete (yyvsp[-9].st);
        s.push_back((yyvsp[-7].ptr));
        s.push_back(makeLeaf("new"));
        s.push_back((yyvsp[-3].ptr));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode("=", s);
    }
#line 3566 "parser.tab.c"
    break;

  case 183: /* VariableDeclarator2: IDENTIFIER '[' zerooroneExpression ']' '[' zerooroneExpression ']' '=' KEY_new PrimitiveType '[' ']' '[' ']' List2  */
#line 1202 "parser.y"
                                                                                                                         {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("IDENTIFIER (" + *(yyvsp[-14].st)+")" ));
        delete (yyvsp[-14].st);
        s.push_back((yyvsp[-12].ptr));
        s.push_back((yyvsp[-9].ptr));
        s.push_back(makeLeaf("new"));
        s.push_back((yyvsp[-5].ptr));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode("=", s);
    }
#line 3582 "parser.tab.c"
    break;

  case 184: /* VariableDeclarator2: IDENTIFIER '[' zerooroneExpression ']' '[' zerooroneExpression ']' '[' zerooroneExpression ']' '=' KEY_new PrimitiveType '[' ']' '[' ']' '[' ']' List3  */
#line 1213 "parser.y"
                                                                                                                                                             {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("IDENTIFIER (" + *(yyvsp[-19].st)+")" ));
        delete (yyvsp[-19].st);
        s.push_back((yyvsp[-17].ptr));
        s.push_back((yyvsp[-14].ptr));
        s.push_back((yyvsp[-11].ptr));
        s.push_back(makeLeaf("new"));
        s.push_back((yyvsp[-7].ptr));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode("=", s);
    }
#line 3599 "parser.tab.c"
    break;

  case 185: /* List1: '{' ArrEle1 '}'  */
#line 1228 "parser.y"
                    {
        (yyval.ptr)=(yyvsp[-1].ptr);
    }
#line 3607 "parser.tab.c"
    break;

  case 186: /* ArrEle1: ArrEle1 ',' Expression  */
#line 1234 "parser.y"
                           {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-2].ptr));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode("ArrEle1", s);
    }
#line 3618 "parser.tab.c"
    break;

  case 187: /* ArrEle1: Expression  */
#line 1240 "parser.y"
                 {
       (yyval.ptr)=(yyvsp[0].ptr);
    }
#line 3626 "parser.tab.c"
    break;

  case 188: /* List2: '{' ArrEle2 '}'  */
#line 1246 "parser.y"
                    {
        (yyval.ptr)=(yyvsp[-1].ptr);
    }
#line 3634 "parser.tab.c"
    break;

  case 189: /* ArrEle2: ArrEle2 ',' List1  */
#line 1252 "parser.y"
                      {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-2].ptr));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode("ArrEle2", s);
    }
#line 3645 "parser.tab.c"
    break;

  case 190: /* ArrEle2: List1  */
#line 1258 "parser.y"
            {
        (yyval.ptr)=(yyvsp[0].ptr);
    }
#line 3653 "parser.tab.c"
    break;

  case 191: /* List3: '{' ArrEle3 '}'  */
#line 1264 "parser.y"
                    {
        (yyval.ptr)=(yyvsp[-1].ptr);
    }
#line 3661 "parser.tab.c"
    break;

  case 192: /* ArrEle3: ArrEle3 ',' List2  */
#line 1270 "parser.y"
                      {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-2].ptr));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode("ArrEle3", s);
    }
#line 3672 "parser.tab.c"
    break;

  case 193: /* ArrEle3: List2  */
#line 1276 "parser.y"
            {
        (yyval.ptr)=(yyvsp[0].ptr);
    }
#line 3680 "parser.tab.c"
    break;

  case 194: /* MethodDeclaration: Modifiers MethodHeader MethodBody  */
#line 1282 "parser.y"
                                      {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-2].ptr));
        s.push_back((yyvsp[-1].ptr));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode("MethodDeclaration", s);
    }
#line 3692 "parser.tab.c"
    break;

  case 195: /* MethodHeader: Type Methodeclarator  */
#line 1292 "parser.y"
                         {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-1].ptr));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode("MethodHeader", s);
    }
#line 3703 "parser.tab.c"
    break;

  case 196: /* MethodHeader: KEY_void Methodeclarator  */
#line 1298 "parser.y"
                               {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("void"));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode("MethodHeader", s);
    }
#line 3714 "parser.tab.c"
    break;

  case 197: /* Methodeclarator: IdenPara Dims  */
#line 1307 "parser.y"
                  {
        (yyval.ptr)=(yyvsp[-1].ptr);
    }
#line 3722 "parser.tab.c"
    break;

  case 198: /* Methodeclarator: IdenPara  */
#line 1310 "parser.y"
               {
        (yyval.ptr)=(yyvsp[0].ptr);
    }
#line 3730 "parser.tab.c"
    break;

  case 199: /* IdenPara: IDENTIFIER '(' formalparameters ')'  */
#line 1316 "parser.y"
                                        {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("IDENTIFIER (" + *(yyvsp[-3].st)+")" ));
        delete (yyvsp[-3].st);
        s.push_back((yyvsp[-1].ptr));
        (yyval.ptr) = makeNode("IdenPara", s);
    }
#line 3742 "parser.tab.c"
    break;

  case 200: /* IdenPara: IDENTIFIER '(' ')'  */
#line 1323 "parser.y"
                         {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("IDENTIFIER (" + *(yyvsp[-2].st)+")" ));
        delete (yyvsp[-2].st);
        (yyval.ptr) = makeNode("IdenPara", s);
    }
#line 3753 "parser.tab.c"
    break;

  case 201: /* formalparameters: formalparameters ',' formalparameter  */
#line 1331 "parser.y"
                                         {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-2].ptr));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode("formalparameters", s);
    }
#line 3764 "parser.tab.c"
    break;

  case 202: /* formalparameters: formalparameter  */
#line 1337 "parser.y"
                      {
        (yyval.ptr)=(yyvsp[0].ptr);
    }
#line 3772 "parser.tab.c"
    break;

  case 203: /* formalparameter: Type VariableDeclarator1  */
#line 1343 "parser.y"
                             {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-1].ptr));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode("formalparameter", s);
    }
#line 3783 "parser.tab.c"
    break;

  case 204: /* formalparameter: Type DOT3 IDENTIFIER  */
#line 1349 "parser.y"
                           {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-2].ptr));
        s.push_back(makeLeaf(*(yyvsp[-1].st)));
        delete (yyvsp[-1].st);
        s.push_back(makeLeaf("IDENTIFIER (" + *(yyvsp[0].st)+")" ));
        delete (yyvsp[0].st);
        (yyval.ptr) = makeNode("formalparameter", s);
    }
#line 3797 "parser.tab.c"
    break;

  case 205: /* MethodBody: Block  */
#line 1361 "parser.y"
          {
        (yyval.ptr)=(yyvsp[0].ptr);
    }
#line 3805 "parser.tab.c"
    break;

  case 206: /* MethodBody: ';'  */
#line 1364 "parser.y"
          {
        (yyval.ptr)=NULL;
    }
#line 3813 "parser.tab.c"
    break;

  case 207: /* Modifiers: Modifiers PublicPrivateStatic  */
#line 1370 "parser.y"
                                  {
        vector<ASTNode*> s;
        s.push_back((yyvsp[-1].ptr));
        s.push_back((yyvsp[0].ptr));
        (yyval.ptr) = makeNode("Modifiers", s);
    }
#line 3824 "parser.tab.c"
    break;

  case 208: /* Modifiers: %empty  */
#line 1376 "parser.y"
        {(yyval.ptr)=NULL;}
#line 3830 "parser.tab.c"
    break;


#line 3834 "parser.tab.c"

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

#line 1380 "parser.y"


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
