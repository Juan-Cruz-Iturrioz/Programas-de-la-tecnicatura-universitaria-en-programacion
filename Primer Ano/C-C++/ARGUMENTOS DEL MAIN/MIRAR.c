/*   ARGUMENTOS DEL MAIN    */

#include <stdio.h>
#include <stdlib.h>

int main( int argc , char ** argv )
{  
		int I ;
		
		if ( argc != 3 ) {
				printf("\n\n CANTIDAD DE ARGUMENTOS INCORRECTA");
				exit(1);
		};
		
		printf("\n\n\n   SEGUNDO ARGUMENTO \n\n");
		for ( I = 0 ; I < atoi(*(argv+1)) ; I++ )
				printf("\n\n\t\t %s" , *(argv+2) );
				
		
		printf("\n\n");	
		return 0 ;
}
		
		

