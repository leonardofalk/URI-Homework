#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

vector<int> primeNumbers;

int GLOBAL_COUNTER = 0;

int josephus(int n, int k) {
    if (n == 1) {
        return 1;
    }

    k = primeNumbers[GLOBAL_COUNTER++];

    return ((josephus(n - 1, k) + k - 1) % n) + 1;
}

int main() {
    for (int i = 2; i <= 32621; i++) {
        if (i > 3) {
            bool isPrime = true;

            for (int j = sqrt(i); j >= 2; j--) {
                if (i % j == 0) {
                    isPrime = false;
                    break;
                }
            }

            if (isPrime) {
                primeNumbers.push_back(i);
            }
        } else {
            primeNumbers.push_back(i);
        }
    }

    int num;

    while (cin >> num) {
        if (num > 0) {
            GLOBAL_COUNTER = 0;

            cout << josephus(num, 0) << endl;
        } else {
            break;
        }
    }

    return 0;
}
