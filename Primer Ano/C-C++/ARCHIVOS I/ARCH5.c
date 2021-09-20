/*   ARCHIVOS DE TEXTO  */
/*   LECTURA DE ARCHIVO      USO DE FEOF()    */

#include <stdio.h>
#include <stdlib.h>

int main( )
{  
		FILE * FP ;
		unsigned char CAR ;
		
		if ( (FP = fopen("ARCH2.EXE","rb")) == NULL ) {
				printf("\n\n   ERROR APERTURA DE ARCHIVO \n\n");
				exit(1) ;			
		}
		
		CAR = getc(FP) ;
		while ( ! feof(FP) ) {
			printf("%02X  " , CAR); 
			CAR = getc(FP) ;
		}
			
		fclose(FP) ;
					
		printf("\n\n");	
		return 0 ;
}
		
		

