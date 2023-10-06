//
// Created by titouan on 06/10/23.
//
#include <stdio.h>
#include <stdlib.h>
#include "nb_string.h"


int main() {
	int max_palindrome, curr_test;
	int min_j;

	max_palindrome = 0;
	min_j = 100;

	for (int i = 999; i >= 100; i--) {
		if (999 * i < max_palindrome) {
			break;
		}

		for (int j = 999; j >= min_j; j--) {
			curr_test = j * i;
			if (curr_test < max_palindrome) {
				break;
			}
			if (palindromic_nb(curr_test)) {
				min_j = j;
				max_palindrome = curr_test;
				break;
			}
		}
	}
	printf("%d\n", max_palindrome);


	return EXIT_SUCCESS;
}
