#pragma once
#include<bits/stdc++.h>
using namespace std;
#define ll long long

typedef struct sym_entry{
    string token;
	string type;
    int lineno;
	int size;
	int offset;
	map<string, sym_entry* > * entry;

	struct desc { 
		string reg;
		bool stack;
		bool heap;
	} addr_descriptor;

	int isArray = 0;
	int is_derefer = 0;
	vector<int> array_dims;
	vector<int> modifiers = {1, 0, 0};		// public/private, static, final
}sym_entry;

typedef map<string, sym_entry* > sym_table;

extern sym_table* cur_table;
extern sym_table global_st;
extern map<sym_table*, sym_table*> parent_table;
extern map<string, pair<string,vector<string> > > func_arg;

void symbolTableInit();
sym_entry* createEntry(string, string, int, sym_table*, vector<int>&, int, int, int);
sym_entry* lookup(string id);
sym_entry* curLookup(string id);
void insertSymbol(sym_table&, string, string, string, int, sym_table*, vector<int>&, int);
void makeSymbolTable(string, string, int, vector<int>&,int);
void paramInsert(sym_table&, string, string, string, int, sym_table*, vector<int>&, int);
void clear_paramoffset();
vector<string> getFuncArgs(string);
string getFuncType(string);
void insertFuncArg(string &, vector<string> &, string &);
void printSymbolTable(sym_table*, string);
string funcProtoLookup(string);
void endSymbolTable(int);
int getSize(string);
int getOffset(string, string);
int getFuncSize(string);
int getClassSize(string);