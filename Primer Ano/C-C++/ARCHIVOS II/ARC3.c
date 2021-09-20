/*   ARCHIVOS BINARIOS  */
/*   LECTURA        ESTRUCTURA DE CODIGO ERRONEA  */

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
		int A ;
							
		if ( (FP = fopen("BD","rb")) == NULL ) {
				printf("\n\n   ERROR APERTURA DE ARCHIVO \n\n");
				exit(1) ;			
		}
		
		printf("\n\n\t %-15s %10s %10s\n" , "NOMBRE" , "SEXO" , "EDAD");
		while ( ! feof(FP) ) {
				A = fread ( &X , sizeof(X) , 1 , FP );
				printf("\n\n\t %-15s %10c %10d \t\t\t %d" , 
				X.NOM , X.SEX , X.EDAD , A );
		}
	
		fclose(FP) ;
					
		printf("\n\n");	
		return 0 ;
}
		
		

