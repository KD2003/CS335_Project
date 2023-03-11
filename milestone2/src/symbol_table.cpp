#include "symbol_table.h"

// sym_table gst;
// map<sym_table*, sym_table*> parent_table;
// map<string, pair< string,vector<string> > > func_arg;
// sym_table* curr_table;
// stack<int> Goffset, Loffset, blockSz;
// int max_size = 0;
// int param_offset = -4;
// int struct_count = 1;
// int avl=0;
// extern int isArray;
// extern vector<int> array_dims;
// extern map<string, int> func_usage_map;
// extern int dump_sym_table;
// map<string, pair<string, int>> globaldecl;
// int blockCnt = 1;

// // initialize base symbol table
// void symTable_init(){
// 	Goffset.push(0);
// 	Loffset.push(0);
// 	blockSz.push(0);
// 	parent_table.insert(make_pair(&gst, nullptr));
// 	curr_table = &gst;
// 	insertKeywords();
// }

// // constructor for symbol table entry
// sym_entry* createEntry(string type, int size, int offset, sym_table* ptr){
// 	sym_entry* new_sym = new sym_entry();
// 	new_sym->type = type;
// 	new_sym->size = size;
// 	new_sym->offset = offset;
// 	new_sym->entry = ptr;
// 	return new_sym;
// }

// // create new symbol tables for new scopes
// void makeSymbolTable(string name, string f_type, int offset_flag){
// 	if(!avl){
// 		sym_table* new_table = new sym_table;

// 		if(f_type != "") insertSymbol(*curr_table, name , "FUNC_" + f_type , 0 , new_table);
// 		else{
// 			insertSymbol(*curr_table, name , "Block",0, new_table);
// 			blockCnt++;
// 		}

// 		Goffset.push(0);
// 		if(offset_flag)blockSz.push(0);
// 		parent_table.insert(make_pair(new_table, curr_table));

// 		curr_table = new_table;
// 	}
// 	else{
// 		avl = 0;
// 		(*parent_table[curr_table]).erase("dummyF_name");
// 		(*parent_table[curr_table]).insert(make_pair(name, createEntry("FUNC_"+f_type,0,Loffset.top(), curr_table)));
// 		Loffset.pop();
// 	}
// }

// // remove func prototype from symbol table
// void removeFuncProto(){
// 	avl = 0;
// 	clear_paramoffset();
// 	updSymbolTable("dummyF_name",1);
// 	parent_table.erase((*curr_table)["dummyF_name"]->entry);
// 	(*curr_table).erase("dummyF_name");
// 	Loffset.pop();
// }

// // update current symbol table and set parent as current (end of scope)
// void updSymbolTable(string id, int offset_flag){
// 	int temp = Goffset.top();
// 	Goffset.pop();
// 	Goffset.top()+=temp;

// 	curr_table = parent_table[curr_table];

// 	sym_entry* entry = lookup(id);
// 	if(entry) entry->size = blockSz.top();

// 	if(offset_flag){
// 		temp = blockSz.top();
// 		blockSz.pop();
// 		blockSz.top()+=temp;
// 	}
// }

// // look up currently visible symbol table entry that corresponds to the id
// sym_entry* lookup(string id){
// 	sym_table* temp = curr_table;
// 	while(temp){
// 		if((*temp).find(id)!=(*temp).end()) return (*temp)[id];
// 		temp = parent_table[temp];
// 	}
// 	return nullptr;
// }

// // look up function prototype parameter list
// string funcProtoLookup(string id){
// 	if(func_arg.find(id)!= func_arg.end())return func_arg[id].first;
// 	else return "";
// }

// // find total size of local variables a function
// int func_local_size(string name){
// 	return gst[name]->size;
// }

// // look up for a symbol in current symbol table only (only the current scope)
// sym_entry* currLookup(string id){
// 	if((*curr_table).find(id)==(*curr_table).end()) return nullptr;
// 	return (*curr_table)[id];
// }

// // insert keywords into global symbol table
// void insertKeywords(){
// 	vector<string> key_words = {"auto","break","case","char","const","continue","default","do","double","else","enum","extern","float","for","goto","if","int","long","register","return","short","signed","sizeof","static","struct","switch","typedef","union","unsigned","void","volatile","while"}; 
// 	vector<string> op = {"...",">>=","<<=","+=","-=","*=","/=","%=","&=","^=","|=",">>","<<","++","--","->","&&","||","<=",">=","==","!=",";","{","<%","}","%>",",",":","=","(",")","[","<:","]",":>",".","&","!","~","-","+","*","/","%","<",">","^","|","?"};

// 	for(auto h:key_words){
// 		insertSymbol(*curr_table, h, "keyword", 8, nullptr);
// 	}
// 	for(auto h:op){
// 		insertSymbol(*curr_table, h, "operator", 8, nullptr);
// 	}
	
// 	// important io functions
// 	vector<string> type = {"char*", "..."};
// 	insert_imp_func("printf", type, "int");
// 	insert_imp_func("scanf", type, "int");

// 	// dynamic allocation functions
// 	type = {"int"};
// 	insert_imp_func("malloc", type, "void*");
// 	type = {"int", "int"};
// 	insert_imp_func("calloc", type, "void*");
// 	type = {"void*"};
// 	insert_imp_func("free", type, "void");

