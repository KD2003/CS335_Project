%{
#include"AST.h"
#include <stdio.h>
#include <string>
#include <fstream>
using namespace std;

FILE* dotfile;
extern FILE* yyin;
extern int yyrestart(FILE*);

bool gotinputfile, gotoutputfile, verbosemode;

string type;

int yylex();
int yyerror(const char *str);

%}

%locations
%token KEYWORD IDENTIFIER LITERAL OPERATOR INTTYPE FPTYPE BOOLTYPE ASSIGNOP CONDOR CONDAND EQALITYOP RELATIONOP SHIFTOP ADDOP MULTOP ADDOP2 UNARYOP KEY_VAR KEY_assert KEY_yield KEY_throw KEY_break KEY_continue KEY_return KEY_if KEY_else KEY_for KEY_permits KEY_while KEY_sync KEY_final KEY_extends KEY_super KEY_this KEY_class KEY_void KEY_public KEY_new KEY_static DOT3 KEY_private KEY_import

%union{
    std::string *st;
    ASTNode *ptr;
}

%type<st> KEYWORD IDENTIFIER LITERAL OPERATOR INTTYPE FPTYPE BOOLTYPE ASSIGNOP CONDOR CONDAND EQALITYOP RELATIONOP SHIFTOP ADDOP MULTOP ADDOP2 UNARYOP KEY_VAR KEY_assert KEY_yield KEY_throw KEY_break KEY_continue KEY_return KEY_if KEY_else KEY_for KEY_permits KEY_while KEY_sync KEY_final KEY_extends KEY_super KEY_this KEY_class KEY_void KEY_public KEY_new KEY_static DOT3 KEY_private KEY_import

%type<ptr> Start ImportList ClassDeclarationList Imports Type PrimitiveType IDENdotIDEN PublicPrivateStatic ClassType ArrayType Dims
%type<ptr> Primary PrimaryNoNewArray ClassInstanceCreationExpression Zeroorone_ArgumentList FieldAccess ArrayAccess MethodInvocation ArgumentList ArrayCreationExpression DimExpr Expression AssignmentExpression Assignment ConditionalExpression ConditionalAndExpression ConditionalOrExpression AndExpression ExclusiveOrExpression InclusiveOrExpression EqualityExpression RelationalExpression ShiftExpression MultiplicativeExpression AdditiveExpression UnaryExpression UnaryExpressionNotPlusMinus CastExpression PostfixExpression
%type<ptr> Block BlockStatement BlockStatements LocalVariableDeclaration LocalVariableType Statement StatementExpression StatementNoShortIf StatementWithoutTrailingSubstatement LeftHandSide AssertStatement BreakContinueStatement ForInit ForStatement ForStatementNoShortIf StatementExpressionList
%type<ptr> ClassDeclaration NormalClassDeclaration ClassExtends ClassPermits cTypeName ClassBody ClassBodyDeclaration ClassBodyDeclarations VariableDeclarator VariableDeclaratorList zerooroneExpression VariableDeclarator1 VariableDeclarator2 List1 List2 List3 ArrEle1 ArrEle2 ArrEle3 MethodHeader MethodDeclaration MethodBody Methodeclarator IdenPara formalparameter formalparameters Modifiers

%left ADDOP MULTOP SHIFTOP EQALITYOP ADDOP2 '*'
%right ASSIGNOP '='

%%
Start:
    ImportList ClassDeclarationList		{
        vector<ASTNode*> s;
        s.push_back($1);
        s.push_back($2);
        $$ = makeNode("Start", s);
        }
;

ImportList:
    ImportList Imports  {
        vector<ASTNode*> s;
        s.push_back($1);
        s.push_back($2);
        $$ = makeNode("ImportList", s);
    }
    |   {
        $$=NULL;
    }
;

ClassDeclarationList:
    ClassDeclarationList ClassDeclaration       {
        vector<ASTNode*> s;
        s.push_back($1);
        s.push_back($2);
        $$ = makeNode("ClassDeclarationList", s);
    }
    | ClassDeclaration      {
        $$=$1;
    }
;

Imports:
    KEY_import IDENdotIDEN ';'      {
        vector<ASTNode*> s;
        s.push_back($2);
        $$ = makeNode("import", s);
    }
    | KEY_import KEY_static IDENdotIDEN ';'     {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("static"));
        s.push_back($3);
        $$ = makeNode("import", s);
    }
    | KEY_import IDENdotIDEN '.' '*' ';'        {
        vector<ASTNode*> s;
        s.push_back($2);
        s.push_back(makeLeaf("*"));
        $$ = makeNode("import", s);   
    }
    | KEY_import KEY_static IDENdotIDEN '.' '*' ';'     {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("static"));
        s.push_back($3);
        $$ = makeNode("import", s);
    }
;

// §4 (Types, Values, and Variables) Start
Type:
    PrimitiveType   {
        $$=$1;
    }
    | ArrayType     {
        $$=$1;
    }
    | ClassType     {
        $$=$1;
    }
;

