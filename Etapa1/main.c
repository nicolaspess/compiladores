// Etapa 1
// Daniel Machado Nidejelski, Nícolas Vincent Dall'Bello Pessutto 

#include <stdio.h>
#include <stdin.h>
#include <stdlib.h>
#include "tokens.h"

extern int isRunning();
extern int getLineNumber();
extern void initMe();
extern FILE* yyin;
extern FILE* yytext;
extern int yylex();

int main(int argc, char *argv[]){
	int tok;
	FILE* file;
	
	if (!(file = fopen("teste1.txt", "r"))) {
		printf ("Erro em arq!");
	}
	
	yyin = file;
	initMe();
	
	while(isRunning()){
		tok = yylex();
		if(!isRunning()) break;
		
		switch(tok){
			case KW_CHAR:   printf("CHAR - Linha: %d \n", getLineNumber()); break;
            		case KW_INT:    printf("INT - Linha: %d \n", getLineNumber()); break;
            		case KW_FLOAT:  printf("FLOAT - Linha: %d \n", getLineNumber()); break;
            		case KW_IF:     printf("IF - Linha: %d \n", getLineNumber()); break;
            		case KW_THEN:   printf("THEN - Linha: %d \n", getLineNumber()); break;
            		case KW_ELSE:   printf("ELSE - Linha: %d \n", getLineNumber()); break;
            		case KW_WHILE:  printf("WHILE - Linha: %d \n", getLineNumber()); break;
            		case KW_FOR:    printf("FOR - Linha: %d \n", getLineNumber()); break;
            		case KW_READ:   printf("READ - Linha: %d \n", getLineNumber()); break;
			case KW_PRINT:  printf("PRINT - Linha: %d \n", getLineNumber()); break;
            		case KW_RETURN:	printf("RETURN - Linha: %d \n", getLineNumber()); break;
					
            		case OPERATOR_LE:  printf("OPERATOR_LE - Linha: %d \n", getLineNumber()); break;
            		case OPERATOR_GE:  printf("OPERATOR_GE - Linha: %d \n", getLineNumber()); break;
            		case OPERATOR_EQ:  printf("OPERATOR_EQ - Linha: %d \n", getLineNumber()); break;
            		case OPERATOR_NE:  printf("OPERATOR_NE - Linha: %d \n", getLineNumber()); break;
            		case OPERATOR_AND: printf("OPERATOR_AND - Linha: %d \n", getLineNumber()); break;
            		case OPERATOR_OR:  printf("OPERATOR_OR - Linha: %d \n", getLineNumber()); break;
					
            		case TK_IDENTIFIER: printf("TOK_IDENTIF - Linha: %d \n", getLineNumber()); break;
			case LIT_INTEGER:   printf("LIT_INT - Linha: %d \n", getLineNumber()); break;
            		case LIT_REAL:      printf("LIT_REAL - Linha: %d \n", getLineNumber()); break;
            		case LIT_CHAR:      printf("LIT_CHARAC - Linha: %d \n", getLineNumber()); break;
            		case LIT_STRING:    printf("LIT_STRING - Linha: %d \n", getLineNumber()); break;
            		case TOKEN_ERROR:   printf("ERRO - Linha: %d \n", getLineNumber()); break;
            		default:            printf("UNKNOWN - Linha: %d | SIMB. =  %c \n", getLineNumber(),tok); break;
		}
	}	
	//hash_Print();
        exit(0); 
}
