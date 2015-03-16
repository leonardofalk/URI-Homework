#include <iostream>
#include <cmath>

using namespace std;

long long int gcd(long long int  a, long long int  b) {
    if (b > 0 and a > b) {
        return gcd(b, a % b);
    } else {
        return a;
    }
}

int main() {
    int times;
    string a, b;
    cin >> times;

    for (int i = 1; i <= times; i++) {
        cin >> a >> b;
        long long int val1 = strtol(a.c_str(), NULL, 2), val2 = strtol(b.c_str(), NULL, 2);

        if (val2 > val1) {swap(val1, val2);}

        if (gcd(val1, val2) > 1) {
            cout << "Pair #" << i << ": All you need is love!\n";
        } else {
            cout << "Pair #" << i << ": Love is not all you need!\n";
        }
    }

    return 0;
}
