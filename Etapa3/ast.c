#include "ast.h"
#include <stdio.h>
#include <stdlib.h>

AST* astCreate(int type, hash_Node *symbol, AST *son0, AST *son1, AST *son2, AST *son3){
	
	AST* newnode;
	newnode = (AST*) calloc(1,sizeof(AST));
	newnode->tipo = type;
	newnode->symbol = symbol;
	newnode->son[0] = son0;
	newnode->son[1] = son1;
	newnode->son[2] = son2;
	newnode->son[3] = son3;
	return newnode;
}

void astPrint(AST *node, int level){
	int i;
	if(!node) return;

	for(i = 0; i < level; i++)
		fprintf(stderr,"  ");
	fprintf(stderr,"AST(");
	switch(node->tipo){
		case AST_SYMBOL: fprintf(stderr, "AST_SYMBOL, \n");break;
		case AST_ADD: fprintf(stderr, "AST_ADD, \n");break;
		case AST_SUB: fprintf(stderr, "AST_SUB, \n");break;
		case AST_MUL: fprintf(stderr, "AST_MUL, \n");break;
		case AST_DIV: fprintf(stderr, "AST_DIV, \n");break;
		case AST_MOD: fprintf(stderr, "AST_MOD, \n");break;
		case AST_LESS: fprintf(stderr, "AST_LESS, \n");break;
		case AST_BIGGER: fprintf(stderr, "AST_BIGGER, \n");break;
		case AST_ASS: fprintf(stderr, "AST_ASS, \n");break;
		case AST_IFT: fprintf(stderr, "AST_IFT, \n");break;
		case AST_IFTE: fprintf(stderr, "AST_IFTE, \n");break;
		case AST_WHILE: fprintf(stderr, "AST_WHILE, \n");break;
		case AST_FOR: fprintf(stderr, "AST_FOR, \n");break;
		case AST_BLOCO: fprintf(stderr, "AST_BLOCO, \n");break;
		case AST_BLOCOCMD: fprintf(stderr, "AST_BLOCOCMD, \n");break;
		case AST_FIMCMD: fprintf(stderr, "AST_FIMCMD, \n");break;
		case AST_NOT: fprintf(stderr, "AST_NOT, \n");break;
		case AST_KWPRINT: fprintf(stderr, "AST_KWPRINT, \n");break;
		case AST_KWREAD: fprintf(stderr, "AST_KWREAD, \n");break;
		case AST_KWRETURN: fprintf(stderr, "AST_KWRETURN, \n");break;
		case AST_PT1: fprintf(stderr, "AST_PT1, \n");break;
		case AST_PT2: fprintf(stderr, "AST_PT2, \n");break;
		case AST_ARR: fprintf(stderr, "AST_ARR, \n");break;
		case AST_FUNCALL: fprintf(stderr, "AST_FUNCALL, \n");break;
		case AST_ARGFUN: fprintf(stderr, "AST_ARGFUN, \n");break;
		case AST_ARGFUNFIM: fprintf(stderr, "AST_ARGFUNFIM, \n");break;
		case AST_EXP: fprintf(stderr, "AST_EXP, \n");break;
		case AST_ASSPT1: fprintf(stderr, "AST_ASSPT1, \n");break;
		case AST_ASSPT2: fprintf(stderr, "AST_ASSPT2, \n");break;
		case AST_ASSARR: fprintf(stderr, "AST_ASSARR, \n");break;
		case AST_KWCHAR: fprintf(stderr, "AST_KWCHAR, \n");break;
		case AST_KWINT: fprintf(stderr, "AST_KWINT, \n");break;
		case AST_KWFLOAT: fprintf(stderr, "AST_KWFLOAT, \n");break;
		case AST_LDEC: fprintf(stderr, "AST_LDEC, \n");break;
		case AST_DEC: fprintf(stderr, "AST_DEC, \n");break;
		case AST_DECPT: fprintf(stderr, "AST_DECPT, \n");break;
		case AST_DECPTASS: fprintf(stderr, "AST_DECPTASS, \n");break;
		case AST_DECARR: fprintf(stderr, "AST_DECARR, \n");break;
		case AST_DECFUN: fprintf(stderr, "AST_DECFUN, \n");break;
		case AST_PRINTARG: fprintf(stderr, "AST_PRINTARG, \n");break;
		case AST_LPARAM: fprintf(stderr, "AST_LPARAM, \n");break;
		case AST_FPARAM: fprintf(stderr, "AST_FPARAM, \n");break;
		case AST_PARAM: fprintf(stderr, "AST_PARAM, \n");break;
		case AST_INI: fprintf(stderr, "AST_INI, \n");break;
		case AST_INI2: fprintf(stderr, "AST_INI2, \n");break;
		case AST_LE: fprintf(stderr, "AST_LE, \n" );break;
		case AST_GE: fprintf(stderr, "AST_GE, \n" );break;
		case AST_EQ: fprintf(stderr, "AST_EQ, \n" );break;
		case AST_NE: fprintf(stderr, "AST_NE, \n" );break;
		case AST_AND: fprintf(stderr, "AST_AND, \n" );break;
		case AST_OR: fprintf(stderr, "AST_OR, \n" );break;
		default: fprintf(stderr, "UNKNOWN, \n");break;
	}
	for (i=0; i<MAX_SONS; i++)
		astPrint(node->son[i],level+1);
}

