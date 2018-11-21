%{
#include "omicron.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "y.tab.h"


int linea = 1;
int columna = 1;

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
	return TOK_NONE;
}

class {
	columna+=yyleng;
	return TOK_CLASS;
}

inherits {
	columna+=yyleng;
	return TOK_INHERITS;
}

instance_of {
	columna+=yyleng;
	return TOK_INSTANCE_OF;
}

discard {
	columna+=yyleng;
	return TOK_DISCARD;
}

itself {
	columna+=yyleng;
	return TOK_ITSELF;
}

hidden {
	columna+=yyleng;
	return TOK_HIDDEN;
}
secret {
	columna+=yyleng;
	return TOK_SECRET;
}

exposed {
	columna+=yyleng;
	return TOK_EXPOSED;
}

unique {
	columna+=yyleng;
	return TOK_UNIQUE;
}

function {
	columna+=yyleng;
	return TOK_FUNCTION;
}
return {
	columna+=yyleng;
	return TOK_RETURN;
}

main {
	columna+=yyleng;
	return TOK_MAIN;
}

int {
	columna+=yyleng;
	return TOK_INT;
}

boolean {
	columna+=yyleng;
	return TOK_BOOLEAN;
}

array {
	columna+=yyleng;
	return TOK_ARRAY;
}

if {
	columna+=yyleng;
	return TOK_IF;
}

else {
	columna+=yyleng;
	return TOK_ELSE;
}

while {
	columna+=yyleng;
	return TOK_WHILE;
}

scanf {
	columna+=yyleng;
	return TOK_SCANF;
}
printf {
	columna+=yyleng;
	return TOK_PRINTF;
}

false {
	columna+=yyleng;
	return TOK_FALSE;
}

true {
	columna+=yyleng;
	return TOK_TRUE;
}

; {
	columna+=yyleng;
	return yytext[0];
}

# {
	columna+=yyleng;
	return yytext[0];
}

, {
	columna+=yyleng;
	return yytext[0];
}

= {
	columna+=yyleng;
	return yytext[0];
}

\( {
	columna+=yyleng;
	return yytext[0];
}

\) {
	columna+=yyleng;
	return yytext[0];
}

\[ {
	columna+=yyleng;
	return yytext[0];
}

\] {
	columna+=yyleng;
	return yytext[0];
}

\{ {
	columna+=yyleng;
	return yytext[0];
}

\} {
	columna+=yyleng;
	return yytext[0];
}

\: {
	columna+=yyleng;
	return yytext[0];
}

\+ {
	columna+=yyleng;
	return yytext[0];
}

\- {
	columna+=yyleng;
	return yytext[0];
}

\/ {
	columna+=yyleng;
	return yytext[0];
}

\* {
	columna+=yyleng;
	return yytext[0];
}

\< {
	columna+=yyleng;
	return yytext[0];
}

\> {
	columna+=yyleng;
	return yytext[0];
}

\& {
	columna+=yyleng;
	return yytext[0];
}

\! {
	columna+=yyleng;
	return yytext[0];
}

\. {
	columna+=yyleng;
	return yytext[0];
}

"==" {
	columna+=yyleng;
	return TOK_IGUAL;
}

"!=" {
	columna+=yyleng;
	return TOK_DISTINTO;
}

"<=" {
	columna+=yyleng;
	return TOK_MENORIGUAL;
}

">=" {
	columna+=yyleng;
	return TOK_MAYORIGUAL;
}

"||" {
	columna+=yyleng;
	return TOK_OR;
}

"&&" {
	columna+=yyleng;
	return TOK_AND;
}
"->" {
	columna+=yyleng;
	return TOK_FLECHA;
}

{IDENTIFICADOR} {
  if(yyleng > 50){
  	columna+=yyleng;
	fprintf(stderr, "ERROR MORFOLOGICO:%d:%d:IDENTIFICADOR DEMASIADO LARGO (%s)\n", linea, columna, yytext);
    return -1;
  }
  columna+=yyleng;
	strcpy(yylval.atributos.lexema, yytext);
  return TOK_IDENTIFICADOR;
}

{ENTERO} {
	columna+=yyleng;
	yylval.atributos.valor_entero=atoi(yytext);
	return TOK_CONSTANTE_ENTERA;
}

{COMENTARIO} {linea+=1; columna=0;}

{SALTO} {linea+=1; columna=0;}

{BLANCO} {columna+=yyleng;}

{ERROR} {
	columna+=yyleng;
	fprintf(stderr, "ERROR MORFOLOGICO:%d:%d:CARACTER INVALIDO (%s)\n", linea, columna, yytext);
	return -1;
}

%%
