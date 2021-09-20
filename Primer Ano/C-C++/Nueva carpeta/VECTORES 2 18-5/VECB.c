/*  VECTORES APAREADOS */


#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define NUM 16

void CARGAR ( int [] , char [] , float [] , int );
void MIRAR ( int [] , char [] , float [] , int );

int main()
{
		int LEG[NUM] ;
		char SEX[NUM] ;
		float PROM[NUM] ;
		
		srand(674);
				
		CARGAR ( LEG , SEX , PROM , NUM );
		MIRAR ( LEG , SEX , PROM , NUM );
								
		printf("\n\nFIN DEL PROGRAMA\n" );
		return 0 ;	
}  

void CARGAR ( int L[] , char S[] , float P[] , int N )
{
		int I ;
		/*   CARGA DE LOS VECTORES   */		
		for ( I = 0 ; I < N ; I++ ) {
				L[I] =  10000 + rand()%90000 ;
				//      S[I] =  'F' + (rand()%2)*('M'-'F');
				S[I] = (rand()%2) ? 'M' : 'F' ;
				P[I] =  2 + (rand()%801)/100.0   ;
		}
			
}

void MIRAR ( int L[] , char S[] , float P[] , int N )
{
		int I ;
		/*   IMPRESION DE LOS DATOS   */
		printf("\n\n\t\t %10s %10s %12s\n" , "LEGAJO" , "SEXO" , "PROMEDIO" );	
		for ( I = 0 ; I < N ; I++ ) 
				printf("\n\t\t %10d %10c %12.2f" , L[I] , S[I] , P[I] );
		printf("\n");		
}


