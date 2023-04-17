#include "3ac.h"
using namespace std;
#include"codegen.h"

vector<quad> code; 
extern int yylineno;
extern string file_path;
long long cnt = 0;
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

bool isop(string s){
    if(s.find("String")!=string::npos){
        return true;
    }
    if(s.find("int")!=string::npos&& s!="stackpointer--"){
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
    genCode();
    code.clear();
    nxt=0;
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