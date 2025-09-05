#include <stdio.h>

char dom[2][13]= { {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31} };

int leap(int year){
	return (year%400==0 || year%100!=0 && year%4==0);
}

int main (int day, int year, int month){ //passar data para qual dia do ano é
	int i;
	printf("Data (DD MM AAAA): ");
	scanf("%d %d %d", &day, &month, &year);
	for (i=1; i < month; i++){
		day += dom[leap(year)][i];
	};
	printf("%d\n", day);
}
