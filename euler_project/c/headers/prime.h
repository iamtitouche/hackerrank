//
// Created by titouan on 05/10/23.
//
/**
 *  @file	prime.h
 *  @brief	Prime Calculation Module
 *
 *  \author
 *  Created by Titouan SADOUN on 05.10.23.
 *  Copyright 2023 Titouan SADOUN. All rights reserved.
 *
 */
#ifndef PROJECT_EULER_PRIME_H
#define PROJECT_EULER_PRIME_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>


typedef struct prime_factor {
    ulong value;
    int multiplicity;
    struct prime_factor* next;
}prime_factor;


prime_factor* prime_factors(ulong n) {
	prime_factor *first_factor, *curr_factor = NULL;
	ulong sqrt_n = (ulong) pow((double) n, 0.5);

	while (n % 2 == 0 && n > 0) {
		if (!curr_factor) {
			curr_factor = malloc(sizeof(prime_factor));
			curr_factor->next = NULL;
			curr_factor->value = 2;
			curr_factor->multiplicity = 1;
			first_factor = curr_factor;
		}
		else {
			curr_factor->multiplicity++;
		}
		n = n / 2;
	}


	for (ulong i = 3; i <= sqrt_n; i += 2) {
		while (n % i == 0) {
			if (!curr_factor) {
				curr_factor = malloc(sizeof(prime_factor));
				curr_factor->next = NULL;
				curr_factor->value = i;
				curr_factor->multiplicity = 1;
				first_factor = curr_factor;
			}
			else {
				if (curr_factor->value == i) {
					curr_factor->multiplicity++;
				}
				else {
					prime_factor *new_factor = malloc(sizeof(prime_factor));
					new_factor->next = NULL;
					new_factor->value = i;
					new_factor->multiplicity = 1;
					curr_factor->next = new_factor;
					curr_factor = new_factor;
				}
			}
			n = n / i;
		}
		if (n == 1) break;
	}

	if (n > 1) {
		if (!curr_factor) {
			first_factor = malloc(sizeof(prime_factor));
			first_factor->value = n;
			first_factor->multiplicity = 1;
			first_factor->next = NULL;
		}
		else {
			prime_factor *new_factor = malloc(sizeof(prime_factor));
			new_factor->value = n;
			new_factor->multiplicity = 1;
			new_factor->next = NULL;
			curr_factor->next = new_factor;
		}
	}

	return first_factor;
}


int count_prime_factors(prime_factor *factors) {
	if (factors == NULL) {
		return 0;
	}
	int i = 1;
	while (factors->next != NULL) {
		i++;
		factors = factors->next;
	}
	return i;
}


bool* prime_list(int n) {
	bool *prime_bool = malloc((n + 1) * sizeof(bool));

	prime_bool[0] = false;
	prime_bool[1] = false;
	prime_bool[2] = true;

	for (int i = 3; i <= n; i += 2) {
		prime_bool[i] = true;
		prime_bool[i + 1] = false;
	}



	prime_bool[n] = (n % 2 == 1);

	double sqrt_n = pow(n, 0.5);

	for (int i = 3; i <= sqrt_n; i += 2) {
		if (prime_bool[i]) {
			for (int j = 2 * i; j <= n; j += i) {
				prime_bool[j] = false;
			}
		}
	}

	return prime_bool;
}



void prime_list_from_previous_list(int n, int past_lenght, bool *prime_bool) {
	if (past_lenght <= 3) {
		prime_bool = prime_list(n);
		return;
	}
	printf("prime 1");

	if (n < past_lenght) {
		return;
	}

	printf("prime 1");
	prime_bool = realloc(prime_bool, (n + 1) * sizeof(bool));

	printf("prime 1");
	for (int i = 2 * (past_lenght / 2) + 1; i <= n; i += 2) {
		prime_bool[i] = true;
		prime_bool[i + 1] = false;
	}
	printf("prime 1");
	double sqrt_n = pow(n, 0.5);

	for (int i = 3; i <= sqrt_n; i += 2) {
		if (prime_bool[i]) {
			for (int j = 2 * i; j <= n; j += i) {
				prime_bool[j] = false;
			}
		}
	}
}



ulong* prime_list_from_booleans(bool *prime_bool, ulong size, int *n_primes) {

	*n_primes = 0;
	for (ulong i = 0; i < size; i++) {
		if (prime_bool[i]) {
			(*n_primes)++;
		}
	}

	ulong *prime_list = malloc((*n_primes) * sizeof(int));

	int i = 0;

	for (ulong j = 0; j < size; j++) {
		if (prime_bool[j]) {
			prime_list[i] = j;
			i++;
		}
	}
	return prime_list;
}


#endif//PROJECT_EULER_PRIME_H
