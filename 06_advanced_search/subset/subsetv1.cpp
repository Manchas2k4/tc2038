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

void printSolution(const std::set<int> &S) {
  std::set<int>::iterator it;

  std::cout << "{";
  for (it = S.begin(); it != S.end(); it++) {
    std::cout << (*it) << " ";
  }
  std::cout << "}\n";
}

void subset(const std::vector<int> &A, std::set<int> S,
            int acum, int target, int level) {
  if (acum == target) {
    printSolution(S);
    return;
  }

  if (acum > target) {
    return;
  }

  if (level < A.size()) {
    subset(A, S, acum, target, level + 1);
    S.insert(A[level]);
    subset(A, S, acum + A[level], target, level + 1);
  }
}

int main(int argc, char* argv[]) {
  std::vector<int> A;
  std::set<int> S;
  int n, aux, target;

  std::cin >> n >> target;
  for (int i = 0; i < n; i++) {
    std::cin >> aux;
    A.push_back(aux);
  }

  subset(A, S, 0, target, 0);
  return 0;
}
