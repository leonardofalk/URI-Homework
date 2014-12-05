#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
 
using namespace std;
 
int main() {
    double t, price, totalp = 0, totalf = 0;
    string fruit, fruits;
 
    cin >> t;
 
    for (int i = 1; i <= t; i++) {
        cin >> price;
        cin.get();
        totalp += price;
        getline(cin, fruits);
 
        stringstream DIVIDE_STRING(fruits);
        /*
			eplicação de como funciona 'stringstream'
			string base: "banana melancia uva tomate"
			
			stringstream split("banana melancia uva tomate")
			
			Vai simular um loop com 4 saidas, como se fossem 4 valores lidos com 'cin' linha por linha
			
			1ª volta do laço
			split >> str; => "banana"
			2ª volta do laço
			split >> str; => "melancia"
			3ª volta do laço
			split >> str; => "uva"
			4ª volta do laço
			split >> str; => "tomate"
			
			A variavel pode ser a mesma pois a cada volta ele sobrescreve o valor na mesma.
        */
        
        int f = 0;
        
        while (DIVIDE_STRING >> fruit) {
        	/*
        		a cada fruta lida soma um valor no contador
        		o nome delas nao é importante nesse caso e sim a quantidade
        	*/
            f++;
        }
        
        totalf += f;
        cout << "day " << i << ": " << f << " kg\n";
    }
 
    cout << fixed << setprecision(2);
    cout << totalf / t << " kg by day\n";
    cout << "R$ " << totalp / t << " by day\n";
}
