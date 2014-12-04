#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;

int M;

bool ordenacao (int a, int b){
    if (b%M == a%M){ /// retorna primeiro os impares e depois os pares;
        if(abs(a)%2 ==abs(b)%2){ ///comparando dois pares ou dois impares
            if (a%2 != 0){ ///impares
                return a > b;
            }else{ ///a e b são pares
                return b > a;
            }
        }
        return abs(a)%2 > abs(b)%2; /// impares antes dos pares
    }
    return a%M < b%M;
}

int main() {

    int N, num, dados[10001];

    cin >> N >> M;

    while (N){

        for (int i=0;i<N;i++){
            cin >> dados[i];
        }

        sort (dados,dados+N,ordenacao);

        cout << N << " " << M << endl;

        for(int i=0;i<N;i++){
            cout << dados[i] << endl;
        }


        cin >> N >> M;
    }

    cout << "0 0" << endl;

    return 0;
}

