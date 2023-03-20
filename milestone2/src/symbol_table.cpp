#include "symbol_table.h"

sym_table global_st;
map<sym_table*, sym_table*> parent_table;
map<string, pair< string,vector<string> > > func_arg;
sym_table* cur_table;

int avl = 0;

// extern int isArray;
extern int dump_sym_table;
// extern vector<int> array_dims;

void symbolTableInit(){
	parent_table.insert(make_pair(&global_st, nullptr));
	cur_table = &global_st;
	// insert keywords?
}

sym_entry* createEntry(string token, string lexeme, string type, int lineno, sym_table* ptr){
	sym_entry* new_symEnt = new sym_entry;
	new_symEnt->token = token;
	new_symEnt->lexeme = lexeme;
	new_symEnt->type = type;
	new_symEnt->lineno = lineno;
	new_symEnt->entry = ptr;
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

void insertSymbol(sym_table& table, string id, string token, string lexeme, string type, int lineno, sym_table* ptr){
	table.insert(make_pair(id, createEntry(token, lexeme, type, lineno, ptr)));
	// if(type[type.length()-1] == '*' && !array_dims.empty()){
	// 	vector<int> temp;
	// 	int cur = 1;
	// 	for(int i = array_dims.size()-1; i>=1; i--){
	// 		cur*=array_dims[i];
	// 		temp.push_back(cur);
	// 	}
	// 	reverse(temp.begin(), temp.end());
	// 	table[id]->array_dims = temp;
	// 	if(isArray){
	// 		table[id]->isArray = 1;
	// 		isArray = 0;
	// 	}
	// 	array_dims.clear();
	// }
}

void makeSymbolTable(string name, string f_type, int lineno){
	if(!avl){
		sym_table* new_table = new sym_table;

		if(f_type != "") insertSymbol(*cur_table, name , "FUNC", f_type, "FUNC", lineno, new_table);
		else{
			insertSymbol(*cur_table, name , "Block", "", "", lineno, new_table);
		}
		parent_table.insert(make_pair(new_table, cur_table));

		cur_table = new_table;
	}
	else{
		avl = 0;
		(*parent_table[cur_table]).erase("dummyF_name");
		(*parent_table[cur_table]).insert(make_pair(name, createEntry("FUNC", f_type, "FUNC", lineno, cur_table)));
	}
}

void createParamList(int lineno){
	makeSymbolTable("dummyF_name", "",lineno);
	avl = 1;
}

void paramInsert(sym_table& table, string id, string token, string lexeme,string type, int lineno, sym_table* ptr){
	table.insert(make_pair(id, createEntry(token, lexeme, type, lineno, ptr)));
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

void printSymbolTable(sym_table* table, string file_name){
	if(!dump_sym_table) return;
	FILE* file = fopen(file_name.c_str(), "w");
  	fprintf( file,"Name, Token, Lexeme, Type, Lineno\n");
  	for(auto it: (*table)){
    	fprintf(file,"%s,%s,%s,%s,%d\n", it.first.c_str(), it.second->token.c_str(), it.second->lexeme.c_str() ,it.second->type.c_str(), it.second->lineno);
  	}
  	fclose(file);
}

string funcProtoLookup(string id){
	if(func_arg.find(id)!= func_arg.end())return func_arg[id].first;
	else return "";
}

void removeFuncProto(){
	avl = 0;
	endSymbolTable("dummyF_name");
	parent_table.erase((*cur_table)["dummyF_name"]->entry);
	(*cur_table).erase("dummyF_name");
}

void endSymbolTable(string id){
	cur_table = parent_table[cur_table];
}