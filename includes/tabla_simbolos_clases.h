#ifndef TABLA_SIMBOLOS_CLASES_H
#define TABLA_SIMBOLOS_CLASES_H

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
void nuevaClase();

/*Inserta un simbolo en una clase concreta*/
void nuevoSimboloEnClase();

/*Comprueba si un simbolo esta en una clase*/
void checkSimboloEnClase();

#endif // TABLA_SIMBOLOS_CLASES_H