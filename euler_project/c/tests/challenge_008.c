//
// Created by titouan on 07/10/23.
//
#include <stdio.h>
#include <stdlib.h>


int main() {
	int n_lines = 20;

	FILE *fptr;
	fptr = fopen("misc/challenge_008.txt","r");

	char **lines = calloc(n_lines, sizeof(char*));


	for (int i = 0; i < n_lines; i++) {
		*(lines+i) = malloc(50 * sizeof(char));
		fscanf(fptr, "%s\n", *(lines+i));

	}

	printf("%c\n", *(*(lines + 2) + 4));



	return EXIT_SUCCESS;
}