// 	// file io functions
// 	type = {"char*", "char*"};
// 	insert_imp_func("fopen", type, "FILE*");
// 	type = {"char*", "FILE*"};
// 	insert_imp_func("fputs", type, "int");
// 	type = {"char*", "int", "FILE*"};
// 	insert_imp_func("fgets", type, "int");
// 	type = {"FILE*"};
// 	insert_imp_func("fclose", type, "int");
// 	type = {"FILE*", "char*", "..."};
// 	insert_imp_func("fprintf", type, "int");
// 	type = {"FILE*", "char*", "..."};
// 	insert_imp_func("fscanf", type, "int");
// 	type = {"FILE*"};
// 	insert_imp_func("fgetc", type, "char");
// 	type = {"char", "FILE*"};
// 	insert_imp_func("fputc", type, "char");

// 	// string Functions
// 	type = {"char*"};
// 	insert_imp_func("strlen", type, "int");
// 	type = {"char*", "char*"};
// 	insert_imp_func("strcmp", type, "int");
// 	type = {"char*", "char*", "int"};
// 	insert_imp_func("strncmp", type, "int");
// 	type = {"char*", "char*"};
// 	insert_imp_func("strcpy", type, "char*");
// 	insert_imp_func("strcat", type, "char*");
// }

// // helper function to insert library functions in symbol table
// void insert_imp_func(string func_name, vector<string> type, string ret_type){
// 	insertSymbol(*curr_table, func_name, "FUNC_"+ret_type, 4, nullptr);
// 	func_arg.insert({func_name, make_pair("FUNC_"+ret_type, type)});
// 	func_usage_map.insert({func_name, 0});
// }

// // find the type of a symbol
// string getType(string id){
// 	sym_entry* entry = lookup(id);
// 	string ret = "";
// 	if(entry) ret += entry->type;
// 	return ret;
// }

// // initialize creation of a function table
// void createParamList(){
// 	Loffset.push(Goffset.top());
// 	makeSymbolTable("dummyF_name", "",1);
// 	avl = 1;
// }

// // create a symbol table entry and put it in the given symbol table
// void insertSymbol(sym_table& table, string id, string type, int size, sym_table* ptr){
// 	table.insert(make_pair(id, createEntry(type, size, blockSz.top(), ptr)));
// 	if(type[type.length()-1] == '*' && !array_dims.empty()){
// 		vector<int> temp;
// 		int curr = 1;
// 		for(int i = array_dims.size()-1; i>=1; i--){
// 			curr*=array_dims[i];
// 			temp.push_back(curr);
// 		}
// 		reverse(temp.begin(), temp.end());
// 		table[id]->array_dims = temp;
// 		if(isArray){
// 			table[id]->isArray = 1;
// 			isArray = 0;
// 		}
// 		array_dims.clear();
// 	}
// 	blockSz.top()+=size;
// 	Goffset.top()+=size;
// }

// // insert function parameters into the symbol table of the function
// void paramInsert(sym_table& table, string id, string type, int size, sym_table* ptr){
// 	table.insert(make_pair(id, createEntry(type, size, param_offset-size, ptr)));
// 	if(type[type.length()-1] == '*' && !array_dims.empty()){
// 		size = 4;
// 		vector<int> temp;
// 		int curr = 1;
// 		for(int i = array_dims.size()-1; i>=1; i--){
// 			curr*=array_dims[i];
// 			temp.push_back(curr);
// 		}
// 		reverse(temp.begin(), temp.end());
// 		table[id]->array_dims = temp;
// 		table[id]->offset = param_offset - size;
// 		array_dims.clear();
// 	}
// 	param_offset-=size;
// }

// // reset parameter offset global variable before insertion
// void clear_paramoffset(){
// 	param_offset = -4;
// }

// // return the list of function arguments
// vector<string> getFuncArgs(string id){
// 	vector<string> temp;
// 	temp.push_back("#NO_FUNC");
// 	if(func_arg.find(id) != func_arg.end()) return func_arg[id].second;
// 	else return temp;
// }

// // return the return type of the required function
// string getFuncType(string id){
// 	if(func_arg.find(id) != func_arg.end()) return func_arg[id].first;
// 	return "";
// }

// // update the argument list and return type of a function
// void insertFuncArg(string &func, vector<string> &arg, string &tp){
// 	func_arg.insert(make_pair(func, make_pair(string("FUNC_" +tp),arg)));
// }

// // set global variables
// void setGlobal(){
// 	for(auto &it: gst){
// 		if(it.second->type.substr(0,2) == "in" || it.second->type.substr(0,2)=="ch"){
// 			globaldecl.insert(make_pair(it.first,make_pair("0", 0)));
// 			if(it.second->size > 4) globaldecl[it.first].second = it.second->size/4;
// 		}
// 	}
// }

// // write the specified symbol table into a csv file
// void printSymbolTable(sym_table* table, string file_name){
// 	if(!dump_sym_table) return;
// 	FILE* file = fopen(file_name.c_str(), "w");
//   	fprintf( file,"Name, Type, Size, isInitialized, Offset\n");
//   	for(auto it: (*table)){
//     	fprintf(file,"%s,%s,", it.first.c_str(), it.second->type.c_str());
// 		fprintf(file, "%d,%d\n", (it.second)->size, (it.second)->offset);
//   	}
//   	fclose(file);
// }


// NEW
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