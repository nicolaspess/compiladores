#include <stdio.h>
#include "tac.h"


TAC* tacCreate(int type, hash_Node *res, hash_Node *op1, hash_Node *op2)
{
	TAC *newtac = 0;
	newtac = (TAC*) calloc(1, sizeof(TAC));
	newtac->type = type;
	newtac->res = res;
	newtac->op1 = op1;
	newtac->op2 = op2;
	newtac->prev = 0;
	newtac->next = 0;
	return newtac;
}


TAC* tacPrintSingle(TAC *tac)
{
	if(!tac) return;
	fprintf(stderr, "TAC(");
	switch (tac->type)
	{
		case TAC_SYMBOL: fprintf(stderr, "TAC_SYMBOL"); break;
		case TAC_ADD: fprintf(stderr, "TAC_ADD"); break;
		case TAC_SUB: fprintf(stderr, "TAC_SUB"); break;
		case TAC_MUL: fprintf(stderr, "TAC_MUL"); break;
		case TAC_DIV: fprintf(stderr, "TAC_DIV"); break;

		case TAC_ASSIGN: fprintf(stderr, "TAC_ASSIGN"); break;

		case TAC_L: fprintf(stderr, "TAC_L"); break;
		case TAC_G: fprintf(stderr, "TAC_G"); break;
		case TAC_LE : fprintf(stderr, "TAC_LE"); break;
		case TAC_GE : fprintf(stderr, "TAC_GE"); break;
		case TAC_EQ : fprintf(stderr, "TAC_EQ"); break;
		case TAC_NE : fprintf(stderr, "TAC_NE"); break;
		case TAC_AND : fprintf(stderr, "TAC_AND"); break;
		case TAC_OR : fprintf(stderr, "TAC_OR"); break;

		case TAC_PRINT : fprintf(stderr, "TAC_PRINT"); break;
		case TAC_PRINTARG : fprintf(stderr, "TAC_PRINTARG"); break;
		case TAC_READ : fprintf(stderr, "TAC_READ"); break;

		case TAC_RETURN : fprintf(stderr, "TAC_RETURN"); break;
		case TAC_FUNCALL : fprintf(stderr, "TAC_FUNCALL"); break;

		case TAC_JZ : fprintf(stderr, "TAC_JZ"); break;
		case TAC_LABEL : fprintf(stderr, "TAC_LABEL"); break;
		case TAC_JMP : fprintf(stderr, "TAC_JMP"); break;
		case TAC_BEGINFUN : fprintf(stderr, "TAC_BEGINFUN"); break;
		case TAC_ENDFUN : fprintf(stderr, "TAC_ENDFUN"); break;
		default: fprintf(stderr, "TAC_UNKNOWN"); break;
	}

	if(tac->res) fprintf(stderr, " %s", tac->res->text);
	else fprintf(stderr, ",0");

	if(tac->op1) fprintf(stderr, " %s", tac->op1->text);
	else fprintf(stderr, ",0");

	if(tac->op2) fprintf(stderr, " %s", tac->op2->text);
	else fprintf(stderr, ",0");
	fprintf(stderr, ")\n");
}

TAC* tacPrintBack(TAC *tac)
{	
	printf("tacPrintBack__-> OIII TO AQUI\n");
	if (!tac) return;
	printf("tacPrintBack__-> PASSOUUU\n");
	tacPrintSingle(tac);
	printf("tacPrintBack__-> OLARRR\n");
	tacPrintBack(tac->prev);
	printf("tacPrintBack__-> KKKK\n");
}

TAC* tacJoin(TAC *l1, TAC *l2)
{
	TAC* aux = 0;
	if(!l1) return l2;
	if(!l2) return l1;
	
	for(aux = l2; aux->prev; aux = aux->prev)
		aux->prev = l1;
	return l2;
}