void printSource(AST *raiz){

   //printNodeSource(AST *node, FILE *source_code);

	
}

void printNodeSource(AST *node, FILE *source_code){
	if (node){
		switch(node->tipo){
			case AST_SYMBOL: 
				fprintf(source_code, "%s\n", node->symbol->texto);
				if(node->son[0] != 0 ){
					fprintf(source_code, " ");
					printNodeSource(node->son[0], source_code);
				}
			break;

			case AST_ADD: 
				printNodeSource(node->son[0], source_code);
				fprintf(source_code, " + ");
				printNodeSource(node->son[1], source_code);
			break;

			case AST_SUB: 
				printNodeSource(node->son[0], source_code);
				fprintf(source_code, " - ");
				printNodeSource(node->son[1], source_code);
			break;

			case AST_MUL: 
				printNodeSource(node->son[0], source_code);
				fprintf(source_code, " * ");
				printNodeSource(node->son[1], source_code);
			break;

			case AST_DIV: 
				printNodeSource(node->son[0], source_code);
				fprintf(source_code, " / ");
				printNodeSource(node->son[1], source_code);
			break;

			case AST_MOD: 
				printNodeSource(node->son[0], source_code);
				fprintf(source_code, " %% ");
				printNodeSource(node->son[1], source_code);
			break;

			case AST_LESS: 
				printNodeSource(node->son[0], source_code);
				fprintf(source_code, " < ");
				printNodeSource(node->son[1], source_code);
			break;

			case AST_BIGGER: 
				printNodeSource(node->son[0], source_code);
				fprintf(source_code, " > ");
				printNodeSource(node->son[1], source_code);
			break;

			case AST_LE: 
				printNodeSource(node->son[0], source_code);
				fprintf(source_code, " <= ");
				printNodeSource(node->son[1], source_code);
			break;

			case AST_GE: 
				printNodeSource(node->son[0], source_code);
				fprintf(source_code, " >= ");
				printNodeSource(node->son[1], source_code);
			break;

			case AST_EQ: 
				printNodeSource(node->son[0], source_code);
				fprintf(source_code, " == ");
				printNodeSource(node->son[1], source_code);
			break;

			case AST_NE: 
				printNodeSource(node->son[0], source_code);
				fprintf(source_code, " != ");
				printNodeSource(node->son[1], source_code);
			break;

			case AST_AND: 
				printNodeSource(node->son[0], source_code);
				fprintf(source_code, " && ");
				printNodeSource(node->son[1], source_code);
			break;

			case AST_OR: 
				printNodeSource(node->son[0], source_code);
				fprintf(source_code, " || ");
				printNodeSource(node->son[1], source_code);
			break;

			case AST_ASS: 
				fprintf(source_code, "%s=", node->symbol->texto);
				printNodeSource(node->son[0], source_code);
			break;

			case AST_IFT: 
				fprintf(source_code, "if (");
				printNodeSource(node->son[0], source_code);
				fprintf(source_code, ") then ");
				printNodeSource(node->son[1], source_code);
			break;

			case AST_IFTE: 
				fprintf(source_code, "if (");
				printNodeSource(node->son[0], source_code);
				fprintf(source_code, ") then ");
				printNodeSource(node->son[1], source_code);
				fprintf(source_code, " else ");
				printNodeSource(node->son[2], source_code);
			break;

			case AST_WHILE: 
				fprintf(source_code, "while (");
				printNodeSource(node->son[0], source_code);
				fprintf(source_code, ") ");
				printNodeSource(node->son[1], source_code);
			break;

			case AST_FOR: 
				fprintf(source_code, "for (");
				printNodeSource(node->son[0], source_code);
				fprintf(source_code, " to ");
				printNodeSource(node->son[1], source_code);
				fprintf(source_code, ")");
				printNodeSource(node->son[2], source_code);
			break;

			case AST_BLOCO: 
				fprintf(source_code, "{");
				printNodeSource(node->son[0], source_code);
				fprintf(source_code, "}");
			break;

			case AST_BLOCOCMD: 
				printNodeSource(node->son[0], source_code);
				printNodeSource(node->son[1], source_code);
			break;

			case AST_FIMCMD: 
				fprintf(source_code, "; ");
				printNodeSource(node->son[0], source_code);
				printNodeSource(node->son[1], source_code);
			break;

			case AST_NOT: 
				fprintf(source_code, " ! ");
				printNodeSource(node->son[0], source_code);
			break;

			case AST_KWPRINT: 
				fprintf(source_code, "print ");
				printNodeSource(node->son[0], source_code);
			break;

			case AST_KWREAD: 
				fprintf(source_code, "read ");
				printNodeSource(node->son[0], source_code);
			break;

			case AST_KWRETURN: 
				fprintf(source_code, "return ");
				printNodeSource(node->son[0], source_code);
			break;

			case AST_PT1: 
				fprintf(source_code, "#");
				fprintf(source_code, "%s", node->symbol->texto);
			break;

			case AST_PT2: 
				fprintf(source_code, "&");
				fprintf(source_code, "%s", node->symbol->texto);
			break;

			case AST_ARR: 
				fprintf(source_code, "%s[", node->symbol->texto);
				printNodeSource(node->son[0], source_code);
				fprintf(source_code, "]");
			break;

			case AST_FUNCALL: 
				fprintf(source_code, "%s(", node->symbol->texto);
				printNodeSource(node->son[0], source_code);
				fprintf(source_code, ")");
			break;

			case AST_ARGFUN: 
				printNodeSource(node->son[0], source_code);
			break;

			case AST_ARGFUNFIM:
				fprintf(source_code, ",");
				printNodeSource(node->son[0], source_code);

				printNodeSource(node->son[1], source_code);
			break;

			case AST_EXP: 
				fprintf(source_code, " ( ");
				printNodeSource(node->son[0], source_code);
				fprintf(source_code, " ) ");
			break;

			case AST_ASSPT1: 
				fprintf(source_code, "%s=#", node->symbol->texto);
				printNodeSource(node->son[0], source_code);
			break;

			case AST_ASSPT2: 
				fprintf(source_code, "%s=&", node->symbol->texto);
				printNodeSource(node->son[0], source_code);
			break;

			case AST_ASSARR: 
				fprintf(source_code, "%s [", node->symbol->texto);
				printNodeSource(node->son[0], source_code);
				fprintf(source_code, " ] = ");
				printNodeSource(node->son[1], source_code);
			break;

			case AST_KWCHAR: 
				fprintf(source_code, "char");
			break;

			case AST_KWINT: 
				fprintf(source_code, "int");
			break;

			case AST_KWFLOAT: 
				fprintf(source_code, "float");
			break;

			case AST_LDEC: ;

			case AST_DEC: 
				printNodeSource(node->son[0], source_code);
				fprintf(source_code, " %s = ", node->symbol->texto);
				printNodeSource(node->son[1], source_code);
				fprintf(source_code, ";");
			break;

			case AST_DECPT: 
				printNodeSource(node->son[0], source_code);
				fprintf(source_code, " #");
				fprintf(source_code, " %s", node->symbol->texto);
				fprintf(source_code, ";");
			break;

			case AST_DECPTASS: 
				printNodeSource(node->son[0], source_code);
				fprintf(source_code, " #");
				fprintf(source_code, " %s = ", node->symbol->texto);
				printNodeSource(node->son[1], source_code);
				fprintf(source_code, ";");
			break;			

			case AST_DECARR: 
				printNodeSource(node->son[0], source_code);
				fprintf(source_code, " %s [", node->symbol->texto);
				printNodeSource(node->son[1], source_code);
				fprintf(source_code, "] ");
				printNodeSource(node->son[2], source_code);
				fprintf(source_code, ";");
			break;

			case AST_DECFUN: 
				printNodeSource(node->son[0], source_code);
				fprintf(source_code, " %s (", node->symbol->texto);
				printNodeSource(node->son[1], source_code);
				fprintf(source_code, ") ");
				printNodeSource(node->son[2], source_code);
			break;

			case AST_PRINTARG: 
				printNodeSource(node->son[0], source_code);
				fprintf(source_code, " ");
				printNodeSource(node->son[1], source_code);
			break;

			case AST_LPARAM: 
				printNodeSource(node->son[0], source_code);
				printNodeSource(node->son[1], source_code);
			break;

			case AST_FPARAM: 
				fprintf(source_code, ",");
				printNodeSource(node->son[0], source_code);
				printNodeSource(node->son[1], source_code);
			break;

			case AST_PARAM: 
				printNodeSource(node->son[0], source_code);
				fprintf(source_code, " %s", node->symbol->texto);
			break;

			case AST_INI: 
				fprintf(source_code, ": ");
				printNodeSource(node->son[0], source_code);
			break;

			case AST_INI2: 
				printNodeSource(node->son[0], source_code);
				fprintf(source_code, " ");
				printNodeSource(node->son[1], source_code);
			break;

		}
	}
}
