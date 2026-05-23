#include <stdio.h>
#include <string.h>

#include <stdio.h>
#define MAX_SIZE 101
char C[MAX_SIZE];
int top = -1;

void Push(char x){
	if (top==MAX_SIZE-1){
		printf("Erro: stack overflow\n");
		return;
	}
	C[++top] = x;
}

void Pop(){
	if (top==-1){
		printf("Erro: não há elemento para retirar\n");
		return;
	}
	top--;
}

int Top(){
	return C[top];
}

void Reverse (char *C, int n){
	for(int i=0; i<n; i++)
		Push(C[i]);
	for(int i=0; i<n; i++){
		C[i] = Top();
		Pop();
	}
}

int main(){
	char A[MAX_SIZE];
	scanf("%s", A);
	Reverse(A, strlen(A));
	printf("Frase invertida: %s\n", A);
}
