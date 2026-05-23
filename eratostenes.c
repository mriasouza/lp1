#include <stdio.h>
#include <math.h>

int primos(int n) {
	int i, j, p;
	n=1000;
	for (i=2; i<=n; i++){
		p = 1;
		for (j=2; j<=sqrt(i); j++){
			if (i%j==0){
				p = 0;
				break;
			}
		}
	if (p==1){
		printf("%d ", i);
	}
}	

}
int main() {  
	primos();
	return 0;
}
