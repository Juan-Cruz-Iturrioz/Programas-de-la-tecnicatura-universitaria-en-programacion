/*  VECTORES  */
/*  PASAJE DE VECTORES A FUNCION   */


#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define N 10

void FUNCION ( int , int [] );

int main()
{
		int VEC[N] , A , I ;
				
		printf("\n\n   TAMAÑO DEL VECTOR  = %d BYTES\n\n" , sizeof(VEC) );
				
		/*   CARGA DEL VECTOR   */		
		A = 25 ;
		for ( I = 0 ; I < N ; I++ ) 
				VEC[I] = rand()%100 ;
				
				
		/*   IMPRESION DE LOS VECTORES   */
		printf("\n\n\n\n\t\tIMPRESION DEL VECTOR Y A\n\n\t");		
		printf("%02d\t" , A);
		for ( I = 0 ; I < N ; I++ ) 
				printf("%5d" , VEC[I] );
					
		FUNCION ( A , VEC );	
					
		/*   IMPRESION DE LOS VECTORES   */
		printf("\n\n\n\n\t\tIMPRESION DEL VECTOR Y A\n\n\t");		
		printf("%02d\t" , A);
		for ( I = 0 ; I < N ; I++ ) 
				printf("%5d" , VEC[I] );
							
		printf("\n\n\nFIN DEL PROGRAMA\n\n\n\n" );
		return 0 ;	
}  

void FUNCION ( int A , int V[] )     
{
		int I ;
		printf("\n\n\n\n\n\n   TAMAÑO DEL PUNTERO V  = %d BYTES\n\n" , sizeof(V) );
		A = 2 * A ;
		for ( I = 0 ; I < N ; I++ ) 
				V[I] = 2 * V[I] ;
}
