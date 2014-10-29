#include <iostream>
#include <algorithm>

/ * erro na função de comparação */

using namespace std;

struct numarray {
	unsigned long long int value;
	int module_by2;
	int module_byN;
};

bool compare(numarray a, numarray b) {
	if (a.module_byN == b.module_byN) {
		if (a.module_by2 == b.module_by2) {
			if (a.module_by2 != 0) {
				return a.value > b.value;
			} else {
				return a.value < b.value;
			}
		} else {
			return a.module_by2 > b.module_by2;
		}
	} else {
		return a.module_byN < b.module_byN;
	}
}

int main() {
	unsigned long long int x, y, i;
	
	while (cin >> x >> y) {
		if (x == 0 and y == 0) {
			cout << "0 0\n";
			
			return 0;
		}
		
		numarray vet[x];
		
		for (i = 0; i < x; i++) {
			cin >> vet[i].value;
			vet[i].module_byN = vet[i].value % y;
			vet[i].module_by2 = vet[i].value % 2;
		}
		
		sort(vet, vet+x, compare);
		
		cout << x << " " << y << "\n";
		
		for (i = 0; i < x; i++) {
			cout << vet[i].value << "\n";
		}
	}
	
	return 0;
}
