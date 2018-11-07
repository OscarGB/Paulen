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
	node_p node = searchNode(simbolos->graph, nombre_clase);

	/*Metemos los parametros de la funcion en el nombre del simbolo
	ATENCION: sobreescribimos simbolo_a_insertar*/
	if(tipo == FUNCION) {
		simbolo_a_insertar = crearNombreFuncion(simbolo_a_insertar, numero_parametros, tipo_args);
	}

	nombre_ambito = getAmbito(node);

	nombre_prefijo = addPrefijo(nombre_ambito, simbolo_a_insertar);
	simbolo_p s = createSimbolo(nombre_prefijo,
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
	/*Nuestro simbolo guarda una copia del nombre_prefijo con reserva*/




	if(node->local != NULL){
		ht_insert(node->local, nombre_prefijo, s);
	}
	else{
		ht_insert(node->principal, nombre_prefijo, s);
	}
	free(nombre_prefijo);
	if(tipo == FUNCION)
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
int buscarIdEnJerarquiaDesdeClase( simbolos_p simbolos, 
									char * simbolo_a_buscar,
                          			char * nombre_clase, 
  									simbolo_p *s,
  									char * nombre_ambito_encontrado){
	char * nombre_prefijo = NULL;
	char * nombre_ambito = NULL;
	char * main_name = "main";
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
			node = searchNode(simbolos->graph, node->padres[i]);
			nombre_ambito = getAmbito(node);
			nombre_prefijo = addPrefijo(nombre_ambito, simbolo_a_buscar);
            if(ht_isin(node->principal, nombre_prefijo)){
				*s = ht_search(node->principal,nombre_prefijo);
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
int buscarIdIDCualificadoClase(    simbolos_p simbolos, char * nombre_clase_cualifica,
                        char * nombre_id,char * nombre_clase_desde,
                        simbolo_p *s,
                        char * nombre_ambito_encontrado){

	node_p node = searchNode(simbolos->graph, nombre_clase_cualifica);
	if(!node){
		return ERROR;
	}
	else{
		buscarIdEnJerarquiaDesdeClase(simbolos, nombre_id, nombre_clase_cualifica, s, nombre_ambito_encontrado);
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
		strcpy(nombre_instancia_cualifica, nombre_ambito_encontrado);
		(*s)->tipo<=0;
		node_p node = getINode(simbolos->graph, (*s)->tipo);
		strcpy(nombre_clase_cualifica, node->name);
		if(!aplicarAccesos(simbolos, nombre_clase_desde, nombre_ambito_encontrado, *s)){
			return ERROR;
		}
		if(buscarIdEnJerarquiaDesdeClase(simbolos, nombre_id, nombre_clase_cualifica, s, nombre_ambito_encontrado)){
			return aplicarAccesos(simbolos, nombre_clase_desde, nombre_ambito_encontrado, *s);
		}
	}
	return ERROR;
}



