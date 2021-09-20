/*   ARCHIVOS BINARIOS  */
/*   MODIFICACIONES        DUPLICAR LA EDAD DE "LAURA"  */

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
							
		if ( (FP = fopen("BD","rb")) == NULL ) {
				printf("\n\n   ERROR APERTURA DE ARCHIVO \n\n");
				exit(1) ;			
		}
		
		printf("\n\n\t\t %-15s %10s %10s\n" , "NOMBRE" , "SEXO" , "EDAD");
		fread ( &X , sizeof(X) , 1 , FP );
		while ( ! feof(FP) ) {
				printf("\n\n\t\t %-15s %10c %10d" , X.NOM , X.SEX , X.EDAD);
				fread ( &X , sizeof(X) , 1 , FP );
		}
	
		fclose(FP) ;
					
		printf("\n\n");	
		return 0 ;
}
		
		

