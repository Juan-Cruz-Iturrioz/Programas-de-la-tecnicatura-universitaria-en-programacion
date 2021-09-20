/*  VECTORES  */
/*  BUSQUEDA BINARIA   */


#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define NUM 2000000

void CARGAR ( int [] , int );
void MIRAR ( int [] , int );
void ORDENAR ( int [] , int );
int BUSBIN ( int [] , int , int );

int main()
{
		int VEC[NUM] ;
		int X , POS ;
		srand(674);
				
		CARGAR ( VEC , NUM );
		MIRAR ( VEC , NUM );
				
		ORDENAR ( VEC , NUM );
		MIRAR ( VEC , NUM );
				
		printf("\n\n   VALOR A BUSCAR  =  ");
		scanf("%d" , &X);
		
		POS = BUSBIN ( VEC , NUM , X );
		
		if ( POS < 0 )
			printf("\n\n  %d NO SE ENCUENTRA EN EL VECTOR" , X );
		else		
			printf("\n\n  %d SE ENCUENTRA EN LA POSICION %d" , X , POS);	
				
		printf("\n\n\nFIN DEL PROGRAMA\n\n\n\n" );
		return 0 ;	
}  

void CARGAR ( int V[] , int N )
{
		int I ;
		/*   CARGA DEL VECTOR   */		
		for ( I = 0 ; I < N ; I++ ) 
				V[I] = rand()%10000 ;
}

void MIRAR ( int V[] , int N )
{
		int I ;
		/*   IMPRESION DEL VECTOR   */
		printf("\n\n\n\n\t\tIMPRESION DEL VECTOR\n\n");		
		for ( I = 0 ; I < N ; I++ ) 
				printf("%4d" , I );
		printf("\n");
		for ( I = 0 ; I < N ; I++ ) 
				printf("%4d" , V[I] );
}

void ORDENAR ( int V[] , int N )
{
		int I , J ;
		int AUX ;
				
		for ( I = 0 ; I < N-1 ; I++ ) 
				for ( J = 0 ; J < N-I-1 ; J++ ) 
						if ( V[J] > V[J+1] ) {
								AUX = V[J] ;
								V[J] = V[J+1] ;
								V[J+1] = AUX ;						
						}
}



int BUSBIN ( int V[] , int N , int X )
{
		int MAYOR , MENOR , MEDIO ;
		
		MENOR = 0 ;
		MAYOR = N-1 ;
		
		while ( MAYOR >= MENOR ) {
				MEDIO = ( MAYOR + MENOR ) / 2 ;
				if ( V[MEDIO] == X )
						return MEDIO ;
				/*  TODAVIA NO LO ENCONTRE   */
				if ( X < V[MEDIO] )
						MAYOR = MEDIO - 1 ;
				else
						MENOR = MEDIO + 1 ;
		}
		return -1 ;
}
