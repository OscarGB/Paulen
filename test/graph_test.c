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

	graph = createGraph();

	printf("Graph created. Displaying...\n");

	displayGraph(graph);
	/*Adding some nodes without parents*/
	strcpy(str, "a content");
	strcpy(name, "a");
	a = addNode(graph, NULL, 0, name, str);

	strcpy(str, "b content");
	strcpy(name, "b");
	b = addNode(graph, NULL, 0, name, str);
	
	strcpy(str, "c content");
	strcpy(name, "c");
	c = addNode(graph, NULL, 0, name, str);
	
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
	strcpy(str, "d content");
	strcpy(name, "d");
	addNode(graph, list, 2, name, str);
	list[0] = b;
	list[1] = c;
	strcpy(str, "e content");
	strcpy(name, "e");
	e = addNode(graph, list, 2, name, str);
	list[0] = e;
	strcpy(str, "f content");
	strcpy(name, "f");
	addNode(graph, list, 1, name, str);

	printf("Three more nodes added. Displaying...\n\n");
	displayGraph(graph);

	printf("\n");

	destroyGraph(graph);
	printf("Graph destroyed\n");

	return 0;

}