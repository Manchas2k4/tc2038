/**
	The program calculates the minimum amount of coins 
	that would have to return a change, using a greedy
	algorithm. The program receives from console: the 
	change to give (amount), the number of coins in the
	systems (n) and the denomination of the same ones.
	
	@author Pedro Perez
	@version 1.0 16/01/2019
*/

#include <stdio.h>
#include <stdlib.h>

int compare (const void * a, const void * b) {
  return ( *(int*)b - *(int*)a );
}

/**
	@param n, number of different denominations
	@param coins, array with the denominations of the coins
	@param amount, amount to be given in change 
	@retun the minimum amount of coins
 */
int coin_change(int n, int coins[], int amount) {
	int minimum = 0, i;
	
	qsort (coins, n, sizeof(int), compare);
	for (i = 0; i < n; i++) {
		minimum += amount / coins[i];
		amount %= coins[i];
	}
	return minimum;
}

int main(int argc, char* argv[]) {
	int *array = NULL;
	int i, n, amount, min;
	
	scanf("%i", &amount);
	scanf("%i", &n);
	
	array = (int*) malloc(n * sizeof(int));
	for (i = 0; i < n; i++) {
		scanf("%i", (array + i));
	}
	
	min = coin_change(n, array, amount);
	printf("%i\n", min);
	
	return 0;
}
