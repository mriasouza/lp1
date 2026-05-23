#include <stdio.h>
#include <string.h>

int count(char * str){
	int c = 0;
	char *pch;
	pch = strtok (str, " ,.;:\n\t");
	
	while(pch!=NULL){
		c++;
		pch = strtok (NULL, " ,.;:\n\t");
	}
	printf("%d", c);
	return 0;
}	

int main(){
	char str[1024];
	fgets(str, 1024, stdin);
	count(str);
}
