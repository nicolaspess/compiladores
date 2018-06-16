#pragma once
#include <stdlib.h>
#include <stdio.h>
#include "ast.h"
#include "y.tab.h"

extern void compilar(ASTREE *node);
extern void setOutputFile(FILE *output);
const char * tokenToString(int token);
const char * astTipoToString(int type);