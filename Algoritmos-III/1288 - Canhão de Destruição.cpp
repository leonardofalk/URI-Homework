#include <iostream>

using namespace std;

int knapsack(int weight[], int value[], int arraySize, int maximumWeight) {
    int t[51][101], a, b;

    for (int col = 0; col <= maximumWeight; col++) {
        t[0][col] = 0;

        for (int i = 1; i <= arraySize; i++) {
            a = t[i - 1][col];

            if (weight[i] > col){
                b = 0;
            } else {
                b = t[i - 1][col - weight[i]] + value[i];
            }

            if (a > b) {
                t[i][col] = a;
            } else {
                t[i][col] = b;
            }
        }
    }

    return t[arraySize][maximumWeight];
}

int main() {
    int testCases, capacity, n;

    cin >> testCases;

    while (testCases--) {
        cin >> n;

        int weight[n + 1];
        int value [n + 1];

        for (int i = 1; i <= n; i++) {
            cin >> value[i] >> weight[i];
        }

        int maximumCapacity, castleHP;

        cin >> maximumCapacity >> castleHP;

        int ans = knapsack(weight, value, n, maximumCapacity);

        if (ans >= castleHP) {
            cout << "Missao completada com sucesso\n";
        } else {
            cout << "Falha na missao\n";
        }
    }
}
