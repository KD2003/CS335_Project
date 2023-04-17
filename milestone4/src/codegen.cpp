#include "codegen.h"

map<string, set<qid> > reg_desc;
map<int ,string> leaders;
stack<qid> params;
map<int, string> stringlabels;
map<int, int> pointed_by;
map<qid, int> addr_pointed_to;

int string_cnt = 0;
int label_cnt = 0;
int arg_size = 0;
int in_func = 0;

set<string> exclude_this;
qid empty_var("",NULL);

extern ofstream code_file;
extern sym_table global_st;
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
        int s=4;
        for(int i=0; i<v.size(); i++){
            s*=v[i];
        }
        return s;
    }
    return 4;
}
// comment below code to compile
//----------------------------------------------------- Arithmetic Operators ----------------------------------------------------//

// // addtion operation
// void add_op(quad* instr){
//     if(is_integer(instr->arg1.first) && is_integer(instr->arg2.first)){
//         int val = (stoi(instr->arg1.first) + stoi(instr->arg2.first));
//         string str = get_mem_location(&instr->res, &empty_var, instr->idx, 0);
//         code_file << "\tmov " << str <<", " << "dword "<< val << "\n";
//     }
//     else{
//         string reg1 = getReg(&instr->arg1, &instr->res, &instr->arg2, instr->idx);
//         string mem2 = get_mem_location(&instr->arg2, &instr->arg1, instr->idx, 0);

//         if(instr->arg1.second->is_derefer){
//             string str = get_mem_location(&instr->arg1, &instr->arg2, instr->idx, -1);
//             code_file<<"\tmov "<<str <<", "<< reg1<<endl;
//             code_file<<"\tmov "<<reg1<<", [ "<<reg1<<" ]\n";
//         }
        
//         if(instr->arg1.second->isArray && !instr->arg2.second->isArray){
//             int size = giveArraySize(instr->arg1.second);
//             exclude_this.insert(reg1);
//             string temp_reg = getTemporaryReg(&instr->arg2, instr->idx);
//             exclude_this.erase(reg1);
//             code_file << "\tmov "<<temp_reg << ", "<< mem2<<"\n";
//             code_file << "\timul "<<temp_reg << ", "<< size<<"\n";
//             mem2 = temp_reg;
//         }
//         else if(instr->arg1.second->isArray && instr->arg2.second->isArray){
//             int size = giveArraySize(instr->arg1.second);
//             code_file << "\timul "<<reg1 << ", "<< size<<"\n";
//         }

//         code_file << "\tadd " << reg1 << ", " << mem2 <<endl;
//         update_reg_desc(reg1, &instr->res);
//     }
// }

// // subtraction operation
// void sub_op(quad* instr){
//     if(is_integer(instr->arg1.first) && is_integer(instr->arg2.first)){
//         int val = (stoi(instr->arg1.first) - stoi(instr->arg2.first));
//         string str = get_mem_location(&instr->res, &empty_var, instr->idx, 0);
//         code_file << "\tmov " << str <<", " << "dword "<< val << "\n";
//     }
//     else{        
//         string reg1 = getReg(&instr->arg1, &instr->res, &instr->arg2, instr->idx);
//         string mem2 = get_mem_location(&instr->arg2, &instr->arg1, instr->idx, 0);
        
//         if(instr->arg1.second->is_derefer){
//             string str = get_mem_location(&instr->arg1, &instr->arg2, instr->idx, -1);
//             code_file<<"\tmov "<<str <<", "<< reg1<<endl;
//             code_file<<"\tmov "<<reg1<<", [ "<<reg1<<" ]\n";
//         }

//         if(instr->arg1.second->isArray && !instr->arg2.second->isArray){
//             int size = giveArraySize(instr->arg1.second);
//             exclude_this.insert(reg1);
//             string temp_reg = getTemporaryReg(&instr->arg2, instr->idx);
//             exclude_this.erase(reg1);
//             code_file << "\tmov "<<temp_reg << ", "<< mem2<<"\n";
//             code_file << "\timul "<<temp_reg << ", "<< size<<"\n";
//             mem2 = temp_reg;
//         }
//         else if(!instr->arg1.second->isArray && instr->arg2.second->isArray ){
//                 int size = giveArraySize(instr->arg2.second);
//                 code_file << "\timul "<<reg1 << ", "<< size<<"\n";
//         }

//         code_file << "\tsub " << reg1 << ", " << mem2 <<endl;
//         update_reg_desc(reg1, &instr->res);
//     }
// }

// // multiplicative operation
// void mul_op(quad* instr){
//     if(is_integer(instr->arg1.first) && is_integer(instr->arg2.first)){
//         int val = (stoi(instr->arg1.first) * stoi(instr->arg2.first));
//         string str = get_mem_location(&instr->res, &empty_var, instr->idx, 0);
//         code_file << "\tmov " << str <<", " << "dword "<< val << "\n";
//     }
//     else{
//         string reg1 = getReg(&instr->arg1, &instr->res, &instr->arg2, instr->idx);
//         string mem2 = get_mem_location(&instr->arg2, &instr->arg1, instr->idx, 0);
        
//         if(instr->arg1.second->is_derefer){
//             string str = get_mem_location(&instr->arg1, &instr->arg2, instr->idx, -1);
//             code_file<<"\tmov "<<str <<", "<< reg1<<endl;
//             code_file<<"\tmov "<<reg1<<", [ "<<reg1<<" ]\n";
//         }
//         code_file << "\timul " << reg1 << ", " << mem2 <<endl;
//         update_reg_desc(reg1, &instr->res);
//     }
// }


