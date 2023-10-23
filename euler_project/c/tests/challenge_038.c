//
// Created by titouan on 23/10/23.
//
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include "nb_string.h"


int main() {
	uint32_t max = 0;


	uint32_t i = 1;
	uint32_t concatenated;
	uint32_t product;

	while (i < 50000) {//condition de sortie non optimisée mais l'algorithme s'exécute déjà en temps largement raisonnable
                concatenated = i;
		product = i * 2;
		while ((int) log10((double) product) + (int) log10((double) concatenated) <= 7) {
			concatenated = concatenate_int(concatenated, product);
			if (is_n_pandigital((int) concatenated, 9)) {
				if (concatenated > max) {
					max = concatenated;
				}
			}
			product += i;
		}
		i++;
	}

	printf("Answer : %d\n", max);

	return EXIT_SUCCESS;
}
