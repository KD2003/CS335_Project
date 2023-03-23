%{
#include <stdio.h>
#include <iostream>
#include"AST.h"
#include"typecheck.h"
#include <fstream>

FILE* dotfile;
extern FILE* yyin;
extern int yyrestart(FILE*);
extern int yylineno;

bool gotinputfile, gotoutputfile, verbosemode;

int dump_sym_table=0;
int isArray=0;
int cnt1=0,cnt2=0,cnt3=0;
int block_count = 0;

string type="";
string class_type="";
string idendotiden ="";
string funcName="", funcType ="";

vector<int> array_dims;
vector<int> modifier ={1,0,0};
vector<string> funcArgs;
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

%type<ptr> Start ImportList ClassDeclarationList Imports Type PrimitiveType IDENdotIDEN PublicPrivateStatic ClassType ArrayType Dims Literal F MethodIDEN
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
        idendotiden = idendotiden + "." +*$3;
        $$->temp_name = idendotiden;
        delete $3;
        $$ = makeNode(".", s);
    }
    | IDENTIFIER    {
        $$ = makeLeaf("ID (" + *$1 + ")");
        class_type=*$1;
        idendotiden = *$1;
        $$->temp_name = idendotiden;
        delete $1;
    }
;

PublicPrivateStatic:
    KEY_public      {
        $$ = makeLeaf("public");
        modifier[0]=2;
    }
    | KEY_private       {
        $$ = makeLeaf("private");
        modifier[0]=1;
    }
    | KEY_static        {
        $$ = makeLeaf("static");
        modifier[1]=1;
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

        if(idendotiden != "String"){
            yyerror("Array of this type is not supported");
        }
        else{
            $$->type = "String";
            isArray =1;
            type = "String";
            $$->expType = 2;
        }
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
        if($3->type!="int"){
            yyerror("Index of the array should be integer");
        }
    }
;

MethodInvocation:
    IDENdotIDEN '(' Zeroorone_ArgumentList ')'          {
        vector<ASTNode*> s;
        s.push_back($1);
        s.push_back($3);
        $$ = makeNode("MethodInvocation", s);

        string t = postfixExpression(idendotiden,2);
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

        //3ac
        emit(qid("param",NULL),$3->addr,qid("",NULL),qid("",NULL));
    }
    | Expression        {
        $$ = $1;

        //3ac
        emit(qid("param",NULL),$1->addr,qid("",NULL),qid("",NULL));

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
            yyerror("Index of the array should be integer");
        }
    }
    | '[' Expression ']'        {
        vector<ASTNode*> s;
        s.push_back($2);
        $$ = makeNode("DimExpr", s);

        if($2->type!="INT"){
            yyerror("Index of the array should be integer");
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
                    $$->type=t;
                // if($1->expType == 3 && $3->isInit){
				// 	updInit($1->temp_name);
				// }

                //3ac
                if(*$2=="="){
                    $$->addr=$1->addr;
                    emit(qid("=",NULL),$3->addr,qid("",NULL),$1->addr); 
                }
                else if(*$2=="*="){
                    qid temp=newtemp($1->type,curr_table);
                    emit(qid("*",NULL),$1->addr,$3->addr,temp);
                    $$->addr=temp;
                }
                else if(*$2=="/="){
                    qid temp=newtemp($1->type,curr_table);
                    emit(qid("/",NULL),$1->addr,$3->addr,temp);
                    $$->addr=temp;
                }
                else if(*$2=="%="){
                    qid temp=newtemp($1->type,curr_table);
                    emit(qid("%",NULL),$1->addr,$3->addr,temp);
                    $$->addr=temp;
                }
                else if(*$2=="+="){
                    qid temp=newtemp($1->type,curr_table);
                    emit(qid("+",NULL),$1->addr,$3->addr,temp);
                    $$->addr=temp;
                }
                else if(*$2=="-="){
                    qid temp=newtemp($1->type,curr_table);
                    emit(qid("-",NULL),$1->addr,$3->addr,temp);
                    $$->addr=temp;
                }
                else if(*$2=="<<="){
                    qid temp=newtemp($1->type,curr_table);
                    emit(qid("<<",NULL),$1->addr,$3->addr,temp);
                    $$->addr=temp;
                }
                else if(*$2==">>="){
                    qid temp=newtemp($1->type,curr_table);
                    emit(qid(">>",NULL),$1->addr,$3->addr,temp);
                    $$->addr=temp;
                }
                else if(*$2==">>>="){
                    qid temp=newtemp($1->type,curr_table);
                    emit(qid(">>>",NULL),$1->addr,$3->addr,temp);
                    $$->addr=temp;
                }
                else if(*$2=="&="){
                    qid temp=newtemp($1->type,curr_table);
                    emit(qid("&",NULL),$1->addr,$3->addr,temp);
                    $$->addr=temp;
                }
                else if(*$2=="\^="){
                    qid temp=newtemp($1->type,curr_table);
                    emit(qid("^",NULL),$1->addr,$3->addr,temp);
                    $$->addr=temp;
                }
                else if(*$2=="\|="){
                    qid temp=newtemp($1->type,curr_table);
                    emit(qid("|",NULL),$1->addr,$3->addr,temp);
                    $$->addr=temp;
                }

            }
            else{
                yyerror("Incompatible Types when comparing");
                $$->is_error=1;
            }
        }
        else if($1->expType==4){
                fprintf(stdout,"Left side cannot be a constant");
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
                    $$->type=t;
                // if($1->expType == 3 && $3->isInit){
				// 	updInit($1->temp_name);
				// }

                //3ac
                $$->addr=$1->addr;
                emit(qid("=",NULL),$3->addr,qid("",NULL),$1->addr);
            }
            else{
                yyerror("Incompatible Types when comparing");
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

        //  left for later
    }
