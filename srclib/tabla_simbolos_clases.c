#include "tabla_simbolos_clases.h"
#include "simbolo.h"
#include "hash_table.h"
#include <string.h>

/*Crea la estructura y reserva toda la memoria necesaria
iniciarTablasSimbolosClases()*/
simbolos_p createSimbolos(char* name){
	simbolos_p sim = (simbolos_p)malloc(sizeof(simbolos_t));
	sim->graph = createGraph(name);
	sim->main_principal = ht_new("main");
	sim->main_local = NULL;

	return sim;
}

/*Elimina la estructura y libera toda la memoria ocupada*/
void eliminaSimbolos(simbolos_p simbolos){
	if(simbolos->main_local) ht_del_hash_table(simbolos->main_local);
	char** keys;
	int i;
	list_elem_p lelem = simbolos->graph->nodes_list->head;
	while(lelem != NULL){
		if(lelem->node->local != NULL){
			keys =  ht_get_keys(lelem->node->local);
			i = 0;
			while(keys[i] != NULL){
				eliminaSimbolo(ht_search(lelem->node->local, keys[i]));
				i++;
			}
			free(keys);
		}
		keys =  ht_get_keys(lelem->node->principal);
		i = 0;
		while(keys[i] != NULL){
			eliminaSimbolo(ht_search(lelem->node->principal, keys[i]));
			i++;
		}
		free(keys);
		lelem=lelem->next;
	}
	if(simbolos->main_local != NULL){
		keys =  ht_get_keys(simbolos->main_local);
		i = 0;
		while(keys[i] != NULL){
			eliminaSimbolo(ht_search(simbolos->main_local, keys[i]));
			i++;
		}
		free(keys);
	}
	keys =  ht_get_keys(simbolos->main_principal);
	i = 0;
	while(keys[i] != NULL){
		eliminaSimbolo(ht_search(simbolos->main_principal, keys[i]));
		i++;
	}
	free(keys);

	ht_del_hash_table(simbolos->main_principal);
	destroyGraph(simbolos->graph);
	free(simbolos);
}

/*Inserta una clase en el gafo
abrirClase() y abrirClaseHeredaN(), para una clase que no hereda, poner numparents a 0 y parents a NULL*/
void nuevaClase(simbolos_p simbolos, char** parents, int numparents, char* name){
	node_p padres[numparents];
	for(int i = 0; i<numparents;i++){
		padres[i] = searchNode(simbolos->graph, parents[i]);
	}
	addNode(simbolos->graph, padres, numparents, name);
}

/*Cierra una clase*/
void cerrarClase(simbolos_p simbolos,
				char* name, 
				int n_atributos_clase, 
				int n_atributos_instancia,
				int num_metodos_sobreescribibles,
				int num_metodos_no_sobreescribibles){
	/*-------------------------------------------------------------------------------------------------------TODO*/
	return;
}

/*Cierra el ambito local de una clase
tablaSimbolosClasesCerrarAmbitoEnClase()*/
void cerrarLocalEnClase(simbolos_p simbolos, char* nombre_clase){
	eliminaLocalEnClase(simbolos, nombre_clase);
}

/*Inserta un simbolo en una clase concreta*/
/*TODO falta el prefijo de clase*/
void nuevoSimboloEnClase(simbolos_p simbolos, char* simbolo_a_insertar,  
	char* nombre_clase, 			int clase,
	int tipo,                        int estructura,
	int direcciones,                    int numero_parametros,
	int numero_variables_locales,        int posicion_variable_local,
	int posicion_parametro,            int dimension,
	int tamanio,                    int filas,
	int columnas,                    int capacidad,
	int numero_atributos_clase,            int numero_atributos_instancia,
	int numero_metodos_sobreescribibles,    int numero_metodos_no_sobreescribibles,
	int tipo_acceso,                  int tipo_miembro, 
	int posicion_atributo_instancia,        int posicion_metodo_sobreescribible,
	int num_acumulado_atributos_instancia,    int num_acumulado_metodos_sobreescritura,
	int posicion_acumulada_atributos_instancia,
	int posicion_acumulada_metodos_sobreescritura,
	int * tipo_args
){
	simbolo_p s = createSimbolo(simbolo_a_insertar,
								clase,
								tipo,
								estructura,
								direcciones,
								numero_parametros,
								numero_variables_locales,
								posicion_variable_local,
								posicion_parametro,
								dimension,
								tamanio,
								filas,
								columnas,
								capacidad,
								numero_atributos_clase,
								numero_atributos_instancia,
								numero_metodos_sobreescribibles,
								numero_metodos_no_sobreescribibles,
								tipo_acceso,
								tipo_miembro, 
								posicion_atributo_instancia,
								posicion_metodo_sobreescribible,
								num_acumulado_atributos_instancia,
								num_acumulado_metodos_sobreescritura,
								posicion_acumulada_atributos_instancia,
								posicion_acumulada_metodos_sobreescritura,
								tipo_args);
	node_p node = searchNode(simbolos->graph, nombre_clase);
	if(node->local != NULL){
		ht_insert(node->local, simbolo_a_insertar, s);
	}
	else{
		ht_insert(node->principal, simbolo_a_insertar, s);
	}
}

