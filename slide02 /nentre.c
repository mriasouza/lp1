#include <stdio.h>

 // Versão C do exercício 8.

int main (void){
    int a = 0.0;
    int b = 0.0;
    int i;

    printf("Digite um número: ");
    scanf("%d", &a);

    printf("Digite outro número: ");
    scanf("%d", &b);

    for(i = a; i <= b; i++){
        printf("%d\n", i);
    }

    return 0;
}
