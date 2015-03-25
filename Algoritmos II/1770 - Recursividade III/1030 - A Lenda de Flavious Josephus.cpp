#include <iostream>

using namespace std;

int josephus(int n, int k) {
    return ((n == 1) ? 1 : ((josephus(n-1,k)+k-1) % n)+1);
}

int main() {
    int times;

    cin >> times;

    for (int i = 1; i <= times; i++) {
        int a, b;

        cin >> a >> b;

        cout << "Case " << i << ": " << josephus(a, b) << endl;
    }
}
