#include <iostream>

using namespace std;

/* problema simples na verdade usa calculos ao inves de strings */

int main() {
	long long int x, y, val, caso = 1;
	
	while (cin >> x >> y) {
		if (x == 0 and y == 0) {
			return 0;
		}
		
		if (y >= x) {
			cout << "Case " << caso++ << ": 0\n";
		} else {
			while (val <= 26) {
				val = 1;
			
				if (y + (y * val) >= x) {
					cout << "Case " << caso++ << ": " << val << endl;
					break;
				} else {
					val++;
				}
			}
			
			if (val > 26) {
				cout << "Case " << caso++ << ": impossible\n";
			}
		}
	}
}