PrimitiveType:
    INTTYPE     {
        $$ = makeLeaf(*$1);
        $$->type = *$1;
        if(type=="") type = *$1;
        delete $1;
    }
    | FPTYPE       {
        $$ = makeLeaf(*$1);
        $$->type = *$1;
        if(type=="") type = *$1;
        delete $1;
    }
    | BOOLTYPE      {
        $$ = makeLeaf(*$1);
        $$->type = *$1;
        if(type=="") type = *$1;
        delete $1;
    }
;

IDENdotIDEN:
    IDENdotIDEN '.' IDENTIFIER      {
        vector<ASTNode*> s;
        s.push_back($1);
        s.push_back(makeLeaf("ID (" + *$3 + ")"));
        delete $3;
        $$ = makeNode(".", s);
    }
    | IDENTIFIER    {
        $$ = makeLeaf("ID (" + *$1 + ")");
        delete $1;
    }
;

PublicPrivateStatic:
    KEY_public      {
        $$ = makeLeaf("public");
    }
    | KEY_private       {
        $$ = makeLeaf("private");
    }
    | KEY_static        {
        $$ = makeLeaf("static");
    }
;

ClassType:
    IDENdotIDEN     {
        $$=$1;
    }
;
ArrayType:
    PrimitiveType Dims      {
        $$=$1;
    }
    | ClassType Dims        {
        $$=$1;
    }
;
Dims:
    '[' ']'     {$$=NULL;}
    | Dims '[' ']'  {
        $$=NULL;
    }
;

// §4 (Types, Values, and Variables) END

//Productions from §15 (Expressions) START
Primary:
    PrimaryNoNewArray   {
        $$ = $1;
    }
    | ArrayCreationExpression       {
        $$ = $1;
    }
;

PrimaryNoNewArray:
    LITERAL     {
        $$ = makeLeaf("Literal");
    }
    /* | ClassLiteral */
    | KEY_this      {
        $$ = makeLeaf("this");
    }
    | IDENdotIDEN '.' KEY_this      {
        vector<ASTNode*> s;
        s.push_back($1);
        s.push_back(makeLeaf("this"));
        $$ = makeNode("PrimaryNoNewArray", s);
    }
    | '(' Expression ')'        {
        $$ = $2;
    }
    | ClassInstanceCreationExpression       {
        $$ = $1;
    }
    | FieldAccess       {
        $$ = $1;
    }
    | ArrayAccess       {
        $$ = $1;
    }
    | MethodInvocation      {
        $$ = $1;
    }
;

ClassInstanceCreationExpression:
    KEY_new IDENdotIDEN '(' Zeroorone_ArgumentList ')' ClassBody        {
        vector<ASTNode*> s;
        s.push_back($2);
        s.push_back($4);
        s.push_back($6);
        $$ = makeNode("new", s);
    }
    | KEY_new IDENdotIDEN '(' Zeroorone_ArgumentList ')'        {
        vector<ASTNode*> s;
        s.push_back($2);
        s.push_back($4);
        $$ = makeNode("new", s);
    }
;

Zeroorone_ArgumentList:
    ArgumentList        {
        $$ = $1;
    }
    |   {
        $$=NULL;
    }
;

FieldAccess:
    Primary '.' IDENTIFIER      {
        vector<ASTNode*> s;
        s.push_back($1);
        s.push_back(makeLeaf("ID (" + *$3 + ")"));
        delete $3;
        
        $$ = makeNode("FieldAccess", s);
    }
    | KEY_super '.' IDENTIFIER      {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("ID (" + *$3 + ")"));
        delete $3;
        $$ = makeNode("super", s);
    }
    | IDENdotIDEN '.' KEY_super '.' IDENTIFIER      {
        vector<ASTNode*> s;
        s.push_back($1);
        s.push_back(makeLeaf("super"));
        s.push_back(makeLeaf("ID (" + *$5 + ")"));
        delete $5;
        $$ = makeNode("FieldAccess", s);
    }
;

ArrayAccess:
    IDENdotIDEN '[' Expression ']'      {
        vector<ASTNode*> s;
        s.push_back($1);
        s.push_back($3);
        $$ = makeNode("ArrayAccess", s);
    }
    | PrimaryNoNewArray '[' Expression ']'      {
        vector<ASTNode*> s;
        s.push_back($1);
        s.push_back($3);
        $$ = makeNode("ArrayAccess", s);
    }
;

MethodInvocation:
    IDENdotIDEN '(' Zeroorone_ArgumentList ')'          {
        vector<ASTNode*> s;
        s.push_back($1);
        s.push_back($3);
        
        
        $$ = makeNode("MethodInvocation", s);
    }
    | Primary '.' IDENTIFIER '(' Zeroorone_ArgumentList ')'     {
        vector<ASTNode*> s;
        s.push_back($1);
        s.push_back(makeLeaf("ID (" + *$3 + ")"));
        delete $3;
        s.push_back($5);
        
        
        
        $$ = makeNode("MethodInvocation", s);
    }
    | KEY_super '.' IDENTIFIER '(' Zeroorone_ArgumentList ')'       {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("super"));
        s.push_back(makeLeaf("ID (" + *$3 + ")"));
        delete $3;
        s.push_back($5);
        
        
        
        $$ = makeNode("MethodInvocation", s);
    }
    | IDENdotIDEN '.' KEY_super '.' IDENTIFIER '(' Zeroorone_ArgumentList ')'      {
        vector<ASTNode*> s;
        s.push_back($1);
        s.push_back(makeLeaf("super"));
        s.push_back(makeLeaf("ID (" + *$5 + ")"));
        delete $5;
        s.push_back($7);
        $$ = makeNode("MethodInvocation", s);   
    }
