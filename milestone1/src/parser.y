%{
#include <iostream>
#include <string>
#include "AST.h"
using namespace std;

int yylex();
int yyerror(const char *str);

%}

%locations
%token KEYWORD IDENTIFIER LITERAL OPERATOR INTTYPE FPTYPE BOOLTYPE ASSIGNOP CONDOR CONDAND EQALITYOP RELATIONOP SHIFTOP ADDOP MULTOP ADDOP2 UNARYOP KEY_VAR KEY_assert KEY_yiethr KEY_brecon KEY_return KEY_if KEY_else KEY_for KEY_permits KEY_while KEY_sync KEY_final KEY_extends KEY_super KEY_this KEY_class KEY_void KEY_public KEY_new KEY_static DOT3 KEY_abstract KEY_native KEY_strictf KEY_private KEY_import

%type <lit> LITERAL 

%union{
    std::string *lit;
}

%%
prog:
    ImportList ClassDeclarationList		{cout << "Program Completed\n";}
;

ImportList:
    ImportList Imports
    |
;

ClassDeclarationList:
    ClassDeclarationList ClassDeclaration
    | ClassDeclaration
;

Imports:
    KEY_import IDENdotIDEN ';'
    | KEY_import KEY_static IDENdotIDEN ';'
    | KEY_import IDENdotIDEN '.' '*' ';'
    | KEY_import KEY_static IDENdotIDEN '.' '*' ';'
;

// §4 (Types, Values, and Variables) Start
Type:
    PrimitiveType
    | ArrayType
    | ClassType
;

PrimitiveType:
    INTTYPE
    | FPTYPE
    | BOOLTYPE
;

IDENdotIDEN:
    IDENdotIDEN '.' IDENTIFIER
    | IDENTIFIER
;

PublicPrivateStatic:
    KEY_public | KEY_private | KEY_static
;

ClassType:
    IDENdotIDEN
;

ArrayType:
    PrimitiveType Dims
    | ClassType Dims
;
Dims:
    '[' ']'
    | Dims '[' ']'
;

// §4 (Types, Values, and Variables) END

//Productions from §15 (Expressions) START
Primary:
    PrimaryNoNewArray
    | ArrayCreationExpression
;

PrimaryNoNewArray:
    LITERAL
    /* | ClassLiteral */
    | KEY_this
    | IDENdotIDEN '.' KEY_this
    | '(' Expression ')'  
    | ClassInstanceCreationExpression
    | FieldAccess
    | ArrayAccess
    | MethodInvocation
;

ClassLiteral: //confirm once
    IDENdotIDEN Zero_or_moreSquarebracket '.' KEY_class
    | PrimitiveType Zero_or_moreSquarebracket '.' KEY_class
    | KEY_void '.' KEY_class
;

Zero_or_moreSquarebracket:
    Zero_or_moreSquarebracket '[' ']'
    |   
;

ClassInstanceCreationExpression:
    KEY_new IDENdotIDEN '(' Zeroorone_ArgumentList ')' ClassBody
    | KEY_new IDENdotIDEN '(' Zeroorone_ArgumentList ')'
;

Zeroorone_ArgumentList:
    ArgumentList | 
;

FieldAccess:
    Primary '.' IDENTIFIER  
    | KEY_super '.' IDENTIFIER
    | IDENdotIDEN '.' KEY_super '.' IDENTIFIER
;

ArrayAccess:
    IDENdotIDEN '[' Expression ']'
    | PrimaryNoNewArray '[' Expression ']'
;

MethodInvocation:
    IDENdotIDEN '(' Zeroorone_ArgumentList ')'
    | Primary '.' IDENTIFIER '(' Zeroorone_ArgumentList ')'
    | KEY_super '.' IDENTIFIER '(' Zeroorone_ArgumentList ')'
    | IDENdotIDEN '.' KEY_super '.' IDENTIFIER '(' Zeroorone_ArgumentList ')'
;

ArgumentList:
    ArgumentList ',' Expression
    | Expression
;

ArrayCreationExpression:        // array initiaizer to do
    KEY_new PrimitiveType DimExpr Dims
    | KEY_new PrimitiveType DimExpr
    | KEY_new IDENdotIDEN DimExpr Dims
    | KEY_new IDENdotIDEN DimExpr
    /* | KEY_new PrimitiveType Dims ArrayInitializer */
;

DimExpr:
    DimExpr '[' Expression ']'
    | '[' Expression ']'
;

Expression:
    AssignmentExpression
;

AssignmentExpression:
    ConditionalExpression
    | Assignment
;

