#include <stdio.h>
#include <stdlib.h>

int way_change(int *S, int size, int c) {
	int **table, i, j, x, y;
	int result, rows, cols;

	rows = c + 1;
	cols = size;
	table = (int**) malloc(sizeof(int*) * rows);

	for (i = 0; i < rows; i++) {
		table[i] = (int*) malloc(sizeof(int) * cols);
	}

	for (j = 0; j < cols; j++) {
		table[0][j] = 1;
	}

	for (i = 1; i < rows; i++) {
		for (j = 0; j < cols; j++) {
			// Count of solutions including S[j]
            x = (i-S[j] >= 0) ? table[i - S[j]][j] : 0;

            // Count of solutions excluding S[j]
            y = (j >= 0) ? table[i][j - 1] : 0; 

            // total count
            table[i][j] = x + y;
		}
	}

	result = table[c][size - 1];

	for (i = 0; i < (c + 1); i++) {
		free(table[i]);
	}
	free(table);

	return result;
}

int main(int argc, char* argv[]) {
	int i, c, n, *array;

	scanf("%i %i", &c, &n);

	array = (int*) malloc(sizeof(int) * n);

	for (i = 0; i < n; i++) {
		scanf("%i", &array[i]);
	}

	printf("ways = %i\n", way_change(array, n, c));

	free(array);

	return 0;
}