;

ArgumentList:
    ArgumentList ',' Expression     {
        vector<ASTNode*> s;
        s.push_back($1);
        s.push_back($3);
        $$ = makeNode(",", s);
    }
    | Expression        {
        $$ = $1;
    }
;

ArrayCreationExpression:        // array initiaizer to do
    KEY_new PrimitiveType DimExpr Dims      {
        vector<ASTNode*> s;
        s.push_back($2);
        s.push_back($3);
        $$ = makeNode("new", s);
    }
    | KEY_new PrimitiveType DimExpr     {
        vector<ASTNode*> s;
        s.push_back($2);
        s.push_back($3);
        $$ = makeNode("new", s);
    }
    | KEY_new IDENdotIDEN DimExpr Dims      {
        vector<ASTNode*> s;
        s.push_back($2);
        s.push_back($3);
        $$ = makeNode("new", s);
    }
    | KEY_new IDENdotIDEN DimExpr       {
        vector<ASTNode*> s;
        s.push_back($2);
        s.push_back($3);
        $$ = makeNode("new", s);
    }
;

DimExpr:
    DimExpr '[' Expression ']'  {
        vector<ASTNode*> s;
        s.push_back($1);
        s.push_back($3);
        $$ = makeNode("DimExpr", s);
    }
    | '[' Expression ']'        {
        vector<ASTNode*> s;
        s.push_back($2);
        $$ = makeNode("DimExpr", s);
    }
;

Expression:
    AssignmentExpression    {
        $$ = $1;
    }
;

AssignmentExpression:
    ConditionalExpression       {
        $$ = $1;
    }
    | Assignment        {
        $$ = $1;
    }
;

Assignment:
    LeftHandSide ASSIGNOP Expression	    {
        vector<ASTNode*> s;
        s.push_back($1);
        s.push_back($3);
        $$ = makeNode(*$2, s);
        delete $2;
    }
    | LeftHandSide '=' Expression       {
        vector<ASTNode*> s;
        s.push_back($1);
        s.push_back($3);
        $$ = makeNode("=", s);
    }
;

ConditionalExpression:
    ConditionalOrExpression     {
        $$ = $1;
    }
    | ConditionalOrExpression '?' Expression ':' ConditionalExpression      {
        vector<ASTNode*> s;
        s.push_back($1);
        s.push_back(makeLeaf("?"));
        s.push_back($3);
        s.push_back(makeLeaf(":"));
        s.push_back($5);
        $$ = makeNode("ConditionalExpression", s);
    }
;

ConditionalOrExpression:
    ConditionalAndExpression        {
        $$ = $1;
    }
    | ConditionalOrExpression CONDOR ConditionalAndExpression       {
        vector<ASTNode*> s;
        s.push_back($1);
        s.push_back($3);
        $$ = makeNode("||", s);
    }
;

ConditionalAndExpression:
    InclusiveOrExpression   {
        $$ = $1;
    }
    | ConditionalAndExpression CONDAND InclusiveOrExpression        {
        vector<ASTNode*> s;
        s.push_back($1);
        s.push_back($3);
        $$ = makeNode("&&", s);
    }
;

AndExpression:
    EqualityExpression      {
        $$ = $1;
    }
    | AndExpression '&' EqualityExpression      {
        vector<ASTNode*> s;
        s.push_back($1);
        s.push_back($3);
        $$ = makeNode("&", s);
    }
;

ExclusiveOrExpression:
    AndExpression       {
        $$ = $1;
    }
    | ExclusiveOrExpression '^' AndExpression       {
        vector<ASTNode*> s;
        s.push_back($1);
        s.push_back($3);
        $$ = makeNode("^", s);
    }
;       

InclusiveOrExpression:
    ExclusiveOrExpression       {
        $$ = $1;
    }
    | InclusiveOrExpression '|' ExclusiveOrExpression       {
        vector<ASTNode*> s;
        s.push_back($1);
        s.push_back($3);
        $$ = makeNode("|", s);
    }
;

EqualityExpression:
    RelationalExpression    {
        $$ = $1;
    }
    | EqualityExpression EQALITYOP RelationalExpression {
        vector<ASTNode*> s;
        s.push_back($1);
        s.push_back($3);
        $$ = makeNode(*$2, s);
        delete $2;
    }
;

RelationalExpression:
    ShiftExpression     {
        $$ = $1;
    }
    | RelationalExpression RELATIONOP ShiftExpression       {
        vector<ASTNode*> s;
        s.push_back($1);
        s.push_back($3);
        $$ = makeNode(*$2, s);
        delete $2;
    }
