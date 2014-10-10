#include <iostream>
#include <string>
#include <algorithm>

/// 10% das respostas com erro

using namespace std;

int main() {
	int times;
	string a, b, c;
	
	cin >> times;
	cin.get();
	
	for (int i = 1; i <= times; i++) {
		getline(cin, a); getline(cin, b); getline(cin, c);
		
		int bsize = b.size(), csize = c.size();
		bool erro = 0;
		
		// verificando valores do cafe da manha string 'b'
		for (int x = 0; x < bsize; x++) {
			int pos = a.find(b[x]);
			
			if (pos == -1) {
				a = "CHEATER";
				erro = 1;
				break;
			} else {
				a.erase(pos, 1);
			}
		}
		
		// verificando valores do almoço string 'c'
		for (int x = 0; x < csize; x++) {
			int pos = a.find(c[x]);
			
			if (pos == -1) {
				erro = 1;
				a = "CHEATER";
				break;
			} else {
				a.erase(pos, 1);
			}
		}
		
		if (!erro) {
			sort(a.begin(), a.end());
		}
			
		cout << a << endl;
	}
}
