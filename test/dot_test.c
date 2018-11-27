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
	int args[2] = {1,3};
	for (i = 0; i < 5; i++){
		padres[i] = (char*) malloc(sizeof(char)*10);
	}

	nuevoSimboloEnMain(simbol, "v1", 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,EXPOSED,0,0,0,0,0,0,0,NULL);

	nuevaClase(simbol, NULL, 0, "AA");
	nuevoSimboloEnClase(simbol, "a1", "AA", 0,AC,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,EXPOSED,0,0,0,0,0,0,0,NULL);
	nuevoSimboloEnClase(simbol, "sa1", "AA", 0,AC,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,HIDDEN,0,0,0,0,0,0,0,NULL);

	nuevoSimboloEnClase(simbol, "aia1", "AA", 0,AI,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,EXPOSED,0,0,0,0,0,0,0,NULL);
	nuevoSimboloEnClase(simbol, "aia2", "AA", 0,AI,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,EXPOSED,0,0,0,0,0,0,0,NULL);
	nuevoSimboloEnClase(simbol, "ma1", "AA", 0,MS,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,EXPOSED,0,0,0,0,0,0,0,args);
	iniciaLocalEnClase(simbol, "AA", "ma1", 0,0,0,0);
	/*Estos son simbolos de la tabla local*/
	nuevoSimboloEnClase(simbol, "pmA1", "AA", 0,AC,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,EXPOSED,0,0,0,0,0,0,0,NULL);
	nuevoSimboloEnClase(simbol, "v1mA1", "AA", 0,AC,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,EXPOSED,0,0,0,0,0,0,0,NULL);


	check_simbol(simbol, "v1", "AA", NULL, 1, NOCUALIFICADO);
	check_simbol(simbol, "x", "AA",NULL, 0, NOCUALIFICADO);
	check_simbol(simbol, "v1mA1", "AA",NULL, 1, NOCUALIFICADO);
	check_simbol(simbol, "a1", "AA",NULL, 1, NOCUALIFICADO);

	cerrarLocalEnClase(simbol, "AA");

	check_simbol(simbol, "ma1@1@3", "AA",NULL, 1, NOCUALIFICADO);
	check_simbol(simbol, "v1mA1", "AA",NULL, 0, NOCUALIFICADO);

	cerrarClase(simbol, "AA", 0,0,0,0);
	nuevaClase(simbol, NULL, 0, "BB");

	nuevoSimboloEnClase(simbol, "bbb1", "BB", 0,AC,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,HIDDEN,0,0,0,0,0,0,0,NULL);
	nuevoSimboloEnClase(simbol, "bbb2", "BB", 0,AC,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,HIDDEN,0,0,0,0,0,0,0,NULL);
	nuevoSimboloEnClase(simbol, "bbb3", "BB", 0,AC,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,HIDDEN,0,0,0,0,0,0,0,NULL);
	nuevoSimboloEnClase(simbol, "mb1", "BB", 0,MS,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,EXPOSED,0,0,0,0,0,0,0,args);
	nuevoSimboloEnClase(simbol, "mnsb1", "BB", 0,MNS,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,EXPOSED,0,0,0,0,0,0,0,args);
	nuevoSimboloEnClase(simbol, "bib1", "BB", 0,AI,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,EXPOSED,0,0,0,0,0,0,0,NULL);

	cerrarClase(simbol, "BB", 0,0,0,0);

	nuevoSimboloEnMain(simbol, "f1", 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,EXPOSED,0,0,0,0,0,0,0,NULL);
	iniciaLocal(simbol, "f1");
	nuevoSimboloEnMain(simbol, "f1", 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,EXPOSED,0,0,0,0,0,0,0,NULL);
	nuevoSimboloEnMain(simbol, "pf1", 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,EXPOSED,0,0,0,0,0,0,0,NULL);

	check_simbol(simbol, "pf1", "main",NULL, 1, NOCUALIFICADO);
	check_simbol(simbol, "v1", "main",NULL, 1, NOCUALIFICADO);
	check_simbol(simbol, "a1", "main",NULL, 0, NOCUALIFICADO);

	nuevoSimboloEnMain(simbol, "v1f11", 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,EXPOSED,0,0,0,0,0,0,0,NULL);
	
	cerrarLocal(simbol);

	check_simbol(simbol, "v1", "main",NULL, 1, NOCUALIFICADO);
	check_simbol(simbol, "x", "main",NULL, 0, NOCUALIFICADO);

	nuevoSimboloEnMain(simbol, "claseAA", 0,-getIndex(simbol->graph, "AA"),0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,EXPOSED,0,0,0,0,0,0,0,NULL);
	nuevoSimboloEnMain(simbol, "claseBB", 0,-getIndex(simbol->graph, "BB"),0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,EXPOSED,0,0,0,0,0,0,0,NULL);

	check_simbol(simbol, "a1", "main", "claseAA", 1, INSTANCIA);
	check_simbol(simbol, "sa1", "main", "claseAA", 0, INSTANCIA);
	check_simbol(simbol, "a1", "main", "claseCC", 0, INSTANCIA);
	check_simbol(simbol, "a1", "main", "claseBB", 0, INSTANCIA);

	check_simbol(simbol, "a1", "main", "BB", 0, CLASE);
	check_simbol(simbol, "a1", "main", "AA", 1, CLASE);
	check_simbol(simbol, "sa1", "main", "AA", 0, CLASE);
	check_simbol(simbol, "sa1", "main", "CC", 0, CLASE);

	check_simbol(simbol, "a1", "AA", "", 1, BUSCAR_PARA_CLASE);
	check_simbol(simbol, "ba1", "AA", "", 0, BUSCAR_PARA_CLASE);
	check_simbol(simbol, "ma1@1@3", "AA", "", 1, BUSCAR_PARA_CLASE);
	check_simbol(simbol, "ma1@1@3@1", "AA", "", 0, BUSCAR_PARA_CLASE);
	check_simbol(simbol, "a1", "BB", "", 0, BUSCAR_PARA_CLASE);
	check_simbol(simbol, "f1", "AA", "", 0, BUSCAR_PARA_CLASE);

	check_simbol(simbol, "a1", "AA", "", 1, BUSCAR_PARA_INSTANCIA);
	check_simbol(simbol, "f1", "AA", "", 1, BUSCAR_PARA_INSTANCIA);

	tablaSimbolosClasesToDot(simbol);
	tablaSimbolosClasesToNASM(simbol);

	eliminaSimbolos(simbol);

	for (i = 0; i < 5; i++){
		free(padres[i]);
	}
	free(padres);

	return 0;
}