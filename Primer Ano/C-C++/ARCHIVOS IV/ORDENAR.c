/*   ARCHIVOS BINARIOS  */
/*   LECTURA  */

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
		struct ALUMNO X , Y ;
		int N , I , J ;
							
		if ( (FP = fopen("BD","r+b")) == NULL ) {
				printf("\n\n   ERROR APERTURA DE ARCHIVO \n\n");
				exit(1) ;			
		}
		
		fseek ( FP , 0L , SEEK_END );
		N = ftell(FP) / sizeof(X) ;
		printf("\n\n    BD TIENE %d REGISTROS" , N);
		getchar();
	
		for ( I = 0 ; I < N-1 ; I++ )
				for ( J = 0 ; J < N-I-1 ; J++ )  {
						fseek ( FP , (long)J*sizeof(X) , SEEK_SET );
						fread ( &X , sizeof(X) , 1 , FP );
						fread ( &Y , sizeof(Y) , 1 , FP );
						if ( strcmp(X.NOM,Y.NOM) > 0 ) {
							fseek ( FP , (long)J*sizeof(X) , SEEK_SET );
							fwrite ( &Y , sizeof(Y) , 1 , FP );
							fwrite ( &X , sizeof(X) , 1 , FP );
						}
				}
			
		fclose(FP) ;
					
		printf("\n\n");	
		return 0 ;
}
		
		

