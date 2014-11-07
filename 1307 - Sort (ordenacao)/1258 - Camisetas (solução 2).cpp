#include <iostream>
#include <algorithm>
#include <cstdio>
 
using namespace std;
 
 
typedef struct {
    string Nome;
    string Cor;
    int Tam;
    char Tamanho;
}Alunos;
 
 
bool ordena( Alunos a, Alunos b){
    if (a.Cor==b.Cor){
        if (a.Tam==b.Tam){
            return (a.Nome < b.Nome);
        }
        return (a.Tam < b.Tam);
    }
    return (a.Cor < b.Cor);
}
 
 
int main(){
    ios::sync_with_stdio(false);
    //freopen("12582.in","r", stdin);
 
    int N;
    char Tam;
    cin >> N;
    cin.get();
 
    Alunos Turma[60];
 
    while (N){
        for (int i=0; i<N; i++){
            getline(cin,Turma[i].Nome);
            cin >> Turma[i].Cor;
            cin >> Turma[i].Tamanho;
            if (Turma[i].Tamanho=='P'){
                Turma[i].Tam=1;
            }
            if (Turma[i].Tamanho=='M'){
                Turma[i].Tam=2;
            }
            if (Turma[i].Tamanho=='G'){
                Turma[i].Tam=3;
            }
            cin.get();
        }
 
    sort(Turma, Turma+N, ordena);
 
        for (int i=0; i<N; i++){
            cout << Turma[i].Cor << " " << Turma[i].Tamanho << " " << Turma[i].Nome << endl;
        }
 
 
        cin >> N;
        cin.get();
        if (N!=0){
            cout << endl;
        }
 
 
    }
 
 
 return 0;
}
