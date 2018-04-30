// Etapa 3
// Daniel Machado Nidejelski, Nícolas Vincent Dall'Bello Pessutto 

#include <stdio.h>
#include <stdlib.h>
#include "ast.h"

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
	
	if (argc < 2){
		printf("Argumentos faltando. Chamar etapa e nome do arquivo de saida. \n");
	}else if (!(file = fopen(argv[1], "r"))) {
		printf ("Erro em arq!");
	}else{
		if( source_code = fopen(argv[2], "w+")){
			yyin = file;
			initMe();
			
			yyparse();
			
			printf("\n Sintaxe correta! OK! \n");
			
			hash_Print();
			
		    exit(0); 
		}else{
			fprintf(stderr, "Erro ao criar arquivo de saída \n");
		}
	}
}
