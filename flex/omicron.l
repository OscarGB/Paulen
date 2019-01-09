%{
#include "omicron.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "omicron.tab.h"

int linea = 1;
int columna = 1;
extern FILE * sintactico;
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
	fprintf(sintactico, ";D: none\n");
	columna+=yyleng;
	return TOK_NONE;
}

class {
	fprintf(sintactico, ";D: class\n");
	columna+=yyleng;
	return TOK_CLASS;
}

inherits {
	fprintf(sintactico, ";D: inherits\n");
	columna+=yyleng;
	return TOK_INHERITS;
}

instance_of {
	fprintf(sintactico, ";D: instance_of\n");
	columna+=yyleng;
	return TOK_INSTANCE_OF;
}

discard {
	fprintf(sintactico, ";D: discard\n");
	columna+=yyleng;
	return TOK_DISCARD;
}

itself {
	fprintf(sintactico, ";D: itself\n");
	columna+=yyleng;
	return TOK_ITSELF;
}

hidden {
	fprintf(sintactico, ";D: hidden\n");
	columna+=yyleng;
	return TOK_HIDDEN;
}
secret {
	fprintf(sintactico, ";D: secret\n");
	columna+=yyleng;
	return TOK_SECRET;
}

exposed {
	fprintf(sintactico, ";D: exposed\n");
	columna+=yyleng;
	return TOK_EXPOSED;
}

unique {
	fprintf(sintactico, ";D: unique\n");
	columna+=yyleng;
	return TOK_UNIQUE;
}

function {
	fprintf(sintactico, ";D: function\n");
	columna+=yyleng;
	return TOK_FUNCTION;
}
return {
	fprintf(sintactico, ";D: return\n");
	columna+=yyleng;
	return TOK_RETURN;
}

main {
	fprintf(sintactico, ";D: main\n");
	columna+=yyleng;
	return TOK_MAIN;
}

int {
	fprintf(sintactico, ";D: int\n");
	columna+=yyleng;
	return TOK_INT;
}

boolean {
	fprintf(sintactico, ";D: boolean\n");
	columna+=yyleng;
	return TOK_BOOLEAN;
}

array {
	fprintf(sintactico, ";D: array\n");
	columna+=yyleng;
	return TOK_ARRAY;
}

if {
	fprintf(sintactico, ";D: if\n");
	columna+=yyleng;
	return TOK_IF;
}

else {
	fprintf(sintactico, ";D: else\n");
	columna+=yyleng;
	return TOK_ELSE;
}

while {
	fprintf(sintactico, ";D: while\n");
	columna+=yyleng;
	return TOK_WHILE;
}

for {
	fprintf(sintactico, ";D: for\n");
	columna+=yyleng;
	return TOK_FOR;
}

switch {
	fprintf(sintactico, ";D: switch\n");
	columna+=yyleng;
	return TOK_SWITCH;
}

break { 
	fprintf(sintactico, ";D: break\n");
	columna += yyleng;
	return TOK_BREAK;
}

case { 
	fprintf(sintactico, ";D: case\n");
	columna += yyleng;
	return TOK_CASE;
}

default { 
	fprintf(sintactico, ";D: default\n");
	columna += yyleng;
	return TOK_DEFAULT;
}

scanf {
	fprintf(sintactico, ";D: scanf\n");
	columna+=yyleng;
	return TOK_SCANF;
}
printf {
	fprintf(sintactico, ";D: printf\n");
	columna+=yyleng;
	return TOK_PRINTF;
}

false {
	fprintf(sintactico, ";D: false\n");
	columna+=yyleng;
	return TOK_FALSE;
}

true {
	fprintf(sintactico, ";D: true\n");
	columna+=yyleng;
	return TOK_TRUE;
}

; {
	fprintf(sintactico, ";D: ;\n");
	columna+=yyleng;
	return yytext[0];
}

# {
	fprintf(sintactico, ";D: #\n");
	columna+=yyleng;
	return yytext[0];
}

, {
	fprintf(sintactico, ";D: ,\n");
	columna+=yyleng;
	return yytext[0];
}

= {
	fprintf(sintactico, ";D: =\n");
	columna+=yyleng;
	return yytext[0];
}

\( {
	fprintf(sintactico, ";D: (\n");
	columna+=yyleng;
	return yytext[0];
}

\) {
	fprintf(sintactico, ";D: )\n");
	columna+=yyleng;
	return yytext[0];
}

\[ {
	fprintf(sintactico, ";D:  [\n");
	columna+=yyleng;
	return yytext[0];
}

\] {
	fprintf(sintactico, ";D: ]\n");
	columna+=yyleng;
	return yytext[0];
}

\{ {
	fprintf(sintactico, ";D: {\n");
	columna+=yyleng;
	return yytext[0];
}

\} {
	fprintf(sintactico, ";D: }\n");
	columna+=yyleng;
	return yytext[0];
}

\: {
	fprintf(sintactico, ";D: :\n");
	columna+=yyleng;
	return yytext[0];
}

\+ {
	fprintf(sintactico, ";D: +\n");
	columna+=yyleng;
	return yytext[0];
}

\- {
	fprintf(sintactico, ";D: -\n");
	columna+=yyleng;
	return yytext[0];
}

\/ {
	fprintf(sintactico, ";D: /\n");
	columna+=yyleng;
	return yytext[0];
}

\* {
	fprintf(sintactico, ";D: *\n");
	columna+=yyleng;
	return yytext[0];
}

\< {
	fprintf(sintactico, ";D: <\n");
	columna+=yyleng;
	return yytext[0];
}

\> {
	fprintf(sintactico, ";D: >\n");
	columna+=yyleng;
	return yytext[0];
}

\& {
	fprintf(sintactico, ";D: &\n");
	columna+=yyleng;
	return yytext[0];
}

\! {
	fprintf(sintactico, ";D: !\n");
	columna+=yyleng;
	return yytext[0];
}

\. {
	fprintf(sintactico, ";D: .\n");
	columna+=yyleng;
	return yytext[0];
}

"==" {
	fprintf(sintactico, ";D: ==\n");
	columna+=yyleng;
	return TOK_IGUAL;
}

"!=" {
	fprintf(sintactico, ";D: !=\n");
	columna+=yyleng;
	return TOK_DISTINTO;
}

"<=" {
	fprintf(sintactico, ";D: <=\n");
	columna+=yyleng;
	return TOK_MENORIGUAL;
}

">=" {
	fprintf(sintactico, ";D: >=\n");
	columna+=yyleng;
	return TOK_MAYORIGUAL;
}

"||" {
	fprintf(sintactico, ";D: ||\n");
	columna+=yyleng;
	return TOK_OR;
}

"&&" {
	fprintf(sintactico, ";D: &&\n");
	columna+=yyleng;
	return TOK_AND;
}
"->" {
	fprintf(sintactico, ";D: ->\n");
	columna+=yyleng;
	return TOK_FLECHA;
}
"^" {
	fprintf(sintactico, ";D: ^\n");
	columna+=yyleng;
	return TOK_EXP;
}

{IDENTIFICADOR} {
  if(yyleng > 50){
  	columna+=yyleng;
	fprintf(stderr, "ERROR MORFOLOGICO:%d:%d:IDENTIFICADOR DEMASIADO LARGO (%s)\n", linea, columna, yytext);
    return -1;
  }
  fprintf(sintactico, ";D: %s\n", yytext);
  columna+=yyleng;
  strcpy(yylval.atributos.lexema, yytext);
  return TOK_IDENTIFICADOR;
}

{ENTERO} {
	fprintf(sintactico, ";D: %s\n", yytext);
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
