#include <stdio.h>
#include <stdlib.h>

void print_numbers(int* nump) {
	int i = 0, jump=0;

	for(i=0; i<5; i++){
		printf("%d, ", *(nump + jump));
		jump ++ ;
	}
}

int main() {
	int numbers[5] = {1,2,3,4,5};

	print_numbers(numbers);

	return 0;
}