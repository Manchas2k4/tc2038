// =================================================================
//
// File: inversion.cpp
// Author: Pedro Perez
// Description: This file contains the implementation of the longest
//							common prefix algorithm using the divide and conquer
//							technique.
//
// Copyright (c) 2021 by Tecnologico de Monterrey.
// All Rights Reserved. May be reproduced for any non-commercial
// purpose.
// =================================================================

#include <iostream>
#include <string>

std::string find_prefix(const std::string &str1, const std::string &str2) {
	std::string result;
	int len1, len2, i, j;

	len1 = str1.length();
	len2 = str2.length();
	i = j = 0;
	while (i < len1 && j < len2) {
		if (str1[i] != str2[j]) {
			break;
		}
		result.push_back(str1[i]);
		i++; j++;
	}
	return result;
}

std::string common_prefix(std::string arr[], int low, int high) {
	int mid;

	if (low == high) {
		return arr[low];
	}

	if (low < high) {
		mid = low + (high - low) / 2;
		std::string str1 = common_prefix(arr, low, mid);
		std::string str2 = common_prefix(arr, mid + 1, high);

		return find_prefix(str1, str2);
	}

	return std::string("aux");
}

int main(int argc, char* argv[]) {
	std::string *arr;
	int n;

	std::cin >> n;
	arr = new std::string[n];
	for (int i = 0; i < n; i++) {
		std::cin >> arr[i];
	}
	std::cout << "result = " << common_prefix(arr, 0, n - 1) << "\n";
	return 0;
}
