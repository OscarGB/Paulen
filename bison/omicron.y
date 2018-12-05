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


simbolos_p simbolos = NULL;
simbolo_p s =NULL;
simbolo_p * simbolos_main=NULL;
char id_ambito[100];
int etiqueta = 0;
int contador_variables=0;
char * etiqueta_nombre_actual=NULL;
int tipo_actual = 0;
int clase_actual = 0;
int valor_actual = 0;
int num_parametros_actual=0;
int num_variables_locales_actual=0;
int pos_parametro_actual = 0;
char* nombre_actual_simbolo=NULL;

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
void ifthenelse_inicio(FILE * fpasm, int exp_es_variable, int etiqueta);
void ifthen_inicio(FILE * fpasm, int exp_es_variable, int etiqueta);
void ifthen_fin(FILE* fpasm, int etiqueta);
void ifthenelse_fin_then(FILE* fpasm, int etiqueta);
void ifthenelse_fin( FILE * fpasm, int etiqueta);
void ifthenelse_fin( FILE * fpasm, int etiqueta);
void asignarDestinoEnPila(FILE* fpasm, int es_variable, char * eax, char * ebx);
void gc_scanf_funcion(FILE *salida, int num_param_actual, int posicion_parametro, int categoria, int tipo);
void gc_lectura(FILE * salida, char * nombre, int tipo);
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
%type <atributos> lectura
%type <atributos> escritura
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
		}
		;

escritura_TS : {
			escribir_subseccion_data(salida);
			escribir_cabecera_bss(salida);
			simbolos_main = ht_get_values(simbolos->main_principal);
			for(int i=0;simbolos_main[i]!=NULL;i++){
				nombre_actual_simbolo = simbolos_main[i]->nombre;
				escribe_variables(salida, nombre_actual_simbolo, 1);
			}
			escribe_cabecera(salida);
		}
		;

escritura_main : {
			escribir_inicio_main(salida);
		}
		;

final_programa : {
			imprimir_error(salida);
		}
		;

inicioTabla : {
			simbolos = createSimbolos("Programa");
				if (simbolos->main_principal == NULL){
					fprintf(salida, "Error al inicializar la tabla\n");
					return -1;
				}
		}
		;


declaraciones: declaracion
		{
		}
		|
		declaracion declaraciones
		{
		}
		;

declaracion: modificador_acceso clase identificadores ';'
		{
		}
		|
		modificador_acceso declaracion_clase ';'
		{
		}
		;

modificador_acceso: /*vacio*/
		{
		}
		|
		TOK_HIDDEN TOK_UNIQUE
		{
		}
		|
		TOK_SECRET TOK_UNIQUE
		{
		}
		|
		TOK_EXPOSED TOK_UNIQUE
		{
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
			clase_actual=1;
		}
		|
		clase_vector
		{
			clase_actual=3;
		}
		|
		clase_objeto
		{
			clase_actual=5;
		}
		;


declaracion_clase: modificadores_clase TOK_CLASS TOK_IDENTIFICADOR TOK_INHERITS identificadores '{' declaraciones funciones '}'
		{
		}
		|
		modificadores_clase TOK_CLASS TOK_IDENTIFICADOR '{' declaraciones funciones '}'
		{
		}
		;

modificadores_clase: /*vacio*/
		{
		}
		;

clase_escalar: tipo
		{
		}
		;

tipo: TOK_INT
		{
			tipo_actual = INT;
		}
		|
		TOK_BOOLEAN
		{
			tipo_actual = BOOLEAN;
		}
		;

clase_objeto: '{' TOK_IDENTIFICADOR '}'
		{
		}
		;

clase_vector: TOK_ARRAY tipo '[' TOK_CONSTANTE_ENTERA ']'
		{
		}
		;

identificadores: identificador ',' identificadores
		{
			nombre_actual_simbolo = $1.lexema;
			if(buscarParaDeclararIdTablaSimbolosAmbitos(simbolos, $1.lexema, &s, id_ambito)){
				fprintf(salida, "Error al declarar el el elemento, ya esta declarado\n");
			}
			else{
				printf("hola: %d\n", tipo_actual);
				$1.tipo =tipo_actual;
				nuevoSimboloEnMain(simbolos, $1.lexema, clase_actual,tipo_actual,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,EXPOSED,0,0,0,0,0,0,0,NULL);
			}
		}
		|
 		identificador
		{
			nombre_actual_simbolo = $1.lexema;
			if(buscarParaDeclararIdTablaSimbolosAmbitos(simbolos, $1.lexema, &s, id_ambito)){
				fprintf(salida, "Error al declarar el el elemento, ya esta declarado\n");
			}
			else{
				printf("hola: %d\n", tipo_actual);
				$1.tipo =tipo_actual;
				nuevoSimboloEnMain(simbolos, $1.lexema, clase_actual,tipo_actual,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,EXPOSED,0,0,0,0,0,0,0,NULL);
			}
		}
		;

