#include <stdio.h>
#include <string.h>

#define vit 3
#define emp 1
#define der 0

 // Ex. 7: Calculadora de pontos do Campeonato Brasileiro

typedef struct {
    char nomeTime[100];
    int numV, numE, numD, pontosT;

} Brasileirao;

int main () {
    Brasileirao times[20];
    int i;
    int t = 20;
    int auxMa = 0;
    int auxMe = 0;

    for(i = 0; i < t; i++){
        printf("Digite o nome do seu time: ");
        scanf("%s", times[i].nomeTime);
        printf("Digite o número de vitórias: ");
        scanf("%d", &times[i].numV);
        printf("Digite o número de empates: ");
        scanf("%d", &times[i].numE);
        printf("Digite o número de derrota: ");
        scanf("%d", &times[i].numD);
        times[i].pontosT = times[i].numV * vit + times[i].numE * emp + times[i].numD * der;
    }

    for(i = 1; i < t; i++){
        if(times[i].pontosT > times[auxMa].pontosT){
            auxMa = i;
        } 
        else if(times[i].pontosT < times[auxMe].pontosT){
            auxMe = i;
        }
    } 

    printf("%s tem a maior pontuação\n", times[auxMa].nomeTime);
    printf("%s tem a menor pontuação\n", times[auxMe].nomeTime);

    return 0;
}

