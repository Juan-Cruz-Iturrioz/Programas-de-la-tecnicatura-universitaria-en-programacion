/*  VECTORES APAREADOS */


#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define NUM 5

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
								
		printf("\n\n\nFIN DEL PROGRAMA\n\n\n\n" );
		return 0 ;	
}  

void CARGAR ( int L[] , char S[] , float P[] , int N )
{
		int I ;
		/*   CARGA DE LOS VECTORES   */		
		for ( I = 0 ; I < N ; I++ ) {
				printf("\n\n    LEGAJO     =   ");
				scanf("%d" , &L[I] );
				printf("\n\n    SEXO       =   ");
				fflush(stdin);
				S[I] = getchar();
				printf("\n\n    PROMEDIO   =   ");
				scanf("%f" , &P[I] );
		}
			
}

void MIRAR ( int L[] , char S[] , float P[] , int N )
{
		int I ;
		/*   IMPRESION DE LOS DATOS   */
		printf("\n\n\t\t %10s %10s %12s\n" , "LEGAJO" , "SEXO" , "PROMEDIO" );	
		for ( I = 0 ; I < N ; I++ ) 
				printf("\n\n\t\t %10d %10c %12.2f" , L[I] , S[I] , P[I] );
		printf("\n");		
}


