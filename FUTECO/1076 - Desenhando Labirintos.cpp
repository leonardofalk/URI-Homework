#include <iostream>
#include <cstdio>
 
#define maxV 10000 /// máximo de vértices
 
using namespace std;
 
int cnt, lbl[maxV], movimentos, cont=0, V, A,G;
int adj[100][100];
 
void pathR (int v) {
    int w;
    lbl[v] = cnt++;
    for (w = 0; w < V; w++) {
           if (adj[v][w] == 1) {
            if (lbl[w] == -1) {
                movimentos++;
                pathR(w);
            }
        }
    }
}
 
void DIGRAPHpath (int origem) {
    int v;
    for (v = 0; v < V; v++) {
        lbl[v] = -1;
    }
    pathR (origem);
}
 
int main(void) {
 
     
    int orig,dest,N,casos,origem;
    cin >> casos;
    while (casos--) {
 
        cin >> origem;
        cin >> V; ///Vertices
 
/// Zera a Matriz de Adj.
        for (int i=0; i<V; i++) {
            for (int j=0; j<V; j++) {
                adj[i][j]=0;
            }
        }
        movimentos=0;
        cin >> A; ///Arestas
        for (int i=0; i<A; i++) {
            cin >> orig >> dest;
            adj[orig][dest]=1;
            adj[dest][orig]=1;
/// se for grafo (ao inves de digrafo (seta p ambas direcoes)
        }
 
        DIGRAPHpath(origem);
        cout << movimentos*2 << endl;
    }
 
    return(0);
}
