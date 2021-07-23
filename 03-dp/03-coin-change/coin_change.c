// =================================================================
//
// File: max_sum.c
// Author: Pedro Perez
// Description: This file contains the implementation of the
//							coin change problem. The algorithm uses the
//              DP technique.
//
// Copyright (c) 2021 by Tecnologico de Monterrey.
// All Rights Reserved. May be reproduced for any non-commercial
// purpose.
// =================================================================

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

#define SIZE 1000

int coin_change(int c, int *S, int n) {
	int *aux, i, j, c1, result;

	c1 = c + 1;
	aux = (int*) malloc(sizeof(int) * c1);

	for (i = 0; i < c1; i++) {
		aux[i] = INT_MAX;
	}

	aux[0] = 0;
	for (i = 0; i < n; i++) {
		for (j = S[i]; j < c1; j++) {
			aux[j] = MIN(1 + aux[j - S[i]], aux[j]);
		}
	}

	result = aux[c];
	free(aux);

	return result;
}

int main(int argc, char* argv[]) {
	int i, n, c, array[SIZE];

	scanf("%i %i", &c, &n);
	for (i = 0; i < n; i++) {
		scanf("%i", &array[i]);
	}
	printf("result = %i\n", coin_change(c, array, n));
	return 0;
}
