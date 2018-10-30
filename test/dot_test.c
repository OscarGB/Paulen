#include "tabla_simbolos_clases.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	simbolos_p simbol = createSimbolos("Test_graph");
	node_p a, b, c, e;
	node_p list[5];
	char str[20];
	char name[5];

	// nuevaClase(simbol, NULL, 0, "a");
	// nuevaClase(simbol, NULL, 0, "b");
	// nuevaClase(simbol, NULL, 0, "c");


	strcpy(name, "a");
	a = addNode(simbol->graph, NULL, 0, name);

	strcpy(name, "b");
	b = addNode(simbol->graph, NULL, 0, name);
	
	strcpy(name, "c");
	c = addNode(simbol->graph, NULL, 0, name);

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

	list[0] = b;
	list[1] = a;
	strcpy(name, "d");
	addNode(simbol->graph, list, 2, name);
	list[0] = b;
	list[1] = c;
	strcpy(name, "e");
	e = addNode(simbol->graph, list, 2, name);
	list[0] = e;
	strcpy(name, "f");
	addNode(simbol->graph, list, 1, name);

	nuevoSimboloEnClase(simbol, "a", "sim1", PRINCIPAL);

	tablaSimbolosClasesToDot(simbol);

	eliminaSimbolos(simbol);

	return 0;
}