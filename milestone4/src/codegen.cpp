#include "codegen.h"

map<string, set<qid> > reg_desc;
map<int ,string> leaders;
map<int, string> stringlabels;
map<int, int> pointed_by;
vector<qid> params;

int string_cnt = 0;
int label_cnt = 0;
int arg_size = 0;
int in_func = 0;

set<string> exclude_this;
qid empty_var("",NULL);

extern ofstream code_file;
extern map<string, int> method_invoked;
extern vector<quad> code;

string get_label(){
    return "L" +to_string(label_cnt++);
}

void gen_data_section(){
    for(auto it: method_invoked){
        if(it.second) code_file << "extern "<<it.first<<"\n";
    }
}

void starting_code(){
    code_file << "\nsection .text\n";
    code_file << "\tglobal main\n";
}

int is_integer(string text){
    for(int i=0; i<text.length(); i++){
        if(text[i] >= '0' && text[i]<='9'){
            continue;
        }
        else return 0;
    }
    return 1;
}

int giveArraySize(sym_entry* entry){
    vector<int> v = entry->array_dims;
    if(!v.empty()){
        int s=getSize(entry->type);
        for(int i=0; i<v.size(); i++){
            s*=v[i];
        }
        return s;
    }
    return 8;
}

void add_op(quad* instr){
    if(is_integer(instr->arg1.first) && is_integer(instr->arg2.first)){
        long val = (stol(instr->arg1.first) + stol(instr->arg2.first));
        string str = get_mem_location(&instr->res, &empty_var, instr->idx, 0);
        code_file << "\tmov $" << val <<", " << str << "\n";
    }
    else{
        string reg1 = getReg(&instr->arg1, &instr->res, &instr->arg2, instr->idx);
        string mem2 = get_mem_location(&instr->arg2, &instr->arg1, instr->idx, 0);

        if(instr->arg1.second->is_derefer){
            string str = get_mem_location(&instr->arg1, &instr->arg2, instr->idx, -1);
            code_file<<"\tmov "<<reg1 <<", "<< str<<"\n";
            code_file<<"\tmov "<<reg1<<", [ "<<reg1<<" ]\n";
        }
        
        if(instr->arg1.second->isArray && !instr->arg2.second->isArray){
            int size = giveArraySize(instr->arg1.second);
            exclude_this.insert(reg1);
            string temp_reg = getTemporaryReg(&instr->arg2, instr->idx);
            exclude_this.erase(reg1);
            code_file << "\tmov "<< mem2 << ", "<< temp_reg <<"\n";
            code_file << "\timul "<< size << ", "<< temp_reg <<"\n";
            mem2 = temp_reg;
        }
        else if(instr->arg1.second->isArray && instr->arg2.second->isArray){
            int size = giveArraySize(instr->arg1.second);
            code_file << "\timul "<< size << ", "<< reg1 <<"\n";
        }
        code_file << "\tadd " << mem2 << ", " << reg1 <<"\n";
        update_reg_desc(reg1, &instr->res);
    }
}

void sub_op(quad* instr){
    if(is_integer(instr->arg1.first) && is_integer(instr->arg2.first)){
        long val = (stol(instr->arg1.first) - stol(instr->arg2.first));
        string str = get_mem_location(&instr->res, &empty_var, instr->idx, 0);
        code_file << "\tmov $" << val <<", " << str << "\n";
    }
    else{        
        string reg1 = getReg(&instr->arg1, &instr->res, &instr->arg2, instr->idx);
        string mem2 = get_mem_location(&instr->arg2, &instr->arg1, instr->idx, 0);
        
        if(instr->arg1.second->is_derefer){
            string str = get_mem_location(&instr->arg1, &instr->arg2, instr->idx, -1);
            code_file<<"\tmov "<< reg1 << ", " << str << "\n";
            code_file<<"\tmov "<< reg1<< ", [ " << reg1 << " ]\n";
        }

        if(instr->arg1.second->isArray && !instr->arg2.second->isArray){
            int size = giveArraySize(instr->arg1.second);
            exclude_this.insert(reg1);
            string temp_reg = getTemporaryReg(&instr->arg2, instr->idx);
            exclude_this.erase(reg1);
            code_file << "\tmov "<< mem2 << ", "<< temp_reg <<"\n";
            code_file << "\timul "<< size << ", "<< temp_reg <<"\n";
            mem2 = temp_reg;
        }
        else if(!instr->arg1.second->isArray && instr->arg2.second->isArray ){
                int size = giveArraySize(instr->arg2.second);
                code_file << "\timul "<< size << ", "<< reg1 <<"\n";
        }
        code_file << "\tsub " << mem2 << ", " << reg1 <<"\n";
        update_reg_desc(reg1, &instr->res);
    }
}

