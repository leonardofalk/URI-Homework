#include <iostream>
#include <cstdio>
#include <stack>
#include <queue>

using namespace std;

int main(){

    int N;

    while( cin >> N ) {

        bool ehFila = true, ehPilha = true, ehPQ = true;

        priority_queue<int> pq;
        queue<int> fila;
        stack<int> pilha;
        int acao, X;

        for(int i=0;i<N;i++){

            cin >> acao >> X;
            if(acao == 1){
                fila.push(X);
                pilha.push(X);
                pq.push(X);
            }
            if(acao == 2){

                if(pilha.top() != X){
                    ehPilha = false;
                } else {
                    pilha.pop();
                }
                if(fila.front() != X){
                    ehFila = false;
                } else{
                    fila.pop();
                }
                if(pq.top() != X){
                    ehPQ = false;
                } else {
                    pq.pop();
                }
            }
        }

        if (!ehPilha and !ehFila and !ehPQ){
            cout << "impossible" << endl;
        } else if (ehPilha and ehPQ){
            cout << "not sure" << endl;
        } else if (ehPilha and ehFila){
            cout << "not sure" << endl;
        } else if (ehPQ and ehFila){
            cout << "not sure" << endl;
        } else if (ehPQ){
            cout << "priority queue" << endl;
        } else if (ehFila){
            cout << "queue" << endl;
        } else if (ehPilha){
            cout << "stack" << endl;
        }
    }
    return 0;
}
