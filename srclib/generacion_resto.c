#include "generacion_resto.h"

void resto(FILE* fpasm, int es_variable_1, int es_variable_2){
	fprintf(fpasm, "\n\t; Resto\n");    
	fprintf(fpasm,"\tpop dword ebx\n");
    fprintf(fpasm,"\tpop dword eax\n");
    if(es_variable_1){
        fprintf(fpasm, "\tmov eax, dword [eax]\n");
    }
    if(es_variable_2){
        fprintf(fpasm, "\tmov ebx, dword [ebx]\n");
    }
    fprintf(fpasm, "\tcmp ebx, 0\n"); /*Comparamos con 0 para ver que no estamos dividiendo por 0*/
    fprintf(fpasm, "\tje __error_division\n");/*De ser igual saltamos a la rutina de error de division*/
    fprintf(fpasm, "\tcdq\n");
    fprintf(fpasm, "\tidiv ebx\n");
	fprintf(fpasm, "\tpush dword edx\n");/*Metemos en la pila unicamente el resto de la division*/
}