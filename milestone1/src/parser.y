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
        vector<ASTNode*> s;
        s.push_back($1);
        s.push_back($2);
        $$ = makeNode("prog", s);
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
        s.push_back(makeLeaf("import"));
        s.push_back($2);
        $$ = makeNode("Imports", s);
    }
    | KEY_import KEY_static IDENdotIDEN ';'     {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("import"));
        s.push_back(makeLeaf("static"));
        s.push_back($3);
        $$ = makeNode("Imports", s);
    }
    | KEY_import IDENdotIDEN '.' '*' ';'        {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("import"));
        s.push_back($2);
        s.push_back(makeLeaf("*"));
        
        $$ = makeNode("Imports", s);   
    }
    | KEY_import KEY_static IDENdotIDEN '.' '*' ';'     {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("import"));
        s.push_back(makeLeaf("static"));
        s.push_back($3);
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
        vector<ASTNode*> s;
        s.push_back(makeLeaf(*$1));
        delete $1;
        $$ = makeNode("PrimitiveType", s);
    }
    | FPTYPE       {
        vector<ASTNode*> s;
        s.push_back(makeLeaf(*$1));
        delete $1;
        $$ = makeNode("PrimitiveType", s);
    }
    | BOOLTYPE      {
        vector<ASTNode*> s;
        s.push_back(makeLeaf(*$1));
        delete $1;
        $$ = makeNode("PrimitiveType", s);
    }
;

IDENdotIDEN:
    IDENdotIDEN '.' IDENTIFIER      {
        vector<ASTNode*> s;
        s.push_back($1);
        s.push_back(makeLeaf("IDENTIFIER (" + *$3 + ")"));
        delete $3;
        $$ = makeNode("IDENdotIDEN", s);
    }
    | IDENTIFIER    {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("IDENTIFIER (" + *$1 + ")"));
        delete $1;
        $$ = makeNode("IDENdotIDEN", s);
    }
;

PublicPrivateStatic:
    KEY_public      {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("public"));
        $$ = makeNode("PublicPrivateStatic", s);
    }
    | KEY_private       {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("private"));
        $$ = makeNode("PublicPrivateStatic", s);
    }
    | KEY_static        {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("static"));
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
        vector<ASTNode*> s;
        s.push_back(makeLeaf("Literal"));
        $$ = makeNode("PrimaryNoNewArray", s);
    }
    /* | ClassLiteral */
    | KEY_this      {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("this"));
        $$ = makeNode("PrimaryNoNewArray", s);
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
        s.push_back(makeLeaf("new"));
        s.push_back($2);
        s.push_back($4);
        s.push_back($6);
        $$ = makeNode("ClassInstanceCreationExpression", s);
    }
    | KEY_new IDENdotIDEN '(' Zeroorone_ArgumentList ')'        {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("new"));
        s.push_back($2);
        s.push_back($4);
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
        vector<ASTNode*> s;
        s.push_back($1);
        s.push_back(makeLeaf("IDENTIFIER (" + *$3 + ")"));
        delete $3;
        
        $$ = makeNode("FieldAccess", s);
    }
    | KEY_super '.' IDENTIFIER      {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("super"));
        s.push_back(makeLeaf("IDENTIFIER (" + *$3 + ")"));
        delete $3;
        $$ = makeNode("FieldAccess", s);
    }
    | IDENdotIDEN '.' KEY_super '.' IDENTIFIER      {
        vector<ASTNode*> s;
        s.push_back($1);
        s.push_back(makeLeaf("super"));
        s.push_back(makeLeaf("IDENTIFIER (" + *$5 + ")"));
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
        s.push_back(makeLeaf("IDENTIFIER (" + *$3 + ")"));
        delete $3;
        s.push_back($5);
        
        
        
        $$ = makeNode("MethodInvocation", s);
    }
    | KEY_super '.' IDENTIFIER '(' Zeroorone_ArgumentList ')'       {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("super"));
        s.push_back(makeLeaf("IDENTIFIER (" + *$3 + ")"));
        delete $3;
        s.push_back($5);
        
        
        
        $$ = makeNode("MethodInvocation", s);
    }
    | IDENdotIDEN '.' KEY_super '.' IDENTIFIER '(' Zeroorone_ArgumentList ')'      {
        vector<ASTNode*> s;
        s.push_back($1);
        s.push_back(makeLeaf("super"));
        s.push_back(makeLeaf("IDENTIFIER (" + *$5 + ")"));
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
        
        
        $$ = makeNode("ArguementList", s);
    }
    | Expression        {
        $$ = $1;
    }
