#include "codegen.h"

map<string, set<qid> > reg_desc;
map<int ,string> leaders;
stack<qid>  params;
map<int, string> stringlabels;
map<int, int> pointed_by;
map<qid, int> addr_pointed_to;

int string_counter = 0;
int label_counter = 0;
int arg_size = 0;
int in_func = 0;

set<string> exclude_this;

qid empty_var("",NULL);

extern ofstream code_file;
extern sym_table global_st;




// string get_label(){
//     return "L" +to_string(label_counter++);
// }

// void gen_data_section(){
//     for(auto it: func_usage_map){
//         if(it.second) code_file << "extern "<<it.first<<"\n";
//     }
// }

// void starting_code(){
//     code_file << "\nsection .text\n";
//     code_file << "\tglobal main\n";
// }

// int is_integer(string sym){
//     for(int i=0; i<sym.length(); i++){
//         if(sym[i] >= '0' && sym[i]<='9'){
//             continue;
//         }
//         else return 0;
//     }
//     return 1;
// }

// int is_pointerType(string type){
//     if(type[type.length() - 1] == '*'){
//         return 1;
//     }
//     return 0;
// }

// int give_size(sym_entry* entry){
//     vector<int> v = entry->array_dims;
//     if(!v.empty()){
//         int s=4;
//         for(int i=0; i<v.size(); i++){
//             s*=v[i];
//         }
//         return s;
//     }
//     return 4;
// }
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
        
//         if(is_pointerType(instr->arg1.second->type) && !is_pointerType(instr->arg2.second->type)){
//             int size = give_size(instr->arg1.second);
//             exclude_this.insert(reg1);
//             string temp_reg = getTemporaryReg(&instr->arg2, instr->idx);
//             exclude_this.erase(reg1);
//             code_file << "\tmov "<<temp_reg << ", "<< mem2<<"\n";
//             code_file << "\timul "<<temp_reg << ", "<< size<<"\n";
//             mem2 = temp_reg;
//         }
//         else if(!is_pointerType(instr->arg1.second->type) && is_pointerType(instr->arg2.second->type) ){
//             int size = give_size(instr->arg1.second);
//             code_file << "\timul "<<reg1 << ", "<< size<<"\n";
//         }

//         code_file << "\tadd " << reg1 << ", " << mem2 <<endl;
//         update_reg_desc(reg1, &instr->res);
//     }
// }
// 
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

//         if(is_pointerType(instr->arg1.second->type) && !is_pointerType(instr->arg2.second->type)){
//             int size = give_size(instr->arg1.second);
//             exclude_this.insert(reg1);
//             string temp_reg = getTemporaryReg(&instr->arg2, instr->idx);
//             exclude_this.erase(reg1);
//             code_file << "\tmov "<<temp_reg << ", "<< mem2<<"\n";
//             code_file << "\timul "<<temp_reg << ", "<< size<<"\n";
//             mem2 = temp_reg;
//         }
//         else if(!is_pointerType(instr->arg1.second->type) && is_pointerType(instr->arg2.second->type) ){
//                 int size = give_size(instr->arg2.second);
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






// //----------------------------------------------------- Main function and helper functions----------------------------------------------------//

// // main function which calls other function
// void genCode(){
//     findBasicBlocks();
//     initializeRegs();
//     nextUse();
//     jumpOptimisation();
//     vector<int> visited = findDeadCode();
    
//     gen_data_section();
//     starting_code();

//     int index = 0;
//     for (auto it=leaders.begin(); it != leaders.end(); it++){
//         if(!visited[index++]){
//             continue;
//         }

//         code_file << it->second <<":\n";
//         auto it1 = it;
//         it1++;
//         if(it1 == leaders.end()) break;
        
//         int ended = 0;
//         int start = it->first;
//         int end = it1->first;
        
