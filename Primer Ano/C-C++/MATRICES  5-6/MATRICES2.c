/*  MATRICES  */
/*  AUTOMATIZAR LA CARGA   */


#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

#define FILAS    3
#define COLUMNAS 4



int main()
{
		int MAT[FILAS][COLUMNAS] ;
		int I , J ;
		srand ( 654 );

		/*   CARGAR LOS VALORES DE LA MATRIZ   */
		for ( I = 0 ; I < FILAS ; I++ )
				for ( J = 0 ; J < COLUMNAS ; J++ ) 
						MAT[I][J]  =  rand()%100 ;
			
				
		
		/*   IMPRESION DE LOS VALORES DE LA MATRIZ   */
		printf("\n\n\n");		
		for ( I = 0 ; I < FILAS ; I++ ) {
				printf("\n\n\n\t\t\t");
				for ( J = 0 ; J < COLUMNAS ; J++ ) 
						printf("%6d" , MAT[I][J] );
		}
	
		printf("\n\n\nFIN DEL PROGRAMA\n\n\n\n" );
		return 0 ;	
}  	
		
		