// // CHECK
// // divison operation
// void div_op(quad* instr){
//     if(is_integer(instr->arg1.first) && is_integer(instr->arg2.first)){
//         int val = (stoi(instr->arg1.first) / stoi(instr->arg2.first));
//         string str = get_mem_location(&instr->res, &empty_var, instr->idx, 0);
//         code_file << "\tmov " << str <<", " << "dword "<< val << "\n";
//     }
//     else{
//         free_reg("eax");
//         free_reg("edx");
//         string str = get_mem_location(&instr->arg1, &instr->arg2, instr->idx, 0);
//         code_file<<"\tmov eax"<<", "<< str <<"\n";
//         reg_desc["eax"].insert(instr->arg1);
//         reg_desc["edx"].insert(instr->arg1);
        
//         exclude_this.insert("edx");
//         exclude_this.insert("eax");
//         string reg2 = getReg(&instr->arg2, &instr->res, &empty_var, instr->idx);
//         if(instr->arg2.second->is_derefer){ 
//             string str = get_mem_location(&instr->arg2, &instr->arg1, instr->idx, -1);
//             code_file<<"\tmov "<<str <<", "<< reg2<<endl;
//             code_file<<"\tmov "<<reg2<<", [ "<<reg2<<" ]\n";
//         }
//         exclude_this.clear(); 

//         code_file<<"\tcdq\n";
//         code_file<<"\tidiv "<<reg2<<"\n";

//         instr->res.second->addr_descriptor.reg = "eax";
//         reg_desc["eax"].clear();
//         reg_desc["edx"].clear();
//         reg_desc["eax"].insert(instr->res);
//     }
// }

// // modulo operation
// void mod_op(quad* instr){
//     if(is_integer(instr->arg1.first) && is_integer(instr->arg2.first)){
//         int val = (stoi(instr->arg1.first) % stoi(instr->arg2.first));
//         string str = get_mem_location(&instr->res, &empty_var, instr->idx, 0);
//         code_file << "\tmov " << str <<", " << "dword "<< val << "\n";
//     }
//     else{
//         free_reg("eax");
//         free_reg("edx");
//         string str = get_mem_location(&instr->arg1,&instr->arg2, instr->idx, 0);
//         code_file<<"\tmov eax"<<", "<< str <<"\n";
//         reg_desc["eax"].insert(instr->arg1);
//         reg_desc["edx"].insert(instr->arg1);
//         string reg2 = getReg(&instr->arg2, &instr->res, &empty_var, instr->idx);
//         if(instr->arg2.second->is_derefer){
//             string str = get_mem_location(&instr->arg2, &instr->arg1, instr->idx, -1);
//             code_file<<"\tmov "<<str <<", "<< reg2<<endl;
//             code_file<<"\tmov "<<reg2<<", [ "<<reg2<<" ]\n";
//         }

//         code_file<<"\tcdq\n";
//         code_file<<"\tidiv "<<reg2<<"\n";
//         instr->res.second->addr_descriptor.reg = "edx";
//         reg_desc["eax"].clear();
//         reg_desc["edx"].clear();
//         reg_desc["edx"].insert(instr->res);
//     }
// }

// //----------------------------------------------------- Conditional Operators----------------------------------------------------//

// // logical and operation (&&)
// void logic_and(quad *instr){
    
//     if(is_integer(instr->arg1.first) && is_integer(instr->arg2.first)){
//         int a = stoi(instr->arg1.first);
//         int b = stoi(instr->arg2.first);
//         string reg = get_mem_location(&instr->res, &empty_var, instr->idx, 1);
//         if(a && b){
//             code_file << "\tmov "<<reg<<", dword "<<1<<"\n";
//         }
//         else{
//             code_file << "\tmov "<<reg<<", dword "<<0<<"\n";
//         }
//     }
//     else{
//         string l1 = "", l2 = "";
//         l1 = get_label();
//         l2 = get_label();
//         string reg = getReg(&instr->arg1, &instr->res, &instr->arg2, instr->idx);    
//         if(instr->arg1.second->is_derefer){
//             string str = get_mem_location(&instr->arg1, &instr->arg2, instr->idx, -1);
//             code_file<<"\tmov "<<str <<", "<< reg<<endl;
//             code_file<<"\tmov "<<reg<<", [ "<<reg<<" ]\n";
//         }

//         string mem2 = getReg(&instr->arg2, &empty_var, &instr->arg1, instr->idx);
    
//         code_file << "\tcmp "<<reg<<", dword "<<0<<"\n";
//         code_file << "\tje "<<l1<<"\n";
//         code_file << "\tcmp "<<mem2<<", dword "<<0<<"\n";
//         code_file << "\tje "<<l1<<"\n";
//         code_file << "\tmov "<<reg<<", dword "<<1<<"\n";
//         code_file << "\tjmp "<<l2<<"\n";
//         code_file << l1 <<":\n";
//         code_file << "\tmov "<<reg<<", dword "<<0<<"\n";
//         code_file << l2 <<":\n";
//         update_reg_desc(reg, &instr->res);
//     }
// }

// // Logical or operation (||)
// void logic_or(quad *instr){
    
