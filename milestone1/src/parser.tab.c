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
  YYSYMBOL_VariableDeclaratorList = 140,   /* VariableDeclaratorList  */
  YYSYMBOL_cVariableDeclarator = 141,      /* cVariableDeclarator  */
  YYSYMBOL_VariableDeclarator = 142,       /* VariableDeclarator  */
  YYSYMBOL_VariableDeclaratorId = 143,     /* VariableDeclaratorId  */
  YYSYMBOL_MethodDeclaration = 144,        /* MethodDeclaration  */
  YYSYMBOL_Methodmodifiers = 145,          /* Methodmodifiers  */
  YYSYMBOL_Methodmodifier = 146,           /* Methodmodifier  */
  YYSYMBOL_MethodHeader = 147,             /* MethodHeader  */
  YYSYMBOL_Result = 148,                   /* Result  */
  YYSYMBOL_Methodeclarator = 149,          /* Methodeclarator  */
  YYSYMBOL_IdenPara = 150,                 /* IdenPara  */
  YYSYMBOL_formalparameters = 151,         /* formalparameters  */
  YYSYMBOL_formalparameterlist = 152,      /* formalparameterlist  */
  YYSYMBOL_cformalparameter = 153,         /* cformalparameter  */
  YYSYMBOL_formalparameter = 154,          /* formalparameter  */
  YYSYMBOL_VariableModifier = 155,         /* VariableModifier  */
  YYSYMBOL_VariableArityParameter = 156,   /* VariableArityParameter  */
  YYSYMBOL_MethodBody = 157,               /* MethodBody  */
  YYSYMBOL_ConstructorDeclaration = 158,   /* ConstructorDeclaration  */
  YYSYMBOL_ConstructorModifiers = 159,     /* ConstructorModifiers  */
  YYSYMBOL_ConstructorBody = 160,          /* ConstructorBody  */
  YYSYMBOL_zerooroneExplicitConstructorInvocation = 161, /* zerooroneExplicitConstructorInvocation  */
  YYSYMBOL_ExplicitConstructorInvocation = 162 /* ExplicitConstructorInvocation  */
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
#define YYLAST   1373

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  65
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  98
/* YYNRULES -- Number of rules.  */
#define YYNRULES  240
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  454

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
      72,    73,    74,    75,    76,    77,    78,    79,    80,    84,
      85,    86,    90,    91,    95,    96,    97,   102,   106,   106,
     110,   110,   114,   115,   116,   121,   122,   127,   128,   129,
     130,   134,   138,   139,   143,   144,   145,   146,   147,   148,
     153,   154,   155,   159,   159,   163,   167,   171,   172,   173,
     177,   178,   182,   183,   187,   188,   192,   193,   197,   198,
     202,   203,   207,   208,   212,   213,   217,   218,   222,   223,
     227,   228,   232,   233,   234,   235,   236,   240,   244,   245,
     246,   247,   254,   258,   258,   262,   263,   264,   268,   272,
     273,   274,   278,   279,   280,   281,   282,   283,   287,   288,
     289,   290,   291,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   307,   308,   309,   313,   314,   315,   319,   320,
     324,   325,   329,   330,   331,   332,   333,   334,   335,   336,
     337,   341,   342,   343,   344,   345,   346,   347,   348,   349,
     353,   354,   358,   362,   362,   369,   370,   373,   374,   377,
     381,   381,   385,   386,   392,   395,   396,   397,   398,   401,
     401,   404,   407,   411,   411,   415,   418,   419,   422,   423,
     424,   425,   426,   429,   433,   436,   437,   440,   441,   445,
     446,   454,   458,   458,   462,   462,   462,   462,   462,   462,
     462,   466,   470,   471,   472,   473,   477,   478,   482,   485,
     486,   490,   493,   493,   496,   497,   501,   501,   504,   508,
     509,   512,   515,   515,   519,   523,   523,   526,   527,   528,
     529
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
  "VariableDeclaratorList", "cVariableDeclarator", "VariableDeclarator",
  "VariableDeclaratorId", "MethodDeclaration", "Methodmodifiers",
  "Methodmodifier", "MethodHeader", "Result", "Methodeclarator",
  "IdenPara", "formalparameters", "formalparameterlist",
  "cformalparameter", "formalparameter", "VariableModifier",
  "VariableArityParameter", "MethodBody", "ConstructorDeclaration",
  "ConstructorModifiers", "ConstructorBody",
  "zerooroneExplicitConstructorInvocation",
  "ExplicitConstructorInvocation", YY_NULLPTR
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

