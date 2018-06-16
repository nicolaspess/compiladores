%{
#include "ast.h"
#include "compila.h"
#include<stdio.h>
#include<stdlib.h>
extern int getLineNumber(void);
int yyerror(char const *s);
int yylex();
%}

%union {
	symbol_t *symbol;
	char *charValue;
	struct ASTREE_s *node;
	int token;
}

%token KW_CHAR       256
%token KW_INT        257
%token KW_FLOAT      259
%token KW_IF         261
%token KW_THEN       262
%token KW_ELSE       263
%token KW_WHILE      264
%token KW_FOR        265
%token KW_TO         269
%token KW_READ       266
%token KW_RETURN     267
%token KW_PRINT      268

%token OPERATOR_LE   270
%token OPERATOR_GE   271
%token OPERATOR_EQ   272
%token OPERATOR_NE   273
%token OPERATOR_AND  274
%token OPERATOR_OR   275

%error-verbose
%token <symbol>TK_IDENTIFIER 280
%token <symbol>LIT_INTEGER   281
%token <symbol>LIT_REAL      282
%token <symbol>LIT_CHAR      285
%token <symbol>LIT_STRING    286
%token TYPEBOOL    287
%token TOKEN_ERROR   290

%token DT_CHAR 291
%token DT_INTEGER 292
%token DT_FLOAT 293

%type <node> program
%type <node> dec
%type <node> decl
%type <node> Value
%type <node> Valuel
%type <node> block
%type <node> cmdl
%type <node> cmd
%type <node> expr
%type <node> Param
%type <node> Paraml
%type <node> Eleml
%type <node> Elem
%type <node> Argl

%type <token> Type

%left OPERATOR_OR
%left OPERATOR_AND
%left '!' OPERATOR_EQ OPERATOR_NE
%left '>' OPERATOR_GE
%left '<' OPERATOR_LE
%left '+' '-'
%left '*' '/'
%right '['']'
%right '('')'

%%

program:
	decl { $$ = astCreate(ASTREE_PROGRAM,0,$1,0,0,0); astSetRoot($$); compilar($$); }
	;

decl:
	dec decl { 
		if($1 != 0) {
			$$ = astCreate(ASTREE_DEC_LIST,0,$1,$2,0,0);
			} else {
				$$ = $2;
			}
	}
	| {$$ = 0;}
	;

dec:
	Type TK_IDENTIFIER '=' Value ';' { $$ = astCreate(ASTREE_DEC_VALUE,$2,$4,0,0,0); $$->dataType = $1;}
	| Type TK_IDENTIFIER '[' LIT_INTEGER ']' ';' {
		ASTREE *size = astCreate(ASTREE_SYMBOL,$4,0,0,0,0);
		$$ = astCreate(ASTREE_DEC_VECTOR,$2,size,0,0,0);
		$$->dataType = $1;
	}
	| Type TK_IDENTIFIER '[' LIT_INTEGER ']' ':' Valuel ';' {
		ASTREE *size = astCreate(ASTREE_SYMBOL,$4,0,0,0,0);
		$$ = astCreate(ASTREE_DEC_VECTOR_INIT,$2, size,$7,0,0);
		$$->dataType = $1;
	}
	| Type '#' TK_IDENTIFIER '=' Value ';' {
		$$ = astCreate(ASTREE_DEC_POINTER,$3, $5,0,0,0);
		$$->dataType = $1;
	}
	| Type TK_IDENTIFIER '(' Paraml ')' block {
		$$ = astCreate(ASTREE_DEC_FUNC,$2 ,$4,$6,0,0);
		$$->dataType = $1;
	}
	;

Type:
	  KW_CHAR {$$ = KW_CHAR;}
	| KW_INT {$$ = KW_INT;}
	| KW_FLOAT {$$ = KW_FLOAT;}
	;

Value:
	LIT_INTEGER { $$ = astCreate(ASTREE_SYMBOL,$1,0,0,0,0); }
	| LIT_REAL  { $$ = astCreate(ASTREE_SYMBOL,$1,0,0,0,0); }
	| LIT_CHAR  { $$ = astCreate(ASTREE_SYMBOL,$1,0,0,0,0); }
	;

Valuel:
	Value Valuel { $$ = astCreate(ASTREE_VALUE_LIST,0,$1,$2,0,0); }
	| {$$ = 0;}
	;

Paraml:
	Param ',' Paraml { 
		if($3 != 0) {
			$$ = astCreate(ASTREE_PARAM_LIST,0, $1,$3,0,0);
		} else {
			$$ = $1;
		}
	}
	| Param { $$ = astCreate(ASTREE_PARAM_LIST, 0, $1,0,0,0); }
	| { $$ = 0; }
	;

Param:
	Type TK_IDENTIFIER {
		$$ = astCreate(ASTREE_PARAM,$2 ,0,0,0,0);
		$$->dataType = $1;
	}
	;

block:
	'{' cmdl '}' {$$ = astCreate(ASTREE_BLOCK,0,$2,0,0,0);}
	;

cmdl:
	cmd ';' cmdl {
		if($1 != 0) {
			$$ = astCreate(ASTREE_CMD_LIST,0,$1,$3,0,0);
		} else {
			$$ = $3;
		}
	}
	| cmd { if($1 != 0) { $$ = astCreate(ASTREE_CMD_LIST,0,$1,0,0,0); } }
	;

