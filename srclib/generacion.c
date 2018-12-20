#include <stdio.h>
#include "generacion.h"
#include "tabla_simbolos_clases.h"

/* OBSERVACIÓN GENERAL A TODAS LAS FUNCIONES:
Todas ellas escriben el código NASM a un FILE* proporcionado como primer argumento.
*/


/*
Código para el principio de la sección .bss.
Con seguridad sabes que deberás reservar una variable entera para guardar el puntero de pila extfinido (esp). Se te sugiere el nombre __esp para esta variable.
*/

void escribir_cabecera_bss(FILE* fpasm){
  fprintf(fpasm, "\nsegment .bss\n");
  declarar_variable(fpasm, "_esp", 1);
}


/*
Declaración (con directiva db) de las variables que contienen el texto de los mensajes para la identificación de errores en tiempo de ejecución.
En este punto, al menos, debes ser capaz de detectar la división por 0.
*/

void escribir_subseccion_data(FILE* fpasm){
  fprintf(fpasm, "segment .data\n");
  fprintf(fpasm, "mensaje_1 db \"Indice fuera de rango\", 0\n");
  fprintf(fpasm, "mensaje_2 db \"Division por cero\", 0\n");
}


/*
Para ser invocada en la sección .bss cada vez que se quiera declarar una variable:
El argumento nombre es el de la variable.
tipo puede ser ENTERO o BOOLEANO (observa la declaración de las constantes del principio del fichero).
Esta misma función se invocará cuando en el compilador se declaren vectores, por eso se adjunta un argumento final (tamano) que para esta primera práctica siempre recibirá el valor 1.
*/

void declarar_variable(FILE* fpasm,  char* nombre, int tamano){
  fprintf(fpasm, "_%s resd %d\n", nombre, tamano);
}


/*
Para escribir el comienzo del segmento .text, básicamente se indica que se exporta la etiqueta main y que se usarán las funciones declaradas en la librería olib.o
*/

void escribir_segmento_codigo(FILE* fpasm){
  fprintf(fpasm, "\nsegment .text\n");
  fprintf(fpasm, "global main\n");
  fprintf(fpasm, "extern print_int, print_boolean, print_string, print_blank, print_endofline, scan_int, scan_boolean\n");
}


/*
En este punto se debe escribir, al menos, la etiqueta main y la sentencia que guarda el puntero de pila en su variable (se recomifina usar __esp).
*/

void escribir_inicio_main(FILE* fpasm){
  fprintf(fpasm, "\n; PROCEDIMIENTO PRINCIPAL\n");
  fprintf(fpasm, "main:\n");
  fprintf(fpasm, "mov dword [__esp], esp\n");
}



/*
Al final del programa se escribe:
El código NASM para salir de manera controlada cuando se detecta un error en tiempo de ejecución (cada error saltará a una etiqueta situada en esta zona en la que se imprimirá el correspondiente mensaje y se saltará a la zona de finalización del programa).
En el final del programa se debe:
·Restaurar el valor del puntero de pila (a partir de su variable __esp)
·Salir del programa (ret).
*/

void escribir_fin(FILE* fpasm){
  fprintf(fpasm, "\n\t\t;FINAL DEL PROGRAMA\n");
  fprintf(fpasm, "\t\tjmp near _fin\n");
  fprintf(fpasm, "\t\t__error_division:\n");
  fprintf(fpasm, "\t\tpush mensaje_1\n");
  fprintf(fpasm, "\t\tjmp near __salida_mensaje_error\n");
  fprintf(fpasm, "\t\t__salida_mensaje_error:\n");
  fprintf(fpasm, "\t\tcall print_string\n");
  fprintf(fpasm, "\t\tcall print_endofline\n");

  fprintf(fpasm, "\t\t_fin:\n");
  fprintf(fpasm, "\t\tmov dword esp, [__esp]\n");
  fprintf(fpasm, "\t\tret\n");
}


