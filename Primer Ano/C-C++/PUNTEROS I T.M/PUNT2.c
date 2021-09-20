/*   ARITMETICA DE PUNTEROS   */

#include <stdio.h>
#include <stdlib.h>



int main( )
{  
		short int * P ;
		int * Q ;
		
		P = (short int *)0X2000 ;
		Q = (int *)0X2000 ;
		
		printf("\n\n   P = %p        Q = %p " , P , Q );
	
		P = P + 4 ;
		Q = Q + 4 ;
	
		printf("\n\n\n\n   P = %p        Q = %p " , P , Q );
		
		printf("\n\n");	
		return 0 ;
}
		
		

