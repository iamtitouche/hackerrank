//
// Created by titouan on 21/10/23.
//
#include <iostream>
#include <cstdio>
#include <iomanip>
using namespace std;

int main() {
	int a;
	long b;
	char c;
	float f;
	double d;

	scanf("%d", &a);
	scanf("%ld", &b);
	scanf(" %c", &c);
	scanf("%f", &f);
	scanf("%lf", &d);

	std::cout << a << endl << b << endl << c << endl;

	std::cout << fixed << setprecision(3) << f << std::endl;
	std::cout << fixed << setprecision(9) << d << std::endl;

	return EXIT_SUCCESS;
}