//     if(is_integer(instr->arg1.first) && is_integer(instr->arg2.first)){
//         int a = stoi(instr->arg1.first);
//         int b = stoi(instr->arg2.first);
//         string reg = get_mem_location(&instr->res, &empty_var, instr->idx, 1);
//         if(a || b){
//             code_file << "\tmov "<< reg <<", dword "<<1<<"\n";
//         }
//         else{
//             code_file << "\tmov "<<reg<<", dword "<<0<<"\n";
//         }
//     }
//     else{
//         string l1 = "", l2 = "";
//         l1 = get_label();
//         l2 = get_label();
//         string reg = getReg(&instr->arg1, &instr->res, &instr->arg2, instr->idx);    
//         if(instr->arg1.second->is_derefer){
//             string str = get_mem_location(&instr->arg1, &instr->arg2, instr->idx, -1);
//             code_file<<"\tmov "<<str <<", "<< reg<<endl;
//             code_file<<"\tmov "<<reg<<", [ "<<reg<<" ]\n";
//         }

//         string mem2 = getReg(&instr->arg2, &empty_var, &instr->arg1, instr->idx);

//         code_file << "\tcmp "<<reg<<", dword "<<0<<"\n";
//         code_file << "\tjne "<<l1<<"\n";
//         code_file << "\tcmp "<<mem2<<", dword "<<0<<"\n";
//         code_file << "\tjne "<<l1<<"\n";
//         code_file << "\tmov "<<reg<<", dword "<<0<<"\n";
//         code_file << "\tjmp "<<l2<<"\n";
//         code_file << l1 <<":\n";
//         code_file << "\tmov "<<reg<<", dword "<<1<<"\n";
//         code_file << l2 <<":\n";
//         update_reg_desc(reg, &instr->res);
//     }
// }


// void comparison_op(quad* instr){
//     string op = instr->op.first;
//     string l1 = "", l2 = "";
//     l1 = get_label();
//     l2 = get_label();
        
//     if(is_integer(instr->arg1.first) && is_integer(instr->arg2.first)){
//         int val = 0;
        
//         if(op == "==")      val = (stoi(instr->arg1.first)  ==  stoi(instr->arg2.first));
//         else if(op == "<")  val = (stoi(instr->arg1.first)  <   stoi(instr->arg2.first));
//         else if(op == "<=") val = (stoi(instr->arg1.first)  <=  stoi(instr->arg2.first));
//         else if(op == ">")  val = (stoi(instr->arg1.first)  >   stoi(instr->arg2.first));
//         else if(op == ">=") val = (stoi(instr->arg1.first)  >=  stoi(instr->arg2.first));
//         else if(op == "!=") val = (stoi(instr->arg1.first)  !=  stoi(instr->arg2.first));
        
//         string mem = get_mem_location(&instr->res, &empty_var, instr->idx, 1);
//         code_file << "\tmov " << mem <<", " << "dword "<< val << "\n";
//         return;
//     }

//     string reg = getReg(&instr->arg1, &empty_var, &instr->arg2, instr->idx);
    
//     if(instr->arg1.second->is_derefer){
//         string str = get_mem_location(&instr->arg1, &instr->arg2, instr->idx, -1);
//         code_file<<"\tmov "<<str <<", "<< reg<<endl;
//         code_file<<"\tmov "<<reg<<", [ "<<reg<<" ]\n";
//     }

//     string jump_instruction = "";
    
//     if(op == "==")      jump_instruction = "je";
//     else if(op == "<")  jump_instruction = "jl";
//     else if(op == "<=") jump_instruction = "jle";
//     else if(op == ">")  jump_instruction = "jg";
//     else if(op == ">=") jump_instruction = "jge";
//     else if(op == "!=") jump_instruction = "jne";

//     string mem2 = get_mem_location(&instr->arg2, &instr->arg1, instr->idx, 0);

//     code_file << "\tcmp "<<reg<<", " << mem2 <<"\n";
//     code_file << "\t"<<jump_instruction << " "<<l1<<"\n";
//     code_file << "\tmov " << reg <<", " << "dword 0"<<"\n";
//     code_file << "\tjmp " << l2 <<"\n";
//     code_file << l1 << ":"<<"\n";
//     code_file << "\tmov " << reg <<", " << "dword 1"<<"\n";
//     code_file << l2 <<":" <<"\n";
//     update_reg_desc(reg, &instr->res);
// }


// //----------------------------------------------------- Bitwise operators ----------------------------------------------------//


// // Left shift operation
// void lshift_op(quad* instr){
//     exclude_this.insert("ecx");
//     string reg1 = getReg(&instr->arg1, &instr->res, &instr->arg2, instr->idx);
    
//     if(instr->arg1.second->is_derefer) {
//         string str = get_mem_location(&instr->arg1, &instr->arg2, instr->idx, -1);
//         code_file<<"\tmov "<<str <<", "<< reg1<<endl;
//         code_file<<"\tmov "<<reg1<<", [ "<<reg1<<" ]\n";
//     }

//     free_reg("ecx");
//     string mem2 = get_mem_location(&instr->arg2, &instr->arg1, instr->idx, 0);
//     code_file << "\tmov " << "ecx" << ", " << mem2 <<"\n";
//     mem2 = "cl";    
//     code_file << "\tshl " << reg1 << ", " << mem2 <<"\n";
//     exclude_this.clear();
//     update_reg_desc(reg1, &instr->res);
// }

