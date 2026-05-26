#include <stdio.h>
#include <string.h>

void ordenar (int * a, int * b){
	int t;
	{
		t = *a;
		*a = *b;
		*b = t;
	}
}
int main(void){

	int month, day, year, valid;
	char monthname[16], line[256]; 
	enum months {jan = 1, fev, mar, abr, mai, jun, jul, ago, set, out, nov, dez};
	while (fgets(line, sizeof(line), stdin) > 0) { 
		if (sscanf(line, "%d %s %d", &day, monthname, &year)==3 || sscanf(line, "%d de %s de %d", &day, monthname, &year) == 3){ 
			valid=1;
			if (strcmp(monthname, "janeiro")==0)
				month = jan;
			else if (strcmp(monthname, "fevereiro")==0)
				month = fev;
			else if (strcmp(monthname, "março")==0)
				month = mar;
			else if (strcmp(monthname, "abril")==0)
				month = abr;
			else if (strcmp(monthname, "maio")==0)
				month = mai;
			else if (strcmp(monthname, "junho")==0)
				month = jun;
			else if (strcmp(monthname, "julho")==0)
				month = jul;
			else if (strcmp(monthname, "agosto")==0)
				month = ago;
			else if (strcmp(monthname, "setembro")==0)
				month = set;
			else if (strcmp(monthname, "outubro")==0)
				month = out;
			else if (strcmp(monthname, "novembro")==0)
				month = nov;
			else if (strcmp(monthname, "dezembro")==0)
				month = dez;
		}
		else if (sscanf(line, "%d/%d/%d", &month, &day, &year) == 3) {
			valid=1;
			ordenar(&month, &day);
		}
	} if (valid==1) printf("%02d/%02d/%d", day, month, year);
	return 0;
}
