%{
#include <iostream>
#include <string>
using namespace std;

int yylex();
int yyerror(const char *str);

%}

%locations
%token KEYWORD IDENTIFIER LITERAL OPERATOR INTTYPE FPTYPE BOOLTYPE ASSIGNOP CONDOR CONDAND EQALITYOP RELATIONOP SHIFTOP ADDOP MULTOP ADDOP2 UNARYOP KEY_VAR KEY_assert KEY_yiethr KEY_brecon KEY_return KEY_if KEY_else KEY_for KEY_permits KEY_record KEY_while KEY_sync KEY_final KEY_extends KEY_super KEY_this KEY_class KEY_void KEY_public KEY_new COLON2 KEY_throws KEY_static KEY_enum DOT3 KEY_abstract KEY_native KEY_strictf KEY_protected KEY_private

%type <lit> LITERAL 

%union{
    std::string *lit;
}

%%
prog:
    ClassDeclaration		{cout << "Program Completed\n";}
;

// §4 (Types, Values, and Variables) Start
Type:
    PrimitiveType
    | ArrayType
;

PrimitiveType:
    NumericType
    | BOOLTYPE
;

NumericType:
    INTTYPE
    | FPTYPE
;

IDENdotIDEN:
    IDENdotIDEN '.' IDENTIFIER
    | IDENTIFIER
;

PublicPrivate:
    KEY_public | KEY_private
;

ClassType:
    IDENdotIDEN
;

ArrayType:
    PrimitiveType Dims
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
    | ClassLiteral
    | KEY_this
    | IDENdotIDEN '.' KEY_this
    | '(' Expression ')'  
    | ClassInstanceCreationExpression
    | FieldAccess
    | ArrayAccess
    | MethodInvocation
    | MethodReference
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
    UnqualifiedClassInstanceCreationExpression
    | IDENdotIDEN '.' UnqualifiedClassInstanceCreationExpression
    | Primary '.' UnqualifiedClassInstanceCreationExpression
;


UnqualifiedClassInstanceCreationExpression:
    KEY_new IDENdotIDEN '(' Zeroorone_ArgumentList ')' ZerooroneClassBody
;

Zeroorone_ArgumentList:
    ArgumentList | 
;

ZerooroneClassBody:
    ClassBody | 
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
    Expression Zeroormore_CommaExpression
;

Zeroormore_CommaExpression:
    Zeroormore_CommaExpression ',' Expression
    | 
;

MethodReference:
    IDENdotIDEN COLON2  IDENTIFIER
    | Primary COLON2 IDENTIFIER
    | KEY_super COLON2 IDENTIFIER
    | IDENdotIDEN '.' KEY_super COLON2 IDENTIFIER
    | ClassType COLON2 KEY_new
    | ArrayType COLON2 KEY_new
;


ArrayCreationExpression:
    KEY_new PrimitiveType DimExprs Dims
    | KEY_new PrimitiveType DimExprs
    | KEY_new PrimitiveType Dims ArrayInitializer
;

DimExprs:
    DimExprs DimExpr | DimExpr
;

DimExpr:
    '[' Expression ']'
;

Expression:
    AssignmentExpression
;

AssignmentExpression:
    ConditionalExpression
    | LeftHandSide ASSIGNOP Expression		// or Assignment
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
    | PostfixExpression
    | UNARYOP UnaryExpression
    | CastExpression
;

CastExpression:
    '(' PrimitiveType ')' UnaryExpression
;

PostfixExpression:
    Primary
    | IDENdotIDEN
    | Primary ADDOP2
    | IDENdotIDEN ADDOP2
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
    ClassDeclaration
    | LocalVariableDeclaration ';'
    | Statement
;

LocalVariableDeclaration:
    VariableModifier LocalVariableType VariableDeclaratorList
;

LocalVariableType:
    Type
    | ClassType
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
    AssignmentExpression
    | MethodInvocation
    | ClassInstanceCreationExpression
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
    KEY_for '(' ';' ';' ')' Statement
    | KEY_for '(' ForInit ';' ';' ')' Statement
    | KEY_for '(' ';' Expression ';' ')' Statement
    | KEY_for '(' ';' ';' StatementExpressionList ')' Statement
    | KEY_for '(' ';' Expression ';' StatementExpressionList ')' Statement
    | KEY_for '(' ForInit ';' Expression ';' ')' Statement
    | KEY_for '(' ForInit ';' ';' StatementExpressionList ')' Statement
    | KEY_for '(' ForInit ';' Expression ';' StatementExpressionList ')' Statement
    | KEY_for '(' LocalVariableDeclaration ':' Expression ')' Statement
