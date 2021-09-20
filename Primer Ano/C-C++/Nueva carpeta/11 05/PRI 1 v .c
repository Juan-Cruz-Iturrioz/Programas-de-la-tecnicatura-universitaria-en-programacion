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

	else
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

for(DIV=2;DIV<NU/2;DIV++){
	
	if(!(NU%DIV))
	return 0;
	}

	return 1;
}

int SUMIN(int N){

	int I,K;
	
	if(PRIMOS(N-2)){
	
	printf("%d = %d + %d",N,2,N-2);
	
	return 1;
	
	}
	
		if(PRIMOS(N-4)){
				printf("%d = %d + %d +%d \n",N,2,2,N-4);
				return 1;
				
		}	
			
				
}
 

	







