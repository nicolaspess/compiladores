/// Etapa 4
// Daniel Machado , Nicolas Pessutto

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "semantic.h"
#include "y.tab.h"


ASTREE *raiz;
int erroSemantica = 0;


int verificaSemantica(ASTREE* node)
{
	raiz = node;	
	
	setaTipos(node); 
	//verificaNaoDeclarado();
	verificaUso(node);
	verificaOperandos(node);

	return erroSemantica;
}

void setaTipos(ASTREE* node)
{
	int i;
	if (!node) return;
	
	if(node->type == ASTREE_VARINI){
		if(node->symbol->type != SYMBOL_IDENTIFIER){
			fprintf(stderr,"ERRO: Identificador ja foi declarado! \n");
			erroSemantica++;
		}
		else{
			node->symbol->type = SYMBOL_VAR;
			if(node->son[0]->type == ASTREE_INT) node->symbol->tk_type = SYMBOL_DATATYPE_INT;
			if(node->son[0]->type == ASTREE_FLOAT) node->symbol->tk_type = SYMBOL_DATATYPE_FLOAT;
			if(node->son[0]->type == ASTREE_CHAR) node->symbol->tk_type = SYMBOL_DATATYPE_CHAR;
		}
	}
	if(node->type == ASTREE_ARRINI){
		if(node->symbol->type != SYMBOL_IDENTIFIER){
			fprintf(stderr,"ERRO: Identificador ja foi declarado! \n");
			erroSemantica++;
		}
		else{
			node->symbol->type = SYMBOL_ARR;
			if(node->son[0]->type == ASTREE_INT) node->symbol->tk_type = SYMBOL_DATATYPE_INT;
			if(node->son[0]->type == ASTREE_FLOAT) node->symbol->tk_type = SYMBOL_DATATYPE_FLOAT;
			if(node->son[0]->type == ASTREE_CHAR) node->symbol->tk_type = SYMBOL_DATATYPE_CHAR;
		}
	}
	if (node->type == ASTREE_FUNDEF){
		if(node->symbol->type != SYMBOL_IDENTIFIER){
			fprintf(stderr, "ERRO: Identificador ja foi declarado! \n");
			erroSemantica++;
		}
		else{
			node->symbol->type = SYMBOL_FUN;
			node->symbol->numparam = contaNumParam(node->son[1]);
			if(node->son[0]->type == ASTREE_INT) node->symbol->tk_type = SYMBOL_DATATYPE_INT;
			if(node->son[0]->type == ASTREE_FLOAT) node->symbol->tk_type = SYMBOL_DATATYPE_FLOAT;
			if(node->son[0]->type == ASTREE_CHAR) node->symbol->tk_type = SYMBOL_DATATYPE_CHAR;
		}
	}
	if(node->type == ASTREE_PARAM){
		if(node->symbol->type != SYMBOL_IDENTIFIER){
			fprintf(stderr, "ERRO: Identificador ja foi declarado! \n");
			erroSemantica++;
		}
		else{
			node->symbol->type = SYMBOL_VAR;
			if(node->son[0]->type == ASTREE_INT) node->symbol->tk_type = SYMBOL_DATATYPE_INT;
			if(node->son[0]->type == ASTREE_FLOAT) node->symbol->tk_type = SYMBOL_DATATYPE_FLOAT;
			if(node->son[0]->type == ASTREE_CHAR) node->symbol->tk_type = SYMBOL_DATATYPE_CHAR;
			if(node->son[0]->type == ASTREE_CHAR) node->symbol->tk_type = SYMBOL_DATATYPE_CHAR;
		}
	}
	for (i=0; i<MAX_SONS; ++i)
		setaTipos(node->son[i]);
}

void verificaNaoDeclarado(void)
{
	hashVerificaNaoDeclarado();
}