cmd:
	block {$$ = $1;}
	| TK_IDENTIFIER '=' expr {$$ = astCreate(ASTREE_VALUE_ASSIGNMENT,$1,$3,0,0,0);}
	| '#' TK_IDENTIFIER '=' expr {$$ = astCreate(ASTREE_POINTER_ASSIGNMENT,$2,$4,0,0,0);}
	| TK_IDENTIFIER '[' expr ']' '=' expr {$$ = astCreate(ASTREE_VECTOR_ASSIGNMENT,$1, $3,$6,0,0);}
	| KW_READ TK_IDENTIFIER {$$ = astCreate(ASTREE_READ,$2,0,0,0,0);}
	| KW_PRINT Eleml {$$ = astCreate(ASTREE_PRINT,0,$2,0,0,0);}
	| KW_RETURN expr {$$ = astCreate(ASTREE_RETURN,0,$2,0,0,0);}
	| KW_IF '(' expr ')' KW_THEN cmd {$$ = astCreate(ASTREE_IF_THEN,0,$3,$6,0,0);}
	| KW_IF '(' expr ')' KW_THEN cmd KW_ELSE cmd {$$ = astCreate(ASTREE_IF_THEN_ELSE,0,$3,$6,$8,0);}
	| KW_WHILE '(' expr ')' cmd {$$ = astCreate(ASTREE_WHILE,0,$3,$5,0,0);}
	| KW_FOR '(' TK_IDENTIFIER '=' expr KW_TO expr ')' cmd {
		ASTREE *ass = astCreate(ASTREE_VALUE_ASSIGNMENT,$3,$5,0,0,0);
		$$ = astCreate(ASTREE_FOR,0, ass,$7,$9,0);
	}
	| {$$ = 0;}
	;

Eleml:
	Elem Eleml {
		if($2 != 0) {
			$$ = astCreate(ASTREE_ELEM_LIST,0,$1,$2,0,0);
		} else {
			$$ = astCreate(ASTREE_ELEM_LIST,0,$1,0,0,0);
		}
	}
	| {$$ = 0;}
	;

Elem:
	LIT_STRING {$$ = astCreate(ASTREE_SYMBOL, $1, 0,0,0,0);}
	| expr {$$ = $1;}
	;

expr:
	expr '+' expr {$$ = astCreate(ASTREE_ADD,0,$1,$3,0,0);}
	| expr '-' expr {$$ = astCreate(ASTREE_SUB,0,$1,$3,0,0);}
	| expr '*' expr {$$ = astCreate(ASTREE_MULT,0,$1,$3,0,0);}
	| expr '/' expr {$$ = astCreate(ASTREE_DIV,0,$1,$3,0,0);}
	| expr '<' expr {$$ = astCreate(ASTREE_LESS,0,$1,$3,0,0);}
	| expr '>' expr {$$ = astCreate(ASTREE_GREATER,0,$1,$3,0,0);}
	| expr OPERATOR_LE expr {$$ = astCreate(ASTREE_LESS_EQ,0,$1,$3,0,0);}
	| expr OPERATOR_GE expr {$$ = astCreate(ASTREE_GREATER_EQ,0,$1,$3,0,0);}
	| expr OPERATOR_EQ expr {$$ = astCreate(ASTREE_EQ,0,$1,$3,0,0);}
	| expr OPERATOR_NE expr {$$ = astCreate(ASTREE_NEQ,0,$1,$3,0,0);}
	| expr OPERATOR_AND expr {$$ = astCreate(ASTREE_AND,0,$1,$3,0,0);}
	| expr OPERATOR_OR expr {$$ = astCreate(ASTREE_OR,0,$1,$3,0,0);}
	| '!' expr {$$ = astCreate(ASTREE_NOT,0,$2,0,0,0);}
	| '(' expr ')' {$$ = $2;}
	| TK_IDENTIFIER {$$ = astCreate(ASTREE_SYMBOL,$1,0,0,0,0);}
	| TK_IDENTIFIER '[' expr ']' {$$ = astCreate(ASTREE_VECTOR_ACCESS,$1,$3,0,0,0);}
	| '&' TK_IDENTIFIER {$$ = astCreate(ASTREE_SYMBOL_ADDRESS,$2,0,0,0,0);}
	| '#' TK_IDENTIFIER {$$ = astCreate(ASTREE_SYMBOL_POINTER,$2,0,0,0,0);}
	| Value {$$ = $1;}
	| TK_IDENTIFIER '(' Argl ')' {$$ = astCreate(ASTREE_INVOKE_FUNC,$1,$3,0,0,0);}
	| TK_IDENTIFIER '(' ')' {$$ = astCreate(ASTREE_INVOKE_FUNC,$1,0,0,0,0);}
	;

Argl:
	expr ',' Argl {
		$$ = astCreate(ASTREE_ARG_LIST,0,$1,$3,0,0);
	}
	| expr { $$ = astCreate(ASTREE_ARG_LIST,0,$1,0,0,0); }
	;

%%

int yyerror(char const *s) {
	printf("%s na linha %d\n", s, getLineNumber());
	return 0;
}