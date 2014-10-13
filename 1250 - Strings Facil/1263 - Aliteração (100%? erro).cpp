#include <iostream>			/// cout/cin
#include <algorithm>		/// transform
#include <string>			/// begin/end/getline
#include <sstream>			/// stringstream

// portal nao diz a porcentagem de erro mas acerta na maioria dos casos de teste (5 de 6)

using namespace std;

int main() {
	string line, word;
	
	while (getline(cin, line)) {
		int times = 0;
		/// qualquer simbolo na var 'last' serve pois vamos comparar com caracteres
		/// do alfabeto 'a'-'z'
		char comp = line[0], last = '=';
		
		/// deixa todos os caracteres da string minusculos para comparação
		/// retirado de:
		/// http://stackoverflow.com/questions/313970/how-to-convert-stdstring-to-lower-case
		transform(line.begin(), line.end(), line.begin(), ::tolower);
		
		/// isso aqui é só pra ajudar a achar os erros
		/// cout << line << endl;
		
		/// recria a entrada com o string stream
		stringstream split(line);
		
		/// daqui pra baixo nem o macguiver entende
		while (split >> word) {
			if (word[0] == comp and word[0] != last) {
				times++;
			}
			
			last = comp;
			comp = word[0];
		}
		
		cout << times << endl;
	}
}
