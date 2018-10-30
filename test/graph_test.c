#include "graph.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	graph_p graph;
	node_p a, b, c, e;
	node_p list[5];
	char str[20];
	char name[5];

	graph = createGraph("grafo 1");

	printf("Graph %s created. Displaying...\n", graph->name);

	displayGraph(graph);
	/*Adding some nodes without parents*/
	strcpy(name, "a");
	a = addNode(graph, NULL, 0, name);

	strcpy(name, "b");
	b = addNode(graph, NULL, 0, name);
	
	strcpy(name, "c");
	c = addNode(graph, NULL, 0, name);
	
	printf("\n");

	printf("Three nodes without parents created. Displaying...\n\n");
	displayGraph(graph);

	printf("\n");


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
	addNode(graph, list, 2, name);
	list[0] = b;
	list[1] = c;
	strcpy(name, "e");
	e = addNode(graph, list, 2, name);
	list[0] = e;
	strcpy(name, "f");
	addNode(graph, list, 1, name);

	printf("Three more nodes added. Displaying...\n\n");
	displayGraph(graph);

	printf("\n");

	destroyGraph(graph);
	printf("Graph destroyed\n");

	return 0;

}