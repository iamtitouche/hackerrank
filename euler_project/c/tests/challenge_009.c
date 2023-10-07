//
// Created by titouan on 07/10/23.
//
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(int argc, char **argv) {
	if (argc != 2) {
		printf("One int argument needed");
		return EXIT_FAILURE;
	}
	int n = atoi(argv[1]);
	int a, b, c;
	int b_limit;

	for (a = 0; a <= n / 3; a++) {
		b_limit = (1000 - a) / 2;

		for (b = a + 1; b <= b_limit; b++) {

			c = (int) pow(a*a + b*b, 0.5);

			if (c > b && a + b + c == n && a*a + b*b == c*c) {
				int product = a * b * c;
				printf("Answer : %d\n", product);
				return EXIT_SUCCESS;
			}
		}
	}

	return EXIT_SUCCESS;
}
