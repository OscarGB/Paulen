#ifndef SIMBOLO_H
#define SIMBOLO_H

typedef struct _simbolo {
	char* id;
	char* nombre;
	int clase;
    int tipo;
    int estructura;
    int direcciones;
    int numero_parametros;
    int numero_variables_locales;
    int posicion_variable_local;
    int posicion_parametro;
    int dimension;
    int tamanio;
    int filas;
    int columnas;
    int capacidad;
    int numero_atributos_clase;
    int numero_atributos_instancia;
    int numero_metodos_sobreescribibles;
    int numero_metodos_no_sobreescribibles;
    int tipo_acceso;
    int tipo_miembro; 
    int posicion_atributo_instancia;
    int posicion_metodo_sobreescribible;
    int num_acumulado_atributos_instancia;
    int num_acumulado_metodos_sobreescritura;
    int posicion_acumulada_atributos_instancia;
    int posicion_acumulada_metodos_sobreescritura;
    int * tipo_args;
} simbolo_t, *simbolo_p;

simbolo_p createSimbolo(	char* id,
							char* nombre,
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
						    int * tipo_args);

void eliminaSimbolo(simbolo_p s);

#endif // SIMBOLO_H