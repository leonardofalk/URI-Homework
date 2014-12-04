#include <iostream>
#include <string>
#include <sstream>
 
using namespace std;
 
int main () {
	int times;
	
	/// le o numero de casos de teste
	cin >> times;
	/// le a linha nova pra limpar o buffer
	cin.get();
	
	for (int i = 1; i <= times; i++) {
		string words, word, final = "";
		
		/// pega a linha da frase e guarda
		getline(cin, words);
		/// cria uma stream com a frase inteira
		stringstream palavras(words);
		/// separa as palavras da frase
		while (palavras >> word) {
			/// pega a primeira letra de cada palavra e concatena no valor final
			final = final + word[0];
		}
		/// mostra o valor final
		cout << final << endl;
	}
	
	return 0;
}