;

ArrayCreationExpression:        // array initiaizer to do
    KEY_new PrimitiveType DimExpr Dims      {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("new"));
        s.push_back($2);
        s.push_back($3);
        s.push_back($4);
        
        
        
        $$ = makeNode("ArrayCreationExpression", s);
    }
    | KEY_new PrimitiveType DimExpr     {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("new"));
        s.push_back($2);
        s.push_back($3);
        
        
        $$ = makeNode("ArrayCreationExpression", s);
    }
    | KEY_new IDENdotIDEN DimExpr Dims      {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("new"));
        s.push_back($2);
        s.push_back($3);
        s.push_back($4);
        
        
        
        $$ = makeNode("ArrayCreationExpression", s);
    }
    | KEY_new IDENdotIDEN DimExpr       {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("new"));
        s.push_back($2);
        s.push_back($3);
        
        
        $$ = makeNode("ArrayCreationExpression", s);
    }
    /* | KEY_new PrimitiveType Dims ArrayInitializer */
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
        s.push_back(makeLeaf(*$2));
        s.push_back($3);
        delete $2;
        
        
        $$ = makeNode("Assignment", s);
    }	// or Assignment
    | LeftHandSide '=' Expression       {
        vector<ASTNode*> s;
        s.push_back($1);
        s.push_back(makeLeaf("="));
        s.push_back($3);
        
        
        $$ = makeNode("Assignment", s);
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
        s.push_back(makeLeaf("||"));
        s.push_back($3);
        
        
        
        $$ = makeNode("ConditionalOrExpression", s);
    }
;

ConditionalAndExpression:
    InclusiveOrExpression   {
        $$ = $1;
    }
    | ConditionalAndExpression CONDAND InclusiveOrExpression        {
        vector<ASTNode*> s;
        s.push_back($1);
        s.push_back(makeLeaf("&&"));
        s.push_back($3);
        
        
        
        $$ = makeNode("ConditionalAndExpression", s);
    }
;

AndExpression:
    EqualityExpression      {
        $$ = $1;
    }
    | AndExpression '&' EqualityExpression      {
        vector<ASTNode*> s;
        s.push_back($1);
        s.push_back(makeLeaf("&"));
        s.push_back($3);
        
        
        $$ = makeNode("AndExpression", s);
    }
;

ExclusiveOrExpression:
    AndExpression       {
        $$ = $1;
    }
    | ExclusiveOrExpression '^' AndExpression       {
        vector<ASTNode*> s;
        s.push_back($1);
        s.push_back(makeLeaf("^"));
        s.push_back($3);
        
        
        $$ = makeNode("ExclusiveOrExpression", s);
    }
;       

InclusiveOrExpression:
    ExclusiveOrExpression       {
        $$ = $1;
    }
    | InclusiveOrExpression '|' ExclusiveOrExpression       {
        vector<ASTNode*> s;
        s.push_back($1);
        s.push_back(makeLeaf("|"));
        s.push_back($3);
        
        
        $$ = makeNode("InclusiveOrExpression", s);
    }
;

EqualityExpression:
    RelationalExpression    {
        $$ = $1;
    }
    | EqualityExpression EQALITYOP RelationalExpression {
        vector<ASTNode*> s;
        s.push_back($1);
        s.push_back(makeLeaf(*$2));
        s.push_back($3);
        delete $2;
        
        
        $$ = makeNode("EqualityExpression", s);
    }
;

RelationalExpression:
    ShiftExpression     {
        $$ = $1;
    }
    | RelationalExpression RELATIONOP ShiftExpression       {
        vector<ASTNode*> s;
        s.push_back($1);
        s.push_back(makeLeaf(*$2));
        s.push_back($3);
        delete $2;
        
        
        $$ = makeNode("RelationalExpression", s);
    }
;

ShiftExpression:
    AdditiveExpression      {
        $$ = $1;
    }
    | ShiftExpression SHIFTOP AdditiveExpression    {
        vector<ASTNode*> s;
        s.push_back($1);
        s.push_back(makeLeaf(*$2));
        s.push_back($3);
        delete $2;
        
        
        $$ = makeNode("ShiftExpression", s);
    }
;

AdditiveExpression:
    MultiplicativeExpression        {
        $$ = $1;
    }
    | AdditiveExpression ADDOP MultiplicativeExpression     {
        vector<ASTNode*> s;
        s.push_back($1);
        s.push_back(makeLeaf(*$2));
        s.push_back($3);
        delete $2;
        
        
        $$ = makeNode("AdditiveExpression", s);
    }
