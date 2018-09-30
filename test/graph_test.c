#include "graph.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*int main(int argc, char* argv[]){
	char input[20];
	int vertices, src, dest;

	printf("Number of vertices: ");
	scanf("%d", &vertices);

	graph_p graph = createGraph(vertices, DIRECTED);	

	printf("Displaying %d vertices node.\n", vertices);

	displayGraph(graph);

	fflush(stdout);

	fgets(input, 20, stdin);


    if ((strlen(input) > 1) && (input[strlen (input) - 1] == '\n'))
        input[strlen (input) - 1] = '\0';

	while(strncmp(input, "exit", strlen("exit")) != 0 || strncmp(input, "EXIT", strlen("EXIT")) != 0){
		if(strncmp(input, "add edge", strlen("add edge")) == 0){
			printf("Source: ");
			scanf("%d", &src);
			printf("Dest: ");
			scanf("%d", &dest);

			addEdge(graph, src, dest);
			printf("Edge %d-%d added.\n", src, dest);

			displayGraph(graph);
		}

		fflush(stdout);

		fgets(input, 20, stdin);


	    if ((strlen(input) > 0) && (input[strlen (input) - 1] == '\n'))
	        input[strlen (input) - 1] = '\0';
	}

	destroyGraph(graph);


	return 0;
}*/

int main(){
	graph_p graph;
	node_p node, a, b, c, d, e, f;
	node_p list[5];

	graph = createGraph();

	printf("Graph created. Displaying...\n");

	displayGraph(graph);

	/*Adding some nodes without parents*/
	a = addNode(graph, NULL, "a", "a content");
	b = addNode(graph, NULL, "b", "b content");
	c = addNode(graph, NULL, "c", "c content");

	printf("Three nodes without parents created. Displaying...\n");
	displayGraph(graph);

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
	list = {a, b};
	d = addNode(graph, list, "d", "d content");
	list = {b,c};
	e = addNode(graph, list, "e", "e content");
	list = {e};
	f = addNode(graph, list, "f", "f content");

	printf("Three more nodes added. Displaying...\n");
	displayGraph(graph);

	destroyGraph(graph);
	printf("Graph destroyed\n");

	return 0;

}