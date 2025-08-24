#include <stdio.h>

// Somatório dos quadrados

int main(void){

    int n = 0;
    int soma = 0;

    printf("Entre com um número: ");
    scanf("%d", &n);

    for(int i = 1; i <= n; i++){
        soma = soma + i * i;
    }

    printf("A soma é %d\n", soma);

}