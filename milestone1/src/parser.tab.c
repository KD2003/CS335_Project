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
  YYSYMBOL_numerictype = 73,               /* numerictype  */
  YYSYMBOL_ReferenceType = 74,             /* ReferenceType  */
  YYSYMBOL_IDENdotIDEN = 75,               /* IDENdotIDEN  */
  YYSYMBOL_IDENdotIDENdot = 76,            /* IDENdotIDENdot  */
  YYSYMBOL_NumericType = 77,               /* NumericType  */
  YYSYMBOL_ClassModifier = 78,             /* ClassModifier  */
  YYSYMBOL_ClassType = 79,                 /* ClassType  */
  YYSYMBOL_Zeroorone_TypeArguments = 80,   /* Zeroorone_TypeArguments  */
  YYSYMBOL_ArrayType = 81,                 /* ArrayType  */
  YYSYMBOL_Dims = 82,                      /* Dims  */
  YYSYMBOL_TypeParameter = 83,             /* TypeParameter  */
  YYSYMBOL_TypeBound = 84,                 /* TypeBound  */
  YYSYMBOL_TypeArguments = 85,             /* TypeArguments  */
  YYSYMBOL_TypeArgumentList = 86,          /* TypeArgumentList  */
  YYSYMBOL_cTypeArgument = 87,             /* cTypeArgument  */
  YYSYMBOL_TypeArgument = 88,              /* TypeArgument  */
  YYSYMBOL_Wildcard = 89,                  /* Wildcard  */
  YYSYMBOL_zerooroneWildcardBounds = 90,   /* zerooroneWildcardBounds  */
  YYSYMBOL_WildcardBounds = 91,            /* WildcardBounds  */
  YYSYMBOL_Primary = 92,                   /* Primary  */
  YYSYMBOL_PrimaryNoNewArray = 93,         /* PrimaryNoNewArray  */
  YYSYMBOL_ClassLiteral = 94,              /* ClassLiteral  */
  YYSYMBOL_Zero_or_moreSquarebracket = 95, /* Zero_or_moreSquarebracket  */
  YYSYMBOL_ClassInstanceCreationExpression = 96, /* ClassInstanceCreationExpression  */
  YYSYMBOL_UnqualifiedClassInstanceCreationExpression = 97, /* UnqualifiedClassInstanceCreationExpression  */
  YYSYMBOL_ZerooroneTypeArguments = 98,    /* ZerooroneTypeArguments  */
  YYSYMBOL_ZerooroneArgumentList = 99,     /* ZerooroneArgumentList  */
  YYSYMBOL_ZerooroneClassBody = 100,       /* ZerooroneClassBody  */
  YYSYMBOL_ClassOrInterfaceTypeToInstantiate = 101, /* ClassOrInterfaceTypeToInstantiate  */
  YYSYMBOL_Zeroormore_DotIdentifier = 102, /* Zeroormore_DotIdentifier  */
  YYSYMBOL_FieldAccess = 103,              /* FieldAccess  */
  YYSYMBOL_ArrayAccess = 104,              /* ArrayAccess  */
  YYSYMBOL_MethodInvocation = 105,         /* MethodInvocation  */
  YYSYMBOL_Zeroorone_ArgumentList = 106,   /* Zeroorone_ArgumentList  */
  YYSYMBOL_ArgumentList = 107,             /* ArgumentList  */
  YYSYMBOL_Zeroormore_CommaExpression = 108, /* Zeroormore_CommaExpression  */
  YYSYMBOL_MethodReference = 109,          /* MethodReference  */
  YYSYMBOL_ArrayCreationExpression = 110,  /* ArrayCreationExpression  */
  YYSYMBOL_DimExprs = 111,                 /* DimExprs  */
  YYSYMBOL_Zeroormore_DimExpr = 112,       /* Zeroormore_DimExpr  */
  YYSYMBOL_DimExpr = 113,                  /* DimExpr  */
  YYSYMBOL_Expression = 114,               /* Expression  */
  YYSYMBOL_AssignmentExpression = 115,     /* AssignmentExpression  */
  YYSYMBOL_ConditionalExpression = 116,    /* ConditionalExpression  */
  YYSYMBOL_ConditionalOrExpression = 117,  /* ConditionalOrExpression  */
  YYSYMBOL_ConditionalAndExpression = 118, /* ConditionalAndExpression  */
  YYSYMBOL_AndExpression = 119,            /* AndExpression  */
  YYSYMBOL_ExclusiveOrExpression = 120,    /* ExclusiveOrExpression  */
  YYSYMBOL_InclusiveOrExpression = 121,    /* InclusiveOrExpression  */
  YYSYMBOL_EqualityExpression = 122,       /* EqualityExpression  */
  YYSYMBOL_RelationalExpression = 123,     /* RelationalExpression  */
  YYSYMBOL_ShiftExpression = 124,          /* ShiftExpression  */
  YYSYMBOL_AdditiveExpression = 125,       /* AdditiveExpression  */
  YYSYMBOL_MultiplicativeExpression = 126, /* MultiplicativeExpression  */
  YYSYMBOL_UnaryExpression = 127,          /* UnaryExpression  */
  YYSYMBOL_CastExpression = 128,           /* CastExpression  */
  YYSYMBOL_PostfixExpression = 129,        /* PostfixExpression  */
  YYSYMBOL_Block = 130,                    /* Block  */
  YYSYMBOL_BlockStatements = 131,          /* BlockStatements  */
  YYSYMBOL_BlockStatement = 132,           /* BlockStatement  */
  YYSYMBOL_LocalVariableDeclaration = 133, /* LocalVariableDeclaration  */
  YYSYMBOL_LocalVariableType = 134,        /* LocalVariableType  */
  YYSYMBOL_Statement = 135,                /* Statement  */
  YYSYMBOL_StatementNoShortIf = 136,       /* StatementNoShortIf  */
  YYSYMBOL_StatementWithoutTrailingSubstatement = 137, /* StatementWithoutTrailingSubstatement  */
  YYSYMBOL_StatementExpression = 138,      /* StatementExpression  */
  YYSYMBOL_LeftHandSide = 139,             /* LeftHandSide  */
  YYSYMBOL_AssertStatement = 140,          /* AssertStatement  */
  YYSYMBOL_BreakContinueStatement = 141,   /* BreakContinueStatement  */
  YYSYMBOL_ForStatement = 142,             /* ForStatement  */
  YYSYMBOL_ForStatementNoShortIf = 143,    /* ForStatementNoShortIf  */
  YYSYMBOL_ForInit = 144,                  /* ForInit  */
  YYSYMBOL_StatementExpressionList = 145,  /* StatementExpressionList  */
  YYSYMBOL_StatementExpressionMore = 146,  /* StatementExpressionMore  */
  YYSYMBOL_ArrayInitializer = 147,         /* ArrayInitializer  */
  YYSYMBOL_zerooroneVariableInitializerList = 148, /* zerooroneVariableInitializerList  */
  YYSYMBOL_VariableInitializerList = 149,  /* VariableInitializerList  */
  YYSYMBOL_cVariableInitializer = 150,     /* cVariableInitializer  */
  YYSYMBOL_VariableInitializer = 151,      /* VariableInitializer  */
  YYSYMBOL_ClassDeclaration = 152,         /* ClassDeclaration  */
  YYSYMBOL_NormalClassDeclaration = 153,   /* NormalClassDeclaration  */
  YYSYMBOL_ClassModifiers = 154,           /* ClassModifiers  */
  YYSYMBOL_ClassExtends = 155,             /* ClassExtends  */
  YYSYMBOL_ClassPermits = 156,             /* ClassPermits  */
  YYSYMBOL_cTypeName = 157,                /* cTypeName  */
  YYSYMBOL_ClassBody = 158,                /* ClassBody  */
  YYSYMBOL_ClassBodyDeclarations = 159,    /* ClassBodyDeclarations  */
  YYSYMBOL_ClassBodyDeclaration = 160,     /* ClassBodyDeclaration  */
  YYSYMBOL_ClassMemberDeclaration = 161,   /* ClassMemberDeclaration  */
  YYSYMBOL_FieldDeclaration = 162,         /* FieldDeclaration  */
  YYSYMBOL_FieldModifiers = 163,           /* FieldModifiers  */
  YYSYMBOL_FieldModifier = 164,            /* FieldModifier  */
  YYSYMBOL_VariableDeclaratorList = 165,   /* VariableDeclaratorList  */
  YYSYMBOL_cVariableDeclarator = 166,      /* cVariableDeclarator  */
  YYSYMBOL_VariableDeclarator = 167,       /* VariableDeclarator  */
  YYSYMBOL_VariableDeclaratorId = 168,     /* VariableDeclaratorId  */
  YYSYMBOL_MethodDeclaration = 169,        /* MethodDeclaration  */
  YYSYMBOL_Methodmodifiers = 170,          /* Methodmodifiers  */
  YYSYMBOL_Methodmodifier = 171,           /* Methodmodifier  */
  YYSYMBOL_Methodheader = 172,             /* Methodheader  */
  YYSYMBOL_Throws_s = 173,                 /* Throws_s  */
  YYSYMBOL_Result = 174,                   /* Result  */
  YYSYMBOL_Methodeclarator = 175,          /* Methodeclarator  */
  YYSYMBOL_recieveparameters = 176,        /* recieveparameters  */
  YYSYMBOL_formalparameters = 177,         /* formalparameters  */
  YYSYMBOL_recieveparameter = 178,         /* recieveparameter  */
  YYSYMBOL_formalparameterlist = 179,      /* formalparameterlist  */
  YYSYMBOL_cformalparameter = 180,         /* cformalparameter  */
  YYSYMBOL_formalparameter = 181,          /* formalparameter  */
  YYSYMBOL_VariableModifier = 182,         /* VariableModifier  */
  YYSYMBOL_VariableArityParameter = 183,   /* VariableArityParameter  */
  YYSYMBOL_Throws = 184,                   /* Throws  */
  YYSYMBOL_ExceptionTypeList = 185,        /* ExceptionTypeList  */
  YYSYMBOL_cExceptionType = 186,           /* cExceptionType  */
  YYSYMBOL_ExceptionType = 187,            /* ExceptionType  */
  YYSYMBOL_MethodBody = 188,               /* MethodBody  */
  YYSYMBOL_InstanceInitializer = 189,      /* InstanceInitializer  */
  YYSYMBOL_StaticInitializer = 190,        /* StaticInitializer  */
  YYSYMBOL_ConstructorDeclaration = 191,   /* ConstructorDeclaration  */
  YYSYMBOL_zeroormore_ConstructorModifier = 192, /* zeroormore_ConstructorModifier  */
  YYSYMBOL_ConstructorModifier = 193,      /* ConstructorModifier  */
  YYSYMBOL_ConstructorDeclarator = 194,    /* ConstructorDeclarator  */
  YYSYMBOL_zeroorone_TypeParameters = 195, /* zeroorone_TypeParameters  */
  YYSYMBOL_TypeParameters = 196,           /* TypeParameters  */
  YYSYMBOL_TypeParamerList = 197,          /* TypeParamerList  */
  YYSYMBOL_TypeParameterc = 198,           /* TypeParameterc  */
  YYSYMBOL_ConstructorBody = 199,          /* ConstructorBody  */
  YYSYMBOL_zerooroneExplicitConstructorInvocation = 200, /* zerooroneExplicitConstructorInvocation  */
  YYSYMBOL_ExplicitConstructorInvocation = 201, /* ExplicitConstructorInvocation  */
  YYSYMBOL_EnumDeclaration = 202,          /* EnumDeclaration  */
  YYSYMBOL_zeroormoreClassModifier = 203,  /* zeroormoreClassModifier  */
  YYSYMBOL_EnumBody = 204,                 /* EnumBody  */
  YYSYMBOL_zerooronecomma = 205,           /* zerooronecomma  */
  YYSYMBOL_zerooroneEnumConstantList = 206, /* zerooroneEnumConstantList  */
  YYSYMBOL_zerooroneEnumBodyDeclarations = 207, /* zerooroneEnumBodyDeclarations  */
  YYSYMBOL_EnumConstantList = 208,         /* EnumConstantList  */
  YYSYMBOL_cEnumConstant = 209,            /* cEnumConstant  */
  YYSYMBOL_EnumConstant = 210,             /* EnumConstant  */
  YYSYMBOL_bracketZeroorone_ArgumentList = 211, /* bracketZeroorone_ArgumentList  */
  YYSYMBOL_EnumBodyDeclarations = 212,     /* EnumBodyDeclarations  */
  YYSYMBOL_zeroormoreClassBodyDeclaration = 213, /* zeroormoreClassBodyDeclaration  */
  YYSYMBOL_RecordDeclaration = 214,        /* RecordDeclaration  */
  YYSYMBOL_RecordHeader = 215,             /* RecordHeader  */
  YYSYMBOL_zerooroneRecordComponentList = 216, /* zerooroneRecordComponentList  */
  YYSYMBOL_RecordComponentList = 217,      /* RecordComponentList  */
  YYSYMBOL_cRecordComponent = 218,         /* cRecordComponent  */
  YYSYMBOL_RecordComponent = 219,          /* RecordComponent  */
  YYSYMBOL_VariableArityRecordComponent = 220, /* VariableArityRecordComponent  */
  YYSYMBOL_RecordBody = 221,               /* RecordBody  */
  YYSYMBOL_zeroormoreRecordBodyDeclaration = 222, /* zeroormoreRecordBodyDeclaration  */
  YYSYMBOL_RecordBodyDeclaration = 223,    /* RecordBodyDeclaration  */
  YYSYMBOL_CompactConstructorDeclaration = 224 /* CompactConstructorDeclaration  */
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
#define YYFINAL  11
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1870

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  69
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  156
/* YYNRULES -- Number of rules.  */
#define YYNRULES  346
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  654

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
       0,    22,    22,    27,    28,    32,    33,    37,    38,    45,
      46,    47,    53,    54,    58,    85,    86,    93,    93,    97,
      98,   102,   102,   106,   107,   108,   111,   112,   115,   116,
     120,   121,   124,   127,   130,   131,   134,   135,   138,   141,
     142,   145,   146,   152,   153,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   171,   172,   173,   174,   175,
     179,   180,   184,   185,   186,   191,   195,   195,   199,   199,
     203,   203,   208,   212,   212,   216,   216,   221,   222,   223,
     228,   229,   234,   235,   236,   237,   238,   239,   243,   243,
     247,   247,   252,   256,   257,   262,   263,   264,   265,   266,
     267,   268,   273,   274,   275,   276,   277,   278,   282,   286,
     286,   290,   294,   298,   299,   300,   304,   305,   309,   310,
     314,   315,   319,   320,   324,   325,   329,   330,   334,   335,
     339,   340,   344,   345,   349,   350,   354,   355,   359,   360,
     361,   362,   363,   367,   371,   372,   373,   381,   385,   385,
     389,   390,   391,   395,   399,   400,   404,   405,   406,   407,
     408,   409,   413,   414,   415,   416,   417,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   433,   436,   437,   441,
     442,   443,   447,   448,   452,   453,   457,   458,   459,   460,
     461,   462,   463,   464,   465,   469,   470,   471,   472,   473,
     474,   475,   476,   477,   481,   482,   485,   489,   489,   496,
     499,   500,   503,   507,   507,   511,   512,   518,   519,   520,
     523,   524,   525,   526,   529,   530,   533,   536,   540,   540,
     544,   547,   548,   551,   552,   553,   554,   557,   558,   559,
     562,   565,   566,   569,   569,   572,   575,   576,   579,   580,
     584,   585,   590,   594,   595,   599,   599,   599,   599,   599,
     599,   599,   599,   599,   603,   604,   608,   609,   613,   614,
     618,   619,   623,   624,   627,   628,   632,   633,   637,   640,
     640,   643,   647,   647,   650,   653,   656,   659,   660,   663,
     666,   667,   670,   673,   676,   679,   680,   683,   683,   686,
     689,   690,   693,   696,   699,   700,   704,   708,   709,   712,
     713,   714,   715,   718,   721,   722,   725,   728,   729,   732,
     733,   736,   737,   740,   743,   744,   747,   750,   751,   754,
     757,   758,   761,   764,   767,   768,   771,   774,   775,   778,
     779,   782,   785,   788,   789,   792,   796
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
  "PrimitiveType", "numerictype", "ReferenceType", "IDENdotIDEN",
  "IDENdotIDENdot", "NumericType", "ClassModifier", "ClassType",
  "Zeroorone_TypeArguments", "ArrayType", "Dims", "TypeParameter",
  "TypeBound", "TypeArguments", "TypeArgumentList", "cTypeArgument",
  "TypeArgument", "Wildcard", "zerooroneWildcardBounds", "WildcardBounds",
  "Primary", "PrimaryNoNewArray", "ClassLiteral",
  "Zero_or_moreSquarebracket", "ClassInstanceCreationExpression",
  "UnqualifiedClassInstanceCreationExpression", "ZerooroneTypeArguments",
  "ZerooroneArgumentList", "ZerooroneClassBody",
  "ClassOrInterfaceTypeToInstantiate", "Zeroormore_DotIdentifier",
  "FieldAccess", "ArrayAccess", "MethodInvocation",
  "Zeroorone_ArgumentList", "ArgumentList", "Zeroormore_CommaExpression",
  "MethodReference", "ArrayCreationExpression", "DimExprs",
  "Zeroormore_DimExpr", "DimExpr", "Expression", "AssignmentExpression",
  "ConditionalExpression", "ConditionalOrExpression",
  "ConditionalAndExpression", "AndExpression", "ExclusiveOrExpression",
  "InclusiveOrExpression", "EqualityExpression", "RelationalExpression",
  "ShiftExpression", "AdditiveExpression", "MultiplicativeExpression",
  "UnaryExpression", "CastExpression", "PostfixExpression", "Block",
  "BlockStatements", "BlockStatement", "LocalVariableDeclaration",
  "LocalVariableType", "Statement", "StatementNoShortIf",
  "StatementWithoutTrailingSubstatement", "StatementExpression",
  "LeftHandSide", "AssertStatement", "BreakContinueStatement",
  "ForStatement", "ForStatementNoShortIf", "ForInit",
  "StatementExpressionList", "StatementExpressionMore", "ArrayInitializer",
  "zerooroneVariableInitializerList", "VariableInitializerList",
  "cVariableInitializer", "VariableInitializer", "ClassDeclaration",
  "NormalClassDeclaration", "ClassModifiers", "ClassExtends",
  "ClassPermits", "cTypeName", "ClassBody", "ClassBodyDeclarations",
  "ClassBodyDeclaration", "ClassMemberDeclaration", "FieldDeclaration",
  "FieldModifiers", "FieldModifier", "VariableDeclaratorList",
  "cVariableDeclarator", "VariableDeclarator", "VariableDeclaratorId",
  "MethodDeclaration", "Methodmodifiers", "Methodmodifier", "Methodheader",
  "Throws_s", "Result", "Methodeclarator", "recieveparameters",
  "formalparameters", "recieveparameter", "formalparameterlist",
  "cformalparameter", "formalparameter", "VariableModifier",
  "VariableArityParameter", "Throws", "ExceptionTypeList",
  "cExceptionType", "ExceptionType", "MethodBody", "InstanceInitializer",
  "StaticInitializer", "ConstructorDeclaration",
  "zeroormore_ConstructorModifier", "ConstructorModifier",
  "ConstructorDeclarator", "zeroorone_TypeParameters", "TypeParameters",
  "TypeParamerList", "TypeParameterc", "ConstructorBody",
  "zerooroneExplicitConstructorInvocation",
  "ExplicitConstructorInvocation", "EnumDeclaration",
  "zeroormoreClassModifier", "EnumBody", "zerooronecomma",
  "zerooroneEnumConstantList", "zerooroneEnumBodyDeclarations",
  "EnumConstantList", "cEnumConstant", "EnumConstant",
  "bracketZeroorone_ArgumentList", "EnumBodyDeclarations",
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

