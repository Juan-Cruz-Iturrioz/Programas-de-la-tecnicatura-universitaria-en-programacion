#include <stdio.h>

int SUM (int);
int SUMIN(int);
int PRIMOS(int);
int main(){

int NUM;

printf("in NUM : ");
scanf("%d",&NUM);

if(!(NUM%2))
SUM(NUM);

if(NUM%2)
SUMIN(NUM);
return 0;}

int SUM(int N){


int I;

for(I=2;I<N;I++){

		if(PRIMOS(I)&&PRIMOS(N-I)){
	
			printf("%d = %d + %d \n",N,I,N-I);
			return 1;
			}
			
	
	}

}


int PRIMOS(int NU){

int DIV;

for(DIV=2;DIV<NU;DIV++){
	
	if(!(NU%DIV))
	return 0;
	}

	return 1;
}

int SUMIN(int N){

	int I,K;

	for(I=2;I<N;I++){
		for(K=2;K<N;K++){
	
			
	
			if(PRIMOS(I)&&PRIMOS(K)&&PRIMOS(N-I-K)){
			
				
				printf("%d = %d + %d +%d \n",N,I,K,N-I-K);
				return 1;
				
				}	
			}
		}		
}
 

	







