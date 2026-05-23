#include <stdio.h>

float prodes(int t, float a[t], float b[t]);

int main (){
	int n, i, j;
	scanf("%d", &n);
	float x[n], y[n];
	for (i=0; i<n; i++){
		scanf("%f", &x[i]);
	}
	for (j=0; j<n; j++){
		scanf("%f", &y[j]);
	}
	prodes(n, x, y);
}

float prodes(int t, float a[t], float b[t]){
	int i, j;
	float sum;
	for (i=0; i<t; i++){
		for (j=0; j<t; j++){
			if (i==j){
				sum+=a[i]*b[j];
			}
		}	
	}
	printf("%.2f", sum);
}
