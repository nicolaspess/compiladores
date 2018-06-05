#ifndef TAC_HEADER
#define TAC_HEADER

#include <stdio.h>
#include "tabelaHash.h"
#include "ast.h"

#define TAC_SYMBOL 1
#define TAC_ADD 2
#define TAC_SUB 3
#define TAC_MUL 4
#define TAC_DIV 5
#define TAC_ASSIGN 6

#define TAC_L 7
#define TAC_G 8
#define TAC_LE 9 
#define TAC_GE 10 
#define TAC_EQ 11
#define TAC_NE 12
#define TAC_AND 13
#define TAC_OR 14

#define TAC_PRINT 15
#define TAC_PRINTARG 16
#define TAC_READ 17

#define TAC_RETURN 19
#define TAC_FUNCALL 20
#define TAC_ARG 21

#define TAC_JZ 30
#define TAC_LABEL 31
#define TAC_JMP 32
#define TAC_BEGINFUN 33
#define TAC_ENDFUN 35



typedef struct tac{
	int type;
	hash_Node* res;
	hash_Node* op1;
	hash_Node* op2;
	struct tac *prev;
	struct tav *next;
} TAC;

TAC* tacCreate(int type, hash_Node *res, hash_Node *op1, hash_Node *op2);
TAC* tacPrintSingle(TAC *tac);
TAC* tacPrintForward(TAC *first);
TAC* tacReverse(TAC *last);
TAC* tacPrintBack(TAC *tac);
TAC* tacJoin(TAC* l1, TAC* l2);
TAC* codeGenerator(ASTREE *node);
TAC* makeBinOp(int type, TAC* code0, TAC* code1);
TAC* makeWhile(TAC* code0, TAC* code1);
TAC* makeIfThen(TAC* code0, TAC* code1);
TAC* makeFun(hash_Node* func, TAC* c);
#endif