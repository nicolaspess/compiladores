#ifndef AST_HEADER
#define AST_HEADER

#include "tabelaHash.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX_SONS 4

#define ASTREE_ADD 1
#define ASTREE_SUB 2
#define ASTREE_MUL 3
#define ASTREE_DIV 4

#define ASTREE_L 5
#define ASTREE_G 6
#define ASTREE_LE 7
#define ASTREE_GE 8
#define ASTREE_EQ 9 
#define ASTREE_NE 10
#define ASTREE_AND 11
#define ASTREE_OR 12

#define ASTREE_PARAM 13
#define ASTREE_FUNDEF 14
#define ASTREE_FUNCALL 15

#define ASTREE_INT 16
#define ASTREE_CHAR 18
#define ASTREE_FLOAT 19

#define ASTREE_PARENTHESIS 21
#define ASTREE_BRACES 22

#define ASTREE_ATR 23
#define ASTREE_ARRAY_WRITE 24
#define ASTREE_ARRAY_READ 25

#define ASTREE_VARDECL 26
#define ASTREE_ARRDECL 27
#define ASTREE_VARINI 28
#define ASTREE_ARRINI 29

#define ASTREE_PRINT 30
#define ASTREE_PRINTL 31
#define ASTREE_READ 32
#define ASTREE_RETURN 33
#define ASTREE_WHILE 34
#define ASTREE_IF 35
#define ASTREE_ELSE 36
#define ASTREE_NOT 37

#define ASTREE_VARPT 38
#define ASTREE_VARPTINI 39
#define ASTREE_SYMBOL 40

#define ASTREE_CMDL 100
#define ASTREE_DFNL 101
#define ASTREE_PARL 102
#define ASTREE_PARCALLL 103
#define ASTREE_INTL 104
#define ASTREE_INTL2 106
#define ASTREE_FIMCMDL 107
#define ASTREE_FPARL 108
#define ASTREE_ASSPT1 109
#define ASTREE_ASSPT2 110
#define ASTREE_FOR 111
#define ASTREE_PRINTARG 112
#define ASTREE_PT1 113
#define ASTREE_PT2 114
#define ASTREE_MOD 115
#define ASTREE_ARGFUN 116
#define ASTREE_ARGFUNFIM 117
#define ASTREE_EXP 118

#define ASTREE_QUOTES 105

FILE * source_code;

typedef struct ast_node
{
	int type;
	hash_Node * symbol;
	struct ast_node * son[MAX_SONS];
}ASTREE;

ASTREE* astCreate(int type, hash_Node *symbol, ASTREE *son0, ASTREE *son1, ASTREE *son2, ASTREE *son3);
void astPrint(ASTREE *node, int level);

void printSource(ASTREE *raiz);
void printNodeSource(ASTREE *node, FILE *source_code);


#endif
