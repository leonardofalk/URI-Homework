#include <iostream>			/// cout/cin
#include <algorithm>			/// transform
#include <string>			/// begin/end/getline
#include <sstream>			/// stringstream

using namespace std;

int main() {
	string line, word;
	
	while (getline(cin, line)) {
		/*
		   deixa todos os caracteres da string minusculos para comparação
		   retirado de:
		   http://stackoverflow.com/questions/313970/how-to-convert-stdstring-to-lower-case
		*/
		transform(line.begin(), line.end(), line.begin(), ::tolower);
		
		// divide a entrada com o string stream
		stringstream split(line);
		
		split >> word;
		char comp = word[0], last = '0';
		int streak = 0, total = 0;
		
		/*
		   nao entendo muito bem como, mas funciona
		   achei la no forum e modifiquei
		*/
		while (split >> word) {
			if (word[0] == comp and word[0] != last) {
				total++;
				last = word[0];
			} else if (word[0] != comp) {
				comp = word[0];
				last = '5';
			}
		}
		
		cout << total << endl;
	}
}
