#include <stdio.h>

int main (int argc, char* argv[]){
   if (argc!=3){
   	printf("Número incorreto de argumentos.\nSintaxe esperada:\nNomeDoExecutável NomeArqTexto NomeArqBinário\n");
   	return 1;
   }
   
   int numero;	
	FILE *iTextFile = NULL, *oBinaryFile = NULL;
	
	if ((iTextFile=fopen(argv[1],"rt"))==NULL){
		perror("Erro de arquivo texto");
		return 2;
	}
	
	if ((oBinaryFile=fopen(argv[2],"wb"))==NULL){
		perror("Erro de arquivo binário");
		return 2;
	}
	
	while (fscanf(iTextFile,"%d",&numero)==1){
		if (ferror(iTextFile)){
			perror("Erro de arquivo texto");
			return 3;
		}
		if (fwrite(&numero, sizeof(numero), 1, oBinaryFile)!=1){
			perror("Erro de arquivo binário");
			return 4;
		}
	}	

	fflush (oBinaryFile);
	if (ferror(oBinaryFile)){
		perror("Erro de arquivo binário");
		return 5;
	}		

	
	if (fclose(iTextFile)){
		perror("Erro de arquivo texto 1");
		return 6;
	}
		
	if (fclose(oBinaryFile)){
		perror("Erro de arquivo binário 3");
		return 6;
	}
			
}

