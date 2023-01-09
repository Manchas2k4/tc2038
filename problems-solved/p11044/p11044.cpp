#include <iostream>
#include <iomanip>

using namespace std;

int main(int argc, char* argv[]) {
    int cases, n, m;

    cin >> cases;
    while (cases--) {
        cin >> n >> m;
        cout << ((n / 3) * (m / 3)) << "\n";
    }
    return 0;
}