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
#define CLASE 4
#define BUSCAR_PARA_CLASE 3
#define BUSCAR_PARA_INSTANCIA 5
#define BUSCAR_PARA_TABLA 6
#define BUSCAR_PARA_LOCAL 7

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
				printf("DC OK: %s encontrado en %s\n", simbolo, nombre_ambito_encontrado);
			}
			else{
				printf("DC ERROR: %s debería encontrarse\n", simbolo);
			}
		}else{
			if(!buscarParaDeclararMiembroClase(simbol, clase_desde, simbolo, &s, nombre_ambito_encontrado)){
				printf("DC OK: %s no encontrado\n", simbolo);
			}
			else{
				printf("DC ERROR %s no debería encontrarse\n", simbolo);
			}
		}
	}

	if(prueba == BUSCAR_PARA_INSTANCIA){
		if(deberia_estar){
			if(buscarParaDeclararMiembroInstancia(simbol, clase_desde, simbolo, &s, nombre_ambito_encontrado)){
				printf("DM OK: %s encontrado en %s\n", simbolo, nombre_ambito_encontrado);
			}
			else{
				printf("DM ERROR: %s debería encontrarse\n", simbolo);
			}
		}else{
			if(!buscarParaDeclararMiembroInstancia(simbol, clase_desde, simbolo, &s, nombre_ambito_encontrado)){
				printf("DM OK: %s no encontrado\n", simbolo);
			}
			else{
				printf("DM ERROR %s no debería encontrarse\n", simbolo);
			}
		}
	}

	if(prueba == BUSCAR_PARA_TABLA){
		if(deberia_estar){
			if(buscarParaDeclararIdTablaSimbolosAmbitos(simbol, simbolo, &s, nombre_ambito_encontrado)){
				printf("DT OK: %s encontrado en %s\n", simbolo, nombre_ambito_encontrado);
			}
			else{
				printf("DT ERROR: %s debería encontrarse\n", simbolo);
			}
		}else{
			if(!buscarParaDeclararIdTablaSimbolosAmbitos(simbol, simbolo, &s, nombre_ambito_encontrado)){
				printf("DT OK: %s no encontrado\n", simbolo);
			}
			else{
				printf("DT ERROR %s no debería encontrarse\n", simbolo);
			}
		}
	}

	if(prueba == BUSCAR_PARA_LOCAL){
		if(deberia_estar){
			if(buscarParaDeclararIdLocalEnMetodo(simbol, clase_desde, simbolo, &s, nombre_ambito_encontrado)){
				printf("DL OK: %s encontrado en %s\n", simbolo, nombre_ambito_encontrado);
			}
			else{
				printf("DL ERROR: %s debería encontrarse\n", simbolo);
			}
		}else{
			if(!buscarParaDeclararIdLocalEnMetodo(simbol, clase_desde, simbolo, &s, nombre_ambito_encontrado)){
				printf("DL OK: %s no encontrado\n", simbolo);
			}
			else{
				printf("DL ERROR %s no debería encontrarse\n", simbolo);
			}
		}
	}
}

int main(){
	int i;
	simbolos_p simbol = createSimbolos("Test_graph");
	char **padres = (char**)malloc(sizeof(char*)*5);
	int args[1] = {1};
	for (i = 0; i < 5; i++){
		padres[i] = (char*) malloc(sizeof(char)*10);
	}

	check_simbol(simbol, "v1", NULL, NULL, 0, BUSCAR_PARA_TABLA);
	nuevoSimboloEnMain(simbol, "v1", 0,ENTERO,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,EXPOSED,0,0,0,0,0,0,0,NULL);

	check_simbol(simbol, "v1", NULL, NULL, 1, BUSCAR_PARA_TABLA);
	
	check_simbol(simbol, "ma1@1", NULL, NULL, 0, BUSCAR_PARA_TABLA);
	nuevoSimboloEnMain(simbol, "ma1", 0,FUNCION,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,EXPOSED,0,0,0,0,0,0,0,args);

	check_simbol(simbol, "p1", NULL, NULL, 0, BUSCAR_PARA_TABLA);
	nuevoSimboloEnMain(simbol, "p1", 0,ENTERO,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,EXPOSED,0,0,0,0,0,0,0,NULL);
	
	iniciaLocal(simbol, "ma1@1");
	nuevoSimboloEnMain(simbol, "ma1", 0,FUNCION,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,EXPOSED,0,0,0,0,0,0,0,args);
	nuevoSimboloEnMain(simbol, "p1", 0,ENTERO,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,EXPOSED,0,0,0,0,0,0,0,NULL);

	check_simbol(simbol, "ma1@1", NULL, NULL, 1, BUSCAR_PARA_TABLA);

	check_simbol(simbol, "p1", NULL, NULL, 1, BUSCAR_PARA_TABLA);

	cerrarLocal(simbol);

	eliminaSimbolos(simbol);

	for (i = 0; i < 5; i++){
		free(padres[i]);
	}
	free(padres);

	return 0;
}