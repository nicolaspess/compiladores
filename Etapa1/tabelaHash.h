// Etapa 1
// Daniel Machado Nidejelski, Nícolas Vincent Dall'Bello Pessutto 

#define SIZE 999

typedef struct hash
{
	int tipo;
	char* texto;
	struct hash *prox; 
}hash_Node;

hash_Node* Tabela[SIZE];

void hash_Init();
void hash_Print();
hash_Node* hash_Insert(int tipo, char* texto);
hash_Node* hash_Find(char* texto);
int hash_Address(char* texto);
