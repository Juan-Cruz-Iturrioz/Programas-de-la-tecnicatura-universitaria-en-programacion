/*  VECTOR DE STRINGS  */
/*  ORDENAMIENTO  */


#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>

#define NUM   12
#define LARGO 20

void CARGAR ( char [][LARGO] , int );
void MIRAR ( char [][LARGO] , int );
void ORDENAR ( char [][LARGO] , int );

int main()
{
		char VS[NUM][LARGO];
		
		CARGAR ( VS , NUM );
		MIRAR ( VS , NUM );
		
		ORDENAR ( VS , NUM );
		MIRAR ( VS , NUM );
		
		printf("\n\n\n");
		return 0 ;	
}  	
				

void CARGAR ( char VS[][LARGO] , int N )
{
		char VSAUX[NUM][LARGO] = {"FELIPE","ANA","LAURA","ESTEBAN",
							   "PEPE","LOLA","PACO","LUIS",
							   "CHRISTIAN","PAULA","LAUTARO","PEDRO"};
		int I ;
		
		for ( I = 0 ; I < N ; I++ )
				strcpy ( VS[I] , VSAUX[I] ) ;		
}

void MIRAR ( char VS[][LARGO] , int N )
{
		int I ;
					
		printf("\n\n\n");
		for ( I = 0 ; I < N ; I++ )  
				printf("\n\t\t %s" , VS[I] );			
		printf("\n\n\n");
		getchar();
}


void ORDENAR ( char VS[][LARGO] , int N )
{
		int I , J ;
		char AUX[LARGO] ;
					
		for ( I = 0 ; I < N-1 ; I++ )
				for ( J = 0 ; J < N-I-1 ; J++ )
						if ( strcmp(VS[J] , VS[J+1] ) > 0 )  {
								/*  SWAPPING  */
								strcpy ( AUX , VS[J] );
								strcpy ( VS[J]  , VS[J+1] );
								strcpy ( VS[J+1] , AUX ) ;						
						}
}
