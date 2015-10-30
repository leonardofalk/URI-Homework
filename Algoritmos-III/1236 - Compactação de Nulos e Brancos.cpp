#include <iostream>
#include <cstdio>

using namespace std;

string getCompressed(string str) {
    int size = str.size();
    string res = "", c = (str[0] == ' ') ? "$" : "#";

    if (size >= 3) {
        while (size > 255) {
            res += c + char(255);
            size -= 255;
        }

        res += c + char(size);
    } else {
        for (int i = 0; i < size; i++) {
            res += str[0];
        }
    }

    return res;
}

void compress(string str) {
    string temp = "";
    int i = 0;

    while (str[i] != '\0') {
        char c = str[i];

        if (c == ' ' || c == '0') {
            while (str[i] == c) {
                temp += str[i];
                i++;
            }

            cout << getCompressed(temp);

            i--;
            temp = "";
        } else {
            cout << c;
        }

        i++;
    }

    cout << "\n";
}

int main() {
    int testCases;
    string line;

    #ifndef ONLINE_JUDGE
        freopen("1236.in", "r", stdin);
    #endif

    cin >> testCases; cin.get();

    while (getline(cin, line)) {
        compress(line);
    }
}
