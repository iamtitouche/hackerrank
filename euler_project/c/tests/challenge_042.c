//
// Created by titouan on 25/10/23.
//
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>


int score(char *name) {
	int i = 0;
	int score = 0;
	while (*(name + i) != '\0') {
		score += (int) *(name + i) - 64;
		i++;
	}
	return score;
}

bool is_triangle(int n) {
	int m = (int) pow(2 * n, 0.5);

	if (m * (m + 1) == n * 2) {
		return true;
	}
        return false;
}

int main() {
	FILE *fptr;
	fptr = fopen("misc/challenge_042.txt","r");

	size_t size = 2000;
	char *words[size];
	words[0] = malloc(sizeof(char));

	int i = 0;
	while (fscanf(fptr, "\"%[ABCDEFGHIJKLMNOPQRSTUVWXYZ]\", ", words[i]) == 1) {
		i++;
		*(words + i) = malloc(sizeof(char));
	}
	fclose(fptr);

	int count = 0;

	for (int a = 0; a < i; a++) {
		int scr = score(words[a]);
		if (is_triangle(scr)) {
			count++;
		}
	}

	printf("Asnwer : %i", count);

	return EXIT_SUCCESS;
}


