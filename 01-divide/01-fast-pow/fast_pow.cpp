// =================================================================
//
// File: fast_pow.cpp
// Author: Pedro Perez
// Description: This file contains the implementation of the fast
//							exponentiation algorithm, which employs the divide
//							and conquer technique.
//
// Copyright (c) 2021 by Tecnologico de Monterrey.
// All Rights Reserved. May be reproduced for any non-commercial
// purpose.
// =================================================================

#include <iostream>

double fastPow(double x, int n) {
	if (n < 0) {
		return fastPow(1/x, -n);
	} else if (n == 0) {
		return 1;
	} else if (n == 1) {
		return x;
	} else if (n % 2 == 0) {
		return fastPow(x * x, n / 2);
	} else { // if (n % 2 != 0) {
		return x * fastPow(x * x, (n - 1) / 2);
	}
}

int main(int argc, char* argv[]) {
	double x;
	int n;

	std::cin >> x >> n;
	std::cout << x << "^" << n << " = " << fastPow(x,n) << "\n";
}
