#include <iostream>			/// cin/ cout
#include <string>			/// string/size/substr

using namespace std;

int main() {
	int x;
	string a, b, c;
	
	cin >> x;
	
	while (x--) {
		c = "";
		cin >> a >> b;
		
		int atam = a.size(), btam = b.size();
		
		/// variavel do tipo size_t é unsigned, propria para funções de string
		size_t maxsize = min(atam, btam);
		
		/// concatena os valores na variavel c até o numero de caracteres
		/// minimo que as duas palavras contem
		for (int i = 0; i < maxsize; i++) {
			c = c + a[i] + b[i];
		}
		
		/// junta o resto da string que sobrou apos a metade em diante 'maxsize'
		if (atam > btam) {
			/// substr retorna uma nova string a partir da string dada,
			/// na posição 'maxsize' em até 'atam-maxsize' caracteres
			c = c + a.substr(maxsize, atam-maxsize);
		} else if (btam > atam) {
			c = c + b.substr(maxsize, btam-maxsize);
		}
		
		cout << c << endl;
	}
	
	return 0;
}
