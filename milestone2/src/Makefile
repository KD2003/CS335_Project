compile:
	bison -dv parser.y
	flex scanner.l
	g++ -o milestone2 AST.cpp symbol_table.cpp typecheck.cpp parser.tab.c lex.yy.c -lfl
