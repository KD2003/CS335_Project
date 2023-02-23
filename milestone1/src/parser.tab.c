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
  YYSYMBOL_68_ = 68,                       /* "="  */
  YYSYMBOL_YYACCEPT = 69,                  /* $accept  */
  YYSYMBOL_prog = 70,                      /* prog  */
  YYSYMBOL_Type = 71,                      /* Type  */
  YYSYMBOL_PrimitiveType = 72,             /* PrimitiveType  */
  YYSYMBOL_numerictype = 73,               /* numerictype  */
  YYSYMBOL_ReferenceType = 74,             /* ReferenceType  */
  YYSYMBOL_PackageName = 75,               /* PackageName  */
  YYSYMBOL_TypeName = 76,                  /* TypeName  */
  YYSYMBOL_ExpressionName = 77,            /* ExpressionName  */
  YYSYMBOL_NumericType = 78,               /* NumericType  */
  YYSYMBOL_MethodName = 79,                /* MethodName  */
  YYSYMBOL_ClassModifier = 80,             /* ClassModifier  */
  YYSYMBOL_ClassType = 81,                 /* ClassType  */
  YYSYMBOL_Zeroorone_TypeArguments = 82,   /* Zeroorone_TypeArguments  */
  YYSYMBOL_ArrayType = 83,                 /* ArrayType  */
  YYSYMBOL_Dims = 84,                      /* Dims  */
  YYSYMBOL_TypeParameter = 85,             /* TypeParameter  */
  YYSYMBOL_TypeBound = 86,                 /* TypeBound  */
  YYSYMBOL_TypeArguments = 87,             /* TypeArguments  */
  YYSYMBOL_TypeArgumentList = 88,          /* TypeArgumentList  */
  YYSYMBOL_cTypeArgument = 89,             /* cTypeArgument  */
  YYSYMBOL_TypeArgument = 90,              /* TypeArgument  */
  YYSYMBOL_Wildcard = 91,                  /* Wildcard  */
  YYSYMBOL_zerooroneWildcardBounds = 92,   /* zerooroneWildcardBounds  */
  YYSYMBOL_WildcardBounds = 93,            /* WildcardBounds  */
  YYSYMBOL_Primary = 94,                   /* Primary  */
  YYSYMBOL_PrimaryNoNewArray = 95,         /* PrimaryNoNewArray  */
  YYSYMBOL_ClassLiteral = 96,              /* ClassLiteral  */
  YYSYMBOL_Zero_or_moreSquarebracket = 97, /* Zero_or_moreSquarebracket  */
  YYSYMBOL_ClassInstanceCreationExpression = 98, /* ClassInstanceCreationExpression  */
  YYSYMBOL_UnqualifiedClassInstanceCreationExpression = 99, /* UnqualifiedClassInstanceCreationExpression  */
  YYSYMBOL_ZerooroneTypeArguments = 100,   /* ZerooroneTypeArguments  */
  YYSYMBOL_ZerooroneArgumentList = 101,    /* ZerooroneArgumentList  */
  YYSYMBOL_ZerooroneClassBody = 102,       /* ZerooroneClassBody  */
  YYSYMBOL_ClassOrInterfaceTypeToInstantiate = 103, /* ClassOrInterfaceTypeToInstantiate  */
  YYSYMBOL_Zeroormore_DotIdentifier = 104, /* Zeroormore_DotIdentifier  */
  YYSYMBOL_FieldAccess = 105,              /* FieldAccess  */
  YYSYMBOL_ArrayAccess = 106,              /* ArrayAccess  */
  YYSYMBOL_MethodInvocation = 107,         /* MethodInvocation  */
  YYSYMBOL_Zeroorone_ArgumentList = 108,   /* Zeroorone_ArgumentList  */
  YYSYMBOL_ArgumentList = 109,             /* ArgumentList  */
  YYSYMBOL_Zeroormore_CommaExpression = 110, /* Zeroormore_CommaExpression  */
  YYSYMBOL_MethodReference = 111,          /* MethodReference  */
  YYSYMBOL_ArrayCreationExpression = 112,  /* ArrayCreationExpression  */
  YYSYMBOL_DimExprs = 113,                 /* DimExprs  */
  YYSYMBOL_Zeroormore_DimExpr = 114,       /* Zeroormore_DimExpr  */
  YYSYMBOL_DimExpr = 115,                  /* DimExpr  */
  YYSYMBOL_Expression = 116,               /* Expression  */
  YYSYMBOL_AssignmentExpression = 117,     /* AssignmentExpression  */
  YYSYMBOL_AmbigiousName = 118,            /* AmbigiousName  */
  YYSYMBOL_ConditionalExpression = 119,    /* ConditionalExpression  */
  YYSYMBOL_ConditionalOrExpression = 120,  /* ConditionalOrExpression  */
  YYSYMBOL_ConditionalAndExpression = 121, /* ConditionalAndExpression  */
  YYSYMBOL_AndExpression = 122,            /* AndExpression  */
  YYSYMBOL_ExclusiveOrExpression = 123,    /* ExclusiveOrExpression  */
  YYSYMBOL_InclusiveOrExpression = 124,    /* InclusiveOrExpression  */
  YYSYMBOL_EqualityExpression = 125,       /* EqualityExpression  */
  YYSYMBOL_RelationalExpression = 126,     /* RelationalExpression  */
  YYSYMBOL_ShiftExpression = 127,          /* ShiftExpression  */
  YYSYMBOL_AdditiveExpression = 128,       /* AdditiveExpression  */
  YYSYMBOL_MultiplicativeExpression = 129, /* MultiplicativeExpression  */
  YYSYMBOL_UnaryExpression = 130,          /* UnaryExpression  */
  YYSYMBOL_CastExpression = 131,           /* CastExpression  */
  YYSYMBOL_PostfixExpression = 132,        /* PostfixExpression  */
  YYSYMBOL_Block = 133,                    /* Block  */
  YYSYMBOL_BlockStatements = 134,          /* BlockStatements  */
  YYSYMBOL_BlockStatement = 135,           /* BlockStatement  */
  YYSYMBOL_VariableModifier = 136,         /* VariableModifier  */
  YYSYMBOL_LocalVariableDeclaration = 137, /* LocalVariableDeclaration  */
  YYSYMBOL_LocalVariableType = 138,        /* LocalVariableType  */
  YYSYMBOL_Statement = 139,                /* Statement  */
  YYSYMBOL_StatementNoShortIf = 140,       /* StatementNoShortIf  */
  YYSYMBOL_StatementWithoutTrailingSubstatement = 141, /* StatementWithoutTrailingSubstatement  */
  YYSYMBOL_StatementExpression = 142,      /* StatementExpression  */
  YYSYMBOL_LeftHandSide = 143,             /* LeftHandSide  */
  YYSYMBOL_AssertStatement = 144,          /* AssertStatement  */
  YYSYMBOL_BreakContinueStatement = 145,   /* BreakContinueStatement  */
  YYSYMBOL_ForStatement = 146,             /* ForStatement  */
  YYSYMBOL_ForStatementNoShortIf = 147,    /* ForStatementNoShortIf  */
  YYSYMBOL_ForInit = 148,                  /* ForInit  */
  YYSYMBOL_StatementExpressionList = 149,  /* StatementExpressionList  */
  YYSYMBOL_StatementExpressionMore = 150,  /* StatementExpressionMore  */
  YYSYMBOL_ArrayInitializer = 151,         /* ArrayInitializer  */
  YYSYMBOL_zerooroneVariableInitializerList = 152, /* zerooroneVariableInitializerList  */
  YYSYMBOL_VariableInitializerList = 153,  /* VariableInitializerList  */
  YYSYMBOL_cVariableInitializer = 154,     /* cVariableInitializer  */
  YYSYMBOL_VariableInitializer = 155,      /* VariableInitializer  */
  YYSYMBOL_ClassDeclaration = 156,         /* ClassDeclaration  */
  YYSYMBOL_NormalClassDeclaration = 157,   /* NormalClassDeclaration  */
  YYSYMBOL_ClassModifiers = 158,           /* ClassModifiers  */
  YYSYMBOL_ClassExtends = 159,             /* ClassExtends  */
  YYSYMBOL_ClassPermits = 160,             /* ClassPermits  */
  YYSYMBOL_cTypeName = 161,                /* cTypeName  */
  YYSYMBOL_ClassBody = 162,                /* ClassBody  */
  YYSYMBOL_ClassBodyDeclarations = 163,    /* ClassBodyDeclarations  */
  YYSYMBOL_ClassBodyDeclaration = 164,     /* ClassBodyDeclaration  */
  YYSYMBOL_ClassMemberDeclaration = 165,   /* ClassMemberDeclaration  */
  YYSYMBOL_FieldDeclaration = 166,         /* FieldDeclaration  */
  YYSYMBOL_FieldModifiers = 167,           /* FieldModifiers  */
  YYSYMBOL_FieldModifier = 168,            /* FieldModifier  */
  YYSYMBOL_VariableDeclaratorList = 169,   /* VariableDeclaratorList  */
  YYSYMBOL_cVariableDeclarator = 170,      /* cVariableDeclarator  */
  YYSYMBOL_VariableDeclarator = 171,       /* VariableDeclarator  */
  YYSYMBOL_VariableInitializer_eq = 172,   /* VariableInitializer_eq  */
  YYSYMBOL_VariableDeclaratorId = 173,     /* VariableDeclaratorId  */
  YYSYMBOL_MethodDeclaration = 174,        /* MethodDeclaration  */
  YYSYMBOL_Methodmodifiers = 175,          /* Methodmodifiers  */
  YYSYMBOL_Methodmodifier = 176,           /* Methodmodifier  */
  YYSYMBOL_Methodheader = 177,             /* Methodheader  */
  YYSYMBOL_Throws_s = 178,                 /* Throws_s  */
  YYSYMBOL_Result = 179,                   /* Result  */
  YYSYMBOL_Methodeclarator = 180,          /* Methodeclarator  */
  YYSYMBOL_recieveparameters = 181,        /* recieveparameters  */
  YYSYMBOL_formalparameters = 182,         /* formalparameters  */
  YYSYMBOL_recieveparameter = 183,         /* recieveparameter  */
  YYSYMBOL_formalparameterlist = 184,      /* formalparameterlist  */
  YYSYMBOL_cformalparameter = 185,         /* cformalparameter  */
  YYSYMBOL_formalparameter = 186,          /* formalparameter  */
  YYSYMBOL_Variablemodifiers = 187,        /* Variablemodifiers  */
  YYSYMBOL_VariableArityParameter = 188,   /* VariableArityParameter  */
  YYSYMBOL_Throws = 189,                   /* Throws  */
  YYSYMBOL_ExceptionTypeList = 190,        /* ExceptionTypeList  */
  YYSYMBOL_cExceptionType = 191,           /* cExceptionType  */
  YYSYMBOL_ExceptionType = 192,            /* ExceptionType  */
  YYSYMBOL_MethodBody = 193,               /* MethodBody  */
  YYSYMBOL_InstanceInitializer = 194,      /* InstanceInitializer  */
  YYSYMBOL_StaticInitializer = 195,        /* StaticInitializer  */
  YYSYMBOL_ConstructorDeclaration = 196,   /* ConstructorDeclaration  */
  YYSYMBOL_zeroormore_ConstructorModifier = 197, /* zeroormore_ConstructorModifier  */
  YYSYMBOL_ConstructorModifier = 198,      /* ConstructorModifier  */
  YYSYMBOL_ConstructorDeclarator = 199,    /* ConstructorDeclarator  */
  YYSYMBOL_zeroorone_TypeParameters = 200, /* zeroorone_TypeParameters  */
  YYSYMBOL_TypeParameters = 201,           /* TypeParameters  */
  YYSYMBOL_TypeParamerList = 202,          /* TypeParamerList  */
  YYSYMBOL_TypeParameterc = 203,           /* TypeParameterc  */
  YYSYMBOL_ConstructorBody = 204,          /* ConstructorBody  */
  YYSYMBOL_zerooroneBlockStatements = 205, /* zerooroneBlockStatements  */
  YYSYMBOL_zerooroneExplicitConstructorInvocation = 206, /* zerooroneExplicitConstructorInvocation  */
  YYSYMBOL_ExplicitConstructorInvocation = 207, /* ExplicitConstructorInvocation  */
  YYSYMBOL_EnumDeclaration = 208,          /* EnumDeclaration  */
  YYSYMBOL_zeroormoreClassModifier = 209,  /* zeroormoreClassModifier  */
  YYSYMBOL_EnumBody = 210,                 /* EnumBody  */
  YYSYMBOL_zerooronecomma = 211,           /* zerooronecomma  */
  YYSYMBOL_zerooroneEnumConstantList = 212, /* zerooroneEnumConstantList  */
  YYSYMBOL_zerooroneEnumBodyDeclarations = 213, /* zerooroneEnumBodyDeclarations  */
  YYSYMBOL_EnumConstantList = 214,         /* EnumConstantList  */
  YYSYMBOL_cEnumConstant = 215,            /* cEnumConstant  */
  YYSYMBOL_EnumConstant = 216,             /* EnumConstant  */
  YYSYMBOL_bracketZeroorone_ArgumentList = 217, /* bracketZeroorone_ArgumentList  */
  YYSYMBOL_EnumBodyDeclarations = 218,     /* EnumBodyDeclarations  */
  YYSYMBOL_zeroormoreClassBodyDeclaration = 219, /* zeroormoreClassBodyDeclaration  */
  YYSYMBOL_RecordDeclaration = 220,        /* RecordDeclaration  */
  YYSYMBOL_RecordHeader = 221,             /* RecordHeader  */
  YYSYMBOL_zerooroneRecordComponentList = 222, /* zerooroneRecordComponentList  */
  YYSYMBOL_RecordComponentList = 223,      /* RecordComponentList  */
  YYSYMBOL_cRecordComponent = 224,         /* cRecordComponent  */
  YYSYMBOL_RecordComponent = 225,          /* RecordComponent  */
  YYSYMBOL_VariableArityRecordComponent = 226, /* VariableArityRecordComponent  */
  YYSYMBOL_RecordBody = 227,               /* RecordBody  */
  YYSYMBOL_zeroormoreRecordBodyDeclaration = 228, /* zeroormoreRecordBodyDeclaration  */
  YYSYMBOL_RecordBodyDeclaration = 229,    /* RecordBodyDeclaration  */
  YYSYMBOL_CompactConstructorDeclaration = 230 /* CompactConstructorDeclaration  */
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
#define YYLAST   2032

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  69
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  162
/* YYNRULES -- Number of rules.  */
#define YYNRULES  363
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  676

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   307


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
      45,    46,    47,    48,    49,    50,    51,    68
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    22,    22,    27,    28,    32,    33,    37,    38,    45,
      46,    47,    53,    54,    57,    58,    61,    62,    65,    66,
      70,    73,    73,    77,    78,    79,    83,    83,    87,    88,
      89,    92,    93,    96,    97,   101,   102,   105,   108,   111,
     112,   115,   116,   119,   122,   123,   126,   127,   133,   134,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     152,   153,   154,   155,   156,   160,   161,   165,   166,   167,
     172,   176,   176,   180,   180,   184,   184,   189,   193,   193,
     197,   197,   202,   203,   204,   209,   210,   215,   216,   217,
     218,   219,   220,   224,   224,   228,   228,   233,   237,   238,
     243,   244,   245,   246,   247,   248,   249,   254,   255,   256,
     257,   258,   259,   263,   267,   267,   271,   275,   279,   280,
     284,   285,   289,   290,   294,   295,   299,   300,   304,   305,
     309,   310,   314,   315,   319,   320,   324,   325,   329,   330,
     334,   335,   339,   340,   344,   345,   349,   350,   351,   352,
     353,   357,   361,   362,   363,   371,   375,   375,   379,   380,
     381,   385,   385,   389,   393,   394,   398,   399,   400,   401,
     402,   403,   407,   408,   409,   410,   411,   415,   416,   417,
     418,   419,   420,   421,   422,   423,   427,   428,   429,   430,
     431,   435,   436,   437,   441,   442,   446,   447,   451,   452,
     453,   454,   455,   456,   457,   458,   459,   463,   464,   465,
     466,   467,   468,   469,   470,   471,   475,   476,   479,   483,
     483,   490,   493,   494,   497,   501,   502,   506,   507,   513,
     514,   515,   518,   519,   520,   521,   524,   525,   528,   531,
     535,   535,   539,   542,   543,   546,   547,   548,   549,   552,
     553,   554,   557,   560,   561,   564,   564,   567,   570,   571,
     574,   577,   578,   581,   582,   587,   591,   592,   596,   596,
     596,   596,   596,   596,   596,   596,   596,   600,   601,   605,
     606,   610,   611,   615,   616,   620,   621,   624,   625,   629,
     630,   634,   637,   637,   640,   643,   643,   646,   649,   652,
     655,   658,   659,   662,   663,   666,   667,   670,   673,   676,
     679,   680,   683,   683,   686,   689,   690,   693,   696,   699,
     700,   704,   707,   708,   711,   712,   715,   716,   717,   718,
     721,   724,   725,   728,   731,   732,   735,   736,   739,   740,
     743,   746,   747,   750,   753,   754,   757,   760,   761,   764,
     767,   770,   771,   774,   777,   778,   781,   782,   785,   788,
     791,   792,   795,   799
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
  "'^'", "'|'", "'{'", "'}'", "';'", "\"=\"", "$accept", "prog", "Type",
  "PrimitiveType", "numerictype", "ReferenceType", "PackageName",
  "TypeName", "ExpressionName", "NumericType", "MethodName",
  "ClassModifier", "ClassType", "Zeroorone_TypeArguments", "ArrayType",
  "Dims", "TypeParameter", "TypeBound", "TypeArguments",
  "TypeArgumentList", "cTypeArgument", "TypeArgument", "Wildcard",
  "zerooroneWildcardBounds", "WildcardBounds", "Primary",
  "PrimaryNoNewArray", "ClassLiteral", "Zero_or_moreSquarebracket",
  "ClassInstanceCreationExpression",
  "UnqualifiedClassInstanceCreationExpression", "ZerooroneTypeArguments",
  "ZerooroneArgumentList", "ZerooroneClassBody",
  "ClassOrInterfaceTypeToInstantiate", "Zeroormore_DotIdentifier",
  "FieldAccess", "ArrayAccess", "MethodInvocation",
  "Zeroorone_ArgumentList", "ArgumentList", "Zeroormore_CommaExpression",
  "MethodReference", "ArrayCreationExpression", "DimExprs",
  "Zeroormore_DimExpr", "DimExpr", "Expression", "AssignmentExpression",
  "AmbigiousName", "ConditionalExpression", "ConditionalOrExpression",
  "ConditionalAndExpression", "AndExpression", "ExclusiveOrExpression",
  "InclusiveOrExpression", "EqualityExpression", "RelationalExpression",
  "ShiftExpression", "AdditiveExpression", "MultiplicativeExpression",
  "UnaryExpression", "CastExpression", "PostfixExpression", "Block",
  "BlockStatements", "BlockStatement", "VariableModifier",
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
  "VariableDeclarator", "VariableInitializer_eq", "VariableDeclaratorId",
  "MethodDeclaration", "Methodmodifiers", "Methodmodifier", "Methodheader",
  "Throws_s", "Result", "Methodeclarator", "recieveparameters",
  "formalparameters", "recieveparameter", "formalparameterlist",
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

