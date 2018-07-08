#include "compila.h"

FILE *f;

void setOutputFile(FILE *output) {
	f = output;
}
void printTipoDado(ASTREE *node);
void printTipo(ASTREE *node);
void printIdentifier(ASTREE *node);
void printAssignment();
void printSymbol(symbol_t *symbol);
void printInputKeyword();
void printOutputKeyword();
void printWhileKeyword();
void printReturnKeyword();
void printIfKeyword();
void printToKeyword();
void printElseKeyword();
void printThenKeyword();
void printForKeyword();
void printVectorAssignment();
void printPontoEVirgula();
void printVirgula();
void printLineFeed();
void printAbreIndex();
void printFechaIndex();
void printAbreBloco();
void printFechaBloco();
void printAbreParentesis();
void printFechaParentesis();
void printSpace();
void printPonteiroSymbol();
void printEnderecoSymbol();

void compilar(ASTREE *node) {
	if (!node){
		return;
	}

	switch(node->type) {
		case ASTREE_PROGRAM:
			compilar(node->children[0]);//lista de declaracoes
			break;

		case ASTREE_DEC_LIST:
			compilar(node->children[0]);//declaracao de valor, vetor (init tb), ou funcao
			compilar(node->children[1]);//outra lista de declaracoes
			break;

		case ASTREE_DEC_VALUE:
			printTipoDado(node);
			printIdentifier(node);
			printAssignment();
			compilar(node->children[0]);//symbol
			printPontoEVirgula();
			printLineFeed();
			break;

		case ASTREE_DEC_VECTOR:
			printTipoDado(node);
			printIdentifier(node);
			printAbreIndex();
			compilar(node->children[0]);//tamanho symbol
			printFechaIndex();
			printPontoEVirgula();
			printLineFeed();
			break;

		case ASTREE_DEC_VECTOR_INIT:
			printTipoDado(node);
			printIdentifier(node);
			printAbreIndex();
			compilar(node->children[0]);//tamanho symbol
			printFechaIndex();
			printVectorAssignment();
			compilar(node->children[1]);//lista de valores
			printPontoEVirgula();
			printLineFeed();
			break;

		case ASTREE_DEC_POINTER:
			printTipoDado(node);
			printPonteiroSymbol();
			printIdentifier(node);
			printAssignment();
			compilar(node->children[0]);//symbol
			printPontoEVirgula();
			printLineFeed();
			break;

		case ASTREE_DEC_FUNC:
			printTipoDado(node);
			printIdentifier(node);

			printAbreParentesis();
			compilar(node->children[0]);//lista de parametros
			printFechaParentesis();
			printSpace();
			
			compilar(node->children[1]);//bloco
			break;

		case ASTREE_PARAM_LIST:
			compilar(node->children[0]);//parametro
			if(node->children[1]) {
				printVirgula();
				compilar(node->children[1]);//lista de parametros
			}
			break;

		case ASTREE_PARAM:
			printTipoDado(node);
			printIdentifier(node);
			break;

		case ASTREE_VALUE_LIST:			
			compilar(node->children[0]); //declaracao de valor, vetor (init tb), ou funcao
			printSpace();			
			compilar(node->children[1]); //outra lista de declaracoes
			break;

		case ASTREE_SYMBOL:
			printSymbol(node->symbol);
			break;

		case ASTREE_SYMBOL_ADDRESS:
			printEnderecoSymbol();
			printIdentifier(node);
			break;

		case ASTREE_SYMBOL_POINTER:
			printPonteiroSymbol();
			printIdentifier(node);
			break;

		case ASTREE_BLOCK: 
			printAbreBloco();
			printLineFeed();		
			compilar(node->children[0]);//lista de comandos
			printFechaBloco();
			printLineFeed();
			break;

		case ASTREE_CMD_LIST:
			compilar(node->children[0]);//comando
			printPontoEVirgula(); 
			printLineFeed();
			compilar(node->children[1]);//outra lista de comandos
			break;

		case ASTREE_VALUE_ASSIGNMENT:
			printIdentifier(node);
			printAssignment();
			compilar(node->children[0]);//expressao
			break;

		case ASTREE_VECTOR_ASSIGNMENT:
			printIdentifier(node);
			printAbreIndex();
			compilar(node->children[0]);//index expressao
			printFechaIndex();
			printAssignment();
			compilar(node->children[1]);//valor expressao
			break;

		case ASTREE_VECTOR_ACCESS:
			printIdentifier(node);
			printAbreIndex();
			compilar(node->children[0]);//index expressao
			printFechaIndex();
			break;

		case ASTREE_READ:
			printInputKeyword();
			printIdentifier(node);
			break;

		case ASTREE_PRINT:
			printOutputKeyword();
			compilar(node->children[0]);//lista de elementos (symbol, literal, string ou expressao)
			break;

		case ASTREE_ELEM_LIST:
			compilar(node->children[0]);//elemento(symbol, literal, string ou expressao)
			printSpace();
			compilar(node->children[1]);//outra lista de elementos
			break;

		case ASTREE_RETURN:
			printReturnKeyword();
			compilar(node->children[0]);//lista de elementos 
			break;

		case ASTREE_IF_THEN:
			printIfKeyword();
			printAbreParentesis();
			compilar(node->children[0]);//expressao condicao if
			printFechaParentesis();
			printThenKeyword();
			printLineFeed();
			compilar(node->children[1]);//comando
			break;

		case ASTREE_IF_THEN_ELSE:
			printIfKeyword();
			printAbreParentesis();
			compilar(node->children[0]);//condicao expressao if then else
			printFechaParentesis();
			printThenKeyword();
			printLineFeed();
			compilar(node->children[1]);//comando
			printElseKeyword();
			compilar(node->children[2]);//outro comando
			printLineFeed();
			break;

		case ASTREE_WHILE:
			printWhileKeyword();
			printAbreParentesis();
			compilar(node->children[0]);//condicao expessao while
			printFechaParentesis();
			printLineFeed();
			compilar(node->children[1]);//comando
			break;

		case ASTREE_FOR:
			printForKeyword();
			printAbreParentesis();
			compilar(node->children[0]);
			printToKeyword();
			compilar(node->children[1]);
			printFechaParentesis();
			printLineFeed();
			compilar(node->children[2]);
			break;

		case ASTREE_INVOKE_FUNC:
			printIdentifier(node);
			printAbreParentesis();
			compilar(node->children[0]);//lista de argumentos
			printFechaParentesis();
			break;

		case ASTREE_ARG_LIST:
			compilar(node->children[0]);//argumento
			if(node->children[1]) {
				printVirgula();
				compilar(node->children[1]);//lista de parametros
			}
			break;

		case ASTREE_NOT:
			printTipo(node);
			compilar(node->children[0]);
			break;
        //igual para todas
		case ASTREE_ADD:
		case ASTREE_SUB:
		case ASTREE_MULT:
		case ASTREE_DIV:
		case ASTREE_LESS:
		case ASTREE_GREATER:
		case ASTREE_LESS_EQ:
		case ASTREE_GREATER_EQ:
		case ASTREE_EQ:
		case ASTREE_NEQ:
		case ASTREE_AND:
		case ASTREE_OR:
			compilar(node->children[0]);//expressao
			printTipo(node);
			compilar(node->children[1]);//expressao
			break;

		default:
			fprintf(f, "Not implemented yet. ast-> %d\n",node->type);
			break;
	}
	return;
}

