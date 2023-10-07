//
// Created by titouan on 07/10/23.
//
#include <stdio.h>
#include <stdlib.h>

ulong step(ulong n) {
	if (n % 2 == 0) {
		return n / 2;
	}
	return 3 * n + 1;
}

int count_step(ulong n, int* list_count) {
	int count = 0;
	ulong curr_n = n;
	while (curr_n != 1) {
		curr_n = step(curr_n);
		count++;
		if (curr_n < n) {
			count += list_count[curr_n - 1];
			break;
		}
	}
	list_count[n - 1] = count;
	return count;
}

int main(int argc, char **argv) {
	if (argc != 2) {
		printf("One int argument needed");
		return EXIT_FAILURE;
	}
	int n = atoi(argv[1]), max = 0, count, answer = 1;

	int *list_count = calloc(n, sizeof(int));

	for (int i = 1; i <= n; i++) {
		count = count_step(i, list_count);
		if (count > max) {
			max = count;
			answer = i;
		}
	}

	printf("Answer : %d\n", answer);

	return EXIT_SUCCESS;
}
