//
// Created by titouan on 12/10/23.
//
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main() {
	int product = 1;
	int total_digits = 1;
	int n = 1;
	int trigger = 1;
	int digits_n = 1;

	while (trigger != 10000000){
		if (total_digits >= trigger) {
			int index = total_digits - trigger;
			product *= (n / (int) pow(10, index)) % 10;
			trigger *= 10;
		}
		n++;
		digits_n = (int) log10(n) + 1;
		total_digits += digits_n;
	}

	printf("Answer : %d\n", product);

	return EXIT_SUCCESS;

}
