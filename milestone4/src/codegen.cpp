#include "codegen.h"

int string_counter = 0;
int label_counter = 0;

extern ofstream code_file;





// comment below code to compile
//----------------------------------------------------- Arithmetic Operators ----------------------------------------------------//

// addtion operation
void add_op(quad* instr){
    if(is_integer(instr->arg1.first) && is_integer(instr->arg2.first)){
        int val = (stoi(instr->arg1.first) + stoi(instr->arg2.first));
        string str = get_mem_location(&instr->res, &empty_var, instr->idx, 0);
        code_file << "\tmov " << str <<", " << "dword "<< val << "\n";
    }
    else{
        string reg1 = getReg(&instr->arg1, &instr->res, &instr->arg2, instr->idx);
        string mem2 = get_mem_location(&instr->arg2, &instr->arg1, instr->idx, 0);

        if(instr->arg1.second->is_derefer){
            string str = get_mem_location(&instr->arg1, &instr->arg2, instr->idx, -1);
            code_file<<"\tmov "<<str <<", "<< reg1<<endl;
            code_file<<"\tmov "<<reg1<<", [ "<<reg1<<" ]\n";
        }
        
        if(is_pointerType(instr->arg1.second->type) && !is_pointerType(instr->arg2.second->type)){
            int size = give_size(instr->arg1.second);
            exclude_this.insert(reg1);
            string temp_reg = getTemporaryReg(&instr->arg2, instr->idx);
            exclude_this.erase(reg1);
            code_file << "\tmov "<<temp_reg << ", "<< mem2<<"\n";
            code_file << "\timul "<<temp_reg << ", "<< size<<"\n";
            mem2 = temp_reg;
        }
        else if(!is_pointerType(instr->arg1.second->type) && is_pointerType(instr->arg2.second->type) ){
            int size = give_size(instr->arg1.second);
            code_file << "\timul "<<reg1 << ", "<< size<<"\n";
        }

        code_file << "\tadd " << reg1 << ", " << mem2 <<endl;
        update_reg_desc(reg1, &instr->res);
    }
}

// subtraction operation
void sub_op(quad* instr){
    if(is_integer(instr->arg1.first) && is_integer(instr->arg2.first)){
        int val = (stoi(instr->arg1.first) - stoi(instr->arg2.first));
        string str = get_mem_location(&instr->res, &empty_var, instr->idx, 0);
        code_file << "\tmov " << str <<", " << "dword "<< val << "\n";
    }
    else{        
        string reg1 = getReg(&instr->arg1, &instr->res, &instr->arg2, instr->idx);
        string mem2 = get_mem_location(&instr->arg2, &instr->arg1, instr->idx, 0);
        
        if(instr->arg1.second->is_derefer){
            string str = get_mem_location(&instr->arg1, &instr->arg2, instr->idx, -1);
            code_file<<"\tmov "<<str <<", "<< reg1<<endl;
            code_file<<"\tmov "<<reg1<<", [ "<<reg1<<" ]\n";
        }

        if(is_pointerType(instr->arg1.second->type) && !is_pointerType(instr->arg2.second->type)){
            int size = give_size(instr->arg1.second);
            exclude_this.insert(reg1);
            string temp_reg = getTemporaryReg(&instr->arg2, instr->idx);
            exclude_this.erase(reg1);
            code_file << "\tmov "<<temp_reg << ", "<< mem2<<"\n";
            code_file << "\timul "<<temp_reg << ", "<< size<<"\n";
            mem2 = temp_reg;
        }
        else if(!is_pointerType(instr->arg1.second->type) && is_pointerType(instr->arg2.second->type) ){
                int size = give_size(instr->arg2.second);
                code_file << "\timul "<<reg1 << ", "<< size<<"\n";
        }

        code_file << "\tsub " << reg1 << ", " << mem2 <<endl;
        update_reg_desc(reg1, &instr->res);
    }
}

