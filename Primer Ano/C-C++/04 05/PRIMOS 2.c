
#include <stdio.h>

int PRIMO(int);

int main()
{
		int NUM,M;
        M=0;
		for(NUM=1;NUM<=100;NUM++){

		if( PRIMO(NUM) )
		printf("%d\n",NUM);
		M=M+1;
		}

        printf("%d",M);
		return 0;
}

	int PRIMO(int NUM){

	int DIV;

		for(DIV=2;DIV<=NUM/2;DIV++){

		if(!(NUM%DIV))
		return 0;

		


		}

return 1;
	}



