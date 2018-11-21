#include "tabla_simbolos_clases.h"
#include "macros.h"
#include "hash_table.h"
#include "simbolo.h"
#include "graph.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NOCUALIFICADO 1
#define INSTANCIA 2
#define CLASE 3
#define BUSCAR_PARA_CLASE 4
#define BUSCAR_PARA_INSTANCIA 5

void check_simbol(simbolos_p simbol, char* simbolo, char* clase_desde, char* nombre_cualifica, int deberia_estar, int prueba){
	
	simbolo_p s = NULL;
	char nombre_ambito_encontrado[100];
	if(prueba == NOCUALIFICADO){
		if(deberia_estar){
			if(buscarIdNoCualificado(simbol, simbolo, clase_desde, &s, nombre_ambito_encontrado)){
				printf("NC OK: %s encontrado en %s\n", simbolo, nombre_ambito_encontrado);
			}
			else{
				printf("NC ERROR: %s debería encontrarse\n", simbolo);
			}
		}else{
			if(!buscarIdNoCualificado(simbol, simbolo, clase_desde, &s, nombre_ambito_encontrado)){
				printf("NC OK: %s no encontrado\n", simbolo);
			}
			else{
				printf("NC ERROR %s no debería encontrarse\n", simbolo);
			}
		}
	}
	if(prueba == INSTANCIA){
		if(deberia_estar){
			if(buscarIdCualificadoInstancia(simbol, nombre_cualifica, simbolo, clase_desde, &s, nombre_ambito_encontrado)){
				printf("CI OK: %s encontrado en %s\n", simbolo, nombre_ambito_encontrado);
			}
			else{
				printf("CI ERROR: %s debería encontrarse\n", simbolo);
			}
		}else{
			if(!buscarIdCualificadoInstancia(simbol, nombre_cualifica, simbolo, clase_desde, &s, nombre_ambito_encontrado)){
				printf("CI OK: %s no encontrado\n", simbolo);
			}
			else{
				printf("CI ERROR %s no debería encontrarse\n", simbolo);
			}
		}
	}
	if(prueba == CLASE){
		if(deberia_estar){
			if(buscarIdCualificadoClase(simbol, nombre_cualifica, simbolo, clase_desde, &s, nombre_ambito_encontrado)){
				printf("CC OK: %s encontrado en %s\n", simbolo, nombre_ambito_encontrado);
			}
			else{
				printf("CC ERROR: %s debería encontrarse\n", simbolo);
			}
		}else{
			if(!buscarIdCualificadoClase(simbol, nombre_cualifica, simbolo, clase_desde, &s, nombre_ambito_encontrado)){
				printf("CC OK: %s no encontrado\n", simbolo);
			}
			else{
				printf("CC ERROR %s no debería encontrarse\n", simbolo);
			}
		}
	}

	if(prueba == BUSCAR_PARA_CLASE){
		if(deberia_estar){
			if(buscarParaDeclararMiembroClase(simbol, clase_desde, simbolo, &s, nombre_ambito_encontrado)){
				printf("CC OK: %s encontrado en %s\n", simbolo, nombre_ambito_encontrado);
			}
			else{
				printf("CC ERROR: %s debería encontrarse\n", simbolo);
			}
		}else{
			if(!buscarParaDeclararMiembroClase(simbol, clase_desde, simbolo, &s, nombre_ambito_encontrado)){
				printf("CC OK: %s no encontrado\n", simbolo);
			}
			else{
				printf("CC ERROR %s no debería encontrarse\n", simbolo);
			}
		}
	}

	if(prueba == BUSCAR_PARA_INSTANCIA){
		if(deberia_estar){
			if(buscarParaDeclararMiembroInstancia(simbol, clase_desde, simbolo, &s, nombre_ambito_encontrado)){
				printf("CC OK: %s encontrado en %s\n", simbolo, nombre_ambito_encontrado);
			}
			else{
				printf("CC ERROR: %s debería encontrarse\n", simbolo);
			}
		}else{
			if(!buscarParaDeclararMiembroInstancia(simbol, clase_desde, simbolo, &s, nombre_ambito_encontrado)){
				printf("CC OK: %s no encontrado\n", simbolo);
			}
			else{
				printf("CC ERROR %s no debería encontrarse\n", simbolo);
			}
		}
	}
}

