#include <iostream>
#include <string>
 
using namespace std;
 
int main() {
    int times, n;
    string temp;
     
    cin >> times;
     
    for (int z = 1; z <= times; z++) {
        cin >> n;
         
        string alunos[n], chamadas[n];
        
        /* le todos os alunos */
        for (int i = 0; i < n; i++) {
            cin >> alunos[i];
        }
        
        /* le todos as chamadas */
        for (int i = 0; i < n; i++) {
            cin >> chamadas[i];
        }
        
        /* essa string vai ser elaborada até o final e entao jogada no output */
        temp = "";
        
        for (int x = 0; x < n; x++) {
        	/* tam tem o tamanho da chamada para o 'x' aluno da sequencia */
            double tam = chamadas[x].size();
            /* 
                total é o total de frequencia do aluno 'x'
                cham é a porcentagem de cada dia de aula, supondo que sao 10 dias, cham = 0.1
                tam2 é uma variavel backup do tam, pois nao podemos altera-lo dentro do loop
                porem precisamos em determinado momento
             */
            double total = 0.0, cham = (1.0 / tam), tam2 = tam;
             
            for (int y = 0; y < tam; y++) {
                if (chamadas[x][y] == 'P') {
                    /* se o aluno estava presente entao apenas somamos 1 dia a mais ao total em porcentagem */
                    total += cham;
                } else if (chamadas[x][y] == 'M') {
                    /*
                       no caso 'M' entao o aluno entregou um atestado medico entao temos que descontar o dia
                       do calculo ja feito e reiniciar a contagem, porem isso nao pode ser feito no meio do loop
                       pois metade dos calculos ja podem ter sido feitos, entao as proximas chamadas sao uma tecnica
                       pra recalcular tudo feito até agora com o novo valor pra 'cham'
                    */
                    total /= cham;    // variavel total é agora um backup do numero de presenças que o aluno teve
                    tam2--;		      // diminuimos o numero de aulas
                    cham = 1.0 / tam2;// recalculamos a nova porcentagem de cada dia
                    total *= cham;    // recalculamos o novo valor 'total' a partir da contagem dos dias * porcentagem nova
                }
            }
     
            if (total < 0.75) {
                /* se o total tem menos de 75% entao o aluno reprovou */
                temp = temp + alunos[x] + " ";
            }
        }
        
        /* mostramos toda a string 'temp' até o penultimo caractere, ja que o ultimo é um espaço de sobra */
        cout << temp.substr(0, temp.size()-1) << endl;
    }
}
