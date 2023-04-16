#pragma once
#include <bits/stdc++.h>
#include "3ac.h"
using namespace std;


int is_integer(string sym);
void add_op(quad* instr);
void sub_op(quad* instr);
void mul_op(quad* instr);
void div_op(quad* instr);
void mod_op(quad* instr);
void bitwise_or_op(quad* instr);
void bitwise_and_op(quad* instr);
void return_op(quad* instr);
void clear_regs();
void call_func(quad &instr);
void add_op(quad* instr);
void assign_op(quad* instr);
void comparison_op(quad* instr, string op);
void logic_and(quad* instr);
void logic_or(quad* instr);
void bitwise_op(quad* instr);
void unary_op(quad* instr);
void pointer_op(quad* instr);
void free_reg(string reg);
void ptr_op(quad* instr);
void member_access(quad* instr);
void array_op(quad* instr);
void goto_op(quad* instr);