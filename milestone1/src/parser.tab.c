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
  YYSYMBOL_KEY_record = 29,                /* KEY_record  */
  YYSYMBOL_KEY_while = 30,                 /* KEY_while  */
  YYSYMBOL_KEY_sync = 31,                  /* KEY_sync  */
  YYSYMBOL_KEY_final = 32,                 /* KEY_final  */
  YYSYMBOL_KEY_extends = 33,               /* KEY_extends  */
  YYSYMBOL_KEY_super = 34,                 /* KEY_super  */
  YYSYMBOL_KEY_this = 35,                  /* KEY_this  */
  YYSYMBOL_KEY_class = 36,                 /* KEY_class  */
  YYSYMBOL_KEY_void = 37,                  /* KEY_void  */
  YYSYMBOL_KEY_public = 38,                /* KEY_public  */
  YYSYMBOL_KEY_new = 39,                   /* KEY_new  */
  YYSYMBOL_COLON2 = 40,                    /* COLON2  */
  YYSYMBOL_KEY_throws = 41,                /* KEY_throws  */
  YYSYMBOL_KEY_static = 42,                /* KEY_static  */
  YYSYMBOL_KEY_enum = 43,                  /* KEY_enum  */
  YYSYMBOL_DOT3 = 44,                      /* DOT3  */
  YYSYMBOL_KEY_abstract = 45,              /* KEY_abstract  */
  YYSYMBOL_KEY_native = 46,                /* KEY_native  */
  YYSYMBOL_KEY_strictf = 47,               /* KEY_strictf  */
  YYSYMBOL_KEY_protected = 48,             /* KEY_protected  */
  YYSYMBOL_KEY_private = 49,               /* KEY_private  */
  YYSYMBOL_50_ = 50,                       /* '.'  */
  YYSYMBOL_51_ = 51,                       /* '['  */
  YYSYMBOL_52_ = 52,                       /* ']'  */
  YYSYMBOL_53_ = 53,                       /* '('  */
  YYSYMBOL_54_ = 54,                       /* ')'  */
  YYSYMBOL_55_ = 55,                       /* ','  */
  YYSYMBOL_56_ = 56,                       /* '='  */
  YYSYMBOL_57_ = 57,                       /* '?'  */
  YYSYMBOL_58_ = 58,                       /* ':'  */
  YYSYMBOL_59_ = 59,                       /* '&'  */
  YYSYMBOL_60_ = 60,                       /* '^'  */
  YYSYMBOL_61_ = 61,                       /* '|'  */
  YYSYMBOL_62_ = 62,                       /* '{'  */
  YYSYMBOL_63_ = 63,                       /* '}'  */
  YYSYMBOL_64_ = 64,                       /* ';'  */
  YYSYMBOL_YYACCEPT = 65,                  /* $accept  */
  YYSYMBOL_prog = 66,                      /* prog  */
  YYSYMBOL_Type = 67,                      /* Type  */
  YYSYMBOL_PrimitiveType = 68,             /* PrimitiveType  */
  YYSYMBOL_NumericType = 69,               /* NumericType  */
  YYSYMBOL_IDENdotIDEN = 70,               /* IDENdotIDEN  */
  YYSYMBOL_PublicPrivate = 71,             /* PublicPrivate  */
  YYSYMBOL_ClassType = 72,                 /* ClassType  */
  YYSYMBOL_ArrayType = 73,                 /* ArrayType  */
  YYSYMBOL_Dims = 74,                      /* Dims  */
  YYSYMBOL_Primary = 75,                   /* Primary  */
  YYSYMBOL_PrimaryNoNewArray = 76,         /* PrimaryNoNewArray  */
  YYSYMBOL_ClassLiteral = 77,              /* ClassLiteral  */
  YYSYMBOL_Zero_or_moreSquarebracket = 78, /* Zero_or_moreSquarebracket  */
  YYSYMBOL_ClassInstanceCreationExpression = 79, /* ClassInstanceCreationExpression  */
  YYSYMBOL_UnqualifiedClassInstanceCreationExpression = 80, /* UnqualifiedClassInstanceCreationExpression  */
  YYSYMBOL_Zeroorone_ArgumentList = 81,    /* Zeroorone_ArgumentList  */
  YYSYMBOL_ZerooroneClassBody = 82,        /* ZerooroneClassBody  */
  YYSYMBOL_FieldAccess = 83,               /* FieldAccess  */
  YYSYMBOL_ArrayAccess = 84,               /* ArrayAccess  */
  YYSYMBOL_MethodInvocation = 85,          /* MethodInvocation  */
  YYSYMBOL_ArgumentList = 86,              /* ArgumentList  */
  YYSYMBOL_Zeroormore_CommaExpression = 87, /* Zeroormore_CommaExpression  */
  YYSYMBOL_MethodReference = 88,           /* MethodReference  */
  YYSYMBOL_ArrayCreationExpression = 89,   /* ArrayCreationExpression  */
  YYSYMBOL_DimExprs = 90,                  /* DimExprs  */
  YYSYMBOL_DimExpr = 91,                   /* DimExpr  */
  YYSYMBOL_Expression = 92,                /* Expression  */
  YYSYMBOL_AssignmentExpression = 93,      /* AssignmentExpression  */
  YYSYMBOL_ConditionalExpression = 94,     /* ConditionalExpression  */
  YYSYMBOL_ConditionalOrExpression = 95,   /* ConditionalOrExpression  */
  YYSYMBOL_ConditionalAndExpression = 96,  /* ConditionalAndExpression  */
  YYSYMBOL_AndExpression = 97,             /* AndExpression  */
  YYSYMBOL_ExclusiveOrExpression = 98,     /* ExclusiveOrExpression  */
  YYSYMBOL_InclusiveOrExpression = 99,     /* InclusiveOrExpression  */
  YYSYMBOL_EqualityExpression = 100,       /* EqualityExpression  */
  YYSYMBOL_RelationalExpression = 101,     /* RelationalExpression  */
  YYSYMBOL_ShiftExpression = 102,          /* ShiftExpression  */
  YYSYMBOL_AdditiveExpression = 103,       /* AdditiveExpression  */
  YYSYMBOL_MultiplicativeExpression = 104, /* MultiplicativeExpression  */
  YYSYMBOL_UnaryExpression = 105,          /* UnaryExpression  */
  YYSYMBOL_CastExpression = 106,           /* CastExpression  */
  YYSYMBOL_PostfixExpression = 107,        /* PostfixExpression  */
  YYSYMBOL_Block = 108,                    /* Block  */
  YYSYMBOL_BlockStatements = 109,          /* BlockStatements  */
  YYSYMBOL_BlockStatement = 110,           /* BlockStatement  */
  YYSYMBOL_LocalVariableDeclaration = 111, /* LocalVariableDeclaration  */
  YYSYMBOL_LocalVariableType = 112,        /* LocalVariableType  */
  YYSYMBOL_Statement = 113,                /* Statement  */
  YYSYMBOL_StatementNoShortIf = 114,       /* StatementNoShortIf  */
  YYSYMBOL_StatementWithoutTrailingSubstatement = 115, /* StatementWithoutTrailingSubstatement  */
  YYSYMBOL_StatementExpression = 116,      /* StatementExpression  */
  YYSYMBOL_LeftHandSide = 117,             /* LeftHandSide  */
  YYSYMBOL_AssertStatement = 118,          /* AssertStatement  */
  YYSYMBOL_BreakContinueStatement = 119,   /* BreakContinueStatement  */
  YYSYMBOL_ForStatement = 120,             /* ForStatement  */
  YYSYMBOL_ForStatementNoShortIf = 121,    /* ForStatementNoShortIf  */
  YYSYMBOL_ForInit = 122,                  /* ForInit  */
  YYSYMBOL_StatementExpressionList = 123,  /* StatementExpressionList  */
  YYSYMBOL_StatementExpressionMore = 124,  /* StatementExpressionMore  */
  YYSYMBOL_ArrayInitializer = 125,         /* ArrayInitializer  */
  YYSYMBOL_zerooroneVariableInitializerList = 126, /* zerooroneVariableInitializerList  */
  YYSYMBOL_VariableInitializerList = 127,  /* VariableInitializerList  */
  YYSYMBOL_cVariableInitializer = 128,     /* cVariableInitializer  */
  YYSYMBOL_VariableInitializer = 129,      /* VariableInitializer  */
  YYSYMBOL_ClassDeclaration = 130,         /* ClassDeclaration  */
  YYSYMBOL_NormalClassDeclaration = 131,   /* NormalClassDeclaration  */
  YYSYMBOL_ClassModifiers = 132,           /* ClassModifiers  */
  YYSYMBOL_ClassExtends = 133,             /* ClassExtends  */
  YYSYMBOL_ClassPermits = 134,             /* ClassPermits  */
  YYSYMBOL_cTypeName = 135,                /* cTypeName  */
  YYSYMBOL_ClassBody = 136,                /* ClassBody  */
  YYSYMBOL_ClassBodyDeclarations = 137,    /* ClassBodyDeclarations  */
  YYSYMBOL_ClassBodyDeclaration = 138,     /* ClassBodyDeclaration  */
  YYSYMBOL_FieldDeclaration = 139,         /* FieldDeclaration  */
  YYSYMBOL_FieldModifiers = 140,           /* FieldModifiers  */
  YYSYMBOL_VariableDeclaratorList = 141,   /* VariableDeclaratorList  */
  YYSYMBOL_cVariableDeclarator = 142,      /* cVariableDeclarator  */
  YYSYMBOL_VariableDeclarator = 143,       /* VariableDeclarator  */
  YYSYMBOL_VariableDeclaratorId = 144,     /* VariableDeclaratorId  */
  YYSYMBOL_MethodDeclaration = 145,        /* MethodDeclaration  */
  YYSYMBOL_Methodmodifiers = 146,          /* Methodmodifiers  */
  YYSYMBOL_Methodmodifier = 147,           /* Methodmodifier  */
  YYSYMBOL_MethodHeader = 148,             /* MethodHeader  */
  YYSYMBOL_Result = 149,                   /* Result  */
  YYSYMBOL_Methodeclarator = 150,          /* Methodeclarator  */
  YYSYMBOL_recieveparameters = 151,        /* recieveparameters  */
  YYSYMBOL_formalparameters = 152,         /* formalparameters  */
  YYSYMBOL_recieveparameter = 153,         /* recieveparameter  */
  YYSYMBOL_formalparameterlist = 154,      /* formalparameterlist  */
  YYSYMBOL_cformalparameter = 155,         /* cformalparameter  */
  YYSYMBOL_formalparameter = 156,          /* formalparameter  */
  YYSYMBOL_VariableModifier = 157,         /* VariableModifier  */
  YYSYMBOL_VariableArityParameter = 158,   /* VariableArityParameter  */
  YYSYMBOL_MethodBody = 159,               /* MethodBody  */
  YYSYMBOL_ConstructorDeclaration = 160,   /* ConstructorDeclaration  */
  YYSYMBOL_ConstructorModifiers = 161,     /* ConstructorModifiers  */
  YYSYMBOL_ConstructorBody = 162,          /* ConstructorBody  */
  YYSYMBOL_zerooroneExplicitConstructorInvocation = 163, /* zerooroneExplicitConstructorInvocation  */
  YYSYMBOL_ExplicitConstructorInvocation = 164 /* ExplicitConstructorInvocation  */
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
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1405

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  65
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  100
/* YYNRULES -- Number of rules.  */
#define YYNRULES  244
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  469

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   304


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
       2,     2,     2,     2,     2,     2,     2,     2,    59,     2,
      53,    54,     2,     2,    55,     2,    50,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    58,    64,
       2,    56,     2,    57,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    51,     2,    52,    60,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    62,    61,    63,     2,     2,     2,     2,
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
      45,    46,    47,    48,    49
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    22,    22,    27,    28,    32,    33,    37,    38,    42,
      43,    47,    47,    51,    55,    58,    59,    66,    67,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    85,
      86,    87,    91,    92,    96,    97,    98,   103,   107,   107,
     111,   111,   115,   116,   117,   122,   123,   128,   129,   130,
     131,   135,   139,   140,   144,   145,   146,   147,   148,   149,
     154,   155,   156,   160,   160,   164,   168,   172,   173,   174,
     178,   179,   183,   184,   188,   189,   193,   194,   198,   199,
     203,   204,   208,   209,   213,   214,   218,   219,   223,   224,
     228,   229,   233,   234,   235,   236,   237,   241,   245,   246,
     247,   248,   255,   259,   259,   263,   264,   265,   269,   273,
     274,   275,   279,   280,   281,   282,   283,   284,   288,   289,
     290,   291,   292,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   308,   309,   310,   314,   315,   316,   320,   321,
     325,   326,   330,   331,   332,   333,   334,   335,   336,   337,
     338,   342,   343,   344,   345,   346,   347,   348,   349,   350,
     354,   355,   359,   363,   363,   370,   371,   374,   375,   378,
     382,   382,   386,   387,   393,   396,   397,   398,   399,   402,
     402,   405,   408,   412,   412,   416,   419,   420,   423,   424,
     425,   426,   427,   430,   433,   434,   437,   440,   441,   444,
     445,   449,   450,   455,   459,   459,   463,   463,   463,   463,
     463,   463,   463,   463,   467,   471,   473,   474,   478,   479,
     483,   484,   487,   488,   492,   493,   497,   500,   500,   503,
     507,   507,   510,   514,   515,   518,   521,   521,   525,   529,
     530,   533,   534,   535,   536
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
  "KEY_for", "KEY_permits", "KEY_record", "KEY_while", "KEY_sync",
  "KEY_final", "KEY_extends", "KEY_super", "KEY_this", "KEY_class",
  "KEY_void", "KEY_public", "KEY_new", "COLON2", "KEY_throws",
  "KEY_static", "KEY_enum", "DOT3", "KEY_abstract", "KEY_native",
  "KEY_strictf", "KEY_protected", "KEY_private", "'.'", "'['", "']'",
  "'('", "')'", "','", "'='", "'?'", "':'", "'&'", "'^'", "'|'", "'{'",
  "'}'", "';'", "$accept", "prog", "Type", "PrimitiveType", "NumericType",
  "IDENdotIDEN", "PublicPrivate", "ClassType", "ArrayType", "Dims",
  "Primary", "PrimaryNoNewArray", "ClassLiteral",
  "Zero_or_moreSquarebracket", "ClassInstanceCreationExpression",
  "UnqualifiedClassInstanceCreationExpression", "Zeroorone_ArgumentList",
  "ZerooroneClassBody", "FieldAccess", "ArrayAccess", "MethodInvocation",
  "ArgumentList", "Zeroormore_CommaExpression", "MethodReference",
  "ArrayCreationExpression", "DimExprs", "DimExpr", "Expression",
  "AssignmentExpression", "ConditionalExpression",
  "ConditionalOrExpression", "ConditionalAndExpression", "AndExpression",
  "ExclusiveOrExpression", "InclusiveOrExpression", "EqualityExpression",
  "RelationalExpression", "ShiftExpression", "AdditiveExpression",
  "MultiplicativeExpression", "UnaryExpression", "CastExpression",
  "PostfixExpression", "Block", "BlockStatements", "BlockStatement",
  "LocalVariableDeclaration", "LocalVariableType", "Statement",
  "StatementNoShortIf", "StatementWithoutTrailingSubstatement",
  "StatementExpression", "LeftHandSide", "AssertStatement",
  "BreakContinueStatement", "ForStatement", "ForStatementNoShortIf",
  "ForInit", "StatementExpressionList", "StatementExpressionMore",
  "ArrayInitializer", "zerooroneVariableInitializerList",
  "VariableInitializerList", "cVariableInitializer", "VariableInitializer",
  "ClassDeclaration", "NormalClassDeclaration", "ClassModifiers",
  "ClassExtends", "ClassPermits", "cTypeName", "ClassBody",
  "ClassBodyDeclarations", "ClassBodyDeclaration", "FieldDeclaration",
  "FieldModifiers", "VariableDeclaratorList", "cVariableDeclarator",
  "VariableDeclarator", "VariableDeclaratorId", "MethodDeclaration",
  "Methodmodifiers", "Methodmodifier", "MethodHeader", "Result",
  "Methodeclarator", "recieveparameters", "formalparameters",
  "recieveparameter", "formalparameterlist", "cformalparameter",
  "formalparameter", "VariableModifier", "VariableArityParameter",
  "MethodBody", "ConstructorDeclaration", "ConstructorModifiers",
  "ConstructorBody", "zerooroneExplicitConstructorInvocation",
  "ExplicitConstructorInvocation", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-253)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-238)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -253,    43,  -253,  -253,   162,  -253,    50,  -253,  -253,  -253,
      90,    57,    57,  -253,    -7,    -6,  -253,  -253,    34,    34,
    -253,    15,    -6,  -253,  -253,    71,    10,  -253,  -253,  -253,
    -253,  -253,  -253,  -253,   129,  -253,   573,  -253,   109,  -253,
    -253,    57,   793,  -253,  -253,  -253,   151,   106,  -253,  -253,
    -253,  -253,  -253,  -253,  -253,  -253,  -253,  -253,  -253,   106,
    -253,  -253,    89,   176,   138,    34,   145,  -253,  1352,  1352,
    1352,  1352,  1352,    21,   643,   159,   169,   171,   174,    46,
    -253,   183,   286,  1352,  -253,  -253,   106,    52,   181,   204,
      91,   196,  -253,  -253,  -253,    16,    17,  -253,  -253,  -253,
    -253,  -253,    25,   236,   191,   193,   198,   244,   250,   252,
     249,   253,  -253,  -253,  -253,  -253,  -253,   205,  -253,  -253,
     213,    27,  -253,  -253,  -253,  -253,   292,   106,   214,  -253,
     223,   228,   230,   230,  -253,  -253,  -253,   231,  -253,   254,
     893,    40,  -253,  -253,  -253,  -253,  -253,  -253,  -253,    75,
    -253,   225,   227,  -253,  -253,   233,  1352,   690,  1352,  1352,
     294,   298,   267,   257,   -15,    12,   256,   155,  -253,   300,
      95,  1352,  1352,   168,   275,   278,  -253,   315,    35,  1352,
    1352,  1352,  1352,  1352,  1352,  1352,  1352,  1352,  1352,  1352,
    1352,  -253,  -253,  1352,  1352,  -253,  -253,  -253,  -253,   151,
     230,  -253,   266,  1071,  -253,   273,   254,    14,   276,   279,
    -253,  1352,  -253,  -253,  -253,  -253,   281,   965,   274,  -253,
     269,  -253,   282,   283,  -253,   287,  -253,  1314,    -3,   257,
    -253,  1352,  1352,  -253,   295,   289,  -253,    77,  -253,    57,
    -253,   291,   285,  -253,  -253,   308,  -253,  -253,  -253,   296,
    -253,   293,   236,   290,   198,   244,   191,   193,   250,   252,
     249,   253,  -253,  -253,  -253,  -253,   151,  1071,  -253,  -253,
    -253,  -253,   276,   302,  -253,   303,  -253,  -253,   163,  -253,
     304,   929,   752,   305,  1352,   309,   971,   893,   297,  1352,
     306,  -253,   230,  -253,   317,  -253,  -253,  -253,   368,   373,
    -253,  -253,   325,  -253,  1352,  -253,  1352,  -253,   160,  -253,
    -253,   327,   347,   322,   331,   151,  -253,   330,   337,   338,
     341,  -253,   369,   371,  -253,   893,   349,  1107,   352,  1352,
    1131,   344,  -253,  -253,   364,  -253,    -6,  -253,   366,  1352,
     367,  -253,   357,  -253,   370,   106,  -253,   221,  -253,  -253,
    -253,   929,  1352,  1007,  1352,   893,  -253,   893,   893,   374,
     893,  -253,   893,   375,  1170,  -253,  -253,  -253,  1352,  -253,
    -253,  -253,  1071,   230,     7,   377,  1352,    61,   157,  -253,
    -253,  -253,   163,  -253,  -253,   378,  1029,   381,   358,   387,
    -253,  -253,  -253,   893,  -253,  -253,   893,   893,   391,   392,
    -253,  1352,  1352,   237,    37,   843,   380,   929,  1192,   383,
    1352,  1065,   929,  -253,  -253,  -253,   893,  -253,   396,   398,
     164,   400,  -253,   447,   428,   929,   401,  1231,   402,  1253,
     393,  -253,  -253,   395,   399,  1352,  1352,  -253,   929,  -253,
     929,   929,   406,   929,   929,   407,  1292,  -253,  -253,   408,
     410,  -253,  -253,  -253,   929,  -253,  -253,   929,   929,   411,
     403,   414,  -253,  -253,  -253,   929,  -253,  -253,  -253
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
     180,     0,     2,   174,     0,     1,     0,    11,    12,   179,
       0,     0,     0,   187,     0,     0,   175,    10,   184,    13,
     181,   205,     0,   176,   177,     0,   182,   104,   185,   189,
     236,   190,   186,   188,     0,   192,     0,   191,     0,   178,
       9,     0,   180,     7,     8,     6,     0,     3,     5,   194,
       4,   211,   210,   217,   209,   208,   212,   213,   207,   215,
     206,   204,     0,     0,     0,   183,    10,    19,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      21,     0,     0,     0,   102,   124,    33,    99,     0,     0,
      98,    17,    20,    24,    34,    25,    26,    27,    28,    18,
     132,    67,    70,    72,    78,    80,    74,    76,    82,    84,
      86,    88,    90,    96,    94,   123,   103,     0,   107,   112,
       0,     0,   126,   127,   117,   105,     0,   202,     0,   198,
     200,     0,    14,   216,   234,   233,   203,     0,   214,   221,
       0,    99,    24,    25,    26,    27,    93,    92,    95,     0,
      66,     0,     0,   141,   128,     0,     0,   231,     0,     0,
       0,     0,     0,     0,     0,    33,     0,     0,   101,     0,
       0,     0,    39,     0,     0,     0,   100,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   106,   125,     0,     0,   111,   230,   109,   110,     0,
     201,   193,   196,     0,    15,     0,   221,     0,   231,     0,
     113,     0,   138,   130,   140,   129,     0,     0,   161,   164,
       0,   160,     0,     0,    56,    43,    31,     0,     0,    61,
      64,    39,     0,    23,     0,     0,    54,     0,    22,     0,
      35,     0,     0,    38,    53,     0,    58,    59,    55,    42,
      36,     0,    73,     0,    75,    77,    79,    81,    83,    85,
      87,    89,    91,    68,    69,   108,     0,   168,   172,   173,
     199,    16,   231,     0,   225,     0,   222,   228,     0,   220,
       0,     0,     0,     0,     0,   162,     0,     0,     0,    39,
       0,    62,    60,    63,     0,    97,    30,    32,     0,     0,
      45,    47,    51,    29,    39,    46,     0,   197,     0,   167,
     171,     0,     0,     0,   226,     0,   139,    10,     0,     0,
       0,   114,     0,   112,   122,     0,     0,     0,     0,     0,
       0,     0,   116,   131,     0,    65,    41,    57,    44,     0,
       0,    71,     0,   166,   169,   219,   224,   240,   235,   231,
     231,     0,     0,   231,     0,     0,   142,     0,     0,     0,
       0,   163,     0,     0,     0,    49,    37,    40,    39,    52,
      48,   165,     0,   218,     0,    21,     0,     0,     0,   104,
     239,   227,     0,   229,   119,     0,     0,   161,     0,     0,
     115,   145,   144,     0,   150,   143,     0,     0,     0,     0,
     170,    39,    39,     0,     0,   180,     0,     0,     0,     0,
       0,     0,     0,   146,   148,   147,     0,    50,     0,     0,
       0,     0,   238,     0,     0,     0,     0,     0,     0,     0,
       0,   121,   149,     0,     0,    39,    39,   232,     0,   151,
       0,     0,     0,     0,     0,     0,     0,   242,   241,     0,
       0,   120,   154,   153,     0,   159,   152,     0,     0,     0,
       0,     0,   155,   157,   156,     0,   243,   244,   158
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -253,  -253,   -26,   -32,  -253,    -1,    85,     0,   -29,   -39,
     123,  -253,  -253,   -70,   -42,  -161,  -200,  -253,   -40,   -24,
      80,  -253,  -253,  -253,  -253,  -253,   245,   397,   255,   173,
    -253,   301,   299,   310,   307,   311,   312,   288,   313,   314,
     -36,  -253,  -253,   -20,   105,  -253,  -144,  -253,   277,    92,
     -65,  -154,  -253,  -253,  -253,  -253,  -253,   137,  -195,  -253,
     263,  -253,  -253,  -253,  -252,   493,  -253,  -253,  -253,   483,
    -253,    -8,  -253,  -253,  -253,  -253,   316,  -253,   234,   187,
    -253,  -253,  -253,  -253,  -253,  -253,   319,   238,  -253,  -253,
    -253,   165,  -156,  -253,  -253,  -253,  -253,  -253,  -253,  -253
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,   207,    86,    48,    87,     9,    88,    89,   132,
      90,    91,    92,   173,   142,    94,   242,   366,    95,    96,
     145,   243,   302,    98,    99,   229,   230,   244,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,    42,   116,   117,   199,   118,   322,
     119,   120,   121,   122,   123,   124,   324,   220,   221,   285,
     269,   308,   309,   344,   270,   125,     3,     4,    14,    15,
      26,    16,    21,    32,    33,    34,   128,   202,   129,   130,
      35,    36,    61,    62,    63,   138,   208,   275,   209,   276,
     314,   277,   126,   383,   136,    37,    38,   348,   379,   380
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      93,    31,    47,   219,    59,    50,    23,    24,    46,   240,
      18,    19,    20,   218,    39,   310,   167,   250,   273,  -237,
     133,    11,  -195,  -195,  -195,   152,  -136,  -137,   143,   143,
     143,   294,   146,   147,   148,    25,   180,   193,   231,   249,
      65,   249,   135,     5,   144,   144,   144,   160,   205,   274,
     163,   165,   278,     7,    10,    13,    13,   161,   168,   267,
     401,    17,  -135,   131,     8,    41,   232,   141,   141,   141,
     168,   421,  -136,  -137,   239,    40,   239,    27,    28,    29,
     169,   164,   181,   194,    25,   153,   160,   326,   200,   334,
     170,   171,   169,   172,    47,   167,   161,    50,    93,    40,
     197,   169,   170,   171,   340,   172,    30,    47,  -135,   176,
      50,   403,   171,    64,   172,    93,   278,   298,    11,    49,
     400,    60,    97,    12,   228,    19,   198,   299,   219,   237,
     238,   177,   359,   211,   239,   363,    43,    44,    45,   212,
     143,   178,   143,   143,   143,   143,   143,   143,   143,   143,
     143,    27,    13,   134,   262,   127,   144,   131,   144,   144,
     144,   144,   144,   144,   144,   144,   144,     7,   399,   398,
      43,    44,    45,   219,    47,   361,   219,    50,     8,   141,
     137,   141,   141,   141,   141,   141,   141,   141,   141,   141,
     292,   139,   143,   278,   382,   196,   295,   177,     6,   219,
       7,   418,   419,   140,   298,   234,   235,   404,   144,   387,
     219,     8,   156,   426,   299,   342,   323,   435,   245,   235,
      97,   174,   157,   343,   158,    17,    67,   159,    43,    44,
      45,   141,   442,   162,   445,   449,   450,    97,   164,    93,
      93,    40,   240,   250,   175,    93,    47,   179,   182,    50,
     183,   459,   315,   184,   219,   374,   375,   186,    81,   185,
      82,    43,    44,    45,   187,   189,   143,   188,   333,   191,
     190,   420,   238,   219,   376,   219,   239,   192,   201,   203,
     204,   205,   144,    93,   206,    93,   323,    93,    93,   213,
      17,   214,   219,    43,    44,    45,    17,   215,   224,    43,
      44,    45,   225,   226,   236,   141,   373,   143,   227,    93,
     233,    93,   195,    93,   246,    93,    93,   247,    93,   248,
      93,   266,    93,   144,   196,   271,   150,   150,   367,   150,
    -223,   296,   284,   286,   279,   281,   287,   288,   150,   301,
     289,   297,   323,   300,   303,   305,   377,   323,   306,   304,
      47,    93,   312,    50,    93,    93,   406,   313,   335,    27,
     323,    97,    97,    93,   329,    93,    93,    97,   316,   327,
      93,   336,   337,   323,    93,   323,   323,   338,   323,   323,
     339,   345,   346,    93,   347,    93,   349,    93,   351,   323,
     352,   353,   323,   323,   354,   355,    93,  -118,    93,    93,
     323,    93,    93,   357,    93,    97,   360,    97,   364,    97,
      97,   150,    93,   150,   150,    93,    93,   210,   365,   368,
     371,   370,   411,    93,   423,   372,   150,   150,   393,   396,
     402,    97,   407,    97,   150,    97,   150,    97,    97,   410,
      97,   412,    97,   384,    97,   416,   417,   427,   150,   150,
     433,   437,   434,   436,   438,   440,   443,   446,   150,   447,
     454,   457,   460,   448,   461,   465,   150,   466,   149,   151,
     378,   155,   150,    97,   293,   259,    97,    97,   467,   341,
     166,   252,   150,   256,   405,    97,   150,    97,    97,   254,
     388,   291,    97,     2,   255,   257,    97,    22,   258,   424,
     307,   260,   350,   261,   431,    97,     0,    97,     0,    97,
     311,     0,     0,     0,   381,   265,     0,   439,    97,     0,
      97,    97,   150,    97,    97,   272,    97,     0,     0,     0,
     451,     0,   452,   453,    97,   455,   456,    97,    97,   150,
       0,   150,     0,     0,   150,    97,   462,     0,     0,   463,
     464,     0,     0,   216,     0,   222,   223,   468,   321,   150,
       0,     0,     0,     0,   332,     0,     0,     0,   241,     0,
       0,     0,     0,     0,     0,     0,   251,     0,   253,     0,
      43,    44,    45,     0,     0,     0,     0,     0,     0,     0,
     263,   264,     0,     0,   150,     0,     0,     0,     0,     0,
     268,     0,   356,     0,    51,    52,     0,   150,   280,   150,
      53,     7,     0,     0,   283,    54,     0,     0,    55,    56,
      57,    58,     8,   150,   290,     0,     0,   150,   210,     0,
       0,   150,   390,     0,   391,   392,     0,   394,     0,   395,
       0,   150,     0,     0,     0,     0,     0,    17,    67,     0,
      43,    44,    45,     0,     0,     0,   150,   150,     0,    68,
       0,    69,    70,     0,   268,   150,   150,     0,     0,     0,
     413,     0,     0,   414,   415,     0,     0,    79,    80,     0,
      81,   328,    82,   331,   321,     0,     0,     0,     0,   332,
     150,   150,     0,   432,    17,    67,    83,    43,    44,    45,
       0,     0,   356,     0,     0,     0,    68,   154,    69,    70,
       0,     0,     0,     0,     0,   390,     0,   391,   392,     0,
     394,   395,     0,     0,    79,    80,     0,    81,     0,    82,
       0,   413,     0,     0,   414,   415,   369,     0,     0,     0,
       0,     0,   432,    83,     0,     0,     0,     0,     0,   385,
       0,   389,     0,     0,   217,     0,    17,    67,     0,    43,
      44,    45,     0,     0,     0,     0,     0,     0,    68,   268,
      69,    70,     0,   166,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   409,     0,     0,    79,    80,     0,    81,
       0,    82,     0,     0,     0,     0,     0,    66,    67,     0,
      43,    44,    45,     0,     0,    83,   325,   428,   430,    68,
       0,    69,    70,  -231,    71,    72,    73,    74,    75,     0,
      76,     0,     0,    77,    78,  -231,     0,    79,    80,     0,
      81,     0,    82,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    83,    66,    67,     0,
      43,    44,    45,     0,     0,    27,    84,    85,     0,    68,
       0,    69,    70,  -231,    71,    72,    73,    74,    75,     0,
      76,     0,     0,    77,    78,  -231,     0,    79,    80,     0,
      81,     0,    82,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    83,    66,    67,     0,
      43,    44,    45,     0,     0,    27,   422,    85,     0,    68,
       0,    69,    70,     0,    71,    72,    73,    74,    75,     0,
      76,     0,     0,    77,    78,     0,     0,    79,    80,     0,
      81,     0,    82,   317,    67,     0,    43,    44,    45,     0,
       0,     0,     0,     0,     0,    68,    83,    69,    70,     0,
      71,    72,    73,    74,   318,    27,   319,    85,     0,   320,
      78,     0,     0,    79,    80,     0,    81,     0,    82,    17,
      67,     0,    43,    44,    45,    17,    67,     0,    43,    44,
      45,    68,    83,    69,    70,     0,     0,    68,     0,    69,
      70,    27,     0,    85,     0,     0,     0,     0,     0,    79,
      80,     0,    81,     0,    82,    79,    80,     0,    81,     0,
      82,    17,    67,     0,    43,    44,    45,     0,    83,     0,
       0,     0,     0,    68,    83,    69,    70,     0,     0,   282,
       0,     0,     0,    17,    67,   330,    43,    44,    45,     0,
       0,    79,    80,     0,    81,    68,    82,    69,    70,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      83,     0,     0,    79,    80,     0,    81,     0,    82,    17,
      67,   386,    43,    44,    45,    17,    67,     0,    43,    44,
      45,    68,    83,    69,    70,     0,     0,    68,     0,    69,
      70,     0,     0,   408,     0,     0,     0,     0,     0,    79,
      80,     0,    81,     0,    82,    79,    80,     0,    81,     0,
      82,    17,    67,     0,    43,    44,    45,     0,    83,     0,
       0,     0,     0,    68,    83,    69,    70,     0,     0,   429,
       0,     0,     0,   267,     0,    17,    67,     0,    43,    44,
      45,    79,    80,     0,    81,     0,    82,    68,     0,    69,
      70,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      83,   358,     0,     0,     0,    79,    80,     0,    81,     0,
      82,     0,     0,     0,    17,    67,     0,    43,    44,    45,
       0,     0,     0,     0,    83,   362,    68,     0,    69,    70,
       0,     0,     0,     0,     0,     0,    17,    67,     0,    43,
      44,    45,     0,     0,    79,    80,     0,    81,    68,    82,
      69,    70,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    83,   397,     0,    79,    80,     0,    81,
       0,    82,     0,     0,     0,    17,    67,     0,    43,    44,
      45,     0,     0,     0,     0,    83,   425,    68,     0,    69,
      70,     0,     0,     0,     0,     0,     0,    17,    67,     0,
      43,    44,    45,     0,     0,    79,    80,     0,    81,    68,
      82,    69,    70,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    83,   441,     0,    79,    80,     0,
      81,     0,    82,     0,     0,     0,    17,    67,     0,    43,
      44,    45,     0,     0,     0,     0,    83,   444,    68,     0,
      69,    70,     0,     0,     0,     0,     0,     0,    17,    67,
       0,    43,    44,    45,     0,     0,    79,    80,     0,    81,
      68,    82,    69,    70,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    83,   458,     0,    79,    80,
       0,    81,     0,    82,     0,     0,    17,    67,     0,    43,
      44,    45,     0,     0,     0,     0,   204,    83,    68,     0,
      69,    70,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    79,    80,     0,    81,
       0,    82,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    83
};

