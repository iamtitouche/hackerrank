//
// Created by titouan on 07/10/23.
//
#include <stdio.h>
#include <stdlib.h>
#include "prime.h"

int main(int argc, char **argv) {
	if (argc != 2) {
		printf("One int argument needed");
		return EXIT_FAILURE;
	}
	int n = atoi(argv[1]);
	ulong sum = 0;
	bool *indexes_are_primes = prime_list(n);

	for (int i = 0; i <= n; i++) {
		if (indexes_are_primes[i]) {
			sum += i;
		}
	}

	printf("Answer : %ld\n", sum);

	return EXIT_SUCCESS;
}
