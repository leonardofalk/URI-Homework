#include <iostream>
#include <stack>
 
using namespace std;
 
int main () {
    string D;
     
    while(getline(cin, D)) {
        stack<char> s;
        int siz = D.size();
         
        for (int i = 0; i < siz; i++) {
            if (D[i] == '(') {
                s.push('(');
            }
 
            if (D[i] == ')') {
                if (!s.empty()) {
                    s.pop();
                } else {
                    s.push('1');
                }
            }
        }
         
        cout << ((s.empty()) ? "correct" : "incorrect") << endl;
    }
 
    return 0;
}