funciones: funcion funciones
		{
		}
		|
		/*vacio*/
		{
		}
		;

funcion: TOK_FUNCTION modificador_acceso tipo_retorno TOK_IDENTIFICADOR '(' parametros_funcion ')' '{' declaraciones_funcion sentencias '}'
		{
		}
		;

tipo_retorno: TOK_NONE
		{
		}
		|
		tipo
		{
		}
		;

parametros_funcion: parametro_funcion resto_parametros_funcion
		{
		}
		|
		/*vacio*/
		{
		}
		;

resto_parametros_funcion: ';' parametro_funcion resto_parametros_funcion
		{
		}
		|
		/*vacio*/
		{
		}
		;

parametro_funcion: tipo TOK_IDENTIFICADOR
		{
		}
		;

declaraciones_funcion: declaraciones
		{
		}
		|
		/*vacio*/
		{
		}
		;

sentencias: sentencia
		{
		}
		|
		sentencia sentencias
		{
		}
		;

sentencia: sentencia_simple ';'
		{
		}
		|
		bloque
		{
		}
		;

sentencia_simple: asignacion
		{
		}
		|
		lectura
		{
		}
		|
		escritura
		{
		}
		|
		retorno_funcion
		{
		}
		|
		identificador_clase '.' TOK_IDENTIFICADOR '(' lista_expresiones ')'
		{
		}
		|
		TOK_IDENTIFICADOR '(' lista_expresiones ')'
		{
		}
		|
		destruir_objeto
		{
		}
		;

destruir_objeto: TOK_DISCARD TOK_IDENTIFICADOR
		{
		}
		;

bloque: condicional
		{
		}
		|
		bucle
		{
		}
		;

asignacion: TOK_IDENTIFICADOR '=' exp
		{
			if(buscarIdNoCualificado(simbolos, $1.lexema, "main", &s, id_ambito)){
				gc_asigexp_ident(salida, $3.direcciones, $1.lexema);
			}
			else{
				printf("****Error semántico en lin %d: Acceso a variable no declarada (%s)\n", linea, $1.lexema);
			}
		}
		|
		elemento_vector '=' exp
		{
		}
		|
		elemento_vector '=' TOK_INSTANCE_OF TOK_IDENTIFICADOR '(' lista_expresiones ')'
		{
		}
		|
		TOK_IDENTIFICADOR '=' TOK_INSTANCE_OF TOK_IDENTIFICADOR '(' lista_expresiones ')'
		{
		}
		|
		identificador_clase '.' TOK_IDENTIFICADOR '=' exp
		{
		}
		;

elemento_vector: TOK_IDENTIFICADOR '[' exp ']'
		{
		}
		;

condicional: if_exp '(' exp ')' '{' sentencias '}'
		{
			fprintf(salida, "fin_ifelse%d:\n", $1.etiqueta);

		}
		|
		if_exp_sentencias TOK_ELSE '{' sentencias '}'
		{
		}
		;
if_exp_sentencias:if_exp sentencias '}'{
			$$.etiqueta = $1.etiqueta;
			fprintf(salida, "jmp near fin_ifelse%d\n", $1.etiqueta);
			fprintf(salida, "fin_then%d:\n", $1.etiqueta);
		}

if_exp: TOK_IF '(' exp ')' '{'{
			if ($3.tipo != BOOLEAN){
				printf("****Error semántico en lin %d: Comparacion con operandos boolean.\n", linea);
				return -1;
			}

			$$.etiqueta = etiqueta++;
			fprintf(salida, "pop eax\n");
			if($3.direcciones == 1){
				fprintf(salida, "mov eax, [eax]\n");
			}
			fprintf(salida, "cmp eax, 0\n");
			fprintf(salida, "je near fin_then%d\n", $$.etiqueta);
		}


bucle: TOK_WHILE '(' exp ')' '{' sentencias '}'
		{
		}
		;

