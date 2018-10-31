#include "tabla_simbolos_clases.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	int i;
	simbolos_p simbol = createSimbolos("Test_graph");
	char **padres = (char**)malloc(sizeof(char*)*5);
	for (i = 0; i < 5; i++){
		padres[i] = (char*) malloc(sizeof(char)*10);
	}

	nuevaClase(simbol, NULL, 0, "a");
	nuevaClase(simbol, NULL, 0, "b");
	nuevaClase(simbol, NULL, 0, "c");

	/*Adding children*/
	/*
	a --- d
	    /
	   /
	  /
	b --- e --- f
	    /   
	   /
      /
	c
	*/

	strcpy(padres[0],"b");
	strcpy(padres[1],"a");
	nuevaClase(simbol, padres, 2, "d");

	strcpy(padres[0],"b");
	strcpy(padres[1],"c");
	nuevaClase(simbol, padres, 2, "e");

	strcpy(padres[0],"e");
	nuevaClase(simbol, padres, 1, "f");

	nuevoSimboloEnClase(simbol, "a", "sim a1", PRINCIPAL);
	nuevoSimboloEnClase(simbol, "b", "sim b1", PRINCIPAL);
	nuevoSimboloEnClase(simbol, "c", "sim c1", PRINCIPAL);
	nuevoSimboloEnClase(simbol, "d", "sim d1", PRINCIPAL);
	nuevoSimboloEnClase(simbol, "e", "sim e1", PRINCIPAL);
	nuevoSimboloEnClase(simbol, "f", "sim f1", PRINCIPAL);

	tablaSimbolosClasesToDot(simbol);

	eliminaSimbolos(simbol);

	for (i = 0; i < 5; i++){
		free(padres[i]);
	}

	return 0;
}