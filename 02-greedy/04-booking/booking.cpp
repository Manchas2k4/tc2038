
// =================================================================
//
// File: coin_change.cpp
// Author: Pedro Perez
// Description: The program implements the greedy algorithm of
//              booking reservation. This code uses the greedy
//              technique.
//
// Copyright (c) 2021 by Tecnologico de Monterrey.
// All Rights Reserved. May be reproduced for any non-commercial
// purpose.
// =================================================================

#include <iostream>
#include <algorithm>
#include <vector>

int bookingProblem(std::vector<int> &arrival,
                   std::vector<int> &departure, int k) {
	int current, required, i, j;

	std::sort(arrival.begin(), arrival.end());
	std::sort(departure.begin(), departure.end());

	i = j = 0;
	current = required = 0;
	while (i < arrival.size() && j  < departure.size()) {
		if (arrival[i] < departure[j]) {
			current++;
			required = std::max(current, required);
			i++;
		} else {
			current--;
			j++;
		}
	}
	while (i < arrival.size()) {
		current++;
		required = std::max(current, required);
		i++;
	}
	while (j < departure.size()) {
		current--;
		j++;
	}

	return (k >= required);
}


int main(int argc, char* argv[]) {
	std::vector<int> arrival;
  std::vector<int> departure;
  int n, k, t1, t2;

	std::cin >> n >> k;
	for (int i = 0; i < n; i++) {
    std::cin >> t1 >> t2;
    arrival.push_back(t1);
    departure.push_back(t2);
	}
	if (bookingProblem(arrival, departure, k)) {
		std::cout << "YES\n";
	} else {
		std::cout << "NO\n";
	}
	return 0;
}