// // Right Shift operation
// void rshift_op(quad* instr){
//     exclude_this.insert("ecx");
//     string reg1 = getReg(&instr->arg1, &instr->res, &instr->arg2, instr->idx);
    
//     if(instr->arg1.second->is_derefer) {
//         string str = get_mem_location(&instr->arg1, &instr->arg2, instr->idx, -1);
//         code_file<<"\tmov "<<str <<", "<< reg1<<endl;
//         code_file<<"\tmov "<<reg1<<", [ "<<reg1<<" ]\n";
//     }

//     free_reg("ecx");
//     string mem2 = get_mem_location(&instr->arg2, &instr->arg1, instr->idx, 0);
//     code_file << "\tmov " << "ecx" << ", " << mem2 <<"\n";
//     mem2 = "cl";    
//     code_file << "\tsar " << reg1 << ", " << mem2 <<"\n";
//     exclude_this.clear();
//     update_reg_desc(reg1, &instr->res);
// }

// void bitwise_op(quad* instr){
//     string op = instr->op.first;

//     if(is_integer(instr->arg1.first) && is_integer(instr->arg2.first)){
//         int val = 0;
        
//         if(op[0] == '^')        val = (stoi(instr->arg1.first) ^ stoi(instr->arg2.first));
//         else if(op[0] == '&')   val = (stoi(instr->arg1.first) & stoi(instr->arg2.first));
//         else if(op[0] == '|')   val = (stoi(instr->arg1.first) | stoi(instr->arg2.first));
        
//         string mem = get_mem_location(&instr->res, &empty_var, instr->idx, 1);
//         code_file << "\tmov " << mem <<", " << "dword "<< val << "\n";
//         return;
//     }
//     string reg = getReg(&instr->arg1, &instr->res, &instr->arg2, instr->idx);
    
//     if(instr->arg1.second->is_derefer){
//         string str = get_mem_location(&instr->arg1, &instr->arg2, instr->idx, -1);
//         code_file<<"\tmov "<<str <<", "<< reg<<endl;
//         code_file<<"\tmov "<<reg<<", [ "<<reg<<" ]\n";
//     }

//     string instruction = "";
    
//     if(op[0] == '^')      instruction = "xor";
//     else if(op[0] == '&') instruction = "and";
//     else if(op[0] == '|') instruction = "or";
    
//     string mem2 = get_mem_location(&instr->arg2, &instr->arg1, instr->idx, 0);
//     code_file << "\t"<<instruction<< " "<<reg <<", "<<mem2 <<"\n";
//     update_reg_desc(reg, &instr->res);
// }

// //----------------------------------------------------- Assignment ----------------------------------------------------//

// void assign_op(quad* instr){
//     // for global variables
//     if(!in_func){
//         if(instr->res.first == "array_init") return;
//         globaldecl[instr->res.first].first = instr->arg1.first;
//         return;
//     }
//     // *x = 1
//     if(instr->res.second->is_derefer){
//         string res_mem = getReg(&instr->res, &empty_var, &instr->arg1, -1);
//         string arg1_mem = getReg(&instr->arg1, &empty_var, &instr->res, -1);
//         res_mem = "[ " + res_mem + " ]";

//         if(instr->arg1.second->is_derefer){
//             code_file<<"\tmov "<<arg1_mem <<", [ "<<arg1_mem<<" ]"<<"\n";
//         }
//         code_file<<"\tmov "<<res_mem<<", "<<arg1_mem<<"\n";
//     }
//     // x = 1
//     else if(is_integer(instr->arg1.first)){
//         string mem = get_mem_location(&instr->res, &instr->arg1, instr->idx, 1);
//         if(reg_desc.find(mem) != reg_desc.end()){
//             free_reg(mem);
//             update_reg_desc(mem, &instr->res);
//         }
//         code_file << "\tmov "<< mem << ", dword "<< instr->arg1.first <<endl;
//     }
//     // for user defined types 
//     else if(typeLookup(instr->res.second->type)){
        
//         for(auto it: reg_desc){
//             free_reg(it.first);
//         }

//         string reg = getTemporaryReg(&empty_var, instr->idx);
//         int res_offset = instr->res.second->offset, temp_offset = instr->arg1.second->offset;
//         int struct_size = getStructsize(instr->res.second->type);
        
//         for(int i = 0; i<struct_size; i+=4){
//             code_file<<"\tmov "<<reg<<", [ ebp - "<<temp_offset + 4 + i<<" ]\n";
//             code_file<<"\tmov [ ebp - "<<res_offset + 4 + i<<" ], "<<reg<<"\n";
//         }
//     } 
//     // x = y
//     else{
//         string reg = getReg(&instr->arg1, &instr->res, &empty_var, instr->idx);
        
//         if(instr->arg1.second->is_derefer){
//             code_file<<"\tmov "<<reg <<", [ "<<reg<<" ]"<<"\n";
//             update_reg_desc(reg, &instr->res);        
//         }
//         else {
//             reg_desc[reg].insert(instr->res);
//             string prev_reg = instr->res.second->addr_descriptor.reg;
//             if(prev_reg != "") reg_desc[prev_reg].erase(instr->res);
//             instr->res.second->addr_descriptor.reg = reg;
//         }

//         if(instr->res.first=="array_init"){
//             string tem = get_mem_location(&instr->res,&empty_var,instr->idx,-1);
//             code_file << "\tmov " << tem << ", " << reg << "\n";
//             free_reg(reg);
//         }

