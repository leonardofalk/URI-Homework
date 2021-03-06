#include <iostream>
#include <vector>
#ifndef ONLINE_JUDGE
    #include <cstdio>
#endif
 
using namespace std;
 
int main() {
    int testCases, cut, tam, n;
 
    #ifndef ONLINE_JUDGE
        freopen("leo.in", "r", stdin);
    #endif
 
    cin >> testCases;
 
    for (int x = 0; x < testCases; x++) {
        if (x) {
            cout << endl;
        }
 
        cin >> cut >> tam;
        vector<int> hashv[cut];
        vector<int>::iterator it;
 
        for (int i = 0; i < tam; i++) {
            cin >> n;
 
            hashv[n % cut].push_back(n);
        }
 
        for (int i = 0; i < cut; i++) {
                cout << i;
            for (it = hashv[i].begin(); it != hashv[i].end(); it++) {
                cout << " -> " << *it;
            }
 
            cout << " -> \\" << endl;
        }
    }
}
