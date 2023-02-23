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
  YYSYMBOL_61_ = 61,                       /* ':'  */
  YYSYMBOL_62_ = 62,                       /* '&'  */
  YYSYMBOL_63_ = 63,                       /* '^'  */
  YYSYMBOL_64_ = 64,                       /* '|'  */
  YYSYMBOL_65_ = 65,                       /* '{'  */
  YYSYMBOL_66_ = 66,                       /* '}'  */
  YYSYMBOL_67_ = 67,                       /* ';'  */
  YYSYMBOL_68_transient_ = 68,             /* "transient"  */
  YYSYMBOL_69_volatile_ = 69,              /* "volatile"  */
  YYSYMBOL_70_ = 70,                       /* "="  */
  YYSYMBOL_YYACCEPT = 71,                  /* $accept  */
  YYSYMBOL_prog = 72,                      /* prog  */
  YYSYMBOL_Type = 73,                      /* Type  */
  YYSYMBOL_PrimitiveType = 74,             /* PrimitiveType  */
  YYSYMBOL_numerictype = 75,               /* numerictype  */
  YYSYMBOL_ReferenceType = 76,             /* ReferenceType  */
  YYSYMBOL_PackageName = 77,               /* PackageName  */
  YYSYMBOL_TypeName = 78,                  /* TypeName  */
  YYSYMBOL_ExpressionName = 79,            /* ExpressionName  */
  YYSYMBOL_PackageorTypeName = 80,         /* PackageorTypeName  */
  YYSYMBOL_NumericType = 81,               /* NumericType  */
  YYSYMBOL_MethodName = 82,                /* MethodName  */
  YYSYMBOL_ClassModifier = 83,             /* ClassModifier  */
  YYSYMBOL_ClassType = 84,                 /* ClassType  */
  YYSYMBOL_Zeroorone_TypeArguments = 85,   /* Zeroorone_TypeArguments  */
  YYSYMBOL_ArrayType = 86,                 /* ArrayType  */
  YYSYMBOL_Dims = 87,                      /* Dims  */
  YYSYMBOL_TypeParameter = 88,             /* TypeParameter  */
  YYSYMBOL_Zeroorone_TypeBound = 89,       /* Zeroorone_TypeBound  */
  YYSYMBOL_TypeBound = 90,                 /* TypeBound  */
  YYSYMBOL_TypeArguments = 91,             /* TypeArguments  */
  YYSYMBOL_TypeArgumentList = 92,          /* TypeArgumentList  */
  YYSYMBOL_cTypeArgument = 93,             /* cTypeArgument  */
  YYSYMBOL_TypeArgument = 94,              /* TypeArgument  */
  YYSYMBOL_Wildcard = 95,                  /* Wildcard  */
  YYSYMBOL_zerooroneWildcardBounds = 96,   /* zerooroneWildcardBounds  */
  YYSYMBOL_WildcardBounds = 97,            /* WildcardBounds  */
  YYSYMBOL_Primary = 98,                   /* Primary  */
  YYSYMBOL_PrimaryNoNewArray = 99,         /* PrimaryNoNewArray  */
  YYSYMBOL_ClassLiteral = 100,             /* ClassLiteral  */
  YYSYMBOL_Zero_or_moreSquarebracket = 101, /* Zero_or_moreSquarebracket  */
  YYSYMBOL_ClassInstanceCreationExpression = 102, /* ClassInstanceCreationExpression  */
  YYSYMBOL_UnqualifiedClassInstanceCreationExpression = 103, /* UnqualifiedClassInstanceCreationExpression  */
  YYSYMBOL_ZerooroneTypeArguments = 104,   /* ZerooroneTypeArguments  */
  YYSYMBOL_ZerooroneArgumentList = 105,    /* ZerooroneArgumentList  */
  YYSYMBOL_ZerooroneClassBody = 106,       /* ZerooroneClassBody  */
  YYSYMBOL_ClassOrInterfaceTypeToInstantiate = 107, /* ClassOrInterfaceTypeToInstantiate  */
  YYSYMBOL_Zeroormore_DotIdentifier = 108, /* Zeroormore_DotIdentifier  */
  YYSYMBOL_FieldAccess = 109,              /* FieldAccess  */
  YYSYMBOL_ArrayAccess = 110,              /* ArrayAccess  */
  YYSYMBOL_MethodInvocation = 111,         /* MethodInvocation  */
  YYSYMBOL_Zeroorone_ArgumentList = 112,   /* Zeroorone_ArgumentList  */
  YYSYMBOL_ArgumentList = 113,             /* ArgumentList  */
  YYSYMBOL_Zeroormore_CommaExpression = 114, /* Zeroormore_CommaExpression  */
  YYSYMBOL_MethodReference = 115,          /* MethodReference  */
  YYSYMBOL_ArrayCreationExpression = 116,  /* ArrayCreationExpression  */
  YYSYMBOL_Zeroorone_Dims = 117,           /* Zeroorone_Dims  */
  YYSYMBOL_DimExprs = 118,                 /* DimExprs  */
  YYSYMBOL_Zeroormore_DimExpr = 119,       /* Zeroormore_DimExpr  */
  YYSYMBOL_DimExpr = 120,                  /* DimExpr  */
  YYSYMBOL_Expression = 121,               /* Expression  */
  YYSYMBOL_AssignmentExpression = 122,     /* AssignmentExpression  */
  YYSYMBOL_AmbigiousName = 123,            /* AmbigiousName  */
  YYSYMBOL_ConditionalExpression = 124,    /* ConditionalExpression  */
  YYSYMBOL_ConditionalOrExpression = 125,  /* ConditionalOrExpression  */
  YYSYMBOL_ConditionalAndExpression = 126, /* ConditionalAndExpression  */
  YYSYMBOL_AndExpression = 127,            /* AndExpression  */
  YYSYMBOL_ExclusiveOrExpression = 128,    /* ExclusiveOrExpression  */
  YYSYMBOL_InclusiveOrExpression = 129,    /* InclusiveOrExpression  */
  YYSYMBOL_EqualityExpression = 130,       /* EqualityExpression  */
  YYSYMBOL_RelationalExpression = 131,     /* RelationalExpression  */
  YYSYMBOL_ShiftExpression = 132,          /* ShiftExpression  */
  YYSYMBOL_AdditiveExpression = 133,       /* AdditiveExpression  */
  YYSYMBOL_MultiplicativeExpression = 134, /* MultiplicativeExpression  */
  YYSYMBOL_UnaryExpression = 135,          /* UnaryExpression  */
  YYSYMBOL_CastExpression = 136,           /* CastExpression  */
  YYSYMBOL_PostfixExpression = 137,        /* PostfixExpression  */
  YYSYMBOL_Block = 138,                    /* Block  */
  YYSYMBOL_BlockStatements = 139,          /* BlockStatements  */
  YYSYMBOL_BlockStatement = 140,           /* BlockStatement  */
  YYSYMBOL_VariableModifier = 141,         /* VariableModifier  */
  YYSYMBOL_LocalVariableDeclaration = 142, /* LocalVariableDeclaration  */
  YYSYMBOL_LocalVariableType = 143,        /* LocalVariableType  */
  YYSYMBOL_Statement = 144,                /* Statement  */
  YYSYMBOL_StatementNoShortIf = 145,       /* StatementNoShortIf  */
  YYSYMBOL_StatementWithoutTrailingSubstatement = 146, /* StatementWithoutTrailingSubstatement  */
  YYSYMBOL_StatementExpression = 147,      /* StatementExpression  */
  YYSYMBOL_LeftHandSide = 148,             /* LeftHandSide  */
  YYSYMBOL_AssertStatement = 149,          /* AssertStatement  */
  YYSYMBOL_BreakContinueStatement = 150,   /* BreakContinueStatement  */
  YYSYMBOL_ForStatement = 151,             /* ForStatement  */
  YYSYMBOL_ForStatementNoShortIf = 152,    /* ForStatementNoShortIf  */
  YYSYMBOL_ForInit = 153,                  /* ForInit  */
  YYSYMBOL_StatementExpressionList = 154,  /* StatementExpressionList  */
  YYSYMBOL_StatementExpressionMore = 155,  /* StatementExpressionMore  */
  YYSYMBOL_ArrayInitializer = 156,         /* ArrayInitializer  */
  YYSYMBOL_zerooroneVariableInitializerList = 157, /* zerooroneVariableInitializerList  */
  YYSYMBOL_VariableInitializerList = 158,  /* VariableInitializerList  */
  YYSYMBOL_cVariableInitializer = 159,     /* cVariableInitializer  */
  YYSYMBOL_VariableInitializer = 160,      /* VariableInitializer  */
  YYSYMBOL_ClassDeclaration = 161,         /* ClassDeclaration  */
  YYSYMBOL_NormalClassDeclaration = 162,   /* NormalClassDeclaration  */
  YYSYMBOL_ClassModifiers = 163,           /* ClassModifiers  */
  YYSYMBOL_ClassExtends = 164,             /* ClassExtends  */
  YYSYMBOL_ClassPermits = 165,             /* ClassPermits  */
  YYSYMBOL_cTypeName = 166,                /* cTypeName  */
  YYSYMBOL_ClassBody = 167,                /* ClassBody  */
  YYSYMBOL_ClassBodyDeclarations = 168,    /* ClassBodyDeclarations  */
  YYSYMBOL_ClassBodyDeclaration = 169,     /* ClassBodyDeclaration  */
  YYSYMBOL_ClassMemberDeclaration = 170,   /* ClassMemberDeclaration  */
  YYSYMBOL_FieldDeclaration = 171,         /* FieldDeclaration  */
  YYSYMBOL_FieldModifiers = 172,           /* FieldModifiers  */
  YYSYMBOL_FieldModifier = 173,            /* FieldModifier  */
  YYSYMBOL_VariableDeclaratorList = 174,   /* VariableDeclaratorList  */
  YYSYMBOL_cVariableDeclarator = 175,      /* cVariableDeclarator  */
  YYSYMBOL_VariableDeclarator = 176,       /* VariableDeclarator  */
  YYSYMBOL_VariableInitializer_eq = 177,   /* VariableInitializer_eq  */
  YYSYMBOL_VariableDeclaratorId = 178,     /* VariableDeclaratorId  */
  YYSYMBOL_MethodDeclaration = 179,        /* MethodDeclaration  */
  YYSYMBOL_Methodmodifiers = 180,          /* Methodmodifiers  */
  YYSYMBOL_Methodmodifier = 181,           /* Methodmodifier  */
  YYSYMBOL_Methodheader = 182,             /* Methodheader  */
  YYSYMBOL_Throws_s = 183,                 /* Throws_s  */
  YYSYMBOL_Result = 184,                   /* Result  */
  YYSYMBOL_Methodeclarator = 185,          /* Methodeclarator  */
  YYSYMBOL_Dims_s = 186,                   /* Dims_s  */
  YYSYMBOL_recieveparameters = 187,        /* recieveparameters  */
  YYSYMBOL_formalparameters = 188,         /* formalparameters  */
  YYSYMBOL_recieveparameter = 189,         /* recieveparameter  */
  YYSYMBOL_identifier_dot = 190,           /* identifier_dot  */
  YYSYMBOL_formalparameterlist = 191,      /* formalparameterlist  */
  YYSYMBOL_cformalparameter = 192,         /* cformalparameter  */
  YYSYMBOL_formalparameter = 193,          /* formalparameter  */
  YYSYMBOL_Variablemodifiers = 194,        /* Variablemodifiers  */
  YYSYMBOL_VariableArityParameter = 195,   /* VariableArityParameter  */
  YYSYMBOL_Throws = 196,                   /* Throws  */
  YYSYMBOL_ExceptionTypeList = 197,        /* ExceptionTypeList  */
  YYSYMBOL_cExceptionType = 198,           /* cExceptionType  */
  YYSYMBOL_ExceptionType = 199,            /* ExceptionType  */
  YYSYMBOL_MethodBody = 200,               /* MethodBody  */
  YYSYMBOL_InstanceInitializer = 201,      /* InstanceInitializer  */
  YYSYMBOL_StaticInitializer = 202,        /* StaticInitializer  */
  YYSYMBOL_ConstructorDeclaration = 203,   /* ConstructorDeclaration  */
  YYSYMBOL_zeroormore_ConstructorModifier = 204, /* zeroormore_ConstructorModifier  */
  YYSYMBOL_ConstructorModifier = 205,      /* ConstructorModifier  */
  YYSYMBOL_ConstructorDeclarator = 206,    /* ConstructorDeclarator  */
  YYSYMBOL_zeroorone_TypeParameters = 207, /* zeroorone_TypeParameters  */
  YYSYMBOL_TypeParameters = 208,           /* TypeParameters  */
  YYSYMBOL_TypeParamerList = 209,          /* TypeParamerList  */
  YYSYMBOL_TypeParameterc = 210,           /* TypeParameterc  */
  YYSYMBOL_ConstructorBody = 211,          /* ConstructorBody  */
  YYSYMBOL_zerooroneBlockStatements = 212, /* zerooroneBlockStatements  */
  YYSYMBOL_zerooroneExplicitConstructorInvocation = 213, /* zerooroneExplicitConstructorInvocation  */
  YYSYMBOL_ExplicitConstructorInvocation = 214, /* ExplicitConstructorInvocation  */
  YYSYMBOL_EnumDeclaration = 215,          /* EnumDeclaration  */
  YYSYMBOL_zeroormoreClassModifier = 216,  /* zeroormoreClassModifier  */
  YYSYMBOL_EnumBody = 217,                 /* EnumBody  */
  YYSYMBOL_zerooronecomma = 218,           /* zerooronecomma  */
  YYSYMBOL_zerooroneEnumConstantList = 219, /* zerooroneEnumConstantList  */
  YYSYMBOL_zerooroneEnumBodyDeclarations = 220, /* zerooroneEnumBodyDeclarations  */
  YYSYMBOL_EnumConstantList = 221,         /* EnumConstantList  */
  YYSYMBOL_cEnumConstant = 222,            /* cEnumConstant  */
  YYSYMBOL_EnumConstant = 223,             /* EnumConstant  */
  YYSYMBOL_bracketZeroorone_ArgumentList = 224, /* bracketZeroorone_ArgumentList  */
  YYSYMBOL_EnumBodyDeclarations = 225,     /* EnumBodyDeclarations  */
  YYSYMBOL_zeroormoreClassBodyDeclaration = 226, /* zeroormoreClassBodyDeclaration  */
  YYSYMBOL_RecordDeclaration = 227,        /* RecordDeclaration  */
  YYSYMBOL_RecordHeader = 228,             /* RecordHeader  */
  YYSYMBOL_zerooroneRecordComponentList = 229, /* zerooroneRecordComponentList  */
  YYSYMBOL_RecordComponentList = 230,      /* RecordComponentList  */
  YYSYMBOL_cRecordComponent = 231,         /* cRecordComponent  */
  YYSYMBOL_RecordComponent = 232,          /* RecordComponent  */
  YYSYMBOL_VariableArityRecordComponent = 233, /* VariableArityRecordComponent  */
  YYSYMBOL_RecordBody = 234,               /* RecordBody  */
  YYSYMBOL_zeroormoreRecordBodyDeclaration = 235, /* zeroormoreRecordBodyDeclaration  */
  YYSYMBOL_RecordBodyDeclaration = 236,    /* RecordBodyDeclaration  */
  YYSYMBOL_CompactConstructorDeclaration = 237 /* CompactConstructorDeclaration  */
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
#define YYFINAL  18
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   2039

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  71
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  167
/* YYNRULES -- Number of rules.  */
#define YYNRULES  377
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  703

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   309


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
       2,     2,     2,     2,     2,     2,     2,     2,    62,     2,
      59,    60,     2,     2,    57,     2,    52,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    61,    67,
      55,     2,    56,    58,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    53,     2,    54,    63,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    65,    64,    66,     2,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50,    51,    68,    69,    70
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    22,    22,    27,    28,    32,    33,    37,    38,    45,
      46,    47,    53,    54,    57,    58,    61,    62,    65,    66,
      69,    70,    74,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    81,    82,    83,    87,    87,    91,    92,    93,
      96,    97,   100,   103,   104,   107,   108,   111,   114,   117,
     118,   121,   122,   125,   128,   129,   132,   133,   139,   140,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     158,   159,   160,   161,   162,   166,   167,   171,   172,   173,
     178,   182,   182,   186,   186,   190,   190,   195,   199,   199,
     203,   203,   208,   209,   210,   215,   216,   221,   222,   223,
     224,   225,   226,   230,   230,   234,   234,   239,   243,   244,
     249,   250,   251,   252,   253,   254,   255,   260,   261,   262,
     263,   267,   267,   271,   275,   275,   279,   283,   287,   288,
     292,   293,   297,   298,   302,   303,   307,   308,   312,   313,
     317,   318,   322,   323,   327,   328,   332,   333,   337,   338,
     342,   343,   347,   348,   352,   353,   357,   358,   359,   360,
     361,   365,   369,   370,   371,   379,   383,   383,   387,   388,
     389,   393,   393,   397,   401,   402,   406,   407,   408,   409,
     410,   411,   415,   416,   417,   418,   419,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   435,   436,   437,   438,
     439,   443,   444,   445,   449,   450,   454,   455,   459,   460,
     461,   462,   463,   464,   465,   466,   467,   471,   472,   473,
     474,   475,   476,   477,   478,   479,   483,   484,   487,   491,
     491,   498,   501,   502,   505,   509,   510,   514,   515,   521,
     522,   523,   526,   527,   528,   529,   532,   533,   536,   539,
     543,   543,   547,   550,   551,   554,   555,   556,   557,   560,
     561,   562,   566,   569,   570,   573,   573,   573,   573,   573,
     574,   575,   578,   581,   582,   585,   588,   589,   592,   597,
     601,   602,   606,   606,   606,   606,   606,   606,   606,   606,
     606,   610,   611,   615,   616,   620,   621,   625,   629,   630,
     633,   634,   637,   638,   642,   645,   646,   649,   652,   652,
     655,   658,   658,   661,   664,   667,   670,   673,   674,   677,
     678,   681,   682,   685,   688,   691,   694,   695,   698,   698,
     698,   701,   704,   705,   708,   711,   714,   715,   719,   722,
     723,   726,   727,   730,   736,   739,   740,   743,   746,   747,
     750,   751,   754,   755,   758,   761,   762,   765,   768,   769,
     772,   775,   776,   779,   782,   785,   786,   789,   792,   793,
     796,   797,   800,   803,   806,   807,   810,   814
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
  "'['", "']'", "'<'", "'>'", "','", "'?'", "'('", "')'", "':'", "'&'",
  "'^'", "'|'", "'{'", "'}'", "';'", "\"transient\"", "\"volatile\"",
  "\"=\"", "$accept", "prog", "Type", "PrimitiveType", "numerictype",
  "ReferenceType", "PackageName", "TypeName", "ExpressionName",
  "PackageorTypeName", "NumericType", "MethodName", "ClassModifier",
  "ClassType", "Zeroorone_TypeArguments", "ArrayType", "Dims",
  "TypeParameter", "Zeroorone_TypeBound", "TypeBound", "TypeArguments",
  "TypeArgumentList", "cTypeArgument", "TypeArgument", "Wildcard",
  "zerooroneWildcardBounds", "WildcardBounds", "Primary",
  "PrimaryNoNewArray", "ClassLiteral", "Zero_or_moreSquarebracket",
  "ClassInstanceCreationExpression",
  "UnqualifiedClassInstanceCreationExpression", "ZerooroneTypeArguments",
  "ZerooroneArgumentList", "ZerooroneClassBody",
  "ClassOrInterfaceTypeToInstantiate", "Zeroormore_DotIdentifier",
  "FieldAccess", "ArrayAccess", "MethodInvocation",
  "Zeroorone_ArgumentList", "ArgumentList", "Zeroormore_CommaExpression",
  "MethodReference", "ArrayCreationExpression", "Zeroorone_Dims",
  "DimExprs", "Zeroormore_DimExpr", "DimExpr", "Expression",
  "AssignmentExpression", "AmbigiousName", "ConditionalExpression",
  "ConditionalOrExpression", "ConditionalAndExpression", "AndExpression",
  "ExclusiveOrExpression", "InclusiveOrExpression", "EqualityExpression",
  "RelationalExpression", "ShiftExpression", "AdditiveExpression",
  "MultiplicativeExpression", "UnaryExpression", "CastExpression",
  "PostfixExpression", "Block", "BlockStatements", "BlockStatement",
  "VariableModifier", "LocalVariableDeclaration", "LocalVariableType",
  "Statement", "StatementNoShortIf",
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
  "cVariableDeclarator", "VariableDeclarator", "VariableInitializer_eq",
  "VariableDeclaratorId", "MethodDeclaration", "Methodmodifiers",
  "Methodmodifier", "Methodheader", "Throws_s", "Result",
  "Methodeclarator", "Dims_s", "recieveparameters", "formalparameters",
  "recieveparameter", "identifier_dot", "formalparameterlist",
  "cformalparameter", "formalparameter", "Variablemodifiers",
  "VariableArityParameter", "Throws", "ExceptionTypeList",
  "cExceptionType", "ExceptionType", "MethodBody", "InstanceInitializer",
  "StaticInitializer", "ConstructorDeclaration",
  "zeroormore_ConstructorModifier", "ConstructorModifier",
  "ConstructorDeclarator", "zeroorone_TypeParameters", "TypeParameters",
  "TypeParamerList", "TypeParameterc", "ConstructorBody",
  "zerooroneBlockStatements", "zerooroneExplicitConstructorInvocation",
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

