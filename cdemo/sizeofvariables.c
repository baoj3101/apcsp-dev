#include <stdio.h>

int main () {

	int a = 10;
	printf ("Size of int is %d\n", sizeof(a));
	long int b = 10;
	printf ("Size of long int is %d\n", sizeof(b));
	unsigned int c = 10;
	printf ("Size of unsigned int is %d\n", sizeof(c));
	signed int d = 10;
	printf ("Size of signed int is %d\n", sizeof(d));
	short  int e = 10;
	printf ("Size of short int is %d\n", sizeof(e));
	char f = 'g';
	printf ("Size of char is %d\n", sizeof(f));
	float g = 3.14;
	printf ("Size of float is %d\n", sizeof(g));
	double h = 3.14;
	printf ("Size of double is %d\n", sizeof(h));
}
