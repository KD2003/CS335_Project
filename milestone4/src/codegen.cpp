#include "codegen.h"

map<string, set<qid> > reg_desc;
map<int ,string> leaders;
vector<qid> params;
vector<qid> rec_params;
map<string,string> str_mp; // all the strings to it's name
map<int, string> stringlabels; // all the labels to string
map<string,string> str_temp; // temp_var -> it's string value

int string_cnt = 0;
int label_cnt = 0;
int arg_size = 0;
int in_func = 0;
int str_label=0;

set<string> exclude_this;
qid empty_var("",NULL);

extern ofstream code_file;
extern map<string, int> method_invoked;
extern vector<quad> code;

string print_str;

string get_label(){
    return "Label" +to_string(label_cnt++);
}

void gen_data_section(){
    for(auto it: method_invoked){
        if(it.second) code_file << "extern "<<it.first<<"\n";
    }
}

void start_code(){
    code_file << "\t.global main\n";
    code_file << "\t.text\n";
}

int all_int(string text){
    for(int i=0; i<text.length(); i++){
        if(text[i] >= '0' && text[i]<='9'){
            continue;
        }
        else return 0;
    }
    return 1;
}

void add_op(quad* line){
    if(all_int(line->arg1.first) && all_int(line->arg2.first)){
        long val = (stol(line->arg1.first) + stol(line->arg2.first));
        string str = get_mem_location(&line->res, 0);
        code_file << "\tmovl $" << val <<", " << str << "\n";
        return;
    }
    if(all_int(line->arg1.first)){
        long val = stol(line->arg1.first);
        string reg2 = getReg(&line->arg2);
        code_file << "\tadd $" << val << ", " << reg2 <<"\n";
        update_reg_val(reg2, &line->res);
        return;
    }
    else if(all_int(line->arg2.first)){
        long val = stol(line->arg2.first);
        string reg1 = getReg(&line->arg1);
        code_file << "\tadd $" << val << ", " << reg1 <<"\n";
        update_reg_val(reg1, &line->res);
        return;
    }
    string reg1 = getReg(&line->arg1);
    string mem2 = get_mem_location(&line->arg2, 0);

    code_file << "\tadd " << mem2 << ", " << reg1 <<"\n";
    update_reg_val(reg1, &line->res);
}

void sub_op(quad* line){
    if(all_int(line->arg1.first) && all_int(line->arg2.first)){
        long val = (stol(line->arg1.first) - stol(line->arg2.first));
        string str = get_mem_location(&line->res,  0);
        code_file << "\tmovl $" << val <<", " << str << "\n";
        return;
    }     
    if(all_int(line->arg1.first)){
        long val = stol(line->arg1.first);
        string reg2 = getReg(&line->arg2);
        code_file << "\tsub $" << val << ", " << reg2 <<"\n";
        code_file << "\t neg " << reg2 << "\n";
        update_reg_val(reg2, &line->res);
        return;
    }
    else if(all_int(line->arg2.first)){
        long val = stol(line->arg2.first);
        string reg1 = getReg(&line->arg1);
        code_file << "\tsub $" << val << ", " << reg1 <<"\n";
        update_reg_val(reg1, &line->res);
        return;
    }
    string reg1 = getReg(&line->arg1);
    string mem2 = get_mem_location(&line->arg2, 0);
    
    code_file << "\tsub " << mem2 << ", " << reg1 <<"\n";
    update_reg_val(reg1, &line->res);
}

void mul_op(quad* line){
    if(all_int(line->arg1.first) && all_int(line->arg2.first)){
        long val = (stol(line->arg1.first) * stol(line->arg2.first));
        string str = get_mem_location(&line->res, 0);
        code_file << "\tmovl $" << val <<", " << str << "\n";
        return;
    }
    if(all_int(line->arg1.first)){
        long val = stol(line->arg1.first);
        string reg2 = getReg(&line->arg2);
        code_file << "\timul $" << val << ", " << reg2 <<"\n";
        update_reg_val(reg2, &line->res);
        return;
    }
    else if(all_int(line->arg2.first)){
        long val = stol(line->arg2.first);
        string reg1 = getReg(&line->arg1);
        code_file << "\timul $" << val << ", " << reg1 <<"\n";
        update_reg_val(reg1, &line->res);
        return;
    }
    string reg1 = getReg(&line->arg1);
    string mem2 = get_mem_location(&line->arg2, 0);
    
    code_file << "\timul " << mem2 << ", " << reg1 <<"\n";
    update_reg_val(reg1, &line->res);
}

