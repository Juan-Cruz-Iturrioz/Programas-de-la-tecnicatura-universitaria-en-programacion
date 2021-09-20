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


int PRIMOS(int N){

int DIV;

for(DIV=2;DIV<N;DIV++){
	
	if(!(N%DIV))
	return 0;
	}

	return 1;
}

int SUMIN(int N){

			if(PRIMOS(N-4)){
	
				printf("%d = %d + %d +%d \n",N,2,2,N-4);
				return 1;
			}
}
 	
 

	







