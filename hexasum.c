#include <stdio.h>

int main (){
	int c;
	signed int a;
	signed int b;
	scanf("%d", &a);
	scanf("%d", &b);
	c = a + b;
	printf("%hhX %hhd\n", a, a);
	printf("%hhX %hhd\n", b, b);
	printf("%hhX %hhd\n", c, c);
	return 0;
}

