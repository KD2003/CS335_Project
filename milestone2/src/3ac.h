#pragma once

#include <bits/stdc++.h>
#include "typecheck.h"

using namespace std;

typedef pair <string, sym_entry*> qid;

typedef struct quadruple{
    qid op;
    qid arg1;
    qid arg2;
    qid res;
    int idx;
} quad;

void emit(qid, qid , qid , qid , int );
void emit(quad);
void backpatch(vector<int>& , int);
qid newtemp(string);
int assign_exp(string op, string type, string type1,string type2, qid arg1, qid arg2);
void casepatch(vector<int>& bplist, qid target);
void print3AC_code(string );
void backpatch_rem();
string newLabel();
vector<int> mergelist(vector <int>&, vector <int>&);
int nextinstr();
quad make_quad(qid, qid , qid , qid , int );
void addline();
void remline();
bool isop(string );