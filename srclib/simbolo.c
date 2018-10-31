#include "simbolo.h"
#include <stdlib.h>
#include <string.h>

simbolo_p createSimbolo(	char* id,
							int clase,
						    int tipo,
						    int estructura,
						    int direcciones,
						    int numero_parametros,
						    int numero_variables_locales,
						    int posicion_variable_local,
						    int posicion_parametro,
						    int dimension,
						    int tamanio,
						    int filas,
						    int columnas,
						    int capacidad,
						    int numero_atributos_clase,
						    int numero_atributos_instancia,
						    int numero_metodos_sobreescribibles,
						    int numero_metodos_no_sobreescribibles,
						    int tipo_acceso,
						    int tipo_miembro, 
						    int posicion_atributo_instancia,
						    int posicion_metodo_sobreescribible,
						    int num_acumulado_atributos_instancia,
						    int num_acumulado_metodos_sobreescritura,
						    int posicion_acumulada_atributos_instancia,
						    int posicion_acumulada_metodos_sobreescritura,
						    int * tipo_args){

	simbolo_p s = (simbolo_p)malloc(sizeof(simbolo_t));
	s->id = (char*)malloc(sizeof(char)*strlen(id) + 1);
	strcpy(s->id, id);
	s->clase = clase;
    s->tipo = tipo;
    s->estructura = estructura;
    s->direcciones = direcciones;
    s->numero_parametros = numero_parametros;
    s->numero_variables_locales = numero_variables_locales;
    s->posicion_variable_local = posicion_variable_local;
    s->posicion_parametro = posicion_parametro;
    s->dimension = dimension;
    s->tamanio = tamanio;
    s->filas = filas;
    s->columnas = columnas;
    s->capacidad = capacidad;
    s->numero_atributos_clase = numero_atributos_clase;
    s->numero_atributos_instancia = numero_atributos_instancia;
    s->numero_metodos_sobreescribibles = num_acumulado_metodos_sobreescritura;
    s->numero_metodos_no_sobreescribibles = numero_metodos_no_sobreescribibles;
    s->tipo_acceso = tipo_acceso;
    s->tipo_miembro =  tipo_miembro;
    s->posicion_atributo_instancia = posicion_atributo_instancia;
    s->posicion_metodo_sobreescribible = posicion_metodo_sobreescribible;
    s->num_acumulado_atributos_instancia = num_acumulado_atributos_instancia;
    s->num_acumulado_metodos_sobreescritura = num_acumulado_metodos_sobreescritura;
    s->posicion_acumulada_atributos_instancia = posicion_acumulada_atributos_instancia;
    s->posicion_acumulada_metodos_sobreescritura = posicion_acumulada_metodos_sobreescritura;

    return s;

}

void eliminaSimbolo(simbolo_p s){
	free(s->id);
	free(s);
	return;
}