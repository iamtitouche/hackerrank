//
// Created by titouan on 15/10/23.
//
#include <stdio.h>
#include <stdlib.h>



int recursive_count_combinations(int count, int price, int next_coin, int n_coins, int *coins) {
	price += *(coins + next_coin) * n_coins;
	if (price > 200) {
		return count;
	}
	else if (price == 200) {
		printf("found one\n");
		return count + 1;
	}
	else {
		if (next_coin < 7) {
			next_coin++;
			for (n_coins = 0; n_coins <= 200 - price / *(coins + next_coin); n_coins++) {
				count = recursive_count_combinations(count, price, next_coin, n_coins, coins);
			}
		}
		return count;
	}
}


int main() {
	int *coins = calloc(8, sizeof(int));

	*coins = 1;
	for (int i = 1; i < 8; i++) {
		if (i % 3 != 2) {
			*(coins + i) = 2 * *(coins + i - 1);
		}
		else {
			*(coins + i) = 5 * *(coins + i - 1) / 2;
		}
	}

	int answer = recursive_count_combinations(0, 0, 0, 1, coins);

	printf("Answer : %i\n", answer);
\
	return EXIT_SUCCESS;
}