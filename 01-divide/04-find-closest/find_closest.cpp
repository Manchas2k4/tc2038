// =================================================================
//
// File: inversion.cpp
// Author: Pedro Perez
// Description: This file contains the implementation of the
//							algorithm that finds the element closest to X within
//							an array using the divide and rule technique.
//
// Copyright (c) 2021 by Tecnologico de Monterrey.
// All Rights Reserved. May be reproduced for any non-commercial
// purpose.
// =================================================================
#include <iostream>

int getClosest(int val1, int val2, int target) {
	if (target - val1 > val2 - target) {
		return val2;
	} else {
		return val1;
	}
}

int findClosest(int *arr, int n, int target) {
	int low, high, mid;

	if (target < arr[0]) {
		return arr[0];
	}

	if (target >= arr[n - 1]) {
		return arr[n - 1];
	}

	low = 0;
	high = n - 1;
	mid = 0;
	while (low < high) {
		mid = low + ( (high - low) / 2 );
		if (target == arr[mid]) {
			return arr[mid];
		} else if (target < arr[mid]) {
			if (mid > 0 && target > arr[mid - 1]) {
				return getClosest(arr[mid - 1], arr[mid], target);
			}
			high = mid;
		} else {
			if (mid < (n - 1) && target < arr[mid + 1]) {
				return getClosest(arr[mid], arr[mid + 1], target);
			}
			low = mid;
		}
	}
	return -1;
}

int main(int argc, char* argv[]) {
	int i, n, target, *arr;

	std::cin >> n >> target;

	arr = new int[n];
	for (i = 0; i < n; i++) {
		std::cin >> arr[i];
	}
	std::cout << "Closest of " << target << " = "
						<< findClosest(arr, n, target) << "\n";

	delete [] arr;
	return 0;
}
