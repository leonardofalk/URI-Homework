#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
 
using namespace std;
 
int main() {
    int times, maxVal;
    string phrase;
     
    cin >> times;
    cin.get();
     
    for (int x = 1; x <= times; x++) {
        int letters[26] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
        maxVal = 0;
         
        getline(cin, phrase);
        transform(phrase.begin(), phrase.end(), phrase.begin(), ::tolower);
         
        int phraseSize = phrase.size();
         
        for (int i = 0; i < phraseSize; i++) {
            if (isalpha(phrase[i])) {
                int pos = phrase[i]-97;
                letters[pos]++;
                maxVal = max(maxVal, letters[pos]);
            }
        }
         
        for (int i = 0; i < 26; i++) {
            if (letters[i] >= maxVal) {
                cout << char(i+97);
            }
        }
         
        cout << endl;
    }
}
