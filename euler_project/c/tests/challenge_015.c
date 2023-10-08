//
// Created by titouan on 08/10/23.
//
#include <stdio.h>
#include <stdlib.h>
#include "binomial.h"


int main(int argc, char **argv) {
	if (argc != 2) {
		printf("One int argument needed smaller than 50");
		return EXIT_FAILURE;
	}
	int n = atoi(argv[1]);

	ulong result = binomial_coefficient(n / 2, n);

	printf("Answer : %ld\n", result);

	return EXIT_SUCCESS;
}
