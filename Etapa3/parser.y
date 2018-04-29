%{
#include <stdio.h>
#include <stdlib.h>
extern int getLineNumber();
%}

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


%type <ast> listaDeDeclaracoes
%type <ast> declaracoes
%type <ast> tipo
%type <ast> literal
%type <ast> inicializacao
%type <ast> inicializacao2
%type <ast> listaDeParametros
%type <ast> fimDeParametros
%type <ast> parametros
%type <ast> bloco
%type <ast> blocoDeComandos
%type <ast> fimDeComando
%type <ast> comando
%type <ast> controleFluxo
%type <ast> atribuicao
%type <ast> argprint
%type <ast> argprint2
%type <ast> expressao
%type <ast> listaDeArgumentos
%type <ast> fimDeArgumentos
%type <ast> argfunc

%left '+' '-' '*' '/' '%' '!' '<' '>'
%left OPERATOR_LE OPERATOR_GE OPERATOR_NE OPERATOR_AND OPERATOR_OR OPERATOR_EQ

%start programa

%%
programa : listaDeDeclaracoes { astPrint($1, 0);  }
         ;
		 
listaDeDeclaracoes : declaracoes listaDeDeclaracoes { $$ = astCreate(AST_LDEC, 0, $1, $2, 0, 0); }
	                 | { $$ = 0; }
                   ;

declaracoes : tipo TK_IDENTIFIER '=' literal ';'                        { $$ = astCreate(AST_DEC, $2, $1, $4, 0, 0); }
            | tipo '#' TK_IDENTIFIER ';'                                { $$ = astCreate(AST_DECPT, $3, $1, 0, 0, 0); }
            | tipo '#' TK_IDENTIFIER '=' literal ';'                    { $$ = astCreate(AST_DECPTASS, $3, $1, $5, 0, 0); }
            | tipo TK_IDENTIFIER '[' lit ']' inicializacao ';'          { $$ = astCreate(AST_DECARR, $2, $1, $4, $6, 0); }
            | tipo TK_IDENTIFIER '(' listaDeParametros ')' bloco        { $$ = astCreate(AST_DECFUN, $2, $1, $4, $6, 0); }
            ;

lit: LIT_INTEGER { $$ = astCreate(AST_SYMBOL, $1, 0, 0, 0, 0); }
   ;

tipo : KW_CHAR  { $$ = astCreate(AST_KWCHAR, 0, 0, 0, 0, 0); }
     | KW_INT   { $$ = astCreate(AST_KWINT, 0, 0, 0, 0, 0); }
     | KW_FLOAT { $$ = astCreate(AST_KWFLOAT, 0, 0, 0, 0, 0); }
     ;

literal : LIT_CHAR     { $$ = astCreate(AST_SYMBOL, $1, 0, 0, 0, 0); }
	      | LIT_INTEGER  { $$ = astCreate(AST_SYMBOL, $1, 0, 0, 0, 0); }
	      | LIT_REAL     { $$ = astCreate(AST_SYMBOL, $1, 0, 0, 0, 0); }
	      | LIT_STRING   { $$ = astCreate(AST_SYMBOL, $1, 0, 0, 0, 0); }
	      ;

inicializacao : ':' inicializacao2        { $$ = astCreate(AST_INI, 0, $1, 0, 0, 0); }
              | { $$ = 0; }
              ;
			  
inicializacao2 : literal inicializacao2   { $$ = astCreate(AST_INI2, 0, $1, $2, 0, 0); }
               | { $$ = 0; }
               ;

listaDeParametros : parametro fimDeParametros  { $$ = astCreate(AST_LPARAM, 0, $1, $2, 0, 0); }                
                ;

fimDeParametros : ',' parametro fimDeParametros { $$ = astCreate(AST_FPARAM, 0, $1, $2, 0, 0); }
                | { $$ = 0; }
                ;

parametro : tipo TK_IDENTIFIER  { $$ = astCreate(AST_PARAM, $2, $1, 0, 0, 0); }
          | { $$ = 0; }
          ;

bloco : '{' blocoDeComandos '}' { $$ = astCreate(AST_BLOCO, 0, $2, 0, 0, 0); }
      ;

blocoDeComandos : comando fimDeComando { $$ = astCreate(AST_BLOCOCMD, 0, $1, $2, 0, 0); }
                ;

fimDeComando : ';' comando fimDeComando { $$ = astCreate(AST_FIMCMD, 0, $2, $3, 0, 0); }
             | { $$ = 0; }
             ;

comando : bloco                   { $$ = $1 }
        | KW_READ TK_IDENTIFIER   { $$ = astCreate(AST_KWREAD, $2, 0, 0, 0, 0); }
        | KW_PRINT argprint       { $$ = astCreate(AST_KWPRINT, 0, $2, 0, 0, 0); }
        | KW_RETURN expressao     { $$ = astCreate(AST_KWRETURN, 0, $2, 0, 0, 0); }
        | atribuicao              { $$ = $1 }
        | controleFluxo           { $$ = $1 }
        | { $$ = 0; }
        ;

