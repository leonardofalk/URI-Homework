#include <iostream>
#include <algorithm>

using namespace std;

struct camisa {
	string cor, tamanho, nome;
};

bool comp(camisa a, camisa b) {
	int atam = ((a.tamanho[0] == 'P') ? 0 : ((a.tamanho[0] == 'M') ? 1 : 2)), btam = ((b.tamanho[0] == 'P') ? 0 : ((b.tamanho[0] == 'M') ? 1 : 2));
	int acor = ((a.cor[0] == 'b') ? 0 : 1), bcor = ((b.cor[0] == 'b') ? 0 : 1);
	
	if (acor == bcor) {
		if (atam == btam) {
			return a.nome < b.nome;
		} else {
			return atam < btam;
		}
	} else {
		return acor < bcor;
	}
}

int main() {
	int times;
	bool newline = 0;
	
	while (cin >> times) {
		cin.get();
		
		if (times == 0) {
			return 0;
		}
		
		camisa vet[times];
		
		for (int i = 0; i < times; i++) {
			getline(cin, vet[i].nome);
			cin >> vet[i].cor >> vet[i].tamanho;
			cin.get();
		}
		
		sort(vet, vet+times, comp);
		
		if (!newline) {
			newline = 1;
		} else {
			cout << endl;
		}
		
		for (int i = 0; i < times; i++) {
			cout << vet[i].cor << " " << vet[i].tamanho << " " << vet[i].nome << endl;
		}
	}
}
