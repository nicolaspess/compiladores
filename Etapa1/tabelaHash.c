// Etapa 1
// Daniel Machado Nidejelski, Nícolas Vincent Dall'Bello Pessutto 

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tabelaHash.h"

void hash_Init(){
	int i;
	
	for(i=0;i<=SIZE;i++){ Tabela[i] = 0 };
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
	//implementar
}

hash_Node* hash_Insert(int tipo, char* texto){
	//implementar
}

int hash_Address(char* texto){
	//implementar
}

