
#include <stdio.h>

int PRIMO(int);

int main()
{
		int NUM,M,N,K=0;


		for(NUM=1;NUM<=20000;NUM++){
        N=0;
        M=0;
		if( PRIMO(NUM) ){
		N=NUM;
		M=N+2;
		}
		if( PRIMO(M)&&M!=0)
		printf("%d/%-d ",N,M);
        K=K+1;
        }

        printf("la c es %d",K);



		return 0;
}

	int PRIMO(int NUM){

	int DIV;

		for(DIV=2;DIV<=NUM/2;DIV++){

		if(!(NUM%DIV))
		return 0;

		return 1;


		}


	}



