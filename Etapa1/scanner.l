// Etapa 1
// Daniel Machado Nidejelski, Nícolas Vincent Dall'Bello Pessutto 

%{
#include "tokens.h"
#include "tabelaHash.h"
int running = 1;  
int linhaNumero = 1;    
%}

%x COMMENT

%%
char   {return KW_CHAR;}
int    {return KW_INT;}
float  {return KW_FLOAT;}
if     {return KW_IF; }
then   {return KW_THEN;}
else   {return KW_ELSE;}
while  {return KW_WHILE;}
for    {return KW_FOR;}
read   {return KW_READ;}
print  {return KW_PRINT;}
return {return KW_RETURN;}
"<="   {return OPERATOR_LE;}
">="   {return OPERATOR_GE;}
"=="   {return OPERATOR_EQ;}
"!="   {return OPERATOR_NE;}
"&&"   {return OPERATOR_AND;}
"||"   {return OPERATOR_OR;}

[a-zA-Z_][a-zA-Z_0-9]*   {hash_Insert(TK_IDENTIFIER, yytext); return TK_IDENTIFIER;}

[0-9]+                   {hash_Insert(LIT_INTEGER, yytext); return LIT_INTEGER;}
[0-9]+\.[0-9]+           {hash_Insert(LIT_REAL, yytext); return LIT_REAL;}

'[a-zA-Z]'               {hash_Insert(LIT_CHAR, yytext); return LIT_CHAR;}
\"(\\.|[^"])*\"          {hash_Insert(LIT_STRING, yytext); return LIT_STRING;}

[-,;:()\[\]{}+*/<>=!&$#] {return yytext[0];}
[ \t] 
[\n]                     {linhaNumero++;}
"//".*
"/*"                     {BEGIN(COMMENT);}
.                        {return TOKEN_ERROR;}

<COMMENT>"\n"            {linhaNumero++;}
<COMMENT>"*/"            {BEGIN(INITIAL);}
<COMMENT>.   

%%

int yywrap(){ 
    running = 0;  
    return 1; 
}

void initMe(){
    hash_Init();
} 

int isRunning(){
    return running;
}

int getLineNumber(void){
    return linhaNumero;
}

FILE* file(char* filename){
    yyin = fopen(filename,"r");
    return yyin;
}

int simboloASCII(){
    return yytext[0];
}
