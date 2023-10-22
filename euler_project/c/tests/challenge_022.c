//
// Created by titouan on 21/10/23.
//
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>


int main() {
	int n = 1, total = 0;

	FILE *fptr;
	fptr = fopen("misc/challenge_022.txt","r");

	size_t size = 5000;
	char *names[size];
	names[0] = malloc(sizeof(char[30]));

	int i = 0;
	while (fscanf(fptr, "\"%s,\" ", names[i]) == 1) {

		printf("%s", names[i]);

		i++;
		if (i == size) {
			size += 5000;
			realloc(names, size);
		}
		*(names + i) = malloc(sizeof(char));
	}


	char c;
	fscanf(fptr, "%c", &c);

	while (c == '\"') {
		int score = 0;
		printf("%i : ", n);
		fscanf(fptr, "%c", &c);
		while (c != '\"' && c != '\0') {
			printf("%c", c);
			score += (int) c - 64;
			fscanf(fptr, "%c", &c);
		}
		total += score * n;
		n++;
		printf(" %i\n", score);
		if (fscanf(fptr, ", %c", &c) != 1) {
			break;
		};

	}

	fclose(fptr);

	printf("Answer : %i", total);

	return EXIT_SUCCESS;
}
