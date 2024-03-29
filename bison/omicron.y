%{
#include "generacion.h"
#include "omicron.h"
#include "tabla_simbolos_clases.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TIPO_RETORNO numero_atributos_clase
#define MAX_TAM_VECTOR 256

extern int linea;
extern int columna;
extern FILE * salida;
extern FILE * sintactico;

simbolos_p simbolos = NULL;
simbolo_p s =NULL;
simbolo_p * simbolos_main=NULL;
char id_ambito[100];
int etiqueta = 0;
int getiqueta =0;
int etiquetas[100];
int cima_etiquetas = 0;
int contador_variables=0;
char * etiqueta_nombre_actual=NULL;
int tipo_actual = 0;
int clase_actual = 0;
int valor_actual = 0;
int num_parametros_actual=0;
int tipos_parametros[100];
int num_variables_locales_actual=0;
int pos_variable_local_actual=0;
int pos_parametro_actual = 0;
char* nombre_actual_simbolo=NULL;
char* nombre_funcion;
char nombres_parametros[100][100];
int  num_parametros_llamada_actual = 0;
int fn_return = 0;
int en_explist = 0;
int tipo_retorno = 0;
int tamanio_vector_actual =0;
char* nombre_prefijo;
int flag_if=0;

int etiqueta_exponencial = 0;
char switch_var[256];
int case_cont = 0;
int switch_etiqueta;
int ultimo;

void escribe_cabecera (FILE * salida);
void escribe_variables (FILE * salida, char* nombre, int tipo, int tamanio);
void gc_suma_enteros(FILE *salida, int es_direccion_op1, int es_direccion_op2);
void gc_resta_enteros(FILE *salida, int es_direccion_op1, int es_direccion_op2);
void gc_exponencial_enteros(FILE *salida, int es_direccion_op1, int es_direccion_op2, int etiqueta_exponencial);
void gc_division_enteros(FILE *salida, int es_direccion_op1, int es_direccion_op2);
void gc_producto_enteros(FILE *salida, int es_direccion_op1, int es_direccion_op2);
void gc_negacion_entero(FILE *salida, int es_direccion_op1);
void gc_and_logico(FILE *salida, int es_direccion_op1, int es_direccion_op2);
void gc_or_logico(FILE *salida, int es_direccion_op1, int es_direccion_op2);
void gc_not_logico(FILE *salida, int es_direccion_op1, int etiqueta);
void gc_igual(FILE *salida, int es_direccion_op1, int es_direccion_op2, int etiqueta);
void gc_distinto(FILE *salida, int es_direccion_op1, int es_direccion_op2, int etiqueta);
void gc_menorigual(FILE *salida, int es_direccion_op1, int es_direccion_op2, int etiqueta);
void gc_mayorigual(FILE *salida, int es_direccion_op1, int es_direccion_op2, int etiqueta);
void gc_menor(FILE *salida, int es_direccion_op1, int es_direccion_op2, int etiqueta);
void gc_mayor(FILE *salida, int es_direccion_op1, int es_direccion_op2, int etiqueta);
void gc_vectores_indice(FILE *salida, int es_direccion_op1, char *lexema, int tam_vector);
void gc_printf_vectores(FILE *salida, int etiqueta, int tamanio, int tipo);
void gc_printf(FILE *salida, int es_direccion_op1, int tipo);
void gc_asigexp_ident(FILE *salida, int es_direccion_op1, char *lexema);
void gc_ifthenelse_inicio(FILE * salida, int exp_es_variable, int etiqueta);
void gc_ifthen_inicio(FILE * salida, int exp_es_variable, int etiqueta);
void gc_ifthen_fin(FILE* salida, int etiqueta);
void gc_ifthenelse_fin_then(FILE* salida, int etiqueta);
void gc_ifthenelse_fin( FILE * salida, int etiqueta);
void gc_ifthenelse_fin( FILE * salida, int etiqueta);
void asignarDestinoPila(FILE* salida, int es_variable, char * eax, char * ebx);
void gc_scanf_funcion(FILE *salida, int num_param_actual, int posicion_parametro, int categoria, int tipo);
void gc_lectura(FILE * salida, char * nombre, int tipo);
void gc_inicio_cuerpo_funcion (FILE *salida, char * lexema, int num_variable_locales);
void gc_final_cuerpo_funcion (FILE *salida, int esdireccion);
void gc_identificador_asignacion_local(FILE *salida, int es_direccion, int categoria, int numero_param, int posicion);
void gc_asignar_exp_a_elementovector(FILE *salida, int es_direccion_op1);
void gc_llamarfuncion (FILE *salida, char * lexema, int num_parametros);
void gc_escribirParametro(FILE *salida, int posicion_parametro, int num_parametros_actual);
void gc_escribirVariableLocal(FILE *salida,int posicion_variable_local);
void gc_escribir_elemento_vector(FILE *salida, int es_direccion_op1, char *lexema, int tam_vector);
void gc_while_fin(FILE * salida,int etiqueta);
void gc_while_inicio(FILE * salida,int  etiqueta);
void gc_while_exp_pila (FILE * salida, int exp_es_variable, int etiqueta);
void imprimir_error(FILE * salida);
void yyerror();

%}

%union{
	tipo_atributos atributos;
}

%token TOK_NONE
%token TOK_CLASS
%token TOK_INHERITS
%token TOK_INSTANCE_OF
%token TOK_DISCARD
%token TOK_ITSELF
%token TOK_FLECHA
%token TOK_HIDDEN
%token TOK_SECRET
%token TOK_EXPOSED
%token TOK_UNIQUE
%token TOK_FUNCTION


%token TOK_MAIN
%token TOK_INT
%token TOK_BOOLEAN
%token TOK_ARRAY
%token TOK_IF
%token TOK_ELSE
%token TOK_WHILE
%token TOK_SCANF
%token TOK_PRINTF
%token TOK_RETURN

%token TOK_IGUAL
%token TOK_DISTINTO
%token TOK_MENORIGUAL
%token TOK_MAYORIGUAL
%token TOK_OR
%token TOK_AND


%token TOK_FOR
%token TOK_SWITCH
%token TOK_CASE
%token TOK_DEFAULT
%token TOK_BREAK
%token TOK_FLOAT
%token TOK_MALLOC
%token TOK_CPRINTF
%token TOK_FREE
%token TOK_SET
%token TOK_OF
%token TOK_UNION
%token TOK_INTERSECTION
%token TOK_ADD
%token TOK_CLEAR
%token TOK_SIZE
%token TOK_CONTAINS
%token TOK_CONSTANTE_REAL
%token TOK_TRUE
%token TOK_FALSE

/*Identificadores*/
%token <atributos> TOK_IDENTIFICADOR

/*Constantes*/
%token <atributos> TOK_CONSTANTE_ENTERA


