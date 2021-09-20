#include <stdio.h>

int main(){
		int I,J,E;

		for(I=0;I<20;I++){

				for(J=0;J<40;J++)
						putchar(' ');

				for(E=0;E<I+1;E++)
						putchar('*');   	

				printf("\n");	   
		}

		return 0 ;
}