//         for(int idx=start; idx < end; idx++){
//             quad instr = code[idx];
//             if(instr.arg1.first != "") instr.arg1.first = char_to_int(instr.arg1.first);
//             if(instr.arg2.first != "") instr.arg2.first = char_to_int(instr.arg2.first);
            
//             if(debug_mode) code_file<<"\t\t\t\t\t\t\t\t\t\t;"<<instr.arg1.first<<" "<<instr.op.first<<" "<<instr.arg2.first<<" "<<instr.res.first<<"\n";
            
//             if(instr.op.first.substr(0, 5) == "FUNC_" && instr.op.first[(instr.op.first.size() - 3)] == 't'){
//                 in_func = 1;
//                 gen_func_label(&instr);
//             }
//             else if(instr.op.first.substr(0,2) == "++"  
//                     ||instr.op.first.substr(0,2) == "--" 
//                     ||instr.op.first == "!" 
//                     ||instr.op.first == "~" 
//                     ||instr.op.first == "unary-" 
//                     ||instr.op.first == "unary+") unary_op(&instr);
//             else if(instr.op.first == "unary&" || instr.op.first == "unary*") pointer_op(&instr);
//             else if(instr.op.first[0] == '+')    add_op(&instr);
//             else if(instr.op.first == "=")   assign_op(&instr);
//             else if(instr.op.first.substr(0, 5) == "FUNC_" && instr.op.first[(instr.op.first.size() - 3)] == 'd'){
//                 end_basic_block();
//                 code_file << "\txor eax, eax\n";
//                 code_file << "\tleave\n";
//                 code_file << "\tret\n";
//                 clear_regs();
//                 in_func = 0;
                
//             }
//             else if(instr.op.first[0] == '-') sub_op(&instr);
//             else if(instr.op.first[0] == '*') mul_op(&instr);
//             else if(instr.op.first[0] == '/') div_op(&instr);
//             else if(instr.op.first[0] == '%') mod_op(&instr);
//             else if(instr.op.first == "RETURN"){
//                 return_op(&instr);
//             }
//             else if(instr.op.first == "param") params.push(instr.arg1);
//             else if(instr.op.first == "CALL") call_func(&instr);
//             else if(instr.op.first == "=="  
//                     ||instr.op.first == "<" 
//                     ||instr.op.first == "<=" 
//                     ||instr.op.first == ">" 
//                     ||instr.op.first == ">=" 
//                     ||instr.op.first == "!=" ) comparison_op(&instr); 

//             else if(instr.op.first == "&&") logic_and(&instr);
//             else if(instr.op.first == "||") logic_or(&instr);
//             else if(instr.op.first.substr(0,2) == "<<") lshift_op(&instr);
//             else if(instr.op.first.substr(0,2) == ">>") rshift_op(&instr);
//             else if(instr.op.first[0] == '^' ||  instr.op.first[0] == '&' || instr.op.first[0] == '|') bitwise_op(&instr);
//             else if(instr.op.first == "GOTO") {    
//                 goto_op(&instr);
//             }
//             else if(instr.op.first == "PTR_OP") ptr_op(&instr);
//             else if(instr.op.first == "member_access") member_access(&instr);
//             else if(instr.op.first == "[ ]") array_op(&instr);
//             else if(instr.op.first == "SIZEOF") sizeof_op(&instr);
//         }
//         end_basic_block();
//     }

//     print_global_data();
    
// }

