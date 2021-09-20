/*  VECTORES  */
/*  DETERMINACION DEL VALOR MINIMO   */


#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define NUM 20

void CARGAR ( int [] , int );
void MIRAR ( int [] , int );
int MINIMO ( int [] , int );

int main()
{
		int VEC[NUM] ;
		srand(655);
				
		CARGAR ( VEC , NUM );
		MIRAR ( VEC , NUM );
		
		printf("\n\n   EL VALOR MINIMO ES %d" , MINIMO(VEC,NUM) );
				
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


int MINIMO ( int V[] , int N )
{
		int I , MIN ;
		
		MIN = V[0] ;		
		for ( I = 1 ; I < N ; I++ ) 
				if ( V[I] < MIN )
						MIN = V[I] ;
		return MIN ;
}