/*
Función que debe ser invocada cuando se sabe un operando de una operación aritmético-lógica y se necesita introducirlo en la pila.
nombre es la cadena de caracteres del operando tal y como debería aparecer en el fuente NASM
es_variable indica si este operando es una variable (como por ejemplo b1) con un 1 u otra cosa (como por ejemplo 34) con un 0. Recuerda que en el primer caso internamente se representará como _b1 y, sin embargo, en el segundo se representará tal y como esté en el argumento (34).
*/

void escribir_operando(FILE* fpasm, char* nombre, int es_variable){
  fprintf(fpasm, "\n\t\t; Guarda el operando %s en la pila\n", nombre);
  fprintf(fpasm, "\t\tpush dword %s%s\n", es_variable ? "_" : "", nombre);
}


/*
Genera el código para asignar valor a la variable de nombre nombre.
Se toma el valor de la cima de la pila.
El último argumento es el que indica si lo que hay en la cima de la pila es una referencia (1) o ya un valor explícito (0).
*/

void asignar(FILE* fpasm, char* nombre, int es_variable){
  fprintf(fpasm, "\n\t\t; Asignacion de a pila a %s\n", nombre);
  fprintf(fpasm, "\t\tpop dword eax\n");
  if(es_variable){
    fprintf(fpasm, "\t\tmov eax,dword [eax]\n");
  }
  else{
    fprintf(fpasm, "\t\tmov dword [_%s], eax\n", nombre);
  }
}


/* FUNCIONES ARITMÉTICO-LÓGICAS BINARIAS */
/*
En todas ellas se realiza la operación como se ha resumido anteriormente:
Se extrae de la pila los operandos
Se realiza la operación
Se guarda el resultado en la pila
Los dos últimos argumentos indican respectivamente si lo que hay en la pila es una referencia a un valor o un valor explícito.
Deben tenerse en cuenta las peculiaridades de cada operación. En este sentido sí hay que mencionar explícitamente que, en el caso de la división, se debe controlar si el divisor es “0” y en ese caso se debe saltar a la rutina de error controlado (restaurando el puntero de pila en ese caso y comprobando en el retorno que no se produce “Segmentation Fault”)
*/
void sumar(FILE* fpasm, int es_variable_1, int es_variable_2){
  fprintf(fpasm, "\n\t\t; Suma\n");
  fprintf(fpasm, "\t\tpop dword ebx\n");
  fprintf(fpasm, "\t\tpop dword eax\n");

  if(es_variable_1){
    fprintf(fpasm, "\t\tmov dword eax, [eax]\n");
  }
  if(es_variable_2){
    fprintf(fpasm, "\t\tmov dword ebx, [ebx]\n");
  }

  fprintf(fpasm,"\t\tadd eax, ebx\n");
  fprintf(fpasm, "\t\tpush dword eax\n");
}


void restar(FILE* fpasm, int es_variable_1, int es_variable_2){
  fprintf(fpasm, "\n\t\t; Resta\n");
  fprintf(fpasm, "\t\tpop dword ebx\n");
  fprintf(fpasm, "\t\tpop dword eax\n");
  if(es_variable_1){
    fprintf(fpasm, "\t\tmov dword eax, [eax]\n");
  }
  fprintf(fpasm, "\t\tsub eax, %s\n", es_variable_2 ? "[ebx]" : "ebx");
  fprintf(fpasm, "\t\tpush dword eax\n");
}


void multiplicar(FILE* fpasm, int es_variable_1, int es_variable_2){
  fprintf(fpasm, "\n\t\t; Multiplicacion\n");
  fprintf(fpasm, "\t\tpop dword ebx\n");
  fprintf(fpasm, "\t\tpop dword eax\n");
  if(es_variable_1){
    fprintf(fpasm, "\t\tmov eax, [eax]\n");
  }
  fprintf(fpasm, "\t\timul dword %s\n", es_variable_2 ? "[ebx]" : "ebx");
  fprintf(fpasm, "\t\tpush dword eax\n");
}


