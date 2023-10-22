//
// Created by titouan on 21/10/23.
//
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int score(char *name) {
	int i = 0;
	int score = 0;
	while (*(name + i) != '\0') {
		score += (int) *(name + i) - 64;
		i++;
	}
	return score;
}


int main() {
	FILE *fptr;
	fptr = fopen("misc/challenge_022.txt","r");

	size_t size = 6000;
	char *names[size];
	names[0] = malloc(sizeof(char));

	int i = 0;
	while (fscanf(fptr, "\"%[ABCDEFGHIJKLMNOPQRSTUVWXYZ]\", ", names[i]) == 1) {
		i++;
		*(names + i) = malloc(sizeof(char));
	}

	fclose(fptr);

	for (int a = 0; a < i - 1; a++) {
		for (int b = 0; b < i - a - 1; b++) {
			if (strcmp(names[b], names[b + 1]) > 0) {
				char *tmp = names[b];
				names[b] = names[b + 1];
				names[b + 1] = tmp;
			}
		}
	}

	int total = 0;

	for (int j = 0; j < i; j++) {
		total += score(names[j]) * (j + 1);
	}


	printf("Answer : %i", total);

	return EXIT_SUCCESS;
}
