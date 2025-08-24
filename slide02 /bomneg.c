#include <stdio.h>

// Ex. 3: Conversão de dólar para real na compra de um celular

#define dolar 3.17
int main (void){
    
    int preco;

    printf("Qual o preço do celular em dólares? ");
    scanf("%d", &preco);

    if (preco * dolar <= 1000){
        printf("Bom negócio\n");
    }

    return 0;
}
