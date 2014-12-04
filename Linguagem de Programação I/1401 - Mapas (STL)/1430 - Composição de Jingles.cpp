#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
	map <char, double> duration = {
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
				if (total == 1) {
					count++;
				}
				
				total = 0;
			} else {
				total += duration[notes[i]];	
			}
		}
		
		cout << count << endl;
	}
	
	return 0;
}
