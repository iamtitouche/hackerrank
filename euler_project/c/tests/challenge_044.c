//
// Created by titouan on 25/10/23.
//
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>


void calculate_pentagonal(int *pentagonal, int first, int size) {
	for (int i = first; i < size; i++) {
		pentagonal[i] = (i+1) * (3 * (i + 1) - 1) / 2;
	}
}


bool is_pentagonal(int n) {
	int m = (1 + (int) pow(1 + 24 * n, 0.5)) / 6;

	if (m * (3 * m - 1) == 2 * n) {
		return true;
	}

	return false;
}


int main() {
	int new_size = 3;
	int last_size = 1;
	int step = 3;
	int *pentagonal = calloc(new_size, sizeof(int));
	int d = 0;

	calculate_pentagonal(pentagonal, new_size - step, new_size);

	bool not_found = true;
	int n = 0;

	while (not_found && n < 2) {
		for (int i = 0; i < last_size; i++) {
			if (i == new_size - 1) {
				last_size = new_size;
				new_size += step;
				pentagonal = realloc(pentagonal, new_size * sizeof(int));
				calculate_pentagonal(pentagonal, new_size - step, new_size);
				break;
			}
			if (d != 0 && pentagonal[i + 1] - pentagonal[i] > d) {
				not_found = false;
				break;
			}
			for (int j = last_size; j < new_size; j++) {
				if (d != 0 && pentagonal[j] - pentagonal[i] > d) {
					break;
				}
				printf("Test : %i, %i\n", pentagonal[j], pentagonal[i]);
				if (is_pentagonal(pentagonal[j] + pentagonal[i]) &&
				    is_pentagonal(pentagonal[j] - pentagonal[i])) {
					if (d == 0 || pentagonal[j] - pentagonal[i] < d) {
						d = pentagonal[j] - pentagonal[i];
						printf("%i\n", d);
					}
				}

			}
		}
		for (int i = last_size; i < new_size && not_found; i++) {
			if (i == new_size - 1) {
				last_size = new_size;
				new_size += step;
				pentagonal = realloc(pentagonal, new_size * sizeof(int));
				calculate_pentagonal(pentagonal, new_size - step, new_size);
				break;
			}
			if (d != 0 && pentagonal[i + 1] - pentagonal[i] > d) {
				not_found = false;
				break;
			}
			for (int j = i + 1; j < new_size; j++) {
				if (d != 0 && pentagonal[j] - pentagonal[i] > d) {
					break;
				}
				if (is_pentagonal(pentagonal[j] + pentagonal[i]) &&
				    is_pentagonal(pentagonal[j] - pentagonal[i])) {
					if (d == 0 || pentagonal[j] - pentagonal[i] < d) {
						d = pentagonal[j] - pentagonal[i];
						printf("%i\n", d);
					}
				}
			}
		}
		n++;
	}



	printf("Answer : %i", d);




	return EXIT_SUCCESS;
}
