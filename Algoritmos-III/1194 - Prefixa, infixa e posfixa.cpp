#include <iostream>
 
using namespace std;
 
int current;
 
void BT(string prefixa, string infixa, int p, int q) {
    if (p <= q) {
        current++;
        int pos = infixa.find(prefixa[current]);
        BT(prefixa, infixa, p, pos-1);
        BT(prefixa, infixa, pos+1, q);
        cout << infixa[pos];
    }
}
 
int main() {
    int testCases;
     
    cin >> testCases;
     
    for (int i = 1; i <= testCases; i++) {
        current = -1;
        int n;
        string pre, in;
         
        cin >> n >> pre >> in;
         
        BT(pre, in, 0, n-1);
        cout << endl;
    }
}