%type <atributos> programa
%type <atributos> escritura_main
%type <atributos> inicioTabla
%type <atributos> declaraciones
%type <atributos> declaracion
%type <atributos> clase
%type <atributos> clase_escalar
%type <atributos> tipo
%type <atributos> clase_vector
%type <atributos> identificadores
%type <atributos> funciones
%type <atributos> fn_name
%type <atributos> fn_complete_name
%type <atributos> fn_declaration
%type <atributos> funcion
%type <atributos> parametros_funcion
%type <atributos> resto_parametros_funcion
%type <atributos> parametro_funcion
%type <atributos> declaraciones_funcion
%type <atributos> sentencias
%type <atributos> sentencia_simple
%type <atributos> bloque
%type <atributos> asignacion
%type <atributos> elemento_vector
%type <atributos> if_exp
%type <atributos> if_exp_sentencias
%type <atributos> bucle
%type <atributos> for
%type <atributos> switch
%type <atributos> for_inicio
%type <atributos> for_medio
%type <atributos> switch_ini
%type <atributos> casos
%type <atributos> while_exp
%type <atributos> while
%type <atributos> lectura
%type <atributos> escritura
%type <atributos> idf_llamada_funcion
%type <atributos> retorno_funcion
%type <atributos> exp
%type <atributos> comparacion
%type <atributos> constante
%type <atributos> constante_logica
%type <atributos> constante_entera
%type <atributos> identificador

%left '+' '-' TOK_OR
%left '*' '/' TOK_AND
%right MENOSU '!' TOK_EXP

%start programa

%%

programa: inicioTabla TOK_MAIN '{' declaraciones escritura_TS funciones escritura_main sentencias final_programa '}'
		{
			fprintf(sintactico, ";R: programa: TOK_MAIN '{' declaraciones funciones sentencias '}'\n");
		}
		;

escritura_TS: {
			escribir_subseccion_data(salida);
			escribir_cabecera_bss(salida);
			simbolos_main = (simbolo_p *)ht_get_values(simbolos->main_principal);
			for(int i=0;simbolos_main[i]!=NULL;i++){
				nombre_actual_simbolo = simbolos_main[i]->nombre;
				escribe_variables(salida, nombre_actual_simbolo, simbolos_main[i]->tipo, simbolos_main[i]->tamanio > 0 ? simbolos_main[i]->tamanio : 1);
				free(nombre_actual_simbolo);
			}
			escribe_cabecera(salida);
		}
		;

escritura_main: {
			escribir_inicio_main(salida);
		}
		;

final_programa: {
			imprimir_error(salida);
		}
		;

inicioTabla: {
			simbolos = createSimbolos("Programa");
			if (simbolos->main_principal == NULL){
				fprintf(salida, "Error al inicializar la tabla\n");
				return -1;
			}
		}
		;


declaraciones: declaracion
		{
			fprintf(sintactico,";R: declaraciones: declaracion\n");
		}
		|
		declaracion declaraciones
		{
			fprintf(sintactico,";R: declaraciones: declaracion declaraciones\n");
		}
		;

declaracion: modificadores_acceso clase identificadores ';'
		{
			tamanio_vector_actual =0;
			fprintf(sintactico,";R: declaracion: modificadores_acceso clase identificadores ';'\n");
		}
		|
		modificadores_acceso declaracion_clase ';'
		{
			fprintf(sintactico,";R: declaracion: modificadores_acceso declaracion_clase \n");
		}
		;

modificadores_acceso: /*vacio*/
		{
			fprintf(sintactico,";R: modificadores_acceso: \n");
		}
		|
		TOK_HIDDEN TOK_UNIQUE
		{
			fprintf(sintactico,"TOK_HIDDEN TOK_UNIQUE\n");
		}
		|
		TOK_SECRET TOK_UNIQUE
		{
			fprintf(sintactico,"TOK_SECRET TOK_UNIQUE\n");
		}
		|
		TOK_EXPOSED TOK_UNIQUE
		{
			fprintf(sintactico,"TOK_EXPOSED TOK_UNIQUE\n");
		}
		|
		TOK_HIDDEN
		{
		}
		|
		TOK_SECRET
		{
		}
		|
		TOK_EXPOSED
		{
		}
		|
		TOK_UNIQUE
		{
		}
		;

clase: clase_escalar
		{
			clase_actual=ESCALAR;
			fprintf(sintactico,";R: clase: clase_escalar\n");
		}
		|
		clase_vector
		{
			clase_actual=VECTOR;
			fprintf(sintactico,";R: clase: clase_vector\n");
		}
		|
		clase_objeto
		{
			clase_actual=OBJETO;
			fprintf(sintactico,";R: clase: clase_objeto\n");
		}
		;


declaracion_clase: modificadores_clase TOK_CLASS TOK_IDENTIFICADOR TOK_INHERITS identificadores '{' declaraciones funciones '}'
		{
			fprintf(sintactico,";R: declaracion_clase: modificadores_clase TOK_CLASS TOK_IDENTIFICADOR TOK_INHERITS identificadores '{' declaraciones funciones '}'\n");
		}
		|
		modificadores_clase TOK_CLASS TOK_IDENTIFICADOR '{' declaraciones funciones '}'
		{
			fprintf(sintactico,";R: declaracion_clase: modificadores_clase TOK_CLASS TOK_IDENTIFICADOR '{' declaraciones funciones '}'\n");
		}
		;

modificadores_clase: /*vacio*/
		{
			fprintf(sintactico,";R: modificadores_clase: \n");
		}
		;

clase_escalar: tipo
		{
			fprintf(sintactico,";R: clase_escalar: tipo\n");
		}
		;

tipo: TOK_INT
		{
			tipo_actual = INT;
			fprintf(sintactico,";R: tipo: TOK_INT\n");
		}
		|
		TOK_BOOLEAN
		{

			tipo_actual = BOOLEAN;
			fprintf(sintactico,";R: tipo: TOK_BOOLEAN\n");
		}
		;

clase_objeto: '{' TOK_IDENTIFICADOR '}'
		{
			fprintf(sintactico,";R: clase_objeto: '{' TOK_IDENTIFICADOR '}'\n");
		}
		;

clase_vector: TOK_ARRAY tipo '[' TOK_CONSTANTE_ENTERA ']'
		{
			fprintf(sintactico,";R: clase_vector: array tipo '[' TOK_CONSTANTE_ENTERA ']'\n");
			tamanio_vector_actual = $4.valor_entero;

			if ((tamanio_vector_actual < 1) || (tamanio_vector_actual> MAX_TAM_VECTOR)){
				printf("****Error semantico en lin %d: El tamanio del vector excede del maximo o es menor que 1.\n", linea);
				return -1;
			}
		}
		;

identificadores: identificador
		{
			fprintf(sintactico,";R: identificadores: TOK_IDENTIFICADOR\n");
		}
		|
		identificador ',' identificadores
		{
			fprintf(sintactico,";R: identificadores: TOK_IDENTIFICADOR ',' identificadores\n");
		}
		;

funciones: funcion funciones
		{
			fprintf(sintactico,";R: funciones: funcion funciones\n");
		}
		|
		/*vacio*/
		{
			fprintf(sintactico,";R: funciones: \n");
		}
		;

fn_name: TOK_FUNCTION modificadores_acceso tipo_retorno TOK_IDENTIFICADOR
		{
			fprintf(sintactico,";R: funcion: TOK_FUNCTION modificadores_acceso tipo_retorno TOK_IDENTIFICADOR ");
			if(buscarIdNoCualificado(simbolos, $4.lexema, "main", &s, id_ambito)==ERROR){
				for(int i=0; i<=num_parametros_actual;i++){
					tipos_parametros[i]=0;
				}
				num_variables_locales_actual = 0;
				pos_variable_local_actual = 1;
				num_parametros_actual = 0;
				pos_parametro_actual = 0;
				fn_return = 0;
				tipo_retorno = tipo_actual;
				$$.tipo= tipo_retorno;
				strcpy ($$.lexema, $4.lexema);
			}
			else{
				printf("****Error semantico en lin %d: Declaracion duplicada.\n", linea);
				return -1;
			}
		}
		;

