#include <stdio.h>
#include <stdlib.h>

#define N 1000
#define DA 6
int DADOS();

int main(){


int I,K,D,VEN[DA];

for(K=0;K<DA;K++)
VEN[K]=0;

srand(674);

for(I=0;I<N;I++){
	D=DADOS();

	for(K=1;K<=DA;K++){
		if(K==D)
		VEN[K-1] = VEN [K-1] + 1;
		}
		
	}
for(K=0;K<(DA);K++)
printf("la c %d es %d \n",K+1,VEN[K]);
	
	
	
return 0;}

int DADOS(){
return 1+rand()%DA;

}

 

