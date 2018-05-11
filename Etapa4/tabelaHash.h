// Etapa 1
// Daniel Machado Nidejelski, Nícolas Vincent Dall'Bello Pessutto 

#define SIZE 999

#define SYMBOL_ID 1
#define SYMBOL_LIT_INT 2
#define SYMBOL_LIT_FLOAT 3
#define SYMBOL_SCALAR 4
#define SYMBOL_FUNCTION 5
#define SYMBOL_VECTOR 6
#define SYMBOL_POINTER 7

typedef struct hash
{
	int tk_tipo;
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
