#include <iostream>
 
using namespace std;
int main() {
    string linha;
    char c;
    while (getline(cin,linha)) {
        for (int i=0; i<linha.size(); i++) {
            if(isalpha(linha[i])) {
                if(isupper(linha[i])) {
                    c = ((linha[i]+13)%91);
                    if (c < 40) {
                        c=c+'A';
                    }
                } else {
                    c = ((linha[i]+13)%123);
                    if (c < 40) {
                        c=c+'a';
                    }
                }
                cout <<c;
            } else {
                cout << linha[i];
            }
        }
        cout <<endl;
    }
    return 0;
}
