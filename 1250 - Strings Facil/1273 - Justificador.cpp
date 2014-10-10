#include <iostream>			/// cin/cout
#include <iomanip>			/// setw
#include <cmath>			/// max
#include <string>			/// string/size
 
using namespace std;
 
int main() {
    int n; bool newline = 0;
 
    while (cin >> n) {
        if (n == 0) {
            return 0;
        }
 
        int strsize = 0;
        string words[n]; /// vetor de strings
 
        for (int i = 0; i < n; i++) {
            cin >> words[i];
            /// aqui pegamos o maximo de letras de cada palavra e salvamos na variavel
            /// para justificar depois, o cast (int) serve para converter o tipo da variavel retornada em size
            /// ela retorna uma variavel do tipo 'size_t' e não int e a função 'max' aceita apenas int
            /// por isso a conversão
            strsize = max(strsize, (int) words[i].size());
            /// salva em 'strsize' o numero de letras entre o valor
            /// que ele ja possuia e o numero de letras da nova palavra
        }
 
 		/// essa variavel e if são para colocar linha nova entre as respostas mas não apos a ultima linha
 		/// portanto ela é colocada fora do loop principal para ser inicializada uma unica vez
        if (!newline) {
            newline = 1;
        } else {
            cout << endl;
        }
 
 		/// o truque é bem simples, o valor maximo arquivado em 'strsize' é o valor o qual usamos
 		/// para justificar o texto com X caracteres usando 'setw'
        for (int i = 0; i < n; i++) {
            cout << setw(strsize) << words[i] << endl;
        }
    }
 
    return 0;
}
