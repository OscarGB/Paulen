#ifndef PRIME_H
#define PRIME_H

/* Checks if a number is prime :
	1 -> prime
	0 -> not prime
	-1 undefine (<2)
*/
int is_prime(const int x);

/* Gets the next prime number starting in *x*, if *x* is prime, return *x* */
int next_prime(int x);

#endif // PRIME_H