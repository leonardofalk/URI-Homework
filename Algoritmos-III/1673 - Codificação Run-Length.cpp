#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
  
#define rd(fl) freopen(fl, "r", stdin);
  
using namespace std;
  
string createString(string str) {
    int tam = str.size();
  
    if (tam == 1) {
        if (str == "1") {
            return "11";
        } else {
            return str;
        }
    } else {
        string answer = "";
  
        while (tam > 9) {
            answer += "9";
            answer += str[0];
            tam -= 9;
        }
  
        answer += ('0' + tam);
        answer += str[0];
         
        if (tam == 1) {
            answer += "1";
        }
  
        return answer;
    }
  
    return "";
}
  
int main() {
    string line;
  
    #ifndef ONLINE_JUDGE
        rd("1673.in")
    #endif // ONLINE_JUDGE
  
    while (getline(cin, line)) {
        int i = 0;
        vector<string> parts;
  
        while (line[i] != '\0') {
            char lastChar = line[i];
            string temp = "";
  
            temp += lastChar;
  
            while (line[++i] == lastChar) {
                temp += lastChar;
            }
  
            i--;
  
            parts.push_back(createString(temp));
            i++;
        }
  
        string ans = "";
  
        for (int a = 0, b = parts.size(); a < b; a++) {
            int tam = parts[a].size();
  
            if (tam > 1) {
                if (tam == 2 && parts[a][0] == '1') {
                    ans += parts[a];
                } else {
                    if (ans != "") {
                        cout << 1 << ans << 1;
                        ans = "";
                    }
  
                    cout << parts[a];
                }
            } else {
                ans += parts[a];
            }
        }
  
        if (ans != "") {
            cout << "1" + ans + "1";
        }
  
        cout << endl;
    }
}
