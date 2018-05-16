#include "ast.h"
#include <stdio.h>
#include <stdlib.h>

ASTREE* astCreate(int type, hash_Node *symbol, ASTREE *son0, ASTREE *son1, ASTREE *son2, ASTREE *son3){
	
	printf("tipo: %d \n", type);
	if (symbol == NULL){
		printf("é nulo\n");
	}else{
		printf("nao é nulo\n");
	}

	ASTREE* newnode;
	newnode = (ASTREE*) malloc(sizeof(ASTREE));
	newnode->type = type;
	newnode->symbol = symbol;
	newnode->son[0] = son0;
	newnode->son[1] = son1;
	newnode->son[2] = son2;
	newnode->son[3] = son3;
	return newnode;
}

void astPrint(ASTREE *node, int level){
	int i;
	if(!node) return;

	for(i = 0; i < level; i++)
		fprintf(stderr,"  ");
	fprintf(stderr,"AST(");
	switch(node->type){
		case ASTREE_SYMBOL: fprintf(stderr, "AST_SYMBOL, \n");break;
		case ASTREE_ADD: fprintf(stderr, "AST_ADD, \n");break;
		case ASTREE_SUB: fprintf(stderr, "AST_SUB, \n");break;
		case ASTREE_MUL: fprintf(stderr, "AST_MUL, \n");break;
		case ASTREE_DIV: fprintf(stderr, "AST_DIV, \n");break;
		case ASTREE_MOD: fprintf(stderr, "AST_MOD, \n");break;
		case ASTREE_L: fprintf(stderr, "AST_LESS, \n");break;
		case ASTREE_G: fprintf(stderr, "AST_BIGGER, \n");break;
		case ASTREE_ATR: fprintf(stderr, "AST_ASS, \n");break;
		case ASTREE_IF: fprintf(stderr, "AST_IFT, \n");break;
		case ASTREE_ELSE: fprintf(stderr, "AST_IFTE, \n");break;
		case ASTREE_WHILE: fprintf(stderr, "AST_WHILE, \n");break;
		case ASTREE_FOR: fprintf(stderr, "AST_FOR, \n");break;
		case ASTREE_BRACES: fprintf(stderr, "AST_BLOCO, \n");break;
		case ASTREE_CMDL: fprintf(stderr, "AST_BLOCOCMD, \n");break;
		case ASTREE_FIMCMDL: fprintf(stderr, "AST_FIMCMD, \n");break;
		case ASTREE_NOT: fprintf(stderr, "AST_NOT, \n");break;
		case ASTREE_PRINT: fprintf(stderr, "AST_KWPRINT, \n");break;
		case ASTREE_READ: fprintf(stderr, "AST_KWREAD, \n");break;
		case ASTREE_RETURN: fprintf(stderr, "AST_KWRETURN, \n");break;
		case ASTREE_PT1: fprintf(stderr, "AST_PT1, \n");break;
		case ASTREE_PT2: fprintf(stderr, "AST_PT2, \n");break;
		case ASTREE_ARRAY_READ: fprintf(stderr, "AST_ARR_READ, \n");break;
		case ASTREE_ARRAY_WRITE: fprintf(stderr, "AST_ARR_WRITE, \n");break;
		case ASTREE_FUNCALL: fprintf(stderr, "AST_FUNCALL, \n");break;
		case ASTREE_ARGFUN: fprintf(stderr, "AST_ARGFUN, \n");break;
		case ASTREE_ARGFUNFIM: fprintf(stderr, "AST_ARGFUNFIM, \n");break;
		case ASTREE_PARENTHESIS: fprintf(stderr, "AST_EXP, \n");break;
		case ASTREE_ASSPT1: fprintf(stderr, "AST_ASSPT1, \n");break;
		case ASTREE_ASSPT2: fprintf(stderr, "AST_ASSPT2, \n");break;
		case ASTREE_CHAR: fprintf(stderr, "AST_KWCHAR, \n");break;
		case ASTREE_INT: fprintf(stderr, "AST_KWINT, \n");break;
		case ASTREE_FLOAT: fprintf(stderr, "AST_KWFLOAT, \n");break;
		case ASTREE_DFNL: fprintf(stderr, "AST_LDEC, \n");break;
		case ASTREE_VARINI: fprintf(stderr, "AST_DEC, \n");break;
		case ASTREE_VARPT: fprintf(stderr, "AST_DECPT, \n");break;
		case ASTREE_VARPTINI: fprintf(stderr, "AST_DECPTASS, \n");break;
		case ASTREE_ARRINI: fprintf(stderr, "AST_DECARR, \n");break;
		case ASTREE_FUNDEF: fprintf(stderr, "AST_DECFUN, \n");break;
		case ASTREE_PRINTARG: fprintf(stderr, "AST_PRINTARG, \n");break;
		case ASTREE_PARL: fprintf(stderr, "AST_LPARAM, \n");break;
		case ASTREE_FPARL: fprintf(stderr, "AST_FPARAM, \n");break;
		case ASTREE_PARAM: fprintf(stderr, "AST_PARAM, \n");break;
		case ASTREE_INTL: fprintf(stderr, "AST_INI, \n");break;
		case ASTREE_INTL2: fprintf(stderr, "AST_INI2, \n");break;
		case ASTREE_LE: fprintf(stderr, "AST_LE, \n" );break;
		case ASTREE_GE: fprintf(stderr, "AST_GE, \n" );break;
		case ASTREE_EQ: fprintf(stderr, "AST_EQ, \n" );break;
		case ASTREE_NE: fprintf(stderr, "AST_NE, \n" );break;
		case ASTREE_AND: fprintf(stderr, "AST_AND, \n" );break;
		case ASTREE_OR: fprintf(stderr, "AST_OR, \n" );break;
		default: fprintf(stderr, "UNKNOWN, \n");break;
	}
	for (i=0; i<MAX_SONS; i++)
		astPrint(node->son[i],level+1);
}