#define YYPACT_NINF (-530)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-362)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     293,  -530,  -530,    21,   293,  -530,  -530,     6,  -530,    52,
    -530,  -530,  -530,  -530,    49,    64,   103,    63,    68,    76,
     115,   162,  1917,    44,    87,  -530,   166,   188,  -530,   184,
    -530,  -530,    92,    59,   210,   214,  -530,  -530,    75,   233,
    -530,  -530,  -530,  -530,   221,  -530,  -530,  -530,   245,  1917,
    -530,  -530,   380,    89,  -530,   209,   257,  -530,  -530,  -530,
      68,   153,    87,  -530,  -530,   289,   235,   287,   380,   283,
     305,   309,  -530,   184,   369,   115,  -530,    54,  -530,  -530,
     383,   390,  -530,  1010,  -530,  -530,   315,  -530,  -530,  -530,
     392,   324,  -530,  -530,   333,  -530,  -530,  -530,  -530,   260,
    -530,  -530,   224,   229,   394,  -530,  -530,  -530,  -530,   375,
     416,  -530,  -530,  -530,  -530,   418,  -530,   166,  -530,  -530,
      46,   366,  -530,   370,  -530,  1941,  -530,  1880,    87,  -530,
     368,  -530,   184,  -530,    92,   373,   324,  -530,   374,   382,
    -530,   219,   386,   319,  -530,   385,   395,   397,  1880,  1880,
    1880,  1880,  1880,     2,  1320,   379,   387,   393,   399,  -530,
     126,  -530,   404,   147,  1880,  -530,  -530,   402,   407,   123,
    -530,   401,   120,   420,   144,   410,  -530,  -530,  -530,   452,
     453,  -530,  -530,  -530,  -530,   414,  -530,    24,   455,   405,
     408,   406,   457,   458,   456,   461,   462,  -530,  -530,   466,
    -530,  -530,   316,   409,  -530,  -530,   421,   463,  -530,  -530,
    -530,  -530,   437,   441,   324,   430,   442,   432,   441,   441,
     394,  -530,  -530,  -530,   439,   375,   497,   438,   375,   443,
      59,   214,   235,  -530,   501,  -530,   380,  -530,   153,   440,
    1941,   227,  1880,  -530,  -530,   448,  -530,  -530,  -530,   489,
    -530,  -530,  1965,   444,  -530,  -530,  -530,   380,   380,  -530,
    -530,  -530,    54,  -530,  -530,  -530,  1136,   359,   288,  -530,
    -530,  -530,  -530,  -530,   268,   447,   449,  -530,  -530,   459,
    1880,  1240,  1880,  1880,   386,    25,   477,   474,   361,  -530,
     515,   217,   469,   386,   109,   364,   386,    98,  1880,   372,
    1880,   386,   490,   386,    34,  1880,   526,  1880,  1880,  1880,
    1880,  1880,  1880,  1880,  1880,  1880,  1880,  1880,  -530,  -530,
    -530,  -530,   392,  -530,  -530,  1880,  -530,   479,   441,  -530,
     392,  -530,  1880,  -530,   375,   380,  -530,    59,   214,  -530,
     478,    95,  -530,  -530,   380,  -530,  -530,   370,   533,  -530,
    -530,  -530,  -530,   305,   481,  -530,  1965,  -530,  -530,  -530,
    -530,   382,  -530,   504,   485,  1880,  -530,  -530,  -530,  -530,
     483,  1344,   486,   487,   484,  -530,   488,   492,   542,  -530,
     549,  -530,  1816,  1840,   324,  -530,  1840,   324,   502,   496,
    1880,  -530,   552,   226,  -530,   559,   528,   572,   386,   574,
    -530,   525,   543,   523,   550,  -530,   591,  -530,   593,  -530,
     544,  -530,   455,   540,   406,   457,   405,   408,   458,   456,
     461,   462,  -530,  -530,  -530,  -530,   442,  -530,  -530,   309,
    -530,   545,  -530,    20,    -9,   546,   497,  -530,  1880,   294,
     568,   569,   231,   570,  -530,  -530,    -9,  -530,   438,  -530,
    1880,  -530,  -530,  -530,  -530,   547,  1189,  1472,   551,  1880,
    1904,  -530,  1384,  1136,   233,  -530,   553,   555,  -530,   545,
     441,   557,  -530,   441,   607,   386,  1880,  -530,  -530,   386,
      32,   554,  -530,  -530,   558,  -530,  -530,  -530,  -530,  -530,
     560,  -530,  1880,  -530,  -530,  1880,  -530,   571,  -530,   587,
     562,  -530,   573,   380,  -530,   478,   148,   566,    55,   567,
    1084,   561,   575,  -530,  -530,  -530,   381,   578,   579,   581,
    -530,   600,   601,  -530,  1136,   582,  1515,   583,  -530,  1558,
     564,  -530,  -530,  1880,  -530,  1880,  -530,  -530,  -530,   585,
    -530,   629,  -530,   637,  1880,  1880,  1880,  -530,   545,   611,
    -530,  -530,   324,   617,  -530,   392,  -530,    62,   618,  1880,
     620,  1880,  -530,  -530,  1189,  1880,  1280,  1880,  1136,  -530,
    1136,  1136,   597,  1136,  1136,   604,  1601,   605,    87,  -530,
     602,   606,   609,   621,  -530,  -530,   441,   573,   617,   608,
     622,   612,   623,  -530,   624,  1408,   599,   619,   625,  -530,
    -530,  -530,  1136,  -530,  -530,  1136,  1136,   627,  -530,  -530,
    1880,  -530,  -530,  -530,  -530,   380,  -530,  1880,   631,  1880,
     634,  1189,  1644,   639,  1880,  1448,  1189,  -530,  -530,  -530,
    1136,   628,   643,   630,  -530,   632,  -530,   663,  1189,   636,
    1687,   649,  1730,   645,  -530,  -530,  -530,   690,   646,   648,
    1189,  -530,  1189,  1189,   650,  1189,  1189,   656,  1773,  -530,
    -530,  -530,  -530,  -530,  -530,  1189,  -530,  -530,  1189,  1189,
     657,  -530,  -530,  -530,  1189,  -530
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
     332,    21,    22,     0,   332,     2,   229,     0,   230,     0,
     231,     1,   236,   331,     0,     0,     0,     0,   316,     0,
       0,     0,   254,     0,     0,   232,     0,     0,   315,   337,
     330,    14,   241,    27,     0,   238,   274,   273,   268,   272,
     271,   275,   276,   269,   270,   157,   251,   307,     0,   254,
     245,   249,     0,   254,   250,     0,   267,   246,   247,   248,
     316,   311,     0,   233,   234,    34,     0,     0,   352,     0,
     345,   335,   336,   342,     0,     0,   239,     0,    23,    26,
       0,     0,   308,    60,   242,   243,    10,     7,     8,     6,
       0,     3,     5,     4,     9,    11,   255,   256,   253,    34,
     282,   281,     0,     0,     0,   268,   272,   270,   266,   280,
       0,   312,   313,   310,   235,     0,    33,     0,   318,   317,
       0,     0,   351,   355,   357,   254,   349,    60,    76,   334,
     339,   340,   342,    15,   241,    45,     0,    41,     0,    40,
      42,    27,    27,    16,    50,     7,     8,     6,    60,    60,
      60,    60,    60,     0,    60,     0,     0,     0,     0,   297,
       0,    52,     0,     0,    60,   155,   178,     0,    66,   153,
      66,     0,     0,     0,   152,    48,    51,    55,    67,    56,
      57,    58,    59,    49,   186,    17,   118,   124,   126,   132,
     134,   128,   130,   136,   138,   140,   142,   144,   150,   148,
     177,   156,     0,     0,   160,   166,     0,     0,   180,   181,
     171,   158,     0,    30,   264,     0,   259,   262,    28,    29,
       0,   306,   305,   265,     0,   280,     0,     0,   280,     0,
      27,    36,   320,   356,     0,   350,     0,   353,   311,     0,
     254,    16,    60,    55,    58,     0,    93,    99,   117,   148,
     343,    75,   254,     0,   338,   341,   240,     0,     0,    43,
      44,    37,     0,    38,    24,    25,    60,     0,   153,    56,
      57,   147,   146,   149,     0,     0,     0,   197,   182,     0,
      60,    60,    60,    60,    27,     0,     0,     0,     0,    71,
       0,     0,     0,    27,     0,     0,    27,    27,    60,     0,
      60,    27,     0,    27,     0,    60,     0,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    60,   154,   165,
     161,   164,     0,   159,   179,    60,    31,     0,   263,   252,
       0,   257,    60,   260,   280,   286,   277,    27,   303,   299,
     302,   325,   309,   279,   286,   319,   358,   355,     0,   362,
     359,   360,   146,   345,    97,   154,   254,   346,   333,    46,
      47,    40,   167,     0,     0,    60,   194,   184,   196,   183,
       0,    60,   217,   220,     0,   216,     0,     0,     0,    83,
       0,    64,    60,    60,   108,   115,    60,   110,    79,     0,
      60,    54,     0,     0,    53,     0,     0,     0,    72,     0,
      68,     0,     0,     0,     0,   106,     0,    82,     0,    69,
       0,   120,   127,     0,   129,   131,   133,   135,   137,   139,
     141,   143,   145,   163,   119,    32,   259,   227,   228,   335,
     222,   226,   278,     0,   162,     0,     0,   300,    60,     0,
       0,    26,     0,     0,   157,   324,   162,   354,     0,   344,
      60,   347,    39,    63,    65,     0,    60,    60,     0,    60,
      60,   218,    60,    60,     0,   103,     0,     0,   111,   226,
     107,   113,   112,   109,     0,    27,    60,   151,   102,    27,
       0,     0,    61,   100,     0,    85,    62,    87,   105,   101,
       0,    86,    60,   258,   221,    60,   224,     0,   290,   162,
       0,   287,   293,     0,   285,   302,    27,     0,   316,     0,
      60,     0,     0,   363,    98,   195,    16,     0,     0,     0,
     168,     0,   166,   176,    60,     0,    60,     0,   219,    60,
       0,   170,   185,    60,   116,    60,   114,    78,    77,     0,
      73,     0,    84,     0,    60,    60,    60,   125,   226,     0,
     161,   295,   284,   162,   291,     0,   301,     0,     0,    60,
       0,    60,   321,   314,    60,    60,    60,    60,    60,   198,
      60,    60,     0,    60,    60,     0,    60,     0,    76,   104,
       0,     0,     0,     0,   224,   289,   283,   293,   162,     0,
       0,     0,     0,   173,     0,    60,   217,     0,     0,   169,
     201,   200,    60,   206,   199,    60,    60,     0,    91,    70,
      60,    88,    89,    90,   292,     0,   294,    60,     0,    60,
       0,    60,    60,     0,    60,    60,    60,   202,   204,   203,
      60,     0,     0,     0,   327,     0,   326,     0,    60,     0,
      60,     0,    60,     0,   175,   205,    92,     0,     0,     0,
      60,   207,    60,    60,     0,    60,    60,     0,    60,   298,
     328,   329,   174,   210,   209,    60,   215,   208,    60,    60,
       0,   211,   213,   212,    60,   214
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -530,  -530,   -25,   -42,  -530,   -35,  -530,     3,    42,  -530,
    -530,  -530,   -21,   -87,    -7,   -45,   -41,  -530,  -154,  -530,
     358,   460,  -530,  -530,  -530,   388,  -530,  -530,   192,   -81,
    -282,   389,  -529,   142,  -530,  -530,    90,   363,    -6,  -288,
    -458,  -530,  -530,  -530,   433,  -530,   252,   641,   129,  -530,
     232,  -530,   419,   417,   415,   423,   426,   424,   425,   427,
     422,  -109,  -530,   251,    13,   296,  -530,   -82,  -278,  -530,
     262,   330,   307,  -277,  -530,  -530,  -530,  -530,  -530,   167,
    -355,  -530,   -65,  -530,  -530,   193,  -316,   743,  -530,   740,
    -530,   722,   613,   101,   697,   -97,  -530,  -530,   695,  -530,
     434,   323,   428,  -530,   197,  -530,   698,  -530,  -530,  -217,
     655,   548,   429,   314,  -530,  -530,   175,   211,  -480,  -530,
    -530,  -530,   261,   329,  -530,  -530,  -530,  -530,   -56,  -530,
    -530,   -53,  -530,  -530,   538,   326,  -530,  -530,  -530,  -530,
     768,  -530,   347,  -530,  -530,  -530,   651,   749,   435,  -530,
     445,  -530,  -530,  -530,  -530,   464,   563,  -530,  -530,   556,
    -530,  -530
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     3,   101,   136,    92,   167,    34,   168,   169,   170,
     171,     4,   172,    78,   173,   213,    66,   116,    79,   138,
     263,   139,   140,   259,   260,   174,   175,   176,   267,   243,
     178,   290,   539,   250,   389,   475,   179,   180,   244,   245,
     246,   354,   182,   183,   384,   471,   385,   247,   248,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   249,   200,    83,   201,   499,   203,   322,
     204,   521,   205,   206,   207,   208,   209,   210,   523,   374,
     375,   461,   428,   429,   430,   496,   469,   211,     6,     7,
      23,    24,    76,   251,    48,    49,    50,    51,    52,    53,
     215,   331,   216,   333,   217,    54,    55,    56,   103,   227,
     104,   225,   434,   500,   435,   501,   554,   502,   503,   616,
     228,   339,   437,   340,   223,    57,    58,    59,    60,    61,
     109,    27,    28,    67,   118,   342,   511,   444,   445,     8,
       9,    30,   130,    71,   253,    72,   131,   132,   128,   254,
     357,    10,    69,   121,   122,   237,   123,   124,   126,   239,
     240,   349
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      35,   202,   177,   372,   373,   113,   276,   110,   336,   289,
      91,   343,   403,    91,   102,   400,   431,    93,   540,   551,
      93,    11,   409,    32,   497,   159,    91,    90,   238,   379,
     590,    94,   592,    93,    94,    47,   542,   307,   407,   271,
     272,   273,   137,   120,    14,    95,   218,    94,    95,   219,
     233,  -288,    82,    17,   264,   265,    94,   498,    86,   407,
      91,    95,    47,    87,    88,    89,    99,    93,    18,   277,
      95,    87,    88,    89,    20,   398,   232,   181,   134,  -255,
      77,    94,   308,    15,  -255,  -255,  -255,    77,   633,    77,
     635,   218,   234,    20,   231,    95,   398,    16,    21,   241,
     144,   540,   525,   540,   145,   146,   147,    19,   615,    22,
     557,   -12,   135,   133,    77,  -255,   222,   432,    25,    31,
     135,   287,   291,    26,    63,    64,  -255,   219,    22,    96,
    -312,   160,   161,   352,   162,  -191,   163,   -60,    47,   398,
      97,    29,   288,   238,    74,   393,   394,   -60,   -60,    75,
      77,    33,    22,    77,   438,   356,    87,    88,    89,   540,
      91,   540,   301,   114,    77,   296,    33,    93,   284,   328,
      65,   572,    81,   212,   575,   297,   298,   321,   285,   548,
     373,    94,   348,   528,  -316,   177,   303,   441,    70,   398,
     268,   268,   268,   111,    91,    95,   304,   378,   380,   202,
     177,    93,    77,   557,   112,   338,   392,   395,   422,   397,
     399,   120,   184,    99,   404,    94,   406,   408,    87,    88,
      89,   607,   359,   360,   400,  -256,   409,   137,    86,    95,
    -256,  -256,  -256,    87,    88,    89,    94,    94,   269,   269,
     269,    94,   383,   386,   289,   577,   218,    68,   100,   373,
      95,    95,   373,    47,   440,    95,   581,   582,   583,   356,
     181,  -256,    80,   100,   -10,    47,    81,   639,   479,   -10,
     212,   -13,  -256,   303,    77,   181,  -313,   390,   480,   -12,
     212,   477,    77,   508,   268,   654,   -20,   657,   596,   373,
      36,    37,   117,    91,    45,   115,   221,   105,    45,   373,
      93,   106,    91,   670,    40,    41,    42,    43,   107,    93,
     433,    84,   -12,   212,    94,    77,   -10,   -10,   468,   433,
      86,   472,   631,    94,   115,    87,    88,    89,    95,   365,
     296,  -237,   269,     1,   199,   366,   296,    95,   319,   470,
     297,   298,   473,   119,     2,   373,   506,   298,   125,   268,
     320,   268,   268,   268,   268,   268,   268,   268,   268,   268,
     295,   -10,   299,   373,   127,   373,   129,   -12,   212,    47,
      77,   -12,   212,   133,    77,   177,   177,   212,   -20,   177,
     266,   373,   177,   439,    86,    81,   212,   141,   538,    87,
      88,    89,   541,   543,   142,   184,   214,   269,   224,   269,
     269,   269,   269,   269,   269,   269,   269,   269,   257,   258,
     184,   363,   364,    81,   382,   338,   396,   364,   226,   399,
     229,   408,   230,   -10,   402,   364,   235,   236,   202,   177,
     261,   269,   268,   -12,   212,   252,    77,   -18,   280,   262,
     -20,    77,   564,   177,   293,   177,   281,   -19,   177,   -66,
     181,   181,   282,   558,   181,   560,   286,   181,   283,   294,
     300,    91,   302,   305,  -192,  -193,   306,   310,    93,   309,
     312,   311,   313,   315,   314,   325,   323,   532,   555,   316,
     269,   317,    94,   177,   202,   177,   318,   177,   324,   177,
     177,   326,   177,   177,   327,   177,    95,   329,   335,   330,
     332,   337,   344,   341,   181,   346,   350,   586,   353,   355,
     358,   270,   270,   270,   367,   381,   368,   199,   181,   388,
     181,   177,   137,   181,   177,   177,   369,   382,   362,   391,
     411,   405,   199,   425,   268,   436,    94,   448,   450,   454,
     177,   177,   453,   456,   460,   177,   465,   459,   463,   177,
      95,   462,   464,   466,   474,   476,   478,   177,   181,   177,
     181,   177,   181,   481,   181,   181,   482,   181,   181,   177,
     181,   177,   177,    91,   177,   177,   483,   177,   484,   485,
      93,   486,   269,   487,   177,   184,   184,   177,   177,   184,
     632,   488,   184,   177,    94,   489,   181,   490,   491,   181,
     181,   492,   495,   504,   507,   270,   -71,   509,    95,   534,
     535,   537,   533,   544,   515,   181,   181,   545,   526,   546,
     181,   550,   552,   549,   181,   559,   561,   562,   568,  -172,
     553,   576,   181,   579,   181,   563,   181,   565,   566,   184,
     567,   580,   570,   573,   181,   578,   181,   181,   585,   181,
     181,   159,   181,   184,   589,   184,   591,   602,   184,   181,
     624,   610,   181,   181,   605,   608,   611,   617,   181,   612,
     270,   619,   270,   270,   270,   270,   270,   270,   270,   270,
     270,   613,   618,   620,   621,   626,   625,   630,   646,   647,
     648,   650,   649,   184,   659,   184,   652,   184,   634,   184,
     184,   636,   184,   184,   270,   184,   640,   199,   199,   655,
     665,   199,   658,   660,   199,   661,   668,   674,   520,   452,
     609,   387,   361,   536,   547,   531,   412,   417,   416,   442,
     443,   184,   414,   597,   184,   184,   415,   418,   421,   419,
     510,   584,   420,     5,    12,    62,    85,   256,    98,   493,
     184,   184,   588,   270,   108,   184,   423,   220,   426,   184,
     512,   199,   614,   522,   587,   505,   556,   184,   334,   184,
     345,   184,    13,   446,   513,   199,   494,   199,    73,   184,
     199,   184,   184,   255,   184,   184,   569,   184,   449,     0,
       0,     0,   274,   275,   184,   279,   351,   184,   184,   347,
       0,   451,     0,   184,     0,   292,     0,     0,     0,     0,
       0,   447,     0,     0,     0,   199,     0,   199,     0,   199,
       0,   199,   199,     0,   199,   199,   362,   199,     0,     0,
     599,     0,   600,   601,     0,   603,   604,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   199,     0,   270,   199,   199,     0,     0,
       0,     0,     0,     0,   627,     0,     0,   628,   629,     0,
       0,   522,   199,   199,     0,     0,     0,   199,     0,     0,
       0,   199,     0,   520,     0,     0,     0,     0,   531,   199,
       0,   199,   645,   199,   593,     0,     0,     0,     0,     0,
     569,   199,     0,   199,   199,     0,   199,   199,     0,   199,
       0,     0,   599,     0,   600,   601,   199,   603,   604,   199,
     199,   370,     0,   376,   377,   199,     0,   627,   522,     0,
     628,   629,     0,   522,     0,     0,   645,     0,     0,   401,
       0,     0,     0,     0,     0,   522,   410,     0,     0,   413,
       0,   637,     0,     0,     0,     0,   644,   522,     0,   522,
     522,     0,   522,   522,     0,     0,   424,     0,   651,     0,
       0,     0,   522,   427,     0,   522,   522,     0,     0,     0,
     662,   522,   663,   664,     0,   666,   667,     0,     0,     0,
       0,     0,     0,     0,     0,   671,     0,     0,   672,   673,
       0,     0,     0,     0,   675,     0,   455,     0,     0,     0,
       0,     0,   458,     0,   143,   144,     0,     0,     0,   145,
     146,   147,     0,   467,   427,     0,     0,   427,   148,     0,
     149,   150,  -162,   151,   152,   153,   154,   155,     0,   156,
       0,  -332,   157,   158,   159,     0,   160,   161,  -237,   162,
       1,   163,     0,     0,     0,  -332,     0,     0,     0,     0,
       0,     2,     0,     0,     0,     0,     0,     0,     0,   164,
       0,     0,     0,     0,     0,    45,   165,   166,     0,   292,
       0,     0,     0,     0,     0,     0,     0,     0,   143,   144,
       0,   514,     0,   145,   146,   147,     0,     0,     0,     0,
     527,     0,   148,   530,   149,   150,  -162,   151,   152,   153,
     154,   155,     0,   156,     0,  -332,   157,   158,   159,     0,
     160,   161,  -237,   162,     1,   163,     0,     0,     0,  -332,
       0,     0,     0,     0,     0,     2,   427,     0,     0,     0,
     143,   144,     0,   164,     0,   145,   146,   147,     0,    45,
    -322,   166,     0,     0,   148,     0,   149,   150,     0,   151,
     152,   153,   154,   155,     0,   156,     0,     0,   157,   158,
       0,     0,   160,   161,     0,   162,   467,   163,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   516,   144,   164,     0,     0,   145,   146,
     147,    45,     0,   166,     0,     0,   594,   148,   598,   149,
     150,     0,   151,   152,   153,   154,   517,     0,   518,     0,
       0,   519,   158,     0,     0,   160,   161,     0,   162,     0,
     163,     0,     0,     0,     0,     0,   623,     0,     0,     0,
       0,     0,     0,     0,   241,   144,     0,     0,   164,   145,
     146,   147,     0,     0,    45,     0,   166,     0,   148,     0,
     149,   150,  -162,     0,     0,   641,   643,     0,     0,     0,
       0,     0,     0,     0,   159,     0,   160,   161,     0,   162,
       0,   163,     0,     0,   241,   144,     0,     0,     0,   145,
     146,   147,     0,     0,     0,     0,     0,     0,   148,   164,
     149,   150,  -162,     0,     0,     0,     0,   371,     0,     0,
       0,     0,     0,     0,   159,     0,   160,   161,     0,   162,
       0,   163,     0,     0,   241,   144,     0,     0,     0,   145,
     146,   147,     0,     0,     0,     0,     0,     0,   148,   164,
     242,   150,     0,     0,     0,     0,     0,   595,   241,   144,
       0,     0,     0,   145,   146,   147,   160,   161,     0,   162,
       0,   163,   148,     0,   242,   150,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   164,
     160,   161,     0,   162,     0,   163,     0,   278,   241,   144,
       0,     0,     0,   145,   146,   147,     0,     0,     0,     0,
       0,     0,   148,   164,   242,   150,     0,     0,     0,     0,
       0,   457,   241,   144,     0,     0,     0,   145,   146,   147,
     160,   161,     0,   162,     0,   163,   148,     0,   242,   150,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   164,   160,   161,     0,   162,     0,   163,
       0,   529,   241,   144,     0,     0,     0,   145,   146,   147,
       0,     0,     0,     0,     0,     0,   148,   164,   242,   150,
       0,     0,     0,     0,     0,   622,   241,   144,     0,     0,
       0,   145,   146,   147,   160,   161,     0,   162,     0,   163,
     148,     0,   149,   150,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   164,   160,   161,
       0,   162,     0,   163,     0,   642,     0,     0,     0,   241,
     144,     0,     0,     0,   145,   146,   147,     0,     0,     0,
       0,   164,   524,   148,     0,   149,   150,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   160,   161,     0,   162,     0,   163,     0,     0,     0,
       0,     0,   241,   144,     0,     0,     0,   145,   146,   147,
       0,     0,     0,     0,   164,   571,   148,     0,   149,   150,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   160,   161,     0,   162,     0,   163,
       0,     0,     0,     0,     0,   241,   144,     0,     0,     0,
     145,   146,   147,     0,     0,     0,     0,   164,   574,   148,
       0,   149,   150,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   160,   161,     0,
     162,     0,   163,     0,     0,     0,     0,     0,   241,   144,
       0,     0,     0,   145,   146,   147,     0,     0,     0,     0,
     164,   606,   148,     0,   149,   150,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     160,   161,     0,   162,     0,   163,     0,     0,     0,     0,
       0,   241,   144,     0,     0,     0,   145,   146,   147,     0,
       0,     0,     0,   164,   638,   148,     0,   149,   150,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   160,   161,     0,   162,     0,   163,     0,
       0,     0,     0,     0,   241,   144,     0,     0,     0,   145,
     146,   147,     0,     0,     0,     0,   164,   653,   148,     0,
     149,   150,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   160,   161,     0,   162,
       0,   163,     0,     0,     0,     0,     0,   241,   144,     0,
       0,     0,   145,   146,   147,     0,     0,     0,     0,   164,
     656,   148,     0,   149,   150,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   160,
     161,     0,   162,     0,   163,     0,     0,     0,     0,     0,
     241,   144,     0,     0,     0,   145,   146,   147,     0,     0,
       0,     0,   164,   669,   148,     0,   242,   150,     0,     0,
       0,     0,     0,     0,   241,   144,     0,     0,     0,   145,
     146,   147,   160,   161,     0,   162,     0,   163,   148,     0,
     242,   150,     0,     0,     0,     0,     0,     0,     0,     0,
     326,     0,     0,     0,     0,   164,   160,   161,     0,   162,
       0,   163,     0,     0,   241,   144,     0,     0,     0,   145,
     146,   147,     0,   327,     0,     0,     0,     0,   148,   164,
     242,   150,     0,     0,     0,     0,     0,     0,   241,   144,
       0,     0,     0,   145,   146,   147,   160,   161,     0,   162,
       0,   163,   148,     0,   149,   150,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   164,
     160,   161,     0,   162,     0,   163,     0,     0,     0,     0,
      36,    37,     0,     0,     0,     0,  -267,    38,     0,     0,
       0,    39,     0,   164,    40,    41,    42,    43,    44,     0,
       0,     0,  -311,     0,    36,    37,     0,     0,     0,     0,
    -267,    38,    45,  -244,    46,    39,     0,     0,    40,    41,
      42,    43,    44,     0,     0,     0,  -311,     0,    36,    37,
       0,     0,     0,     0,  -267,    38,    45,  -361,    46,    39,
       0,     0,    40,    41,    42,    43,    44,     0,     0,     0,
    -311,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      45,  -348,    46
};

