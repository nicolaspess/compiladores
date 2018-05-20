%{
#include <stdio.h>
#include <stdlib.h>
#include "ast.h"
#include "semantic.h"
extern int getLineNumber();

ASTREE *root;
int erro;
%}

%union{ 
    hash_Node *symbol;
    ASTREE *ast;
}


%token KW_CHAR       256
%token KW_INT        257
%token KW_FLOAT      259
%token KW_IF         261
%token KW_THEN       262
%token KW_ELSE       263
%token KW_WHILE      264
%token KW_FOR        265
%token KW_READ       266
%token KW_PRINT      267
%token KW_RETURN     268
%token KW_TO         269

%token OPERATOR_LE   270
%token OPERATOR_GE   271
%token OPERATOR_EQ   272
%token OPERATOR_NE   273
%token OPERATOR_AND  274
%token OPERATOR_OR   275

%token <symbol> TK_IDENTIFIER 280
%token <symbol> LIT_INTEGER   281
%token <symbol> LIT_REAL      282
%token <symbol> LIT_CHAR      283
%token <symbol> LIT_STRING    284

%token TOKEN_ERROR   290

%type <ast>programa
%type <ast>listaDeDeclaracoes
%type <ast>declaracoes
%type <ast>tipo
%type <ast>literal
%type <ast>inicializacao
%type <ast>inicializacao2
%type <ast>listaDeParametros
%type <ast>fimDeParametros
%type <ast>parametro
%type <ast>bloco
%type <ast>blocoDeComandos
%type <ast>fimDeComando
%type <ast>comando
%type <ast>controleFluxo
%type <ast>atribuicao
%type <ast>argprint
%type <ast>argprint2
%type <ast>expressao
%type <ast>listaDeArgumentos
%type <ast>fimDeArgumentos
%type <ast>argfunc

%left '+' '-' '*' '/' '%' '!' '<' '>'
%left OPERATOR_LE OPERATOR_GE OPERATOR_NE OPERATOR_AND OPERATOR_OR OPERATOR_EQ

%start programa

%%
programa : listaDeDeclaracoes { root = $$; astPrint(root, 0); erro = verificaSemantica(root); printSource($1); }
         ;

listaDeDeclaracoes : declaracoes listaDeDeclaracoes { $$ = astCreate(ASTREE_DFNL, 0, $1, $2, 0, 0); }
	                 | { $$ = 0; }
                   ;

declaracoes : tipo TK_IDENTIFIER '=' literal ';'                   { $$ = astCreate(ASTREE_VARINI, $2, $1, $4, 0, 0); }
            | tipo '#' TK_IDENTIFIER ';'                           { $$ = astCreate(ASTREE_VARPT, $3, $1, 0, 0, 0); }
            | tipo '#' TK_IDENTIFIER '=' literal ';'               { $$ = astCreate(ASTREE_VARPTINI, $3, $1, $5, 0, 0); }
            | tipo TK_IDENTIFIER '[' literal ']' inicializacao ';' { $$ = astCreate(ASTREE_ARRINI, $2, $1, $4, $6, 0); }
            | tipo TK_IDENTIFIER '(' listaDeParametros ')' bloco   { $$ = astCreate(ASTREE_FUNDEF, $2, $1, $4, $6, 0); }
            ;

tipo : KW_CHAR  { $$ = astCreate(ASTREE_CHAR, 0, 0, 0, 0, 0); }
     | KW_INT   { $$ = astCreate(ASTREE_INT, 0, 0, 0, 0, 0); }
     | KW_FLOAT { $$ = astCreate(ASTREE_FLOAT, 0, 0, 0, 0, 0); }
     ;

literal : LIT_CHAR     { $$ = astCreate(ASTREE_SYMBOL, $1, 0, 0, 0, 0); }
	      | LIT_INTEGER  { $$ = astCreate(ASTREE_SYMBOL, $1, 0, 0, 0, 0); }
	      | LIT_REAL     { $$ = astCreate(ASTREE_SYMBOL, $1, 0, 0, 0, 0); }
	      | LIT_STRING   { $$ = astCreate(ASTREE_SYMBOL, $1, 0, 0, 0, 0); }
	      ;		

inicializacao : ':' inicializacao2        { $$ = astCreate(ASTREE_INTL, 0, $2, 0, 0, 0); }
              | { $$ = 0; }
              ;
			  
inicializacao2 : literal inicializacao2   { $$ = astCreate(ASTREE_INTL2, 0, $1, $2, 0, 0); }
               | { $$ = 0; }
               ;

listaDeParametros : parametro fimDeParametros  { $$ = astCreate(ASTREE_PARL, 0, $1, $2, 0, 0); }                
                ;

fimDeParametros : ',' parametro fimDeParametros { $$ = astCreate(ASTREE_FPARL, 0, $2, $3, 0, 0); }
                | { $$ = 0; }
                ; 

parametro : tipo TK_IDENTIFIER  { $$ = astCreate(ASTREE_PARAM, $2, $1, 0, 0, 0); }
          | { $$ = 0; }
          ;

bloco : '{' blocoDeComandos '}' { $$ = astCreate(ASTREE_BRACES, 0, $2, 0, 0, 0); }
      ;

blocoDeComandos : comando fimDeComando { $$ = astCreate(ASTREE_CMDL, 0, $1, $2, 0, 0); }
                ;

fimDeComando : ';' comando fimDeComando { $$ = astCreate(ASTREE_FIMCMDL, 0, $2, $3, 0, 0); }
             | { $$ = 0; }
             ;

