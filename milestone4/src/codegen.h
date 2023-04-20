#pragma once
#include <bits/stdc++.h>
#include "3ac.h"
using namespace std;

void gen_data_section();
void start_code();
void gen_func_label(string );
void generateCode(string func_name);

void findBasicBlocks();
void end_basic_block();
void return_instruct();
void end_func();
int all_int(string);

string get_mem_location(qid*, int);
string getTemporaryReg(qid*);
string getReg(qid*);

// op
void add_op(quad*);
void sub_op(quad*);
void mul_op(quad*);
void div_op(quad*);
void mod_op(quad*);
void logic_or(quad*);
void logic_and(quad*);
void bitwise_op(quad*);
void comparison_op(quad*);
void shift_op(quad*);
void unary_op(quad*);
void assign_op(quad*);
void goto_op(quad*);
void return_op(quad*);

// mem management
void clear_regs();
void call_func(quad&);
void free_reg(string);
void update_reg_desc(string, qid*);
void initializeRegs();
void print_str_labels();
void save_rec_param();
string assign_str_label();
void jump_nxt(int );