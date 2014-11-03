#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

/* using 'stable_sort' seems to work while 'sort' gives wrong answer of 50 % */

using namespace std;

bool comp(string a, string b) {
    return a.size() > b.size();
}

int main() {
    int times; string line, temp;
    
    cin >> times;
    cin.get();
    
    while(times--) {
        vector<string> words;
        
        getline(cin, line);
        
        stringstream split(line);
        
        while (split >> temp) {
            words.push_back(temp);
        }
        
        stable_sort(words.begin(), words.end(), comp);
        
        int tam = words.size();
        
        for (int i = 0; i < tam; i++) {
            cout << words[i] << ((i != tam-1) ? " " : "\n");
        }
    }
    
    return 0;
}