fn_complete_name: fn_name '(' parametros_funcion ')'{
			fprintf(sintactico, "'(' parametros_funcion ')' ");
			nombre_funcion = crearNombreFuncion($1.lexema, num_parametros_actual, tipos_parametros);
			nombre_prefijo = addPrefijo("main", nombre_funcion);
			nuevoSimboloEnMain(simbolos, nombre_prefijo,0,FUNCION,0,0,num_parametros_actual,0,0,0,0,0,0,0,0,$1.tipo,0,0,0,EXPOSED,0,0,0,0,0,0,0,tipos_parametros);

			iniciaLocal(simbolos, nombre_funcion);
			free(nombre_prefijo);
			for(int i =0; i<num_parametros_actual; i++){
				nombre_prefijo = addPrefijo(nombre_funcion, nombres_parametros[i]);
				nuevoSimboloEnMain(simbolos, nombre_prefijo, PARAMETRO, tipos_parametros[i],0,0,0,0,0,i,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,NULL);
				free(nombre_prefijo);
			}

			if(simbolos->main_local == NULL){
				fprintf(sintactico, "Error al inicializar la tabla\n");
				return -1;
			}
			if(buscarIdNoCualificado(simbolos, nombre_funcion, "main", &s, id_ambito)){
				s->numero_parametros = num_parametros_actual;
				s->numero_variables_locales = num_variables_locales_actual;
			}
			$$.tipo = $1.tipo;
			strcpy($$.lexema, nombre_funcion);
		}
		;

fn_declaration: fn_complete_name '{' declaraciones_funcion {
			fprintf(sintactico, "'{' declaraciones_funcion ");
			nombre_prefijo = addPrefijo("main", $1.lexema);
			gc_inicio_cuerpo_funcion (salida, nombre_prefijo, num_variables_locales_actual);
			$$.tipo = $1.tipo;

		}
		;


funcion: fn_declaration sentencias '}'
		{
			fprintf(sintactico, "sentencias '}'\n");
			cerrarLocal(simbolos);
			for(int i=0; i<num_parametros_llamada_actual; i++){
				tipos_parametros[num_parametros_llamada_actual]=0;
			}
			simbolos->main_local=NULL;
			$$.tipo = $1.tipo;
			if(fn_return==0){
				printf("****Error: funcion %s sin sentencia return\n", $1.lexema);
				return -1;
			}
		}
		;

tipo_retorno: TOK_NONE
		{
			fprintf(sintactico,";R: tipo_retorno: TOK_NONE\n");
		}
		|
		tipo
		{
			fprintf(sintactico,";R: tipo_retorno: tipo\n");
		}
		;

parametros_funcion: parametro_funcion resto_parametros_funcion
		{
			fprintf(sintactico,";R: parametros_funcion: parametro_funcion resto_parametros_funcion\n");
		}
		|
		/*vacio*/
		{
			fprintf(sintactico,";R: parametros_funcion: \n");
		}
		;

resto_parametros_funcion: ';' parametro_funcion resto_parametros_funcion
		{
			fprintf(sintactico,";R: resto_parametros_funcion: parametro_funcion resto_parametros_funcion\n");
		}
		|
		/*vacio*/
		{
			fprintf(sintactico,";R: resto_parametros_funcion: \n");
		}
		;

parametro_funcion: tipo idpf
		{
			fprintf(sintactico,";R: parametro_funcion: tipo TOK_IDENTIFICADOR\n");
		}
		;

declaraciones_funcion: declaraciones
		{
			fprintf(sintactico,";R: declaraciones_funcion: declaraciones\n");
		}
		|
		/*vacio*/
		{
			fprintf(sintactico,";R: declaraciones_funcion:\n");
		}
		;

sentencias: sentencia
		{
			fprintf(sintactico,";R: sentencias: sentencia\n");
		}
		|
		sentencia sentencias
		{
			fprintf(sintactico,";R: sentencias: sentencia sentencias\n");
		}
		;

sentencia: sentencia_simple ';'
		{
			fprintf(sintactico,";R: sentencia: sentencia_simple ';'\n");
		}
		|
		bloque
		{
			fprintf(sintactico,";R: sentencia: bloque\n");
		}
		;

sentencia_simple: asignacion
		{
			fprintf(sintactico,";R: sentencia_simple: asignacion\n");
		}
		|
		lectura
		{
			fprintf(sintactico,";R: sentencia_simple: lectura\n");
		}
		|
		escritura
		{
			fprintf(sintactico,";R: sentencia_simple: escritura\n");
		}
		|
		retorno_funcion
		{
			fprintf(sintactico,";R: sentencia_simple: retorno_funcion\n");
		}
		|
		identificador_clase '.' TOK_IDENTIFICADOR '(' lista_expresiones ')'
		{
			fprintf(sintactico,";R: sentencia_simple: identificador_clase '.' TOK_IDENTIFICADOR '(' lista_expresiones ')'\n");
		}
		|
		TOK_IDENTIFICADOR '(' lista_expresiones ')'
		{
			fprintf(sintactico,";R: sentencia_simple: TOK_IDENTIFICADOR '(' lista_expresiones ')'\n");
		}
		|
		destruir_objeto
		{
			fprintf(sintactico,";R: sentencia_simple: destruir_objeto\n");
		}
		;

destruir_objeto: TOK_DISCARD TOK_IDENTIFICADOR
		{
			fprintf(sintactico,";R: destruir_objeto: TOK_DISCARD TOK_IDENTIFICADOR\n");
		}
		;

bloque: condicional
		{
			fprintf(sintactico,";R: bloque: condicional\n");
		}
		|
		bucle
		{
			fprintf(sintactico,";R: bloque: bucle\n");
		}
		|
		for
		{
			fprintf(sintactico,";R: bloque: for\n");
		}
		|
		switch
		{
			fprintf(sintactico,";R: bloque: switch\n");
		}
		;



for: for_medio sentencias '}'
	    {
	        for_final(salida, addPrefijo("main", $1.lexema) ,$1.etiqueta);
    	}
		;    


for_medio: for_inicio ';' comparacion ';' TOK_IDENTIFICADOR '+' '+' ')' '{'
    	{
	        if ($3.es_direccion == 1 || $3.tipo != BOOLEAN) {
	            printf("****Error semántico en lin %d: Bucle con condicion de tipo int (%s)\n", linea, $1.lexema);

	        }

	        if (buscarIdNoCualificado(simbolos, $3.lexema, "main", &s, id_ambito)) {
	            $5.tipo = s->tipo;
	        }
	        else {
	            printf("****Error semántico en lin %d: Acceso a variable no declarada (%s)\n", linea, $1.lexema);
	        }

	        if ($5.tipo != ENTERO) {
	            printf("****Error semántico en lin %d: Indice de bucle no entero (%s)\n", linea, $5.lexema);
	        }

	        strcpy($$.lexema, $1.lexema);
	        $$.etiqueta = $1.etiqueta;
	        for_medio(salida, $3.es_direccion, $1.etiqueta);
	    }
	    ;