static const yytype_int16 yycheck[] =
{
      21,    83,    83,   281,   281,    61,     4,    60,   225,   163,
      52,   228,   300,    55,    55,   297,   332,    52,   476,   499,
      55,     0,   304,    20,     4,    34,    68,    52,   125,     4,
     559,    52,   561,    68,    55,    22,     4,    13,     4,   148,
     149,   150,    77,    68,    38,    52,    91,    68,    55,    94,
       4,    60,    39,     4,   141,   142,    77,    37,     4,     4,
     102,    68,    49,     9,    10,    11,     4,   102,     4,    67,
      77,     9,    10,    11,    30,    41,   117,    83,    75,     4,
      55,   102,    58,    31,     9,    10,    11,    55,   617,    55,
     619,   136,    46,    30,   115,   102,    41,    45,    35,     4,
       5,   559,   457,   561,     9,    10,    11,     4,   588,    65,
      55,    52,    58,     4,    55,    40,   103,   334,    17,     4,
      58,   163,   164,    55,    23,    24,    51,   172,    65,    40,
      55,    36,    37,   242,    39,    12,    41,    42,   125,    41,
      51,    65,   163,   240,    52,    36,    37,    52,    53,    57,
      55,     4,    65,    55,    59,   252,     9,    10,    11,   617,
     202,   619,    42,    62,    55,    42,     4,   202,    42,   214,
       4,   526,    52,    53,   529,    52,    53,   202,    52,   495,
     457,   202,   238,   460,    36,   266,    42,   341,     4,    41,
     148,   149,   150,    40,   236,   202,    52,   284,   285,   281,
     281,   236,    55,    55,    51,   226,   293,   294,   317,   296,
     297,   236,    83,     4,   301,   236,   303,   304,     9,    10,
      11,   576,   257,   258,   506,     4,   508,   262,     4,   236,
       9,    10,    11,     9,    10,    11,   257,   258,   148,   149,
     150,   262,   287,   288,   398,   533,   291,    59,    39,   526,
     257,   258,   529,   240,   341,   262,   544,   545,   546,   356,
     266,    40,    52,    39,     4,   252,    52,   622,    42,    42,
      53,    52,    51,    42,    55,   281,    55,    60,    52,    52,
      53,   390,    55,    52,   242,   640,    59,   642,   566,   566,
      33,    34,    57,   335,    65,    35,    67,    40,    65,   576,
     335,    44,   344,   658,    47,    48,    49,    50,    51,   344,
     335,    66,    52,    53,   335,    55,    56,    57,   383,   344,
       4,   386,   610,   344,    35,     9,    10,    11,   335,    61,
      42,    38,   242,    40,    83,    67,    42,   344,    22,   384,
      52,    53,   387,    56,    51,   622,    52,    53,    65,   307,
      34,   309,   310,   311,   312,   313,   314,   315,   316,   317,
     168,    42,   170,   640,    59,   642,    57,    52,    53,   356,
      55,    52,    53,     4,    55,   456,   457,    53,    59,   460,
      61,   658,   463,   341,     4,    52,    53,     4,   475,     9,
      10,    11,   479,   480,     4,   266,     4,   307,     4,   309,
     310,   311,   312,   313,   314,   315,   316,   317,    35,    36,
     281,    52,    53,    52,    53,   436,    52,    53,    43,   506,
       4,   508,     4,    42,    52,    53,    60,    57,   510,   510,
      56,   341,   390,    52,    53,    67,    55,    52,    59,    57,
      59,    55,    61,   524,    42,   526,    59,    52,   529,    52,
     456,   457,    59,   506,   460,   508,    52,   463,    59,    52,
      59,   503,    42,    53,    12,    12,    52,    62,   503,    14,
      64,    63,    15,    17,    16,    12,    67,   464,   503,    18,
     390,    19,   503,   564,   566,   566,    20,   568,    67,   570,
     571,    54,   573,   574,    53,   576,   503,    67,    59,    57,
      68,     4,    59,    65,   510,     4,    66,   552,    60,    20,
      66,   148,   149,   150,    67,    38,    67,   266,   524,     4,
     526,   602,   557,   529,   605,   606,    67,    53,   266,    60,
       4,    41,   281,    54,   492,    57,   557,     4,    57,    54,
     621,   622,    38,    60,    57,   626,     4,    61,    60,   630,
     557,    67,    60,     4,    52,    59,     4,   638,   564,   640,
     566,   642,   568,     4,   570,   571,    38,   573,   574,   650,
     576,   652,   653,   615,   655,   656,     4,   658,     4,    54,
     615,    38,   492,    60,   665,   456,   457,   668,   669,   460,
     615,    41,   463,   674,   615,     4,   602,     4,    54,   605,
     606,    61,    57,    57,    36,   242,    37,    37,   615,    54,
      53,     4,    59,    59,    67,   621,   622,    59,    67,    59,
     626,    34,    60,    52,   630,    59,    59,    66,    28,    28,
      57,    67,   638,     4,   640,    60,   642,    59,    59,   510,
      59,     4,    60,    60,   650,    60,   652,   653,    37,   655,
     656,    34,   658,   524,    36,   526,    36,    60,   529,   665,
      61,    59,   668,   669,    60,    60,    60,    59,   674,    60,
     307,    59,   309,   310,   311,   312,   313,   314,   315,   316,
     317,    60,    60,    60,    60,    60,    67,    60,    60,    46,
      60,    28,    60,   564,     4,   566,    60,   568,    67,   570,
     571,    67,   573,   574,   341,   576,    67,   456,   457,    60,
      60,   460,    67,    67,   463,    67,    60,    60,   456,   361,
     578,   288,   262,   471,   492,   463,   307,   312,   311,   341,
     341,   602,   309,   566,   605,   606,   310,   313,   316,   314,
     444,   548,   315,     0,     4,    23,    49,   134,    53,   426,
     621,   622,   555,   390,    56,   626,   322,   102,   330,   630,
     446,   510,   587,   456,   553,   436,   505,   638,   220,   640,
     232,   642,     4,   344,   448,   524,   429,   526,    29,   650,
     529,   652,   653,   132,   655,   656,   524,   658,   353,    -1,
      -1,    -1,   151,   152,   665,   154,   240,   668,   669,   236,
      -1,   356,    -1,   674,    -1,   164,    -1,    -1,    -1,    -1,
      -1,   347,    -1,    -1,    -1,   564,    -1,   566,    -1,   568,
      -1,   570,   571,    -1,   573,   574,   564,   576,    -1,    -1,
     568,    -1,   570,   571,    -1,   573,   574,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   602,    -1,   492,   605,   606,    -1,    -1,
      -1,    -1,    -1,    -1,   602,    -1,    -1,   605,   606,    -1,
      -1,   564,   621,   622,    -1,    -1,    -1,   626,    -1,    -1,
      -1,   630,    -1,   621,    -1,    -1,    -1,    -1,   626,   638,
      -1,   640,   630,   642,   564,    -1,    -1,    -1,    -1,    -1,
     638,   650,    -1,   652,   653,    -1,   655,   656,    -1,   658,
      -1,    -1,   650,    -1,   652,   653,   665,   655,   656,   668,
     669,   280,    -1,   282,   283,   674,    -1,   665,   621,    -1,
     668,   669,    -1,   626,    -1,    -1,   674,    -1,    -1,   298,
      -1,    -1,    -1,    -1,    -1,   638,   305,    -1,    -1,   308,
      -1,   621,    -1,    -1,    -1,    -1,   626,   650,    -1,   652,
     653,    -1,   655,   656,    -1,    -1,   325,    -1,   638,    -1,
      -1,    -1,   665,   332,    -1,   668,   669,    -1,    -1,    -1,
     650,   674,   652,   653,    -1,   655,   656,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   665,    -1,    -1,   668,   669,
      -1,    -1,    -1,    -1,   674,    -1,   365,    -1,    -1,    -1,
      -1,    -1,   371,    -1,     4,     5,    -1,    -1,    -1,     9,
      10,    11,    -1,   382,   383,    -1,    -1,   386,    18,    -1,
      20,    21,    22,    23,    24,    25,    26,    27,    -1,    29,
      -1,    31,    32,    33,    34,    -1,    36,    37,    38,    39,
      40,    41,    -1,    -1,    -1,    45,    -1,    -1,    -1,    -1,
      -1,    51,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,
      -1,    -1,    -1,    -1,    -1,    65,    66,    67,    -1,   438,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     4,     5,
      -1,   450,    -1,     9,    10,    11,    -1,    -1,    -1,    -1,
     459,    -1,    18,   462,    20,    21,    22,    23,    24,    25,
      26,    27,    -1,    29,    -1,    31,    32,    33,    34,    -1,
      36,    37,    38,    39,    40,    41,    -1,    -1,    -1,    45,
      -1,    -1,    -1,    -1,    -1,    51,   495,    -1,    -1,    -1,
       4,     5,    -1,    59,    -1,     9,    10,    11,    -1,    65,
      66,    67,    -1,    -1,    18,    -1,    20,    21,    -1,    23,
      24,    25,    26,    27,    -1,    29,    -1,    -1,    32,    33,
      -1,    -1,    36,    37,    -1,    39,   535,    41,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     4,     5,    59,    -1,    -1,     9,    10,
      11,    65,    -1,    67,    -1,    -1,   565,    18,   567,    20,
      21,    -1,    23,    24,    25,    26,    27,    -1,    29,    -1,
      -1,    32,    33,    -1,    -1,    36,    37,    -1,    39,    -1,
      41,    -1,    -1,    -1,    -1,    -1,   595,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     4,     5,    -1,    -1,    59,     9,
      10,    11,    -1,    -1,    65,    -1,    67,    -1,    18,    -1,
      20,    21,    22,    -1,    -1,   624,   625,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    34,    -1,    36,    37,    -1,    39,
      -1,    41,    -1,    -1,     4,     5,    -1,    -1,    -1,     9,
      10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    18,    59,
      20,    21,    22,    -1,    -1,    -1,    -1,    67,    -1,    -1,
      -1,    -1,    -1,    -1,    34,    -1,    36,    37,    -1,    39,
      -1,    41,    -1,    -1,     4,     5,    -1,    -1,    -1,     9,
      10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    18,    59,
      20,    21,    -1,    -1,    -1,    -1,    -1,    67,     4,     5,
      -1,    -1,    -1,     9,    10,    11,    36,    37,    -1,    39,
      -1,    41,    18,    -1,    20,    21,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,
      36,    37,    -1,    39,    -1,    41,    -1,    67,     4,     5,
      -1,    -1,    -1,     9,    10,    11,    -1,    -1,    -1,    -1,
      -1,    -1,    18,    59,    20,    21,    -1,    -1,    -1,    -1,
      -1,    67,     4,     5,    -1,    -1,    -1,     9,    10,    11,
      36,    37,    -1,    39,    -1,    41,    18,    -1,    20,    21,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    59,    36,    37,    -1,    39,    -1,    41,
      -1,    67,     4,     5,    -1,    -1,    -1,     9,    10,    11,
      -1,    -1,    -1,    -1,    -1,    -1,    18,    59,    20,    21,
      -1,    -1,    -1,    -1,    -1,    67,     4,     5,    -1,    -1,
      -1,     9,    10,    11,    36,    37,    -1,    39,    -1,    41,
      18,    -1,    20,    21,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,    36,    37,
      -1,    39,    -1,    41,    -1,    67,    -1,    -1,    -1,     4,
       5,    -1,    -1,    -1,     9,    10,    11,    -1,    -1,    -1,
      -1,    59,    60,    18,    -1,    20,    21,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    36,    37,    -1,    39,    -1,    41,    -1,    -1,    -1,
      -1,    -1,     4,     5,    -1,    -1,    -1,     9,    10,    11,
      -1,    -1,    -1,    -1,    59,    60,    18,    -1,    20,    21,
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
      -1,    -1,    -1,    -1,     4,     5,    -1,    -1,    -1,     9,
      10,    11,    36,    37,    -1,    39,    -1,    41,    18,    -1,
      20,    21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      54,    -1,    -1,    -1,    -1,    59,    36,    37,    -1,    39,
      -1,    41,    -1,    -1,     4,     5,    -1,    -1,    -1,     9,
      10,    11,    -1,    53,    -1,    -1,    -1,    -1,    18,    59,
      20,    21,    -1,    -1,    -1,    -1,    -1,    -1,     4,     5,
      -1,    -1,    -1,     9,    10,    11,    36,    37,    -1,    39,
      -1,    41,    18,    -1,    20,    21,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,
      36,    37,    -1,    39,    -1,    41,    -1,    -1,    -1,    -1,
      33,    34,    -1,    -1,    -1,    -1,    39,    40,    -1,    -1,
      -1,    44,    -1,    59,    47,    48,    49,    50,    51,    -1,
      -1,    -1,    55,    -1,    33,    34,    -1,    -1,    -1,    -1,
      39,    40,    65,    66,    67,    44,    -1,    -1,    47,    48,
      49,    50,    51,    -1,    -1,    -1,    55,    -1,    33,    34,
      -1,    -1,    -1,    -1,    39,    40,    65,    66,    67,    44,
      -1,    -1,    47,    48,    49,    50,    51,    -1,    -1,    -1,
      55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      65,    66,    67
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    40,    51,    70,    80,   156,   157,   158,   208,   209,
     220,     0,   158,   209,    38,    31,    45,     4,     4,     4,
      30,    35,    65,   159,   160,   162,    55,   200,   201,    65,
     210,     4,    76,     4,    75,    81,    33,    34,    40,    44,
      47,    48,    49,    50,    51,    65,    67,   133,   163,   164,
     165,   166,   167,   168,   174,   175,   176,   194,   195,   196,
     197,   198,   160,   162,   162,     4,    85,   202,    59,   221,
       4,   212,   214,   216,    52,    57,   161,    55,    82,    87,
      52,    52,   133,   134,    66,   163,     4,     9,    10,    11,
      71,    72,    73,    74,    81,    83,    40,    51,   167,     4,
      39,    71,    85,   177,   179,    40,    44,    51,   175,   199,
     200,    40,    51,   197,   162,    35,    86,    57,   203,    56,
      71,   222,   223,   225,   226,    65,   227,    59,   217,    57,
     211,   215,   216,     4,    76,    58,    72,    74,    88,    90,
      91,     4,     4,     4,     5,     9,    10,    11,    18,    20,
      21,    23,    24,    25,    26,    27,    29,    32,    33,    34,
      36,    37,    39,    41,    59,    66,    67,    74,    76,    77,
      78,    79,    81,    83,    94,    95,    96,    98,    99,   105,
     106,   107,   111,   112,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   135,   136,   137,   139,   141,   142,   143,   144,   145,
     146,   156,    53,    84,     4,   169,   171,   173,    84,    84,
     179,    67,   133,   193,     4,   180,    43,   178,   189,     4,
       4,    81,    85,     4,    46,    60,    57,   224,   164,   228,
     229,     4,    20,    98,   107,   108,   109,   116,   117,   132,
     102,   162,    67,   213,   218,   215,   161,    35,    36,    92,
      93,    56,    57,    89,    82,    82,    61,    97,    77,   105,
     106,   130,   130,   130,   116,   116,     4,    67,    67,   116,
      59,    59,    59,    59,    42,    52,    52,    72,    81,    87,
     100,    72,   116,    42,    52,    97,    42,    52,    53,    97,
      59,    42,    42,    42,    52,    53,    52,    13,    58,    14,
      62,    63,    64,    15,    16,    17,    18,    19,    20,    22,
      34,    71,   138,    67,    67,    12,    54,    53,    84,    67,
      57,   170,    68,   172,   180,    59,   178,     4,    81,   190,
     192,    65,   204,   178,    59,   203,     4,   225,   197,   230,
      66,   228,   130,    60,   110,    20,   164,   219,    66,    74,
      74,    90,   139,    52,    53,    61,    67,    67,    67,    67,
     116,    67,   137,   142,   148,   149,   116,   116,    82,     4,
      82,    38,    53,    84,   113,   115,    84,   113,     4,   103,
      60,    60,    82,    36,    37,    82,    52,    82,    41,    82,
      99,   116,    52,   108,    82,    41,    82,     4,    82,    99,
     116,     4,   121,   116,   124,   125,   122,   123,   126,   127,
     128,   129,   130,   169,   116,    54,   171,   116,   151,   152,
     153,   155,   178,    71,   181,   183,    57,   191,    59,    77,
      82,    87,    94,   100,   206,   207,   181,   224,     4,   217,
      57,   219,    89,    38,    54,   116,    60,    67,   116,    61,
      57,   150,    67,    60,    60,     4,     4,   116,   151,   155,
      84,   114,   151,    84,    52,   104,    59,   130,     4,    42,
      52,     4,    38,     4,     4,    54,    38,    60,    41,     4,
       4,    54,    61,   170,   211,    57,   154,     4,    37,   136,
     182,   184,   186,   187,    57,   192,    52,    36,    52,    37,
     134,   205,   182,   204,   116,    67,     4,    27,    29,    32,
     139,   140,   141,   147,    60,   149,    67,   116,   142,    67,
     116,   139,   133,    59,    54,    53,   115,     4,    82,   101,
     109,    82,     4,    82,    59,    59,    59,   119,   155,    52,
      34,   187,    60,    57,   185,    71,   191,    55,   200,    59,
     200,    59,    66,    60,    61,    59,    59,    59,    28,   139,
      60,    60,   149,    60,    60,   149,    67,   108,    60,     4,
       4,   108,   108,   108,   154,    37,    84,   186,   173,    36,
     101,    36,   101,   140,   116,    67,   137,   148,   116,   139,
     139,   139,    60,   139,   139,    60,    60,   149,    60,   102,
      59,    60,    60,    60,   185,   187,   188,    59,    60,    59,
      60,    60,    67,   116,    61,    67,    60,   139,   139,   139,
      60,   108,    71,   101,    67,   101,    67,   140,    60,   149,
      67,   116,    67,   116,   140,   139,    60,    46,    60,    60,
      28,   140,    60,    60,   149,    60,    60,   149,    67,     4,
      67,    67,   140,   140,   140,    60,   140,   140,    60,    60,
     149,   140,   140,   140,    60,   140
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    69,    70,    71,    71,    72,    72,    73,    73,    74,
      74,    74,    75,    75,    76,    76,    77,    77,    78,    78,
      79,    80,    80,    81,    81,    81,    82,    82,    83,    83,
      83,    84,    84,    85,    85,    86,    86,    87,    88,    89,
      89,    90,    90,    91,    92,    92,    93,    93,    94,    94,
      95,    95,    95,    95,    95,    95,    95,    95,    95,    95,
      96,    96,    96,    96,    96,    97,    97,    98,    98,    98,
      99,   100,   100,   101,   101,   102,   102,   103,   104,   104,
      82,    82,   105,   105,   105,   106,   106,   107,   107,   107,
     107,   107,   107,   108,   108,    82,    82,   109,   110,   110,
     111,   111,   111,   111,   111,   111,   111,   112,   112,   112,
     112,   112,   112,   113,   114,   114,   115,   116,   117,   117,
     118,   118,    77,    77,   119,   119,   120,   120,   121,   121,
     122,   122,   123,   123,   124,   124,   125,   125,   126,   126,
     127,   127,   128,   128,   129,   129,   130,   130,   130,   130,
     130,   131,   132,   132,   132,   133,   134,   134,   135,   135,
     135,   136,   136,   137,   138,   138,   139,   139,   139,   139,
     139,   139,   140,   140,   140,   140,   140,   141,   141,   141,
     141,   141,   141,   141,   141,   141,   142,   142,   142,   142,
     142,   143,   143,   143,   144,   144,   145,   145,   146,   146,
     146,   146,   146,   146,   146,   146,   146,   147,   147,   147,
     147,   147,   147,   147,   147,   147,   148,   148,   149,   150,
     150,   151,   152,   152,   153,   154,   154,   155,   155,   156,
     156,   156,   157,   157,   157,   157,   158,   158,   159,   160,
     161,   161,   162,   163,   163,   164,   164,   164,   164,   165,
     165,   165,   166,   167,   167,   168,   168,   169,   170,   170,
     171,   172,   172,   173,   173,   174,   175,   175,   176,   176,
     176,   176,   176,   176,   176,   176,   176,   177,   177,   178,
     178,   179,   179,   180,   180,   181,   181,   182,   182,   183,
     183,   184,   185,   185,   186,   187,   187,   136,   188,   189,
     190,   191,   191,   192,   192,   193,   193,   194,   195,   196,
     197,   197,   198,   198,   199,   200,   200,   201,   202,   203,
     203,   204,   205,   205,   206,   206,   207,   207,   207,   207,
     208,   209,   209,   210,   211,   211,   212,   212,   213,   213,
     214,   215,   215,   216,   217,   217,   218,   219,   219,   220,
     221,   222,   222,   223,   224,   224,   225,   225,   226,   227,
     228,   228,   229,   230
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     2,     4,     4,     1,     0,     2,     2,
       2,     2,     3,     2,     1,     2,     2,     3,     2,     3,
       0,     1,     1,     2,     1,     0,     2,     2,     1,     1,
       1,     1,     1,     3,     3,     1,     1,     1,     1,     1,
       0,     4,     4,     4,     3,     3,     0,     1,     3,     3,
       7,     1,     0,     1,     0,     1,     0,     3,     2,     0,
       1,     0,     3,     3,     5,     4,     4,     4,     7,     7,
       7,     7,     9,     1,     0,     1,     0,     2,     3,     0,
       4,     4,     4,     4,     6,     4,     3,     4,     3,     4,
       3,     4,     4,     2,     2,     0,     3,     1,     1,     3,
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
       1,     1,     4,     2,     0,     1,     1,     2,     3,     0,
       2,     2,     0,     2,     1,     3,     2,     0,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     4,     2,
       0,     1,     1,     6,     5,     2,     0,     1,     0,     4,
       2,     2,     3,     0,     4,     2,     0,     1,     4,     2,
       2,     3,     0,     1,     1,     1,     1,     1,     2,     4,
       2,     0,     1,     1,     6,     1,     0,     3,     2,     3,
       2,     4,     1,     0,     1,     0,     6,     6,     8,     8,
       4,     2,     0,     5,     1,     0,     1,     0,     1,     0,
       2,     2,     0,     3,     4,     0,     2,     2,     0,     6,
       3,     1,     0,     2,     3,     0,     2,     1,     3,     3,
       2,     0,     2,     3
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
#line 2217 "parser.tab.c"
    break;


#line 2221 "parser.tab.c"

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

#line 803 "parser.y"


int main(){
    if(yyparse()) return 0;
    
    return 0;
}
