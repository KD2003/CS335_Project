#include <fstream>
#include "3ac.h"

using namespace std;

vector<quad> code; 
extern int yylineno;
extern string file_path;
long long cnt = 0;
long long lcnt = 0;

int nxt=0;

void emit(qid op, qid arg1, qid arg2, qid res, int idx){
    quad tmp;
    tmp.op = op;
    tmp.arg1 = arg1;
    tmp.arg2 = arg2;
    tmp.res = res;
    tmp.idx = idx;
    if(idx == -1) tmp.idx = code.size();
    code.push_back(tmp);
    nxt++;
}

void emit(quad q){
    code.push_back(q);
    nxt++;
}

quad make_quad(qid op, qid arg1, qid arg2, qid res, int idx){
    quad tmp;
    tmp.op = op;
    tmp.arg1 = arg1;
    tmp.arg2 = arg2;
    tmp.res = res;
    tmp.idx = idx;
    return tmp;
}

void backpatch(vector<int>& bplist, int target){
    for(int i=0;i<bplist.size(); i++){
        code[bplist[i]].idx = target;
    }
}

qid newtemp(string type){
    // creating temp variables
    string id = "#V"+to_string(cnt++);
    vector<int> def={1,0,0};
    insertSymbol(*cur_table, id, "Temp_var", type, yylineno, NULL, def, getSize(type));
    return qid(id, lookup(id));
}

int assign_exp(string op, string type, string type1,string type2, qid arg1, qid arg2){
    // emitting code for all type of assignment expressions
    string temp_op = "";
    qid sym_typ ;  
    qid sym_typ1;
    int flag1 = 0;
    int a;
    string str = op;
    str.pop_back();
    if(op != "="){
        temp_op = "" + op.substr(0, 1);    
        sym_typ = newtemp(type);    
    }
    else{
        sym_typ = arg2;
    }
    if(op == "<<=" ||op == ">>=")temp_op += temp_op;
    

    if(isInt(type1) && isInt(type2) ){
        temp_op += "int" ;
        if(op != "=")a = code.size(), emit(qid( temp_op ,lookup(str)),arg1 ,arg2, sym_typ, -1);
    }
    else if( isFloat(type1) && isInt(type2)){
        flag1 = 1;
        sym_typ1 = newtemp(type);
        temp_op += "real" ;
        a = code.size();
        emit(qid("inttoreal",NULL), arg2, qid("" , NULL) , sym_typ1, -1);
        if(op != "=")emit(qid( temp_op ,lookup(str)),arg1 ,sym_typ1 , sym_typ, -1);
    }
    else if( isFloat(type2) && isInt(type1)){
        flag1 = 1;
        sym_typ1 = newtemp(type);
        temp_op += "int" ;
        a = code.size();
        emit(qid("realtoint",NULL), arg2, qid("" , NULL) , sym_typ1, -1);
        if(op != "=")emit(qid( temp_op ,lookup(str)),arg1 ,sym_typ1 , sym_typ, -1);
    }
    else if(isFloat(type1) && isFloat( type2) ){
        temp_op += "real" ;
        if(op != "=")a = code.size(), emit(qid( temp_op ,lookup(str)),arg1 ,arg2, sym_typ, -1);
    }


    if(!(op == "=" && flag1 )){ a = code.size(); emit( qid ("=", lookup("=")), sym_typ, qid("", NULL), arg1, -1);}
    else emit( qid ("=", lookup("=")), sym_typ1, qid("", NULL), arg1, -1);

    return a;
}

void backpatch_rem(){
    // backpatching all the remaining goto to Function end
    int i,j;
    i = j = code.size()-1;
    i--;
    while(code[i].op.first.substr(0,5)!="FUNC_"){
        if(code[i].op.first =="GOTO" && code[i].idx==0)code[i].idx = j;
        i--;
        
    }
}

bool isop(string s){
    if(s.find("String")!=string::npos){
        return true;
    }
    if(s.find("int")!=string::npos&& s!="stackpointer"){
        return true;
    }
    if(s.find("float")!=string::npos){
        return true;
    }
    if(s.find("double")!=string::npos){
        return true;
    }
    if(s.find("short")!=string::npos){
        return true;
    }
    if(s.find("long")!=string::npos){
        return true;
    }
    if(s.find("char")!=string::npos){
        return true;
    }
    if(s.find("byte")!=string::npos){
        return true;
    }
    if(s.find("boolean")!=string::npos){
        return true;
    }
    if(s.find("long long")!=string::npos){
        return true;
    }
    if(s=="+" || s=="="|| s=="*="|| s=="/="|| s=="%="|| s=="+="|| s=="-="|| s=="<<="|| s==">>="|| s==">>>="|| s=="&="|| s=="^="|| s=="|=")
        return true;
    if(s==">"||s=="="||s==">"||s=="<"||s=="!"||s=="~"||s=="?"||s==":"||s=="->"||s=="=="||s==">="||s=="<="||s=="!="||s=="&&"||s=="||"||s=="+"||s=="-"||s=="*"||s=="/"||s=="&"||s=="|"||s=="^"||s=="%"||s=="<<"||s==">>"||s==">>>")
        return true;

    return false;
}

void print3AC_code(string filename, int paramsize){
    ofstream tac_file;
    tac_file.open(file_path+filename+".txt");
    tac_file << filename << ":" << '\n';
    tac_file << "beginfunc " + to_string(getFuncSize(filename)-paramsize)<< '\n';
    for(int i=0;i<code.size(); i++){

        if(code[i].op.first=="="){
            if(code[i].arg1.first=="call"){
                tac_file << code[i].res.first << " " <<  code[i].op.first << " " << code[i].arg1.first << " " << code[i].arg2.first << "\n";continue;
            }
            tac_file << code[i].res.first << " " <<  code[i].op.first << " " << code[i].arg1.first << "\n";continue;
        }

        if(isop(code[i].op.first)){
            tac_file<<code[i].res.first << " = "<<code[i].arg1.first<<" "<<code[i].op.first<<" " <<code[i].arg2.first<<"\n";continue;
        }

        tac_file<<code[i].op.first<< " ";
        if(code[i].op.first=="goto"){
            tac_file << code[i].idx+2 << "\n";continue;
        }
        tac_file << code[i].arg1.first << " "; 
        tac_file <<" "<<code[i].arg2.first<<" "<<code[i].res.first << " ";
        if(code[i].op.first=="goto"){
            if(code[i].arg1.first==""){
                tac_file << code[i].idx+2 ;
            }
        }
        if(code[i].res.first=="goto"){
            tac_file << code[i].idx+2 ;
        }
        tac_file << '\n';
    }
    tac_file << "endfunc_" << '\n';
    code.clear();
    nxt=0;
}

string newlabel(){
    string tmp="#L"+to_string(lcnt++);
    return tmp;
}

vector<int> mergelist(vector <int> &list1, vector <int> &list2){
    vector<int> temp;
    for(auto i:list1) temp.push_back(i);
    for(auto i:list2) temp.push_back(i);
    return temp;
}

int nextinstr(){
    return nxt;
}

void addline(){
    nxt++;
}
void remline(){
    nxt--;
}