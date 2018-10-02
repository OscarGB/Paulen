#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_numbers(char* input) {
	char *str = input;
	int i;

	for(i=0; i<5; i++){
		printf("%s\n", str);
	}
}

int main() {
	char str[7] = "String";

	print_numbers(&str[0]);

	return 0;
}