static const yytype_int16 yycheck[] =
{
      42,    21,    34,   157,    36,    34,    14,    15,    34,   170,
      11,    12,    12,   157,    22,   267,    86,   178,     4,     4,
      59,    28,     7,     8,     9,     4,    10,    10,    68,    69,
      70,   231,    68,    69,    70,    50,    11,    10,    53,     4,
      41,     4,    62,     0,    68,    69,    70,    40,    51,    35,
      82,    83,   208,    38,     4,    62,    62,    50,    18,    62,
      53,     4,    10,    51,    49,    55,    54,    68,    69,    70,
      18,    34,    56,    56,    39,     4,    39,    62,    63,    64,
      40,    82,    57,    56,    50,    64,    40,   282,   127,   289,
      50,    51,    40,    53,   126,   165,    50,   126,   140,     4,
     126,    40,    50,    51,   304,    53,    21,   139,    56,    18,
     139,    50,    51,     4,    53,   157,   272,    40,    28,    34,
     372,    36,    42,    33,   163,   126,   126,    50,   282,    34,
      35,    40,   327,    58,    39,   330,     7,     8,     9,    64,
     180,    50,   182,   183,   184,   185,   186,   187,   188,   189,
     190,    62,    62,    64,   190,     4,   180,    51,   182,   183,
     184,   185,   186,   187,   188,   189,   190,    38,   368,   364,
       7,     8,     9,   327,   206,   329,   330,   206,    49,   180,
       4,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     229,    53,   232,   349,   350,    32,   232,    40,    36,   353,
      38,   401,   402,    58,    40,    50,    51,    50,   232,   353,
     364,    49,    53,   408,    50,    55,   281,    53,    50,    51,
     140,    40,    53,    63,    53,     4,     5,    53,     7,     8,
       9,   232,   427,    50,   429,   435,   436,   157,   239,   281,
     282,     4,   403,   404,    40,   287,   278,    51,    12,   278,
      59,   446,   278,    60,   408,    34,    35,    13,    37,    61,
      39,     7,     8,     9,    14,    16,   306,    15,   288,    64,
      17,    34,    35,   427,    53,   429,    39,    64,    64,    56,
      52,    51,   306,   325,    53,   327,   351,   329,   330,    64,
       4,    64,   446,     7,     8,     9,     4,    64,     4,     7,
       8,     9,     4,    36,     4,   306,   345,   347,    51,   351,
      54,   353,    20,   355,    39,   357,   358,    39,   360,     4,
     362,    55,   364,   347,    32,    52,    71,    72,   336,    74,
      54,    36,    58,    64,    55,    54,    54,    54,    83,    54,
      53,    52,   407,    52,    36,    52,   347,   412,    58,    53,
     382,   393,    50,   382,   396,   397,   382,    54,    52,    62,
     425,   281,   282,   405,    55,   407,   408,   287,    64,    64,
     412,    54,     4,   438,   416,   440,   441,     4,   443,   444,
      55,    54,    35,   425,    62,   427,    55,   429,    58,   454,
      53,    53,   457,   458,    53,    26,   438,    26,   440,   441,
     465,   443,   444,    54,   446,   325,    54,   327,    64,   329,
     330,   156,   454,   158,   159,   457,   458,   140,    54,    53,
      63,    54,    64,   465,    44,    55,   171,   172,    54,    54,
      53,   351,    54,   353,   179,   355,   181,   357,   358,    58,
     360,    54,   362,   351,   364,    54,    54,    64,   193,   194,
      54,     4,    54,    53,    26,    54,    54,    64,   203,    64,
      54,    54,    54,    64,    54,    54,   211,    64,    71,    72,
     347,    74,   217,   393,   229,   187,   396,   397,    64,   306,
      83,   180,   227,   184,   379,   405,   231,   407,   408,   182,
     353,   228,   412,     0,   183,   185,   416,    14,   186,   407,
     266,   188,   315,   189,   412,   425,    -1,   427,    -1,   429,
     272,    -1,    -1,    -1,   349,   199,    -1,   425,   438,    -1,
     440,   441,   267,   443,   444,   206,   446,    -1,    -1,    -1,
     438,    -1,   440,   441,   454,   443,   444,   457,   458,   284,
      -1,   286,    -1,    -1,   289,   465,   454,    -1,    -1,   457,
     458,    -1,    -1,   156,    -1,   158,   159,   465,   281,   304,
      -1,    -1,    -1,    -1,   287,    -1,    -1,    -1,   171,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   179,    -1,   181,    -1,
       7,     8,     9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     193,   194,    -1,    -1,   339,    -1,    -1,    -1,    -1,    -1,
     203,    -1,   325,    -1,    31,    32,    -1,   352,   211,   354,
      37,    38,    -1,    -1,   217,    42,    -1,    -1,    45,    46,
      47,    48,    49,   368,   227,    -1,    -1,   372,   351,    -1,
      -1,   376,   355,    -1,   357,   358,    -1,   360,    -1,   362,
      -1,   386,    -1,    -1,    -1,    -1,    -1,     4,     5,    -1,
       7,     8,     9,    -1,    -1,    -1,   401,   402,    -1,    16,
      -1,    18,    19,    -1,   267,   410,   411,    -1,    -1,    -1,
     393,    -1,    -1,   396,   397,    -1,    -1,    34,    35,    -1,
      37,   284,    39,   286,   407,    -1,    -1,    -1,    -1,   412,
     435,   436,    -1,   416,     4,     5,    53,     7,     8,     9,
      -1,    -1,   425,    -1,    -1,    -1,    16,    64,    18,    19,
      -1,    -1,    -1,    -1,    -1,   438,    -1,   440,   441,    -1,
     443,   444,    -1,    -1,    34,    35,    -1,    37,    -1,    39,
      -1,   454,    -1,    -1,   457,   458,   339,    -1,    -1,    -1,
      -1,    -1,   465,    53,    -1,    -1,    -1,    -1,    -1,   352,
      -1,   354,    -1,    -1,    64,    -1,     4,     5,    -1,     7,
       8,     9,    -1,    -1,    -1,    -1,    -1,    -1,    16,   372,
      18,    19,    -1,   376,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   386,    -1,    -1,    34,    35,    -1,    37,
      -1,    39,    -1,    -1,    -1,    -1,    -1,     4,     5,    -1,
       7,     8,     9,    -1,    -1,    53,    54,   410,   411,    16,
      -1,    18,    19,    20,    21,    22,    23,    24,    25,    -1,
      27,    -1,    -1,    30,    31,    32,    -1,    34,    35,    -1,
      37,    -1,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    53,     4,     5,    -1,
       7,     8,     9,    -1,    -1,    62,    63,    64,    -1,    16,
      -1,    18,    19,    20,    21,    22,    23,    24,    25,    -1,
      27,    -1,    -1,    30,    31,    32,    -1,    34,    35,    -1,
      37,    -1,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    53,     4,     5,    -1,
       7,     8,     9,    -1,    -1,    62,    63,    64,    -1,    16,
      -1,    18,    19,    -1,    21,    22,    23,    24,    25,    -1,
      27,    -1,    -1,    30,    31,    -1,    -1,    34,    35,    -1,
      37,    -1,    39,     4,     5,    -1,     7,     8,     9,    -1,
      -1,    -1,    -1,    -1,    -1,    16,    53,    18,    19,    -1,
      21,    22,    23,    24,    25,    62,    27,    64,    -1,    30,
      31,    -1,    -1,    34,    35,    -1,    37,    -1,    39,     4,
       5,    -1,     7,     8,     9,     4,     5,    -1,     7,     8,
       9,    16,    53,    18,    19,    -1,    -1,    16,    -1,    18,
      19,    62,    -1,    64,    -1,    -1,    -1,    -1,    -1,    34,
      35,    -1,    37,    -1,    39,    34,    35,    -1,    37,    -1,
      39,     4,     5,    -1,     7,     8,     9,    -1,    53,    -1,
      -1,    -1,    -1,    16,    53,    18,    19,    -1,    -1,    64,
      -1,    -1,    -1,     4,     5,    64,     7,     8,     9,    -1,
      -1,    34,    35,    -1,    37,    16,    39,    18,    19,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      53,    -1,    -1,    34,    35,    -1,    37,    -1,    39,     4,
       5,    64,     7,     8,     9,     4,     5,    -1,     7,     8,
       9,    16,    53,    18,    19,    -1,    -1,    16,    -1,    18,
      19,    -1,    -1,    64,    -1,    -1,    -1,    -1,    -1,    34,
      35,    -1,    37,    -1,    39,    34,    35,    -1,    37,    -1,
      39,     4,     5,    -1,     7,     8,     9,    -1,    53,    -1,
      -1,    -1,    -1,    16,    53,    18,    19,    -1,    -1,    64,
      -1,    -1,    -1,    62,    -1,     4,     5,    -1,     7,     8,
       9,    34,    35,    -1,    37,    -1,    39,    16,    -1,    18,
      19,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      53,    54,    -1,    -1,    -1,    34,    35,    -1,    37,    -1,
      39,    -1,    -1,    -1,     4,     5,    -1,     7,     8,     9,
      -1,    -1,    -1,    -1,    53,    54,    16,    -1,    18,    19,
      -1,    -1,    -1,    -1,    -1,    -1,     4,     5,    -1,     7,
       8,     9,    -1,    -1,    34,    35,    -1,    37,    16,    39,
      18,    19,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    53,    54,    -1,    34,    35,    -1,    37,
      -1,    39,    -1,    -1,    -1,     4,     5,    -1,     7,     8,
       9,    -1,    -1,    -1,    -1,    53,    54,    16,    -1,    18,
      19,    -1,    -1,    -1,    -1,    -1,    -1,     4,     5,    -1,
       7,     8,     9,    -1,    -1,    34,    35,    -1,    37,    16,
      39,    18,    19,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    53,    54,    -1,    34,    35,    -1,
      37,    -1,    39,    -1,    -1,    -1,     4,     5,    -1,     7,
       8,     9,    -1,    -1,    -1,    -1,    53,    54,    16,    -1,
      18,    19,    -1,    -1,    -1,    -1,    -1,    -1,     4,     5,
      -1,     7,     8,     9,    -1,    -1,    34,    35,    -1,    37,
      16,    39,    18,    19,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    53,    54,    -1,    34,    35,
      -1,    37,    -1,    39,    -1,    -1,     4,     5,    -1,     7,
       8,     9,    -1,    -1,    -1,    -1,    52,    53,    16,    -1,
      18,    19,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    34,    35,    -1,    37,
      -1,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    53
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    66,   130,   131,   132,     0,    36,    38,    49,    71,
       4,    28,    33,    62,   133,   134,   136,     4,    70,    70,
      72,   137,   134,   136,   136,    50,   135,    62,    63,    64,
      71,   108,   138,   139,   140,   145,   146,   160,   161,   136,
       4,    55,   109,     7,     8,     9,    67,    68,    69,    71,
      73,    31,    32,    37,    42,    45,    46,    47,    48,    68,
      71,   147,   148,   149,     4,    70,     4,     5,    16,    18,
      19,    21,    22,    23,    24,    25,    27,    30,    31,    34,
      35,    37,    39,    53,    63,    64,    68,    70,    72,    73,
      75,    76,    77,    79,    80,    83,    84,    85,    88,    89,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   110,   111,   113,   115,
     116,   117,   118,   119,   120,   130,   157,     4,   141,   143,
     144,    51,    74,    74,    64,   108,   159,     4,   150,    53,
      58,    70,    79,    83,    84,    85,   105,   105,   105,    92,
      93,    92,     4,    64,    64,    92,    53,    53,    53,    53,
      40,    50,    50,    68,    70,    68,    92,    78,    18,    40,
      50,    51,    53,    78,    40,    40,    18,    40,    50,    51,
      11,    57,    12,    59,    60,    61,    13,    14,    15,    16,
      17,    64,    64,    10,    56,    20,    32,    67,    72,   112,
      74,    64,   142,    56,    52,    51,    53,    67,   151,   153,
     113,    58,    64,    64,    64,    64,    92,    64,   111,   116,
     122,   123,    92,    92,     4,     4,    36,    51,    74,    90,
      91,    53,    54,    54,    50,    51,     4,    34,    35,    39,
      80,    92,    81,    86,    92,    50,    39,    39,     4,     4,
      80,    92,    96,    92,    99,   100,    97,    98,   101,   102,
     103,   104,   105,    92,    92,   141,    55,    62,    92,   125,
     129,    52,   151,     4,    35,   152,   154,   156,   157,    55,
      92,    54,    64,    92,    58,   124,    64,    54,    54,    53,
      92,   125,    74,    91,    81,   105,    36,    52,    40,    50,
      52,    54,    87,    36,    53,    52,    58,   143,   126,   127,
     129,   152,    50,    54,   155,    67,    64,     4,    25,    27,
      30,   113,   114,   115,   121,    54,   123,    64,    92,    55,
      64,    92,   113,   108,    81,    52,    54,     4,     4,    55,
      81,    94,    55,    63,   128,    54,    35,    62,   162,    55,
     144,    58,    53,    53,    53,    26,   113,    54,    54,   123,
      54,   116,    54,   123,    64,    54,    82,   136,    53,    92,
      54,    63,    55,    74,    34,    35,    53,    70,    75,   163,
     164,   156,   157,   158,   114,    92,    64,   111,   122,    92,
     113,   113,   113,    54,   113,   113,    54,    54,   123,    81,
     129,    53,    53,    50,    50,   109,    67,    54,    64,    92,
      58,    64,    54,   113,   113,   113,    54,    54,    81,    81,
      34,    34,    63,    44,   114,    54,   123,    64,    92,    64,
      92,   114,   113,    54,    54,    53,    53,     4,    26,   114,
      54,    54,   123,    54,    54,   123,    64,    64,    64,    81,
      81,   114,   114,   114,    54,   114,   114,    54,    54,   123,
      54,    54,   114,   114,   114,    54,    64,    64,   114
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    65,    66,    67,    67,    68,    68,    69,    69,    70,
      70,    71,    71,    72,    73,    74,    74,    75,    75,    76,
      76,    76,    76,    76,    76,    76,    76,    76,    76,    77,
      77,    77,    78,    78,    79,    79,    79,    80,    81,    81,
      82,    82,    83,    83,    83,    84,    84,    85,    85,    85,
      85,    86,    87,    87,    88,    88,    88,    88,    88,    88,
      89,    89,    89,    90,    90,    91,    92,    93,    93,    93,
      94,    94,    95,    95,    96,    96,    97,    97,    98,    98,
      99,    99,   100,   100,   101,   101,   102,   102,   103,   103,
     104,   104,   105,   105,   105,   105,   105,   106,   107,   107,
     107,   107,   108,   109,   109,   110,   110,   110,   111,   112,
     112,   112,   113,   113,   113,   113,   113,   113,   114,   114,
     114,   114,   114,   115,   115,   115,   115,   115,   115,   115,
     115,   115,   116,   116,   116,   117,   117,   117,   118,   118,
     119,   119,   120,   120,   120,   120,   120,   120,   120,   120,
     120,   121,   121,   121,   121,   121,   121,   121,   121,   121,
     122,   122,   123,   124,   124,   125,   125,   126,   126,   127,
     128,   128,   129,   129,   130,   131,   131,   131,   131,   132,
     132,   133,   134,   135,   135,   136,   137,   137,   138,   138,
     138,   138,   138,   139,   140,   140,   141,   142,   142,   143,
     143,   144,   144,   145,   146,   146,   147,   147,   147,   147,
     147,   147,   147,   147,   148,   149,   149,   149,   150,   150,
     151,   151,   152,   152,   153,   153,   154,   155,   155,   156,
     157,   157,   158,   159,   159,   160,   161,   161,   162,   163,
     163,   164,   164,   164,   164
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     1,     1,     3,
       1,     1,     1,     1,     2,     2,     3,     1,     1,     1,
       1,     1,     3,     3,     1,     1,     1,     1,     1,     4,
       4,     3,     3,     0,     1,     3,     3,     6,     1,     0,
       1,     0,     3,     3,     5,     4,     4,     4,     6,     6,
       8,     2,     3,     0,     3,     3,     3,     5,     3,     3,
       4,     3,     4,     2,     1,     3,     1,     1,     3,     3,
       1,     5,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     2,     2,     1,     2,     1,     4,     1,     1,
       2,     2,     3,     2,     0,     1,     2,     1,     3,     1,
       1,     1,     1,     3,     5,     7,     5,     1,     1,     3,
       7,     5,     1,     1,     1,     2,     1,     1,     2,     3,
       3,     5,     1,     1,     1,     1,     1,     1,     3,     5,
       3,     2,     6,     7,     7,     7,     8,     8,     8,     9,
       7,     6,     7,     7,     7,     8,     8,     8,     9,     7,
       1,     1,     2,     3,     0,     4,     3,     1,     0,     2,
       3,     0,     1,     1,     1,     4,     5,     5,     6,     2,
       0,     2,     3,     3,     0,     3,     2,     0,     1,     1,
       1,     1,     1,     4,     2,     0,     2,     3,     0,     3,
       1,     2,     1,     3,     2,     0,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     1,     2,     1,     6,     5,
       2,     0,     1,     0,     4,     2,     2,     3,     0,     4,
       2,     0,     4,     1,     1,     7,     1,     0,     4,     1,
       0,     5,     5,     7,     7
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
  case 2: /* prog: ClassDeclaration  */
#line 22 "parser.y"
                                {cout << "Program Completed\n";}
#line 1889 "parser.tab.c"
    break;


#line 1893 "parser.tab.c"

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

#line 540 "parser.y"


int main(){
    if(yyparse()) return 0;
    
    return 0;
}
