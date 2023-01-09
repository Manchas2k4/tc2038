#include <iostream>
#include <iomanip>
#include <cstring>
#include <vector>

using namespace std;

const int MAX = 1000010;

int primes[MAX];
int nprimes;

void sieve() {
    char isPrime[MAX];

    nprimes = 0; 
    // memset(isPrime, 1, sizeof(isPrime));
    memset(isPrime, 1, sizeof(char) * MAX);
    for (int i = 2; i < MAX; i++) {
        if (isPrime[i] == 1) {
            for (int j = (i * 2); j < MAX; j += i) {
                isPrime[j] = 0;
            }
            primes[nprimes++] = i;
        }
    }
}

int binarySearch(int value) {
    int mid, low, high;

    low = 0;
    high = nprimes;
    while (low <= high) {
        mid = low + ((high - low) / 2);
        if (value == primes[mid]) {
            return mid;
        } else if (value < primes[mid]) {
            high = mid - 1;
        } else { // if (value > primes[mid])
            low = mid + 1;
        }
    }
    return low;
}

int main(int argc, char* argv[]) {
    int i, j, number, acum, cases;

    sieve();
    cases = 1;
    while (1) {
        cin >> number;

        if (number == 0) {
            break;
        }

        i = 0;
        acum = 0;
        while (primes[i] < number) {
            j = binarySearch(number - primes[i]);
            while (i < j) {
                if (primes[i] + primes[j] <= number) {
                    acum += (j - i);
                    break;
                }
                j--;
            }
            i++;
        }
        cout << "Case " << cases++ << ": " << acum << "\n";
    }
    return 0;
}