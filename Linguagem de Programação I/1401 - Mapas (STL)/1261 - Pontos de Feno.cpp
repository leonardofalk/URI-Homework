#include <iostream>
#include <map>
#include <sstream>
#include <string>

using namespace std;

int main() {
	map <string, int> words_value;
	int words, phrases; string msg, tmp; int temp;
	
	cin >> words >> phrases;
	
	for (int i = 1; i <= words; i++) {
		cin >> msg >> temp;
		words_value[msg] = temp;
	}
	
	cin.get();
	
	for (int i = 1; i <= phrases; i++) {
		int total = 0;
		
		while (getline(cin, msg) and msg.size() != 1) {
			stringstream split(msg);
			
			while (split >> tmp) {
				total += words_value[tmp];
			}
		}
		
		cout << total << endl;
	}
	
}
