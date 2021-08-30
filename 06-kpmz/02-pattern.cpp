#include <iostream>
#include <string>
#include <vector>

int patternMatchingNaive(const std::string &pattern, const std::string &text) {
  int n, m;
  std::string segment;

  n = text.size();
  m = pattern.size();
  for (int i = 0; i < (n - m + 1); i++) {
    segment = text.substr(i, m);
    if (pattern == segment) {
      return i;
    }
  }
  return -1;
}

std::vector<int> preprocessing(const std::string &pattern) {
  int i, j, m = pattern.size();
  std::vector<int> V(m);

  V[0] = i = j = 0;
  while (i < m) {
    if (pattern[i] == pattern[j]) {
      V[i] = j + 1;
      i++; j++;
    } else {
      if (j == 0) {
        V[i] = 0;
        i++;
      } else {
        j = V[j - 1];
      }
    }
  }
  return V;
}

int KMP(const std::string &pattern, const std::string &text) {
  int m, n, i, j, pos;
  std::vector<int> V;

  m = pattern.size();
  n = text.size();
  V = preprocessing(pattern);
  pos = i = j = 0;
  while (i < n) {
    if (text[i] == pattern[j]) {
      i++;
      j++;
      if (j == m) {
        return pos;
      }
    } else {
      if (j == 0) {
        i++;
        pos = i;
      } else {
        pos = i - V[j - 1];
        j = V[j - 1];
      }
    }
  }
  return -1;
}

int main(int argc, char* argv[]) {
  std::string pattern, text;

  std::cin >> pattern >> text;
  std::cout << "Naive, " << pattern << " found at position "
            << (patternMatchingNaive(pattern, text) + 1) << "\n";
  std::cout << "KMP, " << pattern << " found at position "
            << (KMP(pattern, text) + 1) << "\n";
  return 0;
}
