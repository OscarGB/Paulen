#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>

#include "hash_table.h"
#include "prime.h"


/* Elemento de la tabla hash */
typedef struct _ht_item {
	char* key; // Clave por la que buscar
	void* value; // Valor almacenado
}ht_item;

/* Tabla hash */
struct  _ht_hash_table {
	char name[100]; // Nombre
	int size; // Tamaño
	int count; // Numero de elementos dentro de la tabla
	int base_size; // Numero base de elementos
	ht_item** items; // Tabla
};

/* Item to mark as deleted */
static ht_item HT_DELETED_ITEM = {NULL, NULL};

/* Delete a *ht_item* */
static void ht_del_item(ht_item* i) {
	if(i == &HT_DELETED_ITEM) 
		return;
	if(i!=NULL && i->key!=NULL){
		free(i->key); 
		i->key=NULL;
	}
	if(i!=NULL){ 
		free(i); 
		i=NULL;
	}
}

/* Create a new *ht_item*, makes a copy of k and v to prevent modification */
static ht_item* ht_new_item(char* k, void* v) {
	ht_item* i = NULL;
	i = malloc(sizeof(ht_item));
	if(!i) return NULL; // Check errors malloc
	i->key = NULL;
	i->value = NULL;
	i->key = strdup(k); // Check errors strdup (inside malloc)
	if(!i->key){
		ht_del_item(i);
		return NULL;
	}
	i->value = v;
	return i;
}

/* Generic hash function */
static int ht_hash(char* s, int a, int m) {
	long hash = 0;
	int len_s = strlen(s);
	for (int i = 0; i < len_s; i++) {
		hash += (long)pow(a, len_s - (i+1)) * s[i];
		hash = hash % m;
	}
	return (int)hash;
}

/* Hash function for an element, performs the double hashing */
static int ht_get_hash(char* s, int num_buckets, int attempt) {
	int hash_a = ht_hash(s, HT_PRIME_1, num_buckets);
	int hash_b = ht_hash(s, HT_PRIME_2, num_buckets);
	return (hash_a + (attempt * (hash_b + 1))) % num_buckets;
}

/* Creates a *ht* of certain size */
static ht_hash_table* ht_new_sized(int base_size, char* name) {
	ht_hash_table* ht = malloc(sizeof(ht_hash_table));
	strcpy(ht->name, name);
	if(!ht) return NULL;
	ht->base_size = base_size;

	ht->size = next_prime(ht->base_size);

	ht->count = 0;
	ht->items = calloc((size_t)ht->size, sizeof(ht_item*));
	if(!ht->items) free(ht);
	return ht;
}

/* Resize a *ht* */
static void ht_resize(ht_hash_table* ht, int base_size) {
	if (base_size < HT_INITIAL_BASE_SIZE) {
		return;
	}
	ht_hash_table* new_ht = ht_new_sized(base_size, ht->name);
	if(!new_ht) return;
	for (int i = 0; i < ht->size; i++) {
		ht_item* item = ht->items[i];
		if (item != NULL && item != &HT_DELETED_ITEM) {
			ht_insert(new_ht, item->key, item->value);
		}
	}

	ht->base_size = new_ht->base_size;
	ht->count = new_ht->count;

	// To delete new_ht, we give it ht's size and items 
	int tmp_size = ht->size;
	ht->size = new_ht->size;
	new_ht->size = tmp_size;

	ht_item** tmp_items = ht->items;
	ht->items = new_ht->items;
	new_ht->items = tmp_items;

	ht_del_hash_table(new_ht);
}

/* Resize to double the size of *ht* */
static void ht_resize_up(ht_hash_table* ht) {
	int new_size = ht->base_size * 2;
	ht_resize(ht, new_size);
	
}

/* Resize to half the size of *ht* */
static void ht_resize_down(ht_hash_table* ht) {
	
	int new_size = ht->base_size / 2;
	ht_resize(ht, new_size);
	
}

/* Delete a *ht_hash_table* */
void ht_del_hash_table(hash_table_p ht) {
	for (int i = 0; i < ht->size; i++) { // Delete items
		ht_del_item(ht->items[i]);
	}
	free(ht->items);
	free(ht);
	ht = NULL;
}

