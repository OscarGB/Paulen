#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tabla_simbolos_clases.h"

simbolos_p simbolos = NULL;

int process_line(FILE * f){
	char line[1000], ambito[1000], to_print[1000];
	simbolo_p s;
	char *tok, *tok1;
	char* res;

	res = fgets(line, 1000, f);
	strcpy(to_print, line);
	strtok(to_print, "\n");
	if(!res){
		return 1;
	}
	tok = strtok(res, " \t\n");
	if(strcmp(tok, "inicia_tsc") == 0){
		tok = strtok(NULL, " \t\n");
		simbolos = createSimbolos(tok);
		printf("%s\n", to_print);
	}
	else if(strcmp(tok, "abrir_clase") == 0){
		tok = strtok(NULL, " \t\n");
		nuevaClase(simbolos, NULL, 0, tok);
		printf("%s\n", to_print);
	}
	else if(strcmp(tok, "insertar_tsa_main") == 0){
		printf("%s\n", to_print);




	}
	else if(strcmp(tok, "buscar") == 0){
		tok = strtok(NULL, " \t\n");
		if(strcmp(tok, "declarar_main") == 0){
			printf("%s: ", to_print);
			tok = strtok(NULL, " \t\n");
			if(buscarParaDeclararIdTablaSimbolosAmbitos(simbolos, tok, &s, ambito) == ERROR){
				printf("No encontrado: se puede declarar\n");
			}
			else{
				printf("Existe id: no se puede declarar\n");
			}
		}
		else if(strcmp(tok, "declarar_miembro_instancia") == 0){
			printf("%s: ", to_print);
			tok = strtok(NULL, " \t\n");
			tok1 = strtok(NULL, " \t\n");
			if(buscarParaDeclararMiembroInstancia(simbolos,tok, tok1, &s, ambito) == ERROR){
				printf("No encontrado: se puede eclarar\n");
			}
			else{
				printf("Existe id: no se puede declarar\n");
			}
		}
	}
	else{
		printf("DESCONOCIDO\n");
	}
}

int main(int argc, char const *argv[])
{
	FILE * f = fopen(argv[1], "r");
	while(process_line(f) != 1){
		continue;
	}
	fclose(f);
	return 0;
}