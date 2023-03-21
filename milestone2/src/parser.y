%{
#include"AST.h"
#include"typecheck.h"
#include <stdio.h>
#include <string>
#include <fstream>
using namespace std;

FILE* dotfile;
extern FILE* yyin;
extern int yyrestart(FILE*);
extern int yylineno;

bool gotinputfile, gotoutputfile, verbosemode;

int dump_sym_table=0;
int isArray=0;
int cnt1=0,cnt2=0,cnt3=0;
string type="";
string class_type="";
vector<int> array_dims;
vector<vector<string> > curArgs(1,vector<string>() );

int yylex();
int yyerror(const char *str);

%}

%locations
%token KEYWORD IDENTIFIER INTLIT FPLIT BOOLLIT CHARLIT STRLIT OPERATOR INTTYPE FPTYPE BOOLTYPE ASSIGNOP CONDOR CONDAND EQALITYOP RELATIONOP SHIFTOP ADDOP MULTOP ADDOP2 UNARYOP KEY_VAR KEY_assert KEY_yield KEY_throw KEY_break KEY_continue KEY_return KEY_if KEY_else KEY_for KEY_permits KEY_while KEY_sync KEY_final KEY_extends KEY_super KEY_this KEY_class KEY_void KEY_public KEY_new KEY_static DOT3 KEY_private KEY_import

%union{
    std::string *st;
    ASTNode *ptr;
}

%type<st> KEYWORD IDENTIFIER INTLIT FPLIT BOOLLIT CHARLIT STRLIT OPERATOR INTTYPE FPTYPE BOOLTYPE ASSIGNOP CONDOR CONDAND EQALITYOP RELATIONOP SHIFTOP ADDOP MULTOP ADDOP2 UNARYOP KEY_VAR KEY_assert KEY_yield KEY_throw KEY_break KEY_continue KEY_return KEY_if KEY_else KEY_for KEY_permits KEY_while KEY_sync KEY_final KEY_extends KEY_super KEY_this KEY_class KEY_void KEY_public KEY_new KEY_static DOT3 KEY_private KEY_import

%type<ptr> Start ImportList ClassDeclarationList Imports Type PrimitiveType IDENdotIDEN PublicPrivateStatic ClassType ArrayType Dims Literal
%type<ptr> Primary PrimaryNoNewArray ClassInstanceCreationExpression Zeroorone_ArgumentList FieldAccess ArrayAccess MethodInvocation ArgumentList ArrayCreationExpression DimExpr Expression AssignmentExpression Assignment ConditionalExpression ConditionalAndExpression ConditionalOrExpression AndExpression ExclusiveOrExpression InclusiveOrExpression EqualityExpression RelationalExpression ShiftExpression MultiplicativeExpression AdditiveExpression UnaryExpression UnaryExpressionNotPlusMinus CastExpression postfixExpression
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
        type="";
    }
    | KEY_import KEY_static IDENdotIDEN ';'     {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("static"));
        s.push_back($3);
        $$ = makeNode("import", s);
        type="";
    }
    | KEY_import IDENdotIDEN '.' '*' ';'        {
        vector<ASTNode*> s;
        s.push_back($2);
        s.push_back(makeLeaf("*"));
        $$ = makeNode("import", s);   
        type="";
    }
    | KEY_import KEY_static IDENdotIDEN '.' '*' ';'     {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("static"));
        s.push_back($3);
        $$ = makeNode("import", s);
        type="";
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
        class_type=class_type+"."+*$3;
        delete $3;
        $$ = makeNode(".", s);
    }
    | IDENTIFIER    {
        $$ = makeLeaf("ID (" + *$1 + ")");
        class_type=*$1;
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
        $$->type = class_type;
    }
