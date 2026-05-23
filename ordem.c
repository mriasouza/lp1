#include <stdio.h>
#include <stdlib.h>

int main (){
	int t, j;
	double * pVet;
	scanf("%d", &t);
	pVet = malloc(t*sizeof(*pVet));
	for (j,=0; j<t; j++){
		scanf("%lf", &pVet[j]);
	}
	int i;
 	for (i=0; i<t-1; i++){
 		for (j = 0; j < t - i - 1; j++) {
 			if (pVet[j]<pVet[j+1]){
 				double temp = pVet[j];
 			 	pVet[j] = pVet[j+1];
 			 	pVet[j+1] = temp;
 		}
 	}
 }
 	for (i=0; i<t; i++){
 		 printf("%.2lf ", pVet[i]);
 	}
	free(pVet);
 	pVet = NULL;
 	
 	return 0;
	
}

