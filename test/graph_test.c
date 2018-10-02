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
	a = addNode(graph, NULL, 0, &name[0], &str[0]);

	strcpy(str, "b content");
	strcpy(name, "b");
	b = addNode(graph, NULL, 0, &name[0], &str[0]);
	
	strcpy(str, "c content");
	strcpy(name, "c");
	c = addNode(graph, NULL, 0, &name[0], &str[0]);
	
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
	list[0] = a;
	list[1] = b;
	strcpy(str, "d content");
	strcpy(name, "d");
	addNode(graph, list, 2, &name[0], &str[0]);
	list[0] = b;
	list[1] = c;
	strcpy(str, "e content");
	strcpy(name, "e");
	e = addNode(graph, list, 2, &name[0], &str[0]);
	list[0] = e;
	strcpy(str, "f content");
	strcpy(name, "f");
	addNode(graph, list, 1, &name[0], &str[0]);

	printf("Three more nodes added. Displaying...\n\n");
	displayGraph(graph);

	printf("\n");

	destroyGraph(graph);
	printf("Graph destroyed\n");

	return 0;

}