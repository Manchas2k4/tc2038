// =================================================================
//
// File: permutation.cpp
// Author: Pedro Perez
// Description: This file contains the algorithm implementation that
//              the subsets whose sum is equal to a target value
//              using the Backtracking technique.
//
// Copyright (c) 2021 by Tecnologico de Monterrey.
// All Rights Reserved. May be reproduced for any non-commercial
// purpose.
// =================================================================

#include <iostream>
#include <vector>
#include <set>

typedef unsigned char uchar;

uchar add(uchar mask, int pos) {
  return (mask | (1 << pos));
}

uchar remove(uchar mask, int pos) {
  return (mask & !(1 << pos));
}

bool test(uchar mask, int pos) {
  return ((mask & (1 << pos)) != 0);
}

void printSolution(const std::vector<int> &S, uchar mask) {
  std::cout << "{";
  for (int i = 0; i < S.size(); i++) {
    if (test(mask, i)) {
        std::cout << S[i] << " ";
    }
  }
  std::cout << "}\n";
}

void subset(const std::vector<int> &A, uchar mask,
            int acum, int target, int level) {

    if (acum > target) {
      return;
    }

    if (acum == target) {
        printSolution(A, mask);
        return;
    }

    if (level < A.size()) {
        subset(A, mask, acum, target, level + 1);
        mask = add(mask, level);
        subset(A, mask, acum + A[level], target, level + 1);
    }
}

int main(int argc, char* argv[]) {
    std::vector<int> A;
    uchar mask;
    int n, aux, target;

    std::cin >> n >> target;
    for (int i = 0; i < n; i++) {
        std::cin >> aux;
        A.push_back(aux);
    }

    subset(A, mask, 0, target, 0);
    return 0;
}
