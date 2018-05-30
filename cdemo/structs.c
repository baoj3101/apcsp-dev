#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {

	char firstName[50];
	char lastName[50];
	int  age;
	int  id;
};

int printStudent (struct Student* student) {
	printf ("First Name : %s\n", student->firstName);
	printf ("Last Name  : %s\n", student->lastName);
	printf ("Age        : %d\n", student->age);
	printf ("ID         : %d\n", student->id);
}

int main (int argc, char* argv[]) {

	struct Student students[100];

	// use command line to enter student info using quadruples 
	if (argc < 5 || argc % 4 != 1) {
		printf ("Usage: run <firstName lastName age id> ...\n");
		exit (1);
	}
	
	int N = (argc - 1) / 4;
	for (int i = 0; i < N; i++) {
		int j = i*4+1;
		strcpy(students[i].firstName, argv[j]);
		strcpy(students[i].lastName, argv[j+1]);
  		students[i].age       = atoi(argv[j+2]);
		students[i].id        = atoi(argv[j+3]);
		printStudent(&students[i]);
	}
}
