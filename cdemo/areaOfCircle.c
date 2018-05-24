#include <stdio.h>

double areaofcircle (double r) {

	return 3.14 * r * r;
}

int main() {

	double r = 0;

	for (r = 3.5; r <= 12.5; r=r+0.5) {

		double a = areaofcircle (r);
		printf("the area of a circle with radius %6.2f is %6.2f\n", r, a);

	}
}
