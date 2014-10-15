#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
 
using namespace std;
 
 
string jantar(string dieta, string cafe, string almoco){
    int pos;
 
 
    for (int i=0; i<cafe.size(); i++){
        int pos = dieta.find(cafe[i]);
            if (pos<0){
                return "CHEATER";
            }
            dieta.erase(pos,1);
        }
 
    for (int i=0; i<almoco.size(); i++){
        pos = dieta.find(almoco[i]);
            if (pos<0){
                return "CHEATER";
            }
            dieta.erase(pos,1);
        }
 
 
 
 
 
 
    sort (dieta.begin(),dieta.end());
    return dieta;
 
}
 
 
int main(){
 
    //freopen ("1248.in", "r", stdin);
    string dieta, cafe, almoco, janta;
    int N;
    cin >> N;
    cin.get();
    while(N--){
        getline (cin,dieta);
        getline (cin,cafe);
        getline (cin,almoco);
 
    cout << jantar(dieta,cafe,almoco) << endl;
    }
 
    return 0;
}