void dividir(FILE* fpasm, int es_variable_1, int es_variable_2){
  fprintf(fpasm, "\n\t\t; Division\n");
  fprintf(fpasm,"\t\tpop dword ebx\n");
  fprintf(fpasm,"\t\tpop dword eax\n");
  if(es_variable_1){
    fprintf(fpasm, "\t\tmov eax, dword [eax]\n");
  }
  if(es_variable_2){
    fprintf(fpasm, "\t\tmov ebx, dword [ebx]\n");
  }
  fprintf(fpasm, "\t\tcmp ebx, 0\n"); /*Comparamos con 0 para ver que no estamos dividiendo por 0*/
  fprintf(fpasm, "\t\tje __error_division\n");/*De ser igual saltamos a la rutina de error de division*/
  fprintf(fpasm, "\t\tcdq\n");
  fprintf(fpasm, "\t\tidiv ebx\n");
  fprintf(fpasm, "\t\tpush dword eax\n");/*Metemos en la pila unicamente el cociente de la division*/
}



void o(FILE* fpasm, int es_variable_1, int es_variable_2){
  fprintf(fpasm, "\n\t\t; Disyuncion logica\n");
  if(es_variable_1 && !es_variable_2) {/*Caso en el que solo es variable el primer operando*/
    fprintf(fpasm, "\t\tpop dword eax\n");
    fprintf(fpasm, "\t\tpop dword ebx\n");
    fprintf(fpasm, "\t\tor eax, [ebx]\n");
  } else {/*Caso en el que son ambos variables, solo el segundo operando es una variable o en el que ninguno lo es*/
    fprintf(fpasm, "\t\tpop dword ebx\n");
    fprintf(fpasm, "\t\tpop dword eax\n");
    if(es_variable_1){
      fprintf(fpasm, "\t\tmov dword eax, [eax]\n");
    }
    fprintf(fpasm, "\t\tor eax, %s\n", es_variable_2 ? "[ebx]" : "ebx");
  }
  fprintf(fpasm, "\t\tpush dword eax\n");
}



void y(FILE* fpasm, int es_variable_1, int es_variable_2){
  fprintf(fpasm, "\n\t\t; Conjuncion logica\n");
  if(es_variable_1 && !es_variable_2) {/*Caso en el que solo es variable el primer operando*/
    fprintf(fpasm, "\t\tpop dword eax\n");
    fprintf(fpasm, "\t\tpop dword ebx\n");
    fprintf(fpasm, "\t\tand eax, [ebx]\n");
  } else {/*Caso en el que son ambos variables, solo el segundo operando es una variable o en el que ninguno lo es*/
    fprintf(fpasm, "\t\tpop dword ebx\n");
    fprintf(fpasm, "\t\tpop dword eax\n");
    if(es_variable_1){
      fprintf(fpasm, "\t\tmov dword eax, [eax]\n");
    }
    fprintf(fpasm, "\t\tand eax, %s\n", es_variable_2 ? "[ebx]" : "ebx");
  }
  fprintf(fpasm, "\t\tpush dword eax\n");
}


/*
Función aritmética de cambio de signo.
Es análoga a las binarias, excepto que sólo requiere de un acceso a la pila ya que sólo usa un operando.
*/

void cambiar_signo(FILE* fpasm, int es_variable){
  fprintf(fpasm, "\n\t\t; Cambio de signo\n");
  fprintf(fpasm, "\t\tpop dword eax\n");
  if(es_variable){
    fprintf(fpasm, "\t\tmov dword eax, [eax]\n");
  }
  fprintf(fpasm, "\t\tneg dword eax\n");
  fprintf(fpasm, "\t\tpush dword eax\n");
}


/*
Función monádica lógica de negación. No hay un código de operación de la ALU que realice esta operación por lo que se debe codificar un algoritmo que, si encuentra en la cima de la pila un 0 deja en la cima un 1 y al contrario.
El último argumento es el valor de etiqueta que corresponde (sin lugar a dudas, la implementación del algoritmo requerirá etiquetas). Véase en los ejemplos de programa principal como puede gestionarse el número de etiquetas cuantos_no.
*/

