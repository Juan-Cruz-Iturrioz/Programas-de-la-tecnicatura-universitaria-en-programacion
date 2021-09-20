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
int R=0;
		int MAT[FILAS][COLUMNAS] ;
		srand ( 1969 );

		while(R==0) {
				GENERAR ( MAT , FILAS , COLUMNAS );
				R=SOLUCION ( MAT , FILAS , COLUMNAS );  //getchar();
		}
		MIRAR   ( MAT , FILAS , COLUMNAS );
		printf("\n" );
		//getchar();
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
				M[J][rand()%C]  =  1 ;										
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
	//	sleep(3);
//		if (SOLUCION(MAT,F,C))
//			priintf("\n  SE DETECTO UNA SOLUCION AL PROBLEMA DE LAS 8 REINAS ");
}

int SOLUCION  ( int M [][COLUMNAS] , int F , int C){

int I,J,K,N,R,RA;
	
	for(I=0;I<F;I++)
	
	for(J=0;J<C;J++)
	if(M[I][J]==1){
	R=I;
	
	for(K=I+1;K<F;K++)
	for(N=0;N<C;N++)
	
	
	if(M[K][N]==1){
	RA=K;
	
	if(R+J==RA+N)
	return 0;
	if(J==N)
	return 0;
	if(R-J==RA-N)
	return 0;
	}
	
	
	
	
	}


return 1;}