/*Inserta un simbolo en el main
insertarTablaSimbolosAmbitos()*/
/*TODO falta el prefijo de clase*/
void nuevoSimboloEnMain(simbolos_p simbolos, char* simbolo_a_insertar,  
	int clase,
	int tipo,                        int estructura,
	int direcciones,                    int numero_parametros,
	int numero_variables_locales,        int posicion_variable_local,
	int posicion_parametro,            int dimension,
	int tamanio,                    int filas,
	int columnas,                    int capacidad,
	int numero_atributos_clase,            int numero_atributos_instancia,
	int numero_metodos_sobreescribibles,    int numero_metodos_no_sobreescribibles,
	int tipo_acceso,                  int tipo_miembro, 
	int posicion_atributo_instancia,        int posicion_metodo_sobreescribible,
	int num_acumulado_atributos_instancia,    int num_acumulado_metodos_sobreescritura,
	int posicion_acumulada_atributos_instancia,
	int posicion_acumulada_metodos_sobreescritura,
	int * tipo_args
){
	simbolo_p s = createSimbolo(simbolo_a_insertar,
								clase,
								tipo,
								estructura,
								direcciones,
								numero_parametros,
								numero_variables_locales,
								posicion_variable_local,
								posicion_parametro,
								dimension,
								tamanio,
								filas,
								columnas,
								capacidad,
								numero_atributos_clase,
								numero_atributos_instancia,
								numero_metodos_sobreescribibles,
								numero_metodos_no_sobreescribibles,
								tipo_acceso,
								tipo_miembro, 
								posicion_atributo_instancia,
								posicion_metodo_sobreescribible,
								num_acumulado_atributos_instancia,
								num_acumulado_metodos_sobreescritura,
								posicion_acumulada_atributos_instancia,
								posicion_acumulada_metodos_sobreescritura,
								tipo_args);
	if(simbolos->main_local != NULL){
		ht_insert(simbolos->main_local, simbolo_a_insertar, s);
	}
	else{
		ht_insert(simbolos->main_principal, simbolo_a_insertar, s);
	}
}

/*Comprueba si un simbolo esta en una clase*/
/*TODO falta el prefijo de clase*/
int checkSimboloEnClase(simbolos_p simbolos, char* nombre_clase, char* simbolo_a_comprobar, int ambito){
	hash_table_p h = getHT(simbolos->graph, nombre_clase, ambito);
	return ht_isin(h, simbolo_a_comprobar);
}

/*Crea la tabla local
abrirAmbitoClase()*/
void iniciaLocal(simbolos_p simbolos, char* nombre){
	if(simbolos->main_local) ht_del_hash_table(simbolos->main_local);
	simbolos->main_local = ht_new(nombre);
}

/*Elimina la tabla local*/
void eliminaLocal(simbolos_p simbolos){
	char **keys =  ht_get_keys(simbolos->main_local);
	int i = 0;
	while(keys[i] != NULL){
		eliminaSimbolo(ht_search(simbolos->main_local, keys[i]));
		i++;
	}
	free(keys);
	if(simbolos->main_local) ht_del_hash_table(simbolos->main_local);
	simbolos->main_local = NULL;
}

/*Cierra local del main*/
void cerrarLocal(simbolos_p simbolos){
	eliminaLocal(simbolos);
}

/*Crea la tabla local de una clase
tablaSimbolosClasesAbrirAmbitoEnClase()*/
void iniciaLocalEnClase(simbolos_p simbolos,
						char* nombre_clase, 
						char* nombre_ambito,
						int categoria_ambito,
						int acceso_metodo,
						int tipo_metodo,
						int posicion_metodo_sobre){
	createHTLocal(simbolos->graph, nombre_clase, nombre_ambito);
}

