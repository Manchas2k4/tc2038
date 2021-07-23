// =================================================================
//
// File: fibonacci.c
// Author: Pedro Perez
// Description: This file contains the implementation of the
//							Fibonacci serie. The algorithm uses the
//              DP technique.
//
// Copyright (c) 2021 by Tecnologico de Monterrey.
// All Rights Reserved. May be reproduced for any non-commercial
// purpose.
// =================================================================

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned long ul;
typedef unsigned int ui;

ul fib1(ui n) {
	if (n < 1) {
		return -1;
	} else if (n == 1 || n == 2) {
		return 1;
	} else {
		return fib1(n - 1) + fib1(n - 2);
	}
}

ul fib2(ui n, ul *A) {
	if (n < 1) {
		return -1;
	} else if (n == 1 || n == 2) {
		return 1;
	} else if (A[n] != -1) {
		return A[n];
	} else {
		A[n] = fib2(n - 1, A) + fib2(n - 2, A);
		return A[n];
	}
}

void fib3(ui n, ul *A) {
	ui i;

	A[1] = A[2] = 1;
	for (i = 3; i <= n; i++) {
		A[i] = A[i - 1] + A[i - 2];
	}
}

int main(int argc, char* argv[]) {
	ui n;
	ul *A, result;

	scanf("%u", &n);

	A = (ul*) malloc((n + 1) * sizeof(ul));
	memset(A, -1, (n + 1) * sizeof(ul));

	printf("fib1(%u) = %li\n", n, fib1(n));
	printf("fib2(%u) = %li\n", n, fib2(n, A));

	fib3(n, A);
	printf("fib3(%u) = %li\n", n, A[n]);

	free(A);
	return 0;
}