void mul_op(quad* instr){
    if(is_integer(instr->arg1.first) && is_integer(instr->arg2.first)){
        long val = (stol(instr->arg1.first) * stol(instr->arg2.first));
        string str = get_mem_location(&instr->res, &empty_var, instr->idx, 0);
        code_file << "\tmov $" << val <<", " << str << "\n";
    }
    else{
        string reg1 = getReg(&instr->arg1, &instr->res, &instr->arg2, instr->idx);
        string mem2 = get_mem_location(&instr->arg2, &instr->arg1, instr->idx, 0);
        
        if(instr->arg1.second->is_derefer){
            string str = get_mem_location(&instr->arg1, &instr->arg2, instr->idx, -1);
            code_file<<"\tmov "<< reg1 <<", "<< str << "\n";
            code_file<<"\tmov "<< reg1 <<", [ "<< reg1 <<" ]\n";
        }
        code_file << "\timul " << mem2 << ", " << reg1 <<"\n";
        update_reg_desc(reg1, &instr->res);
    }
}

void div_op(quad* instr){
    if(is_integer(instr->arg1.first) && is_integer(instr->arg2.first)){
        long val = (stol(instr->arg1.first) / stol(instr->arg2.first));
        string str = get_mem_location(&instr->res, &empty_var, instr->idx, 0);
        code_file << "\tmov $" << val <<", " << str << "\n";
    }
    else{
        free_reg("%rax");
        free_reg("%rdx");
        string str = get_mem_location(&instr->arg1, &instr->arg2, instr->idx, 0);
        code_file<<"\tmov "<< str << ", %rax\n";
        reg_desc["%rax"].insert(instr->arg1);
        reg_desc["%rdx"].insert(instr->arg1);
        exclude_this.insert("%rax");
        exclude_this.insert("%rdx");
        string reg2 = getReg(&instr->arg2, &instr->res, &empty_var, instr->idx);
        if(instr->arg2.second->is_derefer){ 
            string str = get_mem_location(&instr->arg2, &instr->arg1, instr->idx, -1);
            code_file<<"\tmov "<< reg2 <<", "<< str <<"\n";
            code_file<<"\tmov "<< reg2 <<", [ "<< reg2 <<" ]\n";
        }
        exclude_this.clear();
        code_file<<"\tidiv "<< reg2 <<"\n";
        instr->res.second->addr_descriptor.reg = "%rax";
        reg_desc["%rax"].clear();
        reg_desc["%rdx"].clear();
        reg_desc["%rax"].insert(instr->res);
    }
}

void mod_op(quad* instr){
    if(is_integer(instr->arg1.first) && is_integer(instr->arg2.first)){
        long val = (stol(instr->arg1.first) % stol(instr->arg2.first));
        string str = get_mem_location(&instr->res, &empty_var, instr->idx, 0);
        code_file << "\tmov $" << val <<", " << str << "\n";
    }
    else{
        free_reg("%rax");
        free_reg("%rdx");
        string str = get_mem_location(&instr->arg1, &instr->arg2, instr->idx, 0);
        code_file<<"\tmov "<< str << ", %rax\n";
        reg_desc["%rax"].insert(instr->arg1);
        reg_desc["%rdx"].insert(instr->arg1);
        exclude_this.insert("%rax");
        exclude_this.insert("%rdx");
        string reg2 = getReg(&instr->arg2, &instr->res, &empty_var, instr->idx);
        if(instr->arg2.second->is_derefer){
            string str = get_mem_location(&instr->arg2, &instr->arg1, instr->idx, -1);
            code_file<<"\tmov "<< reg2 <<", "<< str <<"\n";
            code_file<<"\tmov "<< reg2 <<", [ "<< reg2 <<" ]\n";
        }
        exclude_this.clear();
        code_file <<"\tidiv "<< reg2 <<"\n";
        instr->res.second->addr_descriptor.reg = "%rdx";
        reg_desc["%rax"].clear();
        reg_desc["%rdx"].clear();
        reg_desc["%rdx"].insert(instr->res);
    }
}

