//
// Created by titouan on 12/10/23.
//
#include <stdio.h>
#include <stdlib.h>


int main() {
	int dim = 20;

	int max = 1788696;
	int product;

	int **lines = calloc(dim, sizeof(int*));

	FILE *fptr;
	fptr = fopen("misc/challenge_011.txt","r");

	char *nb_str = malloc(2 * sizeof(char));

	for (int i = 0; i < dim; i++) {
		*(lines + i) = calloc(dim, sizeof(int));
		for (int j = 0; j < dim; j++) {
			fscanf(fptr, "%s ", nb_str);
			*(*(lines + i) + j) = atoi(nb_str);
		}
	}

	fclose(fptr);

	for (int i = 0; i < dim; i++) {
		for (int j = 0; j < dim; j++) {
			if (i <= dim - 4) {
				product = *(*(lines + i) + j) * *(*(lines + i+1) + j) * *(*(lines + i+2) + j) * *(*(lines + i+3) + j);
				if (product > max) {
					max = product;
				}
				if (j <= dim - 4) {
					product = *(*(lines + i) + j) * *(*(lines + i+1) + j+1) * *(*(lines + i+2) + j+2) * *(*(lines + i+3) + j+3);
					if (product > max) {
						max = product;
					}
					product = *(*(lines + i) + j) * *(*(lines + i) + j+1) * *(*(lines + i) + j+2) * *(*(lines + i) + j+3);
					if (product > max) {
						max = product;
					}
					if (i >= 3) {
						product = *(*(lines + i) + j) * *(*(lines + i-1) + j+1) * *(*(lines + i-2) + j+2) * *(*(lines + i-3) + j+3);
						if (product > max) {
							max = product;
						}
					}
				}
			}
			else if (j <= dim - 4) {
				product = *(*(lines + i) + j) * *(*(lines + i) + j+1) * *(*(lines + i) + j+2) * *(*(lines + i) + j+3);
				if (product > max) {
					max = product;
				}
			}
		}
	}



	printf("Answer : %d\n", max);

	return EXIT_SUCCESS;
}

