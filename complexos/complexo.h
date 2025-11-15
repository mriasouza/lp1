#ifndef COMPLEXO_H
#define COMPLEXO_H

typedef struct {
	double img;
	double real;
} complexo;

void complexo_le(complexo *z);

void complexo_imprime(complexo *z, FILE* filename);

complexo complexo_soma(complexo *a, complexo *b);

complexo complexo_sub(complexo *a, complexo *b);

complexo complexo_mult(complexo *a, complexo *b);

double complexo_absoluto(complexo *z);

complexo complexo_conjugado(complexo *z);

#endif
