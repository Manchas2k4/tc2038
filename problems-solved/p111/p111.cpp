#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <cctype>

using namespace std;

const int SIZE = 30;

int correct[SIZE], input[SIZE], M[SIZE][SIZE];
int n;

int solve() {
    for (int i = 0; i <= n; i++) {
        M[i][0] = 0;
    }

    for (int j = 0; j <= n; j++) {
        M[0][j] = 0;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if  (correct[i] == input[j]) {
                M[i][j] = M[i - 1][j - 1] + 1;
            } else {
                M[i][j] = max(M[i - 1][j], M[i][j - 1]);
            }
        }
    }

    return M[n][n];
}

int main(int argc, char* argv[]) {
    int position;
    string line;
    
    getline(cin, line);
    n = stoi(line);
    
    getline(cin, line);
    stringstream in(line);
    for (int i = 1; i <= n; i++) {
        in >> position;
        correct[position] = i;
    }

    while(getline(cin, line)) {
        stringstream in(line);
        for (int i = 1; i <= n; i++) {
            in >> position;
            input[position] = i;
        }
        cout << solve() << "\n"; 
    }
    return 0;
}

/*
bool isThereSpaces(const string &s) {
    for (int i = 0; i < s.length(); i++) {
        if (isblank(s[i])) {
            return true;
        }
    }
    return false;
}

int main(int argc, char* argv[]) {
    string line;
    int position;
    bool finished;

    finished = false;
    while(!finished) {
        finished = (getline(cin, line)).eof();

        if (!isThereSpaces(line)) {
            n = stoi(line);
            
            getline(cin, line);
            stringstream in(line);
            for (int i = 1; i <= n; i++) {
                in >> position;
                correct[position] = i;
            }
        } else {
            stringstream in(line);
            for (int i = 1; i <= n; i++) {
                in >> position;
                input[position] = i;
            }
            cout << solve() << "\n"; 
        }
    }
    return 0;
}
*/