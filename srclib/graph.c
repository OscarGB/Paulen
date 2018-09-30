#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

/* Function to create a graph with n vertices; Creates both directed and undirected graphs*/
graph_p createGraph()
{
    graph_p graph = (graph_p)malloc(sizeof(graph_t));
    if(!graph)
        exit(1);
    graph->num_nodes = 0;
    graph->nodes_list = (adjlist_p)malloc(sizeof(adjlist_t));
    if(!graph->nodes_list){
        free(graph);
        exit(1);
    }

    return graph;
}

/*Destroys an adjList from the last element*/
void destroyAdjList(adjlist_p list)
{
    list_elem_p elem = list->head;
    list_elem_p next = elem-> next;
    int num = list->num_members;
    if(list -> num_members > 0){
        while(next){
            elem = next;
            next = elem->next;
        }

        while(num > 0){
            next = elem;
            elem = next->prev;
            free(next);
            num--;
        }

        free(list);
    }
}

void destroyNode(node_p node)
{
    if(node)
    {
        destroyAdjList(node->parents);
        destroyAdjList(node->children);
        free(node);
    }

    return;
}

/*Destroys the graph*/
void destroyGraph(graph_p graph)
{
    if(graph)
    {
        if(graph->nodes_list)
        {
            destroyAdjList(graph->nodes_list);
        }
        /*Free the graph*/
        free(graph);
    }
}

void addNode(graph_t *graph, node_p* node_parents, int numparents, char** name, char** content)
{
    adjlist_p parents; /*Parents list*/
    adjlist_p children; /*Children list*/
    list_elem_p parent_element; /*Element for the parents list*/
    list_elem_p children_element; /*Element for the children list*/
    list_elem_p graph_element;
    node_p new_node;
    list_elem_p aux;
    int i, jump;

    parents = (adjlist_p)malloc(sizeof(adjlist_t));
    if(!parents){
        destroyGraph(graph);
        exit(1);
    }

    children = (adjlist_p)malloc(sizeof(adjlist_t));
    if(!children){
        free(parents);
        destroyGraph(graph);
        exit(1);
    }

    new_node = (node_p)malloc(sizeof(node_t));
    if(!new_node){
        free(parents);
        free(children);
        destroyGraph(graph);
        exit(1);
    }

    parent_element = (list_elem_p)malloc(sizeof(list_elem_t));
    if(!parent_element){
        free(new_node);
        free(parents);
        free(children);
        destroyGraph(graph);
        exit(1);
    }

    children_element = (list_elem_p)malloc(sizeof(list_elem_t));
    if(!children_element){
        free(parent_element);
        free(new_node);
        free(parents);
        free(children);
        destroyGraph(graph);
        exit(1);
    }

    graph_element = (list_elem_p)malloc(sizeof(list_elem_t));
    if(!graph_element){
        free(children_element);
        free(parent_element);
        free(new_node);
        free(parents);
        free(children);
        destroyGraph(graph);
        exit(1);
    }

    /*Filling the new node*/
    new_node -> name = name;
    new_node -> content = content;
    
    /*Adding the node to the graph*/
    graph_element -> node = new_node;

    for(i = 0; i < numparents; i++) {
        /*Adding the parents to the node's parents list*/
        parent_element = (list_elem_p)malloc(sizeof(list_elem_t));
        if(!parent_element){
            destroyAdjList(parents);
            destroyAdjList(children);
            free(new_node);
            free(children);
            destroyGraph(graph);
            exit(1);
        }

        parent_element -> node = *(node_parents + jump);
        parent_element -> next = parents -> head;
        parents -> head -> prev = parent_element;
        parent_element -> prev = NULL;
        parents -> head = parent_element;

        parents -> num_members ++;

        /*Adding the node to its parents' children list*/
        children_element = (list_elem_p)malloc(sizeof(list_elem_t));
        if(!parent_element){
            destroyAdjList(parents);
            destroyAdjList(children);
            free(new_node);
            free(children);
            destroyGraph(graph);
            exit(1);
        }
        children_element -> node = *(node_parents + jump);
        children_element -> next = children -> head;
        children -> head -> prev = children_element;
        children_element -> prev = NULL;
        children -> head = children_element;
        children -> num_members ++;


        jump ++;
        
    }

    aux = graph->nodes_list->head;
    graph->nodes_list->head = graph_element;
    graph_element -> next = aux;
    aux -> prev = graph_element;
    graph -> nodes_list -> num_members ++;

    children_element->node = new_node;
    children_element->prev = NULL;

    graph->num_nodes ++;

    return;
}

void displayAdjlist(adjlist_p list)
{
    list_elem_p elem = list->head;
    list_elem_p next = elem->next;

    while(elem){
        printf("%s || ", *(elem->node->name));
        elem = next;
        next = elem->next;
    }
}

/* Function to print the adjacency list of graph*/
void displayGraph(graph_p graph)
{
    list_elem_p elem = graph->nodes_list->head;
    list_elem_p next = elem->next;

    if(!elem)
    {
        printf("Empty graph.\n");
    }

    while(elem){
        printf("Node %s:\nParents: ", *(elem->node->name));
        displayAdjlist(elem->node->parents);
        elem = next;
        next = elem->next;
    }
}