void no(FILE* fpasm, int es_variable, int cuantos_no){
  fprintf(fpasm, "\n\t\t; Negacion logica\n");
  fprintf(fpasm,"\t\tpop eax\n");
  fprintf(fpasm, "\t\tcmp dword %s, 0\n", es_variable ? "[eax]" : "eax");
  fprintf(fpasm, "\t\tje __uno_%d\n", cuantos_no);
  fprintf(fpasm, "\t\tpush dword 0\n");
  fprintf(fpasm, "\t\tjmp __fin_no_%d\n", cuantos_no);
  fprintf(fpasm, "\t\t__uno_%d:\n", cuantos_no);
  fprintf(fpasm, "\t\tpush dword 1\n");
  fprintf(fpasm, "\t\t__fin_no_%d:\n", cuantos_no);
}



/* FUNCIONES COMPARATIVAS */
/*
Todas estas funciones reciben como argumento si los elementos a comparar son o no variables. El resultado de las operaciones, que siempre será un booleano (“1” si se cumple la comparación y “0” si no se cumple), se deja en la pila como en el resto de operaciones. Se deben usar etiquetas para poder gestionar los saltos necesarios para implementar las comparaciones.
*/
void igual(FILE* fpasm, int es_variable1, int es_variable2, int etiqueta){
  fprintf(fpasm, "\n\t\t; Comparacion de igualdad\n");
  if(es_variable1 && !es_variable2) {/*Caso en el que el primer operando es una variable y el segundo otra cosa*/
    fprintf(fpasm, "\t\tpop dword eax\n");
    fprintf(fpasm, "\t\tpop dword ebx\n");
    fprintf(fpasm, "\t\tcmp eax, [ebx]\n");
  } else {/*Caso en el que los dos son variables, en el que solo el segundo operando es una varible o que ninguno lo sea*/
    fprintf(fpasm, "\t\tpop dword ebx\n");
    fprintf(fpasm, "\t\tpop dword eax\n");
    if(es_variable1){
      fprintf(fpasm, "\t\tmov dword eax, [eax]\n");
    }
    fprintf(fpasm, "\t\tcmp eax, %s\n", es_variable2 ? "[ebx]" : "ebx");
  }

  fprintf(fpasm, "\t\tje __igual_%d\n", etiqueta);/* Comprobamos igualdad */
  fprintf(fpasm, "\t\tpush dword 0\n");/*Caso en el que no se cumple la igualdad*/
  fprintf(fpasm, "\t\tjmp __fin_igual_%d\n", etiqueta);/*Saltamos al final de nuestra rutina para comprobar la igualdad*/

  fprintf(fpasm, "\t\t__igual_%d:\n", etiqueta);/*En el caso de que se cumpla la igualdad*/
  fprintf(fpasm, "\t\tpush dword 1\n");/*Metemos un 1 en la pila*/
  fprintf(fpasm, "\t\t__fin_igual_%d:\n", etiqueta);/*FIn de la igualdad*/
}




void distinto(FILE* fpasm, int es_variable1, int es_variable2, int etiqueta){
  fprintf(fpasm, "\n\t\t; Comparacion de distinto\n");
  if(es_variable1 && !es_variable2) {/*Caso en el que el primer operando es una variable y el segundo otra cosa*/
    fprintf(fpasm, "\t\tpop dword eax\n");
    fprintf(fpasm, "\t\tpop dword ebx\n");
    fprintf(fpasm, "cmp eax, [ebx]\n");
  } else {/*Caso en el que los dos son variables, en el que solo el segundo operando es una varible o que ninguno lo sea*/
    fprintf(fpasm, "\t\tpop dword ebx\n");
    fprintf(fpasm, "\t\tpop dword eax\n");
    if(es_variable1){
      fprintf(fpasm, "\t\tmov dword eax, [eax]\n");
    }
    fprintf(fpasm, "\t\tcmp eax, %s\n", es_variable2 ? "[ebx]" : "ebx");
  }
  fprintf(fpasm, "\t\tje __distinto_%d\n", etiqueta);/* Comprobamos igualdad */
  fprintf(fpasm, "\t\tpush dword 1\n");/*Caso en el que se cumple la igualdad*/
  fprintf(fpasm, "\t\tjmp __fin_distinto_%d\n", etiqueta);/*Saltamos al final*/
  fprintf(fpasm, "\t\t__distinto_%d:\n", etiqueta);
  fprintf(fpasm, "\t\tpush dword 0\n");
  fprintf(fpasm, "\t\t__fin_distinto_%d:\n", etiqueta);
}