;

MultiplicativeExpression:
    UnaryExpression     {
        $$ = $1;      
    }
    | MultiplicativeExpression MULTOP UnaryExpression       {
        vector<ASTNode*> s;
        s.push_back($1);
        s.push_back(makeLeaf(*$2));
        s.push_back($3);
        delete $2;
        
        
        $$ = makeNode("MultiplicativeExpression", s);
    }
;

UnaryExpression:
    ADDOP2 UnaryExpression      {
        vector<ASTNode*> s;
        s.push_back(makeLeaf(*$1));
        s.push_back($2);
        delete $1;
        
        $$ = makeNode("UnaryExpression", s);
    }
    | ADDOP UnaryExpression     {
        vector<ASTNode*> s;
        s.push_back(makeLeaf(*$1));
        s.push_back($2);
        delete $1;
        
        $$ = makeNode("UnaryExpression", s);
    }
    | UnaryExpressionNotPlusMinus   {
        $$ = $1;
    }
    | CastExpression        {
        vector<ASTNode*> s;
        s.push_back($1);
        
        $$ = makeNode("UnaryExpression", s);
    }
;

UnaryExpressionNotPlusMinus:
    PostfixExpression   {
        $$ = $1;
    }
    | UNARYOP UnaryExpression   {
        vector<ASTNode*> s;
        s.push_back(makeLeaf(*$1));
        s.push_back($2);
        delete $1;
        
        $$ = makeNode("UnaryExpressionNotPlus", s);
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
        vector<ASTNode*> s;
        s.push_back(makeLeaf("var"));
        $$ = makeNode("LocalVariableType", s);
    }
;

Statement:
    StatementWithoutTrailingSubstatement {
        $$=$1;
    }
    | IDENTIFIER ':' Statement {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("IDENTIFIER (" + *$1+")" ));
        delete $1;
        s.push_back(makeLeaf(":"));
        s.push_back($3);
        $$ = makeNode("Statement", s);
    }
    | KEY_if '(' Expression ')' Statement {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("if"));
        s.push_back($3);
        s.push_back($5);
        $$ = makeNode("Statement", s);
    }
    | KEY_if '(' Expression ')' StatementNoShortIf KEY_else Statement {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("if"));
        s.push_back($3);
        s.push_back($5);
        s.push_back(makeLeaf("else"));
        s.push_back($7);
        $$ = makeNode("Statement", s);
    }
    | KEY_while '(' Expression ')' Statement {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("while"));
        s.push_back($3);
        s.push_back($5);
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
        vector<ASTNode*> s;
        s.push_back(makeLeaf("IDENTIFIER (" + *$1+")" ));
        delete $1;
        s.push_back(makeLeaf(":"));
        s.push_back($3);
        $$ = makeNode("StatementNoShortIf", s);
    }
    | KEY_if '(' Expression ')' StatementNoShortIf KEY_else StatementNoShortIf {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("if"));
        s.push_back($3);
        s.push_back($5);
        s.push_back(makeLeaf("else"));
        s.push_back($7);
        $$ = makeNode("StatementNoShortIf", s);
    }
    | KEY_while '(' Expression ')' StatementNoShortIf {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("while"));
        s.push_back($3);
        s.push_back($5);
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
        vector<ASTNode*> s;
        s.push_back(makeLeaf("return"));
        $$ = makeNode("StatementWithoutTrailingSubstatement", s);
    }
    | KEY_return Expression ';' {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("return"));
        s.push_back($2);
        $$ = makeNode("StatementWithoutTrailingSubstatement", s);
    }
    | KEY_yield Expression ';' {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("yield"));
        s.push_back($2);
        $$ = makeNode("StatementWithoutTrailingSubstatement", s);
    }
    | KEY_throw Expression ';' {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("throw"));
        s.push_back($2);
        $$ = makeNode("StatementWithoutTrailingSubstatement", s);
    }
    | KEY_sync '(' Expression ')' Block {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("sync"));
        s.push_back($3);
        s.push_back($5);
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
        vector<ASTNode*> s;
        s.push_back(makeLeaf(*$1));
        delete $1;
        $$ = makeNode("StatementExpression", s);
    }
    | PostfixExpression ADDOP2 {
        vector<ASTNode*> s;
        s.push_back($1);
        s.push_back(makeLeaf(*$2));
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
        vector<ASTNode*> s;
        s.push_back(makeLeaf("assert"));
        s.push_back($2);
        $$ = makeNode("AssertStatement", s);
    }
    | KEY_assert Expression ':' Expression ';' {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("assert"));
        s.push_back($2);
        s.push_back(makeLeaf(":"));
        s.push_back($4);
        $$ = makeNode("AssertStatement", s);
    }
