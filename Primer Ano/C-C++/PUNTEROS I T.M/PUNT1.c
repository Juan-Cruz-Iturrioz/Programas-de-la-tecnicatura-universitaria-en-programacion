/*   PUNTEROS   */

#include <stdio.h>
#include <stdlib.h>



int main( )
{  
		int A ;
		int * P ;
		float * Q ;
		
		A = 654 ;
		P = &A ;
		
		printf("\n\n   A = %d    &A = %p    P = %p    *P = %d" , 
		A , &A , P , *P );
		
		*P = 89754 ;
		
		printf("\n\n   A = %d    &A = %p    P = %p    *P = %d" , 
		A , &A , P , *P );
		
		
		Q = (float *)P ;
		printf("\n\n\n   Q = %p    P = %p   " , Q , P );
		printf("\n\n\n   *Q = %f    *P = %d   " , *Q , *P );
		
		P = (int *)0X28FEB8 ;
		printf("\n\n\n   P = %p   *P = %d   " , P , *P );
		
	
		
		printf("\n\n\n\n\n   DIRCCION DE FUNCIONES  PRINTF = %p  MAIN = %p " , printf , main );
		
		printf("\n\n");	
		return 0 ;
}
		
		