//         if(instr->res.second->type[instr->res.second->type.length()-1] == '*'){
//             pointed_by[addr_pointed_to[instr->arg1]] = 1;
//         }

//         if(pointed_by[instr->res.second->offset]){
//             string reg_stored = instr->res.second->addr_descriptor.reg;
//             instr->res.second->addr_descriptor.reg = "";
//             reg_desc[reg_stored].erase(instr->res);
//             string str = get_mem_location(&instr->res, &instr->arg1, instr->idx, 0);
//             code_file<<"\tmov "<< str <<", "<<reg_stored<<"\n";
//         }

//         instr->res.second->addr_descriptor.stack = 0;
//     }
// }



// //----------------------------------------------------- Unary Operators ----------------------------------------------------//

// void unary_op(quad* instr){
//     string op = instr->op.first;
//     string temp;
   
//     string reg = getReg(&instr->arg1, &instr->res, &instr->arg2, instr->idx);
//     temp =reg;

//     string instruction = "";
//     if(op[2] == 'P'){
//         // TODO
//         if(op == "++P")      instruction = "inc";
//         else if(op == "--P") instruction = "dec";
        
//         if(instr->arg1.second->is_derefer){
//             string reg = getReg(&instr->arg1, &instr->res, &instr->arg2, instr->idx);
//             string reg1 = getTemporaryReg(&instr->arg1, instr->idx);

//             reg = "[ " + reg + " ]";

//             code_file<<"\tmov "<<reg1<<", "<<reg<<endl;
//             code_file<<"\t"<<instruction<<" "<<reg1<<endl;
//             code_file<<"\tmov "<<reg<<", "<<reg1<<endl;
//             update_reg_desc(reg1, &instr->res);
//         }
//         else{
//             string reg = getReg(&instr->arg1, &instr->res, &instr->arg2, instr->idx);
//             code_file<<"\t"<<instruction<<" "<<reg<<endl;
//             free_reg(reg);
//             update_reg_desc(reg, &instr->res);
//         }
        
//     }
//     else if(op[2] == 'S'){
//         if(op == "++S")      instruction = "inc";
//         else if(op == "--S") instruction = "dec";
        
//         if(instr->arg1.second->is_derefer){
//             string reg = getReg(&instr->arg1, &instr->res, &instr->arg2, instr->idx);
//             string reg1 = getTemporaryReg(&instr->arg1, instr->idx);

//             reg = "[ " + reg + " ]";
//             code_file<<"\tmov "<<reg1<<", "<<reg<<endl;
//             update_reg_desc(reg1, &instr->res);

//             code_file<<"\t"<<instruction<<" "<<reg1<<endl;
//             code_file<<"\tmov "<<reg<<", "<<reg1<<endl;
//         }
//         else{
//             string reg = getReg(&instr->arg1, &instr->res, &instr->arg2, instr->idx);
//             string reg1 = getTemporaryReg(&instr->arg1, instr->idx);
//             code_file<<"\tmov "<<reg1<<", "<<reg<<endl;
//             update_reg_desc(reg1, &instr->res);

//             code_file<<"\t"<<instruction<<" "<<reg<<endl;
//             string str = get_mem_location(&instr->arg1, &empty_var,instr->idx,-1);
//             code_file<<"\tmov "<<str<<", "<<reg<<"\n";
//         }
//     }
//     else if(op =="~" ) {
//         instruction = "not";
//         string reg1 = getTemporaryReg(&instr->arg1, instr->idx);
//         if(instr->arg1.second->is_derefer){
//             reg = "[ " + reg + " ]";
//         }

//         code_file<<"\tmov "<<reg1<<", "<<reg<<"\n";
//         code_file << "\t"<<instruction<< " "<<reg1<<"\n";        
//         update_reg_desc(reg1, &instr->res);
//     }
//     else if(op == "unary-"){
//         instruction = "neg";
//         string reg1 = getTemporaryReg(&instr->arg1, instr->idx);
        
//         if(instr->arg1.second->is_derefer){
//             reg = "[ " + reg + " ]";
//         }

//         code_file<<"\tmov "<<reg1<<", "<<reg<<"\n";
//         code_file << "\t"<<instruction<< " "<<reg1<<"\n";        
//         update_reg_desc(reg1, &instr->res);
//     }
//     else if(op == "unary+"){
//         reg_desc[reg].insert(instr->res);
//         instr->res.second->addr_descriptor.reg = reg;
//     }
//     else if(op == "!"){
//         string l1 = get_label();
//         string l2 = get_label();
//         string reg1 = getTemporaryReg(&instr->arg1, instr->idx);
        
//         if(instr->arg1.second->is_derefer){
//             reg = "[ " + reg + " ]";
//         }

//         code_file<<"\tmov "<<reg1<<", "<<reg<<"\n";
//         code_file << "\tcmp "<<reg1<<", dword "<<0<<"\n";  //dword inserted
//         code_file << "\tje "<<l1<<"\n";
//         code_file << "\tmov "<<reg1<<", dword "<<0<<"\n";
//         code_file << "\tjmp "<<l2<<"\n";
//         code_file << l1 <<":\n";
//         code_file << "\tmov "<<reg1<<", dword "<<1<<"\n";
//         code_file << l2 <<":\n";
//         update_reg_desc(reg1, &instr->res);
//     }
// }

