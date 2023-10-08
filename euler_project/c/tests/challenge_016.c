//
// Created by titouan on 08/10/23.
//
#include <stdio.h>
#include <stdlib.h>
#include "large_integer.h"

int main() {
	large_integer *n = malloc(sizeof(large_integer));

	n->length = 1;
	n->digits = malloc( n->length * sizeof(int));
	n->digits[0] = 1;

	for (int _ = 0; _ < 1000; _++) {
		n = double_value(n);
	}

	int sum = 0;

	for (int i = 0; i < n->length; i++) {
		sum += n->digits[i];
	}

	printf("Answer : %d\n", sum);

	return EXIT_SUCCESS;
}