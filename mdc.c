#include <stdio.h>

void ordenar (int * a, int * b);

int mdc (int a, int b);
	
int main(){
	int x, y;
	scanf("%d" "%d", &x, &y);
	printf("%d\n", mdc(x,y));
	return 0;
}

void ordenar (int * a, int * b){
	int t;
	if (*a<*b){
		t = *a;
		*a = *b;
		*b = t;
	}
}

int mdc(int a, int b){
	int r;
	if (a<b);
		ordenar(&a, &b);
	while (a%b!=0){
		r = a % b;
		a = b;
		b = r;
	}
	return r;
}