Assignment:
    LeftHandSide ASSIGNOP Expression		// or Assignment
    | LeftHandSide '=' Expression
;

ConditionalExpression:
    ConditionalOrExpression
    | ConditionalOrExpression '?' Expression ':' ConditionalExpression
;

ConditionalOrExpression:
    ConditionalAndExpression
    | ConditionalOrExpression CONDOR ConditionalAndExpression
;

ConditionalAndExpression:
    InclusiveOrExpression
    | ConditionalAndExpression CONDAND InclusiveOrExpression
;

AndExpression:
    EqualityExpression
    | AndExpression '&' EqualityExpression
;

ExclusiveOrExpression:
    AndExpression
    | ExclusiveOrExpression '^' AndExpression
;

InclusiveOrExpression:
    ExclusiveOrExpression
    | InclusiveOrExpression '|' ExclusiveOrExpression
;

EqualityExpression:
    RelationalExpression
    | EqualityExpression EQALITYOP RelationalExpression
;

RelationalExpression:
    ShiftExpression
    | RelationalExpression RELATIONOP ShiftExpression
;

ShiftExpression:
    AdditiveExpression
    | ShiftExpression SHIFTOP AdditiveExpression
;

AdditiveExpression:
    MultiplicativeExpression
    | AdditiveExpression ADDOP MultiplicativeExpression
;

MultiplicativeExpression:
    UnaryExpression
    | MultiplicativeExpression MULTOP UnaryExpression
;

UnaryExpression:
    ADDOP2 UnaryExpression
    | ADDOP UnaryExpression
    | UnaryExpressionNotPlusMinus
    | CastExpression
;

UnaryExpressionNotPlusMinus:
    PostfixExpression
    | UNARYOP UnaryExpression
;

CastExpression:
    '(' PrimitiveType ')' UnaryExpression
;

PostfixExpression:
    Primary
    | IDENdotIDEN
    | PostfixExpression ADDOP2
;
// 15 end

// Productions from §14 (Blocks, Statements, and Patterns)

Block:
    '{' BlockStatements '}'
;

BlockStatements:
    BlockStatements BlockStatement | 
;

BlockStatement:
    LocalVariableDeclaration ';'
    | Statement
;

LocalVariableDeclaration:
    LocalVariableType VariableDeclaratorList   {cout << "local var dec";}
;

LocalVariableType:
    Type        {cout <<"type";}
    | KEY_VAR
;

Statement:
    StatementWithoutTrailingSubstatement
    | IDENTIFIER ':' Statement
    | KEY_if '(' Expression ')' Statement
    | KEY_if '(' Expression ')' StatementNoShortIf KEY_else Statement 
    | KEY_while '(' Expression ')' Statement
    | ForStatement
;

StatementNoShortIf:
    StatementWithoutTrailingSubstatement
    | IDENTIFIER ':' StatementNoShortIf
    | KEY_if '(' Expression ')' StatementNoShortIf KEY_else StatementNoShortIf 
    | KEY_while '(' Expression ')' StatementNoShortIf 
    | ForStatementNoShortIf
;

StatementWithoutTrailingSubstatement:		// left try statement
    Block
    | ';'
    | StatementExpression ';'
    | AssertStatement
    | BreakContinueStatement
    | KEY_return ';'
    | KEY_return Expression ';'
    | KEY_yiethr Expression ';'
    | KEY_sync '(' Expression ')' Block
;

StatementExpression:
    Assignment
    | MethodInvocation
    | ADDOP2 UnaryExpression
    | PostfixExpression ADDOP2
    /* | ClassInstanceCreationExpression */
;

LeftHandSide:
    IDENdotIDEN
    | FieldAccess
    | ArrayAccess
;

AssertStatement:
    KEY_assert Expression ';'
    | KEY_assert Expression ':' Expression ';'
;

BreakContinueStatement:
    KEY_brecon IDENTIFIER ';'
    | KEY_brecon ';'
;

ForStatement:
    KEY_for '(' ForInit ';' ';' ')' Statement
    | KEY_for '(' ForInit ';' Expression ';' ')' Statement
    | KEY_for '(' ForInit ';' ';' StatementExpressionList ')' Statement
    | KEY_for '(' ForInit ';' Expression ';' StatementExpressionList ')' Statement
    /* | KEY_for '(' LocalVariableDeclaration ':' Expression ')' Statement */
;

