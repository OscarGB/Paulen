#include "tabla_simbolos_clases.h"

/*Crea la estructura y reserva toda la memoria necesaria*/
simbolos_p createSimbolos(){
	simbolos_p sim = (simbolos_p)malloc(sizeof(simbolos_t));
	sim->graph = createGraph();
	sim->main_principal = ht_new("main");
	sim->main_local = NULL;
}

/*Elimina la estructura y libera toda la memoria ocupada*/
void eliminaSimbolos(simbolos_p simbolos){
	if(simbolos->main_local) ht_del_hash_table(simbolos->main_local);
	ht_del_hash_table(simbolos->main_principal);
	destroyGraph(simbolos->graph);
}

/*Inserta una clase en el gafo*/
void nuevaClase(simbolos_p simbolos, char** parents, int numparents, char* name){
	node_p padres[numparents];
	for(int i; i<numparents;i++){
		padres[i] = searchNode(simbolos->graph, parents[i]);
	}
	addNode(simbolos->graph, padres, numparents, name);
}

/*Inserta un simbolo en una clase concreta*/
void nuevoSimboloEnClase(simbolos_p simbolos, char* nombre_clase, char* simbolo_a_insertar, int ambito){
	hash_table_p h = getHT(simbolos->graph, nombre_clase, ambito);
	ht_insert(h, simbolo_a_insertar, NULL);
}

/*Comprueba si un simbolo esta en una clase*/
int checkSimboloEnClase(simbolos_p simbolos, char* nombre_clase, char* simbolo_a_comprobar, int ambito){
	hash_table_p h = getHT(simbolos->graph, nombre_clase, ambito);
	return ht_isin(h, simbolo_a_comprobar);
}

/*Crea la tabla local*/
void iniciaLocal(simbolos_p simbolos, char* nombre){
	if(simbolos->main_local) ht_del_hash_table(simbolos->main_local);
	simbolos->main_local = ht_new(nombre);
}

/*Elimina la tabla local*/
void eliminaLocal(simbolos_p simbolos){
	if(simbolos->main_local) ht_del_hash_table(simbolos->main_local);
	simbolos->main_local = NULL;
}

/*Crea la tabla local de una clase*/
void iniciaLocalEnClase(simbolos_p simbolos, char* nombre_clase, char* nombre){
	hash_table_p h = getHT(simbolos->graph, nombre_clase, LOCAL);
	if(h) ht_del_hash_table(h);
	h = ht_new(nombre);
}

/*Elimina la tabla local de una clase*/
void eliminaLocalEnClase(simbolos_p simbolos, char* nombre_clase){
	hash_table_p h = getHT(simbolos->graph, nombre_clase, LOCAL);
	if(h) ht_del_hash_table(h);
	h = NULL;
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
	hash_table_p h = getHT(simbolos->graph, nombre_clase, LOCAL);
	return ht_get_keys(h);
}

