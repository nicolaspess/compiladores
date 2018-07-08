/*

	//Feito por Marcos Praisler de Souza (242239) e João Batista Henz (242251)
*/

%{
#include <stdio.h>
#include <stdlib.h>
#include "genco.h"
//#include "hash.h"
#include "astree.h"
#include "asmgen.h"


void semanticSetTypes() ; //recursiva
void semanticCheckUndeclared(void);
void semanticCheckUsage();
void semanticCheckOperands();





int yylex();
void yyerror(char const *s);

%}


%union{AST* ast; HASH_NODE* symbol;}


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

%token TOKEN_ERROR 290

%type <ast> exp
%type <ast> lcmd
%type <ast> cmd
%type <ast> block
%type <ast> decl
%type <ast> dec
%type <ast> vardec
%type <ast> fundec
%type <ast> lit
%type <ast> litlist
%type <ast> litlist2
%type <ast> vartype
%type <ast> argsdef
%type <ast> atrib
%type <ast> printargs
%type <ast> tailprint
%type <ast> argprint
%type <ast> args
%type <ast> largs



%left OPERATOR_AND OPERATOR_OR '!'
%left '<' '>' OPERATOR_LE OPERATOR_GE OPERATOR_EQ OPERATOR_NE
%left '+' '-'
%left '*' '/'

%start program

%%
program : decl { //astPrint($1,0);
					TAC* code;
					printSource($1);
					//semanticSetTypes($1);
					//semanticCheckUndeclared();
					//semanticCheckUsage($1);
					//semanticCheckOperands($1);
					code = tacReverse(tacGenerator($1));
					tacPrintForward(code);
					//hash_print();
					//asmGenerator("out.s",code);
				}



decl : dec decl { $$ = astCreate(AST_DECL, 0, $1, $2, 0, 0); printf("ola \n");}
	|	{ $$ = 0; }
	;

dec : vardec { $$ = $1; }
	| fundec { $$ = $1; }
	;

vardec : vartype TK_IDENTIFIER '=' lit ';' { $$ = astCreate(AST_VARDEC, $2, $1, $4, 0, 0); }
	| vartype '#' TK_IDENTIFIER '=' lit ';' { $$ = astCreate(AST_PTDEC, $3, $1, $5, 0, 0); }
	| vartype TK_IDENTIFIER '[' lit ']' litlist {$$ = astCreate(AST_VECDEC, $2, $1, $4, $6, 0); }
	;

lit: LIT_INTEGER { $$ = astCreate(AST_SYMBOL, $1, 0, 0, 0, 0); }
	| LIT_REAL { $$ = astCreate(AST_SYMBOL, $1, 0, 0, 0, 0); }
	| LIT_CHAR { $$ = astCreate(AST_SYMBOL, $1, 0, 0, 0, 0); }
	| LIT_STRING {$$ = astCreate(AST_SYMBOL, $1, 0, 0, 0, 0); }
	;

litlist: ':' litlist2 { $$ = astCreate(AST_LITLIST, 0, $2, 0, 0, 0); }
	| {$$ = 0;}
	;

litlist2: lit litlist2 { $$ = astCreate(AST_LITLIST2, 0, $1, $2, 0, 0); }
	| ';' {$$ = 0;}
	;



fundec : vartype TK_IDENTIFIER '(' argsdef ')' cmd { $$ = astCreate(AST_FUNDEC,$2,$1,0,$4,$6); }
	;

args: exp largs {$$ = astCreate(AST_ARGS, 0, $1, $2, 0, 0);}
	| {$$ = 0;}
	;

largs: ',' exp largs {$$ = astCreate(AST_ARGS, 0, $2, $3, 0, 0);}
	| {$$ = 0;}
	;


argsdef: vartype TK_IDENTIFIER ',' argsdef { $$ = astCreate(AST_ARGSDEF,$2,$1,$4,0,0); }
	| vartype TK_IDENTIFIER argsdef { $$ = astCreate(AST_ARGSDEF,$2,$1,$3,0,0); }
	|	{ $$ = 0; }
	;


vartype: KW_CHAR  { $$ = astCreate(AST_KWCHAR,0,0,0,0,0); }
	| KW_INT { $$ = astCreate(AST_KWINT,0,0,0,0,0); }
	| KW_FLOAT { $$ = astCreate(AST_KWFLOAT, 0,0,0,0,0); }
	;



block: '(' lcmd ')'  { $$ = astCreate(AST_BLOCK,0,$2,0,0,0); }
	;


