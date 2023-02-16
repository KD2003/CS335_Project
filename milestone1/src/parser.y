%{
#include <iostream>
#include <string>
using namespace std;

int yylex();
int yyerror(const char *str);

%}

%locations
%token KEYWORD IDENTIFIER LITERAL ESCSEQ OPERATOR SEP INTTYPE FPTYPE BOOLTYPE ASSIGNOP CONDOR CONDAND EQALITYOP RELATIONOP SHIFTOP ADDOP MULTOP ADDOP2 UNARYOP

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
    annotations numerictype
    | annotations BOOLTYPE
;

numerictype:
    INTTYPE
    | FPTYPE
;

annotations:
    annotations Annotation
    | Annotation
;

Annotation:
    NormalAnnotation
    | MarkerAnnotation
    | SingleElementAnnotation
;

NormalAnnotation:
    '@' TypeName '(' ElementValuePairList ')'
    | '@' TypeName
;

ElementValuePairList:
    ElementValuePair ElementValuePairMore
;

ElementValuePairMore:
    ElementValuePairMore ',' ElementValuePair |
;

ElementValuePair:
    IDENTIFIER '=' ElementValue
;

ElementValue:
    Annotation			// left here
;

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

Primary:

;

ArrayInitialiser:
    VariableInitialisers
;

VariableInitialisers:
    VariableInitialiser_question ',' VariableInitialisers
    | 
;

VariableInitialiser_question:
    VariableInitialiser
    | 
;

VariableInitializerList:
    VariableInitialiser cVariableInitialiser
;

cVariableInitialiser:
    ',' VariableInitialiser cVariableInitialiser
    |
;

VariableInitialiser:
    Expression
    | ArrayInitialiser
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
Variablemodifier:
    Annotation
    | "final"    
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

%%

int main(){
    if(yyparse()) return 0;
    
    return 0;
}
