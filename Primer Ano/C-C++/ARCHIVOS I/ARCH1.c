/*   ARCHIVOS DE TEXTO  */
/*   ESCRITURA EN ARCHIVO */

#include <stdio.h>
#include <stdlib.h>



int main( )
{  
		FILE * FP ;
		char CAR ;
		
		if ( (FP = fopen("PEPE","w")) == NULL ) {
				printf("\n\n   ERROR APERTURA DE ARCHIVO \n\n");
				exit(1) ;			
		}
		
		CAR = getchar() ;
		while ( CAR != '$' ) {
			putc ( CAR , FP );
			CAR = getchar() ;
		}
			
		fclose(FP) ;
					
		printf("\n\n");	
		return 0 ;
}
		
		

