#include <stdio.h>
#include <stdlib.h>

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

#define SIZE 1000

int max_sum(int *array, int size) {
	int i, sum, ans;
	
	sum = ans = 0;
	for(i = 0; i < size; i++) {
		sum += array[i];
		ans = MAX(sum, ans);
		if (sum < 0) {
			sum = 0;
		}
	}
	return ans;
}

int main(int argc, char* argv[]) {
	int array[SIZE], n, i;
	
	scanf("%i", &n);
	for (i = 0; i < n; i++) {
		scanf("%i", &array[i]);
	}
	printf("result = %i\n", max_sum(array, n));
	return 0;
}
