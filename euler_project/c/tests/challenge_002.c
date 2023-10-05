//
// Created by titouan on 05/10/23.
//
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char **argv) {
	if (argc != 2) {
		printf("One int argument needed");
		return EXIT_FAILURE;
	}

	int n_max = atoi(argv[1]);
	int a, b, sum;
	a = 1;
	b = 2;
	sum = 2;
	while (b < n_max) {
		int tmp = a + b;
		a = b;
		b = tmp;
		if (b % 2 == 0) {
			sum += b;
		}
	}

	printf("Answer : %i", sum);

	return EXIT_SUCCESS;
}
