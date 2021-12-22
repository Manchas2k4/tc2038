
// =================================================================
//
// File: maximum.cpp
// Author: Pedro Perez
// Description: Given an array A, we have to find the maximum
//							possible product with the subset of elements present
//							in the array. The maximum product can be just one of
//							the elements in the array. This code uses the greedy
//							technique.
//
// Copyright (c) 2021 by Tecnologico de Monterrey.
// All Rights Reserved. May be reproduced for any non-commercial
// purpose.
// =================================================================

#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

int maximumProduct(std::vector<int> &a) {
	int max_neg, count_neg, count_zero;
	int product, i;
	if (a.size() == 1) {
		return a[0];
	}

	max_neg = INT_MIN;
	count_neg = count_zero = 0;
	product = 1;
	for (i = 0; i < a.size(); i++) {
		if (a[i] == 0) {
			count_zero++;
			continue;
		}

		if (a[i] < 0) {
			count_neg++;
			max_neg = std::max(a[i], max_neg);
		}

		product *= a[i];
	}

	if (count_zero == a.size()) {
		return 0;
	}

	if (count_neg % 2 == 1) {
		if (count_neg == 1 && count_zero > 0 &&
			 (count_neg + count_zero) == a.size()) {
			return 0;
		}
		product = product / max_neg;
	}

	return product;
}

int main(int argc, char* argv[]) {
	int n, i, aux;
	std::vector<int> a;

	std::cin >> n;
	for (i = 0; i < n; i++) {
		std::cin >> aux;
		a.push_back(aux);
	}
	std::cout << maximumProduct(a) << "\n";

	return 0;
}
