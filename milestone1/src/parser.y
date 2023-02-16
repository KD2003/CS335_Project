%{
#include <iostream>
#include <string>
using namespace std;

int yylex();
int yyerror(const char *str);

%}

%locations
%token KEYWORD IDENTIFIER LITERAL ESCSEQ OPERATOR SEP INTTYPE FPTYPE BOOLTYPE ASSIGNOP CONDOR CONDAND EQALITYOP RELATIONOP SHIFTOP ADDOP MULTOP ADDOP2 UNARYOP KEY_VAR KEY_assert KEY_yiethr KEY_brecon KEY_return KEY_if KEY_else KEY_for KEY_while KEY_sync KEY_final

%type <lit> LITERAL 

%union{
    std::string *lit;
}

%%
prog:
    start
    | KEYWORD		{cout << "keyword\n";}
;


PrimitiveType:
    numerictype
    | BOOLTYPE
;

numerictype:
    INTTYPE
    | FPTYPE
;

// 15 Expressions

Expression:
    AssignmentExpression
;

AssignmentExpression:
    ConditionalExpression
    | LeftHandSide ASSIGNOP Expression		// or Assignment
;

AmbigiousName:
    AmbigiousName '.' IDENTIFIER
    | IDENTIFIER
;

ExpressionName:
    AmbigiousName '.' IDENTIFIER
    | IDENTIFIER
;

ConditionalExpression:
    ConditionalOrExpression
    | ConditionalOrExpression '?' Expression ':' ConditionalExpression
    | ConditionalOrExpression '?' Expression ':' LambdaExpression
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
    Primary			// need to make primary
    | ExpressionName
    | PostfixExpression ADDOP2
;
//Productions from §15 (Expressions)
Primary:
    PrimaryNoNewArray
    | ArrayCreationExpression 
;


PrimaryNoNewArray:
    Literal
    | ClassLiteral
    | "this"
    | TypeName '.' "this"
    | '(' Expression ')'  
    | ClassInstanceCreationExpression
    | FieldAccess
    | ArrayAccess
    | MethodInvocation
    | MethodReference
;


ClassLiteral: //confirm once
    | TypeName Zero_or_moreSquarebracket '.' "class" 
    | NumericType Zero_or_moreSquarebracket '.' "class"
    | "boolean" Zero_or_moreSquarebracket '.' "class"
    | "void" '.' "class"
;

Zero_or_moreSquarebracket:
    Zero_or_moreSquarebracket "[ ]" 
    |   
;

ClassInstanceCreationExpression:
    UnqualifiedClassInstanceCreationExpression
    | ExpressionName '.' UnqualifiedClassInstanceCreationExpression
    | Primary '.' UnqualifiedClassInstanceCreationExpression
;


UnqualifiedClassInstanceCreationExpression:
    "new" ZerooroneTypeArguments ClassOrInterfaceTypeToInstantiate '(' ZerooroneArgumentList ')' ZerooroneClassBody
;

ZerooroneTypeArguments:
    TypeArguments | 
;

ZerooroneArgumentList:
    ArgumentList | 
;

ZerooroneClassBody:
    ClassBody | 
;


ClassOrInterfaceTypeToInstantiate:
    Identifier Zeroormore_DotIdentifier Zeroorone_TypeArguments //ignoring diamond <>
;

Zeroormore_DotIdentifier:
    '.' Identifier | 
;

Zeroorone_TypeArguments:
    TypeArguments |  
;


FieldAccess:
    Primary '.' Identifier  
    | "super" '.' Identifier
    | TypeName '.' "super" '.' Identifier
;


ArrayAccess:
    ExpressionName '[' Expression ']'
    | PrimaryNoNewArray '[' Expression ']'
;


MethodInvocation:
    MethodName '(' Zeroorone_ArgumentList ')'
    | TypeName '.' Zeroorone_TypeArguments Identifier '(' Zeroorone_ArgumentList ')'
    | ExpressionName '.' Zeroorone_TypeArguments Identifier '(' Zeroorone_ArgumentList ')'
    | Primary '.' Zeroorone_TypeArguments Identifier '(' Zeroorone_ArgumentList ')'
    | "super" '.' Zeroorone_TypeArguments Identifier '(' Zeroorone_ArgumentList ')'
    | TypeName '.' "super" '.' Zeroorone_TypeArguments Identifier '(' Zeroorone_ArgumentList ')'
;

Zeroorone_ArgumentList:
    ArgumentList | 
;

Zeroorone_TypeArguments:
    TypeArguments | 
;


ArgumentList:
    Expression Zeroormore_CommaExpression
;

Zeroormore_CommaExpression:
    Zeroormore_CommaExpression ',' Expression
    | 
;


MethodReference:
    ExpressionName "::" Zeroorone_TypeArguments Identifier
    | Primary "::" Zeroorone_TypeArguments Identifier
    | ReferenceType "::" Zeroorone_TypeArguments Identifier
    | "super" "::" Zeroorone_TypeArguments Identifier
    | TypeName '.' "super" "::" Zeroorone_TypeArguments Identifier
    | ClassType "::" Zeroorone_TypeArguments "new"
    | ArrayType "::" "new"
;


ArrayCreationExpression:
    "new" PrimitiveType DimExprs Zeroorone_Dims
    | "new" ClassOrInterfaceType DimExprs Zeroorone_Dims
    | "new" PrimitiveType Dims ArrayInitializer
    | "new" ClassOrInterfaceType Dims ArrayInitializer
;

