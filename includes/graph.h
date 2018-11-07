#include <stdio.h>
#include <stdlib.h>
#include "hash_table.h"
#include "macros.h"

#ifndef _GRAPH_H_
#define _GRAPH_H_



typedef struct adjlist adjlist_t, *adjlist_p;

/* Node*/
typedef struct node
{
    char name[100];    /*Name of the node*/
    char** padres;  /*Name of the parents in order of creation (newest to oldest)*/
    adjlist_p parents; /*List of parents*/
    adjlist_p children; /*List of children*/
    hash_table_p local; /*Tabla simbolos local*/
    hash_table_p principal; /*Tabla simbolos principal*/
    int numparents;
}node_t, *node_p;

typedef struct list_elem list_elem_t, *list_elem_p;

/*Elements of and adjlist*/
struct list_elem
{
    node_p node;
    list_elem_p next;
    list_elem_p prev;
};

/* Adjacency list: there will be 2 per node, parents and
children */
struct adjlist
{
    int num_members;           /*number of members in the list (for future use)*/
    list_elem_p head;      /*head of the adjacency linked list*/
};

/* Graph structure. A graph is an array of adjacency lists.
   Size of array will be number of vertices in graph*/
typedef struct graph_t
{
    int num_nodes;         /*Number of vertices*/
    adjlist_t *nodes_list;     /*List with all the nodes*/
    hash_table_p nodes_hash_table;  /*Hash table for node access*/
    char* name;
    
}graph_t, *graph_p;

graph_p createGraph(char* name);

node_p addNode(graph_t *graph, node_p* parents, int numparents, char* name);

void destroyGraph(graph_p graph);

void destroyNode(node_p node);

void displayGraph(graph_p graph);

node_p searchNode(graph_p graph, char* key);

node_p getINode(graph_p graph, int indice);

hash_table_p getHT(graph_p graph, char* key, int tipo);

void createHTLocal(graph_p graph, char* key, char* name);

void deleteHTLocal(graph_p graph, char* key);

/*Devuelve el nombre del ambito principal, a no ser que exista el ambito local*/
char * getAmbito(node_p node);

#endif