#define YYPACT_NINF (-503)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-345)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     302,  -503,  -503,    28,   302,  -503,  -503,     6,  -503,    88,
    -503,  -503,  -503,  -503,    72,   117,   157,   159,    14,    89,
     182,   182,   593,    57,   139,  -503,   215,   174,  -503,   231,
    -503,  -503,    21,    65,   204,  -503,  -503,    94,   192,  -503,
    -503,  -503,  -503,   415,  -503,  -503,  -503,   200,   593,  -503,
    -503,   398,    96,  -503,   212,   481,  -503,  -503,  -503,    14,
     103,   139,  -503,  -503,   258,   241,   245,   398,   250,   259,
     267,  -503,   231,   326,   182,  -503,    90,  -503,  -503,   334,
    -503,  1071,  -503,  -503,   382,  -503,  -503,  -503,   340,   301,
    -503,  -503,   125,  -503,  -503,  -503,  -503,   376,  -503,  -503,
     318,   145,   356,  -503,  -503,  -503,  -503,   323,   367,  -503,
    -503,  -503,  -503,   385,  -503,   215,  -503,  -503,    44,   346,
    -503,   337,  -503,   976,  -503,  1811,   139,  -503,   336,  -503,
     231,  -503,    21,   261,   301,  -503,   358,   343,  -503,   363,
     165,  -503,   360,   368,   371,  1811,  1811,  1811,  1811,  1811,
      16,   849,   377,   381,   383,   387,   151,  -503,   375,   149,
    1811,  -503,  -503,   402,   202,   296,  -503,   293,   419,   186,
     412,  -503,  -503,  -503,    50,    77,  -503,  -503,  -503,  -503,
    -503,    38,   454,   410,   413,   411,   463,   466,   467,   462,
     473,  -503,  -503,   475,  -503,  -503,   428,  -503,  -503,   430,
      79,  -503,  -503,  -503,  -503,   453,   451,   458,   301,   438,
     450,   452,   458,   458,   356,  -503,  -503,  -503,   459,   323,
     182,   446,   323,   468,  -503,   204,   241,  -503,   513,  -503,
     398,  -503,   103,   456,   976,   167,  -503,  -503,   476,  -503,
    -503,  -503,  -503,  -503,  1447,   470,  -503,  -503,  -503,   398,
     398,  -503,  -503,  -503,    90,  -503,  -503,  1811,  1173,   303,
     344,  -503,  -503,  -503,  -503,  -503,   -16,   472,   474,  -503,
    -503,   478,  1811,   354,  1811,  1811,   363,    15,   488,   485,
     331,  -503,   537,   357,   484,   363,   363,   326,  1811,   397,
     195,  -503,   363,   545,  -503,   400,   363,   511,   363,    19,
    1811,  1811,  1811,  1811,  1811,  1811,  1811,  1811,  1811,  1811,
    1811,  1811,  -503,  -503,  -503,  1811,  1811,  -503,  -503,  -503,
     340,  -503,   500,   458,  -503,   340,  -503,  1424,   323,   398,
    -503,   204,  -503,   504,  1803,  -503,  -503,   398,  -503,  -503,
     337,   553,  -503,  -503,  -503,   259,   512,  1447,  -503,  -503,
    -503,  -503,   343,   514,  -503,   533,   518,  1811,  -503,  -503,
    -503,  -503,   521,  1264,   516,   525,   515,  -503,   524,   526,
     583,  -503,   584,  -503,   917,    69,   301,  -503,    69,   301,
     538,   530,  1811,  -503,   587,   588,   539,   557,   363,    61,
     540,   559,   561,  -503,   604,  -503,   605,  -503,   556,   454,
     549,   411,   463,   410,   413,   466,   467,   462,   473,  -503,
    -503,  -503,  -503,  -503,   450,  1424,  -503,  -503,  -503,  -503,
      22,   554,   560,   182,  -503,  1811,   344,   332,   580,   581,
     268,   582,  -503,  -503,   554,  -503,   446,  -503,  1811,  -503,
    -503,  -503,  -503,  -503,   552,  1224,  1464,   555,  1811,  1811,
    -503,  1304,  1173,   192,  -503,   563,   571,  -503,   458,   575,
    -503,   458,   625,   363,  1811,  -503,  -503,  -503,  -503,  -503,
     626,  -503,   632,  1811,  -503,  -503,  -503,   579,  -503,  1811,
    -503,   267,  -503,  -503,   594,  -503,   585,  -503,   590,   499,
    -503,   504,    98,   603,   592,    26,   596,  1122,   602,  -503,
    -503,  -503,   339,   606,   608,   610,  -503,   624,   635,  -503,
    1173,   612,  1507,   615,  -503,  1550,   616,  -503,  -503,  1811,
    -503,  1811,  -503,  -503,  -503,   618,  -503,  -503,   627,   628,
    1811,  -503,   586,   607,   653,   301,  -503,  -503,   340,  -503,
     633,  1811,   660,  1811,  -503,  -503,  1224,  1811,   766,  1811,
    1173,  -503,  1173,  1173,   637,  1173,  1173,   638,  1593,   642,
     139,  1811,  -503,   643,  -503,  1424,  -503,   458,   590,  -503,
    1811,   645,   649,   651,  -503,   656,  1344,   657,   652,   663,
    -503,  -503,  -503,  1173,  -503,  -503,  1173,  1173,   664,  -503,
    -503,   665,  -503,  -503,  -503,   499,  -503,   668,   662,  1811,
     666,  1224,  1636,   667,  1811,  1384,  1224,  -503,  -503,  -503,
    1173,  -503,   685,   669,  -503,   672,  -503,   705,  1224,   681,
    1679,   684,  1722,   679,  -503,  -503,   709,  -503,   680,  1224,
    -503,  1224,  1224,   689,  1224,  1224,   690,  1765,  -503,  -503,
    -503,  -503,  -503,  1224,  -503,  -503,  1224,  1224,   691,  -503,
    -503,  -503,  1224,  -503
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
     315,    17,    18,     0,   315,     2,   217,     0,   218,     0,
     219,     1,   224,   314,     0,     0,     0,     0,   301,     0,
       0,     0,   242,     0,     0,   220,     0,     0,   300,   320,
     313,    13,   229,    22,   226,   261,   260,   255,   259,   258,
     262,   263,   256,   257,   149,   239,   292,     0,   242,   233,
     237,     0,   242,   238,     0,   254,   234,   235,   236,   301,
     296,     0,   221,   222,    29,     0,     0,   335,     0,   328,
     318,   319,   325,     0,     0,   227,     0,    19,    21,     0,
     293,    55,   230,   231,    10,     7,     8,     6,     0,     3,
       5,     4,     9,    11,   243,   244,   241,    29,   269,   268,
       0,     0,     0,   255,   259,   257,   253,   267,     0,   297,
     298,   295,   223,     0,    28,     0,   303,   302,     0,     0,
     334,   338,   340,   242,   332,    55,    71,   317,   322,   323,
     325,    12,   229,    40,     0,    36,     0,    35,    37,    22,
      13,    45,     7,     8,     6,    55,    55,    55,    55,    55,
       0,    55,     0,     0,     0,     0,     0,    47,     0,     0,
      55,   147,   168,     0,   145,    22,    61,     0,     0,   144,
      43,    46,    50,    62,    51,    52,    53,    54,    44,   176,
     113,   116,   118,   124,   126,   120,   122,   128,   130,   132,
     134,   136,   142,   140,   167,   148,     0,   152,   156,     0,
       0,   170,   171,   161,   150,     0,     0,    25,   251,     0,
     247,   249,    23,    24,     0,   291,   290,   252,     0,   267,
       0,     0,   267,     0,    13,    31,   305,   339,     0,   333,
       0,   336,   296,     0,   242,    13,    50,    53,     0,    88,
      94,   112,   326,    70,   242,     0,   321,   324,   228,     0,
       0,    38,    39,    32,     0,    33,    20,    55,    55,     0,
     145,    51,    52,   139,   138,   141,     0,     0,     0,   185,
     172,     0,    55,    55,    55,    55,    22,     0,     0,     0,
       0,    66,     0,     0,     0,    22,    22,    14,    55,     0,
       0,    48,    67,     0,    63,     0,    22,     0,    22,     0,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,   146,   151,   169,    55,    55,   155,   282,   154,
       0,    26,     0,   250,   240,     0,   245,    55,   267,   273,
     264,   289,   285,   288,   308,   294,   266,   273,   304,   341,
     338,     0,   345,   342,   343,   328,    92,   242,   329,   316,
      41,    42,    35,     0,   157,     0,     0,    55,   182,   174,
     184,   173,     0,    55,   205,   208,     0,   204,     0,     0,
       0,    78,     0,    59,    55,     0,   103,   110,     0,   105,
      74,     0,    55,    49,     0,     0,     0,     0,    22,     0,
       0,     0,     0,   101,     0,    77,     0,    64,     0,   119,
       0,   121,   123,   125,   127,   129,   131,   133,   135,   137,
     114,   115,   153,    27,   247,    55,   215,   216,   248,   265,
       0,   283,     0,     0,   286,    55,     0,    22,     0,    21,
       0,     0,   149,   307,   283,   337,     0,   327,    55,   330,
      34,    82,    58,    60,     0,    55,    55,     0,    55,    55,
     206,    55,    55,     0,    98,     0,     0,   106,   102,   108,
     107,   104,     0,    22,    55,   143,    97,    95,    80,    56,
       0,    79,     0,    55,    57,   100,    96,     0,    81,    55,
     246,   318,   210,   214,     0,   277,     0,   274,   280,     0,
     272,   288,     0,     0,     0,   301,     0,    55,     0,   346,
      93,   183,    13,     0,     0,     0,   158,     0,   156,   166,
      55,     0,    55,     0,   207,    55,     0,   160,   175,    55,
     111,    55,   109,    73,    72,     0,    68,    99,     0,     0,
      55,   117,     0,   212,     0,   271,   283,   278,     0,   287,
       0,    55,     0,    55,   306,   299,    55,    55,    55,    55,
      55,   186,    55,    55,     0,    55,    55,     0,    55,     0,
      71,    55,    83,     0,   209,    55,   276,   270,   280,   283,
      55,     0,     0,     0,   163,     0,    55,   205,     0,     0,
     159,   189,   188,    55,   194,   187,    55,    55,     0,    86,
      65,     0,    85,   213,   279,     0,   281,     0,     0,    55,
       0,    55,    55,     0,    55,    55,    55,   190,   192,   191,
      55,    87,     0,     0,   310,     0,   309,     0,    55,     0,
      55,     0,    55,     0,   165,   193,     0,   311,     0,    55,
     195,    55,    55,     0,    55,    55,     0,    55,   284,   312,
     164,   198,   197,    55,   203,   196,    55,    55,     0,   199,
     201,   200,    55,   202
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -503,  -503,   -22,   -29,  -503,    10,   -20,   421,  -503,  -503,
     -18,    27,    12,   -84,   -30,  -503,  -155,  -503,   401,   505,
    -503,  -503,  -503,   426,  -503,  -503,  -109,   -67,  -147,   427,
    -502,   205,  -503,  -503,  -136,   -32,    48,  -225,  -300,  -503,
    -503,  -503,   487,  -503,   309,   464,   399,   290,  -503,   471,
     469,   477,   479,   486,   482,   489,   483,   491,  -130,  -503,
    -503,     5,   349,  -503,  -266,  -503,   431,    75,   111,  -181,
    -503,  -503,  -503,  -503,  -503,   230,  -440,  -503,  -125,  -503,
    -503,  -503,  -402,   785,  -503,   789,  -503,   771,   674,   127,
     747,  -102,  -503,  -503,   744,  -503,   490,   384,   492,   266,
    -503,   753,  -503,  -503,  -182,   699,   595,   493,   378,  -503,
    -503,   243,   277,  -379,  -503,  -503,  -503,   324,   393,  -503,
    -503,  -503,  -503,   -48,  -503,  -503,   -57,  -503,  -503,   597,
     386,  -503,  -503,  -503,   814,  -503,   338,  -503,  -503,  -503,
     696,   791,   494,  -503,   495,  -503,  -503,  -503,  -503,   496,
     598,  -503,  -503,   599,  -503,  -503
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     3,    99,   134,    90,   163,   164,   165,   166,     4,
     167,    77,   168,   207,    65,   114,    78,   136,   255,   137,
     138,   251,   252,   169,   170,   171,   289,   236,   173,   282,
     525,   242,   381,   463,   174,   175,   237,   238,   239,   346,
     177,   178,   376,   459,   377,   240,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,    81,   195,   196,   320,   197,   507,   198,   199,
     200,   201,   202,   203,   509,   366,   367,   450,   417,   481,
     482,   533,   418,   204,     6,     7,    23,    24,    75,   243,
      47,    48,    49,    50,    51,    52,   209,   326,   210,   211,
      53,    54,    55,   101,   221,   102,   219,   421,   486,   422,
     487,   537,   488,   205,   596,   222,   332,   424,   333,   217,
      56,    57,    58,    59,    60,   107,    27,    28,    66,   116,
     335,   432,   433,     8,     9,    30,   128,    70,   245,    71,
     129,   130,   126,   246,   348,    10,    68,   119,   120,   231,
     121,   122,   124,   233,   234,   342
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      32,    33,   108,    34,   281,   212,   511,   364,   213,   261,
     261,   261,   111,   483,   172,   263,   264,   265,   294,   371,
     268,   232,    89,   395,   100,    89,   484,    46,    11,    88,
     395,    33,   353,    92,    33,   259,    92,   330,    89,   571,
     336,   573,   489,    80,    14,   118,   357,    33,   227,    92,
     212,   301,   358,    46,   132,   489,    33,   295,    92,   485,
     292,    91,  -180,    93,    91,   471,    93,   292,   597,    26,
      76,    89,   554,    73,    76,   557,    17,    91,    74,    93,
      33,   492,    92,   213,   269,   226,   135,    20,    93,  -181,
     228,   315,   365,    33,    84,   225,   302,   615,  -243,    85,
      86,    87,    97,  -243,  -243,  -243,   216,    85,    86,    87,
      91,  -180,    93,   262,   262,   262,    76,    73,   588,    15,
      76,    18,   322,    22,   323,   260,   260,   260,    46,   176,
     279,   283,   232,    16,  -243,   415,    94,   281,  -181,    33,
     316,   280,   347,   109,    25,  -243,   419,    95,   133,  -297,
      62,    63,   397,    31,   110,    29,   133,   489,    85,    86,
      87,    19,   619,   593,   526,   261,   256,   261,   261,   261,
     261,   261,   261,   261,   261,   261,    89,    79,   206,   429,
     633,   409,   636,   319,   341,    33,    31,    92,   112,    20,
     595,   172,   293,   276,    21,   375,   378,   648,   261,   212,
      33,    89,   331,   277,    76,    22,   172,   -10,   118,   -10,
      33,    44,    92,   215,  -179,    91,    97,    93,   206,    64,
     206,    85,    86,    87,   257,    22,   257,   258,   298,    33,
      33,    92,    92,    67,    33,    69,    92,   388,   299,    46,
      91,   526,    93,   526,   286,   347,   261,   389,   529,    46,
     457,    98,   465,   460,   287,   288,    79,    76,    44,   350,
     351,    93,    93,  -179,   135,   365,    93,    82,   514,   262,
     526,   262,   262,   262,   262,   262,   262,   262,   262,   262,
     294,   260,   577,   260,   260,   260,   260,   260,   260,   260,
     260,   260,   458,   113,   559,   461,   249,   250,   115,   526,
      89,   117,   262,   370,   372,   563,   176,   420,    89,    33,
     298,    92,   384,   385,   426,   420,   123,    33,   125,    92,
     495,   176,    84,   392,   127,   394,   396,    85,    86,    87,
     131,   365,   290,   291,   365,   296,   591,   292,   139,    91,
    -225,    93,     1,   261,   208,    79,   206,    91,   397,    93,
     262,    76,    46,     2,   206,   355,   356,    98,   235,   141,
     218,   428,   260,   142,   143,   144,   220,   365,   290,   291,
     493,   223,   145,   292,   146,   147,  -283,   365,   172,   172,
     -10,   -10,   172,    79,   374,   172,   286,   492,  -283,   224,
     156,   157,   206,   158,   230,   159,   287,   288,   257,    76,
     254,   546,    84,    33,   244,   331,   229,    85,    86,    87,
     206,   113,   -15,   160,   253,   470,   472,   382,    76,  -244,
     -16,   365,   363,   -61,  -244,  -244,  -244,   278,   -13,   206,
     172,   -13,   -10,   -10,   -13,   206,   272,   -13,   542,   365,
     273,   365,   274,   172,   285,   172,   275,   262,   172,   387,
     356,   567,   391,   356,   293,  -244,   365,    84,   518,   260,
      89,   297,    85,    86,    87,   300,  -244,   538,   303,    33,
    -298,    92,    33,   304,    92,   317,   306,   305,   307,   172,
     310,   172,   308,   172,   309,   172,   172,   318,   172,   172,
     524,   172,   311,   176,   176,   312,   313,   176,   314,    91,
     176,    93,   135,    84,    93,   321,   324,   325,    85,    86,
      87,   322,   334,   327,    35,    36,   172,   339,   329,   172,
     172,   103,   396,   343,   241,   104,   373,   337,    39,    40,
      41,    42,   105,   318,   172,   172,   345,   349,   374,   172,
     359,   380,   360,   172,   383,   176,   361,   241,   241,   390,
     241,   172,   393,   172,   413,   172,   508,   436,   176,   241,
     176,   423,   172,   176,   172,   172,    89,   172,   172,   438,
     172,   442,   443,   612,   441,    33,   172,    92,   448,   172,
     172,   445,   449,   451,   452,   172,   453,   454,   455,   464,
     462,   466,   467,   468,   176,   469,   176,   474,   176,   473,
     176,   176,   475,   176,   176,    91,   176,    93,   476,   477,
     478,   479,   266,   267,  -275,   271,   494,   490,   -66,   496,
     501,   574,   519,   512,   284,   520,    35,    36,   521,   523,
     527,   176,  -254,    37,   176,   176,   528,    38,   530,   540,
      39,    40,    41,    42,    43,   535,   534,   536,  -296,   176,
     176,   541,   550,   564,   176,   543,   241,   508,   176,    44,
    -232,    45,   545,  -162,   565,   547,   176,   548,   176,   549,
     176,   241,   552,   241,   241,   555,   617,   176,   560,   176,
     176,   624,   176,   176,   558,   176,   561,   241,   562,   354,
     566,   176,   570,   630,   176,   176,   572,   583,   586,   241,
     176,   241,   589,   592,   640,   598,   641,   642,   599,   644,
     645,   600,   508,   638,   241,   241,   601,   508,   649,   604,
     605,   650,   651,   606,   610,   611,   241,   653,   613,   508,
     614,   626,   628,   629,   616,   620,   362,   627,   368,   369,
     508,   631,   508,   508,   634,   508,   508,   637,   639,   643,
     646,   652,   386,   440,   508,   427,   241,   508,   508,   352,
     430,   431,   241,   508,   398,   590,   400,   379,   522,   531,
     235,   141,   399,   241,   403,   142,   143,   144,   578,   410,
     411,   497,   401,   404,   145,     5,   146,   147,  -283,   405,
     402,   416,   407,    12,    61,    83,    96,   406,   480,   214,
    -283,   408,   156,   157,   569,   158,   248,   159,   106,   328,
     412,   594,   498,   568,   241,   539,   491,   414,    13,   532,
      72,   444,   499,   338,   241,   160,   247,   447,   340,     0,
     434,     0,     0,   344,   576,     0,   435,   241,   456,   437,
       0,     0,   439,     0,     0,     0,     0,   241,     0,     0,
     241,     0,     0,   235,   141,     0,     0,     0,   142,   143,
     144,     0,     0,   241,     0,     0,     0,   145,     0,   146,
     147,     0,   241,     0,     0,     0,   506,     0,     0,   416,
       0,     0,     0,   517,     0,   156,   157,     0,   158,   284,
     159,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   500,     0,     0,     0,     0,     0,   160,     0,
       0,     0,   513,     0,     0,   516,     0,   270,   241,     0,
     241,   235,   141,     0,     0,     0,   142,   143,   144,   241,
       0,     0,     0,     0,     0,   145,     0,   146,   147,     0,
     241,   551,   241,     0,     0,     0,   241,     0,   241,     0,
       0,     0,     0,   156,   157,     0,   158,     0,   159,     0,
     241,     0,     0,     0,   241,     0,     0,     0,     0,   241,
       0,   321,     0,     0,     0,   241,   160,   354,     0,     0,
       0,   580,     0,   581,   582,   456,   584,   585,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   241,     0,
       0,     0,     0,   241,   241,     0,     0,     0,     0,    35,
      36,   575,     0,   579,   607,  -254,    37,   608,   609,     0,
      38,     0,     0,    39,    40,    41,    42,    43,     0,   416,
       0,  -296,   506,     0,     0,     0,     0,   517,     0,     0,
     603,   625,    44,  -344,    45,     0,     0,     0,     0,   551,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     580,     0,   581,   582,     0,   584,   585,     0,   621,   623,
       0,     0,     0,     0,   607,   140,   141,   608,   609,     0,
     142,   143,   144,   625,     0,     0,     0,     0,     0,   145,
       0,   146,   147,  -283,   148,   149,   150,   151,   152,     0,
     153,     0,  -315,   154,   155,  -283,     0,   156,   157,  -225,
     158,     1,   159,     0,     0,     0,  -315,     0,     0,     0,
       0,     0,     2,     0,     0,     0,   140,   141,     0,     0,
     160,   142,   143,   144,     0,     0,     0,    44,   161,   162,
     145,     0,   146,   147,  -283,   148,   149,   150,   151,   152,
       0,   153,     0,  -315,   154,   155,  -283,     0,   156,   157,
    -225,   158,     1,   159,     0,     0,     0,  -315,     0,     0,
       0,     0,     0,     2,     0,     0,     0,   140,   141,     0,
       0,   160,   142,   143,   144,     0,     0,     0,    44,   544,
     162,   145,     0,   146,   147,     0,   148,   149,   150,   151,
     152,     0,   153,     0,     0,   154,   155,     0,     0,   156,
     157,     0,   158,     0,   159,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   502,   141,
       0,     0,   160,   142,   143,   144,     0,     0,     0,    44,
       0,   162,   145,     0,   146,   147,     0,   148,   149,   150,
     151,   503,     0,   504,     0,     0,   505,   155,     0,     0,
     156,   157,     0,   158,     0,   159,     0,     0,   235,   141,
       0,     0,     0,   142,   143,   144,     0,     0,     0,     0,
       0,     0,   145,   160,   146,   147,     0,     0,     0,     0,
      44,     0,   162,     0,     0,     0,     0,     0,     0,     0,
     156,   157,     0,   158,     0,   159,     0,     0,   235,   141,
       0,     0,     0,   142,   143,   144,     0,     0,     0,     0,
       0,     0,   145,   160,   146,   147,     0,     0,     0,     0,
       0,     0,   446,     0,     0,     0,     0,     0,     0,     0,
     156,   157,     0,   158,     0,   159,     0,     0,   235,   141,
       0,     0,     0,   142,   143,   144,     0,     0,     0,     0,
       0,     0,   145,   160,   146,   147,     0,     0,     0,     0,
       0,     0,   515,     0,     0,     0,     0,     0,     0,     0,
     156,   157,     0,   158,     0,   159,     0,     0,   235,   141,
       0,     0,     0,   142,   143,   144,     0,     0,     0,     0,
       0,     0,   145,   160,   146,   147,     0,     0,     0,     0,
       0,     0,   602,     0,     0,     0,     0,     0,     0,     0,
     156,   157,     0,   158,     0,   159,     0,     0,   235,   141,
       0,     0,     0,   142,   143,   144,     0,     0,     0,     0,
       0,     0,   145,   160,   146,   147,     0,     0,     0,     0,
       0,     0,   622,     0,     0,     0,     0,     0,     0,     0,
     156,   157,     0,   158,     0,   159,     0,     0,   235,   141,
       0,     0,     0,   142,   143,   144,     0,     0,     0,     0,
      35,    36,   145,   160,   146,   147,  -254,    37,     0,     0,
     415,    38,     0,     0,    39,    40,    41,    42,    43,     0,
     156,   157,  -296,   158,     0,   159,     0,     0,     0,     0,
       0,   235,   141,    44,  -331,    45,   142,   143,   144,     0,
       0,     0,     0,   160,   510,   145,     0,   146,   147,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   156,   157,     0,   158,     0,   159,     0,
       0,     0,     0,     0,   235,   141,     0,     0,     0,   142,
     143,   144,     0,     0,     0,     0,   160,   553,   145,     0,
     146,   147,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   156,   157,     0,   158,
       0,   159,     0,     0,     0,     0,     0,   235,   141,     0,
       0,     0,   142,   143,   144,     0,     0,     0,     0,   160,
     556,   145,     0,   146,   147,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   156,
     157,     0,   158,     0,   159,     0,     0,     0,     0,     0,
     235,   141,     0,     0,     0,   142,   143,   144,     0,     0,
       0,     0,   160,   587,   145,     0,   146,   147,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   156,   157,     0,   158,     0,   159,     0,     0,
       0,     0,     0,   235,   141,     0,     0,     0,   142,   143,
     144,     0,     0,     0,     0,   160,   618,   145,     0,   146,
     147,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   156,   157,     0,   158,     0,
     159,     0,     0,     0,     0,     0,   235,   141,     0,     0,
       0,   142,   143,   144,     0,     0,     0,     0,   160,   632,
     145,     0,   146,   147,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   156,   157,
       0,   158,     0,   159,     0,     0,     0,     0,     0,   235,
     141,     0,     0,     0,   142,   143,   144,     0,     0,     0,
       0,   160,   635,   145,     0,   146,   147,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   156,   157,     0,   158,     0,   159,   235,   141,     0,
       0,     0,   142,   143,   144,   235,   141,     0,     0,     0,
     142,   143,   144,     0,   160,   647,     0,     0,     0,   145,
       0,   146,   147,     0,     0,     0,     0,     0,     0,   156,
     157,     0,   158,     0,   159,   -55,     0,   156,   157,     0,
     158,     0,   159,     0,     0,   -55,   -55,     0,    76,     0,
       0,     0,   425,     0,     0,     0,     0,     0,     0,     0,
     160
};

