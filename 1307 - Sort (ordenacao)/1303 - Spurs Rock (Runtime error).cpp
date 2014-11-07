/*
	runtime error if more than 1 test entry
	main vector needs to be changed to avoid this problem
*/

#include <iostream>
#include <algorithm>

using namespace std;

/* Structure for each team array */
struct Team {
	int id = -1;
	int won = 0;
	double avg = 0;
};

/* Compare function to sort teams */
bool comp(Team a, Team b) {
	if (a.won == b.won) {
		return a.avg > b.avg;
	}
	
	return a.won > b.won;
}

int main() {
	int times, x, y, z, w, inst = 1;
	
	while (cin >> times) {
		if (times <= 0) {
			return 0;
		}
		
		Team vet[times];
		
		for (int i = 1; i <= (times * (times - 1) / 2); i++) {
			cin >> x >> y >> z >> w;
			
			vet[x-1].id = x;
			vet[z-1].id = z;
			
			vet[x-1].avg += y/w;
			vet[z-1].avg += w/y;
			
			if (y == w) {
				if (x < z) {
					vet[x-1].won++;
				} else {
					vet[z-1].won++;
				}
			} else if (y > w) {
				vet[x-1].won++;
			} else {
				vet[z-1].won++;
			}
		}
		
		sort(vet, vet + times, comp);
		
		if (inst > 1) {
			cout << "\n";
		}
		
		cout << "Instancia " << inst++ << "\n";
		
		for (int i = 0; i < times; i++) {
			cout << ((i > 0) ? " " : "") << vet[i].id;
		}
	
		cout << "\n";
	}
}
