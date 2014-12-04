#include <iostream>			/// cin/cout
#include <string>			/// string/size

using namespace std;

int main() {
	int x;
	string path;
	
	while (cin >> path >> x) {
		int num = 0, tam = path.size()-1, backup_x = x;
		
		/// loop pra percorrer a string lida
		for (int i = 0; i <= tam; i++) {
			if (path[i] == 'W') {
				/// se a letra lida for 'W' então temos 2 possibilidades:
				/// se a letra anterior for 'R' e o ciclo nao estiver terminado
				/// entao somamos 2, pois o no outro if a sentença usada nao determina
				/// se o ciclo ja terminou, portanto somamos ele aqui
				if (i > 0 and path[i - 1] == 'R' and x >= 1 and x != backup_x) {
					num += 2;
				} else {
					/// se a situação de cima nao ocorrer, apenas somamos uma operação
					num++;
				}
				
				/// de qualquer jeito, resetamos a variavel de ciclos
				x = backup_x;
			} else if (path[i] == 'R') {
				/// aqui tambem ha 2 possibilidades, ou o ciclo estao no fim
				/// ou é a ultima letra da string lida, que tambem determina o fim
				/// de um ciclo, portanto somamos em qualquer uma das alternativas
				if (x <= 1 or i == tam) {
					num++;
					x = backup_x;
				} else {
					/// se nenhuma das 2 situações ocorrer entao
					/// é apenas mais um passo do ciclo
					x--;
				}
			}
		}
		
		cout << num << endl;
	}
	
	return 0;
}