;

ShiftExpression:
    AdditiveExpression      {
        $$ = $1;
    }
    | ShiftExpression SHIFTOP AdditiveExpression    {
        vector<ASTNode*> s;
        s.push_back($1);
        s.push_back($3);
        $$ = makeNode(*$2, s);
        delete $2;
    }
;

AdditiveExpression:
    MultiplicativeExpression        {
        $$ = $1;
    }
    | AdditiveExpression ADDOP MultiplicativeExpression     {
        vector<ASTNode*> s;
        s.push_back($1);
        s.push_back($3);
        $$ = makeNode(*$2, s);
        delete $2;
    }
;

MultiplicativeExpression:
    UnaryExpression     {
        $$ = $1;      
    }
    | MultiplicativeExpression MULTOP UnaryExpression       {
        vector<ASTNode*> s;
        s.push_back($1);
        s.push_back($3);
        $$ = makeNode(*$2, s);
        delete $2;
    }
    | MultiplicativeExpression '*' UnaryExpression       {
        vector<ASTNode*> s;
        s.push_back($1);
        s.push_back($3);
        $$ = makeNode("*", s);
    }
;

UnaryExpression:
    ADDOP2 UnaryExpression      {
        vector<ASTNode*> s;
        s.push_back($2);
        $$ = makeNode(*$1, s);
        delete $1;
    }
    | ADDOP UnaryExpression     {
        vector<ASTNode*> s;
        s.push_back($2);        
        $$ = makeNode(*$1, s);
        delete $1;
    }
    | UnaryExpressionNotPlusMinus   {
        $$ = $1;
    }
    | CastExpression        {
        $$=$1;
    }
;

UnaryExpressionNotPlusMinus:
    PostfixExpression   {
        $$ = $1;
    }
    | UNARYOP UnaryExpression   {
        vector<ASTNode*> s;
        s.push_back($2);        
        $$ = makeNode(*$1, s);
        delete $1;
    }
;

CastExpression:
    '(' PrimitiveType ')' UnaryExpression   {
        vector<ASTNode*> s;
        s.push_back($2);
        s.push_back($4);
        $$ = makeNode("CastExpression", s);
    }
;

PostfixExpression:
    Primary {
        $$ = $1;
    }
    | IDENdotIDEN       {
        $$ = $1;
    }
    | PostfixExpression ADDOP2      {
        vector<ASTNode*> s;
        s.push_back($1);
        s.push_back(makeLeaf(*$2));
        $$ = makeNode("Postfix Expression", s);
        delete $2;
    }
;
// 15 end

// Productions from §14 (Blocks, Statements, and Patterns)

Block:
    '{' BlockStatements '}' {
        $$=$2;
    }
;

BlockStatements:
    BlockStatements BlockStatement {
        vector<ASTNode*> s;
        s.push_back($1);
        s.push_back($2);
        $$ = makeNode("BlockStatements", s);
    }
    |       {
        $$=NULL;
    }
;

BlockStatement:
    LocalVariableDeclaration ';' {
        $$=$1;
    }
    | Statement {
        $$=$1;
    }
;

LocalVariableDeclaration:
    LocalVariableType VariableDeclaratorList {
        vector<ASTNode*> s;
        s.push_back($1);
        s.push_back($2);
        $$ = makeNode("LocalVariableDeclaration", s);
    }
;

LocalVariableType:
    Type {
        $$=$1;
    }
    | KEY_VAR {
        $$ = makeLeaf("var");
    }
;

Statement:
    StatementWithoutTrailingSubstatement {
        $$=$1;
    }
    | IDENTIFIER ':' Statement {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("ID (" + *$1+")" ));
        s.push_back(makeLeaf(":"));
        s.push_back($3);
        $$ = makeNode("Statement", s);
        delete $1;
    }
    | KEY_if '(' Expression ')' Statement {
        vector<ASTNode*> s;
        s.push_back($3);
        s.push_back($5);
        $$ = makeNode("if", s);
    }
    | KEY_if '(' Expression ')' StatementNoShortIf KEY_else Statement {
        vector<ASTNode*> s,s1;
        s1.push_back($7);
        s.push_back($3);
        s.push_back($5);
        s.push_back(makeNode("else", s1));
        $$ = makeNode("if", s);
    }
    | KEY_while '(' Expression ')' Statement {
        vector<ASTNode*> s;
        s.push_back($3);
        s.push_back($5);
        $$ = makeNode("while", s);
    }
    | ForStatement {
        $$=$1;
    }
;

