#ifndef TABLA_SIMBOLOS_CLASES_H
#define TABLA_SIMBOLOS_CLASES_H

typedef struct _simbolos
{
    hash_table_p main_principal;  /*Hash table for main*/
    hash_table_p main_local; /*Hash table for methods in main*/
	graph_p graph;

}simbolos_t, *simbolos_p;

simbolos_p createSimbolos();


#endif // TABLA_SIMBOLOS_CLASES_H