//
// Created by titouan on 07/10/23.
//
#ifndef PROJET_EULER_LARGE_INTEGER_H
#define PROJET_EULER_LARGE_INTEGER_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>


//Création du type large_integer
//Le paramètre length est le nombre de chiffres qui composent l'entier
//Le paramètre digits est un array d'entier (int) compris entre 0 et 9 inclus qui correspondent au décimale de poids faible d'abord
typedef struct large_integer {
    int length;
    int *digits;
}large_integer;

large_integer* double_value(large_integer *number) {
	int carried_out = 0;
	int tmp;
	large_integer *result = malloc(sizeof(large_integer));
	result->length = number->length;
	result->digits = malloc( result->length * sizeof(int));

	for (int i = 0; i < number->length; i++) {
		tmp = 2 * number->digits[i] + carried_out;
		result->digits[i] = tmp % 10;
		carried_out = tmp / 10;
	}

	if (carried_out != 0) {
		result->length++;
		result->digits = realloc(result->digits, result->length * sizeof(int));
		result->digits[result->length - 1] = carried_out;
	}

	return result;
}


//Fonction sum_large_integers
//Renvoie un pointeur vers un large_integer calculé comme la somme des large_integer d'addresses a et b
large_integer* sum_large_integers(large_integer *a, large_integer *b) {
	int carried_out = 0;
	int tmp;

	if (a->length < b->length) {
		large_integer *c = a;
		a = b;
		b = c;
	}

	large_integer *result = malloc(sizeof(large_integer));
	result->length = a->length;
	result->digits = malloc( result->length * sizeof(int));

	int i;
	for (i = 0; i < b->length; i++) {
		tmp = a->digits[i] + b->digits[i] + carried_out;
		result->digits[i] = tmp%10;
		carried_out = tmp / 10;
	}

	if (carried_out != 0) {
		if (b->length == a->length) {
			result->length++;
			result->digits = realloc(result->digits, result->length * sizeof(int));
			result->digits[b->length] = carried_out;
			return result;
		}
	}

	for (int j = i; j < result->length; j++) {
		tmp = a->digits[j] + carried_out;
		result->digits[j] = tmp % 10;
		carried_out = tmp / 10;
	}

	if (carried_out != 0) {
		result->length++;
		result->digits = realloc(result->digits, result->length * sizeof(int));
		result->digits[result->length - 1] = carried_out;
	}

	return result;
}

large_integer* create_large_integer(int n) {
	large_integer *number = malloc(sizeof(large_integer));

	number->length = (int) log10((double ) n) + 1;
	number->digits = malloc( number->length * sizeof(int));

	for (int i = 0; i < number->length; i++) {
		number->digits[i] = n % 10;
		n /= 10;
	}

	return number;
}

large_integer* create_large_integer_from_str(char *n, int size) {
	large_integer *number = malloc(sizeof(large_integer));

	number->length = size;
	number->digits = malloc( number->length * sizeof(int));

	for (int i = 0; i < number->length; i++) {
		number->digits[i] = (int) n[number->length - 1 - i] - 48;
	}

	return number;
}

large_integer* multiply_by_int(large_integer *number, int factor) {
	int carried_out = 0;
	int tmp;

	large_integer *result = malloc(sizeof(large_integer));
	result->length = number->length;
	result->digits = malloc( result->length * sizeof(int));

	int i;
	for (i = 0; i < result->length; i++) {
		tmp = number->digits[i] * factor + carried_out;
		result->digits[i] = tmp % 10;
		carried_out = tmp / 10;
	}

	if (carried_out != 0) {
		result->length += (int) log10((double) carried_out) + 1;
		result->digits = realloc(result->digits, result->length * sizeof(int));
	}

	for (i = i; i < result->length; i++) {
		result->digits[i] = carried_out % 10;
		carried_out /= 10;
	}

	return result;
}

bool palindromic_large_nb(large_integer *number) {
	for (int i = 0; i < number->length / 2; i++) {
		if (number->digits[i] != number->digits[number->length - i - 1]) {
			return false;
		}
	}

	return true;
}


large_integer* binary_from_int(int n) {
	large_integer *binary = malloc(sizeof(large_integer));
	binary->length = (int) log2((double) n) + 1;
	binary->digits = malloc(binary->length * sizeof(int));

	for (int i = 0; i < binary->length; i++) {
		binary->digits[i] = n % 2;
		n = n / 2;
	}

	return binary;
}


large_integer* large_power_of_int(int n, int power) {
	large_integer *result = create_large_integer(n);

	for (int i = 1; i < power; i++) {
		large_integer *tmp = result;
		result = multiply_by_int(result, n);
		free(tmp->digits);
		free(tmp);
	}


	return result;
}


bool greater_than(large_integer a, large_integer b) {
	if (a.length > b.length) {
		return true;
	}
	else if (a.length == b.length) {
		for (int i = a.length - 1; i >= 0; i--) {
			if (a.digits[i] > b.digits[i]) {
				return true;
			}
			if (a.digits[i] < b.digits[i]) {
				return false;
			}
		}
	}
	return false;
}

bool equal_to(large_integer a, large_integer b) {
	if (a.length != b.length) {
		return false;
	}
	if (a.length == b.length) {
		for (int i = a.length - 1; i >= 0; i--) {
			if (a.digits[i] != b.digits[i]) {
				return false;
			}
		}
	}
	return true;
}

void print_large_integer(large_integer *number) {
	for (int i = number->length - 1; i >= 0; i--) {
		printf("%d", number->digits[i]);
	}
	printf("\n");
}


int sum_of_digits(large_integer *number) {
	int sum = 0;

	for (int i = 0; i < number->length; i++) {
		sum += number->digits[i];
	}

	return sum;
}


#endif //PROJET_EULER_LARGE_INTEGER_H
