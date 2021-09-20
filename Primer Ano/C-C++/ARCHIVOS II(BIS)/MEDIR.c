/*   MIDE EL TAMAÑO DE UN ARCHIVO  */

#include <stdio.h>
#include <stdlib.h>

int main( int argc , char ** argv )
{  
		FILE * FP ;
		
		if ( (FP = fopen( *(argv+1) ,"rb")) == NULL ) {
				printf("\n\n   ERROR APERTURA DE ARCHIVO \n\n");
				exit(1) ;			
		}
		
		fseek ( FP , 0L , SEEK_END );
		printf("\n\n\t %s MIDE %d BYTES" , *(argv+1) ,  ftell(FP) );
				
		fclose(FP) ;
					
		printf("\n\n");	
		return 0 ;
}
		
		

