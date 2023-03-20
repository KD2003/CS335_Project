#include "typecheck.h"

//RETURNS THE TYPE OF IDENTIFIER id USING lookup
string primaryExpression(string id) {
    sym_entry* n = lookup(id);
    if(n) {
        string s = n->type;
        return s;     
    }
    string temp = funcProtoLookup(id);
    if(temp!=""){
        temp += "#";
    }
    return temp; 
}

string postfixExpression(string type_name, int rule_num) {
    string result_type;
    switch(rule_num) {
        case 1: {
            if(type_name.back()=='*')return type_name.substr(0,type_name.length()-1);
            return "";
        }
        case 2:{
            if(type_name.substr(0, 5)=="FUNC_")return type_name.substr(5, type_name.length() - 5); 
            return "";
        }
        case 3:{
            if(type_name.substr(0, 5)=="FUNC_")return type_name.substr(5, type_name.length() - 5);
            return "";
        }
        case 6:{
            if(isInt(type_name) || type_name == "char")return type_name;
            return "";
        }
        case 7:{
            if(isInt(type_name) || type_name == "char")return type_name;
            return "";
        }
        default : return "";
    }   
}

string checkType(string a, string b){
    if(a == b)return "ok";
    if((a == "void*" && b.back()=='*')||(a.back()=='*' && b == "void"))return "ok";
    if(a.back()=='*' && b.back()=='*')return "warning";
    if((isInt(a) && b.back()=='*')||(isInt(b)&&a.back()=='*'))return "warning";
    if(a == "char" || isInt(a)) a = "long double";
    if(b == "char" || isInt(b)) b = "long double";
    if(isFloat(a) && isFloat(b)) return "ok";
    return "";
}

string argExp(string a, string b, int rule_num){
    if(rule_num == 1){
        if(a == "void") return a;
        return "";
    }
    else{
        if(a == "void" && b=="void") return a;
        return "";
    }
}

string unaryExp(string op, string type){
    if(op=="*") return postfixExpression(type, 1);
    else if(op == "&") type+="*";
    else if(op=="+" || op=="-"){
        if(!(isInt(type) || isFloat(type))) return "";
    }
    else if(op=="~" && !isInt(type)){
        return "";
    }
    else if(op=="!" && type!="boolean") return "";
    return type;
}

string mulExp(string a, string b, char op){
    if(op=='*' || op =='/'){
        if(isInt(a) && isInt(b)) return "int";
        else if((isInt(a) || isFloat(a)) && (isInt(b) || isFloat(b))) return "float";
        return "";
    }
    else if(op=='%'){
        if(isInt(a) && isInt(b)) return "int";
    }
    return "";
}

string addExp(string a, string b, char op){
    if(isInt(a) && isInt(b)) return "int";
    else if((isInt(a) || isFloat(a)) && (isInt(b) || isFloat(b))) return "real";
    else if((isInt(a) && b=="char") || (a=="char" && isInt(b))) return "char";
    else if(isInt(a) && b.back()=='*') return b;
    else if(a.back()=='*' && isInt(b)) return a;
    return "";
}

string shiftExp(string a, string b){
    if(isInt(a) && isInt(b)) return "ok";
    return "";
}

string relExp(string a, string b){
    if((isInt(a) || isFloat(a) || a=="char") && (isInt(b) || isFloat(b) ||b=="char")) return "boolean";
    if((isInt(a) || a=="char") && b.back()=='*') return "Boolean";
    if((isInt(b) || b=="char") && a.back()=='*') return "Boolean";
    return "";
}

string eqExp(string a, string b){
    if(a==b) return "Ok";
    if((isInt(a) || isFloat(a) || a=="char") && (isInt(b) || isFloat(b) ||b=="char")) return "Ok";
    if((isInt(a) && b.back()=='*') || (a.back()=='*' && isInt(b))) return "ok";
    return "";
}

string bitExp(string a, string b){
    if(a=="boolean" && b=="boolean") return "ok";
    if((a=="boolean" || isInt(a)) && (b=="boolean" || isInt(b))) return "Ok";
    return "";
}

string assignExp(string a, string b, string op){
    if(op=="="){
        return checkType(a,b);
    }
    if(op == "*=" || op == "/=" || op == "%="){
        if(mulExp(a, b, op[0])=="") return "";
        else return "ok";
    }
    if(op == "+=" || op == "-="){
        if(addExp(a, b, op[0])=="") return "";
        else return "ok";
    }
    if(op == ">>=" || op == "<<="){
        if(shiftExp(a, b)=="") return "";
        else return "ok";
    }
    if(op == "&=" || op == "|=" || op == "^="){
        if(bitExp(a, b)=="") return "";
        else return "ok";
    }
    return "";
}

string condExp(string a,string b){
    if(a == b)return a;
    if(a == "char"|| isInt(a)) a = "float";
    if(b == "char"|| isInt(b)) b = "float";
    if(isFloat(a) && isFloat(b)) return "int";
    if(a.back() == '*' && b.back() == '*')return "void*" ;
    return "";
}

bool isInt(string type){
    if(type=="byte") return 1;
    if(type=="int") return 1;
    if(type=="long") return 1;
    if(type=="short") return 1;
    if(type=="char") return 1;
    return 0;
}

bool isFloat(string type){
   if(type=="float") return 1;
   if(type=="double") return 1;
   return 0;
}

bool isVoid(string type){
    if(type.length() < 4) return 0;
    else if(type.substr(0,4) == "void") return 1;
    else return 0;
}