
#include "semantic.h"
#include <stdio.h>

void set_declarations(AST *node){
	if (!node) return;

	if(node->type == AST_VARDEC){

		if(node->symbol->type != SYMBOL_ID){
			fprintf(stderr, "Semantic error: symbol %s already declared. \n", node->symbol->texto);
			//exit(4);
		}else{
			node->symbol->type = SYMBOL_SCALAR;
		}
	}
}

void semanticCheckOperations(AST *node){
	if(node->type == AST_ADD || node->type == AST_SUB || node->type == AST_MUL || node->type == AST_DIV ){
		
	}
}