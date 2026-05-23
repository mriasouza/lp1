#include <stdio.h>
#include <ctype.h>

int main (){
	int c, in = 0, w = 0;
	while ((c = getchar()) != EOF){
		switch (c) {
			case ',': case ';': case '.': case ':': case '\t': case '\n': case ' ':
				if (in){
					w++;
					in = 0;
				}
				break;
			default:
					in = 1;	
				break;	
		}
	}
	printf("%d", w);
	return 0;
}
