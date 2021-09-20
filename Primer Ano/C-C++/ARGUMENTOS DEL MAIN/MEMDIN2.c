/*   GESTION DINAMICA DE MEMORIA    */

#include <stdio.h>
#include <stdlib.h>

int main( )
{  
		int C ;
		float F ;
				
		for ( C = 0 ; malloc(1000) ; C++ ) 
			printf("%10d" , C);
		
		printf("\n\n\n   MEMORIA OBTENIDA = %d" , 1000 * C );
		F = (float)(1000*C)/1024 ;	
		F = F/1024 ;	
		F = F/1024 ;	
		
		printf("\n\n\n   MEMORIA OBTENIDA = %.2f   GB" , F );
		
		printf("\n\n");	
		return 0 ;
}
		
		