for_inicio: TOK_FOR '(' asignacion
    	{
        	strcpy($$.lexema, $3.lexema);
        	for_ini(salida, etiqueta);
        	$$.etiqueta = etiqueta;
	        etiqueta++;
    	}


switch: switch_ini casos'}'
   		 {   
    	    switch_fin(salida, switch_etiqueta);
   		 }

switch_ini: TOK_SWITCH '(' TOK_IDENTIFICADOR ')' '{'
    	{
	        if (buscarIdNoCualificado(simbolos, $3.lexema, "main", &s, id_ambito)==ERROR) {
	            printf("****Error semántico en lin %d: Acceso a variable no declarada (%s)\n", linea, $3.lexema);
	        }
	        case_cont = 0;
	        strcpy (switch_var, $3.lexema);
	        switch_etiqueta = etiqueta;
	        etiqueta ++;
	        switch_ini(salida);
    	}

casos: caso casos
	    {
	    }
	    |
	    caso
	    {
	    }
  
caso: cabecera final_caso
	    {
	    } 

cabecera: TOK_CASE constante_entera ':'
	    {
	        case_cont ++;
	        escribir_operando(salida, addPrefijo("main",switch_var), 1);
	        switch_caso(salida, switch_var, switch_etiqueta, case_cont, ultimo);
	    }

final_caso: sentencias TOK_BREAK ';'
	    {
	        switch_fin_caso(salida, switch_etiqueta, case_cont);
	    }

asignacion: TOK_IDENTIFICADOR '=' exp
		{
			if (simbolos->main_local != NULL){

				if(buscarIdNoCualificado(simbolos, $1.lexema, "main", &s, id_ambito)==ERROR){
					printf("****Error semántico en lin %d: Acceso a variable no declarada (%s)\n", linea, $1.lexema);
					return -1;
				}

				if (s->tipo != $3.tipo){
					printf("****Error semántico en lin %d: Asignacion incompatible.\n", linea);
					return -1;
		    	}

			    if (s->clase == PARAMETRO){
			        gc_identificador_asignacion_local(salida, $3.es_direccion, s->clase, num_parametros_actual, s->posicion_parametro);
			    } else {
			        gc_identificador_asignacion_local(salida, $3.es_direccion, s->clase, num_variables_locales_actual, s->posicion_variable_local);
				}
			}
			else{
				if(buscarIdNoCualificado(simbolos, $1.lexema, "main", &s, id_ambito)){
					if (s->tipo != $3.tipo){
						printf("****Error semántico en lin %d: Asignacion incompatible.\n", linea);
						return -1;
		    		}
					gc_asigexp_ident(salida, $3.es_direccion, s->id);
				}
				else{
					printf("****Error semántico en lin %d: Acceso a variable no declarada (%s)\n", linea, $1.lexema);
				}
				fprintf(sintactico,";R: asignacion:  TOK_IDENTIFICADOR '=' exp\n");
				}
			}
		|
		elemento_vector '=' exp
		{
			fprintf(sintactico,";R: asignacion: elemento_vector '=' exp\n");
			if ($1.tipo != $3.tipo){
				printf("****Error semántico en lin %d: Asignacion incompatible\n", linea);
				return -1;
			}
			gc_asignar_exp_a_elementovector(salida, $3.es_direccion);
			$$.tipo=$1.tipo;
			$$.es_direccion = 0;
		}
		|
		elemento_vector '=' TOK_INSTANCE_OF TOK_IDENTIFICADOR '(' lista_expresiones ')'
		{
			fprintf(sintactico,";R: asignacion: elemento_vector '=' TOK_INSTANCE_OF TOK_IDENTIFICADOR '(' lista_expresiones ')'\n");
		}
		|
		TOK_IDENTIFICADOR '=' TOK_INSTANCE_OF TOK_IDENTIFICADOR '(' lista_expresiones ')'
		{
			fprintf(sintactico,";R: asignacion: TOK_IDENTIFICADOR '=' TOK_INSTANCE_OF TOK_IDENTIFICADOR '(' lista_expresiones ')'\n");
		}
		|
		identificador_clase '.' TOK_IDENTIFICADOR '=' exp
		{
			fprintf(sintactico,";R: asignacion: identificador_clase '.' TOK_IDENTIFICADOR '=' exp\n");
		}
		;

elemento_vector: TOK_IDENTIFICADOR '[' exp ']'
		{
			if($3.tipo != INT){
				printf("****Error semántico en lin %d: El indice en una operacion de indexacion tiene que ser de tipo entero.\n", linea);
				return -1;
			}

			fprintf(sintactico,";R: elemento_vector: TOK_IDENTIFICADOR '[' exp ']'\n");
			if(simbolos->main_local !=NULL){
				if(buscarIdNoCualificado(simbolos, $1.lexema, "main", &s, id_ambito)==ERROR){
					printf("****Error semantico en lin %d: Acceso a variable no declarada\n", linea);
				}
			}else{
				if(buscarIdNoCualificado(simbolos, $1.lexema, "main", &s, id_ambito)==ERROR){
					printf("****Error semantico en lin %d: Acceso a variable no declarada\n", linea);
				}
			}

			
			if (s->clase != VECTOR){
				printf("****Error semántico en lin %d: Intento de indexacion de una variable que no es de tipo vector.\n", linea);
				return -1;
			}

			gc_escribir_elemento_vector(salida, $3.es_direccion, s->id, s->tamanio);
			$$.es_direccion = 1;
			$$.tipo = s->tipo;
			
		}
		;

condicional: if_exp sentencias '}'
		{

			fprintf(sintactico,";R: condicional: if_exp '(' exp ')' '{' sentencias '}'\n");
			gc_ifthen_fin(salida, $1.etiqueta);
		}
		|
		if_exp_sentencias TOK_ELSE '{' sentencias '}'
		{
			fprintf(sintactico,";R: condicional: if_exp_sentencias TOK_ELSE '{' sentencias '}'\n");
			gc_ifthenelse_fin(salida, $1.etiqueta);
		}
		;

if_exp_sentencias: if_exp sentencias '}'
		{
			fprintf(sintactico,";R: if_exp_sentencias: if_exp sentencias '}'\n");
			$$.etiqueta = $1.etiqueta;
			gc_ifthenelse_fin_then(salida, $1.etiqueta);
		}
		;

if_exp: TOK_IF '(' exp ')' '{'
		{
			fprintf(sintactico,";R: if_exp: TOK_IF '(' exp ')' '{'\n");
			if ($3.tipo != BOOLEAN){
				if($3.valor_entero != 0){
					printf("****Error semántico en lin %d: Comparacion con condicion de tipo int.\n", linea);
				}else{
					printf("****Error semántico en lin %d: Comparacion con operandos boolean.\n", linea);
				}
				return -1;
			}

			$$.etiqueta = etiqueta++;
			gc_ifthen_inicio(salida, $3.es_direccion, $$.etiqueta);
			
		}
		;

bucle : while_exp sentencias '}'{
			fprintf(sintactico,";R: bucle: TOK_WHILE '(' exp ')' '{' sentencias '}'\n");
			etiqueta = etiquetas[cima_etiquetas];
			gc_while_fin(salida, etiqueta);
			cima_etiquetas --;
		}
		;

