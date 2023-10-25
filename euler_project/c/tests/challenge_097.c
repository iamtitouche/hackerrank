//
// Created by titouan on 25/10/23.
//
#include "large_integer.h"

large_integer *keep_n_last_digit(int n, large_integer *value) {
	large_integer *tmp = malloc(sizeof(large_integer));
	tmp->length = n;
	tmp->digits = malloc(n * sizeof(int));

	for (int i = 0; i < n; i++) {
		tmp->digits[i] = value->digits[i];
	}

	free(value->digits);

	free(value);

	return tmp;
}


int main() {
	large_integer *n = create_large_integer(1);
	for (int power = 1; power <= 7830457; power++) {
		large_integer *tmp = n;
		n = double_value(n);
		free(tmp->digits);
		free(tmp);
		if (n->length > 20) {
			n = keep_n_last_digit(11, n);
		}
		if (power % 100000 == 0) {
			printf("%i\n", power / 1000);
		}
	}

	n = multiply_by_int(n, 28433);

	large_integer *one = create_large_integer(1);

	n = sum_large_integers(one, n);

	printf("Answer : ");


	for (int i = 9; i >= 0; i--) {
		printf("%i", n->digits[i]);

	}

	return EXIT_SUCCESS;
}