StatementNoShortIf:
    StatementWithoutTrailingSubstatement {
        $$=$1;
    }
    | IDENTIFIER ':' StatementNoShortIf {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("ID (" + *$1+")" ));
        delete $1;
        s.push_back(makeLeaf(":"));
        s.push_back($3);
        $$ = makeNode("StatementNoShortIf", s);
    }
    | KEY_if '(' Expression ')' StatementNoShortIf KEY_else StatementNoShortIf {
        vector<ASTNode*> s,s1;
        s1.push_back($7);
        s.push_back($3);
        s.push_back($5);
        s.push_back(makeNode("else", s1));
        $$ = makeNode("if", s);
    }
    | KEY_while '(' Expression ')' StatementNoShortIf {
        vector<ASTNode*> s;
        s.push_back($3);
        s.push_back($5);
        $$ = makeNode("while", s);
    }
    | ForStatementNoShortIf {
        $$=$1;
    }
;

StatementWithoutTrailingSubstatement:		// left try statement
    Block   {
        $$=$1;
    }
    | ';' {
        $$=NULL;
    }
    | StatementExpression ';' {
        $$=$1;
    }
    | AssertStatement {
        $$=$1;
    }
    | BreakContinueStatement {
        $$=$1;
    }
    | KEY_return ';' {
        $$ = makeLeaf("return");
    }
    | KEY_return Expression ';' {
        vector<ASTNode*> s;
        s.push_back($2);
        $$ = makeNode("return", s);
    }
    | KEY_yield Expression ';' {
        vector<ASTNode*> s;
        s.push_back($2);
        $$ = makeNode("yield", s);
    }
    | KEY_throw Expression ';' {
        vector<ASTNode*> s;
        s.push_back($2);
        $$ = makeNode("throw", s);
    }
    | KEY_sync '(' Expression ')' Block {
        vector<ASTNode*> s;
        s.push_back($3);
        s.push_back($5);
        $$ = makeNode("sync", s);
    }
;

StatementExpression:
    Assignment {
        $$=$1;
    }
    | MethodInvocation {
        $$=$1;
    }
    | ADDOP2 UnaryExpression {
        vector<ASTNode*> s;
        s.push_back($2);
        $$ = makeNode(*$1, s);
        delete $1;
    }
    | PostfixExpression ADDOP2 {
        vector<ASTNode*> s;
        s.push_back($1);
        s.push_back(makeLeaf(*$2));
        delete $2;
        $$ = makeNode("Statement Expression", s);
    }
    /* | ClassInstanceCreationExpression */
;

LeftHandSide:
    IDENdotIDEN {
        $$=$1;
    }
    | FieldAccess {
        $$=$1;
    }
    | ArrayAccess {
        $$=$1;
    }
;

AssertStatement:
    KEY_assert Expression ';' {
        vector<ASTNode*> s;
        s.push_back($2);
        $$ = makeNode("assert", s);
    }
    | KEY_assert Expression ':' Expression ';' {
        vector<ASTNode*> s;
        s.push_back($2);
        s.push_back(makeLeaf(":"));
        s.push_back($4);
        $$ = makeNode("assert", s);
    }
;

BreakContinueStatement:
    KEY_break IDENTIFIER ';' {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("ID (" + *$2+")" ));
        delete $2;
        $$ = makeNode("break", s);
    }
    | KEY_break ';' {
        $$ = makeLeaf("break");
    }
    | KEY_continue IDENTIFIER ';' {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("ID (" + *$2+")" ));
        delete $2;
        $$ = makeNode("continue", s);
    }
    | KEY_continue ';' {
        $$ = makeLeaf("continue");
    }
;

ForStatement:
    KEY_for '(' ForInit ';' ';' ')' Statement {
        vector<ASTNode*> s;
        s.push_back($3);
        s.push_back($7);
        $$ = makeNode("for", s);
    }
    | KEY_for '(' ForInit ';' Expression ';' ')' Statement {
        vector<ASTNode*> s;
        s.push_back($3);
        s.push_back($5);
        s.push_back($8);
        $$ = makeNode("for", s);
    }
    | KEY_for '(' ForInit ';' ';' StatementExpressionList ')' Statement {
        vector<ASTNode*> s;
        s.push_back($3);
        s.push_back($6);
        s.push_back($8);
        $$ = makeNode("for", s);
    }
    | KEY_for '(' ForInit ';' Expression ';' StatementExpressionList ')' Statement {
        vector<ASTNode*> s;
        s.push_back($3);
        s.push_back($5);
        s.push_back($7);
        s.push_back($9);
        $$ = makeNode("for", s);
    }
    /* | KEY_for '(' LocalVariableDeclaration ':' Expression ')' Statement */
;

ForStatementNoShortIf:
    KEY_for '(' ForInit ';' ';' ')' StatementNoShortIf {
        vector<ASTNode*> s;
        s.push_back($3);
        s.push_back($7);
        $$ = makeNode("for", s);
    }
    | KEY_for '(' ForInit ';' Expression ';' ')' StatementNoShortIf {
        vector<ASTNode*> s;
        s.push_back($3);
        s.push_back($5);
        s.push_back($8);
        $$ = makeNode("for", s);
    }
    | KEY_for '(' ForInit ';' ';' StatementExpressionList ')' StatementNoShortIf {
        vector<ASTNode*> s;
        s.push_back($3);
        s.push_back($6);
        s.push_back($8);
        $$ = makeNode("for", s);
    }
    | KEY_for '(' ForInit ';' Expression ';' StatementExpressionList ')' StatementNoShortIf {
        vector<ASTNode*> s;
        s.push_back($3);
        s.push_back($5);
        s.push_back($7);
        s.push_back($9);
        $$ = makeNode("for", s);
    }