void menor_igual(FILE* fpasm, int es_variable1, int es_variable2, int etiqueta){
  fprintf(fpasm, "\n\t\t; Comparacion de menor o igual\n");
  fprintf(fpasm, "\t\tpop dword ebx\n");
  fprintf(fpasm, "\t\tpop dword eax\n");
  if(es_variable1){
    fprintf(fpasm, "\t\tmov eax, dword [eax]\n");
  }
  if(es_variable2){
    fprintf(fpasm, "\t\tmov ebx, dword [ebx]\n");
  }
  fprintf(fpasm, "\t\tcmp eax, ebx\n");
  fprintf(fpasm, "\t\tjle __menor_o_igual_%d\n", etiqueta);/* Comprobamos menor o igual */
  fprintf(fpasm, "\t\tpush dword 0\n");/* Caso se cumple la condicion */
  fprintf(fpasm, "\t\tjmp __fin_menor_o_igual_%d\n", etiqueta);
  fprintf(fpasm, "\t\t__menor_o_igual_%d:\n", etiqueta);
  fprintf(fpasm, "\t\tpush dword 1\n");
  fprintf(fpasm, "\t\t__fin_menor_o_igual_%d:\n", etiqueta);
}



void mayor_igual(FILE* fpasm, int es_variable1, int es_variable2, int etiqueta){
  fprintf(fpasm, "\n\t\t; Comparacion de mayor o igual\n");
  fprintf(fpasm, "\t\tpop dword ebx\n");
  fprintf(fpasm, "\t\tpop dword eax\n");
  if(es_variable1){
    fprintf(fpasm, "\t\tmov eax, dword [eax]\n");
  }
  if(es_variable2){
    fprintf(fpasm, "\t\tmov ebx, dword [ebx]\n");
  }
  fprintf(fpasm, "\t\tcmp eax, ebx\n");
  fprintf(fpasm, "\t\tjge __mayor_o_igual_%d\n", etiqueta);/* Comprobamos mayor o igual */
  fprintf(fpasm, "\t\tpush dword 0\n");
  fprintf(fpasm, "\t\tjmp __fin_mayor_o_igual_%d\n", etiqueta);
  fprintf(fpasm, "\t\t__mayor_o_igual_%d:\n", etiqueta);
  fprintf(fpasm, "\t\tpush dword 1\n");
  fprintf(fpasm, "\t\t__fin_mayor_o_igual_%d:\n", etiqueta);
}


void menor(FILE* fpasm, int es_variable1, int es_variable2, int etiqueta){
  fprintf(fpasm, "\n\t\t; Comparacion de menor\n");
  fprintf(fpasm, "\t\tpop dword ebx\n");
  fprintf(fpasm, "\t\tpop dword eax\n");
  if(es_variable1){
    fprintf(fpasm, "\t\tmov eax, dword [eax]\n");
  }
  if(es_variable2){
    fprintf(fpasm, "\t\tmov ebx, dword [ebx]\n");
  }
  fprintf(fpasm, "\t\tcmp eax, ebx\n");
  fprintf(fpasm, "\t\tjl __menor_%d\n", etiqueta);/* Comprobamos menor*/
  fprintf(fpasm, "\t\tpush dword 0\n");
  fprintf(fpasm, "\t\tjmp __fin_menor_%d\n", etiqueta);
  fprintf(fpasm, "\t\t__menor_%d:\n", etiqueta);
  fprintf(fpasm, "\t\tpush dword 1\n");
  fprintf(fpasm, "\t\t__fin_menor_%d:\n", etiqueta);
}


