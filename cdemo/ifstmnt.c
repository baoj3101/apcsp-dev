#include <stdio.h>

int main () {

	int a = 0;
	int b = 1;

	if (a == b) {
		printf ("a is equal to b\n");
	}

	if (a != b) {
		printf ("a is not equal to b\n");
	}

	if (a > b) {
		printf ("a is greater than b\n");
	}

	if (a >= b) {
		printf ("a is greater than or equal to b\n");
	}

	if (a == 0 && b == 0) {
		printf ("a AND b equal to 0\n");
	}

	if (a == 0 || b == 0) {
		printf ("a OR b equals to 0\n");
	}

	if (!(a == 0)) {
		printf ("NOT (a equals to 0)\n");
	}

}
