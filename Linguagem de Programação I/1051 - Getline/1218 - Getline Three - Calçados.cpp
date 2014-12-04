#include iostream
#include string
#include sstream
 
using namespace std;
 
int main() {
    int nx, caso = 1;
    string sexo, todos;
 
    while (cin  nx) {
        int m = 0, f = 0, same = 0, n;
        cin.get();
 
        getline(cin, todos);
 
        stringstream sapatos(todos);
 
        while (sapatos  n  sexo) {
            if (n == nx) {
                same++;
                 
                if (sexo == M) {
                    m++;
                } else {
                    f++;
                }
            }
        }
 
        if (caso  1) {
            cout  endl;
        }
 
        cout  Caso   caso  n;
        cout  Pares Iguais   same  endl;
        cout  F   f  endl;
        cout  M   m  endl;
        caso++;
    }
}