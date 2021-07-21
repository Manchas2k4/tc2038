
// =================================================================
//
// File: coin_change.cpp
// Author: Pedro Perez
// Description: The program implements the greedy algorithm of
//							activity selection. Receive console: the number of
//							activities, followed by the start and end time of
//							each of them.
//
// Copyright (c) 2021 by Tecnologico de Monterrey.
// All Rights Reserved. May be reproduced for any non-commercial
// purpose.
// =================================================================

#include <iostream>
#include <algorithm>
#include <vector>

typedef struct act {
	int start, end;
} activity;

bool compare(activity left, activity right) {
	return (left.end < right.end);
}

void activitySelection(std::vector<activity> &array) {
	int i, j;

	std::sort(array.begin(), array.end(), compare);
	i = 0;

	std::cout << "(" << array[i].start << ", " << array[i].end << "), ";
	for (j = 1; j < array.size(); j++) {
		if (array[j].start >= array[i].end) {
			std::cout << "(" << array[j].start << ", " << array[j].end << "), ";
			i = j;
		}
	}
	std::cout << "\n";
}

int main(int argc, char* argv[]) {
	std::vector<activity> array;
	activity aux;
	int i, n;

	std::cin >> n;
	for (i = 0; i < n; i++) {
		std::cin >> aux.start >> aux.end;
		array.push_back(aux);
	}
	activitySelection(array);
	return 0;
}
