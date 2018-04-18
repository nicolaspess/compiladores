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
		case AST_ASS: fprintf(stderr, "AST_ASS, \n");
		case AST_IFTE: fprintf(stderr, "AST_IFTE, \n");
		case AST_WHILE: fprintf(stderr, "AST_WHILE, \n");
		case AST_FOR: fprintf(stderr, "AST_FOR, \n");
		default: fprintf(stderr, "UNKNOWN, \n");
	}
	for (i=0; i<MAX_SONS; i++)
		astPrint(node->son[i],level+1);
}