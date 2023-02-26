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
  YYSYMBOL_ESCSEQ = 6,                     /* ESCSEQ  */
  YYSYMBOL_OPERATOR = 7,                   /* OPERATOR  */
  YYSYMBOL_SEP = 8,                        /* SEP  */
  YYSYMBOL_INTTYPE = 9,                    /* INTTYPE  */
  YYSYMBOL_FPTYPE = 10,                    /* FPTYPE  */
  YYSYMBOL_BOOLTYPE = 11,                  /* BOOLTYPE  */
  YYSYMBOL_ASSIGNOP = 12,                  /* ASSIGNOP  */
  YYSYMBOL_CONDOR = 13,                    /* CONDOR  */
  YYSYMBOL_CONDAND = 14,                   /* CONDAND  */
  YYSYMBOL_EQALITYOP = 15,                 /* EQALITYOP  */
  YYSYMBOL_RELATIONOP = 16,                /* RELATIONOP  */
  YYSYMBOL_SHIFTOP = 17,                   /* SHIFTOP  */
  YYSYMBOL_ADDOP = 18,                     /* ADDOP  */
  YYSYMBOL_MULTOP = 19,                    /* MULTOP  */
  YYSYMBOL_ADDOP2 = 20,                    /* ADDOP2  */
  YYSYMBOL_UNARYOP = 21,                   /* UNARYOP  */
  YYSYMBOL_KEY_VAR = 22,                   /* KEY_VAR  */
  YYSYMBOL_KEY_assert = 23,                /* KEY_assert  */
  YYSYMBOL_KEY_yiethr = 24,                /* KEY_yiethr  */
  YYSYMBOL_KEY_brecon = 25,                /* KEY_brecon  */
  YYSYMBOL_KEY_return = 26,                /* KEY_return  */
  YYSYMBOL_KEY_if = 27,                    /* KEY_if  */
  YYSYMBOL_KEY_else = 28,                  /* KEY_else  */
  YYSYMBOL_KEY_for = 29,                   /* KEY_for  */
  YYSYMBOL_KEY_permits = 30,               /* KEY_permits  */
  YYSYMBOL_KEY_record = 31,                /* KEY_record  */
  YYSYMBOL_KEY_while = 32,                 /* KEY_while  */
  YYSYMBOL_KEY_sync = 33,                  /* KEY_sync  */
  YYSYMBOL_KEY_final = 34,                 /* KEY_final  */
  YYSYMBOL_KEY_extends = 35,               /* KEY_extends  */
  YYSYMBOL_KEY_super = 36,                 /* KEY_super  */
  YYSYMBOL_KEY_this = 37,                  /* KEY_this  */
  YYSYMBOL_KEY_class = 38,                 /* KEY_class  */
  YYSYMBOL_KEY_void = 39,                  /* KEY_void  */
  YYSYMBOL_KEY_public = 40,                /* KEY_public  */
  YYSYMBOL_KEY_new = 41,                   /* KEY_new  */
  YYSYMBOL_COLON2 = 42,                    /* COLON2  */
  YYSYMBOL_KEY_throws = 43,                /* KEY_throws  */
  YYSYMBOL_KEY_static = 44,                /* KEY_static  */
  YYSYMBOL_KEY_enum = 45,                  /* KEY_enum  */
  YYSYMBOL_DOT3 = 46,                      /* DOT3  */
  YYSYMBOL_KEY_abstract = 47,              /* KEY_abstract  */
  YYSYMBOL_KEY_native = 48,                /* KEY_native  */
  YYSYMBOL_KEY_strictf = 49,               /* KEY_strictf  */
  YYSYMBOL_KEY_protected = 50,             /* KEY_protected  */
  YYSYMBOL_KEY_private = 51,               /* KEY_private  */
  YYSYMBOL_52_ = 52,                       /* '.'  */
  YYSYMBOL_53_ = 53,                       /* '['  */
  YYSYMBOL_54_ = 54,                       /* ']'  */
  YYSYMBOL_55_ = 55,                       /* '<'  */
  YYSYMBOL_56_ = 56,                       /* '>'  */
  YYSYMBOL_57_ = 57,                       /* ','  */
  YYSYMBOL_58_ = 58,                       /* '?'  */
  YYSYMBOL_59_ = 59,                       /* '('  */
  YYSYMBOL_60_ = 60,                       /* ')'  */
  YYSYMBOL_61_ = 61,                       /* '='  */
  YYSYMBOL_62_ = 62,                       /* ':'  */
  YYSYMBOL_63_ = 63,                       /* '&'  */
  YYSYMBOL_64_ = 64,                       /* '^'  */
  YYSYMBOL_65_ = 65,                       /* '|'  */
  YYSYMBOL_66_ = 66,                       /* '{'  */
  YYSYMBOL_67_ = 67,                       /* '}'  */
  YYSYMBOL_68_ = 68,                       /* ';'  */
  YYSYMBOL_YYACCEPT = 69,                  /* $accept  */
  YYSYMBOL_prog = 70,                      /* prog  */
  YYSYMBOL_Type = 71,                      /* Type  */
  YYSYMBOL_PrimitiveType = 72,             /* PrimitiveType  */
  YYSYMBOL_NumericType = 73,               /* NumericType  */
  YYSYMBOL_ReferenceType = 74,             /* ReferenceType  */
  YYSYMBOL_IDENdotIDEN = 75,               /* IDENdotIDEN  */
  YYSYMBOL_ClassModifier = 76,             /* ClassModifier  */
  YYSYMBOL_ClassType = 77,                 /* ClassType  */
  YYSYMBOL_Zeroorone_TypeArguments = 78,   /* Zeroorone_TypeArguments  */
  YYSYMBOL_ArrayType = 79,                 /* ArrayType  */
  YYSYMBOL_Dims = 80,                      /* Dims  */
  YYSYMBOL_TypeParameter = 81,             /* TypeParameter  */
  YYSYMBOL_TypeBound = 82,                 /* TypeBound  */
  YYSYMBOL_TypeArguments = 83,             /* TypeArguments  */
  YYSYMBOL_TypeArgumentList = 84,          /* TypeArgumentList  */
  YYSYMBOL_cTypeArgument = 85,             /* cTypeArgument  */
  YYSYMBOL_TypeArgument = 86,              /* TypeArgument  */
  YYSYMBOL_Wildcard = 87,                  /* Wildcard  */
  YYSYMBOL_WildcardBounds = 88,            /* WildcardBounds  */
  YYSYMBOL_Primary = 89,                   /* Primary  */
  YYSYMBOL_PrimaryNoNewArray = 90,         /* PrimaryNoNewArray  */
  YYSYMBOL_ClassLiteral = 91,              /* ClassLiteral  */
  YYSYMBOL_Zero_or_moreSquarebracket = 92, /* Zero_or_moreSquarebracket  */
  YYSYMBOL_ClassInstanceCreationExpression = 93, /* ClassInstanceCreationExpression  */
  YYSYMBOL_UnqualifiedClassInstanceCreationExpression = 94, /* UnqualifiedClassInstanceCreationExpression  */
  YYSYMBOL_Zeroorone_ArgumentList = 95,    /* Zeroorone_ArgumentList  */
  YYSYMBOL_ZerooroneClassBody = 96,        /* ZerooroneClassBody  */
  YYSYMBOL_ClassOrInterfaceTypeToInstantiate = 97, /* ClassOrInterfaceTypeToInstantiate  */
  YYSYMBOL_FieldAccess = 98,               /* FieldAccess  */
  YYSYMBOL_ArrayAccess = 99,               /* ArrayAccess  */
  YYSYMBOL_MethodInvocation = 100,         /* MethodInvocation  */
  YYSYMBOL_ArgumentList = 101,             /* ArgumentList  */
  YYSYMBOL_Zeroormore_CommaExpression = 102, /* Zeroormore_CommaExpression  */
  YYSYMBOL_MethodReference = 103,          /* MethodReference  */
  YYSYMBOL_ArrayCreationExpression = 104,  /* ArrayCreationExpression  */
  YYSYMBOL_DimExprs = 105,                 /* DimExprs  */
  YYSYMBOL_DimExpr = 106,                  /* DimExpr  */
  YYSYMBOL_Expression = 107,               /* Expression  */
  YYSYMBOL_AssignmentExpression = 108,     /* AssignmentExpression  */
  YYSYMBOL_ConditionalExpression = 109,    /* ConditionalExpression  */
  YYSYMBOL_ConditionalOrExpression = 110,  /* ConditionalOrExpression  */
  YYSYMBOL_ConditionalAndExpression = 111, /* ConditionalAndExpression  */
  YYSYMBOL_AndExpression = 112,            /* AndExpression  */
  YYSYMBOL_ExclusiveOrExpression = 113,    /* ExclusiveOrExpression  */
  YYSYMBOL_InclusiveOrExpression = 114,    /* InclusiveOrExpression  */
  YYSYMBOL_EqualityExpression = 115,       /* EqualityExpression  */
  YYSYMBOL_RelationalExpression = 116,     /* RelationalExpression  */
  YYSYMBOL_ShiftExpression = 117,          /* ShiftExpression  */
  YYSYMBOL_AdditiveExpression = 118,       /* AdditiveExpression  */
  YYSYMBOL_MultiplicativeExpression = 119, /* MultiplicativeExpression  */
  YYSYMBOL_UnaryExpression = 120,          /* UnaryExpression  */
  YYSYMBOL_CastExpression = 121,           /* CastExpression  */
  YYSYMBOL_PostfixExpression = 122,        /* PostfixExpression  */
  YYSYMBOL_Block = 123,                    /* Block  */
  YYSYMBOL_BlockStatements = 124,          /* BlockStatements  */
  YYSYMBOL_BlockStatement = 125,           /* BlockStatement  */
  YYSYMBOL_LocalVariableDeclaration = 126, /* LocalVariableDeclaration  */
  YYSYMBOL_LocalVariableType = 127,        /* LocalVariableType  */
  YYSYMBOL_Statement = 128,                /* Statement  */
  YYSYMBOL_StatementNoShortIf = 129,       /* StatementNoShortIf  */
  YYSYMBOL_StatementWithoutTrailingSubstatement = 130, /* StatementWithoutTrailingSubstatement  */
  YYSYMBOL_StatementExpression = 131,      /* StatementExpression  */
  YYSYMBOL_LeftHandSide = 132,             /* LeftHandSide  */
  YYSYMBOL_AssertStatement = 133,          /* AssertStatement  */
  YYSYMBOL_BreakContinueStatement = 134,   /* BreakContinueStatement  */
  YYSYMBOL_ForStatement = 135,             /* ForStatement  */
  YYSYMBOL_ForStatementNoShortIf = 136,    /* ForStatementNoShortIf  */
  YYSYMBOL_ForInit = 137,                  /* ForInit  */
  YYSYMBOL_StatementExpressionList = 138,  /* StatementExpressionList  */
  YYSYMBOL_StatementExpressionMore = 139,  /* StatementExpressionMore  */
  YYSYMBOL_ArrayInitializer = 140,         /* ArrayInitializer  */
  YYSYMBOL_zerooroneVariableInitializerList = 141, /* zerooroneVariableInitializerList  */
  YYSYMBOL_VariableInitializerList = 142,  /* VariableInitializerList  */
  YYSYMBOL_cVariableInitializer = 143,     /* cVariableInitializer  */
  YYSYMBOL_VariableInitializer = 144,      /* VariableInitializer  */
  YYSYMBOL_ClassDeclaration = 145,         /* ClassDeclaration  */
  YYSYMBOL_NormalClassDeclaration = 146,   /* NormalClassDeclaration  */
  YYSYMBOL_ClassModifiers = 147,           /* ClassModifiers  */
  YYSYMBOL_ClassExtends = 148,             /* ClassExtends  */
  YYSYMBOL_ClassPermits = 149,             /* ClassPermits  */
  YYSYMBOL_cTypeName = 150,                /* cTypeName  */
  YYSYMBOL_ClassBody = 151,                /* ClassBody  */
  YYSYMBOL_ClassBodyDeclarations = 152,    /* ClassBodyDeclarations  */
  YYSYMBOL_ClassBodyDeclaration = 153,     /* ClassBodyDeclaration  */
  YYSYMBOL_ClassMemberDeclaration = 154,   /* ClassMemberDeclaration  */
  YYSYMBOL_FieldDeclaration = 155,         /* FieldDeclaration  */
  YYSYMBOL_FieldModifiers = 156,           /* FieldModifiers  */
  YYSYMBOL_FieldModifier = 157,            /* FieldModifier  */
  YYSYMBOL_VariableDeclaratorList = 158,   /* VariableDeclaratorList  */
  YYSYMBOL_cVariableDeclarator = 159,      /* cVariableDeclarator  */
  YYSYMBOL_VariableDeclarator = 160,       /* VariableDeclarator  */
  YYSYMBOL_VariableDeclaratorId = 161,     /* VariableDeclaratorId  */
  YYSYMBOL_MethodDeclaration = 162,        /* MethodDeclaration  */
  YYSYMBOL_Methodmodifiers = 163,          /* Methodmodifiers  */
  YYSYMBOL_Methodmodifier = 164,           /* Methodmodifier  */
  YYSYMBOL_Methodheader = 165,             /* Methodheader  */
  YYSYMBOL_Result = 166,                   /* Result  */
  YYSYMBOL_Methodeclarator = 167,          /* Methodeclarator  */
  YYSYMBOL_recieveparameters = 168,        /* recieveparameters  */
  YYSYMBOL_formalparameters = 169,         /* formalparameters  */
  YYSYMBOL_recieveparameter = 170,         /* recieveparameter  */
  YYSYMBOL_formalparameterlist = 171,      /* formalparameterlist  */
  YYSYMBOL_cformalparameter = 172,         /* cformalparameter  */
  YYSYMBOL_formalparameter = 173,          /* formalparameter  */
  YYSYMBOL_VariableModifier = 174,         /* VariableModifier  */
  YYSYMBOL_VariableArityParameter = 175,   /* VariableArityParameter  */
  YYSYMBOL_MethodBody = 176,               /* MethodBody  */
  YYSYMBOL_InstanceInitializer = 177,      /* InstanceInitializer  */
  YYSYMBOL_StaticInitializer = 178,        /* StaticInitializer  */
  YYSYMBOL_ConstructorDeclaration = 179,   /* ConstructorDeclaration  */
  YYSYMBOL_zeroormore_ConstructorModifier = 180, /* zeroormore_ConstructorModifier  */
  YYSYMBOL_ConstructorModifier = 181,      /* ConstructorModifier  */
  YYSYMBOL_ConstructorDeclarator = 182,    /* ConstructorDeclarator  */
  YYSYMBOL_zeroorone_TypeParameters = 183, /* zeroorone_TypeParameters  */
  YYSYMBOL_TypeParameters = 184,           /* TypeParameters  */
  YYSYMBOL_TypeParamerList = 185,          /* TypeParamerList  */
  YYSYMBOL_TypeParameterc = 186,           /* TypeParameterc  */
  YYSYMBOL_ConstructorBody = 187,          /* ConstructorBody  */
  YYSYMBOL_zerooroneExplicitConstructorInvocation = 188, /* zerooroneExplicitConstructorInvocation  */
  YYSYMBOL_ExplicitConstructorInvocation = 189, /* ExplicitConstructorInvocation  */
  YYSYMBOL_EnumDeclaration = 190,          /* EnumDeclaration  */
  YYSYMBOL_EnumBody = 191,                 /* EnumBody  */
  YYSYMBOL_zerooronecomma = 192,           /* zerooronecomma  */
  YYSYMBOL_zerooroneEnumConstantList = 193, /* zerooroneEnumConstantList  */
  YYSYMBOL_zerooroneEnumBodyDeclarations = 194, /* zerooroneEnumBodyDeclarations  */
  YYSYMBOL_EnumConstantList = 195,         /* EnumConstantList  */
  YYSYMBOL_cEnumConstant = 196,            /* cEnumConstant  */
  YYSYMBOL_EnumConstant = 197,             /* EnumConstant  */
  YYSYMBOL_bracketZeroorone_ArgumentList = 198, /* bracketZeroorone_ArgumentList  */
  YYSYMBOL_EnumBodyDeclarations = 199,     /* EnumBodyDeclarations  */
  YYSYMBOL_zeroormoreClassBodyDeclaration = 200, /* zeroormoreClassBodyDeclaration  */
  YYSYMBOL_RecordDeclaration = 201,        /* RecordDeclaration  */
  YYSYMBOL_RecordHeader = 202,             /* RecordHeader  */
  YYSYMBOL_zerooroneRecordComponentList = 203, /* zerooroneRecordComponentList  */
  YYSYMBOL_RecordComponentList = 204,      /* RecordComponentList  */
  YYSYMBOL_cRecordComponent = 205,         /* cRecordComponent  */
  YYSYMBOL_RecordComponent = 206,          /* RecordComponent  */
  YYSYMBOL_VariableArityRecordComponent = 207, /* VariableArityRecordComponent  */
  YYSYMBOL_RecordBody = 208,               /* RecordBody  */
  YYSYMBOL_zeroormoreRecordBodyDeclaration = 209, /* zeroormoreRecordBodyDeclaration  */
  YYSYMBOL_RecordBodyDeclaration = 210,    /* RecordBodyDeclaration  */
  YYSYMBOL_CompactConstructorDeclaration = 211 /* CompactConstructorDeclaration  */
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
#define YYFINAL  7
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1913

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  69
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  143
/* YYNRULES -- Number of rules.  */
#define YYNRULES  320
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  606

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   306


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
       2,     2,     2,     2,     2,     2,     2,     2,    63,     2,
      59,    60,     2,     2,    57,     2,    52,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    62,    68,
      55,    61,    56,    58,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    53,     2,    54,    64,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    66,    65,    67,     2,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50,    51
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    22,    22,    27,    28,    32,    33,    37,    38,    44,
      45,    46,    50,    51,    81,    81,    85,    86,    99,    99,
     103,   104,   105,   108,   109,   112,   113,   117,   120,   123,
     126,   127,   130,   131,   134,   135,   138,   139,   145,   146,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     165,   166,   167,   171,   172,   176,   177,   178,   183,   187,
     187,   191,   191,   196,   200,   201,   202,   207,   208,   213,
     214,   215,   216,   217,   221,   225,   226,   230,   231,   232,
     233,   234,   235,   236,   241,   242,   243,   244,   245,   246,
     250,   250,   254,   258,   262,   263,   264,   268,   269,   273,
     274,   278,   279,   283,   284,   288,   289,   293,   294,   298,
     299,   303,   304,   308,   309,   313,   314,   318,   319,   323,
     324,   325,   326,   327,   331,   335,   336,   337,   338,   346,
     350,   350,   354,   355,   356,   360,   364,   365,   369,   370,
     371,   372,   373,   374,   378,   379,   380,   381,   382,   386,
     387,   388,   389,   390,   391,   392,   393,   394,   398,   401,
     402,   406,   407,   408,   412,   413,   417,   418,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   434,   435,   436,
     437,   438,   439,   440,   441,   442,   446,   447,   451,   455,
     455,   462,   465,   466,   469,   473,   473,   477,   478,   484,
     485,   486,   489,   490,   491,   492,   495,   495,   498,   501,
     505,   505,   509,   512,   513,   516,   517,   518,   519,   522,
     523,   524,   527,   530,   531,   534,   534,   537,   540,   541,
     544,   545,   549,   550,   555,   559,   560,   564,   564,   564,
     564,   564,   564,   564,   564,   564,   568,   569,   578,   579,
     583,   584,   588,   589,   592,   593,   597,   598,   602,   605,
     605,   608,   612,   612,   615,   631,   632,   635,   638,   641,
     644,   645,   648,   648,   651,   654,   655,   658,   661,   664,
     665,   669,   673,   674,   677,   678,   679,   680,   683,   686,
     689,   690,   693,   694,   697,   698,   701,   704,   705,   708,
     711,   712,   715,   718,   719,   722,   725,   728,   729,   732,
     735,   736,   739,   740,   743,   746,   749,   750,   753,   754,
     757
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
  "IDENTIFIER", "LITERAL", "ESCSEQ", "OPERATOR", "SEP", "INTTYPE",
  "FPTYPE", "BOOLTYPE", "ASSIGNOP", "CONDOR", "CONDAND", "EQALITYOP",
  "RELATIONOP", "SHIFTOP", "ADDOP", "MULTOP", "ADDOP2", "UNARYOP",
  "KEY_VAR", "KEY_assert", "KEY_yiethr", "KEY_brecon", "KEY_return",
  "KEY_if", "KEY_else", "KEY_for", "KEY_permits", "KEY_record",
  "KEY_while", "KEY_sync", "KEY_final", "KEY_extends", "KEY_super",
  "KEY_this", "KEY_class", "KEY_void", "KEY_public", "KEY_new", "COLON2",
  "KEY_throws", "KEY_static", "KEY_enum", "DOT3", "KEY_abstract",
  "KEY_native", "KEY_strictf", "KEY_protected", "KEY_private", "'.'",
  "'['", "']'", "'<'", "'>'", "','", "'?'", "'('", "')'", "'='", "':'",
  "'&'", "'^'", "'|'", "'{'", "'}'", "';'", "$accept", "prog", "Type",
  "PrimitiveType", "NumericType", "ReferenceType", "IDENdotIDEN",
  "ClassModifier", "ClassType", "Zeroorone_TypeArguments", "ArrayType",
  "Dims", "TypeParameter", "TypeBound", "TypeArguments",
  "TypeArgumentList", "cTypeArgument", "TypeArgument", "Wildcard",
  "WildcardBounds", "Primary", "PrimaryNoNewArray", "ClassLiteral",
  "Zero_or_moreSquarebracket", "ClassInstanceCreationExpression",
  "UnqualifiedClassInstanceCreationExpression", "Zeroorone_ArgumentList",
  "ZerooroneClassBody", "ClassOrInterfaceTypeToInstantiate", "FieldAccess",
  "ArrayAccess", "MethodInvocation", "ArgumentList",
  "Zeroormore_CommaExpression", "MethodReference",
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
  "ClassBodyDeclarations", "ClassBodyDeclaration",
  "ClassMemberDeclaration", "FieldDeclaration", "FieldModifiers",
  "FieldModifier", "VariableDeclaratorList", "cVariableDeclarator",
  "VariableDeclarator", "VariableDeclaratorId", "MethodDeclaration",
  "Methodmodifiers", "Methodmodifier", "Methodheader", "Result",
  "Methodeclarator", "recieveparameters", "formalparameters",
  "recieveparameter", "formalparameterlist", "cformalparameter",
  "formalparameter", "VariableModifier", "VariableArityParameter",
  "MethodBody", "InstanceInitializer", "StaticInitializer",
  "ConstructorDeclaration", "zeroormore_ConstructorModifier",
  "ConstructorModifier", "ConstructorDeclarator",
  "zeroorone_TypeParameters", "TypeParameters", "TypeParamerList",
  "TypeParameterc", "ConstructorBody",
  "zerooroneExplicitConstructorInvocation",
  "ExplicitConstructorInvocation", "EnumDeclaration", "EnumBody",
  "zerooronecomma", "zerooroneEnumConstantList",
  "zerooroneEnumBodyDeclarations", "EnumConstantList", "cEnumConstant",
  "EnumConstant", "bracketZeroorone_ArgumentList", "EnumBodyDeclarations",
  "zeroormoreClassBodyDeclaration", "RecordDeclaration", "RecordHeader",
  "zerooroneRecordComponentList", "RecordComponentList",
  "cRecordComponent", "RecordComponent", "VariableArityRecordComponent",
  "RecordBody", "zeroormoreRecordBodyDeclaration", "RecordBodyDeclaration",
  "CompactConstructorDeclaration", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-390)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-303)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -390,    32,  -390,  -390,   467,  -390,  -390,  -390,    33,    74,
    -390,    96,  -390,  -390,    61,   123,    72,   138,    90,  -390,
     151,   151,  -390,    10,   119,  -390,   166,  -390,   152,  -390,
     144,   317,   158,  -390,   150,   140,   165,   349,   119,  -390,
    -390,   172,   184,  -390,  -390,   151,  -390,   188,  -390,   104,
    -390,  -390,  -390,    59,   201,  -390,  -390,   110,  -390,   204,
    -390,  -390,  -390,  -390,  -390,   262,   213,    76,  -390,  -390,
     271,   215,  -390,  -390,  -390,  -390,  -390,  -390,  -390,   269,
    -390,  1175,  -390,  -390,  -390,   263,  -390,  1816,   119,  -390,
     216,   229,   165,   138,   234,   240,  -390,   298,   240,   240,
    -390,   249,  1375,  -390,   151,   200,   201,  -390,   252,  -390,
    -390,   270,  -390,   958,  -390,  -390,   330,  -390,    16,  -390,
    -390,  -390,  -390,  -390,  -390,  -390,  -390,  -390,  -390,  -390,
     301,  -390,    46,   338,  -390,  -390,  -390,   265,   340,  -390,
    1816,  1816,  1816,    67,  -390,   293,   212,  1816,   201,   312,
     327,   230,   314,    95,   302,  -390,  -390,  -390,   297,    31,
      37,  -390,  -390,  -390,  -390,  -390,  -390,  -390,     8,   348,
     300,   306,   299,   356,   358,   355,   366,   373,  -390,  -390,
    -390,    45,  -390,  -390,  -390,   309,  -390,   166,  -390,  -390,
     331,  -390,   317,  -390,  -390,    48,  -390,  -390,   150,   317,
     317,  -390,  -390,   339,  -390,   186,  1816,  1816,    15,  1152,
     350,   360,   361,   362,  -390,  -390,  -390,  -390,  -390,  -390,
    -390,   329,  -390,  -390,   345,  -390,  -390,  -390,  -390,   434,
     201,   346,  -390,   364,   338,  -390,  -390,  -390,   363,  -390,
    1854,  -390,   372,   112,  -390,  -390,  -390,  -390,  -390,   270,
      20,   369,   370,   197,   151,    65,   374,   243,   270,  -390,
     270,   189,  1816,  1816,   284,   270,   395,  -390,   270,    19,
    1816,   172,   385,  1816,  1816,  1816,  1816,  1816,  1816,  1816,
    1816,  1816,  1816,  1816,  1816,  1816,  1395,  -390,  -390,  -390,
    -390,   265,  -390,  -390,    76,  1061,   -14,   379,   383,  -390,
    -390,   386,  1816,  1192,  1816,  1816,  -390,  -390,  -390,  -390,
    -390,   330,   240,  -390,   401,   635,  -390,   317,  1816,   407,
     313,    88,  -390,  -390,   317,   459,  -390,   460,  -390,  1792,
     -31,   370,  -390,   -31,   370,   140,   406,  1816,  -390,   432,
     418,   469,   471,   136,  -390,   270,   475,  -390,   433,   428,
     451,   449,  -390,   488,  -390,   489,  -390,   442,  -390,  1816,
     348,   435,   299,   356,   300,   306,   358,   355,   366,   373,
    -390,  -390,  -390,  -390,  -390,  -390,  -390,  1816,  -390,  -390,
    -390,  -390,   439,  1232,   440,  -390,   438,  -390,   448,   450,
    -390,   330,   635,  -390,  -390,  -390,    98,   453,   452,   210,
     457,   462,    26,  1010,   453,  -390,   468,   465,  -390,   240,
    -390,  -390,   240,  -390,  1816,  -390,  -390,  -390,  -390,  -390,
     270,    42,   472,  -390,  -390,  -390,  -390,  -390,   474,  -390,
    -390,  1816,   443,  1112,  1448,   466,  1816,   473,  1272,  1061,
     215,  -390,   184,  -390,  -390,   476,  -390,   477,  -390,  -390,
     357,  -390,    85,   499,  1816,  1816,   500,  -390,   478,  1816,
    -390,   479,   536,  -390,   537,  1816,  1816,  -390,  -390,   190,
     483,   484,   485,  -390,   521,   523,  -390,  1061,   496,  1491,
     498,  1816,  1534,   493,  -390,  -390,   495,   506,   527,   201,
     508,   330,   507,   512,   513,   509,  -390,   514,   119,  -390,
     516,   517,   519,  1112,  1816,  1312,  1816,  1061,  -390,  1061,
    1061,   520,  1061,  -390,  1061,   529,  1577,  -390,   635,  -390,
     240,  -390,  -390,  1816,   515,   526,  1816,  -390,  -390,  1816,
    -390,  -390,  -390,   531,  1352,   505,   530,   535,  -390,  -390,
    -390,  1061,  -390,  -390,  1061,  1061,   541,  -390,  -390,   357,
    -390,   542,  -390,  -390,   543,   545,  1112,  1620,   538,  1816,
    1392,  1112,  -390,  -390,  -390,  1061,   561,   547,   549,  -390,
     548,  1112,   551,  1663,   569,  1706,   553,  -390,  -390,   577,
    -390,  -390,  1112,  -390,  1112,  1112,   572,  1112,  1112,   574,
    1749,  -390,  -390,  -390,  -390,  1112,  -390,  -390,  1112,  1112,
     575,  -390,  -390,  -390,  1112,  -390
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
     207,     0,     2,   199,     0,   200,   201,     1,     0,     0,
      14,     0,    15,   206,   276,     0,     0,     0,     0,   275,
       0,     0,   214,     0,     0,   202,   293,   288,    26,   280,
       0,   308,     0,    13,   211,    19,   208,   236,     0,   203,
     204,   301,   291,   292,   298,     0,    25,   278,   277,    13,
       7,     8,     6,     0,     3,     5,     4,     9,    11,     0,
     307,   311,   313,   317,   305,     0,   209,     0,    16,    18,
       0,     0,   131,   212,   221,   267,   213,   215,   219,     0,
     220,     0,   216,   217,   218,   276,   205,    60,    62,   290,
     295,   296,    27,     0,     0,    22,   312,     0,    20,    21,
     306,   309,   236,    12,     0,    35,     0,    32,     0,    31,
      33,    19,   268,   207,   225,   226,     0,   223,    26,   243,
     242,   249,   237,   241,   240,   244,   245,   238,   239,   248,
       0,   235,     0,     0,   272,   273,   270,     0,     0,    40,
       0,     0,     0,     0,    42,     0,     0,     0,    54,     0,
     126,     0,     0,   125,    38,    41,    45,    55,     0,    46,
      47,    48,    59,    49,    39,    76,    93,    94,    97,    99,
     105,   107,   101,   103,   109,   111,   113,   115,   117,   123,
     121,     0,   299,    61,   304,     0,   294,     0,   279,    23,
       0,   314,     0,   315,   318,     0,   316,   319,   210,     0,
       0,    34,    28,    29,    17,    13,     0,     0,     0,     0,
       0,     0,     0,     0,   129,   150,    45,    48,   158,   149,
     130,     0,   134,   138,     0,   152,   153,   143,   132,     0,
     233,     0,   229,   231,     0,   266,   265,   234,     0,   246,
     283,   269,     0,   126,    46,    47,   120,   119,   122,    19,
       0,     0,     0,     0,     0,    54,     0,     0,    19,   128,
      19,     0,     0,    60,     0,    19,     0,   127,    19,     0,
       0,   301,    74,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   236,   289,   297,    24,
     310,     0,    36,    37,     0,     0,     0,     0,     0,   167,
     154,     0,     0,   263,     0,     0,   133,   151,   137,   262,
     136,     0,   232,   222,   227,     0,   247,   253,     0,     0,
       0,     0,   131,   282,   253,     0,    65,     0,    52,     0,
       0,    85,    91,     0,    87,    19,     0,     0,    44,     0,
       0,     0,     0,     0,    43,    19,     0,    56,     0,     0,
       0,     0,    83,     0,    64,     0,    57,     0,   300,     0,
     100,     0,   102,   104,   106,   108,   110,   112,   114,   116,
     118,    95,    96,   303,   320,    30,   139,     0,   164,   156,
     166,   155,     0,     0,   187,   190,     0,   186,     0,     0,
     135,     0,   193,   197,   198,   230,     0,   263,     0,     0,
       0,     0,   276,   207,   263,    80,     0,     0,    88,    84,
      90,    89,    86,    63,    60,   124,    51,    53,    79,    77,
      19,     0,     0,    67,    69,    50,    82,    78,     0,    68,
      75,     0,     0,     0,     0,     0,     0,   188,     0,     0,
       0,   228,   291,   192,   196,     0,   257,     0,   254,   260,
       0,   252,     0,     0,    60,    60,     0,   281,     0,    60,
      92,     0,     0,    66,     0,    60,    60,    98,   165,    13,
       0,     0,     0,   140,     0,   138,   148,     0,     0,     0,
       0,     0,     0,     0,   142,   157,     0,   194,     0,   251,
     258,     0,     0,     0,     0,     0,   274,     0,    62,    81,
       0,     0,     0,     0,     0,   263,     0,     0,   168,     0,
       0,     0,     0,   189,     0,     0,     0,   191,     0,   256,
     250,   263,   263,    60,     0,     0,    60,    72,    58,    60,
      70,    71,   145,     0,     0,   187,     0,     0,   141,   171,
     170,     0,   176,   169,     0,     0,     0,   195,   259,     0,
     261,     0,   285,   284,     0,     0,     0,     0,     0,     0,
       0,     0,   172,   174,   173,     0,     0,     0,     0,    73,
       0,     0,     0,     0,     0,     0,     0,   147,   175,     0,
     286,   287,     0,   177,     0,     0,     0,     0,     0,     0,
       0,   264,   146,   180,   179,     0,   185,   178,     0,     0,
       0,   181,   183,   182,     0,   184
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -390,  -390,   -48,   -23,  -390,   -26,   -20,  -390,   -17,    83,
      -2,   -15,   -55,  -390,  -255,  -390,  -390,   315,  -390,  -390,
     396,  -390,  -390,  -138,  -104,  -254,   131,   145,  -390,   607,
     624,    43,  -390,  -390,  -390,  -390,   397,  -127,   413,   308,
     217,  -390,   376,   375,   380,   384,   387,   382,   371,   381,
     388,  -124,  -390,  -390,    -1,   342,  -390,  -300,  -390,   274,
     354,   121,  -192,  -390,  -390,  -390,  -390,  -390,   160,  -389,
    -390,  -122,  -390,  -390,  -390,  -379,   666,  -390,  -390,  -390,
     645,  -390,   195,  -390,   -90,  -390,  -390,  -390,  -390,   367,
    -390,   278,   182,  -390,  -390,  -390,  -390,   550,   445,   365,
     277,  -390,  -390,  -390,   163,  -370,  -390,  -390,  -390,  -390,
    -390,   584,  -390,  -390,   -12,  -390,  -390,  -390,   399,  -390,
    -390,  -390,  -390,   246,  -390,  -390,  -390,  -390,   524,   422,
    -390,  -390,  -390,  -390,  -390,  -390,  -390,   503,  -390,  -390,
    -390,  -390,  -390
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,    53,   148,    55,   149,   150,    13,   151,    68,
     152,    95,    29,    46,    69,   108,   203,   109,   110,   201,
     153,   154,   155,   264,   156,   157,   158,   182,   336,   159,
     160,   161,   162,   272,   163,   164,   331,   332,   165,   218,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   219,   113,   220,   221,   311,   222,
     474,   223,   224,   181,   225,   226,   227,   476,   386,   387,
     437,   394,   442,   443,   487,   395,   228,     3,     4,    23,
      24,    66,   183,    37,    76,    77,    78,    79,   117,   231,
     314,   232,   233,    80,    81,   131,   132,   133,   239,   397,
     447,   398,   448,   490,   449,   229,   550,   237,    82,    83,
      84,    85,   136,   137,   138,    19,    30,    47,   241,   322,
     323,     5,    27,    90,    42,   185,    43,    91,    44,    88,
     186,   286,     6,    32,    59,    60,   101,    61,    62,    64,
     102,   196,   197
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      34,    35,    18,   384,    36,    56,   346,   347,    54,   216,
     257,    35,   194,   444,    57,   356,   246,   247,   248,   298,
     -10,   273,   190,   354,   326,    35,   130,   450,    92,    58,
     354,   116,     7,   129,   450,   392,    75,    14,   188,    98,
      20,   107,    99,  -162,   106,   478,   463,    35,   377,  -163,
      57,    45,   291,    56,   378,    56,    54,   284,    54,    35,
     345,    35,    57,    96,    57,    58,   274,   345,   -13,    94,
     112,   -13,   -10,   -10,    67,    67,    22,    58,    15,    58,
      49,   452,   129,   299,   198,    50,    51,    52,   134,   118,
     511,    98,  -162,   515,    50,    51,    52,    67,  -163,   135,
      16,    75,   445,    17,    56,    97,   285,    54,   -10,   249,
      35,   385,    72,    57,   235,   267,    17,   257,    94,   250,
     243,   243,   243,   252,   255,   337,    35,   546,    58,   253,
     268,   236,   259,    98,   105,   446,    99,   268,    26,   547,
     402,   -10,    28,   105,   346,   347,   -10,   269,   356,    31,
     -10,   450,   549,    20,   260,    33,   217,    94,    21,   370,
     -10,   -10,    70,    94,   261,   262,    56,    67,   572,    54,
      41,   263,    35,   292,   293,    57,   106,   106,   420,    35,
      35,   310,    57,    57,   586,    22,   589,    45,   421,    22,
      58,   216,    65,   103,   204,    67,   373,    58,    58,   216,
      48,   600,    65,    56,   410,   535,    54,   410,   408,    35,
      25,   411,    57,   415,   103,   312,    33,    70,    39,    40,
     319,    50,    51,    52,    63,   343,   344,    58,   -10,   254,
     345,    87,   -10,    86,   335,   199,   200,   330,   333,    94,
      98,    89,   385,    94,    67,    93,   343,   344,   295,    70,
     329,   345,   503,   243,    94,   243,   243,   243,   243,   243,
     243,   243,   243,   243,   100,   452,   103,    67,   107,   396,
     104,   106,   265,    49,    35,   111,   396,    57,    50,    51,
      52,    72,    70,    94,   184,    75,   187,   385,   189,   513,
     385,    56,    58,   190,    54,   339,   340,    35,    56,   216,
      57,    54,   191,   134,    35,    49,   192,    57,   202,   114,
      50,    51,    52,   385,   135,    58,   409,   243,    17,   412,
     115,    49,    58,   320,   385,    67,    50,    51,    52,   216,
     216,   240,   325,   327,   230,   216,   350,   340,   217,  -161,
     121,   341,   238,   342,   242,   251,   217,   259,   351,   400,
     401,   353,   355,  -224,   258,   270,   266,   271,  -224,  -224,
    -224,    49,   275,   276,   278,   385,    50,    51,    52,   260,
     277,   279,   281,   216,   280,   216,   287,   216,   216,   261,
     262,   385,    67,   385,   282,   289,   263,   453,  -161,  -224,
     456,   309,   283,    71,   349,   166,   294,   306,   385,   216,
    -224,   216,   491,   216,  -271,   216,   216,   328,   216,   302,
     216,   243,   216,   307,   313,    72,    73,    74,   413,   303,
     304,   305,   317,   329,    56,   315,   107,    54,   254,   106,
      35,   324,    35,    57,   338,    57,   352,   216,    49,   485,
     216,   216,   359,    50,    51,    52,   217,   379,    58,   260,
      58,   380,   216,   216,   381,   166,   308,   216,   391,   399,
     262,   216,    67,   405,   406,   414,   263,   216,   309,   216,
     416,   216,   417,   418,   520,   419,   217,   217,   216,   422,
     216,   216,   217,   216,   216,   355,   216,   423,   424,   425,
     426,   216,   427,   428,   216,   216,   429,   431,     8,   433,
     216,   566,   436,   462,   464,     9,   438,    10,   439,   451,
     440,   468,    11,  -255,   166,   166,   454,   166,    12,   460,
     217,   455,   217,    56,   217,   217,    54,   459,   488,    35,
     481,   465,    57,   466,   479,   492,   495,   489,   496,   498,
     499,   500,   504,   505,   506,   461,   217,    58,   217,   507,
     217,  -144,   217,   217,   475,   217,   509,   217,   512,   217,
     256,   516,   517,   518,   519,   521,   523,   559,   526,   376,
     166,   166,   524,   525,   527,   529,   582,   530,   166,   531,
     541,   591,   166,   552,   217,   493,   494,   217,   217,   544,
     497,   556,   166,   166,   553,   561,   501,   502,   560,   217,
     217,   565,   567,   568,   217,   569,   573,   579,   217,   375,
     166,   584,   166,   166,   217,   580,   217,   581,   217,   296,
     297,   590,   301,   166,   475,   217,   166,   217,   217,   587,
     217,   217,   595,   217,   598,   604,   321,   166,   217,    49,
     139,   217,   217,   528,    50,    51,    52,   217,   467,   360,
     334,   367,   364,   140,   551,   141,   142,   554,   365,   362,
     555,   366,   368,   363,   403,   536,     2,   166,    38,   441,
     369,   143,   144,   522,   145,   348,   146,   475,   390,   316,
     234,   458,   475,   357,   548,   166,   195,   361,   486,   404,
     374,   166,   475,   358,   147,   290,     0,   371,   372,     0,
     166,   392,     0,   475,     0,   475,   475,   473,   475,   475,
       0,   288,     0,   484,     0,   382,   475,   388,   389,   475,
     475,     0,   166,     0,     0,   475,     0,     0,   393,     0,
       0,   256,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   407,     0,   166,     0,   166,   244,   244,   244,
       0,   508,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   166,   166,   245,   245,   245,   166,     0,     0,
       0,     0,   430,   166,   166,     0,     0,   376,     0,     0,
       0,   538,     0,   539,   540,     0,   542,     0,   543,     0,
     432,     0,     0,     0,     0,     0,   435,     0,     0,     0,
       0,     0,     0,     0,     0,   393,     0,     0,     0,     0,
       0,     0,   166,     0,   166,   562,     0,     0,   563,   564,
       0,     0,     0,     0,     0,     0,   166,     0,     0,     0,
     473,   166,     0,     0,   166,   484,     0,   166,     0,   578,
       0,     0,   166,     0,     0,   508,     0,   244,     0,   480,
       0,   483,     0,     0,     0,     0,   538,   532,   539,   540,
       0,   542,   543,     0,   245,     0,     0,   166,   166,   562,
       0,     0,   563,   564,     0,     0,     0,     0,   578,     0,
     244,     0,   244,   244,   244,   244,   244,   244,   244,   244,
     244,     0,     0,     0,     0,     0,     0,   245,     0,   245,
     245,   245,   245,   245,   245,   245,   245,   245,     0,     0,
     570,     0,     0,     0,     0,   577,     0,   533,     0,   537,
       0,     0,     0,     0,     0,   583,     0,     0,     0,     0,
       0,   393,     0,     0,     0,     0,   592,     0,   593,   594,
       0,   596,   597,     0,   244,     0,     0,   558,     0,   601,
       0,     0,   602,   603,     0,     0,     0,     0,   605,     0,
       0,   245,   205,   139,     0,     0,     0,    50,    51,    52,
       0,     0,   574,   576,     0,     0,   140,     0,   141,   142,
    -263,   206,   207,   208,   209,   210,     0,   211,     0,     0,
     212,   213,  -263,     0,   143,   144,     0,   145,     0,   146,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   205,   139,     0,   147,     0,    50,
      51,    52,     0,     0,    72,   214,   215,     0,   140,     0,
     141,   142,  -263,   206,   207,   208,   209,   210,   244,   211,
       0,     0,   212,   213,  -263,     0,   143,   144,     0,   145,
       0,   146,     0,     0,     0,   245,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   205,   139,     0,     0,   147,
      50,    51,    52,     0,     0,     0,    72,   457,   215,   140,
       0,   141,   142,     0,   206,   207,   208,   209,   210,     0,
     211,     0,     0,   212,   213,     0,     0,   143,   144,     0,
     145,     0,   146,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   469,   139,     0,     0,
     147,    50,    51,    52,     0,     0,     0,    72,     0,   215,
     140,     0,   141,   142,     0,   206,   207,   208,   209,   470,
       0,   471,     0,     0,   472,   213,     0,     0,   143,   144,
       0,   145,     0,   146,     0,     0,    49,   139,     0,     0,
       0,    50,    51,    52,     0,     0,     0,     0,     0,     0,
     140,   147,   141,   142,     0,     0,     0,     0,    72,   118,
     215,     0,     0,     0,    50,    51,    52,     0,   143,   144,
       0,   145,     0,   146,     0,     0,    49,   139,     0,     0,
       0,    50,    51,    52,     0,     0,     0,     0,   119,   120,
     140,   147,   141,   142,   121,   122,     0,     0,     0,   123,
     300,     0,   124,   125,   126,   127,   128,     0,   143,   144,
       0,   145,     0,   146,     0,     0,    49,   139,     0,     0,
       0,    50,    51,    52,     0,     0,     0,     0,     0,     0,
     140,   147,   141,   142,     0,     0,     0,     0,     0,     0,
     383,     0,     0,     0,     0,     0,     0,     0,   143,   144,
       0,   145,     0,   146,     0,     0,    49,   139,     0,     0,
       0,    50,    51,    52,     0,     0,     0,     0,     0,     0,
     140,   147,   141,   142,     0,     0,     0,     0,     0,     0,
     434,     0,     0,     0,     0,     0,     0,     0,   143,   144,
       0,   145,     0,   146,     0,     0,    49,   139,     0,     0,
       0,    50,    51,    52,     0,     0,     0,     0,     0,     0,
     140,   147,   141,   142,     0,     0,     0,     0,     0,     0,
     482,     0,     0,     0,     0,     0,     0,     0,   143,   144,
       0,   145,     0,   146,     0,     0,    49,   139,     0,     0,
       0,    50,    51,    52,     0,     0,     0,     0,     0,     0,
     140,   147,   141,   142,     0,     0,     0,     0,     0,  -224,
     534,     0,     0,     0,  -224,  -224,  -224,     0,   143,   144,
       0,   145,     0,   146,     0,     0,    49,   139,     0,  -224,
       0,    50,    51,    52,  -224,  -224,  -224,     0,     0,     0,
     140,   147,   141,   142,     0,  -224,     0,     0,     0,    71,
     557,     0,     0,     0,     0,     0,  -224,     0,   143,   144,
    -271,   145,     0,   146,     0,  -224,     0,     0,     0,    71,
       0,    72,   193,    74,     0,     0,  -224,     0,     0,     0,
    -271,   147,    49,   139,     0,     0,     0,    50,    51,    52,
     575,    72,  -302,    74,     0,     0,   140,     0,   141,   142,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   143,   144,     0,   145,     0,   146,
       0,     0,     0,     0,     0,    49,   139,     0,     0,     0,
      50,    51,    52,     0,     0,     0,     0,   147,   477,   140,
       0,   141,   142,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   143,   144,     0,
     145,     0,   146,     0,     0,     0,     0,     0,    49,   139,
       0,     0,     0,    50,    51,    52,     0,     0,     0,     0,
     147,   510,   140,     0,   141,   142,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     143,   144,     0,   145,     0,   146,     0,     0,     0,     0,
       0,    49,   139,     0,     0,     0,    50,    51,    52,     0,
       0,     0,     0,   147,   514,   140,     0,   141,   142,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   143,   144,     0,   145,     0,   146,     0,
       0,     0,     0,     0,    49,   139,     0,     0,     0,    50,
      51,    52,     0,     0,     0,     0,   147,   545,   140,     0,
     141,   142,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   143,   144,     0,   145,
       0,   146,     0,     0,     0,     0,     0,    49,   139,     0,
       0,     0,    50,    51,    52,     0,     0,     0,     0,   147,
     571,   140,     0,   141,   142,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   143,
     144,     0,   145,     0,   146,     0,     0,     0,     0,     0,
      49,   139,     0,     0,     0,    50,    51,    52,     0,     0,
       0,     0,   147,   585,   140,     0,   141,   142,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   143,   144,     0,   145,     0,   146,     0,     0,
       0,     0,     0,    49,   139,     0,     0,     0,    50,    51,
      52,     0,     0,     0,     0,   147,   588,   140,     0,   141,
     142,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   143,   144,     0,   145,     0,
     146,     0,     0,     0,     0,     0,    49,   139,     0,     0,
       0,    50,    51,    52,     0,     0,     0,     0,   147,   599,
     140,     0,   141,   142,     0,     0,     0,     0,     0,     0,
      49,   139,     0,     0,     0,    50,    51,    52,   143,   144,
       0,   145,     0,   146,   140,     0,   141,   142,     0,     0,
       0,     0,     0,     0,     0,     0,   189,     0,     0,     0,
       0,   147,   143,   144,     0,   145,     0,   146,    49,   139,
       0,     0,     0,    50,    51,    52,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   147,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     143,   144,     0,   145,     0,   146,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    67,
       0,     0,     0,   318
};

