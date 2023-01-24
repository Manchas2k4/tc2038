#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

const int MAX_ROWS = 9;
const int MAX_MOVES = 7;
const int MOVE_OPTIONS = 3;

const int renMoves[] = { 0, -1,  0};
const int colMoves[] = {-1,  0, +1};
const string moveNames[] = {"left", "forth", "right"};
const string solution = "IEHOVA#";

int rens, cols;
string grid[MAX_ROWS];
string output[MAX_MOVES];

bool backtracking(int ren, int col, int pos) {
    int newRen, newCol;

    if (grid[ren][col] == '#') {
        cout << output[0];
        for (int i = 1; i < pos; i++) {
            cout << " " << output[i];
        }
        cout << "\n";
        return true;
    }

    if (pos == solution.size()) {
        return false;
    }

    for (int i = 0; i < MAX_MOVES; i++) {
        newRen = ren + renMoves[i];
        newCol = col + colMoves[i];
        if (newRen >= 0 && newRen < rens &&
            newCol >= 0 && newCol < cols && 
            grid[newRen][newCol] == solution[pos]) {

            output[pos] = moveNames[i];
            if (backtracking(newRen, newCol, pos + 1)) {
                return true;
            }
        }
    }

    return false;
}

int main(int argc, char* argv[]) {
    int cases, initialRen, initialCol;

    cin >> cases;
    while(cases--) {
        cin >> rens >> cols;

        for (int i = 0; i < rens; i++) {
            cin >> grid[i];
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == '@') {
                    initialRen = i;
                    initialCol = j;
                }
            }
        }

        backtracking(initialRen, initialCol, 0);
    }
    return 0;
}