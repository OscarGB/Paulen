#include "hash_table.h"
#include <stdio.h>
#include <string.h>

#define FREEHT\
	if(ht!=NULL){ ht_del_hash_table(ht); ht=NULL;}

int main() {
	ht_hash_table* ht = ht_new();
	if(!ht){
		printf("ERROR al crear la tabla\n");
		return 1;
	}

	char keys[12][20] = {"a", "b", "c", "d", "e", "hola", "arbol", "arbusto", "8569", "874222", "874521", "54121318"};
	char values[12][20] = {"va", "vb", "vc", "vd", "ve", "vhola", "varbol", "varbusto", "v8569", "v874222", "v874521", "v54121318"};

	int i;

	for(i = 0; i < 12; i++){
		ht_insert(ht, keys[i], (void *)values[i]);
	}
	for(i = 0; i < 12; i++){
		char* a = (char *)ht_search(ht, keys[i]);
		if(a != NULL && values[i]!=a/* != 0*/){
			printf("ERROR, no se ha encontrado un elemento insertado\n");
			FREEHT
			return -1;
		}
	}
	printf("Todos los elementos han sido insertados\n");
	for(i = 0; i < 5; i++){
		ht_delete(ht, keys[i]);
	}
	for(i = 0; i < 5; i++){
		if(ht_search(ht, keys[i]) != NULL){
			printf("ERROR, se ha encontrado un elemento eliminado\n");
			FREEHT
			return -1;
		}
	}
	printf("Todos los elementos han sido eliminados\n");

	FREEHT
	printf("OK\n");
	return 0;

}

#undef FREEHT