static const yytype_int16 yycheck[] =
{
      20,    21,    14,   303,    21,    31,   261,   261,    31,   113,
     148,    31,   102,   392,    31,   269,   140,   141,   142,     4,
       4,    13,    53,     4,     4,    45,    81,   397,    45,    31,
       4,    79,     0,    81,   404,    66,    37,     4,    93,    54,
      30,    67,    57,    12,    67,   434,     4,    67,    62,    12,
      67,    35,     4,    79,    68,    81,    79,    12,    81,    79,
      41,    81,    79,     4,    81,    67,    58,    41,    52,    53,
      71,    55,    56,    57,    55,    55,    66,    79,     4,    81,
       4,    55,   130,    68,   104,     9,    10,    11,    40,     4,
     479,   106,    61,   482,     9,    10,    11,    55,    61,    51,
       4,   102,     4,    55,   130,    46,    61,   130,     4,    42,
     130,   303,    66,   130,    68,    20,    55,   255,    53,    52,
     140,   141,   142,   146,   147,    60,   146,   516,   130,   146,
      42,   132,    20,   148,    58,    37,   151,    42,    66,   518,
      52,    37,     4,    58,   399,   399,    42,    52,   402,    59,
      46,   521,   522,    30,    42,     4,   113,    53,    35,   283,
      56,    57,    52,    53,    52,    53,   192,    55,   557,   192,
       4,    59,   192,   199,   200,   192,   199,   200,    42,   199,
     200,   229,   199,   200,   573,    66,   575,    35,    52,    66,
     192,   295,    52,     4,   111,    55,   286,   199,   200,   303,
      56,   590,    52,   229,   331,   505,   229,   334,   330,   229,
      15,   333,   229,   337,     4,   230,     4,    52,    23,    24,
     240,     9,    10,    11,    66,    36,    37,   229,    42,   146,
      41,    59,    42,    38,   254,    35,    36,   252,   253,    53,
     255,    57,   434,    53,    55,    57,    36,    37,    62,    52,
      53,    41,    62,   273,    53,   275,   276,   277,   278,   279,
     280,   281,   282,   283,    60,    55,     4,    55,   294,   317,
      57,   294,    42,     4,   294,     4,   324,   294,     9,    10,
      11,    66,    52,    53,    68,   286,    57,   479,    54,   481,
     482,   317,   294,    53,   317,    52,    53,   317,   324,   403,
     317,   324,     4,    40,   324,     4,    57,   324,    56,    40,
       9,    10,    11,   505,    51,   317,   331,   337,    55,   334,
      51,     4,   324,   240,   516,    55,     9,    10,    11,   433,
     434,    66,   249,   250,     4,   439,    52,    53,   295,    12,
      39,   258,     4,   260,     4,    52,   303,    20,   265,    36,
      37,   268,   269,     4,    42,    53,    42,    60,     9,    10,
      11,     4,    14,    63,    65,   557,     9,    10,    11,    42,
      64,    15,    17,   477,    16,   479,    67,   481,   482,    52,
      53,   573,    55,   575,    18,    54,    59,   399,    61,    40,
     402,    34,    19,    44,   263,    87,    57,    68,   590,   503,
      51,   505,   450,   507,    55,   509,   510,    38,   512,    59,
     514,   431,   516,    68,    68,    66,    67,    68,   335,    59,
      59,    59,    59,    53,   450,    61,   452,   450,   345,   452,
     450,    59,   452,   450,    60,   452,    41,   541,     4,   440,
     544,   545,    57,     9,    10,    11,   403,    68,   450,    42,
     452,    68,   556,   557,    68,   147,    22,   561,    57,    52,
      53,   565,    55,     4,     4,    59,    59,   571,    34,   573,
      38,   575,    54,     4,   489,     4,   433,   434,   582,     4,
     584,   585,   439,   587,   588,   402,   590,    54,    60,    38,
      41,   595,     4,     4,   598,   599,    54,    62,    31,    60,
     604,   549,    62,   420,   421,    38,    68,    40,    60,    57,
      60,    68,    45,    60,   206,   207,    59,   209,    51,    54,
     477,    59,   479,   549,   481,   482,   549,    59,    52,   549,
      57,    59,   549,    59,    68,    36,    36,    60,    60,    60,
       4,     4,    59,    59,    59,   414,   503,   549,   505,    28,
     507,    28,   509,   510,   433,   512,    60,   514,    60,   516,
     147,    68,    67,    57,    37,    57,    59,    62,    59,   295,
     262,   263,    60,    60,    60,    59,    28,    60,   270,    60,
      60,     4,   274,    68,   541,   454,   455,   544,   545,    60,
     459,    60,   284,   285,    68,    60,   465,   466,    68,   556,
     557,    60,    60,    60,   561,    60,    68,    46,   565,   294,
     302,    60,   304,   305,   571,    68,   573,    68,   575,   206,
     207,    68,   209,   315,   503,   582,   318,   584,   585,    60,
     587,   588,    60,   590,    60,    60,   240,   329,   595,     4,
       5,   598,   599,   498,     9,    10,    11,   604,   431,   273,
     253,   280,   277,    18,   523,    20,    21,   526,   278,   275,
     529,   279,   281,   276,   322,   505,     0,   359,    23,   391,
     282,    36,    37,   491,    39,   262,    41,   556,   311,   234,
     130,   404,   561,   270,   521,   377,   102,   274,   442,   324,
     291,   383,   571,   271,    59,   192,    -1,   284,   285,    -1,
     392,    66,    -1,   582,    -1,   584,   585,   433,   587,   588,
      -1,   187,    -1,   439,    -1,   302,   595,   304,   305,   598,
     599,    -1,   414,    -1,    -1,   604,    -1,    -1,   315,    -1,
      -1,   318,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   329,    -1,   436,    -1,   438,   140,   141,   142,
      -1,   477,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   454,   455,   140,   141,   142,   459,    -1,    -1,
      -1,    -1,   359,   465,   466,    -1,    -1,   503,    -1,    -1,
      -1,   507,    -1,   509,   510,    -1,   512,    -1,   514,    -1,
     377,    -1,    -1,    -1,    -1,    -1,   383,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   392,    -1,    -1,    -1,    -1,
      -1,    -1,   504,    -1,   506,   541,    -1,    -1,   544,   545,
      -1,    -1,    -1,    -1,    -1,    -1,   518,    -1,    -1,    -1,
     556,   523,    -1,    -1,   526,   561,    -1,   529,    -1,   565,
      -1,    -1,   534,    -1,    -1,   571,    -1,   240,    -1,   436,
      -1,   438,    -1,    -1,    -1,    -1,   582,   503,   584,   585,
      -1,   587,   588,    -1,   240,    -1,    -1,   559,   560,   595,
      -1,    -1,   598,   599,    -1,    -1,    -1,    -1,   604,    -1,
     273,    -1,   275,   276,   277,   278,   279,   280,   281,   282,
     283,    -1,    -1,    -1,    -1,    -1,    -1,   273,    -1,   275,
     276,   277,   278,   279,   280,   281,   282,   283,    -1,    -1,
     556,    -1,    -1,    -1,    -1,   561,    -1,   504,    -1,   506,
      -1,    -1,    -1,    -1,    -1,   571,    -1,    -1,    -1,    -1,
      -1,   518,    -1,    -1,    -1,    -1,   582,    -1,   584,   585,
      -1,   587,   588,    -1,   337,    -1,    -1,   534,    -1,   595,
      -1,    -1,   598,   599,    -1,    -1,    -1,    -1,   604,    -1,
      -1,   337,     4,     5,    -1,    -1,    -1,     9,    10,    11,
      -1,    -1,   559,   560,    -1,    -1,    18,    -1,    20,    21,
      22,    23,    24,    25,    26,    27,    -1,    29,    -1,    -1,
      32,    33,    34,    -1,    36,    37,    -1,    39,    -1,    41,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     4,     5,    -1,    59,    -1,     9,
      10,    11,    -1,    -1,    66,    67,    68,    -1,    18,    -1,
      20,    21,    22,    23,    24,    25,    26,    27,   431,    29,
      -1,    -1,    32,    33,    34,    -1,    36,    37,    -1,    39,
      -1,    41,    -1,    -1,    -1,   431,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     4,     5,    -1,    -1,    59,
       9,    10,    11,    -1,    -1,    -1,    66,    67,    68,    18,
      -1,    20,    21,    -1,    23,    24,    25,    26,    27,    -1,
      29,    -1,    -1,    32,    33,    -1,    -1,    36,    37,    -1,
      39,    -1,    41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     4,     5,    -1,    -1,
      59,     9,    10,    11,    -1,    -1,    -1,    66,    -1,    68,
      18,    -1,    20,    21,    -1,    23,    24,    25,    26,    27,
      -1,    29,    -1,    -1,    32,    33,    -1,    -1,    36,    37,
      -1,    39,    -1,    41,    -1,    -1,     4,     5,    -1,    -1,
      -1,     9,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      18,    59,    20,    21,    -1,    -1,    -1,    -1,    66,     4,
      68,    -1,    -1,    -1,     9,    10,    11,    -1,    36,    37,
      -1,    39,    -1,    41,    -1,    -1,     4,     5,    -1,    -1,
      -1,     9,    10,    11,    -1,    -1,    -1,    -1,    33,    34,
      18,    59,    20,    21,    39,    40,    -1,    -1,    -1,    44,
      68,    -1,    47,    48,    49,    50,    51,    -1,    36,    37,
      -1,    39,    -1,    41,    -1,    -1,     4,     5,    -1,    -1,
      -1,     9,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      18,    59,    20,    21,    -1,    -1,    -1,    -1,    -1,    -1,
      68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,    37,
      -1,    39,    -1,    41,    -1,    -1,     4,     5,    -1,    -1,
      -1,     9,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      18,    59,    20,    21,    -1,    -1,    -1,    -1,    -1,    -1,
      68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,    37,
      -1,    39,    -1,    41,    -1,    -1,     4,     5,    -1,    -1,
      -1,     9,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      18,    59,    20,    21,    -1,    -1,    -1,    -1,    -1,    -1,
      68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,    37,
      -1,    39,    -1,    41,    -1,    -1,     4,     5,    -1,    -1,
      -1,     9,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      18,    59,    20,    21,    -1,    -1,    -1,    -1,    -1,     4,
      68,    -1,    -1,    -1,     9,    10,    11,    -1,    36,    37,
      -1,    39,    -1,    41,    -1,    -1,     4,     5,    -1,     4,
      -1,     9,    10,    11,     9,    10,    11,    -1,    -1,    -1,
      18,    59,    20,    21,    -1,    40,    -1,    -1,    -1,    44,
      68,    -1,    -1,    -1,    -1,    -1,    51,    -1,    36,    37,
      55,    39,    -1,    41,    -1,    40,    -1,    -1,    -1,    44,
      -1,    66,    67,    68,    -1,    -1,    51,    -1,    -1,    -1,
      55,    59,     4,     5,    -1,    -1,    -1,     9,    10,    11,
      68,    66,    67,    68,    -1,    -1,    18,    -1,    20,    21,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    36,    37,    -1,    39,    -1,    41,
      -1,    -1,    -1,    -1,    -1,     4,     5,    -1,    -1,    -1,
       9,    10,    11,    -1,    -1,    -1,    -1,    59,    60,    18,
      -1,    20,    21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,    37,    -1,
      39,    -1,    41,    -1,    -1,    -1,    -1,    -1,     4,     5,
      -1,    -1,    -1,     9,    10,    11,    -1,    -1,    -1,    -1,
      59,    60,    18,    -1,    20,    21,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      36,    37,    -1,    39,    -1,    41,    -1,    -1,    -1,    -1,
      -1,     4,     5,    -1,    -1,    -1,     9,    10,    11,    -1,
      -1,    -1,    -1,    59,    60,    18,    -1,    20,    21,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    36,    37,    -1,    39,    -1,    41,    -1,
      -1,    -1,    -1,    -1,     4,     5,    -1,    -1,    -1,     9,
      10,    11,    -1,    -1,    -1,    -1,    59,    60,    18,    -1,
      20,    21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    36,    37,    -1,    39,
      -1,    41,    -1,    -1,    -1,    -1,    -1,     4,     5,    -1,
      -1,    -1,     9,    10,    11,    -1,    -1,    -1,    -1,    59,
      60,    18,    -1,    20,    21,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,
      37,    -1,    39,    -1,    41,    -1,    -1,    -1,    -1,    -1,
       4,     5,    -1,    -1,    -1,     9,    10,    11,    -1,    -1,
      -1,    -1,    59,    60,    18,    -1,    20,    21,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    36,    37,    -1,    39,    -1,    41,    -1,    -1,
      -1,    -1,    -1,     4,     5,    -1,    -1,    -1,     9,    10,
      11,    -1,    -1,    -1,    -1,    59,    60,    18,    -1,    20,
      21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    36,    37,    -1,    39,    -1,
      41,    -1,    -1,    -1,    -1,    -1,     4,     5,    -1,    -1,
      -1,     9,    10,    11,    -1,    -1,    -1,    -1,    59,    60,
      18,    -1,    20,    21,    -1,    -1,    -1,    -1,    -1,    -1,
       4,     5,    -1,    -1,    -1,     9,    10,    11,    36,    37,
      -1,    39,    -1,    41,    18,    -1,    20,    21,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    54,    -1,    -1,    -1,
      -1,    59,    36,    37,    -1,    39,    -1,    41,     4,     5,
      -1,    -1,    -1,     9,    10,    11,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    59,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      36,    37,    -1,    39,    -1,    41,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,
      -1,    -1,    -1,    59
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    70,   145,   146,   147,   190,   201,     0,    31,    38,
      40,    45,    51,    76,     4,     4,     4,    55,   183,   184,
      30,    35,    66,   148,   149,   151,    66,   191,     4,    81,
     185,    59,   202,     4,    75,    75,    77,   152,   149,   151,
     151,     4,   193,   195,   197,    35,    82,   186,    56,     4,
       9,    10,    11,    71,    72,    73,    74,    77,    79,   203,
     204,   206,   207,    66,   208,    52,   150,    55,    78,    83,
      52,    44,    66,    67,    68,   123,   153,   154,   155,   156,
     162,   163,   177,   178,   179,   180,   151,    59,   198,    57,
     192,   196,    77,    57,    53,    80,     4,    46,    80,    80,
      60,   205,   209,     4,    57,    58,    72,    74,    84,    86,
      87,     4,   123,   124,    40,    51,    71,   157,     4,    33,
      34,    39,    40,    44,    47,    48,    49,    50,    51,    71,
      81,   164,   165,   166,    40,    51,   181,   182,   183,     5,
      18,    20,    21,    36,    37,    39,    41,    59,    72,    74,
      75,    77,    79,    89,    90,    91,    93,    94,    95,    98,
      99,   100,   101,   103,   104,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   132,    96,   151,    68,   194,   199,    57,    81,    54,
      53,     4,    57,    67,   153,   180,   210,   211,    75,    35,
      36,    88,    56,    85,    78,     4,    23,    24,    25,    26,
      27,    29,    32,    33,    67,    68,    93,   100,   108,   123,
     125,   126,   128,   130,   131,   133,   134,   135,   145,   174,
       4,   158,   160,   161,   166,    68,   123,   176,     4,   167,
      66,   187,     4,    75,    98,    99,   120,   120,   120,    42,
      52,    52,    72,    77,    78,    72,   107,    92,    42,    20,
      42,    52,    53,    59,    92,    42,    42,    20,    42,    52,
      53,    60,   102,    13,    58,    14,    63,    64,    65,    15,
      16,    17,    18,    19,    12,    61,   200,    67,   197,    54,
     206,     4,    74,    74,    57,    62,   107,   107,     4,    68,
      68,   107,    59,    59,    59,    59,    68,    68,    22,    34,
      71,   127,    80,    68,   159,    61,   167,    59,    59,    75,
      78,    89,   188,   189,    59,    78,     4,    78,    38,    53,
      80,   105,   106,    80,   105,    75,    97,    60,    60,    52,
      53,    78,    78,    36,    37,    41,    83,    94,   107,    95,
      52,    78,    41,    78,     4,    78,    94,   107,   198,    57,
     111,   107,   114,   115,   112,   113,   116,   117,   118,   119,
     120,   107,   107,   153,   187,    86,   128,    62,    68,    68,
      68,    68,   107,    68,   126,   131,   137,   138,   107,   107,
     158,    57,    66,   107,   140,   144,    71,   168,   170,    52,
      36,    37,    52,   124,   168,     4,     4,   107,   140,    80,
     106,   140,    80,    78,    59,   120,    38,    54,     4,     4,
      42,    52,     4,    54,    60,    38,    41,     4,     4,    54,
     107,    62,   107,    60,    68,   107,    62,   139,    68,    60,
      60,   160,   141,   142,   144,     4,    37,   169,   171,   173,
     174,    57,    55,   183,    59,    59,   183,    67,   169,    59,
      54,    95,    78,     4,    78,    59,    59,   109,    68,     4,
      27,    29,    32,   128,   129,   130,   136,    60,   138,    68,
     107,    57,    68,   107,   128,   123,   192,   143,    52,    60,
     172,    71,    36,    95,    95,    36,    60,    95,    60,     4,
       4,    95,    95,    62,    59,    59,    59,    28,   128,    60,
      60,   138,    60,   131,    60,   138,    68,    67,    57,    37,
      80,    57,   161,    59,    60,    60,    59,    60,    96,    59,
      60,    60,   129,   107,    68,   126,   137,   107,   128,   128,
     128,    60,   128,   128,    60,    60,   138,   144,   173,   174,
     175,    95,    68,    68,    95,    95,    60,    68,   107,    62,
      68,    60,   128,   128,   128,    60,    71,    60,    60,    60,
     129,    60,   138,    68,   107,    68,   107,   129,   128,    46,
      68,    68,    28,   129,    60,    60,   138,    60,    60,   138,
      68,     4,   129,   129,   129,    60,   129,   129,    60,    60,
     138,   129,   129,   129,    60,   129
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    69,    70,    71,    71,    72,    72,    73,    73,    74,
      74,    74,    75,    75,    76,    76,    77,    77,    78,    78,
      79,    79,    79,    80,    80,    81,    81,    82,    83,    84,
      85,    85,    86,    86,    87,    87,    88,    88,    89,    89,
      90,    90,    90,    90,    90,    90,    90,    90,    90,    90,
      91,    91,    91,    92,    92,    93,    93,    93,    94,    95,
      95,    96,    96,    97,    98,    98,    98,    99,    99,   100,
     100,   100,   100,   100,   101,   102,   102,   103,   103,   103,
     103,   103,   103,   103,   104,   104,   104,   104,   104,   104,
     105,   105,   106,   107,   108,   108,   108,   109,   109,   110,
     110,   111,   111,   112,   112,   113,   113,   114,   114,   115,
     115,   116,   116,   117,   117,   118,   118,   119,   119,   120,
     120,   120,   120,   120,   121,   122,   122,   122,   122,   123,
     124,   124,   125,   125,   125,   126,   127,   127,   128,   128,
     128,   128,   128,   128,   129,   129,   129,   129,   129,   130,
     130,   130,   130,   130,   130,   130,   130,   130,   131,   131,
     131,   132,   132,   132,   133,   133,   134,   134,   135,   135,
     135,   135,   135,   135,   135,   135,   135,   136,   136,   136,
     136,   136,   136,   136,   136,   136,   137,   137,   138,   139,
     139,   140,   141,   141,   142,   143,   143,   144,   144,   145,
     145,   145,   146,   146,   146,   146,   147,   147,   148,   149,
     150,   150,   151,   152,   152,   153,   153,   153,   153,   154,
     154,   154,   155,   156,   156,   157,   157,   158,   159,   159,
     160,   160,   161,   161,   162,   163,   163,   164,   164,   164,
     164,   164,   164,   164,   164,   164,   165,   165,   166,   166,
     167,   167,   168,   168,   169,   169,   170,   170,   171,   172,
     172,   173,   174,   174,   175,   176,   176,   177,   178,   179,
     180,   180,   181,   181,   182,   183,   183,   184,   185,   186,
     186,   187,   188,   188,   189,   189,   189,   189,   190,   191,
     192,   192,   193,   193,   194,   194,   195,   196,   196,   197,
     198,   198,   199,   200,   200,   201,   202,   203,   203,   204,
     205,   205,   206,   206,   207,   208,   209,   209,   210,   210,
     211
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     1,     1,     1,     2,     4,     1,     0,
       2,     2,     2,     2,     3,     2,     1,     2,     3,     2,
       3,     0,     1,     1,     2,     1,     2,     2,     1,     1,
       1,     1,     1,     3,     3,     1,     1,     1,     1,     1,
       4,     4,     3,     3,     0,     1,     3,     3,     7,     1,
       0,     1,     0,     2,     3,     3,     5,     4,     4,     4,
       7,     7,     7,     9,     2,     3,     0,     4,     4,     4,
       4,     6,     4,     3,     4,     3,     4,     3,     4,     4,
       2,     1,     3,     1,     1,     3,     3,     1,     5,     1,
       3,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     3,     1,     3,     1,     3,     2,
       2,     1,     2,     1,     4,     1,     1,     2,     2,     3,
       2,     0,     1,     2,     1,     3,     1,     1,     1,     3,
       5,     7,     5,     1,     1,     3,     7,     5,     1,     1,
       1,     2,     1,     1,     2,     3,     3,     5,     1,     1,
       1,     1,     1,     1,     3,     5,     3,     2,     6,     7,
       7,     7,     8,     8,     8,     9,     7,     6,     7,     7,
       7,     8,     8,     8,     9,     7,     1,     1,     2,     3,
       0,     4,     1,     0,     2,     3,     0,     1,     1,     1,
       1,     1,     4,     5,     5,     6,     2,     0,     2,     3,
       3,     0,     3,     2,     0,     1,     1,     1,     1,     1,
       1,     1,     4,     2,     0,     1,     1,     2,     3,     0,
       3,     1,     2,     1,     3,     2,     0,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     3,     1,     1,
       6,     5,     2,     0,     1,     0,     4,     2,     2,     3,
       0,     4,     2,     0,     4,     1,     1,     1,     2,     3,
       2,     0,     1,     1,     6,     1,     0,     3,     2,     3,
       0,     4,     1,     0,     6,     6,     8,     8,     4,     5,
       1,     0,     1,     0,     1,     0,     2,     3,     0,     3,
       4,     0,     2,     2,     0,     6,     3,     1,     0,     2,
       3,     0,     2,     1,     3,     3,     2,     0,     1,     1,
       3
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
#line 2131 "parser.tab.c"
    break;


#line 2135 "parser.tab.c"

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

#line 761 "parser.y"


int main(){
    if(yyparse()) return 0;
    
    return 0;
}
