%{
#include<iostream>
#include"parser.tab.h"
using namespace std;


string txt;

%}


INTTYPE byte|short|int|long|char
FPTYPE float|double
BOOLTYPE boolean
KEYWORD abstract|continue|for|new|switch|assert|default|if|package|synchronized|boolean|do|goto|private|this|break|double|implements|protected|throw|byte|else|import|public|throws|case|enum|instanceof|return|transient|catch|extends|int|short|try|char|final|interface|static|void|class|finally|long|strictfp|volatile|const|float|native|super|while|"_"|exports|opens|requires|uses|module|permits|sealed|var|non-sealed|provides|to|with|open|record|transitive|yield
ID [a-zA-Z_][a-zA-Z0-9_]*
BOOLNULLLIT true|false|null
DECINUM ([0-9]|[1-9][0-9_]*[0-9])[Ll]?
HEXNUM 0[Xx]([0-9a-fA-F]|[0-9a-fA-F][0-9a-fA-F_]*[0-9a-fA-F])[lL]?
OCTNUM 0([_]*)?([0-7]|[0-7][0-7_]*[0-7])[lL]?
BINNUM 0[Bb]([01]|[01][01_]*[01])[lL]?
DIGITS [0-9]|[0-9][0-9_]*[0-9]
EXPPART [eE][+-]?{DIGITS}
DECFLOAT ({DIGITS}[.]{DIGITS}?{EXPPART}?[fFdD]?)|([.]{DIGITS}{EXPPART}?[fFDd]?)|({DIGITS}{EXPPART}[fFDd]?)|({DIGITS}{EXPPART}?[fFDd])
HEXSIG ({HEXNUM}[.]?)|(0[xX]([0-9a-fA-F]|[0-9a-fA-F][0-9a-fA-F_]*[0-9a-fA-F])?[.]([0-9a-fA-F]|[0-9a-fA-F][0-9a-fA-F_]*[0-9a-fA-F]))
HEXFLOAT {HEXSIG}[Pp][+-]?{DIGITS}[fFDd]?
ESCSEQ \\b|\\s|\\t|\\n|\\f|\\r|"\\\""|"\\\'"|"\\\\"|"\0"|\\[0-3]?[0-7]{1,2}
CHARLIT [']([^\'\\]|{ESCSEQ})[']
STRLIT ["]([^"\\\n]|{ESCSEQ}|\\(.|\n))*["]
SEP1 ";"|","|"."|"@"|"("|"{"|"["|")"|"}"|"]"
DOT3 "..."
ASSIGNOP "="|"*="|"/="|"%="|"+="|"-="|"<<="|">>="|">>>="|"&="|"\^="|"\|="
SINGLEOP "&"|"^"|"|"|":"|'?'
OPERATOR "="|">"|"<"|"!"|"~"|"?"|":"|"->"|"=="|">="|"<="|"!="|"&&"|"|"{2}|"++"|"--"|"+"|"-"|"*"|"/"|"&"|"|"|"^"|"%"|"<<"|">>"|">>>"|"+="|"-="|"*="|"/="|"&="|"\|="|"\^="|"%="|"<<="|">>="|">>>="

%option yylineno
%x COMMENT
%x txtblk
%%

[ \t\f\r\n]+	{ }/*White Space*/

"//".* {
    //cout << "COMMENT  "<< "\n";
}

"/*"                    { BEGIN(COMMENT); }
<COMMENT>"*/"           { /*cout << "Comment\n";*/ BEGIN(INITIAL); }
<COMMENT>([^*]|\n)+|.   { /* skip everything */ }
<COMMENT><<EOF>>        {
    printf("Line number: %d The comment did not close. Expected }\n", yylineno);
    return 0;
}


{INTTYPE} {return(INTTYPE);}

{FPTYPE} {return(FPTYPE);}

{BOOLTYPE} {return(BOOLTYPE);}

var {return(KEY_VAR);}
assert {return(KEY_assert);}
yield|throw {return(KEY_yiethr);}
break|continue {return(KEY_brecon);}
return {return(KEY_return);}
if {return(KEY_if);}
else {return(KEY_else);}
while {return(KEY_while);}
for {return(KEY_for);}
synchronized {return(KEY_sync);}
final {return(KEY_final);}
extends {return(KEY_extends);}
super {return(KEY_super);}
class {return(KEY_class);}
void {return(KEY_void);}
this {return(KEY_this);}
new {return(KEY_new);}
throws {return(KEY_throws);}
static {return(KEY_static);}
enum {return(KEY_enum);}
public {return(KEY_public);}
protected {return(KEY_protected);}
private {return(KEY_private);}
abstract {return(KEY_abstract);}
native {return(KEY_native);}
strictf {return(KEY_strictf);}//This is a new change 
permits {return(KEY_permits);}
record {return(KEY_record);}

{KEYWORD} {
    return(KEYWORD);
}

 
{DECINUM}|{HEXNUM}|{OCTNUM}|{BINNUM} {
    //cout << "Integar literal\n";
    return(LITERAL);
}

{HEXFLOAT}|{DECFLOAT} {
    //cout << "Floating point\n";
    return(LITERAL);
}

 
{BOOLNULLLIT} {
    //cout << "Literal\n";
    return(LITERAL);
}
 
{ID} {
    return(IDENTIFIER);
}

["]{3}[ \t\f]*[\r\n] {txt = yytext; BEGIN(txtblk);}
<txtblk>([^"\\]|{ESCSEQ}|[\r\n])* {txt+=yytext;}
<txtblk>(["]{2}|["])([^"\\]|\n)+ {txt+=yytext;}
<txtblk>["]{3} {
    txt+=yytext;
    /*cout << "Text block\n";*/
    BEGIN(INITIAL);
    return(LITERAL);}
<txtblk><<EOF>> {printf("Line number: %d The text block did not close. Expected \"\"\"\n", yylineno); return 0;}

{CHARLIT} {
    return(LITERAL);
}

{STRLIT} {
    return(LITERAL);
}

"=" {return((int)yytext[0]);}

{ASSIGNOP} {return(ASSIGNOP);}

"|"{2} {return(CONDOR);}

"&&" {return(CONDAND);}
"=="|"!=" {return(EQALITYOP);}
"<"|">"|"<="|">=" {return(RELATIONOP);}
"<<"|">>"|">>>" {return(SHIFTOP);}
"+"|"-" {return(ADDOP);}
"++"|"--" {return(ADDOP2);}
"~"|"!" {return(UNARYOP);}
"*"|"/"|"%" {return(MULTOP);}
"::" {return(COLON2);}
{SINGLEOP} {return((int)yytext[0]);}

{OPERATOR} {
    return(OPERATOR);
}

{SEP1} {
    return((int)yytext[0]);
}

{DOT3} {
    return(DOT3);
}

<<EOF>> {
    return 0;
}

. {
    printf("Line number: %d Error: Illegal Character: %s", yylineno, yytext);
    return 0;
}


%%

void showError(){
    printf("Error: Line %d: Illegal character %s\n", yylineno, yytext);
}

int yyerror(const char *str){
    printf("Error on line %d : %s\n", yylineno,str);
    printf("%s\n", yytext);
    return 0;
}

int yywrap(){
  return 1;
}
