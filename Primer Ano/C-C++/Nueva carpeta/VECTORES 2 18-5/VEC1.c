/*  VECTORES  */
/*  ORDENAMIENTO POR SELECCION   */


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
		srand(61);
				
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
		int AUX , PRIMERO ;
		
		for ( PRIMERO = 0 ; PRIMERO < N-1 ; PRIMERO++ ) {
				PM = PRIMERO ;	
				for ( I = PRIMERO+1 ; I < N ; I++ ) 
						if ( V[I] < V[PM] ) 
								PM = I ;
				/*  SWAPPING  */
				AUX = V[PRIMERO] ;
				V[PRIMERO] = V[PM] ;
				V[PM] = AUX ;
		//		MIRAR(V,N);getch();
		}	
			
}