#define YYTABLE_NINF (-228)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -344,    70,  -344,  -344,   112,  -344,    82,  -344,  -344,  -344,
      25,    85,    85,  -344,     0,   -37,  -344,  -344,    64,    64,
    -344,   228,   -37,  -344,  -344,   126,    94,  -344,  -344,  -344,
    -344,  -344,  -344,  -344,  -344,  -344,   246,  -344,  -344,    85,
     714,    89,  -344,  -344,  -344,   180,   140,  -344,  -344,   310,
     142,    64,   144,  -344,  1320,  1320,  1320,  1320,  1320,    20,
     886,   161,   171,   175,   179,    35,  -344,   184,   267,  1320,
    -344,  -344,   140,   189,   203,   206,   172,   196,  -344,  -344,
    -344,    21,    23,  -344,  -344,  -344,  -344,  -344,    26,   250,
     199,   207,   212,   255,   266,   268,   269,   265,  -344,  -344,
    -344,  -344,  -344,   222,  -344,  -344,   223,    49,  -344,  -344,
    -344,  -344,   252,   235,   140,   230,  -344,   239,   244,   248,
    -344,  -344,  -344,  -344,  -344,  -344,  -344,  -344,   140,  -344,
    -344,    -1,   293,    39,  -344,   814,    88,  -344,  -344,  -344,
    -344,  -344,  -344,  -344,    43,  -344,   240,   241,  -344,  -344,
     242,  1320,   892,  1320,  1320,   303,   304,   273,   259,    -8,
      80,   257,    31,  -344,   309,   117,  1320,  1320,   137,   277,
     281,  -344,   318,    30,  1320,  1320,  1320,  1320,  1320,  1320,
    1320,  1320,  1320,  1320,  1320,  1320,  -344,  -344,  1320,  1320,
    -344,  -344,  -344,  -344,   180,   271,  -344,  -344,   209,  -344,
     248,  -344,   272,  1050,  -344,   280,   248,  -344,  -344,  -344,
    -344,   140,   183,   270,  1320,   158,    86,  -344,  -344,  -344,
    1320,  -344,  -344,  -344,  -344,   275,   928,   282,  -344,   279,
    -344,   285,   290,  -344,   292,  -344,  1314,     3,   259,  -344,
    1320,  1320,  -344,   312,   294,  -344,    87,  -344,    85,  -344,
     297,   296,  -344,  -344,   315,  -344,  -344,  -344,   300,  -344,
     308,   250,   307,   212,   255,   199,   207,   266,   268,   269,
     265,  -344,  -344,  -344,  -344,  -344,   313,    28,   180,  1050,
    -344,  -344,  -344,  -344,   248,  1320,  1320,   120,    63,   764,
     311,   850,  1086,   316,  1320,   321,   950,   814,   317,  1320,
     319,  -344,   248,  -344,   323,  -344,  -344,  -344,   369,   380,
    -344,  -344,   334,  -344,  1320,  -344,  1320,  -344,   386,  -344,
    -344,    -6,  -344,  -344,   338,   341,   185,   345,  -344,  -344,
     342,   348,   349,   351,  -344,   379,   382,  -344,   814,   355,
    1092,   356,  1320,  1143,   347,  -344,  -344,   360,  -344,   -37,
    -344,   363,  1320,   367,  -344,  -344,  -344,   361,  -344,   368,
     364,   365,  1320,  1320,   850,  1320,   986,  1320,   814,  -344,
     814,   814,   371,   814,  -344,   814,   372,  1149,  -344,  -344,
    -344,  1320,  -344,  -344,  -344,  1050,  -344,  -344,   373,   376,
    -344,   378,   992,   377,   370,   383,  -344,  -344,  -344,   814,
    -344,  -344,   814,   814,   388,   390,  -344,   385,   387,   850,
    1200,   389,  1320,  1028,   850,  -344,  -344,  -344,   814,  -344,
    -344,  -344,   410,   850,   400,  1206,   402,  1257,   395,  -344,
    -344,   850,  -344,   850,   850,   408,   850,   850,   409,  1263,
    -344,  -344,  -344,   850,  -344,  -344,   850,   850,   411,  -344,
    -344,  -344,   850,  -344
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
     180,     0,     2,   174,     0,     1,     0,    11,    12,   179,
       0,     0,     0,   187,     0,     0,   175,    10,   184,    13,
     181,   233,     0,   176,   177,     0,   182,   104,   185,   189,
     232,   190,   186,   188,   192,   191,   203,   178,     9,     0,
     180,     0,     7,     8,     6,     0,     3,     5,     4,     0,
       0,   183,    10,    19,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    21,     0,     0,     0,
     102,   124,    33,    99,     0,     0,    98,    17,    20,    24,
      34,    25,    26,    27,    28,    18,   132,    67,    70,    72,
      78,    80,    74,    76,    82,    84,    86,    88,    90,    96,
      94,   123,   103,     0,   107,   112,     0,     0,   126,   127,
     117,   105,     0,   227,   200,     0,   196,   198,     0,    14,
     208,   207,   215,   206,   205,   209,   210,   204,   212,   213,
     202,     0,     0,   236,   231,     0,    99,    24,    25,    26,
      27,    93,    92,    95,     0,    66,     0,     0,   141,   128,
       0,     0,   227,     0,     0,     0,     0,     0,     0,     0,
      33,     0,     0,   101,     0,     0,     0,    39,     0,     0,
       0,   100,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   106,   125,     0,     0,
     111,   226,   109,   110,     0,     0,   219,   223,     0,   225,
     199,   193,   194,     0,    15,     0,   214,   230,   229,   201,
     211,   217,     0,    21,     0,     0,     0,   104,   235,   113,
       0,   138,   130,   140,   129,     0,     0,   161,   164,     0,
     160,     0,     0,    56,    43,    31,     0,     0,    61,    64,
      39,     0,    23,     0,     0,    54,     0,    22,     0,    35,
       0,     0,    38,    53,     0,    58,    59,    55,    42,    36,
       0,    73,     0,    75,    77,    79,    81,    83,    85,    87,
      89,    91,    68,    69,   108,   218,   221,     0,     0,   168,
     172,   173,   197,    16,   216,    39,    39,     0,     0,   180,
       0,     0,     0,     0,     0,   162,     0,     0,     0,    39,
       0,    62,    60,    63,     0,    97,    30,    32,     0,     0,
      45,    47,    51,    29,    39,    46,     0,   227,     0,   224,
     195,     0,   167,   171,     0,     0,     0,     0,   234,   139,
      10,     0,     0,     0,   114,     0,   112,   122,     0,     0,
       0,     0,     0,     0,     0,   116,   131,     0,    65,    41,
      57,    44,     0,     0,    71,   222,   228,     0,   166,   169,
       0,     0,    39,    39,     0,     0,   227,     0,     0,   142,
       0,     0,     0,     0,   163,     0,     0,     0,    49,    37,
      40,    39,    52,    48,   165,     0,   238,   237,     0,     0,
     119,     0,     0,   161,     0,     0,   115,   145,   144,     0,
     150,   143,     0,     0,     0,     0,   170,     0,     0,     0,
       0,     0,     0,     0,     0,   146,   148,   147,     0,    50,
     239,   240,     0,     0,     0,     0,     0,     0,     0,   121,
     149,     0,   151,     0,     0,     0,     0,     0,     0,     0,
     120,   154,   153,     0,   159,   152,     0,     0,     0,   155,
     157,   156,     0,   158
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -344,  -344,  -100,   -13,  -344,    -4,   419,     5,   -16,   -98,
     331,  -344,  -344,   -50,   -40,  -155,   -93,  -344,   -15,   426,
      75,  -344,  -344,  -344,  -344,  -344,   231,   -31,   362,   150,
    -344,   298,   289,   295,   302,   305,   291,   306,   314,   320,
     -41,  -344,  -344,   -20,   274,  -344,  -147,  -344,   251,  -343,
      24,  -146,  -344,  -344,  -344,  -344,  -344,   121,  -224,  -344,
     249,  -344,  -344,  -344,  -260,   490,  -344,  -344,  -344,   478,
    -344,   -11,  -344,  -344,  -344,   301,  -344,   216,   -47,  -344,
    -344,  -344,  -344,  -344,  -344,   375,  -344,  -344,  -344,   182,
    -104,  -344,  -344,  -344,  -344,  -344,  -344,  -344
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,    45,    72,    47,    73,     9,    74,    75,   119,
      76,    77,    78,   168,   137,    80,   251,   379,    81,    82,
     140,   252,   312,    84,    85,   238,   239,   253,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,    40,   102,   103,   194,   104,   335,
     105,   106,   107,   108,   109,   110,   337,   229,   230,   295,
     281,   321,   322,   359,   282,   111,     3,     4,    14,    15,
      26,    16,    21,    32,    33,   115,   202,   116,   117,    34,
      49,   130,   131,   132,   210,    50,   195,   196,   276,   197,
     112,   199,   209,    35,    36,   134,   217,   218
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      79,    31,   129,    23,    24,   227,   228,    18,    19,   198,
     249,    37,   192,   141,   142,   143,   200,    20,   259,   323,
      48,   390,   162,    46,   147,    13,   144,   146,    11,   150,
     206,  -136,   114,  -137,   258,    51,   128,   175,   161,   138,
     138,   138,    25,    17,    53,   240,    42,    43,    44,   357,
     136,   136,   136,    11,   205,   158,   160,   358,    12,   188,
     237,    27,    13,   207,   159,   279,   422,   258,   339,   248,
       5,   429,   318,   212,   213,   155,    67,  -136,    68,  -137,
     432,   243,   244,   176,   148,   156,    10,    13,   440,    17,
     441,   442,   214,   444,   445,    79,    48,   327,   277,    46,
     449,   220,   248,   450,   451,   189,   163,   221,    19,   453,
     162,   208,    79,   284,    25,    83,   372,   193,   138,   376,
     225,    38,   231,   232,    38,   406,   172,   308,   164,   215,
      38,   118,   249,   259,   241,   250,   288,   309,   165,   166,
     302,   167,   113,   260,   271,   262,   228,   304,     6,    39,
       7,   246,   247,   404,   326,   247,   248,   272,   273,   248,
     138,     8,   138,   138,   138,   138,   138,   138,   138,   138,
     138,   136,   280,   136,   136,   136,   136,   136,   136,   136,
     136,   136,    48,   161,   114,    46,   424,   254,   244,   290,
     171,   118,   324,   325,   228,   293,   374,   228,   164,  -135,
     305,   435,   135,   438,   133,   300,   347,   163,   287,   166,
      83,   167,   172,   198,   151,   448,    42,    43,    44,   393,
     228,   353,   173,   155,   152,   308,   138,    83,   153,   164,
     319,   228,   154,   156,   157,   309,   285,   136,   362,   165,
     166,   191,   167,   169,   159,  -135,   170,   174,   280,    79,
      41,    79,    79,    42,    43,    44,    17,    79,   178,    42,
      43,    44,   177,   341,   228,   344,     7,   179,   181,   388,
     389,    17,   190,   180,    42,    43,    44,     8,   346,   228,
     182,   228,   185,   183,   191,   184,   186,   187,   405,  -220,
      27,    28,    29,   228,   201,   203,   204,    41,    79,   205,
      79,   138,    79,    79,   222,   223,   224,   233,   234,   235,
     236,   242,   136,   245,   114,   336,   255,    42,    43,    44,
     256,   382,   257,   286,    79,   275,    79,   278,    79,   291,
      79,    79,   283,    79,   391,    79,   395,    79,   380,   297,
     294,   120,   121,   296,   298,   299,   307,   122,   306,   310,
     311,   313,   123,   314,   280,   124,   125,   126,   127,    79,
     315,   411,    79,    79,    83,   316,    83,    83,   317,    79,
      79,   348,    83,   350,    79,   329,   342,   349,    79,    27,
     340,   426,   428,    79,   351,    79,   219,    79,   336,   352,
     356,    79,   360,    79,    79,   361,    79,    79,   363,    79,
     364,   365,   366,    79,   367,   368,    79,    79,  -118,   370,
     373,   377,    79,    83,   378,    83,   381,    83,    83,   145,
     145,   383,   145,   385,   384,   399,   402,   407,   386,   387,
     408,   145,   409,   336,   413,   412,   431,   414,   336,    83,
      30,    83,   418,    83,   419,    83,    83,   336,    83,   420,
      83,   421,    83,   425,   433,   336,   436,   336,   336,   439,
     336,   336,   443,   446,   216,   452,   354,   336,   265,   303,
     336,   336,   267,   261,    83,   266,   336,    83,    83,   263,
     139,   139,   139,   264,    83,    83,   301,   394,   268,    83,
       2,   289,    22,    83,   320,   274,     0,   269,    83,   355,
      83,     0,    83,     0,   270,     0,    83,   211,    83,    83,
       0,    83,    83,   145,    83,   145,   145,     0,    83,     0,
       0,    83,    83,     0,     0,     0,     0,    83,   145,   145,
       0,     0,     0,     0,     0,     0,   145,     0,   145,     0,
       0,     0,   334,     0,     0,     0,     0,     0,   345,     0,
     145,   145,     0,     0,     0,     0,     0,     0,     0,   139,
       0,     0,     0,     0,     0,   145,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   145,     0,     0,     0,
       0,     0,   145,     0,     0,     0,     0,     0,   145,   369,
       0,     0,     0,     0,     0,     0,     0,     0,   145,     0,
       0,   139,   145,   139,   139,   139,   139,   139,   139,   139,
     139,   139,     0,     0,     0,   219,     0,     0,     0,   396,
       0,   397,   398,     0,   400,     0,   401,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   145,     0,     0,     0,     0,     0,   145,   145,     0,
     415,     0,     0,   416,   417,     0,   145,     0,   145,     0,
     334,   145,     0,     0,     0,   345,     0,   139,     0,   430,
       0,     0,     0,     0,   369,     0,   145,     0,     0,     0,
       0,     0,   396,     0,   397,   398,     0,   400,   401,     0,
       0,     0,     0,     0,   415,     0,     0,   416,   417,     0,
       0,     0,     0,   430,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   145,     0,     0,     0,    52,    53,
       0,    42,    43,    44,   145,   145,     0,   145,     0,   145,
      54,     0,    55,    56,  -227,    57,    58,    59,    60,    61,
       0,    62,   139,   145,    63,    64,  -227,   145,    65,    66,
       0,    67,     0,    68,   145,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    69,    52,    53,
       0,    42,    43,    44,   145,   145,    27,    70,    71,     0,
      54,     0,    55,    56,  -227,    57,    58,    59,    60,    61,
       0,    62,     0,     0,    63,    64,  -227,     0,    65,    66,
       0,    67,     0,    68,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    69,    52,    53,
       0,    42,    43,    44,     0,     0,    27,   328,    71,     0,
      54,     0,    55,    56,     0,    57,    58,    59,    60,    61,
       0,    62,     0,     0,    63,    64,     0,     0,    65,    66,
       0,    67,     0,    68,   330,    53,     0,    42,    43,    44,
       0,     0,     0,     0,     0,     0,    54,    69,    55,    56,
       0,    57,    58,    59,    60,   331,    27,   332,    71,     0,
     333,    64,     0,     0,    65,    66,     0,    67,     0,    68,
      17,    53,     0,    42,    43,    44,    17,    53,     0,    42,
      43,    44,    54,    69,    55,    56,     0,     0,    54,     0,
      55,    56,    27,     0,    71,     0,     0,     0,     0,     0,
      65,    66,     0,    67,     0,    68,    65,    66,     0,    67,
       0,    68,    17,    53,     0,    42,    43,    44,     0,    69,
       0,     0,     0,     0,    54,    69,    55,    56,     0,     0,
     149,     0,     0,     0,    17,    53,   226,    42,    43,    44,
       0,     0,    65,    66,     0,    67,    54,    68,    55,    56,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    69,     0,     0,    65,    66,     0,    67,     0,    68,
      17,    53,   292,    42,    43,    44,    17,    53,     0,    42,
      43,    44,    54,    69,    55,    56,     0,     0,    54,     0,
      55,    56,     0,     0,   343,     0,     0,     0,     0,     0,
      65,    66,     0,    67,     0,    68,    65,    66,     0,    67,
       0,    68,    17,    53,     0,    42,    43,    44,     0,    69,
       0,     0,     0,     0,    54,    69,    55,    56,     0,     0,
     392,     0,     0,     0,    17,    53,   410,    42,    43,    44,
       0,     0,    65,    66,     0,    67,    54,    68,    55,    56,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    69,     0,     0,    65,    66,     0,    67,     0,    68,
      17,    53,   427,    42,    43,    44,    17,    53,     0,    42,
      43,    44,    54,    69,    55,    56,     0,     0,    54,     0,
      55,    56,   279,     0,     0,     0,     0,     0,     0,     0,
      65,    66,     0,    67,     0,    68,    65,    66,     0,    67,
       0,    68,     0,     0,     0,     0,     0,     0,     0,    69,
     338,     0,     0,     0,     0,    69,   371,    17,    53,     0,
      42,    43,    44,    17,    53,     0,    42,    43,    44,    54,
       0,    55,    56,     0,     0,    54,     0,    55,    56,     0,
       0,     0,     0,     0,     0,     0,     0,    65,    66,     0,
      67,     0,    68,    65,    66,     0,    67,     0,    68,     0,
       0,     0,     0,     0,     0,     0,    69,   375,     0,     0,
       0,     0,    69,   403,    17,    53,     0,    42,    43,    44,
      17,    53,     0,    42,    43,    44,    54,     0,    55,    56,
       0,     0,    54,     0,    55,    56,     0,     0,     0,     0,
       0,     0,     0,     0,    65,    66,     0,    67,     0,    68,
      65,    66,     0,    67,     0,    68,     0,     0,     0,     0,
       0,     0,     0,    69,   423,     0,     0,     0,     0,    69,
     434,    17,    53,     0,    42,    43,    44,    17,    53,     0,
      42,    43,    44,    54,     0,    55,    56,     0,     0,    54,
       0,    55,    56,     0,     0,     0,     0,     0,     0,     0,
       0,    65,    66,     0,    67,     0,    68,    65,    66,     0,
      67,     0,    68,     0,     0,     0,     0,     0,     0,     0,
      69,   437,     0,     0,     0,     0,    69,   447,    17,    53,
       0,    42,    43,    44,    17,    53,     0,    42,    43,    44,
      54,     0,    55,    56,     0,     0,    54,     0,    55,    56,
       0,     0,     0,     0,     0,     0,     0,     0,    65,    66,
       0,    67,     0,    68,    65,    66,     0,    67,     0,    68,
       0,     0,     0,     0,     0,     0,   204,    69,     0,     0,
       0,     0,     0,    69
};

