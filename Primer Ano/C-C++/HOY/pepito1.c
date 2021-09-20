#include <stdio.h>

int main(){
		int I,J,E;

		for(I=0;I<20;I++){

				for(J=0;J<39-I;J++)
						putchar(' ');

				for(J=0;J<2*I+1;J++)
						putchar('*');   	

				printf("\n");	   
		}

		return 0 ;
}
