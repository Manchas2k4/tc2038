// =================================================================
//
// File: eight_queen.cpp
// Author: Pedro Perez
// Description: This file contains the implementation of the 8
//              queens algorithm. The algorithm uses Backtracking
//              technique.
//
// Copyright (c) 2021 by Tecnologico de Monterrey.
// All Rights Reserved. May be reproduced for any non-commercial
// purpose.
// =================================================================

#include <iostream>
#include <cmath>

int caseNumber = 0;

bool canPlace(int *rows, int r, int c) {
  for (int i = 0; i < c; i++) {
    if ( (rows[i] == r) || (abs(rows[i] - r) == abs(i - c)) ) {
      return false;
    }
  }
  return true;
}

void eigthQueens(int *rows, int a, int b, int c) {
  if (c == 8 && rows[b] == a) {
    std::cout << "Solution " << (++caseNumber) << ": ";
    for (int i = 0; i < 8; i++) {
      std::cout << (rows[i] + 1) << " ";
    }
    std::cout << "\n";
  }

  for (int r = 0; r < 8; r++) {
    if (canPlace(rows, r, c)) {
      rows[c] = r;
      eigthQueens(rows, a, b, c + 1);
    }
  }
}

int main(int argc, char* argv[]) {
  int a, b;
  int rows[8] = {0};

  std::cin >> a >> b;
  eigthQueens(rows, a, b, 0);
}