;

BreakContinueStatement:
    KEY_break IDENTIFIER ';' {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("break"));
        s.push_back(makeLeaf("IDENTIFIER (" + *$2+")" ));
        delete $2;
        $$ = makeNode("BreakContinueStatement", s);
    }
    | KEY_break ';' {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("break"));
        $$ = makeNode("BreakContinueStatement", s);
    }
    | KEY_continue IDENTIFIER ';' {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("continue"));
        s.push_back(makeLeaf("IDENTIFIER (" + *$2+")" ));
        delete $2;
        $$ = makeNode("BreakContinueStatement", s);
    }
    | KEY_continue ';' {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("continue"));
        $$ = makeNode("BreakContinueStatement", s);
    }
;

ForStatement:
    KEY_for '(' ForInit ';' ';' ')' Statement {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("for"));
        s.push_back($3);
        s.push_back($7);
        $$ = makeNode("ForStatement", s);
    }
    | KEY_for '(' ForInit ';' Expression ';' ')' Statement {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("for"));
        s.push_back($3);
        s.push_back($5);
        s.push_back($8);
        $$ = makeNode("ForStatement", s);
    }
    | KEY_for '(' ForInit ';' ';' StatementExpressionList ')' Statement {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("for"));
        s.push_back($3);
        s.push_back($6);
        s.push_back($8);
        $$ = makeNode("ForStatement", s);
    }
    | KEY_for '(' ForInit ';' Expression ';' StatementExpressionList ')' Statement {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("for"));
        s.push_back($3);
        s.push_back($7);
        s.push_back($9);
        $$ = makeNode("ForStatement", s);
    }
    /* | KEY_for '(' LocalVariableDeclaration ':' Expression ')' Statement */
;

ForStatementNoShortIf:
    KEY_for '(' ForInit ';' ';' ')' StatementNoShortIf {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("for"));
        s.push_back($3);
        s.push_back($7);
        $$ = makeNode("ForStatementNoShortIf", s);
    }
    | KEY_for '(' ForInit ';' Expression ';' ')' StatementNoShortIf {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("for"));
        s.push_back($3);
        s.push_back($5);
        s.push_back($8);
        $$ = makeNode("ForStatementNoShortIf", s);
    }
    | KEY_for '(' ForInit ';' ';' StatementExpressionList ')' StatementNoShortIf {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("for"));
        s.push_back($3);
        s.push_back($6);
        s.push_back($8);
        $$ = makeNode("ForStatementNoShortIf", s);
    }
    | KEY_for '(' ForInit ';' Expression ';' StatementExpressionList ')' StatementNoShortIf {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("for"));
        s.push_back($3);
        s.push_back($5);
        s.push_back($7);
        s.push_back($9);
        $$ = makeNode("ForStatementNoShortIf", s);
    }
    /* | KEY_for '(' LocalVariableDeclaration ':' Expression ')' StatementNoShortIf */
;

ForInit:
    StatementExpressionList {
        vector<ASTNode*> s;
        s.push_back($1);
        $$ = makeNode("ForInit", s);
    }
    | LocalVariableDeclaration {
        vector<ASTNode*> s;
        s.push_back($1);
        $$ = makeNode("ForInit", s);
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
        vector<ASTNode*> s;
        s.push_back($1);
        s.push_back(makeLeaf("class"));
        s.push_back(makeLeaf("IDENTIFIER (" + *$3+")" ));
        delete $3;
        s.push_back($4);
        $$ = makeNode("NormalClassDeclaration", s);
    }
    | Modifiers KEY_class IDENTIFIER ClassExtends ClassBody {
        vector<ASTNode*> s;
        s.push_back($1);
        s.push_back(makeLeaf("class"));
        s.push_back(makeLeaf("IDENTIFIER (" + *$3+")" ));
        delete $3 ;
        s.push_back($4);
        s.push_back($5);
        $$ = makeNode("NormalClassDeclaration", s);
    }
    | Modifiers KEY_class IDENTIFIER ClassPermits ClassBody {
        vector<ASTNode*> s;
        s.push_back($1);
        s.push_back(makeLeaf("class"));
        s.push_back(makeLeaf("IDENTIFIER (" + *$3+")" ));
        delete $3;
        s.push_back($4);
        s.push_back($5);
        $$ = makeNode("NormalClassDeclaration", s);
    }
    | Modifiers KEY_class IDENTIFIER ClassExtends ClassPermits ClassBody {
        vector<ASTNode*> s;
        s.push_back($1);
        s.push_back(makeLeaf("class"));
        s.push_back(makeLeaf("IDENTIFIER (" + *$3+")" ));
        delete $3;
        s.push_back($4);
        s.push_back($5);
        s.push_back($6);
        $$ = makeNode("NormalClassDeclaration", s);
    }
