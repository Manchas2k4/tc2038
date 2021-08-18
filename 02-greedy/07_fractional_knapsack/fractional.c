#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

#define SIZE 100

typedef struct item {
	float value, weight;
} Item;

int compare (const void * a, const void * b) {
  Item *left = (Item*) a;
  Item *right = (Item*) b;
  return ( (right->value / right->weight) - (left->value / left->weight) );
}

double fractional_knapsack(Item *arr, int n, int w) {
	float weight, acum, remain;
	int i;
	
	qsort(arr, n, sizeof(Item), compare);
	
	weight = 0;
	acum = 0;
	for (i = 0; i < n; i++) {
		if (weight + arr[i].weight <= w) {
			weight += arr[i].weight;
			acum += arr[i].value;
		} else {
			remain = w- weight;
			acum += arr[i].value * (remain / arr[i].weight);
		}
	}
	
	return acum;
}

int main(int argc, char* argv[]) {
	int i, n;
	float w;
	Item *arr;
	
	scanf("%i %f", &n, &w);
	arr = (Item*) malloc(sizeof(Item) * n);
	for (i = 0; i < n; i++) {
		scanf("%f %f", &arr[i].value, &arr[i].weight);
	}
	printf("Maximum value we can obtain = %.2f\n", fractional_knapsack(arr, n, w));
	
	free(arr);
	return 0;
}
