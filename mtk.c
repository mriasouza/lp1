#include <stdio.h>
 
// Converter de milhas para quilômetros

#define miles 1.6

int main (void){
    int km;

    printf("Qual a sua velocidade? ");
    scanf("%d", &km);

    if (miles * km >= 80 && miles * km <= 100){
        printf("Mantenha\n");
    }
    else if (miles * km < 80) {
        printf("Acelere\n");
    } 
    else {
        printf("Desacelere\n");
    }

    
}