#include <stdio.h>
#include <stdlib.h>

#define N 10



int MIS(int [], int [],int,int);

int main () {

int I,NC[N];
//NC de numero de cuentas 
char TI[N];
//TI de tipo

srand(1987);

	for(I=0;I<N;I++){
		
		NC[I]=100+rand()%501;
		
		TI[I]='A'+rand()%3;
		
	}		
	
	for(I=0;I<N;I++)
	if(TI[I]=='A')
	printf("%d \t %c\n",NC[I],TI[I]);

return 0;}
 

