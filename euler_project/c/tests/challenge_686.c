//
// Created by titouan on 23/10/23.
//
#include "large_integer.h"

large_integer *keep_n_first_digit(int n, large_integer *value) {
	large_integer *tmp = malloc(sizeof(large_integer));
	tmp->length = n;
	tmp->digits = malloc(n * sizeof(int));

	for (int i = 0; i < n; i++) {
		tmp->digits[i] = value->digits[value->length - n + i];
	}

	free(value->digits);

	free(value);

	return tmp;
}

int main() {
	int n = 0;
	int power = 2;

	large_integer *value = large_power_of_int(2, power);
	//678910

	while (n < 678910) {
		large_integer *tmp = value;
		value = double_value(value);
		free(tmp->digits);
		free(tmp);
		int l = value->length;
		if (value->digits[l - 1] == 1 && value->digits[l - 2] == 2 && value->digits[l - 3] == 3) {
			n++;
		}
		power++;
		if (value->length == 100) {
			value = keep_n_first_digit(75, value);
		}
	}

	printf("Answer : %i", power);

	return EXIT_SUCCESS;
}