while_exp : while exp ')' '{' {
			if($2.tipo != BOOLEAN){
	 			if($2 .valor_entero != 0){
					printf("****Error semántico en lin %d: Bucle while con condicion de tipo int.\n", linea);
				}else{
					printf("****Error semántico en lin %d: Bucle while con operandos boolean.\n", linea);
				}
				return -1;
			}
			etiqueta = etiquetas[cima_etiquetas];
			gc_while_exp_pila(salida, $2.es_direccion, etiqueta);
		}
		;


while : TOK_WHILE '('{
			getiqueta++;
        	cima_etiquetas++;
        	etiquetas[cima_etiquetas]=getiqueta;
        	etiqueta = getiqueta;
			gc_while_inicio(salida, etiqueta);
		}
		;

lectura: TOK_SCANF TOK_IDENTIFICADOR
		{
			if(simbolos->main_local != NULL){
				if(buscarIdNoCualificado(simbolos, $2.lexema, "main", &s, id_ambito)==ERROR){
					printf("****Error semántico en lin %d: Acceso a variable no declarada (%s).\n", linea, $2.lexema);
					return -1;
				}
				
				if(s->clase == PARAMETRO){
					gc_scanf_funcion(salida, num_parametros_actual, s->posicion_parametro, s->clase, s->tipo);
				}
				else{
					gc_scanf_funcion(salida, num_variables_locales_actual, s->posicion_variable_local, s->clase, s->tipo);
				}
			}else{
				if(buscarIdNoCualificado(simbolos, $2.lexema, "main", &s, id_ambito)==ERROR){
					printf("****Error semántico en lin %d: Acceso a variable no declarada (%s).\n", linea, $2.lexema);
					return -1;
				}
				if(s->clase == VECTOR){
					printf("****Error semántico en lin %d: Variable local de tipo no escalar.\n", linea);
					return -1;
				}
				gc_lectura(salida, s->id, s->tipo);
			}
			fprintf(sintactico,";R: lectura: TOK_SCANF TOK_IDENTIFICADOR\n");
		}
		|
		TOK_SCANF elemento_vector
		{
			fprintf(sintactico,";R: lectura: TOK_SCANF elemento_vector\n");
		}
		;

escritura: TOK_PRINTF exp
		{
			gc_printf(salida, $2.es_direccion, $2.tipo);
			fprintf(sintactico,";R: escritura: TOK_PRINTF exp\n");
		}
		;


idf_llamada_funcion: TOK_IDENTIFICADOR
		{
			en_explist = 1;
			strcpy($$.lexema,$1.lexema);
		};

retorno_funcion: TOK_RETURN exp
		{
			fprintf(sintactico,";R: retorno_funcion: TOK_RETURN exp\n");
			if (buscarIdNoCualificado(simbolos, nombre_funcion, "main", &s, id_ambito)==ERROR){
				printf("****Error semántico en lin %d: Acceso a variable no declarada (%s).\n", linea, nombre_funcion);
				return -1;
			}
			if ($2.tipo != tipo_retorno){
				printf("****Error semántico en lin %d: Asignacion incompatible.\n", linea);
				return -1;
			}
			if ($2.es_direccion != 0 && $2.es_direccion != 1){
				printf("****Error semántico en lin %d: Direccion incorrecta.\n", linea);
				return -1;
			}
			fn_return++;
			gc_final_cuerpo_funcion(salida, $2.es_direccion);
		}
		|
		TOK_RETURN TOK_NONE
		{
			fprintf(sintactico,";R: retorno_funcion: TOK_RETURN TOK_NONE\n");
		}
		;

