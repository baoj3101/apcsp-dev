#include <stdio.h>

void arrayAdd (int* A, int s, int n) {

	for (int i = 0; i < s; i++){
		A[i] = (A[i] + n);
	}
}

int main() {

	int A[100];

	for (int i = 0; i < 100; i++) {

		A[i] = i*i;

	}

	arrayAdd (A, 100, 1);

	for (int i = 0; i < 100; i++) {
	printf ("i = %d ,  A[i] = %d\n", i, A[i]);
	}

} 
