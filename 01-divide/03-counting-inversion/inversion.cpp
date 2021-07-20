// =================================================================
//
// File: inversion.cpp
// Author: Pedro Perez
// Description: This file contains the implementation of the
//							algorithm that counts investments (if i < j,
//							arr [i] > arr [j]) modifying the algorithm of the
//							merge sort that uses the divide and conquer
//							technique.
//
// Copyright (c) 2021 by Tecnologico de Monterrey.
// All Rights Reserved. May be reproduced for any non-commercial
// purpose.
// =================================================================
#include <iostream>

void copy(int *A, int *B, int low, int high) {
	int i;

	for (i = low; i <= high; i++) {
		A[i] = B[i];
	}
}

int mergeAndCount(int *A, int *B, int low, int mid, int high) {
	int left, right, i, count;

	left = i = low;
	right = mid + 1;
	count = 0;
	while (left <= mid && right <= high) {
		if (A[left] < A[right]) {
			B[i] = A[left++];
		} else {
			B[i] = A[right++];
			count = count + (mid - left + 1);
		}
		i++;
	}
	while (left <= mid) {
		B[i] = A[left++];
		i++;
	}
	while (right <= high) {
		B[i] = A[right++];
		i++;
	}
	return count;
}

int sortAndCount(int *A, int *B, int low, int high) {
	int r, mid, left, right;

	r = left = right = 0;
	if ( (high - low + 1) == 1 ) {
		return 0;
	} else {
		mid = low + ((high - low) / 2);
		left = sortAndCount(A, B, low, mid);
		right = sortAndCount(A, B, mid + 1, high);
		r = mergeAndCount(A, B, low, mid, high);
		return (r + left + right);
	}
}

int main(int argc, char* argv[]) {
	int i, n, result;
	int *array, *temp;

	std::cin >> n;
	array = new int[n];
	temp = new int[n];
	for (i = 0; i < n; i++) {
		std::cin >> array[i];
	}
	std::cout << "Result = " << sortAndCount(array, temp, 0, n - 1) << "\n";

	delete [] temp;
	delete [] array;
	return 0;
}
