#ifndef AST_HEADER
#define AST_HEADER

#include "tabelaHash.h"

#define MAX_SONS 4

#define AST_SYMBOL 1
#define AST_ADD 2
#define AST_SUB 3
#define AST_MUL 4
#define AST_DIV 5
#define AST_MOD 6
#define AST_LESS 7
#define AST_BIGGER 8
#define AST_ASS 9
#define AST_IFTE 10
#define AST_WHILE 11
#define AST_FOR 12

typedef struct ast_node
{
	int tipo;
	hash_Node * symbol;
	struct as_node * son[MAX_SONS];
} AST;

AST* astCreate(int type, hash_Node *symbol, AST *son0, AST *son1, AST *son2, AST *son3);
void astPrint(AST *node, int level);

#endif