#include <stdio.h>
#include <stdlib.h>

#ifndef _GRAPH_H_
#define _GRAPH_H_

typedef struct adjlist adjlist_t, *adjlist_p;

/* Node*/
typedef struct node
{
    char name[20];    /*Name of the node*/
    char content[20]; /*Node content*/
    adjlist_p parents; /*List of parents*/
    adjlist_p children; /*List of children*/
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
}graph_t, *graph_p;

node_p createNode(int v);

graph_p createGraph();

node_p addNode(graph_t *graph, node_p* parents, int numparents, char* name, char* content);

void destroyGraph(graph_p graph);

void destroyNode(node_p node);

void displayGraph(graph_p graph);


#endif