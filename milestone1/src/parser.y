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

%%

int main(){
    if(yyparse()) return 0;
    
    return 0;
}
