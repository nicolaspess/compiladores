etapa5: y.tab.o lex.yy.o main.o tabelaHash.o ast.o semantic.o tac.o
	gcc -o etapa5 y.tab.o lex.yy.o main.o tabelaHash.o ast.o semantic.o tac.o

tac.o: tac.c
	gcc -c tac.c

main.o: main.c
	gcc -c main.c

ast.o: ast.c
	gcc -c ast.c

semantic.o:
	gcc -c semantic.c

tabelaHash.o: tabelaHash.c
	gcc -c tabelaHash.c

y.tab.o: y.tab.c lex.yy.h
	gcc -c y.tab.c

y.tab.c: parser.y
	yacc -d -v parser.y

lex.yy.o: lex.yy.c
	gcc -c lex.yy.c

lex.yy.h: scanner.l
	lex scanner.l

lex.yy.c: scanner.l
	lex scanner.l

clean:
	rm *.o lex.yy.c y.tab.c y.tab.h etapa5
