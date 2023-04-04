#include "symbol_table.h"
#include <algorithm>
#include <iostream>

sym_table global_st;
map<sym_table*, sym_table*> parent_table;
map<sym_table*, vector<pair<string, sym_table*>>> children_table;
map<string, pair< string,vector<string> > > func_arg;
sym_table* cur_table;
map<string, vector<pair<string, int>>> classVariable;

extern int isArray;
extern vector<int> array_dims;
extern string file_path;
string curClass="";

void symbolTableInit(){
	parent_table.insert(make_pair(&global_st, nullptr));
	children_table.insert(make_pair(&global_st, vector<pair<string, sym_table*>> ()));
	cur_table = &global_st;
	vector<int> temp = {1,0,0};
	insertSymbol(*cur_table, "String" , "CLASS", "CLASS", 0, NULL, temp, 0);
	// insert keywords?
}

sym_entry* createEntry(string token, string type, int lineno, sym_table* ptr, vector<int> &modifiers, int size){
	sym_entry* new_symEnt = new sym_entry;
	new_symEnt->token = token;
	new_symEnt->type = type;
	new_symEnt->lineno = lineno;
	new_symEnt->entry = ptr;
	new_symEnt->modifiers[0] = modifiers[0];
	new_symEnt->modifiers[1] = modifiers[1];
	new_symEnt->modifiers[2] = modifiers[2];
	new_symEnt->size = size;
	// new_symEnt->offset = offset;
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

void insertSymbol(sym_table& table, string id, string token, string type, int lineno, sym_table* ptr, vector<int> &modifiers, int size){
	table.insert(make_pair(id, createEntry(token, type, lineno, ptr, modifiers, size)));
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
	if(parent_table[&table] == &global_st){
		classVariable[curClass].push_back(make_pair(id, size));
	}
}

void makeSymbolTable(string name, string f_type, int lineno, vector<int> &modifiers){
	sym_table* new_table = new sym_table;
	
	if(f_type == "CLASS"){
		insertSymbol(*cur_table, name , f_type, f_type, lineno, new_table, modifiers, 0);
		curClass = name;
		classVariable.insert(make_pair(curClass, vector<pair<string, int>> ()));
	}
	else if(f_type == "Constructor"){
        insertSymbol(*cur_table, name, f_type, f_type, lineno, new_table, modifiers, 0);
    }
	else if(f_type != ""){
		insertSymbol(*cur_table, name , "FUNC_", "FUNC_" + f_type, lineno, new_table, modifiers, 0);
	}
	else{
		insertSymbol(*cur_table, name , "Block", "", lineno, new_table, modifiers, 0);
	}
	parent_table.insert(make_pair(new_table, cur_table));
	if(children_table.find(cur_table) == children_table.end()){
		children_table.insert(make_pair(cur_table, vector<pair<string, sym_table*>> ()));
	}
	children_table[cur_table].push_back(make_pair(name,new_table));
	cur_table = new_table;
}

void paramInsert(sym_table& table, string id, string token, string type, int lineno, sym_table* ptr, vector<int> &modifiers, int size){
	table.insert(make_pair(id, createEntry(token, type, lineno, ptr, modifiers, size)));
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
		string st = "Private";
		if(it.second->modifiers[0]==2) st="Public";
    	fprintf(file,"%s,%s,%s,%d,%s\n", it.second->token.c_str(), it.first.c_str() ,it.second->type.c_str(), it.second->lineno, st.c_str());
  	}
	for(auto it: children_table[table]){
		recurPrintST(file, it.second);
	}
	return;
}

void printSymbolTable(sym_table* table, string file_name){
	if((*table).empty()) return;
	FILE* file = fopen((file_path+file_name).c_str(), "w");
  	fprintf( file,"Token, Lexeme, Type, Lineno,PublicPrivate\n");
	// recurPrintST(file, table);
  	for(auto it: (*table)){
		string st = "Private";
		if(it.second->modifiers[0]==2) st="Public";
		if(it.second->token == "Temp_var") continue;
    	fprintf(file,"%s,%s,%s,%d,%s,%d\n", it.second->token.c_str(), it.first.c_str() ,it.second->type.c_str(), it.second->lineno, st.c_str(), it.second->size);
  	}
  	fclose(file);
}

string funcProtoLookup(string id){
	if(func_arg.find(id)!= func_arg.end())return func_arg[id].first;
	else return "";
}

void endSymbolTable(){
	sym_table* temp_table = cur_table;
	int sum=0;
	string temp_name;
	for(auto it: *temp_table){
		sum+=it.second->size;
	}
	cur_table = parent_table[cur_table];
	for(auto it: children_table[cur_table]){
		if(it.second == temp_table){
			temp_name = it.first;
			break;
		}
	}
	(*cur_table)[temp_name]->size = sum;
}

int classLookup(string id){
	if(id == "String") return 2;
	int sum=0;
	for(auto it: children_table[&global_st]){
		if(it.first == id){
			for(auto it1: *(it.second)){
				string st = it1.second->type;
				if(st.substr(0,5)!="FUNC_"){
					sum += getSize(st);
				}
			}
			return sum;
		}
	}
	return -1;
}

int getSize(string id){
	int x =classLookup(id);
	if(x!=-1) return x;
	if(id == "byte") return 1;
	if(id == "short") return 2;
	if(id == "int") return 4;
	if(id == "long") return 8;
	if(id == "float") return 4;
	if(id == "double") return 8;
	if(id == "boolean") return 1;
	if(id == "char") return 0;
	return 0;
}

int getOffset(string class_name, string id){
	int curOff=0;
	for(auto it: classVariable[class_name]){
		cout << it.first << endl;
		if(it.first == id){
			return curOff;
		}
		curOff += it.second;
	}
	return -1;		// id not found
}

int getFuncSize(string name){
	sym_table* temp_table = cur_table;
	while(temp_table){
		for(auto it: *temp_table){
			if(it.second->token == "FUNC_" && it.first == name){
				return it.second->size;
			}
		}
		temp_table=parent_table[temp_table];
	}
	return -1;
}

int getClassSize(string name){
	int sum =0;
	sym_table* temp_table;
	for(auto it: children_table[&global_st]){
		if(it.first == name) temp_table = it.second;
	}
	if(!temp_table) return -1;
	for(auto it: *temp_table){
		if(it.second->token == "IDENTIFIER" || it.second->token == "Temp_var" || it.second->token == "Block"){
			sum+=it.second->size;
		}
	}
	return sum;
}