void div_op(quad* line){
    if(all_int(line->arg1.first) && all_int(line->arg2.first)){
        long val = (stol(line->arg1.first) / stol(line->arg2.first));
        string str = get_mem_location(&line->res, 0);
        code_file << "\tmovl $" << val <<", " << str << "\n";
        return;
    }
    free_reg("%rax");
    free_reg("%rdx");
    if(all_int(line->arg1.first)){
        long val = stol(line->arg1.first);
        code_file<<"\tmovl $"<< val << ", %rax\n";
        exclude_this.insert("%rax");
        exclude_this.insert("%rdx");
        string reg2 = getReg(&line->arg2);
        exclude_this.clear();
        code_file<<"\tidivq "<< reg2 <<"\n";
    }
    else if(all_int(line->arg2.first)){
        long val = stol(line->arg2.first);
        string str = get_mem_location(&line->arg1,0);
        code_file<<"\tmov "<< str << ", %rax\n";
        exclude_this.insert("%rax");
        exclude_this.insert("%rdx");
        exclude_this.clear();
        code_file<<"\tidivq $"<< val <<"\n";
    }
    else{
        string str = get_mem_location(&line->arg1,0);
        code_file<<"\tmov "<< str << ", %rax\n";
        reg_desc["%rax"].insert(line->arg1);
        reg_desc["%rdx"].insert(line->arg1);
        exclude_this.insert("%rax");
        exclude_this.insert("%rdx");
        string reg2 = getReg(&line->arg2);
        exclude_this.clear();
        code_file<<"\tidivq "<< reg2 <<"\n";
    }
    line->res.second->addr_descriptor.reg = "%rax";
    reg_desc["%rax"].clear();
    reg_desc["%rdx"].clear();
    reg_desc["%rax"].insert(line->res);
}

void mod_op(quad* line){
    if(all_int(line->arg1.first) && all_int(line->arg2.first)){
        long val = (stol(line->arg1.first) % stol(line->arg2.first));
        string str = get_mem_location(&line->res, 0);
        code_file << "\tmovl $" << val <<", " << str << "\n";
        return;
    }
    free_reg("%rax");
    free_reg("%rdx");
    if(all_int(line->arg1.first)){
        long val = stol(line->arg1.first);
        code_file<<"\tmovl $"<< val << ", %rax\n";
        exclude_this.insert("%rax");
        exclude_this.insert("%rdx");
        string reg2 = getReg(&line->arg2);
        exclude_this.clear();
        code_file<<"\tidivq "<< reg2 <<"\n";
    }
    else if(all_int(line->arg2.first)){
        long val = stol(line->arg2.first);
        string str = get_mem_location(&line->arg1,0);
        code_file<<"\tmov "<< str << ", %rax\n";
        exclude_this.insert("%rax");
        exclude_this.insert("%rdx");
        exclude_this.clear();
        code_file<<"\tidivq $"<< val <<"\n";
    }
    else{
        string str = get_mem_location(&line->arg1, 0);
        code_file<<"\tmov "<< str << ", %rax\n";
        reg_desc["%rax"].insert(line->arg1);
        reg_desc["%rdx"].insert(line->arg1);
        exclude_this.insert("%rax");
        exclude_this.insert("%rdx");
        string reg2 = getReg(&line->arg2);
        exclude_this.clear();
        code_file <<"\tidivq "<< reg2 <<"\n";
    }
    line->res.second->addr_descriptor.reg = "%rdx";
    reg_desc["%rax"].clear();
    reg_desc["%rdx"].clear();
    reg_desc["%rdx"].insert(line->res);
}