void logic_or(quad *instr){
    if(is_integer(instr->arg1.first) && is_integer(instr->arg2.first)){
        long a = stol(instr->arg1.first);
        long b = stol(instr->arg2.first);
        string reg = get_mem_location(&instr->res, &empty_var, instr->idx, 1);
        if(a || b){
            code_file << "\tmov $1, "<< reg <<"\n";
        }
        else{
            code_file << "\tmov $0, "<< reg <<"\n";
        }
    }
    else{
        string l1 = "", l2 = "";
        l1 = get_label();
        l2 = get_label();
        string reg = getReg(&instr->arg1, &instr->res, &instr->arg2, instr->idx);    
        if(instr->arg1.second->is_derefer){
            string str = get_mem_location(&instr->arg1, &instr->arg2, instr->idx, -1);
            code_file<<"\tmov "<< reg <<", "<< str <<"\n";
            code_file<<"\tmov "<< reg <<", [ "<< reg <<" ]\n";
        }

        string mem2 = getReg(&instr->arg2, &empty_var, &instr->arg1, instr->idx);

        code_file << "\tadd " << mem2 << ", " << reg << "\n";
        code_file << "\ttest " << reg << ", " << reg << "\n";
        code_file << "\tsetnz " << reg << "\n";
        update_reg_desc(reg, &instr->res);
    }
}

void logic_and(quad *instr){
    if(is_integer(instr->arg1.first) && is_integer(instr->arg2.first)){
        long a = stol(instr->arg1.first);
        long b = stol(instr->arg2.first);
        string reg = get_mem_location(&instr->res, &empty_var, instr->idx, 1);
        if(a && b){
            code_file << "\tmov $1, "<< reg <<"\n";
        }
        else{
            code_file << "\tmov $0, "<< reg <<"\n";
        }
    }
    else{
        string reg = getReg(&instr->arg1, &instr->res, &instr->arg2, instr->idx);    
        if(instr->arg1.second->is_derefer){
            string str = get_mem_location(&instr->arg1, &instr->arg2, instr->idx, -1);
            code_file<<"\tmov "<< reg <<", "<< str <<"\n";
            code_file<<"\tmov "<< reg <<", [ "<< reg <<" ]\n";
        }

        string mem2 = getReg(&instr->arg2, &empty_var, &instr->arg1, instr->idx);
        code_file << "\ttest " << mem2 << ", " << mem2 << "\n";
        code_file << "\tcmovnz " << mem2 << ", " << reg << "\n";
        code_file << "\ttest " << reg << ", " << reg << "\n";
        code_file << "\tsetnz " << reg << "\n";
        update_reg_desc(reg, &instr->res);
    }
}

void bitwise_op(quad* instr){
    string op = instr->op.first;
    if(is_integer(instr->arg1.first) && is_integer(instr->arg2.first)){
        long val = 0;
        if(op[0] == '^')        val = (stol(instr->arg1.first) ^ stol(instr->arg2.first));
        else if(op[0] == '&')   val = (stol(instr->arg1.first) & stol(instr->arg2.first));
        else if(op[0] == '|')   val = (stol(instr->arg1.first) | stol(instr->arg2.first));
        string mem = get_mem_location(&instr->res, &empty_var, instr->idx, 1);
        code_file << "\tmov $" << val <<", " << mem << "\n";
        return;
    }
    string reg = getReg(&instr->arg1, &instr->res, &instr->arg2, instr->idx);
    
    if(instr->arg1.second->is_derefer){
        string str = get_mem_location(&instr->arg1, &instr->arg2, instr->idx, -1);
        code_file<<"\tmov "<< reg <<", "<< str <<"\n";
        code_file<<"\tmov "<< reg <<", [ "<< reg <<" ]\n";
    }

    string op_ins = "";
    if(op[0] == '^')      op_ins = "xor";
    else if(op[0] == '&') op_ins = "and";
    else if(op[0] == '|') op_ins = "or";
    string mem2 = get_mem_location(&instr->arg2, &instr->arg1, instr->idx, 0);
    code_file << "\t" << op_ins << " " << mem2 << ", "<< reg <<"\n";
    update_reg_desc(reg, &instr->res);
}

