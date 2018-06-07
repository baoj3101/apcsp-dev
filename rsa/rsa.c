#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

//	ull lower =  1000000;
//	ull upper = 10000000;
	ull lower =  100;
	ull upper =  500;

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

	printf ("2. n = p * q which is the modulus of both the keys\n");

	n = p * q;
	printf ("   n = %llu\n", n);

	printf ("3. phi = (p - 1) * (q - 1)\n");

	ull phi = (p - 1) * (q - 1);
	printf ("   phi = %llu\n", phi);

	// public key
	printf ("4. Choose e such that e > 1 and co-prime to phi (GCD (e, phi) is 1). e is the public key.\n");
	e = 1000;
	while (1) {
		if (gcd (e, phi) == 1) {
			break;
		}
		e++;
	}
	printf ("   Public key e = %llu\n", e);

	// private key
	printf ("5. Choose d such that d * e = 1 + k * phi, d is the private key\n");
	ull k = 1;
	while (1) {
		k = k + phi;
		if (k % e == 0) {
			d = k / e;
			break;
		}
	}
	printf ("   Private key d = %llu\n", d);
}
// encrypt function
ull enc (ull m) {
	ull c = 1;
	ull i = 0;
	for (i = 0; i < e; i++) {
		c = c * m % n;
	}
	return c;
}

// decrypt function
ull dec (ull c) {
   ull m = 1;
   ull i = 0;
   for (i = 0; i < d; i++) {
      m = m * c % n;
   }
   return m;
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

	printf ("RSA Algorithm:\n");	
	printf ("1. Choose two prime numbers p and q\n");

	// pick p and q
	ull p = rand_prime ();
	ull q = rand_prime ();

	printf ("   Prime number p = %llu\n", p);
	printf ("   Prime number q = %llu\n", q);

	gen_rsa_keys (p, q);

	ull enc_msg[100];
	int i = 0;

	// encryption
	printf ("6. Encryption: cipher text is calculated using c = m ^ e mod n where m is the message\n");
	for (i = 0; i < strlen(msg); i++) {
		ull m = (ull) msg[i];
		ull c = enc (m);
		printf ("   %16c => %-16llu\n", msg[i], c);
		enc_msg[i] = c;
	}
	// decryption
	printf ("7. Decryption: to decrypt a message, c = m ^ d mod n where d is the private key\n");
	for (i = 0; i < strlen(msg); i++) {
		ull c = enc_msg[i];
		char m = (char) dec(c);
		printf ("   %16llu => %-16c\n", c, m); 
	}
}


