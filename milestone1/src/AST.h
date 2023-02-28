#pragma once

#include <bits/stdc++.h>
using namespace std;

typedef struct{
	unsigned long int node_id;
	string node_name;
}ASTNode;

void beginAST();
void endAST();

ASTNode *makeLeaf(string);
ASTNode *makeNode(string , vector<ASTNode*>&);