// // print the data section for the asm file
// void print_global_data(){
//     if(!globaldecl.empty()){
//         code_file<<"section .data\n";
//         for(auto it:globaldecl){
//             if(it.second.second == 0) code_file<<"\t"<<it.first<<get_type_size(it.first)<<it.second.first<<"\n";
//             else{
//                 if(global_array_init_map.find(it.first) == global_array_init_map.end()) code_file<<"\t"<<it.first<<" times "<<it.second.second <<get_type_size(it.first)<<it.second.first<<"\n";
//                 else{
//                     code_file<<"\t"<<it.first<<get_type_size(it.first);
//                     vector<qid> temp = global_array_init_map[it.first];
//                     reverse(temp.begin(), temp.end());
//                     int i;
//                     for(i = 0; i<temp.size()-1; i++){
//                         temp[i].first = char_to_int(temp[i].first);
//                         if(is_integer(temp[i].first)||temp[i].first[0]=='\"') code_file<<temp[i].first<<", ";
//                         else code_file<<"0, ";
//                     }
//                     i = temp.size()-1;
//                     temp[i].first = char_to_int(temp[i].first);
//                     if(is_integer(temp[i].first)||temp[i].first[0]=='\"') code_file<<temp[i].first;
//                     else code_file<<"0";

//                     int extra_elements = it.second.second - temp.size();
//                     while(extra_elements > 0){
//                         extra_elements--;
//                         code_file<<", 0";
//                     }
//                     code_file<<"\n";
//                 }
//             }
//         }
//     }
//     for(auto it: stringlabels){
//         it.second[0] = '\`', it.second[it.second.length()-1] = '\`';
//         code_file<<"__str__"<<it.first<<": db "<<it.second<<", 0\n";
//     }
// }

// string get_type_size(string sym){
//     if(global_st[sym]->type.substr(0,2) == "ch"){
//         return " db ";
//     }
//     else return " dd "; 
// }

// // save the values of variables when going out of basic block
// void end_basic_block(){
//     for(auto reg = reg_desc.begin();reg!=reg_desc.end();reg++){
//         for(auto sym =reg->second.begin() ;sym!=reg->second.end(); sym++){
//             if( is_integer(sym->first)) continue;
//             sym->second->addr_descriptor.reg = "";
//             qid tem = *sym;
//             string str = get_mem_location(&tem, &empty_var, -1, -1); 
//             code_file<<"\tmov " << str <<", "<<reg->first<<"\n";
//         }
//         reg->second.clear();
//     }
// }

// // add sym to variables stores in reg
// void update_reg_desc(string reg, qid* sym){
//     for(auto it = reg_desc[reg].begin();it != reg_desc[reg].end(); it++){
//         it->second->addr_descriptor.reg = "";
//         qid temp = *it;
//     }
    
//     for(auto it = reg_desc.begin(); it != reg_desc.end(); it++){
//         it->second.erase(*sym);
//     }
    
//     reg_desc[reg].clear();
//     reg_desc[reg].insert(*sym);
//     sym->second->addr_descriptor.heap = false;
//     sym->second->addr_descriptor.stack = false;
//     sym->second->addr_descriptor.reg = reg;
// }

// void initializeRegs(){
//     // Add more registers later
//     reg_desc.insert(make_pair("eax", set<qid> () ));
//     reg_desc.insert(make_pair("ecx", set<qid> () ));
//     reg_desc.insert(make_pair("edx", set<qid> () ));
//     reg_desc.insert(make_pair("ebx", set<qid> () ));
//     reg_desc.insert(make_pair("esi", set<qid> () ));
//     reg_desc.insert(make_pair("edi", set<qid> () ));
// }

// // free registers allocated to Dead temporaries
// void freeDeadTemp(int idx){
//     for(auto it = reg_desc.begin(); it != reg_desc.end(); it++){
//         vector<qid> temp;
//         for(auto sym : it->second){
//             if(sym.second->next_use < idx && sym.second->next_use != -1){
//                 temp.push_back(sym);
//                 sym.second->addr_descriptor.reg = "";
//             }
//         }
//         for (auto v : temp){
//             it->second.erase(v);
//         }
//     }
// }

// // Get memmory location of a variable
// // It can return a register or stack memory location
// // -1: only stack mem location required!!
// // 0: otherwise
// // 1: for instructions which require size
// // 2: specifically requres address to be passed on further to some other variable
// string get_mem_location(qid* sym, qid* sym2, int idx, int flag){
//     if(sym->second->is_global){
//         if(globaldecl[sym->first].second == 0) return string('['+sym->first+']');
//         else return sym->first;
//     }
//     if(is_integer(sym->first)){
//         if(flag) return string("dword " + sym->first);
//         else return sym->first;
//     }

