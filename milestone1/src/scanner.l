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
STRLIT ["]([^"\\\n]|\\(.|\n))*["]
TEXTBLK ["]{3}[ \t\f]*[\r\n]([^"\\]|(["]{2}+[^"\\\n]+)|(["]+[^"\\\n]+)|{ESCSEQ}|[\r\n])*["]{3}
SEP1 ";"|","|"."|"@"|"("|"{"|"["|")"|"}"|"]"
SEP2 "..."|"::"
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

{ESCSEQ} {
    return(ESCSEQ);
}

["]{3}[ \t\f]*[\r\n] {txt = yytext; BEGIN(txtblk);}
<txtblk>([^"\\]|{ESCSEQ}|[\r\n])* {txt+=yytext;}
<txtblk>(["]{2}|["])([^"\\]|\n)+ {txt+=yytext;}
<txtblk>["]{3} {
    txt+=yytext;
    /*cout << "Text block\n";*/
    BEGIN(INITIAL);}
<txtblk><<EOF>> {printf("Line number: %d The text block did not close. Expected \"\"\"\n", yylineno); return 0;}

{CHARLIT} {
    return(LITERAL);
}

{STRLIT} {
    return(LITERAL);
}

{OPERATOR} {
    return(OPERATOR);
}

{SEP1} {
    return((int)yytext[0]);
}

{SEP2} {
    return(SEP);
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