void printSymbol(symbol_t *symbol) {
	switch (symbol->type) {
		case LIT_INTEGER:
			fprintf(f, "%d", symbol->intValue);
			break;
		case LIT_REAL:
			fprintf(f, "%.2f", symbol->doubleValue);
			break;
		case LIT_CHAR:
			fprintf(f, "'%c'", symbol->charValue);
			break;
		case LIT_STRING:
			fprintf(f, "%s", symbol->stringValue);
			break;
		case TK_IDENTIFIER:
			fprintf(f, "%s", symbol->key);
			break;
	}
	return;
}

void printToKeyword() {
	fprintf(f, " to ");
	return;
}

void printForKeyword() {
	fprintf(f, "for ");
	return;
}

void printIfKeyword() {
	fprintf(f, "if ");
	return;
}

void printElseKeyword() {
	fprintf(f, "else ");
	return;
}

void printThenKeyword() {
	fprintf(f, "then ");
	return;
}

void printWhileKeyword() {
	fprintf(f, "while ");
	return;
}

void printReturnKeyword() {
	fprintf(f, "return ");
	return;
}

void printOutputKeyword() {
	fprintf(f, "print ");
	return;
}

void printInputKeyword() {
	fprintf(f, "read ");
	return;
}

void printEnderecoSymbol() {
	fprintf(f, "&");
	return;
}

