//
// Created by titouan on 16/10/23.
//

#ifndef PROJET_EULER_POLYNOM_H
#define PROJET_EULER_POLYNOM_H
#include <math.h>


typedef struct integer_polynomial {
    int degree;
    int *coef;
}integer_polynomial;


float int_pol_evaluate(float x, integer_polynomial *pol) {
	float result = 0;
	for (int i = 0; i <= pol->degree; i++) {
		result += pol->coef[i] * pow(x, i);
	}

	return result;
}

#endif //PROJET_EULER_POLYNOM_H
