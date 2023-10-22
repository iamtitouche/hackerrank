//
// Created by titouan on 22/10/23.
//
#include <stdio.h>
#include <stdlib.h>
#include "nb_string.h"
#include "divisors.h"

int main() {
	int final_num = 1;
	int final_den = 1;

	for (int den = 11; den < 100; den++) {
		if (den % 10 == 0) {
			continue;
		}
		for (int num = 10; num < den; num++) {
			if (num % 10 == 0) {
				continue;
			}
			int* digit_c_num = count_digits(num);
			int* digit_c_den = count_digits(den);

			for (int i = 0; i < 10; i++) {
				if (digit_c_den[i] >= 1 && digit_c_num[i] >= 1) {
					digit_c_den[i]--;
					digit_c_num[i]--;
					int new_den = 1;
					int new_num = 1;
					for (int j = 1; j < 10; j++) {
						if (digit_c_den[j] == 1) {
							new_den = j;
						}
						if (digit_c_num[j] == 1) {
							new_num = j;
						}
					}
					if (new_den * num == new_num * den) {
						final_den *= den;
						final_num *= num;
					}
				}
			}
		}
	}

	printf("Answer : %i", final_den / pgcd(final_den, final_num));

	return EXIT_SUCCESS;
}
