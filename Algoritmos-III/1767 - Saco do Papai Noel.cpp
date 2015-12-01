#include <iostream>
#include <vector>
#include <stdio.h>
#include <iomanip>

#define rd(f) freopen(f, "r", stdin)

using namespace std;

struct stc {
    int value = 0;
    int packs = 0;
};

stc t[301][51], a, b;

int maximumWeight, qtdPacks;

stc knapsack(int weight[], int value[], int arraySize, int maximumWeight) {
    for (int col = 0; col <= maximumWeight; col++) {
        t[0][col].value = 0;

        for (int i = 1; i <= arraySize; i++) {
            a = t[i - 1][col];

            if (weight[i] > col){
                b = t[0][col];
            } else {
                b = t[i - 1][col - weight[i]];
                b.value += value[i];
            }

            if (a.value >= b.value) {
                t[i][col] = a;
            } else if (a.value < b.value) {
                t[i][col] = b;
                t[i][col].packs++;
            }
        }
    }

    return t[arraySize][maximumWeight];
}

int findBestWeight() {
    int best = -1, pos = 0;

    for (int weight = 1; weight <= 50; weight++) {
        if (t[maximumWeight][weight].value > best) {
            best = t[maximumWeight][weight].value;
            pos = weight;
        }
    }

    return pos;
}

int main() {
    int testCases;

    #ifndef ONLINE_JUDGE
        rd("1767.in");
    #endif

    cin >> testCases;

    for (int i = 0; i < testCases; i++) {
        qtdPacks = 0;

        cin >> maximumWeight;

        int weight[maximumWeight + 1]; weight[0] = 0;
        int value[maximumWeight  + 1]; value[0]  = 0;

        for (int i = 1; i <= maximumWeight; i++) {
            cin >> value[i] >> weight[i];
        }

        stc ans = knapsack(weight, value, maximumWeight, 50);

        cout << ans.value << " brinquedos\n";

        int packs = findBestWeight();

        cout << "Peso: " << packs << " kg\n";
        cout << "sobra(m) " << maximumWeight - ans.packs << " pacote(s)\n\n";
    }
}