void comparison_op(quad* instr){
    string op = instr->op.first.substr(0,2);
    if(is_integer(instr->arg1.first) && is_integer(instr->arg2.first)){
        long val = 0;
        if(op == "==")      val = (stol(instr->arg1.first) == stol(instr->arg2.first));
        else if(op == "<")  val = (stol(instr->arg1.first) <  stol(instr->arg2.first));
        else if(op == "<=") val = (stol(instr->arg1.first) <= stol(instr->arg2.first));
        else if(op == ">")  val = (stol(instr->arg1.first) >  stol(instr->arg2.first));
        else if(op == ">=") val = (stol(instr->arg1.first) >= stol(instr->arg2.first));
        else if(op == "!=") val = (stol(instr->arg1.first) != stol(instr->arg2.first));  
        string mem = get_mem_location(&instr->res, &empty_var, instr->idx, 1);
        code_file << "\tmov $" << val <<", " << mem << "\n";
        return;
    }
    string reg = getReg(&instr->arg1, &empty_var, &instr->arg2, instr->idx);
    if(instr->arg1.second->is_derefer){
        string str = get_mem_location(&instr->arg1, &instr->arg2, instr->idx, -1);
        code_file<<"\tmov "<< reg <<", "<< str <<"\n";
        code_file<<"\tmov "<< reg <<", [ "<< reg <<" ]\n";
    }

    string set_ins = "";
    if(op == "==")      set_ins = "sete";
    else if(op[0] == '<')  set_ins = "setl";
    else if(op == "<=") set_ins = "setle";
    else if(op[0] == '>')  set_ins = "setg";
    else if(op == ">=") set_ins = "setge";
    else if(op == "!=") set_ins = "setne";

    string mem2 = get_mem_location(&instr->arg2, &instr->arg1, instr->idx, 0);
    code_file << "\tcmp "<< mem2 <<", " << reg <<"\n";
    code_file << "\t"<< set_ins << " " << reg <<"\n";
    update_reg_desc(reg, &instr->res);
}

void shift_op(quad* instr){
    string op = instr->op.first;
    exclude_this.insert("dcx");
    string reg1 = getReg(&instr->arg1, &instr->res, &instr->arg2, instr->idx);
    if(instr->arg1.second->is_derefer) {
        string str = get_mem_location(&instr->arg1, &instr->arg2, instr->idx, -1);
        code_file<<"\tmov "<< reg1 <<", "<< str <<"\n";
        code_file<<"\tmov "<< reg1 <<", [ "<< reg1 <<" ]\n";
    }
    free_reg("dcx");
    string mem2 = get_mem_location(&instr->arg2, &instr->arg1, instr->idx, 0);
    string shift_ins="";
    if(op == "<<") shift_ins = "shl";
    else if(op == ">>") shift_ins = "sar";
    else if(op == ">>>") shift_ins = "shr";
    code_file << "\tmov " << mem2 << ", %rcx\n";
    code_file << "\t" << shift_ins << " \%cl, " << reg1 <<"\n";
    exclude_this.clear();
    update_reg_desc(reg1, &instr->res);
}

void unary_op(quad* instr){
    string op = instr->op.first, unary_ins = "";
    string reg = getReg(&instr->arg1, &instr->res, &instr->arg2, instr->idx);
    if(op[2] == 'P'){
        if(op == "++P")      unary_ins = "inc";
        else if(op == "--P") unary_ins = "dec";
        
        if(instr->arg1.second->is_derefer){
            string reg1 = getTemporaryReg(&instr->arg1, instr->idx);
            reg = "[ " + reg + " ]";
            code_file<<"\tmov "<< reg <<", "<< reg1 <<"\n";
            code_file<<"\t"<< unary_ins <<" "<< reg1 <<"\n";
            code_file<<"\tmov "<< reg1 <<", "<< reg <<"\n";
            update_reg_desc(reg1, &instr->res);
        }
        else{
            code_file<<"\t"<< unary_ins <<" "<< reg <<"\n";
            free_reg(reg);
            update_reg_desc(reg, &instr->res);
        }
        
    }
    else if(op[0] == 'P'){
        if(op == "P++")      unary_ins = "inc";
        else if(op == "P--") unary_ins = "dec";
        if(instr->arg1.second->is_derefer){
            string reg1 = getTemporaryReg(&instr->arg1, instr->idx);
            reg = "[ " + reg + " ]";
            code_file<<"\tmov "<< reg <<", "<< reg1 <<"\n";
            update_reg_desc(reg1, &instr->res);
            code_file<<"\t"<< unary_ins <<" "<< reg1 <<"\n";
            code_file<<"\tmov "<< reg1 <<", "<< reg <<"\n";
        }
        else{
            string reg1 = getTemporaryReg(&instr->arg1, instr->idx);
            code_file<<"\tmov "<< reg <<", "<< reg1 <<"\n";
            update_reg_desc(reg1, &instr->res);
            code_file<<"\t"<< unary_ins <<" "<< reg <<"\n";
            string str = get_mem_location(&instr->arg1, &empty_var,instr->idx,-1);
            code_file<<"\tmov "<< reg <<", "<< str <<"\n";
        }
    }
    else if(op == "~"){
        if(instr->arg1.second->is_derefer){
            reg = "[ " + reg + " ]";
        }
        code_file << "\tnot " << reg <<"\n";
        update_reg_desc(reg, &instr->res);
    }
    else if(op == "-U"){
        if(instr->arg1.second->is_derefer){
            reg = "[ " + reg + " ]";
        }
        code_file << "\tneg " << reg <<"\n";       
        update_reg_desc(reg, &instr->res);
    }
    else if(op == "+U"){
        reg_desc[reg].insert(instr->res);
        instr->res.second->addr_descriptor.reg = reg;
    }
    else if(op == "!"){
        if(instr->arg1.second->is_derefer){
            reg = "[ " + reg + " ]";
        }
        code_file << "\ttest "<< reg <<", "<< reg <<"\n";
        code_file << "\tsete "<< reg <<"\n";
        update_reg_desc(reg, &instr->res);
    }
}