void verificaUso(ASTREE *node)
{
	int i;
	
	if(!node) return;
	
	switch(node->type){
		case ASTREE_VARINI: 
			if(node->symbol->type != SYMBOL_VAR)
			{
				fprintf(stderr, "ERRO: identificador deve ser escalar.\n");
				erroSemantica++;
			}
			if(node->son[0]->symbol != NULL) 
			{	
				if(node->symbol->tk_type <= SYMBOL_DATATYPE_INT && node->son[0]->symbol->tk_type >= SYMBOL_DATATYPE_FLOAT)
				{
					fprintf(stderr, "ERRO: tipos incompativeis.\n");
					erroSemantica++;
				}
			}		
			break;
		case ASTREE_FUNCALL: if(node->symbol->type != SYMBOL_IDENTIFIER)
			{
				fprintf(stderr, "ERRO: identificador deve ser funcao.\n");
				erroSemantica++;
			}
			verificaNumParam(node);
			verificaTipoParam(node);			
			break;
		case ASTREE_FUNDEF: verificaRetorno(node, node->son[2]);
			break;
		case ASTREE_ARRAY_WRITE: 

			if(node->symbol->type != SYMBOL_IDENTIFIER)
			{
				fprintf(stderr, "ERRO: identificador deve ser vetor.\n");
				erroSemantica++;
			}
			if(node->son[0]->symbol != NULL) 
			{	
				if(node->son[0]->symbol->tk_type == SYMBOL_DATATYPE_FLOAT || node->son[0]->symbol->tk_type == SYMBOL_DATATYPE_CHAR)
				{
					fprintf(stderr, "ERRO: indice deve ser int.\n");
					erroSemantica++;
				}
			}
			if(node->son[1]->symbol != NULL) 
			{	
				if(node->symbol->tk_type <= SYMBOL_DATATYPE_INT && node->son[1]->symbol->tk_type >= SYMBOL_DATATYPE_FLOAT)
				{
					fprintf(stderr, "ERRO: tipos incompativeis.\n");
					erroSemantica++;
				}
			}
			if(node->son[0]->type != ASTREE_ADD && node->son[0]->type != ASTREE_SUB && node->son[0]->type != ASTREE_SYMBOL)
			{
				fprintf(stderr, "ERRO: indice deve ser int.\n");
				erroSemantica++;			
			}
			if(node->son[0]->type == ASTREE_ADD || node->son[0]->type == ASTREE_SUB)
			{
				if(maiorTipo(node->son[0]->son[0]->symbol->tk_type,node->son[0]->son[1]->symbol->tk_type) >= SYMBOL_DATATYPE_FLOAT)
				{
					fprintf(stderr, "ERRO: indice deve ser int.\n");
					erroSemantica++;
				}			
			}			
			break;
		case ASTREE_ARRAY_READ: if(node->symbol->type != SYMBOL_IDENTIFIER)
			{
				fprintf(stderr, "ERRO: identificador deve ser vetor.\n");
				erroSemantica++;
			}
			if(node->son[0]->symbol != NULL) 
			{			
				if(node->son[0]->symbol->tk_type == SYMBOL_DATATYPE_FLOAT || node->son[0]->symbol->tk_type == SYMBOL_DATATYPE_CHAR)
				{
					fprintf(stderr, "ERRO: indice deve ser int.\n");
					erroSemantica++;
				}
			}
			if(node->son[0]->type != ASTREE_ADD && node->son[0]->type != ASTREE_SUB && node->son[0]->type != ASTREE_SYMBOL)
			{
				fprintf(stderr, "ERRO: indice deve ser int.\n");
				erroSemantica++;			
			}
			if(node->son[0]->type == ASTREE_ADD || node->son[0]->type == ASTREE_SUB)
			{
				if(maiorTipo(node->son[0]->son[0]->symbol->tk_type,node->son[0]->son[1]->symbol->tk_type) >= SYMBOL_DATATYPE_FLOAT)
				{
					fprintf(stderr, "ERRO: indice deve ser int.\n");
					erroSemantica++;
				}			
			}
			break;
			
		case ASTREE_IF:  
   			{	if(node->son[0]->symbol != NULL) {
        			if (node->son[0]->type != ASTREE_L && node->son[0]->type != ASTREE_G && node->son[0]->type != ASTREE_LE && node->son[0]->type != ASTREE_GE && node->son[0]->type != ASTREE_EQ && node->son[0]->type != ASTREE_NE && node->son[0]->type != ASTREE_NOT)
       				{
            				fprintf(stderr, "ERRO: deve ser condicional\n");
            				erroSemantica++;
        			}}
    			}
			break; 
		case ASTREE_WHILE:
   			{	if(node->son[0]->symbol != NULL) {
        			if (node->son[0]->type != ASTREE_L && node->son[0]->type != ASTREE_G && node->son[0]->type != ASTREE_LE && node->son[0]->type != ASTREE_GE && node->son[0]->type != ASTREE_EQ && node->son[0]->type != ASTREE_NE && node->son[0]->type != ASTREE_NOT)
       				{
            				fprintf(stderr, "ERRO: deve ser condicional\n");
            				erroSemantica++;
        			}}
    			} 
			break;
		case ASTREE_PRINT:
			if(node->son[0]->symbol != NULL) {
			if(node->son[0]->symbol->type != SYMBOL_LIT_STRING)
			{
				fprintf(stderr, "ERRO: deve ser string.\n");
				erroSemantica++;
			}}
			break;
		case ASTREE_READ:
			if(node->symbol->type != SYMBOL_IDENTIFIER)
			{
				fprintf(stderr, "ERRO: identificador deve ser escalar.\n");
				erroSemantica++;
			}
		break;
		case ASTREE_SYMBOL:
			if(node->symbol->type != SYMBOL_IDENTIFIER && node->symbol->type != SYMBOL_LIT_INT && node->symbol->type != SYMBOL_LIT_REAL && node->symbol->type != SYMBOL_LIT_CHAR && node->symbol->type != SYMBOL_LIT_STRING)
			{
				fprintf(stderr, "ERRO: identificador deve ser escalar.\n");
				erroSemantica++;
			}
			break;
		default: break;
	}
	
	for(i=0; i <MAX_SONS; ++i)
		verificaUso(node->son[i]);
}

