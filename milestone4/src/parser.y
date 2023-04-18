%{
#include <stdio.h>
#include <iostream>
#include"AST.h"
#include"codegen.h"
#include <fstream>

FILE* dotfile;
extern FILE* yyin;
extern int yyrestart(FILE*);
extern int yylineno;
extern map<sym_table*, vector<pair<string,sym_table*>>> children_table;

bool gotinputfile, gotoutputfile, verbosemode;

// int dump_sym_table=0;
int tempo=0;
int isArray=0;
int cnt1=0,cnt2=0,cnt3=0;
int block_count = 0;
int func_flag=0;
int for_flag=0;
int arr_dm;
int inPrint = 0;

string type="";
string class_type="", cur_class="";
string idendotiden ="";
string funcName="", funcType ="";
string file_path="";
string code_file_name="";

vector<int> array_dims;
vector<int> modifier ={1,0,0};
vector<string> funcArgs, tempArgs1;
vector<vector<string> > curArgs(1,vector<string>() );

ofstream code_file;

stack<int> block_stack;

int yylex();
int yyerror(const char *str);

stack <quad> forstat;
stack <int> forstat_curr;

map<string,string> mp_param;
map<string, int> method_invoked;

bool inconst=false;

%}

%locations
%token KEYWORD IDENTIFIER INTLIT FPLIT BOOLLIT CHARLIT STRLIT OPERATOR INTTYPE FPTYPE BOOLTYPE ASSIGNOP CONDOR CONDAND EQALITYOP RELATIONOP SHIFTOP ADDOP MULTOP ADDOP2 UNARYOP KEY_VAR KEY_assert KEY_yield KEY_throw KEY_break KEY_continue KEY_return KEY_if KEY_else KEY_for KEY_permits KEY_while KEY_sync KEY_final KEY_extends KEY_super KEY_this KEY_class KEY_void KEY_public KEY_new KEY_static DOT3 KEY_private KEY_import

%union{
    std::string *st;
    ASTNode *ptr;
    int x;
}

%type<st> KEYWORD IDENTIFIER INTLIT FPLIT BOOLLIT CHARLIT STRLIT OPERATOR INTTYPE FPTYPE BOOLTYPE ASSIGNOP CONDOR CONDAND EQALITYOP RELATIONOP SHIFTOP ADDOP MULTOP ADDOP2 UNARYOP KEY_VAR KEY_assert KEY_yield KEY_throw KEY_break KEY_continue KEY_return KEY_if KEY_else KEY_for KEY_permits KEY_while KEY_sync KEY_final KEY_extends KEY_super KEY_this KEY_class KEY_void KEY_public KEY_new KEY_static DOT3 KEY_private KEY_import

%type<ptr> Start ImportList ClassDeclarationList Imports Type PrimitiveType IDENdotIDEN PublicPrivateStatic ClassType ArrayType Dims Literal F MethodIDEN C A
%type<ptr> Primary PrimaryNoNewArray ClassInstanceCreationExpression Zeroorone_ArgumentList FieldAccess ArrayAccess MethodInvocation ArgumentList ArrayCreationExpression DimExpr Expression AssignmentExpression Assignment ConditionalExpression ConditionalAndExpression ConditionalOrExpression AndExpression ExclusiveOrExpression InclusiveOrExpression EqualityExpression RelationalExpression ShiftExpression MultiplicativeExpression AdditiveExpression UnaryExpression UnaryExpressionNotPlusMinus CastExpression postfixExpression
%type<ptr> Block BlockStatement BlockStatements LocalVariableDeclaration LocalVariableType Statement StatementExpression StatementNoShortIf StatementWithoutTrailingSubstatement LeftHandSide AssertStatement BreakContinueStatement ForInit ForStatement ForStatementNoShortIf StatementExpressionList
%type<ptr> ClassDeclaration NormalClassDeclaration ClassExtends ClassPermits cTypeName ClassBody ClassBodyDeclaration ClassBodyDeclarations VariableDeclarator VariableDeclaratorList zerooroneExpression VariableDeclarator1 VariableDeclarator2 List1 List2 List3 ArrEle1 ArrEle2 ArrEle3 MethodHeader MethodDeclaration MethodBody Methodeclarator ConstructorDeclaration formalparameter formalparameters Modifiers
%type<x> MarkerNT 
%type<ptr> MarkerNT2 ForStatementExpressionList ConstructorIDEN
%type<ptr> jumpstat 
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
        $$ = makeNode(".", s);
        class_type=class_type+"."+*$3;
        idendotiden = idendotiden + "." +*$3;
        $$->type=type;
        $$->temp_name = $1->temp_name + "." + *$3;
        
        
        delete $3;
        
    }
    | IDENTIFIER    {
        $$ = makeLeaf("ID (" + *$1 + ")");
        class_type=*$1;
        idendotiden = *$1;
        $$->type=type;
        $$->temp_name = *$1;

        //3ac
        if(mp_param.find(*$1)!=mp_param.end()){
            string tmp=mp_param[*$1];
            $$->addr=qid(tmp,lookup(tmp));
        }
        else{
        qid tmp=qid(*$1,lookup(*$1));
        $$->addr=tmp;
        }


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
        int pos = $1->temp_name.find(".");
        string sub = $1->temp_name.substr(0, pos);
        string first=sub;
        if(pos != -1){
            sub = primaryExpression(sub);
        }
        if(global_st.find(sub) == global_st.end()){
            yyerror(("Undefined class " + sub).c_str());
            $$->is_error = 1;
        }
        else{
            if($1->temp_name.find('.')!=string::npos){
                string sub1 = $1->temp_name.substr(pos+1);
                string second=sub1;
                for(auto it: children_table[&global_st]){
                    if(it.first == sub){
                        if((*(it.second)).find(sub1) == (*(it.second)).end()){
                            yyerror(("Undefined member of class " + sub).c_str());
                            $$->is_error = 1;
                        }
                        else{
                            $$->type = class_type;
                            type = class_type;

                            
                        }
                    }
                }
            }
            else{
                $$->type = class_type;
                type = class_type;
            }
        }
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
        isArray =1;
        $$->expType = 2;
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
        $$->temp_name="this";
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
        $$->temp_name=$2->temp_name;

        //3ac
        int sz=getClassSize($2->temp_name);
        qid tmp=newtemp("int");
        emit(qid("=",NULL),qid(to_string(sz),NULL),qid("",NULL),tmp,-1);
        emit(qid("call_alloc",NULL),tmp,qid("",NULL),qid("",NULL),-1); // pushparam 
        qid obj=newtemp($2->temp_name);
        emit(qid("=",NULL),qid("popparam",NULL),qid("",NULL),obj,-1);
        $$->addr=obj;
    }
    | KEY_new IDENdotIDEN '(' Zeroorone_ArgumentList ')'        {
        vector<ASTNode*> s;
        s.push_back($2);
        s.push_back($4);
        $$ = makeNode("new", s);
        if(type=="")type=$2->type;
        $$->type=type;
        $$->temp_name=$2->temp_name;

        //3ac
        int sz=getClassSize($2->temp_name);
        qid tmp=newtemp("int");
        emit(qid("=",NULL),qid(to_string(sz),NULL),qid("",NULL),tmp,-1);
        emit(qid("call_alloc",NULL),tmp,qid("",NULL),qid("",NULL),-1); // pushparam 
        qid obj=newtemp($2->temp_name);
        emit(qid("=",NULL),qid("popparam",NULL),qid("",NULL),obj,-1);
        $$->addr=obj;


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
        $$ = makeNode("FieldAccess", s);
        if($1->temp_name == "this"){
            string temp = primaryExpression(*$3);
            if(temp == ""){
                yyerror(("Undeclared Identifier " + *$3).c_str());
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
                    $$->temp_name = $1->temp_name+"."+*$3; 
                    // $$->nextlist.clear();
                }
                else{
                    $$->type = temp;
                    $$->temp_name = $1->temp_name+"."+*$3;
                    if(temp.back()=='*') $$->type = temp.substr(0,temp.size()-1);
                    
                    //3ac

                }
            }
        }
        delete $3;
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
        arr_dm=0;
        if($1->temp_name.find('.') == string::npos){
            string temp = primaryExpression($1->temp_name);
            if(temp == ""){
                yyerror(("Undeclared Identifier " + $1->temp_name).c_str());
                $$->is_error = 1;
            }
            else{
                if(temp.back() == '*'){
                    $$->expType = 2;
                    temp = temp.substr(0,temp.size()-1);
                    if(isInt($3->type)){
                        if($3->expType==4 && ($3->intVal>=lookup($1->temp_name)->array_dims[0] || $3->intVal>=0)){
                            yyerror("Array index out of bound");
                            $$->is_error =1;
                        }
                        else{
                            $$->type = temp;
                            $$->temp_name = $1->temp_name;
                            //3ac

                            qid tmp=newtemp("int");
                            if($3->expType==4)emit(qid("*",NULL),qid(to_string(getSize(temp)),NULL),qid(to_string($3->intVal),NULL),tmp,-1);
                            else emit(qid("*",NULL),qid(to_string(getSize(temp)),NULL),$3->addr,tmp,-1);
                            qid tmp2=newtemp(temp);
                            emit(qid("+",NULL),$1->addr,tmp,tmp2,-1);
                            $$->addr=tmp2;
                        }
                    }
                    else{
                        yyerror("Index not integer");
                        $$->is_error=1;
                    }
                }
                else $$->is_error=1;
            }
        }
        else{
            int pos = $1->temp_name.find(".");
            string sub = $1->temp_name.substr(0, pos);
            sub = primaryExpression(sub);
            string sub1 = $1->temp_name.substr(pos+1);
            if(global_st.find(sub) == global_st.end()){
                yyerror(("Undefined class " + sub).c_str());
                $$->is_error = 1;
            }
            else{
                for(auto it: children_table[&global_st]){
                    if(it.first == sub){
                        if((*(it.second)).find(sub1) == (*(it.second)).end()){
                            yyerror(("Undefined member of class " + sub).c_str());
                            $$->is_error = 1;
                        }
                        else{
                            string tem = (*(it.second))[sub1]->type;
                            if((*(it.second))[sub1]->isArray){
                                $$->expType = 2; 
                                if(!isInt($3->type)){
                                    yyerror("Index not integer");
                                    $$->is_error=1;
                                }
                                else{
                                    if($3->expType ==4 && ($3->intVal >= (*(it.second))[sub1]->array_dims[0] || $3->intVal>=0)){
                                        yyerror("Array index out of bound");
                                        $$->is_error =1;
                                    }
                                    else{
                                        $$->type = tem;
                                        $$->temp_name = $1->temp_name;
                                        if(tem.back()=='*') $$->type = tem.substr(0,tem.size()-1);
                                        tem=tem.substr(0,tem.size()-1);
                                        
                                        //3ac
                                        qid tmp=newtemp("int");
                                        if($3->expType == 4) emit(qid("",NULL),qid(to_string(getSize(tem)),NULL),$3->addr,tmp,-1);
                                        else emit(qid("",NULL),qid(to_string(getSize(tem)),NULL),qid(to_string($3->intVal),NULL),tmp,-1);
                                        qid tmp2=newtemp(tem);
                                        emit(qid("+",NULL),$1->addr,tmp,tmp2,-1);
                                        $$->addr=tmp2;
                                    }
                                }
                            }
                            else $$->is_error = 1;
                        }
                    }
                }
            }
        }
    }
    | IDENdotIDEN '[' Expression ']' '[' Expression ']' {
        vector<ASTNode*> s;
        s.push_back($1);
        s.push_back($3);
        s.push_back($6);
        $$ = makeNode("ArrayAccess", s);
        arr_dm=0;
        if($1->temp_name.find('.') == string::npos){
            string temp = primaryExpression($1->temp_name);
            if(temp == ""){
                yyerror(("Undeclared Identifier " + $1->temp_name).c_str());
                $$->is_error = 1;
            }
            else{
                if(temp.back() == '*'){
                    $$->expType = 2;
                    temp=temp.substr(0,temp.size()-1);
                    $$->type = temp;
                    $$->temp_name = $1->temp_name;

                    if(!isInt(temp)){
                        yyerror("Index not integer");
                        $$->is_error=1;
                    }
                    else{
                        if(($3->expType==4 && ($3->intVal>=lookup($1->temp_name)->array_dims[0] || $3->intVal>=0)) ||($6->expType==4 && ($6->intVal>=lookup($1->temp_name)->array_dims[1] || $6->intVal>=0))){
                            yyerror("Array index out of bound");
                            $$->is_error =1;
                        }
                        else{
                            //3ac
                            int c1=lookup($1->temp_name)->array_dims[1] * getSize(temp);
                            // a[i][j]   t1= i * (getsize()* dims[1])  t2 = j * getsize()  t3 = t1 + t2    t4 = a + t3
                            qid tmp=newtemp("int");
                            if($3->expType!=4)
                                emit(qid("*",NULL),$3->addr,qid(to_string(c1),NULL),tmp,-1);
                            else 
                                emit(qid("*",NULL),qid($3->temp_name,NULL),qid(to_string(c1),NULL),tmp,-1);
                            qid tmp2=newtemp("int");
                            if($6->expType!=4)
                                emit(qid("*",NULL),$6->addr,qid(to_string(getSize($6->type)),NULL),tmp2,-1);
                            else 
                                emit(qid("*",NULL),qid($6->temp_name,NULL),qid(to_string(getSize($6->type)),NULL),tmp2,-1);
                            qid tmp3=newtemp("int");
                            emit(qid("+",NULL),tmp,tmp2,tmp3,-1);
                            qid tmp4=newtemp("int");
                            emit(qid("+",NULL),$1->addr,tmp3,tmp4,-1);
                            $$->addr=tmp4;
                        }
                    }
                }
                else $$->is_error = 1;
            }
        }
        else{
            int pos = $1->temp_name.find(".");
            string sub = $1->temp_name.substr(0, pos);
            sub = primaryExpression(sub);
            string sub1 = $1->temp_name.substr(pos+1);
            if(global_st.find(sub) == global_st.end()){
                yyerror(("Undefined class " + sub).c_str());
                $$->is_error = 1;
            }
            else{
                for(auto it: children_table[&global_st]){
                    if(it.first == sub){
                        if((*(it.second)).find(sub1) == (*(it.second)).end()){
                            yyerror(("Undefined member of class " + sub).c_str());
                            $$->is_error = 1;
                        }
                        else{
                            string tem = (*(it.second))[sub1]->type;
                            if((*(it.second))[sub1]->isArray){
                                $$->expType = 2; 
                                tem=tem.substr(0,tem.size()-1);
                                $$->type = tem;
                                $$->temp_name = $1->temp_name;

                                if(!isInt(tem)){
                                    yyerror("Index not integer");
                                    $$->is_error=1;
                                }
                                else{
                                    if(($3->expType==4 && ($3->intVal>=lookup($1->temp_name)->array_dims[0] || $3->intVal>=0)) ||($6->expType==4 && ($6->intVal>=lookup($1->temp_name)->array_dims[1] || $6->intVal>=0))){
                                        yyerror("Array index out of bound");
                                        $$->is_error =1;
                                    }
                                    else{
                                        //3ac
                                        int c1=lookup($1->temp_name)->array_dims[1] * getSize(tem);
                                           // a[i][j]   t1= i * (getsize()* dims[1])  t2 = j * getsize()  t3 = t1 + t2    t4 = a + t3
                                        qid tmp=newtemp("int");
                                        if($3->expType!=4)
                                            emit(qid("*",NULL),$3->addr,qid(to_string(c1),NULL),tmp,-1);
                                        else 
                                            emit(qid("*",NULL),qid($3->temp_name,NULL),qid(to_string(c1),NULL),tmp,-1);
                                        qid tmp2=newtemp("int");
                                        if($6->expType!=4)
                                            emit(qid("*",NULL),$6->addr,qid(to_string(getSize($6->type)),NULL),tmp2,-1);
                                        else 
                                            emit(qid("*",NULL),qid($6->temp_name,NULL),qid(to_string(getSize($6->type)),NULL),tmp2,-1);
                                        qid tmp3=newtemp("int");
                                        emit(qid("+",NULL),tmp,tmp2,tmp3,-1);
                                        qid tmp4=newtemp("int");
                                        emit(qid("+",NULL),$1->addr,tmp3,tmp4,-1);
                                        $$->addr=tmp4;
                                    }
                                }
                            }
                            else $$->is_error = 1;
                        }
                    }
                }
            }
        }
    }
    | IDENdotIDEN '[' Expression ']' '[' Expression ']' '[' Expression ']' {
        vector<ASTNode*> s;
        s.push_back($1);
        s.push_back($3);
        s.push_back($6);
        s.push_back($9);
        $$ = makeNode("ArrayAccess", s);
        arr_dm=0;
        if($1->temp_name.find('.') == string::npos){
            string temp = primaryExpression($1->temp_name);
            if(temp == ""){
                yyerror(("Undeclared Identifier " + $1->temp_name).c_str());
                $$->is_error = 1;
            }
            else{
                if(temp.back() == '*'){
                    $$->expType = 2;
                    temp=temp.substr(0,temp.size()-1);
                    $$->type = temp;
                    $$->temp_name = $1->temp_name;

                    if(!isInt(temp)){
                        yyerror("Index not integer");
                        $$->is_error=1;
                    }
                    else{
                        if(($3->expType==4 && ($3->intVal>=lookup($1->temp_name)->array_dims[0] || $3->intVal>=0)) ||($6->expType==4 && ($6->intVal>=lookup($1->temp_name)->array_dims[1] || $6->intVal>=0))||($9->expType==4 && ($9->intVal>=lookup($1->temp_name)->array_dims[2] || $9->intVal>=0))){
                            yyerror("Array index out of bound");
                            $$->is_error =1;
                        }
                        else{
                            //3ac
                            int c1=lookup($1->temp_name)->array_dims[1] * getSize(temp)*lookup($1->temp_name)->array_dims[2];
                              // a[i][j]   t1= i * (getsize()* dims[1])  t2 = j * getsize()  t3 = t1 + t2    t4 = a + t3
                            qid tmp=newtemp("int");
                            if($3->expType!=4)
                                emit(qid("*",NULL),$3->addr,qid(to_string(c1),NULL),tmp,-1);
                            else 
                                emit(qid("*",NULL),qid($3->temp_name,NULL),qid(to_string(c1),NULL),tmp,-1);
                            qid tmp2=newtemp("int");
                            int c2=lookup($1->temp_name)->array_dims[2] * getSize(temp);
                            if($6->expType!=4)
                                emit(qid("*",NULL),$6->addr,qid(to_string(c2),NULL),tmp2,-1);
                            else 
                                emit(qid("*",NULL),qid($6->temp_name,NULL),qid(to_string(c2),NULL),tmp2,-1);
                            qid tmp3=newtemp("int");
                            if($9->expType!=4)
                                emit(qid("*",NULL),$9->addr,qid(to_string(getSize($9->type)),NULL),tmp3,-1);
                            else 
                                emit(qid("*",NULL),qid($9->temp_name,NULL),qid(to_string(getSize($9->type)),NULL),tmp3,-1);
                            qid tmp4=newtemp("int");
                            emit(qid("+",NULL),tmp,tmp2,tmp4,-1);
                            qid tmp5=newtemp("int");
                            emit(qid("+",NULL),tmp3,tmp4,tmp5,-1);
                            qid tmp6=newtemp("int");
                            emit(qid("+",NULL),$1->addr,tmp5,tmp6,-1);
                            $$->addr=tmp6;
                        }
                    }
                }
                else $$->is_error = 1;
            }
        }
        else{
            int pos = $1->temp_name.find(".");
            string sub = $1->temp_name.substr(0, pos);
            sub = primaryExpression(sub);
            string sub1 = $1->temp_name.substr(pos+1);
            if(global_st.find(sub) == global_st.end()){
                yyerror(("Undefined class " + sub).c_str());
                $$->is_error = 1;
            }
            else{
                for(auto it: children_table[&global_st]){
                    if(it.first == sub){
                        if((*(it.second)).find(sub1) == (*(it.second)).end()){
                            yyerror(("Undefined member of class " + sub).c_str());
                            $$->is_error = 1;
                        }
                        else{
                            string tem = (*(it.second))[sub1]->type;
                            if((*(it.second))[sub1]->isArray){
                                $$->expType = 2; 
                                tem=tem.substr(0,tem.size()-1);
                                $$->type = tem;
                                $$->temp_name = $1->temp_name;

                                if(!isInt(tem)){
                                    yyerror("Index not integer");
                                    $$->is_error=1;
                                }
                                else{
                                    if(($3->expType==4 && ($3->intVal>=lookup($1->temp_name)->array_dims[0] || $3->intVal>=0)) ||($6->expType==4 && ($6->intVal>=lookup($1->temp_name)->array_dims[1] || $6->intVal>=0))||($9->expType==4 && ($9->intVal>=lookup($1->temp_name)->array_dims[2] || $9->intVal>=0))){
                                        yyerror("Array index out of bound");
                                        $$->is_error =1;
                                    }
                                    else{
                                        //3ac
                                        int c1=lookup($1->temp_name)->array_dims[1] * getSize(tem)*lookup($1->temp_name)->array_dims[2];
                             // a[i][j]   t1= i * (getsize()* dims[1])  t2 = j * getsize()  t3 = t1 + t2    t4 = a + t3
                                    qid tmp=newtemp("int");
                                    if($3->expType!=4)
                                        emit(qid("*",NULL),$3->addr,qid(to_string(c1),NULL),tmp,-1);
                                    else 
                                        emit(qid("*",NULL),qid($3->temp_name,NULL),qid(to_string(c1),NULL),tmp,-1);
                                    qid tmp2=newtemp("int");
                                    int c2=lookup($1->temp_name)->array_dims[2] * getSize(tem);
                                    if($6->expType!=4)
                                        emit(qid("*",NULL),$6->addr,qid(to_string(c2),NULL),tmp2,-1);
                                    else 
                                        emit(qid("*",NULL),qid($6->temp_name,NULL),qid(to_string(c2),NULL),tmp2,-1);
                                    qid tmp3=newtemp("int");
                                    if($9->expType!=4)
                                        emit(qid("*",NULL),$9->addr,qid(to_string(getSize($9->type)),NULL),tmp3,-1);
                                    else 
                                        emit(qid("*",NULL),qid($9->temp_name,NULL),qid(to_string(getSize($9->type)),NULL),tmp3,-1);
                                    qid tmp4=newtemp("int");
                                    emit(qid("+",NULL),tmp,tmp2,tmp4,-1);
                                    qid tmp5=newtemp("int");
                                    emit(qid("+",NULL),tmp3,tmp4,tmp5,-1);
                                    qid tmp6=newtemp("int");
                                    emit(qid("+",NULL),$1->addr,tmp5,tmp6,-1);
                                    $$->addr=tmp6;
                                    }
                                }
                            }
                            else $$->is_error = 1;
                        }
                    }
                }
            }
        }
    }