comando : bloco                   { $$ = $1 ;}
        | KW_READ TK_IDENTIFIER   { $$ = astCreate(ASTREE_READ, $2, 0, 0, 0, 0); }
        | KW_PRINT argprint       { $$ = astCreate(ASTREE_PRINT, 0, $2, 0, 0, 0); }
        | KW_RETURN expressao     { $$ = astCreate(ASTREE_RETURN, 0, $2, 0, 0, 0); }
        | atribuicao              { $$ = $1 ;}
        | controleFluxo           { $$ = $1 ;}
        | { $$ = 0; }
        ;

controleFluxo : KW_IF '(' expressao ')' KW_THEN comando                   { $$ = astCreate(ASTREE_IF, 0, $3, $6, 0, 0); }
              | KW_WHILE '(' expressao ')' comando                       { $$ = astCreate(ASTREE_WHILE, 0, $3, $5, 0, 0); }
              | KW_FOR '(' atribuicao KW_TO expressao ')' comando       { $$ = astCreate(ASTREE_FOR, 0, $3, $5, $7, 0); }
              | KW_IF '(' expressao ')' KW_THEN comando KW_ELSE comando { $$ = astCreate(ASTREE_ELSE, 0, $3, $6, $8, 0); }         
	      ;

atribuicao : TK_IDENTIFIER '=' expressao                    { $$ = astCreate(ASTREE_ATR, $1, $3, 0, 0, 0); }
           | '#' TK_IDENTIFIER '=' expressao                { $$ = astCreate(ASTREE_ASSPT1, $2, $4, 0, 0, 0); }
           | '&' TK_IDENTIFIER '=' expressao                { $$ = astCreate(ASTREE_ASSPT2, $2, $4, 0, 0, 0); }
           | TK_IDENTIFIER '[' expressao ']' '=' expressao  { $$ = astCreate(ASTREE_ARRAY_WRITE, $1, $3, $6, 0, 0); }
           ;

argprint : expressao argprint2  { $$ = astCreate(ASTREE_PRINTARG, 0, $1, $2, 0, 0); }
         ;

argprint2: expressao argprint2  { $$ = astCreate(ASTREE_PRINTARG, 0, $1, $2, 0, 0); }
         | { $$ = 0; }
         ;

expressao : TK_IDENTIFIER                           { $$ = astCreate(ASTREE_SYMBOL, $1, 0, 0, 0, 0); }
          | '#' TK_IDENTIFIER                       { $$ = astCreate(ASTREE_PT1, $2, 0, 0, 0, 0); }
          | '&' TK_IDENTIFIER                       { $$ = astCreate(ASTREE_PT2, $2, 0, 0, 0, 0); }
          | TK_IDENTIFIER '[' expressao ']'         { $$ = astCreate(ASTREE_ARRAY_READ, $1, $3, 0, 0, 0); }
          | '(' expressao ')'                       { $$ = astCreate(ASTREE_PARENTHESIS, 0, $2, 0, 0, 0); }
          | literal                                 { $$ = $1 ;}
          | expressao '+' expressao                 { $$ = astCreate(ASTREE_ADD, 0, $1, $3, 0, 0); }
          | expressao '-' expressao                 { $$ = astCreate(ASTREE_SUB, 0, $1, $3, 0, 0); }
          | expressao '*' expressao                 { $$ = astCreate(ASTREE_MUL, 0, $1, $3, 0, 0); }
          | expressao '/' expressao                 { $$ = astCreate(ASTREE_DIV, 0, $1, $3, 0, 0); }
          | expressao '%' expressao                 { $$ = astCreate(ASTREE_MOD, 0, $1, $3, 0, 0); }
          | expressao '>' expressao                 { $$ = astCreate(ASTREE_G, 0, $1, $3, 0, 0); }
          | expressao '<' expressao                 { $$ = astCreate(ASTREE_L, 0, $1, $3, 0, 0); }
          | '!' expressao                           { $$ = astCreate(ASTREE_NOT, 0, $2, 0, 0, 0); }
          | expressao OPERATOR_LE expressao         { $$ = astCreate(ASTREE_LE, 0, $1, $3, 0, 0); }
          | expressao OPERATOR_GE expressao         { $$ = astCreate(ASTREE_GE, 0, $1, $3, 0, 0); }
          | expressao OPERATOR_EQ expressao         { $$ = astCreate(ASTREE_EQ, 0, $1, $3, 0, 0); }
          | expressao OPERATOR_NE expressao         { $$ = astCreate(ASTREE_NE, 0, $1, $3, 0, 0); }
          | expressao OPERATOR_AND expressao        { $$ = astCreate(ASTREE_AND, 0, $1, $3, 0, 0); }
          | expressao OPERATOR_OR expressao         { $$ = astCreate(ASTREE_OR, 0, $1, $3, 0, 0); }
          | TK_IDENTIFIER '(' listaDeArgumentos ')' { $$ = astCreate(ASTREE_FUNCALL, $1, $3, 0, 0, 0); }
          ;

listaDeArgumentos : argfunc fimDeArgumentos     { $$ = astCreate(ASTREE_ARGFUN, 0, $1, $2, 0, 0);}
                  ;

fimDeArgumentos : ',' argfunc fimDeArgumentos   { $$ = astCreate(ASTREE_ARGFUNFIM, 0, $2, $3, 0, 0); }
                | { $$ = 0; }
                ;

argfunc: expressao { $$ = $1 ;}
       | { $$ = 0; }
       ;
%%


ASTREE* get_rootAst()
{
	return root;
}

void resultadoSemantica()
{	
	if(erro > 0)
	{
		fprintf(stderr, "%d erros semanticos.\n", erro);
		exit(4);
	}
}

int yyerror(char * err)
{
	printf("\nErro de sintaxe! Linha: %d \n", getLineNumber());
	exit(3);
}
