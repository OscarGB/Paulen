#ifndef TABLA_SIMBOLOS_CLASES_H
#define TABLA_SIMBOLOS_CLASES_H

#include "graph.h"
#include "hash_table.h"

/*En graph.h estan definidas las siguientes macros de utilidad:

#define LOCAL 0
#define PRINCIPAL 1

que refieren al ámbito de la tabla de simbolos
*/

typedef struct _simbolos
{
    hash_table_p main_principal;  /*Hash table for main*/
    hash_table_p main_local; /*Hash table for methods in main*/
	graph_p graph;

}simbolos_t, *simbolos_p;

/*Crea la estructura y reserva toda la memoria necesaria*/
simbolos_p createSimbolos();

/*Elimina la estructura y libera toda la memoria ocupada*/
void eliminaSimbolos();

/*Inserta una clase en el gafo*/
void nuevaClase(simbolos_p simbolos, node_p* parents, int numparents, char* name);

/*Inserta un simbolo en una clase concreta*/
void nuevoSimboloEnClase(simbolos_p simbolos, char* nombre_clase, char* simbolo_a_insertar, int ambito);

/*Comprueba si un simbolo esta en una clase*/
void checkSimboloEnClase(simbolos_p simbolos, char* nombre_clase, char* simbolo_a_comprobar, int ambito);

#endif // TABLA_SIMBOLOS_CLASES_H