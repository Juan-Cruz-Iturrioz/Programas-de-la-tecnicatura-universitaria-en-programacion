#include <stdio.h>
#include <stdlib.h>

#define N 20

void D(int [],int,int);

int main(){


int I,DIV,L,VEN[N];

srand(674);

for(I=0;I<N;I++){
	
	VEN[I]= 1+rand()%99;
	
	}
	
	printf("IN DIV : ");
	scanf("%d",&DIV);
	
	printf("\n");
	
	D ( VEN , DIV, N);
return 0;}

void D(int V[], int DI , int NUM){

int K;
for(K=0;K<NUM;K++){
if(!(V[K]%DI))
printf("%3d es DIV por %-3d \n",V[K],DI);
}



}
