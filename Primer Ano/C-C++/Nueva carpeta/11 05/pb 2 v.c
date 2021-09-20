#include <stdio.h>

int SUM (int);
int PRIMOS(int);
int main(){

int NUM;

printf("in NUM : ");
scanf("%d",&NUM);

SUM(NUM);


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








