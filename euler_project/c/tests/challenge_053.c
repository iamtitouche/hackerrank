//
// Created by titouan on 18/10/23.
//
#include <stdio.h>
#include <stdlib.h>
#include "binomial.h"


int main(int argc, char **argv) {
	if (argc != 2) {
		printf("One int argument needed");
		return EXIT_FAILURE;
	}
	int n_max = atoi(argv[1]);

	int count = 0;

	ulong binomial_coef;

	for (int n = 1; n <= n_max; n++) {
		for (int r = 2; r <= n / 2; r++) {
			binomial_coef = binomial_coefficient(r, n);
			if (binomial_coef > 1000000) {
				if (2 * r == n) {
					count++;
				}
				else {
					count += 2;
				}
			}
		}
	}

	printf("Answer : %d\n", count);

	return EXIT_SUCCESS;
}