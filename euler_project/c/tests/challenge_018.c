//
// Created by sadount on 09/10/2023.
//
#include <stdio.h>
#include <stdlib.h>




int max(int a, int b) {
	if (a >= b) {
		return a;
	}
	return b;
}
int main() {
    FILE *fptr;
    fptr = fopen("misc/challenge_018.txt","r");


    int n_lines = 15;
    int **lines = calloc(n_lines, sizeof(int*));
    char *nb_str = malloc(2 * sizeof(char));


	for (int i = 0; i < n_lines; i++) {
		*(lines + i) = calloc(i + 1, sizeof(int));
		for (int j = 0; j <= i; j++) {
			fscanf(fptr, "%s ", nb_str);
			*(*(lines + i) + j) = atoi(nb_str);
		}
	}
	fclose(fptr);

	for (int i = n_lines - 2; i >= 0; i--) {
	    for (int j = 0; j <= i; j++) {
		    *(*(lines + i) + j) += max(*(*(lines + i + 1) + j), *(*(lines + i + 1) + j + 1));
	    }
    }

	printf("Answer : %i\n", **lines);






    return EXIT_SUCCESS;
}
