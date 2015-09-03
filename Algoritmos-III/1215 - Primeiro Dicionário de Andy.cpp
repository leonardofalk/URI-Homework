#include <iostream>
#include <list>

using namespace std;

int main() {
	string line;
	list<string> wordsList;
	list<string>::iterator it;
	
	while (getline(cin, line)) {
		string temp = "";
		
		for (int i = 0; line[i] != '\0'; i++) {
			char ch = tolower(line[i]);
			
			if (isalpha(ch)) {
				temp += ch;
			} else if (temp.size() > 0) {
				wordsList.push_back(temp);
				temp = "";
			}
		}
		
		if (temp.size() > 0) {
			wordsList.push_back(temp);
		}
	}
	
	wordsList.sort();
	wordsList.unique();
	
	for (it = wordsList.begin(); it != wordsList.end(); it++) {
		cout << *it << endl;
	}
}
