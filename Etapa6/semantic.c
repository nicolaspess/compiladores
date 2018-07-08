#include "semantic.h"
extern map_t scannedSymbolsMap;

symbol_t* getSymbolInScopes(map_t firstScope, map_t secondScope, char* identifier) {
	symbol_t *symbol;
	symbol = getSymbol(firstScope, identifier);
	if(symbol) {
		return symbol;
	}
	symbol = getSymbol(secondScope, identifier);
	if(symbol) {
		return symbol;
	}
	return NULL;
}

int literalDataTypeFromKeyword(int keyword) {
	switch (keyword) {
		case KW_INT: return LIT_INTEGER;
		case KW_CHAR: return LIT_CHAR;
		case KW_FLOAT: return LIT_REAL;
		case LIT_INTEGER: return LIT_INTEGER;
		case LIT_CHAR: return LIT_CHAR;
		case LIT_REAL: return LIT_REAL;
		default: 
			printf("literalDataTypeFromKeyword não pode converter tipo (%d)\n", keyword);
			return 0;
	}
}

int typeCanTakeliteralDataType(int type, int literalDataType) {
	if(type == literalDataType) {return 1;}//mega gambi hehe
	type=literalDataTypeFromKeyword(type);
	switch (type) {
		case LIT_INTEGER:
		case LIT_REAL:
		case LIT_CHAR:
			return (literalDataType == LIT_INTEGER || literalDataType == LIT_CHAR || literalDataType == LIT_REAL);
		default:
			return 0;
	}
}

//retorna 0 se não for possível
int tryCoercion(int firstType, int secondType) {
	if(firstType == secondType) {return firstType;}//mega gambi hehe
	switch (firstType) {
		case LIT_INTEGER:
			if(secondType == LIT_REAL) {
				return secondType;
			}
			return 0;
		case LIT_REAL:
			if(secondType == LIT_INTEGER) {
				return firstType;
			}

			return 0;
		default:
			return 0;
	}
}


