%{

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "y.tab.h"

int linea = 1;
int columna = 1;
extern FILE * fout;

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
	fprintf(fout, ";D:\t%s\n", yytext);
	return TOK_NONE;
}

class {
	columna+=yyleng;
  	fprintf(fout, ";D:\t%s\n", yytext);
	return TOK_CLASS;
}

inherits {
	columna+=yyleng;
  	fprintf(fout, ";D:\t%s\n", yytext);
	return TOK_INHERITS;
}

instance_of {
	columna+=yyleng;
  	fprintf(fout, ";D:\t%s\n", yytext);
	return TOK_INSTANCE_OF;
}

discard {
	columna+=yyleng;
  	fprintf(fout, ";D:\t%s\n", yytext);
	return TOK_DISCARD;
}

itself {
	columna+=yyleng;
  	fprintf(fout, ";D:\t%s\n", yytext);
	return TOK_ITSELF;
}

hidden {
	columna+=yyleng;
    fprintf(fout, ";D:\t%s\n", yytext);
	return TOK_HIDDEN;
}
secret {
	columna+=yyleng;
  	fprintf(fout, ";D:\t%s\n", yytext);
	return TOK_SECRET;
}

exposed {
	columna+=yyleng;
  	fprintf(fout, ";D:\t%s\n", yytext);
	return TOK_EXPOSED;
}

unique {
	columna+=yyleng;
  	fprintf(fout, ";D:\t%s\n", yytext);
	return TOK_UNIQUE;
}

function {
	columna+=yyleng;
  	fprintf(fout, ";D:\t%s\n", yytext);
	return TOK_FUNCTION;
}
return {
	columna+=yyleng;
  	fprintf(fout, ";D:\t%s\n", yytext);
	return TOK_RETURN;
}

main {
	columna+=yyleng;
  	fprintf(fout, ";D:\t%s\n", yytext);
	return TOK_MAIN;
}

int {
	columna+=yyleng;
  	fprintf(fout, ";D:\t%s\n", yytext);
	return TOK_INT;
}

boolean {
	columna+=yyleng;
  	fprintf(fout, ";D:\t%s\n", yytext);
	return TOK_BOOLEAN;
}

array {
	columna+=yyleng;
  	fprintf(fout, ";D:\t%s\n", yytext);
	return TOK_ARRAY;
}

if {
	columna+=yyleng;
  	fprintf(fout, ";D:\t%s\n", yytext);
	return TOK_IF;
}

else {
	columna+=yyleng;
  	fprintf(fout, ";D:\t%s\n", yytext);
	return TOK_ELSE;
}

while {
	columna+=yyleng;
  	fprintf(fout, ";D:\t%s\n", yytext);
	return TOK_WHILE;
}

scanf {
	columna+=yyleng;
	fprintf(fout, ";D:\t%s\n", yytext);
	return TOK_SCANF;
}
printf {
	columna+=yyleng;
	fprintf(fout, ";D:\t%s\n", yytext);
	return TOK_PRINTF;
}

false {
	columna+=yyleng;
	fprintf(fout, ";D:\t%s\n", yytext);
	return TOK_FALSE;
}

true {
	columna+=yyleng;
	fprintf(fout, ";D:\t%s\n", yytext);
	return TOK_TRUE;
}

; {
	columna+=yyleng;
	fprintf(fout, ";D:\t%s\n", yytext);
	return yytext[0];
}

# {
	columna+=yyleng;
	fprintf(fout, ";D:\t%s\n", yytext);
	return yytext[0];
}

, {
	columna+=yyleng;
	fprintf(fout, ";D:\t%s\n", yytext);
	return yytext[0];
}

= {
	columna+=yyleng;
	fprintf(fout, ";D:\t%s\n", yytext);
	return yytext[0];
}

\( {
	columna+=yyleng;
	fprintf(fout, ";D:\t%s\n", yytext);
	return yytext[0];
}

\) {
	columna+=yyleng;
	fprintf(fout, ";D:\t%s\n", yytext);
	return yytext[0];
}

