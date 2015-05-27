#include <iostream>
#include <queue>
#include <iomanip>
#include <stdio.h>

using namespace std;

int v[1000];

int main() {

    int N, K, M;
    int sel1, sel2, cont, i;
    int pos1, pos2;

    while(cin >> N >> K >> M and N){
        pos1 = 0;
        pos2 = N-1;
        for(i=0;i<N;i++){
            v[i] = i+1;
        }

        cont = 0;

        while(cont < N){

            i = K;
            while (i > 0){
                if(v[pos1] > 0){
                    i--;
                }
                if(i==0){
                    sel1 = pos1;
                }
                pos1 = (pos1+1)%N;
            }

            i = M;
            while(i > 0){
                if(v[pos2] > 0){
                    i--;
                }
                if(i==0){
                    sel2=pos2;
                }
                pos2 = (pos2+N-1)%N;
            }

            if(cont > 0){
                cout <<",";
            }
            if(sel1 != sel2){
                ///cout << setw(3) << v[sel1] << setw(3) << v[sel2];
                printf("%3d%3d",v[sel1],v[sel2]);
                cont += 2;
            } else {
                ///cout << setw(3) << v[sel1];
                printf("%3d", v[sel1]);
                cont++;
            }
            v[sel1] = 0;
            v[sel2] = 0;
        }

        cout << endl;
    }

    return 0;
}
