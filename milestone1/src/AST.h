#include <bits/stdc++.h>
using namespace std;
extern FILE *dotfile;

int noden=1;

typedef struct{
    int Node_id;
    int IntVal;
	double RealVal;
	string StrVal;
    string Name;
} Node;

typedef struct{
	int IntVal;
	double RealVal;
	string StrVal;
} constant;

typedef struct{
	Node* node;
	string str;
} data;

void beginAST(){
    fprintf(dotfile, "digraph AST {\n");
}
void endAST(){
    fprintf(dotfile, "}\n");
}
Node *makeleaf(string s){
    Node *node= new Node;
    node->Node_id=noden++;
    node->Name=s;


    fprintf(dotfile, "\t%lu [label=\"%s\" shape=box ];\n", node->Node_id,node->Name);  ////
    return node;
}
Node *makenode(string s, vector<data>&v){
    Node *node= new Node;
    node->Node_id=noden++;
    node->Name=s;

    fprintf(dotfile, "\t%lu [label=\"%s\"];\n", node->Node_id, node->Name); ////

    // assuming childs are already nodes

    for(auto &i:v){
        fprintf(dotfile, "\t%lu -> %lu;\n", node->Node_id, i.node->Node_id);
    }
    return node;

}

void adddata( vector<data> &v, Node* node, string s, int flag){
	data d;
	d.node = node;
	d.str = s;
	v.push_back(d);
}