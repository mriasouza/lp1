#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int tratarq (FILE * pFile);
int calcdelta (int a, int b, int c);
int calcraiz (int a, int b, int d);

int main (int argc, char * argv[]){
	char filename[256];
	if (scanf("%255s", filename)!=1){
		fprintf(stderr, "Erro: arquivo inexistente\n");
		return 2;
	}
	FILE *pFile = fopen(filename, "r");
	tratarq(pFile);
	return 0;
}


int tratarq (FILE *pFile){
	int *a; int *b; int *c;
	int ch;
	int linhAtual = 0;
	if (!pFile){
		fprintf(stderr, "Erro: arquivo inexistente\n");
		return 2;
	}
	
	while (ch = fgetc(pFile) != EOF){
		if (fscanf(pFile, "%d %d %d", a, b, c)==3){
			calcraiz(*a, *b, calcdelta(*a, *b, *c));
		}
		else {
			return 1;
		}
	}
	
	if (fclose(pFile)==EOF){
		fprintf(stderr, "Erro ao fechar o arquivo\n");
		return 3;
	}
	
	return 0;
}


int calcdelta (int a, int b, int c){
	int d;
	d = pow (b, 2) - 4*a*c;
	return d;
}

int calcraiz (int a, int b, int d){
	if (d<0) {
		printf("Não há raízes para a equação");
		return 1;
	} if (d>=0) {
		float x1 = -b + sqrt(d)/2*a;
		float x2 = -b - sqrt(d)/2*a;
		printf("x1 é %.2f e x2 é %.2f", x1, x2);
	}
	return 0;
}

