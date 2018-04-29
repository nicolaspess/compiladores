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
#define AST_BLOCO 13
#define AST_NOT 14
#define AST_KWPRINT 15
#define AST_KWREAD 16
#define AST_KWRETURN 17
#define AST_PT1 18
#define AST_ARR 19
#define AST_FUNCALL 20
#define AST_ARGFUN 21
#define AST_EXP 22
#define AST_ASSPT1 23
#define AST_ASSPT2 24
#define AST_ASSARR 25
#define AST_KWCHAR 26
#define AST_KWINT 27
#define AST_KWFLOAT 28
#define AST_LDEC 29
#define AST_DEC 30
#define AST_DECPT 31
#define AST_DECARR 32
#define AST_DECFUN 33
#define AST_PRINTARG 34
#define AST_PARAM 35
#define AST_INI 36
#define AST_INI2 37
#define AST_LE 38
#define AST_GE 39
#define AST_EQ 40
#define AST_NE 41
#define AST_AND 42
#define AST_OR 43
#define AST_ARGFUNFIM 44
#define AST_IFT 45
#define AST_BLOCOCMD 46
#define AST_FIMCMD 47
#define AST_DECPTASS 48
#define AST_LPARAM 49
#define AST_FPARAM 50

FILE * source_code;

typedef struct ast_node
{
	int tipo;
	hash_Node * symbol;
	struct as_node * son[MAX_SONS];
} AST;

AST* astCreate(int type, hash_Node *symbol, AST *son0, AST *son1, AST *son2, AST *son3);
void astPrint(AST *node, int level);

void printSource(AST *raiz);
void printNodeSource(AST *node, FILE *source_code);


#endif