void assign_op(quad* line){
    if(all_int(line->arg1.first)){
        string mem = get_mem_location(&line->res, 1);
        if(reg_desc.find(mem) != reg_desc.end()){
            free_reg(mem);
            update_reg_val(mem, &line->res);
        }
        code_file << "\tmovl $"<< line->arg1.first << ", "<< mem <<"\n";
    }
    else{
        string reg = getReg(&line->arg1);
        reg_desc[reg].insert(line->res);
        string prev_reg = line->res.second->addr_descriptor.reg;
        if(prev_reg != "") reg_desc[prev_reg].erase(line->res);
        line->res.second->addr_descriptor.reg = reg;
        line->res.second->addr_descriptor.stack = 0;
    }
}

void logic_or(quad *line){
    if(all_int(line->arg1.first) && all_int(line->arg2.first)){
        long a = stol(line->arg1.first);
        long b = stol(line->arg2.first);
        string reg = get_mem_location(&line->res,1);
        if(a || b){
            code_file << "\tmov $1, "<< reg <<"\n";
        }
        else{
            code_file << "\tmov $0, "<< reg <<"\n";
        }
        return;
    }
    if(all_int(line->arg1.first)){
        long val = stol(line->arg1.first);
        string mem = get_mem_location(&line->res,1);
        if(val){
            code_file << "\tmov $1, " << mem << "\n";
        }else{
            string reg2 = getReg(&line->arg2);
            code_file << "\ttest " << reg2 << ", " << reg2 << "\n";
            code_file << "\tsetnz \%al\n";
            code_file << "\tmovzbq \%al, " << reg2 << "\n";
            update_reg_val(reg2, &line->res);
        }
        return;
    }
    else if(all_int(line->arg2.first)){
        long val = stol(line->arg2.first);
        string mem = get_mem_location(&line->res,1);
        if(val){
            code_file << "\tmov $1, " << mem << "\n";
        }else{
            string reg1 = getReg(&line->arg1);
            code_file << "\ttest " << reg1 << ", " << reg1 << "\n";
            code_file << "\tsetnz \%al\n";
            code_file << "\tmovzbq \%al, " << reg1 << "\n";
            update_reg_val(reg1, &line->res);
        }
        return;
    }
    string reg = getReg(&line->arg1);
    string mem2 = getReg(&line->arg2);
    code_file << "\tadd " << mem2 << ", " << reg << "\n";
    code_file << "\ttest " << reg << ", " << reg << "\n";
    code_file << "\tsetnz \%al\n";
    code_file << "\tmovzbq \%al, " << reg << "\n";
    update_reg_val(reg, &line->res);
}

void logic_and(quad *line){
    if(all_int(line->arg1.first) && all_int(line->arg2.first)){
        long a = stol(line->arg1.first);
        long b = stol(line->arg2.first);
        string reg = get_mem_location(&line->res,1);
        if(a && b){
            code_file << "\tmov $1, "<< reg <<"\n";
        }
        else{
            code_file << "\tmov $0, "<< reg <<"\n";
        }
        return;
    }
    if(all_int(line->arg1.first)){
        long val = stol(line->arg1.first);
        string mem = get_mem_location(&line->res,1);
        if(!val){
            code_file << "\tmov $0, " << mem << "\n";
        }else{
            string reg2 = getReg(&line->arg2);
            code_file << "\ttest " << reg2 << ", " << reg2 << "\n";
            code_file << "\tsetnz \%al\n";
            code_file << "\tmovzbq \%al, " << reg2 << "\n";
            update_reg_val(reg2, &line->res);
        }
        return;
    }
    else if(all_int(line->arg2.first)){
        long val = stol(line->arg2.first);
        string mem = get_mem_location(&line->res,1);
        if(!val){
            code_file << "\tmov $0, " << mem << "\n";
        }else{
            string reg1 = getReg(&line->arg1);
            code_file << "\ttest " << reg1 << ", " << reg1 << "\n";
            code_file << "\tsetnz \%al\n";
            code_file << "\tmovzbq \%al, " << reg1 << "\n";
            update_reg_val(reg1, &line->res);
        }
        return;
    }
    string reg = getReg(&line->arg1);    
    string mem2 = getReg(&line->arg2);
    code_file << "\ttest " << mem2 << ", " << mem2 << "\n";
    code_file << "\tcmovnz " << mem2 << ", " << reg << "\n";
    code_file << "\ttest " << reg << ", " << reg << "\n";
    code_file << "\tsetnz \%al\n";
    code_file << "\tmovzbq \%al, " << reg << "\n";
    update_reg_val(reg, &line->res);
}