/*Elimina la tabla local de una clase*/
void eliminaLocalEnClase(simbolos_p simbolos, char* nombre_clase){
	node_p node = searchNode(simbolos->graph, nombre_clase);
	char **keys =  ht_get_keys(node->local);
	int i = 0;
	while(keys[i] != NULL){
		eliminaSimbolo(ht_search(node->local, keys[i]));
		i++;
	}
	free(keys);
	deleteHTLocal(simbolos->graph, nombre_clase);
}

/*Devuelve todos los simbolos de main*/
char** getSimbolos(simbolos_p simbolos, int ambito){
	if(ambito == LOCAL){
		return ht_get_keys(simbolos->main_local);
	}
	return ht_get_keys(simbolos->main_principal);
}

/*Devuelve todos los simbolos en una clase*/
char** getSimbolosEnClase(simbolos_p simbolos, char* nombre_clase, int ambito){
	hash_table_p h = getHT(simbolos->graph, nombre_clase, ambito);
	return ht_get_keys(h);
}

/*Imprime el grafo linalizado en formato .dot*/
void printLinearGraph(FILE * file, graph_p graph){
	list_elem_p current = NULL;
	list_elem_p next = NULL;
	char * node_name;
	char* next_name;

	current = graph->nodes_list->head;
	next = current->next;

	/*Declaracion de nodos*/

	while(current) {

		node_name = current->node->name;

		fprintf(file, "\t%sL [label=\"%s\"][shape=oval];\n", node_name, node_name);

		current = next;
		if(current)
			next = current->next;

	}

	/*Relaciones*/	
	current = graph->nodes_list->head;
	next = current->next;

	while(next) {

		node_name = current->node->name;
		next_name = next->node->name;

		fprintf(file, "\t%sL -> %sL;\n", node_name, next_name);

		current = next;
		next = current->next;

	}

}

/*Imprime el grafo clase a clase en formato .dot*/
void printDiagram(FILE * file, graph_p graph, simbolos_p tabla_simbolos) {
	list_elem_p current = NULL;
	list_elem_p next = NULL;
	char * node_name;
	char* next_name;
	char* parent_name;
	int i = 0;
	char ** simbolos_clase;

	current = graph->nodes_list->head;
	next = current->next;

	/*Declaracion de nodos*/

	while(current) {

		node_name = current->node->name;

		simbolos_clase = getSimbolosEnClase(tabla_simbolos, node_name, PRINCIPAL);
		i = 0;

		fprintf(file, "\t%s [label=\"{%s|%s", node_name, node_name, node_name);

		while(simbolos_clase[i] != NULL){
			fprintf(file, "\\l");
			fprintf(file, "%s", simbolos_clase[i]);
			i++;
		}

		fprintf(file, "}\"][shape=record];\n");

		free(simbolos_clase);

		current = next;
		if(current)
			next = current->next;

	}

	/*Relaciones con los padres*/
	current = graph->nodes_list->head;
	next = current->next;

	while(next) {

		node_name = current->node->name;

		if(current->node->numparents > 0){
			for(i=0; i<current->node->numparents; i++){
				parent_name = current->node->padres[i];

				fprintf(file, "\t%s -> %s;\n", node_name, parent_name);
			}
		}

		current = next;
		next = current->next;

	}
}

/*Crea un fichero .dot con el nombre del grafo*/
simbolos_p tablaSimbolosClasesToDot(simbolos_p tabla_simbolos){
	FILE * dot = NULL;
	char* file = NULL;
	char* name = tabla_simbolos->graph->name;

	file = (char*)malloc((strlen(tabla_simbolos->graph->name)+5) * sizeof(char));

	strcpy(file, tabla_simbolos->graph->name);

	strcat(file, ".dot");

	dot = fopen(file, "w+");
	if(!dot){
		exit(1);
	}

	fprintf(dot, "digraph %s { rankdir=BT; \n", name);
	fprintf(dot, "\tedge [arrowhead = empty]\n");

	/*Imprime el grafo clase a clase*/
	printDiagram(dot, tabla_simbolos->graph, tabla_simbolos);

	fprintf(dot, "\tedge [arrowhead = normal]\n");
	/*Imprime grafo linealizado*/
	printLinearGraph(dot, tabla_simbolos->graph);
	fprintf(dot, "}\n");

	// fprintf(stdout, "File: %s\n", file);

	fclose(dot);

	free(file);

	return NULL;
}

/*Cierra la tabla de simbolos de clases*/
void cerrarTablaSimbolosClases(simbolos_p simbolos){
	return;
}

