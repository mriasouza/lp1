#include <stdio.h>
#include "complexo.h"
#include "raiz.h"

void complexo_le (complexo *z){
	scanf("%lf %lf", &z->real, &z->img);
}

void complexo_imprime(complexo *z, FILE *filename){
	fprintf(filename, "%.2f%+.2fi", z->real, z->img);
}

complexo complexo_soma(complexo *a, complexo *b){
	complexo resultado;
	resultado.real = a->real + b->real;
	resultado.img = a->img + b->img;
	return resultado;
}

complexo complexo_sub(complexo *a, complexo *b){
	complexo resultado;
	resultado.real = a->real - b->real;
	resultado.img = a->img - b->img;
	return resultado;
}

complexo complexo_mult(complexo *a, complexo *b){
	complexo resultado;
	resultado.real = a->real * b->real - a->img * b->img;
	resultado.img = a->real * b->img + a->img * b->real;
	return resultado;
}

double complexo_absoluto(complexo *z){
	return raiz(z->real * z->real + z->img * z->img);
}

complexo complexo_conjugado(complexo *z){
	complexo resultado;
	resultado.real = z->real;
	resultado.img = -z->img;
	return resultado;
}
