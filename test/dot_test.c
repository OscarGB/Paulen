#include "tabla_simbolos_clases.h"
#include "macros.h"
#include "hash_table.h"
#include "simbolo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void check_simbol(simbolos_p simbol, char* simbolo, char* clase, int deberia_estar){
	
	simbolo_p s = NULL;
	char nombre_ambito_encontrado[100];

	if(deberia_estar){
		if(buscarIdNoCualificado(simbol, simbolo, clase, &s, nombre_ambito_encontrado)){
			printf("OK: %s encontrado en %s\n", simbolo, nombre_ambito_encontrado);
		}
		else{
			printf("ERROR: %s debería encontrarse\n", simbolo);
		}
	}else{
		if(!buscarIdNoCualificado(simbol, simbolo, clase, &s, nombre_ambito_encontrado)){
			printf("OK: %s no encontrado\n", simbolo);
		}
		else{
			printf("ERROR %s no debería encontrarse\n", simbolo);
		}
	}
}

int main(){
	int i;
	simbolos_p simbol = createSimbolos("Test_graph");
	char **padres = (char**)malloc(sizeof(char*)*5);
	for (i = 0; i < 5; i++){
		padres[i] = (char*) malloc(sizeof(char)*10);
	}

	nuevoSimboloEnMain(simbol, "v1", 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,EXPOSED,0,0,0,0,0,0,0,NULL);

	nuevaClase(simbol, NULL, 0, "AA");
	nuevoSimboloEnClase(simbol, "a1", "AA", 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,EXPOSED,0,0,0,0,0,0,0,NULL);
	nuevoSimboloEnClase(simbol, "sa1", "AA", 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,HIDDEN,0,0,0,0,0,0,0,NULL);

	nuevoSimboloEnClase(simbol, "ma1", "AA", 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,EXPOSED,0,0,0,0,0,0,0,NULL);
	iniciaLocalEnClase(simbol, "AA", "ma1", 0,0,0,0);
	nuevoSimboloEnClase(simbol, "ma1", "AA", 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,EXPOSED,0,0,0,0,0,0,0,NULL);
	nuevoSimboloEnClase(simbol, "pmA1", "AA", 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,EXPOSED,0,0,0,0,0,0,0,NULL);
	nuevoSimboloEnClase(simbol, "v1mA1", "AA", 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,EXPOSED,0,0,0,0,0,0,0,NULL);

	check_simbol(simbol, "v1", "AA", 1);
	check_simbol(simbol, "x", "AA", 0);
	check_simbol(simbol, "v1mA1", "AA", 1);
	check_simbol(simbol, "a1", "AA", 1);

	cerrarLocalEnClase(simbol, "AA");

	check_simbol(simbol, "v1mA1", "AA", 0);

	cerrarClase(simbol, "AA", 0,0,0,0);

	nuevoSimboloEnMain(simbol, "f1", 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,EXPOSED,0,0,0,0,0,0,0,NULL);
	iniciaLocal(simbol, "f1");
	nuevoSimboloEnMain(simbol, "f1", 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,EXPOSED,0,0,0,0,0,0,0,NULL);
	nuevoSimboloEnMain(simbol, "pf1", 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,EXPOSED,0,0,0,0,0,0,0,NULL);
	
	check_simbol(simbol, "pf1", "main", 1);
	check_simbol(simbol, "v1", "main", 1);
	check_simbol(simbol, "a1", "main", 0);


	nuevoSimboloEnMain(simbol, "v1f11", 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,EXPOSED,0,0,0,0,0,0,0,NULL);
	
	cerrarLocal(simbol);

	check_simbol(simbol, "v1", "main", 1);
	check_simbol(simbol, "x", "main", 0);



	eliminaSimbolos(simbol);

	for (i = 0; i < 5; i++){
		free(padres[i]);
	}
	free(padres);

	return 0;
}