cmd : atrib { $$ = $1; }
	| KW_PRINT printargs {$$ = astCreate(AST_KWPRINT, 0, $2, 0, 0, 0);}
	| KW_READ TK_IDENTIFIER {$$ = astCreate(AST_KWREAD, $2, 0, 0, 0, 0);}
	| KW_WHILE '(' exp ')' cmd {$$ = astCreate(AST_KWWHILE, 0, $3, $5, 0, 0);}
	| KW_IF '(' exp ')' KW_THEN cmd KW_ELSE cmd {$$ = astCreate(AST_KWIF, 0, $3, $6, $8, 0);}
	| KW_IF '(' exp ')' KW_THEN cmd {$$ = astCreate(AST_KWIF, 0, $3, $6, 0, 0);}
	| KW_RETURN exp {$$ = astCreate(AST_KWRETURN, 0, $2, 0, 0, 0);}
	| block { $$ = $1;}
	| {$$ = 0;}
	;

printargs: argprint tailprint					{ $$ = astCreate(AST_PRINTARGS,0,$1,$2,0,0); }
	;

tailprint: argprint tailprint			{ $$ = astCreate(AST_PRINTARGS,0,$1,$2,0,0); }
	|										{ $$ = 0; }
	;

argprint: exp								{ $$ = $1; }
	| LIT_STRING						{ $$ = astCreate(AST_SYMBOL,$1,0,0,0,0); }
	;


atrib : TK_IDENTIFIER '=' exp { $$ = astCreate(AST_ASSIGN, $1, $3, 0, 0, 0); }
	| '#' TK_IDENTIFIER '=' exp { $$ = astCreate(AST_ASSPT, $2, $4, 0, 0, 0); }
	| '&' TK_IDENTIFIER '=' exp { $$ = astCreate(AST_ASSPT2, $2, $4, 0, 0, 0); }
	| TK_IDENTIFIER '[' exp ']' '=' exp { $$ = astCreate(AST_VASSIGN, $1, $3, $6, 0, 0); }
	;

exp : '(' exp ')' { $$ = astCreate(AST_EXP,0,$2,0,0,0); }
    | TK_IDENTIFIER { $$ = astCreate(AST_SYMBOL,$1,0,0,0,0); }
    | TK_IDENTIFIER '[' exp ']' { $$ = astCreate(AST_VACCESS,$1,$3,0,0,0); }
    | TK_IDENTIFIER '(' args ')' { $$ = astCreate(AST_FUNCALL,$1,$3,0,0,0); }
    | LIT_INTEGER { $$ = astCreate(AST_SYMBOL,$1,0,0,0,0); }
    | LIT_STRING { $$ = astCreate(AST_SYMBOL,$1,0,0,0,0); }
    | LIT_CHAR { $$ = astCreate(AST_SYMBOL,$1,0,0,0,0); }
    | LIT_REAL { $$ = astCreate(AST_SYMBOL,$1,0,0,0,0); }
	| exp OPERATOR_LE exp { $$ = astCreate(AST_LE,0,$1,$3,0,0); }
	| exp OPERATOR_GE exp { $$ = astCreate(AST_GE,0,$1,$3,0,0); }
	| exp OPERATOR_EQ exp { $$ = astCreate(AST_EQ,0,$1,$3,0,0); }
	| exp OPERATOR_NE exp { $$ = astCreate(AST_NE,0,$1,$3,0,0); }
	| exp OPERATOR_AND exp { $$ = astCreate(AST_AND,0,$1,$3,0,0); }
	| exp OPERATOR_OR exp { $$ = astCreate(AST_OR,0,$1,$3,0,0); }
	| exp '*' exp { $$ = astCreate(AST_MUL,0,$1,$3,0,0); }
	| exp '/' exp { $$ = astCreate(AST_DIV,0,$1,$3,0,0); }
	| exp '+' exp { $$ = astCreate(AST_ADD,0,$1,$3,0,0); }
	| exp '-' exp { $$ = astCreate(AST_SUB,0,$1,$3,0,0); }
	| exp '>' exp { $$ = astCreate(AST_GT,0,$1,$3,0,0); }
	| exp '<' exp { $$ = astCreate(AST_LS,0,$1,$3,0,0); }
	| exp '!' exp { $$ = astCreate(AST_NOT, 0,$1,$3,0,0); }
	;



block : '{' lcmd '}' { $$ = astCreate(AST_BLOCK,0,$2,0,0,0); }
	;

lcmd : cmd ';' lcmd    {$$ = astCreate(AST_LCMD,0,$1,$3,0,0);}
	| cmd {$$ = $1;}
	;


%%
int getLineNumber();


void yyerror (char const *s) {
	fprintf (stderr, "Line %d: %s\n",getLineNumber(), s);
	exit(3);
}
