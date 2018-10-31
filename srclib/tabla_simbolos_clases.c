#include "tabla_simbolos_clases.h"
#include "simbolo.h"
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
void nuevoSimboloEnClase(simbolos_p simbolos, char* nombre_clase, char* simbolo_a_insertar, int ambito){
	hash_table_p h = getHT(simbolos->graph, nombre_clase, ambito);
	ht_insert(h, simbolo_a_insertar, NULL);
}

/*Inserta un simbolo en el main
insertarTablaSimbolosAmbitos()*/
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
	if(simbolos->main_local) ht_del_hash_table(simbolos->main_local);
	simbolos->main_local = NULL;
}

/*Crea la tabla local de una clase
tablaSimbolosClasesAbrirAmbitoEnClase()*/
void iniciaLocalEnClase(simbolos_p simbolos,
						char* nombre_clase, 
						char* nombre_ambito,
						int categoria_ambito,
						int acceso_metodo,
						int tipo_metodo,
						int posicion_metodo_sobre,
						int tamanio){
	createHTLocal(simbolos->graph, nombre_clase, nombre_ambito);
}

/*Elimina la tabla local de una clase*/
void eliminaLocalEnClase(simbolos_p simbolos, char* nombre_clase){
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

void cerrarTablaSimbolosClases(simbolos_p simbolos){
	return;
}