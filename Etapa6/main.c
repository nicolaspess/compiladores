#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "compila.h"
#include "semantic.h"
#include "tac.h"
#include "genasm.h"

int isRunning();
int yyparse();
int yylex();
void yyerror(const char *s);
void initMe();
int semantic(ASTREE *rootNode, map_t* scope);

extern FILE *yyin;
extern char *yytext;
extern int yylineno;

int main(int argc, char *argv[]) {
	if (argc != 3) exit(1);

	initMe();

	FILE *fp;
	fp = fopen(argv[1],"r");
	if (fp == NULL) {
		printf("Nao consegue abrir arquivo de entrada: %s\n",argv[1]);
		exit(2);
	}

	FILE *output;
	output = fopen(argv[2],"w");
	if (output == NULL) {
		printf("Nao consegue abrir arquivo de saida: %s\n",argv[2]);
		exit(2);
	}
	setOutputFile(output);

	yyin = fp;

	int parseError = yyparse();
	if(parseError==1) {
		exit(3);
	}
        else printf("\n Sintaxe correta! OK! \n");

	astPrint(root,0);

	int semanticResult = semantic(root, programScope);
	printf("semanticResult = %d\n", semanticResult);
	
	if( semanticResult != 0) {
		printf("Erro na verificacao semantica.\n");
	} else {
		printf("Semantica correta! OK.\n");
	}

	TAC* tac = 0;
        printf("Inicia geracao de codigo.\n");
	tac = generateCode(root);
        printf("Geracao de codigo OK.\n");
        printf("Inicia inversao de TAC.\n");
	tac = tacReverse(tac);
        printf("Inversao de TAC OK.\n");
        printf("Inicia PrintForward TAC.\n");
	tacPrintForward(tac);
        printf("PrintForward TAC OK.\n");
    asmGenerator("out.s",tac);
	exit(semanticResult);
}
