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
	sim->metodos = (metodos_p)malloc(sizeof(metodos_t));
	sim->metodos->nombres = (char**)malloc(sizeof(char*));
	sim->metodos->num = 0;

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
	for(i = 0; i < simbolos->metodos->num; i++){
		free(simbolos->metodos->nombres[i]);
	}
	free(simbolos->metodos->nombres);
	free(simbolos->metodos);
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
	node_p nuevo = searchNode(simbolos->graph, name);
	nuevo->num_ms = simbolos->metodos->num;
}

/*Devuelve todos los simbolos de una clase*/
void** getSimbolosObjetoEnClase(simbolos_p simbolos, char* nombre_clase, int ambito){
	hash_table_p h = getHT(simbolos->graph, nombre_clase, ambito);
	return ht_get_values(h);
}

/*Cierra una clase*/
void cerrarClase(simbolos_p simbolos,
				char* name, 
				int n_atributos_clase, 
				int n_atributos_instancia,
				int num_metodos_sobreescribibles,
				int num_metodos_no_sobreescribibles){
	/*-------------------------------------------------------------------------------------------------------TODO*/
	node_p node = searchNode(simbolos->graph, name);

	list_elem_p current = NULL;
	list_elem_p next = NULL;
	char * node_name;
	char* next_name;
	char* parent_name;
	int i = 0, tipo, j = 0;
	simbolo_p * simbolos_clase;
	simbolo_p s_actual;
	int ms = 0, mns = 0, ai = 0, ac = 0, len = 0;

	current = simbolos->graph->nodes_list->head;
	next = current->next;


	/*Reservamos memoria para los arrays que almacenaran los nombres
	  de los metodos y los atributos para imprimirlos*/
	if(node->num_ms > 0)
		node->ms = (char**)calloc(sizeof(char*), node->num_ms);
	if(node->num_mns > 0)
		node->mns = (char**)malloc(sizeof(char*) * node->num_mns);
	if(node->num_ai > 0)
		node->ai = (char**)malloc(sizeof(char*) * node->num_ai);
	if(node->num_ac > 0)
		node->ac = (char**)malloc(sizeof(char*) * node->num_ac);

	/*Necesito conseguir todos los simbolos de esta clase*/
	/*simbolo_p * simbolos_clase = getAllSimbolsFromClass(class)*/
	simbolos_clase = (simbolo_p *) getSimbolosObjetoEnClase(simbolos, name, PRINCIPAL);

	i = 0;
	s_actual = simbolos_clase[i];

	while(s_actual){
		switch(s_actual->tipo){
			case MS:
				for(j=0; j < simbolos->metodos->num; j++){
					if(strcmp(simbolos->metodos->nombres[j], s_actual->nombre) == 0){
						node->ms[j] = strdup(s_actual->id);
						break;
					}
				}
				break;

			case MNS:
				(node->mns)[mns] = (char*) malloc(sizeof(char) * strlen(s_actual->id) + 1);
				strcpy((node->mns)[mns], s_actual->id);
				mns++;
				break;

			case AC:
				(node->ac)[ac] = (char*) malloc(sizeof(char) * strlen(s_actual->id) + 1);
				strcpy((node->ac)[ac], s_actual->id);
				ac++;
				break;

			case AI:
				(node->ai)[ai] = (char*) malloc(sizeof(char) * strlen(s_actual->id) + 1);
				strcpy((node->ai)[ai], s_actual->id);
				ai++;
				break;
		}
		i++;
		s_actual = simbolos_clase[i];
	}


	/*Liberamos simbolos_clase???*/
	i = 0;
	s_actual = simbolos_clase[i];

	while(s_actual != NULL){
		// eliminaSimbolo(s_actual);
		i++;
		s_actual = simbolos_clase[i];
	}
	free(simbolos_clase);

	return;
}

/*Cierra el ambito local de una clase
tablaSimbolosClasesCerrarAmbitoEnClase()*/
void cerrarLocalEnClase(simbolos_p simbolos, char* nombre_clase){
	eliminaLocalEnClase(simbolos, nombre_clase);
}


