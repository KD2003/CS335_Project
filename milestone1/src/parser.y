%{
#include <iostream>
#include <string>
using namespace std;

int yylex();
int yyerror(const char *str);

%}

%locations
%token KEYWORD IDENTIFIER LITERAL ESCSEQ OPERATOR SEP INTTYPE FPTYPE BOOLTYPE ASSIGNOP CONDOR CONDAND EQALITYOP RELATIONOP SHIFTOP ADDOP MULTOP ADDOP2 UNARYOP KEY_VAR KEY_assert KEY_yiethr KEY_brecon KEY_return KEY_if KEY_else KEY_for KEY_permits KEY_record KEY_while KEY_sync KEY_final KEY_extends KEY_super KEY_this KEY_class KEY_void KEY_public KEY_new COLON2 KEY_throws KEY_static KEY_enum DOT3 KEY_abstract KEY_native KEY_strictf KEY_protected KEY_private

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
    | ReferenceType
;

PrimitiveType:
    NumericType
    | BOOLTYPE
;

NumericType:
    INTTYPE
    | FPTYPE
;

//reference type

ReferenceType:
    ClassType  // ClassorInterfaceType -> CLassType
    | IDENTIFIER
    | ArrayType
;

IDENdotIDEN:
    IDENdotIDEN '.' IDENTIFIER
    | IDENTIFIER
;

// PackageName:
//     IDENTIFIER
//     | PackageName '.' IDENTIFIER
// ;
// TypeName:
//     IDENTIFIER
//     | TypeName '.' IDENTIFIER
// ;
// ExpressionName:
//     IDENTIFIER
//     | AmbigiousName
// ;

// AmbigiousName:
//     AmbigiousName '.' IDENTIFIER
//     | IDENTIFIER
// ;

// ExpressionName:
//     AmbigiousName '.' IDENTIFIER
//     | IDENTIFIER
// ;

// MethodName:
//     IDENTIFIER
// ;
ClassModifier:
    KEY_public | KEY_private //Keywords mein change karna hain
;

ClassType:
    IDENdotIDEN Zeroorone_TypeArguments
    | ClassType '.' IDENTIFIER Zeroorone_TypeArguments
    /* ClassType1
    | ClassType1 TypeArgument */
;

/* ClassType1:
    IDENdotIDEN
    | IDENdotIDEN TypeArgument
    | ClassType1 TypeArgument '.' IDENdotIDEN
    | ClassType1 TypeArgument '.' IDENdotIDEN TypeArgument
; */

Zeroorone_TypeArguments:
    TypeArguments | 
;

ArrayType:
    PrimitiveType Dims
    | ClassType Dims
    | IDENTIFIER Dims
;
Dims:
    '[' ']'
    | Dims '[' ']'
;
TypeParameter:
    IDENTIFIER TypeBound
    | IDENTIFIER
;

TypeBound:
    KEY_extends ClassType
;
TypeArguments:
    '<' TypeArgumentList '>'
;
TypeArgumentList:
    TypeArgument cTypeArgument
;
cTypeArgument:
    cTypeArgument ',' TypeArgument 
    | 
;
TypeArgument:
    ReferenceType
    | Wildcard
;
Wildcard:
    '?' WildcardBounds
    | '?'
;
WildcardBounds:
    KEY_extends ReferenceType
    | KEY_super ReferenceType
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
    KEY_new Zeroorone_TypeArguments ClassOrInterfaceTypeToInstantiate '(' Zeroorone_ArgumentList ')' ZerooroneClassBody
;

Zeroorone_ArgumentList:
    ArgumentList | 
;

ZerooroneClassBody:
    ClassBody | 
;


