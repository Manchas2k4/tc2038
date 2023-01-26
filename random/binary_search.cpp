#include <iostream>
#include <iomanip>
#include "header.h"

using namespace std;

const int MAX = 1048576; // 2^20
const int DISPLAY = 100;

typedef pair<int, int> Pair;

// =================================================================
// Perform a traditional binary search. Looks up the given key in 
// the array and returns the index to a matching element, if found.
//
// @param array, an array of integer numbers.
// @param size, the amount of numbers.
// @param key, the item to search for.
// =================================================================
Pair binarySearch(int *arr, int size, int key) {
    int low, high, mid, cont;

    low = 0;
    high = size - 1;
    cont = 0;
    while (low <= high) {
        cont++;
        mid = low + ((high - low) / 2);
        if (key == arr[mid]) {
            return Pair(mid, cont);
        } else if (key < arr[mid]) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return Pair(-1, cont);
}

// =================================================================
// Performs a binary search that randomly selects the reference 
// element. Looks up the given key in the array and returns the 
// index to a matching element, if found.
//
// @param array, an array of integer numbers.
// @param size, the amount of numbers.
// @param key, the item to search for.
// =================================================================
Pair randomBinarySearch(int *arr, int size, int key) {
    int low, high, mid, cont;

    srand(1234);
    low = 0;
    high = size - 1;
    cont = 0;
    while (low <= high) {
        cont++;
        mid = low + (rand() % (high - low + 1));
        if (key == arr[mid]) {
            return Pair(mid, cont);
        } else if (key < arr[mid]) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return Pair(-1, cont);
}

int main(int argc, char* argv[]) {
    int *arr;
    Pair result;
    double ms;

    arr = new int[MAX];
    for (int i = 0; i < MAX; i++) {
        arr[i] = (i + 1) * 2;
    }

    cout << "It will search for the smallest element of the array. At most, you should perform 20 searches.\n";
    cout << "Using the traditional version\n";
    startTimer();
    result = binarySearch(arr, MAX, 2);
    ms = stopTimer();
    cout << "The number 2 was found at position " << result.first << " after " 
         << result.second << " searches.\n";
    cout << "time = " << setprecision(15) << ms << " ms\n" << endl;
    cout << "Using the randomized version\n";
    startTimer();
    result = randomBinarySearch(arr, MAX, 2);
    ms = stopTimer();
    cout << "The number 2 was found at position " << result.first << " after " 
         << result.second << " searches.\n";
    cout << "time = " << setprecision(15) << ms << " ms\n\n" << endl;

    cout << "An element not found in the array will be searched for.\n";
    cout << "Using the traditional version\n";
    startTimer();
    result = binarySearch(arr, MAX, 1000001);
    ms = stopTimer();
    cout << "The number 1000001 was found at position " << result.first << " after " 
         << result.second << " searches.\n";
    cout << "time = " << setprecision(15) << ms << " ms\n" << endl;
    cout << "Using the randomized version\n";
    startTimer();
    result = randomBinarySearch(arr, MAX, 1000001);
    ms = stopTimer();
    cout << "The number 1000001 was found at position " << result.first << " after " 
         << result.second << " searches.\n";
    cout << "time = " << setprecision(15) << ms << " ms\n" << endl;
}