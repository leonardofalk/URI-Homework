#include <iostream>	/// cin/cout
#include <string>	/// string/length
   
using namespace std;
   
int main() {
    int times;
       
    cin >> times;
       
    for (int i= 1; i <= times; i++) {
        string word;
           
        cin >> word;
           
        if (word.length() == 3) { /// mesmo que word.size()
            if (word[0] == 'o' or word[1] == 'n' or word[2] == 'e') {
                cout << "1\n";
            } else {
                cout << "2\n";
            }
        } else {
            cout << "3\n";
        }
    }
       
    return 0;
}