;
ClassExtends:
    KEY_extends ClassType {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("extends"));
        s.push_back($2);
        $$ = makeNode("ClassExtends", s);
    }
;
ClassPermits:
    KEY_permits IDENdotIDEN cTypeName {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("permits"));
        s.push_back($2);
        s.push_back($3);
        $$ = makeNode("ClassPermits", s);
    }
;

cTypeName:
    cTypeName ',' IDENdotIDEN {
        vector<ASTNode*> s;
        s.push_back($1);
        s.push_back($3);
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
        vector<ASTNode*> s;
        s.push_back(makeLeaf("IDENTIFIER (" + *$1 +")" ));
        delete $1;
        $$ = makeNode("VariableDeclarator1", s);
    }
    | IDENTIFIER '[' zerooroneExpression ']' {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("IDENTIFIER (" + *$1 +")" ));
        delete $1;
        s.push_back($3);
        $$ = makeNode("VariableDeclarator1", s);
    }
    | IDENTIFIER '[' zerooroneExpression ']' '[' zerooroneExpression ']' {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("IDENTIFIER (" + *$1 +")" ));
        delete $1;
        s.push_back($3);
        s.push_back($6);
        $$ = makeNode("VariableDeclarator1", s);
    }
    | IDENTIFIER '[' zerooroneExpression ']' '[' zerooroneExpression ']' '[' zerooroneExpression ']' {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("IDENTIFIER (" + *$1+")" ));
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
        s.push_back(makeLeaf("IDENTIFIER (" + *$1+")" ));
        delete $1;
        s.push_back(makeLeaf("="));
        s.push_back($3);
        $$ = makeNode("VariableDeclarator2", s);
    }
    | IDENTIFIER '[' zerooroneExpression ']' '=' List1 {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("IDENTIFIER (" + *$1+")" ));
        delete $1;
        s.push_back($3);
        s.push_back(makeLeaf("="));
        s.push_back($6);
        $$ = makeNode("VariableDeclarator2", s);
    }
    | IDENTIFIER '[' zerooroneExpression ']' '[' zerooroneExpression ']' '=' List2 {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("IDENTIFIER (" + *$1+")" ));
        delete $1;
        s.push_back($3);
        s.push_back($6);
        s.push_back(makeLeaf("="));
        s.push_back($9);
        $$ = makeNode("VariableDeclarator2", s);
    }
    | IDENTIFIER '[' zerooroneExpression ']' '[' zerooroneExpression ']' '[' zerooroneExpression ']' '=' List3 {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("IDENTIFIER (" + *$1+")" ));
        delete $1;
        s.push_back($3);
        s.push_back($6);
        s.push_back($9);
        s.push_back(makeLeaf("="));
        s.push_back($12);
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
        vector<ASTNode*> s;
        s.push_back($1);
        s.push_back($3);
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
        vector<ASTNode*> s;
        s.push_back($1);
        s.push_back($3);
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
        vector<ASTNode*> s;
        s.push_back($1);
        s.push_back($3);
        $$ = makeNode("ArrEle3", s);
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
        s.push_back(makeLeaf("void"));
        s.push_back($2);
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
        vector<ASTNode*> s;
        s.push_back(makeLeaf("IDENTIFIER (" + *$1+")" ));
        delete $1;
        s.push_back($3);
        $$ = makeNode("IdenPara", s);
    }
    | IDENTIFIER '(' ')' {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("IDENTIFIER (" + *$1+")" ));
        delete $1;
        $$ = makeNode("IdenPara", s);
    }
;
formalparameters:
    formalparameters ',' formalparameter {
        vector<ASTNode*> s;
        s.push_back($1);
        s.push_back($3);
        $$ = makeNode("formalparameters", s);
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
        s.push_back(makeLeaf("IDENTIFIER (" + *$3+")" ));
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

int main(){
    dotfile = fopen("graphtest.dot","w");
    beginAST();
    if(yyparse()) return 0;
    endAST();
    return 0;
}