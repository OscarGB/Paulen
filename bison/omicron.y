%{
#include "generacion.h"
#include "omicron.h"
#include "tabla_simbolos_clases.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


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
char nombre_funcion[100];
int  num_parametros_llamada_actual = 0;
int fn_return = 0;
int en_explist = 0;

void escribe_cabecera (FILE * salida);
void escribe_variables (FILE * salida, char* nombre, int tamanio);
void gc_suma_enteros(FILE *salida, int es_direccion_op1, int es_direccion_op2);
void gc_resta_enteros(FILE *salida, int es_direccion_op1, int es_direccion_op2);
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
void gc_ident_asiglocal(FILE *salida, int es_direccion, int categoria, int nPar, int pos);
void gc_asigexp_ident(FILE *salida, int es_direccion_op1, char *lexema);
void ifthenelse_inicio(FILE * salida, int exp_es_variable, int etiqueta);
void ifthen_inicio(FILE * salida, int exp_es_variable, int etiqueta);
void ifthen_fin(FILE* salida, int etiqueta);
void ifthenelse_fin_then(FILE* salida, int etiqueta);
void ifthenelse_fin( FILE * salida, int etiqueta);
void ifthenelse_fin( FILE * salida, int etiqueta);
void asignarDestinoPila(FILE* salida, int es_variable, char * eax, char * ebx);
void gc_scanf_funcion(FILE *salida, int num_param_actual, int posicion_parametro, int categoria, int tipo);
void gc_lectura(FILE * salida, char * nombre, int tipo);
void gc_inicio_cuerpo_funcion (FILE *salida, char * lexema, int num_variable_locales);
void gc_final_cuerpo_funcion (FILE *salida, int esdireccion);
void gc_identificador_asignacion_local(FILE *salida, int es_direccion, int categoria, int numero_param, int posicion);
void gc_asignar_exp_a_elementovector(FILE *salida, int es_direccion_op1, char *lexema);
void gc_llamarfuncion (FILE *salida, char * lexema, int num_parametros);
void gc_escribirParametro(FILE *salida, int posicion_parametro, int num_parametros_actual);
void gc_escribirVariableLocal(FILE *salida,int posicion_variable_local);
void gc_indexacion_vectores(FILE *salida, int es_direccion_op1, char *lexema, int tam_vector);
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
%right MENOSU '!'

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
			simbolos_main = ht_get_values(simbolos->main_principal);
			for(int i=0;simbolos_main[i]!=NULL;i++){
				nombre_actual_simbolo = simbolos_main[i]->nombre;
				escribe_variables(salida, nombre_actual_simbolo, 1);
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


				iniciaLocal(simbolos, $4.lexema);
				/*Habra que insertar en la tabla local de igual forma que con nuevoSimboloMain*/


				if(simbolos->main_local == NULL){
					fprintf(sintactico, "Error al inicializar la tabla\n");
					return -1;
				}

				num_variables_locales_actual = 0;
				pos_variable_local_actual = 1;
				num_parametros_actual = 0;
				pos_parametro_actual = 0;
				fn_return = 0;
				strcpy ($$.lexema, $4.lexema);
				strcpy (nombre_funcion, $4.lexema);
				fprintf(stdout, "%s", nombre_funcion);
				fflush(stdout);
			}
			else{
				printf("****Error semantico en lin %d: Declaracion duplicada.\n", linea);
				return -1;
			}
		}
		;

fn_complete_name: fn_name '(' parametros_funcion ')'
		{
			fprintf(sintactico, "'(' parametros_funcion ')' ");
			nuevoSimboloEnMain(simbolos, nombre_funcion, 0,FUNCION,0,0,num_parametros_actual,0,0,0,0,0,0,0,0,0,0,0,0,EXPOSED,0,0,0,0,0,0,0,tipos_parametros);
			if(buscarIdNoCualificado(simbolos, nombre_funcion, "main", &s, id_ambito)){
				s->numero_parametros = num_parametros_actual;
				s->numero_variables_locales = num_variables_locales_actual;
			}
			strcpy($$.lexema, $1.lexema);
		}
		;

fn_declaration: fn_complete_name '{' declaraciones_funcion
		{
			fprintf(sintactico, "'{' declaraciones_funcion ");
			gc_inicio_cuerpo_funcion (salida, $1.lexema, num_variables_locales_actual);
		}
		;