;
ArrayType:
    PrimitiveType Dims      {
        $$=$1;
        isArray=1;
        $$->expType =2;
    }
    | ClassType Dims        {
        $$=$1;
        isArray=1;
        $$->expType=2;
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
Literal:
    INTLIT     {
        $$ = makeLeaf("Literal");
        $$->type ="int";
        $$->intVal = atoi((*$1).c_str());
        $$->expType = 4;
        delete $1;
    }
    | FPLIT     {
        $$ = makeLeaf("Literal");
        $$->type ="float";
        $$->realVal = atof((*$1).c_str());
        $$->expType = 4;
        delete $1;
    }
    | BOOLLIT       {
        $$ = makeLeaf("Literal");
        if(*$1 == "null"){
            //null
        }
        else{
            if(*$1=="true") $$->intVal=1;
            else $$->intVal=0;
            $$->type = "boolean";
        }
        $$->expType = 4;
        delete $1;
    }
    | CHARLIT       {
        $$ = makeLeaf("Literal");
        $$->type ="char";
        $$->strVal = *$1;
        $$->expType = 4;
        delete $1;
    }
    | STRLIT    {
        $$ = makeLeaf("Literal");
        $$->type ="String";
        $$->strVal = *$1;
        $$->expType = 5;
        delete $1;
    }
;

Primary:
    PrimaryNoNewArray   {
        $$ = $1;
    }
    | ArrayCreationExpression       {
        $$ = $1;
    }
;

PrimaryNoNewArray:
    Literal     {
        $$ = $1;
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
        if(type=="")type=$2->type;
        $$->type=type;
    }
    | KEY_new IDENdotIDEN '(' Zeroorone_ArgumentList ')'        {
        vector<ASTNode*> s;
        s.push_back($2);
        s.push_back($4);
        $$ = makeNode("new", s);
        if(type=="")type=$2->type;
        $$->type=type;
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

        if(type=="")type=$1->type;
        $$->type=type;

    }
    | PrimaryNoNewArray '[' Expression ']'      {
        vector<ASTNode*> s;
        s.push_back($1);
        s.push_back($3);
        $$ = makeNode("ArrayAccess", s);

        if(type=="")type=$1->type;
        $$->type=type;
        if($3->type!="INT"){
            fprintf(stdout,"Index of the array should be integer.");
        }
    }
;

MethodInvocation:
    IDENdotIDEN '(' Zeroorone_ArgumentList ')'          {
        vector<ASTNode*> s;
        s.push_back($1);
        s.push_back($3);
        $$ = makeNode("MethodInvocation", s);


        // string t=postfixExpression($1->type,2);
        // if(t.empty()){
        //     t=getFuncType($1->temp_name);
        // }

        // if(type=="")type=$1->type;
        // $$->type=type;
        string t = postfixExpression($1->type,2);
		curArgs.push_back(vector<string>() ); 

		if(t.empty()){
			t = getFuncType($1->temp_name);
		}

		if(!($1->is_error) && $1->expType!=4){
			if(!t.empty()){	
				$$->type = t;
                if($1->expType==3){
                    vector<string> funcArg = getFuncArgs($1->temp_name);
                    if(funcArg.empty()){
                        yyerror(("Too few Arguments to Function " + $1->temp_name).c_str());
                    }
                    else{
                        //3ac
                    }
                }
            }
            else{
				yyerror(("Function " + $1->temp_name + " not declared in this scope").c_str());
                $$->is_error=1;
            }
        }
        else{
            if($1->expType==4)yyerror("Constant Expression");
            $$->is_error=1;
        }


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
        
        // lookup for functions

		// if(!($3->is_error || $5->is_error) && $3->expType!=4){
		// 	if(!t.empty()){
		// 		if($3->expType ==3){
		// 			vector<string> funcArgs = getFuncArgs($1->temp_name);
		// 			vector<string> tempArgs =curArgs.back();
		// 			for(int i=0;i<funcArgs.size();i++){
		// 				if(funcArgs[i]=="...")break;
		// 				if(tempArgs.size()==i){
		// 					yyerror(("Too few Arguments to Function " + $1->temp_name).c_str());
		// 					break;
		// 				}
		// 				string msg = checkType(funcArgs[i],tempArgs[i]);

		// 				// if(msg =="warning"){
		// 				// 	warning(("Incompatible conversion of " +  tempArgs[i] + " to parameter of type " + funcArgs[i]).c_str());
		// 				// }
		// 				else if(msg.empty()){
		// 					yyerror(("Incompatible Argument to the function " + $1->temp_name).c_str());
		// 					$$->is_error = 1;
		// 					break;
		// 				}
		// 				if(i==funcArgs.size()-1 && i<tempArgs.size()-1){
		// 					yyerror(("Too many Arguments to Function " + $3->temp_name).c_str());
		// 					$$->is_error = 1;
		// 					break;
		// 				}

		// 			}	

		// 			//--3AC
		// 			// if(!$$->is_error){
		// 			// 	qid q = newtemp($$->type);
		// 			// 	$$->place = q;
		// 			// 	$$->nextlist.clear();

		// 			// 	emit(qid("CALL", NULL), qid($1->temp_name,NULL), qid(to_string(curArgs.back().size()), NULL), q, -1);
		// 			// 	curArgs.pop_back();

		// 			// 	if(func_usage_map.find($1->temp_name) != func_usage_map.end()){
		// 			// 		func_usage_map[$1->temp_name] = 1;
		// 			// 	}
		// 			// }

		// 		}
		// 	}
		// 	else{
		// 		yyerror("Invalid function call");
		// 		$$->is_error=1;
		// 	}
		// }
		// else{
		// 	if($1->expType==4){
		// 		yyerror("constant expression cannot be used as lvalue");
		// 	}
		// 	$$->is_error=1;
		// }
    }
    | IDENdotIDEN '.' KEY_super '.' IDENTIFIER '(' Zeroorone_ArgumentList ')'      {
        vector<ASTNode*> s;
        s.push_back($1);
        s.push_back(makeLeaf("super"));
        s.push_back(makeLeaf("ID (" + *$5 + ")"));
        delete $5;
        s.push_back($7);
        $$ = makeNode("MethodInvocation", s);   

        //
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

ArrayCreationExpression: 
    KEY_new PrimitiveType DimExpr Dims      {
        vector<ASTNode*> s;
        s.push_back($2);
        s.push_back($3);
        $$ = makeNode("new", s);

        if(type=="")type=$2->type;
        $$->type=type;

    }
    | KEY_new PrimitiveType DimExpr     {
        vector<ASTNode*> s;
        s.push_back($2);
        s.push_back($3);
        $$ = makeNode("new", s);

        if(type=="")type=$2->type;
        $$->type=type;
    }
    | KEY_new IDENdotIDEN DimExpr Dims      {
        vector<ASTNode*> s;
        s.push_back($2);
        s.push_back($3);
        $$ = makeNode("new", s);

        if(type=="")type=$2->type;
        $$->type=type;
    }
    | KEY_new IDENdotIDEN DimExpr       {
        vector<ASTNode*> s;
        s.push_back($2);
        s.push_back($3);
        $$ = makeNode("new", s);

        if(type=="")type=$2->type;
        $$->type=type;
    }
;

DimExpr:
    DimExpr '[' Expression ']'  {
        vector<ASTNode*> s;
        s.push_back($1);
        s.push_back($3);
        $$ = makeNode("DimExpr", s);

        if($3->type!="INT"){
            fprintf(stdout,"Index of the array should be integer.");
        }
    }
    | '[' Expression ']'        {
        vector<ASTNode*> s;
        s.push_back($2);
        $$ = makeNode("DimExpr", s);

        if($2->type!="INT"){
            fprintf(stdout,"Index of the array should be integer.");
        }
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

        string t=assignExp($1->type,$3->type,*$2);
        if(!$1->is_error && !$3->is_error && $1->expType!=4){
            if(!t.empty()){
                if(t=="ok"){
                    $$->type=$1->type;
                }
                // if($1->expType == 3 && $3->isInit){
				// 	updInit($1->temp_name);
				// }
            }
            else{
                fprintf(stdout,"Incompatible Types when comparing");
                $$->is_error=1;
            }
        }
        else if($1->expType==4){
                fprintf(stdout,"Right side cannot be a constant");
        }
        $$->is_error=1;
        delete $2;
    }
    | LeftHandSide '=' Expression       {
        vector<ASTNode*> s;
        s.push_back($1);
        s.push_back($3);
        $$ = makeNode("=", s);

        string t=assignExp($1->type,$3->type,"=");
        if(!$1->is_error && !$3->is_error && $1->expType!=4){
            if(!t.empty()){
                if(t=="ok"){
                    $$->type=$1->type;
                }
                // if($1->expType == 3 && $3->isInit){
				// 	updInit($1->temp_name);
				// }
            }
            else{
                fprintf(stdout,"Incompatible Types when comparing");
                $$->is_error=1;
            }
        }
        else if($1->expType==4){
                fprintf(stdout,"Right side cannot be a constant");
        }
        $$->is_error=1;
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

        //
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

        string t=assignExp($1->type,$3->type,*$2);
        if(!$1->is_error && !$3->is_error && $1->expType!=4){
            if(!t.empty()){
                if(t=="ok"){
                    $$->type=$1->type;
                }
                // if($1->expType == 3 && $3->isInit){
				// 	updInit($1->temp_name);
				// }
            }
            else{
                fprintf(stdout,"Incompatible Types when comparing");
                $$->is_error=1;
            }
        }
        else if($1->expType==4){
                fprintf(stdout,"Right side cannot be a constant");
        }
        $$->is_error=1;
        delete $2;
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

        string t=assignExp($1->type,$3->type,*$2);
        if(!$1->is_error && !$3->is_error && $1->expType!=4){
            if(!t.empty()){
                if(t=="ok"){
                    $$->type=$1->type;
                }
                // if($1->expType == 3 && $3->isInit){
				// 	updInit($1->temp_name);
				// }
            }
            else{
                fprintf(stdout,"Incompatible Types when comparing");
                $$->is_error=1;
            }
        }
        else if($1->expType==4){
                fprintf(stdout,"Right side cannot be a constant");
        }
        $$->is_error=1;
        delete $2;
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

        string t=assignExp($1->type,$3->type,"&");
        if(!$1->is_error && !$3->is_error && $1->expType!=4){
            if(!t.empty()){
                if(t=="ok"){
                    $$->type=$1->type;
                }
                // if($1->expType == 3 && $3->isInit){
				// 	updInit($1->temp_name);
				// }
            }
            else{
                fprintf(stdout,"Incompatible Types when comparing");
                $$->is_error=1;
            }
        }
        else if($1->expType==4){
                fprintf(stdout,"Right side cannot be a constant");
        }
        $$->is_error=1;
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


    string t=assignExp($1->type,$3->type,"^");
        if(!$1->is_error && !$3->is_error && $1->expType!=4){
            if(!t.empty()){
                if(t=="ok"){
                    $$->type=$1->type;
                }
                // if($1->expType == 3 && $3->isInit){
				// 	updInit($1->temp_name);
				// }
            }
            else{
                fprintf(stdout,"Incompatible Types when comparing");
                $$->is_error=1;
            }
        }
        else if($1->expType==4){
                fprintf(stdout,"Right side cannot be a constant");
        }
        $$->is_error=1;
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

        string t=assignExp($1->type,$3->type,"|");
        if(!$1->is_error && !$3->is_error && $1->expType!=4){
            if(!t.empty()){
                if(t=="ok"){
                    $$->type=$1->type;
                }
                // if($1->expType == 3 && $3->isInit){
				// 	updInit($1->temp_name);
				// }
            }
            else{
                fprintf(stdout,"Incompatible Types when comparing");
                $$->is_error=1;
            }
        }
        else if($1->expType==4){
                fprintf(stdout,"Right side cannot be a constant");
        }
        $$->is_error=1;
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
        string t=assignExp($1->type,$3->type,*$2);
        if(!$1->is_error && !$3->is_error && $1->expType!=4){
            if(!t.empty()){
                if(t=="ok"){
                    $$->type=$1->type;
                }
                // if($1->expType == 3 && $3->isInit){
				// 	updInit($1->temp_name);
				// }
            }
            else{
                fprintf(stdout,"Incompatible Types when comparing");
                $$->is_error=1;
            }
        }
        else if($1->expType==4){
                fprintf(stdout,"Right side cannot be a constant");
        }
        $$->is_error=1;
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

        string t=assignExp($1->type,$3->type,*$2);
        if(!$1->is_error && !$3->is_error && $1->expType!=4){
            if(!t.empty()){
                if(t=="ok"){
                    $$->type=$1->type;
                }
                // if($1->expType == 3 && $3->isInit){
				// 	updInit($1->temp_name);
				// }
            }
            else{
                fprintf(stdout,"Incompatible Types when comparing");
                $$->is_error=1;
            }
        }
        else if($1->expType==4){
                fprintf(stdout,"Right side cannot be a constant");
        }
        $$->is_error=1;
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

        string t=assignExp($1->type,$3->type,*$2);
        if(!$1->is_error && !$3->is_error && $1->expType!=4){
            if(!t.empty()){
                if(t=="ok"){
                    $$->type=$1->type;
                }
                // if($1->expType == 3 && $3->isInit){
				// 	updInit($1->temp_name);
				// }
            }
            else{
                fprintf(stdout,"Incompatible Types when comparing");
                $$->is_error=1;
            }
        }
        else if($1->expType==4){
                fprintf(stdout,"Right side cannot be a constant");
        }
        $$->is_error=1;
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

        string t=assignExp($1->type,$3->type,*$2);
        if(!$1->is_error && !$3->is_error && $1->expType!=4){
            if(!t.empty()){
                if(t=="ok"){
                    $$->type=$1->type;
                }
                // if($1->expType == 3 && $3->isInit){
				// 	updInit($1->temp_name);
				// }
            }
            else{
                fprintf(stdout,"Incompatible Types when comparing");
                $$->is_error=1;
            }
        }
        else if($1->expType==4){
                fprintf(stdout,"Right side cannot be a constant");
        }
        $$->is_error=1;
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

        string t=assignExp($1->type,$3->type,*$2);
        if(!$1->is_error && !$3->is_error && $1->expType!=4){
            if(!t.empty()){
                if(t=="ok"){
                    $$->type=$1->type;
                }
                // if($1->expType == 3 && $3->isInit){
				// 	updInit($1->temp_name);
				// }
            }
            else{
                fprintf(stdout,"Incompatible Types when comparing");
                $$->is_error=1;
            }
        }
        else if($1->expType==4){
                fprintf(stdout,"Right side cannot be a constant");
        }
        $$->is_error=1;
        delete $2;
    }
    | MultiplicativeExpression '*' UnaryExpression       {
        vector<ASTNode*> s;
        s.push_back($1);
        s.push_back($3);
        $$ = makeNode("*", s);

        string t=assignExp($1->type,$3->type,"*");
        if(!$1->is_error && !$3->is_error && $1->expType!=4){
            if(!t.empty()){
                if(t=="ok"){
                    $$->type=$1->type;
                }
                // if($1->expType == 3 && $3->isInit){
				// 	updInit($1->temp_name);
				// }
            }
            else{
                fprintf(stdout,"Incompatible Types when comparing");
                $$->is_error=1;
            }
        }
        else if($1->expType==4){
                fprintf(stdout,"Right side cannot be a constant");
        }
        $$->is_error=1;
    }
;

UnaryExpression:
    ADDOP2 UnaryExpression      {
        vector<ASTNode*> s;
        s.push_back($2);
        $$ = makeNode(*$1, s);
        delete $1;

        string t=postfixExpression($2->type,6);
            if(!t.empty()){
                if(t=="ok"){
                    $$->type=t;
                }
                // if($1->expType == 3 && $3->isInit){
				// 	updInit($1->temp_name);
				// }
            }
            else{
                fprintf(stdout,"Incompatible Types when comparing");
                $$->is_error=1;
            }
    }
    | ADDOP UnaryExpression     {
        vector<ASTNode*> s;
        s.push_back($2);        
        $$ = makeNode(*$1, s);
        delete $1;

        string t=postfixExpression($2->type,6);
            if(!t.empty()){
                if(t=="ok"){
                    $$->type=t;
                }
                // if($1->expType == 3 && $3->isInit){
				// 	updInit($1->temp_name);
				// }
            }
            else{
                fprintf(stdout,"Incompatible Types when comparing");
                $$->is_error=1;
            }
    }
    | UnaryExpressionNotPlusMinus   {
        $$ = $1;
    }
    | CastExpression        {
        $$=$1;
    }
;

UnaryExpressionNotPlusMinus:
    postfixExpression   {
        $$ = $1;
    }
    | UNARYOP UnaryExpression   {
        vector<ASTNode*> s;
        s.push_back($2);        
        $$ = makeNode(*$1, s);

        if(!$2->is_error){
            string t = unaryExp(*$1,$2->type);
			if(!t.empty()){
				$$->type = t;
			}
			else{
				yyerror("Type inconsistent with operator");
				$$->is_error = 1;
			}
		}
		else{
			$$->is_error = 1;
		}
        delete $1;
    }
;

CastExpression:
    '(' PrimitiveType ')' UnaryExpression   {
        vector<ASTNode*> s;
        s.push_back($2);
        s.push_back($4);
        $$ = makeNode("CastExpression", s);

        if(type=="")type=$2->type;
        $$->type=type;
        //
    }
;

postfixExpression:
    Primary {
        $$ = $1;
    }
    | IDENdotIDEN       {
        $$ = $1;
    }
    | postfixExpression ADDOP2      {
        vector<ASTNode*> s;
        s.push_back($1);
        s.push_back(makeLeaf(*$2));
        $$ = makeNode("Postfix Expression", s);
        delete $2;

        //
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
        type="";
    }
    | Statement {
        $$=$1;
    }
;

LocalVariableDeclaration:
    KEY_final LocalVariableType VariableDeclaratorList {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("final"));
        s.push_back($2);
        s.push_back($3);
        $$ = makeNode("LocalVariableDeclaration", s);

        if(type=="")type=$2->type;
        $$->type=type;
        $3->type=type;
    }
    | LocalVariableType VariableDeclaratorList {
        vector<ASTNode*> s;
        s.push_back($1);
        s.push_back($2);
        $$ = makeNode("LocalVariableDeclaration", s);

        if(type=="")type=$1->type;
        $$->type=type;
        $2->type=type;
    }
;

LocalVariableType:
    Type {
        $$=$1;
    }
    | KEY_VAR {
        $$ = makeLeaf("var");

        if(type=="")type="var";
        $$->type=type;
        delete $1;
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
        type="";
    }
    | StatementExpression ';' {
        $$=$1;
        type="";
    }
    | AssertStatement {
        $$=$1;
    }
    | BreakContinueStatement {
        $$=$1;
    }
    | KEY_return ';' {
        $$ = makeLeaf("return");
        type="";
    }
    | KEY_return Expression ';' {
        vector<ASTNode*> s;
        s.push_back($2);
        $$ = makeNode("return", s);
        type="";
    }
    | KEY_yield Expression ';' {
        vector<ASTNode*> s;
        s.push_back($2);
        $$ = makeNode("yield", s);
        type="";
    }
    | KEY_throw Expression ';' {
        vector<ASTNode*> s;
        s.push_back($2);
        $$ = makeNode("throw", s);
        type="";
    }
    | KEY_sync '(' Expression ')' Block {
        vector<ASTNode*> s;
        s.push_back($3);
        s.push_back($5);
        $$ = makeNode("sync", s);
        type="";
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

        string t=postfixExpression($2->type,6);
            if(!t.empty()){
                if(t=="ok"){
                    $$->type=t;
                }
                // if($1->expType == 3 && $3->isInit){
				// 	updInit($1->temp_name);
				// }
            }
            else{
                fprintf(stdout,"Incompatible Types when comparing");
                $$->is_error=1;
            }
    }
    | postfixExpression ADDOP2 {
        vector<ASTNode*> s;
        s.push_back($1);
        s.push_back(makeLeaf(*$2));
        delete $2;
        $$ = makeNode("Statement Expression", s);

        string t=postfixExpression($1->type,6);
            if(!t.empty()){
                if(t=="ok"){
                    $$->type=t;
                }
                // if($1->expType == 3 && $3->isInit){
				// 	updInit($1->temp_name);
				// }
            }
            else{
                fprintf(stdout,"Incompatible Types when comparing");
                $$->is_error=1;
            }
    }
    /* | ClassInstanceCreationExpression */
;

LeftHandSide:
    IDENdotIDEN {
        $$=$1;
        if(type=="")type="IdendotIden String Name";
        $$->type=type;
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

        if($2->type!="boolean"){
            $$->is_error=1;
        }
        type="";

    }
    | KEY_assert Expression ':' Expression ';' {
        vector<ASTNode*> s;
        s.push_back($2);
        s.push_back(makeLeaf(":"));
        s.push_back($4);
        $$ = makeNode("assert", s);

        if($2->type!="boolean" && $4->type!="void")
        type="";
    }
;

BreakContinueStatement:
    KEY_break IDENTIFIER ';' {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("ID (" + *$2+")" ));
        delete $2;
        $$ = makeNode("break", s);
        type="";
    }
    | KEY_break ';' {
        $$ = makeLeaf("break");
        type="";
    }
    | KEY_continue IDENTIFIER ';' {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("ID (" + *$2+")" ));
        delete $2;
        $$ = makeNode("continue", s);
        type="";
    }
    | KEY_continue ';' {
        $$ = makeLeaf("continue");
        type="";
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
        type="";
    }
    | LocalVariableDeclaration {
        $$ = $1;
        type="";
    }
    |   {
        $$=NULL;
        type="";
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
        s.push_back($4);
        $$ = makeNode("class", s);

        delete $3;
    }
    | Modifiers KEY_class IDENTIFIER ClassExtends ClassBody {
        vector<ASTNode*> s;
        s.push_back($1);
        s.push_back(makeLeaf("ID (" + *$3+")" ));
        s.push_back($4);
        s.push_back($5);
        $$ = makeNode("class", s);

        delete $3;
    }
    | Modifiers KEY_class IDENTIFIER ClassPermits ClassBody {
        vector<ASTNode*> s;
        s.push_back($1);
        s.push_back(makeLeaf("ID (" + *$3+")" ));
        s.push_back($4);
        s.push_back($5);
        $$ = makeNode("class", s);

        delete $3;
    }
    | Modifiers KEY_class IDENTIFIER ClassExtends ClassPermits ClassBody {
        vector<ASTNode*> s;
        s.push_back($1);
        s.push_back(makeLeaf("ID (" + *$3+")" ));
        s.push_back($4);
        s.push_back($5);
        s.push_back($6);
        $$ = makeNode("class", s);

        delete $3;
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
    }
    | ClassDeclaration {
        $$=$1;
    }
    | ';' {
        $$=NULL;
        type="";
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
        else if(class_type!="") $$->type=class_type;
        else{
            printf("Type is not defined at : %d\n",yylineno);
        }

        if(curLookup(*$1)){
				string errstr = *$1 + " is already declared";
				yyerror(errstr.c_str());
				$$->is_error = 1;            
        }
        else{
            insertSymbol(*cur_table,*$1, "IDENTIFIER", *$1, type, yylineno, NULL);
        }
        delete $1;
    }
    | IDENTIFIER '[' zerooroneExpression ']' {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("ID (" + *$1 +")" ));
        s.push_back($3);
        $$ = makeNode("VariableDeclarator1", s);
        $$->type=type;
        if($3->type!="INT"){
            fprintf(stdout,"Index of the array should be integer.");
        }
        //
        if(curLookup(*$1)){
				string errstr = *$1 + " is already declared";
				yyerror(errstr.c_str());
				$$->is_error = 1;            
        }
        else{
            isArray=1;
            if($3==NULL) array_dims.push_back(0);
            else array_dims.push_back($3->intVal);
            insertSymbol(*cur_table, *$1, "IDENTIFIER", *$1, type, yylineno, NULL);
        }
        delete $1;
    }
    | IDENTIFIER '[' zerooroneExpression ']' '[' zerooroneExpression ']' {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("ID (" + *$1 +")" ));
        s.push_back($3);
        s.push_back($6);
        $$ = makeNode("VariableDeclarator1", s);
        $$->type=type;

        if(curLookup(*$1)){
				string errstr = *$1 + " is already declared";
				yyerror(errstr.c_str());
				$$->is_error = 1;            
        }
        else{
            isArray=1;
            if($3==NULL) array_dims.push_back(0);
            else array_dims.push_back($3->intVal);
            if($6==NULL) array_dims.push_back(0);
            else array_dims.push_back($6->intVal);
            insertSymbol(*cur_table, *$1, "IDENTIFIER", *$1, type, yylineno, NULL);
        }
        delete $1;
    }
    | IDENTIFIER '[' zerooroneExpression ']' '[' zerooroneExpression ']' '[' zerooroneExpression ']' {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("ID (" + *$1+")" ));
        s.push_back($3);
        s.push_back($6);
        s.push_back($9);
        $$ = makeNode("VariableDeclarator1", s);
        $$->type=type;

        if(curLookup(*$1)){
				string errstr = *$1 + " is already declared";
				yyerror(errstr.c_str());
				$$->is_error = 1;            
        }
        else{
            isArray=1;
            if($3==NULL) array_dims.push_back(0);
            else array_dims.push_back($3->intVal);
            if($6==NULL) array_dims.push_back(0);
            else array_dims.push_back($6->intVal);
            if($9==NULL) array_dims.push_back(0);
            else array_dims.push_back($9->intVal);
            insertSymbol(*cur_table, *$1, "IDENTIFIER", *$1, type, yylineno, NULL);
        }
        delete $1;
    }
