#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
 
using namespace std;
 
int main() {
    double t, price, totalp = 0, totalf = 0;
    string fruit, fruits;
 
    cin >> t;
 
    for (int i = 1; i <= t; i++) {
        cin >> price;
        cin.get();
        totalp += price;
        getline(cin, fruits);
 
        stringstream amount(fruits);
        int f = 0;
        while (amount >> fruit) {
            f++;
        }
        totalf += f;
        cout << "day " << i << ": " << f << " kg\n";
    }
 
    cout << fixed << setprecision(2);
    cout << totalf / t << " kg by day\n";
    cout << "R$ " << totalp / t << " by day\n";
}