void assign_op(quad* instr){
    if(instr->res.second->is_derefer){
        string res_mem = getReg(&instr->res, &empty_var, &instr->arg1, -1);
        string arg1_mem = getReg(&instr->arg1, &empty_var, &instr->res, -1);
        res_mem = "[ " + res_mem + " ]";
        if(instr->arg1.second->is_derefer){
            code_file <<"\tmov [ "<< arg1_mem <<" ], "<< arg1_mem <<"\n";
        }
        code_file <<"\tmov "<< arg1_mem <<", "<< res_mem <<"\n";
    }
    else if(is_integer(instr->arg1.first)){
        string mem = get_mem_location(&instr->res, &instr->arg1, instr->idx, 1);
        if(reg_desc.find(mem) != reg_desc.end()){
            free_reg(mem);
            update_reg_desc(mem, &instr->res);
        }
        code_file << "\tmov $"<< instr->arg1.first << ", "<< mem <<"\n";
    }
    else{
        string reg = getReg(&instr->arg1, &instr->res, &empty_var, instr->idx);
        if(instr->arg1.second->is_derefer){
            code_file<<"\tmov [ "<< reg <<" ], "<< reg <<"\n";
            update_reg_desc(reg, &instr->res);        
        }
        else {
            reg_desc[reg].insert(instr->res);
            string prev_reg = instr->res.second->addr_descriptor.reg;
            if(prev_reg != "") reg_desc[prev_reg].erase(instr->res);
            instr->res.second->addr_descriptor.reg = reg;
        }
        if(instr->res.first=="array_init"){
            string tem = get_mem_location(&instr->res,&empty_var,instr->idx,-1);
            code_file << "\tmov " << reg << ", " << tem << "\n";
            free_reg(reg);
        }
        if(pointed_by[instr->res.second->offset]){
            string reg_stored = instr->res.second->addr_descriptor.reg;
            instr->res.second->addr_descriptor.reg = "";
            reg_desc[reg_stored].erase(instr->res);
            string str = get_mem_location(&instr->res, &instr->arg1, instr->idx, 0);
            code_file<<"\tmov "<< reg_stored <<", "<< str <<"\n";
        }
        instr->res.second->addr_descriptor.stack = 0;
    }
}

// // member access for variable of user defined data type
// void member_access(quad* instr){
//     if(!instr->arg1.second->is_derefer){
//         instr->res.second->offset = instr->arg1.second->offset - instr->arg2.second->offset - instr->arg2.second->size + instr->arg1.second->size;
//         if(instr->arg2.second->isArray) {
//             instr->res.second->offset += instr->arg2.second->size - 4;
//         }
//         pointed_by[instr->res.second->offset] = 1;
//         instr->res.second->isArray = instr->arg2.second->isArray;
//     }
//     else{
//         string reg = getReg(&instr->arg1, &instr->res, &instr->arg2, instr->idx);
//         code_file<<"\tadd "<<reg<<", "<<instr->arg2.second->offset<<"\n";
        
