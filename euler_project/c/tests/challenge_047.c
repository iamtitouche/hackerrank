//
// Created by titouan on 23/10/23.
//
#include <stdlib.h>
#include <stdbool.h>
#include "prime.h"



int main() {
	ulong n = 2 * 3 * 5 * 7;
	int *n_factors = calloc(4, sizeof(int));

	for (int i = 0; i < 4; i++) {
		prime_factor *factors = prime_factors(n + i);
		n_factors[(n + i) % 4] = count_prime_factors(factors);
	}




	while (true) {
		bool not_solution = true;
		for (int j = 0; j < 4; j++) {
			if (n_factors[(n + j) % 4] != 4) {
				n += 1 + j;
				for (int i = 3; i >= 3 - j; i--) {
					prime_factor *factors = prime_factors(n + i);
					n_factors[(n + i) % 4] = count_prime_factors(factors);
				}
				not_solution = false;
				break;
			}
		}
		if (not_solution) {
			break;
		}
	}



	printf("Answer : %d", n);

	return EXIT_SUCCESS;
}
