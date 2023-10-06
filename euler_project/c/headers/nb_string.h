//
// Created by titouan on 06/10/23.
//

#ifndef PROJET_EULER_NB_STRING_H
#define PROJET_EULER_NB_STRING_H


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>


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

#endif //PROJET_EULER_NB_STRING_H
