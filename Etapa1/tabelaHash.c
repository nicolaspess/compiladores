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
			printf("Tabela[i]: %d , Texto: %s",i,nodo->texto);
		}
	}
}

hash_Node* hash_Find(char* texto){
	hash_Node *node;
	int address;
	address = hash_Address(texto);

	for (node = Tabela[address]; node; node = node->prox){
		if( strcmp(node->texto, texto) == 0 ){
			return node;
		}
	}
	return 0;
}

hash_Node* hash_Insert(int tipo, char* texto){
	int address;
	hash_Node *newnode = 0;
	address = hash_Address(texto);
	newnode = (hash_Node*) calloc(1,sizeof(hash_Node));
	newnode->texto = calloc(strlen(texto)+1, sizeof(char));
	strcpy(newnode->texto, texto);
	newnode->tipo = tipo;
	newnode->prox = Tabela[address];
	Tabela[address] = newnode;
	return newnode;
}

int hash_Address(char* texto){
	int address = 1;
	int i;
	
	for (i = 0; i < strlen(texto); ++i)
	{
		address = (address *texto[i]) % SIZE + 1;
	}
	return address -1;
}

