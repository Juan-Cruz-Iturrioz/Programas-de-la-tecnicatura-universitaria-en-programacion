/*   ARCHIVOS BINARIOS  */
/*   ACCESO RANDOM CON RESPECTO AL ORIGEN */

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
		int POS ;
							
		if ( (FP = fopen("BD","rb")) == NULL ) {
				printf("\n\n   ERROR APERTURA DE ARCHIVO \n\n");
				exit(1) ;			
		}
/*		
		printf("\n\n\t\t %-15s %10s %10s\n" , "NOMBRE" , "SEXO" , "EDAD");
		fread ( &X , sizeof(X) , 1 , FP );
		while ( ! feof(FP) ) {
				printf("\n\t\t %-15s %10c %10d" , X.NOM , X.SEX , X.EDAD);
				fread ( &X , sizeof(X) , 1 , FP );
		}
*/	
		printf("\n\n    POSICION   :   ");
		scanf("%d" , &POS);
		while ( POS >= 0 ) {
				fseek ( FP , (long)POS*sizeof(X) , SEEK_SET );
				fread ( &X , sizeof(X) , 1 , FP );
				printf("\n\t\t %-15s %10c %10d" , X.NOM , X.SEX , X.EDAD);
			
				printf("\n\n    POSICION   :   ");
				scanf("%d" , &POS);
		}
		
		fclose(FP) ;
					
		printf("\n\n");	
		return 0 ;
}
		
		

