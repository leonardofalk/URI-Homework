#include <iostream>		/// cin.cout/cin.get;
#include <string>		/// string/find/erase/begin/end
#include <algorithm>		/// sort

using namespace std;

int main() {
	int times;
	string a, b, c;
	
	cin >> times;
	/// limpa o buffer de linha nova
	cin.get();
	
	for (int i = 1; i <= times; i++) {
		/// le os 3 valores de string
		getline(cin, a); getline(cin, b); getline(cin, c);
		
		/// calcula o tamanho da string de cada valor
		int bsize = b.size(), csize = c.size(), pos;
		/// erro é falso enquanto o usuario nao trapacear
		bool erro = 0;
		
		/// verificando valores do cafe da manha string 'b'
		for (int x = 0; x < bsize; x++) {
			pos = a.find(b[x]);
			
			/// retorna -1 se não achar o char na string
			if (pos == -1) {
				/// usuario trapaceou
				erro = 1;
				/// nao tem porque continuar o loop pois o usuario é cheater
				break;
			} else {
				/// apaga em '1' letra a string na posição dada
				a.erase(pos, 1);
			}
		}
		
		/// verificando valores do almoço string 'c'
		for (int x = 0; x < csize; x++) {
			pos = a.find(c[x]);
			
			if (pos == -1) {
				erro = 1;
				break;
			} else {
				a.erase(pos, 1);
			}
		}
		
		/// se em algum momento a variavel erro for berdadeira entao
		/// o usuario trapaceou na dieta então, senão organizamos a 
		/// string com 'sort' pra deixar em ordem e mostramos a string
		if (!erro) {
			sort(a.begin(), a.end());
			cout << a << endl;
		} else {
			cout << "CHEATER\n";
		}
	}
}
