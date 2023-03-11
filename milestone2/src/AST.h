#pragma once

#include <bits/stdc++.h>
#include"3ac.h"
using namespace std;

typedef struct{
	unsigned long int node_id;
	string node_name;
	string type;
	int expType = 0;	// 1 -> Variable, 2 -> Array, 3-> Function, 4 -> Constant, 5 -> string  			 	
	int isInit;
	int intVal;
	double realVal;
	string strVal;
	int is_error = 0;

	string temp_name;
	qid place;
}ASTNode;

void beginAST();
void endAST();

ASTNode *makeLeaf(string);
ASTNode *makeNode(string , vector<ASTNode*>&);