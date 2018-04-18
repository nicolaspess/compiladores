%{
#include <stdio.h>
#include <stdlib.h>
extern int getLineNumber();
%}

%union {
  hash_Node *symbol;
  AST *ast;
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

%token TK_IDENTIFIER 280
%token LIT_INTEGER   281
%token LIT_REAL      282
%token LIT_CHAR      283
%token LIT_STRING    284

%token TOKEN_ERROR   290

%type<ast> expressao
%type<ast> comando


%left '<' '>'  
%left '!' OPERATOR_LE OPERATOR_GE OPERATOR_EQ OPERATOR_NE OPERATOR_AND OPERATOR_OR
%left '+' '-'
%left '*' '/'

%%
programa : listaDeDeclaracoes
         ;
		 
listaDeDeclaracoes : declaracoes listaDeDeclaracoes
	           |
                   ;

declaracoes : tipo TK_IDENTIFIER '=' literal ';'
            | tipo TK_IDENTIFIER '[' LIT_INTEGER ']' inicializacao ';'
            | tipo '#' TK_IDENTIFIER ';'
            | tipo '#' TK_IDENTIFIER '=' literal ';'
            | tipo TK_IDENTIFIER '(' listaDeParametros ')' bloco			
			;	   

inicializacao : ':' inicializacao2 
              |
              ;
			  
inicializacao2 : literal inicializacao2
               |
               ;	

tipo : KW_CHAR
     | KW_INT
     | KW_FLOAT
     ;

literal : LIT_CHAR
	| LIT_INTEGER
	| LIT_REAL
	| LIT_STRING
	;		
	
listaDeParametros : parametro fimDeParametros
                | 
                ;

fimDeParametros : ',' parametro fimDeParametros 
                |
                ;

parametro : tipo TK_IDENTIFIER 
          | 
          ;	
	
bloco : '{' blocoDeComandos '}'
      ;

blocoDeComandos : comando fimDeComando
                ;

fimDeComando : ';' comando fimDeComando 
             |
             ;

comando : atribuicao
        | controleFluxo
        | KW_PRINT argprint
        | KW_READ TK_IDENTIFIER
        | bloco
        | KW_RETURN expressao
        |
        ;

atribuicao : TK_IDENTIFIER '=' expressao                    { $$ = astCreate(AST_ASS, $1, $3, 0, 0, 0); }
           | TK_IDENTIFIER '=' '#' expressao
           | TK_IDENTIFIER '=' '&' expressao
           | TK_IDENTIFIER '[' expressao ']' '=' expressao
	   ;

argprint : expressao argprint2
         ;

argprint2: expressao argprint2
	 |
	 ;

listaDeArgumentos : argfunc fimDeArgumentos
                  | 
                  ;

fimDeArgumentos : ',' argfunc fimDeArgumentos 
                |
                ;

argfunc: expressao
       |
       ;
 
expressao : TK_IDENTIFIER                           { $$ = astCreate(AST_SYMBOL, $1, 0, 0, 0, 0); }
          | '#' TK_IDENTIFIER
          | '&' TK_IDENTIFIER
          | TK_IDENTIFIER '[' expressao ']'
          | TK_IDENTIFIER '(' listaDeArgumentos ')'
          | '(' expressao ')' 
          | expressao OPERATOR_LE expressao
	        | expressao OPERATOR_GE expressao
	        | expressao OPERATOR_EQ expressao
	        | expressao OPERATOR_NE expressao
	        | expressao OPERATOR_AND expressao
	        | expressao OPERATOR_OR expressao
    	    | expressao '>' expressao                 { $$ = astCreate(AST_BIGGER, 0, $1, $3, 0, 0); }
    	    | expressao '<' expressao                 { $$ = astCreate(AST_LESS, 0, $1, $3, 0, 0); }
    	    | expressao '+' expressao                 { $$ = astCreate(AST_ADD, 0, $1, $3, 0, 0); }
    	    | expressao '-' expressao                 { $$ = astCreate(AST_SUB, 0, $1, $3, 0, 0); }
    	    | expressao '/' expressao                 { $$ = astCreate(AST_DIV, 0, $1, $3, 0, 0); } 
    	    | expressao '*' expressao                 { $$ = astCreate(AST_MUL, 0, $1, $3, 0, 0); }
    	    | expressao '%' expressao                 { $$ = astCreate(AST_MOD, 0, $1, $3, 0, 0); }
    	    | '!' expressao 
          | LIT_CHAR                                { $$ = astCreate(AST_SYMBOL, $1, 0, 0, 0, 0); }
          | LIT_INTEGER                             { $$ = astCreate(AST_SYMBOL, $1, 0, 0, 0, 0); }
          | LIT_STRING                              { $$ = astCreate(AST_SYMBOL, $1, 0, 0, 0, 0); }
          ;
			   
controleFluxo : KW_IF '('expressao')' KW_THEN comando                 { $$ = astCreate(AST_IFTE, 0, $3, $5, 0, 0); }
              | KW_IF '('expressao')' KW_THEN comando KW_ELSE comando { $$ = astCreate(AST_IFTE, 0, $3, $5, $7, 0); }
              | KW_WHILE '('expressao ')' comando                     { $$ = astCreate(AST_WHILE, 0, $3, $5, 0, 0); }
              | KW_FOR '(' atribuicao KW_TO expressao ')' comando     { $$ = astCreate(AST_FOR, 0, $3, $5, $7, 0); }
	          ;

	
%%
int yyerror(char * err)
{
	printf("\nErro de sintaxe! Linha: %d \n", getLineNumber());
	exit(3);
}