//     if(sym->second->addr_descriptor.reg != "" && flag!=-1){
//         if(!sym->second->is_derefer || flag == 2) return sym->second->addr_descriptor.reg;
//         return "[ " + sym->second->addr_descriptor.reg + " ]";
//     }
    
//     //Symbol in stack
//     int offset = sym->second->offset;
//     int size = sym->second->size;
//     string str;
//     sym->second->addr_descriptor.stack = true;
//     if(offset >= 0) str = string("[ ebp - " + to_string(offset + size) + " ]");
//     else{
//         offset=-offset;
//         str = string("[ ebp + "+to_string(offset) +" ]");
//     }
//     if(sym->second->is_derefer && flag != -1){
//         string reg = getTemporaryReg(sym2, idx);
//         code_file<< "\tmov "<<reg<<", "<<str<<"\n";
//         update_reg_desc(reg, sym);
//         return "[ " + reg + " ]";
//     }

//     return str;
// }

// // Get a temporary register
// string getTemporaryReg(qid* exclude_symbol, int idx){
//     // freeDeadTemp(idx);
//     string reg = "";
//     int mn = 1000000;
//     for (auto it : reg_desc){
//         if( (exclude_symbol && it.second.find(*exclude_symbol) != it.second.end()) || exclude_this.find(it.first) != exclude_this.end()){
//             // skip the reg containing second argument for an instruction
//             continue;
//         }
//         if (it.second.size() < mn){
//             mn =  it.second.size();
//             reg = it.first; 
//         }
//     } 
//     assert(reg != "");
//     free_reg(reg);
//     return reg;
// }

// // allocates a register to a variable
// // efficient allocation is done to minise load or store
// string getReg(qid* sym, qid* result, qid* sym2, int idx){
//     // Case 1
//     string reg = "";
//     if(sym->second->addr_descriptor.reg != "") {
//         reg = sym->second->addr_descriptor.reg;
//         vector<qid> temp;
//         for(auto it: reg_desc[reg]){
//             if(it.first[0]!='#' && !(it.second->addr_descriptor.stack || it.second->addr_descriptor.heap)){
//                 it.second->addr_descriptor.reg = "";
//                 string str = get_mem_location(&it, &empty_var, idx, -1); 
//                 it.second->addr_descriptor.stack = 1;
//                 code_file << "\tmov " << str << ", " << reg <<endl;
//                 temp.push_back(it);
//             }
//         }
        
//         for(auto it: temp){
//             reg_desc[reg].erase(it);
//         }
        
//         return reg;
//     }

//     reg = getTemporaryReg(sym2, idx);
    
//     if(sym->first[0] == '\"'){
//         stringlabels[string_counter] = sym->first;
//         code_file<<"\tmov "<<reg<<", __str__"<<string_counter<<"\n";
//         string_counter++;
//     }
//     else{
//         string str = get_mem_location(sym, sym2, idx, -1);
//         code_file << "\tmov " << reg << ", "<< str <<"\n";
//         sym->second->addr_descriptor.reg = reg;
//         reg_desc[reg].insert(*sym);
//     }
//     return reg;
// }

// // Clear all the registers
// void clear_regs(){
//     for(auto reg = reg_desc.begin(); reg != reg_desc.end(); reg++){
//         reg->second.clear();
//     }
// }


// // free a specific register
// void free_reg(string reg){
//     for(auto sym: reg_desc[reg]){
//         if(is_integer(sym.first)) continue;
        
//         sym.second->addr_descriptor.reg = "";
//         string str = get_mem_location(&sym, &empty_var, -1, -1);
//         code_file<<"\tmov "<< str <<", "<<reg<<"\n";
//     }
//     reg_desc[reg].clear();
// }


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