// multiplicative operation
void mul_op(quad* instr){
    if(is_integer(instr->arg1.first) && is_integer(instr->arg2.first)){
        int val = (stoi(instr->arg1.first) * stoi(instr->arg2.first));
        string str = get_mem_location(&instr->res, &empty_var, instr->idx, 0);
        code_file << "\tmov " << str <<", " << "dword "<< val << "\n";
    }
    else{
        string reg1 = getReg(&instr->arg1, &instr->res, &instr->arg2, instr->idx);
        string mem2 = get_mem_location(&instr->arg2, &instr->arg1, instr->idx, 0);
        
        if(instr->arg1.second->is_derefer){
            string str = get_mem_location(&instr->arg1, &instr->arg2, instr->idx, -1);
            code_file<<"\tmov "<<str <<", "<< reg1<<endl;
            code_file<<"\tmov "<<reg1<<", [ "<<reg1<<" ]\n";
        }
        code_file << "\timul " << reg1 << ", " << mem2 <<endl;
        update_reg_desc(reg1, &instr->res);
    }
}


// CHECK
// divison operation
void div_op(quad* instr){
    if(is_integer(instr->arg1.first) && is_integer(instr->arg2.first)){
        int val = (stoi(instr->arg1.first) / stoi(instr->arg2.first));
        string str = get_mem_location(&instr->res, &empty_var, instr->idx, 0);
        code_file << "\tmov " << str <<", " << "dword "<< val << "\n";
    }
    else{
        free_reg("eax");
        free_reg("edx");
        string str = get_mem_location(&instr->arg1, &instr->arg2, instr->idx, 0);
        code_file<<"\tmov eax"<<", "<< str <<"\n";
        reg_desc["eax"].insert(instr->arg1);
        reg_desc["edx"].insert(instr->arg1);
        
        exclude_this.insert("edx");
        exclude_this.insert("eax");
        string reg2 = getReg(&instr->arg2, &instr->res, &empty_var, instr->idx);
        if(instr->arg2.second->is_derefer){ 
            string str = get_mem_location(&instr->arg2, &instr->arg1, instr->idx, -1);
            code_file<<"\tmov "<<str <<", "<< reg2<<endl;
            code_file<<"\tmov "<<reg2<<", [ "<<reg2<<" ]\n";
        }
        exclude_this.clear(); 

        code_file<<"\tcdq\n";
        code_file<<"\tidiv "<<reg2<<"\n";

        instr->res.second->addr_descriptor.reg = "eax";
        reg_desc["eax"].clear();
        reg_desc["edx"].clear();
        reg_desc["eax"].insert(instr->res);
    }
}

// modulo operation
void mod_op(quad* instr){
    if(is_integer(instr->arg1.first) && is_integer(instr->arg2.first)){
        int val = (stoi(instr->arg1.first) % stoi(instr->arg2.first));
        string str = get_mem_location(&instr->res, &empty_var, instr->idx, 0);
        code_file << "\tmov " << str <<", " << "dword "<< val << "\n";
    }
    else{
        free_reg("eax");
        free_reg("edx");
        string str = get_mem_location(&instr->arg1,&instr->arg2, instr->idx, 0);
        code_file<<"\tmov eax"<<", "<< str <<"\n";
        reg_desc["eax"].insert(instr->arg1);
        reg_desc["edx"].insert(instr->arg1);
        string reg2 = getReg(&instr->arg2, &instr->res, &empty_var, instr->idx);
        if(instr->arg2.second->is_derefer){
            string str = get_mem_location(&instr->arg2, &instr->arg1, instr->idx, -1);
            code_file<<"\tmov "<<str <<", "<< reg2<<endl;
            code_file<<"\tmov "<<reg2<<", [ "<<reg2<<" ]\n";
        }

        code_file<<"\tcdq\n";
        code_file<<"\tidiv "<<reg2<<"\n";
        instr->res.second->addr_descriptor.reg = "edx";
        reg_desc["eax"].clear();
        reg_desc["edx"].clear();
        reg_desc["edx"].insert(instr->res);
    }
}