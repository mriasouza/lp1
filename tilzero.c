#include <stdio.h>

// Ex. 5: Ler números e escrever a soma

int main (void){
    int n;
    int soma = 0;
    while(printf("Digite um número: "), scanf("%d", &n) == 1 && n != 0){ 
        soma = soma + n;
    }
    printf("A soma é %d\n", soma);
}