void printPonteiroSymbol() {
	fprintf(f, "#");
	return;
}

void printSpace() {
	fprintf(f, " ");
	return;
}

void printAbreIndex() {
	fprintf(f, "[");
	return;
}

void printFechaIndex() {
	fprintf(f, "]");
	return;
}

void printAbreParentesis() {
	fprintf(f, "(");
	return;
}

void printFechaParentesis() {
	fprintf(f, ")");
	return;
}

void printAbreBloco() {
	fprintf(f, "{");
	return;
}

void printFechaBloco() {
	fprintf(f, "}");
	return;
}

void printPontoEVirgula() {
	fprintf(f, ";");
	return;
}

void printVirgula() {
	fprintf(f, ", ");
	return;
}

void printLineFeed() {
	fprintf(f, "\n");
	return;
}

void printVectorAssignment() {
	fprintf(f, " : ");
	return;
}

void printAssignment() {
	fprintf(f, " = ");
	return;
}

void printIdentifier(ASTREE *node) {
	fprintf(f, "%s", node->symbol->stringValue);
	return;
}

void printTipoDado(ASTREE *node) {
	fprintf(f, "%s ", tokenToString(node->dataType));
	return;
}

void printTipo(ASTREE *node) {
	fprintf(f, " %s ", astTipoToString(node->type));
	return;
}

const char * tokenToString(int token) {
	switch (token) {
		case KW_FLOAT:
		case LIT_REAL:
			return "float";
			break;
		case KW_CHAR:
		case LIT_CHAR:
			return "char";
			break;
		case KW_INT:
		case LIT_INTEGER:
			return "int";
			break;
		case LIT_STRING:
			return "string";
			break;
		
		default: 
			return "default";
	}
}

const char * astTipoToString(int type) {
	switch (type) {
		case ASTREE_DEC_VECTOR:
			return "vector";
			break;
		case ASTREE_DEC_VALUE:
			return "assignment";
			break;
		case ASTREE_CMD_LIST:
			return "command list";
			break;
		case ASTREE_PROGRAM:
			return "program";
			break;
		case ASTREE_SYMBOL:
			return "symbol";
			break;
		case ASTREE_VALUE_LIST:
			return "value list";
			break;
		case ASTREE_BLOCK:
			return "block";
			break;
		case ASTREE_ADD:
			return "+";
			break;
		case ASTREE_SUB:
			return "-";
			break;
		case ASTREE_MULT:
			return "*";
			break;
		case ASTREE_DIV:
			return "/";
			break;
		case ASTREE_LESS:
			return "<";
			break;
		case ASTREE_GREATER:
			return ">";
			break;
		case ASTREE_LESS_EQ:
			return "<=";
			break;
		case ASTREE_GREATER_EQ:
			return ">=";
			break;
		case ASTREE_EQ:
			return "==";
			break;
		case ASTREE_NEQ:
			return "!=";
			break;
		case ASTREE_AND:
			return "&&";
			break;
		case ASTREE_OR:
			return "||";
			break;
		case ASTREE_NOT:
			return "!";
			break;

		default: 
			return "default";
	}
}