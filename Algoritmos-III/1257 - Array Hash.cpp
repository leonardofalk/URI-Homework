#include <iostream>
#ifndef ONLINE_JUDGE
    #include <cstdio>
#endif
 
using namespace std;
 
int main() {
    int testCases, n; string line;
 
    #ifndef ONLINE_JUDGE
       // freopen("leo.in", "r", stdin);
    #endif
 
    cin >> testCases;
 
    while (testCases--) {
        cin >> n; cin.get();
 
        int val = 0;
 
        for (int x = 0; x < n; x++) {
            getline(cin, line);
            int val2 = 0;
 
            for (int i = 0; line[i] != '\0'; i++) {
                val2 += x + i + int(line[i]-'A');
            }
 
            val += val2;
        }
 
        cout << val << endl;
    }
}
