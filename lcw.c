#include <stdio.h>
#include <ctype.h>

int lcw(FILE * pFile);
int main(){
	char filename[256];
	scanf("%s", filename);
	FILE * pFile = fopen(filename, "r");	

	if (!pFile){
		fprintf(stderr, "Erro no arquivo %s\n", filename);
		return 1;
	}
	
	lcw(pFile);
	
	if (fclose(pFile)==EOF){
		fprintf(stderr, "Erro ao fechar o arquivo\n");
		return 2;
	}
	
	return 0;

}

int lcw(FILE * pFile){
	int c;
	int total = 0;
	int imp = 0;
	int line = 0;
	
	while ((c=fgetc(pFile))!=EOF){
		total++;
		
		if (isprint(c))
			imp++;
		
		if(c=='\n')
			line++;
	}

	printf("%d\n", total);
    printf("%d\n", imp);
    printf("%d\n", line);

}
