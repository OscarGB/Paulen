#include "padres.h"
#include <string.h>
#include <stdio.h>

#define MAX_PADRES 100

/* Comprueba que un vector está vacío */
int vacio(char** list, int size){
	for (int i = 0; i < size; i++){
		if(list[i] != NULL){
			return 0;
		}
	}
	return 1;
}

/* Comprueba que un vector de vectores está vacío */
int vacio2D(char*** list, int size){
	for(int i = 0; i < size; i++){
		if(list[i] == NULL){
			continue;
		}
		if(list[i][0] != NULL){
			return 0;
		}
	}
	return 1;
}

/* Devuelve la lista de padres directos */
char** get_padres(graph_p grafo, char** padres, int size){
	
	char** todos_los_padres = (char**) calloc(MAX_PADRES, sizeof(char*));

	int tamano_padres = 0;

	char*** padres_de_padres = (char***) calloc(size, sizeof(char**));

	if(size == 0){
		free(padres_de_padres);
		return todos_los_padres;
	}

	int flag = 0;

	int graph_size = grafo->num_nodes;

	list_elem_p elemento = grafo->nodes_list->head;

	for(int i = 0; i < graph_size; i++){
		if(vacio(padres, size) && vacio2D(padres_de_padres, size)){
			free(padres_de_padres);
			free(todos_los_padres);
			return todos_los_padres;
		}

		if(elemento == NULL){
			free(padres_de_padres);
			free(todos_los_padres);
			return NULL;
		}

		flag = 0;

		for(int j = 0; j < size; j++){
			if(padres[j] != NULL && strcmp(padres[j], elemento->node->name) == 0){
				padres_de_padres[j] = elemento->node->padres;
				todos_los_padres[tamano_padres] = elemento->node->name;
				tamano_padres++;
				padres[j] = NULL;
				flag = 1;
				break;
			}
		}

		
		for(int j = 0; j < size; j++){
			if(padres_de_padres[j] == NULL) continue;
			if(strcmp(padres_de_padres[j][0], elemento->node->name) == 0){
				if(flag == 0){
					todos_los_padres[tamano_padres] = elemento->node->name;
					tamano_padres++;
					flag = 1;
				}
				padres_de_padres[j]++;
			}
		}

		elemento = elemento->next;
	}

	free(padres_de_padres);
	free(todos_los_padres);
	return NULL;


}