/*Concatena el simbolo al nombre del ambito, con una _ en medio*/
char * addPrefijo(char * nombre_ambito, char * simbolo) {
	char* nombre_prefijo = NULL;
	char * underscore = "_";

	/*Reservamos memoria para el nombre del simbolo: clase_nombreSimbolo*/
	nombre_prefijo = (char *)malloc(sizeof(char) * (strlen(nombre_ambito) + 1 + strlen(simbolo) + 1)); 
	strcpy(nombre_prefijo, nombre_ambito);
	strcat(nombre_prefijo, "_");
	strcat(nombre_prefijo, simbolo);

	return nombre_prefijo;
}

/*Crea el nombre de una funcion intercalando los parametros con @.
El resultado debe concatenarse al resto del nombre (ambito + simbolo)
Se reserva memoria*/
char * crearNombreFuncion(char* simbolo_a_insertar, int num_parametros, int * tipo_args){
	int i;
	char buffer[2];
	char * resultado = (char *)malloc(sizeof(char) * (strlen(simbolo_a_insertar) + num_parametros * 2 + 1));
	strcpy(resultado, simbolo_a_insertar);
	for(i = 0; i < num_parametros; i++){
		strcat(resultado, "@");
		sprintf(buffer, "%d", tipo_args[i]);
		strcat(resultado, buffer);
	}
	return resultado;
}

