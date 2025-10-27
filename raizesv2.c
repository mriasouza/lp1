#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int tratarq (FILE * pFile);
float calcdelta (float a, float b, float c);
int calcraiz (float a, float b, float d);

int main (int argc, char * argv[]){

	char filename[256];
	
	if (scanf("%s", filename)!=1){
		fprintf(stderr, "Erro no arquivo");
		return 2;
	}
	
	FILE *pFile = fopen(filename, "r");
	tratarq(pFile);
	
	return 0;
}


int tratarq (FILE *pFile){
	float g[3];
	float num;
	int count = 0;
	
	if (!pFile){
		fprintf(stderr, "Erro: arquivo inexistente\n");
		return 2;
	}
	
	while (fscanf(pFile, "%f", &num)==1){
		g[count] = num;
		count++;
		if (count == 3){
			calcraiz(g[0], g[1], calcdelta(g[0], g[1], g[2]));
			count = 0;
		}
	}
	
	if (fclose(pFile)==EOF){
		fprintf(stderr, "Erro ao fechar o arquivo\n");
		return 3;
	}
	
	return 0;
}


float calcdelta (float a, float b, float c){
	float d;
	d = pow (b, 2) - (4*a*c);
	printf("A equação é %.2fx² + (%.2f)x + (%.2f)\n", a, b, c);
	return d;
}

int calcraiz (float a, float b, float d){
	if (d<0) {
		printf("Não há raízes para a equação\n");
		return 1;
	} float x1 = (-b + sqrt(d))/(2*a);
	float x2 = (-b - sqrt(d))/(2*a);
	if (d>0){
		printf("Há duas raízes: x1 é %.2f e x2 é %.2f\n", x1, x2); 
	} else if (d==0)
		printf("Há apenas uma raíz: x é %.2f\n", x1);
	return 0;
}
