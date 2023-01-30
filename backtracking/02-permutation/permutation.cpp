// =================================================================
//
// File: permutation.cpp
// Author: Pedro Perez
// Description: This file contains the implementation of the
//              algorithm that generates all the permutations of a
//              number using the Backtracking technique.
//
// Copyright (c) 2021 by Tecnologico de Monterrey.
// All Rights Reserved. May be reproduced for any non-commercial
// purpose.
// =================================================================

#include <iostream>
#include <string>

void swap(std::string &s, int i, int j) {
  char aux = s[i];
  s[i] = s[j];
  s[j] = aux;
}

void permutation(std::string &s, int pos) {
  if (pos == 0) {
    std::cout << s << "\n";
  } else {
    for (int i = 0; i <= pos; i++) {
      swap(s, i, pos);
      permutation(s, pos - 1);
      swap(s, i, pos);
    }
  }
}

int main(int argc, char* argv[]) {
  std::string s;

  std::cin >> s;
  permutation(s, s.size() - 1);

  return 0;
}
