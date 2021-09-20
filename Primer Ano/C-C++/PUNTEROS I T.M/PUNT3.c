/*   ARITMETICA DE PUNTEROS   */

#include <stdio.h>
#include <stdlib.h>



int main( )
{  
		int * P ;
		int * Q ;
		
		P = (int *)0X2000 ;
		Q = (int *)0X200A ;
		
		printf("\n\n   P = %p        Q = %p " , P , Q );
		printf("\n\n\n\n   Q-P = %d     " , Q-P );
		
		printf("\n\n");	
		return 0 ;
}
		
		

