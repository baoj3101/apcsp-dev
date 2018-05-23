#include <stdio.h>

int main () {

	int a = 2;
	int b = 3;
	int c = a + b;

	printf ("Sum of %d and %d is %d\n", a, b, c);

	int tmp = c;
	c = a;
	a = tmp;

	printf ("Swap a and c, a = %d, c = %d\n", a, c);

}
