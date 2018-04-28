#include "ast.h"

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
		case AST_SYMBOL: fprintf(stderr, "AST_SYMBOL, \n");
		case AST_ADD: fprintf(stderr, "AST_ADD, \n");
		case AST_SUB: fprintf(stderr, "AST_SUB, \n");
		case AST_MUL: fprintf(stderr, "AST_MUL, \n");
		case AST_DIV: fprintf(stderr, "AST_DIV, \n");
		case AST_MOD: fprintf(stderr, "AST_MOD, \n");
		case AST_LESS: fprintf(stderr, "AST_LESS, \n");
		case AST_BIGGER: fprintf(stderr, "AST_BIGGER, \n");
		case AST_ASS: fprintf(stderr, "AST_ASS, \n");
		case AST_IFTE: fprintf(stderr, "AST_IFTE, \n");
		case AST_WHILE: fprintf(stderr, "AST_WHILE, \n");
		case AST_FOR: fprintf(stderr, "AST_FOR, \n");
		case AST_BLOCO: fprintf(stderr, "AST_BLOCO, \n");
		case AST_NOT: fprintf(stderr, "AST_NOT, \n");
		case AST_KWPRINT: fprintf(stderr, "AST_KWPRINT, \n");
		case AST_KWREAD: fprintf(stderr, "AST_KWREAD, \n");
		case AST_KWRETURN: fprintf(stderr, "AST_KWRETURN, \n");
		case AST_PT1: fprintf(stderr, "AST_PT1, \n");
		case AST_PT2: fprintf(stderr, "AST_PT2, \n");
		case AST_ARR: fprintf(stderr, "AST_ARR, \n");
		case AST_FUNCALL: fprintf(stderr, "AST_FUNCALL, \n");
		case AST_ARGFUN: fprintf(stderr, "AST_ARGFUN, \n");
		case AST_EXP: fprintf(stderr, "AST_EXP, \n");
		case AST_ASSPT1: fprintf(stderr, "AST_ASSPT1, \n");
		case AST_ASSPT2: fprintf(stderr, "AST_ASSPT2, \n");
		case AST_ASSARR: fprintf(stderr, "AST_ASSARR, \n");
		case AST_KWCHAR: fprintf(stderr, "AST_KWCHAR, \n");
		case AST_KWINT: fprintf(stderr, "AST_KWINT, \n");
		case AST_KWFLOAT: fprintf(stderr, "AST_KWFLOAT, \n");
		case AST_LDEC: fprintf(stderr, "AST_LDEC, \n");
		case AST_DEC: fprintf(stderr, "AST_DEC, \n");
		case AST_DECPT: fprintf(stderr, "AST_DECPT, \n");
		case AST_DECARR: fprintf(stderr, "AST_DECARR, \n");
		case AST_DECFUN: fprintf(stderr, "AST_DECFUN, \n");
		case AST_PRINTARG: fprintf(stderr, "AST_PRINTARG, \n");
		case AST_PARAM: fprintf(stderr, "AST_PARAM, \n");
		case AST_INI: fprintf(stderr, "AST_INI, \n");
		case AST_INI2: fprintf(stderr, "AST_INI2, \n");
		default: fprintf(stderr, "UNKNOWN, \n");
	}
	for (i=0; i<MAX_SONS; i++)
		astPrint(node->son[i],level+1);
}

void printSource(AST *raiz){

	printNodeSource(AST *node, FILE *source_code){
		
	}
}