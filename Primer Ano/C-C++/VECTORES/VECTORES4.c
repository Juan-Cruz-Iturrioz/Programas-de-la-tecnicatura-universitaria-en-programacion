/*  VECTORES  */
/*  COPIA DIRECTA DE VECTORES   */


#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define N 10

int main()
{
		int VEC1[N] , VEC2[N] , I ;
				
//		printf("\n\n   TAMAÑO DEL VECTOR  = %d BYTES\n\n" , sizeof(VEC) );
				
		/*   CARGA DEL VECTOR   */		
		for ( I = 0 ; I < N ; I++ ) 
				VEC1[I] = rand()%100 ;
				
				
		/*   IMPRESION DE LOS VECTORES   */
		printf("\n\n\n\n\t\tIMPRESION DEL VECTOR 1\n\n\t");		
		for ( I = 0 ; I < N ; I++ ) 
				printf("%5d" , VEC1[I] );
		printf("\n\n\n\n\t\tIMPRESION DEL VECTOR 2\n\n\t");		
		for ( I = 0 ; I < N ; I++ ) 
				printf("%5d" , VEC2[I] );			
				
//		VEC2 = VEC1 ;    ESTO NO SE PUEDE HACER		
				
		for ( I = 0 ; I < N ; I++ ) 
				VEC2[I] = VEC1[I] ;			
								
		/*   IMPRESION DE LOS VECTORES   */
		printf("\n\n\n\n\t\tIMPRESION DEL VECTOR 1\n\n\t");		
		for ( I = 0 ; I < N ; I++ ) 
				printf("%5d" , VEC1[I] );
		printf("\n\n\n\n\t\tIMPRESION DEL VECTOR 2\n\n\t");		
		for ( I = 0 ; I < N ; I++ ) 
				printf("%5d" , VEC2[I] );			
				
				
		printf("\n\n\nFIN DEL PROGRAMA\n\n\n\n" );
		return 0 ;	
}  
