#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct img {
    int largura;
    int altura;
    int maxval;
    int *pixels;
};

typedef struct img img;

int lerCabecalho(FILE *pF, int *largura, int *altura, int *maxval) {
    char magic[3];
    
    if (fscanf(pF, "%s", magic) != 1) {
        return 1;
    }
    
    if (strcmp(magic, "P2") != 0) {
        return 1;
    }
    
    while ((int c = fgetc(pF)) != EOF) {
        if (c == '#') {
            // Se for um comentário, lê até o final da linha
            while ((c = fgetc(pF)) != EOF && c != '\n');
        } else if (!isspace(c)) {
            // Se for um caractere não-branco e não-comentário, 
            // volta um caractere e sai do loop
            ungetc(c, pF);
            break;
        }
    }
    
    if (fscanf(pF, "%d %d %d", &largura, &altura, &maxval) != 3) {
        return 2;
    }
    
    return 0;
}

int lerPixels(FILE *pF, img *p) {
    int totalPixels = p->largura * p->altura;
    
    p->pixels = (int *)malloc(totalPixels * sizeof(int));
    if (p->pixels == NULL)
        return 1;
        
    for (int i = 0; i < totalPixels; i++) {
        if (fscanf(pF, "%d", &p->pixels[i]) != 1) {
            free(p->pixels);
            return 2;
        }
    }
    return 0;
}

int main() {
    char filename[256];
    struct img imagem;
    
    if (scanf("%s", filename) != 1) {
        fprintf(stderr, "Erro: arquivo inexistente\n");
        return 1;
    }
    
    FILE *pF = fopen(filename, "r");
    if (!pF) {
        fprintf(stderr, "Erro: arquivo inexistente\n");
        return 1;
    }
    
    if (lerCabecalho(pF, &imagem.largura, &imagem.altura, &imagem.maxval) != 0) {
        fclose(pF);
        fprintf(stderr, "Erro: arquivo inexistente\n");
        return 1;
    }
    
    if (lerPixels(pF, &imagem) != 0) {
        fclose(pF);
        fprintf(stderr, "Erro: arquivo inexistente\n");
        return 1;
    }
    
    fclose(pF);
    
    for (int i = 0; i < imagem.altura; i++) {
        for (int j = 0; j < imagem.largura; j++) {
            int pixel = imagem.pixels[i * imagem.largura + j];
            printf("%3X", pixel);
            
            if (j < imagem.largura - 1) {
                printf(" ");
            }
        }
        printf("\n");
    }
    
    free(imagem.pixels);
    
    return 0;
}