#define YYPACT_NINF (-547)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-376)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     892,  -547,  -547,  -547,  -547,  -547,  -547,  -547,  -547,  -547,
      86,   892,  -547,  -547,    -7,  -547,   113,  -547,  -547,  -547,
    -547,    67,   106,   151,   136,   109,   103,   212,   218,  1892,
      57,   137,  -547,   244,   228,  -547,   292,  -547,   246,   248,
     261,   120,   266,   282,   369,   381,    38,    58,   425,   451,
     471,   281,   355,  -547,  -547,  -547,  -547,   268,   275,  1892,
    -547,  -547,   488,   303,  -547,   509,  1072,  -547,  -547,  -547,
     109,   213,   137,  -547,  -547,   307,   287,   289,   488,   286,
     296,   311,  -547,   292,   212,  -547,   342,    47,  -547,  -547,
     365,   371,  -547,  1131,  -547,  -547,  -547,   190,  -547,  -547,
    -547,   372,   328,  -547,  -547,    94,  -547,  -547,  -547,  -547,
    -547,  -547,  -547,   305,  -547,  -547,   545,    37,   380,  -547,
    -547,  -547,  -547,  -547,  -547,  -547,  -547,  -547,  -547,   344,
     385,  -547,  -547,  -547,  -547,  -547,   391,  -547,  -547,   244,
    -547,  -547,    97,   336,  -547,   340,  -547,  1931,  -547,  1839,
     137,  -547,   331,  -547,   292,   248,  -547,   198,   328,  -547,
     345,   347,  -547,   186,   352,   617,  -547,   357,   359,   360,
    1839,  1839,  1839,  1839,  1839,    31,  1030,   366,   367,   373,
     379,   593,   125,  -547,   362,   121,  1839,  -547,  -547,   386,
     387,   179,  -547,   383,   247,   401,   138,   392,  -547,  -547,
    -547,   434,   435,  -547,  -547,  -547,  -547,   396,  -547,    60,
     452,   406,   409,   412,   462,   463,   466,   468,   475,  -547,
    -547,   480,  -547,  -547,   643,   428,  -547,  -547,   438,   489,
    -547,  -547,  -547,  -547,   461,   464,   328,   449,   467,   453,
     464,   464,   380,  -547,  -547,  -547,   474,   344,   522,   465,
     344,   476,   120,   282,   287,  -547,   530,  -547,   488,  -547,
     213,   472,  1931,   207,  1839,  -547,  -547,   477,  -547,  -547,
    -547,   523,  -547,  -547,  1970,   479,  -547,  -547,  -547,   488,
     488,  -547,  -547,  -547,    47,  -547,  -547,  -547,  1284,   231,
     262,  -547,  -547,  -547,  -547,  -547,    22,   483,   484,  -547,
    -547,   491,  1839,   724,  1839,  1839,   352,    36,   508,   494,
     249,  -547,   556,    96,   503,   352,   104,   258,   352,   110,
    1839,   279,  1839,   352,   526,   352,    35,  1839,   560,  1839,
    1839,  1839,  1839,  1839,  1839,  1839,  1839,  1839,  1839,  1839,
    -547,  -547,  -547,  -547,   372,  -547,  -547,  1839,  -547,   515,
     464,  -547,  -547,   372,  -547,  1839,  -547,   344,   488,  -547,
     120,   282,  -547,   517,     9,  -547,  -547,   488,  -547,  -547,
     340,   568,  -547,  -547,  -547,  -547,   296,   524,  -547,  1970,
    -547,  -547,  -547,  -547,   347,   379,  -547,   548,   534,  1839,
    -547,  -547,  -547,  -547,   536,  -547,  1196,   529,   542,   533,
    -547,   547,   549,   604,  -547,   609,  -547,   601,  1815,   328,
    -547,  1815,   328,   562,   559,  1839,  -547,   616,   157,  -547,
     619,   587,   625,   352,   635,  -547,   589,   608,   590,   615,
    -547,   645,  -547,   653,  -547,   610,  -547,   452,   602,   412,
     462,   406,   409,   463,   466,   468,   475,  -547,  -547,  -547,
    -547,   467,  -547,  -547,   311,  -547,   614,  -547,   662,    40,
     623,   522,  -547,   630,  -547,  -547,    40,  -547,   465,  -547,
    1839,  -547,  -547,  -547,  -547,   606,  1343,  1471,   618,  1839,
    1879,  -547,  1383,  1284,   621,  -547,   628,   637,  -547,   614,
     464,  -547,   629,  -547,  -547,   680,   352,  1839,  -547,  -547,
     352,    66,   634,  -547,  -547,   636,  -547,  -547,  -547,  -547,
    -547,   638,  -547,  1839,  -547,  -547,  1839,  -547,   642,   652,
     664,   640,  -547,   646,   488,  -547,   517,   647,  1220,   648,
     649,  -547,  -547,  -547,   727,   659,   660,   661,  -547,   683,
     693,  -547,  1284,   665,  1514,   666,  -547,  1557,   641,  -547,
    -547,  1839,  -547,  1839,  -547,  -547,  -547,   670,  -547,   718,
    -547,   720,  1839,  1839,  1839,  -547,   614,  -547,  -547,  -547,
    -547,   328,   697,  -547,   372,  -547,  1839,  -547,  -547,  1343,
    1839,   846,  1839,  1284,  -547,  1284,  1284,   672,  1284,  1284,
     676,  1600,   677,   137,  -547,   679,   681,   688,   690,  -547,
    -547,   646,   697,   692,  -547,   695,  1407,   678,   673,   702,
    -547,  -547,  -547,  1284,  -547,  -547,  1284,  1284,   704,  -547,
    -547,  1839,  -547,  -547,  -547,  -547,   488,  -547,   701,  1343,
    1643,   705,  1839,  1447,  1343,  -547,  -547,  -547,  1284,   711,
     728,   352,   715,  1343,   716,  1686,   717,  1729,   708,  -547,
    -547,  -547,   774,   751,  1343,  -547,  1343,  1343,   729,  1343,
    1343,   730,  1772,  -547,   733,  -547,  -547,  -547,  1343,  -547,
    -547,  1343,  1343,   734,  1839,  -547,  -547,  -547,  1343,   735,
    -547,   726,   792,  -547,   747,   109,   764,   742,  1839,   743,
     737,   448,  1839,   262,   162,    95,    71,   769,   748,  1839,
     749,   741,  -547
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
     346,    29,    28,    23,    27,    26,    30,    31,    24,    25,
       0,   346,     2,   239,     0,   240,     0,   241,     1,   246,
     345,     0,     0,     0,     0,   333,     0,     0,     0,   264,
       0,     0,   242,     0,     0,   332,   351,   344,    14,   251,
       0,    36,     0,   248,    29,    28,    23,    27,    26,    30,
      31,    24,    25,   167,   270,   271,   323,     0,     0,   264,
     255,   259,     0,   264,   260,     0,   281,   256,   257,   258,
     333,   327,     0,   243,   244,    44,     0,     0,   366,     0,
     359,   349,   350,   356,     0,   249,     0,     0,    32,    35,
       0,     0,   324,    70,   261,   252,   253,    10,     7,     8,
       6,     0,     3,     5,     4,     9,    11,   269,   265,   268,
     266,   267,   263,    44,   296,   295,     0,     0,     0,   288,
     287,   282,   286,   285,   289,   290,   283,   284,   280,   294,
       0,   328,   329,   330,   326,   245,     0,    42,    43,     0,
     335,   334,     0,     0,   365,   369,   371,   264,   363,    70,
      86,   348,   353,   354,   356,   251,    15,    55,     0,    51,
       0,    50,    52,    36,    36,    16,    60,     7,     8,     6,
      70,    70,    70,    70,    70,     0,    70,     0,     0,     0,
      29,    28,     0,    62,     0,     0,    70,   165,   188,     0,
      76,   163,    76,     0,     0,     0,   162,    58,    61,    65,
      77,    66,    67,    68,    69,    59,   196,    17,   128,   134,
     136,   142,   144,   138,   140,   146,   148,   150,   152,   154,
     160,   158,   187,   166,     0,     0,   170,   176,     0,     0,
     190,   191,   181,   168,     0,    39,   299,     0,   274,   277,
      37,    38,     0,   322,   321,   279,     0,   294,     0,     0,
     294,     0,    36,    46,   337,   370,     0,   364,     0,   367,
     327,     0,   264,    16,    70,    65,    68,     0,   103,   109,
     127,   158,   357,    85,   264,     0,   352,   355,   250,     0,
       0,    53,    54,    47,     0,    48,    33,    34,    70,     0,
     163,    66,    67,   157,   156,   159,     0,     0,     0,   207,
     192,     0,    70,    70,    70,    70,    36,     0,     0,     0,
       0,    81,     0,     0,     0,    36,    36,     0,    36,    36,
      70,     0,    70,    36,     0,    36,     0,    70,     0,    70,
      70,    70,    70,    70,    70,    70,    70,    70,    70,    70,
     164,   175,   171,   174,     0,   169,   189,    70,    40,     0,
     298,   278,   262,     0,   272,    70,   275,   294,   301,   291,
      36,   319,   315,   318,   342,   325,   293,   301,   336,   372,
     369,     0,   376,   373,   374,   156,   359,   107,   164,   264,
     360,   347,    56,    57,    50,     0,   177,     0,     0,    70,
     204,   194,   206,   193,     0,   313,    70,   227,   230,     0,
     226,     0,     0,     0,    93,     0,    74,    70,    70,   122,
     125,    70,   122,    89,     0,    70,    64,     0,     0,    63,
       0,     0,     0,    82,     0,    78,     0,     0,     0,     0,
     116,     0,    92,     0,    79,     0,   130,   137,     0,   139,
     141,   143,   145,   147,   149,   151,   153,   155,   173,   129,
      41,   274,   237,   238,   349,   232,   236,   292,   306,   172,
       0,     0,   316,     0,   167,   341,   172,   368,     0,   358,
      70,   361,    49,    73,    75,     0,    70,    70,     0,    70,
      70,   228,    70,    70,     0,   113,     0,     0,   119,   236,
     121,   117,   123,   120,   118,     0,    36,    70,   161,   112,
      36,     0,     0,    71,   110,     0,    95,    72,    97,   115,
     111,     0,    96,    70,   273,   231,    70,   234,     0,     0,
     172,     0,   302,   309,     0,   300,   318,     0,    70,     0,
       0,   377,   108,   205,    16,     0,     0,     0,   178,     0,
     176,   186,    70,     0,    70,     0,   229,    70,     0,   180,
     195,    70,   126,    70,   124,    88,    87,     0,    83,     0,
      94,     0,    70,    70,    70,   135,   236,   305,   304,   171,
     311,   299,   172,   307,     0,   317,    70,   338,   331,    70,
      70,    70,    70,    70,   208,    70,    70,     0,    70,    70,
       0,    70,     0,    86,   114,     0,     0,     0,     0,   234,
     297,   309,   172,     0,   183,     0,    70,   227,     0,     0,
     179,   211,   210,    70,   216,   209,    70,    70,     0,   101,
      80,    70,    98,    99,   100,   308,     0,   310,     0,    70,
      70,     0,    70,    70,    70,   212,   214,   213,    70,     0,
       0,    36,     0,    70,     0,    70,     0,    70,     0,   185,
     215,   102,     0,     0,    70,   217,    70,    70,     0,    70,
      70,     0,    70,   314,     0,   184,   220,   219,    70,   225,
     218,    70,    70,     0,    70,   221,   223,   222,    70,     0,
     224,     0,     0,    16,     0,   333,     0,     0,    70,     0,
       0,    70,    70,     0,     0,   333,     0,     0,     0,    70,
       0,     0,   343
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -547,  -547,   -50,   -51,  -547,   -61,  -547,    25,  -150,  -547,
    -547,  -547,  -547,   -28,   -79,   -55,   -42,   -36,  -547,  -547,
    -166,  -547,   426,   528,  -547,  -547,  -547,   123,  -547,  -547,
     -73,   -77,  -313,   455,  -546,   223,  -547,  -547,   -59,   -10,
      45,  -269,  -482,  -547,  -547,  -547,   405,   510,  -547,   329,
     668,   168,  -547,   310,  -547,   497,   496,   499,   500,   506,
     512,   507,   498,   511,  -127,  -547,   290,     7,   384,  -547,
     -88,  -295,  -547,   439,   348,  -241,  -103,  -547,  -547,  -547,
    -547,  -547,   264,  -452,  -547,  -153,  -547,  -547,   293,  -346,
       3,  -547,   841,  -547,   823,   703,    48,   801,  -129,  -547,
    -547,   798,  -547,   518,   414,   519,  -547,   300,  -547,   797,
    -547,  -547,  -209,   754,   644,   306,   521,   418,  -547,  -547,
    -547,   288,   318,  -487,  -547,  -547,  -547,   368,   430,  -547,
    -547,  -547,  -547,   -47,  -547,  -547,   -68,  -547,  -547,   639,
     424,  -547,  -547,  -547,  -547,   884,  -547,   442,  -547,  -547,
    -547,   744,   861,   525,  -547,   520,  -547,  -547,  -547,  -547,
     532,   650,  -547,  -547,   654,  -547,  -547
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    10,   115,   158,   103,   189,    42,   190,   191,    40,
     192,   193,    11,   194,    88,   195,   235,    76,   137,   138,
      89,   160,   285,   161,   162,   281,   282,   196,   197,   198,
     289,   265,   200,   312,   557,   272,   414,   496,   201,   202,
     266,   267,   268,   377,   204,   205,   491,   409,   492,   410,
     269,   270,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   271,   222,    93,   223,
     520,   225,   344,   226,   539,   227,   228,   229,   230,   231,
     232,   541,   399,   400,   481,   453,   454,   455,   517,   489,
      57,    13,    14,    30,    31,    85,   273,    58,    59,    60,
      61,    62,    63,   237,   354,   238,   356,   239,    64,    65,
      66,   117,   249,   118,   247,   351,   459,   521,   460,   519,
     522,   573,   523,   524,   627,   250,   362,   462,   363,   245,
      67,    68,    69,    70,    71,   129,    34,    35,    77,   140,
     365,   529,   464,   465,    15,    16,    37,   152,    81,   275,
      82,   153,   154,   150,   276,   380,    17,    79,   143,   144,
     259,   145,   146,   148,   261,   262,   372
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      43,   104,   130,    12,   104,   224,   425,   106,   397,   456,
     106,   102,   101,   434,   102,   558,   199,   104,   260,   311,
     290,   290,   290,   106,   134,   543,   159,   102,   142,   116,
     603,    21,   106,   570,   105,   298,    56,   105,   359,   432,
     404,   366,  -265,   293,   294,   295,   -82,  -265,  -265,  -265,
     105,    97,    39,   428,    92,   104,    98,    99,   100,   105,
     240,   106,  -268,   241,    87,   102,    56,  -268,  -268,  -268,
     560,    24,    32,   329,   395,   113,   423,  -282,    73,    74,
      98,    99,   100,   389,   286,   287,    18,    27,   105,   390,
      87,    87,   587,  -328,   558,   590,   233,  -286,   299,   432,
    -303,   255,    53,   254,   243,   157,  -265,  -265,   253,   155,
      25,   291,   291,   291,   290,   626,   240,   317,   330,   321,
     135,    87,    29,    53,   244,    41,  -268,  -268,   679,   157,
      98,    99,   100,   260,   309,   313,   423,   375,   203,   618,
     418,   419,   689,   256,    22,   379,    91,   234,   457,   234,
     696,   423,   241,   700,    56,    26,   415,   310,    23,    87,
     292,   292,   292,   104,    33,    87,    27,   306,    36,   106,
     566,    28,   -12,   102,   343,    87,    87,   307,   644,   290,
     325,   290,   290,   290,   290,   290,   290,   290,   290,   290,
     326,  -201,   558,   658,   350,   661,   105,   104,   311,   500,
     398,    29,    29,   106,   325,   291,   558,   102,   142,   501,
     673,   199,   447,   371,   695,   224,    38,   558,   382,   383,
     361,   318,    41,   159,   106,   106,   199,   403,   405,   106,
     105,   319,   320,   279,   280,   540,   417,   420,   -13,   422,
     424,    87,   -12,   234,   429,    87,   431,   433,    75,   -10,
     379,   105,   105,   131,   292,   488,   105,   311,   493,   -12,
     234,   206,    87,   132,   133,   290,   -22,   408,   411,    56,
     291,   240,   291,   291,   291,   291,   291,   291,   291,   291,
     291,    56,   592,   387,   388,  -266,   607,    78,   498,   323,
    -266,  -266,  -266,   596,   597,   598,    80,   104,   -19,    91,
     234,    91,   407,   106,   318,    84,   104,   102,   458,   -10,
     421,   388,   106,    86,   319,   320,   102,   458,    90,   292,
    -283,   292,   292,   292,   292,   292,   292,   292,   292,   292,
     105,   427,   388,   203,    91,    94,  -329,   107,   540,   105,
     136,    95,   136,   108,   139,   141,   156,   109,   203,  -266,
    -266,   147,   639,   110,   111,   149,   291,   -12,   234,  -267,
      87,   -10,   -10,   290,  -267,  -267,  -267,   490,   151,   163,
     490,    54,    55,  -288,   398,   164,   236,   546,  -288,  -288,
    -288,   234,   434,   221,   246,  -269,    56,   248,   540,   251,
    -269,  -269,  -269,   540,  -284,   252,   257,   258,   274,   199,
     199,   283,   540,   199,   284,   292,   199,    87,  -288,   -20,
    -330,   -21,   -76,   540,   308,   540,   540,   556,   540,   540,
    -287,   559,   561,  -267,  -267,   302,   303,   540,   315,  -285,
     540,   540,   304,   361,  -285,  -285,  -285,   540,   305,   316,
     224,   398,   322,   324,   398,   327,  -202,  -203,   328,  -269,
    -269,   199,   263,   166,   291,  -289,   206,   167,   168,   169,
    -289,  -289,  -289,   104,  -285,   199,   331,   199,   332,   106,
     199,   206,   333,   102,   574,  -290,   334,   335,   398,   336,
    -290,  -290,  -290,   337,   182,   183,   338,   184,   398,   185,
    -289,   550,    97,   224,   339,   345,   105,    98,    99,   100,
     340,   347,   199,   292,   199,   346,   199,   692,   199,   199,
    -290,   199,   199,   113,   199,   348,   352,   349,    98,    99,
     100,   203,   203,   355,   353,   203,   360,   398,   203,   350,
     364,   233,   684,   358,   369,   367,   199,   376,   373,   199,
     199,   693,   398,   378,   398,   381,   406,   407,   114,    97,
     391,   392,   199,   199,    98,    99,   100,   199,   393,   398,
     413,   199,   653,   416,   436,   104,   199,   430,   199,   450,
     199,   106,   468,   203,   461,   102,   640,   199,   221,   199,
     199,   470,   199,   199,   114,   199,   473,   203,   474,   203,
     479,   199,   203,   221,   199,   199,   476,  -313,   105,   480,
     482,   199,  -313,  -313,  -313,   263,   166,   483,   485,   484,
     167,   168,   169,   486,   495,  -313,   433,   686,   497,   170,
     499,   264,   172,   502,   203,   503,   203,   697,   203,   504,
     203,   203,   291,   203,   203,   159,   203,   182,   183,   505,
     184,   106,   185,   506,   206,   206,   507,    97,   206,   510,
     508,   206,    98,    99,   100,   348,   509,   511,   203,   -10,
     186,   203,   203,   513,   512,   341,   518,   527,   105,   -12,
     234,   516,    87,   533,   203,   203,   -22,   342,   288,   203,
     525,   292,   553,   203,   555,   544,    53,   551,   203,   568,
     203,   552,   203,   562,   567,   563,   206,   564,   569,   203,
     571,   203,   203,   572,   203,   203,   576,   203,   591,   578,
     206,   583,   206,   203,   577,   206,   203,   203,   580,   581,
     582,  -182,   594,   203,   595,   585,   588,   386,   263,   166,
     593,   395,   613,   167,   168,   169,   616,   619,   621,   632,
     633,   622,   170,   654,   171,   172,  -172,   206,   623,   206,
     624,   206,   628,   206,   206,   629,   206,   206,   395,   206,
     182,   183,   634,   184,   638,   185,   221,   221,   641,   -10,
     221,   651,   645,   221,   652,   662,   656,   659,   663,   -12,
     234,   206,    87,   186,   206,   206,   -22,   664,   579,   668,
     671,   396,   674,   682,   678,   681,   683,   206,   206,   685,
     687,   688,   206,   690,   691,   698,   206,   699,   702,   701,
     472,   206,   384,   206,   694,   206,   620,   494,   221,   463,
     412,   554,   206,   565,   206,   206,   437,   206,   206,   441,
     206,   439,   221,   442,   221,   445,   206,   221,   440,   206,
     206,   296,   297,   444,   301,   608,   206,   443,   528,   446,
     263,   166,    19,    72,   314,   167,   168,   169,   278,   599,
      96,   112,   448,   128,   170,   514,   171,   172,  -172,   221,
     242,   221,   451,   221,   602,   221,   221,   600,   221,   221,
     395,   221,   182,   183,   530,   184,   357,   185,   466,   625,
     601,   526,   531,   368,   575,    20,   515,    83,   277,   471,
       0,   469,   467,   221,     0,   186,   221,   221,   370,     0,
       0,     0,     0,   606,     0,   538,   374,     0,     0,   221,
     221,     0,   549,     0,   221,     1,     2,   604,   221,     0,
    -247,     0,     3,   221,     0,   221,     4,   221,     0,     5,
       6,     7,     8,     9,   221,     0,   221,   221,     0,   221,
     221,     0,   221,     0,     0,     0,     0,     0,   221,     0,
       0,   221,   221,     0,     0,     0,     0,     0,   221,     0,
     394,     0,   401,   402,     0,     0,     0,   642,     0,     0,
       0,   584,   649,     0,     0,     0,     0,     0,   426,     0,
       0,   655,     0,     0,     0,   435,     0,     0,   438,     0,
       0,     0,   665,     0,   666,   667,     0,   669,   670,     0,
       0,     0,     0,     0,     0,   449,   675,     0,   386,   676,
     677,     0,   610,   452,   611,   612,   680,   614,   615,     0,
       0,     0,     0,     0,   263,   166,     0,     0,     0,   167,
     168,   169,     0,     0,     0,     0,     0,     0,   170,     0,
     264,   172,   635,     0,     0,   636,   637,   475,     0,     0,
       0,     0,     0,     0,   478,     0,   182,   183,   538,   184,
       0,   185,     0,   549,     0,   487,   452,   650,     0,   452,
       0,     0,   584,     0,     0,     0,     0,     0,     0,   186,
       0,     0,     0,   610,     0,   611,   612,   300,   614,   615,
       0,     0,     0,     0,     0,   119,   120,   635,     0,     0,
     636,   637,   121,     0,     0,     0,   122,   650,     0,   123,
     124,   125,   126,   127,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   165,   166,     0,   532,     0,
     167,   168,   169,     0,     0,     0,     0,   545,     0,   170,
     548,   171,   172,  -172,   173,   174,   175,   176,   177,     0,
     178,     0,  -346,   179,   180,   181,     0,   182,   183,  -247,
     184,     3,   185,     0,     0,     4,  -346,     0,     5,     6,
       7,     8,     9,     0,   452,     0,     0,     0,     0,     0,
     186,     0,     0,     0,     0,     0,    53,   187,   188,     0,
     263,   166,     0,     0,     0,   167,   168,   169,     0,     0,
       0,     0,     0,     0,   170,     0,   264,   172,     0,     0,
       0,   487,     0,     0,   165,   166,     0,     0,     0,   167,
     168,   169,   182,   183,     0,   184,     0,   185,   170,     0,
     171,   172,  -172,   173,   174,   175,   176,   177,   605,   178,
     609,  -346,   179,   180,   181,   186,   182,   183,  -247,   184,
       3,   185,     0,   477,     4,  -346,     0,     5,     6,     7,
       8,     9,     0,     0,   631,     0,     0,     0,     0,   186,
       0,     0,     0,     0,     0,    53,  -339,   188,   165,   166,
       0,     0,     0,   167,   168,   169,     0,     0,     0,     0,
     646,   648,   170,     0,   171,   172,     0,   173,   174,   175,
     176,   177,     0,   178,     0,     0,   179,   385,     0,     0,
     182,   183,     0,   184,     0,   185,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   186,     0,     0,     0,   534,   166,    53,
       0,   188,   167,   168,   169,     0,     0,     0,     0,     0,
     314,   170,     0,   171,   172,     0,   173,   174,   175,   176,
     535,     0,   536,     0,     0,   537,   385,     0,     0,   182,
     183,     0,   184,     0,   185,     0,     0,   263,   166,     0,
       0,     0,   167,   168,   169,     0,     0,     0,     0,     0,
       0,   170,   186,   264,   172,     0,     0,     0,    53,     0,
     188,   263,   166,     0,     0,     0,   167,   168,   169,   182,
     183,     0,   184,     0,   185,   170,     0,   264,   172,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   186,   182,   183,     0,   184,     0,   185,     0,
     547,   263,   166,     0,     0,     0,   167,   168,   169,     0,
       0,     0,     0,     0,     0,   170,   186,   264,   172,     0,
       0,     0,     0,     0,   630,   263,   166,     0,     0,     0,
     167,   168,   169,   182,   183,     0,   184,     0,   185,   170,
       0,   171,   172,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   186,   182,   183,     0,
     184,     0,   185,     0,   647,     0,     0,     0,   263,   166,
       0,     0,     0,   167,   168,   169,     0,     0,     0,     0,
     186,   542,   170,     0,   171,   172,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     182,   183,     0,   184,     0,   185,     0,     0,     0,     0,
       0,   263,   166,     0,     0,     0,   167,   168,   169,     0,
       0,     0,     0,   186,   586,   170,     0,   171,   172,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   182,   183,     0,   184,     0,   185,     0,
       0,     0,     0,     0,   263,   166,     0,     0,     0,   167,
     168,   169,     0,     0,     0,     0,   186,   589,   170,     0,
     171,   172,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   182,   183,     0,   184,
       0,   185,     0,     0,     0,     0,     0,   263,   166,     0,
       0,     0,   167,   168,   169,     0,     0,     0,     0,   186,
     617,   170,     0,   171,   172,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   182,
     183,     0,   184,     0,   185,     0,     0,     0,     0,     0,
     263,   166,     0,     0,     0,   167,   168,   169,     0,     0,
       0,     0,   186,   643,   170,     0,   171,   172,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   182,   183,     0,   184,     0,   185,     0,     0,
       0,     0,     0,   263,   166,     0,     0,     0,   167,   168,
     169,     0,     0,     0,     0,   186,   657,   170,     0,   171,
     172,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   182,   183,     0,   184,     0,
     185,     0,     0,     0,     0,     0,   263,   166,     0,     0,
       0,   167,   168,   169,     0,     0,     0,     0,   186,   660,
     170,     0,   171,   172,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   182,   183,
       0,   184,     0,   185,     0,     0,     0,     0,     0,   263,
     166,     0,     0,     0,   167,   168,   169,     0,     0,     0,
       0,   186,   672,   170,     0,   264,   172,     0,     0,     0,
       0,     0,     0,   263,   166,     0,     0,     0,   167,   168,
     169,   182,   183,     0,   184,     0,   185,   170,     0,   264,
     172,     0,     0,     0,     0,     0,     0,     0,   349,     0,
       0,     0,     0,     0,   186,   182,   183,     0,   184,     0,
     185,     0,     0,   263,   166,     0,     0,     0,   167,   168,
     169,     0,     0,     0,     0,     0,     0,   170,   186,   171,
     172,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   182,   183,     0,   184,     0,
     185,     0,     0,  -346,     0,    44,    45,     0,     0,     0,
    -247,  -281,    46,     0,     0,     0,    47,  -346,   186,    48,
      49,    50,    51,    52,     0,     0,     0,  -327,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    53,  -254,     0,
      54,    55,  -346,     0,    44,    45,     0,     0,     0,  -247,
    -281,    46,     0,     0,     0,    47,  -346,     0,    48,    49,
      50,    51,    52,     0,     0,     0,  -327,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    53,  -375,     0,    54,
      55,  -346,     0,    44,    45,     0,     0,     0,  -247,  -281,
      46,     0,     0,     0,    47,  -346,     0,    48,    49,    50,
      51,    52,     0,     0,     0,  -327,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    53,  -362,     0,    54,    55
};

