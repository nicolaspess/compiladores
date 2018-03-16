// Etapa 1
// Daniel Machado Nidejelski, Nícolas Vincent Dall'Bello Pessutto 

#define SIZE 999

typedef struct hash
{
	int tipo;
	char* texto;
	struct hash *prox; 
}hashNode;

hashNode* Tabela[SIZE];

void hashInit();
void hashPrint();
hashNode* hashInsert(int tipo, char* texto);
hashNode* hashFind(char* texto);
int hashAddress(char* texto);
