//
// Created by titouan on 25/10/23.
//
#include "nb_string.h"
#include "prime.h"
#include "math.h"

int main() {
	int n = 987654321;
	int answer = 0;

	bool* prime = prime_list(n);

	for (int i = n; i > 0; i--) {
		if (prime[i]) {
			int n_digits = (int) log10(i) + 1;
			if (is_n_pandigital(i, n_digits)) {
				answer = i;
				break;
			}
		}
	}

	printf("Answer : %i", answer);

	return EXIT_SUCCESS;
}
