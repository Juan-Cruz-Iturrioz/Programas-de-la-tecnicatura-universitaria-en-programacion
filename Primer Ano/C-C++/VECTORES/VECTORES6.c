/*  VECTORES  */
/*  PASAJE DE VECTORES A FUNCION   */


#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define NUM 10

void CARGAR ( int [] , int );
void MIRAR ( int [] , int );

int main()
{
		int VEC[NUM] ;
				
		CARGAR ( VEC , NUM );
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
		printf("\n\n\n\n\t\tIMPRESION DEL VECTOR\n\n\t");		
		for ( I = 0 ; I < N ; I++ ) 
				printf("%5d" , V[I] );
}
