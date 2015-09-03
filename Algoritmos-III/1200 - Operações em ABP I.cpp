#include <iostream>
 
#define VARTYPE string
 
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
 
string toshow = "";
 
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
 
bool busca(nodo *tree, VARTYPE k) {
    if (tree == NULL) {
        return 0;
    } else if (tree->informacao == k) {
        return 1;
    }
 
    if (tree->informacao > k) {
       return busca (tree->esquerda, k);
    } else {
       return busca (tree->direita, k);
    }
}
 
void infixa (nodo *tree) {
    if (tree != NULL) {
        infixa(tree->esquerda);
        toshow += " " + tree->informacao;
        infixa(tree->direita);
    }
}
 
void posfixa(nodo *tree) {
    if (tree != NULL) {
        posfixa(tree->esquerda);
        posfixa(tree->direita);
         toshow += " " + tree->informacao;
    }
}
 
void prefixa(nodo *tree) {
    if (tree != NULL) {
        toshow += " " + tree->informacao;
        prefixa(tree->esquerda);
        prefixa(tree->direita);
    }
}
 
int main(){
    string line;
    nodo *tree = 0;
 
    while (cin >> line) {
        if (line == "INFIXA") {
            infixa(tree);
            cout << toshow.substr(1) << endl;
            toshow = "";
        } else if (line == "POSFIXA") {
            posfixa(tree);
            cout << toshow.substr(1) << endl;
            toshow = "";
        } else if (line == "PREFIXA") {
            prefixa(tree);
            cout << toshow.substr(1) << endl;
            toshow = "";
        } else {
            VARTYPE ch;
 
            cin >> ch;
 
            if (line == "I") {
                tree = insere(tree, ch);
            } else if (line == "P") {
                if (busca(tree, ch)) {
                    cout << ch << " existe\n";
                } else {
                    cout << ch << " nao existe\n";
                }
            }
        }
    }
 
    return 0;
}
