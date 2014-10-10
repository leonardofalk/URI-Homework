#include <iostream>		/// cin/cout
#include <string>		/// string/size

using namespace std;

int main() {
	int times, x;
	string word;
	
	cin >> times;
	
	for (int i = 1; i <= times; i++) {
		cin >> word >> x;
		
		/// se o valor de decodificação 'x' for 0 não precisa calcular nada
		if (x == 0) {
			cout << word << endl;
		} else {
			int tam = word.size();
			
			for (int a = 0; a < tam; a++) {
				/// aqui pegamos cada letra e subtraimos 'x' letras para achar a mensagem
				/// caso esse valor resultante seja menor que 'A' na tabela ascii, somamos
				/// 26 letras para achar o valor de traz pra frente
				word[a] = (word[a] - x) + ((word[a]-x < 'A') ? 26 : 0);
			}
			
			cout << word << endl;
		}
	}
	
	return 0;
}
