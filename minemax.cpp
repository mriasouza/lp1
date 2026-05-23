#include <stdio.h>
#include <stdlib.h>

typedef struct Bst {
	int E;
	Bst * Esq;
	Bst * Dir;
}T;
 
int min(T*raiz){
	if(raiz==NULL){
		printf("Árvore vazia :(\n"
		return -1;
	} 
	else if(raiz->Esq==NULL){
		return raiz->E;
	}
	return min(raiz->Esq);
}

int Max(T*raiz){
	if(raiz==NULL){
		printf("Árvore vazia :(\n"
		return -1;
	} 
	else if(raiz->Dir==NULL){
		return raiz->E;
	}
	return Max(raiz->Dir);
}
