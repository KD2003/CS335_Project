#include "typecheck.h"

string primaryExpression(string id) {
    sym_entry* n = lookup(id);
    if(n){
        string s = n->type;
        if(n->isArray) return s+"*";
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
        case 1:{
            if(type_name.substr(0, 5)=="FUNC_")return type_name.substr(5, type_name.length() - 5); 
            return "";
        }
        case 2:{
            if(isInt(type_name) || isFloat(type_name))return type_name;
            return "";
        }
        default : return "";
    }   
}

string checkType(string a, string b){
    if(a == b)return a;
    if(isInt(b)) return a;
    if(isFloat(a) && isFloat(b)) return a;
    return "";
}

string unaryExp(string type, string op){
    if(op=="+" || op=="-"){
        if(!(isInt(type) || isFloat(type))) return "";
    }
    else if(op=="~" && !isInt(type)){
        return "";
    }
    else if(op=="!" && type!="boolean") return "";
    return type;
}

string mulExp(string a, string b){
    return promotedType(a, b);
}

string addExp(string a, string b){
    return promotedType(a,b);
}

string shiftExp(string a, string b){
    if(isInt(a) && isInt(b)) return promotedType(a,b);
    return "";
}

string relExp(string a, string b){
    if((isInt(a) || isFloat(a)) && (isInt(b) || isFloat(b))) return "boolean";
    return "";
}

string eqExp(string a, string b){
    if((isInt(a) || isFloat(a) || a=="boolean") && (isInt(b) || isFloat(b) ||b=="boolean")) return "boolean";
    return "";
}

string bitExp(string a, string b){
    if(a=="boolean" && b=="boolean") return "boolean";
    if(isInt(a) && isInt(b)) return promotedType(a,b);
    return "";
}

string assignExp(string a, string b, string op){
    if(op=="="){
        return checkType(a,b);
    }
    if(op == "*=" || op == "/=" || op == "%="){
        if(mulExp(a, b)=="") return "";
        else return "ok";
    }
    if(op == "+=" || op == "-="){
        if(addExp(a, b)=="") return "";
        else return "ok";
    }
    if(op == ">>=" || op == "<<=" || ">>>="){
        if(shiftExp(a, b)=="") return "";
        else return "ok";
    }
    if(op == "&=" || op == "|=" || op == "^="){
        if(bitExp(a, b)=="") return "";
        else return "ok";
    }
    return "";
}

string condExp(string a,string b, string c,string op){
    if(op == "&&" | op== "||"){
        if(a == "boolean" && b=="boolean") return "boolean";
        return "";
    }
    if(a == "boolean" && b!="void" && c!= "void"){
        if(b==c) return b;
        return promotedType(b,c);
    }
    return "";
}

string promotedType(string a, string b){
    if(a == "boolean" || b =="boolean") return "";
    if(a == "double" || b=="double") return "double";
    if(a == "float" || b=="float") return "float";
    if(a == "long" || b=="long") return "long";
    if(isInt(a) || isInt(b)) return "int";
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
    if(type == "void") return 1;
    return 0;
}