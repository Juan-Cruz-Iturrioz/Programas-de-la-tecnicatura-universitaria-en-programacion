/*   ARCHIVOS BINARIOS  */
/*   ALTAS  */

#include <stdio.h>
#include <stdlib.h>

struct ALUMNO {
		char NOM[20];
		char SEX ;
		int EDAD ;
};

#define N 4

int main( )
{  
		FILE * FP ;
		struct ALUMNO X ;
		int I ;
						
		if ( (FP = fopen("BD","ab")) == NULL ) {
				printf("\n\n   ERROR APERTURA DE ARCHIVO \n\n");
				exit(1) ;			
		}
		
		for ( I = 0 ; I < N ; I++ ) {
				printf("\n\n   NOMBRE   :  ");
				fflush(stdin);
				gets ( X.NOM );
				printf("\n   SEXO     :  ");
				X.SEX = getchar();
				printf("\n   EDAD     :  ");
				scanf("%d", &(X.EDAD) );
			
				fwrite ( &X , sizeof(X) , 1 , FP );
		}
					
		fclose(FP) ;
					
		printf("\n\n");	
		return 0 ;
}
		
		

