#include <iostream>			/// cin/cout
#include <string>			/// string/replace/find/getline

using namespace std;

int main() {
	string phrase;
	
	while (getline(cin, phrase)) {
		/// o getline ja verifica se chegamos ou não no fim de arquivo (EOF) assim como o 'cin'
		
		int state = 1, pos = phrase.find("_");
		
		/// pos retorna -1 quando não acha o valor que pedimos pra procurar
		while (pos != -1) {
			/// replace troca o valor na posição dada 'pos' utilizando o numero de casas '1' da string para
			/// outra string, a variavel 'state' indica se é o primeiro ou segundo par da tag que queremos trocar
			/// quando o valor de state é par então estamos fechando (</tag>) a tag quando é impar
			/// foi o primeiro valor que encontramos, então estamos abrindo (<tag>)
			phrase.replace(pos, 1, ((state % 2 == 0) ? "</i>" : "<i>"));
			
			/// aumenta o state
			state++;
			
			/// procura a proxima parte pra ser substituida
			pos = phrase.find("_");
		}
		
		/// repete os passos acima, mas com a tag <b></b>
		state = 1, pos = phrase.find("*");
		
		while (pos != -1) {
			phrase.replace(pos, 1, ((state % 2 == 0) ? "</b>" : "<b>"));
			state++;
			pos = phrase.find("*");
		}
		
		cout << phrase << endl;
	}
}
