#pragma once
#include <bits/stdc++.h>
#include "3ac.h"
using namespace std;

void gen_data_section();
void starting_code();
void gen_func_label(string );
void genCode(string func_name);
void update_reg_desc(string, qid*);
void initializeRegs();
void findBasicBlocks();
void end_basic_block();
void return_instruct();
void end_func();

string get_mem_location(qid*, qid*, int);
string getTemporaryReg(qid*);
string getReg(qid*, qid*);

int is_integer(string);
int giveArraySize(sym_entry*);
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
void member_access(quad*);
void array_op(quad*);
void goto_op(quad*);
void return_op(quad*);
void clear_regs();
void call_func(quad&);
void free_reg(string);
string char_to_int(string);
void print_string_labels();