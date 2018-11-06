#include <stdio.h>
#include <string.h>

int yylex();
int yyparse();
FILE * fout = NULL;

int main(int argc, char const *argv[]) {
  extern FILE * yyin;
  int ret=1;
  /* code */
  if(argc != 3){
    printf("Se deben de meter 3 parametros de entrada:\n");
    printf("./nombre_ejecutable fichero_entrada fichero_salida \n");
    return -1;
  }

  yyin = fopen(argv[1], "r");
  if (yyin==NULL){
    return 1;
  }
  fout = fopen(argv[2], "w");
  if (fout==NULL){
    return 1;
  }

  if(yyparse()!=0){
  }else{
    while(ret){
      ret = yylex();
    }
  }

  fclose(yyin);
  fclose(fout);
  return 0;
}