// // Calculates the nextuse of temporary variables
// void nextUse(){
//     for(auto it=leaders.begin(); it != leaders.end(); it++){
//         auto it1 = it;
//         it1++;
//         if(it1 == leaders.end()) break;

//         for(int i= (it1->first)-1; i>= (it->first); i--){
//             if(code[i].arg1.first != "" && code[i].arg1.first[0] == '#' && code[i].arg1.second && code[i].arg1.second->next_use == -1){
//                 code[i].arg1.second->next_use = i;
//             } 
//             if(code[i].arg2.first != "" && code[i].arg2.first[0] == '#' && code[i].arg2.second && code[i].arg2.second->next_use == -1){
//                 code[i].arg2.second->next_use = i;
//             }
//             if(code[i].res.first != "" && code[i].res.first[0] == '#' && code[i].res.second && code[i].res.second->next_use == -1){
//                 code[i].res.second->next_use = i;
//             } 
//         }
//     }
// }

//  // Finds Basic block in 3AC code.
// void findBasicBlocks(){
//     for (int i=0;i< (int)code.size(); i++){

//         if (i == 0){
//             leaders.insert(make_pair(i, get_label()));
//             continue;
//         }
//         if(code[i].op.first.substr(0, 5) == "FUNC_"){
//                 if(code[i].op.first[code[i].op.first.length()-3] == 't') leaders.insert(make_pair(i, get_label()));
//                 else if(i+1 != code.size()) leaders.insert(make_pair(i+1, get_label()));
//         }
//         else if(code[i].op.first == "GOTO"){
//             leaders.insert(make_pair(code[i].idx, get_label()));
//             leaders.insert(make_pair(i+1, get_label()));
//         }   
//     }
//     leaders.insert(make_pair(code.size(), get_label()));
// }

// //----------------------------------------------------- Dead Code Removal ----------------------------------------------------//
// void dfs(int curr, vector<int>&visited, vector<vector<int> >&adj_list){
//     visited[curr]=1;
//     for(auto h:adj_list[curr]){
//         if(!visited[h]) dfs(h, visited, adj_list);
//     }
// }

// vector<int> findDeadCode(){

//     int n = leaders.size()+1;
//     vector<int> visited(n, 0);
//     vector<vector<int > > adj_list(n, vector<int>());

//     int id = 0;
//     unordered_map<int , int> get_leader;
//     for(auto it:leaders){
//         get_leader.insert(make_pair(it.first, id++));
//     }
//     id=0;
//     for(auto it = leaders.begin(); it!=leaders.end(); ++it){
//         int start = it->first;
//         auto it1 = it;
//         ++it1;
//         if(it1 == leaders.end()) break;
//         int last = it1->first - 1;

//         if(code[last].op.first == "GOTO"){
//             adj_list[id].push_back(get_leader[code[last].idx]);
//             if(code[last].arg1.first == "IF") adj_list[id].push_back(get_leader[last+1]);
//         }
//         else{
//             adj_list[id].push_back(get_leader[last+1]);
//         }
//         id++;
//     }

//     dfs(0, visited, adj_list);
//     return visited;
// }

// //----------------------------------------------------- Jump to Jump optimization ----------------------------------------------------//
// int findDest(int j, int cnt){
//     if(cnt>200) return j;
//     if((code[j].op.first == "GOTO" && code[j].arg1.first != "IF") && !(j>0 && code[j-1].op.first == "GOTO" && code[j-1].arg1.first == "IF")){
//         return (code[j].idx = findDest(code[j].idx, cnt+1));
//     }
//     return j;
// }

// void jumpOptimisation(){
//     for(int i=0; i<(int)code.size(); ++i){
//         if((code[i].op.first == "GOTO" && code[i].arg1.first != "IF") && !(i>0 && code[i-1].op.first == "GOTO" && code[i-1].arg1.first == "IF")){
//             code[i].idx = findDest(code[i].idx, 0);
//         }
//     }
// }