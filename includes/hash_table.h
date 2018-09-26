#ifndef HASH_H
#define HASH_H

#define HT_INITIAL_BASE_SIZE 7 // Base size for the HT
#define HT_PRIME_1 379 // Prime 1 for hashing
#define HT_PRIME_2 461 // Prime 2 for hashing

typedef struct _ht_item ht_item;
typedef struct _ht_hash_table ht_hash_table;

/* Create a *ht_hash_table* */
ht_hash_table* ht_new();

/* Delete a *ht_hash_table* */
void ht_del_hash_table(ht_hash_table* ht);

/* Insert an element to *ht* with *key* and *value* */
void ht_insert(ht_hash_table* ht, char* key, void* value);

/* Search for a *key* in *ht* and return its *value* */
void* ht_search(ht_hash_table* ht, char* key);

/* Delete a *key* from *ht* */
void ht_delete(ht_hash_table* h, char* key);

/* Prints a hash table */
void print_table(ht_hash_table* ht);

#endif // HASH_H