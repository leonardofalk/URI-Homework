#include <iostream>	/// cin/cout
#include <string>	/// string/stod
#include <cmath>	/// floor/ceil

using namespace std;

int main() {
	string num, cut;

	while (cin >> num >> cut) {
		/// stod converte uma string em double
		/// e adiciona valores em falta a direita e esquerda

		double realnum = stod(num);
		double realcut = stod(cut);
  
		if (realnum - int(realnum) <= realcut) {
			cout << int(floor(realnum)) << endl;
		} else {
			cout << int(ceil(realnum)) << endl;
		}
	}

	return 0;
}