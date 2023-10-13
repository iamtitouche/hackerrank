//
// Created by titouan on 13/10/23.
//
#include <stdio.h>
#include <stdlib.h>
#include "large_integer.h"

typedef struct large_int_list_elem {
	large_integer *value;
    	struct large_int_list_elem *next;
    	struct large_int_list_elem *previous;
}large_int_list_elem;


void insert(large_integer *to_insert, large_int_list_elem **head, int *count) {
	if ((*head) == NULL) {
		*head = malloc(sizeof(large_int_list_elem));
		(*head)->value = to_insert;
		(*head)->next = NULL;
		(*head)->previous = NULL;
		(*count)++;
                return;
	}
        large_int_list_elem *current = *head;
	if (!greater_than(*to_insert, *(current->value))) {
		if (equal_to(*((*head)->value), *to_insert)) {
			return;
		}
		current->previous = malloc(sizeof(large_int_list_elem));
		current->previous->value = to_insert;
		current->previous->next = current;
		*head = current->previous;
		(*head)->previous = NULL;
		(*count)++;
		//Insérer to_insert en tete de liste
		return;
	}
	while (greater_than(*to_insert, *(current->value))) {
		if (current->next == NULL) {
			current->next = malloc(sizeof(large_int_list_elem));
			current->next->value = to_insert;
			current->next->next = NULL;
			current->next->previous = current;
			(*count)++;
			return;
		}
		current = current->next;
	}
	if (equal_to(*(current->value), *to_insert)) {
		return;
	}
	large_int_list_elem *tmp = malloc(sizeof(large_int_list_elem));

	tmp->next = current;
	tmp->previous = current->previous;
	tmp->value = to_insert;
	tmp->previous->next = tmp;
	current->previous = tmp;
	(*count)++;
}


int main(int argc, char **argv) {
	if (argc != 2) {
		printf("One int argument needed");
		return EXIT_FAILURE;
	}
	int n_max = atoi(argv[1]);

	large_int_list_elem **head = malloc(sizeof(large_int_list_elem*));

	int count = 0;

	for (int a = 2; a <= n_max; a++) {
		for (int b = 2; b <= n_max; b++) {
			large_integer* tmp = large_power_of_int(a, b);
			insert(tmp, head, &count);
		}
	}

	printf("Answer : %d\n", count);


	return EXIT_SUCCESS;
}