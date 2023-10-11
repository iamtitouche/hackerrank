//
// Created by titouan on 11/10/23.
//
#include <stdlib.h>
#include <stdio.h>
#include "prime.h"

bool is_truncable_prime(int n, bool *primes_bool) {
	int tmp = n;

	while (log10(tmp) >= 1) {
		tmp = tmp % (int) pow(10, (int) log10(tmp));
		if (!primes_bool[tmp]) {
			return false;
		}
	}

	tmp = n;

	while (log10(tmp) >= 1) {
		tmp = tmp / 10;
		if (!primes_bool[tmp]) {
			return false;
		}
	}

	return true;
}


int main() {
	int n_primes = 0, sum = 0, found = 0;
	bool *primes_bool = prime_list(10);
	int primes_limit = 10;
	printf("1\n");
	ulong *primes = prime_list_from_booleans(primes_bool, primes_limit + 1, &n_primes);

	while (found <= 11) {
		printf("2\n");
		prime_list_from_previous_list(primes_limit + 100000, primes_limit + 1, primes_bool);
		printf("3\n");
		primes = prime_list_from_booleans(primes_bool, primes_limit + 1, &n_primes);
		for (int i = primes_limit; i < n_primes; i++) {
			if (is_truncable_prime((int) primes[i], primes_bool)) {
				found++;
				printf("%ld\n", primes[i]);
				sum += (int) primes[i];
			}
		}
		printf("4\n");
		primes_limit += 100000;
	}

	printf("Answer : %d\n", sum);

	return EXIT_SUCCESS;
}