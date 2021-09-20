#include <stdio.h>
#include <stdlib.h>

#define N 20

float PRO(int [],int);

int main(){


int I,VEN[N];

srand(674);

for(I=0;I<N;I++){
	
	VEN[I]= 1+rand()%99;
	
	}

	printf("el PRO ES %2.2f ",PRO ( VEN , N));
	
	
return 0;}

float PRO(int V[], int NUM){

int K,T=0;
for(K=0;K<NUM;K++){
T=T+V[K];
}

return T/NUM;

}
