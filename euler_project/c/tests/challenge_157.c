//
// Created by titouan on 09/10/23.
//
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>

int main()
{
	int count = 0;
	for (int n = 1; n <= 9; n++)
	{
		uint64_t power_of_10 = (uint64_t) pow(10, n);

		for(uint64_t p = 1; p <= 2 * power_of_10; p++) {

			uint64_t a_start = (uint64_t) power_of_10 / p;

			for (uint64_t a = a_start; a <= 2 * power_of_10 / p; a++)
			{
				if (p * a > power_of_10)
				{
					if (a * power_of_10 % (p * a - power_of_10) == 0) {
						count++;
					}
				}
			}
		}
	}
	printf("Answer : %d\n", count);

	return EXIT_SUCCESS;
}

