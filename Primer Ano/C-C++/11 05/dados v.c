#include <stdio.h>

#include<conio.h>

#include<stdlib.h>

#define N 1000

#define CARAS 6

int main(){

int I,K,SUMC;

int DADOS[N];

	for(I=0;I<N;I++){
	
	 DADOS[I]=rand()%CARAS+1;
	
	}
	
	for(K=1;K<=CARAS;K++){
	SUMC=0;
		for(I=0;I<N;I++){
		
			if( DADOS[I]==K)
			SUMC++;
		}
	
	printf("la catidar de DADOS CON CARAS %d SON %d \n",K,SUMC);
	
	}
	

return 0;}
