//
// Created by titouan on 09/10/23.
//
#include <stdio.h>
#include <stdlib.h>
#include "large_integer.h"


int main(int argc, char **argv) {
	if (argc != 2) {
		printf("One int argument needed");
		return EXIT_FAILURE;
	}
	int n_digit = atoi(argv[1]);

	int count = 2;
	large_integer *n = malloc(sizeof(large_integer));

	n->length = 1;
	n->digits = malloc( n->length * sizeof(int));
	n->digits[0] = 1;

	large_integer *m = malloc(sizeof(large_integer));

	m->length = 1;
	m->digits = malloc( m->length * sizeof(int));
	m->digits[0] = 1;

	large_integer *c;

	while (m->length < n_digit) {
		c = sum_large_integers(n, m);
		n = m;
		m = c;
		count++;
	}

	printf("Answer : %d\n", count);

	return EXIT_SUCCESS;
}
