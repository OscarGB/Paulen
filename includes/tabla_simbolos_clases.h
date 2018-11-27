#ifndef TABLA_SIMBOLOS_CLASES_H
#define TABLA_SIMBOLOS_CLASES_H

#include "graph.h"
#include "hash_table.h"
#include "macros.h"
#include "simbolo.h"

/*En macros.h estan definidas las siguientes macros de utilidad:

#define LOCAL 0
#define PRINCIPAL 1

que refieren al ámbito de la tabla de simbolos
*/

typedef struct _metodos
{
	int num;
	char** nombres;

}metodos_t, *metodos_p;

typedef struct _simbolos
{
    hash_table_p main_principal;  /*Hash table for main*/
    hash_table_p main_local; /*Hash table for methods in main*/
	graph_p graph; /*Graph class*/

	metodos_p metodos; /*Métodos sobreescribibles*/

}simbolos_t, *simbolos_p;

/*Crea la estructura y reserva toda la memoria necesaria
iniciarTablasSimbolosClases()*/
simbolos_p createSimbolos(char* name);

/*Elimina la estructura y libera toda la memoria ocupada*/
void eliminaSimbolos(simbolos_p simbolos);

/*Inserta una clase en el gafo
abrirClase() y abrirClaseHeredaN(), para una clase que no hereda, poner numparents a 0 y parents a NULL*/
void nuevaClase(simbolos_p simbolos, char** parents, int numparents, char* name);

/*Cierra una clase*/
void cerrarClase(simbolos_p simbolos,
				char* name, 
				int n_atributos_clase, 
				int n_atributos_instancia,
				int num_metodos_sobreescribibles,
				int num_metodos_no_sobreescribibles);

/*Cierra el ambito local de una clase
tablaSimbolosClasesCerrarAmbitoEnClase()*/
void cerrarLocalEnClase(simbolos_p simbolos, char* nombre_clase);

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
);

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
);

/*Comprueba si un simbolo esta en una clase*/
int checkSimboloEnClase(simbolos_p simbolos, char* nombre_clase, char* simbolo_a_comprobar, int ambito);

/*Crea la tabla local
abrirAmbitoClase()*/
void iniciaLocal(simbolos_p simbolos, char* nombre);

/*Elimina la tabla local*/
void eliminaLocal(simbolos_p simbolos);

/*Cierra local del main*/
void cerrarLocal(simbolos_p simbolos);

/*Crea la tabla local de una clase
tablaSimbolosClasesAbrirAmbitoEnClase()*/
void iniciaLocalEnClase(simbolos_p simbolos,
						char* nombre_clase, 
						char* nombre_ambito,
						int categoria_ambito,
						int acceso_metodo,
						int tipo_metodo,
						int posicion_metodo_sobre);

/*Elimina la tabla local de una clase*/
void eliminaLocalEnClase(simbolos_p simbolos, char* nombre_clase);

/*Devuelve todos los simbolos de main*/
char** getSimbolos(simbolos_p simbolos, int ambito);

/*Devuelve todos los simbolos en una clase*/
char** getSimbolosEnClase(simbolos_p simbolos, char* nombre_clase, int ambito);

/*Imprime el grafo linalizado en formato .dot*/
void printLinearGraph(FILE * file, graph_p graph);

/*Imprime el grafo clase a clase en formato .dot*/
void printDiagram(FILE * file, graph_p graph, simbolos_p tabla_simbolos);

/*Crea un fichero .dot con el nombre del grafo*/
simbolos_p tablaSimbolosClasesToDot(simbolos_p tabla_simbolos);

/*Crea un fichero .asm con el nombre del grafo*/
simbolos_p tablaSimbolosClasesToNASM(simbolos_p tabla_simbolos);

/*Cierra la tabla de simbolos de clases*/
void cerrarTablaSimbolosClases(simbolos_p simbolos);

/*Comprueba los accesos de un simbolo concreto*/
int aplicarAccesos(simbolos_p simbolos, char * clase_actual, 
					char * clase_variable_encontrada, simbolo_p s);

/*Busca un simbolo en la jerarquia de clases*/
int buscarIdEnJerarquiaDesdeClase( simbolos_p simbolos, 
									char * simbolo_a_buscar,
                          			char * nombre_clase, 
  									simbolo_p *s,
  									char * nombre_ambito_encontrado);

/*Busca un id no cualificado*/
int buscarIdNoCualificado(  simbolos_p simbolos,
                     		char * nombre_simbolo, char * clase_actual,
                    		simbolo_p * s, 
							char * nombre_ambito_encontrado);

/*Buscar un id cualificado de una clase (no de una instancia)*/
int buscarIdCualificadoClase(    simbolos_p simbolos, char * nombre_clase_cualifica,
	                        char * nombre_id,char * nombre_clase_desde,
	                        simbolo_p *s,
	                        char * nombre_ambito_encontrado);

/*Buscar un id cualificado por una instancia (no de clase)*/
int buscarIdCualificadoInstancia(simbolos_p simbolos,
							char * nombre_instancia_cualifica,
							char * nombre_id, char * nombre_clase_desde,
							simbolo_p * s,
							char * nombre_ambito_encontrado);

/* Para declarar miembro de una instancia.
Es necesario comprobar la jerarquia de padres
1. Se comprueba el ambito actual. Si existe, OK (no se inserta)
2. Se busca en la jerarquia usando buscarIdJerarquiaDesdeClase():
	a) ERROR -> Se podra declarar
	b) OK -> :
		2.1/ Si es metodo sobreescribible, hay que avisarlo para usar el mismo offset
		2.2/ Si es atributo de instancia, no se puede declarar
		2.3/ Si es UNIQUE, no podra declararse
*/
int buscarParaDeclararMiembroInstancia(	simbolos_p simbolos,
									char * nombre_clase,
									char * nombre_simbolo,
									simbolo_p * s,
									char * nombre_ambito_encontrado);

/*Para declarar elementos UNIQUE
Hay que estar en la clase en la que quieres declarar
Miramos unicamente en el ambito actual. Si existe y es accesible, OK (no se inserta)

nombre_clase es el de la clase desde la que se busca
nombre_simbolo incluye el prefijo
nombre_ambito_encontrado
*/
int buscarParaDeclararMiembroClase(	simbolos_p simbolos,
									char * nombre_clase,
									char * nombre_simbolo,
									simbolo_p * s,
									char * nombre_ambito_encontrado);


int buscarParaDeclararIdTablaSimbolosAmbitos(simbolos_p simbolos, 
                                    char* id, 
                                    simbolo_p * s,  
                                    char* id_ambito);

int buscarParaDeclararIdLocalEnMetodo(simbolos_p simbolos, 
                            char * nombre_clase,
                            char * nombre_id,
                            simbolo_p * s, 
                            char * nombre_ambito_encontrado);


#endif //TABLA_SIMBOLOS_CLASES_H