int main(){
	int i;
	simbolos_p simbol = createSimbolos("Test_graph");
	char **padres = (char**)malloc(sizeof(char*)*5);
	int args2[2] = {1,1};
	int args1[1] = {1};
	for (i = 0; i < 5; i++){
		padres[i] = (char*) malloc(sizeof(char)*10);
	}

	nuevaClase(simbol, NULL, 0, "AA");
	
	check_simbol(simbol, "sA1", "AA", "", 0, BUSCAR_PARA_CLASE);
	nuevoSimboloEnClase(simbol, "sA1", "AA", 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,SECRET,0,0,0,0,0,0,0,NULL);
	
	check_simbol(simbol, "sA1", "AA", "", 1, BUSCAR_PARA_CLASE);
	// nuevoSimboloEnClase(simbol, "sA1", "AA", 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,SECRET,0,0,0,0,0,0,0,NULL);

	check_simbol(simbol, "hA1", "AA", "", 0, BUSCAR_PARA_CLASE);
	nuevoSimboloEnClase(simbol, "hA1", "AA", 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,HIDDEN,0,0,0,0,0,0,0,NULL);

	check_simbol(simbol, "xA1", "AA", "", 0, BUSCAR_PARA_CLASE);
	nuevoSimboloEnClase(simbol, "xA1", "AA", 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,EXPOSED,0,0,0,0,0,0,0,NULL);

	check_simbol(simbol, "MA1@1", "AA", "", 0, BUSCAR_PARA_CLASE);
	nuevoSimboloEnClase(simbol, "MA1", "AA", 0,FUNCION,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,HIDDEN,0,0,0,0,0,0,0,args1);

	check_simbol(simbol, "MA1@1", "AA", "", 1, BUSCAR_PARA_CLASE);
	// nuevoSimboloEnClase(simbol, "MA1", "AA", 0,FUNCION,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,SECRET,0,0,0,0,0,0,0,args1);

	check_simbol(simbol, "MA1@1@1", "AA", "", 0, BUSCAR_PARA_CLASE);
	nuevoSimboloEnClase(simbol, "MA1", "AA", 0,FUNCION,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,HIDDEN,0,0,0,0,0,0,0,args2);

	cerrarClase(simbol, "AA", 0,0,0,0);

	


	nuevaClase(simbol, NULL, 0, "BB");

	check_simbol(simbol, "sA1", "BB", "", 0, BUSCAR_PARA_CLASE);
	nuevoSimboloEnClase(simbol, "sA1", "BB", 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,SECRET,0,0,0,0,0,0,0,NULL);

	check_simbol(simbol, "hA1", "BB", "", 0, BUSCAR_PARA_CLASE);
	nuevoSimboloEnClase(simbol, "hA1", "BB", 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,HIDDEN,0,0,0,0,0,0,0,NULL);

	check_simbol(simbol, "xA1", "BB", "", 0, BUSCAR_PARA_CLASE);
	nuevoSimboloEnClase(simbol, "xA1", "BB", 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,EXPOSED,0,0,0,0,0,0,0,NULL);


	check_simbol(simbol, "MB1@1", "BB", "", 0, BUSCAR_PARA_CLASE);
	nuevoSimboloEnClase(simbol, "MB1", "BB", 0,FUNCION,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,SECRET,0,0,0,0,0,0,0,args1);

	check_simbol(simbol, "MA1@1", "BB", "", 0, BUSCAR_PARA_CLASE);
	nuevoSimboloEnClase(simbol, "MA1", "BB", 0,FUNCION,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,HIDDEN,0,0,0,0,0,0,0,args1);

	check_simbol(simbol, "MA2@1@1", "BB", "", 0, BUSCAR_PARA_CLASE);
	nuevoSimboloEnClase(simbol, "MA2", "BB", 0,FUNCION,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,EXPOSED,0,0,0,0,0,0,0,args2);

	cerrarClase(simbol, "BB", 0,0,0,0);

	eliminaSimbolos(simbol);

	for (i = 0; i < 5; i++){
		free(padres[i]);
	}
	free(padres);

	return 0;
}