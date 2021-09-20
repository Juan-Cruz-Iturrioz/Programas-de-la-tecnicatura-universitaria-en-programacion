/*   ARCHIVOS DE TEXTO  */
/*   ESCRITURA CON FORMATO   */

#include <stdio.h>
#include <stdlib.h>

int main( )
{  
		FILE * FP ;
		float F ;
		F = 7.5 ;
		
		if ( (FP = fopen("FLOTA","w")) == NULL ) {
				printf("\n\n   ERROR APERTURA DE ARCHIVO \n\n");
				exit(1) ;			
		}
		
		fprintf ( FP , "%f" , F );
			
		fclose(FP) ;
					
		fprintf(stdout,"\n\n   FIN DE ESTE MARAVILLOSO PROGRAMA\n\n");	
		return 0 ;
}
		
		

