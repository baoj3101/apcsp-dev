#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long ull;

ull n = 0;	// p*q
ull e = 0;	// public key
ull d = 0;	// private key

// check if the give number is a prime number or not
// return 1 if yes
// return 0 if no
int is_prime (ull n) {

	if (n%2 == 0) { 
		return n == 2;
	}
	if (n%3 == 0) { 
		return n == 3;
	}
	ull p = 5;
	while (p*p <= n) {
		if (n%p == 0) return 0;
		p += 2;
		if (n%p == 0) return 0;
		p += 4;
	}
	return 1;
}

// generate a large random prime number within the range [lower, upper]
ull rand_prime () {

	ull lower =  1000000;
	ull upper = 10000000;
	ull range = upper - lower + 1;

	while (1) {
		ull  r = 1 | (rand() % range + lower);

		if (is_prime(r)) {
			return r;
		}
	}
}

// generate rsa keys
ull gcd (ull a, ull b) {

	int rem = 0;
	while (1) {
		rem = a % b;
		if (rem == 0) {
			return b;
		}

		a = b;
		b = rem;
	}
}

int gen_rsa_keys (ull p, ull q) {

	n = p * q;
	ull phi = (p - 1) * (q - 1);

	// public key
	e = 1000;
	while (1) {
		if (gcd (e, phi) == 1) {
			break;
		}
		e++;
	}
	printf ("public key e = %llu\n", e);
	// private key
	ull k = 1;
	while (1) {
		k = k + phi;
		if (k % e == 0) {
			d = k / e;
			break;
		}
	}
	printf ("private key d = %llu\n", d);

}


// this is the main function with the following usage:
// run <random seed> <text to be encrypted>
int main (int argc, char* argv[]) {
	if (argc != 3) {

		printf ("usage: run <random seed> <text to be encrypted>\n");
		exit (1);
	}

	int randseed = atoi (argv[1]);
	char* msg = argv[2];

	// set random seed
	srand (randseed);

	// pick p and q
	ull p = rand_prime ();
	ull q = rand_prime ();
	
	printf ("prime number p = %llu\n", p);
	printf ("prime number q = %llu\n", q);

	gen_rsa_keys (p, q);

}
