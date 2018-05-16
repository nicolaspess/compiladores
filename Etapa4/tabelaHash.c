// Etapa 1
// Daniel Machado Nidejelski, Nícolas Vincent Dall'Bello Pessutto 

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tabelaHash.h"

void hash_Init(){
	int i;
	
	for(i=0;i<=SIZE;i++){ Tabela[i] = 0; }
}

void hash_Print(){
	int i;
	hash_Node *nodo;
	
	for(i=0;i<SIZE;i++){
		for(nodo=Tabela[i]; nodo; nodo = nodo->prox){
			printf("Tabela[i]: %d , text: %s \n",i,nodo->text);
		}
	}
}

hash_Node* hash_Find(char* text){
	hash_Node *node;
	int address;
	address = hash_Address(text);

	for (node = Tabela[address]; node; node = node->prox){
		if( strcmp(node->text, text) == 0 ){
			return node;
		}
	}
	return 0;
}

hash_Node* hash_Insert(int type, char* text){
	int address;
	hash_Node *newnode = 0;
	address = hash_Address(text);
	newnode = (hash_Node*) calloc(1,sizeof(hash_Node));
	newnode->text = calloc(strlen(text)+1, sizeof(char));
	strcpy(newnode->text, text);
	newnode->type = type;
	newnode->tk_type = type;
	newnode->prox = Tabela[address];
	Tabela[address] = newnode;
	return newnode;
}

int hash_Address(char* text){
	int address = 1;
	int i;
	
	for (i = 0; i < strlen(text); ++i)
	{
		address = (address *text[i]) % SIZE + 1;
	}
	return address -1;
}

void hashVerificaNaoDeclarado(){
	int i;
	hash_Node *node;
	for(i = 0; i< SIZE; i++){
		for(node = Tabela[i]; node; node = node->prox){
			if(node->type == SYMBOL_IDENTIFIER){
				fprintf(stderr, "ERRO semantico: variavel '%s' nao foi declarada.\n", node->text);			
			}	
		}
	}
}

