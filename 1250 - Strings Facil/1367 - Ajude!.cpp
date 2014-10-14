#include <iostream>			/// cin/cout
#include <string>			/// string/append/begin/end/size
#include <algorithm>		/// sort

using namespace std;

int main() {
	int x, time;
	string team, judge;
	
	while (cin >> x) {
		string TEAMS_LOST = "", TEAMS_WON = "";
		int totalTime = 0;
		
		if (x == 0) {
			return 0;
		}
		
		for (int i = 1; i <= x; i++) {
			cin >> team >> time >> judge;
			
			if (judge == "correct") {
				/// se o time acertou, entao colocamos ele na parte dos vencedores
				TEAMS_WON.append(team);
				
				/// somamos o tempo que o time demorou no total
				totalTime += time;
				
				/// sorteamos a string de times que ja tentaram mas erraram
				/// para que o loop seja mais rapido nao tendo que percorrer
				/// todos os membros
				sort(TEAMS_LOST.begin(), TEAMS_LOST.end());
				/// tamanho da string
				int vetn = TEAMS_LOST.size();
				
				/// aqui verificamos com o loop se o time atual ja havia tentando
				/// resolver o exercicio, se sim adicionamos 20 minutos de peso
				/// ao total para cada tentativa, paramos quando a incidencia
				/// nao for do mesmo membro
				for (int a = 0; a < vetn; a++) {
					if (TEAMS_LOST[a] == team[0]) {
						totalTime += 20;
					} else if (TEAMS_LOST[a] > team[0]) {
						/// aqui a incidencia ja não é do mesmo membro que acabamos de ler
						/// e como a string esta organizada com o sort, nao precisamos
						/// ir ate o fim da string
						break;
					}
				}
			} else if (judge == "incorrect") {
				/// se o time errou apenas adicionamos o seu nome na lista dos que ja tentaram
				TEAMS_LOST.append(team);
			}
		}
		
		cout << TEAMS_WON.size() << " " << totalTime << endl;
	}
}
