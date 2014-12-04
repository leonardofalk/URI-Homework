#include <iostream>
#include <iomanip>
#include <cstdio>
 
using namespace std;
int main () {
    double val; char name[1000];
    double div = 0.0, total = 0.0;
 
    while (gets(name)) {
        cin >> val;
        /// cleans the new line from the buffer, allowing to read the next name and number
        getchar();
 
        total += val;
        div += 1.0;
    }
 
    cout << fixed << setprecision(1) << total / div << endl;
}