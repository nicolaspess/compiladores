#include "genasm.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int searchStr(char* string){
	int i;
	for(i = 0; i < 100; i++)
		if(strcmp(string, strings_list[i]) == 0)
			return i;
	
}

void asmGenerator(char *filename, TAC* code){
	TAC *tac;
	FILE *fout;

	if(!(fout = fopen(filename, "w+"))){
		fprintf(stderr,"Couldn't open ASM output file.\n");
		exit(5);
	}

	fprintf(fout, "\t.section	.rodata\n");

	hashmap_printLabel(programScope, fout);

	hashmap_printString(scannedSymbolsMap, fout);

	fprintf(fout,	".LC0:\n"
					"\t.string	\"%%d\"\n");
	
	int temIO = 0;
	int numArgsFunDec = 12;
	int numArgsFunCall = 0;
	for (tac=code; tac != NULL; tac=tac->next){
		printf("\n");
		switch(tac->type){
			case TAC_LABEL: 
				printf("TAC_LABEL\n"); 
				printf("res charvalue: %s\n", tac->res->charValue);
				printf("res stringvalue: %s\n", tac->res->stringValue);
				printf("res intvalue: %d\n", tac->res->intValue);
				printf("res key: %s\n", tac->res->key);
				printf("res type: %d\n", tac->res->type);
				fprintf(fout, "\n.%s:\n", tac->res->key); break;
			case TAC_FUNC_CALL:
				//reseta numArgsFunCall
				numArgsFunCall = 0;
				printf("TAC_FUNC_CALL\n"); 
				printf("res charvalue: %s\n", tac->res->charValue);
				printf("res stringvalue: %s\n", tac->res->stringValue);
				printf("res intvalue: %d\n", tac->res->intValue);
				printf("res key: %s\n", tac->res->key);
				printf("res type: %d\n", tac->res->type);
				fprintf(fout, 	"\n##FUNCALL\n"
				   				"\tmovl $0, %%eax\n"
								"\tcall %s\n", tac->res->stringValue);
				break;
			case TAC_ARG:

				printf("TAC_ARG\n"); 
				printf("res charvalue: %s\n", tac->res->charValue);
				printf("res stringvalue: %s\n", tac->res->stringValue);
				printf("res intvalue: %d\n", tac->res->intValue);
				printf("res key: %s\n", tac->res->key);
				printf("res type: %d\n", tac->res->type);
				printf("op1 intvalue: %d\n", tac->op1->intValue);
				printf("op1 charvalue: %s\n", tac->op1->charValue);
				printf("op1 stringvalue: %s\n", tac->op1->stringValue);
				fprintf(fout, "\n##ARG FUNCALL\n");
				if(tac->res->type = LIT_INTEGER){
					if (numArgsFunCall >= 1)
						fprintf(fout, "\tmovl	$%d, %d(%%esp)\n", tac->op1->intValue, numArgsFunCall * 4);
					else
						fprintf(fout, "\tmovl	$%d, (%%esp)\n", tac->op1->intValue);
				}
				numArgsFunCall++;
				break;
  			case TAC_BEGIN_FUNC:
  				temIO = 0;
  				printf("TAC_BEGIN_FUNC\n"); 
				printf("res charvalue: %s\n", tac->res->charValue);
				printf("res stringvalue: %s\n", tac->res->stringValue);
				printf("res intvalue: %d\n", tac->res->intValue);
				printf("res key: %s\n", tac->res->key);
				printf("res type: %d\n", tac->res->type);
  				fprintf(fout, 	"\n##BEGFUN\n"
				 				"\t.text\n"
								"\t.globl	%s\n"
								"\t.type	%s, @function\n\n"
								"%s:\n"
								"\tpushl	%%ebp\n"
								"\tmovl	%%esp, %%ebp\n", tac->res->stringValue, tac->res->stringValue, tac->res->stringValue);
    			break;

    		case TAC_ARGDEC:
    			printf("TAC_ARGDEC\n");
    			printf("res charvalue: %s\n", tac->res->charValue);
				printf("res stringvalue: %s\n", tac->res->stringValue);
				printf("res intvalue: %d\n", tac->res->intValue);
				printf("res key: %s\n", tac->res->key);
				printf("res type: %d\n", tac->res->type);
				
				//fprintf(fout, "\n##TAC_ARGDEC\n");
				//fprintf(fout,	"\tmovl	%d(%%ebp), %%eax\n", numArgsFunDec);

				//numArgsFunDec = numArgsFunDec - 4;;
   				break;

  			case TAC_END_FUNC: 
  				printf("TAC_END_FUNC\n"); 
				printf("res charvalue: %s\n", tac->res->charValue);
				printf("res stringvalue: %s\n", tac->res->stringValue);
				printf("res intvalue: %d\n", tac->res->intValue);
				printf("res key: %s\n", tac->res->key);
				printf("res type: %d\n", tac->res->type);
    			if (temIO == 1){
    				fprintf(fout,  	"\n\tleave\n"
									"\tret\n");
    			}else {
    				fprintf(fout,  	"\n\tpopl	%%ebp\n"
									"\tret\n");	
    			}
    			temIO = 0;    			
    			break;

    		case TAC_RETURN:
    			printf("TAC_RETURN\n"); 
				printf("res charvalue: %s\n", tac->res->charValue);
				printf("res stringvalue: %s\n", tac->res->stringValue);
				printf("res intvalue: %d\n", tac->res->intValue);
				printf("res key: %s\n", tac->res->key);
				printf("res type: %d\n", tac->res->type);
    			if(tac->res->type == LIT_INTEGER)
    				fprintf(fout, "movl $%d, %%eax\n", tac->res->intValue);
    			else
    				fprintf(fout, "movl %s, %%eax\n", tac->res->stringValue);
    			break;
    		case TAC_READ:
    			printf("TAC_READ\n"); 
				printf("res charvalue: %s\n", tac->res->charValue);
				printf("res stringvalue: %s\n", tac->res->stringValue);
				printf("res intvalue: %d\n", tac->res->intValue);
				printf("res key: %s\n", tac->res->key);
				printf("res type: %d\n", tac->res->type);
    			fprintf(fout,	"\n##READ\n"
	    						"\tandl	$-16, %%esp\n"
								"\tsubl	$16, %%esp\n"
								"\tmovl	$.LC0, %%eax\n"
								"\tmovl	$%s, 4(%%esp)\n"
								"\tmovl	%%eax, (%%esp)\n"
								"\tcall	__isoc99_scanf\n", tac->res->stringValue);
    			break;
			
			case TAC_PRINTARG:
				temIO = 1;
				printf("TAC_PRINTARG\n"); 
				printf("res charvalue: %s\n", tac->res->charValue);
				printf("res stringvalue: %s\n", tac->res->stringValue);
				printf("res intvalue: %d\n", tac->res->intValue);
				printf("res key: %s\n", tac->res->key);
				printf("res type: %d\n", tac->res->type);
				if(tac->res->type == LIT_STRING){
					fprintf(fout, 	"\n## PRINT\n"
									"\tmovl $.string%d_label, %%eax\n"
									"\tmovl %%eax, (%%esp)\n"
									"\tcall printf\n", searchStr(tac->res->stringValue));
				}else if(tac->res->type == TK_IDENTIFIER){
					fprintf(fout, 	"\n## PRINT\n"
									"\tandl	$-16, %%esp\n"
									"\tsubl	$16, %%esp\n"
									"\tmovl	%s, %%edx\n"
									"\tmovl	$.LC0, %%eax\n"
									"\tmovl	%%edx, 4(%%esp)\n"
									"\tmovl	%%eax, (%%esp)\n"
									"\t call printf\n", tac->res->stringValue);
				}
				break;
			
			case TAC_DEC_POINTER: 
				printf("TAC_DEC_POINTER\n"); 
				printf("res charvalue: %s\n", tac->res->charValue);
				printf("res stringvalue: %s\n", tac->res->stringValue);
				printf("res intvalue: %d\n", tac->res->intValue);
				printf("res key: %s\n", tac->res->key);
				printf("res type: %d\n", tac->res->type);
				printf("op1 intvalue: %d\n", tac->op1->intValue);
				printf("op1 charvalue: %s\n", tac->op1->charValue);
				printf("op1 stringvalue: %s\n", tac->op1->stringValue);
				fprintf(fout, 	"\n##POINTER DEC\n"
								"\t.globl	%s\n"
								"\t.data\n"
								"\t.align 4\n"
								"\t.type	%s, @object\n"
								"\t.size	%s, 4\n"
								"%s:\n"
								"\t.long	%d", tac->res->stringValue, tac->res->stringValue, tac->res->stringValue, tac->res->stringValue, tac->op1->intValue);
				break;

			case TAC_DEC_VALUE:
				printf("TAC_DEC_VALUE\n");
				printf("res charvalue: %s\n", tac->res->charValue);
				printf("res stringvalue: %s\n", tac->res->stringValue);
				printf("res intvalue: %d\n", tac->res->intValue);
				printf("res key: %s\n", tac->res->key);
				printf("res type: %d\n", tac->res->type);
				printf("op1 intvalue: %d\n", tac->op1->intValue);
				fprintf(fout, 	"\n##VARDEC\n"
								"\t.globl	%s\n"
								"\t.data\n"
								"\t.align 4\n"
								"\t.type	%s, @object\n"
								"\t.size	%s, 4\n"
								"%s:\n"
								"\t.long	%d", tac->res->stringValue, tac->res->stringValue, tac->res->stringValue, tac->res->stringValue, tac->op1->intValue);
				break;

			case TAC_VECDEC:
				printf("TAC_VECDEC\n"); 
				printf("res charvalue: %s\n", tac->res->charValue);
				printf("res stringvalue: %s\n", tac->res->stringValue);
				printf("res intvalue: %d\n", tac->res->intValue);
				printf("res key: %s\n", tac->res->key);
				printf("res type: %d\n", tac->res->type);
				printf("op1 key: %s\n", tac->op1->key);
				printf("op1 intvalue: %d\n", tac->op1->intValue);
				printf("op1 charvalue: %s\n", tac->op1->charValue);
				printf("op1 stringvalue: %s\n", tac->op1->stringValue);
				fprintf(fout, "\n ## TAC_VECDEC\n"
							"\t.globl	%s\n"
							"\t.data\n"
							"\t.align 4\n"
							"\t.type	%s, @object\n"
							"\t.size	%s, %d\n"
							"%s:\n",tac->res->stringValue, tac->res->stringValue, tac->res->stringValue,tac->op1->intValue*4 ,tac->res->stringValue);
				break;
			case TAC_DECVEC_VALUE:
				printf("TAC_VECDEC_VALUE\n"); 
				printf("res charvalue: %s\n", tac->res->charValue);
				printf("res stringvalue: %s\n", tac->res->stringValue);
				printf("res intvalue: %d\n", tac->res->intValue);
				printf("res key: %s\n", tac->res->key);
				printf("res type: %d\n", tac->res->type);

				fprintf(fout, "\t.long %d\n", tac->res->intValue);
				break;


			case TAC_DEC_VECTOR:
				printf("TAC_DEC_VECTOR\n"); 
				printf("res charvalue: %s\n", tac->res->charValue);
				printf("res stringvalue: %s\n", tac->res->stringValue);
				printf("res intvalue: %d\n", tac->res->intValue);
				printf("res key: %s\n", tac->res->key);
				printf("res type: %d\n", tac->res->type);
				printf("op1 key: %s\n", tac->op1->key);
				printf("op1 intvalue: %d\n", tac->op1->intValue);
				printf("op1 charvalue: %s\n", tac->op1->charValue);
				printf("op1 stringvalue: %s\n", tac->op1->stringValue);
				fprintf(fout, 	"\n##DEC_VECTOR\n"
								"\t.comm	%s,%d,4\n", tac->res->stringValue, tac->op1->intValue * 4);
				printf("fim TAC_DEC_VECTOR\n");
				break;
  			
  			case TAC_JUMP: 
  				printf("TAC_JUMP\n"); 
				printf("res charvalue: %s\n", tac->res->charValue);
				printf("res stringvalue: %s\n", tac->res->stringValue);
				printf("res intvalue: %d\n", tac->res->intValue);
				printf("res key: %s\n", tac->res->key);
				printf("res type: %d\n", tac->res->type);
  				fprintf(fout, "\n\tjmp .%s\n", tac->res->key); break;

			case TAC_IFZERO: 
				printf("TAC_IFZERO\n"); 
				printf("res charvalue: %s\n", tac->res->charValue);
				printf("res stringvalue: %s\n", tac->res->stringValue);
				printf("res intvalue: %d\n", tac->res->intValue);
				printf("res key: %s\n", tac->res->key);
				printf("res type: %d\n", tac->res->type);
				printf("op1 key: %s\n", tac->op1->key);
				printf("op1 intvalue: %d\n", tac->op1->intValue);
				printf("op1 charvalue: %s\n", tac->op1->charValue);
				printf("op1 stringvalue: %s\n", tac->op1->stringValue);
				fprintf(fout, " .%s\n", tac->res->key);break;

			case TAC_GREATER: 
				printf("TAC_GREATER\n"); 
				printf("res charvalue: %s\n", tac->res->charValue);
				printf("res stringvalue: %s\n", tac->res->stringValue);
				printf("res intvalue: %d\n", tac->res->intValue);
				printf("res key: %s\n", tac->res->key);
				printf("res type: %d\n", tac->res->type);
				printf("op1 key: %s\n", tac->op1->key);
				printf("op1 intvalue: %d\n", tac->op1->intValue);
				printf("op1 charvalue: %s\n", tac->op1->charValue);
				printf("op1 stringvalue: %s\n", tac->op1->stringValue);
				fprintf(fout, "\n##GREATER\n");
				if (tac->op1->type == LIT_INTEGER)
					fprintf(fout, "\tmovl $%d, %%edx\n", tac->op1->intValue);
				else
					fprintf(fout, "\tmovl %s, %%edx\n", tac->op1->stringValue);
				if (tac->op2->type == LIT_INTEGER)
					fprintf(fout, "\tmovl $%d, %%eax\n", tac->op2->intValue);
				else
					fprintf(fout, "\tmovl %s, %%eax\n", tac->op2->stringValue);
				fprintf(fout, "\tcmpl %%eax, %%edx\n");
				fprintf(fout, "\tjg");
				break;

			case TAC_LESS: 
				fprintf(fout, "\n##LESS\n");
				if (tac->op1->type == LIT_INTEGER)
					fprintf(fout, "\tmovl $%d, %%edx\n", tac->op1->intValue);
				else
					fprintf(fout, "\tmovl %s, %%edx\n", tac->op1->stringValue);
				if (tac->op2->type == LIT_INTEGER)
					fprintf(fout, "\tmovl $%d, %%eax\n", tac->op2->intValue);
				else
					fprintf(fout, "\tmovl %s, %%eax\n", tac->op2->stringValue);
				fprintf(fout, "\tcmpl %%eax, %%edx\n");
				fprintf(fout, "\tjle");
				break;

			case TAC_GREATER_EQ: 
				fprintf(fout, "\n##GREATER OR EQUAL\n");
				if (tac->op1->type == LIT_INTEGER)
					fprintf(fout, "\tmovl $%d, %%edx\n", tac->op1->intValue);
				else
					fprintf(fout, "\tmovl %s, %%edx\n", tac->op1->stringValue);
				if (tac->op2->type == LIT_INTEGER)
					fprintf(fout, "\tmovl $%d, %%eax\n", tac->op2->intValue);
				else
					fprintf(fout, "\tmovl %s, %%eax\n", tac->op2->stringValue);
				fprintf(fout, "\tcmpl %%eax, %%edx\n");
				fprintf(fout, "\tjge");
				break;

			case TAC_LESS_EQ: 
				fprintf(fout, "\n##LESS OR EQUAL\n");
				if (tac->op1->type == LIT_INTEGER)
					fprintf(fout, "\tmovl $%d, %%edx\n", tac->op1->intValue);
				else
					fprintf(fout, "\tmovl %s, %%edx\n", tac->op1->stringValue);
				if (tac->op2->type == LIT_INTEGER)
					fprintf(fout, "\tmovl $%d, %%eax\n", tac->op2->intValue);
				else
					fprintf(fout, "\tmovl %s, %%eax\n", tac->op2->stringValue);
				fprintf(fout, "\tcmpl %%eax, %%edx\n");
				fprintf(fout, "\tjle");
				break;

			case TAC_EQ: 
				fprintf(fout, "\n##EQUAL\n");
				if (tac->op1->type == LIT_INTEGER)
					fprintf(fout, "\tmovl $%d, %%edx\n", tac->op1->intValue);
				else
					fprintf(fout, "\tmovl %s, %%edx\n", tac->op1->stringValue);
				if (tac->op2->type == LIT_INTEGER)
					fprintf(fout, "\tmovl $%d, %%eax\n", tac->op2->intValue);
				else
					fprintf(fout, "\tmovl %s, %%eax\n", tac->op2->stringValue);
				fprintf(fout, "\tcmpl %%eax, %%edx\n");
				fprintf(fout, "\tje");
				break;


			case TAC_NEQ: 
				fprintf(fout, "\n##NOT EQUAL\n");
				if (tac->op1->type == LIT_INTEGER)
					fprintf(fout, "\tmovl $%d, %%edx\n", tac->op1->intValue);
				else
					fprintf(fout, "\tmovl %s, %%edx\n", tac->op1->stringValue);
				if (tac->op2->type == LIT_INTEGER)
					fprintf(fout, "\tmovl $%d, %%eax\n", tac->op2->intValue);
				else
					fprintf(fout, "\tmovl %s, %%eax\n", tac->op2->stringValue);
				fprintf(fout, "\tcmpl %%eax, %%edx\n");
				fprintf(fout, "\tjne");
				break;


  			case TAC_ADD: 
  				fprintf(fout,"\n##ADD\n");
				printf("TAC_ADD\n");
				printf("res charvalue: %s\n", tac->res->charValue);
				printf("res stringvalue: %s\n", tac->res->stringValue);
				printf("res intvalue: %d\n", tac->res->intValue);
				printf("res key: %s\n", tac->res->key);
				printf("res type: %d\n", tac->res->type);
				printf("op1 key: %s\n", tac->op1->key);
				printf("op1 intvalue: %d\n", tac->op1->intValue);
				printf("op1 charvalue: %s\n", tac->op1->charValue);
				printf("op1 stringvalue: %s\n", tac->op1->stringValue);
				if (tac->op1->type == LIT_INTEGER)
					fprintf(fout, "\tmovl $%d, %%edx\n", tac->op1->intValue);
				else 
					fprintf(fout, "\tmovl %s, %%edx\n", tac->op1->stringValue);
				if (tac->op2->type == LIT_INTEGER)
					fprintf(fout, "\tmovl $%d, %%eax\n", tac->op2->intValue);
				else 
					fprintf(fout, "\tmovl %s, %%eax\n", tac->op2->stringValue);
				fprintf(fout, "\taddl %%edx, %%eax\n");
				//fprintf(fout, "\tmovl %%eax, %s\n", tac->next->res->stringValue);
  				break;

  			case TAC_SUB: 
  				fprintf(fout,"\n##SUB\n");
				if (tac->op1->type == LIT_INTEGER)
					fprintf(fout, "\tmovl $%d, %%edx\n", tac->op1->intValue);
				else 
					fprintf(fout, "\tmovl	%s, %%edx\n", tac->op1->stringValue);
				if (tac->op2->type == LIT_INTEGER)
					fprintf(fout, "\tmovl $%d, %%eax\n", tac->op2->intValue);
				else 
					fprintf(fout, "\tmovl	%s, %%eax\n", tac->op2->stringValue);

				fprintf(fout, "\tmovl	%%edx, %%ecx\n");
				fprintf(fout, "\tsubl	%%eax, %%ecx\n");
				fprintf(fout, "\tmovl	%%ecx, %%eax\n");
  				break;

  			case TAC_MULT: 
  				fprintf(fout,"\n##MUL\n");
				if (tac->op1->type == LIT_INTEGER)
					fprintf(fout, "\tmovl $%d, %%edx\n", tac->op1->intValue);
				else 
					fprintf(fout, "\tmovl %s, %%edx\n", tac->op1->stringValue);
				if (tac->op2->type == LIT_INTEGER)
					fprintf(fout, "\tmovl $%d, %%eax\n", tac->op2->intValue);
				else 
					fprintf(fout, "\tmovl %s, %%eax\n", tac->op2->stringValue);
				fprintf(fout, "\timull %%edx, %%eax\n");
  				break;

  			case TAC_DIV: 
  				fprintf(fout,"\n##DIV\n");
				if (tac->op1->type == LIT_INTEGER)
					fprintf(fout, "\tmovl $%d, %%eax\n", tac->op1->intValue);
				else 
					fprintf(fout, "\tmovl %s, %%eax\n", tac->op1->stringValue);
				if (tac->op2->type == LIT_INTEGER)
					fprintf(fout, "\tmovl $%d, %%edx\n", tac->op2->intValue);
				else 
					fprintf(fout, "\tmovl %s, %%edx\n", tac->op2->stringValue);

				fprintf(fout,	"\tmovl	%%edx, -4(%%ebp)\n"
								"\tmovl	%%eax, %%edx\n"
								"\tsarl	$31, %%edx\n"
								"\tidivl	-4(%%ebp)\n");
  				break;


  			case TAC_VALUE_ASSIGNMENT: 
				printf("TAC_VALUE_ASSIGNMENT\n"); 
				printf("res charvalue: %s\n", tac->res->charValue);
				printf("res stringvalue: %s\n", tac->res->stringValue);
				printf("res intvalue: %d\n", tac->res->intValue);
				printf("res key: %s\n", tac->res->key);
				printf("res type: %d\n", tac->res->type);
				printf("op1 key: %s\n", tac->op1->key);
				printf("op1 type: %d\n", tac->op1->type);
				printf("op1 intvalue: %d\n", tac->op1->intValue);
				printf("op1 charvalue: %s\n", tac->op1->charValue);
				printf("op1 stringvalue: %s\n", tac->op1->stringValue);
				fprintf(fout,"\n##ASSIGN\n");
				if (tac->prev->type == TAC_FUNC_CALL)
					fprintf(fout, "\tmovl %%eax, %s\n", tac->res->stringValue);
				else if (tac->op1->type == LIT_INTEGER)
					fprintf(fout, "\tmovl %%eax, %s\n", tac->res->stringValue);
				else{
					fprintf(fout, "\tmovl %s, %%eax\n", tac->op1->stringValue);
					fprintf(fout, "\tmovl %%eax, %s\n", tac->res->stringValue);
				}
				break;

			case TAC_VASSIGN: 
				printf("TAC_VASSIGN\n"); 
				printf("res charvalue: %s\n", tac->res->charValue);
				printf("res stringvalue: %s\n", tac->res->stringValue);
				printf("res intvalue: %d\n", tac->res->intValue);
				printf("res key: %s\n", tac->res->key);
				printf("res type: %d\n", tac->res->type);
				printf("op1 key: %s\n", tac->op1->key);
				printf("op1 intvalue: %d\n", tac->op1->intValue);
				printf("op1 charvalue: %s\n", tac->op1->charValue);
				printf("op1 stringvalue: %s\n", tac->op1->stringValue);
				fprintf(fout, "\n##VEC ASSIGN\n");
				if (tac->prev->type == TAC_FUNC_CALL){
					fprintf(fout, "\tmovl %%eax, %s+%d\n", tac->res->stringValue, tac->op1->intValue * 4);
				}else if(tac->prev->type == TAC_VACCESS){
					fprintf(fout, "\tmovl %d+%d, %%eax\n"
								  "\tmovl %%eax, %s+%d\n", tac->prev->op1->intValue, tac->prev->op2->intValue * 4, tac->res->stringValue, tac->op1->intValue * 4);
				}else if (tac->op2->type == LIT_INTEGER){
					fprintf(fout, "\tmovl $%d, %s+%d\n", tac->op2->intValue, tac->res->stringValue, tac->op1->intValue * 4);
				}else{ //var
					fprintf(fout, "\tmovl %s, %%eax\n"
				    			  "\tmovl %%eax, %s+%d\n", tac->op2->stringValue, tac->res->stringValue, tac->op1->intValue * 4);
				}
				break;

			case TAC_VACCESS: 
				fprintf(fout, "\n##VEC READ\n");
				fprintf(fout,"\tmovl	%s+%d, %%eax\n", tac->op1->stringValue, tac->op2->intValue * 4, tac->res->stringValue);
				break;
			default:
				printf("TAC not detected: %d\n", tac->type);
		}
	}

	fclose(fout);
}