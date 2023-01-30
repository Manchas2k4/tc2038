// =================================================================
//
// File: coin_change.cpp
// Author: Pedro Perez
// Description: The program calculates the minimum amount of coins
//							that would have to return a change, using a greedy
//							algorithm. The program receives from console: the
//							change to give (amount), the number of coins in the
//							systems (n) and the denomination of the same ones
//							using the greedy technique.
//
// Copyright (c) 2021 by Tecnologico de Monterrey.
// All Rights Reserved. May be reproduced for any non-commercial
// purpose.
// =================================================================
#include <iostream>
#include <algorithm>
#include <vector>

bool compare (int a, int b) {
  return (a > b);
}

int coinChange(std::vector<int> coins, int amount) {
	int minimum = 0, i;

	std::sort (coins.begin(), coins.end(), compare);
	for (i = 0; i < coins.size(); i++) {
		minimum += amount / coins[i];
		amount %= coins[i];
	}
	return minimum;
}

int main(int argc, char* argv[]) {
	std::vector<int> array;
	int i, n, amount, min, aux;

	std::cin >> amount >> n;

	for (i = 0; i < n; i++) {
		std::cin >> aux;
		array.push_back(aux);
	}

	min = coinChange(array, amount);
	std::cout << "Result = " << min << "\n";

	return 0;
}
