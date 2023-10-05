//
// Created by titouan on 05/10/23.
//
#include <stdio.h>
#include <stdlib.h>
#include "prime.h"


int main(int argc, char **argv) {
	if (argc != 2) {
		printf("One ulong argument needed");
		return EXIT_FAILURE;
	}
	ulong n = atol(argv[1]);

	prime_factor *curr_factor = prime_factors(n);

	while (curr_factor->next != NULL) {
		curr_factor = curr_factor->next;
	}

	printf("Answer : %ld\n", curr_factor->value);

	return EXIT_SUCCESS;
}