/*   ARCHIVOS DE TEXTO  */
/*   LECTURA DE ARCHIVO */

#include <stdio.h>
#include <stdlib.h>



int main( )
{  
		FILE * FP ;
		char CAR ;
		
		if ( (FP = fopen("arch2.c","r")) == NULL ) {
				printf("\n\n   ERROR APERTURA DE ARCHIVO \n\n");
				exit(1) ;			
		}
		
		CAR = getc(FP) ;
		while ( CAR != EOF ) {
			putchar ( CAR );
			CAR = getc(FP) ;
		}
			
		fclose(FP) ;
					
		printf("\n\n");	
		return 0 ;
}
		
		

