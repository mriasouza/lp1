#include <stdio.h>

// Ex. 2: Comparação numérica

int main (void){
    double a = 0.0;
    double b = 0.0;

    printf("Digite um número: ");
    scanf("%lf", &a);

    printf("Digite outro número: ");
    scanf("%lf", &b);

    if (a > b){
        printf("%.2lf é maior\n", a);
    } else {
        printf("%.2lf é maior \n", b);
    }

    return 0;
}
