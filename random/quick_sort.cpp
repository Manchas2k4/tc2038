#include <iostream>
#include <iomanip>
#include "header.h"

using namespace std;

const int SIZE = 100000; //1e5
const int DISPLAY = 100;
const int TOP_VALUE = 1000;

// =================================================================
// Initializes an array with random values between 1 and TOP_VALUE.
//
// @param array, an array of integer numbers.
// @param size, the amount of numbers.
// =================================================================
void fillArray(int *array, int size) {
	int i;

	for (i = 0; i < size; i++) {
		array[i] = size - i;
	}
}

// =================================================================
// Displays the first N locations in the array.
//
// @param array, an array of integer numbers.
// @param size, the amount of numbers.
// =================================================================
void displayArray(const char *text, int *array) {
	int i;

	printf("%s = [%4i", text, array[0]);
	for (i = 1; i < DISPLAY; i++) {
		printf(",%4i", array[i]);
	}
	printf(", ... ,]\n");
}

// =================================================================
// Find the pivot to be used for separation
//
// @param A, the destination array.
// @param low, lower index.
// @param high, higher index.
// @return the pivot number, otherwise it returns -1.
// =================================================================
template <class T>
int findPivot(T *A, int low, int high) {
	int i;

	for (i = low + 1; i <= high; i++) {
		if (A[low] > A[i]) {
			return A[low];
		} else if (A[low] < A[i]){
			return A[i];
		}
	}
	return -1;
}

// =================================================================
// Separate the elements. On the left side of the range [low, high]
// places the elements that are less than the pivot; on the right
// side, the elements that are greater than or equal to the pivot.
//
// @param A, the destination array.
// @param low, lower index.
// @param high, higher index.
// @return the point where elements greater than or equal to the
//		   pivot begin.
// =================================================================
template <class T>
int makePartition(T *A, int low, int high, int pivot) {
	int i, j;

	i = low;
	j = high;
	while (i < j) {
		swap(A, i , j);
		while (A[i] < pivot) {
			i++;
		}
		while (A[j] >= pivot) {
			j--;
		}
	}
	return i;
}

// =================================================================
// First, it generates a random position and swaps it for the low 
// position (random skin). If there is a pivot, separate the 
// elements into less than the pivot and greater than or equal to 
// it. Finally, it invokes the quick sort on both sets.
//
// @param A, the destination array.
// @param low, lower index.
// @param high, higher index.
// =================================================================
template <class T>
void randomizeQuick(T *A, int low, int high) {
	int pivot, pos, size,  i;

    i = low + (rand() % (high - low + 1));
    swap(A, i, low);

	pivot = findPivot(A, low, high);
	if (pivot != -1) {
		pos = makePartition(A, low, high, pivot);
		randomizeQuick(A, low, pos - 1);
		randomizeQuick(A, pos, high);
	}
}

// =================================================================
// If there is a pivot, separate the elements into less than the 
// pivot and greater than or equal to it. Finally, it invokes the 
// quick sort on both sets.
//
// @param A, the destination array.
// @param low, lower index.
// @param high, higher index.
// =================================================================
template <class T>
void quick(T *A, int low, int high) {
	int pivot, pos, size,  i;

    pivot = findPivot(A, low, high);
	if (pivot != -1) {
		pos = makePartition(A, low, high, pivot);
		quick(A, low, pos - 1);
		quick(A, pos, high);
	}
}

// =================================================================
// Performs the quick sort algorithm.
//
// @param A, an array of T elements.
// @param size, the number of elements in the array.
// =================================================================
template <class T>
void quickSort(T *A, int size, int random = 0) {
    if (!random) {
	    quick(A, 0, size - 1);
    } else {
        randomizeQuick(A, 0, size - 1);
    }
}


int main(int argc, char* argv[]) {
    int *arr;
    double ms;

    srand(1234);
    arr = new int[SIZE];

    cout << "Using the randomize quick sort\n";
    fillArray(arr, SIZE);
    displayArray("before: ", arr);
    startTimer();
    quickSort(arr, SIZE);
    ms = stopTimer();
    displayArray("after: ", arr);
    cout << "time = " << setprecision(15) << ms << " ms\n" << endl;

    cout << "Using the standard quick sort\n";
    fillArray(arr, SIZE);
    displayArray("before: ", arr);
    startTimer();
    quickSort(arr, SIZE);
    ms = stopTimer();
    displayArray("after: ", arr);
    cout << "time = " << setprecision(15) << ms << " ms\n\n" << endl;

    delete [] arr;
}