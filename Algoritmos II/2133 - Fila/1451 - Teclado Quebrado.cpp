#include <iostream>
#include <list>

using namespace std;

int main() {
        list<char> res;
        list<char>::iterator it;
        
        string line;
        
        while (cin >> line) {
        	res.clear();
        	it = res.begin();
        	
        	for (int i = 0; line[i] != '\0'; i++) {
        		if (line[i] == ']') {
        			it = res.end();
        		} else if (line[i] == '[') {
        			it = res.begin();
        		}
        		
        		if (line[i] != '[' and line[i] != ']') {
        			res.insert(it, line[i]);
        		}
        	}
        	
        	for (it = res.begin(); it != res.end(); it++) {
        		cout << *it;
        	}
        	
        	cout << endl;
        }
        
        return 0;
}
