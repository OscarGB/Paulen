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
	graph_p graph; /*Graph class*/

}simbolos_t, *simbolos_p;

/*Crea la estructura y reserva toda la memoria necesaria*/
simbolos_p createSimbolos(char* graph_name);

/*Elimina la estructura y libera toda la memoria ocupada*/
void eliminaSimbolos(simbolos_p simbolos);

/*Inserta una clase en el gafo*/
void nuevaClase(simbolos_p simbolos, char** parents, int numparents, char* name);

/*Inserta un simbolo en una clase concreta*/
void nuevoSimboloEnClase(simbolos_p simbolos, char* nombre_clase, char* simbolo_a_insertar, int ambito);

/*Comprueba si un simbolo esta en una clase*/
int checkSimboloEnClase(simbolos_p simbolos, char* nombre_clase, char* simbolo_a_comprobar, int ambito);

/*Crea la tabla local*/
void iniciaLocal(simbolos_p simbolos, char* nombre);

/*Elimina la tabla local*/
void eliminaLocal(simbolos_p simbolos);

/*Crea la tabla local de una clase*/
void iniciaLocalEnClase(simbolos_p simbolos, char* nombre_clase, char* nombre);

/*Elimina la tabla local de una clase*/
void eliminaLocalEnClase(simbolos_p simbolos, char* nombre_clase);

/*Devuelve todos los simbolos de main*/
char** getSimbolos(simbolos_p simbolos, int ambito);

/*Devuelve todos los simbolos en una clase*/
char** getSimbolosEnClase(simbolos_p simbolos, char* nombre_clase, int ambito);

/*Crea un fichero .dot con el nombre del grafo*/
simbolos_p tablaSimbolosClasesToDot(simbolos_p tabla_simbolos);

#endif // TABLA_SIMBOLOS_CLASES_H