lectura: TOK_SCANF TOK_IDENTIFICADOR
		{
			if(simbolos->main_local != NULL){
				buscarIdNoCualificado(simbolos, $2.lexema, "main", &s, id_ambito);
				if(s==NULL){
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
				buscarIdNoCualificado(simbolos, $2.lexema, "main", &s, id_ambito);
				if(s==NULL){
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
				printf("tipo: %d", s->tipo);
				gc_lectura(salida, $2.lexema, s->tipo);
			}
		}
		|
		TOK_SCANF elemento_vector
		{
		}

		;

escritura: TOK_PRINTF exp
		{
			gc_printf(salida, $2.direcciones, $2.tipo);
		}
		;

retorno_funcion: TOK_RETURN exp
		{
		}
		|
		TOK_RETURN TOK_NONE
		{
		}
		;

exp: exp '+' exp
		{
			printf("%s, %d", $1.lexema, $1.tipo);
			printf("%s, %d", $3.lexema, $3.tipo);
			if ($1.tipo != INT || $3.tipo != INT){
				printf("****Error semántico en lin %d: Operacion aritmetica con operandos boolean.\n", linea);
				return -1;
			}
			gc_suma_enteros(salida, $1.direcciones, $3.direcciones);
			$$.direcciones = 0;
			$$.tipo = INT;
		}
		|
		exp '-' exp
		{
			if ($1.tipo != INT || $3.tipo != INT){
				printf("****Error semántico en lin %d: Operacion aritmetica con operandos boolean.\n", linea);
				return -1;
			}
			gc_resta_enteros(salida, $1.direcciones, $3.direcciones);
			$$.direcciones = 0;
			$$.tipo = INT;
		}
		|
		exp '/' exp
		{
			if ($1.tipo != INT || $3.tipo != INT){
				printf("****Error semántico en lin %d: Operacion aritmetica con operandos boolean.\n", linea);
				return -1;
			}
			gc_division_enteros(salida, $1.direcciones, $3.direcciones);
			$$.direcciones = 0;
			$$.tipo = INT;
		}
		|
		exp '*' exp
		{
			if ($1.tipo != INT || $3.tipo != INT){
				printf("****Error semántico en lin %d: Operacion aritmetica con operandos boolean.\n", linea);
				return -1;
			}
			gc_producto_enteros(salida, $1.direcciones, $3.direcciones);
			$$.direcciones = 0;
			$$.tipo = INT;
		}
		|
		'-' exp %prec MENOSU
		{
			if ($2.tipo!=INT){
				printf("****Error semántico en lin %d: Operacion aritmetica con operandos boolean.\n", linea);
				return -1;
			}
			gc_negacion_entero(salida, $2.direcciones);
			$$.direcciones = 0;
			$$.tipo = INT;
		}
		|
		exp TOK_AND exp
		{
			if ($1.tipo != BOOLEAN || $3.tipo != BOOLEAN) {
				printf("****Error semántico en lin %d: Operacion logica con operandos int.\n", linea);
				return -1;
			}
			gc_and_logico(salida, $1.direcciones, $3.direcciones);
			$$.direcciones = 0;
			$$.tipo = BOOLEAN;
		}
		|
		exp TOK_OR exp
		{
			if ($1.tipo!=BOOLEAN || $3.tipo!=BOOLEAN) {
				printf("****Error semántico en lin %d: Operacion logica con operandos int.\n", linea);
				return -1;
			}
			gc_or_logico(salida, $1.direcciones, $3.direcciones);
			$$.direcciones = 0;
			$$.tipo = BOOLEAN;
		}
		|
		'!' exp
		{
			if ($2.tipo!=BOOLEAN) {
				printf("****Error semántico en lin %d: Operacion logica con operandos int.\n", linea);
				return -1;
			}
			gc_not_logico(salida, $2.direcciones, etiqueta);
			$$.direcciones = 0;
			$$.tipo = BOOLEAN;
			etiqueta++;
		}
		|
		TOK_IDENTIFICADOR
		{
			if($1.direcciones == 1){
				fprintf(salida,"push dword [_%s]\n", $1.lexema);
			}
			else{
				fprintf(salida,"push dword _%s\n", $1.lexema);
			}
			$$.tipo = $1.tipo;
			$$.direcciones = $1.direcciones;
		}
		|
		constante
		{
			$$.tipo = $1.tipo;
			$$.direcciones = $1.direcciones;
		}
		|
		'(' exp ')'
		{
			$$.tipo = $2.tipo;
			$$.direcciones = $2.direcciones;
		}
		|
		'(' comparacion ')'
		{
			$$.tipo = $2.tipo;
			$$.direcciones = $2.direcciones;
		}
		|
		elemento_vector
		{
			$$.tipo = $1.tipo;
			$$.direcciones = $1.direcciones;
		}
		|
		TOK_IDENTIFICADOR '(' lista_expresiones ')'
		{
		}
		|
		identificador_clase '.' TOK_IDENTIFICADOR '(' lista_expresiones ')'
		{
		}
		|
		identificador_clase '.' TOK_IDENTIFICADOR
		{
		}
		;


identificador_clase: TOK_IDENTIFICADOR
		{
		}
		|
		TOK_ITSELF
		{
		}
		;

lista_expresiones: exp resto_lista_expresiones
		{
		}
		|
		/*vacio*/
		{
		}
		;

resto_lista_expresiones: ',' exp resto_lista_expresiones
		{
		}
		|
		/*vacio*/
		{
		}
		;

comparacion: exp TOK_IGUAL exp
		{
			if ($1.tipo!=INT || $3.tipo!=INT){
				printf("****Error semántico en lin %d: Comparacion con operandos boolean.\n", linea);
				return -1;
			}
			gc_igual(salida, $1.direcciones, $3.direcciones, etiqueta);
			$$.etiqueta = etiqueta++;
			$$.direcciones = 0;
			$$.tipo = BOOLEAN;
		}
		|
		exp TOK_DISTINTO exp
		{
			if ($1.tipo!=INT || $3.tipo!=INT){
				printf("****Error semántico en lin %d: Comparacion con operandos boolean.\n", linea);
				return -1;
			}
			gc_distinto(salida, $1.direcciones, $3.direcciones, etiqueta);
			$$.etiqueta = etiqueta++;
			$$.direcciones = 0;
			$$.tipo = BOOLEAN;
		}
		|
		exp TOK_MAYORIGUAL exp
		{
			if ($1.tipo!=INT || $3.tipo!=INT){
				printf("****Error semántico en lin %d: Comparacion con operandos boolean.\n", linea);
				return -1;
			}
			gc_mayorigual(salida, $1.direcciones, $3.direcciones, etiqueta);
			$$.etiqueta = etiqueta++;
			$$.direcciones = 0;
			$$.tipo = BOOLEAN;
		}
		|
		exp TOK_MENORIGUAL exp
		{
			if ($1.tipo!=INT || $3.tipo!=INT){
				printf("****Error semántico en lin %d: Comparacion con operandos boolean.\n", linea);
				return -1;
			}
			gc_menorigual(salida, $1.direcciones, $3.direcciones, etiqueta);
			$$.etiqueta = etiqueta++;
			$$.direcciones = 0;
			$$.tipo = BOOLEAN;
		}
		|
		exp '>' exp
		{
			if ($1.tipo!=INT || $3.tipo!=INT){
				printf("****Error semántico en lin %d: Comparacion con operandos boolean.\n", linea);
				return -1;
			}
			gc_mayor(salida, $1.direcciones, $3.direcciones, etiqueta);
			$$.etiqueta = etiqueta++;
			$$.direcciones = 0;
			$$.tipo = BOOLEAN;
		}
		|
		exp '<' exp
		{
			if ($1.tipo!=INT || $3.tipo!=INT){
				printf("****Error semántico en lin %d: Comparacion con operandos boolean.\n", linea);
				return -1;
			}
			gc_menor(salida, $1.direcciones, $3.direcciones, etiqueta);
			$$.etiqueta = etiqueta++;
			$$.direcciones = 0;
			$$.tipo = BOOLEAN;
		}
		;

constante: constante_logica
		{
			$$.tipo = $1.tipo;
			$$.direcciones = $1.direcciones;
		}
		|
		constante_entera
		{
			$$.tipo = $1.tipo;
			$$.direcciones = $1.direcciones;
		}
		;

constante_logica: TOK_TRUE
		{
			/* análisis semántico */
			$$.tipo = BOOLEAN;
			$$.direcciones = 0;
			/* generación de código */
			/*fprintf(salida, "; numero_linea %d\n", numero_linea);*/
			fprintf(salida, "\tpush dword 1\n");
		}
		|
		TOK_FALSE
		{
			/* análisis semántico */
			$$.tipo = BOOLEAN;
			$$.direcciones = 0;
			/* generación de código */
			/*fprintf(salida, "; numero_linea %d\n", numero_linea);*/
			fprintf(salida, "\tpush dword 0\n");
		}
		;

constante_entera: TOK_CONSTANTE_ENTERA
		{
			/* análisis semántico */
			$$.tipo = INT;
			$$.direcciones = 0;
			/* generación de código */
			/*fprintf(salida, "; numero_linea %d\n", numero_linea);*/
			fprintf(salida, "\tpush dword %d\n", $1.valor_entero);
		}
		;

/*idpf : TOK_IDENTIFICADOR{
	simbol sim=NULL;
	if(simbol->main_local == NULL){
		printf("****Error semántico en lin %d: El ambito local no esta abierto.\n", linea);
		return -1;
	}*/
	/*Comprobamos que el identificador existe en el ambito actual*/
	/*if(!buscarIdCualificadoInstancia(simbol, $1.lexema, nombre_funcion_actual, "main", &sim, CLASE)){
		printf("****Error semántico en lin %d:  Acceso a variable no declarada (%s).\n", linea, $1.lexema);
		return -1;
	}else{
	    clase_actual = ESCALAR;*/
	    /*Realizamos la insercion*/
	    /*nuevoSimboloEnClase(simbol, $1.lexema, "main", clase_actual, tipo_actual,0,0,0,0,0,pos_parametro_actual,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,NULL)
	    pos_parametro_actual++;
	    num_parametros_actual++;
	}
};*/

identificador: TOK_IDENTIFICADOR
		{
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

void ifthenelse_inicio(FILE * fpasm, int exp_es_variable, int etiqueta){
	fprintf(salida,"; Comprobamos la condicion: if (%d) para ver que es algo asimilable a una variable", etiqueta);
    fprintf(salida, "pop eax\n");
    if (exp_es_variable)
        fprintf(salida, "mov eax, [eax]\n");

    fprintf(salida, "cmp eax, 0\n");
    fprintf(salida, "; En caso de que no se cumpla la condicion nos vamos al else\n");
    fprintf(salida,"je __else_%d\n", etiqueta);
	fprintf(salida, ";Nos metemos en el caso del then (%i) ya que se cumple la condicion", etiqueta);
}


void ifthen_inicio(FILE * fpasm, int exp_es_variable, int etiqueta){
	fprintf(salida,"; Comprobamos la condicion: if (%d) para ver que es algo asimilable a una variable", etiqueta);
    fprintf(salida, "pop eax\n");
    if (exp_es_variable)
        fprintf(salida, "mov eax, [eax]\n");

    fprintf(salida, "cmp eax, 0\n");
    fprintf(salida, "; En caso de que no se cumpla la condicion nos vamos al final del ifthen\n");
    fprintf(salida, "je __endifthen_%d\n", etiqueta);
	fprintf(salida, "; En caso de que se cumpla nos metemos en el caso del then (%i) ya que se cumple la condicion", etiqueta);
}


void ifthen_fin(FILE* fpasm, int etiqueta){
    fprintf(salida, "; Estamos en la parte del final del then (%d) del ifthen", etiqueta);
    fprintf(salida, "__endifthen_%d:", etiqueta);
}


void ifthenelse_fin_then(FILE* fpasm, int etiqueta){
    fprintf(salida, "; Estamos en la parte del final del then (%d) del ifthen_else", etiqueta);
    fprintf(salida, "jmp __endifthen_else_%d", etiqueta);
}

void ifthenelse_fin( FILE * fpasm, int etiqueta){
	fprintf(salida, "; Estamos en la parte del final del else (%d) del ifthen_else", etiqueta);
	fprintf(salida, "__endifthen_else_%d:\n", etiqueta);
}


void asignarDestinoEnPila(FILE* fpasm, int es_variable, char * eax, char * ebx){
	/*Hay algo mas que hacer pero no se el que*/
	/*fprintf(fpasm, "\n\t; Asignacion de a pila a %s\n", nombre);*/
	fprintf(fpasm, "\tpop dword eax\n");
	if(es_variable){
		fprintf(fpasm, "\tmov eax,dword [eax]\n");
	}
	else{
		/*printf(fpasm, "\tmov dword [_%s], eax\n", nombre);*/
	}
	/*fprintf(salida, "; Apilando %s de variable local %d", (es_variable) ? "direccion" : "valor", posicion_variable);*/
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

void yyerror(const char * s) {
	printf("****Error sintactico en [lin %d, col %d]\n", linea, columna);
}
