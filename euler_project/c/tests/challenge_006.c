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

	int sum = 0, sum_of_squares = 0, n = atoi(argv[1]);

	for (int i = 0; i <= n; i++) {
		sum += i;
		sum_of_squares += pow(i, 2);
	}

	int result = (int) pow(sum, 2) - sum_of_squares;
	printf("Answer : %d\n", result);

	return EXIT_SUCCESS;
}
