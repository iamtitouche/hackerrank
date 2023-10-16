//
// Created by titouan on 16/10/23.
//
#include <stdlib.h>
#include <stdio.h>
#include "polynom.h"
#include "prime.h"

int main(int argc, char **argv) {
	if (argc != 2) {
		printf("One int argument needed");
		return EXIT_FAILURE;
	}

	int ab_max = atoi(argv[1]);
	integer_polynomial *pol = malloc(sizeof(integer_polynomial));
	pol->degree = 2;
	pol->coef = malloc((pol->degree + 1) * sizeof(int));
	pol->coef[2] = 1;

	bool *prime_bool = prime_list(1000000);
	int prime_limit = 1000000;
	int max_count = 0;
	int best_a = 0, best_b = 0;

	for (int b = 2; b < ab_max; b++) {
		if (prime_bool[b]) {
			pol->coef[0] = b;
			for (int a = -ab_max + 1; a < ab_max; a++) {
				pol->coef[1] = a;
				int n = 0, count = 0;
				int n_test = (int) int_pol_evaluate((float) n, pol);
				if (n_test > prime_limit) {
					prime_list_from_previous_list(n_test, prime_limit, prime_bool);
					prime_limit = n_test;
				}
				while (n_test > 0 && prime_bool[n_test]) {
					count++;
					n++;
					n_test = (int) int_pol_evaluate(n, pol);
					if (n_test > prime_limit) {
						prime_list_from_previous_list(n_test, prime_limit, prime_bool);
						prime_limit = n_test;
					}
				}
				if (max_count < count) {
					max_count = count;
					best_a = a;
					best_b = b;
				}
			}
		}
	}

	printf("Answer : %d\n", best_a * best_b);

	return EXIT_SUCCESS;
}