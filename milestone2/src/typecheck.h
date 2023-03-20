#include "symbol_table.h"
#include <string>
using namespace std;

string primaryExpression(string id);
string postfixExpression(string type_name, int rule_num);
string checkType(string a, string b);
string unaryExp(string type, string op);
string mulExp(string a, string b);
string addExp(string a, string b);
string shiftExp(string a, string b);
string relExp(string a, string b);
string eqExp(string a, string b);
string bitExp(string a, string b);
string assignExp(string a, string b, string op);
string condExp(string a,string b, string c,string op);
string promotedType(string a, string b);
bool isInt(string type);
bool isFloat(string type);
bool isVoid(string type);