// //----------------------------------------------------- Miscellaneous operations ----------------------------------------------------//


// // member access for pointer of user defined data type
// void ptr_op(quad* instr){
    
//     string reg = getReg(&instr->arg1, &instr->res, &instr->arg2, instr->idx);
//     if(instr->arg1.second->is_derefer){
//         string str = get_mem_location(&instr->arg1, &instr->arg2, instr->idx, -1);
//         code_file<<"\tmov "<<str <<", "<< reg<<endl;
//         code_file<<"\tmov "<<reg<<", [ "<<reg<<" ]\n";
//     }
//     code_file<<"\tadd "<<reg<<", "<<instr->arg2.second->offset<<"\n";

//     if(!instr->arg2.second->isArray) instr->res.second->is_derefer = 1;
//     update_reg_desc(reg, &instr->res);
// }

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

// // referencing element of an array 
// void array_op(quad* instr){
//         string reg = getReg(&instr->res, &empty_var, &instr->arg2, instr->idx);
//         string mem, str;
        
//         if(instr->arg1.second->isArray && !instr->arg1.second->is_global) {
//             if(instr->arg1.second->addr_descriptor.reg != ""){
//                 string temp_reg = instr->arg1.second->addr_descriptor.reg;
//                 instr->arg1.second->addr_descriptor.reg = "";
//                 str = get_mem_location(&instr->arg1, &instr->arg2, instr->idx, 0);
//                 code_file<<"\tmov "<< str <<", "<<temp_reg<<"\n"; 
//             }
//             mem = get_mem_location(&instr->arg1, &instr->arg2, instr->idx, 0);
//             code_file<<"\tlea "<<reg<<", "<<mem<<"\n";
//         }
//         else {
//             mem = get_mem_location(&instr->arg1, &instr->arg2, instr->idx, 0);
//             code_file<<"\tmov "<<reg<<", "<<mem<<"\n";
//         }
        
//         exclude_this.insert(reg);
//         string reg1 = getReg(&instr->arg2, &empty_var, &instr->arg1, instr->idx);
//         if(instr->arg2.second->is_derefer){
//             string str = get_mem_location(&instr->arg1, &instr->arg2, instr->idx, -1);
//             code_file<<"\tmov "<<str <<", "<< reg1<<endl;
//             code_file<<"\tmov "<<reg1<<", [ "<<reg1<<" ]\n";
//         }

//         if(instr->arg1.second->type == "char*"){
//             if(instr->arg1.second->array_dims.empty()) code_file<<"\timul "<<reg1<<", "<<1<<"\n";
//             else code_file<<"\timul "<<reg1<<", "<<1*instr->arg1.second->array_dims[0]<<"\n";
//         }
//         else{
//             if(instr->arg1.second->array_dims.empty()) code_file<<"\timul "<<reg1<<", "<<getSize(instr->res.second->type)<<"\n";
//             else code_file<<"\timul "<<reg1<<", "<<getSize(instr->res.second->type)*instr->arg1.second->array_dims[0]<<"\n";
//         }
       
//         code_file<<"\tadd "<<reg<<", "<<reg1<<"\n";
//         if(instr->arg1.second->array_dims.empty()) instr->res.second->is_derefer = 1;
        
//         exclude_this.clear();
//         reg_desc[reg1].erase(instr->arg2);
//         instr->arg2.second->addr_descriptor.reg = "";
        
//         update_reg_desc(reg, &instr->res);

// }

// //----------------------------------------------------- Return and Goto ----------------------------------------------------//

// // returning from a function
// void return_op(quad* instr){
//     if(instr->arg1.first != ""){
//         if(typeLookup(instr->arg1.second->type)){
//             for(auto it: reg_desc){
//                 free_reg(it.first);
//             }
//             string reg1 = getTemporaryReg(&empty_var, instr->idx);
            
//             exclude_this.insert(reg1);
            
//             string reg2 = getTemporaryReg(&empty_var, instr->idx);
//             exclude_this.clear();
            
//             code_file<<"\tmov "<<reg1<<", [ ebp + "<<arg_size<<" ]\n";
            
//             int struct_size = getStructsize(instr->arg1.second->type);
//             int struct_offset = instr->arg1.second->offset;
//             if(instr->arg1.second->offset < 0){
//                 for(int i = 0; i<struct_size; i+=4){
//                     code_file<<"\tmov "<<reg2<<", [ ebp + "<<abs(struct_offset) - i<<" ]\n";
//                     code_file<<"\tmov [ "<<reg1<<" + "<<struct_size - i - 4<<" ], "<<reg2<<"\n";
//                 }
//             }
//             else{
//                 for(int i = 0; i<struct_size; i+=4){
//                     code_file<<"\tmov "<<reg2<<", [ ebp - "<<struct_offset + 4 + i<<" ]\n";
//                     code_file<<"\tmov [ "<<reg1<<" + "<<struct_size - i - 4<<" ], "<<reg2<<"\n";
//                 }
//             }
//             code_file<<"\tleave\n";
//             code_file<<"\tret\n";
//         }
//         else{
//             string mem = get_mem_location(&instr->arg1, &empty_var, instr->idx, 1);
//             if(mem != "eax") code_file<<"\tmov eax, "<<mem<<"\n";
//             code_file<<"\tleave\n";
//             code_file<<"\tret\n";
//         }
//     }
//     else{
//         code_file<<"\txor eax, eax\n";
//         code_file<<"\tleave\n";
//         code_file<<"\tret\n";
//     }
// }

