etapa1: lex.yy.o main.o tabelaHash.o
	gcc -o etapa1 lex.yy.o main.o tabelaHash.o

main.o: main.c
	gcc -c main.c

tabelaHash.o: tabelaHash.c
	gcc -c tabelaHash.c

lex.yy.o: lex.yy.c
	gcc -c lex.yy.c

lex.yy.c: scanner.l
	flex --header-file=lex.yy.h scanner.l

clean:
	rm *.o lex.yy.c etapa1
