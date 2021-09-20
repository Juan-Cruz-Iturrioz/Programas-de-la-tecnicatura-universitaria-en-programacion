/*   MODIFICADOR STATIC   */

#include <stdio.h>
#include <stdlib.h>

void FUNCION();

int main( )
{  
		int I ;
		
		for ( I = 0 ; I < 10 ; I++ )
				FUNCION() ;
							
		printf("\n\n fin del programa");
		return 0 ;
}

void FUNCION()
{
		int A = 15 ;
		static int B = 15 ;
		
		printf("\n\n  A = %d    B = %d       &A = %p   &B = %p" , 
		A , B , &A , &B );
		
		A++ ;
		B++ ;	
}

