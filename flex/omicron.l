%{
#include <string.h>
#include "tokens.h"

int linea = 1;
int columna = 0;
extern FILE * yyout;

%}

%option noyywrap

DIGITO [0-9]
LETRA [a-zA-Z]
BLANCO [ \t]
SALTO \n
COMENTARIO "//".*\n
IDENTIFICADOR ([a-z]|[A-Z])([0-9]|[a-z]|[A-Z])*
ENTERO {DIGITO}+
ERROR .

%%

none {
	columna+=yyleng; 
	fprintf(yyout, "TOK_NONE\t%d %s\n", TOK_NONE, yytext);
	return TOK_NONE;
}
class {
	columna+=yyleng; 
    fprintf(yyout, "TOK_CLASS\t%d %s\n", TOK_CLASS, yytext);
	return TOK_CLASS;
}
inherits {
	columna+=yyleng; 
    fprintf(yyout, "TOK_INHERITS\t%d %s\n", TOK_INHERITS, yytext);
	return TOK_INHERITS;
}
instance_of {
	columna+=yyleng; 
    fprintf(yyout, "TOK_INSTANCE_OF\t%d %s\n", TOK_INSTANCE_OF, yytext);
	return TOK_INSTANCE_OF;
}
discard {
	columna+=yyleng; 
    fprintf(yyout, "TOK_DISCARD\t%d %s\n", TOK_DISCARD, yytext);
	return TOK_DISCARD;
}
itself {
	columna+=yyleng; 
    fprintf(yyout, "TOK_ITSELF\t%d %s\n", TOK_ITSELF, yytext);
	return TOK_ITSELF;
}
hidden {
	columna+=yyleng; 
    fprintf(yyout, "TOK_HIDDEN\t%d %s\n", TOK_HIDDEN, yytext);
	return TOK_HIDDEN;
}
secret {
	columna+=yyleng; 
    fprintf(yyout, "TOK_SECRET\t%d %s\n", TOK_SECRET, yytext);
	return TOK_SECRET;
}
exposed {
	columna+=yyleng; 
    fprintf(yyout, "TOK_EXPOSED\t%d %s\n", TOK_EXPOSED, yytext);
	return TOK_EXPOSED;
}
unique {
	columna+=yyleng; 
    fprintf(yyout, "TOK_UNIQUE\t%d %s\n", TOK_UNIQUE, yytext);
	return TOK_UNIQUE;
}

function {
	columna+=yyleng; 
    fprintf(yyout, "TOK_FUNCTION\t%d %s\n", TOK_FUNCTION, yytext);
	return TOK_FUNCTION;
}
return {
	columna+=yyleng; 
    fprintf(yyout, "TOK_RETURN\t%d %s\n", TOK_RETURN, yytext);
	return TOK_RETURN;
}
main {
	columna+=yyleng; 
    fprintf(yyout, "TOK_MAIN\t%d %s\n", TOK_MAIN, yytext);
	return TOK_MAIN;
}
int {
	columna+=yyleng; 
    fprintf(yyout, "TOK_INT\t%d %s\n", TOK_INT, yytext);
	return TOK_INT;
}
boolean {
	columna+=yyleng; 
    fprintf(yyout, "TOK_BOOLEAN\t%d %s\n", TOK_BOOLEAN, yytext);
	return TOK_BOOLEAN;
}
array {
	columna+=yyleng; 
    fprintf(yyout, "TOK_ARRAY\t%d %s\n", TOK_ARRAY, yytext);
	return TOK_ARRAY;
}
if {
	columna+=yyleng; 
    fprintf(yyout, "TOK_IF\t%d %s\n", TOK_IF, yytext);
	return TOK_IF;
}
else {
	columna+=yyleng; 
    fprintf(yyout, "TOK_ELSE\t%d %s\n", TOK_ELSE, yytext);
	return TOK_ELSE;
}
while {
	columna+=yyleng; 
    fprintf(yyout, "TOK_WHILE\t%d %s\n", TOK_WHILE, yytext);
	return TOK_WHILE;
}
scanf {
	columna+=yyleng; 
    fprintf(yyout, "TOK_SCANF\t%d %s\n", TOK_SCANF, yytext);
	return TOK_SCANF;
}
printf {
	columna+=yyleng; 
    fprintf(yyout, "TOK_PRINTF\t%d %s\n", TOK_PRINTF, yytext);
	return TOK_PRINTF;
}
false {
	columna+=yyleng; 
    fprintf(yyout, "TOK_FALSE\t%d %s\n", TOK_FALSE, yytext);
	return TOK_FALSE;
}
true {
	columna+=yyleng; 
    fprintf(yyout, "TOK_TRUE\t%d %s\n", TOK_TRUE, yytext);
	return TOK_TRUE;
}


; {
	columna+=yyleng; 
	fprintf(yyout, "SIMBOLO SIMPLE\t%d %c\n", yytext[0], yytext[0]);
	return yytext[0];
}

# {
	columna+=yyleng; 
	fprintf(yyout, "SIMBOLO SIMPLE\t%d %c\n", yytext[0], yytext[0]);
	return yytext[0];
}

, {
	columna+=yyleng; 
	fprintf(yyout, "SIMBOLO SIMPLE\t%d %c\n", yytext[0], yytext[0]);
	return yytext[0];
}

= {
	columna+=yyleng; 
	fprintf(yyout, "SIMBOLO SIMPLE\t%d %c\n", yytext[0], yytext[0]);
	return yytext[0];
}

