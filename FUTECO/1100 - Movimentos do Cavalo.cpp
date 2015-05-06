#include <iostream>
#define TAM 9
#define INFINITO 999999999

using namespace std;


typedef struct {
    int origem;
    int destino;
    int peso;
} ARESTA;


ARESTA arestas[350];


int BellmanFord(int n_arestas, int n_nodos, int origem, int destino) {
    int i,j,trocou=1;
    int distancia[65];

    for (i = 0; i < n_nodos; i++) {
        distancia[i] = INFINITO;
    }

    distancia[origem]=0;

    for (i = 0; i < n_nodos && trocou; i++) { // se nenhuma iteração teve efeito, ~trocou portanto sai
        trocou = 0;
        for (j = 0; j < n_arestas; j++) {
            if (distancia[arestas[j].destino] > distancia[arestas[j].origem] + arestas[j].peso) {
                distancia[arestas[j].destino] = distancia[arestas[j].origem] + arestas[j].peso;
                trocou=1;
            }
        }
    }
    return distancia[destino];
}


int main() {

    int tabuleiro[TAM][TAM];

    int cont = 1, i, j;
    for (int i=1; i<TAM; i++) {
        for (int j=1; j<TAM; j++) {
            tabuleiro[i][j] = cont++;

        }
    }

    //flood-fill
    cont = 0;
    for(int i = 1; i < TAM; i++) {
        for(int j = 1; j < TAM; j++) {
            if( (i + 1) < TAM && (j + 2) < TAM ) {
                //1+1, 1+2 (2,3) OK
                arestas[cont].origem = tabuleiro[i][j];
                arestas[cont].destino = tabuleiro[i + 1][j + 2];
                arestas[cont].peso = 1;
                cont++;
            }
            if( (i + 1) < TAM && (j - 2) >= 1 ) {
                arestas[cont].origem = tabuleiro[i][j];
                arestas[cont].destino = tabuleiro[i + 1][j - 2];
                arestas[cont].peso = 1;
                cont++;
            }
            if( (i + 2) < TAM && (j + 1) < TAM ) {
                arestas[cont].origem = tabuleiro[i][j];
                arestas[cont].destino = tabuleiro[i + 2][j + 1];
                arestas[cont].peso = 1;
                cont++;
            }
            if( (i + 2) < TAM && (j - 1) >= 1 ) {
                arestas[cont].origem = tabuleiro[i][j];
                arestas[cont].destino = tabuleiro[i + 2][j - 1];
                arestas[cont].peso = 1;
                cont++;
            }
            if( (i - 1) > 0 && (j + 2) < TAM ) {
                arestas[cont].origem = tabuleiro[i][j];
                arestas[cont].destino = tabuleiro[i - 1][j + 2];
                arestas[cont].peso = 1;
                cont++;
            }
            if( (i - 1) > 0 && (j - 2) >= 1 ) {
                arestas[cont].origem = tabuleiro[i][j];
                arestas[cont].destino = tabuleiro[i - 1][j - 2];
                arestas[cont].peso = 1;
                cont++;
            }
        }
    }

    int origem = 1;
    int destino = 8;
    cout << BellmanFord(cont, 64, origem, destino);



    return 0;
}
