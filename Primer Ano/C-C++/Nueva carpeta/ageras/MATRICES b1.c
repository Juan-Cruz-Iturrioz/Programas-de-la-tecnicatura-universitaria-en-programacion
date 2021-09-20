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
void SOLUCION  ( int [][COLUMNAS] , int  , int );

int main()
{
	srand(1969);
		int MAT[FILAS][COLUMNAS] ;
		
				GENERAR ( MAT , FILAS , COLUMNAS );
				MIRAR   ( MAT , FILAS , COLUMNAS ); 
				SOLUCION ( MAT , FILAS , COLUMNAS );
				 
		
		
		printf("\n" );
	
		return 0 ;	
}  	
		
	
void GENERAR ( int M[][COLUMNAS] , int F , int C )
{
		int I , J=0 ;				
		
		/*   CARGAR LOS VALORES DE LA MATRIZ   */
		for ( I = 0 ; I < F ; I++ )
				for ( J = 0 ; J < C ; J++ ) 
				M[I][J]  =  1+rand()%100;
					
		/*for ( J = 0 ; J < C ; J++ ) 
				M[C][J]  =  1 ;			*/							
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
//		if (SOLUCION(MAT,F,C))
//			priintf("\n  SE DETECTO UNA SOLUCION AL PROBLEMA DE LAS 8 REINAS ");
}

void SOLUCION ( int M[][COLUMNAS] , int F , int C ){
int I,J,L=0,D=0,IA,JA,R;
//IA de I aux+1
//JA de J aux

	for(I=0;I<F;I++)
		for(J=0;J<C;J++)
		
			if(M[I][J]==45){
				for(R=1, IA = I , JA = J , D=M [IA] [JA],L=D; IA < F /*&& /*JA < J */; JA++, IA++ ,R=R+2){
				D = D+M [IA+1] [JA+1];
				printf("\n D = %d", M [IA] [JA]);
				
				printf("\t SL = %d",L );
				if(JA<C-2){
				L = L+ M [IA+1] [JA-R];
				
				printf("\t L = %d",M [IA+1] [JA-R] );
				
				}
				
				
				}
			
				/*for( R = 2 , IA = I , JA = J ; IA-1 > 0 &&  -1 > 0; IA-- ,JA-- ){
				S = S + M [IA] [JA];
				D = D + M [JA] [IA];
				}*/
			
				
			}
			
			printf("\n\nD=%d ,L=%d",D,L);
			
		
			

}
