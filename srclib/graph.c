#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graph.h"
#include "padres.h"

/* Function to create a graph with n vertices; Creates both directed and undirected graphs*/
graph_p createGraph(char* input)
{
    graph_p graph = (graph_p)malloc(sizeof(graph_t));
    if(!graph) {
        exit(1);
    }
    graph->num_nodes = 0;
    graph->nodes_list = (adjlist_p)malloc(sizeof(adjlist_t));
    if(!graph->nodes_list){
        free(graph);
        exit(1);
    }

    graph->name = (char*)malloc(strlen(input)*sizeof(char)+1);

    strcpy(graph->name, input);

    if(!(graph->nodes_hash_table = ht_new(""))){
        free(graph->name);
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

    while(elem!=NULL){
        next = elem->next;
        destroyNode(elem->node);
        free(elem);
        elem=next;
    }
    free(list);
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

void destroyArrays(node_p node){
    int i;
    char* aux;
    if(node->ms){
        for(i = 0; i < node->num_ms; i++ ){
            free(node->ms[i]);
        }
        free(node->ms);
        node->ms = NULL;
    }
    if(node->mns){
        for(i = 0; i < node->num_mns; i++ ){
            free(node->mns[i]);
        }
        free(node->mns);
        node->mns = NULL;
    }
    if(node->ac){
        for(i = 0; i < node->num_ac; i++ ){
            free(node->ac[i]);
        }
        free(node->ac);
        node->ac = NULL;
    }
    if(node->ai){
        for(i = 0; i < node->num_ai; i++ ){
            free(node->ai[i]);
        }
        free(node->ai);
        node->ai = NULL;
    }
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
        destroyArrays(node);
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
        free(graph->name);
        free(graph);
    }
}

node_p addNode(graph_t *graph, node_p* node_parents, int numparents, char* name)
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
    new_node -> parents = parents;
    new_node -> children = children;
    new_node -> principal = ht_new(name);
    new_node -> local = NULL;
    
    char* nombres_padres[numparents+1];
    for(i = 0; i < numparents;i++){
        nombres_padres[i] = node_parents[i]->name;
    }
    new_node-> padres = get_padres(graph, nombres_padres, numparents);
    new_node->numparents = numparents;

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
        graph->nodes_list->head->next = aux;
        aux -> prev = graph_element;
        graph -> nodes_list -> num_members ++;
    }

    new_node->num_ms = 0;
    new_node->num_mns = 0;
    new_node->num_ac = 0;
    new_node->num_ai = 0;

    new_node->ms = NULL;
    new_node->mns = NULL;
    new_node->ac = NULL;
    new_node->ai = NULL;

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
    if(node->local) ht_del_hash_table(node->local); //En principio no seria necesario
    node -> local = ht_new(name);
}

void deleteHTLocal(graph_p graph, char* key){
    node_p node = searchNode(graph, key);
    ht_del_hash_table(node->local);
    node -> local = NULL;
}

/*Devuelve el nombre del ambito principal, a no ser que exista el ambito local*/
char * getAmbito(node_p node){
    if(node->local) {
        return ht_get_name(node->local);
    }
    else
        return ht_get_name(node->principal);
}


node_p getINode(graph_p graph, int indice){
    list_elem_p elem = graph->nodes_list->head;
    for(int i = 1; i < indice; i++){
        elem = elem->next;
    }
    return elem->node;
}


int getIndex(graph_p graph, char* key){
    list_elem_p elem = graph->nodes_list->head;
    int i = 0;
    while(elem != NULL){
        i++;
        if(!strcmp(key, elem->node->name)){
            return i;
        }
        elem = elem->next;
    }
    return ERROR;
}