void mayor(FILE* fpasm, int es_variable1, int es_variable2, int etiqueta){
  fprintf(fpasm, "\n\t\t; Comparacion de mayor\n");
  fprintf(fpasm, "\t\tpop dword ebx\n");
  fprintf(fpasm, "\t\tpop dword eax\n");
  if(es_variable1){
    fprintf(fpasm, "\t\tmov eax, dword [eax]\n");
  }
  if(es_variable2){
    fprintf(fpasm, "\t\tmov ebx, dword [ebx]\n");
  }
  fprintf(fpasm, "\t\tcmp eax, ebx\n");
  fprintf(fpasm, "\t\tjg __mayor_%d\n", etiqueta);/*Comprobamos mayor*/
  fprintf(fpasm, "\t\tpush dword 0\n");
  fprintf(fpasm, "\t\tjmp __fin_mayor_%d\n", etiqueta);
  fprintf(fpasm, "\t\t__mayor_%d:\n", etiqueta);
  fprintf(fpasm, "\t\tpush dword 1\n");
  fprintf(fpasm, "\t\t__fin_mayor_%d:\n", etiqueta);
}

/* FUNCIONES DE ESCRITURA Y LECTURA */
/*
Se necesita saber el tipo de datos que se va a procesar (ENTERO o BOOLEANO) ya que hay diferentes funciones de librería para la lectura (idem. escritura) de cada tipo.
Se deben insertar en la pila los argumentos necesarios, realizar la llamada (call) a la función de librería correspondiente y limpiar la pila.
*/
void leer(FILE* fpasm, char* nombre, int tipo){
  fprintf(fpasm, "\n\t\t; Lectura\n");
  fprintf(fpasm, "\t\tpush dword _%s\n",nombre);
  fprintf(fpasm, "\t\tcall %s\n", (tipo == ENTERO) ? "scan_int" : "scan_boolean");/*Hay error si el tipo no es entero o booleano y llamamos a la funcion scan_boolean */
  fprintf(fpasm, "\t\tadd esp, 4\n");/*Limpiamos la pila*/
}


void escribir(FILE* fpasm, int es_variable, int tipo){
  fprintf(fpasm, "\n\t\t; Escritura\n");
  if (es_variable){
    fprintf(fpasm, "\t\tpop eax\n");
    fprintf(fpasm, "\t\tpush dword [eax]\n");
  }
  /* Si tipo no es ENTERO o BOLEANO habria error, pero simplemente llama a print_boolean */
  fprintf(fpasm, "\t\tcall %s\n", (tipo == ENTERO) ? "print_int" : "print_boolean");
  fprintf(fpasm, "\t\tcall print_endofline\n");
  fprintf(fpasm, "\t\tadd esp, 4\n\n");/*Limpiamos la pìla*/
}

void llamarFuncion(FILE * fpasm, char * nombre_funcion, int num_argumentos){
  fprintf(fpasm, "\t\tcall _%s\n", nombre_funcion);
  fprintf(fpasm, "\t\tadd esp, 4*%d\n", num_argumentos);
  fprintf(fpasm, "\t\tpush dword eax\n");
}

void declararFuncion(FILE * fpasm, char * nombre_funcion, int num_var_loc){
  fprintf(fpasm, "_%s:\n", nombre_funcion);
	fprintf(fpasm, "\t\tpush ebp\n");
	fprintf(fpasm, "\t\tmov ebp, esp\n");
	fprintf(fpasm, "\t\tsub esp, 4*%d\n", num_var_loc);
}

void retornarFuncion(FILE * fpasm, int es_variable){
  fprintf(fpasm, "\t\tpop dword eax\n");
	if (es_variable==1){
   		fprintf(fpasm,"\t\tmov eax, [eax]\n");
	}
	fprintf(fpasm, "\t\tmov dword esp, ebp\n");
	fprintf(fpasm, "\t\tpop dword ebp\n");
	fprintf(fpasm, "\t\tret\n");
}

