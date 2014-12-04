#include <iostream>     /// cin/cout
/// toupper: [padrao] Converte tudo para maiusculo
/// tolower: [padrao] Converte tudo para minusculo

using namespace std;

int main() {
	string word;
	
	while (getline(cin, word)) {
		/// state == 'numero par' é maiuscula, state == 'impar' é minuscula
		int tam = word.size(), state = 0;
		
		for (int i = 0; i < tam; i++) {
			if (isalpha(word[i])) {
				/// verifica se é par entao é maiuscula senao minuscula
				word[i] = ((state % 2 == 0) ? (toupper(word[i])) : (tolower(word[i])));
				
				/// aumenta o state pois a proxima deve ser o oposto da letra de agora
				state++;
			}
		}
		
		cout << word << endl;
	}
}