;

ForInit:
    StatementExpressionList {
        $$ = $1;
    }
    | LocalVariableDeclaration {
        $$ = $1;
    }
    |   {
        $$=NULL;
    }
;

StatementExpressionList:
    StatementExpressionList ',' StatementExpression  {
        vector<ASTNode*> s;
        s.push_back($1);
        s.push_back($3);
        $$ = makeNode(",", s);
    }
    | StatementExpression {
        $$=$1;
    }
;

// 14 end

//Classes
ClassDeclaration:
    NormalClassDeclaration {
        $$=$1;
    }
;
NormalClassDeclaration:
    Modifiers KEY_class IDENTIFIER ClassBody {
        vector<ASTNode*> s;
        s.push_back($1);
        s.push_back(makeLeaf("ID (" + *$3+")" ));
        delete $3;
        s.push_back($4);
        $$ = makeNode("class", s);
    }
    | Modifiers KEY_class IDENTIFIER ClassExtends ClassBody {
        vector<ASTNode*> s;
        s.push_back($1);
        s.push_back(makeLeaf("ID (" + *$3+")" ));
        delete $3 ;
        s.push_back($4);
        s.push_back($5);
        $$ = makeNode("class", s);
    }
    | Modifiers KEY_class IDENTIFIER ClassPermits ClassBody {
        vector<ASTNode*> s;
        s.push_back($1);
        s.push_back(makeLeaf("ID (" + *$3+")" ));
        delete $3;
        s.push_back($4);
        s.push_back($5);
        $$ = makeNode("class", s);
    }
    | Modifiers KEY_class IDENTIFIER ClassExtends ClassPermits ClassBody {
        vector<ASTNode*> s;
        s.push_back($1);
        s.push_back(makeLeaf("ID (" + *$3+")" ));
        delete $3;
        s.push_back($4);
        s.push_back($5);
        s.push_back($6);
        $$ = makeNode("class", s);
    }
;
ClassExtends:
    KEY_extends ClassType {
        vector<ASTNode*> s;
        s.push_back($2);
        $$ = makeNode("extends", s);
    }
;
ClassPermits:
    KEY_permits IDENdotIDEN cTypeName {
        vector<ASTNode*> s;
        s.push_back($2);
        s.push_back($3);
        $$ = makeNode("permits", s);
    }
;

cTypeName:
    cTypeName ',' IDENdotIDEN {
        vector<ASTNode*> s;
        s.push_back($1);
        s.push_back($3);
        $$ = makeNode(",", s);
    }
    |   {
        $$=NULL;
    }
;

ClassBody:
    '{' ClassBodyDeclarations '}' {
        $$=$2;
    }
;
ClassBodyDeclarations:
    ClassBodyDeclarations ClassBodyDeclaration {
        vector<ASTNode*> s;
        s.push_back($1);
        s.push_back($2);
        $$ = makeNode("ClassBodyDeclarations", s);
    }
    |   {
        $$=NULL;
    }
;
ClassBodyDeclaration:
    Modifiers Type VariableDeclaratorList ';' {
        vector<ASTNode*> s;
        s.push_back($1);
        s.push_back($2);
        s.push_back($3);
        $$ = makeNode("ClassBodyDeclaration", s);
        type = "";
    }
    | ClassDeclaration {
        $$=$1;
    }
    | ';' {
        $$=NULL;
    }
    | Block {
        $$=$1;
    }
    | Modifiers IdenPara Block {
        vector<ASTNode*> s;
        s.push_back($1);
        s.push_back($2);
        s.push_back($3);
        $$ = makeNode("ClassBodyDeclaration", s);
    }
    | MethodDeclaration {
        $$=$1;
    }
;

VariableDeclaratorList:
    VariableDeclaratorList ',' VariableDeclarator {
        vector<ASTNode*> s;
        s.push_back($1);
        s.push_back($3);
        $$ = makeNode(",", s);
    }
    | VariableDeclarator {
        $$=$1;
    }
;

VariableDeclarator:
    VariableDeclarator1 {
        $$=$1;
    }
    | VariableDeclarator2 {
        $$=$1;
    }
;

zerooroneExpression:
    Expression {
        $$=$1;
    }
    |   {$$=NULL;}
;

VariableDeclarator1:
    IDENTIFIER {
        $$ = makeLeaf("ID (" + *$1 +")");

        $$->expType = 1;
        if(type!="") $$->type = type;
        else{
            printf("Type is not defined\n");
        }
        delete $1;
    }
    | IDENTIFIER '[' zerooroneExpression ']' {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("ID (" + *$1 +")" ));
        delete $1;
        s.push_back($3);
        $$ = makeNode("VariableDeclarator1", s);
    }
    | IDENTIFIER '[' zerooroneExpression ']' '[' zerooroneExpression ']' {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("ID (" + *$1 +")" ));
        delete $1;
        s.push_back($3);
        s.push_back($6);
        $$ = makeNode("VariableDeclarator1", s);
    }
    | IDENTIFIER '[' zerooroneExpression ']' '[' zerooroneExpression ']' '[' zerooroneExpression ']' {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("ID (" + *$1+")" ));
        delete $1;
        s.push_back($3);
        s.push_back($6);
        s.push_back($9);
        $$ = makeNode("VariableDeclarator1", s);
    }