int semantic(ASTREE *node, map_t* scope) {
	if(!scope) {
		return SEMANTIC_ERROR;
	}
	int error, type, literalDataType, size, argCount, rightSideType,leftSideType, coercionType;
	char *identifier;
	ASTREE *valueNode, *listNode;
	symbol_t *declaredSymbol;

	if (!node){
		return SEMANTIC_SUCCESS;
	}
	switch(node->type) {
		case ASTREE_PROGRAM:
			printf("semantic ASTREE_PROGRAM OK.\n");
			return semantic(node->children[0], programScope);//declaration list

		case ASTREE_DEC_LIST:
			printf("semantic ASTREE_DEC_LIST OK\n");
			error = semantic(node->children[0], programScope);//declaration of value, vector, initialized vector or function
			if(error) {
				return error;
			}
			error = semantic(node->children[1], programScope);//another declaration list
			if(error) {
				return error;
			}
			return SEMANTIC_SUCCESS;

		case ASTREE_DEC_VALUE:
			printf("semantic ASTREE_DEC_VALUE\n");
			
			identifier = node->symbol->key;
			type = node->dataType;

			valueNode = node->children[0];
			literalDataType = valueNode->symbol->type;

			if(! typeCanTakeliteralDataType(type, literalDataType)) {
			// if ( literalDataTypeFromKeyword(type) != literalDataType) {
				printf("declarou um %d, passou  um %d\n",type,literalDataType);
				return SEMANTIC_ERROR;
			}

			declaredSymbol = getSymbol(programScope, identifier);
			if(declaredSymbol) {
				printf("Simbolo ja foi declarado.\n");
				return SEMANTIC_ERROR;
			}

			printf("adicionado como: %s, %d\n", identifier,literalDataTypeFromKeyword(type));
			addSymbol(programScope, literalDataTypeFromKeyword(type), identifier, node->symbol->line);

			return SEMANTIC_SUCCESS;

		case ASTREE_DEC_VECTOR:
			printf("semantic ASTREE_DEC_VECTOR OK.\n");
			identifier = node->symbol->key;
			literalDataType = literalDataTypeFromKeyword(node->dataType);
			size = node->children[0]->symbol->intValue;
			
			declaredSymbol = getSymbol(programScope, identifier);
			if(declaredSymbol) {
				printf("simbolo ja foi declarado.\n");
				return SEMANTIC_ERROR;
			}

			printf("adicionado como: %s, %d\n", identifier,literalDataType);
			declaredSymbol = addSymbol(programScope, literalDataType, identifier, node->symbol->line);
			declaredSymbol->isArray = 1;
			declaredSymbol->arrayCapacity = size;

			return SEMANTIC_SUCCESS;

		case ASTREE_DEC_VECTOR_INIT:
			printf("semantic ASTREE_DEC_VECTOR_INIT\n");
			size = node->children[0]->symbol->intValue;
			type = node->dataType;
			identifier = node->symbol->stringValue;

			listNode = node->children[1];
			argCount = 0;
			while(listNode) {
				if (argCount > size - 1) {
					return SEMANTIC_ERROR;
				}

				literalDataType = listNode->children[0]->symbol->type;
				if ( literalDataTypeFromKeyword(type) != literalDataType) {
					printf("declarou um %d, passou um %d\n",type,literalDataType);
					return SEMANTIC_ERROR;
				}

				listNode = listNode->children[1];
				if(listNode == NULL && argCount < size - 1) {
					return SEMANTIC_ERROR;
				}
				argCount++;
			}

			declaredSymbol = getSymbol(programScope, identifier);
			if(declaredSymbol) {
				printf("simbolo ja foi declarado.\n");
				return SEMANTIC_ERROR;
			}
			literalDataType = literalDataTypeFromKeyword(type);
			printf("adicionado como: %s, %d\n", identifier,literalDataType);
			declaredSymbol = addSymbol(programScope, literalDataType, identifier, node->symbol->line);
			declaredSymbol->isArray = 1;
			declaredSymbol->arrayCapacity = size;
			return  SEMANTIC_SUCCESS;

		case ASTREE_DEC_POINTER:
			printf("semantic ASTREE_DEC_POINTER\n");
			identifier = node->symbol->stringValue;
			type = node->dataType;

			valueNode = node->children[0];
			literalDataType = valueNode->symbol->type;

			if ( ! typeCanTakeliteralDataType(type, literalDataType) ) {
				printf("declarou um %d, passou um %d\n",type,literalDataType);
				return SEMANTIC_ERROR;
			}

			declaredSymbol = getSymbol(programScope, identifier);
			if(declaredSymbol) {
				printf("simbolo ja foi declarado.\n");
				return SEMANTIC_ERROR;
			}
			printf("adicionado como: %s, %d\n", identifier,literalDataType);
			declaredSymbol = addSymbol(programScope, literalDataType, identifier, node->symbol->line);
			declaredSymbol->isPointer = 1;
			return SEMANTIC_SUCCESS;

		case ASTREE_DEC_FUNC:
			printf("semantic ASTREE_DEC_FUNC\n");
			
			literalDataType = literalDataTypeFromKeyword(node->dataType);

			identifier = node->symbol->stringValue;
			declaredSymbol = getSymbol(programScope, identifier);
			if(declaredSymbol) {
				printf("simbolo ja foi declarado.\n");
				return SEMANTIC_ERROR;
			}
			
			printf("adicionado como: %s, %d\n", identifier,literalDataType);
			declaredSymbol = addSymbol(programScope, literalDataType, identifier, node->symbol->line);
			declaredSymbol->isFunction = 1;

			map_t functionScope = newMap();
			declaredSymbol->scope = functionScope;

			addSymbol(functionScope, literalDataType, "_return_type_", 0);

			listNode = node->children[0];//param_list
			argCount = 0;
			while(listNode) { //enquanto tem param_list
				valueNode = listNode->children[0];//pega param
				literalDataType = literalDataTypeFromKeyword(valueNode->dataType); //pega tipo do param
				identifier = valueNode->symbol->key;
				printf("parametro %d, %s, tipo %d\n",argCount, identifier,literalDataType);

				symbol_t *paramSymbol = getSymbol(functionScope, identifier);
				if(paramSymbol) {
					printf("Simbolo ja foi declarado na funcao\n");
					return SEMANTIC_ERROR;
				}
				paramSymbol = addSymbol(functionScope, literalDataType, identifier, node->symbol->line);
				paramSymbol->dataType = literalDataType;
				declaredSymbol->parameters[argCount] = paramSymbol;
				
				argCount++;
				listNode = listNode->children[1];
			}
			declaredSymbol->argCount = argCount;
			return  semantic(node->children[1], functionScope);//passa escopo pro bloco

		case ASTREE_SYMBOL_POINTER:
		case ASTREE_SYMBOL_ADDRESS:
		case ASTREE_SYMBOL:
			printf("semantic ASTREE_SYMBOL, %s\n", node->symbol->key);
			type = node->symbol->type;
			if(type != TK_IDENTIFIER) {
				node->dataType = node->symbol->type;
				return SEMANTIC_SUCCESS;
			}
			identifier = node->symbol->key;
			// printf("%d\n", node->symbol->type);
			declaredSymbol = getSymbolInScopes(scope, programScope, identifier);
			if (!declaredSymbol) {
				printf("Simbolo nao declarado\n");
				return SEMANTIC_ERROR;
			}
			node->dataType = declaredSymbol->type;
			printf("semantic ASTREE_SYMBOL, %s, tipo %d\n", node->symbol->key, node->dataType);

			if (declaredSymbol->isArray) {
				printf("Erro: Vetor precisa de indexacao\n");
				return SEMANTIC_ERROR;
			}

			if (declaredSymbol->isFunction) {
				printf("Erro: Funcao deve ter  argumentos\n");
				return SEMANTIC_ERROR;
			}

			if(node->type==ASTREE_SYMBOL_POINTER && !declaredSymbol->isPointer) {
				printf("Erro: Identificador nao pode ser ponteiro\n");
				return SEMANTIC_ERROR;
			}

			return SEMANTIC_SUCCESS;

		case ASTREE_BLOCK:
			printf("semantic ASTREE_BLOCK\n");
			return semantic(node->children[0], scope);

		case ASTREE_CMD_LIST:
			printf("semantic ASTREE_CMD_LIST\n");
			error = semantic(node->children[0], scope);
			if(error) {
				return error;
			}
			error = semantic(node->children[1], scope);
			if(error) {
				return error;
			}
			return SEMANTIC_SUCCESS;

		case ASTREE_POINTER_ASSIGNMENT:
		case ASTREE_VALUE_ASSIGNMENT:
			printf("semantic ASTREE_ASSIGNMENT, %s\n", node->symbol->key);

			error = semantic(node->children[0], scope); //se tem sucesso, popula node->children[0]->dataType com o tipo resultante
			if(error) {
				return error;
			}
			
			identifier = node->symbol->key;
			valueNode = node->children[0];
			literalDataType = valueNode->dataType;
		
			printf("declaracao como: %s, %d\n", identifier,literalDataType);
			declaredSymbol = getSymbolInScopes(scope,programScope,identifier);
			if(!declaredSymbol) {
				printf("nao estava declarado escopo algum\n");
				return SEMANTIC_ERROR;
			}
			
			type = declaredSymbol->type;
			printf("tipo: %d, lit: %d\n", type,literalDataType);
			if ( ! typeCanTakeliteralDataType(type, literalDataType) ) {
				printf("declarou um %d, passou um um %d\n", type, literalDataType);
				return SEMANTIC_ERROR;
			}

			if(declaredSymbol->isArray) {
				printf("Erro: vetor precisa de indexacao\n");
				return SEMANTIC_ERROR;
			}

			if(declaredSymbol->isFunction) {
				printf("Erro: func deve ter argumentos\n");
				return SEMANTIC_ERROR;
			}
			
			if(declaredSymbol->isPointer && node->type!=ASTREE_POINTER_ASSIGNMENT) {
				if(node->children[0]->type!=ASTREE_SYMBOL_ADDRESS) {
					printf("Erro: somente um endereco a um ponteiro\n");
					return SEMANTIC_ERROR;
				}
			}

			return SEMANTIC_SUCCESS;

		case ASTREE_VECTOR_ASSIGNMENT:
			printf("semantic ASTREE_VECTOR_ASSIGNMENT, %s\n", node->symbol->key);
			error = semantic(node->children[0], scope); //se tem sucesso, popula node->children[0]->dataType com o tipo resultante
			if(error) {
				return error;
			}

			identifier = node->symbol->key;
			valueNode = node->children[0];
			literalDataType = valueNode->dataType;

			if(literalDataType!=LIT_INTEGER) {
				printf("Indice vetor pecisa ser inteiro(%d). Eh um %d.\n",LIT_INTEGER,literalDataType);
				return SEMANTIC_ERROR;
			}
			
			error = semantic(node->children[1], scope); //se tem sucesso, popula node->children[0]->dataType com o tipo resultante
			if(error) {
				return error;
			}

			valueNode = node->children[1];
			literalDataType = valueNode->dataType;
			printf("declaracao como: %s, %d\n", identifier,literalDataType);
			declaredSymbol = getSymbolInScopes(scope,programScope,identifier);
			if(!declaredSymbol) {
				printf("nao esta declarado escopo algum\n");
				return SEMANTIC_ERROR;
			}
			
			type = declaredSymbol->type;
			printf("tipo: %d, lit: %d\n", type,literalDataType);
			if ( ! typeCanTakeliteralDataType(type, literalDataType) ) {
				printf("declarou um %d, porem passou uum %d\n", type, literalDataType);
				return SEMANTIC_ERROR;
			}

			if(!declaredSymbol->isArray) {
				printf("Erro: Var nao pode ser indexada\n");
				return SEMANTIC_ERROR;
			}

			if(declaredSymbol->isFunction) {
				printf("Erro: func nao pode ser indexada\n");
				return SEMANTIC_ERROR;
			}

			return SEMANTIC_SUCCESS;

			break;

		case ASTREE_VECTOR_ACCESS:
			printf("semantic ASTREE_VECTOR_ACCESS, %s\n", node->symbol->key);
			error = semantic(node->children[0], scope); //se tem sucesso, popula node->children[0]->dataType com o tipo resultante
			if(error) {
				return error;
			}
			valueNode = node->children[0];
			literalDataType = valueNode->dataType;
			
			if(literalDataType!=LIT_INTEGER) {
				printf("Indice do vetor precisa ser inteiro(%d). Eh um %d.\n",LIT_INTEGER,literalDataType);
				return SEMANTIC_ERROR;
			}

			identifier = node->symbol->key;

			declaredSymbol = getSymbolInScopes(scope,programScope,identifier);
			if(!declaredSymbol) {
				printf("nao esta declarado em escopo algum\n");
				return SEMANTIC_ERROR;
			}
			
			type = declaredSymbol->type;
			node->dataType=type;

			if(!declaredSymbol->isArray) {
				printf("erro: var nao pode ser indexada\n");
				return SEMANTIC_ERROR;
			}

			return SEMANTIC_SUCCESS;

		case ASTREE_READ:
			printf("semantic ASTREE_READ, %s\n", node->symbol->key);
			// semantic(node->children[0]);
			break;

		case ASTREE_PRINT:
			printf("semantic ASTREE_PRINT\n");
			error = semantic(node->children[0], scope);
			if(error) {
				return error;
			}

			return SEMANTIC_SUCCESS;

		case ASTREE_ELEM_LIST:
			printf("semantic ASTREE_ELEM_LIST\n");
			error = semantic(node->children[0], scope);
			if(error) {
				return error;
			}

			error = semantic(node->children[1], scope);
			if(error) {
				return error;
			}

			return SEMANTIC_SUCCESS;

		case ASTREE_RETURN:
			printf("semantic ASTREE_RETURN\n");
			error = semantic(node->children[0], scope);
			if(error) {
				return error;
			}
			symbol_t *returnSymbol = getSymbol(scope, "_return_type_");
			if(!returnSymbol) {
				printf("Nao achou um return\n");
				return SEMANTIC_ERROR;
			}

			printf("esperado = (%d) | recebido (%d)\n", returnSymbol->type, node->children[0]->dataType);
			if(node->children[0]->dataType != returnSymbol->type) {
				printf("Retornou tipo errado\n");
				return SEMANTIC_ERROR;
			}
			return SEMANTIC_SUCCESS;

		case ASTREE_IF_THEN:
			printf("semantic ASTREE_IF_THEN\n");
			error = semantic(node->children[0], scope);
			if(error) {
				return error;
			}

			if (!(node->children[0]->dataType==TYPEBOOL)) {
				printf("Expressao com tipo invalido.\n");
				return SEMANTIC_ERROR;
			}
			node->dataType=node->children[0]->dataType;

			error = semantic(node->children[1], scope);
			if(error) {
				return error;
			}

			return SEMANTIC_SUCCESS;	

			break;

		case ASTREE_IF_THEN_ELSE:
			printf("semantic ASTREE_IF_THEN_ELSE\n");
			error = semantic(node->children[0], scope);
			if(error) {
				return error;
			}

			if (!(node->children[0]->dataType==TYPEBOOL)) {
				printf("Expressao com tipo invalido.\n");
				return SEMANTIC_ERROR;
			}
			node->dataType=node->children[0]->dataType;

			error = semantic(node->children[1], scope);
			if(error) {
				return error;
			}

			error = semantic(node->children[2], scope);
			if(error) {
				return error;
			}

			return SEMANTIC_SUCCESS;

			break;

		case ASTREE_WHILE:
			printf("semantic ASTREE_WHILE\n");
			error = semantic(node->children[0], scope);
			if(error) {
				return error;
			}

			if (node->children[0]->dataType!=TYPEBOOL) {
				printf("Expressao com tipo invalido.\n");
				return SEMANTIC_ERROR;
			}
			node->dataType=node->children[0]->dataType;

			error = semantic(node->children[1], scope);
			if(error) {
				return error;
			}

			return SEMANTIC_SUCCESS;

			break;

		case ASTREE_FOR:
			printf("semantic ASTREE_FOR\n");
			error = semantic(node->children[0], scope);
			if(error) {
				return error;
			}

			error = semantic(node->children[1], scope);
			if(error) {
				return error;
			}

			error = semantic(node->children[2], scope);
			if(error) {
				return error;
			}

			return SEMANTIC_SUCCESS;
			break;

		case ASTREE_INVOKE_FUNC:
			printf("semantic ASTREE_INVOKE_FUNC, %s\n", node->symbol->key);
			
			identifier = node->symbol->key;
			declaredSymbol = getSymbolInScopes(scope, programScope, identifier);
			if(!declaredSymbol) {
				printf("simbolo nao foi declarado.\n");
				return SEMANTIC_ERROR;
			}
			node->dataType = declaredSymbol->type;
			if (!declaredSymbol->isFunction) {
				printf("simbolo nao eh funcao\n");
				return SEMANTIC_ERROR;
			}

			listNode = node->children[0];//arg_list
			argCount = 0;
			while(listNode) { //enquanto tem arg_list
				if(argCount >= declaredSymbol->argCount) {
					printf("Mais args do que o esperado.\n");
					return SEMANTIC_ERROR;
				}
				valueNode = listNode->children[0];//pega symbol
				error = semantic(valueNode, scope);
				if(error) {
					printf("Erro em um argumento\n");
					return error;
				}
				
				literalDataType = valueNode->dataType; //pega tipo do param
				
				symbol_t *param = (symbol_t*)declaredSymbol->parameters[argCount];
				printf("argumento = (%d)| parametro = (%d)",literalDataType,param->dataType);
				if(!typeCanTakeliteralDataType(param->dataType,literalDataType)) {
					printf("Argumento difere do esperado.\n");
					return SEMANTIC_ERROR;
				}
				
				argCount++;
				listNode = listNode->children[1];
			}
			if(argCount < declaredSymbol->argCount) {
				printf("Faltam argumentos.\n");
				return SEMANTIC_ERROR;
			}
			return SEMANTIC_SUCCESS;
			
		case ASTREE_ARG_LIST:
			printf("semantic ASTREE_ARG_LIST\n");
			// semantic(node->children[0]);
			if(node->children[1]) {
				// semantic(node->children[1]);
			}
			break;

		case ASTREE_NOT:
		case ASTREE_AND:
		case ASTREE_OR:
		case ASTREE_GREATER:
		case ASTREE_LESS_EQ:
		case ASTREE_GREATER_EQ:
		case ASTREE_EQ:
		case ASTREE_NEQ:
		case ASTREE_LESS:
		case ASTREE_DIV:
		case ASTREE_MULT:
		case ASTREE_SUB:
		case ASTREE_ADD:
			printf("semantic ASTREE_BINARY OPERATION\n");
			printf("primeiro filho type %d\n",node->children[0]->type);
			error = semantic(node->children[0], scope);
			if (error) {
				return SEMANTIC_ERROR;
			}
			if (! node->children[1] ) {
				node->dataType = TYPEBOOL;	
				return SEMANTIC_SUCCESS;
			}
			error = semantic(node->children[1], scope);
			if (error) {
				return SEMANTIC_ERROR;
			}

			//se chegar aqui tem dois filhos com data type preenchido
			leftSideType = node->children[0]->dataType;
			rightSideType = node->children[1]->dataType;

			coercionType = tryCoercion(leftSideType, rightSideType);
			if(!coercionType) {
				return SEMANTIC_ERROR;
			}
			node->dataType = coercionType;//falta fazer coercion e checks disso

			if(node->type==ASTREE_GREATER ||
				node->type==ASTREE_LESS_EQ ||
				node->type==ASTREE_GREATER_EQ ||
				node->type==ASTREE_EQ ||
				node->type==ASTREE_NEQ ||
				node->type==ASTREE_LESS ||
				node->type==ASTREE_AND ||
				node->type==ASTREE_OR
			) {
				node->dataType = TYPEBOOL;
				return SEMANTIC_SUCCESS;
			}

			if(node->type==ASTREE_DIV ||
				node->type==ASTREE_MULT ||
				node->type==ASTREE_SUB
			) {
				type = node->children[0]->symbol->type;
				if(type == TK_IDENTIFIER) {
					identifier = node->children[0]->symbol->key;
					declaredSymbol = getSymbolInScopes(scope, programScope, identifier);
					if(declaredSymbol->isPointer) {
						printf("Erro: A unica operacao permitida com ponteiros eh soma\n");
						return SEMANTIC_ERROR;
					}
				}
				type = node->children[1]->symbol->type;
				if(type == TK_IDENTIFIER) {
					identifier = node->children[1]->symbol->key;
					declaredSymbol = getSymbolInScopes(scope, programScope, identifier);
					if(declaredSymbol->isPointer) {
						printf("Erro: A unica operacao permitida com ponteiros eh soma\n");
						return SEMANTIC_ERROR;
					}
				}
			}
			return SEMANTIC_SUCCESS;
			
		default:
			printf("semantica UNKNOWN. ast-> %d\n",node->type);
			return SEMANTIC_ERROR;
	}
	return SEMANTIC_SUCCESS;
}
