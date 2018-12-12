#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tabla_simbolos_clases.h"

simbolos_p simbolos = NULL;

int process_line(FILE * f){
	char line[1000], ambito[1000], to_print[1000];
	simbolo_p s;
	char *tok, *tok1, *nombre;
	char* padres[1000];
	char* res;
	int i;
	int categoria, tipo_basico, estructura, tipo_acceso, tipo_miembro;

	res = fgets(line, 1000, f);
	if(!res){
		return 1;
	}
	strcpy(to_print, line);
	strtok(to_print, "\n");
	tok = strtok(res, " \t\n");
	if(strcmp(tok, "inicia_tsc") == 0){
		tok = strtok(NULL, " \t\n");
		simbolos = createSimbolos(tok);
		printf("inicial_tsc\n");
	}
	else if(strcmp(tok, "abrir_clase") == 0){
		tok = strtok(NULL, " \t\n");
		nuevaClase(simbolos, NULL, 0, tok);
		printf("%s\n", to_print);
	}
	else if(strcmp(tok, "abrir_clase_hereda") == 0){
		tok = strtok(NULL, " \t\n");
		i = 0;
		padres[i] = strtok(NULL, " \t\n");
		while(padres[i]){
			i++;
			padres[i] = strtok(NULL, " \t\n");
		}
		nuevaClase(simbolos, padres, i, tok);
		printf("%s\n", to_print);
	}
	else if(strcmp(tok, "cerrar_clase") == 0){
		tok = strtok(NULL, " \t\n");
		cerrarClase(simbolos, tok, 0, 0, 0, 0);
		printf("%s\n", to_print);
	}
	else if(strcmp(tok, "cerrar_ambito_tsc") == 0){
		tok = strtok(NULL, " \t\n");
		eliminaLocalEnClase(simbolos, tok);
		printf("%s\n", to_print);
	}
	else if(strcmp(tok, "cerrar_tsc") == 0){
		eliminaSimbolos(simbolos);
		printf("%s\n", to_print);
	}
	else if(strcmp(tok, "cerrar_ambito_tsa_main") == 0){
		cerrarLocal(simbolos);
		printf("%s\n", to_print);
	}
	else if(strcmp(tok, "insertar_tsa_main") == 0){
		printf("%s\n", to_print);
		printf("\n=================== main =================\n\n");
		printf("FALTA LLENAR ESTE TROZO\n\n");
		tok = strtok(NULL, " \t\n");
		tok1 = strtok(NULL, " \t\n");
		categoria = atoi(tok1);
		tok1 = strtok(NULL, " \t\n");
		tipo_basico = atoi(tok1);
		tok1 = strtok(NULL, " \t\n");
		estructura = atoi(tok1);
		tok1 = strtok(NULL, " \t\n");
		tipo_acceso = atoi(tok1);
		tok1 = strtok(NULL, " \t\n");
		tipo_miembro = atoi(tok1);

		nuevoSimboloEnMain(simbolos,tok,categoria,tipo_basico,estructura,0,0,0,0,0,0,0,0,0,0,0,0,0,0,tipo_acceso,tipo_miembro,0,0,0,0,0,0,NULL);
	}
	else if(strcmp(tok, "insertar_tsc") == 0){
		printf("%s\n", to_print);
		tok = strtok(NULL, " \t\n");
		printf("\n=================== %s =================\n\n", tok);
		printf("FALTA LLENAR ESTE TROZO\n\n");
		nombre = strtok(NULL, " \t\n");
		tok1 = strtok(NULL, " \t\n");
		categoria = atoi(tok1);
		tok1 = strtok(NULL, " \t\n");
		tipo_basico = atoi(tok1);
		tok1 = strtok(NULL, " \t\n");
		estructura = atoi(tok1);
		tok1 = strtok(NULL, " \t\n");	
		tipo_acceso = atoi(tok1);
		tok1 = strtok(NULL, " \t\n");
		tipo_miembro = atoi(tok1);

		nuevoSimboloEnClase(simbolos,nombre,tok,categoria,tipo_basico,estructura,0,0,0,0,0,0,0,0,0,0,0,0,0,0,tipo_acceso,tipo_miembro,0,0,0,0,0,0,NULL);
	}
	else if(strcmp(tok, "abrir_ambito_tsc") == 0){
		printf("%s\n", to_print);
		tok = strtok(NULL, " \t\n");
		nombre = strtok(NULL, " \t\n");
		printf("\n=================== %s =================\n\n", nombre);
		printf("FALTA LLENAR ESTE TROZO\n\n");
		tok1 = strtok(NULL, " \t\n");
		categoria = atoi(tok1);
		tok1 = strtok(NULL, " \t\n");
		tipo_basico = atoi(tok1);
		tok1 = strtok(NULL, " \t\n");	
		tipo_acceso = atoi(tok1);
		tok1 = strtok(NULL, " \t\n");
		tipo_miembro = atoi(tok1);
		nuevoSimboloEnClase(simbolos,nombre,tok,categoria,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,tipo_acceso,tipo_miembro,0,0,0,0,0,0,NULL);
		iniciaLocalEnClase(simbolos,tok,nombre,categoria,tipo_acceso,tipo_miembro,0);
	}
	else if(strcmp(tok, "abrir_ambito_tsa_main") == 0){
		printf("%s\n", to_print);
		tok = strtok(NULL, " \t\n");
		printf("\n=================== %s =================\n\n", tok);
		printf("FALTA LLENAR ESTE TROZO\n\n");
		tok1 = strtok(NULL, " \t\n");
		tipo_basico = atoi(tok1);
		nuevoSimboloEnMain(simbolos,tok,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,NULL);
		iniciaLocal(simbolos,tok);
	}
	else if(strcmp(tok, "buscar") == 0){
		tok = strtok(NULL, " \t\n");
		if(strcmp(tok, "declarar_main") == 0){
			printf("%s: ", to_print);
			tok = strtok(NULL, " \t\n");
			if(buscarParaDeclararIdTablaSimbolosAmbitos(simbolos, tok, &s, ambito) == ERROR){
				printf("No encontrado: se puede declarar\n");
			}
			else{
				printf("Encontrado en %s: no se puede declarar\n", ambito);
			}
		}
		else if(strcmp(tok, "declarar_miembro_instancia") == 0){
			printf("%s: ", to_print);
			tok = strtok(NULL, " \t\n");
			tok1 = strtok(NULL, " \t\n");
			if(buscarParaDeclararMiembroInstancia(simbolos,tok, tok1, &s, ambito) == ERROR){
				printf("No encontrado: se puede declarar\n");
			}
			else{
				printf("Existe id: no se puede declarar\n");
			}
		}
		else if(strcmp(tok, "id_no_cualificado") == 0){
			printf("%s: ", to_print);
			tok = strtok(NULL, " \t\n");
			tok1 = strtok(NULL, " \t\n");
			if(buscarIdNoCualificado(simbolos,tok, tok1, &s, ambito) == ERROR){
				printf("No encontrado\n");
			}
			else{
				printf("Encontrado en %s\n",ambito);
			}
		}
		else if(strcmp(tok, "jerarquia") == 0){
			printf("%s: ", to_print);
			tok = strtok(NULL, " \t\n");
			tok1 = strtok(NULL, " \t\n");
			if(buscarIdEnJerarquiaDesdeClase(simbolos,tok, tok1, &s, ambito) == ERROR){
				printf("No encontrado\n");
			}
			else{
				printf("Encontrado en %s\n",ambito);
			}
		}
		else if(strcmp(tok, "id_cualificado_instancia") == 0){
			printf("%s: ", to_print);
			tok = strtok(NULL, " \t\n");
			tok1 = strtok(NULL, " \t\n");
			nombre = strtok(NULL, " \t\n");
			if(buscarIdCualificadoInstancia(simbolos,tok, tok1, nombre, &s, ambito) == ERROR){
				printf("No encontrado\n");
			}
			else{
				printf("Encontrado en %s\n",ambito);
			}
		}
		else if(strcmp(tok, "id_cualificado_clase") == 0){
			printf("%s: ", to_print);
			tok = strtok(NULL, " \t\n");
			tok1 = strtok(NULL, " \t\n");
			nombre = strtok(NULL, " \t\n");
			if(buscarIdCualificadoClase(simbolos,tok, tok1, nombre, &s, ambito) == ERROR){
				printf("No encontrado\n");
			}
			else{
				printf("Encontrado en %s\n",ambito);
			}
		}
		else if(strcmp(tok, "declarar_miembro_clase") == 0){
			printf("%s: ", to_print);
			tok = strtok(NULL, " \t\n");
			tok1 = strtok(NULL, " \t\n");
			if(buscarParaDeclararMiembroClase(simbolos,tok, tok1, &s, ambito) == ERROR){
				printf("No encontrado: se puede declarar\n");
			}
			else{
				printf("Existe id: no se puede declarar\n");
			}
		}
		else if(strcmp(tok, "declarar_id_local_metodo") == 0){
			printf("%s: ", to_print);
			tok = strtok(NULL, " \t\n");
			tok1 = strtok(NULL, " \t\n");
			if(buscarParaDeclararIdLocalEnMetodo(simbolos,tok, tok1, &s, ambito) == ERROR){
				printf("No encontrado: se puede declarar\n");
			}
			else{
				printf("Existe id: no se puede declarar\n");
			}
		}
	}
	else{
		printf("%s\n", to_print);
	}
	return 0;
}

int main(int argc, char const *argv[])
{
	FILE * f = fopen(argv[1], "r");
	while(process_line(f) != 1){
		continue;
	}
	fclose(f);
	return 0;
}