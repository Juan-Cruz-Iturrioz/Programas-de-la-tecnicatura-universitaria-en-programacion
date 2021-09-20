/*   ARCHIVOS BINARIOS  */
/*   BUSQUEDA BINARIA  */

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
		char BUF[20];
		int MIN , MAX , MED , ENCONTRADO , N ;
							
		if ( (FP = fopen("BD","rb")) == NULL ) {
				printf("\n\n   ERROR APERTURA DE ARCHIVO \n\n");
				exit(1) ;			
		}
		
		fseek ( FP , 0L , SEEK_END );
		N = ftell(FP) / sizeof(X) ;
		printf("\n\n    BD TIENE %d REGISTROS" , N);
		getchar();
		
		printf("\n\n    NOMBRE A BUSCAR  :  " );
		gets(BUF) ;
		
		MIN = 0 ;
		MAX = N-1 ;
		ENCONTRADO = 0 ;
		
		while ( MIN <= MAX && ! ENCONTRADO ) {
				MED = ( MIN + MAX ) / 2 ;
				fseek ( FP , (long)MED*sizeof(X) , SEEK_SET );
				fread ( &X , sizeof(X) , 1 , FP );
				printf("\n %2d   %12s  %6d  %6d " , 
				MED , X.NOM , MIN , MAX);
				getchar();
				if ( ! strcmp( BUF , X.NOM) ) 
						ENCONTRADO = 1 ;					
				else 
						if ( strcmp( BUF , X.NOM) < 0 )
								MAX = MED-1 ;
						else 	
								MIN = MED+1 ;
		}
		
		if ( ! ENCONTRADO )
				printf("\n\n  %s NO ESTA EN EL ARCHIVO" , BUF);
		else {
				fseek ( FP , (long)MED*sizeof(X) , SEEK_SET );
				fread ( &X , sizeof(X) , 1 , FP );
				printf("\n\n\t\t %-15s %10s %10s\n" , 
				"NOMBRE" , "SEXO" , "EDAD");
				printf("\n\n\t\t %-15s %10c %10d" , 
				X.NOM , X.SEX , X.EDAD);			
		}
					
		fclose(FP) ;
					
		printf("\n\n");	
		return 0 ;
}
		
		

