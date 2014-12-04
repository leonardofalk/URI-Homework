#include <iostream>		/// cin/cout
#include <string>		/// string/size

using namespace std;
   
int main() {
	int times, led_values[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
	string num;
    
	cin >> times;
    
	for (int i = 1; i <= times; i++) {
		int ans = 0;

		cin >> num;
		
		int strSize = num.size();
		
        	for (int x = 0; x < strSize; x++) {
        		/// converte o valor em string para um valor numerico
        		/// e associa a sequencia do valor no vetor 'led_values'
			ans += led_values[num[x]-'0'];
		}

		cout << ans << " leds\n";
	}
  
    return 0;
}
