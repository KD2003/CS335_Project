#include "symbol_table.h"
#include <algorithm>

sym_table global_st;
map<sym_table*, sym_table*> parent_table;
map<sym_table*, vector<pair<string, sym_table*>>> children_table;
map<string, pair< string,vector<string> > > func_arg;
sym_table* cur_table;

extern int isArray;
extern vector<int> array_dims;

void symbolTableInit(){
	parent_table.insert(make_pair(&global_st, nullptr));
	children_table.insert(make_pair(&global_st, vector<pair<string, sym_table*>> ()));
	cur_table = &global_st;
	vector<int> temp = {1,0,0};
	insertSymbol(*cur_table, "String" , "CLASS", "CLASS", 0, NULL, temp);
	// insert keywords?
}

sym_entry* createEntry(string token, string lexeme, string type, int lineno, sym_table* ptr, vector<int> &modifiers){
	sym_entry* new_symEnt = new sym_entry;
	new_symEnt->token = token;
	new_symEnt->lexeme = lexeme;
	new_symEnt->type = type;
	new_symEnt->lineno = lineno;
	new_symEnt->entry = ptr;
	new_symEnt->modifiers[0] = modifiers[0];
	new_symEnt->modifiers[1] = modifiers[1];
	new_symEnt->modifiers[2] = modifiers[2];
	return new_symEnt;
}

sym_entry* lookup(string id){
	sym_table* temp = cur_table;
	while(temp){
		if((*temp).find(id)!=(*temp).end()) return (*temp)[id];
		temp = parent_table[temp];
	}
	return nullptr;
}

sym_entry* curLookup(string id){
	if((*cur_table).find(id)==(*cur_table).end()) return nullptr;
	return (*cur_table)[id];
}

void insertSymbol(sym_table& table, string id, string token, string type, int lineno, sym_table* ptr, vector<int> &modifiers){
	table.insert(make_pair(id, createEntry(token, id, type, lineno, ptr, modifiers)));
	if(!array_dims.empty()){
		// vector<int> temp;
		// int cur = 1;
		// for(int i = array_dims.size()-1; i>=1; i--){
		// 	cur*=array_dims[i];
		// 	temp.push_back(cur);
		// }
		// reverse(temp.begin(), temp.end());
		// table[id]->array_dims = temp;
		table[id]->array_dims = array_dims;
		if(isArray){
			table[id]->isArray = 1;
			isArray = 0;
		}
		array_dims.clear();
	}
}

void makeSymbolTable(string name, string f_type, int lineno, vector<int> &modifiers){
	sym_table* new_table = new sym_table;
	
	if(f_type == "CLASS"){
		insertSymbol(*cur_table, name , f_type, f_type, lineno, new_table, modifiers);
	}
	else if(f_type != ""){
		insertSymbol(*cur_table, name , "FUNC_", "FUNC_" + f_type, lineno, new_table, modifiers);
	}
	else{
		insertSymbol(*cur_table, name , "Block", "", lineno, new_table, modifiers);
	}
	parent_table.insert(make_pair(new_table, cur_table));
	if(children_table.find(cur_table) == children_table.end()){
		children_table.insert(make_pair(new_table, vector<pair<string, sym_table*>> ()));
	}
	children_table[cur_table].push_back(make_pair(name,new_table));
	cur_table = new_table;
}

void paramInsert(sym_table& table, string id, string token, string type, int lineno, sym_table* ptr, vector<int> &modifiers){
	table.insert(make_pair(id, createEntry(token, id, type, lineno, ptr, modifiers)));
}

vector<string> getFuncArgs(string id){
	vector<string> temp;
	temp.push_back("#NO_FUNC");
	if(func_arg.find(id) != func_arg.end()) return func_arg[id].second;
	else return temp;
}

string getFuncType(string id){
	if(func_arg.find(id) != func_arg.end()) return func_arg[id].first;
	return "";
}

void insertFuncArg(string &func, vector<string> &arg, string &tp){
	func_arg.insert(make_pair(func, make_pair(string("FUNC_" +tp),arg)));
}

void recurPrintST(FILE* file, sym_table* table){
	for(auto it: (*table)){
    	fprintf(file,"%s,%s,%s,%s,%d\n", it.first.c_str(), it.second->token.c_str(), it.second->lexeme.c_str() ,it.second->type.c_str(), it.second->lineno);
  	}
	for(auto it: children_table[table]){
		recurPrintST(file, it.second);
	}
	return;
}

void printSymbolTable(sym_table* table, string file_name){
	if((*table).empty()) return;
	FILE* file = fopen(file_name.c_str(), "w");
  	fprintf( file,"Token, Lexeme, Type, Lineno\n");
	// recurPrintST(file, table);
  	for(auto it: (*table)){
    	fprintf(file,"%s,%s,%s,%d\n", it.second->token.c_str(), it.first.c_str() ,it.second->type.c_str(), it.second->lineno);
  	}
  	fclose(file);
}

string funcProtoLookup(string id){
	if(func_arg.find(id)!= func_arg.end())return func_arg[id].first;
	else return "";
}

void endSymbolTable(){
	cur_table = parent_table[cur_table];
}