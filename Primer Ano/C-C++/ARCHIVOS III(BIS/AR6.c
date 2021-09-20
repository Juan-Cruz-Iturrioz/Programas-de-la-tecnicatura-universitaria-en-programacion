/*   ARCHIVOS BINARIOS  */
/*   MODIFICACIONES        DUPLICAR LA EDAD DE TODAS LAS MUJERES  */


#include <stdio.h>
#include <stdlib.h>

struct ALUMNO {
		char NOM[20];
		char SEX ;
		int EDAD ;
};

int main( )
{  
		FILE * FP ;
		struct ALUMNO X ;
				
							
		if ( (FP = fopen("BD","r+b")) == NULL ) {
				printf("\n\n   ERROR APERTURA DE ARCHIVO \n\n");
				exit(1) ;			
		}
		
		
		fread ( &X , sizeof(X) , 1 , FP );
		while ( ! feof(FP)  ) {
				if ( X.SEX == 'F' ) {
						X.EDAD = 2 * X.EDAD ;
						fseek ( FP , (long)(-1)*sizeof(X) , SEEK_CUR );
						fwrite ( &X , sizeof(X) , 1 , FP );
						fseek ( FP , 0L , SEEK_CUR ); // FUNDAMENTAL !!
				}
				fread ( &X , sizeof(X) , 1 , FP );
				
		}
	
		fclose(FP) ;
					
		printf("\n\n");	
		return 0 ;
}
		
		

