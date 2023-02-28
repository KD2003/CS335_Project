#pragma once

#include <bits/stdc++.h>
using namespace std;


typedef struct{
	unsigned long int node_id;
	string node_name;
}ASTNode;

typedef struct{
	ASTNode* node;
	string str;
	bool is_node;
}stuff;


void beginAST();
void endAST();

void insertAttr(vector<stuff>&, ASTNode* , string , int );
ASTNode *makeLeaf(string);
ASTNode *makeNode(string , vector<stuff>&);