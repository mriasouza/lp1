#include <stdio.h>
#include <stdlib.h>

int main (){
	int t, j;
	double * pVet;
	scanf("%d", &t);
	pVet = malloc(t*sizeof(*pVet));
	for (j=0; j<t; j++){
		scanf("%lf", &pVet[j]);
	}
	int i;
 	for (i=0; i<t-1; i++){
 			if (pVet[i]<pVet[i+1]){
 				double temp = pVet[i];
 			 	pVet[i] = pVet[i+1];
 			 	pVet[i+1] = temp;
 		}
 	}
 	for (i=0; i<t; i++){
 		 printf("%.2lf ", pVet[i]);
 	}
	free(pVet);
 	pVet = NULL;
 	
 	return 0;
	
}