;

VariableDeclarator2:
    IDENTIFIER '=' Expression {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("ID (" + *$1+")" ));
        delete $1;
        s.push_back($3);
        $$ = makeNode("=",s);
    }
    | IDENTIFIER '[' zerooroneExpression ']' '=' List1 {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("ID (" + *$1+")" ));
        delete $1;
        s.push_back($3);
        s.push_back($6);
        $$ = makeNode("=", s);
    }
    | IDENTIFIER '[' zerooroneExpression ']' '[' zerooroneExpression ']' '=' List2 {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("ID (" + *$1+")" ));
        delete $1;
        s.push_back($3);
        s.push_back($6);
        s.push_back($9);
        $$ = makeNode("=", s);
    }
    | IDENTIFIER '[' zerooroneExpression ']' '[' zerooroneExpression ']' '[' zerooroneExpression ']' '=' List3 {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("ID (" + *$1+")" ));
        delete $1;
        s.push_back($3);
        s.push_back($6);
        s.push_back($9);
        s.push_back($12);
        $$ = makeNode("=", s);
    }
    | IDENTIFIER '[' zerooroneExpression ']' '=' KEY_new PrimitiveType '[' zerooroneExpression ']' List1 {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("ID (" + *$1+")" ));
        delete $1;
        s.push_back($3);
        s.push_back(makeLeaf("new"));
        s.push_back($7);
        s.push_back($9);
        s.push_back($11);
        $$ = makeNode("=", s);
    }
    | IDENTIFIER '[' zerooroneExpression ']' '[' zerooroneExpression ']' '=' KEY_new PrimitiveType '[' zerooroneExpression ']' '[' zerooroneExpression ']' List2 {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("ID (" + *$1+")" ));
        delete $1;
        s.push_back($3);
        s.push_back($6);
        s.push_back(makeLeaf("new"));
        s.push_back($10);
        s.push_back($12);
        s.push_back($15);
        s.push_back($17);
        $$ = makeNode("=", s);
    }
    | IDENTIFIER '[' zerooroneExpression ']' '[' zerooroneExpression ']' '[' zerooroneExpression ']' '=' KEY_new PrimitiveType '[' zerooroneExpression ']' '[' zerooroneExpression ']' '[' zerooroneExpression ']' List3 {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("ID (" + *$1+")" ));
        delete $1;
        s.push_back($3);
        s.push_back($6);
        s.push_back($9);
        s.push_back(makeLeaf("new"));
        s.push_back($13);
        s.push_back($15);
        s.push_back($18);
        s.push_back($21);
        s.push_back($23);
        $$ = makeNode("=", s);
    }
    | IDENTIFIER '[' zerooroneExpression ']' '=' KEY_new PrimitiveType '[' zerooroneExpression ']' {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("ID (" + *$1+")" ));
        delete $1;
        s.push_back($3);
        s.push_back(makeLeaf("new"));
        s.push_back($7);
        s.push_back($9);
        $$ = makeNode("=", s);
    }
    | IDENTIFIER '[' zerooroneExpression ']' '[' zerooroneExpression ']' '=' KEY_new PrimitiveType '[' zerooroneExpression ']' '[' zerooroneExpression ']' {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("ID (" + *$1+")" ));
        delete $1;
        s.push_back($3);
        s.push_back($6);
        s.push_back(makeLeaf("new"));
        s.push_back($10);
        s.push_back($12);
        s.push_back($15);
        $$ = makeNode("=", s);
    }
    | IDENTIFIER '[' zerooroneExpression ']' '[' zerooroneExpression ']' '[' zerooroneExpression ']' '=' KEY_new PrimitiveType '[' zerooroneExpression ']' '[' zerooroneExpression ']' '[' zerooroneExpression ']' {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("ID (" + *$1+")" ));
        delete $1;
        s.push_back($3);
        s.push_back($6);
        s.push_back($9);
        s.push_back(makeLeaf("new"));
        s.push_back($13);
        s.push_back($15);
        s.push_back($18);
        s.push_back($21);
        $$ = makeNode("=", s);
    }
;

List1:
    '{' ArrEle1 '}' {
        $$=$2;
    }
;

ArrEle1:
    ArrEle1 ',' Expression {
        vector<ASTNode*> s;
        s.push_back($1);
        s.push_back($3);
        $$ = makeNode(",", s);
    }
    | Expression {
       $$=$1;
    }
;

List2:
    '{' ArrEle2 '}' {
        $$=$2;
    }
;

