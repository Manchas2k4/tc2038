#include <iostream>
#include <iomanip>
#include <algorithm>
#include <queue>

using namespace std;

const int ROWS = 11;
const int COLS = 101;

int main(int argc, char* argv[]) {
    int input[ROWS][COLS], sum[ROWS][COLS];
    int maxRows, maxCols, iRen, minRen, minimum, ren;
    int a, b, c;
    bool first;
    queue<int> path;

    while(cin >> maxRows >> maxCols) {
        for (int i = 0; i < maxRows; i++) {
            for (int j = 0; j < maxCols; j++) {
                cin >> input[i][j];
            }
        }

        for (int i = 0; i < maxRows; i++) {
            sum[i][maxCols - 1] = input[i][maxCols - 1];
        }

        for (int j = maxCols - 2; j >= 0; j--) {
            for (int i = 0; i < maxRows; i++) {
                a = sum[(i + maxRows - 1) % maxRows] [j + 1];
                b = sum[i] [j + 1];
                c = sum[(i + maxRows + 1) % maxRows] [j + 1];
                sum[i][j] = min(a, min(b, c)) + input[i][j];
            }
        }

        minimum = sum[0][0];
        iRen = 0;
        for (int i = 1; i < maxRows; i++) {
            if (sum[i][0] < minimum) {
                minimum = sum[i][0];
                iRen = i;
            }
        }

        path.push(iRen);
        for (int j = 1; j < maxCols; j++) {
            a = sum[iRen][j - 1] - input[iRen][j - 1];
            minRen = maxRows + 1;

            ren = (iRen + maxRows - 1) % maxRows;
            if (sum[ren][j] == a) {
                if (ren < minRen) {
                    minRen = ren;
                }
            }

            ren = iRen;
            if (sum[ren][j] == a) {
                if (ren < minRen) {
                    minRen = ren;
                }
            }

            ren = (iRen + maxRows + 1) % maxRows;
            if (sum[ren][j] == a) {
                if (ren < minRen) {
                    minRen = ren;
                }
            }

            iRen = minRen;
            path.push(minRen);
        }

        first = true;
        while (!path.empty()) {
            if (!first) {
                cout << " ";
            }
            
            first = false;
            cout << (path.front() + 1);
            path.pop();
        }
        cout << "\n" << minimum << "\n";
    }
    return 0;
}