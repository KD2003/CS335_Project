compile:
	bison -dv parser.y
	flex scanner.l
	g++ -o ASTGenerator parser.tab.c lex.yy.c test.cpp -lfl
