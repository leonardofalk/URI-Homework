#include <iostream>
#include <string>
#include <sstream>
 
using namespace std;
 
int main() {
    int nx, caso = 1;
    string sexo, todos;
 
    while (cin  nx) {
        int m = 0, f = 0, same = 0, n;
		cin.get();
 
        getline(cin, todos);
 
        stringstream sapatos(todos);
        /*
        	todos = "01 M 02 F 03 M ...";
        	
        	depois do 'stringstream'
        	
        	sapatos >> str = "01";
        	sapatos >> str = "M";
        	sapatos >> str = "02";
        	sapatos >> str = "F";
        	sapatos >> str = "03";
        	sapatos >> str = "M";
        	...
        	
        	usamos nesse caso 2 variaveis: uma para o numero do calçado e outra para o genero
        	o stringstream vai pegar 2 valores em cada rodada e colocar nessas variaveis
        */
        while (sapatos >> n >> sexo) {
            if (n == nx) {
                same++;
                 
                if (sexo == M) {
                    m++;
                } else {
                    f++;
                }
            }
        }
 
        if (caso > 1) {
            cout << endl;
        }
 
        cout << "Caso: " << caso << endl;
        cout << "Pares Iguais: "<< same << endl;
        cout << "F: " << f << endl;
        cout << "M: " << m << endl;
        caso++;
    }
}