void bitwise_op(quad* line){
    string op = line->op.first;
    if(all_int(line->arg1.first) && all_int(line->arg2.first)){
        long val = 0;
        if(op[0] == '^')        val = (stol(line->arg1.first) ^ stol(line->arg2.first));
        else if(op[0] == '&')   val = (stol(line->arg1.first) & stol(line->arg2.first));
        else if(op[0] == '|')   val = (stol(line->arg1.first) | stol(line->arg2.first));
        string mem = get_mem_location(&line->res, 1);
        code_file << "\tmovl $" << val <<", " << mem << "\n";
        return;
    }
    string op_ins = "";
    if(op[0] == '^')      op_ins = "xor";
    else if(op[0] == '&') op_ins = "and";
    else if(op[0] == '|') op_ins = "or";
    if(all_int(line->arg1.first)){
        long val = stol(line->arg1.first);
        string reg2 = getReg(&line->arg2);
        code_file << "\t" << op_ins << " $" << val << ", "<< reg2 <<"\n";
        update_reg_val(reg2, &line->res);
        return;
    }
    else if(all_int(line->arg2.first)){
        long val = stol(line->arg2.first);
        string reg1 = getReg(&line->arg1);
        code_file << "\t" << op_ins << " $" << val << ", "<< reg1 <<"\n";
        update_reg_val(reg1, &line->res);
        return;
    }
    string reg = getReg(&line->arg1);
    string mem2 = get_mem_location(&line->arg2, 0);
    code_file << "\t" << op_ins << " " << mem2 << ", "<< reg <<"\n";
    update_reg_val(reg, &line->res);
}

void comparison_op(quad* line){
    string op = line->op.first.substr(0,2);
    if(all_int(line->arg1.first) && all_int(line->arg2.first)){
        long val = 0;
        if(op == "==")      val = (stol(line->arg1.first) == stol(line->arg2.first));
        else if(op == "<")  val = (stol(line->arg1.first) <  stol(line->arg2.first));
        else if(op == "<=") val = (stol(line->arg1.first) <= stol(line->arg2.first));
        else if(op == ">")  val = (stol(line->arg1.first) >  stol(line->arg2.first));
        else if(op == ">=") val = (stol(line->arg1.first) >= stol(line->arg2.first));
        else if(op == "!=") val = (stol(line->arg1.first) != stol(line->arg2.first));  
        string mem = get_mem_location(&line->res,1);
        code_file << "\tmovl $" << val <<", " << mem << "\n";
        return;
    }
    string set_ins = "";
    if(op == "==")      set_ins = "sete";
    else if(op[0] == '<')  set_ins = "setl";
    else if(op == "<=") set_ins = "setle";
    else if(op[0] == '>')  set_ins = "setg";
    else if(op == ">=") set_ins = "setge";
    else if(op == "!=") set_ins = "setne";
    if(all_int(line->arg1.first)){
        if(op == "==")      set_ins = "sete";
        else if(op[0] == '<')  set_ins = "setge";
        else if(op == "<=") set_ins = "setg";
        else if(op[0] == '>')  set_ins = "setle";
        else if(op == ">=") set_ins = "setl";
        else if(op == "!=") set_ins = "setne";
        long val = stol(line->arg1.first);
        string reg2 = getReg(&line->arg2);
        code_file << "\tcmp $"<< val <<", " << reg2 <<"\n";
        code_file << "\t"<< set_ins << " \%al\n";
        code_file << "\tmovzbq \%al, " << reg2 << "\n";
        update_reg_val(reg2, &line->res);
        return;
    }
    else if(all_int(line->arg2.first)){
        long val = stol(line->arg2.first);
        string reg1 = getReg(&line->arg1);
        code_file << "\tcmp $"<< val <<", " << reg1 <<"\n";
        code_file << "\t"<< set_ins << " \%al\n";
        code_file << "\tmovzbq \%al, " << reg1 << "\n";
        update_reg_val(reg1, &line->res);
        return;
    }
    string reg = getReg(&line->arg1);
    string mem2 = get_mem_location(&line->arg2, 0);
    code_file << "\tcmp "<< mem2 <<", " << reg <<"\n";
    code_file << "\t"<< set_ins << " \%al\n";
    code_file << "\tmovzbq \%al, " << reg << "\n";
    update_reg_val(reg, &line->res);
}

