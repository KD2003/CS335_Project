#include "symbol_table.h"
#include <string>
using namespace std;

string primaryExpression(string id);
string postfixExpression(string type_name, int rule_num);
string checkType(string a, string b);
string argExp(string a, string b, int  rule_num);
string unaryExp(string op, string type);
string mulExp(string a, string b, char op);
string addExp(string a, string b, char op);
string shiftExp(string a, string b);
string relExp(string a, string b);
string eqExp(string a, string b);
string bitExp(string a, string b);
string assignExp(string a, string b, string op);
string condExp(string a,string b);
bool isInt(string type);
bool isFloat(string type);
bool isVoid(string type);