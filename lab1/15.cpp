
/*
@author Kamil Nowak
@subject Zadanie 15 - laboratorium 1
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <cmath>

int main() {
	double x = 3.14;
	double y = 12.56;
	double z = 7.;
	int k = 2;
	int m = 4;

	double w1 = pow(x / y / z, 1. / 3) * log(pow(x, 2) + pow(y, 2));
	double w2 = sin(k * x / 2) * cos(m * y) + y * exp(2 * x - 1);
	double w3 = fabs(x / (2 * pow(y, 2) + 1)) + pow(y / (pow(z, 2) + 3), 1. / 2) + 5 * pow(y + z, 3.);
	double w4 = x / y / z * pow(z + 1, 1./3) + pow(pow(x, 2) + pow(z, 2) + 1, 1. / k) - fabs(y);
	double w5 = 1 / pow(pow(x, 2) + pow(y, 2) + pow(k, 2), 1. / 2) + 1 / x * sin(k * y);

	printf("w1 = %0.8f\nw2 = %0.8f\nw3 = %0.8f\nw4 = %0.8f\nw5 = %0.8f", w1, w2, w3, w4, w5);
}



