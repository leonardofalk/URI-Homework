/*
	20% wrong answer
*/

#include <iostream>
#include <algorithm>
 
using namespace std;
 
struct Team {
    int id = 0, won = 0, points = 0;
    double avg = 0;
};
 
bool comp(Team a, Team b) {
    if (a.won == b.won) {
        if (a.avg == b.avg) {
            if (a.points == b.points) {
                return a.id < b.id;
            }
             
            return a.points > b.points;
        }
         
        return a.avg > b.avg;
    }
     
    return a.won > b.won;
}
 
int main() {
    int cases, id1, points1, id2, points2, instancia = 1;
     
    while (cin >> cases) {
        if (cases == 0) {
            return 0;
        }
         
        int tam = (cases * (cases - 1)) / 2;
         
        Team vet[cases];
         
        for (int i = 1; i <= tam; i++) {
            cin >> id1 >> points1 >> id2 >> points2;
             
            vet[id1 - 1].id = id1;
            vet[id2 - 1].id = id2;
            vet[id1 - 1].points += points1;
            vet[id2 - 1].points += points2;
             
            if (points1 == 0) {
                vet[id2 - 1].avg += points2;
            } else if (points2 != 0) {
                vet[id2 - 1].avg += points2 / points1;
            }
             
            if (points2 == 0) {
                vet[id1 - 1].avg += points1;
            } else if (points1 != 0) {
                vet[id1 - 1].avg += points1 / points2;
            }
             
             
            if (points1 > points2) {
                vet[id1 - 1].won += 2;
                vet[id2 - 1].won++;
            } else if (points1 < points2) {
                vet[id2 - 1].won += 2;
                vet[id1 - 1].won++;
            } else {
                 
            }
        }
         
        sort(vet, vet + cases, comp);
         
        cout << ((instancia > 1) ? "\n" : "") << "Instancia " << instancia++ << "\n";
         
        for (int j = 0; j < cases; j++) {
            cout << ((j > 0) ? " " : "") << vet[j].id;
        }
     
        cout << "\n";
    }
}