ArrEle2:
    ArrEle2 ',' List1 {
        vector<ASTNode*> s;
        s.push_back($1);
        s.push_back($3);
        $$ = makeNode(",", s);
    }
    | List1 {
        $$=$1;
    }
;

List3:
    '{' ArrEle3 '}' {
        $$=$2;
    }
;

ArrEle3:
    ArrEle3 ',' List2 {
        vector<ASTNode*> s;
        s.push_back($1);
        s.push_back($3);
        $$ = makeNode(",", s);
    }
    | List2 {
        $$=$1;
    }
;

MethodDeclaration:
    Modifiers MethodHeader MethodBody {
        vector<ASTNode*> s;
        s.push_back($1);
        s.push_back($2);
        s.push_back($3);
        $$ = makeNode("MethodDeclaration", s);
    }
;

MethodHeader:
    Type Methodeclarator {
        vector<ASTNode*> s;
        s.push_back($1);
        s.push_back($2);
        $$ = makeNode("MethodHeader", s);
    }
    | KEY_void Methodeclarator {
        vector<ASTNode*> s;
        s.push_back($2);
        $$ = makeNode("void", s);
    }
;

Methodeclarator:
    IdenPara Dims {
        $$=$1;
    }
    | IdenPara {
        $$=$1;
    }
;

IdenPara:
    IDENTIFIER '(' formalparameters ')' {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("ID (" + *$1+")" ));
        delete $1;
        s.push_back($3);
        $$ = makeNode("IdenPara", s);
    }
    | IDENTIFIER '(' ')' {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("ID (" + *$1+")" ));
        delete $1;
        $$ = makeNode("IdenPara", s);
    }
;
formalparameters:
    formalparameters ',' formalparameter {
        vector<ASTNode*> s;
        s.push_back($1);
        s.push_back($3);
        $$ = makeNode(",", s);
    }
    | formalparameter {
        $$=$1;
    }
;

formalparameter:
    Type VariableDeclarator1 {
        vector<ASTNode*> s;
        s.push_back($1);
        s.push_back($2);
        $$ = makeNode("formalparameter", s);
    }
    | Type DOT3 IDENTIFIER {
        vector<ASTNode*> s;
        s.push_back($1);
        s.push_back(makeLeaf(*$2));
        delete $2;
        s.push_back(makeLeaf("ID (" + *$3+")" ));
        delete $3;
        $$ = makeNode("formalparameter", s);
    }
;

MethodBody:
    Block {
        $$=$1;
    }
    | ';' {
        $$=NULL;
    }
;

Modifiers:
    Modifiers PublicPrivateStatic {
        vector<ASTNode*> s;
        s.push_back($1);
        s.push_back($2);
        $$ = makeNode("Modifiers", s);
    }
    |   {$$=NULL;}
;

// Class and Method END
%%

void print_help(){
    printf(" options :::\n");
    printf(" --help           Display available options.\n");
    printf(" --input <file>   take <file> as input file.\n");
    printf(" --output <file>  will print the dot script in <file>.\n");
    printf(" --verbose        display the procedure in bit details.\n"); 
    return;                                                     
}

int main(int argc, char* argv[]){
    gotinputfile=false;
    gotoutputfile=false;
    verbosemode=false;

    for(int i=1;i<argc;i++){
        if(!strcmp(argv[i],"--input")){
            if(i==argc-1){
                printf("Error :: input file name not given.\n");
                return 0;
            }
            else if(gotinputfile){
                printf("Error :: multiple input file name detected.\n");
                return 0;
            }
            else{
                yyin = fopen(argv[i+1],"r");
                /* printf("%s\n", argv[i+1]); */
                if(yyin==NULL){
                    printf("%s can not be opened as an input file.\n", argv[i+1]);
                    return 0;
                } 
                i++;
                gotinputfile=true;
                continue;
            }
        }
        else if(!strcmp(argv[i],"--output")){
            if(i==argc-1){
                printf("Error :: output file name not given.\n");
                return 0;
            }
            else if(gotoutputfile){
                printf("Error :: multiple output file name detected.\n");
                return 0;
            }
            else{
                dotfile = fopen(argv[i+1], "w");
                i++;
                gotoutputfile=true;
                continue;
            }
        }
        else if(!strcmp(argv[i],"--help")){
            print_help();
            return 0;
        }
        else if(!strcmp(argv[i],"--verbose")){
            verbosemode=true;
        }
        else{
            printf("Argument: %s  not recognised.\n", argv[i]);return 0;
            
        }
    }
    if(!gotinputfile){
        printf("Inputfile name not mentioned.\n");
        return 0;
    }

    if(verbosemode){
        printf("Input file is opened");
        printf("....\n");
        printf("Starting the parser...\n");
    }

    if(!gotoutputfile) dotfile = fopen("temp.dot", "w");

    if(dotfile==NULL){
        printf("Dot file can not be opened.\n");
        return 0;
    }
    yyrestart(yyin);

    beginAST();
    if(yyparse()) return 0;
    endAST();
    
    if(verbosemode){
        printf("Parser work completed..\n");
        printf("Dot script has generated successfully");
        printf("....\n");
    }
}