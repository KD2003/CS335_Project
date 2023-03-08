#pragma once

#include <bits/stdc++.h>
using namespace std;
#define ll long long

typedef struct sym_entry{
    string token;
    string lexeme;
	string type;
    int lineno;
	int size;
	bool init;
	int offset;
	map<string, sym_entry* > * entry;
	struct desc { 
		string reg;
		bool stack;
		bool heap;
	} addr_descriptor;

	int heap_mem = 0;
	int next_use = -1;
	int is_derefer = 0;
	int isArray = 0;
	int size_of_pointed = 0;
	int is_global = 0;

	vector<int> array_dims;
	string storage_class;
}sym_entry;