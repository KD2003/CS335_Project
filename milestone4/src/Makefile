compile:
	bison -dtv parser.y
	flex scanner.l
	g++ -o milestone4 parser.tab.c lex.yy.c AST.cpp symbol_table.cpp typecheck.cpp 3ac.cpp codegen.cpp