void printSource(ASTREE *raiz){

   printNodeSource(raiz, source_code);

	
}

void printNodeSource(ASTREE *node, FILE *source_code){
	

	if (node){
		switch(node->type){
			
			case ASTREE_SYMBOL: 
				fprintf(source_code, " %s ", node->symbol->text);
				if(node->son[0] != 0 ){
					fprintf(source_code, " ");
					printNodeSource(node->son[0], source_code);
				}
			break;

			case ASTREE_ADD: 
				printNodeSource(node->son[0], source_code);
				fprintf(source_code, " + ");
				printNodeSource(node->son[1], source_code);
			break;

			case ASTREE_SUB: 
				printNodeSource(node->son[0], source_code);
				fprintf(source_code, " - ");
				printNodeSource(node->son[1], source_code);
			break;

			case ASTREE_MUL: 
				printNodeSource(node->son[0], source_code);
				fprintf(source_code, " * ");
				printNodeSource(node->son[1], source_code);
			break;

			case ASTREE_DIV: 
				printNodeSource(node->son[0], source_code);
				fprintf(source_code, " / ");
				printNodeSource(node->son[1], source_code);
			break;

			case ASTREE_MOD: 
				printNodeSource(node->son[0], source_code);
				fprintf(source_code, " %% ");
				printNodeSource(node->son[1], source_code);
			break;

			case ASTREE_L: 
				printNodeSource(node->son[0], source_code);
				fprintf(source_code, " < ");
				printNodeSource(node->son[1], source_code);
			break;

			case ASTREE_G: 
				printNodeSource(node->son[0], source_code);
				fprintf(source_code, " > ");
				printNodeSource(node->son[1], source_code);
			break;

			case ASTREE_LE: 
				printNodeSource(node->son[0], source_code);
				fprintf(source_code, " <= ");
				printNodeSource(node->son[1], source_code);
			break;

			case ASTREE_GE: 
				printNodeSource(node->son[0], source_code);
				fprintf(source_code, " >= ");
				printNodeSource(node->son[1], source_code);
			break;

			case ASTREE_EQ: 
				printNodeSource(node->son[0], source_code);
				fprintf(source_code, " == ");
				printNodeSource(node->son[1], source_code);
			break;

			case ASTREE_NE: 
				printNodeSource(node->son[0], source_code);
				fprintf(source_code, " != ");
				printNodeSource(node->son[1], source_code);
			break;

			case ASTREE_AND: 
				printNodeSource(node->son[0], source_code);
				fprintf(source_code, " && ");
				printNodeSource(node->son[1], source_code);
			break;

			case ASTREE_OR: 
				printNodeSource(node->son[0], source_code);
				fprintf(source_code, " || ");
				printNodeSource(node->son[1], source_code);
			break;

			case ASTREE_VARINI: 
				fprintf(source_code, "%s=", node->symbol->text);
				printNodeSource(node->son[0], source_code);
			break;

			case ASTREE_IF: 
				fprintf(source_code, "if (");
				printNodeSource(node->son[0], source_code);
				fprintf(source_code, ") then ");
				printNodeSource(node->son[1], source_code);
			break;

			case ASTREE_ELSE: 
				fprintf(source_code, "if (");
				printNodeSource(node->son[0], source_code);
				fprintf(source_code, ") then ");
				printNodeSource(node->son[1], source_code);
				fprintf(source_code, " else ");
				printNodeSource(node->son[2], source_code);
			break;

			case ASTREE_WHILE: 
				fprintf(source_code, "while (");
				printNodeSource(node->son[0], source_code);
				fprintf(source_code, ") ");
				printNodeSource(node->son[1], source_code);
			break;

			case ASTREE_FOR: 
				fprintf(source_code, "for (");
				printNodeSource(node->son[0], source_code);
				fprintf(source_code, " to ");
				printNodeSource(node->son[1], source_code);
				fprintf(source_code, ") \n");
				printNodeSource(node->son[2], source_code);
			break;

			case ASTREE_BRACES: 
				fprintf(source_code, "\n{ \n ");
				printNodeSource(node->son[0], source_code);
				fprintf(source_code, "\n}\n ");
			break;

			case ASTREE_CMDL: 
				printNodeSource(node->son[0], source_code);
				printNodeSource(node->son[1], source_code);
			break;

			case ASTREE_FIMCMDL: 
				fprintf(source_code, ";\n");
				printNodeSource(node->son[0], source_code);
				printNodeSource(node->son[1], source_code);
			break;

			case ASTREE_NOT: 
				fprintf(source_code, " ! ");
				printNodeSource(node->son[0], source_code);
			break;

			case ASTREE_PRINT: 
				fprintf(source_code, "print ");
				printNodeSource(node->son[0], source_code);
			break;

			case ASTREE_READ: 
				fprintf(source_code, "read ");
				printNodeSource(node->son[0], source_code);
			break;

			case ASTREE_RETURN: 
				fprintf(source_code, "return ");
				printNodeSource(node->son[0], source_code);
			break;

			case ASTREE_PT1: 
				fprintf(source_code, "#");
				fprintf(source_code, "%s", node->symbol->text);
			break;

			case ASTREE_PT2: 
				fprintf(source_code, "&");
				fprintf(source_code, "%s", node->symbol->text);
			break;

			case ASTREE_ARRAY_READ: 
				fprintf(source_code, "%s[", node->symbol->text);
				printNodeSource(node->son[0], source_code);
				fprintf(source_code, "]");
			break;

			case ASTREE_FUNCALL: 
				fprintf(source_code, "%s(", node->symbol->text);
				printNodeSource(node->son[0], source_code);
				fprintf(source_code, ")");
			break;

			case ASTREE_ARGFUN: 
				printNodeSource(node->son[0], source_code);
			break;

			case ASTREE_ARGFUNFIM:
				fprintf(source_code, ",");
				printNodeSource(node->son[0], source_code);

				printNodeSource(node->son[1], source_code);
			break;

			case ASTREE_PARENTHESIS: 
				fprintf(source_code, " ( ");
				printNodeSource(node->son[0], source_code);
				fprintf(source_code, " ) ");
			break;

			case ASTREE_ASSPT1: 
				fprintf(source_code, "%s=#", node->symbol->text);
				printNodeSource(node->son[0], source_code);
			break;

			case ASTREE_ASSPT2: 
				fprintf(source_code, "%s=&", node->symbol->text);
				printNodeSource(node->son[0], source_code);
			break;

			case ASTREE_ARRAY_WRITE: 
				fprintf(source_code, "%s [", node->symbol->text);
				printNodeSource(node->son[0], source_code);
				fprintf(source_code, " ] = ");
				printNodeSource(node->son[1], source_code);
			break;

			case ASTREE_CHAR: 
				fprintf(source_code, "char");
			break;

			case ASTREE_INT: 
				fprintf(source_code, "int");
			break;

			case ASTREE_FLOAT: 
				fprintf(source_code, "float");
			break;

			case ASTREE_DFNL: 
				printNodeSource(node->son[0], source_code);
				printNodeSource(node->son[1], source_code);
			break;

			case ASTREE_ATR: 
				printNodeSource(node->son[0], source_code);
				fprintf(source_code, " %s = ", node->symbol->text);
				printNodeSource(node->son[1], source_code);
				fprintf(source_code, ";\n");
			break;

			case ASTREE_VARPT: 
				printNodeSource(node->son[0], source_code);
				fprintf(source_code, " #");
				fprintf(source_code, " %s", node->symbol->text);
				fprintf(source_code, ";\n");
			break;

			case ASTREE_VARPTINI: 
				printNodeSource(node->son[0], source_code);
				fprintf(source_code, " #");
				fprintf(source_code, " %s = ", node->symbol->text);
				printNodeSource(node->son[1], source_code);
				fprintf(source_code, ";\n");
			break;			

			case ASTREE_ARRINI: 
				printNodeSource(node->son[0], source_code);
				fprintf(source_code, " %s [", node->symbol->text);
				printNodeSource(node->son[1], source_code);
				fprintf(source_code, "] ");
				printNodeSource(node->son[2], source_code);
				fprintf(source_code, ";\n");
			break;

			case ASTREE_FUNDEF: 
				printNodeSource(node->son[0], source_code);
				fprintf(source_code, " %s( ", node->symbol->text);
				printNodeSource(node->son[1], source_code);
				fprintf(source_code, " ) ");
				printNodeSource(node->son[2], source_code);
			break;

			case ASTREE_PRINTARG: 
				printNodeSource(node->son[0], source_code);
				fprintf(source_code, " ");
				printNodeSource(node->son[1], source_code);
			break;

			case ASTREE_PARL: 
				printNodeSource(node->son[0], source_code);
				printNodeSource(node->son[1], source_code);
			break;

			case ASTREE_FPARL: 
				fprintf(source_code, ",");
				printNodeSource(node->son[0], source_code);
				printNodeSource(node->son[1], source_code);
			break;

			case ASTREE_PARAM: 
				printNodeSource(node->son[0], source_code);
				fprintf(source_code, " %s", node->symbol->text);
			break;

			case ASTREE_INTL: 
				fprintf(source_code, ": ");
				printNodeSource(node->son[0], source_code);
			break;

			case ASTREE_INTL2: 
				printNodeSource(node->son[0], source_code);
				fprintf(source_code, " ");
				printNodeSource(node->son[1], source_code);
			break;

			default:
				fputs("UNKNOWN", source_code);
			break;

		}
	}
}