ClassOrInterfaceTypeToInstantiate:
    IDENdotIDEN Zeroorone_TypeArguments //ignoring diamond <>
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
    | IDENdotIDEN '.' TypeArguments IDENTIFIER '(' Zeroorone_ArgumentList ')'
    | Primary '.' Zeroorone_TypeArguments IDENTIFIER '(' Zeroorone_ArgumentList ')'
    | KEY_super '.' Zeroorone_TypeArguments IDENTIFIER '(' Zeroorone_ArgumentList ')'
    | IDENdotIDEN '.' KEY_super '.' Zeroorone_TypeArguments IDENTIFIER '(' Zeroorone_ArgumentList ')'
;

ArgumentList:
    Expression Zeroormore_CommaExpression
;

Zeroormore_CommaExpression:
    Zeroormore_CommaExpression ',' Expression
    | 
;

MethodReference:
    IDENdotIDEN COLON2 Zeroorone_TypeArguments IDENTIFIER
    | Primary COLON2 Zeroorone_TypeArguments IDENTIFIER
    | ReferenceType COLON2 Zeroorone_TypeArguments IDENTIFIER
    | KEY_super COLON2 Zeroorone_TypeArguments IDENTIFIER
    | IDENdotIDEN '.' KEY_super COLON2 Zeroorone_TypeArguments IDENTIFIER
    | ClassType COLON2 Zeroorone_TypeArguments KEY_new
    | ArrayType COLON2 KEY_new
;


ArrayCreationExpression:
    KEY_new PrimitiveType DimExprs Dims
    | KEY_new PrimitiveType DimExprs
    | KEY_new ClassType DimExprs Dims
    | KEY_new ClassType DimExprs
    | KEY_new PrimitiveType Dims ArrayInitializer
    | KEY_new ClassType Dims ArrayInitializer
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
    // | ADDOP2 UnaryExpression
    // | PostfixExpression ADDOP2
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
    '{' zerooroneVariableInitializerList zerooronecomma '}'
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
    | EnumDeclaration
    | RecordDeclaration
;
NormalClassDeclaration:
    ClassModifiers KEY_class IDENTIFIER ClassBody
    | ClassModifiers KEY_class IDENTIFIER ClassExtends ClassBody
    | ClassModifiers KEY_class IDENTIFIER ClassPermits ClassBody
    | ClassModifiers KEY_class IDENTIFIER ClassExtends ClassPermits ClassBody
;
ClassModifiers:
    ClassModifiers ClassModifier |
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
    ClassMemberDeclaration
    | InstanceInitializer
    | StaticInitializer
    | ConstructorDeclaration
;
ClassMemberDeclaration:
    FieldDeclaration
    | MethodDeclaration
    | ';'
;
FieldDeclaration:
    FieldModifiers Type VariableDeclaratorList ';'
;
FieldModifiers:
    FieldModifiers FieldModifier
    |
;
FieldModifier:
    KEY_public | KEY_private
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
//Method inside class

MethodDeclaration:
    Methodmodifiers Methodheader MethodBody
;

Methodmodifiers:
    Methodmodifiers Methodmodifier
    |
;

Methodmodifier:
    KEY_public | KEY_protected | KEY_private | KEY_abstract | KEY_static | KEY_final | KEY_sync | KEY_native | KEY_strictf //Keywords mein change karna hain
;

Methodheader:
    Result Methodeclarator
    | TypeParameter Result Methodeclarator
;

// Throws_s:
//     Throws_s Throws
//     |
// ;

Result:
    Type
    | KEY_void 
;

Methodeclarator:
    IDENTIFIER '(' recieveparameters formalparameters ')' Dims
    | IDENTIFIER '(' recieveparameters formalparameters ')'
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
    Type IDENTIFIER '.' KEY_this
    | Type KEY_this
;

formalparameterlist:
    formalparameter cformalparameter
;
cformalparameter:
    cformalparameter ',' formalparameter |
;
formalparameter:
    VariableModifier Type VariableDeclaratorId VariableArityParameter
;

VariableModifier:
    VariableModifier KEY_final |
;
VariableArityParameter:
    VariableModifier Type DOT3 IDENTIFIER