\( {
	columna+=yyleng; 
	fprintf(yyout, "SIMBOLO SIMPLE\t%d %c\n", yytext[0], yytext[0]);
	return yytext[0];
}

\) {
	columna+=yyleng; 
	fprintf(yyout, "SIMBOLO SIMPLE\t%d %c\n", yytext[0], yytext[0]);
	return yytext[0];
}

\[ {
	columna+=yyleng; 
	fprintf(yyout, "SIMBOLO SIMPLE\t%d %c\n", yytext[0], yytext[0]);
	return yytext[0];
}

\] {
	columna+=yyleng; 
	fprintf(yyout, "SIMBOLO SIMPLE\t%d %c\n", yytext[0], yytext[0]);
	return yytext[0];
}

\{ {
	columna+=yyleng; 
	fprintf(yyout, "SIMBOLO SIMPLE\t%d %c\n", yytext[0], yytext[0]);
	return yytext[0];
}

\} {
	columna+=yyleng; 
	fprintf(yyout, "SIMBOLO SIMPLE\t%d %c\n", yytext[0], yytext[0]);
	return yytext[0];
}

\: {
	columna+=yyleng; 
	fprintf(yyout, "SIMBOLO SIMPLE\t%d %c\n", yytext[0], yytext[0]);
	return yytext[0];
}

\+ {
	columna+=yyleng; 
	fprintf(yyout, "SIMBOLO SIMPLE\t%d %c\n", yytext[0], yytext[0]);
	return yytext[0];
}

\- {
	columna+=yyleng; 
	fprintf(yyout, "SIMBOLO SIMPLE\t%d %c\n", yytext[0], yytext[0]);
	return yytext[0];
}

\/ {
	columna+=yyleng; 
	fprintf(yyout, "SIMBOLO SIMPLE\t%d %c\n", yytext[0], yytext[0]);
	return yytext[0];
}

\* {
	columna+=yyleng; 
	fprintf(yyout, "SIMBOLO SIMPLE\t%d %c\n", yytext[0], yytext[0]);
	return yytext[0];
}

\< {
	columna+=yyleng; 
	fprintf(yyout, "SIMBOLO SIMPLE\t%d %c\n", yytext[0], yytext[0]);
	return yytext[0];
}

\> {
	columna+=yyleng; 
	fprintf(yyout, "SIMBOLO SIMPLE\t%d %c\n", yytext[0], yytext[0]);
	return yytext[0];
}

\& {
	columna+=yyleng; 
	fprintf(yyout, "SIMBOLO SIMPLE\t%d %c\n", yytext[0], yytext[0]);
	return yytext[0];
}

\! {
	columna+=yyleng; 
	fprintf(yyout, "SIMBOLO SIMPLE\t%d %c\n", yytext[0], yytext[0]);
	return yytext[0];
}

\. {
	columna+=yyleng; 
	fprintf(yyout, "SIMBOLO SIMPLE\t%d %c\n", yytext[0], yytext[0]);
	return yytext[0];
}

"==" {
	columna+=yyleng; 
    fprintf(yyout, "TOK_IGUAL\t%d %s\n", TOK_IGUAL, yytext);
	return TOK_IGUAL;
}
"!=" {
	columna+=yyleng; 
    fprintf(yyout, "TOK_DISTINTO\t%d %s\n", TOK_DISTINTO, yytext);
	return TOK_DISTINTO;
}
"<=" {
	columna+=yyleng; 
    fprintf(yyout, "TOK_MENORIGUAL\t%d %s\n", TOK_MENORIGUAL, yytext);
	return TOK_MENORIGUAL;
}
">=" {
	columna+=yyleng; 
    fprintf(yyout, "TOK_MAYORIGUAL\t%d %s\n", TOK_MAYORIGUAL, yytext);
	return TOK_MAYORIGUAL;
}
"||" {
	columna+=yyleng; 
    fprintf(yyout, "TOK_OR\t%d %s\n", TOK_OR, yytext);
	return TOK_OR;
}
"&&" {
	columna+=yyleng; 
    fprintf(yyout, "TOK_AND\t%d %s\n", TOK_AND, yytext);
	return TOK_AND;
}
"->" {
	columna+=yyleng; 
    fprintf(yyout, "TOK_FLECHA\t%d %s\n", TOK_FLECHA, yytext);
	return TOK_FLECHA;
}

{IDENTIFICADOR} {
  if(yyleng > MAX_LONG_ID){
  	columna+=yyleng; 
    fprintf(yyout, "TOK_ERROR\t%d %s\n", TOK_ERROR, yytext);
    return TOK_ERROR;
  }
  columna+=yyleng;
  fprintf(yyout, "TOK_IDENTIFICADOR\t%d %s\n", TOK_IDENTIFICADOR, yytext);
  return TOK_IDENTIFICADOR;
}
{ENTERO} {
	columna+=yyleng; 
    fprintf(yyout, "TOK_CONSTANTE_ENTERA\t%d %s\n", TOK_CONSTANTE_ENTERA, yytext);
	return TOK_CONSTANTE_ENTERA;
}
{COMENTARIO} {linea+=1; columna=0;}
{SALTO} {linea+=1; columna=0;}
{BLANCO} {columna+=yyleng;}
{ERROR} {
	columna+=yyleng; 
    fprintf(yyout, "TOK_ERROR\t%d %s\n", TOK_ERROR, yytext);
	return TOK_ERROR;
}

%%

