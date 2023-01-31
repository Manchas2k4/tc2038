#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <list>

using namespace std;

int main(int argc, char* argv[]) {
    vector<string> original(1001);
    vector<string> ordered(1001);
    list<string> result;
    string input;
    int count;
    bool add;

    count = 0;
    while(1) {
        cin >> input;

        if (input == "#") {
            break;
        }

        original[count] = input;

        transform(input.begin(), input.end(), input.begin(), ::toupper);
        sort(input.begin(), input.end());
        ordered[count] = input;

        count++;
    }

    for (int i = 0; i < count; i++) {
        add = true;
        for (int j = 0; j < count; j++) {
            if (i == j) {
                continue;
            }

            if (original[i].size() != original[j].size()) {
                continue;
            }

            if (ordered[i] == ordered[j]) {
                add = false;
            }
        }

        if (add) {
            result.push_back(original[i]);
        }
    }

    result.sort();
    for (string s : result) {
        cout << s << "\n";
    }
    return 0;
}