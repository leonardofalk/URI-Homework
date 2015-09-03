#include <iostream>
#include <cstdio>
#include <cstdlib>
 
#define VARTYPE int
 
using namespace std;
 
struct nodo {
    nodo *esquerda;
    VARTYPE informacao;
    nodo *direita;
    nodo (VARTYPE info):
        informacao(info),
        esquerda(0),
        direita (0) {}
};
 
nodo *P;
 
struct nodo *insere (nodo *tree, VARTYPE informacao) {
    if (tree == NULL){
        tree = new nodo (informacao);
    } else if (informacao < tree->informacao){
        tree->esquerda = insere(tree->esquerda, informacao);
    } else if ( informacao > tree->informacao ){
        tree->direita = insere(tree->direita, informacao);
    }
    return tree;
};
 
 
struct nodo *GetMax(nodo *tree) {
    if (tree->direita == NULL) {
        P = tree;
        tree = tree->esquerda;
    } else {
        tree->direita = GetMax(tree->direita);
    }
 
    return tree;
};
 
struct nodo *retira(nodo *tree, VARTYPE informacao) {
    if (tree == NULL) {
        cout << "Elemento nao encontrado" << endl;
    } else {
        if (informacao == tree->informacao) {
            P = tree;
 
            if (tree->esquerda == NULL) {
                tree = tree->direita;
            } else {
                if (tree->direita == NULL) {
                    tree = tree->esquerda;
                } else {
                    tree->esquerda = GetMax(tree->esquerda);
                    tree->informacao = P->informacao;
                }
 
                free(P);
            }
        } else {
            if (informacao < tree->informacao) {
                tree->esquerda = retira(tree->esquerda, informacao);
            } else {
                tree->direita = retira(tree->direita, informacao);
            }
        }
    }
 
    return tree;
};
 
void infixa (nodo *tree) {
    if (tree != NULL){
        infixa(tree->esquerda);
        cout << " " << tree->informacao;
        infixa(tree->direita);
    }
}
 
void posfixa(nodo *tree) {
    if (tree != NULL){
        posfixa(tree->esquerda);
        posfixa(tree->direita);
        cout << " " << tree->informacao;
    }
}
 
void prefixa(nodo *tree) {
    if (tree != NULL){
        cout << " " << tree->informacao;
        prefixa(tree->esquerda);
        prefixa(tree->direita);
    }
}
 
int main(){
    int testCases, elementos, valor;
    cin >> testCases;
    nodo *raiz;
     
    for (int i = 1; i <= testCases; i++) {
        raiz = 0;
        cout << "Case " << i << ":\n";
        cin >> elementos;
         
        while (elementos--) {
            cin >> valor;
            raiz = insere(raiz, valor);
        }
         
        cout << "Pre.:"; 
        prefixa(raiz);
        cout << endl;
        cout << "In..:";
        infixa(raiz);
        cout << endl;
        cout << "Post:";
        posfixa(raiz);
        cout << endl << endl;
    }
     
    return 0;
}
