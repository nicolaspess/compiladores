#include "ast.h"

ASTREE* astSetRoot(ASTREE *newRoot) {
	root = newRoot;
	return root;
}

ASTREE* astCreate(int type, symbol_t* symbol, struct ASTREE_s *firstChild, struct ASTREE_s *secondChild, struct ASTREE_s *thirdChild, struct ASTREE_s *fourthChild) {
	ASTREE *node;
	node = (ASTREE*)calloc(1, sizeof(ASTREE));
	node->type = type;
	node->symbol = symbol;
	node->children[0] = firstChild;
	node->children[1] = secondChild;
	node->children[2] = thirdChild;
	node->children[3] = fourthChild;
	return node;
}

void astPrint(ASTREE *node, int level) {
	int i;
	if (!node){ 
		return;
	}
	for(i = 0; i < level; ++i) {
		printf("   ");
	}
	printf("ASTREE(");
	switch(node->type) {
		
		case ASTREE_PROGRAM:
			printf("ASTREE_PROGRAM)\n");
			astPrint(node->children[0],level++);
			break;

		case ASTREE_DEC_LIST:
			printf("ASTREE_DEC_LIST)\n");
			astPrint(node->children[0],level++);
			astPrint(node->children[1],level++);
			break;

		case ASTREE_DEC_VALUE:
			printf("ASTREE_DEC_VALUE)\n");
			astPrint(node->children[0], level++);
			break;

		case ASTREE_DEC_VECTOR:
			printf("ASTREE_DEC_VECTOR)\n");
			astPrint(node->children[0], level++);
			break;

		case ASTREE_DEC_VECTOR_INIT:
			printf("ASTREE_DEC_VECTOR_INIT)\n");
			astPrint(node->children[0], level++);
			astPrint(node->children[1], level++);
			break;

		case ASTREE_DEC_POINTER:
			printf("ASTREE_DEC_POINTER)\n");
			astPrint(node->children[0], level++);
			break;

		case ASTREE_DEC_FUNC:
			printf("ASTREE_DEC_FUNC, %s)\n", node->symbol->key);
			astPrint(node->children[0], level++);
			astPrint(node->children[1], level++);
			break;

		case ASTREE_PARAM_LIST:
			printf("ASTREE_PARAM_LIST)\n");
			astPrint(node->children[0], level++);
			if(node->children[1]) {
				astPrint(node->children[1], level++);
			}
			break;

		case ASTREE_PARAM:
			printf("ASTREE_PARAM, %s)\n", node->symbol->key);
			break;

		case ASTREE_VALUE_LIST:
			printf("ASTREE_VALUE_LIST)\n");
			astPrint(node->children[0], level++);
			astPrint(node->children[1], level++);
			break;

		case ASTREE_SYMBOL:
			printf("ASTREE_SYMBOL, %s)\n", node->symbol->key);
			break;

		case ASTREE_TYPECHAR:
			printf("ASTREE_TYPECHAR, %s)\n", node->symbol->key);
			break;

		case ASTREE_TYPEINT:
			printf("ASTREE_TYPEINT, %s)\n", node->symbol->key);
			break;

		case ASTREE_TYPEFLOAT:
			printf("ASTREE_TYPEFLOAT, %s)\n", node->symbol->key);
			break;

		case ASTREE_SYMBOL_ADDRESS:
			printf("ASTREE_SYMBOL_ADDRESS, %s)\n", node->symbol->key);
			break;

		case ASTREE_SYMBOL_POINTER:
			printf("ASTREE_SYMBOL_POINTER, %s)\n", node->symbol->key);
			break;

		case ASTREE_BLOCK:
			printf("ASTREE_BLOCK)\n");
			astPrint(node->children[0], level++);
			break;

		case ASTREE_CMD_LIST:
			printf("ASTREE_CMD_LIST)\n");
			astPrint(node->children[0], level++);
			astPrint(node->children[1], level++);
			break;

		case ASTREE_VALUE_ASSIGNMENT:
			printf("ASTREE_VALUE_ASSIGNMENT, %s)\n", node->symbol->key);
			astPrint(node->children[0], level++);
			break;

		case ASTREE_VECTOR_ASSIGNMENT:
			printf("ASTREE_VECTOR_ASSIGNMENT, %s)\n", node->symbol->key);
			astPrint(node->children[0], level++);
			astPrint(node->children[1], level++);
			break;

		case ASTREE_VECTOR_ACCESS:
			printf("ASTREE_VECTOR_ACCESS, %s)\n", node->symbol->key);
			astPrint(node->children[0], level++);
			break;

		case ASTREE_READ:
			printf("ASTREE_READ, %s)\n", node->symbol->key);
			astPrint(node->children[0], level++);
			break;

		case ASTREE_PRINT:
			printf("ASTREE_PRINT)\n");
			astPrint(node->children[0], level++);
			break;

		case ASTREE_ELEM_LIST:
			printf("ASTREE_ELEM_LIST)\n");
			astPrint(node->children[0], level++);
			astPrint(node->children[1], level++);
			break;

		case ASTREE_RETURN:
			printf("ASTREE_RETURN)\n");
			astPrint(node->children[0], level++);
			break;

		case ASTREE_IF_THEN:
			printf("ASTREE_IF_THEN)\n");
			astPrint(node->children[0], level++);
			astPrint(node->children[1], level++);
			break;

		case ASTREE_IF_THEN_ELSE:
			printf("ASTREE_IF_THEN_ELSE)\n");
			astPrint(node->children[0], level++);
			astPrint(node->children[1], level++);
			astPrint(node->children[2], level++);
			break;

		case ASTREE_WHILE:
			printf("ASTREE_WHILE)\n");
			astPrint(node->children[0], level++);
			astPrint(node->children[1], level++);
			break;

		case ASTREE_FOR:
			printf("ASTREE_FOR)\n");
			astPrint(node->children[0], level++);
			astPrint(node->children[1], level++);
			astPrint(node->children[2], level++);
			break;

		case ASTREE_INVOKE_FUNC:
			printf("ASTREE_INVOKE_FUNC, %s)\n", node->symbol->key);
			astPrint(node->children[0], level++);
			break;
			
		case ASTREE_ARG_LIST:
			printf("ASTREE_ARG_LIST)\n");
			astPrint(node->children[0], level++);
			if(node->children[1]) {
				astPrint(node->children[1], level++);
			}
			break;

		case ASTREE_NOT:
			printf("ASTREE_NOT)\n");
			astPrint(node->children[0], level++);
			break;

		case ASTREE_ADD:
			printf("ASTREE_ADD)\n");
			astPrint(node->children[0], level++);
			astPrint(node->children[1], level++);
			break;
		case ASTREE_SUB:
			printf("ASTREE_SUB)\n");
			astPrint(node->children[0], level++);
			astPrint(node->children[1], level++);
			break;
		case ASTREE_MULT:
			printf("ASTREE_MULT)\n");
			astPrint(node->children[0], level++);
			astPrint(node->children[1], level++);
			break;
		case ASTREE_DIV:
			printf("ASTREE_DIV)\n");
			astPrint(node->children[0], level++);
			astPrint(node->children[1], level++);
			break;
		case ASTREE_LESS:
			printf("ASTREE_LESS)\n");
			astPrint(node->children[0], level++);
			astPrint(node->children[1], level++);
			break;
		case ASTREE_GREATER:
			printf("ASTREE_GREATER)\n");
			astPrint(node->children[0], level++);
			astPrint(node->children[1], level++);
			break;
		case ASTREE_LESS_EQ:
			printf("ASTREE_LESS_EQ)\n");
			astPrint(node->children[0], level++);
			astPrint(node->children[1], level++);
			break;
		case ASTREE_GREATER_EQ:
			printf("ASTREE_GREATER_EQ)\n");
			astPrint(node->children[0], level++);
			astPrint(node->children[1], level++);
			break;
		case ASTREE_EQ:
			printf("ASTREE_EQ)\n");
			astPrint(node->children[0], level++);
			astPrint(node->children[1], level++);
			break;
		case ASTREE_NEQ:
			printf("ASTREE_NEQ)\n");
			astPrint(node->children[0], level++);
			astPrint(node->children[1], level++);
			break;
		case ASTREE_AND:
			printf("ASTREE_AND)\n");
			astPrint(node->children[0], level++);
			astPrint(node->children[1], level++);
			break;
		case ASTREE_OR:
			printf("ASTREE_OR)\n");
			astPrint(node->children[0], level++);
			astPrint(node->children[1], level++);
			break;

		default:
			printf("UNKNOWN ast-> %d\n",node->type);
			break;
	}
	return;
}