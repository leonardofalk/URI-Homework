#include <iostream>
#include <map>
#include <iomanip>
#include <string>

using namespace std;

int main() {
	map <string, double> avres;
	map <string, double>::iterator it;
	
	string avre; int cases, i, total = 0;
	
	cout << fixed << setprecision(4);
	
	cin >> cases;
	cin.get();
	getline(cin, avre);
	
	for (i = 1; i <= cases; i++) {
		while (getline(cin, avre) and avre[0] != '\0') {
			avres[avre]++;
			total++;
		}
		
		if (i > 1) {
			cout << "\n";
		}
		
		for (it = avres.begin(); it != avres.end(); it++) {
			cout << it -> first << " " << 100.0 * it -> second / total << endl;
		}
		
		total = 0;
		avres.clear();
	}
	
	return 0;
}
