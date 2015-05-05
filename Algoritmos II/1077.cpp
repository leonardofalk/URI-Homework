#include <iostream>
#include <string>
#include <cstdio>
#include <stack>
 
 
using namespace std;
 
 
int main() {

    string entrada;
    char elemento;
    stack <char> pilha;
 
    char prioridade[120];
    prioridade['(']=0;
    prioridade['+']=1;
    prioridade['-']=1;
    prioridade['*']=2;
    prioridade['/']=2;
    prioridade['^']=3;
    
    int n;
    cin >> n;
    
    while(n--){
    
        cin >> entrada;
        
        for (int i=0; i<entrada.size(); i++) {
            elemento = entrada[i];
            if (elemento == '-' or elemento == '+' or elemento == '/' or elemento == '^' or elemento == '*' or elemento == '(' or elemento == ')' ){
                if (pilha.size() == 0 or elemento == '(') {
                    pilha.push(elemento);
                } else if (elemento == ')'){
                    while(pilha.size()>0 and pilha.top() != '(' ) {
                        cout << pilha.top();
                        pilha.pop();
                    }
                    pilha.pop();
                } else {
                        while (pilha.size() > 0  and prioridade[elemento] <= prioridade[pilha.top()]) {
                        cout << pilha.top();
                        pilha.pop();
                    }
                    pilha.push(elemento);
                }
            } else {
                cout << elemento;
            }
        }

        while (pilha.size() > 0) {
            cout << pilha.top();
            pilha.pop();
        }
 
        cout << endl;
    }
 
 
    return 0;
}