// // Goto operation
// void goto_op(quad* instr){
//     end_basic_block();
//     int id = instr->idx;
//     if(instr->arg1.first == "IF"){
//         string reg = get_mem_location(&instr->arg2, &instr->arg1, id, 1);
//         if(is_integer(instr->arg2.first)) reg = getReg(&instr->arg2, &empty_var, &empty_var, instr->idx);
//         code_file << "\tcmp " << reg <<", " << "dword 0"<<"\n";
//         code_file << "\tjne "<<leaders[id]<<"\n";
//     }
//     else{
//         code_file << "\tjmp " << leaders[id] <<"\n";
//     }
// }


// //----------------------------------------------------- Function Call ----------------------------------------------------//

// void call_func(quad *instr){

//     for(auto it: reg_desc){
//         free_reg(it.first);
//     }

//     int curr_reg = 0;
//     int i = stoi(instr->arg2.first);
//     int sz = i;

//     sym_entry* func_entry = lookup(instr->arg1.first);
//     string ret_type = "";
//     if(func_entry) ret_type = func_entry->type.substr(5, func_entry->type.length()-5);
    
//     if(typeLookup(ret_type)){
//         code_file<<"\tlea eax, "<<get_mem_location(&instr->res, &empty_var, -1, -1)<<"\n";
//         code_file<<"\tpush eax\n";
//     }

//     while(i>0){
//         if(params.top().first[0] == '\"'){            
//             stringlabels.insert({string_cnt, params.top().first});
//             code_file<<"\tpush __str__"<<string_cnt<<"\n";
//             string_cnt++;
//         }
//         else if(typeLookup(params.top().second->type)){
//             int type_size = getSize(params.top().second->type), type_offset = params.top().second->offset;
            
//             if(params.top().second->is_derefer) {
//                 string reg = getReg(&params.top(), &empty_var, &empty_var, instr->idx);
                
//                 for(int i = type_size - 4; i>=0; i-=4){
//                     code_file<<"\tpush dword [ "<<reg<<" + "<<i<<" ]\n";
//                 }
//             }
//             else {
//                 if(type_offset > 0){
//                     for(int i = type_offset; i<type_size + type_offset; i+=4){
//                         code_file<<"\tpush dword [ ebp - "<<i+4<<" ]\n";
//                     }
//                 }
//                 else{
//                     for(int i = 0; i<type_size; i+=4){
//                         code_file<<"\tpush dword [ ebp + "<<abs(type_offset+i)<<" ]\n";
//                     }
//                 }
//             }
//         }
//         else if(params.top().second->is_derefer){
//             string mem;
//             mem = get_mem_location(&params.top(), &empty_var, instr->idx, 1);
//             code_file<<"\tpush dword "<<mem<<"\n";
//         }
//         else if(params.top().second->isArray){
//             string str = get_mem_location(&params.top(), &empty_var, instr->idx, 1);
//             code_file<<"\tlea eax, "<< str <<"\n";
//             code_file<<"\tpush eax\n";
//         }
//         else{
//             string mem = get_mem_location(&params.top(), &empty_var, instr->idx, 1);
            
//             if(reg_desc.find(mem) == reg_desc.end() && mem.substr(0,5) != "dword") mem = "dword "+mem;
//             code_file<<"\tpush "<<mem<<"\n";
            
//         }
//         i--;
//         params.pop();
//     }
    
//     code_file<<"\tcall "<<instr->arg1.first<<"\n";
    
//     if(!typeLookup(ret_type)){
//         reg_desc["eax"].insert(instr->res);
//         instr->res.second->addr_descriptor.reg = "eax";
//     }
//     else sz++;

//     // Clear args from stack
//     code_file<<"\tadd esp, "<<4*sz<<"\n";
// }

// // convert char to its ASCII value
// string char_to_int(string sym){
//     if(sym[0]!='\'')return sym;
//     if(sym[1] == '\\'){
//         string s = sym.substr(1,2);
//         if(s == "\\0") return "0";
//         if(s == "\\n") return "10";
//         if(s == "\\t") return "9";
//     } 
//     int val = (int )sym[1];
//     sym = to_string(val);
//     return sym;
// }


// //----------------------------------------------------- Main function and helper functions----------------------------------------------------//

// // main function which calls other function
void genCode(){
    findBasicBlocks();

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
            
    //         if(instr.op.first.substr(0, 5) == "FUNC_" && instr.op.first[(instr.op.first.size() - 3)] == 't'){
    //             in_func = 1;
    //             gen_func_label(&instr);
    //         }
    //         else if(instr.op.first.substr(0,2) == "++"  
    //                 ||instr.op.first.substr(0,2) == "--" 
    //                 ||instr.op.first == "!" 
    //                 ||instr.op.first == "~" 
    //                 ||instr.op.first == "unary-" 
    //                 ||instr.op.first == "unary+") unary_op(&instr);
    //         else if(instr.op.first[0] == '+')    add_op(&instr);
    //         else if(instr.op.first == "=")   assign_op(&instr);
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
    //         else if(instr.op.first == "RETURN"){
    //             return_op(&instr);
    //         }
    //         else if(instr.op.first == "param") params.push(instr.arg1);
    //         else if(instr.op.first == "CALL") call_func(&instr);
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
    //         // else if(instr.op.first == "PTR_OP") ptr_op(&instr);
    //         else if(instr.op.first == "member_access") member_access(&instr);
    //         else if(instr.op.first == "[ ]") array_op(&instr);
    //     }
    //     end_basic_block();
    }

    print_string_labels();
}

