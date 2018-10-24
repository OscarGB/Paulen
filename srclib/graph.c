#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graph.h"
#include "padres.h"

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

    if(!(graph->nodes_hash_table = ht_new(""))){
        free(graph->nodes_list);
        free(graph);
        exit(1);
    }


    graph -> nodes_list -> head = NULL;
    graph -> nodes_list -> num_members = 0;


    return graph;
}

/*Destroys an adjList from the last element*/
void destroyAdjList(adjlist_p list)
{
    list_elem_p elem = list->head;
    list_elem_p next = NULL;
    int num = list->num_members;

    if(elem)
        next = elem -> next;

    if(list -> num_members > 0){
        while(next){
            elem = next;
            next = elem->next;
        }

        while(num > 0){
            next = elem;
            elem = next->prev;
            if(next->node)
                destroyNode(next->node);
            free(next);
            num--;
        }
        if(elem->node){
            destroyNode(elem->node);
        }
        free(elem);
        free(list);
    }
}

void destroyRelatives(adjlist_p list){
    list_elem_p elem = list->head;
    list_elem_p next = NULL;
    int num = list->num_members;

    if(elem)
        next = elem -> next;

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

    }
    free(list);
}

void destroyNode(node_p node)
{
    if(node)
    {
        if(node->local)
            ht_del_hash_table(node->local);
        if(node->principal)
            ht_del_hash_table(node->principal);
        if(node->parents)
            destroyRelatives(node->parents);
        if(node->children)
            destroyRelatives(node->children);
        if(node->padres)
            free(node->padres);
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
        ht_del_hash_table(graph->nodes_hash_table);
        /*Free the graph*/
        free(graph);
    }
}

node_p addNode(graph_t *graph, node_p* node_parents, int numparents, char* name, char* content)
{
    adjlist_p parents; /*Parents list*/
    adjlist_p children; /*Children list*/
    list_elem_p parent_element = NULL; /*Element for the parents list*/
    list_elem_p children_element = NULL; /*Element for the children list*/
    list_elem_p graph_element;
    node_p new_node;
    list_elem_p aux;
    int i, jump=0;

    parents = (adjlist_p)malloc(sizeof(adjlist_t));
    if(!parents){
        destroyGraph(graph);
        exit(1);
    }
    parents -> num_members = 0;
    parents -> head = NULL;

    children = (adjlist_p)malloc(sizeof(adjlist_t));
    if(!children){
        free(parents);
        destroyGraph(graph);
        exit(1);
    }

    children -> num_members = 0;
    children -> head = NULL;

    new_node = (node_p)malloc(sizeof(node_t));
    if(!new_node){
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
    strcpy(new_node->name, name);
    strcpy(new_node->content, content);
    new_node -> parents = parents;
    new_node -> children = children;
    new_node -> principal = ht_new(name);
    new_node -> local = NULL;
    
    char* nombres_padres[numparents];
    for(i = 0; i < numparents;i++){
        nombres_padres[i] = node_parents[i]->name;
    }
    new_node-> padres = get_padres(graph, nombres_padres, numparents);

    /*Adding the node to the graph*/
    graph_element -> node = new_node;

    graph_element -> node -> parents = parents;
    graph_element -> node -> children = children;

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

        if(!parents->head) {
            parents->head = parent_element;
            parent_element -> next = NULL;
            parent_element -> prev = NULL;
        }

        else {
            parent_element -> next = parents -> head;
            parents -> head -> prev = parent_element;
            parent_element -> prev = NULL;
            parents -> head = parent_element;
        }


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

        if(!children->head) {
            children->head = children_element;
            children_element -> next = NULL;
            children_element -> next = NULL;
        }

        else {
            children_element -> next = children -> head;
            children -> head -> prev = children_element;
            children_element -> prev = NULL;
            children -> head = children_element;
        }
        children -> num_members ++;

        jump ++;
        
    }

    if(!graph->nodes_list->head){
        graph->nodes_list->head = graph_element;
        graph->nodes_list->head->next = NULL;
        graph->nodes_list->head->prev = NULL;
    }
    else {
        aux = graph->nodes_list->head;
        graph->nodes_list->head = graph_element;
        graph_element -> next = aux;
        aux -> prev = graph_element;
        graph -> nodes_list -> num_members ++;
    }

    ht_insert(graph -> nodes_hash_table, new_node -> name, new_node);

    // children_element->node = new_node;
    // children_element->prev = NULL;

    graph->num_nodes ++;

    return new_node;
}

void displayAdjlist(adjlist_p list)
{
    list_elem_p elem = list->head;
    list_elem_p next = elem->next;


    while(elem){
        printf("%s || ", elem->node->name);
        elem = next;
        if(elem)
            next = elem->next;
    }
    printf("\n");
}

/* Function to print the adjacency list of graph*/
void displayGraph(graph_p graph)
{
    list_elem_p elem = graph->nodes_list->head;
    list_elem_p next = NULL;

    if(!elem)
    {
        printf("Empty graph.\n");
        return;
    }

    next = elem->next;


    while(elem){

        printf("Node %s:\nParents: ", elem->node->name);

        if(elem->node->parents->num_members > 0)
            displayAdjlist(elem->node->parents);
        else
            printf("None\n");

        int i = 0;

        if(elem->node->padres != NULL){
            printf("Padres ordenados:");
            while(elem->node->padres[i] != NULL){
                printf("%s ", elem->node->padres[i]);
                i++;
            }
            printf("\n");
        }

        elem = next;
        if(next)
            next = elem->next;
    }

}

node_p searchNode(graph_p graph, char* key){
    return ht_search(graph->nodes_hash_table, key);
}


hash_table_p getHT(graph_p graph, char* key, int tipo){
    node_p node = searchNode(graph, key);
    if(tipo == PRINCIPAL)
        return node->principal;
    else{
        return node->local;
    }
}

void createHTLocal(graph_p graph, char* key, char* name){
    node_p node = searchNode(graph, key);
    node -> local = ht_new(name);
}

void deleteHTLocal(graph_p graph, char* key, char* name){
    node_p node = searchNode(graph, key);
    ht_del_hash_table(node->local);
    node -> local = NULL;
}