%{

int running = 1;  
int linhaNumero = 1;    

#include "ast.h"
#include "y.tab.h"


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
to     {return KW_TO;}
"<="   {return OPERATOR_LE;}
">="   {return OPERATOR_GE;}
"=="   {return OPERATOR_EQ;}
"!="   {return OPERATOR_NE;}
"&&"   {return OPERATOR_AND;}
"||"   {return OPERATOR_OR;}

[a-zA-Z_][a-zA-Z_0-9]*   {yylval.symbol = hash_Insert(SYMBOL_IDENTIFIER, yytext); return TK_IDENTIFIER;}

[0-9]+                   {yylval.symbol = hash_Insert(SYMBOL_LIT_INT, yytext); return LIT_INTEGER;}
[0-9]+\.[0-9]+           {yylval.symbol = hash_Insert(SYMBOL_LIT_REAL, yytext); return LIT_REAL;}

'[a-zA-Z]'               {yylval.symbol = hash_Insert(SYMBOL_LIT_CHAR, yytext); return LIT_CHAR;}
\"[^\"\n]*\"             {yylval.symbol = hash_Insert(SYMBOL_LIT_STRING, yytext); return LIT_STRING;}

[-,;:()\[\]{}+*/<>=!&$#] {return yytext[0];}
[\n]                     {linhaNumero++;}
[ \t\r]+

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