static const yytype_int16 yycheck[] =
{
      20,    21,    59,    21,   159,    89,   446,   273,    92,   145,
     146,   147,    60,   415,    81,   145,   146,   147,   165,     4,
       4,   123,    51,     4,    54,    54,     4,    22,     0,    51,
       4,    51,   257,    51,    54,   144,    54,   219,    67,   541,
     222,   543,   421,    38,    38,    67,    62,    67,     4,    67,
     134,    13,    68,    48,    74,   434,    76,   166,    76,    37,
      41,    51,    12,    51,    54,     4,    54,    41,   570,    55,
      55,   100,   512,    52,    55,   515,     4,    67,    57,    67,
     100,    55,   100,   167,    68,   115,    76,    30,    76,    12,
      46,    12,   273,   113,     4,   113,    58,   599,     4,     9,
      10,    11,     4,     9,    10,    11,   101,     9,    10,    11,
     100,    61,   100,   145,   146,   147,    55,    52,   558,    31,
      55,     4,    53,    66,   208,   145,   146,   147,   123,    81,
     159,   160,   234,    45,    40,    66,    40,   292,    61,   159,
      61,   159,   244,    40,    17,    51,   328,    51,    58,    55,
      23,    24,   299,     4,    51,    66,    58,   536,     9,    10,
      11,     4,   602,   565,   464,   301,   139,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   205,    52,    53,   334,
     620,   311,   622,   205,   232,   205,     4,   205,    61,    30,
     569,   258,   165,    42,    35,   279,   280,   637,   334,   283,
     220,   230,   220,    52,    55,    66,   273,    42,   230,    42,
     230,    66,   230,    68,    12,   205,     4,   205,    53,     4,
      53,     9,    10,    11,    59,    66,    59,    62,    42,   249,
     250,   249,   250,    59,   254,     4,   254,    42,    52,   234,
     230,   541,   230,   543,    42,   347,   382,    52,   473,   244,
     375,    39,   382,   378,    52,    53,    52,    55,    66,   249,
     250,   249,   250,    61,   254,   446,   254,    67,   449,   301,
     570,   303,   304,   305,   306,   307,   308,   309,   310,   311,
     427,   301,   548,   303,   304,   305,   306,   307,   308,   309,
     310,   311,   376,    35,   519,   379,    35,    36,    57,   599,
     329,    56,   334,   276,   277,   530,   258,   329,   337,   329,
      42,   329,   285,   286,   334,   337,    66,   337,    59,   337,
      52,   273,     4,   296,    57,   298,   299,     9,    10,    11,
       4,   512,    36,    37,   515,    42,   561,    41,     4,   329,
      38,   329,    40,   479,     4,    52,    53,   337,   495,   337,
     382,    55,   347,    51,    53,    52,    53,    39,     4,     5,
       4,   334,   382,     9,    10,    11,    43,   548,    36,    37,
     427,     4,    18,    41,    20,    21,    22,   558,   445,   446,
       4,    42,   449,    52,    53,   452,    42,    55,    34,     4,
      36,    37,    53,    39,    57,    41,    52,    53,    59,    55,
      57,    62,     4,   423,    68,   423,    60,     9,    10,    11,
      53,    35,    52,    59,    56,   388,   389,    60,    55,     4,
      52,   602,    68,    52,     9,    10,    11,    52,    52,    53,
     497,    55,    56,    57,    52,    53,    59,    55,   495,   620,
      59,   622,    59,   510,    42,   512,    59,   479,   515,    52,
      53,   535,    52,    53,   427,    40,   637,     4,   453,   479,
     489,    42,     9,    10,    11,    53,    51,   489,    14,   489,
      55,   489,   492,    63,   492,    22,    65,    64,    15,   546,
      18,   548,    16,   550,    17,   552,   553,    34,   555,   556,
     463,   558,    19,   445,   446,    20,    68,   449,    68,   489,
     452,   489,   492,     4,   492,    54,    68,    57,     9,    10,
      11,    53,    66,    61,    33,    34,   583,     4,    59,   586,
     587,    40,   495,    67,   125,    44,    38,    59,    47,    48,
      49,    50,    51,    34,   601,   602,    60,    67,    53,   606,
      68,     4,    68,   610,    60,   497,    68,   148,   149,     4,
     151,   618,    41,   620,    54,   622,   445,     4,   510,   160,
     512,    57,   629,   515,   631,   632,   595,   634,   635,    57,
     637,    38,    54,   595,    60,   595,   643,   595,    62,   646,
     647,    60,    57,    68,    60,   652,    60,     4,     4,    59,
      52,     4,     4,    54,   546,    38,   548,    38,   550,    59,
     552,   553,    41,   555,   556,   595,   558,   595,     4,     4,
      54,    62,   148,   149,    60,   151,    36,    57,    37,    37,
      68,   546,    59,    68,   160,    54,    33,    34,    53,     4,
       4,   583,    39,    40,   586,   587,     4,    44,    59,    36,
      47,    48,    49,    50,    51,    60,    52,    57,    55,   601,
     602,    59,    28,    67,   606,    59,   257,   546,   610,    66,
      67,    68,    60,    28,    57,    59,   618,    59,   620,    59,
     622,   272,    60,   274,   275,    60,   601,   629,    60,   631,
     632,   606,   634,   635,    68,   637,    59,   288,    60,   258,
      37,   643,    59,   618,   646,   647,    36,    60,    60,   300,
     652,   302,    60,    60,   629,    60,   631,   632,    59,   634,
     635,    60,   601,     4,   315,   316,    60,   606,   643,    62,
      68,   646,   647,    60,    60,    60,   327,   652,    60,   618,
      68,    46,    60,    28,    68,    68,   272,    68,   274,   275,
     629,    60,   631,   632,    60,   634,   635,    68,    68,    60,
      60,    60,   288,   352,   643,   334,   357,   646,   647,   254,
     334,   334,   363,   652,   300,   560,   302,   280,   459,   479,
       4,     5,   301,   374,   305,     9,    10,    11,   548,   315,
     316,   432,   303,   306,    18,     0,    20,    21,    22,   307,
     304,   327,   309,     4,    23,    48,    52,   308,   414,   100,
      34,   310,    36,    37,   538,    39,   132,    41,    55,   214,
     320,   568,   434,   536,   415,   491,   423,   325,     4,   481,
      29,   357,   436,   226,   425,    59,   130,   363,   230,    -1,
     337,    -1,    -1,   234,    68,    -1,   340,   438,   374,   345,
      -1,    -1,   347,    -1,    -1,    -1,    -1,   448,    -1,    -1,
     451,    -1,    -1,     4,     5,    -1,    -1,    -1,     9,    10,
      11,    -1,    -1,   464,    -1,    -1,    -1,    18,    -1,    20,
      21,    -1,   473,    -1,    -1,    -1,   445,    -1,    -1,   415,
      -1,    -1,    -1,   452,    -1,    36,    37,    -1,    39,   425,
      41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   438,    -1,    -1,    -1,    -1,    -1,    59,    -1,
      -1,    -1,   448,    -1,    -1,   451,    -1,    68,   519,    -1,
     521,     4,     5,    -1,    -1,    -1,     9,    10,    11,   530,
      -1,    -1,    -1,    -1,    -1,    18,    -1,    20,    21,    -1,
     541,   510,   543,    -1,    -1,    -1,   547,    -1,   549,    -1,
      -1,    -1,    -1,    36,    37,    -1,    39,    -1,    41,    -1,
     561,    -1,    -1,    -1,   565,    -1,    -1,    -1,    -1,   570,
      -1,    54,    -1,    -1,    -1,   576,    59,   546,    -1,    -1,
      -1,   550,    -1,   552,   553,   521,   555,   556,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   599,    -1,
      -1,    -1,    -1,   604,   605,    -1,    -1,    -1,    -1,    33,
      34,   547,    -1,   549,   583,    39,    40,   586,   587,    -1,
      44,    -1,    -1,    47,    48,    49,    50,    51,    -1,   565,
      -1,    55,   601,    -1,    -1,    -1,    -1,   606,    -1,    -1,
     576,   610,    66,    67,    68,    -1,    -1,    -1,    -1,   618,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     629,    -1,   631,   632,    -1,   634,   635,    -1,   604,   605,
      -1,    -1,    -1,    -1,   643,     4,     5,   646,   647,    -1,
       9,    10,    11,   652,    -1,    -1,    -1,    -1,    -1,    18,
      -1,    20,    21,    22,    23,    24,    25,    26,    27,    -1,
      29,    -1,    31,    32,    33,    34,    -1,    36,    37,    38,
      39,    40,    41,    -1,    -1,    -1,    45,    -1,    -1,    -1,
      -1,    -1,    51,    -1,    -1,    -1,     4,     5,    -1,    -1,
      59,     9,    10,    11,    -1,    -1,    -1,    66,    67,    68,
      18,    -1,    20,    21,    22,    23,    24,    25,    26,    27,
      -1,    29,    -1,    31,    32,    33,    34,    -1,    36,    37,
      38,    39,    40,    41,    -1,    -1,    -1,    45,    -1,    -1,
      -1,    -1,    -1,    51,    -1,    -1,    -1,     4,     5,    -1,
      -1,    59,     9,    10,    11,    -1,    -1,    -1,    66,    67,
      68,    18,    -1,    20,    21,    -1,    23,    24,    25,    26,
      27,    -1,    29,    -1,    -1,    32,    33,    -1,    -1,    36,
      37,    -1,    39,    -1,    41,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     4,     5,
      -1,    -1,    59,     9,    10,    11,    -1,    -1,    -1,    66,
      -1,    68,    18,    -1,    20,    21,    -1,    23,    24,    25,
      26,    27,    -1,    29,    -1,    -1,    32,    33,    -1,    -1,
      36,    37,    -1,    39,    -1,    41,    -1,    -1,     4,     5,
      -1,    -1,    -1,     9,    10,    11,    -1,    -1,    -1,    -1,
      -1,    -1,    18,    59,    20,    21,    -1,    -1,    -1,    -1,
      66,    -1,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      36,    37,    -1,    39,    -1,    41,    -1,    -1,     4,     5,
      -1,    -1,    -1,     9,    10,    11,    -1,    -1,    -1,    -1,
      -1,    -1,    18,    59,    20,    21,    -1,    -1,    -1,    -1,
      -1,    -1,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      36,    37,    -1,    39,    -1,    41,    -1,    -1,     4,     5,
      -1,    -1,    -1,     9,    10,    11,    -1,    -1,    -1,    -1,
      -1,    -1,    18,    59,    20,    21,    -1,    -1,    -1,    -1,
      -1,    -1,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      36,    37,    -1,    39,    -1,    41,    -1,    -1,     4,     5,
      -1,    -1,    -1,     9,    10,    11,    -1,    -1,    -1,    -1,
      -1,    -1,    18,    59,    20,    21,    -1,    -1,    -1,    -1,
      -1,    -1,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      36,    37,    -1,    39,    -1,    41,    -1,    -1,     4,     5,
      -1,    -1,    -1,     9,    10,    11,    -1,    -1,    -1,    -1,
      -1,    -1,    18,    59,    20,    21,    -1,    -1,    -1,    -1,
      -1,    -1,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      36,    37,    -1,    39,    -1,    41,    -1,    -1,     4,     5,
      -1,    -1,    -1,     9,    10,    11,    -1,    -1,    -1,    -1,
      33,    34,    18,    59,    20,    21,    39,    40,    -1,    -1,
      66,    44,    -1,    -1,    47,    48,    49,    50,    51,    -1,
      36,    37,    55,    39,    -1,    41,    -1,    -1,    -1,    -1,
      -1,     4,     5,    66,    67,    68,     9,    10,    11,    -1,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,    37,
      -1,    39,    -1,    41,    -1,    -1,    -1,    -1,    -1,     4,
       5,    -1,    -1,    -1,     9,    10,    11,    -1,    -1,    -1,
      -1,    59,    60,    18,    -1,    20,    21,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    36,    37,    -1,    39,    -1,    41,     4,     5,    -1,
      -1,    -1,     9,    10,    11,     4,     5,    -1,    -1,    -1,
       9,    10,    11,    -1,    59,    60,    -1,    -1,    -1,    18,
      -1,    20,    21,    -1,    -1,    -1,    -1,    -1,    -1,    36,
      37,    -1,    39,    -1,    41,    42,    -1,    36,    37,    -1,
      39,    -1,    41,    -1,    -1,    52,    53,    -1,    55,    -1,
      -1,    -1,    59,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      59
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    40,    51,    70,    78,   152,   153,   154,   202,   203,
     214,     0,   154,   203,    38,    31,    45,     4,     4,     4,
      30,    35,    66,   155,   156,   158,    55,   195,   196,    66,
     204,     4,    75,    75,    79,    33,    34,    40,    44,    47,
      48,    49,    50,    51,    66,    68,   130,   159,   160,   161,
     162,   163,   164,   169,   170,   171,   189,   190,   191,   192,
     193,   156,   158,   158,     4,    83,   197,    59,   215,     4,
     206,   208,   210,    52,    57,   157,    55,    80,    85,    52,
     130,   131,    67,   159,     4,     9,    10,    11,    71,    72,
      73,    74,    79,    81,    40,    51,   163,     4,    39,    71,
      83,   172,   174,    40,    44,    51,   170,   194,   195,    40,
      51,   192,   158,    35,    84,    57,   198,    56,    71,   216,
     217,   219,   220,    66,   221,    59,   211,    57,   205,   209,
     210,     4,    75,    58,    72,    74,    86,    88,    89,     4,
       4,     5,     9,    10,    11,    18,    20,    21,    23,    24,
      25,    26,    27,    29,    32,    33,    36,    37,    39,    41,
      59,    67,    68,    74,    75,    76,    77,    79,    81,    92,
      93,    94,    96,    97,   103,   104,   105,   109,   110,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   132,   133,   135,   137,   138,
     139,   140,   141,   142,   152,   182,    53,    82,     4,   165,
     167,   168,    82,    82,   174,    68,   130,   188,     4,   175,
      43,   173,   184,     4,     4,    79,    83,     4,    46,    60,
      57,   218,   160,   222,   223,     4,    96,   105,   106,   107,
     114,   115,   100,   158,    68,   207,   212,   209,   157,    35,
      36,    90,    91,    56,    57,    87,    80,    59,    62,    95,
      75,   103,   104,   127,   127,   127,   114,   114,     4,    68,
      68,   114,    59,    59,    59,    59,    42,    52,    52,    72,
      79,    85,    98,    72,   114,    42,    42,    52,    53,    95,
      36,    37,    41,    80,    97,    95,    42,    42,    42,    52,
      53,    13,    58,    14,    63,    64,    65,    15,    16,    17,
      18,    19,    20,    68,    68,    12,    61,    22,    34,    71,
     134,    54,    53,    82,    68,    57,   166,    61,   175,    59,
     173,    79,   185,   187,    66,   199,   173,    59,   198,     4,
     219,   192,   224,    67,   222,    60,   108,   160,   213,    67,
      74,    74,    88,   106,   135,    52,    53,    62,    68,    68,
      68,    68,   114,    68,   133,   138,   144,   145,   114,   114,
      80,     4,    80,    38,    53,    82,   111,   113,    82,   111,
       4,   101,    60,    60,    80,    80,   114,    52,    42,    52,
       4,    52,    80,    41,    80,     4,    80,    97,   114,   118,
     114,   121,   122,   119,   120,   123,   124,   125,   126,   127,
     114,   114,   165,    54,   167,    66,   114,   147,   151,   173,
      71,   176,   178,    57,   186,    59,    75,    76,    80,    85,
      92,    98,   200,   201,   176,   218,     4,   211,    57,   213,
      87,    60,    38,    54,   114,    60,    68,   114,    62,    57,
     146,    68,    60,    60,     4,     4,   114,   147,    82,   112,
     147,    82,    52,   102,    59,   127,     4,     4,    54,    38,
      80,     4,    80,    59,    38,    41,     4,     4,    54,    62,
     166,   148,   149,   151,     4,    37,   177,   179,   181,   182,
      57,   187,    55,   195,    36,    52,    37,   131,   177,   199,
     114,    68,     4,    27,    29,    32,   135,   136,   137,   143,
      60,   145,    68,   114,   138,    68,   114,   135,   130,    59,
      54,    53,   113,     4,    80,    99,   107,     4,     4,   106,
      59,   116,   205,   150,    52,    60,    57,   180,    71,   186,
      36,    59,   195,    59,    67,    60,    62,    59,    59,    59,
      28,   135,    60,    60,   145,    60,    60,   145,    68,   106,
      60,    59,    60,   106,    67,    57,    37,    82,   181,   168,
      59,    99,    36,    99,   136,   114,    68,   133,   144,   114,
     135,   135,   135,    60,   135,   135,    60,    60,   145,    60,
     100,   106,    60,   151,   180,   182,   183,    99,    60,    59,
      60,    60,    68,   114,    62,    68,    60,   135,   135,   135,
      60,    60,    71,    60,    68,    99,    68,   136,    60,   145,
      68,   114,    68,   114,   136,   135,    46,    68,    60,    28,
     136,    60,    60,   145,    60,    60,   145,    68,     4,    68,
     136,   136,   136,    60,   136,   136,    60,    60,   145,   136,
     136,   136,    60,   136
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    69,    70,    71,    71,    72,    72,    73,    73,    74,
      74,    74,    75,    75,    76,    77,    77,    78,    78,    79,
      79,    80,    80,    81,    81,    81,    82,    82,    83,    83,
      84,    84,    85,    86,    87,    87,    88,    88,    89,    90,
      90,    91,    91,    92,    92,    93,    93,    93,    93,    93,
      93,    93,    93,    93,    93,    94,    94,    94,    94,    94,
      95,    95,    96,    96,    96,    97,    98,    98,    99,    99,
     100,   100,   101,   102,   102,    80,    80,   103,   103,   103,
     104,   104,   105,   105,   105,   105,   105,   105,   106,   106,
      80,    80,   107,   108,   108,   109,   109,   109,   109,   109,
     109,   109,   110,   110,   110,   110,   110,   110,   111,   112,
     112,   113,   114,   115,   115,   115,   116,   116,   117,   117,
     118,   118,   119,   119,   120,   120,   121,   121,   122,   122,
     123,   123,   124,   124,   125,   125,   126,   126,   127,   127,
     127,   127,   127,   128,   129,   129,   129,   130,   131,   131,
     132,   132,   132,   133,   134,   134,   135,   135,   135,   135,
     135,   135,   136,   136,   136,   136,   136,   137,   137,   137,
     137,   137,   137,   137,   137,   137,   138,   138,   138,   139,
     139,   139,   140,   140,   141,   141,   142,   142,   142,   142,
     142,   142,   142,   142,   142,   143,   143,   143,   143,   143,
     143,   143,   143,   143,   144,   144,   145,   146,   146,   147,
     148,   148,   149,   150,   150,   151,   151,   152,   152,   152,
     153,   153,   153,   153,   154,   154,   155,   156,   157,   157,
     158,   159,   159,   160,   160,   160,   160,   161,   161,   161,
     162,   163,   163,   164,   164,   165,   166,   166,   167,   167,
     168,   168,   169,   170,   170,   171,   171,   171,   171,   171,
     171,   171,   171,   171,   172,   172,   173,   173,   174,   174,
     175,   175,   176,   176,   177,   177,   178,   178,   179,   180,
     180,   181,   182,   182,   183,   184,   185,   186,   186,   187,
     188,   188,   189,   190,   191,   192,   192,   193,   193,   194,
     195,   195,   196,   197,   198,   198,   199,   200,   200,   201,
     201,   201,   201,   202,   203,   203,   204,   205,   205,   206,
     206,   207,   207,   208,   209,   209,   210,   211,   211,   212,
     213,   213,   214,   215,   216,   216,   217,   218,   218,   219,
     219,   220,   221,   222,   222,   223,   224
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     1,     2,     1,     1,     1,     1,     2,
       4,     1,     0,     2,     2,     2,     2,     3,     2,     1,
       2,     2,     3,     2,     3,     0,     1,     1,     2,     1,
       0,     2,     2,     1,     1,     1,     1,     1,     2,     3,
       1,     1,     1,     1,     1,     0,     4,     4,     4,     3,
       3,     0,     1,     2,     3,     7,     1,     0,     1,     0,
       1,     0,     3,     2,     0,     1,     0,     3,     3,     4,
       4,     4,     4,     6,     6,     7,     7,     8,     1,     0,
       1,     0,     2,     3,     0,     4,     4,     4,     4,     5,
       4,     3,     4,     3,     4,     3,     4,     4,     2,     2,
       0,     3,     1,     1,     3,     3,     1,     5,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     2,     2,
       1,     2,     1,     4,     1,     1,     2,     3,     2,     0,
       1,     2,     1,     3,     1,     1,     1,     3,     5,     7,
       5,     1,     1,     3,     7,     5,     1,     1,     1,     2,
       1,     1,     2,     3,     3,     5,     1,     1,     1,     1,
       1,     1,     3,     5,     3,     2,     6,     7,     7,     7,
       8,     8,     8,     9,     7,     6,     7,     7,     7,     8,
       8,     8,     9,     7,     1,     1,     2,     2,     0,     4,
       1,     0,     2,     3,     0,     1,     1,     1,     1,     1,
       4,     5,     5,     6,     2,     0,     2,     3,     3,     0,
       3,     2,     0,     1,     1,     1,     1,     1,     1,     1,
       4,     2,     0,     1,     1,     2,     3,     0,     3,     1,
       2,     1,     3,     2,     0,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     4,     2,     0,     1,     1,
       6,     5,     2,     0,     1,     0,     4,     2,     2,     3,
       0,     4,     2,     0,     4,     2,     2,     3,     0,     1,
       1,     1,     1,     2,     4,     2,     0,     1,     1,     6,
       1,     0,     3,     2,     3,     2,     4,     1,     0,     6,
       6,     7,     8,     4,     2,     0,     5,     1,     0,     1,
       0,     1,     0,     2,     2,     0,     3,     4,     0,     2,
       2,     0,     6,     3,     1,     0,     2,     3,     0,     2,
       1,     3,     3,     2,     0,     2,     3
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
#line 2163 "parser.tab.c"
    break;


#line 2167 "parser.tab.c"

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

#line 800 "parser.y"


int main(){
    if(yyparse()) return 0;
    
    return 0;
}
