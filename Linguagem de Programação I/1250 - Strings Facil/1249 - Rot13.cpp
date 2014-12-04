#include <iostream>

using namespace std;

int main() {
    string linha;
    char c;
    
    while (getline(cin,linha)) {
    	int tam = linha.size();
    	
        for (int i = 0; i < tam; i++) {
        	/// isalpha retorna true se for uma letra do alfabeto, se nao então falso
            if(isalpha(linha[i])) {
            	/// isupper retorna true se a letra é maiuscula, se não então falso
                if(isupper(linha[i])) {
                	/// se a linha atual mais 13 ultrapassar 90 ('Z') então fazemos o modulo por 91
                	/// retornando ao estado a partir do inicio da lista de caracteres
                    c = ((linha[i] + 13) % 91);
                    
                    if (c < 40) {
                        c = c + 'A';
                    }
                } else {
                	/// se a linha atual mais 13 ultrapassar 123 ('z') então fazemos o modulo por 123
                	/// retornando ao estado a partir do inicio da lista de caracteres
                    c = ((linha[i]+13)%123);
                    
                    if (c < 40) {
                        c = c + 'a';
                    }
                }
                
                cout << c;
            } else {
                cout << linha[i];
            }
        }
        
        cout << endl;
    }
    
    return 0;
}
