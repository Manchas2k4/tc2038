#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <utility>

using namespace std;

int main(int argc, char* argv[]) {
    srand(time(0));
    for (int i = 0; i < 10; i++) {
        cout << rand() % 10000 << "\n";
    }
    return 0;
}