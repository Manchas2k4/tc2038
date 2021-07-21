#include <stdio.h>
#include <stdlib.h>

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

#define SIZE 100

int compare (const void * a, const void * b) {
  return ( *(int*)a - *(int*)b );
}

int booking_problem(int *arrival, int *departure, int n, int k) {
	int current, required, i, j;
	
	qsort(arrival, n, sizeof(int), compare);
	qsort(departure, n, sizeof(int), compare);
	
	i = j = 0;
	current = required = 0;
	while (i < n && j  < n) {
		if (arrival[i] < departure[j]) {
			current++;
			required = MAX(current, required);
			i++;
		} else {
			current--;
			j++;
		}
	}
	while (i < n) {
		current++;
		required = MAX(current, required);
		i++;	
	}
	while (j < n) {
		current--;
		j++;
	}
	
	return (k >= required);
}


int main(int argc, char* argv[]) {
	int arrival[SIZE], departure[SIZE], n, k;
	
	scanf("%i %i", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%i %i", &arrival[i], &departure[i]);
	}
	if (booking_problem(arrival, departure, n, k)) {
		printf("YES\n");
	} else {
		printf("NO\n");
	}
	return 0;
}
