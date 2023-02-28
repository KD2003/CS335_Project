/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    KEYWORD = 258,                 /* KEYWORD  */
    IDENTIFIER = 259,              /* IDENTIFIER  */
    LITERAL = 260,                 /* LITERAL  */
    OPERATOR = 261,                /* OPERATOR  */
    INTTYPE = 262,                 /* INTTYPE  */
    FPTYPE = 263,                  /* FPTYPE  */
    BOOLTYPE = 264,                /* BOOLTYPE  */
    ASSIGNOP = 265,                /* ASSIGNOP  */
    CONDOR = 266,                  /* CONDOR  */
    CONDAND = 267,                 /* CONDAND  */
    EQALITYOP = 268,               /* EQALITYOP  */
    RELATIONOP = 269,              /* RELATIONOP  */
    SHIFTOP = 270,                 /* SHIFTOP  */
    ADDOP = 271,                   /* ADDOP  */
    MULTOP = 272,                  /* MULTOP  */
    ADDOP2 = 273,                  /* ADDOP2  */
    UNARYOP = 274,                 /* UNARYOP  */
    KEY_VAR = 275,                 /* KEY_VAR  */
    KEY_assert = 276,              /* KEY_assert  */
    KEY_yield = 277,               /* KEY_yield  */
    KEY_throw = 278,               /* KEY_throw  */
    KEY_break = 279,               /* KEY_break  */
    KEY_continue = 280,            /* KEY_continue  */
    KEY_return = 281,              /* KEY_return  */
    KEY_if = 282,                  /* KEY_if  */
    KEY_else = 283,                /* KEY_else  */
    KEY_for = 284,                 /* KEY_for  */
    KEY_permits = 285,             /* KEY_permits  */
    KEY_while = 286,               /* KEY_while  */
    KEY_sync = 287,                /* KEY_sync  */
    KEY_final = 288,               /* KEY_final  */
    KEY_extends = 289,             /* KEY_extends  */
    KEY_super = 290,               /* KEY_super  */
    KEY_this = 291,                /* KEY_this  */
    KEY_class = 292,               /* KEY_class  */
    KEY_void = 293,                /* KEY_void  */
    KEY_public = 294,              /* KEY_public  */
    KEY_new = 295,                 /* KEY_new  */
    KEY_static = 296,              /* KEY_static  */
    DOT3 = 297,                    /* DOT3  */
    KEY_private = 298,             /* KEY_private  */
    KEY_import = 299               /* KEY_import  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 17 "parser.y"

    std::string *st;
    ASTNode *ptr;

#line 113 "parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;

int yyparse (void);


#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
