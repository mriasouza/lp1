#include <stdio.h>

union number {
    float f;
    int i;
} n;

int main (){
 	int j, bin;
 	scanf("%f", &n.f);
	for (j=31; j>0; j--){
		bin = (n.i >> j) & 1;
		printf("%d", bin);
	}
}
