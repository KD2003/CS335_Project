#pragma once

#include <bits/stdc++.h>
#include"3ac.h"
using namespace std;

typedef struct{
	unsigned long int node_id;
	string node_name;
	string type;
	int expType = 0;	// 1 -> Variable, 2 -> Array, 3-> Function, 4 -> Constant, 5 -> string  			 	
	int intVal;
	double realVal;
	string strVal;
	int is_error = 0;
	int size;
	
	string temp_name;
	qid place;
	vector<int> truelist;
	vector<int> falselist;
	vector<int> breaklist;
	vector<int> continuelist;
	vector<int> nextlist;
	vector<int> caselist;
}ASTNode;

void beginAST();
void endAST();

ASTNode *makeLeaf(string, int = 0);
ASTNode *makeNode(string , vector<ASTNode*>&);