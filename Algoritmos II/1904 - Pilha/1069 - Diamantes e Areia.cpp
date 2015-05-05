#include <iostream>

using namespace std;

int main() {
    int testCases;

    cin >> testCases;

    while(testCases--) {
        string entry; int a = 0, cont = 0, stringSize;

        cin >> entry; stringSize = entry.size();

        for (int i = 0; i < stringSize; i++) {
            if (entry[i] == '<') {
                a++;
            } else if (entry[i] == '>' && a > 0) {
                cont++; a--;
            }
        }

        cout << cont << endl;
    }

    return 0;
}