ForStatementNoShortIf:
    KEY_for '(' ForInit ';' ';' ')' StatementNoShortIf
    | KEY_for '(' ForInit ';' Expression ';' ')' StatementNoShortIf
    | KEY_for '(' ForInit ';' ';' StatementExpressionList ')' StatementNoShortIf
    | KEY_for '(' ForInit ';' Expression ';' StatementExpressionList ')' StatementNoShortIf
    /* | KEY_for '(' LocalVariableDeclaration ':' Expression ')' StatementNoShortIf */
;

ForInit:
    StatementExpressionList
    | LocalVariableDeclaration
    |
;

StatementExpressionList:
    StatementExpressionList ',' StatementExpression
    | StatementExpression
;

// 14 end

// §10 (Arrays) START
ArrayInitializer:
    '{' zerooroneVariableInitializerList ',' '}'
    | '{' zerooroneVariableInitializerList '}'
;
zerooroneVariableInitializerList:
    VariableInitializerList
    | 
;
VariableInitializerList:
    VariableInitializer cVariableInitializer
;

cVariableInitializer:
    cVariableInitializer ',' VariableInitializer |
;

VariableInitializer:
    Expression
    | ArrayInitializer
;
// §10 (Arrays) END

//Classes
ClassDeclaration:
    NormalClassDeclaration
;
NormalClassDeclaration:
    Modifiers KEY_class IDENTIFIER ClassBody
    | Modifiers KEY_class IDENTIFIER ClassExtends ClassBody
    | Modifiers KEY_class IDENTIFIER ClassPermits ClassBody
    | Modifiers KEY_class IDENTIFIER ClassExtends ClassPermits ClassBody
;
ClassExtends:
    KEY_extends ClassType
;
ClassPermits:
    KEY_permits IDENdotIDEN cTypeName
;

cTypeName:
    cTypeName ',' IDENdotIDEN | 
;

ClassBody:
    '{' ClassBodyDeclarations '}'
;
ClassBodyDeclarations:
    ClassBodyDeclarations ClassBodyDeclaration
    | 
;
ClassBodyDeclaration:
    Modifiers Type VariableDeclaratorList ';'
    | ClassDeclaration
    | ';'
    | Block
    | Modifiers IdenPara Block
    | MethodDeclaration
;

VariableDeclaratorList:
    VariableDeclaratorList ',' VariableDeclarator
    | VariableDeclarator
;

VariableDeclarator:
    VariableDeclarator1
    | VariableDeclarator2
;

zerooroneExpression:
    Expression | 
;

VariableDeclarator1:
    IDENTIFIER
    | IDENTIFIER '[' zerooroneExpression ']'
    | IDENTIFIER '[' zerooroneExpression ']' '[' zerooroneExpression ']'
    | IDENTIFIER '[' zerooroneExpression ']' '[' zerooroneExpression ']' '[' zerooroneExpression ']'
;

VariableDeclarator2:
    IDENTIFIER '=' Expression
    | IDENTIFIER '[' zerooroneExpression ']' '=' List1
    | IDENTIFIER '[' zerooroneExpression ']' '[' zerooroneExpression ']' '=' List2
    | IDENTIFIER '[' zerooroneExpression ']' '[' zerooroneExpression ']' '[' zerooroneExpression ']' '=' List3
;

List1:
    '{' ArrEle1 '}'
;

ArrEle1:
    ArrEle1 ',' Expression
    | Expression
;

List2:
    '{' ArrEle2 '}'
;

ArrEle2:
    ArrEle2 ',' List1
    | List1
;

List3:
    '{' ArrEle3 '}'
;

ArrEle3:
    ArrEle3 ',' List2
    | List2
;

MethodDeclaration:
    Modifiers MethodHeader MethodBody
;

/* Methodmodifiers:
    Methodmodifiers Methodmodifier |
; */

/* Methodmodifier:
    KEY_abstract | KEY_static | KEY_final | KEY_sync | KEY_native | KEY_strictf //Keywords mein change karna hain
; */

MethodHeader:
    Type Methodeclarator      {cout << "MethodHeader";}
    | KEY_void Methodeclarator
;

Methodeclarator:
    IdenPara Dims
    | IdenPara
;

IdenPara:
    IDENTIFIER '(' formalparameters ')'
    | IDENTIFIER '(' ')'
;
formalparameters:
    formalparameters ',' formalparameter
    | formalparameter
;

formalparameter:
    Type VariableDeclarator1
    | Type DOT3 IDENTIFIER
;

VariableModifier:
    KEY_final |
;

MethodBody:
    Block       {cout <<"MEthodBlock";}
    | ';'       {cout << "MethodBody;";}
;

Modifiers:
    Modifiers PublicPrivateStatic | 
;

// Class and Method END
%%

int main(){
    if(yyparse()) return 0;
    
    return 0;
}