void verificaOperandos(ASTREE* node)
{
	int i;
	if (!node) return;
	
	if (node->type == ASTREE_ADD || node->type == ASTREE_SUB || node->type == ASTREE_MUL || 
	    node->type == ASTREE_DIV || node->type == ASTREE_G || node->type == ASTREE_L || 
		node->type == ASTREE_NE || node->type == ASTREE_EQ || node->type == ASTREE_LE || 
		node->type == ASTREE_GE){
		if(node->son[0]->type == ASTREE_G || node->son[0]->type == ASTREE_L || 
		   node->son[0]->type == ASTREE_GE || node->son[0]->type == ASTREE_LE || 
		   node->son[0]->type == ASTREE_NE || node->son[0]->type == ASTREE_EQ || 
		   node->son[0]->type == ASTREE_OR || node->son[0]->type == ASTREE_AND|| 
           node->son[0]->type == ASTREE_NOT) {
			    fprintf(stderr, "ERRO: Operando esquerdo não pode ser logico. \n");
			    erroSemantica++;
		}
		if(node->son[1]->type == ASTREE_G ||
		   node->son[1]->type == ASTREE_L || node->son[1]->type == ASTREE_GE || 
		   node->son[1]->type == ASTREE_LE || node->son[1]->type == ASTREE_NE || 
		   node->son[1]->type == ASTREE_EQ || node->son[1]->type == ASTREE_OR || 
		   node->son[1]->type == ASTREE_AND|| node->son[1]->type == ASTREE_NOT) {
			    fprintf(stderr, "ERRO: Operando direito não pode ser logico. \n");
			    erroSemantica++;
		}
	}
		
	if (node->type == ASTREE_AND || node->type == ASTREE_OR || node->type == ASTREE_NOT){
		if(node->son[0]->type == ASTREE_MUL || node->son[0]->type == ASTREE_ADD || 
		   node->son[0]->type == ASTREE_SUB || node->son[0]->type == ASTREE_DIV) {
			    fprintf(stderr, "ERRO: Operando esquerdo não pode ser aritmético. \n");
			    erroSemantica++;
		}
		if(node->son[1]->type == ASTREE_MUL || node->son[1]->type == ASTREE_ADD || 
		   node->son[1]->type == ASTREE_SUB || node->son[1]->type == ASTREE_DIV) {
			    fprintf(stderr, "ERRO: Operando direito não pode ser aritmético. \n");
			    erroSemantica++;
		}
	}
	
	for (i=0; i<MAX_SONS; ++i)
		verificaOperandos(node->son[i]);
}