static const yytype_int16 yycheck[] =
{
      28,    62,    70,     0,    65,    93,   319,    62,   303,   355,
      65,    62,    62,   326,    65,   497,    93,    78,   147,   185,
     170,   171,   172,    78,    71,   477,    87,    78,    78,    65,
     576,    38,    87,   520,    62,     4,    29,    65,   247,     4,
       4,   250,     4,   170,   171,   172,    37,     9,    10,    11,
      78,     4,    27,   322,    47,   116,     9,    10,    11,    87,
     102,   116,     4,   105,    55,   116,    59,     9,    10,    11,
       4,     4,    24,    13,    34,     4,    41,    39,    30,    31,
       9,    10,    11,    61,   163,   164,     0,    30,   116,    67,
      55,    55,   544,    55,   576,   547,    93,    39,    67,     4,
      60,     4,    65,   139,    67,    58,    68,    69,   136,    84,
       4,   170,   171,   172,   264,   602,   158,   190,    58,   192,
      72,    55,    65,    65,   117,     4,    68,    69,   674,    58,
       9,    10,    11,   262,   185,   186,    41,   264,    93,   591,
      36,    37,   688,    46,    31,   274,    52,    53,   357,    53,
      55,    41,   194,   699,   147,     4,    60,   185,    45,    55,
     170,   171,   172,   224,    55,    55,    30,    42,    65,   224,
     516,    35,    52,   224,   224,    55,    55,    52,   630,   329,
      42,   331,   332,   333,   334,   335,   336,   337,   338,   339,
      52,    12,   674,   645,   236,   647,   224,   258,   364,    42,
     303,    65,    65,   258,    42,   264,   688,   258,   258,    52,
     662,   288,   339,   260,    52,   303,     4,   699,   279,   280,
     248,    42,     4,   284,   279,   280,   303,   306,   307,   284,
     258,    52,    53,    35,    36,   476,   315,   316,    52,   318,
     319,    55,    52,    53,   323,    55,   325,   326,     4,    42,
     379,   279,   280,    40,   264,   408,   284,   423,   411,    52,
      53,    93,    55,    50,    51,   415,    59,   309,   310,   262,
     329,   313,   331,   332,   333,   334,   335,   336,   337,   338,
     339,   274,   551,    52,    53,     4,   581,    59,   415,    42,
       9,    10,    11,   562,   563,   564,     4,   358,    52,    52,
      53,    52,    53,   358,    42,    57,   367,   358,   358,     4,
      52,    53,   367,    52,    52,    53,   367,   367,    52,   329,
      39,   331,   332,   333,   334,   335,   336,   337,   338,   339,
     358,    52,    53,   288,    52,    67,    55,    34,   579,   367,
      35,    66,    35,    40,    57,    56,     4,    44,   303,    68,
      69,    65,   621,    50,    51,    59,   415,    52,    53,     4,
      55,    56,    57,   513,     9,    10,    11,   409,    57,     4,
     412,    68,    69,     4,   477,     4,     4,   480,     9,    10,
      11,    53,   695,    93,     4,     4,   379,    43,   629,     4,
       9,    10,    11,   634,    39,     4,    60,    57,    67,   476,
     477,    56,   643,   480,    57,   415,   483,    55,    39,    52,
      55,    52,    52,   654,    52,   656,   657,   496,   659,   660,
      39,   500,   501,    68,    69,    59,    59,   668,    42,     4,
     671,   672,    59,   461,     9,    10,    11,   678,    59,    52,
     528,   544,    59,    42,   547,    53,    12,    12,    52,    68,
      69,   528,     4,     5,   513,     4,   288,     9,    10,    11,
       9,    10,    11,   524,    39,   542,    14,   544,    62,   524,
     547,   303,    63,   524,   524,     4,    64,    15,   581,    16,
       9,    10,    11,    17,    36,    37,    18,    39,   591,    41,
      39,   484,     4,   581,    19,    67,   524,     9,    10,    11,
      20,    12,   579,   513,   581,    67,   583,    59,   585,   586,
      39,   588,   589,     4,   591,    54,    67,    53,     9,    10,
      11,   476,   477,    70,    57,   480,     4,   630,   483,   571,
      65,   528,   682,    59,     4,    59,   613,    60,    66,   616,
     617,   691,   645,    20,   647,    66,    38,    53,    39,     4,
      67,    67,   629,   630,     9,    10,    11,   634,    67,   662,
       4,   638,   641,    60,     4,   626,   643,    41,   645,    54,
     647,   626,     4,   528,    57,   626,   626,   654,   288,   656,
     657,    57,   659,   660,    39,   662,    38,   542,    54,   544,
      61,   668,   547,   303,   671,   672,    60,     4,   626,    57,
      67,   678,     9,    10,    11,     4,     5,    60,     4,    60,
       9,    10,    11,     4,    52,    22,   695,   685,    59,    18,
       4,    20,    21,     4,   579,    38,   581,   695,   583,     4,
     585,   586,   691,   588,   589,   696,   591,    36,    37,     4,
      39,   696,    41,    54,   476,   477,    38,     4,   480,     4,
      60,   483,     9,    10,    11,    54,    41,     4,   613,    42,
      59,   616,   617,    61,    54,    22,     4,    37,   696,    52,
      53,    57,    55,    67,   629,   630,    59,    34,    61,   634,
      57,   691,    53,   638,     4,    67,    65,    59,   643,    37,
     645,    54,   647,    59,    52,    59,   528,    59,    34,   654,
      60,   656,   657,    57,   659,   660,    59,   662,    67,    60,
     542,    28,   544,   668,    66,   547,   671,   672,    59,    59,
      59,    28,     4,   678,     4,    60,    60,   288,     4,     5,
      60,    34,    60,     9,    10,    11,    60,    60,    59,    61,
      67,    60,    18,    28,    20,    21,    22,   579,    60,   581,
      60,   583,    60,   585,   586,    60,   588,   589,    34,   591,
      36,    37,    60,    39,    60,    41,   476,   477,    67,    42,
     480,    60,    67,   483,    46,    67,    60,    60,     4,    52,
      53,   613,    55,    59,   616,   617,    59,    36,    61,    60,
      60,    67,    59,    67,    60,    60,     4,   629,   630,    52,
      36,    59,   634,    60,    67,    36,   638,    59,    67,    60,
     384,   643,   284,   645,   691,   647,   593,   412,   528,   364,
     310,   492,   654,   513,   656,   657,   329,   659,   660,   333,
     662,   331,   542,   334,   544,   337,   668,   547,   332,   671,
     672,   173,   174,   336,   176,   581,   678,   335,   464,   338,
       4,     5,    11,    30,   186,     9,    10,    11,   155,   566,
      59,    63,   344,    66,    18,   451,    20,    21,    22,   579,
     116,   581,   353,   583,   574,   585,   586,   571,   588,   589,
      34,   591,    36,    37,   466,    39,   242,    41,   367,   601,
     572,   461,   468,   254,   526,    11,   454,    36,   154,   379,
      -1,   376,   370,   613,    -1,    59,   616,   617,   258,    -1,
      -1,    -1,    -1,    67,    -1,   476,   262,    -1,    -1,   629,
     630,    -1,   483,    -1,   634,    33,    34,   579,   638,    -1,
      38,    -1,    40,   643,    -1,   645,    44,   647,    -1,    47,
      48,    49,    50,    51,   654,    -1,   656,   657,    -1,   659,
     660,    -1,   662,    -1,    -1,    -1,    -1,    -1,   668,    -1,
      -1,   671,   672,    -1,    -1,    -1,    -1,    -1,   678,    -1,
     302,    -1,   304,   305,    -1,    -1,    -1,   629,    -1,    -1,
      -1,   542,   634,    -1,    -1,    -1,    -1,    -1,   320,    -1,
      -1,   643,    -1,    -1,    -1,   327,    -1,    -1,   330,    -1,
      -1,    -1,   654,    -1,   656,   657,    -1,   659,   660,    -1,
      -1,    -1,    -1,    -1,    -1,   347,   668,    -1,   579,   671,
     672,    -1,   583,   355,   585,   586,   678,   588,   589,    -1,
      -1,    -1,    -1,    -1,     4,     5,    -1,    -1,    -1,     9,
      10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    18,    -1,
      20,    21,   613,    -1,    -1,   616,   617,   389,    -1,    -1,
      -1,    -1,    -1,    -1,   396,    -1,    36,    37,   629,    39,
      -1,    41,    -1,   634,    -1,   407,   408,   638,    -1,   411,
      -1,    -1,   643,    -1,    -1,    -1,    -1,    -1,    -1,    59,
      -1,    -1,    -1,   654,    -1,   656,   657,    67,   659,   660,
      -1,    -1,    -1,    -1,    -1,    33,    34,   668,    -1,    -1,
     671,   672,    40,    -1,    -1,    -1,    44,   678,    -1,    47,
      48,    49,    50,    51,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     4,     5,    -1,   470,    -1,
       9,    10,    11,    -1,    -1,    -1,    -1,   479,    -1,    18,
     482,    20,    21,    22,    23,    24,    25,    26,    27,    -1,
      29,    -1,    31,    32,    33,    34,    -1,    36,    37,    38,
      39,    40,    41,    -1,    -1,    44,    45,    -1,    47,    48,
      49,    50,    51,    -1,   516,    -1,    -1,    -1,    -1,    -1,
      59,    -1,    -1,    -1,    -1,    -1,    65,    66,    67,    -1,
       4,     5,    -1,    -1,    -1,     9,    10,    11,    -1,    -1,
      -1,    -1,    -1,    -1,    18,    -1,    20,    21,    -1,    -1,
      -1,   553,    -1,    -1,     4,     5,    -1,    -1,    -1,     9,
      10,    11,    36,    37,    -1,    39,    -1,    41,    18,    -1,
      20,    21,    22,    23,    24,    25,    26,    27,   580,    29,
     582,    31,    32,    33,    34,    59,    36,    37,    38,    39,
      40,    41,    -1,    67,    44,    45,    -1,    47,    48,    49,
      50,    51,    -1,    -1,   606,    -1,    -1,    -1,    -1,    59,
      -1,    -1,    -1,    -1,    -1,    65,    66,    67,     4,     5,
      -1,    -1,    -1,     9,    10,    11,    -1,    -1,    -1,    -1,
     632,   633,    18,    -1,    20,    21,    -1,    23,    24,    25,
      26,    27,    -1,    29,    -1,    -1,    32,    33,    -1,    -1,
      36,    37,    -1,    39,    -1,    41,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    59,    -1,    -1,    -1,     4,     5,    65,
      -1,    67,     9,    10,    11,    -1,    -1,    -1,    -1,    -1,
     692,    18,    -1,    20,    21,    -1,    23,    24,    25,    26,
      27,    -1,    29,    -1,    -1,    32,    33,    -1,    -1,    36,
      37,    -1,    39,    -1,    41,    -1,    -1,     4,     5,    -1,
      -1,    -1,     9,    10,    11,    -1,    -1,    -1,    -1,    -1,
      -1,    18,    59,    20,    21,    -1,    -1,    -1,    65,    -1,
      67,     4,     5,    -1,    -1,    -1,     9,    10,    11,    36,
      37,    -1,    39,    -1,    41,    18,    -1,    20,    21,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    59,    36,    37,    -1,    39,    -1,    41,    -1,
      67,     4,     5,    -1,    -1,    -1,     9,    10,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    18,    59,    20,    21,    -1,
      -1,    -1,    -1,    -1,    67,     4,     5,    -1,    -1,    -1,
       9,    10,    11,    36,    37,    -1,    39,    -1,    41,    18,
      -1,    20,    21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    59,    36,    37,    -1,
      39,    -1,    41,    -1,    67,    -1,    -1,    -1,     4,     5,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,    37,
      -1,    39,    -1,    41,    -1,    -1,    -1,    -1,    -1,     4,
       5,    -1,    -1,    -1,     9,    10,    11,    -1,    -1,    -1,
      -1,    59,    60,    18,    -1,    20,    21,    -1,    -1,    -1,
      -1,    -1,    -1,     4,     5,    -1,    -1,    -1,     9,    10,
      11,    36,    37,    -1,    39,    -1,    41,    18,    -1,    20,
      21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,    -1,
      -1,    -1,    -1,    -1,    59,    36,    37,    -1,    39,    -1,
      41,    -1,    -1,     4,     5,    -1,    -1,    -1,     9,    10,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    18,    59,    20,
      21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    36,    37,    -1,    39,    -1,
      41,    -1,    -1,    31,    -1,    33,    34,    -1,    -1,    -1,
      38,    39,    40,    -1,    -1,    -1,    44,    45,    59,    47,
      48,    49,    50,    51,    -1,    -1,    -1,    55,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    65,    66,    -1,
      68,    69,    31,    -1,    33,    34,    -1,    -1,    -1,    38,
      39,    40,    -1,    -1,    -1,    44,    45,    -1,    47,    48,
      49,    50,    51,    -1,    -1,    -1,    55,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    65,    66,    -1,    68,
      69,    31,    -1,    33,    34,    -1,    -1,    -1,    38,    39,
      40,    -1,    -1,    -1,    44,    45,    -1,    47,    48,    49,
      50,    51,    -1,    -1,    -1,    55,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    65,    66,    -1,    68,    69
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    33,    34,    40,    44,    47,    48,    49,    50,    51,
      72,    83,   161,   162,   163,   215,   216,   227,     0,   163,
     216,    38,    31,    45,     4,     4,     4,    30,    35,    65,
     164,   165,   167,    55,   207,   208,    65,   217,     4,    78,
      80,     4,    77,    84,    33,    34,    40,    44,    47,    48,
      49,    50,    51,    65,    68,    69,   138,   161,   168,   169,
     170,   171,   172,   173,   179,   180,   181,   201,   202,   203,
     204,   205,   165,   167,   167,     4,    88,   209,    59,   228,
       4,   219,   221,   223,    57,   166,    52,    55,    85,    91,
      52,    52,   138,   139,    67,    66,   168,     4,     9,    10,
      11,    73,    74,    75,    76,    84,    86,    34,    40,    44,
      50,    51,   172,     4,    39,    73,    88,   182,   184,    33,
      34,    40,    44,    47,    48,    49,    50,    51,   180,   206,
     207,    40,    50,    51,   204,   167,    35,    89,    90,    57,
     210,    56,    73,   229,   230,   232,   233,    65,   234,    59,
     224,    57,   218,   222,   223,    78,     4,    58,    74,    76,
      92,    94,    95,     4,     4,     4,     5,     9,    10,    11,
      18,    20,    21,    23,    24,    25,    26,    27,    29,    32,
      33,    34,    36,    37,    39,    41,    59,    66,    67,    76,
      78,    79,    81,    82,    84,    86,    98,    99,   100,   102,
     103,   109,   110,   111,   115,   116,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   140,   141,   142,   144,   146,   147,   148,
     149,   150,   151,   161,    53,    87,     4,   174,   176,   178,
      87,    87,   184,    67,   138,   200,     4,   185,    43,   183,
     196,     4,     4,    84,    88,     4,    46,    60,    57,   231,
     169,   235,   236,     4,    20,   102,   111,   112,   113,   121,
     122,   137,   106,   167,    67,   220,   225,   222,   166,    35,
      36,    96,    97,    56,    57,    93,    85,    85,    61,   101,
      79,   109,   110,   135,   135,   135,   121,   121,     4,    67,
      67,   121,    59,    59,    59,    59,    42,    52,    52,    74,
      84,    91,   104,    74,   121,    42,    52,   101,    42,    52,
      53,   101,    59,    42,    42,    42,    52,    53,    52,    13,
      58,    14,    62,    63,    64,    15,    16,    17,    18,    19,
      20,    22,    34,    73,   143,    67,    67,    12,    54,    53,
      87,   186,    67,    57,   175,    70,   177,   185,    59,   183,
       4,    84,   197,   199,    65,   211,   183,    59,   210,     4,
     232,   204,   237,    66,   235,   135,    60,   114,    20,   169,
     226,    66,    76,    76,    94,    33,   144,    52,    53,    61,
      67,    67,    67,    67,   121,    34,    67,   142,   147,   153,
     154,   121,   121,    85,     4,    85,    38,    53,    87,   118,
     120,    87,   118,     4,   107,    60,    60,    85,    36,    37,
      85,    52,    85,    41,    85,   103,   121,    52,   112,    85,
      41,    85,     4,    85,   103,   121,     4,   126,   121,   129,
     130,   127,   128,   131,   132,   133,   134,   135,   174,   121,
      54,   176,   121,   156,   157,   158,   160,   183,    73,   187,
     189,    57,   198,   104,   213,   214,   187,   231,     4,   224,
      57,   226,    93,    38,    54,   121,    60,    67,   121,    61,
      57,   155,    67,    60,    60,     4,     4,   121,   156,   160,
      87,   117,   119,   156,   117,    52,   108,    59,   135,     4,
      42,    52,     4,    38,     4,     4,    54,    38,    60,    41,
       4,     4,    54,    61,   175,   218,    57,   159,     4,   190,
     141,   188,   191,   193,   194,    57,   199,    37,   139,   212,
     188,   211,   121,    67,     4,    27,    29,    32,   144,   145,
     146,   152,    60,   154,    67,   121,   147,    67,   121,   144,
     138,    59,    54,    53,   120,     4,    85,   105,   113,    85,
       4,    85,    59,    59,    59,   124,   160,    52,    37,    34,
     194,    60,    57,   192,    73,   198,    59,    66,    60,    61,
      59,    59,    59,    28,   144,    60,    60,   154,    60,    60,
     154,    67,   112,    60,     4,     4,   112,   112,   112,   159,
     186,   193,   178,   105,   145,   121,    67,   142,   153,   121,
     144,   144,   144,    60,   144,   144,    60,    60,   154,    60,
     106,    59,    60,    60,    60,   192,   194,   195,    60,    60,
      67,   121,    61,    67,    60,   144,   144,   144,    60,   112,
      73,    67,   145,    60,   154,    67,   121,    67,   121,   145,
     144,    60,    46,    85,    28,   145,    60,    60,   154,    60,
      60,   154,    67,     4,    36,   145,   145,   145,    60,   145,
     145,    60,    60,   154,    59,   145,   145,   145,    60,   105,
     145,    60,    67,     4,    79,    52,   207,    36,    59,   105,
      60,    67,    59,    79,    98,    52,    55,   207,    36,    59,
     105,    60,    67
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    71,    72,    73,    73,    74,    74,    75,    75,    76,
      76,    76,    77,    77,    78,    78,    79,    79,    80,    80,
      81,    81,    82,    83,    83,    83,    83,    83,    83,    83,
      83,    83,    84,    84,    84,    85,    85,    86,    86,    86,
      87,    87,    88,    89,    89,    90,    90,    91,    92,    93,
      93,    94,    94,    95,    96,    96,    97,    97,    98,    98,
      99,    99,    99,    99,    99,    99,    99,    99,    99,    99,
     100,   100,   100,   100,   100,   101,   101,   102,   102,   102,
     103,   104,   104,   105,   105,   106,   106,   107,   108,   108,
      85,    85,   109,   109,   109,   110,   110,   111,   111,   111,
     111,   111,   111,   112,   112,    85,    85,   113,   114,   114,
     115,   115,   115,   115,   115,   115,   115,   116,   116,   116,
     116,   117,   117,   118,   119,   119,   120,   121,   122,   122,
     123,   123,    79,    79,   124,   124,   125,   125,   126,   126,
     127,   127,   128,   128,   129,   129,   130,   130,   131,   131,
     132,   132,   133,   133,   134,   134,   135,   135,   135,   135,
     135,   136,   137,   137,   137,   138,   139,   139,   140,   140,
     140,   141,   141,   142,   143,   143,   144,   144,   144,   144,
     144,   144,   145,   145,   145,   145,   145,   146,   146,   146,
     146,   146,   146,   146,   146,   146,   147,   147,   147,   147,
     147,   148,   148,   148,   149,   149,   150,   150,   151,   151,
     151,   151,   151,   151,   151,   151,   151,   152,   152,   152,
     152,   152,   152,   152,   152,   152,   153,   153,   154,   155,
     155,   156,   157,   157,   158,   159,   159,   160,   160,   161,
     161,   161,   162,   162,   162,   162,   163,   163,   164,   165,
     166,   166,   167,   168,   168,   169,   169,   169,   169,   170,
     170,   170,   171,   172,   172,   173,   173,   173,   173,   173,
     173,   173,   174,   175,   175,   176,   177,   177,   178,   179,
     180,   180,   181,   181,   181,   181,   181,   181,   181,   181,
     181,   182,   182,   183,   183,   184,   184,   185,   186,   186,
     187,   187,   188,   188,   189,   190,   190,   191,   192,   192,
     193,   194,   194,   141,   195,   196,   197,   198,   198,   199,
     199,   200,   200,   201,   202,   203,   204,   204,   205,   205,
     205,   206,   207,   207,   208,   209,   210,   210,   211,   212,
     212,   213,   213,   214,   215,   216,   216,   217,   218,   218,
     219,   219,   220,   220,   221,   222,   222,   223,   224,   224,
     225,   226,   226,   227,   228,   229,   229,   230,   231,   231,
     232,   232,   233,   234,   235,   235,   236,   237
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     1,     3,     1,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     4,     4,     1,     0,     2,     2,     2,
       2,     3,     2,     1,     0,     2,     2,     3,     2,     3,
       0,     1,     1,     2,     1,     0,     2,     2,     1,     1,
       1,     1,     1,     3,     3,     1,     1,     1,     1,     1,
       0,     4,     4,     4,     3,     3,     0,     1,     3,     3,
       7,     1,     0,     1,     0,     1,     0,     3,     2,     0,
       1,     0,     3,     3,     5,     4,     4,     4,     7,     7,
       7,     7,     9,     1,     0,     1,     0,     2,     3,     0,
       4,     4,     4,     4,     6,     4,     3,     4,     4,     4,
       4,     1,     0,     2,     2,     0,     3,     1,     1,     3,
       3,     1,     3,     1,     1,     5,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     3,     2,     2,     1,     2,
       1,     4,     1,     1,     2,     3,     2,     0,     1,     2,
       1,     2,     0,     3,     1,     1,     1,     3,     5,     7,
       5,     1,     1,     3,     7,     5,     1,     1,     1,     2,
       1,     1,     2,     3,     3,     5,     1,     2,     2,     1,
       1,     1,     1,     1,     3,     5,     3,     2,     6,     7,
       7,     7,     8,     8,     8,     9,     7,     6,     7,     7,
       7,     8,     8,     8,     9,     7,     1,     1,     2,     2,
       0,     2,     1,     0,     2,     3,     0,     1,     1,     1,
       1,     1,     4,     5,     5,     6,     2,     0,     2,     3,
       3,     0,     3,     2,     0,     1,     1,     1,     1,     1,
       1,     2,     4,     2,     0,     1,     1,     1,     1,     1,
       1,     1,     2,     3,     0,     2,     2,     0,     2,     3,
       2,     0,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     4,     2,     0,     1,     1,     6,     1,     0,
       2,     0,     1,     0,     3,     2,     0,     2,     3,     0,
       4,     2,     0,     1,     4,     2,     2,     3,     0,     1,
       1,     1,     1,     1,     2,     4,     2,     0,     1,     1,
       1,     6,     1,     0,     3,     2,     3,     2,     4,     1,
       0,     1,     0,    28,     4,     2,     0,     5,     1,     0,
       1,     0,     1,     0,     2,     2,     0,     3,     4,     0,
       2,     2,     0,     6,     3,     1,     0,     2,     3,     0,
       2,     1,     3,     3,     2,     0,     2,     3
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
#line 2238 "parser.tab.c"
    break;


#line 2242 "parser.tab.c"

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

#line 818 "parser.y"


int main(){
    if(yyparse()) return 0;
    
    return 0;
}
