%{
#include <stdio.h>
#include <stdlib.h>
extern int getLineNumber();
%}

%tok KW_CHAR       256
%tok KW_INT        257
%tok KW_FLOAT      258
%tok KW_IF         259
%tok KW_THEN       260
%tok KW_ELSE       261
%tok KW_WHILE      262
%tok KW_FOR        263
%tok KW_READ       264
%tok KW_PRINT      265
%tok KW_RETURN     266

%tok OPERATOR_LE   270
%tok OPERATOR_GE   271
%tok OPERATOR_EQ   272
%tok OPERATOR_NE   273
%tok OPERATOR_AND  274
%tok OPERATOR_OR   275

%tok TK_IDENTIFIER 280
%tok LIT_INTEGER   281
%tok LIT_REAL      282
%tok LIT_CHAR      283
%tok LIT_STRING    284

%tok TOKEN_ERROR   290

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
            | '#' TK_IDENTIFIER ';'
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

comando : TK_IDENTIFIER '=' expressao
        | //continuar
        ;

expressao : TK_IDENTIFIER 
          | //continuar		
          ;	   
			   
			   
controleFluxo : KW_IF '('exp')' comando
              | KW_IF '('exp')' comando KW_ELSE comando
              | KW_WHILE '('exp ')' comando
              | KW_FOR //continuar
	          ;

	
%%
int yyerror(char * err)
{
	printf("\nErro de sintaxe! Linha: %d \n", getLineNumber());
	exit(3);
}