exp: exp '+' exp
		{
			if ($1.tipo != INT || $3.tipo != INT){
				printf("****Error semántico en lin %d: Operacion aritmetica con operandos boolean.\n", linea);
				return -1;
			}
			gc_suma_enteros(salida, $1.es_direccion, $3.es_direccion);
			$$.es_direccion = 0;
			$$.tipo = INT;
			fprintf(sintactico,";R: exp: exp '+' exp\n");
		}
		|
		exp '-' exp
		{
			if ($1.tipo != INT || $3.tipo != INT){
				printf("****Error semántico en lin %d: Operacion aritmetica con operandos boolean.\n", linea);
				return -1;
			}
			gc_resta_enteros(salida, $1.es_direccion, $3.es_direccion);
			$$.es_direccion = 0;
			$$.tipo = INT;
			fprintf(sintactico,";R: exp: exp '-' exp\n");
		}
		|
		exp TOK_EXP exp
		{
			if($1.tipo != INT || $3.tipo != INT){
				printf("****Error semántico en lin %d: Operacion aritmetica con operandos boolean.\n", linea);
				return -1;
			}
			fprintf(sintactico,";R: exp: exp '^' exp\n");
			$$.es_direccion = 0;
			$$.tipo = INT;
			gc_exponencial_enteros(salida, $1.es_direccion, $3.es_direccion, etiqueta_exponencial);
			etiqueta_exponencial ++;
		}
		|
		exp '/' exp
		{
			if ($1.tipo != INT || $3.tipo != INT){
				printf("****Error semántico en lin %d: Operacion aritmetica con operandos boolean.\n", linea);
				return -1;
			}
			gc_division_enteros(salida, $1.es_direccion, $3.es_direccion);
			$$.es_direccion = 0;
			$$.tipo = INT;
			fprintf(sintactico,";R: exp: exp '/' exp\n");
		}
		|
		exp '*' exp
		{
			if ($1.tipo != INT || $3.tipo != INT){
				printf("****Error semántico en lin %d: Operacion aritmetica con operandos boolean.\n", linea);
				return -1;
			}
			gc_producto_enteros(salida, $1.es_direccion, $3.es_direccion);
			$$.es_direccion = 0;
			$$.tipo = INT;
			fprintf(sintactico,";R: exp: exp '*' exp\n");
		}
		|
		'-' exp %prec MENOSU
		{
			if ($2.tipo!=INT){
				printf("****Error semántico en lin %d: Operacion aritmetica con operandos boolean.\n", linea);
				return -1;
			}
			gc_negacion_entero(salida, $2.es_direccion);
			$$.es_direccion = 0;
			$$.tipo = INT;
			fprintf(sintactico,";R: exp: '-' exp\n");
		}
		|
		exp TOK_AND exp
		{
			if ($1.tipo != BOOLEAN || $3.tipo != BOOLEAN) {
				printf("****Error semántico en lin %d: Operacion logica con operandos int.\n", linea);
				return -1;
			}
			gc_and_logico(salida, $1.es_direccion, $3.es_direccion);
			$$.es_direccion = 0;
			$$.tipo = BOOLEAN;
			fprintf(sintactico,";R: exp: exp TOK_AND exp\n");
		}
		|
		exp TOK_OR exp
		{
			if ($1.tipo!=BOOLEAN || $3.tipo!=BOOLEAN) {
				printf("****Error semántico en lin %d: Operacion logica con operandos int.\n", linea);
				return -1;
			}
			gc_or_logico(salida, $1.es_direccion, $3.es_direccion);
			$$.es_direccion = 0;
			$$.tipo = BOOLEAN;
			fprintf(sintactico,";R: exp: exp TOK_OR exp\n");
		}
		|
		'!' exp
		{
			if ($2.tipo!=BOOLEAN) {
				printf("****Error semántico en lin %d: Operacion logica con operandos int.\n", linea);
				return -1;
			}
			gc_not_logico(salida, $2.es_direccion, etiqueta);
			$$.es_direccion = 0;
			$$.tipo = BOOLEAN;
			etiqueta++;
			fprintf(sintactico,";R: exp: '!' exp \n");
		}
		|
		TOK_IDENTIFICADOR
		{
			if(simbolos->main_local == NULL){
				if(buscarIdNoCualificado(simbolos, $1.lexema, "main", &s, id_ambito)==ERROR){
					printf("****Error semántico en lin %d: Acceso a variable no declarada (%s).\n", linea, $1.lexema);
					return -1;
				}
				if(en_explist == 0){
					fprintf (salida, "\t\tpush dword _%s\n", s->id);
				}else{
					fprintf (salida, "\t\tpush dword [_%s]\n", s->id);
				}
			}else{
				if(buscarIdNoCualificado(simbolos, $1.lexema, "main", &s, id_ambito)==ERROR){
					printf("****Error semántico en lin %d: Acceso a variable no declarada (%s).\n", linea, $1.lexema);
					return -1;
				}
				if(s->clase == PARAMETRO){
					gc_escribirParametro(salida, s->posicion_parametro, num_parametros_actual);
				}else{
					gc_escribirVariableLocal(salida, s->posicion_variable_local);
				}
			}
			$$.tipo = s->tipo;
			$$.es_direccion = 1;

		}
		|
		constante
		{
			$$.tipo = $1.tipo;
			$$.es_direccion = $1.es_direccion;
			fprintf(sintactico,";R: exp: constante\n");
		}
		|
		'(' exp ')'
		{
			$$.tipo = $2.tipo;
			$$.es_direccion = $2.es_direccion;
			fprintf(sintactico,";R: exp: '(' exp ')'\n");
		}
		|
		'(' comparacion ')'
		{
			$$.tipo = $2.tipo;
			$$.es_direccion = $2.es_direccion;
			fprintf(sintactico,";R: exp: '(' comparacion ')'\n");
		}
		|
		elemento_vector
		{
			$$.tipo = $1.tipo;
			$$.es_direccion = $1.es_direccion;
			fprintf(sintactico,";R: exp: '(' elemento_vector ')'\n");
		}
		|
		idf_llamada_funcion '(' lista_expresiones ')'
		{
			fprintf(sintactico,";R: exp: TOK_IDENTIFICADOR '(' lista_expresiones ')'\n");
			
			int aux[100];
			int j=0;
			for (int i =num_parametros_llamada_actual-1; i>=0; i--)	{
				aux[j]=tipos_parametros[i];
				j++;
			}
			for (int i = 0; i <num_parametros_llamada_actual; ++i){
				tipos_parametros[i]=0;
			}
			for (int i=0; i<num_parametros_llamada_actual; ++i){
				tipos_parametros[i]=aux[i];
			}
			for (int i = 0; i <num_parametros_llamada_actual; ++i){
				aux[i]=0;
			}
			nombre_funcion = crearNombreFuncion($1.lexema, num_parametros_llamada_actual, tipos_parametros);
			nombre_prefijo= addPrefijo("main", nombre_funcion);
			if(buscarIdNoCualificado(simbolos, nombre_funcion, "main", &s, id_ambito)==ERROR){
				printf("****Error semántico en lin %d: Acceso a funcion no declarada, revisar parametros o nombre de la funcion(%s).\n", linea, $1.lexema);
				return -1;
			}
			if (s->tipo != FUNCION){
				printf("****Error semántico en lin %d: Identificador no es de categoriaegoria funcion\n", linea);
				return -1;
			}

			if (en_explist == 1){
				printf("****Error semántico en lin %d: No esta permitido el uso de llamadas a funciones como parametros de otras funciones.\n", linea);
				return -1;
			}

			/*Comprobamos que el numero de parametros es correcto*/
			if (s->numero_parametros != num_parametros_llamada_actual){
				printf("****Error semántico en lin %d: Numero incorrecto de parametros en llamada a funcion.\n", linea);
				return -1;
			}

			$$.tipo = s->TIPO_RETORNO;
			$$.es_direccion = 0;
			gc_llamarfuncion(salida, s->id, s->numero_parametros);
			num_parametros_actual=0;
			for (int i=0; i<num_parametros_llamada_actual; ++i){
				tipos_parametros[i]=aux[i];
			}
			num_parametros_llamada_actual = 0;

		}
		|
		identificador_clase '.' TOK_IDENTIFICADOR '(' lista_expresiones ')'
		{
			fprintf(sintactico,";R: exp: identificador_clase '.' TOK_IDENTIFICADOR '(' lista_expresiones ')'\n");
		}
		|
		identificador_clase '.' TOK_IDENTIFICADOR
		{
			fprintf(sintactico,";R: exp: identificador_clase '.' TOK_IDENTIFICADOR\n");
		}
		;


identificador_clase: TOK_IDENTIFICADOR
		{
			fprintf(sintactico,";R: identificador_clase: TOK_IDENTIFICADOR\n");
		}
		|
		TOK_ITSELF
		{
			fprintf(sintactico,";R: identificador_clase: TOK_ITSELF\n");
		}
		;

lista_expresiones: exp resto_lista_expresiones
		{
			fprintf(sintactico,";R: lista_expresiones: exp resto_lista_expresiones\n");
			en_explist = 0;
			tipos_parametros[num_parametros_llamada_actual]=$1.tipo;
			num_parametros_llamada_actual++;
		}
		|
		/*vacio*/
		{
			en_explist=0;
			fprintf(sintactico,";R: lista_expresiones: \n");
		}
		;

resto_lista_expresiones: ',' exp resto_lista_expresiones
		{
			fprintf(sintactico,";R: resto_lista_expresiones: exp resto_lista_expresiones\n");
			tipos_parametros[num_parametros_llamada_actual]=$2.tipo;
			num_parametros_llamada_actual++;
		}
		|
		/*vacio*/
		{
			fprintf(sintactico,";R: resto_lista_expresiones: \n");
		}
		;