/*Comprueba los accesos de un simbolo concreto*/
int aplicarAccesos(simbolos_p simbolos, char * clase_actual, 
					char * clase_variable_encontrada, simbolo_p s){
	// Caso MAIN
	if(strcmp(clase_actual, "main") == 0){
		if (s->tipo_acceso == HIDDEN) return ERROR;
		else{
			return OK;
		}
	}
	else{ // Caso en una clase no main
		if(s->tipo_acceso == HIDDEN){
			if(strcmp(clase_actual, clase_variable_encontrada) == 0){
				return OK; // En la propia clase
			}
			else{
				return ERROR;
			}
		}
		else if(s->tipo_acceso == EXPOSED){
			return OK; // Si expuesto siempre OK
		}
		else if(s->tipo_acceso == SECRET){
			node_p node = searchNode(simbolos->graph, clase_actual);
			int i = 0;
			while(node->padres[i] != NULL){
                if(strcmp(clase_actual, node->padres[i]) == 0){
                	return OK;
                }
                i++;
            }
            return ERROR;
		}
	}
}

/*Busca un simbolo en la jerarquia de clases*/
/*TODO falta todo lo de los prefijos, esto es el esqueleto*/
int buscarIdEnJerarquiaDesdeClase( simbolos_p simbolos, 
									char * simbolo_a_buscar,
                          			char * nombre_clase, 
  									simbolo_p *s,
  									char * nombre_ambito_encontrado){
	node_p node = searchNode(simbolos->graph, nombre_clase);
	if(node->local != NULL){
		if(ht_isin(node->local, simbolo_a_buscar)){
			*s = ht_search(node->local, simbolo_a_buscar);
			strcpy(nombre_ambito_encontrado, ht_get_name(node->local));
			return aplicarAccesos(simbolos, nombre_clase, nombre_ambito_encontrado, *s);
		}
	}
	if(ht_isin(node->principal, simbolo_a_buscar)){
		*s = ht_search(node->principal, simbolo_a_buscar);
		strcpy(nombre_ambito_encontrado, nombre_clase);
		return aplicarAccesos(simbolos, nombre_clase, nombre_clase, *s);
	}
	else{
		int i = 0;
		while(node->padres[i] != NULL){
			node = searchNode(simbolos->graph, node->padres[i]);
            if(ht_isin(node->principal, simbolo_a_buscar)){
				*s = ht_search(node->principal, simbolo_a_buscar);
				strcpy(nombre_ambito_encontrado, node->padres[i]);
				return aplicarAccesos(simbolos, nombre_clase, node->padres[i], *s);
			}
			i++;
        }
        if(ht_isin(node->principal, simbolo_a_buscar)){
			*s = ht_search(simbolos->main_principal, simbolo_a_buscar);
			strcpy(nombre_ambito_encontrado, "main");
			return aplicarAccesos(simbolos, nombre_clase, "main", *s);
		}
	}
	return ERROR;
}

/*Busca un id no cualificado*/
/*TODO falta todo lo de los prefijos, esto es el esqueleto*/
int buscarIdNoCualificado(  simbolos_p simbolos,
                     		char * nombre_simbolo, char * clase_actual,
                    		simbolo_p * s, 
							char * nombre_ambito_encontrado){
	if(strcmp(clase_actual, "main") == 0){
		if(simbolos->main_local != NULL){
			if(ht_isin(simbolos->main_local, nombre_simbolo)){
				*s = ht_search(simbolos->main_local, nombre_simbolo);
				strcpy(nombre_ambito_encontrado, ht_get_name(simbolos->main_local));
				return aplicarAccesos(simbolos, clase_actual, nombre_ambito_encontrado, *s);
			}
		}
		if(ht_isin(simbolos->main_principal, nombre_simbolo)){
			*s = ht_search(simbolos->main_principal, nombre_simbolo);
			strcpy(nombre_ambito_encontrado, "main");
			return aplicarAccesos(simbolos, clase_actual, "main", *s);
		}
		else{
			return ERROR;
		}
	}
	else{
		if(OK == buscarIdEnJerarquiaDesdeClase(simbolos, nombre_simbolo, clase_actual, s, nombre_ambito_encontrado))
			return OK;
		else{
			if(ht_isin(simbolos->main_principal, nombre_simbolo)){
				*s = ht_search(simbolos->main_principal, nombre_simbolo);
				strcpy(nombre_ambito_encontrado, "main");
				return aplicarAccesos(simbolos, clase_actual, "main", *s);
			}
		}
	}
}


