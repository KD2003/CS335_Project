%{
#include"AST.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

FILE* dotfile;

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

%type<ptr> prog ImportList ClassDeclarationList Imports Type PrimitiveType IDENdotIDEN PublicPrivateStatic ClassType ArrayType Dims
%type<ptr> Primary PrimaryNoNewArray ClassInstanceCreationExpression Zeroorone_ArgumentList FieldAccess ArrayAccess MethodInvocation ArgumentList ArrayCreationExpression DimExpr Expression AssignmentExpression Assignment ConditionalExpression ConditionalAndExpression ConditionalOrExpression AndExpression ExclusiveOrExpression InclusiveOrExpression EqualityExpression RelationalExpression ShiftExpression MultiplicativeExpression AdditiveExpression UnaryExpression UnaryExpressionNotPlusMinus CastExpression PostfixExpression
%type<ptr> Block BlockStatement BlockStatements LocalVariableDeclaration LocalVariableType Statement StatementExpression StatementNoShortIf StatementWithoutTrailingSubstatement LeftHandSide AssertStatement BreakContinueStatement ForInit ForStatement ForStatementNoShortIf StatementExpressionList
%type<ptr> ClassDeclaration NormalClassDeclaration ClassExtends ClassPermits cTypeName ClassBody ClassBodyDeclaration ClassBodyDeclarations VariableDeclarator VariableDeclaratorList zerooroneExpression VariableDeclarator1 VariableDeclarator2 List1 List2 List3 ArrEle1 ArrEle2 ArrEle3 MethodHeader MethodDeclaration MethodBody Methodeclarator IdenPara formalparameter formalparameters Modifiers

%%
prog:
    ImportList ClassDeclarationList		{
        vector<stuff> s;
        insertAttr(s, $1);
        insertAttr(s, $2);
        $$ = makeNode("prog", s);
        }
;

ImportList:
    ImportList Imports  {
        vector<stuff> s;
        insertAttr(s, $1);
        insertAttr(s, $2);
        $$ = makeNode("ImportList", s);
    }
    |   {
        $$=NULL;
    }
;

ClassDeclarationList:
    ClassDeclarationList ClassDeclaration       {
        vector<stuff> s;
        insertAttr(s, $1);
        insertAttr(s, $2);
        $$ = makeNode("ClassDeclarationList", s);
    }
    | ClassDeclaration      {
        $$=$1;
    }
;

Imports:
    KEY_import IDENdotIDEN ';'      {
        vector<stuff> s;
        insertAttr(s, makeLeaf("import"));
        insertAttr(s, $2);
        $$ = makeNode("Imports", s);
    }
    | KEY_import KEY_static IDENdotIDEN ';'     {
        vector<stuff> s;
        insertAttr(s, makeLeaf("import"));
        insertAttr(s, makeLeaf("static"));
        insertAttr(s, $3);
        $$ = makeNode("Imports", s);
    }
    | KEY_import IDENdotIDEN '.' '*' ';'        {
        vector<stuff> s;
        insertAttr(s, makeLeaf("import"));
        insertAttr(s, $2);
        insertAttr(s,makeLeaf("*"));
        
        $$ = makeNode("Imports", s);   
    }
    | KEY_import KEY_static IDENdotIDEN '.' '*' ';'     {
        vector<stuff> s;
        insertAttr(s, makeLeaf("import"));
        insertAttr(s, makeLeaf("static"));
        insertAttr(s,$3);
        delete $3;
        $$ = makeNode("Imports", s);
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
        vector<stuff> s;
        insertAttr(s, makeLeaf(*$1));
        delete $1;
        $$ = makeNode("PrimitiveType", s);
    }
    | FPTYPE       {
        vector<stuff> s;
        insertAttr(s, makeLeaf(*$1));
        delete $1;
        $$ = makeNode("PrimitiveType", s);
    }
    | BOOLTYPE      {
        vector<stuff> s;
        insertAttr(s, makeLeaf(*$1));
        delete $1;
        $$ = makeNode("PrimitiveType", s);
    }
;

IDENdotIDEN:
    IDENdotIDEN '.' IDENTIFIER      {
        vector<stuff> s;
        insertAttr(s, $1);
        insertAttr(s, makeLeaf("IDENTIFIER (" + *$3 + ")"));
        delete $3;
        $$ = makeNode("IDENdotIDEN", s);
    }
    | IDENTIFIER    {
        vector<stuff> s;
        insertAttr(s, makeLeaf("IDENTIFIER (" + *$1 + ")"));
        delete $1;
        $$ = makeNode("IDENdotIDEN", s);
    }
;

PublicPrivateStatic:
    KEY_public      {
        vector<stuff> s;
        insertAttr(s, makeLeaf("public"));
        $$ = makeNode("PublicPrivateStatic", s);
    }
    | KEY_private       {
        vector<stuff> s;
        insertAttr(s, makeLeaf("private"));
        $$ = makeNode("PublicPrivateStatic", s);
    }
    | KEY_static        {
        vector<stuff> s;
        insertAttr(s, makeLeaf("static"));
        $$ = makeNode("PublicPrivateStatic", s);
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
        vector<stuff> s;
        insertAttr(s, makeLeaf("Literal"));
        $$ = makeNode("PrimaryNoNewArray", s);
    }
    /* | ClassLiteral */
    | KEY_this      {
        vector<stuff> s;
        insertAttr(s, makeLeaf("this"));
        $$ = makeNode("PrimaryNoNewArray", s);
    }
    | IDENdotIDEN '.' KEY_this      {
        vector<stuff> s;
        insertAttr(s, $1);
        insertAttr(s, makeLeaf("this"));
        
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
        vector<stuff> s;
        insertAttr(s, makeLeaf("new"));
        insertAttr(s, $2);
        insertAttr(s, $4);
        insertAttr(s, $6);
        $$ = makeNode("ClassInstanceCreationExpression", s);
    }
    | KEY_new IDENdotIDEN '(' Zeroorone_ArgumentList ')'        {
        vector<stuff> s;
        insertAttr(s, makeLeaf("new"));
        insertAttr(s, $2);
        insertAttr(s, $4);
        $$ = makeNode("ClassInstanceCreationExpression", s);
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
        vector<stuff> s;
        insertAttr(s, $1);
        insertAttr(s, makeLeaf("IDENTIFIER (" + *$3 + ")"));
        delete $3;
        
        $$ = makeNode("FieldAccess", s);
    }
    | KEY_super '.' IDENTIFIER      {
        vector<stuff> s;
        insertAttr(s, makeLeaf("super"));
        insertAttr(s, makeLeaf("IDENTIFIER (" + *$3 + ")"));
        delete $3;
        $$ = makeNode("FieldAccess", s);
    }
    | IDENdotIDEN '.' KEY_super '.' IDENTIFIER      {
        vector<stuff> s;
        insertAttr(s, $1);
        insertAttr(s, makeLeaf("super"));
        insertAttr(s, makeLeaf("IDENTIFIER (" + *$5 + ")"));
        delete $5;
        
        $$ = makeNode("FieldAccess", s);
    }
;

ArrayAccess:
    IDENdotIDEN '[' Expression ']'      {
        vector<stuff> s;
        insertAttr(s, $1);
        insertAttr(s, $3);
        $$ = makeNode("ArrayAccess", s);
    }
    | PrimaryNoNewArray '[' Expression ']'      {
        vector<stuff> s;
        insertAttr(s, $1);
        insertAttr(s, $3);
        $$ = makeNode("ArrayAccess", s);
    }
;

MethodInvocation:
    IDENdotIDEN '(' Zeroorone_ArgumentList ')'          {
        vector<stuff> s;
        insertAttr(s, $1);
        insertAttr(s, $3);
        
        
        $$ = makeNode("MethodInvocation", s);
    }
    | Primary '.' IDENTIFIER '(' Zeroorone_ArgumentList ')'     {
        vector<stuff> s;
        insertAttr(s, $1);
        insertAttr(s, makeLeaf("IDENTIFIER (" + *$3 + ")"));
        delete $3;
        insertAttr(s, $5);
        
        
        
        $$ = makeNode("MethodInvocation", s);
    }
    | KEY_super '.' IDENTIFIER '(' Zeroorone_ArgumentList ')'       {
        vector<stuff> s;
        insertAttr(s, makeLeaf("super"));
        insertAttr(s, makeLeaf("IDENTIFIER (" + *$3 + ")"));
        delete $3;
        insertAttr(s, $5);
        
        
        
        $$ = makeNode("MethodInvocation", s);
    }
    | IDENdotIDEN '.' KEY_super '.' IDENTIFIER '(' Zeroorone_ArgumentList ')'      {
        vector<stuff> s;
        insertAttr(s, $1);
        insertAttr(s, makeLeaf("super"));
        insertAttr(s, makeLeaf("IDENTIFIER (" + *$5 + ")"));
        delete $5;
        insertAttr(s, $7);
        $$ = makeNode("MethodInvocation", s);   
    }
;

ArgumentList:
    ArgumentList ',' Expression     {
        vector<stuff> s;
        insertAttr(s, $1);
        insertAttr(s, $3);
        
        
        $$ = makeNode("ArguementList", s);
    }
    | Expression        {
        $$ = $1;
    }
;

ArrayCreationExpression:        // array initiaizer to do
    KEY_new PrimitiveType DimExpr Dims      {
        vector<stuff> s;
        insertAttr(s, makeLeaf("new"));
        insertAttr(s, $2);
        insertAttr(s, $3);
        insertAttr(s, $4);
        
        
        
        $$ = makeNode("ArrayCreationExpression", s);
    }
    | KEY_new PrimitiveType DimExpr     {
        vector<stuff> s;
        insertAttr(s, makeLeaf("new"));
        insertAttr(s, $2);
        insertAttr(s, $3);
        
        
        $$ = makeNode("ArrayCreationExpression", s);
    }
    | KEY_new IDENdotIDEN DimExpr Dims      {
        vector<stuff> s;
        insertAttr(s, makeLeaf("new"));
        insertAttr(s, $2);
        insertAttr(s, $3);
        insertAttr(s, $4);
        
        
        
        $$ = makeNode("ArrayCreationExpression", s);
    }
    | KEY_new IDENdotIDEN DimExpr       {
        vector<stuff> s;
        insertAttr(s, makeLeaf("new"));
        insertAttr(s, $2);
        insertAttr(s, $3);
        
        
        $$ = makeNode("ArrayCreationExpression", s);
    }
    /* | KEY_new PrimitiveType Dims ArrayInitializer */
;

DimExpr:
    DimExpr '[' Expression ']'  {
        vector<stuff> s;
        insertAttr(s, $1);
        insertAttr(s, $3);
        
        
        $$ = makeNode("DimExpr", s);
    }
    | '[' Expression ']'        {
        vector<stuff> s;
        insertAttr(s, $2);
        
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
        vector<stuff> s;
        insertAttr(s, $1);
        insertAttr(s, makeLeaf(*$2));
        insertAttr(s, $3);
        delete $2;
        
        
        $$ = makeNode("Assignment", s);
    }	// or Assignment
    | LeftHandSide '=' Expression       {
        vector<stuff> s;
        insertAttr(s, $1);
        insertAttr(s, makeLeaf("="));
        insertAttr(s, $3);
        
        
        $$ = makeNode("Assignment", s);
    }
;

ConditionalExpression:
    ConditionalOrExpression     {
        $$ = $1;
    }
    | ConditionalOrExpression '?' Expression ':' ConditionalExpression      {
        vector<stuff> s;
        insertAttr(s, $1);
        insertAttr(s, makeLeaf("?"));
        insertAttr(s, $3);
        insertAttr(s, makeLeaf(":"));
        insertAttr(s, $5);
        
        
        
        $$ = makeNode("ConditionalExpression", s);
    }
;

ConditionalOrExpression:
    ConditionalAndExpression        {
        $$ = $1;
    }
    | ConditionalOrExpression CONDOR ConditionalAndExpression       {
        vector<stuff> s;
        insertAttr(s, $1);
        insertAttr(s, makeLeaf("||"));
        insertAttr(s, $3);
        
        
        
        $$ = makeNode("ConditionalOrExpression", s);
    }
;

ConditionalAndExpression:
    InclusiveOrExpression   {
        $$ = $1;
    }
    | ConditionalAndExpression CONDAND InclusiveOrExpression        {
        vector<stuff> s;
        insertAttr(s, $1);
        insertAttr(s, makeLeaf("&&"));
        insertAttr(s, $3);
        
        
        
        $$ = makeNode("ConditionalAndExpression", s);
    }
;

AndExpression:
    EqualityExpression      {
        $$ = $1;
    }
    | AndExpression '&' EqualityExpression      {
        vector<stuff> s;
        insertAttr(s, $1);
        insertAttr(s, makeLeaf("&"));
        insertAttr(s, $3);
        
        
        $$ = makeNode("AndExpression", s);
    }
;

ExclusiveOrExpression:
    AndExpression       {
        $$ = $1;
    }
    | ExclusiveOrExpression '^' AndExpression       {
        vector<stuff> s;
        insertAttr(s, $1);
        insertAttr(s, makeLeaf("^"));
        insertAttr(s, $3);
        
        
        $$ = makeNode("ExclusiveOrExpression", s);
    }
;       

InclusiveOrExpression:
    ExclusiveOrExpression       {
        $$ = $1;
    }
    | InclusiveOrExpression '|' ExclusiveOrExpression       {
        vector<stuff> s;
        insertAttr(s, $1);
        insertAttr(s, makeLeaf("|"));
        insertAttr(s, $3);
        
        
        $$ = makeNode("InclusiveOrExpression", s);
    }
;

EqualityExpression:
    RelationalExpression    {
        $$ = $1;
    }
    | EqualityExpression EQALITYOP RelationalExpression {
        vector<stuff> s;
        insertAttr(s, $1);
        insertAttr(s, makeLeaf(*$2));
        insertAttr(s, $3);
        delete $2;
        
        
        $$ = makeNode("EqualityExpression", s);
    }
;

RelationalExpression:
    ShiftExpression     {
        $$ = $1;
    }
    | RelationalExpression RELATIONOP ShiftExpression       {
        vector<stuff> s;
        insertAttr(s, $1);
        insertAttr(s, makeLeaf(*$2));
        insertAttr(s, $3);
        delete $2;
        
        
        $$ = makeNode("RelationalExpression", s);
    }
;

ShiftExpression:
    AdditiveExpression      {
        $$ = $1;
    }
    | ShiftExpression SHIFTOP AdditiveExpression    {
        vector<stuff> s;
        insertAttr(s, $1);
        insertAttr(s, makeLeaf(*$2));
        insertAttr(s, $3);
        delete $2;
        
        
        $$ = makeNode("ShiftExpression", s);
    }
;

AdditiveExpression:
    MultiplicativeExpression        {
        $$ = $1;
    }
    | AdditiveExpression ADDOP MultiplicativeExpression     {
        vector<stuff> s;
        insertAttr(s, $1);
        insertAttr(s, makeLeaf(*$2));
        insertAttr(s, $3);
        delete $2;
        
        
        $$ = makeNode("AdditiveExpression", s);
    }
;

MultiplicativeExpression:
    UnaryExpression     {
        $$ = $1;      
    }
    | MultiplicativeExpression MULTOP UnaryExpression       {
        vector<stuff> s;
        insertAttr(s, $1);
        insertAttr(s, makeLeaf(*$2));
        insertAttr(s, $3);
        delete $2;
        
        
        $$ = makeNode("MultiplicativeExpression", s);
    }
;

UnaryExpression:
    ADDOP2 UnaryExpression      {
        vector<stuff> s;
        insertAttr(s, makeLeaf(*$1));
        insertAttr(s, $2);
        delete $1;
        
        $$ = makeNode("UnaryExpression", s);
    }
    | ADDOP UnaryExpression     {
        vector<stuff> s;
        insertAttr(s, makeLeaf(*$1));
        insertAttr(s, $2);
        delete $1;
        
        $$ = makeNode("UnaryExpression", s);
    }
    | UnaryExpressionNotPlusMinus   {
        $$ = $1;
    }
    | CastExpression        {
        vector<stuff> s;
        insertAttr(s, $1);
        
        $$ = makeNode("UnaryExpression", s);
    }
;

UnaryExpressionNotPlusMinus:
    PostfixExpression   {
        $$ = $1;
    }
    | UNARYOP UnaryExpression   {
        vector<stuff> s;
        insertAttr(s, makeLeaf(*$1));
        insertAttr(s, $2);
        delete $1;
        
        $$ = makeNode("UnaryExpressionNotPlus", s);
    }
;

CastExpression:
    '(' PrimitiveType ')' UnaryExpression   {
        vector<stuff> s;
        insertAttr(s, $2);
        insertAttr(s, $4);
        
        
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
        vector<stuff> s;
        insertAttr(s, $1);
        insertAttr(s, makeLeaf(*$2));
        delete $2;
        
        $$ = makeNode("PostfixExpression", s);
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
        vector<stuff> s;
        insertAttr(s, $1);
        insertAttr(s, $2);
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
        vector<stuff> s;
        insertAttr(s, $1);
        insertAttr(s, $2);
        $$ = makeNode("LocalVariableDeclaration", s);
    }
;

LocalVariableType:
    Type {
        $$=$1;
    }
    | KEY_VAR {
        vector<stuff> s;
        insertAttr(s, makeLeaf("var"));
        $$ = makeNode("LocalVariableType", s);
    }
;

Statement:
    StatementWithoutTrailingSubstatement {
        $$=$1;
    }
    | IDENTIFIER ':' Statement {
        vector<stuff> s;
        insertAttr(s, makeLeaf("IDENTIFIER (" + *$1+")" ));
        delete $1;
        insertAttr(s, makeLeaf(":"));
        insertAttr(s, $3);
        $$ = makeNode("Statement", s);
    }
    | KEY_if '(' Expression ')' Statement {
        vector<stuff> s;
        insertAttr(s, makeLeaf("if"));
        insertAttr(s, $3);
        insertAttr(s, $5);
        $$ = makeNode("Statement", s);
    }
    | KEY_if '(' Expression ')' StatementNoShortIf KEY_else Statement {
        vector<stuff> s;
        insertAttr(s, makeLeaf("if"));
        insertAttr(s, $3);
        insertAttr(s, $5);
        insertAttr(s, makeLeaf("else"));
        insertAttr(s, $7);
        $$ = makeNode("Statement", s);
    }
    | KEY_while '(' Expression ')' Statement {
        vector<stuff> s;
        insertAttr(s, makeLeaf("while"));
        insertAttr(s, $3);
        insertAttr(s, $5);
        $$ = makeNode("Statement", s);
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
        vector<stuff> s;
        insertAttr(s, makeLeaf("IDENTIFIER (" + *$1+")" ));
        delete $1;
        insertAttr(s,makeLeaf(":"));
        insertAttr(s, $3);
        $$ = makeNode("StatementNoShortIf", s);
    }
    | KEY_if '(' Expression ')' StatementNoShortIf KEY_else StatementNoShortIf {
        vector<stuff> s;
        insertAttr(s, makeLeaf("if"));
        insertAttr(s, $3);
        insertAttr(s, $5);
        insertAttr(s, makeLeaf("else"));
        insertAttr(s, $7);
        $$ = makeNode("StatementNoShortIf", s);
    }
    | KEY_while '(' Expression ')' StatementNoShortIf {
        vector<stuff> s;
        insertAttr(s, makeLeaf("while"));
        insertAttr(s, $3);
        insertAttr(s, $5);
        $$ = makeNode("StatementNoShortIf", s);
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
        vector<stuff> s;
        insertAttr(s, makeLeaf("return"));
        $$ = makeNode("StatementWithoutTrailingSubstatement", s);
    }
    | KEY_return Expression ';' {
        vector<stuff> s;
        insertAttr(s, makeLeaf("return"));
        insertAttr(s, $2);
        $$ = makeNode("StatementWithoutTrailingSubstatement", s);
    }
    | KEY_yield Expression ';' {
        vector<stuff> s;
        insertAttr(s, makeLeaf("yield"));
        insertAttr(s, $2);
        $$ = makeNode("StatementWithoutTrailingSubstatement", s);
    }
    | KEY_throw Expression ';' {
        vector<stuff> s;
        insertAttr(s, makeLeaf("throw"));
        insertAttr(s, $2);
        $$ = makeNode("StatementWithoutTrailingSubstatement", s);
    }
    | KEY_sync '(' Expression ')' Block {
        vector<stuff> s;
        insertAttr(s, makeLeaf("sync"));
        insertAttr(s, $3);
        insertAttr(s, $5);
        $$ = makeNode("StatementWithoutTrailingSubstatement", s);
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
        vector<stuff> s;
        insertAttr(s, makeLeaf(*$1));
        delete $1;
        $$ = makeNode("StatementExpression", s);
    }
    | PostfixExpression ADDOP2 {
        vector<stuff> s;
        insertAttr(s, $1);
        insertAttr(s, makeLeaf(*$2));
        delete $2;
        $$ = makeNode("StatementExpression", s);
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
        vector<stuff> s;
        insertAttr(s, makeLeaf("assert"));
        insertAttr(s, $2);
        $$ = makeNode("AssertStatement", s);
    }
    | KEY_assert Expression ':' Expression ';' {
        vector<stuff> s;
        insertAttr(s, makeLeaf("assert"));
        insertAttr(s, $2);
        insertAttr(s, makeLeaf(":"));
        insertAttr(s, $4);
        $$ = makeNode("AssertStatement", s);
    }
;

BreakContinueStatement:
    KEY_break IDENTIFIER ';' {
        vector<stuff> s;
        insertAttr(s, makeLeaf("break"));
        insertAttr(s, makeLeaf("IDENTIFIER (" + *$2+")" ));
        delete $2;
        $$ = makeNode("BreakContinueStatement", s);
    }
    | KEY_break ';' {
        vector<stuff> s;
        insertAttr(s, makeLeaf("break"));
        $$ = makeNode("BreakContinueStatement", s);
    }
    | KEY_continue IDENTIFIER ';' {
        vector<stuff> s;
        insertAttr(s, makeLeaf("continue"));
        insertAttr(s, makeLeaf("IDENTIFIER (" + *$2+")" ));
        delete $2;
        $$ = makeNode("BreakContinueStatement", s);
    }
    | KEY_continue ';' {
        vector<stuff> s;
        insertAttr(s, makeLeaf("continue"));
        $$ = makeNode("BreakContinueStatement", s);
    }
;

ForStatement:
    KEY_for '(' ForInit ';' ';' ')' Statement {
        vector<stuff> s;
        insertAttr(s, makeLeaf("for"));
        insertAttr(s, $3);
        insertAttr(s, $7);
        $$ = makeNode("ForStatement", s);
    }
    | KEY_for '(' ForInit ';' Expression ';' ')' Statement {
        vector<stuff> s;
        insertAttr(s, makeLeaf("for"));
        insertAttr(s, $3);
        insertAttr(s, $5);
        insertAttr(s, $8);
        $$ = makeNode("ForStatement", s);
    }
    | KEY_for '(' ForInit ';' ';' StatementExpressionList ')' Statement {
        vector<stuff> s;
        insertAttr(s, makeLeaf("for"));
        insertAttr(s, $3);
        insertAttr(s, $6);
        insertAttr(s, $8);
        $$ = makeNode("ForStatement", s);
    }
    | KEY_for '(' ForInit ';' Expression ';' StatementExpressionList ')' Statement {
        vector<stuff> s;
        insertAttr(s, makeLeaf("for"));
        insertAttr(s, $3);
        insertAttr(s, $7);
        insertAttr(s, $9);
        $$ = makeNode("ForStatement", s);
    }
    /* | KEY_for '(' LocalVariableDeclaration ':' Expression ')' Statement */
;

ForStatementNoShortIf:
    KEY_for '(' ForInit ';' ';' ')' StatementNoShortIf {
        vector<stuff> s;
        insertAttr(s, makeLeaf("for"));
        insertAttr(s, $3);
        insertAttr(s, $7);
        $$ = makeNode("ForStatementNoShortIf", s);
    }
    | KEY_for '(' ForInit ';' Expression ';' ')' StatementNoShortIf {
        vector<stuff> s;
        insertAttr(s, makeLeaf("for"));
        insertAttr(s, $3);
        insertAttr(s, $5);
        insertAttr(s, $8);
        $$ = makeNode("ForStatementNoShortIf", s);
    }
    | KEY_for '(' ForInit ';' ';' StatementExpressionList ')' StatementNoShortIf {
        vector<stuff> s;
        insertAttr(s, makeLeaf("for"));
        insertAttr(s, $3);
        insertAttr(s, $6);
        insertAttr(s, $8);
        $$ = makeNode("ForStatementNoShortIf", s);
    }
    | KEY_for '(' ForInit ';' Expression ';' StatementExpressionList ')' StatementNoShortIf {
        vector<stuff> s;
        insertAttr(s, makeLeaf("for"));
        insertAttr(s, $3);
        insertAttr(s, $5);
        insertAttr(s, $7);
        insertAttr(s, $9);
        $$ = makeNode("ForStatementNoShortIf", s);
    }
    /* | KEY_for '(' LocalVariableDeclaration ':' Expression ')' StatementNoShortIf */
;

ForInit:
    StatementExpressionList {
        vector<stuff> s;
        insertAttr(s, $1);
        $$ = makeNode("ForInit", s);
    }
    | LocalVariableDeclaration {
        vector<stuff> s;
        insertAttr(s, $1);
        $$ = makeNode("ForInit", s);
    }
    |   {
        $$=NULL;
    }
;

StatementExpressionList:
    StatementExpressionList ',' StatementExpression  {
        vector<stuff> s;
        insertAttr(s, $1);
        insertAttr(s, $3);
        $$ = makeNode("StatementExpressionList", s);
    }
    | StatementExpression {
        $$=$1;
    }
;

// 14 end

// §10 (Arrays) START
/* ArrayInitializer:
    '{' zerooroneVariableInitializerList ',' '}'
    | '{' zerooroneVariableInitializerList '}'
;
zerooroneVariableInitializerList:
    VariableInitializerList
    | 
;
VariableInitializerList:
    VariableInitializerList ',' VariableInitializer
    | VariableInitializer
;
VariableInitializer:
    Expression
    | ArrayInitializer
; */
// §10 (Arrays) END

//Classes
ClassDeclaration:
    NormalClassDeclaration {
        $$=$1;
    }
;
NormalClassDeclaration:
    Modifiers KEY_class IDENTIFIER ClassBody {
        vector<stuff> s;
        insertAttr(s, $1);
        insertAttr(s, makeLeaf("class"));
        insertAttr(s, makeLeaf("IDENTIFIER (" + *$3+")" ));
        delete $3;
        insertAttr(s, $4);
        $$ = makeNode("NormalClassDeclaration", s);
    }
    | Modifiers KEY_class IDENTIFIER ClassExtends ClassBody {
        vector<stuff> s;
        insertAttr(s, $1);
        insertAttr(s, makeLeaf("class"));
        insertAttr(s, makeLeaf("IDENTIFIER (" + *$3+")" ));
        delete $3 ;
        insertAttr(s, $4);
        insertAttr(s, $5);
        $$ = makeNode("NormalClassDeclaration", s);
    }
    | Modifiers KEY_class IDENTIFIER ClassPermits ClassBody {
        vector<stuff> s;
        insertAttr(s, $1);
        insertAttr(s, makeLeaf("class"));
        insertAttr(s, makeLeaf("IDENTIFIER (" + *$3+")" ));
        delete $3;
        insertAttr(s, $4);
        insertAttr(s, $5);
        $$ = makeNode("NormalClassDeclaration", s);
    }
    | Modifiers KEY_class IDENTIFIER ClassExtends ClassPermits ClassBody {
        vector<stuff> s;
        insertAttr(s, $1);
        insertAttr(s, makeLeaf("class"));
        insertAttr(s, makeLeaf("IDENTIFIER (" + *$3+")" ));
        delete $3;
        insertAttr(s, $4);
        insertAttr(s, $5);
        insertAttr(s, $6);
        $$ = makeNode("NormalClassDeclaration", s);
    }
;
ClassExtends:
    KEY_extends ClassType {
        vector<stuff> s;
        insertAttr(s, makeLeaf("extends"));
        insertAttr(s, $2);
        $$ = makeNode("ClassExtends", s);
    }
;
ClassPermits:
    KEY_permits IDENdotIDEN cTypeName {
        vector<stuff> s;
        insertAttr(s, makeLeaf("permits"));
        insertAttr(s, $2);
        insertAttr(s, $3);
        $$ = makeNode("ClassPermits", s);
    }
;

cTypeName:
    cTypeName ',' IDENdotIDEN {
        vector<stuff> s;
        insertAttr(s, $1);
        insertAttr(s, $3);
        $$ = makeNode("cTypeName", s);
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
        vector<stuff> s;
        insertAttr(s, $1);
        insertAttr(s, $2);
        $$ = makeNode("ClassBodyDeclarations", s);
    }
    |   {
        $$=NULL;
    }
;
ClassBodyDeclaration:
    Modifiers Type VariableDeclaratorList ';' {
        vector<stuff> s;
        insertAttr(s, $1);
        insertAttr(s, $2);
        insertAttr(s, $3);
        $$ = makeNode("ClassBodyDeclaration", s);
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
        vector<stuff> s;
        insertAttr(s, $1);
        insertAttr(s, $2);
        insertAttr(s, $3);
        $$ = makeNode("ClassBodyDeclaration", s);
    }
    | MethodDeclaration {
        $$=$1;
    }
;

VariableDeclaratorList:
    VariableDeclaratorList ',' VariableDeclarator {
        vector<stuff> s;
        insertAttr(s, $1);
        insertAttr(s, $3);
        $$ = makeNode("VariableDeclaratorList", s);
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
        vector<stuff> s;
        insertAttr(s, makeLeaf("IDENTIFIER (" + *$1 +")" ));
        delete $1;
        $$ = makeNode("VariableDeclarator1", s);
    }
    | IDENTIFIER '[' zerooroneExpression ']' {
        vector<stuff> s;
        insertAttr(s, makeLeaf("IDENTIFIER (" + *$1 +")" ));
        delete $1;
        insertAttr(s, $3);
        $$ = makeNode("VariableDeclarator1", s);
    }
    | IDENTIFIER '[' zerooroneExpression ']' '[' zerooroneExpression ']' {
        vector<stuff> s;
        insertAttr(s, makeLeaf("IDENTIFIER (" + *$1 +")" ));
        delete $1;
        insertAttr(s, $3);
        insertAttr(s, $6);
        $$ = makeNode("VariableDeclarator1", s);
    }
    | IDENTIFIER '[' zerooroneExpression ']' '[' zerooroneExpression ']' '[' zerooroneExpression ']' {
        vector<stuff> s;
        insertAttr(s, makeLeaf("IDENTIFIER (" + *$1+")" ));
        delete $1;
        insertAttr(s, $3);
        insertAttr(s, $6);
        insertAttr(s, $9);
        $$ = makeNode("VariableDeclarator1", s);
    }
;

VariableDeclarator2:
    IDENTIFIER '=' Expression {
        vector<stuff> s;
        insertAttr(s, makeLeaf("IDENTIFIER (" + *$1+")" ));
        delete $1;
        insertAttr(s, makeLeaf("="));
        insertAttr(s, $3);
        $$ = makeNode("VariableDeclarator2", s);
    }
    | IDENTIFIER '[' zerooroneExpression ']' '=' List1 {
        vector<stuff> s;
        insertAttr(s, makeLeaf("IDENTIFIER (" + *$1+")" ));
        delete $1;
        insertAttr(s, $3);
        insertAttr(s, makeLeaf("="));
        insertAttr(s, $6);
        $$ = makeNode("VariableDeclarator2", s);
    }
    | IDENTIFIER '[' zerooroneExpression ']' '[' zerooroneExpression ']' '=' List2 {
        vector<stuff> s;
        insertAttr(s, makeLeaf("IDENTIFIER (" + *$1+")" ));
        delete $1;
        insertAttr(s, $3);
        insertAttr(s, $6);
        insertAttr(s, makeLeaf("="));
        insertAttr(s, $9);
        $$ = makeNode("VariableDeclarator2", s);
    }
    | IDENTIFIER '[' zerooroneExpression ']' '[' zerooroneExpression ']' '[' zerooroneExpression ']' '=' List3 {
        vector<stuff> s;
        insertAttr(s, makeLeaf("IDENTIFIER (" + *$1+")" ));
        delete $1;
        insertAttr(s, $3);
        insertAttr(s, $6);
        insertAttr(s, $9);
        insertAttr(s, makeLeaf("="));
        insertAttr(s, $12);
        $$ = makeNode("VariableDeclarator2", s);
    }
;

List1:
    '{' ArrEle1 '}' {
        $$=$2;
    }
;

ArrEle1:
    ArrEle1 ',' Expression {
        vector<stuff> s;
        insertAttr(s, $1);
        insertAttr(s, $3);
        $$ = makeNode("ArrEle1", s);
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
        vector<stuff> s;
        insertAttr(s, $1);
        insertAttr(s, $3);
        $$ = makeNode("ArrEle2", s);
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
        vector<stuff> s;
        insertAttr(s, $1);
        insertAttr(s, $3);
        $$ = makeNode("ArrEle3", s);
    }
    | List2 {
        $$=$1;
    }
;

MethodDeclaration:
    Modifiers MethodHeader MethodBody {
        vector<stuff> s;
        insertAttr(s, $1);
        insertAttr(s, $2);
        insertAttr(s, $3);
        $$ = makeNode("MethodDeclaration", s);
    }
;

MethodHeader:
    Type Methodeclarator {
        vector<stuff> s;
        insertAttr(s, $1);
        insertAttr(s, $2);
        $$ = makeNode("MethodHeader", s);
    }
    | KEY_void Methodeclarator {
        vector<stuff> s;
        insertAttr(s, makeLeaf("void"));
        insertAttr(s, $2);
        $$ = makeNode("MethodHeader", s);
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
        vector<stuff> s;
        insertAttr(s, makeLeaf("IDENTIFIER (" + *$1+")" ));
        delete $1;
        insertAttr(s, $3);
        $$ = makeNode("IdenPara", s);
    }
    | IDENTIFIER '(' ')' {
        vector<stuff> s;
        insertAttr(s, makeLeaf("IDENTIFIER (" + *$1+")" ));
        delete $1;
        $$ = makeNode("IdenPara", s);
    }
;
formalparameters:
    formalparameters ',' formalparameter {
        vector<stuff> s;
        insertAttr(s, $1);
        insertAttr(s, $3);
        $$ = makeNode("formalparameters", s);
    }
    | formalparameter {
        $$=$1;
    }
;

formalparameter:
    Type VariableDeclarator1 {
        vector<stuff> s;
        insertAttr(s, $1);
        insertAttr(s, $2);
        $$ = makeNode("formalparameter", s);
    }
    | Type DOT3 IDENTIFIER {
        vector<stuff> s;
        insertAttr(s, $1);
        insertAttr(s, makeLeaf(*$2));
        delete $2;
        insertAttr(s, makeLeaf("IDENTIFIER (" + *$3+")" ));
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
        vector<stuff> s;
        insertAttr(s, $1);
        insertAttr(s, $2);
        $$ = makeNode("Modifiers", s);
    }
    |   {$$=NULL;}
;

// Class and Method END
%%

int main(){
    dotfile = fopen("graphtest.dot","w");
    beginAST();
    if(yyparse()) return 0;
    endAST();
    return 0;
}