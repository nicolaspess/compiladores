#ifndef SYMBOLS_H_
#define SYMBOLS_H_
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "tabelaHash.h"

#define KEY_MAX_LENGTH (256)
#define KEY_PREFIX ("somekey")
#define KEY_COUNT (1024*1024)
#define MAX_PARAMS_COUNT 4

typedef struct symbol_s
{
    char key[KEY_MAX_LENGTH];
    int type;
    int dataType;
    int line;
    int intValue;
    double doubleValue;
    char charValue;
    char stringValue[KEY_MAX_LENGTH];

    int isArray;
	int arrayCapacity;

	int isPointer;

	int isFunction;
    int argCount;
	void* parameters[MAX_PARAMS_COUNT]; //symbols
    map_t scope;
} symbol_t;

map_t scannedSymbolsMap;
map_t programScope;

char strings_list[100][100]; //numero de strings maximo no programa x tamanho maximo das strings

static int string_count = 0;

void printDebugSymbol(symbol_t* symbol);
void printLabelFile(symbol_t* symbol, FILE *fout);
void printTempFile(symbol_t* symbol, FILE *fout);
void printStringFile(symbol_t* symbol, FILE *fout);
void printSymbols(map_t *map);
extern int initMaps();
extern map_t newMap();
extern symbol_t* addSymbol(map_t *map, int type, char* key, int line);
extern symbol_t* getSymbol(map_t *map, char *key);

symbol_t* makeTemp(void);
symbol_t* makeLabel(void);

#endif