;

VariableDeclarator2:
    IDENTIFIER '=' Expression {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("ID (" + *$1+")" ));
        s.push_back($3);
        $$ = makeNode("=",s);

        if(type!=$3->type){
            fprintf(stdout,"Type Clashing at : %d\n",yylineno);
            $$->is_error=1;
        }
        
        if(curLookup(*$1)){
				string errstr = *$1 + " is already declared";
				yyerror(errstr.c_str());
				$$->is_error = 1;            
        }
        else{
            insertSymbol(*cur_table,*$1, "IDENTIFIER", *$1, type, yylineno, NULL);
        }
        delete $1;
    }
    | IDENTIFIER '[' zerooroneExpression ']' '=' List1 {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("ID (" + *$1+")" ));
        s.push_back($3);
        s.push_back($6);
        $$ = makeNode("=", s);
        //
        if($3!=NULL && $3->intVal>cnt1){
            fprintf(stdout,"Index out of bounds, not matching with intitalisers");
        }
        if(type!=$6->type){
            fprintf(stdout,"Type Clashing at : %d\n",yylineno);
            $$->is_error=1;
        }
        
        if(curLookup(*$1)){
				string errstr = *$1 + " is already declared";
				yyerror(errstr.c_str());
				$$->is_error = 1;            
        }
        else{
            isArray=1;
            if($3==NULL) array_dims.push_back(0);
            else array_dims.push_back($3->intVal);
            insertSymbol(*cur_table,*$1, "IDENTIFIER", *$1, type, yylineno, NULL);
        }
        cnt1=0;
        delete $1;
    }
    | IDENTIFIER '[' zerooroneExpression ']' '[' zerooroneExpression ']' '=' List2 {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("ID (" + *$1+")" ));
        s.push_back($3);
        s.push_back($6);
        s.push_back($9);
        $$ = makeNode("=", s);


        if($3!=NULL && $3->intVal>cnt1){
            fprintf(stdout,"Index out of bounds, not matching with intitalisers");
        }
        if($6!=NULL && $6->intVal>cnt2){
            fprintf(stdout,"Index out of bounds, not matching with intitalisers");
        }
        if(type!=$9->type){
            fprintf(stdout,"Type Clashing at : %d\n",yylineno);
            $$->is_error=1;
        }
        
        if(curLookup(*$1)){
				string errstr = *$1 + " is already declared";
				yyerror(errstr.c_str());
				$$->is_error = 1;            
        }
        else{
            isArray=1;
            if($3==NULL) array_dims.push_back(0);
            else array_dims.push_back($3->intVal);
            if($6==NULL) array_dims.push_back(0);
            else array_dims.push_back($6->intVal);
            insertSymbol(*cur_table,*$1, "IDENTIFIER", *$1, type, yylineno, NULL);
        }
        cnt1=0;
        cnt2=0;
        delete $1;
    }
    | IDENTIFIER '[' zerooroneExpression ']' '[' zerooroneExpression ']' '[' zerooroneExpression ']' '=' List3 {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("ID (" + *$1+")" ));
        s.push_back($3);
        s.push_back($6);
        s.push_back($9);
        s.push_back($12);
        $$ = makeNode("=", s);
        //
        if($3!=NULL && $3->intVal>cnt1){
            fprintf(stdout,"Index out of bounds, not matching with intitalisers");
        }
        if($6!=NULL && $6->intVal>cnt2){
            fprintf(stdout,"Index out of bounds, not matching with intitalisers");
        }
        if($9!=NULL && $9->intVal>cnt3){
            fprintf(stdout,"Index out of bounds, not matching with intitalisers");
        }

        if(type!=$12->type){
            fprintf(stdout,"Type Clashing at : %d\n",yylineno);
            $$->is_error=1;
        }
        
        if(curLookup(*$1)){
				string errstr = *$1 + " is already declared";
				yyerror(errstr.c_str());
				$$->is_error = 1;            
        }
        else{
            isArray=1;
            if($3==NULL) array_dims.push_back(0);
            else array_dims.push_back($3->intVal);
            if($6==NULL) array_dims.push_back(0);
            else array_dims.push_back($6->intVal);
            if($9==NULL) array_dims.push_back(0);
            else array_dims.push_back($9->intVal);
            insertSymbol(*cur_table,*$1, "IDENTIFIER", *$1, type, yylineno, NULL);
        }
        cnt1=0,cnt2=0,cnt3=0;
        delete $1;
    }
    | IDENTIFIER '[' zerooroneExpression ']' '=' KEY_new PrimitiveType '[' zerooroneExpression ']' List1 {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("ID (" + *$1+")" ));
        s.push_back($3);
        s.push_back(makeLeaf("new"));
        s.push_back($7);
        s.push_back($9);
        s.push_back($11);
        $$ = makeNode("=", s);
        //
        if($3!=NULL && $3->intVal>cnt1){
            fprintf(stdout,"Index out of bounds, not matching with intitalisers");
            $$->is_error=1;
        }
        if(type!=$7->type){
            fprintf(stdout,"Type Clashing at : %d\n",yylineno);
            $$->is_error=1;
        }
        
        if(curLookup(*$1)){
				string errstr = *$1 + " is already declared";
				yyerror(errstr.c_str());
				$$->is_error = 1;            
        }
        else{
            isArray=1;
            if($3==NULL) array_dims.push_back(0);
            else array_dims.push_back($3->intVal);
            insertSymbol(*cur_table,*$1, "IDENTIFIER", *$1, type, yylineno, NULL);
        }
        cnt1=0;
        delete $1;
    }
    | IDENTIFIER '[' zerooroneExpression ']' '[' zerooroneExpression ']' '=' KEY_new PrimitiveType '[' zerooroneExpression ']' '[' zerooroneExpression ']' List2 {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("ID (" + *$1+")" ));
        s.push_back($3);
        s.push_back($6);
        s.push_back(makeLeaf("new"));
        s.push_back($10);
        s.push_back($12);
        s.push_back($15);
        s.push_back($17);
        $$ = makeNode("=", s);
        //
        if($3!=NULL && $3->intVal>cnt1){
            fprintf(stdout,"Index out of bounds, not matching with intitalisers");
        }
        if($6!=NULL && $6->intVal>cnt2){
            fprintf(stdout,"Index out of bounds, not matching with intitalisers");
        }
        if(type!=$10->type){
            fprintf(stdout,"Type Clashing at : %d\n",yylineno);
            $$->is_error=1;
        }
        
        if(curLookup(*$1)){
				string errstr = *$1 + " is already declared";
				yyerror(errstr.c_str());
				$$->is_error = 1;            
        }
        else{
            isArray=1;
            if($3==NULL) array_dims.push_back(0);
            else array_dims.push_back($3->intVal);
            if($6==NULL) array_dims.push_back(0);
            else array_dims.push_back($6->intVal);
            insertSymbol(*cur_table,*$1, "IDENTIFIER", *$1, type, yylineno, NULL);
        }
        cnt1=0,cnt2=0;
        delete $1;
    }
    | IDENTIFIER '[' zerooroneExpression ']' '[' zerooroneExpression ']' '[' zerooroneExpression ']' '=' KEY_new PrimitiveType '[' zerooroneExpression ']' '[' zerooroneExpression ']' '[' zerooroneExpression ']' List3 {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("ID (" + *$1+")" ));
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
        //
        if($3!=NULL && $3->intVal>cnt1){
            fprintf(stdout,"Index out of bounds, not matching with intitalisers");
        }
        if($6!=NULL && $6->intVal>cnt2){
            fprintf(stdout,"Index out of bounds, not matching with intitalisers");
        }
        if($9!=NULL && $9->intVal>cnt3){
            fprintf(stdout,"Index out of bounds, not matching with intitalisers");
        }
        if(type!=$13->type){
            fprintf(stdout,"Type Clashing at : %d\n",yylineno);
            $$->is_error=1;
        }
        
        if(curLookup(*$1)){
				string errstr = *$1 + " is already declared";
				yyerror(errstr.c_str());
				$$->is_error = 1;            
        }
        else{
            isArray=1;
            if($3==NULL) array_dims.push_back(0);
            else array_dims.push_back($3->intVal);
            if($6==NULL) array_dims.push_back(0);
            else array_dims.push_back($6->intVal);
            if($9==NULL) array_dims.push_back(0);
            else array_dims.push_back($9->intVal);
            insertSymbol(*cur_table,*$1, "IDENTIFIER", *$1, type, yylineno, NULL);
        }
        cnt1=0,cnt2=0,cnt3=0;
        delete $1;
    }
    | IDENTIFIER '[' zerooroneExpression ']' '=' KEY_new PrimitiveType '[' zerooroneExpression ']' {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("ID (" + *$1+")" ));
        s.push_back($3);
        s.push_back(makeLeaf("new"));
        s.push_back($7);
        s.push_back($9);
        $$ = makeNode("=", s);
        // if($3->intVal>cnt){
            // fprintf(stdout,"Index out of bounds");
        // }
        if(type!=$7->type){
            fprintf(stdout,"Type Clashing at : %d\n",yylineno);
            $$->is_error=1;
        }
        
        if(curLookup(*$1)){
				string errstr = *$1 + " is already declared";
				yyerror(errstr.c_str());
				$$->is_error = 1;            
        }
        else{
            isArray=1;
            if($3==NULL) array_dims.push_back(0);
            else array_dims.push_back($3->intVal);
            insertSymbol(*cur_table,*$1, "IDENTIFIER", *$1, type, yylineno, NULL);
        }
        delete $1;
    }
    | IDENTIFIER '[' zerooroneExpression ']' '[' zerooroneExpression ']' '=' KEY_new PrimitiveType '[' zerooroneExpression ']' '[' zerooroneExpression ']' {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("ID (" + *$1+")" ));
        s.push_back($3);
        s.push_back($6);
        s.push_back(makeLeaf("new"));
        s.push_back($10);
        s.push_back($12);
        s.push_back($15);
        $$ = makeNode("=", s);
        //
        if($3!=NULL && $3->intVal>cnt1){
            fprintf(stdout,"Index out of bounds, not matching with intitalisers");
        }
        if($6!=NULL && $6->intVal>cnt2){
            fprintf(stdout,"Index out of bounds, not matching with intitalisers");
        }
        if(type!=$10->type){
            fprintf(stdout,"Type Clashing at : %d\n",yylineno);
            $$->is_error=1;
        }
        
        if(curLookup(*$1)){
				string errstr = *$1 + " is already declared";
				yyerror(errstr.c_str());
				$$->is_error = 1;            
        }
        else{
            isArray=1;
            if($3==NULL) array_dims.push_back(0);
            else array_dims.push_back($3->intVal);
            if($6==NULL) array_dims.push_back(0);
            else array_dims.push_back($6->intVal);
            insertSymbol(*cur_table,*$1, "IDENTIFIER", *$1, type, yylineno, NULL);
        }
        delete $1;
    }
    | IDENTIFIER '[' zerooroneExpression ']' '[' zerooroneExpression ']' '[' zerooroneExpression ']' '=' KEY_new PrimitiveType '[' zerooroneExpression ']' '[' zerooroneExpression ']' '[' zerooroneExpression ']' {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("ID (" + *$1+")" ));
        s.push_back($3);
        s.push_back($6);
        s.push_back($9);
        s.push_back(makeLeaf("new"));
        s.push_back($13);
        s.push_back($15);
        s.push_back($18);
        s.push_back($21);
        $$ = makeNode("=", s);
        //
        // if($3->intVal>cnt){
            // fprintf(stdout,"Index out of bounds");
        // }
        // if($6->intVal>cnt){
            // fprintf(stdout,"Index out of bounds");
        // }
        // if($9->intVal>cnt){
            // fprintf(stdout,"Index out of bounds");
        // }
        if(type!=$13->type){
            fprintf(stdout,"Type Clashing at : %d\n",yylineno);
            $$->is_error=1;
        }
        
        if(curLookup(*$1)){
				string errstr = *$1 + " is already declared";
				yyerror(errstr.c_str());
				$$->is_error = 1;            
        }
        else{
            isArray=1;
            if($3==NULL) array_dims.push_back(0);
            else array_dims.push_back($3->intVal);
            if($6==NULL) array_dims.push_back(0);
            else array_dims.push_back($6->intVal);
            if($9==NULL) array_dims.push_back(0);
            else array_dims.push_back($9->intVal);
            insertSymbol(*cur_table,*$1, "IDENTIFIER", *$1, type, yylineno, NULL);
        }
        delete $1;
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

        cnt1++;
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
        cnt2++;
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
        cnt3++;
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
        type="";
        class_type="";

        // string temp = postfixExpression($1->type,3);
		// if(temp.empty()){
		// 	temp = getFuncType($1->temp_name);
		// }

		// if(!($1->is_error || $3->is_error) && $1->expType!=4){
		// 	if(!temp.empty()){	
		// 		$$->type = temp;
		// 		if($1->expType ==3){
		// 			vector<string> funcArgs = getFuncArgs($1->temp_name);
		// 			vector<string> tempArgs =curArgs.back();
		// 			for(int i=0;i<funcArgs.size();i++){
		// 				if(funcArgs[i]=="...")break;
		// 				if(tempArgs.size()==i){
		// 					yyerror(("Too few Arguments to Function " + $1->temp_name).c_str());
		// 					break;
		// 				}
		// 				string msg = checkType(funcArgs[i],tempArgs[i]);

		// 				if(msg =="warning"){
		// 					warning(("Incompatible conversion of " +  tempArgs[i] + " to parameter of type " + funcArgs[i]).c_str());
		// 				}
		// 				else if(msg.empty()){
		// 					yyerror(("Incompatible Argument to the function " + $1->temp_name).c_str());
		// 					$$->is_error = 1;
		// 					break;
		// 				}
		// 				if(i==funcArgs.size()-1 && i<tempArgs.size()-1){
		// 					yyerror(("Too many Arguments to Function " + $1->temp_name).c_str());
		// 					$$->is_error = 1;
		// 					break;
		// 				}

		// 			}	

		// 			//--3AC
		// 			// if(!$$->is_error){
		// 			// 	qid q = newtemp($$->type);
		// 			// 	$$->place = q;
		// 			// 	$$->nextlist.clear();

		// 			// 	emit(qid("CALL", NULL), qid($1->temp_name,NULL), qid(to_string(curArgs.back().size()), NULL), q, -1);
		// 			// 	curArgs.pop_back();

		// 			// 	if(func_usage_map.find($1->temp_name) != func_usage_map.end()){
		// 			// 		func_usage_map[$1->temp_name] = 1;
		// 			// 	}
		// 			// }

		// 		}
		// 	}
		// 	else{
		// 		yyerror("Invalid function call");
		// 		$$->is_error=1;
		// 	}
		// }
		// else{
		// 	if($1->expType==4){
		// 		yyerror("constant expression cannot be used as lvalue");
		// 	}
		// 	$$->is_error=1;
		// }
    }
    | IDENTIFIER '(' ')' {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("ID (" + *$1+")" ));
        delete $1;
        $$ = makeNode("IdenPara", s);
        type="";
        class_type="";

        // if(!$1->is_error){
		// 	if($1->expType == 1) {
		// 		$$->temp_name = $1->temp_name;
		// 		$$->expType = 3;
		// 		$$->type = $1->type;
		// 		$$->size = getSize($$->type);

		// 		vector<string> temp = getFuncArgs($1->temp_name);
		// 		if((temp.size() == 1 && temp[0] == "#NO_FUNC") || funcArgs == temp){
		// 			insertFuncArg($$->temp_name, funcArgs, $$->type);
		// 			funcArgs.clear();
		// 			funcName = string($1->temp_name);
		// 			funcType = $1->type;
		// 		}
		// 		else {
		// 			yyerror(("Conflicting types for function " + $1->temp_name).c_str());
		// 			$$->is_error = 1;
		// 		}
		// 		//3AC
		// 		// $$->place = qid($$->temp_name, NULL);
		// 		// emit(pair<string,sym_entry*>("FUNC_" + $$->temp_name + " start :",NULL),pair<string,sym_entry*>("",NULL),pair<string,sym_entry*>("",NULL),pair<string,sym_entry*>("",NULL),-2);
		// 	}
		// 	else {
		// 		if($1->expType == 2){
		// 			yyerror( ($1->temp_name + "declared as array of function").c_str());
		// 		}
		// 		else{
		// 			yyerror( ($1->temp_name + "declared as function of function").c_str());
		// 		}
		// 		$$->is_error = 1;
		// 	}
		// }
		// else $$->is_error = 1;
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
        type="";
        class_type="";
    }