comparacion: exp TOK_IGUAL exp
		{
			if ($1.tipo!=INT || $3.tipo!=INT){
				printf("****Error semántico en lin %d: Comparacion con operandos boolean.\n", linea);
				return -1;
			}
			gc_igual(salida, $1.es_direccion, $3.es_direccion, etiqueta);
			$$.etiqueta = etiqueta++;
			$$.es_direccion = 0;
			$$.tipo = BOOLEAN;
			fprintf(sintactico,";R: comparacion: exp TOK_IGUAL exp\n");
		}
		|
		exp TOK_DISTINTO exp
		{
			if ($1.tipo!=INT || $3.tipo!=INT){
				printf("****Error semántico en lin %d: Comparacion con operandos boolean.\n", linea);
				return -1;
			}
			gc_distinto(salida, $1.es_direccion, $3.es_direccion, etiqueta);
			$$.etiqueta = etiqueta++;
			$$.es_direccion = 0;
			$$.tipo = BOOLEAN;
			fprintf(sintactico,";R: comparacion: exp TOK_DISTINTO exp\n");
		}
		|
		exp TOK_MAYORIGUAL exp
		{
			if ($1.tipo!=INT || $3.tipo!=INT){
				printf("****Error semántico en lin %d: Comparacion con operandos boolean.\n", linea);
				return -1;
			}
			gc_mayorigual(salida, $1.es_direccion, $3.es_direccion, etiqueta);
			$$.etiqueta = etiqueta++;
			$$.es_direccion = 0;
			$$.tipo = BOOLEAN;
			fprintf(sintactico,";R: comparacion: exp TOK_MAYORIGUAL exp\n");
		}
		|
		exp TOK_MENORIGUAL exp
		{
			if ($1.tipo!=INT || $3.tipo!=INT){
				printf("****Error semántico en lin %d: Comparacion con operandos boolean.\n", linea);
				return -1;
			}
			gc_menorigual(salida, $1.es_direccion, $3.es_direccion, etiqueta);
			$$.etiqueta = etiqueta++;
			$$.es_direccion = 0;
			$$.tipo = BOOLEAN;
			fprintf(sintactico,";R: comparacion: exp TOK_MENORIGUAL exp\n");
		}
		|
		exp '>' exp
		{
			if ($1.tipo!=INT || $3.tipo!=INT){
				printf("****Error semántico en lin %d: Comparacion con operandos boolean.\n", linea);
				return -1;
			}
			gc_mayor(salida, $1.es_direccion, $3.es_direccion, etiqueta);
			$$.etiqueta = etiqueta++;
			$$.es_direccion = 0;
			$$.tipo = BOOLEAN;
			fprintf(sintactico,";R: comparacion: exp '>' exp\n");
		}
		|
		exp '<' exp
		{
			if ($1.tipo!=INT || $3.tipo!=INT){
				printf("****Error semántico en lin %d: Comparacion con operandos boolean.\n", linea);
				return -1;
			}
			gc_menor(salida, $1.es_direccion, $3.es_direccion, etiqueta);
			$$.etiqueta = etiqueta++;
			$$.es_direccion = 0;
			$$.tipo = BOOLEAN;
			fprintf(sintactico,";R: comparacion: exp '<' exp\n");
		}
		;

constante: constante_logica
		{
			$$.tipo = $1.tipo;
			$$.es_direccion = $1.es_direccion;
			fprintf(sintactico,";R: constante: constante_logica\n");
		}
		|
		constante_entera
		{
			$$.tipo = $1.tipo;
			$$.es_direccion = $1.es_direccion;
			fprintf(sintactico,";R: constante: constante_entera\n");
		}
		;

constante_logica: TOK_TRUE
		{
			$$.tipo = BOOLEAN;
			$$.es_direccion = 0;
			fprintf(salida, "\t\tpush dword 1\n");
			fprintf(sintactico,";R: constante_logica: TOK_TRUE\n");
		}
		|
		TOK_FALSE
		{
			$$.tipo = BOOLEAN;
			$$.es_direccion = 0;
			fprintf(salida, "\t\tpush dword 0\n");
			fprintf(sintactico,";R: constante_logica: TOK_FALSE\n");
		}
		;

constante_entera: TOK_CONSTANTE_ENTERA
		{
			$$.tipo = INT;
			$$.es_direccion = 0;
			fprintf(salida, "\t\tpush dword %d\n", $1.valor_entero);
			fprintf(sintactico,";R: constante_entera: TOK_CONSTANTE_ENTERA\n");
		}
		;


idpf : TOK_IDENTIFICADOR
		{
			clase_actual = ESCALAR;
			strcpy(nombres_parametros[pos_parametro_actual], $1.lexema);
			tipos_parametros[pos_parametro_actual] = tipo_actual;
			pos_parametro_actual++;
		  	num_parametros_actual++;
		};

identificador: TOK_IDENTIFICADOR
		{
			if(simbolos->main_local != NULL){
			nombre_actual_simbolo = addPrefijo(ht_get_name(simbolos->main_local), $1.lexema);
				if(buscarIdNoCualificado(simbolos, $1.lexema, "main", &s, id_ambito)==ERROR){
					nuevoSimboloEnMain(simbolos, nombre_actual_simbolo, clase_actual,tipo_actual,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,EXPOSED,0,0,0,0,0,0,0,NULL);
					pos_variable_local_actual++;
					num_variables_locales_actual++;
					free(nombre_actual_simbolo);
				}
			} else {
				nombre_actual_simbolo = $1.lexema;
				nombre_actual_simbolo = addPrefijo("main", nombre_actual_simbolo);
				if(buscarParaDeclararIdTablaSimbolosAmbitos(simbolos, nombre_actual_simbolo, &s, id_ambito)){
					printf("****Error semántico en lin %d por declaracion duplicada del elemento %s\n", linea, $1.lexema);
				}
				else{
					$1.tipo = tipo_actual;
					nuevoSimboloEnMain(simbolos, nombre_actual_simbolo, clase_actual,tipo_actual,0,1,0,0,0,0,0,tamanio_vector_actual,0,0,0,0,0,0,0,EXPOSED,0,0,0,0,0,0,0,NULL);
				}
				fprintf(sintactico,";R: identificador: TOK_IDENTIFICADOR\n");
				free(nombre_actual_simbolo);
			}
		}
		;
%%

void escribe_cabecera (FILE * salida){
	escribir_segmento_codigo(salida);
	return ;
}

void escribe_variables (FILE * salida, char* nombre, int tipo, int tamanio){
	declarar_variable(salida, nombre, tipo, tamanio);
}

void imprimir_error(FILE * salida){
	escribir_fin(salida);
	return;
}

void gc_suma_enteros(FILE *salida, int es_direccion_op1, int es_direccion_op2) {
	sumar(salida, es_direccion_op1, es_direccion_op2);
	return;
}

void gc_resta_enteros(FILE *salida, int es_direccion_op1, int es_direccion_op2) {
	restar(salida, es_direccion_op1, es_direccion_op2);
	return;
}


void gc_exponencial_enteros(FILE *salida, int es_direccion_op1, int es_direccion_op2, int etiqueta_exponencial){
	exponencial(salida, es_direccion_op1, es_direccion_op2, etiqueta_exponencial);
	return;
}


void gc_division_enteros(FILE *salida, int es_direccion_op1, int es_direccion_op2) {
	dividir(salida, es_direccion_op1, es_direccion_op2);
	return;
}

void gc_producto_enteros(FILE *salida, int es_direccion_op1, int es_direccion_op2) {
	multiplicar(salida, es_direccion_op1, es_direccion_op2);
	return;
}

void gc_negacion_entero(FILE *salida, int es_direccion_op1){
	cambiar_signo(salida, es_direccion_op1);
	return;
}

void gc_and_logico(FILE *salida, int es_direccion_op1, int es_direccion_op2){
	y(salida, es_direccion_op1, es_direccion_op2);
	return;
}

void gc_or_logico(FILE *salida, int es_direccion_op1, int es_direccion_op2){
	o(salida, es_direccion_op1, es_direccion_op2);
	return;
}

void gc_not_logico(FILE *salida, int es_direccion_op1, int etiqueta){
	no(salida, es_direccion_op1, etiqueta);
	return;
}

void gc_igual(FILE *salida, int es_direccion_op1, int es_direccion_op2, int etiqueta){
	igual(salida, es_direccion_op1, es_direccion_op2, etiqueta);
	return;
}

void gc_distinto(FILE *salida, int es_direccion_op1, int es_direccion_op2, int etiqueta){
	distinto(salida, es_direccion_op1, es_direccion_op2, etiqueta);
	return;
}

