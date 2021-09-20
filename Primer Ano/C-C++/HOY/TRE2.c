#include <stdio.h>

int main(){
		int I,J;

		for(I=0;I<20;I++){

				for(J=0;J<40;J++)
						putchar(' ');

				for(J=0;J<I+1;J++)
						putchar('*');   //getchar();

				printf("\n");	   
		}

		return 0 ;
}