Zeroorone_Dims:
    Dims | 
;

Dims:
    '[' ']'
;

DimExprs:
    DimExpr Zeroormore_DimExpr
;

Zeroormore_DimExpr:
    Zeroormore_DimExpr DimExpr | 
;

DimExpr:
    '[' Expression ']'
;

///////// not completed



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

VariableModifier:
    VariableModifier KEY_final |
;

LocalVariableDeclaration:
    VariableModifier LocalVariableType VariableDeclaratorList
;

LocalVariableType:
    UnannType
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
    | ADDOP2 UnaryExpression
    | PostfixExpression ADDOP2
    | MethodInvocation
    | ClassInstanceCreationExpression
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
    | LocalVariableDeclaration;

StatementExpressionList:
    StatementExpression StatementExpressionMore
;

StatementExpressionMore:
    ',' StatementExpression |
;

// 14 end

ArrayInitializer:
    VariableInitializers
;

VariableInitializers:
    VariableInitializer_question ',' VariableInitializers
    | 
;

VariableInitializer_question:
    VariableInitializer
    | 
;

VariableInitializerList:
    VariableInitializer cVariableInitializer
;

cVariableInitializer:
    ',' VariableInitializer cVariableInitializer
    |
;

VariableInitializer:
    Expression
    | ArrayInitializer
;

// Method 
Methodname:
    UnqualifiedMethodIdentifier
;

UnqualifiedMethodIdentifier:
    (Identifier but not Yield)
;

MethodDeclaration:
    Methodmodifiers Methodheader Methodbody
;

Methodmodifiers:
    Methodmodifier Methodmodifiers
    |
;

Methodmodifier:
    (Annotation public protected private
abstract static final synchronized native strictf) //Keywords mein change karna hain
;

Methodheader:
    Result Methodeclarator Throws_s
    | TypeParameter annotations Result Methodeclarator Throws_s
;

Throws_s:
    Throws Throws_s
    |
;

Result:
    Unanntype
    | void 
;

Methodeclarator:
    Identifier '(' recieveparameters formalparameters ')' Dims_s 
;

Dims_s:
    Dims
    |
;
recieveparameters:
    recieveparameter ','
    |
;
formalparameters:
    formalparameterlist
    |
;

recieveparameter:
    annotations UnannType identifier_dot "this"
;
identifier_dot:
    Identifier '.'
    |
;
formalparameterlist:
    formalparameter cformalparameter
;
cformalparameter:
    ',' formalparameter cformalparameter
    |
;
formalparameter:
    Variablemodifiers UnannType VariableDeclaratorId VariableArityParameter
;
Variablemodifiers:
    Variablemodifier Variablemodifiers
    |
;
VariableArityParameter:
    Variablemodifiers UnannType annotations '...' Identifier
;
Throws:
"throws" ExceptionTypeList
;
ExceptionTypeList:
    ExceptionType cExceptionType
;
cExceptionType:
    ',' ExceptionType cExceptionType
    | 
;
ExceptionType:
    ClassType
    | TypeVariable
;

//Classes
ClassDeclaration:
    NormalClassDeclaration
    | EnumDeclaration
    | RecordDeclaration
;
NormalClassDeclaration:
    ClassModifiers class Identifier [ClassExtends] [ClassPermits] ClassBody
;
ClassModifiers:
    ClassModifier ClassModifiers
    |
;
ClassExtends:
    "extend" ClassType
;
ClassPermits:
    permits TypeName {, TypeName}
;
ClassBody:
    '{' ClassBodyDeclarations '}'
;
ClassBodyDeclarations:
    ClassBodyDeclaration ClassBodyDeclarations
    | 
;
ClassBodyDeclaration:
    ClassMemberDeclaration
    | InstanceInitializer
    | StaticInitializer
    | ConstructorDeclaration
;
ClassMemberDeclaration:
    FieldDeclaration
    | MethodDeclaration
    | ClassDeclaration
    | InterfaceDeclaration
    ";"
;
FieldDeclaration:
    FieldModifiers UnannType VariableDeclaratorList ";"
;
FieldModifiers:
    FieldModifier FieldModifiers
    |
;
FieldModifier:
    "public" 
    | "protected" 
    | "private"
    | "static" 
    | "final" 
    | "transient" 
    | "volatile"
;
VariableDeclaratorList:
    VariableDeclarator cVariableDeclarator
;
cVariableDeclarator:
    "," VariableDeclarator cVariableDeclarator
    |
;
VariableDeclarator:
    VariableDeclaratorId VariableInitializer_eq
;
VariableInitializer_eq:
    "=" VariableInitializer 
    |
;
VariableDeclaratorId:
    Identifier Dims_s
;
UnannType:
    UnannPrimitiveType
    | UnannReferenceType
;
UnannPrimitiveType:
    NumericType
    | "boolean"
;
UnannReferenceType:
    UnannClassOrInterfaceType
    | UnannTypeVariable
    | UnannArrayType
;
UnannClassOrInterfaceType:
    UnannClassType
;
UnannClassType:
    Identifier Zeroorone_TypeArguments
    PackageName . Identifier Zeroorone_TypeArguments
    UnannClassOrInterfaceType . Identifier Zeroorone_TypeArguments
;
TypeVariable:
    Identifier
;
ArrayType:
    PrimitiveType Dims
    ClassOrInterfaceType Dims
    TypeVariable Dims
;
Dims:
    '[' ']'
    | Dims '[' ']'
%%

int main(){
    if(yyparse()) return 0;
    
    return 0;
}