//         if(!instr->arg2.second->isArray) instr->res.second->is_derefer = 1;
//         update_reg_desc(reg, &instr->res);
//     }
// }

void array_op(quad* instr){
        string reg = getReg(&instr->res, &empty_var, &instr->arg2, instr->idx);
        string mem, str;
        if(instr->arg1.second->isArray){
            if(instr->arg1.second->addr_descriptor.reg != ""){
                string temp_reg = instr->arg1.second->addr_descriptor.reg;
                instr->arg1.second->addr_descriptor.reg = "";
                str = get_mem_location(&instr->arg1, &instr->arg2, instr->idx, 0);
                code_file<<"\tmov "<< temp_reg <<", "<< str <<"\n"; 
            }
            mem = get_mem_location(&instr->arg1, &instr->arg2, instr->idx, 0);
            code_file<<"\tleaq "<< mem <<", "<< reg <<"\n";
        }
        else {
            mem = get_mem_location(&instr->arg1, &instr->arg2, instr->idx, 0);
            code_file<<"\tmov "<< mem <<", "<< reg <<"\n";
        }
        exclude_this.insert(reg);
        string reg1 = getReg(&instr->arg2, &empty_var, &instr->arg1, instr->idx);
        if(instr->arg2.second->is_derefer){
            string str = get_mem_location(&instr->arg1, &instr->arg2, instr->idx, -1);
            code_file<<"\tmov "<< reg1 <<", "<< str <<"\n";
            code_file<<"\tmov [ "<< reg1 <<" ], "<< reg1 <<" ]\n";
        }
        if(instr->arg1.second->array_dims.empty()) code_file <<"\timul "<< getSize(instr->res.second->type) <<", " << reg1 <<"\n";
        else code_file<<"\timul "<< giveArraySize(instr->res.second) <<", "<< reg1 <<"\n";
        code_file<<"\tadd "<< reg1 <<", "<< reg <<"\n";
        if(instr->arg1.second->array_dims.empty()) instr->res.second->is_derefer = 1;
        exclude_this.clear();
        reg_desc[reg1].erase(instr->arg2);
        instr->arg2.second->addr_descriptor.reg = "";
        update_reg_desc(reg, &instr->res);
}

// //----------------------------------------------------- Goto ----------------------------------------------------//


// Goto operation
void goto_op(quad* instr){
    end_basic_block();
    if(instr->arg1.first == "IF"){
        string loc = get_mem_location(&instr->arg2, &instr->arg1, instr->idx, 1);
        code_file << " cmp " << loc <<", " << " $0"<<"\n";
        code_file << " jne " << leaders[instr->idx]<<"\n";
    }
    else{
        code_file << " jmp " << leaders[instr->idx] <<"\n";
    }
}


// //----------------------------------------------------- Function Call and return ----------------------------------------------------//

void call_func(quad *instr){

    for(auto it: reg_desc){
        free_reg(it.first);
    }

    int npara = stoi(instr->arg2.first);
    int addspace=0;
    for(int i=0;i<npara;i++){
        code_file << "push " <<  get_mem_location(&params[i], &empty_var, -1, -1) << '\n';
        addspace+=params[i].second->size;
    }
    code_file << "sub " << "$"+to_string(addspace)+", " << "%rsp" << '\n';

    code_file << "call " << instr->arg1.first << '\n';  
    code_file << "add " << "$"+to_string(addspace)+", " << "%rsp" << '\n'; 
    params.clear();


}


// storing return value from a func
void return_func(quad* instr){
    
    string dest =  get_mem_location(&instr->res, &empty_var, -1, -1);
    code_file << "mov " << "%rax " << dest << '\n';

}

// convert char to its ASCII value
string char_to_int(string sym){
    if(sym[0]!='\'')return sym;
    if(sym[1] == '\\'){
        string s = sym.substr(1,2);
        if(s == "\\0") return "0";
        if(s == "\\n") return "10";
        if(s == "\\t") return "9";
    } 
    int val = (int )sym[1];
    sym = to_string(val);
    return sym;
}

//returning from a func
void return_instruct(){
    code_file << "ret\n";
}

//ending funciton
void end_func(){
    code_file << "leave\n"; 
}

