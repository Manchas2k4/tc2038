#include <iostream>
#include <string>
#include <vector>

std::vector<int> zFunctionNaive(const std::string &s) {
  int n = s.length();
  std::vector<int> z(n);

  for (int i = 1; i < n; i++) {
    while(i + z[i] < n && s[z[i]] == s[i + z[i]]) {
      z[i]++;
    }
  }
  return z;
}

std::vector<int> zFunctionDP(const std::string &s) {
  int left, right, n = s.length();
  std::vector<int> z(n);

  left = right = 0;
  for (int i = 1; i < n; i++) {
    std::cout << "i = " << i << " left = " << left << " right = " << right << "\n";

    if (i <= right) {
      z[i] = std::min(right - i + 1, z[i - left]);
    }

    while(i + z[i] < n && s[z[i]] == s[i + z[i]]) {
      z[i]++;
      std::cout << z[i] << " ";
    }
    std::cout << "=> Z[" << i << "] = " << z[i] << "\n";

    if (i + z[i] - 1 > right) {
      left = i;
      right = i + z[i] - 1;
    }

    char c;
    std::cin >> c;
  }
  return z;
}

void displayVector(const std::vector<int> &v) {
  std::cout << "[" << v[0];
  for (int i = 1; i < v.size(); i++) {
    std::cout << " " << v[i];
  }
  std::cout << "]\n";
}

int main(int arg, char *argv[]) {
  std::string input;
  std::vector<int> zValues;

  std::cin >> input;
  std::cout << "Naive: \n";
  zValues = zFunctionNaive(input);
  displayVector(zValues);
  std::cout << "\nDP: \n";
  zValues = zFunctionDP(input);
  displayVector(zValues);

  return 0;
}
