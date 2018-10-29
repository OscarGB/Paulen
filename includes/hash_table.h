#ifndef HASH_H
#define HASH_H

#define HT_INITIAL_BASE_SIZE 7 // Base size for the HT
#define HT_PRIME_1 379 // Prime 1 for hashing
#define HT_PRIME_2 461 // Prime 2 for hashing

typedef struct _ht_hash_table ht_hash_table, *hash_table_p;

/* Create a *ht_hash_table* */
hash_table_p ht_new(char* name);

/* Delete a *ht_hash_table* */
void ht_del_hash_table(hash_table_p ht);

/* Insert an element to *ht* with *key* and *value* */
void ht_insert(hash_table_p ht, char* key, void* value);

/* Search for a *key* in *ht* and return its *value* */
void* ht_search(hash_table_p ht, char* key);

/*Checks if a key is present in the hash table*/
int ht_isin(hash_table_p ht, char* key);

/* Delete a *key* from *ht* */
void ht_delete(hash_table_p h, char* key);

/* Prints a hash table */
void ht_print_table(hash_table_p ht);

/*Gets all keys, REMEMBER to free keys but not the items inside
last pointer is NULL*/
char** ht_get_keys(hash_table_p ht);

#endif // HASH_H