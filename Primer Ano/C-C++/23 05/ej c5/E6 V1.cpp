#include <stdio.h>
#include <stdlib.h>

#define N 5

int CRE(int [], int );

int main () {

int I,VEN[N];

for(I=0;I<N;I++){
VEN[I]=N+I;
printf("%d \n",VEN[I]);
}

	if(CRE(VEN,N))
	printf("ES CRE");
	else
	printf("NO ES CRE");

return 0;}
 
int CRE(int V[] ,int NUM){

int K,L=1;

	for(K=0;K<NUM;K++){
	if(V[K+1]>V[K])
	L=L+1;
	}
	
	if(L==NUM)
	return 1;
	
	return 0;
}
