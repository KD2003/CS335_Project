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
void backpatch(vector<int>& , int);
qid newtemp(string);
void print3AC_code(string , int);
vector<int> mergelist(vector <int>&, vector <int>&);
int nextinstr();
quad make_quad(qid, qid , qid , qid , int );
bool isop(string );