// print the data section for the asm file
void print_string_labels(){
    for(auto it: stringlabels){
        code_file<<"__str__"<<it.first<<": db "<<it.second<<", 0\n";
    }
}

// save the values of variables when going out of basic block
void end_basic_block(){
    for(auto reg = reg_desc.begin();reg!=reg_desc.end();reg++){
        for(auto sym =reg->second.begin() ;sym!=reg->second.end(); sym++){
            if(is_integer(sym->first)) continue;
            sym->second->addr_descriptor.reg = "";
            qid tem = *sym;
            string str = get_mem_location(&tem, &empty_var, -1, -1); 
            code_file<<"\tmov " << str <<", "<<reg->first<<"\n";
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
    reg_desc.insert(make_pair("rax", set<qid> () ));
    reg_desc.insert(make_pair("rcx", set<qid> () ));
    reg_desc.insert(make_pair("rdx", set<qid> () ));
    reg_desc.insert(make_pair("rbx", set<qid> () ));
    reg_desc.insert(make_pair("rsi", set<qid> () ));
    reg_desc.insert(make_pair("rdi", set<qid> () ));
}

// Get memmory location of a variable
// It can return a register or stack memory location
// -1: only stack mem location required!!
// 0: otherwise
// 1: for instructions which require size
// 2: specifically requres address to be passed on further to some other variable
string get_mem_location(qid* sym, qid* sym2, int idx, int flag){
    // if(sym->second->is_global){
    //     if(globaldecl[sym->first].second == 0) return string('['+sym->first+']');
    //     else return sym->first;
    // }
    if(is_integer(sym->first)){
        if(flag) return string("dword " + sym->first);
        else return sym->first;
    }

    if(sym->second->addr_descriptor.reg != "" && flag!=-1){
        if(!sym->second->is_derefer || flag == 2) return sym->second->addr_descriptor.reg;
        return "[ " + sym->second->addr_descriptor.reg + " ]";
    }
    
    //Symbol in stack
    int offset = sym->second->offset;
    int size = sym->second->size;
    string str;
    sym->second->addr_descriptor.stack = true;
    if(offset >= 0) str = string("[ ebp - " + to_string(offset + size) + " ]");
    else{
        offset=-offset;
        str = string("[ ebp + "+to_string(offset) +" ]");
    }
    if(sym->second->is_derefer && flag != -1){
        string reg = getTemporaryReg(sym2, idx);
        code_file<< "\tmov "<<reg<<", "<<str<<"\n";
        update_reg_desc(reg, sym);
        return "[ " + reg + " ]";
    }

    return str;
}

// Get a temporary register
string getTemporaryReg(qid* exclude_symbol, int idx){
    string reg = "";
    int mn = 1000000;
    for(auto it : reg_desc){
        if((exclude_symbol && it.second.find(*exclude_symbol) != it.second.end()) || exclude_this.find(it.first) != exclude_this.end()){
            // skip the reg containing second argument for an instruction
            continue;
        }
        if(it.second.size() < mn){
            mn =  it.second.size();
            reg = it.first; 
        }
    } 
    assert(reg != "");
    free_reg(reg);
    return reg;
}

// allocates a register to a variable
// efficient allocation is done to minise load or store
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
                code_file << "\tmov " << str << ", " << reg <<endl;
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
        code_file<<"\tmov "<<reg<<", __str__"<<string_cnt<<"\n";
        string_cnt++;
    }
    else{
        string str = get_mem_location(sym, sym2, idx, -1);
        code_file << "\tmov " << reg << ", "<< str <<"\n";
        sym->second->addr_descriptor.reg = reg;
        reg_desc[reg].insert(*sym);
    }
    return reg;
}

// Clear all the registers
void clear_regs(){
    for(auto reg = reg_desc.begin(); reg != reg_desc.end(); reg++){
        reg->second.clear();
    }
}

// free a specific register
void free_reg(string reg){
    for(auto sym: reg_desc[reg]){
        if(is_integer(sym.first)) continue;
        
        sym.second->addr_descriptor.reg = "";
        string str = get_mem_location(&sym, &empty_var, -1, -1);
        code_file<<"\tmov "<< str <<", "<<reg<<"\n";
    }
    reg_desc[reg].clear();
}

// // function prologue
// void gen_func_label(quad* instr){
//     string s = "";
//     for(int i=5;i<instr->op.first.size(); i++){
//         if(instr->op.first[i] == ' ')break;
//         s += instr->op.first[i];
//     }

//     arg_size = 0;
//     sym_entry* func_entry = lookup(s);
//     for(auto it: *(func_entry->entry)){
//         if(it.second->offset < 0){
//             arg_size = max(arg_size, abs(it.second->offset));
//         }
//     }
//     if(arg_size) arg_size+=4;
//     else arg_size = 8;

//     code_file << s << " :\n";
//     code_file << "\tpush ebp\n";
//     code_file << "\tmov ebp, esp\n"; 
//     code_file << "\tsub esp, "<<func_local_size(s)<<"\n";

//     pointed_by.clear();
// }


 // Finds Basic block in 3AC code.
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