void shift_op(quad* line){
    string op = line->op.first;
    if(all_int(line->arg1.first) && all_int(line->arg2.first)){
        long val = 0;
        if(op == "<<")      val = (stol(line->arg1.first) << stol(line->arg2.first));
        else if(op == ">>")  val = (stol(line->arg1.first) >>  stol(line->arg2.first));
        else if(op == ">>>") val = (unsigned long)(stol(line->arg1.first) >> stol(line->arg2.first));
        string mem = get_mem_location(&line->res,1);
        code_file << "\tmovl $" << val <<", " << mem << "\n";
        return;
    }
    string shift_ins="";
    if(op == "<<") shift_ins = "shl";
    else if(op == ">>") shift_ins = "sar";
    else if(op == ">>>") shift_ins = "shr";
    if(all_int(line->arg1.first)){
        long val = stol(line->arg1.first);
        exclude_this.insert("%rcx");
        string reg = getReg(&line->res);
        string mem2 = get_mem_location(&line->arg2,0);
        free_reg("%rcx");
        code_file << "\tmovl $" << val << ", " << reg <<"\n";
        code_file << "\tmov " << mem2 << ", %rcx\n";
        code_file << "\t" << shift_ins << " \%cl, " << reg <<"\n";
        exclude_this.clear();
        update_reg_val(reg, &line->res);
        return;
    }
    else if(all_int(line->arg2.first)){
        long val = stol(line->arg2.first);
        string reg1 = getReg(&line->arg1);
        code_file << "\t" << shift_ins << " $"<< val <<", " << reg1 <<"\n";
        update_reg_val(reg1, &line->res);
        return;
    }
    exclude_this.insert("%rcx");
    string reg1 = getReg(&line->arg1);
    free_reg("%rcx");
    string mem2 = get_mem_location(&line->arg2,0);
    code_file << "\tmov " << mem2 << ", %rcx\n";
    code_file << "\t" << shift_ins << " \%cl, " << reg1 <<"\n";
    exclude_this.clear();
    update_reg_val(reg1, &line->res);
}

void unary_op(quad* line){
    string op = line->op.first, unary_ins = "";
    string reg = getReg(&line->arg1);
    if(op[2] == 'P'){
        if(op == "++P")      unary_ins = "inc";
        else if(op == "--P") unary_ins = "dec";
        code_file<<"\t"<< unary_ins <<" "<< reg <<"\n";
        free_reg(reg);
        update_reg_val(reg, &line->arg1);
        
    }
    else if(op[0] == 'P'){
        if(op == "P++")      unary_ins = "inc";
        else if(op == "P--") unary_ins = "dec";
        string reg1 = getTemporaryReg(&line->arg1);
        code_file<<"\tmov "<< reg <<", "<< reg1 <<"\n";
        update_reg_val(reg1, &line->arg1);
        code_file<<"\t"<< unary_ins <<" "<< reg <<"\n";
        string str = get_mem_location(&line->arg1,-1);
        code_file<<"\tmov "<< reg <<", "<< str <<"\n";
    }
    else if(op == "~"){
        code_file << "\tnot " << reg <<"\n";
        update_reg_val(reg, &line->arg1);
    }
    else if(op == "-U"){
        code_file << "\tneg " << reg <<"\n";       
        update_reg_val(reg, &line->arg1);
    }
    else if(op == "+U"){
        reg_desc[reg].insert(line->res);
        line->res.second->addr_descriptor.reg = reg;
    }
    else if(op == "!"){
        code_file << "\ttest "<< reg <<", "<< reg <<"\n";
        code_file << "\tsete \%al\n";
        code_file << "\tmovzbq \%al, " << reg << "\n";
        update_reg_val(reg, &line->arg1);
    }
}

void goto_op(quad* line){
    end_basic_block();
    if(line->arg1.first == "IF"){
        string loc = get_mem_location(&line->arg2,  1);
        code_file << "\tcmp " << loc <<", " << " $0"<<"\n";
        code_file << "\tjne " << leaders[line->idx]<<"\n";
    }
    else{
        code_file << "\tjmp " << leaders[line->idx] <<"\n";
    }
}

