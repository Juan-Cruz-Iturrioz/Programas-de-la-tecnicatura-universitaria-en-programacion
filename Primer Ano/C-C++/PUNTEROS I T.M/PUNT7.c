/*   PASAJE POR REFERENCIA   */

#include <stdio.h>
#include <stdlib.h>

void FUNCION ( int , int * );

int main( )
{  
		int A , B ;
		
		A = 654 ;
		B = 852 ;
		
		printf("\n\n Antes de la funcion      A = %d      B = %d" , A , B );
				
		FUNCION ( A , &B );
		
		printf("\n\n Despues de la funcion    A = %d      B = %d" , A , B );
		
				
		printf("\n\n");	
		return 0 ;
}
		
		
void FUNCION ( int X , int * P )
{
		X = 2 * X ;
		//   B EQUIVALE A  *P
		*P = 2 * (*P) ;	// 	*P = 2 * * P ;
		*P = *P**P ;  /*   ELEVAMOS B*2 AL CUADRADO */
}