void verificaRetorno(ASTREE *nodefunc, ASTREE *node)
{	
	int i = 0;
	int data;
	int flag = 0;
	
	if(!node) return;
	
	if(node->type == ASTREE_RETURN)
	{ 
		if(node->son[0] != NULL){ 
			
			if(node->son[0]->type == ASTREE_PARENTHESIS)
			{	
				if(node->son[0]->son[0]->type == ASTREE_ADD || node->son[0]->son[0]->type == ASTREE_SUB || 
				   node->son[0]->son[0]->type == ASTREE_MUL || node->son[0]->son[0]->type == ASTREE_DIV ) {			
				       data = maiorTipo(node->son[0]->son[0]->son[0]->symbol->tk_type, node->son[0]->son[0]->son[1]->symbol->tk_type);
				}
				else {
					if(node->son[0]->son[0]->type == ASTREE_L || node->son[0]->son[0]->type == ASTREE_G ||
					   node->son[0]->son[0]->type == ASTREE_LE || node->son[0]->son[0]->type == ASTREE_GE || 
					   node->son[0]->son[0]->type == ASTREE_EQ || node->son[0]->son[0]->type == ASTREE_NE || 
					   node->son[0]->son[0]->type == ASTREE_NOT || node->son[0]->son[0]->type == ASTREE_AND ||
					   node->son[0]->son[0]->type == ASTREE_OR)	{
					       fprintf(stderr, "ERRO: retorno invalido.\n");
						   flag = 1;	
						   erroSemantica++;
					}
					else{
						data = node->son[0]->son[0]->symbol->tk_type; 
					}

                }			
			}

			if(node->symbol != NULL)
			{
				if (data != nodefunc->symbol->tk_type && flag == 0)
				{
					fprintf(stderr, "ERRO: tipo retorno invalido.\n");	
					erroSemantica++;
				}
			}
		}
	}

	for(i = 0; i < MAX_SONS; i++) 
		verificaRetorno(nodefunc, node->son[i]);

}

void verificaTipoParam(ASTREE* nodecall) 
{
	if(!nodecall) return;
	ASTREE* nodedef;
	if(nodecall->symbol != NULL) nodedef = procura(raiz, nodecall->symbol->text);	

	if(nodecall->son[0] != NULL && nodedef->son[1] != NULL)
	{
		nodecall = nodecall->son[0];	
		nodedef = nodedef->son[1];	
	
		while(nodecall != NULL && nodedef != NULL)
		{	
			if(nodecall->son[0]->symbol != NULL && nodedef->son[0]->symbol != NULL) 
				{
					if(nodecall->son[0]->symbol->tk_type > nodedef->son[0]->symbol->tk_type)
					{
						fprintf(stderr, "ERRO: Tipo de parametro incorreto\n");
						erroSemantica++;
					}
				}
				nodecall = nodecall->son[1];
				nodedef = nodedef->son[1];			
		}
	}
}

ASTREE *procura(ASTREE *node, char *name)
{
	int i;
	ASTREE *fun;
	
	if(!node) return 0;

	if(node->type == ASTREE_FUNDEF)
		if(node->symbol != NULL)
		{			
			if(strcmp(node->symbol->text, name) == 0)
			return node;
		}

		for(i=0; i < MAX_SONS; i++)
			if(node->son[i] != NULL) 
			{
				fun = procura(node->son[i], name);
				if(fun) 
					return fun;
			}
	return 0;
}


void verificaNumParam(ASTREE* node)
{
	int numParam = 0;
	int correct = node->symbol->numparam;
	
	numParam = contaNumParam(node->son[0]);

	if(numParam != correct)
	{
		fprintf(stderr, "ERRO: Numero de parametros incorretos\n");
		erroSemantica++;
	}	
}

int contaNumParam(ASTREE *node)
{
	if(!node) return 0;
	else{
		return 1 + contaNumParam(node->son[1]);
	}

	return 0;
}

int maiorTipo(int a, int b)
{
	if(a > b) return a;
	else return b;
}
