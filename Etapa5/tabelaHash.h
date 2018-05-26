// Etapa 1
// Daniel Machado Nidejelski, Nícolas Vincent Dall'Bello Pessutto 

#define SIZE 999

#define SYMBOL_IDENTIFIER 10
#define SYMBOL_VAR 11
#define SYMBOL_ARR 12
#define SYMBOL_FUN 13
#define SYMBOL_LABEL 14

#define SYMBOL_LIT_INT 100
#define SYMBOL_LIT_REAL 101
#define SYMBOL_LIT_CHAR 102
#define SYMBOL_LIT_STRING 103

#define SYMBOL_DATATYPE_INT 201
#define SYMBOL_DATATYPE_CHAR 202
#define SYMBOL_DATATYPE_FLOAT 203


typedef struct hash
{
	int tk_type;
	int type;
	char* text;
    int numparam;
	struct hash *prox; 
}hash_Node;

hash_Node* Tabela[SIZE];

void hash_Init();
void hash_Print();
hash_Node* hash_Insert(int tipo, char* texto);
hash_Node* hash_Find(char* texto);
int hash_Address(char* texto);

int hashVerificaNaoDeclarado();

hash_Node* makeTemp(void);
hash_Node* makeLabel(void);
