#include <stdio.h>
#include <stdlib.h>

double areaofcircle (double r) {

	return 3.14 * r * r;
}

int main(int argc, char* argv[]) {

	if (argc != 3) {
		printf ("Usage: run <min radius> <max radius>\n");
		exit (1);
	}

	// use atof to convert string to float
	double rmin = atof(argv[1]);
	double rmax = atof(argv[2]);

	double r = 0;
	for (r = rmin; r <= rmax; r=r+0.5) {

		double a = areaofcircle (r);
		printf("the area of a circle with radius %6.2f is %6.2f\n", r, a);

	}
}
