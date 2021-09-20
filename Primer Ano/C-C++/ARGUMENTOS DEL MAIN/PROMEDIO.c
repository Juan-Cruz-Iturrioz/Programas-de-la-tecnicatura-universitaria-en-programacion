/*   ARGUMENTOS DEL MAIN    */

#include <stdio.h>
#include <stdlib.h>

int main( int argc , char ** argv )
{  
		int SUMA ;
		
		if ( ! ( argc-1) ) {
				printf("\n\n   NO HAY ARGUMENTOS");
				exit(1) ;
		}
		
		for ( SUMA = 0 ; *(argv+1) ; argv++ )
				SUMA = SUMA + atoi(*(argv+1));
		
		printf("\n\n\n   PROMEDIO = %.2f" , (float)SUMA / (argc-1) );	
		
		printf("\n\n");	
		return 0 ;
}
		
		

