#include <stdio.h>
#include <string.h>

extern int yyparse();
extern FILE * yyin;
FILE * salida = NULL;

int main(int argc, char ** argv){
  if (argc==1){
    yyin=stdin;
    salida=stdout;
  }else if (argc==2){
    yyin=fopen (argv[1], "r");
    salida=stdout;
  }else if (argc==3){
    yyin=fopen (argv[1], "r");
    salida=fopen (argv[2], "w");
  }
  yyparse();
  if (argc==2){
    fclose (yyin);
  }else if (argc==3){
    fclose (yyin);
    fclose (salida);
  }
  return 0;

}