void escribirParametro(FILE* fpasm, int pos_parametro, int num_total_parametros){
  fprintf(fpasm, "\t\tlea eax, [ebp+4+4*%d]\n", num_total_parametros - pos_parametro);
  fprintf(fpasm, "\t\tpush dword eax\n");
}

void escribirVariableLocal(FILE* fpasm, int posicion_variable_local){
  fprintf(fpasm, "\t\tlea eax, [ebp-4*%d]\n", posicion_variable_local);
  fprintf(fpasm, "\t\tpush dword eax\n");
}

void operandoEnPilaAArgumento(FILE * fpasm, int es_variable){
  fprintf(fpasm, "\t\tpop dword eax\n");
  if(es_variable==1){
    fprintf(fpasm,"\t\tmov eax, [eax]\n");
  }
  fprintf(fpasm, "\t\tpush dword eax\n");
}

void limpiarPila(FILE * fpasm, int num_argumentos){
  fprintf(fpasm, "\t\tadd esp, 4*%d\n", num_argumentos);
}

void while_inicio(FILE * fpasm, int etiqueta){
  fprintf(fpasm, "\t\tinicio_while%d:\n", etiqueta);
}

void while_exp_pila (FILE * fpasm, int exp_es_variable, int etiqueta){
  fprintf(fpasm,"\t\tpop eax\n");
  if(exp_es_variable == 1){
    fprintf(fpasm, "\t\tmov eax, [eax]\n");
  }
  fprintf(fpasm, "\t\tcmp eax, 0\n");
  fprintf(fpasm, "\t\tje near fin_while%d\n", etiqueta);
}

void while_fin( FILE * fpasm, int etiqueta){
  fprintf(fpasm, "\t\tjmp near inicio_while%d\n", etiqueta);
  fprintf(fpasm, "\t\tfin_while%d:\n", etiqueta);
}

void escribir_elemento_vector(FILE * fpasm,char * nombre_vector, int tam_max, int exp_es_direccion){
  fprintf(fpasm, "\t\t; carga el valor del indice en eax\n");
  fprintf(fpasm, "\t\tpop dword eax \n");
  if (exp_es_direccion == 1){
    fprintf(fpasm, "\t\tmov dword eax , [eax]\n");
  }
  fprintf(fpasm, "\t\t; Si el indice es menor que 0, error en tiempo de ejecucion\n");
  fprintf(fpasm, "\t\tcmp eax,0\n");
  fprintf(fpasm, "\t\tjl near mensaje_1\n");
  fprintf(fpasm, "\t\t; Si el indice es mayor de lo permitido, error en tiempo de ejecucion\n");
  fprintf(fpasm, "\t\tcmp eax, %d\n", tam_max-1);
  fprintf(fpasm, "\t\tjg near mensaje_1\n");
  fprintf(fpasm, "\t\tmov dword edx, _%s\n", nombre_vector);
  fprintf(fpasm, "\t\tlea eax, [edx + eax * 4]\n");
  fprintf(fpasm, "\t\tpush dword eax\n");
}

void instance_of(FILE *file, char * nombre_clase, int num_ai){
  fprintf(file, "\t\tpush %d\n", (num_ai+1)*4);
  fprintf(file, "\t\tcall malloc\n\t\tadd esp, 4\n\t\tpush eax\n");
  fprintf(file, "\t\tmov dword [eax], _ms%s\n", nombre_clase);
}

void ifthenelse_inicio(FILE * salida, int exp_es_variable, int etiqueta){
  fprintf(salida,"\t\t; Comprobamos la condicion: if (%d) para ver que es algo asimilable a una variable\n", etiqueta);
    fprintf(salida, "\t\tpop eax\n");
    if (exp_es_variable)
        fprintf(salida, "\t\tmov eax, [eax]\n");

    fprintf(salida, "\t\tcmp eax, 0\n");
    fprintf(salida, "\t\t; En caso de que no se cumpla la condicion nos vamos al else\n");
    fprintf(salida,"\t\tje __else_%d\n", etiqueta);
  fprintf(salida, "\t\t;Nos metemos en el caso del then (%i) ya que se cumple la condicion\n", etiqueta);
}


