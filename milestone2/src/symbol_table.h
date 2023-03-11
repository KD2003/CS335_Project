#pragma once

#include <bits/stdc++.h>
using namespace std;
#define ll long long

// typedef struct sym_entry{
//     string token;
//     string lexeme;
// 	string type;
//     int lineno;
// 	int size;
// 	int offset;
// 	map<string, sym_entry* > * entry;

// 	int isArray = 0;
// 	vector<int> array_dims;
// }sym_entry;

// typedef map<string, sym_entry* > sym_table; 
// typedef map<string, pair< int, sym_table* > > struct_sym_table;

// extern sym_table gst;
// extern map<sym_table*, sym_table*> parent_table;
// extern map<string, pair<string,vector<string> > > func_arg;
// extern sym_table* curr_table;
// extern stack<int> Goffset, Loffset, blockSz;
// extern int avl;

// void symTable_init();
// sym_entry* createEntry(string type, int size, int offset);
// void makeSymbolTable(string name, string f_type,int flag);
// void removeFuncProto();
// void updSymbolTable(string id,int flag);
// sym_entry* lookup(string id);
// sym_entry* currLookup(string id);
// void insertKeywords();
// string getType(string id);
// void createParamList();
// void insertSymbol(sym_table& table, string id, string type, int size, sym_table* ptr);
// vector<string> getFuncArgs(string id);
// void insertFuncArg(string &func, vector<string> &arg, string &tp);
// string getFuncType(string id);
// string funcProtoLookup(string id);
// void printSymbolTable(sym_table* table, string file_name);
// void clear_paramoffset();
// void paramInsert(sym_table& table, string id, string type, int size, sym_table* ptr);
// int func_local_size(string name);
// void insert_imp_func(string func_name, vector<string> type, string ret_type);
// void setGlobal();

// NEW

typedef struct sym_entry{
    string token;
    string lexeme;
	string type;
    int lineno;
	map<string, sym_entry* > * entry;
	int isArray = 0;
	vector<int> array_dims;
}sym_entry;

typedef map<string, sym_entry* > sym_table;



void symbolTableInit();
sym_entry* createEntry(string, string, string, int, sym_table*);
sym_entry* lookup(string id);
sym_entry* curLookup(string id);
void insertSymbol(sym_table&, string, string, string, string, int, sym_table*);
void makeSymbolTable(string, string, int);
void createParamList(int);
void paramInsert(sym_table&, string, string, string,string, int, sym_table*);
vector<string> getFuncArgs(string);
string getFuncType(string);
void insertFuncArg(string &, vector<string> &, string &);
void printSymbolTable(sym_table*, string);
string funcProtoLookup(string);
void removeFuncProto();
void endSymbolTable(string);