#include <iostream>
#include <stack>

using namespace std;

int main () {
    int i, atual, n, top, vetor[1005];

    while (cin>> n and n) {
        while (cin >> vetor[0] and vetor[0]) {
            for (i = 1; i < n; i++) {
                cin >> vetor[i];
            }

            stack <int> pilha;
            atual = 0;

            for (i = 1; i <= n; i++) {
                pilha.push(i);

                while (pilha.size() > 0 && vetor[atual] == pilha.top()) {
                    atual++;
                    pilha.pop();
                }
            }

            cout << ((pilha.size() == 0) ? "Yes" : "No") << endl;
        }

        cout << endl;
    }
}
