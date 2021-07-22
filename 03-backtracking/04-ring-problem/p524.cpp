// =================================================================
//
// File: permutation.cpp
// Author: Pedro Perez
// Description: This file contains the implementation of the UVA's
//              problem 524 using the Backtracking technique.
//
// Copyright (c) 2021 by Tecnologico de Monterrey.
// All Rights Reserved. May be reproduced for any non-commercial
// purpose.
// =================================================================

#include <iostream>
#include <vector>
#include <set>
#include <cmath>

const int SIZE = 20;

std::vector<int> primes = {2,3,5,7,11,13,17,19,23,29,31,37,41};

bool isPrime(int n) {
  for (int i = 0; i < primes.size(); i++) {
      if (primes[i] == n) {
        return true;
      }
  }
  return false;
}

void ring(int *circle, bool *used, int n, int m) {
  if ((m == (n - 1)) && isPrime(circle[n - 1] + circle[n]))  {
    for (int i = 0; i < n; i++) {
      std::cout << circle[i];
      if (i != (n - 1)) {
        std::cout << " ";
      }
    }
    std::cout << "\n";
    return;
  }

  for (int i = 2; i <= n; i++) {
    if (!used[i] && isPrime(circle[m] + i)) {
      used[i] = true;
      circle[m + 1] = i;
      ring(circle, used, n, m + 1);
      used[i] = false;
    }
  }
}

int main(int argc, char* argv[]) {
  int n, cont = 0;
  int circle[20];

  while(std::cin >> n) {
    cont++;
    if (cont > 1) {
      std::cout << "\n";
    }

    bool used[20] = {0};
    circle[0] = circle[n] = 1;
    std::cout << "Case " << cont << ":\n";
    ring(circle, used, n, 0);
  }
}