void gc_menorigual(FILE *salida, int es_direccion_op1, int es_direccion_op2, int etiqueta){
	menor_igual(salida, es_direccion_op1, es_direccion_op2, etiqueta);
	return;
}

void gc_mayorigual(FILE *salida, int es_direccion_op1, int es_direccion_op2, int etiqueta){
	mayor_igual(salida, es_direccion_op1, es_direccion_op2, etiqueta);
	return;
}

void gc_menor(FILE *salida, int es_direccion_op1, int es_direccion_op2, int etiqueta){
	menor(salida, es_direccion_op1, es_direccion_op2, etiqueta);
	return;
}

void gc_mayor(FILE *salida, int es_direccion_op1, int es_direccion_op2, int etiqueta){
	mayor(salida, es_direccion_op1, es_direccion_op2, etiqueta);
	return;
}

void gc_vectores_indice(FILE *salida, int es_direccion_op1, char *lexema, int tam_vector){
	escribir_elemento_vector(salida,lexema, tam_vector, es_direccion_op1);
	return;
}


void gc_asigexp_ident(FILE *salida, int es_direccion_op1, char *lexema){
	asignar(salida, lexema, es_direccion_op1);
	return;
}


void gc_printf(FILE *salida, int es_direccion_op1, int tipo){
	escribir(salida, es_direccion_op1, tipo);
	return;
}

void gc_ifthenelse_inicio(FILE * salida, int exp_es_variable, int etiqueta){
	ifthenelse_inicio(salida, exp_es_variable, etiqueta);
	return;
}


void gc_ifthen_inicio(FILE * salida, int exp_es_variable, int etiqueta){
	ifthen_inicio(salida, exp_es_variable, etiqueta);
	return;
}


void gc_ifthen_fin(FILE* salida, int etiqueta){
    ifthen_fin(salida, etiqueta);
    return;
}


void gc_ifthenelse_fin_then(FILE* salida, int etiqueta){
    ifthenelse_fin_then(salida, etiqueta);
    return;
}

void gc_ifthenelse_fin( FILE * salida, int etiqueta){
	ifthenelse_fin(salida, etiqueta);
	return;
}


void gc_asignarDestinoPila(FILE* salida, int es_variable, char * eax, char * ebx){
	asignarDestinoEnPila(salida, es_variable);
	return;
}

void gc_scanf_funcion(FILE *salida, int num_param_actual, int posicion_parametro, int categoria, int tipo){
	if (categoria == PARAMETRO){
		escribirParametro(salida, posicion_parametro, num_param_actual);
	}else {
		escribirVariableLocal(salida, posicion_parametro);
	}

	if(tipo==INT){
		fprintf(salida,"\t\tcall scan_int\n");
	}else{
		fprintf(salida,"\t\tcall scan_boolean\n");
	}
	fprintf(salida,"\t\tadd esp,4\n");
}

void gc_lectura(FILE * salida, char * nombre, int tipo){
	leer(salida, nombre, tipo);
}

void gc_inicio_cuerpo_funcion (FILE *salida, char * lexema, int num_variable_locales){
	declararFuncion(salida, lexema, num_variable_locales);
}

void gc_final_cuerpo_funcion (FILE *salida, int esdireccion){
	retornarFuncion(salida, esdireccion);
}


void gc_escribirParametro(FILE *salida, int posicion_parametro, int num_parametros_actual){
	escribirParametro(salida, posicion_parametro, num_parametros_actual);
}

void gc_escribirVariableLocal(FILE *salida,int posicion_variable_local){
	escribirVariableLocal(salida, posicion_variable_local);
}


void gc_identificador_asignacion_local(FILE *salida, int es_direccion, int categoria, int numero_param, int posicion){
	fprintf(salida,"\t\tpop dword eax\n");
	if (es_direccion == 1)
		fprintf(salida,"\t\tmov dword eax, [eax]\n");
	if (categoria == PARAMETRO){
		fprintf(salida,"\t\tmov dword [ebp+4+4*%d], eax\n", numero_param-posicion);
	}else{
		fprintf(salida,"\t\tmov dword [ebp-4*%d], eax\n", posicion);
	}
	return;
}

void gc_asignar_exp_a_elementovector(FILE *salida, int es_direccion_op1){
	asignar_valor_vector(salida, es_direccion_op1);
	return;
}

void gc_llamarfuncion (FILE *salida, char * lexema, int num_parametros){
	llamarFuncion(salida, lexema, num_parametros);
}


void gc_escribir_elemento_vector(FILE *salida, int es_direccion_op1, char *lexema, int tam_vector){
	escribir_elemento_vector(salida,lexema, tam_vector, es_direccion_op1);
}


void gc_while_fin(FILE * salida,int  etiqueta){
	while_fin(salida, etiqueta);
}

void gc_while_inicio(FILE * salida,int  etiqueta){
	while_inicio(salida, etiqueta);
}

void gc_while_exp_pila (FILE * salida, int exp_es_variable, int etiqueta){
	while_exp_pila (salida, exp_es_variable, etiqueta);
}


void for_ini(FILE *fpasm, int etiqueta)
{
	if (!fpasm)
	{
		printf("Error del fichero (elevar)\n");
		return;
	}

	fprintf(fpasm, "for_%d:\n", etiqueta);
	return;
}

void for_medio(FILE *fpasm, int es_variable, int etiqueta)
{
	if (!fpasm)
	{
		return;
	}

	fprintf(fpasm, "\tpop eax\n");
	if (es_variable)
	{
		fprintf(fpasm, "\tmov eax, [eax]\n");
	}
	fprintf(fpasm, "\tcmp eax, 0\n");
	fprintf(fpasm, "\tje near fin_for_%d\n", etiqueta);
}

void for_final(FILE *fpasm, char *indice ,int etiqueta)
{
	if (!fpasm)
	{
		return;
	}
	fprintf(fpasm, "\tmov eax, [_%s]\n\tadd eax, 1\n\t mov [_%s], eax\n", indice, indice);
	fprintf(fpasm, "\tjmp for_%d\nfin_for_%d:\n", etiqueta, etiqueta);
	return;
}

void switch_fin(FILE *fpasm, int etiqueta) {
	if (!fpasm)
	{
		return;
	}

	fprintf(fpasm, "fin_switch_%d:\n", etiqueta);
}
void switch_ini(FILE *fpasm) {
	if (!fpasm)
	{
		return;
	}
	fprintf(fpasm, ";Switch\n");
}
void switch_caso(FILE *fpasm, char *switch_var, int etiqueta, int case_cont, int ultimo){
	if (!fpasm)
	{
		return;
	}
	fprintf(fpasm, "\tpop ecx\n\tpop eax\n");
	//Siempre es una variable ( se controla antes)
	fprintf(fpasm, "\tmov ecx, [ecx]\n");

	if (ultimo == 0)
		fprintf(fpasm, "\tcmp eax, ecx\n\tjne near switch_%d_case_%d\n", etiqueta, case_cont);
	else
		fprintf(fpasm, "\tcmp eax, ecx\n\tjne near fin_switch_%d\n", etiqueta);

}

void switch_fin_caso(FILE *fpasm, int etiqueta, int case_cont){
	fprintf(fpasm, "\tjmp fin_switch_%d\nswitch_%d_case_%d:\n", etiqueta, etiqueta, case_cont);
}

void yyerror(const char * s) {
	printf("****Error sintactico en [lin %d, col %d]\n", linea, columna);
}