;
// Throws:
//     KEY_throws ExceptionTypeList
// ;
// ExceptionTypeList:
//     ExceptionType cExceptionType
// ;
// cExceptionType:
//     cExceptionType ',' ExceptionType 
//     | 
// ;
// ExceptionType:
//     ClassType
// ;
MethodBody:
    Block
    | ';'
;
InstanceInitializer:
    Block
;
StaticInitializer:
    KEY_static Block
;
ConstructorDeclaration:
    zeroormore_ConstructorModifier ConstructorDeclarator ConstructorBody
;
zeroormore_ConstructorModifier:
    zeroormore_ConstructorModifier ConstructorModifier 
    | 
;
ConstructorModifier:
    KEY_public | KEY_private
;
ConstructorDeclarator:
    zeroorone_TypeParameters IDENTIFIER '(' recieveparameters formalparameters ')'
;
zeroorone_TypeParameters:
    TypeParameters
    |
;
TypeParameters:
    '<' TypeParamerList '>'
;
TypeParamerList:
    TypeParameter TypeParameterc
;
TypeParameterc:
    TypeParameterc ',' TypeParameter 
    | 
;

ConstructorBody:
    '{' zerooroneExplicitConstructorInvocation BlockStatements '}'
;

zerooroneExplicitConstructorInvocation:
    ExplicitConstructorInvocation
    |
;
ExplicitConstructorInvocation:
    Zeroorone_TypeArguments KEY_this '(' Zeroorone_ArgumentList ')' ';'
    | Zeroorone_TypeArguments KEY_super '(' Zeroorone_ArgumentList ')' ';'
    | IDENdotIDEN '.' zeroorone_TypeParameters KEY_super '(' Zeroorone_ArgumentList ')' ';'
    | Primary '.' zeroorone_TypeParameters KEY_super '(' Zeroorone_ArgumentList ')' ';'
;
EnumDeclaration:
    ClassModifiers KEY_enum IDENTIFIER EnumBody
;
EnumBody:
    '{' zerooroneEnumConstantList zerooronecomma zerooroneEnumBodyDeclarations '}'
;
zerooronecomma:
    ',' 
    |
;
zerooroneEnumConstantList:
    EnumConstantList
    |
;
zerooroneEnumBodyDeclarations:
    EnumBodyDeclarations
    |
;
EnumConstantList:
    EnumConstant cEnumConstant
;
cEnumConstant:
    cEnumConstant ',' EnumConstant
    |
;
EnumConstant:
    IDENTIFIER bracketZeroorone_ArgumentList ZerooroneClassBody
;
bracketZeroorone_ArgumentList:
    '(' Zeroorone_ArgumentList ')' bracketZeroorone_ArgumentList
    |
; 
EnumBodyDeclarations:
    ';' zeroormoreClassBodyDeclaration
;
zeroormoreClassBodyDeclaration:
    zeroormoreClassBodyDeclaration ClassBodyDeclaration 
    |
;
RecordDeclaration:
    ClassModifiers KEY_record IDENTIFIER zeroorone_TypeParameters RecordHeader RecordBody
;
RecordHeader:
    '(' zerooroneRecordComponentList ')'
;
zerooroneRecordComponentList:
    RecordComponentList
    |
;
RecordComponentList:
    RecordComponent cRecordComponent
;
cRecordComponent:
    cRecordComponent ',' RecordComponent 
    |
;
RecordComponent:
    Type IDENTIFIER
    | VariableArityRecordComponent
;
VariableArityRecordComponent:
    Type DOT3 IDENTIFIER
;
RecordBody:
    '{' zeroormoreRecordBodyDeclaration '}'
;
zeroormoreRecordBodyDeclaration:
    zeroormoreRecordBodyDeclaration RecordBodyDeclaration 
    |
;
RecordBodyDeclaration:
    ClassBodyDeclaration
    | CompactConstructorDeclaration
;
CompactConstructorDeclaration:
    zeroormore_ConstructorModifier IDENTIFIER ConstructorBody
;

// Class and Method END
%%

int main(){
    if(yyparse()) return 0;
    
    return 0;
}