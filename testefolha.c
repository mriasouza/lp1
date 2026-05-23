#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char nome[50];
    char matricula[12];
    char endereco[65];
    char cpf[11];
    char codbanco[3];
    char agencia[5];
    char conta[8];
    float valorhora;
    float salariototal;
} Funcionario;

void ordenarnomes(Funcionario funcionarios[]) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 10 - i - 1; j++) {
            if (strcmp(funcionarios[j].nome, funcionarios[j + 1].nome) > 0) {
                Funcionario temp = funcionarios[j];
                funcionarios[j] = funcionarios[j + 1];
                funcionarios[j + 1] = temp;
            }
        }
    }
}


void trim (char * str){
  int i = strlen(str);
  while (i>=0 && str[i]==' ' || str[i]=='\n' || str[i]=='\r'){
    str[i]='\0';
    i--;
  }
}

int lerfuncionario (FILE *f, Funcionario* Func) {
  char lineBuffer[180]; 
  printf("Antes do loop fgets\n");
  while (fgets(lineBuffer, sizeof(lineBuffer), f)){
    strncpy(Func->nome, lineBuffer, 50);
    trim(Func->nome);
    strncpy(Func->matricula, lineBuffer+51, 12);
    trim(Func->matricula);
    strncpy(Func->endereco, lineBuffer+64, 65);
    trim(Func->endereco);
    strncpy(Func->cpf, lineBuffer+130, 11);
    trim(Func->cpf);
    strncpy(Func->codbanco, lineBuffer+142, 3);
    trim(Func->codbanco);
    strncpy(Func->agencia, lineBuffer+146, 5);
    trim(Func->agencia);
    strncpy(Func->conta, lineBuffer+152, 8);
    trim(Func->conta);
    Func->valorhora = atof(lineBuffer+161);
    Func->salariototal = 0;
    return 0;
  }  printf("Depois do loop fgets\n");
}

int lerHoras(FILE *f, char* mat, char* horas){
  int i;
  for (i=0; i<=10; i++){
    fscanf(f, "%12[^/]/%d", mat[i], horas[i]);
  }
  return 0;
}

int main(){
  FILE * funcF = fopen("Funcionarios.txt", "r");
  if (!funcF){
    perror("Erro ao abrir o arquivo de funcionários.\n");
    return 1;
  } 
  
  FILE * horasF = fopen("Novembro.txt", "r");
  if (!horasF){
    perror("Erro ao abrir o arquivo do mês.\n");
    return 2;
  }
  
  Funcionario lista[10];
  char maTemp[10];
  char horasTemp[10]; int i; int j;
  for (i=0; i<=10; i++) {
    lerfuncionario(funcF, &lista[i]);
    lerHoras(horasF, maTemp, horasTemp);
    for (j=0; j<=i; j++){
      if (strcmp(&maTemp[i], lista[j].matricula)==0){
      lista[j].salariototal = horasTemp[j]*lista[j].valorhora;
      break;
     }
    }
  }
  
 if (fclose(funcF)==EOF){
    perror("Erro ao fechar o arquivo de funcionários.\n");
    return 4;
  }
  
   
 if (fclose(horasF)==EOF){
    perror("Erro ao fechar o arquivo do mês.\n");
    return 4;
  }
  
  ordenarnomes(lista);
  for (i=0; i<=0; i++){
    printf("%s|%s|%s|%s|%s|%.2f\n", lista[i].nome, lista[i].cpf, lista[i].codbanco, lista[i].agencia, lista[i].conta, lista[i].salariototal);
  }
}
