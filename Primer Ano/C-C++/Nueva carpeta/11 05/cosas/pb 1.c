#include <stdio.h>

void SUM (int);
int PRIMOS(int);
int main(){

int NUM;

printf("in NUM : ");
scanf("%d",&NUM);

SUM(NUM);


return 0;}

void SUM(int N){

int I,K,S;

for(I=2;I<N;I++){
	for(K=2,S=0;K<N;K++){
	S=I+K;
		if(S==N){
			if(PRIMOS(I)&&PRIMOS(K))
			printf("%d = %d + %d \n",N,I,K);
		
		}
	
	}

}}

int PRIMOS(int NU){

int DIV;

for(DIV=2;DIV<NU;DIV++){
	
	if(!(DIV%NU))
	return 0;
	}
	
	return 1;
}








