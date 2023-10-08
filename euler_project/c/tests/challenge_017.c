//
// Created by titouan on 08/10/23.
//
#include <stdio.h>
#include <stdlib.h>


int count_letters_in_number_bellow_1000(int n) {
	int count = 0;
	int size_of_units[19] = {3, 3, 5, 4, 4, 3, 5, 5, 4, 3, 6, 6, 8, 8, 7, 7, 9, 8, 8};
	int size_of_tenths[9] = {3, 6, 6, 5, 5, 5, 7, 6, 6};

	if (n == 1000) {
		return 11;
	}

	if (n >= 100) {
		count += 7 + size_of_units[(n % 1000) / 100 - 1];
	}

	if (n % 100 >= 1 && n % 100 < 20) {
		count += size_of_units[n % 100 - 1];
		if (n > 100) {
			count += 3;
		}
	}

	if (n % 100 >= 20) {
		count += size_of_tenths[(n % 100) / 10 - 1];
		if (n % 10 > 0) {
			count += size_of_units[n % 10 - 1];
		}
		if (n > 100) {
			count += 3;
		}
	}
	return count;
}

int main() {
	int total = 0;
	for (int i = 1; i <= 1000; i++) {
		total += count_letters_in_number_bellow_1000(i);
	}

	printf("Answer : %d\n", total);

	return EXIT_SUCCESS;
}
