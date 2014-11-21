#include <iostream>
#include <map>
#include <iomanip>

using namespace std;


int main() {
	int cases, toBuy, i, j; map <string, double> fruits;
	
	cout << fixed << setprecision(2);

	cin >> cases;
	
	for (i = 1; i <= cases; i++) {
		double fruitPrice, total = 0.0;
		string fruit;
		
		cin >> toBuy;
		
		for (j = 1; j <= toBuy; j++) {
			cin >> fruit >> fruitPrice;
			fruits[fruit] = fruitPrice;
		}
		
		cin >> toBuy;
		
		for (j = 1; j <= toBuy; j++) {
			cin >> fruit >> fruitPrice;
			total += fruits[fruit] * fruitPrice;
		}
		
		cout << "R$ " << total << endl;
	}
}