\[ {
	columna+=yyleng;
	fprintf(fout, ";D:\t%s\n", yytext);
	return yytext[0];
}

\] {
	columna+=yyleng;
	fprintf(fout, ";D:\t%s\n", yytext);
	return yytext[0];
}

\{ {
	columna+=yyleng;
	fprintf(fout, ";D:\t%s\n", yytext);
	return yytext[0];
}

\} {
	columna+=yyleng;
	fprintf(fout, ";D:\t%s\n", yytext);
	return yytext[0];
}

\: {
	columna+=yyleng;
	fprintf(fout, ";D:\t%s\n", yytext);
	return yytext[0];
}

\+ {
	columna+=yyleng;
	fprintf(fout, ";D:\t%s\n", yytext);
	return yytext[0];
}

\- {
	columna+=yyleng;
	fprintf(fout, ";D:\t%s\n", yytext);
	return yytext[0];
}

\/ {
	columna+=yyleng;
	fprintf(fout, ";D:\t%s\n", yytext);
	return yytext[0];
}

\* {
	columna+=yyleng;
	fprintf(fout, ";D:\t%s\n", yytext);
	return yytext[0];
}

\< {
	columna+=yyleng;
	fprintf(fout, ";D:\t%s\n", yytext);
	return yytext[0];
}

\> {
	columna+=yyleng;
	fprintf(fout, ";D:\t%s\n", yytext);
	return yytext[0];
}

\& {
	columna+=yyleng;
	fprintf(fout, ";D:\t%s\n", yytext);
	return yytext[0];
}

\! {
	columna+=yyleng;
	fprintf(fout, ";D:\t%s\n", yytext);
	return yytext[0];
}

\. {
	columna+=yyleng;
	fprintf(fout, ";D:\t%s\n", yytext);
	return yytext[0];
}

"==" {
	columna+=yyleng;
	fprintf(fout, ";D:\t%s\n", yytext);
	return TOK_IGUAL;
}

"!=" {
	columna+=yyleng;
	fprintf(fout, ";D:\t%s\n", yytext);
	return TOK_DISTINTO;
}

"<=" {
	columna+=yyleng;
	fprintf(fout, ";D:\t%s\n", yytext);
	return TOK_MENORIGUAL;
}

">=" {
	columna+=yyleng;
	fprintf(fout, ";D:\t%s\n", yytext);
	return TOK_MAYORIGUAL;
}

"||" {
	columna+=yyleng;
	fprintf(fout, ";D:\t%s\n", yytext);
	return TOK_OR;
}

"&&" {
	columna+=yyleng;
	fprintf(fout, ";D:\t%s\n", yytext);
	return TOK_AND;
}
"->" {
	columna+=yyleng;
	fprintf(fout, ";D:\t%s\n", yytext);
	return TOK_FLECHA;
}

{IDENTIFICADOR} {
  if(yyleng > 50){
  	columna+=yyleng;
		fprintf(stderr, "ERROR MORFOLOGICO:%d:%d:IDENTIFICADOR DEMASIADO LARGO (%s)\n", linea, columna, yytext);
    return TOK_ERROR;
  }
  columna+=yyleng;
	fprintf(fout, ";D:\t%s\n", yytext);
  return TOK_IDENTIFICADOR;
}

{ENTERO} {
	columna+=yyleng;
	fprintf(fout, ";D:\t%s\n", yytext);
	return TOK_CONSTANTE_ENTERA;
}

{COMENTARIO} {linea+=1; columna=0;}

{SALTO} {linea+=1; columna=0;}

{BLANCO} {columna+=yyleng;}

{ERROR} {
	columna+=yyleng;
	fprintf(stderr, "ERROR MORFOLOGICO:%d:%d:CARACTER INVALIDO (%s)\n", linea, columna, yytext);
	return TOK_ERROR;
}

%%