static const yytype_int16 yycheck[] =
{
      40,    21,    49,    14,    15,   152,   152,    11,    12,   113,
     165,    22,   112,    54,    55,    56,   114,    12,   173,   279,
      36,   364,    72,    36,     4,    62,    57,    58,    28,    60,
     128,    10,     4,    10,     4,    39,    49,    11,    69,    54,
      55,    56,    50,     4,     5,    53,     7,     8,     9,    55,
      54,    55,    56,    28,    51,    68,    69,    63,    33,    10,
     158,    62,    62,    64,    68,    62,   409,     4,   292,    39,
       0,   414,    44,    34,    35,    40,    37,    56,    39,    56,
     423,    50,    51,    57,    64,    50,     4,    62,   431,     4,
     433,   434,    53,   436,   437,   135,   112,    34,   198,   112,
     443,    58,    39,   446,   447,    56,    18,    64,   112,   452,
     160,   131,   152,   211,    50,    40,   340,   112,   133,   343,
     151,     4,   153,   154,     4,   385,    40,    40,    40,   133,
       4,    51,   287,   288,    54,   166,    50,    50,    50,    51,
     238,    53,    53,   174,   185,   176,   292,   240,    36,    55,
      38,    34,    35,   377,    34,    35,    39,   188,   189,    39,
     175,    49,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   175,   203,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   198,   214,     4,   198,   410,    50,    51,   220,
      18,    51,   285,   286,   340,   226,   342,   343,    40,    10,
     241,   425,    58,   427,    62,   236,   299,    18,    50,    51,
     135,    53,    40,   317,    53,   439,     7,     8,     9,   366,
     366,   314,    50,    40,    53,    40,   241,   152,    53,    40,
     277,   377,    53,    50,    50,    50,    53,   241,    53,    50,
      51,    32,    53,    40,   248,    56,    40,    51,   279,   289,
       4,   291,   292,     7,     8,     9,     4,   297,    59,     7,
       8,     9,    12,   294,   410,   296,    38,    60,    13,   362,
     363,     4,    20,    61,     7,     8,     9,    49,   298,   425,
      14,   427,    17,    15,    32,    16,    64,    64,   381,    54,
      62,    63,    64,   439,    64,    56,    52,     4,   338,    51,
     340,   316,   342,   343,    64,    64,    64,     4,     4,    36,
      51,    54,   316,     4,     4,   291,    39,     7,     8,     9,
      39,   352,     4,    53,   364,    54,   366,    55,   368,    54,
     370,   371,    52,   373,   365,   375,   367,   377,   349,    54,
      58,    31,    32,    64,    54,    53,    52,    37,    36,    52,
      54,    36,    42,    53,   385,    45,    46,    47,    48,   399,
      52,   392,   402,   403,   289,    58,   291,   292,    55,   409,
     410,    52,   297,     4,   414,    64,    55,    54,   418,    62,
      64,   412,   413,   423,     4,   425,   135,   427,   364,    55,
       4,   431,    54,   433,   434,    54,   436,   437,    53,   439,
      58,    53,    53,   443,    53,    26,   446,   447,    26,    54,
      54,    64,   452,   338,    54,   340,    53,   342,   343,    57,
      58,    54,    60,    55,    63,    54,    54,    54,    64,    64,
      54,    69,    54,   409,    64,    58,    26,    54,   414,   364,
      21,   366,    54,   368,    54,   370,   371,   423,   373,    64,
     375,    64,   377,    64,    54,   431,    54,   433,   434,    64,
     436,   437,    54,    54,   133,    54,   316,   443,   179,   238,
     446,   447,   181,   175,   399,   180,   452,   402,   403,   177,
      54,    55,    56,   178,   409,   410,   237,   366,   182,   414,
       0,   217,    14,   418,   278,   194,    -1,   183,   423,   317,
     425,    -1,   427,    -1,   184,    -1,   431,   132,   433,   434,
      -1,   436,   437,   151,   439,   153,   154,    -1,   443,    -1,
      -1,   446,   447,    -1,    -1,    -1,    -1,   452,   166,   167,
      -1,    -1,    -1,    -1,    -1,    -1,   174,    -1,   176,    -1,
      -1,    -1,   291,    -1,    -1,    -1,    -1,    -1,   297,    -1,
     188,   189,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   133,
      -1,    -1,    -1,    -1,    -1,   203,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   214,    -1,    -1,    -1,
      -1,    -1,   220,    -1,    -1,    -1,    -1,    -1,   226,   338,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   236,    -1,
      -1,   175,   240,   177,   178,   179,   180,   181,   182,   183,
     184,   185,    -1,    -1,    -1,   364,    -1,    -1,    -1,   368,
      -1,   370,   371,    -1,   373,    -1,   375,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   279,    -1,    -1,    -1,    -1,    -1,   285,   286,    -1,
     399,    -1,    -1,   402,   403,    -1,   294,    -1,   296,    -1,
     409,   299,    -1,    -1,    -1,   414,    -1,   241,    -1,   418,
      -1,    -1,    -1,    -1,   423,    -1,   314,    -1,    -1,    -1,
      -1,    -1,   431,    -1,   433,   434,    -1,   436,   437,    -1,
      -1,    -1,    -1,    -1,   443,    -1,    -1,   446,   447,    -1,
      -1,    -1,    -1,   452,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   352,    -1,    -1,    -1,     4,     5,
      -1,     7,     8,     9,   362,   363,    -1,   365,    -1,   367,
      16,    -1,    18,    19,    20,    21,    22,    23,    24,    25,
      -1,    27,   316,   381,    30,    31,    32,   385,    34,    35,
      -1,    37,    -1,    39,   392,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,     4,     5,
      -1,     7,     8,     9,   412,   413,    62,    63,    64,    -1,
      16,    -1,    18,    19,    20,    21,    22,    23,    24,    25,
      -1,    27,    -1,    -1,    30,    31,    32,    -1,    34,    35,
      -1,    37,    -1,    39,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,     4,     5,
      -1,     7,     8,     9,    -1,    -1,    62,    63,    64,    -1,
      16,    -1,    18,    19,    -1,    21,    22,    23,    24,    25,
      -1,    27,    -1,    -1,    30,    31,    -1,    -1,    34,    35,
      -1,    37,    -1,    39,     4,     5,    -1,     7,     8,     9,
      -1,    -1,    -1,    -1,    -1,    -1,    16,    53,    18,    19,
      -1,    21,    22,    23,    24,    25,    62,    27,    64,    -1,
      30,    31,    -1,    -1,    34,    35,    -1,    37,    -1,    39,
       4,     5,    -1,     7,     8,     9,     4,     5,    -1,     7,
       8,     9,    16,    53,    18,    19,    -1,    -1,    16,    -1,
      18,    19,    62,    -1,    64,    -1,    -1,    -1,    -1,    -1,
      34,    35,    -1,    37,    -1,    39,    34,    35,    -1,    37,
      -1,    39,     4,     5,    -1,     7,     8,     9,    -1,    53,
      -1,    -1,    -1,    -1,    16,    53,    18,    19,    -1,    -1,
      64,    -1,    -1,    -1,     4,     5,    64,     7,     8,     9,
      -1,    -1,    34,    35,    -1,    37,    16,    39,    18,    19,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    53,    -1,    -1,    34,    35,    -1,    37,    -1,    39,
       4,     5,    64,     7,     8,     9,     4,     5,    -1,     7,
       8,     9,    16,    53,    18,    19,    -1,    -1,    16,    -1,
      18,    19,    -1,    -1,    64,    -1,    -1,    -1,    -1,    -1,
      34,    35,    -1,    37,    -1,    39,    34,    35,    -1,    37,
      -1,    39,     4,     5,    -1,     7,     8,     9,    -1,    53,
      -1,    -1,    -1,    -1,    16,    53,    18,    19,    -1,    -1,
      64,    -1,    -1,    -1,     4,     5,    64,     7,     8,     9,
      -1,    -1,    34,    35,    -1,    37,    16,    39,    18,    19,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    53,    -1,    -1,    34,    35,    -1,    37,    -1,    39,
       4,     5,    64,     7,     8,     9,     4,     5,    -1,     7,
       8,     9,    16,    53,    18,    19,    -1,    -1,    16,    -1,
      18,    19,    62,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      34,    35,    -1,    37,    -1,    39,    34,    35,    -1,    37,
      -1,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,
      54,    -1,    -1,    -1,    -1,    53,    54,     4,     5,    -1,
       7,     8,     9,     4,     5,    -1,     7,     8,     9,    16,
      -1,    18,    19,    -1,    -1,    16,    -1,    18,    19,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,    35,    -1,
      37,    -1,    39,    34,    35,    -1,    37,    -1,    39,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    53,    54,    -1,    -1,
      -1,    -1,    53,    54,     4,     5,    -1,     7,     8,     9,
       4,     5,    -1,     7,     8,     9,    16,    -1,    18,    19,
      -1,    -1,    16,    -1,    18,    19,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    34,    35,    -1,    37,    -1,    39,
      34,    35,    -1,    37,    -1,    39,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    53,    54,    -1,    -1,    -1,    -1,    53,
      54,     4,     5,    -1,     7,     8,     9,     4,     5,    -1,
       7,     8,     9,    16,    -1,    18,    19,    -1,    -1,    16,
      -1,    18,    19,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    34,    35,    -1,    37,    -1,    39,    34,    35,    -1,
      37,    -1,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      53,    54,    -1,    -1,    -1,    -1,    53,    54,     4,     5,
      -1,     7,     8,     9,     4,     5,    -1,     7,     8,     9,
      16,    -1,    18,    19,    -1,    -1,    16,    -1,    18,    19,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,    35,
      -1,    37,    -1,    39,    34,    35,    -1,    37,    -1,    39,
      -1,    -1,    -1,    -1,    -1,    -1,    52,    53,    -1,    -1,
      -1,    -1,    -1,    53
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    66,   130,   131,   132,     0,    36,    38,    49,    71,
       4,    28,    33,    62,   133,   134,   136,     4,    70,    70,
      72,   137,   134,   136,   136,    50,   135,    62,    63,    64,
      71,   108,   138,   139,   144,   158,   159,   136,     4,    55,
     109,     4,     7,     8,     9,    67,    68,    69,    73,   145,
     150,    70,     4,     5,    16,    18,    19,    21,    22,    23,
      24,    25,    27,    30,    31,    34,    35,    37,    39,    53,
      63,    64,    68,    70,    72,    73,    75,    76,    77,    79,
      80,    83,    84,    85,    88,    89,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   110,   111,   113,   115,   116,   117,   118,   119,
     120,   130,   155,    53,     4,   140,   142,   143,    51,    74,
      31,    32,    37,    42,    45,    46,    47,    48,    68,   143,
     146,   147,   148,    62,   160,    58,    70,    79,    83,    84,
      85,   105,   105,   105,    92,    93,    92,     4,    64,    64,
      92,    53,    53,    53,    53,    40,    50,    50,    68,    70,
      68,    92,    78,    18,    40,    50,    51,    53,    78,    40,
      40,    18,    40,    50,    51,    11,    57,    12,    59,    60,
      61,    13,    14,    15,    16,    17,    64,    64,    10,    56,
      20,    32,    67,    72,   112,   151,   152,   154,   155,   156,
      74,    64,   141,    56,    52,    51,    74,    64,   108,   157,
     149,   150,    34,    35,    53,    70,    75,   161,   162,   113,
      58,    64,    64,    64,    64,    92,    64,   111,   116,   122,
     123,    92,    92,     4,     4,    36,    51,    74,    90,    91,
      53,    54,    54,    50,    51,     4,    34,    35,    39,    80,
      92,    81,    86,    92,    50,    39,    39,     4,     4,    80,
      92,    96,    92,    99,   100,    97,    98,   101,   102,   103,
     104,   105,    92,    92,   140,    54,   153,    67,    55,    62,
      92,   125,   129,    52,    74,    53,    53,    50,    50,   109,
      92,    54,    64,    92,    58,   124,    64,    54,    54,    53,
      92,   125,    74,    91,    81,   105,    36,    52,    40,    50,
      52,    54,    87,    36,    53,    52,    58,    55,    44,   143,
     142,   126,   127,   129,    81,    81,    34,    34,    63,    64,
       4,    25,    27,    30,   113,   114,   115,   121,    54,   123,
      64,    92,    55,    64,    92,   113,   108,    81,    52,    54,
       4,     4,    55,    81,    94,   154,     4,    55,    63,   128,
      54,    54,    53,    53,    58,    53,    53,    53,    26,   113,
      54,    54,   123,    54,   116,    54,   123,    64,    54,    82,
     136,    53,    92,    54,    63,    55,    64,    64,    81,    81,
     114,    92,    64,   111,   122,    92,   113,   113,   113,    54,
     113,   113,    54,    54,   123,    81,   129,    54,    54,    54,
      64,    92,    58,    64,    54,   113,   113,   113,    54,    54,
      64,    64,   114,    54,   123,    64,    92,    64,    92,   114,
     113,    26,   114,    54,    54,   123,    54,    54,   123,    64,
     114,   114,   114,    54,   114,   114,    54,    54,   123,   114,
     114,   114,    54,   114
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
     138,   138,   138,   139,   140,   141,   141,   142,   142,   143,
     143,   144,   145,   145,   146,   146,   146,   146,   146,   146,
     146,   147,   148,   148,   148,   148,   149,   149,   150,   151,
     151,   152,   153,   153,   154,   154,   155,   155,   156,   157,
     157,   158,   159,   159,   160,   161,   161,   162,   162,   162,
     162
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
       1,     1,     1,     4,     2,     3,     0,     3,     1,     2,
       1,     4,     2,     0,     1,     1,     1,     1,     1,     1,
       1,     2,     1,     1,     2,     1,     2,     1,     4,     1,
       0,     2,     3,     0,     3,     1,     2,     0,     4,     1,
       1,     3,     1,     0,     4,     1,     0,     5,     5,     7,
       7
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
#line 1878 "parser.tab.c"
    break;


#line 1882 "parser.tab.c"

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

#line 533 "parser.y"


int main(){
    if(yyparse()) return 0;
    
    return 0;
}