/* Create a *ht_hash_table* */
ht_hash_table* ht_new(char* name) {
	return ht_new_sized(HT_INITIAL_BASE_SIZE, name);
}

/* Insert an element to *ht* with *key* and *value* */
void ht_insert(hash_table_p ht, char* key, void* value) {

	
	ht_item* item = ht_new_item(key,  value);
	int index = ht_get_hash(item->key, ht->size, 0);
	ht_item* cur_item = ht->items[index];
	int i = 0;
	while (cur_item != NULL && cur_item != &HT_DELETED_ITEM) {
		if (cur_item != &HT_DELETED_ITEM) { // Update a hash key with another value
			if (strcmp(cur_item->key, key) == 0) {
				ht_del_item(cur_item);
				ht->items[index] = item;
				
				return;
			}
		}
		index = ht_get_hash(item->key, ht->size, i);
		cur_item = ht->items[index];
		i++;
	}
	ht->items[index] = item;
	ht->count++;
	int load = ht->count * 100 / ht->size;
	if (load > 70) {
		ht_resize_up(ht);
	}
	
}

/* Search for a *key* in *ht* and return its *value* */
void* ht_search(hash_table_p ht, char* key) {
	int index = ht_get_hash(key, ht->size, 0);
	ht_item* item = ht->items[index];
	int initial_index = index;
	int i = 1;
	while (item != NULL) {
		if (item != &HT_DELETED_ITEM) {
			if (strcmp(item->key, key) == 0) {
				return item->value;
			}
		}   
		index = ht_get_hash(key, ht->size, i);
		if(initial_index == index){
			return NULL;
		}
		item = ht->items[index]; // If an item is NULL stop
		i++;
	} 
	return NULL;
}

/* Delete a *key* from *ht* */
void ht_delete(hash_table_p ht, char* key) {
	
	int index = ht_get_hash(key, ht->size, 0);
	int initial_index = index;
	ht_item* item = ht->items[index];
	int i = 0;
	while (item != NULL) {
		if (item != &HT_DELETED_ITEM) {
			
			if (strcmp(item->key, key) == 0) {
				
				int load = ht->count * 100 / ht->size;
				if (load < 10) {
					ht_resize_down(ht);
				}             
				ht_del_item(item);
				
				ht->items[index] = &HT_DELETED_ITEM; // Mark as deleted
				break;
			}
		}
		index = ht_get_hash(key, ht->size, i);
		if(index == initial_index){
			return;
		}
		item = ht->items[index];
		i++;
	} 
	ht->count--;
	
}

/* Prints a *ht* */
void ht_print_table(hash_table_p ht){
	if(!ht){
		printf("La tabla es NULL\n");
	}
	for(int i = 0; i < ht->size; i++){
		ht_item*  item = ht->items[i];
		if(item == &HT_DELETED_ITEM){
			printf("Hueco borrado\n");
		}
		else if (item != NULL){
			printf("Elemento con clave %s\n", item->key);
		}
		else{
			printf("Hueco vacio\n");
		}
	}
}

/*Checks if a key is present in the hash table*/
int ht_isin(hash_table_p ht, char* key){
	int index = ht_get_hash(key, ht->size, 0);
	ht_item* item = ht->items[index];
	int initial_index = index;
	int i = 1;
	while (item != NULL) {
		if (item != &HT_DELETED_ITEM) {
			if (strcmp(item->key, key) == 0) {
				return 1;
			}
		}   
		index = ht_get_hash(key, ht->size, i);
		if(initial_index == index){
			return 0;
		}
		item = ht->items[index]; // If an item is NULL stop
		i++;
	} 
	return 0;
}


/*Gets all keys, REMEMBER to free keys but not the items inside
last pointer is NULL*/
char** ht_get_keys(hash_table_p ht){
	char** keys = (char**)malloc(sizeof(char*)*(ht->size+1));
	int j = 0;
	for(int i = 0; i < ht->size; i++){
		ht_item*  item = ht->items[i];
		if(item == &HT_DELETED_ITEM){
			continue;
		}
		else if (item != NULL){
			keys[j] = item->key;
			j++;
		}
		else{
			continue;
		}
	}
	keys[j] = NULL;
	return keys;
}