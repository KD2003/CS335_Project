#include "AST.h"

extern FILE *dotfile;


unsigned long int NodeCounter = 1;
void beginAST(){
	fprintf(dotfile, "digraph AST {\n\tordering=out;\n");
}
void endAST(){
	fprintf(dotfile, "}\n");
}


void insertAttr(vector<stuff> &s, ASTNode* nod, string st, int flag){
	stuff d;
	d.node = nod;
	d.str = st;
	d.is_node = flag;
	s.push_back(d);
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

ASTNode *makeNode(string st, vector<stuff> &s){
	//making node and printing it in dot file
	ASTNode *node = new ASTNode;
	node->node_name = st;
	node->node_id = NodeCounter++;

	vector<unsigned long int> op_id;

	for(int i = 0; i<s.size(); ++i){
		if(!s[i].is_node){
			unsigned long int opid = NodeCounter++;
			op_id.push_back(opid);
			if(s[i].str!="") fprintf(dotfile, "\t%lu [label=\"%s\"];\n", opid, s[i].str.c_str());
		}
	}


	fprintf(dotfile, "\t%lu [label=\"%s\"];\n", node->node_id, node->node_name.c_str());

	int j=0;
	for(int i=0; i<s.size(); ++i){
		// if string or node is NULL, dont print in dot 
		if(s[i].is_node && s[i].node ) fprintf(dotfile, "\t%lu -> %lu;\n", node->node_id, s[i].node->node_id);
		if(!s[i].is_node){
			if(s[i].str!="") fprintf(dotfile, "\t%lu -> %lu;\n", node->node_id, op_id[j]);
			j++;
		}
	}

	return node;

}