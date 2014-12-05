#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
	map <char, double> duration = {
		/*
			é possivel definir o mapa com os valores prontos dessa forma
			desde que não esteja sendo compilado no codeblocks, recomendo
			usar o compilador online: http://ideone.com
			
			{CHAVE, VALOR},
		*/
		
		{'W', 1.0},
		{'H', 0.5},
		{'Q', 0.25},
		{'E', 0.125},
		{'S', 0.0625},
		{'T', 0.03125},
		{'X', 0.015625},
	};
	
	string notes;
	
	while(getline(cin, notes) and notes[0] != '*') {
		int tam = notes.size(), count = 0;
		double total = 0.0;
		
		for (int i = 0; i < tam; i++) {
			if (notes[i] == '/') {
				/*
					se o caractere lido é a barra então terminou uma seção de valores
					temos que verificar se a seção terminou com 1 segundo pois é o tempo
					exato de cada seção
				*/
				if (total == 1) {
					count++;
				}
				
				/*
				  	reseta o contador de tempo toda vez mesmo estando com valor diferente de 1 segundo
				*/
				total = 0;
			} else {
				/*
					se for diferente de '/' entao é a chave de um dos valores
					só precisa ser somada com o valor correspondente no mapa
				*/
				total += duration[ notes[i] ];	
			}
		}
		
		cout << count << endl;
	}
	
	return 0;
}