void ifthen_inicio(FILE * salida, int exp_es_variable, int etiqueta){
  fprintf(salida,"\t\t; Comprobamos la condicion: if (%d) para ver que es algo asimilable a una variable\n", etiqueta);
    fprintf(salida, "\t\tpop eax\n");
    if (exp_es_variable)
        fprintf(salida, "\t\tmov eax, [eax]\n");

    fprintf(salida, "\t\tcmp eax, 0\n");
    fprintf(salida, "\t\t; En caso de que no se cumpla la condicion nos vamos al final del ifthen\n");
    fprintf(salida, "\t\tje __endifthen_%d\n", etiqueta);
  fprintf(salida, "\t\t; En caso de que se cumpla nos metemos en el caso del then (%i) ya que se cumple la condicion\n", etiqueta);
}


void ifthen_fin(FILE* salida, int etiqueta){
    fprintf(salida, "\t\t; Estamos en la parte del final del then (%d) del ifthen\n", etiqueta);
    fprintf(salida, "\t\t__endifthen_%d:\n", etiqueta);
}


void ifthenelse_fin_then(FILE* salida, int etiqueta){
    fprintf(salida, "\t\t; Estamos en la parte del final del then (%d) del ifthen_else\n", etiqueta);
    fprintf(salida, "\t\tjmp __endifthen_else_%d\n", etiqueta);
    fprintf(salida, "\t\t__else_%d:\n", etiqueta);
}

void ifthenelse_fin( FILE * salida, int etiqueta){
  fprintf(salida, "\t\t; Estamos en la parte del final del else (%d) del ifthen_else\n", etiqueta);
  fprintf(salida, "\t\t__endifthen_else_%d:\n", etiqueta);
}

void asignarDestinoEnPila(FILE* file, int es_variable) {
  /*
    pop eax
    pop ebx
    if es_variable = 0:
      mov [ebx], eax
    else:
      mov eax, [eax]
      mov [ebx], eax
  */
  fprintf(file, "\t\tpop eax\n\t\tpop ebx\n");
  if(es_variable == 0){
    fprintf(file, "\t\tmov [eax], ebx\n");
  }
  else {
    fprintf(file, "\t\tmov ebx, [ebx]\n\t\tmov [eax], ebx\n");
  }
}

void discardPila (FILE * fd_asm){
  fprintf(fd_asm, "\t\tpop eax\n\t\tpush dword [eax]\n");
  fprintf(fd_asm, "\t\tcall free\n\t\tadd esp, 4\n");
}

char * claseATabla(char * nombre_fuente_clase){
  return addPrefijo("", nombre_fuente_clase);
}

void llamarMetodoSobreescribibleCualificadoInstanciaPila(FILE * fd_asm, char * nombre_metodo){
  fprintf(fd_asm, "\t\tpop eax\n");
  fprintf(fd_asm, "\t\tmov eax, [eax]\n");
  fprintf(fd_asm, "\t\tmov eax, [eax]\n");
  fprintf(fd_asm, "\t\tmov dword ebx, [_offset_%s]\n", nombre_metodo);
  fprintf(fd_asm, "\t\tlea eax, [eax+ebx]\n");
  fprintf(fd_asm, "\t\tmov eax, [eax]\n");
  fprintf(fd_asm, "\t\tcall eax\n");
}

void accederAtributoInstanciaDePila(FILE * fd_asm, char * nombre_atributo){
  fprintf(fd_asm, "\t\tpop eax\n");
  fprintf(fd_asm, "\t\tmov dword ebx, [_offset_%s]\n", nombre_atributo);
  fprintf(fd_asm, "\t\tlea eax, [eax+ebx]\n");
  fprintf(fd_asm, "\t\tpush eax\n");
}