;

ForStatementNoShortIf:
    KEY_for '(' ';' ';' ')' StatementNoShortIf
    | KEY_for '(' ForInit ';' ';' ')' StatementNoShortIf
    | KEY_for '(' ';' Expression ';' ')' StatementNoShortIf
    | KEY_for '(' ';' ';' StatementExpressionList ')' StatementNoShortIf
    | KEY_for '(' ';' Expression ';' StatementExpressionList ')' StatementNoShortIf
    | KEY_for '(' ForInit ';' Expression ';' ')' StatementNoShortIf
    | KEY_for '(' ForInit ';' ';' StatementExpressionList ')' StatementNoShortIf
    | KEY_for '(' ForInit ';' Expression ';' StatementExpressionList ')' StatementNoShortIf
    | KEY_for '(' LocalVariableDeclaration ':' Expression ')' StatementNoShortIf
;

ForInit:
    StatementExpressionList
    | LocalVariableDeclaration
;

StatementExpressionList:
    StatementExpression StatementExpressionMore
;

StatementExpressionMore:
    StatementExpressionMore ',' StatementExpression |
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
    ClassModifiers KEY_class IDENTIFIER ClassBody
    | ClassModifiers KEY_class IDENTIFIER ClassExtends ClassBody
    | ClassModifiers KEY_class IDENTIFIER ClassPermits ClassBody
    | ClassModifiers KEY_class IDENTIFIER ClassExtends ClassPermits ClassBody
;
ClassModifiers:
    ClassModifiers PublicPrivate |
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
    FieldDeclaration
    | ';'
    | Block
    | ConstructorDeclaration
    | MethodDeclaration
;
FieldDeclaration:
    ConstructorModifiers Type VariableDeclaratorList ';'
;

VariableDeclaratorList:
    VariableDeclarator cVariableDeclarator
;
cVariableDeclarator:
    cVariableDeclarator ',' VariableDeclarator 
    |
;
VariableDeclarator:
    VariableDeclaratorId '=' VariableInitializer
    | VariableDeclaratorId
;

VariableDeclaratorId:
    IDENTIFIER Dims
    | IDENTIFIER
;

MethodConstructor:
    
;

MethodDeclaration:
    ConstructorModifiers Methodmodifiers MethodHeader MethodBody
;

Methodmodifiers:
    Methodmodifiers Methodmodifier |
;

Methodmodifier:
    KEY_protected | KEY_abstract | KEY_static | KEY_final | KEY_sync | KEY_native | KEY_strictf //Keywords mein change karna hain
;

MethodHeader:
    Result Methodeclarator
;

Result:
    PrimitiveType
    | VariableDeclaratorId
    | PrimitiveType Dims
    | KEY_void 
;

Methodeclarator:
    IdenPara Dims
    | IdenPara
;

IdenPara:
    IDENTIFIER '(' formalparameters ')'
;
formalparameters:
    formalparameterlist
    |
;

formalparameterlist:
    formalparameter cformalparameter
;
cformalparameter:
    cformalparameter ',' formalparameter |
;
formalparameter:
    VariableModifier Type VariableDeclaratorId
    | VariableArityParameter
;

VariableModifier:
    VariableModifier KEY_final |
;
VariableArityParameter:
    VariableModifier Type DOT3 IDENTIFIER
;

MethodBody:
    Block
    | ';'
;
ConstructorDeclaration:
    ConstructorModifiers IdenPara ConstructorBody
;
ConstructorModifiers:
    PublicPrivate | 
;

ConstructorBody:
    '{' zerooroneExplicitConstructorInvocation BlockStatements '}'
;

zerooroneExplicitConstructorInvocation:
    ExplicitConstructorInvocation |
;
ExplicitConstructorInvocation:
    KEY_this '(' Zeroorone_ArgumentList ')' ';'
    | KEY_super '(' Zeroorone_ArgumentList ')' ';'
    | IDENdotIDEN '.' KEY_super '(' Zeroorone_ArgumentList ')' ';'
    | Primary '.' KEY_super '(' Zeroorone_ArgumentList ')' ';'
;

// Class and Method END
%%

int main(){
    if(yyparse()) return 0;
    
    return 0;
}