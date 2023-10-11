//
// Created by titouan on 11/10/23.
//
#include <stdlib.h>
#include <stdio.h>
#include "large_integer.h"
#include "nb_string.h"

int main(int argc, char **argv) {
	if (argc != 2) {
		printf("One int argument needed");
		return EXIT_FAILURE;
	}
	int n = atoi(argv[1]);

	int sum = 0;

	for (int i = 1; i < n; i++) {
		if (palindromic_nb(i)) {
			if (palindromic_large_nb(binary_from_int(i))) {
				sum += i;
			}
		}
	}

	printf("Answer : %d \n", sum);

	return EXIT_SUCCESS;
}
