//
// Created by titouan on 06/10/23.
//

#ifndef PROJET_EULER_NB_STRING_H
#define PROJET_EULER_NB_STRING_H


#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include <stdbool.h>

int* count_digits(int n) {
	int size = (int) log10(n) +1;

	char n_str[size];
	sprintf(n_str, "%d", n);

	int *digit_count = calloc(10, sizeof(int));

	for (int i = 0; i < size; i++) {
		if (n_str[i] == '0') {
			digit_count[0]++;
		}
		else if (n_str[i] == '1') {
			digit_count[1]++;
		}
		else if (n_str[i] == '2') {
			digit_count[2]++;
		}
		else if (n_str[i] == '3') {
			digit_count[3]++;
		}
		else if (n_str[i] == '4') {
			digit_count[4]++;
		}
		else if (n_str[i] == '5') {
			digit_count[5]++;
		}
		else if (n_str[i] == '6') {
			digit_count[6]++;
		}
		else if (n_str[i] == '7') {
			digit_count[7]++;
		}
		else if (n_str[i] == '8') {
			digit_count[8]++;
		}
		else if (n_str[i] == '9') {
			digit_count[9]++;
		}
	}

	return digit_count;
}


bool palindromic_nb(int n) {
	int length = (int) log10((double) n);

	char n_str[length];
	sprintf(n_str, "%d", n);

	for (int i = 0; i <= length / 2; i++) {
		if (n_str[i] != n_str[length - i]) {
			return false;
		}
	}

	return true;
}

bool are_anagrams(int n, int m) {
	int *digit_count_1 = count_digits(n);
	int *digit_count_2 = count_digits(m);

	for (int i = 0; i < 10; i++) {
		if (digit_count_1[i] != digit_count_2[i]) {
			return false;
		}
	}
	return true;
}


uint32_t concatenate_int(uint32_t a, uint32_t b) {
	if (b == 0) {
		return a * 10;
	}
	else if (a == 0) {
		return b;
	}
	int i = 1;
	while (b / i > 0) {
		i *= 10;
		a *= 10;
	}
	return a + b;
}


bool is_n_pandigital(int a, int n) {
	int *digit_count = count_digits(a);
	for (int i = n; i > 0; i--) {
		if (digit_count[i] != 1) {
			return false;
		}
	}
	return digit_count[0] == 0;
}

#endif //PROJET_EULER_NB_STRING_H
