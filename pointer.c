#include <stdio.h>

int pointer(int * pVet);
	
int main(){
	int x;
	scanf("%d", &x);
	pointer(&x);
	printf("%d", x);
}

int pointer(int * pVet){
	*pVet = *(pVet)+1;
	return *pVet;
}
