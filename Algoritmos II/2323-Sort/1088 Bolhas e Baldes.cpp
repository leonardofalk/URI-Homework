#include <iomanip>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

typedef vector<int> vetor;

vetor v;
int cont = 0;

vetor merge(vetor a, vetor b) {
    int i = 0, j = 0, s1 = a.size(), s2 = b.size();
    vetor r;

    while(i  < s1 && j < s2) {
        if(a[i] < b[j]) {
            r.push_back(a[i]);
            i++;
        } else {
            r.push_back(b[j]);
            cont += (a.size()) - i;
            j++;
        }
    }

    while( i < s1) {
        r.push_back(a[i]);
        i++;
    }

    while(j < s2) {
        r.push_back(b[j]);
        j++;
    }

    return r;
}

vetor mergeSort(int esquerda, int direita) {
    vetor r;
    int meio = (esquerda + direita)/2;

    if(esquerda + 1 >= direita) {
        r.push_back(v[esquerda]);
        return r;
    }

    vetor a = mergeSort(esquerda, meio);
    vetor b = mergeSort(meio, direita);
    r = merge(a,b);

    return r;
}

int main () {
    meio
    int n, x;

    while((cin >>n) && n) {
        cont = 0;
        v.clear();

        for(int i = 0; i < n; ++i) {
            cin >> x;
            v.push_back(x);
        }

        mergeSort(0,n);

        if(cont % 2 !=0 ) cout <<"Marcelo"<<endl;
        else cout <<"Carlos"<<endl;
    }

    return 0;

}