/*Inserta un simbolo en una clase concreta*/
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
	char * nombre_prefijo = NULL;
	char * nombre_ambito = NULL;
	int flag = 0, i = 0;
	node_p node = searchNode(simbolos->graph, nombre_clase);

	if(tipo == FUNCION || tipo == MS || tipo == MNS) {
		simbolo_a_insertar = crearNombreFuncion(simbolo_a_insertar, numero_parametros, tipo_args);
	}
	if(!node->local){
		switch(tipo){
			case MS:
				for(i = 0; i < simbolos->metodos->num; i++){
					if(strcmp(simbolo_a_insertar, simbolos->metodos->nombres[i]) == 0){
						flag = 1;
						break;
					}
				}
				if(!flag){
					simbolos->metodos->nombres = (char**)realloc(simbolos->metodos->nombres, sizeof(char*)*(simbolos->metodos->num + 1));
					simbolos->metodos->nombres[simbolos->metodos->num] = strdup(simbolo_a_insertar);
					simbolos->metodos->num++; 
					node->num_ms++;
				}	
				break;
			case MNS:
				node->num_mns++;
				break;
			case AI:
				node->num_ai++;
				break;
			case AC:
				node->num_ac++;
				break;
		}
	}

	/*Metemos los parametros de la funcion en el nombre del simbolo
	ATENCION: sobreescribimos simbolo_a_insertar*/

	nombre_ambito = getAmbito(node);

	nombre_prefijo = addPrefijo(nombre_ambito, simbolo_a_insertar);
	simbolo_p s = createSimbolo(nombre_prefijo,
								simbolo_a_insertar,
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
	/*Nuestro simbolo guarda una copia del nombre_prefijo con reserva y de simbolo_a_insertar*/


	if(node->local != NULL){
		ht_insert(node->local, nombre_prefijo, s);
	}
	else{
		ht_insert(node->principal, nombre_prefijo, s);
	}
	free(nombre_prefijo);
	// if(tipo == MNS) free(simbolo_a_insertar);
	if(tipo == FUNCION || tipo == MS || tipo == MNS)
		free(simbolo_a_insertar);
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
	char * main_name = "main";
	char * nombre_prefijo = NULL;
	char * nombre_ambito = NULL;

	/*Metemos los parametros de la funcion en el nombre del simbolo
	ATENCION: sobreescribimos simbolo_a_insertar*/
	if(tipo == FUNCION) {
		simbolo_a_insertar = crearNombreFuncion(simbolo_a_insertar, numero_parametros, tipo_args);
	}

	if(simbolos->main_local) {
		nombre_ambito = ht_get_name(simbolos->main_local);
	}
	else {
		nombre_ambito = main_name;
	}

	nombre_prefijo = addPrefijo(nombre_ambito, simbolo_a_insertar);

	simbolo_p s = createSimbolo(nombre_prefijo,
								simbolo_a_insertar,
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
		ht_insert(simbolos->main_local, nombre_prefijo, s);
	}
	else{
		ht_insert(simbolos->main_principal, nombre_prefijo, s);
	}
	free(nombre_prefijo);
	if(tipo == FUNCION)
		free(simbolo_a_insertar);
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

/*Devuelve todos los nombres de simbolos en una clase*/
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

void printTestNASM(FILE * file, graph_p graph, simbolos_p tabla_simbolos){
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
	/*Itera sobre clases linealizadas*/
	while(current) {

		node_name = current->node->name;

		fprintf(file, "\n;CLASE %s\n\n", node_name);

		fprintf(file, "\n;METODOS SOBREESCRIBIBLES\n\n");
		simbolos_clase = current->node->ms;

		for(i = 0; i < current->node->num_ms; i++){
			fprintf(file, "\t\t%s\n", simbolos_clase[i]);
		}

		fprintf(file, "\n;ATRIBUTOS DE CLASE\n\n");
		simbolos_clase = current->node->ac;
		
		for(i = 0; i < current->node->num_ac; i++){
			fprintf(file, "\t\t%s\n", simbolos_clase[i]);
		}


		// free(simbolos_clase);
		current = next;
		if(current)
			next = current->next;
	}
}

void printGlobalHeaderNASM(FILE * file, graph_p graph, simbolos_p tabla_simbolos){
	list_elem_p current = NULL;
	list_elem_p next = NULL;
	char * node_name;
	char* next_name;
	char* parent_name;
	int i = 0;
	char ** simbolos_clase;


	fprintf(file, "\tglobal ");

	/*Metodos sobreescribibles*/

	/*Itera sobre clases linealizadas*/
	current = graph->nodes_list->head;
	next = current->next;
	while(current) {

		simbolos_clase = current->node->ms;

		for(i = 0; i < current->node->num_ms; i++){
			if(simbolos_clase[i] != NULL)
				fprintf(file, "_%s, ", simbolos_clase[i]);
		}

		current = next;
		if(current)
			next = current->next;
	}

	fprintf(file, "_no_defined_method, ");

	/*Metodos no sobreescribibles*/

	/*Itera sobre clases linealizadas*/
	current = graph->nodes_list->head;
	next = current->next;
	while(current) {

		simbolos_clase = current->node->mns;

		for(i = 0; i < current->node->num_mns; i++){
			fprintf(file, "_%s, ", simbolos_clase[i]);
		}

		current = next;
		if(current)
			next = current->next;
	}

	fprintf(file, "_set_offsets, _create_ms_table, ");

	/*Offsets ms*/

	/*Itera sobre clases linealizadas*/
	// current = graph->nodes_list->head;
	// next = current->next;
	// while(current) {

	// 	simbolos_clase = current->node->ms;

	// 	for(i = 0; i < current->node->num_ms; i++){
	// 		fprintf(file, "_offset_%s, ", simbolos_clase[i]);
	// 	}

	// 	current = next;
	// 	if(current)
	// 		next = current->next;
	// }
	for(i=0; i < tabla_simbolos->metodos->num; i++){
		fprintf(file, "_offset_%s, ", tabla_simbolos->metodos->nombres[i]);
	}

	/*Offsets ai*/

	/*Itera sobre clases linealizadas*/
	current = graph->nodes_list->head;
	next = current->next;
	while(current) {

		simbolos_clase = current->node->ai;

		for(i = 0; i < current->node->num_ai; i++){
			fprintf(file, "_offset_%s, ", simbolos_clase[i]);
		}

		current = next;
		if(current)
			next = current->next;
	}

	/*Clases*/
	current = graph->nodes_list->head;
	next = current->next;
	while(current) {
		node_name = current->node->name;
		
		fprintf(file, "_%s, ", node_name);	

		current = next;
		if(current)
			next = current->next;
	}

	/*Atributos clase*/

	/*Itera sobre clases linealizadas*/
	current = graph->nodes_list->head;
	next = current->next;
	while(current) {

		simbolos_clase = current->node->ac;

		for(i = 0; i < current->node->num_ac; i++){
			fprintf(file, "_%s, ", simbolos_clase[i]);
		}

		current = next;
		if(current)
			next = current->next;
	}
}

void printSegmentDataNASM(FILE * file, graph_p graph, simbolos_p tabla_simbolos){
	list_elem_p current = NULL;
	list_elem_p next = NULL;
	char * node_name;
	char* next_name;
	char* parent_name;
	int i = 0, offset = 0;
	char ** simbolos_clase;

	fprintf(file, "segment .data\n");
	fprintf(file, "\t\tmsg_error_indice_vector     db \"Indice de vector fuera de rango\", 0\n\t\tmsg_asignacion     db \"Asignacion\", 0\n\t\t__auxfloat dd 0.0\n\t\t__auxint dd 0.0\n");

	fprintf(file, "\n;METODOS SOBREESCRIBIBLES OFFSET\n");

	// current = graph->nodes_list->head;
	// next = current->next;
	// while(current) {

	// 	simbolos_clase = current->node->ms;

	// 	for(i = 0; i < current->node->num_ms; i++){
	// 		fprintf(file, "\t\t_offset_%s, dd %d\n", simbolos_clase[i], offset*4);
	// 		offset++;
	// 	}


	// 	// free(simbolos_clase);
	// 	current = next;
	// 	if(current)
	// 		next = current->next;
	// }

	for(i=0; i < tabla_simbolos->metodos->num; i++){
		fprintf(file, "\t\t_offset_%s, dd %d\n", tabla_simbolos->metodos->nombres[i], i*4);
	}

	fprintf(file, "\n;ATRIBUTOS INSTANCIA OFFSET\n");
	offset = 1;

	current = graph->nodes_list->head;
	next = current->next;
	while(current) {

		simbolos_clase = current->node->ai;

		for(i = 0; i < current->node->num_ai; i++){
			fprintf(file, "\t\t_offset_%s dd %d\n", simbolos_clase[i], offset*4);
			offset++;
		}


		// free(simbolos_clase);
		current = next;
		if(current)
			next = current->next;
	}
}

void printSegmentBssNASM(FILE * file, graph_p graph, simbolos_p tabla_simbolos){
	list_elem_p current = NULL;
	list_elem_p next = NULL;
	char * node_name;
	char* next_name;
	char* parent_name;
	int i = 0, offset = 1, numclases = 0;
	char ** simbolos_clase;

	fprintf(file, "segment .bss\n");

	current = graph->nodes_list->head;
	next = current->next;
	while(current) {
		numclases++;
		current = next;
		if(current)
			next = current->next;
	}	

	fprintf(file, "\t\t__esp resd %d\n", numclases);

	current = graph->nodes_list->head;
	next = current->next;
	while(current) {
		node_name = current->node->name;

		fprintf(file, ";CLASS %s\n", node_name);
		fprintf(file, "\t\t_%s resd %d\n", node_name, current->node->num_ms);
		offset++;


		// free(simbolos_clase);
		current = next;
		if(current)
			next = current->next;
	}

	fprintf(file, "\n\n;;;;;FALTA SACAR LAS CLASES INSTANCIADAS;;;;;;\n\n");

	fprintf(file, "\n;ATRIBUTOS DE CLASE\n\n");

	current = graph->nodes_list->head;
	next = current->next;
	while(current) {

		simbolos_clase = current->node->ac;

		for(i = 0; i < current->node->num_ac; i++){
			fprintf(file, "\t\t_offset_%s resd 1 \n", simbolos_clase[i]);
			offset++;
		}


		// free(simbolos_clase);
		current = next;
		if(current)
			next = current->next;
	}
}

void instance_of(FILE *file, char * nombre_clase, int num_ai){
	fprintf(file, "\t\tpush %d\n", (num_ai+1)*4);
	fprintf(file, "\t\tcall malloc\n\t\tadd esp, 4\n")
}

void printSegmentTextNASM(FILE * file, graph_p graph, simbolos_p tabla_simbolos){
	list_elem_p current = NULL;
	list_elem_p next = NULL;
	char * node_name;
	char* next_name;
	char* parent_name;
	int i = 0, offset = 1, numclases = 0;
	char ** simbolos_clase;
	simbolo_p sim = NULL;
	char nombre_ambito_encontrado[100];

	fprintf(file, "segment .text\n\t\t;global main\n\n\n");
	fprintf(file, "\t\textern malloc, free\n
	\t\textern scan_int, print_int, scan_float, print_float, scan_boolean, print_boolean\n
	\t\textern print_endofline, print_blank, print_string\n
	\t\textern alfa_malloc, alfa_free, ld_float\n")
	/*Itera sobre clases linealizadas*/
	fprintf(file, "_create_ms_table:\n");
	current = graph->nodes_list->head;
	next = current->next;
	while(current) {

		for(i = 0; i < current->node->num_ms; i++){
			if(buscarIdNoCualificado(tabla_simbolos, tabla_simbolos->metodos->nombres[i], current->node->name, &sim, nombre_ambito_encontrado)){
				if(i == 0)
					fprintf(file, "\t\tmov dword [_%s], _%s\n",current->node->name, sim->id);
				else
					fprintf(file, "\t\tmov dword [_%s+%d], _%s\n", current->node->name, i*4, sim->id);
			}
			else{
				if(i == 0)
					fprintf(file, "\t\tmov dword [_%s], _no_defined_method\n",current->node->name);
				else
					fprintf(file, "\t\tmov dword [_%s+%d], _no_defined_method\n", current->node->name, i*4);
			}
		}

		current = next;
		if(current)
			next = current->next;
	}

}

/*Crea un fichero .asm con el nombre del grafo*/
simbolos_p tablaSimbolosClasesToNASM(simbolos_p tabla_simbolos){
	FILE * nasm = NULL;
	char* file = NULL;
	char* name = tabla_simbolos->graph->name;

	file = (char*)malloc((strlen(tabla_simbolos->graph->name)+5) * sizeof(char));

	strcpy(file, tabla_simbolos->graph->name);

	strcat(file, ".asm");

	nasm = fopen(file, "w+");
	if(!nasm){
		exit(1);
	}

	printGlobalHeaderNASM(nasm, tabla_simbolos->graph, tabla_simbolos);

	fprintf(nasm, "\n\n");

	printSegmentDataNASM(nasm, tabla_simbolos->graph, tabla_simbolos);

	fprintf(nasm, "\n\n");

	printSegmentBssNASM(nasm, tabla_simbolos->graph, tabla_simbolos);

	fprintf(nasm, "\n\n");

	printSegmentTextNASM(nasm, tabla_simbolos->graph, tabla_simbolos);


	// printTestNASM(nasm, tabla_simbolos->graph, tabla_simbolos);

	fclose(nasm);

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
int buscarIdEnJerarquiaDesdeClase( simbolos_p simbolos, 
									char * simbolo_a_buscar,
                          			char * nombre_clase, 
  									simbolo_p *s,
  									char * nombre_ambito_encontrado){
	char * nombre_prefijo = NULL;
	char * nombre_ambito = NULL;
	char * main_name = "main";
	node_p node1;
	node_p node = searchNode(simbolos->graph, nombre_clase);

	/*Busca en al ambito actual, tabla local*/
	if(node->local != NULL){
		nombre_ambito = getAmbito(node);
		nombre_prefijo = addPrefijo(nombre_ambito, simbolo_a_buscar);
		if(ht_isin(node->local, nombre_prefijo)){
			*s = ht_search(node->local, nombre_prefijo);
			strcpy(nombre_ambito_encontrado, nombre_ambito);
			free(nombre_prefijo);
			return aplicarAccesos(simbolos, nombre_clase, nombre_ambito_encontrado, *s);
		}
		free(nombre_prefijo);
	}


	nombre_ambito = ht_get_name(node->principal);
	nombre_prefijo = addPrefijo(nombre_ambito, simbolo_a_buscar);
	/*Buscar en el ambito actual, tabla principal*/
	if(ht_isin(node->principal, nombre_prefijo)){
		*s = ht_search(node->principal, nombre_prefijo);
		strcpy(nombre_ambito_encontrado, nombre_ambito);
		free(nombre_prefijo);
		return aplicarAccesos(simbolos, nombre_clase, nombre_clase, *s);
	}
	else{
		free(nombre_prefijo);
		int i = 0;
		/*Busca el simbolo en la jerarquia linealizada de padres*/
		while(node->padres[i] != NULL){
			node1 = searchNode(simbolos->graph, node->padres[i]);
			nombre_ambito = getAmbito(node1);
			nombre_prefijo = addPrefijo(nombre_ambito, simbolo_a_buscar);
            if(ht_isin(node1->principal, nombre_prefijo)){
				*s = ht_search(node1->principal,nombre_prefijo);
				strcpy(nombre_ambito_encontrado, node->padres[i]);
				free(nombre_prefijo);
				return aplicarAccesos(simbolos, nombre_clase, node->padres[i], *s);
			}
			free(nombre_prefijo);
			i++;
        }

        nombre_prefijo = addPrefijo(main_name, simbolo_a_buscar);
        /*Finalmente lo busca en main*/
        if(ht_isin(simbolos->main_principal, nombre_prefijo)){
			*s = ht_search(simbolos->main_principal, nombre_prefijo);
			strcpy(nombre_ambito_encontrado, main_name);
			free(nombre_prefijo);
			return aplicarAccesos(simbolos, nombre_clase, main_name, *s);
		}
		free(nombre_prefijo);
	}
	return ERROR;
}

/*Para declarar elementos UNIQUE
Hay que estar en la clase en la que quieres declarar
Miramos unicamente en el ambito actual. Si existe y es accesible, OK (no se inserta)

nombre_clase es el de la clase desde la que se busca
nombre_simbolo no incluye el prefijo
nombre_ambito_encontrado
*/
int buscarParaDeclararMiembroClase(	simbolos_p simbolos,
									char * nombre_clase,
									char * nombre_simbolo,
									simbolo_p * s,
									char * nombre_ambito_encontrado){
	char * nombre_ambito = NULL;
	char * nombre_prefijo = NULL;
	node_p node = searchNode(simbolos->graph, nombre_clase);

	if(!node){
		return ERROR;
	}
	/*Busca en al ambito actual, tabla local*/
	if(node->local != NULL){
		nombre_ambito = getAmbito(node);
        nombre_prefijo = addPrefijo(nombre_ambito, nombre_simbolo);
		if(ht_isin(node->local, nombre_prefijo)){
			*s = ht_search(node->local, nombre_prefijo);
			strcpy(nombre_ambito_encontrado, nombre_ambito);
			// return aplicarAccesos(simbolos, nombre_clase, nombre_ambito_encontrado, *s);
			free(nombre_prefijo);
			return OK;
		}

		s = NULL;
		nombre_ambito_encontrado = NULL;
		free(nombre_prefijo);

		return ERROR;
	}


	nombre_ambito = ht_get_name(node->principal);
    nombre_prefijo = addPrefijo(nombre_ambito, nombre_simbolo);
	/*Buscar en el ambito actual, tabla principal*/
	if(ht_isin(node->principal, nombre_prefijo)){
		*s = ht_search(node->principal, nombre_prefijo);
		strcpy(nombre_ambito_encontrado, nombre_ambito);
		free(nombre_prefijo);
		// return aplicarAccesos(simbolos, nombre_clase, nombre_clase, *s);
		return OK;
	}

	s = NULL;
	nombre_ambito_encontrado = NULL;
	free(nombre_prefijo);

	return ERROR;

}

/* Para declarar miembro de una instancia.
Es necesario comprobar la jerarquia de padres
1. Se comprueba el ambito actual. Si existe, OK (no se inserta)
2. Se busca en la jerarquia usando buscarIdJerarquiaDesdeClase():
	a) ERROR -> Se podra declarar
	b) OK -> :
		2.1/ Si es metodo sobreescribible, hay que avisarlo para usar el mismo offset
		2.2/ Si es atributo de instancia, no se puede declarar
		2.3/ Si es UNIQUE, no podra declararse

3. En este caso, el simbolo se mete sin prefijo
*/
int buscarParaDeclararMiembroInstancia(	simbolos_p simbolos,
									char * nombre_clase,
									char * nombre_simbolo,
									simbolo_p * s,
									char * nombre_ambito_encontrado){
	return buscarIdEnJerarquiaDesdeClase(simbolos, nombre_simbolo, nombre_clase, s, nombre_ambito_encontrado);
}

/*Busca un id no cualificado*/
int buscarIdNoCualificado(  simbolos_p simbolos,
                     		char * nombre_simbolo, char * clase_actual,
                    		simbolo_p * s, 
							char * nombre_ambito_encontrado){
	char * nombre_ambito = NULL;
	char * main_name = "main";
	char * nombre_prefijo = NULL;

	/*Busca el simbolo en main (si estamos en main)*/
	if(strcmp(clase_actual, main_name) == 0){
		/*Tabla local de main*/
		if(simbolos->main_local != NULL){
			nombre_ambito = ht_get_name(simbolos->main_local);
			nombre_prefijo = addPrefijo(nombre_ambito, nombre_simbolo);
			if(ht_isin(simbolos->main_local, nombre_prefijo)){
				*s = ht_search(simbolos->main_local, nombre_prefijo);
				strcpy(nombre_ambito_encontrado, nombre_ambito);
				free(nombre_prefijo);
				return aplicarAccesos(simbolos, clase_actual, nombre_ambito_encontrado, *s);
			}
			free(nombre_prefijo);
		}
		nombre_prefijo = addPrefijo(main_name, nombre_simbolo);
		/*Tabla principal de main*/
		if(ht_isin(simbolos->main_principal, nombre_prefijo)){
			*s = ht_search(simbolos->main_principal, nombre_prefijo);
			strcpy(nombre_ambito_encontrado, "main");
			free(nombre_prefijo);
			return aplicarAccesos(simbolos, clase_actual, "main", *s);
		}
		/*Si no esta en main, da error*/
		else{
			free(nombre_prefijo);
			return ERROR;
		}
	}
	/*Si no estamos en main, busca en la jerarquia empezando por el ambito actual*/
	else{
		return buscarIdEnJerarquiaDesdeClase(simbolos, nombre_simbolo, clase_actual, s, nombre_ambito_encontrado);
	}
}

/*Buscar un id cualificado de una clase (no de una instancia)*/
int buscarIdCualificadoClase(    simbolos_p simbolos, char * nombre_clase_cualifica,
                        char * nombre_id,char * nombre_clase_desde,
                        simbolo_p *s,
                        char * nombre_ambito_encontrado){

	node_p node = searchNode(simbolos->graph, nombre_clase_cualifica);
	if(!node){
		return ERROR;
	}
	else{
		if(!buscarIdEnJerarquiaDesdeClase(simbolos, nombre_id, nombre_clase_cualifica, s, nombre_ambito_encontrado)){
			return ERROR;
		}
		return aplicarAccesos(simbolos, nombre_clase_desde, nombre_ambito_encontrado, *s);
	}
}

/*Buscar un id cualificado por una instancia (no de clase)*/
int buscarIdCualificadoInstancia(simbolos_p simbolos,
							char * nombre_instancia_cualifica,
							char * nombre_id, char * nombre_clase_desde,
							simbolo_p * s,
							char * nombre_ambito_encontrado){
	char nombre_clase_cualifica[100];
	if(buscarIdNoCualificado(simbolos, nombre_instancia_cualifica, nombre_clase_desde, s, nombre_ambito_encontrado)){
		strcpy(nombre_clase_cualifica, nombre_ambito_encontrado);
		if((*s)->tipo>=0){
			return ERROR;
		}
		node_p node = getINode(simbolos->graph, -(*s)->tipo);
		strcpy(nombre_clase_cualifica, node->name);
		if(!aplicarAccesos(simbolos, nombre_clase_desde, nombre_ambito_encontrado, *s)){
			return ERROR;
		}
		if(buscarIdEnJerarquiaDesdeClase(simbolos, nombre_id, nombre_clase_cualifica, s, nombre_ambito_encontrado)){
			return aplicarAccesos(simbolos, nombre_clase_desde, nombre_ambito_encontrado, *s);
		}else{
			
		}
	}
	return ERROR;
}

int buscarParaDeclararIdTablaSimbolosAmbitos(simbolos_p simbolos, 
                                    char* id, 
                                    simbolo_p * s,  
                                    char* id_ambito){

	char * nombre_prefijo = NULL;

	if(simbolos->main_local){
		*s = NULL;
		nombre_prefijo = addPrefijo(ht_get_name(simbolos->main_local), id);
		*s = ht_search(simbolos->main_local, nombre_prefijo);
		free(nombre_prefijo);
		if(*s == NULL){
			return ERROR;
		}
		strcpy(id_ambito, ht_get_name(simbolos->main_local));
		return OK;
	}
	else{
		*s = NULL;
		nombre_prefijo = addPrefijo("main", id);
		*s = ht_search(simbolos->main_principal, nombre_prefijo);
		free(nombre_prefijo);
		if(*s == NULL){
			return ERROR;
		}
		strcpy(id_ambito, "main");
		return OK;
	}
}


int buscarParaDeclararIdLocalEnMetodo(simbolos_p simbolos, 
                            char * nombre_clase,
                            char * nombre_id,
                            simbolo_p * s, 
                            char * nombre_ambito_encontrado){

	char * nombre_prefijo = NULL;

	node_p node = searchNode(simbolos->graph, nombre_clase);
	if(!node || !node->local){
		return ERROR;
	}

	nombre_prefijo = addPrefijo(ht_get_name(node->local), nombre_id);

	*s = ht_search(node->local, nombre_prefijo);
	free(nombre_prefijo);
	if(*s == NULL){
		return ERROR;
	}
	strcpy(nombre_ambito_encontrado, ht_get_name(node->local));
	return OK;

}
