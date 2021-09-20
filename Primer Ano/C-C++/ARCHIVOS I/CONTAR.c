/*   ARCHIVOS DE TEXTO  */
/*   LECTURA DE ARCHIVO      USO DE FEOF()    */

#include <stdio.h>
#include <stdlib.h>

int main( int argc , char ** argv )
{  
		FILE * FP ;
		unsigned char CAR ;
		int TAM = 0 ;
		
		if ( (FP = fopen( *(argv+1) ,"rb")) == NULL ) {
				printf("\n\n   ERROR APERTURA DE ARCHIVO \n\n");
				exit(1) ;			
		}
		
		CAR = getc(FP) ;
		while ( ! feof(FP) ) {
			//printf("%02X  " , CAR);
			TAM++ ; 
			CAR = getc(FP) ;
		}
			
		fclose(FP) ;
					
		printf("\n\n %s MIDE %d BYTES\n\n" , *(argv+1) , TAM);	
		return 0 ;
}
		
		

