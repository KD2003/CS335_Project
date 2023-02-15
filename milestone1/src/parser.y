%{
#include <iostream>
#include <string>
using namespace std;

int yylex();
int yyerror(const char *str);

%}

%locations
%token KEYWORD IDENTIFIER LITERAL ESCSEQ OPERATOR SEP INTTYPE FPTYPE BOOLTYPE

%type <lit> LITERAL 

%union{
    std::string *lit;
}

%%
prog:
    start
    | KEYWORD		{cout << "keyword\n";}
;

start:
    word start
    | word
;

word:
    '('			{cout << "Bracket open\n";}
    | ')'		{cout << "Bracket close\n";}
;


primitivetype:
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
    
;

%%

int main(){
    if(yyparse()) return 0;
    
    return 0;
}
