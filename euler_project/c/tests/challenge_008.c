//
// Created by titouan on 07/10/23.
//
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char **argv) {
	if (argc != 2) {
		printf("One int argument needed smaller than 50");
		return EXIT_FAILURE;
	}
	int n = atoi(argv[1]);
	int n_lines = 20;
	int n_columns = 50;

	FILE *fptr;
	fptr = fopen("misc/challenge_008.txt","r");

	char **lines = calloc(n_lines, sizeof(char*));


	for (int i = 0; i < n_lines; i++) {
		*(lines+i) = malloc(50 * sizeof(char));
		fscanf(fptr, "%s\n", *(lines+i));
	}

	unsigned long max = 0;

	for (int i = 0; i < n_lines * n_columns - n; i++) {
		unsigned long product = 1;
		for (int x = i; x < i + n; x++) {
			char new_digit = (char) *(*(lines + x / n_columns) + x % n_columns);
			product *= atoi(&new_digit);
		}
		if (product > max) {
			max = product;
		}
	}

	printf("Answer  : %ld\n", max);

	return EXIT_SUCCESS;
}