void genCode(string func_name){
    findBasicBlocks();
    gen_func_label(func_name);

    int index = 0;
    for(auto it=leaders.begin(); it != leaders.end(); it++){

        code_file << it->second <<":\n";
        auto it1 = it;
        it1++;
        if(it1 == leaders.end()) break;
        
        int ended = 0;
        int start = it->first;
        int end = it1->first;
        
    //     for(int idx=start; idx < end; idx++){
    //         quad instr = code[idx];
    //         if(instr.arg1.first != "") instr.arg1.first = char_to_int(instr.arg1.first);
    //         if(instr.arg2.first != "") instr.arg2.first = char_to_int(instr.arg2.first);
    //         else if(instr.op.first.substr(0,2) == "++"  
    //                 ||instr.op.first.substr(0,2) == "--" 
    //                 ||instr.op.first == "!" 
    //                 ||instr.op.first == "~" 
    //                 ||instr.op.first == "unary-" 
    //                 ||instr.op.first == "unary+") unary_op(&instr);
    //         else if(instr.op.first[0] == '+')    add_op(&instr);
    //         else if(instr.op.first.substr(0, 5) == "FUNC_" && instr.op.first[(instr.op.first.size() - 3)] == 'd'){
    //             end_basic_block();
    //             code_file << "\txor eax, eax\n";
    //             code_file << "\tleave\n";
    //             code_file << "\tret\n";
    //             clear_regs();
    //             in_func = 0;
                
    //         }
    //         else if(instr.op.first[0] == '-') sub_op(&instr);
    //         else if(instr.op.first[0] == '*') mul_op(&instr);
    //         else if(instr.op.first[0] == '/') div_op(&instr);
    //         else if(instr.op.first[0] == '%') mod_op(&instr);
    //         else if(instr.op.first == "CALL") call_func(&instr);
    //         else if(instr.op.first == "param") params.push_back(instr.arg1);
    //         else if(instr.arg1.first == "popreturn") return_func(&instr);
    //         else if(instr.op.first == "stackpointer--") ;
    //         else if(instr.op.first == "endfunc_") end_func();
    //         else if(instr.op.first == "return") return_instruct();
    //         else if(instr.op.first == "=")   assign_op(&instr);
    //         else if(instr.op.first == "=="  
    //                 ||instr.op.first == "<" 
    //                 ||instr.op.first == "<=" 
    //                 ||instr.op.first == ">" 
    //                 ||instr.op.first == ">=" 
    //                 ||instr.op.first == "!=" ) comparison_op(&instr); 

    //         else if(instr.op.first == "&&") logic_and(&instr);
    //         else if(instr.op.first == "||") logic_or(&instr);
    //         else if(instr.op.first.substr(0,2) == "<<") lshift_op(&instr);
    //         else if(instr.op.first.substr(0,2) == ">>") rshift_op(&instr);
    //         else if(instr.op.first[0] == '^' ||  instr.op.first[0] == '&' || instr.op.first[0] == '|') bitwise_op(&instr);
    //         else if(instr.op.first == "GOTO") {    
    //             goto_op(&instr);
    //         }
    //         else if(instr.op.first == "member_access") member_access(&instr);
    //         else if(instr.op.first == "[ ]") array_op(&instr);
    //     }
        end_basic_block();
    }

    print_string_labels();
}

void print_string_labels(){
    for(auto it: stringlabels){
        code_file<<"__str__"<<it.first<<": .asciz "<<it.second<<"\n";
    }
}

void end_basic_block(){
    for(auto reg = reg_desc.begin();reg!=reg_desc.end();reg++){
        for(auto sym =reg->second.begin(); sym!=reg->second.end(); sym++){
            if(is_integer(sym->first)) continue;
            sym->second->addr_descriptor.reg = "";
            qid tem = *sym;
            string str = get_mem_location(&tem, &empty_var, -1, -1); 
            code_file<<"\tmov " << reg->first <<", "<< str <<"\n";
        }
        reg->second.clear();
    }
}

// add sym to variables stores in reg
void update_reg_desc(string reg, qid* sym){
    for(auto it = reg_desc[reg].begin();it != reg_desc[reg].end(); it++){
        it->second->addr_descriptor.reg = "";
        qid temp = *it;
    }
    for(auto it = reg_desc.begin(); it != reg_desc.end(); it++){
        it->second.erase(*sym);
    }
    
    reg_desc[reg].clear();
    reg_desc[reg].insert(*sym);
    sym->second->addr_descriptor.stack = false;
    sym->second->addr_descriptor.reg = reg;
}

