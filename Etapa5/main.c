// Etapa 5
// Daniel Machado Nidejelski, Nícolas Vincent Dall'Bello Pessutto 

#include <stdio.h>
#include <stdlib.h>
#include "ast.h"
#include "semantic.h"

extern int isRunning();
extern int getLineNumber();
extern void initMe();
extern FILE* yyin;
extern FILE* yytext;
extern int yylex();
extern int yyparse();
extern ASTREE* get_rootAst();
extern void resultSemantic();

void compilar(ASTREE *ast){
 
  	if(!ast) return;
	if(ast){	
		
		switch(ast->type){         
			case ASTREE_SYMBOL:
                		fprintf(source_code, "%s", ast->symbol->text);
                		break;
	  		case ASTREE_AND:
                		compilar(ast->son[0]); fprintf(source_code,"&&"); compilar(ast->son[1]);
                		break;
            case ASTREE_OR:
                		compilar(ast->son[0]); fprintf(source_code,"||"); compilar(ast->son[1]);
                		break;
            case ASTREE_ADD:
                		compilar(ast->son[0]); fprintf(source_code,"+"); compilar(ast->son[1]);
                		break;
            case ASTREE_SUB:
                		compilar(ast->son[0]); fprintf(source_code,"-"); compilar(ast->son[1]);
                		break;
            case ASTREE_MUL:
                		compilar(ast->son[0]); fprintf(source_code,"*"); compilar(ast->son[1]);
                		break;
            case ASTREE_DIV:
                		compilar(ast->son[0]); fprintf(source_code,"/"); compilar(ast->son[1]);
                		break;
            case ASTREE_L:
                		compilar(ast->son[0]); fprintf(source_code,"<"); compilar(ast->son[1]);
                		break;
            case ASTREE_G:
                		compilar(ast->son[0]); fprintf(source_code,">"); compilar(ast->son[1]);
                		break;
            case ASTREE_LE:
                		compilar(ast->son[0]); fprintf(source_code,"<="); compilar(ast->son[1]);
                		break;
            case ASTREE_GE:
                		compilar(ast->son[0]); fprintf(source_code,">="); compilar(ast->son[1]);
                		break;
            case ASTREE_EQ:
                		compilar(ast->son[0]); fprintf(source_code,"=="); compilar(ast->son[1]);
                		break;
            case ASTREE_NE:
                		compilar(ast->son[0]); fprintf(source_code,"!="); compilar(ast->son[1]);
                		break;
			case ASTREE_NOT:
                		fprintf(source_code,"!");compilar(ast->son[0]);  
                		break;			
            case ASTREE_READ:
                		fprintf(source_code,"read "); fprintf(source_code,"%s", ast->symbol->text);
                		break;
            case ASTREE_RETURN:
               			fprintf(source_code,"return "); compilar(ast->son[0]);
                		break;
            case ASTREE_WHILE:
                		fprintf(source_code,"while("); compilar(ast->son[0]); fprintf(source_code,")"); compilar(ast->son[1]);
                		break;
			case ASTREE_FUNDEF:
               			fprintf(source_code,"("); compilar(ast->son[0]); fprintf(source_code,")"); fprintf(source_code,"%s", ast->symbol->text); fprintf(source_code,"("); compilar(ast->son[1]); fprintf(source_code,")"); compilar(ast->son[2]);         
                		break;    
            case ASTREE_FUNCALL:
                		fprintf(source_code,"%s", ast->symbol->text); fprintf(source_code,"("); compilar(ast->son[0]); fprintf(source_code,")");
                		break;
 			case ASTREE_PARENTHESIS:
                		fprintf(source_code,"("); compilar(ast->son[0]); fprintf(source_code,")");
                		break;
            case ASTREE_BRACES:
                		fprintf(source_code,"{\n"); compilar(ast->son[0]); fprintf(source_code,"}");
                		break;
			case ASTREE_PARAM:
                 		fprintf(source_code,"%s:", ast->symbol->text); compilar(ast->son[0]);
                		break; 
			case ASTREE_ATR:
                 		fprintf(source_code,"%s", ast->symbol->text); fprintf(source_code,"="); compilar(ast->son[0]);
                		break;
			case ASTREE_ARRAY_WRITE:
                		fprintf(source_code, "%s", ast->symbol->text); fprintf(source_code, "["); compilar(ast->son[0]);fprintf(source_code, "]"); fprintf(source_code, "="); compilar(ast->son[1]);
                		break;
			case ASTREE_ARRAY_READ:
                		fprintf(source_code,"%s", ast->symbol->text); fprintf(source_code,"["); compilar(ast->son[0]); fprintf(source_code,"]");
                		break;
   			case ASTREE_PRINT:
                		fprintf(source_code,"print "); compilar(ast->son[0]); 
                		break;
			case ASTREE_PRINTL:
                		if(ast->son[1] != NULL){
                    		compilar(ast->son[0]); fprintf(source_code,","); compilar(ast->son[1]);
                		}else
                   	 		compilar(ast->son[0]);
                		break;
 			case ASTREE_CMDL:
                		if(ast->son[1] != NULL){
                    		compilar(ast->son[0]); fprintf(source_code,";\n"); compilar(ast->son[1]);
                		}else
                    		compilar(ast->son[0]);
                		break;
            case ASTREE_DFNL:
					    if(ast->son[1] != NULL){
                    	    compilar(ast->son[0]); fprintf(source_code," \n"); compilar(ast->son[1]);
                	    }	
					    else
                    	    compilar(ast->son[0]);
                		break;
            case ASTREE_PARL:
                	    if(ast->son[1] != NULL){
                    	    compilar(ast->son[0]); fprintf(source_code,","); compilar(ast->son[1]);
                	    }else
                    	    compilar(ast->son[0]);
                		break;
            case ASTREE_INTL:
				        if(ast->son[1] != NULL){
                    		fprintf(source_code,":"); compilar(ast->son[0]); fprintf(source_code," "); compilar(ast->son[1]);
                		}else
                    		compilar(ast->son[0]);
               	 		break;
			case ASTREE_VARINI:
                		fprintf(source_code,"%s", ast->symbol->text); compilar(ast->son[0]); fprintf(source_code,"="); compilar(ast->son[1]);fprintf(source_code,";"); compilar(ast->son[2]);
               		 	break;
            case ASTREE_CHAR:
                		fprintf(source_code,"char");
                		break;
            case ASTREE_INT:
                		fprintf(source_code,"int");
               	 		break;
            case ASTREE_FLOAT:
                		fprintf(source_code,"float");
                		break; 
			case ASTREE_IF:
                		fprintf(source_code,"if("); compilar(ast->son[0]); fprintf(source_code,") then ");fprintf(source_code," \n"); compilar(ast->son[1]);
				        break;
			case ASTREE_ELSE:
                		fprintf(source_code,"if("); compilar(ast->son[0]); fprintf(source_code,") then "); compilar(ast->son[1]);fprintf(source_code,"else "); compilar(ast->son[1]);
				        break;  
			case ASTREE_ARRINI:
                		fprintf(source_code,"%s", ast->symbol->text); compilar(ast->son[0]); fprintf(source_code,"["); 	compilar(ast->son[1]); fprintf(source_code,"]"); 	
				
				        if(ast->son[2]!=NULL)
					        compilar(ast->son[2]);
				        fprintf(source_code,";");
                		break;
           
/*          case ASTREE_VARPT:
                		fprintf(source_code,"%s", ast->symbol->text); fprintf(source_code," #"); compilar(ast->son[0]); fprintf(source_code,";");
            			break;
            case ASTREE_VARPTINI:
                		fprintf(source_code,"%s", ast->symbol->text); fprintf(source_code," #"); compilar(ast->son[0]); fprintf(source_code,"="); compilar(ast->son[1]);fprintf(source_code,";"); compilar(ast->son[2]);
            			break;	
				
	    case ASTREE_INTL2:

            			break;
            case ASTREE_FIMCMDL:

            			break;
            case ASTREE_FPARL:

            			break;
				
				*/				
			default:
				printf("ERRO\n");
				break;
		}
	}
	return;
}


int main(int argc, char *argv[]){
	FILE* file;
	
	if (argc < 2){
		printf("Argumentos faltando. Chamar etapa e nome do arquivo de saida. exit(1) \n");
		return 1; // arquivo nao informado
	}
	else if (!(file = fopen(argv[1], "r"))){
		printf ("Erro em arq! exit(2)");
		return 2; // arquivo inexistente
	}
	else{
		if( source_code = fopen(argv[2], "w+")){
			yyin = file;

			initMe();
			
			yyparse();
			
			printf("\n Sintaxe correta! OK! \n");
			
			ASTREE *ast = get_rootAst();
			
			compilar(ast);
			
			hash_Print();
			
			resultadoSemantica();
			 
		}else{
			fprintf(stderr, "Erro ao criar arquivo de saída! exit(2) \n");
			return 2; // arquivo inexistente
		}
	}
	printf("\n Semantica correta! OK, sucesso! exit(0) \n");
	return 0; // sucesso 
}
