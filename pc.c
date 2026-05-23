#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int QtdePrimos(int n) {
	int i, j, c = 0, p;
	for (i=2; i<=n; i++){
        p = 1;
		for (j=2; j<=sqrt(i); j++){
            if (i%j==0){
                p=0;
            }
		}
    if (p=1){
        c+=1;
    }
	return c;
}
}
int main() {
	int n;  
	while (scanf("%d", &n)>0) {
		printf("%d\n", QtdePrimos(n));
	}
}