void initializeRegs(){
    reg_desc.insert(make_pair("%rax", set<qid> () ));
    reg_desc.insert(make_pair("%rcx", set<qid> () ));
    reg_desc.insert(make_pair("%rdx", set<qid> () ));
    reg_desc.insert(make_pair("%rbx", set<qid> () ));
    reg_desc.insert(make_pair("%rsi", set<qid> () ));
    reg_desc.insert(make_pair("%rdi", set<qid> () ));
}

// Get memmory location of a variable
// It can return a register or stack memory location
// -1: only stack mem location required!!
// 0: otherwise
// 1: for instructions which require size
// 2: specifically reqiures address to be passed on further to some other variable
string get_mem_location(qid* sym, qid* sym2, int idx, int flag){
    if(is_integer(sym->first)){
        return string("$" + sym->first);
    }

    if(sym->second->addr_descriptor.reg != "" && flag!=-1){
        if(!sym->second->is_derefer || flag == 2) return sym->second->addr_descriptor.reg;
        return "( " + sym->second->addr_descriptor.reg + " )";
    }
    
    //in stack
    int offset = sym->second->offset;
    sym->second->addr_descriptor.stack = true;


    string str = to_string(-offset-8)+"( rsp)";

    // if(sym->second->is_derefer && flag != -1){
    //     string reg = getTemporaryReg(sym2, idx);
    //     code_file<< "\tmov "<<reg<<", "<<str<<"\n";
    //     update_reg_desc(reg, sym);
    //     return "[ " + reg + " ]";
    // }
    return str;
}

string getTemporaryReg(qid* sym, int idx){
    string reg = "";
    int lim = INT_MAX;
    for(auto it : reg_desc){
        if((sym && it.second.find(*sym) != it.second.end()) || exclude_this.find(it.first) != exclude_this.end()){
            continue;
        }
        if(it.second.size() < lim){
            lim =  it.second.size();
            reg = it.first; 
        }
    }
    assert(reg != "");
    free_reg(reg);
    return reg;
}

string getReg(qid* sym, qid* result, qid* sym2, int idx){
    string reg = "";
    if(sym->second->addr_descriptor.reg != "") {
        reg = sym->second->addr_descriptor.reg;
        vector<qid> temp;
        for(auto it: reg_desc[reg]){
            if(it.first[0]!='#' && !(it.second->addr_descriptor.stack)){
                it.second->addr_descriptor.reg = "";
                string str = get_mem_location(&it, &empty_var, idx, -1);
                it.second->addr_descriptor.stack = 1;
                code_file << "\tmov " << reg << ", " << str <<"\n";
                temp.push_back(it);
            }
        }
        for(auto it: temp){
            reg_desc[reg].erase(it);
        }
        return reg;
    }

    reg = getTemporaryReg(sym2, idx);
    if(sym->first[0] == '\"'){
        stringlabels[string_cnt] = sym->first;
        code_file<<"\tmov $__str__"<<string_cnt<< ", "<< reg << "\n";
        string_cnt++;
    }
    else{
        string str = get_mem_location(sym, sym2, idx, -1);
        code_file << "\tmov " << str << ", "<< reg <<"\n";
        sym->second->addr_descriptor.reg = reg;
        reg_desc[reg].insert(*sym);
    }
    return reg;
}

void clear_regs(){
    for(auto reg = reg_desc.begin(); reg != reg_desc.end(); reg++){
        reg->second.clear();
    }
}

void free_reg(string reg){
    for(auto sym: reg_desc[reg]){
        if(is_integer(sym.first) || sym.second->addr_descriptor.reg !=reg) continue;
        
        sym.second->addr_descriptor.reg = "";
        string str = get_mem_location(&sym, &empty_var, -1, -1);
        code_file<<"\tmov "<< reg <<", "<<str<<"\n";
    }
    reg_desc[reg].clear();
}

//function starting
void gen_func_label(string func_name){
    code_file << "push rbp\n";
    code_file << "mov rsp, rbp\n"; 
    code_file << "sub "<< getFuncSize(func_name) << ", rsp" <<"\n";

}


void findBasicBlocks(){
    for(int i=0;i< (int)code.size(); i++){
        if(i == 0){
            leaders.insert(make_pair(i, get_label()));
            continue;
        }
        if(code[i].op.first == "GOTO"){
            leaders.insert(make_pair(code[i].idx, get_label()));
            leaders.insert(make_pair(i+1, get_label()));
        }   
    }
    leaders.insert(make_pair(code.size(), get_label()));
}