compile:
	bison -dv parser.y
	flex scanner.l
	g++ -o ASTGenerator AST.cpp parser.tab.c lex.yy.c -lfl
