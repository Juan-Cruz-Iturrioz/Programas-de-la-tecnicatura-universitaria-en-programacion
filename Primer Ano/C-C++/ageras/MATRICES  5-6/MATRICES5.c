/*  MATRICES  */
/*  AUTOMATIZAR LA CARGA   */
/*  MODULARIZANDO EL PROGRAMA  */


#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <time.h>

#define FILAS    8
#define COLUMNAS 8

void GENERAR ( int [][COLUMNAS] , int  , int );
void MIRAR   ( int [][COLUMNAS] , int  , int );

int main()
{
		int MAT[FILAS][COLUMNAS] ;
		srand ( 654 );

		GENERAR ( MAT , FILAS , COLUMNAS );
		MIRAR   ( MAT , FILAS , COLUMNAS );
		
		printf("\n\n\nFIN DEL PROGRAMA\n\n" );
		return 0 ;	
}  	
		
	
void GENERAR ( int M[][COLUMNAS] , int F , int C )
{
		int I , J ;				
		
		/*   CARGAR LOS VALORES DE LA MATRIZ   */
		for ( I = 0 ; I < F ; I++ )
				for ( J = 0 ; J < C ; J++ ) 
						M[I][J]  =  rand()%100 ;
}
				
		
void MIRAR ( int M[][COLUMNAS] , int F , int C )
{
		int I , J ;					
		
		/*   IMPRESION DE LOS VALORES DE LA MATRIZ   */
		printf("\n\n\n");		
		for ( I = 0 ; I < F ; I++ ) {
				printf("\n\n\n\t      ");
				for ( J = 0 ; J < C ; J++ ) 
						printf("%5d" , M[I][J] );
		}
}