void call_func(quad *line){
    for(auto it: reg_desc){
        free_reg(it.first);
    }
    if(line->arg1.first=="print"){
        if(params[0].second->type!="string"){
            code_file << "\tmov %rsi, " << get_mem_location(&params[0], -1) << '\n';
        }
        else code_file << "\tmov %rsi, " << str_mp[str_temp[params[0].first]] << '\n';
        code_file << "\tmov %rax, 1\n";
        code_file << "\tmov %rdi, %rax\n";
        code_file << "\tsyscall\n";
        params.erase(params.begin());
        return;
    }
    int npara = stoi(line->arg2.first);
    int addspace=0;
    for(int i=0;i<npara;i++){
        code_file << "\tpush " <<  get_mem_location(&params[i], -1) << '\n';
        addspace+=params[i].second->size;
    }
    code_file << "\tsub " << "$"+to_string(addspace)+", " << "%rsp" << '\n';

    code_file << "\tcall " << line->arg1.first << '\n';  
    code_file << "\tadd " << "$"+to_string(addspace)+", " << "%rsp" << '\n'; 
    params.clear();

}

void return_func(quad* line){
    string dest =  get_mem_location(&line->res, -1);
    code_file << "\tmov " << "%rax, " << dest << '\n';

}

void return_instruct(){
    code_file << "\tret\n";
}

void end_func(){
    code_file << "\tleave\n"; 
}

void generateCode(string func_name){
    leaders.insert(make_pair(0,func_name));
    findleaders();
    gen_func_label(func_name);
    int index = 0;
    for(auto it=leaders.begin(); it != leaders.end(); it++){
        if(it->second!=func_name) code_file << it->second <<":\n";
        auto it1 = it;
        it1++;
        if(it1 == leaders.end()) break;
        int ended = 0;
        int start = it->first;
        int end = it1->first;
        for(int i=start; i <= end; i++){
            if(i!=0 && i==end && code[i-1].op.first!="goto" && code[i-1].res.first!="goto"){
                end_basic_block();
                jump_nxt(i);break;
            }
            else if(i==end){
                end_basic_block();break;
            }
            quad line = code[i];
            if(line.op.first == "++P"  ||line.op.first == "--P"||line.op.first == "P++"||line.op.first == "P--"||line.op.first == "!" ||line.op.first == "~" ||line.op.first == "-U" ||line.op.first == "+U") unary_op(&line);
            else if(line.op.first[0] == '+') add_op(&line);
            else if(line.op.first[0] == '-') sub_op(&line);
            else if(line.op.first[0] == '*') mul_op(&line);
            else if(line.op.first[0] == '/') div_op(&line);
            else if(line.op.first[0] == '%') mod_op(&line);
            else if(line.op.first == "call") call_func(&line);
            else if(line.op.first == "param"){ 
                params.push_back(line.arg1);
            }
            else if(line.arg1.first == "popreturn") return_func(&line);
            else if(line.op.first == "stackpointer--") ;
            else if(line.op.first == "endfunc_") end_func();
            else if(line.op.first == "RETURN") return_instruct();
            else if(line.op.first=="=" && line.arg1.first.size()>7 && line.arg1.first.substr(0,7)=="cast_to");
            else if(line.arg1.first=="base") ;
            else if(line.arg1.first == "popparam"){
                rec_params.push_back(line.res);
                if(i+1==end || code[i+1].arg1.first!="popparam") save_rec_param();
            }
            else if(line.op.first == "=" && line.res.second->type=="string"){
                if(str_mp.find(line.arg1.first)==str_mp.end()){
                    str_mp[line.arg1.first] = assign_str_label();
                    stringlabels[str_label]=line.arg1.first;
                }
                print_str=str_mp[line.arg1.first];
                str_temp[line.res.first]=line.arg1.first;

            }  
            else if(line.op.first == "=")   {
                assign_op(&line);}
            else if(line.op.first == "=="  ||line.op.first == "<"||line.op.first == "<=" ||line.op.first == ">" 
                    ||line.op.first == ">=" 
                    ||line.op.first == "!=" ) comparison_op(&line); 

            else if(line.op.first == "&&") logic_and(&line);
            else if(line.op.first == "||") logic_or(&line);
            else if(line.op.first == "<<"||line.op.first == ">>"||line.op.first == ">>>") shift_op(&line);
            else if(line.op.first[0] == '^' ||  line.op.first[0] == '&' || line.op.first[0] == '|') bitwise_op(&line);
            else if(line.op.first == "goto") {    
                goto_op(&line);
            }
        }
    }
    leaders.clear();
}

