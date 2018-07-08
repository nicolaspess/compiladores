#ifndef ASTREE_H_
#define ASTREE_H_
#include <stdlib.h>
#include <stdio.h>
#include "symbols.h"

#define MAX_CHILDREN 4

#define ASTREE_SYMBOL 0
#define ASTREE_DEC_VALUE 4
#define ASTREE_PROGRAM 5
#define ASTREE_VALUE_LIST 6
#define ASTREE_VALUE_ASSIGNMENT 42
#define ASTREE_POINTER_ASSIGNMENT 50
#define ASTREE_DEC_LIST 39
#define ASTREE_DEC_VECTOR 38
#define ASTREE_DEC_VECTOR_INIT 40
#define ASTREE_DEC_POINTER 41
#define ASTREE_PARAM_LIST 8

#define ASTREE_ADD 1
#define ASTREE_SUB 2
#define ASTREE_CMD_LIST 3

#define ASTREE_DEC_FUNC 7

#define ASTREE_PARAM 9
#define ASTREE_BLOCK 10
#define ASTREE_VECTOR_ASSIGNMENT 11
#define ASTREE_READ 12
#define ASTREE_PRINT 13
#define ASTREE_RETURN 14
#define ASTREE_IF_THEN 15
#define ASTREE_IF_THEN_ELSE 16
#define ASTREE_WHILE 17
#define ASTREE_FOR 18
#define ASTREE_ELEM_LIST 19
// #define ASTREE_DEC_INIT 20
#define ASTREE_ARG_LIST 21
#define ASTREE_INVOKE_FUNC 22
#define ASTREE_VECTOR_ACCESS 23
#define ASTREE_NOT 24
#define ASTREE_OR 25
#define ASTREE_AND 26
#define ASTREE_NEQ 27
#define ASTREE_EQ 28
#define ASTREE_GREATER_EQ 29
#define ASTREE_LESS_EQ 30
#define ASTREE_LESS 31
#define ASTREE_GREATER 32
#define ASTREE_DIV 33
#define ASTREE_MULT 34
#define ASTREE_SYMBOL_ADDRESS 35
#define ASTREE_SYMBOL_POINTER 36
#define ASTREE_DEC 37
#define ASTREE_TYPECHAR 43
#define ASTREE_TYPEINT 44
#define ASTREE_TYPEFLOAT 45

typedef struct ASTREE_s
{
    int type;
    int dataType;
    int arraySize;
	symbol_t *symbol;
	struct ASTREE_s *children[MAX_CHILDREN];
} ASTREE;


ASTREE *root;

extern ASTREE* astCreate(int type, symbol_t* symbol, ASTREE *firstChild, ASTREE *secondChild, ASTREE *thirdChild, ASTREE *fourthChild);
extern void astPrint(ASTREE *node, int level);
extern ASTREE* astSetRoot(ASTREE *newRoot);

#endif