// Etapa 4
// Daniel Machado , Nicolas Pessutto

#include "ast.h"

#ifndef SEMANTIC_H
#define SEMANTIC_H

int verificaSemantica(ASTREE* node);

void setaTipos(ASTREE* node); 
void verificaNaoDeclarado(void);
void verificaUso(ASTREE* node);
void verificaOperandos(ASTREE* node);
void verificaRetorno(ASTREE *nodefunc, ASTREE *node);

void verificaTipoParam(ASTREE* nodecall);
void verificaNumParam(ASTREE* node);
int contaNumParam(ASTREE* node);

int maiorTipo(int a, int b);
ASTREE *procura(ASTREE *node, char *name);

#endif
