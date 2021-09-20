/*  VECTORES  */
/*  EJERCICIO  :  INTERCAMBIO DEL MINIMO CON EL PRIMERO   */


#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define NUM 20

void CARGAR ( int [] , int );
void MIRAR ( int [] , int );
void INTERCAMBIO ( int [] , int );

int main()
{
		int VEC[NUM] ;
		srand(65);
				
		CARGAR ( VEC , NUM );
		MIRAR ( VEC , NUM );
		
		INTERCAMBIO ( VEC , NUM );
		MIRAR ( VEC , NUM );	
			
				
		printf("\n\n\nFIN DEL PROGRAMA\n\n\n\n" );
		return 0 ;	
}  

void CARGAR ( int V[] , int N )
{
		int I ;
		/*   CARGA DEL VECTOR   */		
		for ( I = 0 ; I < N ; I++ ) 
				V[I] = rand()%100 ;
}

void MIRAR ( int V[] , int N )
{
		int I ;
		/*   IMPRESION DEL VECTOR   */
		printf("\n\n\n\n\t\tIMPRESION DEL VECTOR\n\n");		
		for ( I = 0 ; I < N ; I++ ) 
				printf("%4d" , V[I] );
}


void INTERCAMBIO ( int V[] , int N )
{
		int I , PM ;
		int AUX ;
		
		PM = 0 ;		
		for ( I = 1 ; I < N ; I++ ) 
				if ( V[I] < V[PM] ) 
						PM = I ;
		/*  SWAPPING  */
		AUX = V[0] ;
		V[0] = V[PM] ;
		V[PM] = AUX ;
		
		PM = 1 ;		
		for ( I = 2 ; I < N ; I++ ) 
				if ( V[I] < V[PM] ) 
						PM = I ;
		/*  SWAPPING  */
		AUX = V[1] ;
		V[1] = V[PM] ;
		V[PM] = AUX ;
}
