#include <stdio.h>

int SUM (int);
int SUM_IN(int);
int PRIMOS(int);
int main(){

int NUM;

printf("in NUM : ");
scanf("%d",&NUM);

if(!(NUM%2))
SUM(NUM);
else
SUN_IN(NUM);
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

int SUM_IN(int N){

int I,K,J;

for(I=2;I<N;I++){
for(K=2;K<N;K++){
J=N-I-K;
		if(PRIMOS(I)&&PRIMOS(K)&&PRIMOS(J)){
	
			printf("%d = %d + %d \n",N,I,N-I);
			return 1;
			}
		}	
 	}
 
 }
	







