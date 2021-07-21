/**
	The program implements the avid algorithm of activity
	selection. Receive console: the number of activities,
	followed by the start and end time of each of them.
	
	@author Pedro Perez
	@version 1.0 16/01/2019
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct act {
	int start, end;
} activity;

int compare(const void *a, const void *b) {
	activity *left = (activity*) a;
	activity *right = (activity*) b;
	
	return (left->end - right->end);
}

void activity_selection(activity *array, int n) {
	int i, j;
	
	qsort(array, n, sizeof(activity), compare);
	i = 0;
	
	printf("(%i, %i), ", array[i].start, array[i].end);
	for (j = 1; j < n; j++) {
		if (array[j].start >= array[i].end) {
			printf("(%i, %i), ", array[j].start, array[j].end);
			i = j;
		}
	}
	printf("\n");
}

int main(int argc, char* argv[]) {
	activity *array;
	int i, n;
	
	scanf("%i", &n);
	array = (activity*) malloc(sizeof(activity) * n);
	for (i = 0; i < n; i++) {
		scanf("%i %i", &array[i].start, &array[i].end);
	}
	activity_selection(array, n);
	return 0;
}
