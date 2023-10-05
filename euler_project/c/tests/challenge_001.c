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
	int n = atoi(argv[1]);
	int sum = 3 * ((n-1) / 3) * ((n-1) / 3 + 1) / 2;
	sum += 5 * ((n-1) / 5) * ((n-1) / 5 + 1) / 2;
	sum -= 15 * ((n-1) / 15) * ((n-1) / 15 + 1) / 2;

	printf("Answer : %i", sum);

	return EXIT_SUCCESS;
}