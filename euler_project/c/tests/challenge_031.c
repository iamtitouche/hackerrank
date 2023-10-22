//
// Created by titouan on 15/10/23.
//
#include <stdio.h>
#include <stdlib.h>

static int *coins;


//fonction recursive qui compte le nombre de manière sommer à goal - price en utilisant exactement n_coins fois la pièce next_coin et aucune fois les pièces plus grandes.
int recursive_count_combinations(int goal, int price, int next_coin, int n_coins) {
	price += *(coins + next_coin) * n_coins;
	if (price == goal) {
		return 1;
	}
	else {
		next_coin--;
		int count = 0;
		if (next_coin == 0) {
			count += 1;
		}
		else {
			for (n_coins = 0; n_coins <= (goal - price) / *(coins + next_coin); n_coins++) {
				count += recursive_count_combinations(goal, price, next_coin, n_coins);
			}
		}
		return count;
	}
}


int main() {
	coins = calloc(8, sizeof(int));

	*coins = 1;
	for (int i = 1; i < 8; i++) {
		if (i % 3 != 2) {
			*(coins + i) = 2 * *(coins + i - 1);
		}
		else {
			*(coins + i) = 5 * *(coins + i - 1) / 2;
		}
	}

	int answer = recursive_count_combinations(200, 0, 7, 0) + 1;

	printf("Answer : %i\n", answer);

	return EXIT_SUCCESS;
}