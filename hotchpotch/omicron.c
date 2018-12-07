
#include <stdio.h>
#include <stdlib.h>
#include "omicron.h"

FILE * salida;
FILE * sintactico;
extern FILE* yyin;
extern int yylex();
extern int yyparse();

int main(int argc, char const *argv[]) {
	int ret=1;
  /* code */
  if(argc != 3){
    printf("Se deben de meter 3 parametros de entrada:\n");
    printf("./ nombre_ejecutable  fichero_entrada fichero_salida \n");
    return -1;
  }

  yyin = fopen(argv[1], "r");
  salida = fopen(argv[2], "w");
  sintactico = fopen("salida_sintactico.txt", "w");
  
  while(ret){
  	ret = yylex();
  };
  fclose(yyin);
  fclose(salida);
  fclose(sintactico);
  return 0;
}


