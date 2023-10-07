//
// Created by titouan on 07/10/23.
//
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int count_distinct_divisors(unsigned long n) {
	int count = 0;
	for (unsigned long i = 1; i <= pow(n, 0.5); i++) {
		if (n % i == 0) {
			count++;
			if (n / i != i) {
				count++;
			}
		}
	}
	return count;
}

int main(int argc, char **argv) {
	if (argc != 2) {
		printf("One int argument needed");
		return EXIT_FAILURE;
	}

	int n_divisors = atoi(argv[1]);
	unsigned long n = 1;

	int i = 2;

	while (count_distinct_divisors(n) < n_divisors) {
		n += i;
		i++;
	}

	printf("Answer : %ld\n", n);

	return EXIT_SUCCESS;
}
