#
# UFRGS - Compiladores B - Marcelo Johann - 2009/2 - Etapa 1
#
# Makefile for single compiler call
# All source files must be included from code embedded in scanner.l
# In our case, you probably need #include "tabelaHash.c" at the beginning
# and #include "main.c" in the last part of the scanner.l
#

etapa6: tabelaHash.o y.tab.o symbols.o lex.yy.o ast.o compila.o semantic.o tac.o genasm.o main.o 
	gcc -o etapa6  y.tab.o lex.yy.o symbols.o tabelaHash.o ast.o compila.o semantic.o tac.o genasm.o main.o

main.o: main.c
	gcc -c main.c -Wall
tabelaHash.o: tabelaHash.c
	gcc -c tabelaHash.c -Wall
symbols.o: symbols.c
	gcc -c symbols.c -Wall
ast.o: ast.c
	gcc -c ast.c -Wall
compila.o: compila.c
	gcc -c compila.c -Wall
semantic.o: semantic.c
	gcc -c semantic.c -Wall

genasm.o: genasm.c
	gcc -c genasm.c -Wall

tac.o: tac.c
	gcc -c tac.c -Wall

y.tab.o: y.tab.c
	gcc -c y.tab.c -Wall
y.tab.c: parser.y
	yacc parser.y -d

lex.yy.o: lex.yy.c
	gcc -c lex.yy.c -Wall
lex.yy.c: scanner.l symbols.c tabelaHash.c 
	lex scanner.l

clean:
	rm *.o lex.yy.c y.tab.c y.tab.h etapa6