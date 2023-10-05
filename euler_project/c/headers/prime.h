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


#endif//PROJECT_EULER_PRIME_H
