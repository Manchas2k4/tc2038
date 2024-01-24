#include <iostream>
#include <iomanip>
#include <algorithm>
#include <tuple>
#include <cmath>

typedef std::tuple<bool, int, int, int> Triplet;

using namespace std;

Triplet is_there_a_triplet(int *arr, int size) {
	for (int i = 0; i < size; i++) {
		arr[i] *= arr[i];
	}

	sort(arr, arr + size);

	for (int result = size - 1; result >= 2; result--) {
		int left = 0, right = result - 1;
		while (left < right) {
			if (arr[left] + arr[right] == arr[result]) {
				return make_tuple(true, left, right, result);
			} else if (arr[left] + arr[right] < arr[result]) {
				left++;
			} else {
				right--;
			}
		}
	}
	return make_tuple(false, -1, -1, -1);
}

int main(int argc, char* argv[]) {
	int arr[] = {3, 10, 4, 6, 13, 8};
	int i, j, k;
	Triplet answer;

	answer = is_there_a_triplet(arr, 6);
	if (std::get<0>(answer))  {
		i = std::get<1>(answer);
		j = std::get<2>(answer);
		k = std::get<3>(answer);
		cout << "There is a triplet: " << sqrt(arr[i]) << "^2 + " << sqrt(arr[j])
			 << "^2 = " << sqrt(arr[k]) << "^2\n";
	} else {
		cout << "There is no a triplet\n";
	}

	return 0;
}