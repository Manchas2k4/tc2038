#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

const double MIN = -1e9;
const int SIZE = 1005;

typedef pair<double, double> Range;

int solution(Range *arr, int n) {
    double radius = MIN;
    int i, count;

    sort(arr, arr + n);

    i = count = 0;
    while (i < n) {
        while (i < n && arr[i].first <= radius) {
            radius = (radius < arr[i].second)? radius : arr[i].second;
            i++;
        }
        count++;
        radius = arr[i].second;
    }
    return count - 1;
}

int main(int argc, char* argv[]) {
    int n, d, cases;
    double x, y;
    bool noSolution;
    Range arr[SIZE];

    cases = 1;
    while(1) {
        cin >> n >> d;

       if (n == 0 && d == 0) {
            break;
        }

        noSolution = false;
        for (int i = 0; i < n; i++) {
            cin >> x >> y;

            if (y > d) {
                noSolution = true;
                continue;
            }

            arr[i].first  = x - sqrt((d * d) - (y * y));
            arr[i].second = x + sqrt((d * d) - (y * y));
        }
        cout << "Case " << cases++ << ": " 
             << ((noSolution)? -1 : solution(arr, n)) << "\n";
    }

    return 0;
}