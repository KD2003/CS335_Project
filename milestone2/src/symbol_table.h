#pragma once
#include<vector>
#include<string>
#include<map>
using namespace std;
#define ll long long

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
extern sym_table* cur_table;


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