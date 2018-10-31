#include "tabla_simbolos_clases.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	int i;
	simbolos_p simbol = createSimbolos("ej_clases");
	char **padres = (char**)malloc(sizeof(char*)*5);
	for (i = 0; i < 5; i++){
		padres[i] = (char*) malloc(sizeof(char)*10);
	}

	nuevaClase(simbol, NULL, 0, "AA");

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

	strcpy(padres[0],"AA");
	nuevaClase(simbol, padres, 1, "BB");
	
	tablaSimbolosClasesToDot(simbol);

	eliminaSimbolos(simbol);

	for (i = 0; i < 5; i++){
		free(padres[i]);
	}

	return 0;
}