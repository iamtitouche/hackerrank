//
// Created by titouan on 18/10/23.
//
//
// Created by titouan on 12/05/23.
//
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "divisors.h"


int main(int argc, char **argv) {
	if (argc != 2) {
		printf("One int argument needed");
		return EXIT_FAILURE;
	}
	int max = atoi(argv[1]);

	int tot_sum = 0, b;

	for (int a = 1; a <= max; a++) {
		b = sum_of_proper_divisors(a);
		if (b > a && sum_of_proper_divisors(b) == a) {
			tot_sum += a + b;
		}
	}

	printf("Answer : %d\n", tot_sum);

	return EXIT_SUCCESS;
}