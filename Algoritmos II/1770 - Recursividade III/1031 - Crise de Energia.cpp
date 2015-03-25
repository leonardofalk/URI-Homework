#include <iostream>

using namespace std;

int x;

int josephus(int n, int k) {
    if (n == 1) return 1;
    if (n == x) return ((josephus(n - 1, k) + n - 1) % n) + 1;

    return ((josephus(n - 1, k) + k - 1) % n) + 1;
}

int main() {
    while (cin >> x) {
        if (x == 0) {
            break;
        }

        int step = 1;

        while (1 + josephus(x-1, step) != 13) {
            step++;
        }

        cout << step << endl;
    }

    return 0;
}
