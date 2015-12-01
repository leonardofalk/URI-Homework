#include <iostream>
#include <vector>
#include <stdio.h>
#include <iomanip>
 
#define rd(f) freopen(f, "r", stdin)
 
using namespace std;
 
int knapsack(int weight[], int value[], int arraySize, int maximumWeight) {
    int t[21][31], a, b;
 
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
 
    #ifndef ONLINE_JUDGE
        for (int i = 0; i <= arraySize; i++) {
            for (int j = 0; j <= maximumWeight; j++) {
                cout << setw(3) << t[i][j];
            }
 
            cout << endl;
        }
    #endif // ONLINE_JUDGE
 
    return t[arraySize][maximumWeight];
}
 
int main() {
    int arraySize, maximumWeight;
 
    #ifndef ONLINE_JUDGE
        rd("1286.in");
    #endif
 
    while (cin >> arraySize) {
        if (arraySize == 0) {
            break;
        }
 
        int weight[arraySize + 1]; weight[0] = 0;
        int value[arraySize  + 1]; value[0]  = 0;
 
        cin >> maximumWeight;
 
        for (int i = 1; i <= arraySize; i++) {
            cin >> value[i] >> weight[i];
        }
 
        cout << knapsack(weight, value, arraySize, maximumWeight) << " min.\n";
    }
}
