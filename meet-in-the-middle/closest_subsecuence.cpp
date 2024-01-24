#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

vector<int> find_all_sums(vector<int> &numbers,int start, int end, int offset){        
	vector<int> results;
	int n, sum;

	n = end - start + 1;
	for(int i = 0; i < (1<<n); i++){
		sum = 0;
		for(int j = 0; j < n; j++){
			if(i & (1<<j))
				sum += numbers[j+offset];
		}
		results.push_back(sum);
	}
	return results;
}

int maximum_sum_subset(vector<int> &numbers, int goal) {
	int n, result;
	std::vector<int>::iterator itr;

	n = numbers.size();
	if(n == 1) {
		return min(abs(goal), abs(numbers[0] - goal));
	}

	vector<int> left = find_all_sums(numbers, 0, (n / 2) - 1, 0);
	
	vector<int> right = find_all_sums(numbers, (n / 2), (n - 1), (n / 2));
	sort(right.begin(), right.end());
	
	result = INT_MAX;
	for(int i = 0; i < left.size(); i++){
		int j = lower_bound(right.begin(), right.end(), goal - left[i]) - right.begin();

		if(j > 0) {
			result = min(result, abs(goal - right[j - 1] - left[i]));
		}

		if(j < right.size()) {
			result = min(result, abs(goal - right[j] - left[i]));
		}
	}
	return result;
}

int main(int argc, char* argv[]) {
	vector<int> numbers = {5, 3, -1, 7};
	int result, target = 13;

	result = maximum_sum_subset(numbers, target);
	cout << "The maximum possible sum is " << (target - result) << ".\n";
	return 0;
}