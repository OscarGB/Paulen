#include "graph.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]){
	char input[20];
	int vertices, src, dest;

	printf("Number of vertices: ");
	scanf("%d", &vertices);

	graph_p graph = createGraph(vertices, DIRECTED);	

	printf("Displaying %d vertices node.\n", vertices);

	displayGraph(graph);

	fflush(stdout);

	fgets(input, 20, stdin);

    /* Remove trailing newline, if there. */

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

	    /* Remove trailing newline, if there. */

	    if ((strlen(input) > 0) && (input[strlen (input) - 1] == '\n'))
	        input[strlen (input) - 1] = '\0';
	}

	destroyGraph(graph);


	return 0;
}