;

formalparameter:
    Type VariableDeclarator1 {
        vector<ASTNode*> s;
        s.push_back($1);
        s.push_back($2);
        $$ = makeNode("formalparameter", s);

        if(type=="")type=$1->type;
        $$->type=type;
    }
    | KEY_final Type VariableDeclarator1 {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("final"));
        s.push_back($2);
        s.push_back($3);
        $$ = makeNode("formalparameter", s);

        if(type=="")type=$2->type;
        $$->type=type;
    }
    | Type DOT3 IDENTIFIER {
        vector<ASTNode*> s;
        s.push_back($1);
        s.push_back(makeLeaf(*$2));
        delete $2;
        s.push_back(makeLeaf("ID (" + *$3+")" ));
        delete $3;
        $$ = makeNode("formalparameter", s);

        $$->type=type;
    }
    | KEY_final Type DOT3 IDENTIFIER {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("final"));
        s.push_back($2);
        s.push_back(makeLeaf(*$3));
        delete $3;
        s.push_back(makeLeaf("ID (" + *$4+")" ));
        delete $4;
        $$ = makeNode("formalparameter", s);

        $$->type=type;
    }
;

MethodBody:
    Block {
        $$=$1;
    }
    | ';' {
        $$=NULL;
        type="";
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

    symbolTableInit();

    beginAST();
    if(yyparse()) return 0;
    endAST();
    printSymbolTable(cur_table, "Global.csv");
    
    if(verbosemode){
        printf("Parser work completed..\n");
        printf("Dot script has generated successfully");
        printf("....\n");
    }
}