void jump_nxt(int line_no){
    code_file << "\tjmp " << leaders[line_no] << '\n'; 
}

string assign_str_label(){
    return "str"+to_string(str_label++);
}

void print_str_labels(){
    for(auto it: str_mp){
        code_file<<it.second + ":\n";
        code_file << "\t" <<".asciz " << it.first<<"\n";
    }
}

void end_basic_block(){
    for(auto reg = reg_desc.begin();reg!=reg_desc.end();reg++){
        for(auto sym =reg->second.begin(); sym!=reg->second.end(); sym++){
            if(all_int(sym->first)) continue;
            sym->second->addr_descriptor.reg = "";
            qid tem = *sym;
            string str = get_mem_location(&tem, -1); 
            code_file<<"\tmov " << reg->first <<", "<< str <<"\n";
        }
        reg->second.clear();
    }
}


void save_rec_param(){
    // int offset=8;
    // for(auto i:rec_params) offset+=i.second->size;
    // for(auto i:rec_params){
    //     offset+=i.second->size;
    //     code_file << "\tmov "<< to_string(offset)+"(%rsp), " << get_mem_location(&i,-1) << '\n';
    // }
    rec_params.clear();
}
void update_reg_val(string reg, qid* sym){
    for(auto it = reg_desc[reg].begin();it != reg_desc[reg].end(); it++){
        it->second->addr_descriptor.reg = "";
        qid temp = *it;
        string str = get_mem_location(&temp,-1);
        it->second->addr_descriptor.stack = 1;
        code_file << "\tmov " << reg << ", " << str <<"\n";
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

string get_mem_location(qid* sym, int flag){
    if(all_int(sym->first)){
        return string("$" + sym->first);
    }

    if(sym->second->addr_descriptor.reg != "" && flag!=-1){
        if(flag == 2) return sym->second->addr_descriptor.reg;
        return "( " + sym->second->addr_descriptor.reg + " )";
    }
    
    //in stack
    int offset = sym->second->offset;
    sym->second->addr_descriptor.stack = true;

    string str = to_string(-offset-8)+"(%rsp)";
    return str;
}

string getTemporaryReg(qid* sym){
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

string getReg(qid* sym){
    string reg = "";
    if(sym->second->addr_descriptor.reg != "") {
        reg = sym->second->addr_descriptor.reg;
        vector<qid> temp;
        for(auto it: reg_desc[reg]){
            if(it.first[0]!='#' && !(it.second->addr_descriptor.stack)){
                it.second->addr_descriptor.reg = "";
                string str = get_mem_location(&it,-1);
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

    reg = getTemporaryReg(sym);
    if(sym->first[0] == '\"'){
        stringlabels[str_label] = sym->first;
        str_mp[sym->first]=str_label;
        code_file<<"\tmov $__str__"<<str_label<< ", "<< reg << "\n";
        str_label++;
    }
    else{
        string str = get_mem_location(sym, -1);
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
        if(all_int(sym.first) || sym.second->addr_descriptor.reg !=reg) continue;
        
        sym.second->addr_descriptor.reg = "";
        string str = get_mem_location(&sym,-1);
        code_file<<"\tmov "<< reg <<", "<<str<<"\n";
    }
    reg_desc[reg].clear();
}

//function starting
void gen_func_label(string func_name){
    code_file << func_name << ":\n";
    code_file << "\tpush %rbp\n";
    code_file << "\tmov %rsp, %rbp\n"; 
    code_file << "\tsub $"<< getFuncSize(func_name) << ", %rsp" <<"\n";

}

//finding leaders
void findleaders(){
    for(int i=0;i< (int)code.size(); i++){
        if(code[i].op.first == "goto"){
            leaders.insert(make_pair(code[i].idx, get_label()));
            leaders.insert(make_pair(i+1, get_label()));
        }   
    }
    leaders.insert(make_pair(code.size(), get_label()));
}