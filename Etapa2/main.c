// Etapa 2
// Daniel Machado Nidejelski, Nícolas Vincent Dall'Bello Pessutto 

#include <stdio.h>
#include <stdlib.h>

extern int isRunning();
extern int getLineNumber();
extern void initMe();
extern FILE* yyin;
extern FILE* yytext;
extern int yylex();
extern int yyparse();

int main(int argc, char *argv[]){
	int tok;
	FILE* file;
	
	if (!(file = fopen("teste1.txt", "r"))) {
		printf ("Erro em arq!");
	}
	
	yyin = file;
	initMe();
	
	yyparse();
	
	printf("\n Sintaxe correta! OK! \n");
	
	hash_Print();
	
    exit(0); 
}