controleFluxo : KW_IF '('expressao')' KW_THEN comando                   { $$ = astCreate(AST_IFT, 0, $3, $5, 0, 0); }
              | KW_WHILE '('expressao ')' comando                       { $$ = astCreate(AST_WHILE, 0, $3, $5, 0, 0); }
              | KW_FOR '(' atribuicao KW_TO expressao ')' comando       { $$ = astCreate(AST_FOR, 0, $3, $5, $7, 0); }
              | KW_IF '('expressao')' KW_THEN comando KW_ELSE comando 	{ $$ = astCreate(AST_IFTE, 0, $3, $5, $7, 0); }         
	      ;

atribuicao : TK_IDENTIFIER '=' expressao                    { $$ = astCreate(AST_ASS, $1, $3, 0, 0, 0); }
           | TK_IDENTIFIER '=' '#' expressao                { $$ = astCreate(AST_ASSPT1, $1, $4, 0, 0, 0); }
           | TK_IDENTIFIER '=' '&' expressao                { $$ = astCreate(AST_ASSPT2, $1, $4, 0, 0, 0); }
           | TK_IDENTIFIER '[' expressao ']' '=' expressao  { $$ = astCreate(AST_ASSARR, $1, $3, $6, 0, 0); }
           ;

argprint : expressao argprint2  { $$ = astCreate(AST_PRINTARG, 0, $1, $2, 0, 0); }
         ;

argprint2: expressao argprint2  { $$ = astCreate(AST_PRINTARG, 0, $1, $2, 0, 0); }
         |
         ;

expressao : TK_IDENTIFIER                           { $$ = astCreate(AST_SYMBOL, $1, 0, 0, 0, 0); }
          | '#' TK_IDENTIFIER                       { $$ = astCreate(AST_PT1, $2, 0, 0, 0, 0); }
          | '&' TK_IDENTIFIER                       { $$ = astCreate(AST_PT2, $2, 0, 0, 0, 0); }
          | TK_IDENTIFIER '[' expressao ']'         { $$ = astCreate(AST_ARR, $1, $3, 0, 0, 0); }
          | '(' expressao ')'                       { $$ = astCreate(AST_EXP, 0, $2, 0, 0, 0); }
          | literal                                 { $$ = $1 }
          | expressao '+' expressao                 { $$ = astCreate(AST_ADD, 0, $1, $3, 0, 0); }
          | expressao '-' expressao                 { $$ = astCreate(AST_SUB, 0, $1, $3, 0, 0); }
          | expressao '*' expressao                 { $$ = astCreate(AST_MUL, 0, $1, $3, 0, 0); }
          | expressao '/' expressao                 { $$ = astCreate(AST_DIV, 0, $1, $3, 0, 0); }
          | expressao '%' expressao                 { $$ = astCreate(AST_MOD, 0, $1, $3, 0, 0); }
          | expressao '>' expressao                 { $$ = astCreate(AST_BIGGER, 0, $1, $3, 0, 0); }
          | expressao '<' expressao                 { $$ = astCreate(AST_LESS, 0, $1, $3, 0, 0); }
          | '!' expressao                           { $$ = astCreate(AST_NOT, 0, $2, 0, 0, 0); }
          | expressao OPERATOR_LE expressao         { $$ = astCreate(AST_LE, 0, $1, $3, 0, 0); }
          | expressao OPERATOR_GE expressao         { $$ = astCreate(AST_GE, 0, $1, $3, 0, 0); }
          | expressao OPERATOR_EQ expressao         { $$ = astCreate(AST_EQ, 0, $1, $3, 0, 0); }
          | expressao OPERATOR_NE expressao         { $$ = astCreate(AST_NE, 0, $1, $3, 0, 0); }
          | expressao OPERATOR_AND expressao        { $$ = astCreate(AST_AND, 0, $1, $3, 0, 0); }
          | expressao OPERATOR_OR expressao         { $$ = astCreate(AST_OR, 0, $1, $3, 0, 0); }
          | TK_IDENTIFIER '(' listaDeArgumentos ')' { $$ = astCreate(AST_FUNCALL, $1, $3, 0, 0, 0); }
          ;

listaDeArgumentos : argfunc fimDeArgumentos     { $$ = astCreate(AST_ARGFUN, 0, $1, $2, 0, 0);}
                  ;

fimDeArgumentos : ',' argfunc fimDeArgumentos   { $$ = astCreate(AST_ARGFUNFIM, 0, $2, $3, 0, 0); }
                | { $$ = 0; }
                ;

argfunc: expressao { $$ = $1 }
       | { $$ = 0; }
       ;

%%


int yyerror(char * err)
{
	printf("\nErro de sintaxe! Linha: %d \n", getLineNumber());
	exit(3);
}
