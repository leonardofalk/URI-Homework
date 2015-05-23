#include <iostream>
#include <cstdio>
#define Vertex int
#define maxV 10000

using namespace std;

int cnt, lbl[maxV];
int V,A, adj[25][25];
string espacos="";
int entrou = 0;

void pathR (Vertex v,string espacos) {
    Vertex w;
    lbl[v] = cnt++;
    espacos = espacos + "  ";
    for (w = 0; w < V; w++) {
        if (adj[v][w] == 1) {
            entrou = 1;
            cout << espacos << v << "-" << w ;
            if (lbl[w] == -1) { // se nao percorreu ainda
                cout << " pathR(G," << w << ")" << endl;
                pathR(w,espacos);
            } else {
                cout << endl;;
            }
        }
    }
}

int DIAGRAPHpath(void) {
    Vertex v;
    for(v=0; v<V; v++) {
        lbl[v]=-1;
    }

    cnt =0;
    for (v = 0; v < V; v++) {
        if (lbl[v] == -1) {
            entrou=false;
            pathR (v,espacos);
            if (entrou) cout << endl;
        }
    }
}

int main() {
    int orig,dest;
    int casos;
    cin>> casos;

    for(int u=1; u<=casos; u++) {
        cin >> V;

        for (int i=0; i<V; i++) {
            for (int j=0; j<V; j++) {
                adj[i][j]=0;
            }
        }
        cin >> A;
        for (int i=0; i<A; i++) {
            cin >> orig >> dest;
            adj[orig][dest]=1;

        }
        cout << "Caso " << u << ":" << endl;
        DIAGRAPHpath();
    }
    return 0;
}
