// =================================================================
//
// File: ugly.c
// Author: Pedro Perez
// Description: This file contains the implementation of the
//							ugly numbers problem. The algorithm uses the
//              DP technique.
//
// Copyright (c) 2021 by Tecnologico de Monterrey.
// All Rights Reserved. May be reproduced for any non-commercial
// purpose.
// =================================================================

#include <stdio.h>
#include <stdlib.h>

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

void ugly_numbers(int n) {
	int *array, i2, i3, i5;
	int i, ugly;

	array = (int*) malloc(sizeof(int) * (n + 1));

	array[0] = array[1] = 1;
	i2 = i3 = i5 = 1;
	ugly = 0;
	for (i = 2; i <= n; i++) {
		ugly = MIN( (array[i2] * 2),
				MIN( (array[i3] * 3), (array[i5] * 5) )  );
		array[i] = ugly;
		if (ugly == (array[i2] * 2)) i2++;
		if (ugly == (array[i3] * 3)) i3++;
		if (ugly == (array[i5] * 5)) i5++;
	}

	for (i = 1; i <= n; i++) {
		printf("%i ", array[i]);
	}
	printf("\n");

	free(array);
}

int main(int argc, char* argv[]) {
	int n;

	scanf("%i", &n);
	ugly_numbers(n);
	return 0;
}
