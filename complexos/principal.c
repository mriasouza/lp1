#include <stdio.h>
#include "complexo.h"
#include "raiz.h"

void salvar_resultado(complexo* resultado, int op, complexo* a, complexo* b);
void operar_complexos();
void ler_arquivo_complexos();

int main() {
    int opcao;
    
    FILE* saida = fopen("saida.txt", "w");
    if (!saida) {
        perror("Erro ao abrir o arquivo de saída.\n");
        return 1;
    }
    fclose(saida);
    
    do {
        scanf("%d", &opcao);
        
        switch(opcao) {
            case 1:
                operar_complexos();
                break;
            case 2:
                ler_arquivo_complexos();
                break;
            case 0:
                break;
            default:
                printf("Opção inválida!\n");
        }
        
    } while (opcao != 0);
    
    return 0;
}

void salvar_resultado(complexo* resultado, int op, complexo* a, complexo* b) {
    FILE* saida = fopen("saida.txt", "a");
    if (!saida) {
        perror("Erro ao abrir arquivo de saída.\n");
        return;
    }
    
    switch(op) {
        case 1: 
            complexo_imprime(a, saida);
            fprintf(saida, " ");
            complexo_imprime(b, saida);
            fprintf(saida, " ");
            complexo_imprime(resultado, saida);
            break;
        case 2: 
            complexo_imprime(a, saida);
            fprintf(saida, " ");
            complexo_imprime(b, saida);
            fprintf(saida, " ");
            complexo_imprime(resultado, saida);
            break;
        case 3: 
            complexo_imprime(a, saida);
            fprintf(saida, " %.2f", complexo_absoluto(a));
            break;
        case 4: 
            complexo_imprime(a, saida);
            fprintf(saida, " ");
            complexo_imprime(b, saida);
            fprintf(saida, " ");
            complexo_imprime(resultado, saida);
            break;
        case 5: 
            complexo_imprime(a, saida);
            fprintf(saida, " ");
            complexo_imprime(resultado, saida);
            break;
    }
    fprintf(saida, "\n");
    fclose(saida);
}

void operar_complexos() {
    int opo;
    
    do {
        scanf("%d", &opo);
        if (opo == 0) break;
        
        complexo a, b, resultado;
        
        if (opo != 3 && opo != 5) {
            complexo_le(&a);
            complexo_le(&b);
        } else {
            complexo_le(&a);
        }
        
        switch(opo) {
            case 1:
                resultado = complexo_soma(&a, &b);
                complexo_imprime(&resultado, stdout);
                printf("\n");
                salvar_resultado(&resultado, 1, &a, &b);
                break;
                
            case 2:
                resultado = complexo_mult(&a, &b);
                complexo_imprime(&resultado, stdout);
                printf("\n");
                salvar_resultado(&resultado, 2, &a, &b);
                break;
                
            case 3: 
                printf("%.2f\n", complexo_absoluto(&a));
                salvar_resultado(&a, 3, &a, &b);
                break;
                
            case 4: 
                resultado = complexo_sub(&a, &b);
                complexo_imprime(&resultado, stdout);
                printf("\n");
                salvar_resultado(&resultado, 4, &a, &b);
                break;
                
            case 5: 
                resultado = complexo_conjugado(&a);
                complexo_imprime(&resultado, stdout);
                printf("\n");
                salvar_resultado(&resultado, 5, &a, &b);
                break;
                
            default:
                printf("Opção inválida!\n");
        }
        
    } while (opo != 0);
}

void ler_arquivo_complexos() {
    char filename[256];
    scanf("%s", filename);
    
    FILE* pF = fopen(filename, "r");
    if (!pF) {
        perror("Erro ao abrir arquivo.\n");
        return;
    }
    
    complexo a, b;
    int count = 0;
    
    FILE* saida = fopen("saida.txt", "a");
    if (!saida) {
        perror("Erro ao abrir arquivo de saída.\n");
        fclose(pF);
        return;
    }
    
    while (1) {
        if (fscanf(pF, "%lf %lf", &a.real, &a.img) != 2) break;
        if (fscanf(pF, "%lf %lf", &b.real, &b.img) != 2) break;
        
        count++;
        
        int opo;
        do {
            scanf("%d", &opo);
            
            if (opo == 0) break;
            
            complexo resultado;
            
            switch(opo) {
                case 1:
                    resultado = complexo_soma(&a, &b);
                    complexo_imprime(&resultado, stdout);
                    printf("\n");
                    salvar_resultado(&resultado, 1, &a, &b);
                    break;
                    
                case 2:
                    resultado = complexo_mult(&a, &b);
                    complexo_imprime(&resultado, stdout);
                    printf("\n");
                    salvar_resultado(&resultado, 2, &a, &b);
                    break;
                    
                case 3: 
                    printf("%.2f\n", complexo_absoluto(&a));
                    salvar_resultado(&a, 3, &a, &b);
                    break;
                    
                case 4:
                    resultado = complexo_sub(&a, &b);
                    complexo_imprime(&resultado, stdout);
                    printf("\n");
                    salvar_resultado(&resultado, 4, &a, &b);
                    break;
                    
                case 5:
                    resultado = complexo_conjugado(&a);
                    complexo_imprime(&resultado, stdout);
                    printf("\n");
                    salvar_resultado(&resultado, 5, &a, &b);
                    break;
                    
                default:
                    printf("Opção inválida!\n");
            }
        } while (opo != 0);
    }
    
    fclose(pF);
    fclose(saida);
    
    if (count == 0) {
        printf("Nenhum par de números complexos encontrado no arquivo.\n");
    }
}
