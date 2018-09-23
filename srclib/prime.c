#include <math.h>

#include "prime.h"

/* Checks if a number is prime :
	1 -> prime
	0 -> not prime
	-1 undefine (<2)
*/
int is_prime(const int x) {
	if (x < 2) { return -1; }
	if (x < 4) { return 1; }
	if ((x % 2) == 0) { return 0; }
	for (int i = 3; i <= floor(sqrt((double) x)); i += 2) {
		if ((x % i) == 0) {
			return 0;
		}
	}
	return 1;
}

/* Gets the next prime number starting in *x*, if *x* is prime, return *x* */
int next_prime(int x) {
	while (is_prime(x) != 1) {
		x++;
	}
	return x;
}