;

MethodInvocation:
    IDENdotIDEN {if($1->temp_name == "System.out.println") inPrint = 1;}'(' Zeroorone_ArgumentList ')'          {
        vector<ASTNode*> s;
        s.push_back($1);
        s.push_back($4);
        $$ = makeNode("MethodInvocation", s);

        if($1->temp_name == "System.out.println"){
            $$->type = "";

            //3ac
            int argsize=0;
            if($4!=NULL){
                argsize=$4->size;
            }
            emit(qid("call",NULL),qid("print 1",NULL),qid("",NULL),qid("",NULL),-1);
            qid rem=newtemp("int");
            emit(qid("=",NULL),qid(to_string(argsize),NULL),qid("",NULL),rem,-1);
            emit(qid("stackpointer--",NULL),rem,qid("",NULL),qid("",NULL),-1);
            inPrint = 0;

        }
        else{
            string st= $1->temp_name;
            int pos = st.find(".");
            if(pos != -1){
                string sub = st.substr(0,pos);
                sub = primaryExpression(sub);
                string sub1 = $1->temp_name.substr(pos+1);
                if(global_st.find(sub) == global_st.end()){
                    yyerror(("Undefined class " + sub).c_str());
                    $$->is_error = 1;
                }
                else{
                    st = st.substr(pos+1);
                }
            }
            string t = postfixExpression(st,1);
            curArgs.push_back(vector<string>() ); 

            if(t.empty()){
                t = getFuncType(st);
                if(t.substr(0,5)=="FUNC_"){
                    t = t.substr(5);
                    $1->expType = 3;
                }
            }
            if(!($1->is_error) && $1->expType!=4){
                if(!t.empty()){	
                    if($1->expType==3){
                        vector<string> funcArg = getFuncArgs(st);
                        if(funcArg != tempArgs1){
                            yyerror(("Function " + st + " arguments do not match").c_str());
                            $$->is_error = 1;
                        }
                        else{
                            $$->type = t;
                            //3ac
                            int argsize=0;
                            if($4!=NULL){
                                argsize=$4->size;
                            }
                            if(t=="void"){
                                int minus=argsize;
                                emit(qid("call",NULL),qid($1->temp_name,NULL),qid(to_string(funcArg.size()),NULL),qid("",NULL),-1);
                                qid rem=newtemp("int");
                                emit(qid("=",NULL),qid(to_string(minus),NULL),qid("",NULL),rem,-1);
                                emit(qid("stackpointer--",NULL),rem,qid("",NULL),qid("",NULL),-1);
                            }
                            else{
                                int minus=argsize;
                                int plus=getSize(t)+4;
                                qid ad=newtemp("int");
                                emit(qid("=",NULL),qid(to_string(plus),NULL),qid("",NULL),ad,-1);
                                emit(qid("call",NULL),qid($1->temp_name,NULL),qid(to_string(funcArg.size()),NULL),qid("",NULL),-1);
                                qid tmp=newtemp(t);
                                emit(qid("=",NULL),qid("popreturn",NULL),qid("",NULL),tmp,-1);
                                qid rem=newtemp("int");
                                emit(qid("=",NULL),qid(to_string(minus),NULL),qid("",NULL),rem,-1);
                                emit(qid("stackpointer--",NULL),rem,qid("",NULL),qid("",NULL),-1);
                                
                                method_invoked[$1->temp_name] = 1;
                                $$->addr=tmp;
                            }
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
        tempArgs1.clear();
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

        //
    }
;

ArgumentList:
    ArgumentList ',' Expression     {
        vector<ASTNode*> s;
        s.push_back($1);
        s.push_back($3);
        $$ = makeNode(",", s);
        tempArgs1.push_back($3->type);

        //3ac
        if($3->expType==4){
            qid tmp=newtemp($3->type);
            if(isInt($3->type))
                emit(qid("=",NULL),qid(to_string($3->intVal),NULL),qid("",NULL),tmp,-1);
            else 
                emit(qid("=",NULL),qid(to_string($3->realVal),NULL),qid("",NULL),tmp,-1);

            $3->addr=tmp;
        }
        else if($3->expType==5){
            qid tmp=newtemp($3->type);
            emit(qid("=",NULL),qid($3->strVal,NULL),qid("",NULL),tmp,-1);
            $3->addr=tmp;
        }
        emit(qid("param",NULL),$3->addr,qid("",NULL),qid("",NULL),-1);
        $$->size=$1->size+getSize($3->type);
        
    }
    | Expression        {
        $$ = $1;
        $$->size=getSize($1->type);
        tempArgs1.push_back($$->type);

        //3ac
        if($1->expType==4){
            qid tmp=newtemp($1->type);
            if($1->type=="int")
                emit(qid("=",NULL),qid(to_string($1->intVal),NULL),qid("",NULL),tmp,-1);
            else 
                emit(qid("=",NULL),qid(to_string($1->realVal),NULL),qid("",NULL),tmp,-1);

            $1->addr=tmp;
        }
        emit(qid("param",NULL),$1->addr,qid("",NULL),qid("",NULL),-1);
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
                string add="";
                int flag=0;
                if($3->type!=t){
                    qid cast=newtemp(t);
                    emit(qid("=",NULL),qid("cast_to_"+t+" "+$3->temp_name,NULL),qid("",NULL),cast,-1);
                    add=t;
                    flag=1;
                }
                if($1->temp_name.substr(0,5)=="this."){
                    $$->addr=$1->addr;
                    string second=$1->temp_name.substr(5,$1->temp_name.size()-5);
                    if(*$2=="*="){
                        qid offs=newtemp("int");
                        qid tmp=newtemp(t);
                        emit(qid("=",NULL),qid(to_string(getOffset(cur_class,second)),NULL),qid("",NULL),offs,-1);
                        if(mp_param.find($3->temp_name)==mp_param.end()){
                            emit(qid("*",NULL),qid($3->temp_name,NULL),qid("*("+mp_param["this"]+"+"+offs.first+")",NULL),tmp,-1);
                        }
                        else
                            emit(qid("*",NULL),qid(mp_param[$3->temp_name],NULL),qid("*("+mp_param["this"]+"+"+offs.first+")",NULL),tmp,-1);
                        
                        if(mp_param.find($3->temp_name)==mp_param.end()){
                            emit(qid("=",NULL),tmp,qid("",NULL),qid("*("+mp_param["this"]+"+"+offs.first+")",NULL),-1);
                        }
                        else
                            emit(qid("=",NULL),tmp,qid("",NULL),qid("*("+mp_param["this"]+"+"+offs.first+")",NULL),-1);
                    }
                    else if(*$2=="/="){
                        qid offs=newtemp("int");
                        qid tmp=newtemp(t);
                        emit(qid("=",NULL),qid(to_string(getOffset(cur_class,second)),NULL),qid("",NULL),offs,-1);
                        if(mp_param.find($3->temp_name)==mp_param.end()){
                            emit(qid("/",NULL),qid("*("+mp_param["this"]+"+"+offs.first+")",NULL),qid($3->temp_name,NULL),tmp,-1);
                        }
                        else
                            emit(qid("/",NULL),qid("*("+mp_param["this"]+"+"+offs.first+")",NULL),qid(mp_param[$3->temp_name],NULL),tmp,-1);
                        
                        if(mp_param.find($3->temp_name)==mp_param.end()){
                            emit(qid("=",NULL),tmp,qid("",NULL),qid("*("+mp_param["this"]+"+"+offs.first+")",NULL),-1);
                        }
                        else
                            emit(qid("=",NULL),tmp,qid("",NULL),qid("*("+mp_param["this"]+"+"+offs.first+")",NULL),-1);
                    } 
                    else if(*$2=="%="){
                        qid offs=newtemp("int");
                        qid tmp=newtemp(t);
                        emit(qid("=",NULL),qid(to_string(getOffset(cur_class,second)),NULL),qid("",NULL),offs,-1);
                        if(mp_param.find($3->temp_name)==mp_param.end()){
                            emit(qid("%",NULL),qid("*("+mp_param["this"]+"+"+offs.first+")",NULL),qid($3->temp_name,NULL),tmp,-1);
                        }
                        else
                            emit(qid("%",NULL),qid("*("+mp_param["this"]+"+"+offs.first+")",NULL),qid(mp_param[$3->temp_name],NULL),tmp,-1);
                        
                        if(mp_param.find($3->temp_name)==mp_param.end()){
                            emit(qid("=",NULL),tmp,qid("",NULL),qid("*("+mp_param["this"]+"+"+offs.first+")",NULL),-1);
                        }
                        else
                            emit(qid("=",NULL),tmp,qid("",NULL),qid("*("+mp_param["this"]+"+"+offs.first+")",NULL),-1);
                    }
                    else if(*$2=="+="){
                        qid offs=newtemp("int");
                        qid tmp=newtemp(t);
                        emit(qid("=",NULL),qid(to_string(getOffset(cur_class,second)),NULL),qid("",NULL),offs,-1);
                        if(mp_param.find($3->temp_name)==mp_param.end()){
                            emit(qid("+",NULL),qid("*("+mp_param["this"]+"+"+offs.first+")",NULL),qid($3->temp_name,NULL),tmp,-1);
                        }
                        else
                            emit(qid("+",NULL),qid("*("+mp_param["this"]+"+"+offs.first+")",NULL),qid(mp_param[$3->temp_name],NULL),tmp,-1);
                        
                        if(mp_param.find($3->temp_name)==mp_param.end()){
                            emit(qid("=",NULL),tmp,qid("",NULL),qid("*("+mp_param["this"]+"+"+offs.first+")",NULL),-1);
                        }
                        else
                            emit(qid("=",NULL),tmp,qid("",NULL),qid("*("+mp_param["this"]+"+"+offs.first+")",NULL),-1);
                    }
                    else if(*$2=="+="){
                        qid offs=newtemp("int");
                        qid tmp=newtemp(t);
                        emit(qid("=",NULL),qid(to_string(getOffset(cur_class,second)),NULL),qid("",NULL),offs,-1);
                        if(mp_param.find($3->temp_name)==mp_param.end()){
                            emit(qid("+",NULL),qid("*("+mp_param["this"]+"+"+offs.first+")",NULL),qid($3->temp_name,NULL),tmp,-1);
                        }
                        else
                            emit(qid("+",NULL),qid("*("+mp_param["this"]+"+"+offs.first+")",NULL),qid(mp_param[$3->temp_name],NULL),tmp,-1);
                        
                        if(mp_param.find($3->temp_name)==mp_param.end()){
                            emit(qid("=",NULL),tmp,qid("",NULL),qid("*("+mp_param["this"]+"+"+offs.first+")",NULL),-1);
                        }
                        else
                            emit(qid("=",NULL),tmp,qid("",NULL),qid("*("+mp_param["this"]+"+"+offs.first+")",NULL),-1);
                    }
                    else if(*$2=="-="){
                        qid offs=newtemp("int");
                        qid tmp=newtemp(t);
                        emit(qid("=",NULL),qid(to_string(getOffset(cur_class,second)),NULL),qid("",NULL),offs,-1);
                        if(mp_param.find($3->temp_name)==mp_param.end()){
                            emit(qid("-",NULL),qid("*("+mp_param["this"]+"+"+offs.first+")",NULL),qid($3->temp_name,NULL),tmp,-1);
                        }
                        else
                            emit(qid("-",NULL),qid("*("+mp_param["this"]+"+"+offs.first+")",NULL),qid(mp_param[$3->temp_name],NULL),tmp,-1);
                        
                        if(mp_param.find($3->temp_name)==mp_param.end()){
                            emit(qid("=",NULL),tmp,qid("",NULL),qid("*("+mp_param["this"]+"+"+offs.first+")",NULL),-1);
                        }
                        else
                            emit(qid("=",NULL),tmp,qid("",NULL),qid("*("+mp_param["this"]+"+"+offs.first+")",NULL),-1);
                    } 
                    else if(*$2=="<<="){
                        qid offs=newtemp("int");
                        qid tmp=newtemp(t);
                        emit(qid("=",NULL),qid(to_string(getOffset(cur_class,second)),NULL),qid("",NULL),offs,-1);
                        if(mp_param.find($3->temp_name)==mp_param.end()){
                            emit(qid("<<",NULL),qid("*("+mp_param["this"]+"+"+offs.first+")",NULL),qid($3->temp_name,NULL),tmp,-1);
                        }
                        else
                            emit(qid("<<",NULL),qid("*("+mp_param["this"]+"+"+offs.first+")",NULL),qid(mp_param[$3->temp_name],NULL),tmp,-1);
                        
                        if(mp_param.find($3->temp_name)==mp_param.end()){
                            emit(qid("=",NULL),tmp,qid("",NULL),qid("*("+mp_param["this"]+"+"+offs.first+")",NULL),-1);
                        }
                        else
                            emit(qid("=",NULL),tmp,qid("",NULL),qid("*("+mp_param["this"]+"+"+offs.first+")",NULL),-1);
                    }
                    else if(*$2==">>="){
                        qid offs=newtemp("int");
                        qid tmp=newtemp(t);
                        emit(qid("=",NULL),qid(to_string(getOffset(cur_class,second)),NULL),qid("",NULL),offs,-1);
                        if(mp_param.find($3->temp_name)==mp_param.end()){
                            emit(qid(">>",NULL),qid("*("+mp_param["this"]+"+"+offs.first+")",NULL),qid($3->temp_name,NULL),tmp,-1);
                        }
                        else
                            emit(qid(">>",NULL),qid("*("+mp_param["this"]+"+"+offs.first+")",NULL),qid(mp_param[$3->temp_name],NULL),tmp,-1);
                        
                        if(mp_param.find($3->temp_name)==mp_param.end()){
                            emit(qid("=",NULL),tmp,qid("",NULL),qid("*("+mp_param["this"]+"+"+offs.first+")",NULL),-1);
                        }
                        else
                            emit(qid("=",NULL),tmp,qid("",NULL),qid("*("+mp_param["this"]+"+"+offs.first+")",NULL),-1);
                    }
                    else if(*$2==">>>="){
                        qid offs=newtemp("int");
                        qid tmp=newtemp(t);
                        emit(qid("=",NULL),qid(to_string(getOffset(cur_class,second)),NULL),qid("",NULL),offs,-1);
                        if(mp_param.find($3->temp_name)==mp_param.end()){
                            emit(qid(">>>",NULL),qid("*("+mp_param["this"]+"+"+offs.first+")",NULL),qid($3->temp_name,NULL),tmp,-1);
                        }
                        else
                            emit(qid(">>>",NULL),qid("*("+mp_param["this"]+"+"+offs.first+")",NULL),qid(mp_param[$3->temp_name],NULL),tmp,-1);
                        
                        if(mp_param.find($3->temp_name)==mp_param.end()){
                            emit(qid("=",NULL),tmp,qid("",NULL),qid("*("+mp_param["this"]+"+"+offs.first+")",NULL),-1);
                        }
                        else
                            emit(qid("=",NULL),tmp,qid("",NULL),qid("*("+mp_param["this"]+"+"+offs.first+")",NULL),-1);
                    }
                    else if(*$2=="&="){
                        qid offs=newtemp("int");
                        qid tmp=newtemp(t);
                        emit(qid("=",NULL),qid(to_string(getOffset(cur_class,second)),NULL),qid("",NULL),offs,-1);
                        if(mp_param.find($3->temp_name)==mp_param.end()){
                            emit(qid("&",NULL),qid("*("+mp_param["this"]+"+"+offs.first+")",NULL),qid($3->temp_name,NULL),tmp,-1);
                        }
                        else
                            emit(qid("&",NULL),qid("*("+mp_param["this"]+"+"+offs.first+")",NULL),qid(mp_param[$3->temp_name],NULL),tmp,-1);
                        
                        if(mp_param.find($3->temp_name)==mp_param.end()){
                            emit(qid("=",NULL),tmp,qid("",NULL),qid("*("+mp_param["this"]+"+"+offs.first+")",NULL),-1);
                        }
                        else
                            emit(qid("=",NULL),tmp,qid("",NULL),qid("*("+mp_param["this"]+"+"+offs.first+")",NULL),-1);
                    }
                    else if(*$2=="^="){
                        qid offs=newtemp("int");
                        qid tmp=newtemp(t);
                        emit(qid("=",NULL),qid(to_string(getOffset(cur_class,second)),NULL),qid("",NULL),offs,-1);
                        if(mp_param.find($3->temp_name)==mp_param.end()){
                            emit(qid("^",NULL),qid("*("+mp_param["this"]+"+"+offs.first+")",NULL),qid($3->temp_name,NULL),tmp,-1);
                        }
                        else
                            emit(qid("^",NULL),qid("*("+mp_param["this"]+"+"+offs.first+")",NULL),qid(mp_param[$3->temp_name],NULL),tmp,-1);
                        
                        if(mp_param.find($3->temp_name)==mp_param.end()){
                            emit(qid("=",NULL),tmp,qid("",NULL),qid("*("+mp_param["this"]+"+"+offs.first+")",NULL),-1);
                        }
                        else
                            emit(qid("=",NULL),tmp,qid("",NULL),qid("*("+mp_param["this"]+"+"+offs.first+")",NULL),-1);
                    }
                    else if(*$2=="|="){
                        qid offs=newtemp("int");
                        qid tmp=newtemp(t);
                        emit(qid("=",NULL),qid(to_string(getOffset(cur_class,second)),NULL),qid("",NULL),offs,-1);
                        if(mp_param.find($3->temp_name)==mp_param.end()){
                            emit(qid("|",NULL),qid("*("+mp_param["this"]+"+"+offs.first+")",NULL),qid($3->temp_name,NULL),tmp,-1);
                        }
                        else
                            emit(qid("|",NULL),qid("*("+mp_param["this"]+"+"+offs.first+")",NULL),qid(mp_param[$3->temp_name],NULL),tmp,-1);
                        
                        if(mp_param.find($3->temp_name)==mp_param.end()){
                            emit(qid("=",NULL),tmp,qid("",NULL),qid("*("+mp_param["this"]+"+"+offs.first+")",NULL),-1);
                        }
                        else
                            emit(qid("=",NULL),tmp,qid("",NULL),qid("*("+mp_param["this"]+"+"+offs.first+")",NULL),-1);
                    }
                }
                else{

                    qid temp=newtemp($1->type);
                    if(*$2=="="){
                        $$->addr=$1->addr;
                        qid tmp=newtemp($1->type);
                        if($3->expType==4)
                            emit(qid("=",NULL),qid(t+" "+to_string($3->intVal),NULL),qid("",NULL),tmp,-1);
                        else{
                            qid change=$3->addr;
                            string ans=add+" "+change.first;
                            emit(qid("=",NULL),qid(ans,NULL),qid("",NULL),tmp,-1);
                        }
                        emit(qid("=",NULL),tmp,qid("",NULL),$1->addr,-1); 
                    }
                    else if(*$2=="*="){
                        if($3->expType==4)
                            emit(qid("*",NULL),qid(to_string($3->intVal),NULL),$1->addr,temp,-1);
                        else
                            emit(qid("*",NULL),$1->addr,$3->addr,temp,-1);
                        $1->addr=temp;
                    }
                    else if(*$2=="/="){
                        if($3->expType==4)
                            emit(qid("/",NULL),$1->addr,qid(to_string($3->intVal),NULL),temp,-1);
                        else
                            emit(qid("/",NULL),$1->addr,$3->addr,temp,-1);
                        $1->addr=temp;
                    }
                    else if(*$2=="%="){
                        if($3->expType==4)
                            emit(qid("%",NULL),$1->addr,qid(to_string($3->intVal),NULL),temp,-1);
                        else
                            emit(qid("%",NULL),$1->addr,$3->addr,temp,-1);
                        $1->addr=temp;
                    }
                    else if(*$2=="+="){
                        if($3->expType==4)
                            emit(qid("+",NULL),$1->addr,qid(to_string($3->intVal),NULL),temp,-1);
                        else
                            emit(qid("+",NULL),$1->addr,$3->addr,temp,-1);
                        $1->addr=temp;
                    }
                    else if(*$2=="-="){
                        if($3->expType==4)
                            emit(qid("-",NULL),$1->addr,qid(to_string($3->intVal),NULL),temp,-1);
                        else
                            emit(qid("-",NULL),$1->addr,$3->addr,temp,-1);
                        $1->addr=temp;
                    }
                    else if(*$2=="<<="){
                        if($3->expType==4)
                            emit(qid("<<",NULL),$1->addr,qid(to_string($3->intVal),NULL),temp,-1);
                        else
                            emit(qid("<<",NULL),$1->addr,$3->addr,temp,-1);
                        $1->addr=temp;
                    }
                    else if(*$2==">>="){
                        if($3->expType==4)
                            emit(qid(">>",NULL),$1->addr,qid(to_string($3->intVal),NULL),temp,-1);
                        else
                            emit(qid(">>",NULL),$1->addr,$3->addr,temp,-1);
                        $1->addr=temp;
                    }
                    else if(*$2==">>>="){
                        if($3->expType==4)
                            emit(qid(">>>",NULL),$1->addr,qid(to_string($3->intVal),NULL),temp,-1);
                        else
                            emit(qid(">>>",NULL),$1->addr,$3->addr,temp,-1);
                        $1->addr=temp;
                    }
                    else if(*$2=="&="){
                        if($3->expType==4)
                            emit(qid("&",NULL),$1->addr,qid(to_string($3->intVal),NULL),temp,-1);
                        else
                            emit(qid("&",NULL),$1->addr,$3->addr,temp,-1);
                        $1->addr=temp;
                    }
                    else if(*$2=="^="){
                        if($3->expType==4)
                            emit(qid("^",NULL),$1->addr,qid(to_string($3->intVal),NULL),temp,-1);
                        else
                            emit(qid("^",NULL),$1->addr,$3->addr,temp,-1);
                        $1->addr=temp;
                    }
                    else if(*$2=="|="){
                        if($3->expType==4)
                            emit(qid("|",NULL),$1->addr,qid(to_string($3->intVal),NULL),temp,-1);
                        else
                            emit(qid("|",NULL),$1->addr,$3->addr,temp,-1);
                        $1->addr=temp;
                    }
                    qid tmp2=newtemp($1->type);
                    emit(qid("=",NULL),temp,qid("",NULL),temp,-1);
                    $$->addr=$1->addr;
                }
            }
            else{
                yyerror(("Incompatible Types for "+ *$2).c_str());
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
                //3ac
                string add="";
                qid cast=newtemp(t);
                int flag=0;
                if($3->type!=t){
                    emit(qid("=",NULL),qid("cast_to_"+t+" "+$3->temp_name,NULL),qid("",NULL),cast,-1);
                    add=t;
                    flag=1;
                }

                if($1->temp_name.substr(0,5)=="this."){
                    $$->addr=$1->addr;
                    string second=$1->temp_name.substr(5,$1->temp_name.size()-5);
                    qid offs=newtemp("int");
                    emit(qid("=",NULL),qid(to_string(getOffset(cur_class,second)),NULL),qid("",NULL),offs,-1);
                    if(mp_param.find($3->temp_name)==mp_param.end()){
                        emit(qid("=",NULL),qid($3->temp_name,NULL),qid("",NULL),qid("*("+mp_param["this"]+"+"+offs.first+")",NULL),-1);
                    }
                    else
                        emit(qid("=",NULL),qid(mp_param[$3->temp_name],NULL),qid("",NULL),qid("*("+mp_param["this"]+"+"+offs.first+")",NULL),-1);
                }
                else{
                    $$->addr=$1->addr;
                    qid tmp=newtemp(t);
                    if($3->expType==4){
                        if(isInt($3->type))emit(qid("=",NULL),qid(to_string($3->intVal),NULL),qid("",NULL),tmp,-1);
                        else if(isFloat($3->type))emit(qid("=",NULL),qid(to_string($3->realVal),NULL),qid("",NULL),tmp,-1);
                    }
                    else{
                        if(flag){

                            emit(qid("=",NULL),cast,qid("",NULL),tmp,-1);
                        }
                        // else emit(qid("=",NULL),$3->addr,qid("",NULL),tmp,-1);
                    }
                    emit(qid("=",NULL),$3->addr,qid("",NULL),$1->addr,-1);
                }
            }
            else{
                yyerror("Incompatible Types for =");
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
        vector<ASTNode*> s;
        s.push_back($1);
        s.push_back($4);
        $$ = makeNode("||", s);


        string temp=condExp($1->type,$4->type,"","||");
        if(!$1->is_error && !$4->is_error){
            if(!temp.empty()){
                $$->type=temp;
                string add="";
                int flag=0;
                qid cast=newtemp(temp);
                if($4->type!=temp){
                    if($4->expType==4){
                        if($4->type=="int")emit(qid("=",NULL),qid("cast_to_"+temp+" "+to_string($4->intVal),NULL),qid("",NULL),cast,-1);
                        else if($4->type=="float")emit(qid("=",NULL),qid("cast_to_"+temp+" "+to_string($4->realVal),NULL),qid("",NULL),cast,-1);
                    }
                    else emit(qid("=",NULL),qid("cast_to_"+temp+" "+$4->temp_name,NULL),qid("",NULL),cast,-1);
                    add=temp;
                    flag=1;
                }
                if($1->type!=temp){
                    if($1->expType==4){
                        if($1->type=="int")emit(qid("=",NULL),qid("cast_to_"+temp+" "+to_string($1->intVal),NULL),qid("",NULL),cast,-1);
                        else if($1->type=="float")emit(qid("=",NULL),qid("cast_to_"+temp+" "+to_string($1->realVal),NULL),qid("",NULL),cast,-1);
                    }
                    else emit(qid("=",NULL),qid("cast_to_"+temp+" "+$1->temp_name,NULL),qid("",NULL),cast,-1);
                    add=temp;
                    flag=1;
                }
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
    }
;

MarkerNT:
      {$$=nextinstr()+1;} //check if -1 or not
;

ConditionalAndExpression:
    InclusiveOrExpression   {
        $$ = $1;
    }
    | ConditionalAndExpression CONDAND MarkerNT InclusiveOrExpression        {
        vector<ASTNode*> s;
        s.push_back($1);
        s.push_back($4);
        $$ = makeNode("&&", s);

        string temp=condExp($1->type,$4->type,"","&&");
        if(!$1->is_error && !$4->is_error){
            if(!temp.empty()){
                $$->type=temp;
                string add="";
                int flag=0;
                qid cast=newtemp(temp);
                if($4->type!=temp){
                    if($4->expType==4){
                        if($4->type=="int")emit(qid("=",NULL),qid("cast_to_"+temp+" "+to_string($4->intVal),NULL),qid("",NULL),cast,-1);
                        else if($4->type=="float")emit(qid("=",NULL),qid("cast_to_"+temp+" "+to_string($4->realVal),NULL),qid("",NULL),cast,-1);
                    }
                    else emit(qid("=",NULL),qid("cast_to_"+temp+" "+$4->temp_name,NULL),qid("",NULL),cast,-1);
                    add=temp;
                    flag=1;
                }
                if($1->type!=temp){
                    if($1->expType==4){
                        if($1->type=="int")emit(qid("=",NULL),qid("cast_to_"+temp+" "+to_string($1->intVal),NULL),qid("",NULL),cast,-1);
                        else if($1->type=="float")emit(qid("=",NULL),qid("cast_to_"+temp+" "+to_string($1->realVal),NULL),qid("",NULL),cast,-1);
                    }
                    else emit(qid("=",NULL),qid("cast_to_"+temp+" "+$1->temp_name,NULL),qid("",NULL),cast,-1);
                    add=temp;
                    flag=1;
                }
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

        $$->intVal= $1->intVal&$3->intVal;

        string temp=bitExp($1->type,$3->type);
        if(!$1->is_error && !$3->is_error){
            if(!temp.empty()){
                $$->type=temp;
                string add="";
                int flag=0;
                qid cast=newtemp(temp);
                if($3->type!=temp){
                    if($3->expType==4){
                        if(isInt($3->type))emit(qid("=",NULL),qid("cast_to_"+temp+" "+to_string($3->intVal),NULL),qid("",NULL),cast,-1);
                        else if(isFloat($3->type))emit(qid("=",NULL),qid("cast_to_"+temp+" "+to_string($3->realVal),NULL),qid("",NULL),cast,-1);
                    }
                    else emit(qid("=",NULL),qid("cast_to_"+temp+" "+$3->temp_name,NULL),qid("",NULL),cast,-1);
                    add=temp;
                    flag=1;
                }
                if($1->type!=temp){
                    if($1->expType==4){
                        if($1->type=="int")emit(qid("=",NULL),qid("cast_to_"+temp+" "+to_string($1->intVal),NULL),qid("",NULL),cast,-1);
                        else if($1->type=="float")emit(qid("=",NULL),qid("cast_to_"+temp+" "+to_string($1->realVal),NULL),qid("",NULL),cast,-1);
                    }
                    else emit(qid("=",NULL),qid("cast_to_"+temp+" "+$1->temp_name,NULL),qid("",NULL),cast,-1);
                    add=temp;
                    flag=1;
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

        $$->intVal= $1->intVal^$3->intVal;

        string temp=bitExp($1->type,$3->type);
        if(!$1->is_error && !$3->is_error){
            if(!temp.empty()){
                $$->type=temp;
                string add="";
                int flag=0;
                qid tmp=newtemp(temp);
                if($1->expType==4 && $3->expType==4){
                    emit(qid("^",NULL),qid(to_string($1->intVal),NULL),qid(to_string($3->intVal),NULL),tmp,-1);
                }
                else if($3->expType==4){
                    emit(qid("^",NULL),$1->addr,qid(to_string($3->intVal),NULL),tmp,-1);
                }
                else if($1->expType==4){
                    emit(qid("^",NULL),qid(to_string($1->intVal),NULL),$3->addr,tmp,-1);
                }
                else emit(qid("^",NULL),$1->addr,$3->addr,tmp,-1);
                $$->addr=tmp;
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

        $$->intVal= $1->intVal|$3->intVal;

        string temp=bitExp($1->type,$3->type);
        if(!$1->is_error && !$3->is_error){
            if(!temp.empty()){
                $$->type=temp;
                 string add="";
                int flag=0;
                qid cast=newtemp(temp);
                if($3->type!=temp){
                    if($3->expType==4){
                        if(isInt($3->type))emit(qid("=",NULL),qid("cast_to_"+temp+" "+to_string($3->intVal),NULL),qid("",NULL),cast,-1);
                        else if(isFloat($3->type))emit(qid("=",NULL),qid("cast_to_"+temp+" "+to_string($3->realVal),NULL),qid("",NULL),cast,-1);
                    }
                    else emit(qid("=",NULL),qid("cast_to_"+temp+" "+$3->temp_name,NULL),qid("",NULL),cast,-1);
                    add=temp;
                    flag=1;
                }
                if($1->type!=temp){
                    if($1->expType==4){
                        if($1->type=="int")emit(qid("=",NULL),qid("cast_to_"+temp+" "+to_string($1->intVal),NULL),qid("",NULL),cast,-1);
                        else if($1->type=="float")emit(qid("=",NULL),qid("cast_to_"+temp+" "+to_string($1->realVal),NULL),qid("",NULL),cast,-1);
                    }
                    else emit(qid("=",NULL),qid("cast_to_"+temp+" "+$1->temp_name,NULL),qid("",NULL),cast,-1);
                    add=temp;
                    flag=1;
                }
                qid tmp=newtemp(temp);
                if($1->expType==4 && $3->expType==4){
                        emit(qid("|",NULL),qid(to_string($1->intVal),NULL),qid(to_string($3->intVal),NULL),tmp,-1);
                }
                else if($3->expType==4){
                    emit(qid("|",NULL),$1->addr,qid(to_string($3->intVal),NULL),tmp,-1);
                }
                else if($1->expType==4){
                    emit(qid("|",NULL),qid(to_string($1->intVal),NULL),$3->addr,tmp,-1);
                }
                else emit(qid("|",NULL),$1->addr,$3->addr,tmp,-1);
                $$->addr=tmp;

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

        if(*$2=="=="){
            $$->intVal= $1->intVal==$3->intVal;
        }
        else{
            $$->intVal= $1->intVal!=$3->intVal;
        }
        string temp=eqExp($1->type,$3->type);
        if(!$1->is_error && !$3->is_error){
            if(!temp.empty()){
                if($3->expType==4){
                    $$->type=temp;
                    qid no=newtemp(temp);
                    if(isInt($3->type))emit(qid("=",NULL),qid(to_string($3->intVal),NULL),qid("",NULL),no,-1);
                    else if(isFloat($3->type))emit(qid("=",NULL),qid(to_string($3->realVal),NULL),qid("",NULL),no,-1);
                    $3->addr=no;
                }
                //3ac
                qid tmp=newtemp(temp);
                $$->addr=tmp;
                if(*$2=="=="){
                    // emit(qid("==boolean",NULL),$1->addr,$3->addr,tmp,-1);

                    if($1->expType==4 && $3->expType==4){
                        emit(qid("==",NULL),qid(to_string($1->intVal),NULL),qid(to_string($3->intVal),NULL),tmp,-1);
                    }
                    else if($3->expType==4){
                        emit(qid("==",NULL),$1->addr,qid(to_string($3->intVal),NULL),tmp,-1);
                    }
                    else if($1->expType==4){
                        emit(qid("==",NULL),qid(to_string($1->intVal),NULL),$3->addr,tmp,-1);
                    }
                    else emit(qid("==",NULL),$1->addr,$3->addr,tmp,-1);
                    $$->addr=tmp;
                    }
                else{
                    // emit(qid("!=boolean",NULL),$1->addr,$3->addr,tmp,-1);
                    if($1->expType==4 && $3->expType==4){
                        emit(qid("!=",NULL),qid(to_string($1->intVal),NULL),qid(to_string($3->intVal),NULL),tmp,-1);
                    }
                    else if($3->expType==4){
                        emit(qid("!=",NULL),$1->addr,qid(to_string($3->intVal),NULL),tmp,-1);
                    }
                    else if($1->expType==4){
                        emit(qid("!=",NULL),qid(to_string($1->intVal),NULL),$3->addr,tmp,-1);
                    }
                    else emit(qid("!=",NULL),$1->addr,$3->addr,tmp,-1);
                    $$->addr=tmp;
                }
                $$->truelist.push_back(nextinstr()); // check if -1 or not
                $$->falselist.push_back(nextinstr()+1);
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

        if(*$2=="<"){
            $$->intVal= $1->intVal<$3->intVal;
        }
        else if(*$2==">"){
            $$->intVal= $1->intVal>$3->intVal;
        }
        else if(*$2=="<="){
            $$->intVal= $1->intVal<=$3->intVal;
        }
        else{
            $$->intVal= $1->intVal>=$1->intVal;
        }
        string temp=relExp($1->type,$3->type);
        if(!$1->is_error && !$3->is_error){
            if(!temp.empty()){
                $$->type=temp;
                string add="";

                //3ac
                qid tmp=newtemp(temp);

                if($1->expType==4 && $3->expType==4){
                    emit(qid(*$2,NULL),qid(to_string($1->intVal),NULL),qid(to_string($3->intVal),NULL),tmp,-1);
                }
                else if($3->expType==4){
                    emit(qid(*$2,NULL),$1->addr,qid(to_string($3->intVal),NULL),tmp,-1);
                }
                else if($1->expType==4){
                    emit(qid(*$2,NULL),qid(to_string($1->intVal),NULL),$3->addr,tmp,-1);
                }
                else emit(qid(*$2,NULL),$1->addr,$3->addr,tmp,-1);
                $$->addr=tmp;
                $$->truelist.push_back(nextinstr()); // check if -1 or not
                $$->falselist.push_back(nextinstr()+1);
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

        if(*$2=="<<"){
            $$->intVal= $1->intVal<<$3->intVal;
        }
        else if(*$2==">>"){
            $$->intVal= $1->intVal>>$3->intVal;
        }


        string temp=shiftExp($1->type,$3->type);
        if(!$1->is_error && !$3->is_error){
            if(!temp.empty()){
                $$->type=temp;
                string add="";
                //3ac
                qid tmp=newtemp(temp);
                if($1->expType==4 && $3->expType==4){
                        emit(qid(*$2,NULL),qid(to_string($1->intVal),NULL),qid(to_string($3->intVal),NULL),tmp,-1);
                }
                else if($3->expType==4){
                    emit(qid(*$2,NULL),$1->addr,qid(to_string($3->intVal),NULL),tmp,-1);
                }
                else if($1->expType==4){
                    emit(qid(*$2,NULL),qid(to_string($1->intVal),NULL),$3->addr,tmp,-1);
                }
                else emit(qid(*$2,NULL),$1->addr,$3->addr,tmp,-1);
                $$->addr=tmp;
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

        if(*$2=="+"){
        $$->intVal=$1->intVal+$3->intVal;
        $$->realVal=$1->realVal+$3->realVal;
        }
        else{
            $$->intVal=$1->intVal-$3->intVal;
            $$->realVal=$1->realVal-$3->realVal;
        }

        string temp=addExp($1->type,$3->type);
        if(!$1->is_error && !$3->is_error){
            if(inPrint){
                $$->type = "String";
                string add="";
                int flag=0;
                qid cast=newtemp("String");
                if($1->type!="String"){
                    if($1->expType==4){
                        if(isInt($1->type))emit(qid("=",NULL),qid("cast_to_String "+to_string($1->intVal),NULL),qid("",NULL),cast,-1);
                        else if(isFloat($1->type))emit(qid("=",NULL),qid("cast_to_String "+to_string($1->realVal),NULL),qid("",NULL),cast,-1);
                    }
                    else emit(qid("=",NULL),qid("cast_to_String "+$1->temp_name,NULL),qid("",NULL),cast,-1);
                    flag=1;
                }
                if($3->type!="String"){
                    if($3->expType==4){
                        if(isInt($3->type))emit(qid("=",NULL),qid("cast_to_String "+to_string($3->intVal),NULL),qid("",NULL),cast,-1);
                        else if(isFloat($3->type))emit(qid("=",NULL),qid("cast_to_String "+to_string($3->realVal),NULL),qid("",NULL),cast,-1);
                    }
                    else emit(qid("=",NULL),qid("cast_to_String "+$3->temp_name,NULL),qid("",NULL),cast,-1);
                    flag=1;
                }
                
                 //3ac
                qid tmp=newtemp("String");
                $$->addr=tmp;

                if(flag){
                    emit(qid(*$2+"String",NULL),$1->addr,cast,tmp,-1);
                }
                else{
                    if($1->expType==4 && $3->expType==4){
                            emit(qid(*$2,NULL),qid(to_string($1->intVal),NULL),qid(to_string($3->intVal),NULL),tmp,-1);
                    }
                    else if($3->expType==4){
                        emit(qid(*$2,NULL),$1->addr,qid(to_string($3->intVal),NULL),tmp,-1);
                    }
                    else if($1->expType==4){
                        emit(qid(*$2,NULL),qid(to_string($1->intVal),NULL),$3->addr,tmp,-1);
                    }
                    else emit(qid(*$2,NULL),$1->addr,$3->addr,tmp,-1);
                    $$->addr=tmp;
                }
            }
            else if(!temp.empty()){
                $$->type=temp;
                string add="";
                int flag=0;
                qid cast=newtemp(temp);
                if($3->type!=temp){
                    if($3->expType==4){
                        if(isInt($3->type))emit(qid("=",NULL),qid("cast_to_"+temp+" "+to_string($3->intVal),NULL),qid("",NULL),cast,-1);
                        else if(isFloat($3->type))emit(qid("=",NULL),qid("cast_to_"+temp+" "+to_string($3->realVal),NULL),qid("",NULL),cast,-1);
                    }
                    else emit(qid("=",NULL),qid("cast_to_"+temp+" "+$3->temp_name,NULL),qid("",NULL),cast,-1);
                    add=temp;
                    flag=1;
                }
                if($1->type!=temp){
                    if($1->expType==4){
                        if($1->type=="int")emit(qid("=",NULL),qid("cast_to_"+temp+" "+to_string($1->intVal),NULL),qid("",NULL),cast,-1);
                        else if($1->type=="float")emit(qid("=",NULL),qid("cast_to_"+temp+" "+to_string($1->realVal),NULL),qid("",NULL),cast,-1);
                    }
                    else emit(qid("=",NULL),qid("cast_to_"+temp+" "+$1->temp_name,NULL),qid("",NULL),cast,-1);
                    add=temp;
                    flag=1;
                }
                 //3ac
                qid tmp=newtemp(temp);
                $$->addr=tmp;
                if(flag){
                    string add=temp;
                    emit(qid(*$2+add,NULL),$1->addr,cast,tmp,-1);
                }
                else{
                    if($1->expType==4 && $3->expType==4){
                         emit(qid(*$2,NULL),qid(to_string($1->intVal),NULL),qid(to_string($3->intVal),NULL),tmp,-1);
                    }
                    else if($3->expType==4){
                        emit(qid(*$2,NULL),$1->addr,qid(to_string($3->intVal),NULL),tmp,-1);
                    }
                    else if($1->expType==4){
                        emit(qid(*$2,NULL),qid(to_string($1->intVal),NULL),$3->addr,tmp,-1);
                    }
                    else emit(qid(*$2,NULL),$1->addr,$3->addr,tmp,-1);
                }
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

        if(*$2=="/"){
        if($3->intVal)$$->intVal=$1->intVal/$3->intVal;
        if($3->realVal)$$->realVal=$1->realVal/$3->realVal;}
        else{
            // $$->intVal=$1->intVal%$3->intVal;
        }

        string temp=mulExp($1->type,$3->type);
        if(!$1->is_error && !$3->is_error){
            if(!temp.empty()){
                $$->type=temp;
                string add="";
                int flag=0;
                qid cast=newtemp(temp);
                if($3->type!=temp){
                    if($3->expType==4){
                        if(isInt($3->type))emit(qid("=",NULL),qid("cast_to_"+temp+" "+to_string($3->intVal),NULL),qid("",NULL),cast,-1);
                        else if(isFloat($3->type))emit(qid("=",NULL),qid("cast_to_"+temp+" "+to_string($3->realVal),NULL),qid("",NULL),cast,-1);
                    }
                    else emit(qid("=",NULL),qid("cast_to_"+temp+" "+$3->temp_name,NULL),qid("",NULL),cast,-1);
                    add=temp;
                    flag=1;
                }
                if($1->type!=temp){
                    if($1->expType==4){
                        if($1->type=="int")emit(qid("=",NULL),qid("cast_to_"+temp+" "+to_string($1->intVal),NULL),qid("",NULL),cast,-1);
                        else if($1->type=="float")emit(qid("=",NULL),qid("cast_to_"+temp+" "+to_string($1->realVal),NULL),qid("",NULL),cast,-1);
                    }
                    else emit(qid("=",NULL),qid("cast_to_"+temp+" "+$1->temp_name,NULL),qid("",NULL),cast,-1);
                    add=temp;
                    flag=1;
                }

                //3ac
                qid tmp=newtemp(temp);
                $$->addr=tmp;

                if(flag){
                    string add=temp;
                    emit(qid(*$2+add,NULL),$1->addr,cast,tmp,-1);
                    }
                else{
                    if($1->expType==4 && $3->expType==4){
                        emit(qid(*$2,NULL),qid(to_string($1->intVal),NULL),qid(to_string($3->intVal),NULL),tmp,-1);
                    }
                    else if($3->expType==4){
                        emit(qid(*$2,NULL),$1->addr,qid(to_string($3->intVal),NULL),tmp,-1);
                    }
                    else if($1->expType==4){
                        emit(qid(*$2,NULL),qid(to_string($1->intVal),NULL),$3->addr,tmp,-1);
                    }
                    else emit(qid(*$2,NULL),$1->addr,$3->addr,tmp,-1);
                }
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
        
        $$->intVal=$1->intVal*$3->intVal;
        $$->realVal=$1->realVal*$3->realVal;

        string temp=mulExp($1->type,$3->type);
        if(!$1->is_error && !$3->is_error){
            if(!temp.empty()){
                $$->type=temp;
                string add="";
                int flag=0;
                qid cast=newtemp(temp);
                if($3->type!=temp){
                    if($3->expType==4){
                        if(isInt($3->type))emit(qid("=",NULL),qid("cast_to_"+temp+" "+to_string($3->intVal),NULL),qid("",NULL),cast,-1);
                        else if(isFloat($3->type))emit(qid("=",NULL),qid("cast_to_"+temp+" "+to_string($3->realVal),NULL),qid("",NULL),cast,-1);
                    }
                    else emit(qid("=",NULL),qid("cast_to_"+temp+" "+$3->temp_name,NULL),qid("",NULL),cast,-1);
                    add=temp;
                    flag=1;
                }
                if($1->type!=temp){
                    if($1->expType==4){
                        if($1->type=="int")emit(qid("=",NULL),qid("cast_to_"+temp+" "+to_string($1->intVal),NULL),qid("",NULL),cast,-1);
                        else if($1->type=="float")emit(qid("=",NULL),qid("cast_to_"+temp+" "+to_string($1->realVal),NULL),qid("",NULL),cast,-1);
                    }
                    else emit(qid("=",NULL),qid("cast_to_"+temp+" "+$1->temp_name,NULL),qid("",NULL),cast,-1);
                    add=temp;
                    flag=1;
                }

                //3ac
                qid tmp=newtemp(temp);
                $$->addr=tmp;

                if(flag){
                    string add=temp;
                        emit(qid("*"+add,NULL),$1->addr,cast,tmp,-1);
                    }
                else{
                    if($1->expType==4 && $3->expType==4){
                         emit(qid("*",NULL),qid(to_string($1->intVal),NULL),qid(to_string($3->intVal),NULL),tmp,-1);
                    }
                    else if($3->expType==4){
                        emit(qid("*",NULL),$1->addr,qid(to_string($3->intVal),NULL),tmp,-1);
                    }
                    else if($1->expType==4){
                        emit(qid("*",NULL),qid(to_string($1->intVal),NULL),$3->addr,tmp,-1);
                    }
                    else emit(qid("*",NULL),$1->addr,$3->addr,tmp,-1);
                }
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
                    $$->addr=$2->addr;
                    emit(qid("++P",NULL),$2->addr,qid("",NULL),qid("",NULL),-1);
                }
                else{
                    $$->intVal = $2->intVal -1;
                    
                    //3ac
                    $$->addr=$2->addr;
                    emit(qid("--P",NULL),$2->addr,qid("",NULL),qid("",NULL),-1);
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
                
                if(*$1=="-"){ 
                    $$->intVal = - ($2->intVal);

                    //3ac
                    qid tmp=newtemp(temp);
                    $$->addr=tmp;
                    emit(qid("-U",NULL),$2->addr,qid("",NULL),tmp,-1);

                }
                else{ 
                    $$->intVal = $2->intVal;
                    //3ac
                    qid tmp=newtemp(temp);
                    $$->addr=tmp;
                    emit(qid("+U",NULL),$2->addr,qid("",NULL),tmp,-1);
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
            
                //3ac
                qid tmp=newtemp(temp);
                $$->addr=tmp;
                emit(qid(*$1,NULL),$2->addr,qid("",NULL),tmp,-1);
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
            //3ac
            qid cast=newtemp($2->type);
            if($4->expType==4){
                if($4->type=="int")emit(qid("=",NULL),qid("cast_to_"+$2->type+" "+to_string($4->intVal),NULL),qid("",NULL),cast,-1);
                else if($4->type=="float")emit(qid("=",NULL),qid("cast_to_"+$2->type+" "+to_string($4->realVal),NULL),qid("",NULL),cast,-1);
            }
            else if($4->expType==5){
                emit(qid("=",NULL),qid("cast_to_"+$2->type+" "+$4->strVal,NULL),qid("",NULL),cast,-1);
            }
            else emit(qid("=",NULL),qid("cast_to_"+$2->type+" "+$4->temp_name,NULL),qid("",NULL),cast,-1);
            $$->addr=cast;
		}
		else{
			$$->is_error = 1;
		}
        	$$->type = $2->type;
            $4->type=$2->type;
    }
;

postfixExpression:
    Primary {
        $$ = $1;

        if($1->expType==5){
            qid tmp=newtemp("string");
            emit(qid("=",NULL),qid($1->strVal,NULL),qid("",NULL),tmp,-1);
            $$->addr=tmp;

        }

    }
    | IDENdotIDEN      {
        $$ = $1;
        if($1->temp_name.find('.') == string::npos){
            string temp = primaryExpression($1->temp_name);
            if(temp == ""){
                yyerror(("Undeclared Identifier " + $1->temp_name).c_str());
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
                    $$->temp_name = $1->temp_name; 
                    // $$->nextlist.clear();
                }
                else{
                    $$->type = temp;
                    $$->temp_name = $1->temp_name;
                    if(temp.back()=='*') $$->type = temp.substr(0,temp.size()-1);
                    
                    //3ac
                    if($1->expType==4){
                        qid tmp=newtemp("int");
                        emit(qid("=",NULL),qid(to_string($1->intVal),NULL),qid("",NULL),tmp,-1);
                        $$->addr=tmp;
                    }
                    else if($1->expType==5){
                        qid tmp=newtemp("string");
                        emit(qid("=",NULL),qid($1->strVal,NULL),qid("",NULL),tmp,-1);
                        $$->addr=tmp;
                    }

                }
            }
        }
        else{
            int pos = class_type.find(".");
            string sub = class_type.substr(0, pos);
            string first=sub;
            sub = primaryExpression(sub);
            
            string sub1 = class_type.substr(pos+1);
            string second=sub1;
            if(global_st.find(sub) == global_st.end()){
                yyerror(("Undefined class " + sub).c_str());
                $$->is_error = 1;
            }
            else{
                for(auto it: children_table[&global_st]){
                    if(it.first == sub){
                        if((*(it.second)).find(sub1) == (*(it.second)).end()){
                            yyerror(("Undefined member of class " + sub).c_str());
                            $$->is_error = 1;
                        }
                        else{
                            string tem = (*(it.second))[sub1]->type;
                            if(tem.substr(0, 5) == "FUNC_"){
                                $$->expType = 3;
                            }
                            else if((*(it.second))[sub1]->isArray){
                                $$->expType = 2; 
                            }
                            else $$->expType = 1;

                            if(tem.substr(0,5)=="FUNC_" ){
                                $$->type = tem;
                                $$->temp_name = $1->temp_name; 
                                // $$->nextlist.clear();
                            }
                            else{
                                $$->type = tem;
                                $$->temp_name = $1->temp_name;
                                if(tem.back()=='*') $$->type = tem.substr(0,tem.size()-1);
                                
                                //3ac
                                qid temp=newtemp($$->type);
                                emit(qid("+",NULL),qid("*("+first,NULL),qid(to_string(getOffset(sub,second))+")",NULL),temp,-1);
                                $$->addr=temp;
                                

                            }
                        }
                    }
                }
            }
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
                if(*$2 == "++"){
                    $$->intVal = $1->intVal + 1;

                    //3ac
                    $$->addr=$1->addr;
                    emit(qid("P++",NULL),$1->addr,qid("",NULL),qid("",NULL),-1);
                }
                else{
                    $$->intVal = $1->intVal -1;
                    
                    //3ac
                    $$->addr=$1->addr;
                    emit(qid("P--",NULL),$1->addr,qid("",NULL),qid("",NULL),-1);
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
    '{' CHANGE_TABLE BlockStatements '}' {
        $$=$3;
        if($3==NULL) $$=makeLeaf("Block",1);
        // printSymbolTable(cur_table, name);
        if(func_flag>=2){
            int bc = block_stack.top();
            block_stack.pop();
            string str = "Block" + to_string(bc);
            string name = funcName+str+".csv";
            printSymbolTable(cur_table, name);
            endSymbolTable(0);
            func_flag--;
        }
    }
;

BlockStatements:
    BlockStatements BlockStatement {
        vector<ASTNode*> s;
        s.push_back($1);
        s.push_back($2);
        $$ = makeNode("BlockStatements", s);
        
        if($1==NULL){
            $$->breaklist=$2->breaklist;
        }
        else
        $$->breaklist=mergelist($1->breaklist,$2->breaklist);
        if($1==NULL){
            $$->continuelist=$2->continuelist;
        }
        else
        $$->continuelist=mergelist($1->continuelist,$2->continuelist);

    }
    |       {
        $$=NULL;
        // $$ = makeLeaf("BlockStatements", 1);

    }
;

BlockStatement:
    LocalVariableDeclaration ';' {
        $$=$1;
        type="";
    }
    | Statement {
        $$=$1;
        //3ac
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

jumpstat:
    KEY_if '(' Expression ')' MarkerNT Statement {
        vector<ASTNode*> s;
        s.push_back($3);
        s.push_back($6);
        $$ = makeNode("if", s);
        //3ac
        backpatch($3->truelist,$5);
        $$->nextlist=mergelist($3->falselist,$6->nextlist);
        $$->breaklist=$6->breaklist;
        $$->continuelist=$6->continuelist;
        
        
    }
    | KEY_if '(' Expression ')' MarkerNT StatementNoShortIf MarkerNT2 KEY_else MarkerNT Statement {
        vector<ASTNode*> s,s1;
        s1.push_back($10);
        s.push_back($3);
        s.push_back($6);
        s.push_back(makeNode("else", s1));
        $$ = makeNode("if", s);

        //3ac
        backpatch($3->truelist, $5);
        backpatch($3->falselist, $9);
        auto tmp = mergelist($6->nextlist, $7->nextlist) ;
        $$->nextlist = mergelist(tmp, $10->nextlist);
        $$->continuelist=mergelist($6->continuelist,$10->continuelist);
        $$->breaklist=mergelist($6->breaklist,$10->breaklist);
        // $$->nextlist.clear();
    }
    | KEY_while MarkerNT '(' Expression ')' MarkerNT Statement {
        vector<ASTNode*> s;
        s.push_back($4);
        s.push_back($7);
        $$ = makeNode("while", s);

        //3ac
        $7->nextlist=mergelist($7->nextlist,$7->continuelist);
        backpatch($7->nextlist, $2) ;
        backpatch($4->truelist, $6) ;
        $$->nextlist = mergelist($4->falselist,$7->breaklist);
        emit(qid("goto",NULL),qid("",NULL),qid("",NULL),qid("",NULL),$2);
    }
    | ForStatement {
        $$=$1;
        int bc = block_stack.top();
        block_stack.pop();
        string str = "Block" + to_string(bc);
        string name = funcName+str+".csv";
        printSymbolTable(cur_table, name);
        endSymbolTable(0);
        for_flag=0;
        backpatch($$->nextlist,nextinstr()+1);
        $$->nextlist.clear();
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
    | jumpstat {
        backpatch($1->nextlist,nextinstr()+1);
        $1->nextlist.clear();
        $$=$1;
    }
;

MarkerNT2:
      {
        $$=makeLeaf("MarkerNT2",1);
        $$->nextlist.push_back(nextinstr()); //check if -1 or not
        emit(qid("goto",NULL),qid("",NULL),qid("",NULL),qid("",NULL),0);
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
    | KEY_if '(' Expression ')' MarkerNT StatementNoShortIf MarkerNT2 KEY_else MarkerNT StatementNoShortIf {
        vector<ASTNode*> s,s1;
        s1.push_back($10);
        s.push_back($3);
        s.push_back($6);
        s.push_back(makeNode("else", s1));
        $$ = makeNode("if", s);

        //3ac
        backpatch($3->truelist, $5);
        backpatch($3->falselist, $9) ;
        auto tmp = mergelist($6->nextlist, $7->nextlist) ;
        $$->nextlist = mergelist(tmp, $10->nextlist);
    }
    | KEY_while MarkerNT '(' Expression ')' MarkerNT StatementNoShortIf {
        vector<ASTNode*> s;
        s.push_back($4);
        s.push_back($7);
        $$ = makeNode("while", s);

        //3ac
        backpatch($7->nextlist, $2) ;
        backpatch($4->truelist, $6) ;
        $$->nextlist = $4->falselist;
        emit(qid("goto",NULL),qid("",NULL),qid("",NULL),qid("",NULL),$2);
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

        //3ac not done
    }
    | KEY_return ';' {
        $$ = makeLeaf("return");
        type="";

        //3ac
        emit(qid("return",NULL),qid("",NULL),qid("",NULL),qid("",NULL),-1);
    }
    | KEY_return Expression ';' {
        vector<ASTNode*> s;
        s.push_back($2);
        $$ = makeNode("return", s);
        type="";

        //3ac
        backpatch($2->nextlist,nextinstr());
        if($2->expType==4){
            emit(qid("RETURN",NULL),qid(to_string($2->intVal),NULL),qid("",NULL),qid("",NULL),-1);
        }
        emit(qid("RETURN", NULL), $2->addr, qid("", NULL), qid("", NULL), -1);
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

                if(*$1 == "++"){
                    $$->intVal = $2->intVal + 1;

                    //3ac
                    $$->addr=$2->addr;
                    emit(qid("++P",NULL),$2->addr,qid("",NULL),qid("",NULL),-1);
                }
                else{
                    $$->intVal = $2->intVal -1;
                    
                    //3ac
                    $$->addr=$2->addr;
                    emit(qid("--P",NULL),$2->addr,qid("",NULL),qid("",NULL),-1);
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
    | postfixExpression ADDOP2 {
        vector<ASTNode*> s;
        s.push_back($1);
        s.push_back(makeLeaf(*$2));
        $$ = makeNode("Statement Expression", s);

        if(!$1->is_error && $1->expType!=4){
			string temp = postfixExpression($1->type,2);
			if(!temp.empty()){
				$$->type = temp;

                if(*$2 == "++"){
                    $$->intVal = $1->intVal + 1;

                    //3ac
                    $$->addr=$1->addr;
                    emit(qid("P++",NULL),$1->addr,qid("",NULL),qid("",NULL),-1);
                }
                else{
                    $$->intVal = $1->intVal -1;
                    
                    //3ac
                    $$->addr=$1->addr;
                    emit(qid("P--",NULL),$1->addr,qid("",NULL),qid("",NULL),-1);
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
    /* | ClassInstanceCreationExpression */
;

LeftHandSide:
    IDENdotIDEN {
        $$=$1;
        if($1->temp_name.find('.') == string::npos){
            string temp = primaryExpression($1->temp_name);
            if(temp == ""){
                yyerror(("Undeclared Identifier " + $1->temp_name).c_str());
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
                    $$->temp_name = $1->temp_name; 
                    // $$->nextlist.clear();
                }
                else{
                    $$->type = temp;
                    $$->temp_name = $1->temp_name;
                    if(temp.back()=='*') $$->type = temp.substr(0,temp.size()-1);
                    
                    //3ac

                }
            }
        }
        else{
            int pos = $1->temp_name.find(".");
            string sub = $1->temp_name.substr(0, pos);
            sub = primaryExpression(sub);
            string sub1 = $1->temp_name.substr(pos+1);
            if(global_st.find(sub) == global_st.end()){
                yyerror(("Undefined class " + sub).c_str());
                $$->is_error = 1;
            }
            else{
                for(auto it: children_table[&global_st]){
                    if(it.first == sub){
                        if((*(it.second)).find(sub1) == (*(it.second)).end()){
                            yyerror(("Undefined member of class " + sub).c_str());
                            $$->is_error = 1;
                        }
                        else{
                            string tem = (*(it.second))[sub1]->type;
                            if(tem.substr(0, 5) == "FUNC_"){
                                $$->expType = 3;
                            }
                            else if((*(it.second))[sub1]->isArray){
                                $$->expType = 2; 
                            }
                            else $$->expType = 1;

                            if(tem.substr(0,5)=="FUNC_" ){
                                $$->type = tem;
                                $$->temp_name = $1->temp_name; 
                                // $$->nextlist.clear();
                            }
                            else{
                                $$->type = tem;
                                $$->temp_name = $1->temp_name;
                                if(tem.back()=='*') $$->type = tem.substr(0,tem.size()-1);
                                //--3AC
                                // $$->place = qid(string($1), lookup(string($1)));
                                // $$->nextlist.clear();

                            }
                        }
                    }
                }
            }
        }
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

        //3ac
        $$->breaklist.push_back(nextinstr());
        emit(qid("goto",NULL),qid("",NULL),qid("",NULL),qid("",NULL),0);
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

        //3ac
        $$->continuelist.push_back(nextinstr());
        emit(qid("goto",NULL),qid("",NULL),qid("",NULL),qid("",NULL),0);
    }
;
A:
    {
        for_flag=1;
        string str = "Block" +to_string(block_count);
        block_stack.push(block_count);
        block_count++;
        makeSymbolTable(str, "", yylineno, modifier,0);
    }    
;

ForStatementExpressionList:
    MarkerNT StatementExpressionList{
        $$ = $2;
        $$->intVal = $1;
    }
    | MarkerNT  {
        $$ = makeLeaf("ForExpressionlist",1);
        $$->intVal = $1;
    }
;

ForStatement:
    KEY_for '(' A ForInit ';' Expression  ';' ForStatementExpressionList MarkerNT2 ')' MarkerNT Statement {
        vector<ASTNode*> s;
        s.push_back($4);
        s.push_back($6);
        s.push_back($12);
        $$ = makeNode("for", s);

        //3ac
        $12->nextlist=mergelist($12->nextlist,$12->continuelist);
        backpatch($12->nextlist, $8->intVal);
        backpatch($6->truelist, $11);
        $$->nextlist = mergelist($6->falselist,$12->breaklist); 
        backpatch($9->nextlist,$4->intVal);

        emit(qid("goto",NULL),qid("",NULL),qid("",NULL),qid("",NULL),$4->intVal);
    }
    | KEY_for '(' A ForInit ';' ';' ForStatementExpressionList ')' MarkerNT Statement {
        vector<ASTNode*> s;
        s.push_back($4);
        s.push_back($7);
        s.push_back($10);
        $$ = makeNode("for", s);

        //3ac
        $10->nextlist=mergelist($10->nextlist,$10->continuelist);
        backpatch($10->nextlist, $7->intVal);
        $$->nextlist=$10->breaklist;

        emit(qid("goto",NULL),qid("",NULL),qid("",NULL),qid("",NULL),$9);

    }
    /* | KEY_for '(' LocalVariableDeclaration ':' Expression ')' Statement */
;

ForStatementNoShortIf:
    KEY_for '(' A ForInit ';' Expression  ';' ForStatementExpressionList MarkerNT2 ')' MarkerNT StatementNoShortIf {
        vector<ASTNode*> s;
        s.push_back($4);
        s.push_back($6);
        s.push_back($12);
        $$ = makeNode("for", s);

        //3ac

        $12->nextlist=mergelist($12->nextlist,$12->continuelist);
        backpatch($12->nextlist, $8->intVal);
        backpatch($6->truelist, $11);
        $$->nextlist = mergelist($6->falselist,$12->breaklist); 
        backpatch($9->nextlist,$4->intVal);

        emit(qid("goto",NULL),qid("",NULL),qid("",NULL),qid("",NULL),$4->intVal);

    }
    | KEY_for '(' A ForInit ';' ';' ForStatementExpressionList ')' MarkerNT StatementNoShortIf {
        vector<ASTNode*> s;
        s.push_back($4);
        s.push_back($7);
        s.push_back($10);
        $$ = makeNode("for", s);

        //3ac
        $10->nextlist=mergelist($10->nextlist,$10->continuelist);
        backpatch($10->nextlist, $7->intVal);
        $$->nextlist=$10->breaklist;

        emit(qid("goto",NULL),qid("",NULL),qid("",NULL),qid("",NULL),$9);

    }
;

ForInit:
    StatementExpressionList MarkerNT {
        $$ = $1;
        $$->intVal = $2;
        type="";
    }
    | LocalVariableDeclaration MarkerNT {
        $$ = $1;
        $$->intVal = $2;
        type="";
    }
    | MarkerNT {
        $$=makeLeaf("Forinit",1);
        $$->intVal = $1;
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
    Modifiers KEY_class IDENTIFIER{cur_class=*$3;} ClassBody {
        vector<ASTNode*> s;
        s.push_back($1);
        s.push_back(makeLeaf("ID (" + *$3+")" ));
        s.push_back($5);
        $$ = makeNode("class", s);
        string filename=*$3;
        printSymbolTable(cur_table,filename + ".csv");
        endSymbolTable(1);
        func_flag=0;
        cur_class="";
        modifier={1,0,0};
        delete $3;
    }
    | Modifiers KEY_class IDENTIFIER ClassExtends ClassBody {
        vector<ASTNode*> s;
        s.push_back($1);
        s.push_back(makeLeaf("ID (" + *$3+")" ));
        s.push_back($4);
        s.push_back($5);
        $$ = makeNode("class", s);
        modifier={1,0,0};
        delete $3;
    }
    | Modifiers KEY_class IDENTIFIER ClassPermits ClassBody {
        vector<ASTNode*> s;
        s.push_back($1);
        s.push_back(makeLeaf("ID (" + *$3+")" ));
        s.push_back($4);
        s.push_back($5);
        $$ = makeNode("class", s);
        modifier={1,0,0};
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
        modifier={1,0,0};
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
    '{' C ClassBodyDeclarations '}' {
        $$=$3;
        if($3==NULL) makeLeaf("ClassBody",1);
    }
;
CHANGE_TABLE:
     {
        if(!for_flag){
            if(func_flag){
                string str = "Block" +to_string(block_count);
                block_stack.push(block_count);
                block_count++;
                func_flag++;
                makeSymbolTable(str, "", yylineno, modifier,0);
            }
            else func_flag++;
        }
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
        modifier={1,0,0};
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
    | ConstructorDeclaration {
        $$=$1;
    }
    | MethodDeclaration {
        $$=$1;
    }
;

ConstructorIDEN:
    IDENTIFIER {
        $$ = makeLeaf("ID (" + *$1 +")");
        funcName =*$1;
        funcType = "Constructor";
        $$->temp_name = "Constructor" + *$1;
        inconst=true;

        //3ac
        qid tmp=newtemp(type);
        emit(qid("=",NULL),qid("popparam",NULL),qid("",NULL),tmp,-1);
        $$->addr=tmp;
        mp_param["this"]=tmp.first;

        delete $1;
    }
;

ConstructorDeclaration:
    Modifiers ConstructorIDEN F '(' formalparameters ')' Block {
        vector<ASTNode*> s;
        s.push_back($1);
        s.push_back($2);
        s.push_back($5);
        s.push_back($7);
        $$ = makeNode("ConstructorDeclaration", s);

        string str= $2->temp_name.substr(11);

        if(str!=cur_class){
            yyerror(("Constructor can only have the name "+cur_class).c_str());
            $$->is_error = 1;
        }
        else{
            printSymbolTable(cur_table ,$2->temp_name + ".csv");
            endSymbolTable(1);
            print3AC_code($2->temp_name, $5->size);
        }

        modifier={1,0,0};
        inconst=false;
        mp_param.clear();
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

        if(lookup(*$1) && !(inconst)){
				string errstr = *$1 + " is already declared";
				yyerror(errstr.c_str());
				$$->is_error = 1;            
        }
        else{
            insertSymbol(*cur_table, *$1, "IDENTIFIER", type, yylineno, NULL, modifier, getSize(type));
            $$->addr=qid(*$1,lookup(*$1));

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
        if($3!=NULL && $3->type!="int"){
            yyerror("Index of the array should be integer");
        }
        //
        if(lookup(*$1) && !inconst){
				string errstr = *$1 + " is already declared";
				yyerror(errstr.c_str());
				$$->is_error = 1;            
        }
        else{
            isArray=1;
            $$->expType = 2;
            if($3==NULL) array_dims.push_back(0);
            else array_dims.push_back($3->intVal);
            insertSymbol(*cur_table, *$1, "IDENTIFIER", type, yylineno, NULL, modifier, getSize(type)*array_dims[0]);
            
            //3ac!inconst
            $$->addr=qid(*$1,lookup(*$1));
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

        if(lookup(*$1) && !inconst){
				string errstr = *$1 + " is already declared";
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
            insertSymbol(*cur_table, *$1, "IDENTIFIER", type, yylineno, NULL, modifier, getSize(type)*array_dims[0]*array_dims[1]);

            //3ac
            $$->addr=qid(*$1,lookup(*$1));
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

        if(lookup(*$1) && !inconst){
				string errstr = *$1 + " is already declared";
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
            insertSymbol(*cur_table, *$1, "IDENTIFIER", type, yylineno, NULL, modifier, getSize(type)*array_dims[0]*array_dims[1]*array_dims[2]);

            //3ac
            $$->addr=qid(*$1,lookup(*$1));
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
        string t = assignExp(type, $3->type, "=");
        if(t==""){
            yyerror("Type Clashing");
            $$->is_error=1;
        }
        string add="";
        int flag=0;
        qid cast=newtemp(t);
        if($3->type!=t){
            if($3->expType==4){
                if(isInt($3->type))emit(qid("=",NULL),qid("cast_to_"+t+" "+to_string($3->intVal),NULL),qid("",NULL),cast,-1);
                else if(isFloat($3->type))emit(qid("=",NULL),qid("cast_to_"+t+" "+to_string($3->realVal),NULL),qid("",NULL),cast,-1);
            }
            else emit(qid("=",NULL),qid("cast_to_"+t+" "+$3->temp_name,NULL),qid("",NULL),cast,-1);
            add=t;
            flag=1;
        }
        if(lookup(*$1)){
				string errstr = *$1 + " is already declared";
				yyerror(errstr.c_str());
				$$->is_error = 1;            
        }
        else{
            insertSymbol(*cur_table,*$1, "IDENTIFIER", type, yylineno, NULL, modifier, getSize(type));

            //3ac
            $$->addr=qid(*$1,lookup(*$1));
            
            if($3->expType==4){
                qid tmp=newtemp($3->type);
                qid tmp1=qid(*$1,lookup(*$1));
                if(flag){
                    emit(qid("=",NULL),cast,qid("",NULL),tmp1,-1);
                }
                else{
                    if(isInt($3->type))emit(qid("=",NULL),qid(to_string($3->intVal),NULL),qid("",NULL),tmp,-1);
                    else if(isFloat($3->type))emit(qid("=",NULL),qid(to_string($3->realVal),NULL),qid("",NULL),tmp,-1);
                    emit(qid("=",NULL),tmp,qid("",NULL),tmp1,-1);
                    $$->addr=tmp1;
                }
            }
            else{
                qid tmp1=qid(*$1,lookup(*$1));
                if(flag){
                    emit(qid("=",NULL),cast,qid("",NULL),tmp1,-1);
                }
                else if($3->addr.first!="") emit(qid("=",NULL),$3->addr,qid("",NULL),tmp1,-1);
                else emit(qid("=",NULL),qid($3->temp_name,NULL),qid("",NULL),tmp1,-1);
                $$->addr=tmp1;
            }
            

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
        if($3!=NULL && $3->intVal!=cnt1){
            yyerror("Index out of bounds, not matching with intitalisers");
        }
        if(type!=$6->type){
            yyerror("Type Clashing");
            $$->is_error=1;
        }
        
        if(lookup(*$1)){
				string errstr = *$1 + " is already declared";
				yyerror(errstr.c_str());
				$$->is_error = 1;            
        }
        else{
            isArray=1;
            if($3==NULL) array_dims.push_back(cnt1);
            else array_dims.push_back($3->intVal);
            insertSymbol(*cur_table,*$1, "IDENTIFIER", type, yylineno, NULL, modifier, getSize(type)*array_dims[0]);

            //3ac
            $$->addr=qid(*$1,lookup(*$1));
            emit(qid("=",NULL),$6->addr,qid("",NULL),$$->addr,-1);
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


        if($3!=NULL && $3->intVal!=cnt1){
            yyerror("Index out of bounds, not matching with intitalisers");
        }
        if($6!=NULL && $6->intVal!=cnt2){
            yyerror("Index out of bounds, not matching with intitalisers");
        }
        if(type!=$9->type){
            yyerror("Type Clashing");
            $$->is_error=1;
        }
        
        if(lookup(*$1)){
				string errstr = *$1 + " is already declared";
				yyerror(errstr.c_str());
				$$->is_error = 1;            
        }
        else{
            isArray=1;
            if($3==NULL) array_dims.push_back(cnt1);
            else array_dims.push_back($3->intVal);
            if($6==NULL) array_dims.push_back(cnt2);
            else array_dims.push_back($6->intVal);
            insertSymbol(*cur_table,*$1, "IDENTIFIER", type, yylineno, NULL, modifier, getSize(type)*array_dims[0]*array_dims[1]);

            //3ac
            $$->addr=qid(*$1,lookup(*$1));
            emit(qid("=",NULL),$9->addr,qid("",NULL),$$->addr,-1);
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
        if($3!=NULL && $3->intVal!=cnt1){
            yyerror("Index out of bounds, not matching with intitalisers");
        }
        if($6!=NULL && $6->intVal!=cnt2){
            yyerror("Index out of bounds, not matching with intitalisers");
        }
        if($9!=NULL && $9->intVal!=cnt3){
            yyerror("Index out of bounds, not matching with intitalisers");
        }

        if(type!=$12->type){
            yyerror("Type Clashing");
            $$->is_error=1;
        }
        
        if(lookup(*$1)){
				string errstr = *$1 + " is already declared";
				yyerror(errstr.c_str());
				$$->is_error = 1;            
        }
        else{
            isArray=1;
            if($3==NULL) array_dims.push_back(cnt1);
            else array_dims.push_back($3->intVal);
            if($6==NULL) array_dims.push_back(cnt2);
            else array_dims.push_back($6->intVal);
            if($9==NULL) array_dims.push_back(cnt3);
            else array_dims.push_back($9->intVal);
            insertSymbol(*cur_table,*$1, "IDENTIFIER", type, yylineno, NULL, modifier, getSize(type)*array_dims[0]*array_dims[1]*array_dims[2]);

            //3ac
            $$->addr=qid(*$1,lookup(*$1));
            emit(qid("=",NULL),$12->addr,qid("",NULL),$$->addr,-1);
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
        if($3!=NULL && $3->intVal!=cnt1){
            yyerror("Index out of bounds, not matching with intitalisers");
            $$->is_error=1;
        }
        if(type!=$7->type){
            yyerror("Type Clashing");
            $$->is_error=1;
        }
        
        if(lookup(*$1)){
				string errstr = *$1 + " is already declared";
				yyerror(errstr.c_str());
				$$->is_error = 1;            
        }
        else{
            isArray=1;
            if($3==NULL) array_dims.push_back(cnt1);
            else array_dims.push_back($3->intVal);
            insertSymbol(*cur_table,*$1, "IDENTIFIER", type, yylineno, NULL, modifier, getSize(type)*array_dims[0]);

            //3ac
            $$->addr=qid(*$1,lookup(*$1));
            emit(qid("=",NULL),$11->addr,qid("",NULL),$$->addr,-1);
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
        if($3!=NULL && $3->intVal!=cnt1){
            yyerror("Index out of bounds, not matching with intitalisers");
        }
        if($6!=NULL && $6->intVal!=cnt2){
            yyerror("Index out of bounds, not matching with intitalisers");
        }
        if(type!=$10->type){
            yyerror("Type Clashing");
            $$->is_error=1;
        }
        
        if(lookup(*$1)){
				string errstr = *$1 + " is already declared";
				yyerror(errstr.c_str());
				$$->is_error = 1;            
        }
        else{
            isArray=1;
            if($3==NULL) array_dims.push_back(cnt1);
            else array_dims.push_back($3->intVal);
            if($6==NULL) array_dims.push_back(cnt2);
            else array_dims.push_back($6->intVal);
            insertSymbol(*cur_table,*$1, "IDENTIFIER", type, yylineno, NULL, modifier, getSize(type)*array_dims[0]*array_dims[1]);

            //3ac
            $$->addr=qid(*$1,lookup(*$1));
            emit(qid("=",NULL),$17->addr,qid("",NULL),$$->addr,-1);
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
        if($3!=NULL && $3->intVal!=cnt1){
            yyerror("Index out of bounds, not matching with intitalisers");
        }
        if($6!=NULL && $6->intVal!=cnt2){
            yyerror("Index out of bounds, not matching with intitalisers");
        }
        if($9!=NULL && $9->intVal!=cnt3){
            yyerror("Index out of bounds, not matching with intitalisers");
        }
        if(type!=$13->type){
            yyerror("Type Clashing");
            $$->is_error=1;
        }
        
        if(lookup(*$1)){
				string errstr = *$1 + " is already declared";
				yyerror(errstr.c_str());
				$$->is_error = 1;            
        }
        else{
            isArray=1;
            if($3==NULL) array_dims.push_back(cnt1);
            else array_dims.push_back($3->intVal);
            if($6==NULL) array_dims.push_back(cnt2);
            else array_dims.push_back($6->intVal);
            if($9==NULL) array_dims.push_back(cnt3);
            else array_dims.push_back($9->intVal);
            insertSymbol(*cur_table,*$1, "IDENTIFIER", type, yylineno, NULL, modifier, getSize(type)*array_dims[0]*array_dims[1]*array_dims[2]);

            //3ac
            $$->addr=qid(*$1,lookup(*$1));
            emit(qid("=",NULL),$23->addr,qid("",NULL),$$->addr,-1);
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
        if(type!=$7->type){
            yyerror("Type Clashing");
            $$->is_error=1;
        }
        
        if(lookup(*$1)){
				string errstr = *$1 + " is already declared";
				yyerror(errstr.c_str());
				$$->is_error = 1;            
        }
        else{
            isArray=1;
            if($9==NULL) array_dims.push_back(0);
            else array_dims.push_back($9->intVal);
            insertSymbol(*cur_table,*$1, "IDENTIFIER", type, yylineno, NULL, modifier, getSize(type)*array_dims[0]);

            //3ac
            $$->addr=qid(*$1,lookup(*$1));
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
    
        if(type!=$10->type){
            yyerror("Type Clashing");
            $$->is_error=1;
        }
        
        if(lookup(*$1)){
				string errstr = *$1 + " is already declared";
				yyerror(errstr.c_str());
				$$->is_error = 1;            
        }
        else{
            isArray=1;
            if($12==NULL) array_dims.push_back(0);
            else array_dims.push_back($12->intVal);
            if($15==NULL) array_dims.push_back(0);
            else array_dims.push_back($15->intVal);
            insertSymbol(*cur_table,*$1, "IDENTIFIER", type, yylineno, NULL, modifier, getSize(type)*array_dims[0]*array_dims[1]);

            //3ac
            $$->addr=qid(*$1,lookup(*$1));
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
        
        if(type!=$13->type){
            yyerror("Type Clashing");
            $$->is_error=1;
        }
        
        if(lookup(*$1)){
				string errstr = *$1 + " is already declared";
				yyerror(errstr.c_str());
				$$->is_error = 1;            
        }
        else{
            isArray=1;
            if($15==NULL) array_dims.push_back(0);
            else array_dims.push_back($15->intVal);
            if($18==NULL) array_dims.push_back(0);
            else array_dims.push_back($18->intVal);
            if($21==NULL) array_dims.push_back(0);
            else array_dims.push_back($21->intVal);
            insertSymbol(*cur_table,*$1, "IDENTIFIER", type, yylineno, NULL, modifier, getSize(type)*array_dims[0]*array_dims[1]*array_dims[2]);

            //3ac
            $$->addr=qid(*$1,lookup(*$1));
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
        $$->type=$3->type;
        cnt1++;
    }
    | Expression {
       $$=$1;
       cnt1++;
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
        $$->type=$3->type;
        cnt2++;
    }
    | List1 {
        $$=$1;
        cnt2++;
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
        $$->type=$3->type;
        cnt3++;
    }
    | List2 {
        $$=$1;
        cnt3++;
    }
;

MethodDeclaration:
    Modifiers MethodHeader MethodBody{
        // change in grammer
        vector<ASTNode*> s;
        s.push_back($1);
        s.push_back($2);
        s.push_back($3);
        $$ = makeNode("MethodDeclaration", s);

        string fName = funcName;
        printSymbolTable(cur_table ,fName + ".csv");
        endSymbolTable(1);
        print3AC_code($2->temp_name, $2->size);
        func_flag=0;
        modifier={1,0,0};
        mp_param.clear();
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
        $$->temp_name=$2->temp_name;
        modifier={1,0,0};

        $$->size=$2->size;
    }
    | KEY_void {type = "void";} Methodeclarator {
        vector<ASTNode*> s;
        s.push_back($3);
        $$ = makeNode("void", s);
        modifier={1,0,0};
        $$->temp_name=$3->temp_name;

        $$->size=0;
    }
;

Methodeclarator:
    MethodIDEN F '(' formalparameters ')' Dims {
        vector<ASTNode*> s;
        s.push_back($1);
        s.push_back($4);
        $$ = makeNode("MethodDeclarator", s);

        $$->size=$4->size;

        if(!$4->is_error && !$2->is_error){
            $$->temp_name = $1->temp_name;
            $$->expType = 3;
            $$->type = $1->type;

            vector<string> temp = getFuncArgs($1->temp_name);
            if(temp.size()==1 && temp[0] == "#NO_FUNC"){
                insertFuncArg($$->temp_name, funcArgs, $$->type);
                funcArgs.clear();
            }
        }
        else{
            $$->is_error = 1;
        }
    }
    | MethodIDEN F '(' formalparameters ')' {
        vector<ASTNode*> s;
        s.push_back($1);
        s.push_back($4);
        $$ = makeNode("MethodDeclarator", s);

        $$->size=$4->size;

        if(!$4->is_error && !$2->is_error){
            $$->temp_name = $1->temp_name;
            $$->expType = 3;
            $$->type = $1->type;

            vector<string> temp = getFuncArgs($1->temp_name);
            if(temp.size()==1 && temp[0] == "#NO_FUNC"){
                insertFuncArg($$->temp_name, funcArgs, $$->type);
                funcArgs.clear();
            }
        }
        else{
            $$->is_error = 1;
        }
    }
    | MethodIDEN F '(' ')' Dims {
        vector<ASTNode*> s;
        s.push_back($1);
        $$ = makeNode("MethodDeclarator", s);

        if(!$2->is_error){
            $$->temp_name = $1->temp_name;
            $$->expType = 3;
            $$->type = $1->type;

            vector<string> temp = getFuncArgs($1->temp_name);
            // if(lookup($1->temp_name)){
            //     yyerror(("Redeclaration of Method "+ $1->temp_name).c_str());
            //     $$->is_error = 1;
            // }
            if(temp.size()==1 && temp[0] == "#NO_FUNC"){
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
        $$ = makeNode("MethodDeclarator", s);

        if(!$2->is_error){
            $$->temp_name = $1->temp_name;
            $$->expType = 3;
            $$->type = $1->type;

            vector<string> temp = getFuncArgs($1->temp_name);
            // if(lookup($1->temp_name)){
            //     yyerror(("Redeclaration of Method "+ $1->temp_name).c_str());
            //     $$->is_error = 1;
            // }
            if(temp.size()==1 && temp[0] == "#NO_FUNC"){
                insertFuncArg($$->temp_name, funcArgs, $$->type);
                funcArgs.clear();
            }
        }
        else{
            $$->is_error = 1;
        }
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

        //3ac
        qid tmp=newtemp($$->type);
        emit(qid("=",NULL),qid("popparam",NULL),qid("",NULL),tmp,-1);
        mp_param["this"]=tmp.first;
        $$->addr=tmp;
        delete $1;
    }
;

formalparameters:
    formalparameters ',' formalparameter {
        vector<ASTNode*> s;
        s.push_back($1);
        s.push_back($3);
        $$ = makeNode(",", s);

        $$->size=$1->size+$3->size;
    }
    | formalparameter {
        $$=$1;
        type="";
        class_type="";
        modifier = {1,0,0};

        $$->size=$1->size;
    }
;

formalparameter:
    Type VariableDeclarator1 {
        vector<ASTNode*> s;
        s.push_back($1);
        s.push_back($2);
        $$ = makeNode("formalparameter", s);

        $$->size=$2->size;

        if(type=="")type=$1->type;
        $$->type=type;

        if(!$1->is_error && !$2->is_error){
            funcArgs.push_back($2->type);
        }
        else $$->is_error = 1;
        type ="";

        //3ac
        qid tmp=newtemp($$->type);
        emit(qid("=",NULL),qid("popparam",NULL),qid("",NULL),tmp,-1);
        $$->addr=tmp;
        mp_param[$2->temp_name]=tmp.first;

    }
    | KEY_final {modifier[2]=1;} Type VariableDeclarator1 {
        vector<ASTNode*> s;
        s.push_back(makeLeaf("final"));
        s.push_back($3);
        s.push_back($4);
        $$ = makeNode("formalparameter", s);

        if(type=="")type=$3->type;
        $$->type=type;
        if(!$3->is_error && !$4->is_error){
            funcArgs.push_back($4->type);
        }
        else $$->is_error = 1;
        type ="";
    }
    /* | Type DOT3 IDENTIFIER {
        vector<ASTNode*> s;
        s.push_back($1);
        s.push_back(makeLeaf(*$2));
        delete $2;
        s.push_back(makeLeaf("ID (" + *$3+")" ));
        $$ = makeNode("formalparameter", s);

        if(type=="")type=$1->type;
        $$->type=type;

        if(!$1->is_error){
            if(lookup(*$3)){
                yyerror(("Redeclaration of parameter "+ *$3).c_str());
                $$->is_error = 1;
            }
            else{
                paramInsert(*cur_table, *$3, "IDENTIFIER", type, yylineno, NULL, modifier, getSize(type));
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
            if(lookup(*$4)){
                yyerror(("Redeclaration of parameter "+ *$4).c_str());
                $$->is_error = 1;
            }
            else{
                paramInsert(*cur_table, *$4, "IDENTIFIER", type, yylineno, NULL, modifier, getSize(type));
            }
            funcArgs.push_back("...");
            funcArgs.push_back(type);
        }
        else $$->is_error = 1;
        type ="";
        delete $4;
    } */
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
        $$ = makeLeaf("F",1);
        clear_paramoffset();
        if((*cur_table).find(funcName) != (*cur_table).end()){
            yyerror(("Redefinition of method " + funcName).c_str());
            $$->is_error = 1;
        }
        else{
            makeSymbolTable(funcName, funcType, yylineno, modifier,1);
            $$->node_name = funcName;
            block_count = 1;
            
        }
        type = "";
        class_type = "";
        func_flag=0;
        modifier={1,0,0};
    }
;


C:
    {
        $$ = makeLeaf("C",1);
        if(global_st.find(cur_class) != global_st.end()){
            yyerror(("Redefinition of class " + cur_class).c_str());
            $$->is_error = 1;
        }
        else{
            makeSymbolTable(cur_class, "CLASS", yylineno, modifier,1);
            $$->node_name = cur_class;
        }
        type = "";
        class_type = "";
        modifier={1,0,0};
    }
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
                file_path = argv[i+1];
                file_path = file_path.substr(0,file_path.size()-5);
                size_t found = file_path.find_last_of('/');
                if (found == string::npos){
                    code_file_name = file_path;
                }
                else {
                    code_file_name = file_path.substr((int)found + 1);
                }
                system(("mkdir -p "+file_path).c_str());
                file_path+="/";
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

    system(("rm -f "+file_path+"*.csv").c_str());
    system(("rm -f "+file_path+"*.txt").c_str());

    if(!gotoutputfile) dotfile = fopen("temp.dot", "w");

    if(dotfile==NULL){
        printf("Dot file can not be opened.\n");
        return 0;
    }
    yyrestart(yyin);

    symbolTableInit();


    beginAST();
    
    code_file.open(file_path+code_file_name+".s");
    initializeRegs();
    gen_data_section();
    starting_code();

    if(yyparse()) return 0;
    
    endAST();
    printSymbolTable(cur_table, "Global.csv");
    
    if(verbosemode){
        printf("Parser work completed..\n");
        printf("Dot script has generated successfully");
        printf("....\n");
    }
}