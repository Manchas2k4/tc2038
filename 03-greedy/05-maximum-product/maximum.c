#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

#define SIZE 100

int maximum_product(int *a, int n) {
	int max_neg, count_neg, count_zero;
	int product, i;
	if (n == 1) {
		return a[0];
	}
	
	max_neg = INT_MIN;
	count_neg = count_zero = 0;
	product = 1;
	for (i = 0; i < n; i++) {
		if (a[i] == 0) {
			count_zero++;
			continue;
		}
		
		if (a[i] < 0) {
			count_neg++;
			max_neg = MAX(a[i], max_neg);
		}
		
		product *= a[i];
	}
	
	if (count_zero == n) {
		return 0;
	}
	
	if (count_neg % 2 == 1) {
		if (count_neg == 1 && count_zero > 0 && (count_neg + count_zero) == n) {
			return 0;
		}
		product = product / max_neg;
	}
	
	return product;
}

int main(int argc, char* argv[]) {
	int n, i, a[SIZE];
	
	scanf("%i", &n);
	for (i = 0; i < n; i++) {
		scanf("%i", &a[i]);
	}
	printf("%i\n", maximum_product(a, n));
	
	return 0;
}
