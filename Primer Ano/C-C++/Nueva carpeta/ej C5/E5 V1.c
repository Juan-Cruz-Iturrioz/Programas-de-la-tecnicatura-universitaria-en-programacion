#include <stdio.h>
#include <stdlib.h>

#define N 20
#define DA 6-1
int DADOS();

int main(){


int I,K,D,VEN[DA+1];

for(K=0;K<(DA+1);K++)
VEN[K]=0;

srand(674);

for(I=0;I<=N;I++){
	D=DADOS();

	for(K=0;K<7;K++){
		
		if(K==D)
		VEN[K] = VEN [K] + D/K;
		}
		
	}
for(K=0;K<(DA+1);K++)
printf("la c %d es %d \n",K+1,VEN[K]);
	
	
	
return 0;}

int DADOS(){
return 1+rand()%DA;

}

 

