#include <iostream>			/// cin/cout/cin.get
#include <string>			/// string/size/substr/getline

using namespace std;

/// string:reverse
/// pega uma string e retorna a mesma de traz pra frente
string strev(string str) {
	string rev = "";
	int as = str.size();
	
	for (int i = as - 1; i >= 0; i--) {
		rev = rev + str[i];
	}
	
	return rev;
}

int main() {
	int times;
	
	cin >> times;
	cin.get(); /// limpa o buffer
	
	for (int i = 1; i <= times; i++) {
		string word;
		
		/// le toda a frase
		getline(cin, word);
		
		/// calcula o tamanho total e metade da string
		int wordSize = word.size();
		int mid = wordSize/2;
		
		/// mostra do inicio a metade invertido e da metade em diante invertido
		/// o titulo do problema ja da essa dica de procedimento
		cout << strev(word.substr(0, mid)) + strev(word.substr(mid, wordSize)) << endl;
	}
	
	return 0;
}
