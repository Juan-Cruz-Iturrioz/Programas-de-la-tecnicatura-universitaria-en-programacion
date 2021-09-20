/*  MATRICES  */
/*  COLOCA 8 "REINAS" CADA UNA EN SU COLUMNA   */

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <unistd.h>

#define FILAS    8
#define COLUMNAS 8

void GENERAR ( int [][COLUMNAS] , int  , int );
void MIRAR   ( int [][COLUMNAS] , int  , int );
int SOLUCION  ( int [][COLUMNAS] , int  , int );

int main()
{
		int MAT[FILAS][COLUMNAS] ;
		srand ( 654 );

		while(1) {
				GENERAR ( MAT , FILAS , COLUMNAS );
				MIRAR   ( MAT , FILAS , COLUMNAS );   getchar();
		}
		
		printf("\n" );
		getchar();
		return 0 ;	
}  	
		
	
void GENERAR ( int M[][COLUMNAS] , int F , int C )
{
		int I , J ;				
		
		/*   CARGAR LOS VALORES DE LA MATRIZ   */
		for ( I = 0 ; I < F ; I++ )
				for ( J = 0 ; J < C ; J++ ) 
						M[I][J]  =  0 ;
		for ( J = 0 ; J < C ; J++ ) 
				M[rand()%C][J]  =  1 ;										
}
				
		
void MIRAR ( int M[][COLUMNAS] , int F , int C )
{
		int I , J ;					
		
		system("cls") ;
		/*   IMPRESION DE LOS VALORES DE LA MATRIZ   */
		printf("\n");		
		for ( I = 0 ; I < F ; I++ ) {
				printf("\n\n\n\t      ");
				for ( J = 0 ; J < C ; J++ ) 
						printf("%5d" , M[I][J] );
		}
		printf("\n");
		sleep(3);
//		if (SOLUCION(MAT,F,C))
//			priintf("\n  SE DETECTO UNA SOLUCION AL PROBLEMA DE LAS 8 REINAS ");
}
