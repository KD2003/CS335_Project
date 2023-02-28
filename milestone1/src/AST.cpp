#include "AST.h"

extern FILE *dotfile;


unsigned long int NodeCounter = 1;
void beginAST(){
	fprintf(dotfile, "digraph AST {\n\tordering=out;\n");
}
void endAST(){
	fprintf(dotfile, "}\n");
}

ASTNode *makeLeaf(string str){
	//making leaf node and printing it in dot file
	ASTNode *node = new ASTNode;
	node->node_id = NodeCounter++;
	
	string tmp = "";
	for(int i=0; i<str.length(); ++i){
		tmp+=str[i];
		if(str[i]=='\\') tmp+=str[i];	
	}
	node->node_name = tmp;

	if(str[0]=='"'){
		string st = tmp.substr(1,tmp.length()-2);
		fprintf(dotfile, "\t%lu [label=\"\\\"%s\\\"\" shape=box style=filled color=\"dodgerblue\" fillcolor=\"lightyellow\"];\n", node->node_id, st.c_str());
	}
	else{
		fprintf(dotfile, "\t%lu [label=\"%s\" shape=box style=filled color=\"dodgerblue\" fillcolor=\"lightyellow\"];\n", node->node_id,node->node_name.c_str() );
	}

	return node;
}

ASTNode *makeNode(string st, vector<ASTNode*> &s){
	//making node and printing it in dot file
	ASTNode *node = new ASTNode;
	node->node_name = st;
	node->node_id = NodeCounter++;

	fprintf(dotfile, "\t%lu [label=\"%s\"];\n", node->node_id, node->node_name.c_str());

	for(int i=0; i<s.size(); ++i){
		if(s[i]){
			fprintf(dotfile, "\t%lu -> %lu;\n", node->node_id, s[i]->node_id);
		}
	}
	return node;
}