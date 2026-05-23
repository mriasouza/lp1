#include <stdio.h>
#include <stdlib.h>

typedef struct Bst {
	int E;
	Bst* Esq;
	Bst* Dir;
}T;

T* GetNewNode(int x);
T* Insere(T* &raiz, int x);
int Busca(T* raiz, int x);

int main(){
	T* raiz = NULL;
	Insere(raiz, 23);
	Insere(raiz, 4);
	Insere(raiz, 3);
	Insere(raiz, 7);
	for (int i=0; i<24; i++){
		if (Busca(raiz, i)) printf("Achou %d\n", i);
		else printf("Não achou %d\n", i);
	}
}

T* GetNewNode(int x){
	T* novo = (T*)malloc(sizeof(*novo));
	novo->E = x;
	novo->Esq = novo->Dir = NULL;
	return novo;
}

T* Insere(T* &raiz, int x){
	if(raiz==NULL){
		raiz=GetNewNode(x);
	} 
	else if(x<=raiz->E){
		Insere(raiz->Esq, x);
	}
	else {
		Insere(raiz->Dir, x);
	}
	return raiz;
}

int Busca(T* raiz, int x){
	if(raiz==NULL) return 0;
	if(raiz->E==x) return 1;
	else if (x<raiz->E)
		return Busca(raiz->Esq, x);
	else 
		return Busca(raiz->Dir, x);

}