//INTERMEDIATE CODE GENERATOR
TAC* codeGenerator(ASTREE* node)
{
	int i;
	TAC* result;
	TAC* code[MAX_SONS];

	if(!node) return 0;

	for(i=0; i < MAX_SONS; i++)
		code[i] = codeGenerator(node->son[i]);

	TAC* funcall_tac;
	TAC* arg;

	switch(node->type){
		case ASTREE_SYMBOL: result = tacCreate(TAC_SYMBOL, node->symbol, 0, 0); break;
		case ASTREE_ADD: result = tacJoin(code[0], tacJoin(code[1], tacCreate(TAC_ADD, makeTemp(), code[0]?code[0]->res:0, code[1]?code[1]->res:0))); break;
		case ASTREE_SUB: result = tacJoin(code[0], tacJoin(code[1], tacCreate(TAC_SUB, makeTemp(), code[0]?code[0]->res:0, code[1]?code[1]->res:0))); break;
		case ASTREE_MUL: result = tacJoin(code[0], tacJoin(code[1], tacCreate(TAC_MUL, makeTemp(), code[0]?code[0]->res:0, code[1]?code[1]->res:0))); break;
		case ASTREE_DIV: result = tacJoin(code[0], tacJoin(code[1], tacCreate(TAC_DIV, makeTemp(), code[0]?code[0]->res:0, code[1]?code[1]->res:0))); break;
		case ASTREE_L: result = tacJoin(code[0], tacJoin(code[1], tacCreate(TAC_L, makeTemp(), code[0]?code[0]->res:0, code[1]?code[1]->res:0))); break;
		case ASTREE_G: result = tacJoin(code[0], tacJoin(code[1], tacCreate(TAC_G, makeTemp(), code[0]?code[0]->res:0, code[1]?code[1]->res:0))); break;
		case ASTREE_LE: result = tacJoin(code[0], tacJoin(code[1], tacCreate(TAC_LE, makeTemp(), code[0]?code[0]->res:0, code[1]?code[1]->res:0))); break;
		case ASTREE_GE: result = tacJoin(code[0], tacJoin(code[1], tacCreate(TAC_GE, makeTemp(), code[0]?code[0]->res:0, code[1]?code[1]->res:0))); break;
		case ASTREE_EQ: result = tacJoin(code[0], tacJoin(code[1], tacCreate(TAC_EQ, makeTemp(), code[0]?code[0]->res:0, code[1]?code[1]->res:0))); break;
		case ASTREE_NE: result = tacJoin(code[0], tacJoin(code[1], tacCreate(TAC_NE, makeTemp(), code[0]?code[0]->res:0, code[1]?code[1]->res:0))); break;
		case ASTREE_AND: result = tacJoin(code[0], tacJoin(code[1], tacCreate(TAC_AND, makeTemp(), code[0]?code[0]->res:0, code[1]?code[1]->res:0))); break;
		case ASTREE_OR: result = tacJoin(code[0], tacJoin(code[1], tacCreate(TAC_OR, makeTemp(), code[0]?code[0]->res:0, code[1]?code[1]->res:0))); break;

		case ASTREE_ATR: result = tacJoin(code[0], tacCreate(TAC_ASSIGN, node->symbol, code[0]?code[0]->res:0,0)); break;

		case ASTREE_PRINT: return tacCreate(TAC_PRINT, node->symbol, 0, 0); break;
		case ASTREE_PRINTARG: return tacJoin(tacCreate(TAC_PRINTARG, code[0]?code[0]->res:0,0,0),code[1]); break;
		case ASTREE_READ: return tacCreate(TAC_READ, node->symbol, 0, 0); break;

		case ASTREE_WHILE: return makeWhile(code[0], code[1]); break;

		case ASTREE_RETURN: return tacJoin(code[0], tacCreate(TAC_RETURN, code[0]?code[0]->res:0, 0, 0)); break;

		case ASTREE_FUNDEF: return makeFun(node->symbol, code[3]); break;

		case ASTREE_FUNCALL: 
			funcall_tac = tacJoin(code[0], tacCreate(TAC_FUNCALL, node->symbol, 0, 0));
			arg = funcall_tac;

			if(arg != NULL){
				while(arg->prev != NULL){
					arg = arg->prev;
					if(arg->type == TAC_ARG)
						arg->res = node->symbol;
				}
			}
			return funcall_tac;
			break;

		case ASTREE_ARGFUN: return tacJoin(tacJoin(code[0], tacCreate(TAC_ARG, 0, code[0]?code[0]->res:0,0)), code[1]); break;
		default: result = tacJoin(tacJoin(tacJoin(code[0],code[1]),code[2]),code[3]); break;
	}
	return result;
}

TAC* makeBinOp(int type, TAC* code0, TAC* code1)
{
	TAC* newtac = tacCreate(TAC_ADD, makeTemp(), code0?code0->res:0, code1?code1->res:0);

	return tacJoin(code0, tacJoin(code1, newtac));
}

TAC* makeWhile(TAC* code0, TAC* code1)
{
	TAC* finalTacJump = 0;
	TAC* finalTacLabel = 0;
	TAC* initialTacJump = 0;
	TAC* initialTacLabel = 0;


	hash_Node* label_final = makeLabel();
	finalTacLabel = tacCreate(TAC_LABEL, label_final, 0, 0);
	finalTacJump = tacCreate(TAC_JZ, label_final, code0?code0->res:0, 0);

	hash_Node* label_initial = makeLabel();
	initialTacLabel = tacCreate(TAC_LABEL, label_initial, 0 , 0);
	initialTacJump = tacCreate(TAC_JMP, label_initial, code0?code0->res:0,0);

	return tacJoin(tacJoin(tacJoin(tacJoin(tacJoin(initialTacLabel,code0),finalTacJump),code1),initialTacJump),finalTacLabel);

}

TAC* makeIfThen(TAC* code0, TAC* code1)
{
	TAC* newJumpTac = 0;
	TAC* newLabelTac = 0;

	hash_Node *newlabel = makeLabel();
	newLabelTac = tacCreate(TAC_LABEL, newlabel, 0, 0);
	newJumpTac = tacCreate(TAC_JZ, newlabel, code0?code0->res:0, 0);

	return tacJoin(tacJoin(tacJoin(code0,newJumpTac),code1),newLabelTac);
}

TAC* makeFun(hash_Node* func, TAC* c)
{
	TAC* beginFunTac = 0;
	TAC* endFunTac = 0;

	beginFunTac = tacCreate(TAC_BEGINFUN, func, 0, 0);
	endFunTac = tacCreate(TAC_ENDFUN, func, 0, 0);

	return tacJoin(tacJoin(beginFunTac, c), endFunTac);
}