// Etapa 1
// Daniel Machado Nidejelski, Nícolas Vincent Dall'Bello Pessutto 

#include <stdio.h>
#include "tokens.h"

//colocar externs !!!!

int main(int argc, char *argv[]){
    int tok;
	if(argc<2){
		fprintf(stderr,"Err!");
		return 1;
	}
	if(!(file(argv[1]))){
		fprintf(stderr,"Err: nao consegue abrir arq! %s.\n",argv[1]);
		return 2;
	}
	initMe();
	while(isRunning()){
		tok = yylex();
		if(!isRunning()) break;
		switch(tok){
            		case KW_CHAR:		fprintf(stderr, "KW_CHAR linha: %d | TOKEN =  %d \n", getLineNumber(),KW_CHAR); break;
            		case KW_INT:		fprintf(stderr, "KW_INT linha: %d | TOKEN =  %d \n", getLineNumber(),KW_INT); break;
            		case KW_FLOAT:		fprintf(stderr, "KW_FLOAT linha: %d | TOKEN =  %d \n", getLineNumber(),KW_FLOAT); break;
            		case KW_IF:			fprintf(stderr, "KW_IF linha: %d | TOKEN =  %d \n", getLineNumber(),KW_IF); break;
            		case KW_THEN:		fprintf(stderr, "KW_THEN linha: %d | TOKEN =  %d \n", getLineNumber(),KW_THEN); break;
            		case KW_ELSE:		fprintf(stderr, "KW_ELSE linha: %d | TOKEN =  %d \n", getLineNumber(),KW_ELSE); break;
            		case KW_WHILE:		fprintf(stderr, "KW_WHILE linha: %d | TOKEN =  %d \n", getLineNumber(),KW_WHILE); break;
            		case KW_FOR:		fprintf(stderr, "KW_FOR linha: %d | TOKEN =  %d \n", getLineNumber(),KW_FOR); break;
            		case KW_READ:		fprintf(stderr, "KW_READ linha: %d | TOKEN =  %d \n", getLineNumber(),KW_READ); break;
					case KW_PRINT:		fprintf(stderr, "KW_PRINT linha: %d | TOKEN =  %d \n", getLineNumber(),KW_PRINT); break;
            		case KW_RETURN:		fprintf(stderr, "KW_RETURN linha: %d | TOKEN =  %d \n", getLineNumber(),KW_RETURN); break;
					
            		case OPERATOR_LE:	fprintf(stderr, "OPERATOR_LE linha: %d | TOKEN =  %d \n", getLineNumber(),OPERATOR_LE); break;
            		case OPERATOR_GE:	fprintf(stderr, "OPERATOR_GE linha: %d | TOKEN =  %d \n", getLineNumber(),OPERATOR_GE); break;
            		case OPERATOR_EQ:	fprintf(stderr, "OPERATOR_EQ linha: %d | TOKEN =  %d \n", getLineNumber(),OPERATOR_EQ); break;
            		case OPERATOR_NE:	fprintf(stderr, "OPERATOR_NE linha: %d | TOKEN =  %d \n", getLineNumber(),OPERATOR_NE); break;
            		case OPERATOR_AND:	fprintf(stderr, "OPERATOR_AND linha: %d | TOKEN =  %d \n", getLineNumber(),OPERATOR_AND); break;
            		case OPERATOR_OR:	fprintf(stderr, "OPERATOR_OR linha: %d | TOKEN =  %d \n", getLineNumber(),OPERATOR_OR); break;
					
            		case TOK_IDENTIF:	fprintf(stderr, "TOK_IDENTIF linha: %d | TOKEN =  %d \n", getLineNumber(),TOK_IDENTIF); break;
            		case LIT_INT:		fprintf(stderr, "LIT_INT linha: %d | TOKEN =  %d \n", getLineNumber(),LIT_INT); break;
            		case LIT_REAL:		fprintf(stderr, "LIT_REAL linha: %d | TOKEN =  %d \n", getLineNumber(),LIT_REAL); break;
            		case LIT_CHARAC:	fprintf(stderr, "LIT_CHARAC linha: %d | TOKEN =  %d \n", getLineNumber(),LIT_CHARAC); break;
            		case LIT_STRING:	fprintf(stderr, "LIT_STRING linha: %d | TOKEN =  %d \n", getLineNumber(),LIT_STRING); break;
            		case ERRO:			fprintf(stderr, "ERRO linha: %d | TOKEN =  %d \n", getLineNumber(),ERRO); break;
            		default:			fprintf(stderr, "CARACTER ESPECIAL linha: %d | TOKEN =  %d \n", getLineNumber(),tok); break;
		}
	}	
	hashPrint();
    return 0; 
}