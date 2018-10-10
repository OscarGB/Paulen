
#include <stdio.h>
#include "generacion_resto.h"

int main (int argc, char** argv)
{
	FILE* salida;

	if (argc != 2) {fprintf (stdout, "ERROR POCOS ARGUMENTOS\n"); return -1;}

	salida = fopen(argv[1],"w");

	escribir_subseccion_data(salida);
	escribir_cabecera_bss(salida);

	/*Declaraciones*/
	declarar_variable(salida, "x", ENTERO, 1);
	declarar_variable(salida, "y", ENTERO, 1);
	declarar_variable(salida, "z", ENTERO, 1);
	declarar_variable(salida, "a", ENTERO, 1);
	declarar_variable(salida, "j", ENTERO, 1);

	escribir_segmento_codigo(salida);
	escribir_inicio_main(salida);

	/* scanfs */
	leer(salida,"x",ENTERO);
	leer(salida,"y",ENTERO);
	leer(salida,"z",ENTERO);

	/* a=3; */
	escribir_operando(salida,"3",0);
	asignar(salida,"a",0);

	/* j = x % a */
	escribir_operando(salida,"x",1);
	escribir_operando(salida,"a",1);
	resto(salida,1,1);
	asignar(salida,"j",0);

	/* printf(j); */
	escribir_operando(salida,"j",1);
	escribir(salida,1,ENTERO);

	/* j = y % a */
	escribir_operando(salida,"y",1);
	escribir_operando(salida,"a",1);
	resto(salida,1,1);
	asignar(salida,"j",0);

	/* printf(j); */
	escribir_operando(salida,"j",1);
	escribir(salida,1,ENTERO);

	/* j = z % a */
	escribir_operando(salida,"z",1);
	escribir_operando(salida,"a",1);
	resto(salida,1,1);
	asignar(salida,"j",0);

	/* printf(j); */
	escribir_operando(salida,"j",1);
	escribir(salida,1,ENTERO);

	escribir_fin(salida);

	fclose(salida);
	return 0;
}