;

ConditionalOrExpression:
    ConditionalAndExpression        {
        $$ = $1;
    }
    | ConditionalOrExpression CONDOR MarkerNT ConditionalAndExpression       {
        // MarkerNT added of type int
        vector<ASTNode*> s;
        s.push_back($1);
        s.push_back($3);
        $$ = makeNode("||", s);
        string temp=condExp($1->type,$3->type,"",*$2);
        if(!$1->is_error && !$3->is_error){
            if(!temp.empty()){
                $$->type=temp;

                //3ac
                backpatch($1->falselist,$3);
                $$->truelist=mergelist($1->truelist,$4->truelist);
                $$->falselist=$4->falselist;

            }
            else{
                yyerror("Incompatible Types for ||");
                $$->is_error=1;
            }
        }
        else{
            $$->is_error=1;
        }
        delete $2;
    }
;

MarkerNT:
      {$$=code.size()-1;} //check if -1 or not
;

ConditionalAndExpression:
    InclusiveOrExpression   {
        $$ = $1;
    }
    | ConditionalAndExpression CONDAND MarkerNT InclusiveOrExpression        {
        // MArkerNT of type int added
        vector<ASTNode*> s;
        s.push_back($1);
        s.push_back($3);
        $$ = makeNode("&&", s);

        string temp=condExp($1->type,$3->type,"",*$2);
        if(!$1->is_error && !$3->is_error){
            if(!temp.empty()){
                $$->type=temp;

                //3ac
                backpatch($1->truelist,$3);
                $$->falselist=mergelist($1->falselist,$4->falselist);
                $$->truelist=$4->truelist;
            }
            else{
                yyerror("Incompatible Types for &&");
                $$->is_error=1;
            }
        }
        else{
            $$->is_error=1;
        }
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

        string temp=bitExp($1->type,$3->type);
        if(!$1->is_error && !$3->is_error){
            if(!temp.empty()){
                $$->type=temp;

                //3ac
                if($1->type=="boolean" && $3->type="boolean"){
                    backpatch($1->truelist,$3);
                    $$->falselist=mergelist($1->falselist,$4->falselist);
                    $$->truelist=$4->truelist;
                }
            }
            else{
                yyerror("Incompatible Types for &");
                $$->is_error=1;
            }
        }
        else{
            $$->is_error=1;
        }
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

        string temp=bitExp($1->type,$3->type);
        if(!$1->is_error && !$3->is_error){
            if(!temp.empty()){
                $$->type=temp;
            }
            else{
                yyerror("Incompatible Types for ^");
                $$->is_error=1;
            }
        }
        else{
            $$->is_error=1;
        }
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

        string temp=bitExp($1->type,$3->type);
        if(!$1->is_error && !$3->is_error){
            if(!temp.empty()){
                $$->type=temp;

                //3ac
                if($1->type=="boolean" && $3->type="boolean"){
                backpatch($1->falselist,$3);
                $$->truelist=mergelist($1->truelist,$4->truelist);
                $$->falselist=$4->falselist;
                }
            }
            else{
                yyerror("Incompatible Types for |");
                $$->is_error=1;
            }
        }
        else{
            $$->is_error=1;
        }
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
        string temp=eqExp($1->type,$3->type);
        if(!$1->is_error && !$3->is_error){
            if(!temp.empty()){
                $$->type=temp;

                //3ac
                qid tmp=newtemp(temp,curr_table);
                emit(qid(*$2,NULL),$1->addr,$3->addr,tmp,-1);
                $$->addr=tmp;
                $$->truelist.push_back(code.size()); // check if -1 or not
                $$->falselist.push_back(code.size()-1);
                emit(qid("if",NULL),tmp,qid("",NULL),qid("goto",NULL),0);
                emit(qid("goto",NULL),qid("",NULL),qid("",NULL),qid("",NULL),0);
            }
            else{
                yyerror(("Incompatible Types for "+*$2).c_str());
                $$->is_error=1;
            }
        }
        else{
            $$->is_error=1;
        }
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

        string temp=relExp($1->type,$3->type);
        if(!$1->is_error && !$3->is_error){
            if(!temp.empty()){
                $$->type=temp;

                //3ac
                qid tmp=newtemp(temp,curr_table);
                emit(qid(*$2,NULL),$1->addr,$3->addr,tmp,-1);
                $$->addr=tmp;
                $$->truelist.push_back(code.size()); // check if -1 or not
                $$->falselist.push_back(code.size()-1);
                emit(qid("if",NULL),tmp,qid("",NULL),qid("goto",NULL),0);
                emit(qid("goto",NULL),qid("",NULL),qid("",NULL),qid("",NULL),0);

            }
            else{
                yyerror(("Incompatible Types for "+*$2).c_str());
                $$->is_error=1;
            }
        }
        else{
            $$->is_error=1;
        }
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

        string temp=shiftExp($1->type,$3->type);
        if(!$1->is_error && !$3->is_error){
            if(!temp.empty()){
                $$->type=temp;

                //3ac
                qid tmp=newtemp(temp,curr_table);
                $$->addr=tmp;
                emit(qid(*$2,NULL),$1->addr,$3->addr,tmp);
            }
            else{
                yyerror(("Incompatible Types for "+*$2).c_str());
                $$->is_error=1;
            }
        }
        else{
            $$->is_error=1;
        }
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

        string temp=addExp($1->type,$3->type);
        if(!$1->is_error && !$3->is_error){
            if(!temp.empty()){
                $$->type=temp;

                //3ac
                qid tmp=newtemp(temp,curr_table);
                $$->addr=tmp;
                emit(qid(*$2,NULL),$1->addr,$3->addr,tmp);
            }
            else{
                yyerror(("Incompatible Types for "+*$2).c_str());
                $$->is_error=1;
            }
        }
        else{
            $$->is_error=1;
        }
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

        string temp=mulExp($1->type,$3->type);
        if(!$1->is_error && !$3->is_error){
            if(!temp.empty()){
                $$->type=temp;

                //3ac
                qid tmp=newtemp(temp,curr_table);
                $$->addr=tmp;
                emit(qid(*$2,NULL),$1->addr,$3->addr,tmp);
            }
            else{
                yyerror(("Incompatible Types for "+*$2).c_str());
                $$->is_error=1;
            }
        }
        else{
            $$->is_error=1;
        }
        delete $2;
    }
    | MultiplicativeExpression '*' UnaryExpression       {
        vector<ASTNode*> s;
        s.push_back($1);
        s.push_back($3);
        $$ = makeNode("*", s);

        string temp=mulExp($1->type,$3->type);
        if(!$1->is_error && !$3->is_error){
            if(!temp.empty()){
                $$->type=temp;

                //3ac
                qid tmp=newtemp(temp,curr_table);
                $$->addr=tmp;
                emit(qid(*$2,NULL),$1->addr,$3->addr,tmp);
            }
            else{
                yyerror("Incompatible Types for *");
                $$->is_error=1;
            }
        }
        else{
            $$->is_error=1;
        }
    }
