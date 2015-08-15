#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
  
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
  
  
  
int main(){
    string prefixa, infixa;
     
    while (cin >> prefixa >> infixa) {
        current = -1;
        BT(prefixa, infixa, 0, prefixa.size()-1);
        cout << endl;
    }
     
    return 0;
}
