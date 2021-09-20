/*  VECTORES  */
/*  ORDENAMIENTO POR BURBUJEO   */


#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define NUM 100000

void CARGAR ( int [] , int );
void MIRAR ( int [] , int );
void BURBUJA ( int [] , int );

int main()
{
		int VEC[NUM] ;
		srand(61);
				
		CARGAR ( VEC , NUM );
//		MIRAR ( VEC , NUM );
		
		BURBUJA ( VEC , NUM );
//		MIRAR ( VEC , NUM );	
			
				
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


void BURBUJA ( int V[] , int N )
{
		int I , J ;
		int AUX ;
		
		for ( I = 0 ; I < N-1 ; I++ ) 
				for ( J = 0 ; J < N-I-1 ; J++ )
						if ( V[J] > V[J+1] )  {
								/*   swapping  */
								AUX    = V[J] ;
								V[J]   = V[J+1] ;
								V[J+1] = AUX ;							
						}
}
