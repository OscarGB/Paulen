#ifndef MACROS_H
#define MACROS_H

// Errores generales
#define OK 1
#define ERROR 0

// Ambitos
#define LOCAL 0
#define PRINCIPAL 1

// Tipo de acceso
#define HIDDEN 0
#define EXPOSED 1
#define SECRET 2

// Tipo de parametro de funcion
#define ENTERO 1
#define BOOLEANO 3
#define OBJETO 4
#define FUNCION 5
#define MS 6 /*Tipo metodo sobrees.*/
#define MNS 7 /*Tipo metodo no sobrees.*/
#define AC 8 /*Tipo atrib. clsae*/
#define AI 9 /*Tipo atrib. instancia*/

// Recuerdo que las clases tienen tipo como el - indice que tienen en el grafo


#endif //MACROS_H