;

UnaryExpression:
    ADDOP2 UnaryExpression      {
        vector<ASTNode*> s;
        s.push_back($2);
        $$ = makeNode(*$1, s);
        if(!$2->is_error && $2->expType!=4){
			string temp = postfixExpression($2->type,2);
			if(!temp.empty()){
				$$->type = temp;
                if(*$1 == "++"){
                    $$->intVal = $2->intVal + 1;

                    //3ac
                    qid tmp=newtemp(temp,curr_table);
                    $$->addr=tmp;
                    emit(qid("+",NULL),$2->addr,qid("1",NULL),tmp);
                }
                else{
                    $$->intVal = $2->intVal -1;
                    
                    //3ac
                    qid tmp=newtemp(temp,curr_table);
                    $$->addr=tmp;
                    emit(qid("-",NULL),$2->addr,qid("1",NULL),tmp);
                }
				

			}
			else{
				yyerror("Increment not defined for this type");
				$$->is_error = 1;
			}
		}
		else{
			if($2->expType==4){
				yyerror("Cannot increment a constant");
			}
			$$->is_error = 1;
		}
        delete $1;
    }
    | ADDOP UnaryExpression     {
        vector<ASTNode*> s;
        s.push_back($2);        
        $$ = makeNode(*$1, s);
        if(!$2->is_error){
			string temp = unaryExp($2->type,*$1);
			if(!temp.empty()){
				$$->type = temp;
                if(*$2=="-"){ 
                    $$->intval = - $2->intVal;

                    //3ac
                    qid tmp=newtemp(temp,curr_table);
                    $$->addr=tmp;
                    emit(qid(-,NULL),$2->addr,qid("",NULL),tmp);

                }
                else{ 
                    $$->intVal = $2->intVal;

                    $$->addr=$2->addr;
                }
			}
			else{
				yyerror("Unary operator not defined for this type");
				$$->is_error = 1;
			}
		}
		else{
			$$->is_error = 1;
		}
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
    postfixExpression   {
        $$ = $1;
    }
    | UNARYOP UnaryExpression   {
        vector<ASTNode*> s;
        s.push_back($2);        
        $$ = makeNode(*$1, s);

        if(!$2->is_error){
			string temp = unaryExp($2->type,*$1);
			if(!temp.empty()){
				$$->type = temp;
                // if(*$2=="-") $$->intval = - $2->intVal
                // else $$->intVal = $2->intVal;
				
                //3ac
                qid tmp=newtemp(temp,curr_table);
                $$->addr=tmp;
                emit(qid(*$1,NULL),$2->addr,qid("",NULL),tmp);

			}
			else{
				yyerror("Unary operator not defined for this type");
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
        if(!($2->is_error || $4->is_error)){
			//Semantic
			$$->type = $2->type;
			// //--3AC
			// // qid q = newtemp($$->type);
			// $$->place = $4->place;
			// $$->place.second->type = $2->type;
			// $4->nextlist.clear();

            //3ac
            $$->addr=$4->addr;
		}
		else{
			$$->is_error = 1;
		}
    }
;

postfixExpression:
    Primary {
        $$ = $1;
    }
    | IDENdotIDEN      {
        $$ = $1;
        if(idendotiden.find('.') != string::npos){
            string temp = primaryExpression(idendotiden);
            if(temp == ""){
                yyerror(("Undeclared Identifier " + idendotiden).c_str());
                $$->is_error = 1;
            }
            else{
                if(temp.substr(0, 5) == "FUNC_"){
                    $$->expType = 3;
                }
                else if(temp.back() == '*'){
                    $$->expType = 2; 
                }
                else $$->expType = 1;

                if(temp.substr(0,5)=="FUNC_" && temp.back() == '#'){
                    temp.pop_back();
                    $$->type = temp;
                    $$->temp_name = idendotiden; 
                    // $$->nextlist.clear();
                }
                else{
                    $$->type = temp;
                    $$->temp_name = idendotiden;
                    if(temp.back()=='*') $$->type = temp.substr(0,temp.size()-1);
                    //--3AC
                    // $$->place = qid(string($1), lookup(string($1)));
                    // $$->nextlist.clear();

                }
            }
        }
        else{
            // check in class
        }
    }
    | postfixExpression ADDOP2      {
        vector<ASTNode*> s;
        s.push_back($1);
        s.push_back(makeLeaf(*$2));
        $$ = makeNode("Postfix Expression", s);
        if(!$1->is_error && $1->expType!=4){
			string temp = postfixExpression($1->type,2);
			if(!temp.empty()){
				$$->type = temp;
                if(*$1 == "++"){
                    $$->intVal = $1->intVal + 1;

                    //3ac
                    qid tmp=newtemp(temp,curr_table);
                    $$->addr=tmp;
                    emit(qid("+",NULL),$1->addr,qid("1",NULL),tmp);
                }
                else{
                    $$->intVal = $1->intVal -1;
                    
                    //3ac
                    qid tmp=newtemp(temp,curr_table);
                    $$->addr=tmp;
                    emit(qid("-",NULL),$1->addr,qid("1",NULL),tmp);
                }


			}
			else{
				yyerror("Increment not defined for this type");
				$$->is_error = 1;
			}
		}
		else{
			if($1->expType==4){
				yyerror("Cannot increment a constant");
			}
			$$->is_error = 1;
		}
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
        if(!$2->is_error && $2->expType!=4){
			string temp = postfixExpression($2->type,2);
			if(!temp.empty()){
				$$->type = temp;
                if(*$1 == "++") $$->intVal = $2->intVal + 1;
                else $$->intVal = $2->intVal -1;
				//--3AC
				// qid q = newtemp(temp);
				// $$->place = q;
				// $$->nextlist.clear();
				// emit(qid("++S", NULL), $2->place, qid("", NULL), q, -1);
			}
			else{
				yyerror("Increment not defined for this type");
				$$->is_error = 1;
			}
		}
		else{
			if($2->expType==4){
				yyerror("Cannot increment a constant");
			}
			$$->is_error = 1;
		}
        delete $1;
    }
    | postfixExpression ADDOP2 {
        vector<ASTNode*> s;
        s.push_back($1);
        s.push_back(makeLeaf(*$2));
        $$ = makeNode("Statement Expression", s);

        if(!$1->is_error && $1->expType!=4){
			string temp = postfixExpression($1->type,2);
			if(!temp.empty()){
				$$->type = temp;
                if(*$2 == "++") $$->intVal = $1->intVal + 1;
                else $$->intVal = $1->intVal -1;
				//--3AC
				// qid q = newtemp(temp);
				// $$->place = q;
				// $$->nextlist.clear();
				// emit(qid("++S", NULL), $1->place, qid("", NULL), q, -1);
			}
			else{
				yyerror("Increment not defined for this type");
				$$->is_error = 1;
			}
		}
		else{
			if($1->expType==4){
				yyerror("Cannot increment a constant");
			}
			$$->is_error = 1;
		}
        delete $2;
    }
    /* | ClassInstanceCreationExpression */
;

LeftHandSide:
    IDENdotIDEN {
        $$=$1;
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
        $$->temp_name = *$1;
        if(type!="") $$->type = type;
        else if(class_type!="") $$->type=class_type;
        else{
            printf("Type is not defined at : %d\n",yylineno);
        }

        if(curLookup(*$1)){
				string errstr = *$1 + " is already declared\n";
				yyerror(errstr.c_str());
				$$->is_error = 1;            
        }
        else{
            insertSymbol(*cur_table,*$1, "IDENTIFIER", *$1, type, yylineno, NULL, modifier);
        }
        delete $1;
    }
    | IDENTIFIER '[' zerooroneExpression ']' {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("ID (" + *$1 +")" ));
        s.push_back($3);
        $$ = makeNode("VariableDeclarator1", s);
        $$->type=type;
        $$->temp_name = *$1;
        if($3->type!="int"){
            yyerror("Index of the array should be integer");
        }
        //
        if(curLookup(*$1)){
				string errstr = *$1 + " is already declared\n";
				yyerror(errstr.c_str());
				$$->is_error = 1;            
        }
        else{
            isArray=1;
            $$->expType = 2;
            if($3==NULL) array_dims.push_back(0);
            else array_dims.push_back($3->intVal);
            insertSymbol(*cur_table, *$1, "IDENTIFIER", *$1, type, yylineno, NULL, modifier);
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
        $$->temp_name = *$1;

        if(curLookup(*$1)){
				string errstr = *$1 + " is already declared\n";
				yyerror(errstr.c_str());
				$$->is_error = 1;            
        }
        else{
            isArray=1;
            $$->expType = 2;
            if($3==NULL) array_dims.push_back(0);
            else array_dims.push_back($3->intVal);
            if($6==NULL) array_dims.push_back(0);
            else array_dims.push_back($6->intVal);
            insertSymbol(*cur_table, *$1, "IDENTIFIER", *$1, type, yylineno, NULL, modifier);
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
        $$->temp_name = *$1;

        if(curLookup(*$1)){
				string errstr = *$1 + " is already declared\n";
				yyerror(errstr.c_str());
				$$->is_error = 1;            
        }
        else{
            isArray=1;
            $$->expType =2;
            if($3==NULL) array_dims.push_back(0);
            else array_dims.push_back($3->intVal);
            if($6==NULL) array_dims.push_back(0);
            else array_dims.push_back($6->intVal);
            if($9==NULL) array_dims.push_back(0);
            else array_dims.push_back($9->intVal);
            insertSymbol(*cur_table, *$1, "IDENTIFIER", *$1, type, yylineno, NULL, modifier);
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
        cout<<type<<" "<<$3->type<<endl;
        if(type!=$3->type){
            yyerror("Type Clashing");
            $$->is_error=1;
        }
        
        if(curLookup(*$1)){
				string errstr = *$1 + " is already declared\n";
				yyerror(errstr.c_str());
				$$->is_error = 1;            
        }
        else{
            insertSymbol(*cur_table,*$1, "IDENTIFIER", *$1, type, yylineno, NULL, modifier);
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
            yyerror("Index out of bounds, not matching with intitalisers");
        }
        if(type!=$6->type){
            yyerror("Type Clashing");
            $$->is_error=1;
        }
        
        if(curLookup(*$1)){
				string errstr = *$1 + " is already declared\n";
				yyerror(errstr.c_str());
				$$->is_error = 1;            
        }
        else{
            isArray=1;
            if($3==NULL) array_dims.push_back(0);
            else array_dims.push_back($3->intVal);
            insertSymbol(*cur_table,*$1, "IDENTIFIER", *$1, type, yylineno, NULL, modifier);
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
            yyerror("Index out of bounds, not matching with intitalisers");
        }
        if($6!=NULL && $6->intVal>cnt2){
            yyerror("Index out of bounds, not matching with intitalisers");
        }
        if(type!=$9->type){
            yyerror("Type Clashing");
            $$->is_error=1;
        }
        
        if(curLookup(*$1)){
				string errstr = *$1 + " is already declared\n";
				yyerror(errstr.c_str());
				$$->is_error = 1;            
        }
        else{
            isArray=1;
            if($3==NULL) array_dims.push_back(0);
            else array_dims.push_back($3->intVal);
            if($6==NULL) array_dims.push_back(0);
            else array_dims.push_back($6->intVal);
            insertSymbol(*cur_table,*$1, "IDENTIFIER", *$1, type, yylineno, NULL, modifier);
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
            yyerror("Index out of bounds, not matching with intitalisers");
        }
        if($6!=NULL && $6->intVal>cnt2){
            yyerror("Index out of bounds, not matching with intitalisers");
        }
        if($9!=NULL && $9->intVal>cnt3){
            yyerror("Index out of bounds, not matching with intitalisers");
        }

        if(type!=$12->type){
            yyerror("Type Clashing");
            $$->is_error=1;
        }
        
        if(curLookup(*$1)){
				string errstr = *$1 + " is already declared\n";
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
            insertSymbol(*cur_table,*$1, "IDENTIFIER", *$1, type, yylineno, NULL, modifier);
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
            yyerror("Index out of bounds, not matching with intitalisers");
            $$->is_error=1;
        }
        if(type!=$7->type){
            yyerror("Type Clashing");
            $$->is_error=1;
        }
        
        if(curLookup(*$1)){
				string errstr = *$1 + " is already declared\n";
				yyerror(errstr.c_str());
				$$->is_error = 1;            
        }
        else{
            isArray=1;
            if($3==NULL) array_dims.push_back(0);
            else array_dims.push_back($3->intVal);
            insertSymbol(*cur_table,*$1, "IDENTIFIER", *$1, type, yylineno, NULL, modifier);
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
            yyerror("Index out of bounds, not matching with intitalisers");
        }
        if($6!=NULL && $6->intVal>cnt2){
            yyerror("Index out of bounds, not matching with intitalisers");
        }
        if(type!=$10->type){
            yyerror("Type Clashing");
            $$->is_error=1;
        }
        
        if(curLookup(*$1)){
				string errstr = *$1 + " is already declared\n";
				yyerror(errstr.c_str());
				$$->is_error = 1;            
        }
        else{
            isArray=1;
            if($3==NULL) array_dims.push_back(0);
            else array_dims.push_back($3->intVal);
            if($6==NULL) array_dims.push_back(0);
            else array_dims.push_back($6->intVal);
            insertSymbol(*cur_table,*$1, "IDENTIFIER", *$1, type, yylineno, NULL, modifier);
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
            yyerror("Index out of bounds, not matching with intitalisers");
        }
        if($6!=NULL && $6->intVal>cnt2){
            yyerror("Index out of bounds, not matching with intitalisers");
        }
        if($9!=NULL && $9->intVal>cnt3){
            yyerror("Index out of bounds, not matching with intitalisers");
        }
        if(type!=$13->type){
            yyerror("Type Clashing");
            $$->is_error=1;
        }
        
        if(curLookup(*$1)){
				string errstr = *$1 + " is already declared\n";
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
            insertSymbol(*cur_table,*$1, "IDENTIFIER", *$1, type, yylineno, NULL, modifier);
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
            yyerror("Type Clashing");
            $$->is_error=1;
        }
        
        if(curLookup(*$1)){
				string errstr = *$1 + " is already declared\n";
				yyerror(errstr.c_str());
				$$->is_error = 1;            
        }
        else{
            isArray=1;
            if($3==NULL) array_dims.push_back(0);
            else array_dims.push_back($3->intVal);
            insertSymbol(*cur_table,*$1, "IDENTIFIER", *$1, type, yylineno, NULL, modifier);
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
            yyerror("Index out of bounds, not matching with intitalisers");
        }
        if($6!=NULL && $6->intVal>cnt2){
            yyerror("Index out of bounds, not matching with intitalisers");
        }
        if(type!=$10->type){
            yyerror("Type Clashing");
            $$->is_error=1;
        }
        
        if(curLookup(*$1)){
				string errstr = *$1 + " is already declared\n";
				yyerror(errstr.c_str());
				$$->is_error = 1;            
        }
        else{
            isArray=1;
            if($3==NULL) array_dims.push_back(0);
            else array_dims.push_back($3->intVal);
            if($6==NULL) array_dims.push_back(0);
            else array_dims.push_back($6->intVal);
            insertSymbol(*cur_table,*$1, "IDENTIFIER", *$1, type, yylineno, NULL, modifier);
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
            yyerror("Type Clashing");
            $$->is_error=1;
        }
        
        if(curLookup(*$1)){
				string errstr = *$1 + " is already declared\n";
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
            insertSymbol(*cur_table,*$1, "IDENTIFIER", *$1, type, yylineno, NULL, modifier);
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

        $2->type=$1->type;
        $$->type=$1->type;
    }
    | KEY_void Methodeclarator {
        vector<ASTNode*> s;
        s.push_back($2);
        $$ = makeNode("void", s);

        $2->type="void";
        $$->type="void";
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

MethodIDEN:
    IDENTIFIER      {
        $$ = makeLeaf("ID (" + *$1+")" );
        $$->temp_name = *$1;
        funcName = *$1;
        funcType = type;
        $$->type =type;
        type ="";
        class_type="";
        delete $1;
    }
;

IdenPara:
    MethodIDEN F '(' formalparameters ')' {
        vector<ASTNode*> s;
        s.push_back($1);
        s.push_back($4);
        $$ = makeNode("IdenPara", s);

        if(!$4->is_error){
            $$->temp_name = $1->temp_name;
            $$->expType = 3;
            $$->type = $1->type;

            vector<string> temp = getFuncArgs($1->temp_name);
            if(curLookup($1->temp_name)){
                yyerror(("Redeclaration of Parameter "+ $1->temp_name).c_str());
                $$->is_error = 1;
            }
            else if(temp.size()==1 && temp[0] == "#NO_FUNC"){
                insertFuncArg($$->temp_name, funcArgs, $$->type);
                funcArgs.clear();
            }
        }
        else{
            $$->is_error = 1;
        }
    }
    | MethodIDEN F '(' ')' {
        vector<ASTNode*> s;
        s.push_back($1);
        $$ = makeNode("IdenPara", s);

        if(1){
            $$->temp_name = $1->temp_name;
            $$->expType = 3;
            $$->type = $1->type;

            vector<string> temp = getFuncArgs($1->temp_name);
            if(curLookup($1->temp_name)){
                yyerror(("Redeclaration of Parameter "+ $1->temp_name).c_str());
                $$->is_error = 1;
            }
            else if(temp.size()==1 && temp[0] == "#NO_FUNC"){
                insertFuncArg($$->temp_name, funcArgs, $$->type);
                funcArgs.clear();
            }
        }
        else{
            $$->is_error = 1;
        }
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

        if(!$1->is_error && !$2->is_error){
            if($2->expType == 1 || $2->expType ==2){
                if(curLookup($2->temp_name)){
                    yyerror(("Redeclaration of parameter "+ $2->temp_name).c_str());
                    $$->is_error = 1;
                }
                else{
                    paramInsert(*cur_table, $2->temp_name, "IDENTIFIER", $2->temp_name,$2->type, yylineno, NULL, modifier);
                }
            }
            funcArgs.push_back($2->type);
        }
        else $$->is_error = 1;
        type ="";
    }
    | KEY_final Type VariableDeclarator1 {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("final"));
        s.push_back($2);
        s.push_back($3);
        $$ = makeNode("formalparameter", s);

        if(type=="")type=$2->type;
        $$->type=type;
        modifier[2]=1;
        if(!$2->is_error && !$3->is_error){
            if($3->expType == 1 || $3->expType ==2){
                if(curLookup($3->temp_name)){
                    yyerror(("Redeclaration of parameter "+ $3->temp_name).c_str());
                    $$->is_error = 1;
                }
                else{
                    paramInsert(*cur_table, $3->temp_name, "IDENTIFIER", $3->temp_name,$3->type, yylineno, NULL, modifier);
                }
            }
            funcArgs.push_back($3->type);
        }
        else $$->is_error = 1;
        type ="";
    }
    | Type DOT3 IDENTIFIER {
        vector<ASTNode*> s;
        s.push_back($1);
        s.push_back(makeLeaf(*$2));
        delete $2;
        s.push_back(makeLeaf("ID (" + *$3+")" ));
        $$ = makeNode("formalparameter", s);

        if(type=="")type=$1->type;
        $$->type=type;

        if(!$1->is_error){
            if(curLookup(*$3)){
                yyerror(("Redeclaration of parameter "+ *$3).c_str());
                $$->is_error = 1;
            }
            else{
                paramInsert(*cur_table, *$3, "IDENTIFIER", *$3,type, yylineno, NULL, modifier);
            }
            funcArgs.push_back("...");
            funcArgs.push_back(type);
        }
        else $$->is_error = 1;
        type ="";
        delete $3;
    }
    | KEY_final Type DOT3 IDENTIFIER {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("final"));
        s.push_back($2);
        s.push_back(makeLeaf(*$3));
        delete $3;
        s.push_back(makeLeaf("ID (" + *$4+")" ));
        $$ = makeNode("formalparameter", s);

        if(type=="")type=$2->type;
        $$->type=type;
        modifier[2]=1;
        if(!$2->is_error){
            if(curLookup(*$4)){
                yyerror(("Redeclaration of parameter "+ *$4).c_str());
                $$->is_error = 1;
            }
            else{
                paramInsert(*cur_table, *$4, "IDENTIFIER", *$4,type, yylineno, NULL, modifier);
            }
            funcArgs.push_back("...");
            funcArgs.push_back(type);
        }
        else $$->is_error = 1;
        type ="";
        delete $4;
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

F:
     {
        $$ = makeLeaf("F");
        if(global_st.find(funcName) != global_st.end()){
            yyerror(("Redefinition of function " + funcName).c_str());
            $$->is_error = 1;
        }
        else{
            makeSymbolTable(funcName, funcType, yylineno, modifier);
            $$->node_name = funcName;
            block_count = 1;
            type = "";
            class_type = "";
        }
    }

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