funcion: fn_declaration sentencias '}'
		{
			fprintf(sintactico, "sentencias '}'\n");
			cerrarLocal(simbolos);
			simbolos->main_local=NULL;
			if (fn_return == 0){
				printf("****Error semántico en lin %d: Funcion <%s> sin sentencia de retorno.\n", linea, $1.lexema);
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
		;

asignacion: TOK_IDENTIFICADOR '=' exp
		{
			if (simbolos->main_local != NULL){
				if(buscarIdNoCualificado(simbolos, $1.lexema, "local", &s, id_ambito)==ERROR){
					if(buscarIdNoCualificado(simbolos, $1.lexema, "main", &s, id_ambito)==ERROR){
						printf("****Error semántico en lin %d: Acceso a variable no declarada (%s)\n", linea, $1.lexema);
						return -1;
					}
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
			gc_asignar_exp_a_elementovector(salida, $3.es_direccion, $1.lexema);
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

			if($3.tipo != INT){
				printf("****Error semántico en lin %d: El indice en una operacion de indexacion tiene que ser de tipo entero.\n", linea);
				return -1;
			}
			if (s->clase != VECTOR){
				printf("****Error semántico en lin %d: Intento de indexacion de una variable que no es de tipo vector.\n", linea);
				return -1;
			}

			$$.es_direccion = 1;
			$$.tipo = s->tipo;
			gc_indexacion_vectores(salida, $3.es_direccion, s->id, s->tamanio);
		}
		;

condicional: if_exp '(' exp ')' '{' sentencias '}'
		{
			fprintf(salida, "fin_ifelse%d:\n", $1.etiqueta);
			fprintf(sintactico,";R: condicional: if_exp '(' exp ')' '{' sentencias '}'\n");
		}
		|
		if_exp_sentencias TOK_ELSE '{' sentencias '}'
		{
			fprintf(salida, "fin_ifelse%d:\n", $1.etiqueta);
			fprintf(sintactico,";R: condicional: if_exp_sentencias TOK_ELSE '{' sentencias '}'\n");
		}
		;

if_exp_sentencias: if_exp sentencias '}'
		{
			$$.etiqueta = $1.etiqueta;
			fprintf(salida, "jmp near fin_ifelse%d\n", $1.etiqueta);
			fprintf(salida, "fin_then%d:\n", $1.etiqueta);
			fprintf(sintactico,";R: if_exp_sentencias: if_exp sentencias '}'\n");
		}
		;

if_exp: TOK_IF '(' exp ')' '{'
		{
			if ($3.tipo != BOOLEAN){
				printf("****Error semántico en lin %d: Comparacion con operandos boolean.\n", linea);
				return -1;
			}

			$$.etiqueta = etiqueta++;
			fprintf(salida, "pop eax\n");

			if($3.es_direccion == 1){
				fprintf(salida, "mov eax, [eax]\n");
			}
			fprintf(salida, "cmp eax, 0\n");
			fprintf(salida, "je near fin_then%d\n", $$.etiqueta);
			fprintf(sintactico,";R: if_exp: TOK_IF '(' exp ')' '{'\n");
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
	 			printf("****Error semántico en lin %d: Comparacion con operandos boolean.\n", linea);
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
				if(s->clase != ESCALAR){
					printf("****Error semántico en lin %d: Variable local de tipo no escalar.\n", linea);
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
				if(s->clase != ESCALAR){
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
			/*Buscamos identificador en la tabla de simbolos*/
			if(buscarIdNoCualificado(simbolos, $1.lexema, "main", &s, id_ambito)==ERROR){
				printf("****Error semántico en lin %d: Acceso a variable no declarada (%s).\n", linea, $1.lexema);
				return -1;
			}
			/*Comprobamos que es de categoria funcion*/
			if (s->tipo != FUNCION){
				printf("****Error semántico en lin %d: Identificador no es de categoriaegoria funcion\n", linea);
				return -1;
			}
			/*Comprobamos que en_explist no valga 1*/
			if (en_explist == 1){
				printf("****Error semántico en lin %d: No esta permitido el uso de llamadas a funciones como parametros de otras funciones.\n", linea);
				return -1;
			}
			num_parametros_llamada_actual = 0;
			en_explist = 1;
			strcpy($$.lexema, $1.lexema);
		};

retorno_funcion: TOK_RETURN exp
		{
			fprintf(sintactico,";R: retorno_funcion: TOK_RETURN exp\n");
			if (buscarIdNoCualificado(simbolos, nombre_funcion, "local", &s, id_ambito)==0){
				printf("****Error semántico en lin %d: Acceso a variable no declarada (%s).\n", linea, nombre_funcion);
				return -1;
			}
			if ($2.tipo != s->tipo){
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
					fprintf (salida, "push dword _%s\n", s->id);
				}else{
					fprintf (salida, "push dword [_%s]\n", s->id);
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
			if (simbolos->main_local == NULL){
				if(buscarIdNoCualificado(simbolos, $1.lexema, "main", &s, id_ambito)==ERROR){
					printf("****Error semántico en lin %d: Acceso a variable no declarada (%s).\n", linea, $1.lexema);
					return -1;
				}
			} else{
				if(buscarIdNoCualificado(simbolos, $1.lexema, "local", &s, id_ambito)==ERROR){
					printf("****Error semántico en lin %d: Acceso a variable no declarada (%s).\n", linea, $1.lexema);
					return -1;
				}
			}
			/*Comprobamos que el numero de parametros es correcto*/
			if (s->numero_parametros != num_parametros_llamada_actual){
				printf("****Error semántico en lin %d: Numero incorrecto de parametros en llamada a funcion.\n", linea);
				return -1;
			}
			en_explist = 0;
			$$.tipo = s->tipo;
			$$.es_direccion = 0;
			gc_llamarfuncion(salida, s->id, num_parametros_actual);
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
			num_parametros_llamada_actual++;
		}
		|
		/*vacio*/
		{
			fprintf(sintactico,";R: lista_expresiones: \n");
		}
		;

resto_lista_expresiones: ',' exp resto_lista_expresiones
		{
			fprintf(sintactico,";R: resto_lista_expresiones: exp resto_lista_expresiones\n");
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
			/* análisis semántico */
			$$.tipo = BOOLEAN;
			$$.es_direccion = 0;
			/* generación de código */
			/*fprintf(salida, "; numero_linea %d\n", numero_linea);*/
			fprintf(salida, "\tpush dword 1\n");
			fprintf(sintactico,";R: constante_logica: TOK_TRUE\n");
		}
		|
		TOK_FALSE
		{
			/* análisis semántico */
			$$.tipo = BOOLEAN;
			$$.es_direccion = 0;
			/* generación de código */
			/*fprintf(salida, "; numero_linea %d\n", numero_linea);*/
			fprintf(salida, "\tpush dword 0\n");
			fprintf(sintactico,";R: constante_logica: TOK_FALSE\n");
		}
		;

constante_entera: TOK_CONSTANTE_ENTERA
		{
			/* análisis semántico */
			$$.tipo = INT;
			$$.es_direccion = 0;
			/* generación de código */
			/*fprintf(salida, "; numero_linea %d\n", numero_linea);*/
			fprintf(salida, "\tpush dword %d\n", $1.valor_entero);
			fprintf(sintactico,";R: constante_entera: TOK_CONSTANTE_ENTERA\n");
		}
		;


idpf : TOK_IDENTIFICADOR
		{
			if(simbolos->main_local == NULL){
				printf("****Error semántico en lin %d: El ambito local no esta abierto.\n", linea);
				return -1;
			}
			if(buscarIdNoCualificado(simbolos, $1.lexema, "main", &s, id_ambito)==ERROR){
				printf("****Error semántico en lin %d:  Acceso a variable no declarada (%s).\n", linea, $1.lexema);
				return -1;
			}else{
			    clase_actual = ESCALAR;
			    nuevoSimboloEnMain(simbolos, s->id, clase_actual, tipo_actual,0,0,0,0,0,pos_parametro_actual,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,NULL);
					tipos_parametros[pos_parametro_actual] = tipo_actual;
			    pos_parametro_actual++;
			    num_parametros_actual++;
			}
		};

identificador: TOK_IDENTIFICADOR
		{/*REPASAR PORQUE SOLO PUEDEN SER VARIABLES PERO COMO ELLOS LO HAN IMPLEMENTADO NO PODEMOS METER CATEGORIA VARIABLE*/
			if(simbolos->main_local != NULL){
				if(buscarIdNoCualificado(simbolos, $1.lexema, "local", &s, id_ambito)==ERROR){
					if(tipo_actual == ESCALAR){
						nuevoSimboloEnMain(simbolos, s->id, clase_actual,tipo_actual,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,EXPOSED,0,0,0,0,0,0,0,NULL);
						pos_variable_local_actual++;
						num_variables_locales_actual++;
					}else{
						printf("****Error semántico en lin %d: Variable local de tipo no escalar.\n", linea);
						return -1;
					}
				}
			} else {
				nombre_actual_simbolo = $1.lexema;
				nombre_actual_simbolo = addPrefijo("main", nombre_actual_simbolo);
				if(buscarParaDeclararIdTablaSimbolosAmbitos(simbolos, nombre_actual_simbolo, &s, id_ambito)){
					fprintf(salida, "Error al declarar el elemento, ya esta declarado\n");
				}
				else{
					$1.tipo = tipo_actual;
					nuevoSimboloEnMain(simbolos, nombre_actual_simbolo, clase_actual,tipo_actual,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,EXPOSED,0,0,0,0,0,0,0,NULL);
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

void escribe_variables (FILE * salida, char* nombre, int tamanio){
	declarar_variable(salida, nombre, tamanio);
}

void imprimir_error(FILE * salida){
	fprintf(salida, "jmp near fin\n\n");
	fprintf(salida, "error_1: push dword mensaje_1\n");
	fprintf(salida, "	  call print_string\n");
	fprintf(salida, "	  add esp, 4\n");
	fprintf(salida, "	  jmp near fin\n\n");
	fprintf(salida, "error_2: push dword mensaje_2\n");
	fprintf(salida, "         call print_string\n");
	fprintf(salida, "         add esp, 4\n");
	fprintf(salida, "         jmp near fin\n\n");
	fprintf(salida, "fin:\n");
	fprintf(salida, "mov dword esp, [__esp]\n");
	fprintf(salida, "ret\n");
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
	fprintf(salida, "; Cargamos en el registro eax el valor del indice\n");
	fprintf(salida, "pop dword eax \n");
	if (es_direccion_op1 == 1){
		fprintf(salida, "mov dword eax , [eax]\n");
	}
	fprintf(salida, "; Si el indice es menor que 0 se produce un error\n");
	fprintf(salida, "cmp eax,0\n");
	fprintf(salida, "jl near error_1\n");
	fprintf(salida, "; Si el indice es mayor de lo estipulado se comete un error\n");
	fprintf(salida, "cmp eax, %d\n", tam_vector-1);
	fprintf(salida, "jg near error_1\n");
	fprintf(salida, "mov dword edx, _%s\n", lexema);
	fprintf(salida, "lea eax, [edx + eax * 4]\n");
	fprintf(salida, "push dword eax\n");
	return;
}

void gc_ident_asiglocal(FILE *salida, int es_direccion, int categoria, int nPar, int pos){
	fprintf(salida,"pop dword eax\n");
	if (es_direccion == 1)
		fprintf(salida,"mov dword eax, [eax]\n");
	if (categoria == PARAMETRO){
		fprintf(salida,"mov dword [ebp+4+4*%d], eax\n", nPar-pos);
	}else{
		fprintf(salida,"mov dword [ebp-4*%d], eax\n", pos);
	}
	return;
}

void gc_asigexp_ident(FILE *salida, int es_direccion_op1, char *lexema){
	fprintf(salida, "; Cargamos en el registro eax la parte derecha de la asignacion\n");
	fprintf(salida, "pop dword eax\n");
	if (es_direccion_op1==1){
		fprintf(salida,"mov dword eax, [eax]\n");
	}
	fprintf(salida, "; Efectuamos la asignacion\n");
	fprintf(salida,"mov dword [_%s], eax\n", lexema);
	return;
}


void gc_printf(FILE *salida, int es_direccion_op1, int tipo){
	escribir(salida, es_direccion_op1, tipo);
	return;
}

void ifthenelse_inicio(FILE * salida, int exp_es_variable, int etiqueta){
	fprintf(salida,"; Comprobamos la condicion: if (%d) para ver que es algo asimilable a una variable", etiqueta);
    fprintf(salida, "pop eax\n");
    if (exp_es_variable)
        fprintf(salida, "mov eax, [eax]\n");

    fprintf(salida, "cmp eax, 0\n");
    fprintf(salida, "; En caso de que no se cumpla la condicion nos vamos al else\n");
    fprintf(salida,"je __else_%d\n", etiqueta);
	fprintf(salida, ";Nos metemos en el caso del then (%i) ya que se cumple la condicion", etiqueta);
}


void ifthen_inicio(FILE * salida, int exp_es_variable, int etiqueta){
	fprintf(salida,"; Comprobamos la condicion: if (%d) para ver que es algo asimilable a una variable", etiqueta);
    fprintf(salida, "pop eax\n");
    if (exp_es_variable)
        fprintf(salida, "mov eax, [eax]\n");

    fprintf(salida, "cmp eax, 0\n");
    fprintf(salida, "; En caso de que no se cumpla la condicion nos vamos al final del ifthen\n");
    fprintf(salida, "je __endifthen_%d\n", etiqueta);
	fprintf(salida, "; En caso de que se cumpla nos metemos en el caso del then (%i) ya que se cumple la condicion", etiqueta);
}


void ifthen_fin(FILE* salida, int etiqueta){
    fprintf(salida, "; Estamos en la parte del final del then (%d) del ifthen", etiqueta);
    fprintf(salida, "__endifthen_%d:", etiqueta);
}


void ifthenelse_fin_then(FILE* salida, int etiqueta){
    fprintf(salida, "; Estamos en la parte del final del then (%d) del ifthen_else", etiqueta);
    fprintf(salida, "jmp __endifthen_else_%d", etiqueta);
}

void ifthenelse_fin( FILE * salida, int etiqueta){
	fprintf(salida, "; Estamos en la parte del final del else (%d) del ifthen_else", etiqueta);
	fprintf(salida, "__endifthen_else_%d:\n", etiqueta);
}


void asignarDestinoPila(FILE* salida, int es_variable, char * eax, char * ebx){
	/*Hay algo mas que hacer pero no se el que*/
	/*fprintf(salida, "\n\t; Asignacion de a pila a %s\n", nombre);*/
	fprintf(salida, "\tpop dword eax\n");
	if(es_variable){
		fprintf(salida, "\tmov eax,dword [eax]\n");
	}
	else{
		/*printf(salida, "\tmov dword [_%s], eax\n", nombre);*/
	}
	/*fprintf(salida, "; Apilando %s de variable local %d", (es_variable) ? "direccion": "valor", posicion_variable);*/
}

void gc_scanf_funcion(FILE *salida, int num_param_actual, int posicion_parametro, int categoria, int tipo){
	if (categoria == PARAMETRO){
		fprintf(salida,"lea eax, [ebp+4+4*(%d)]\n",num_param_actual - posicion_parametro);
		fprintf(salida,"push dword eax\n");
	}else {
		fprintf(salida,"lea eax, [ebp-4*%d]\n",posicion_parametro);
		fprintf(salida,"push dword eax\n");
	}

	if(tipo==INT){
		fprintf(salida,"call scan_int\n");
	}else{
		fprintf(salida,"call scan_boolean\n");
	}
	fprintf(salida,"add esp,4\n");
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
	fprintf(salida,"pop dword eax\n");
	if (es_direccion == 1)
		fprintf(salida,"mov dword eax, [eax]\n");
	if (categoria == PARAMETRO){
		fprintf(salida,"mov dword [ebp+4+4*%d], eax\n", numero_param-posicion);
	}else{
		fprintf(salida,"mov dword [ebp-4*%d], eax\n", posicion);
	}
	return;
}

void gc_asignar_exp_a_elementovector(FILE *salida, int es_direccion_op1, char *lexema){
	fprintf(salida, "; Cargar en eax la parte derecha de la asignacion\n");
	fprintf(salida,"pop dword eax\n");
	if (es_direccion_op1==1){
		fprintf(salida,"mov dword eax, [eax]\n");
	}
	fprintf(salida, "; Cargar en edx la parte izquierda de la asignacion\n");
	fprintf(salida,"pop dword edx\n");
	fprintf(salida, "; Hacer la asignacion efectiva\n");
	fprintf(salida,"mov dword [edx], eax\n");
	return;
}

void gc_llamarfuncion (FILE *salida, char * lexema, int num_parametros){
	llamarFuncion(salida, lexema, num_parametros);
}


void gc_indexacion_vectores(FILE *salida, int es_direccion_op1, char *lexema, int tam_vector){
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

void yyerror(const char * s) {
	printf("****Error sintactico en [lin %d, col %d]\n", linea, columna);
}
