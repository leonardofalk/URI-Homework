#include <iostream>
#include <stack>
#include <cstdio>

using namespace std;


int main() {
    int n;
    char enTrem[27], saTrem[27];
    while(cin >> n and n) {
        for (int i=0; i<n; i++){
            cin >> enTrem[i];
        }
        for (int i=0; i<n; i++){
            cin >> saTrem[i];
        }

        stack<char> pilha;
        int cont=0;
        for (int i=0; i<n; i++) {
            pilha.push(enTrem[i]);
            cout << "I";
            while (pilha.size() > 0 and saTrem[cont]==pilha.top()){
                cont++;
                pilha.pop();
                cout << "R";
            }
        }
        if (pilha.size() != 0) {
            cout << " Impossible";
        }
        cout << endl;
    }

    return 0;
}
