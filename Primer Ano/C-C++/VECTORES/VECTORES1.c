/*  VECTORES  */


#include <stdio.h>
#include <conio.h>

#define N 10

int main()
{
		int VEC[N] , I ;
		
		printf("\n\n   TAMAÑO DEL VECTOR  = %d BYTES\n\n" , sizeof(VEC) );
				
		/*   CARGA DEL VECTOR   */		
		for ( I = 0 ; I < N ; I++ ) {
				printf("\n\t\t  VEC [ %d ]  =  " , I );
				scanf("%d" , &VEC[I] );
		}		
				
		/*   IMPRESION DEL VECTOR   */
		printf("\n\n\n\n\t\tIMPRESION DEL VECTOR\n\n\t");		
		for ( I = 0 ; I < N ; I++ ) 
				printf("%5d" , VEC[I] );
					
		/*   IMPRESION INVERSA DEL VECTOR   */
		printf("\n\n\n\n\t\tIMPRESION INVERSA 1 DEL VECTOR\n\n\t");		
		for ( I = N-1 ; I >= 0 ; I-- ) 
				printf("%5d" , VEC[I] );
				
		/*   IMPRESION INVERSA DEL VECTOR   */
		printf("\n\n\n\n\t\tIMPRESION INVERSA 2 DEL VECTOR\n\n\t");		
		for ( I = 0 ; I < N ; I++ ) 
				printf("%5d" , VEC[N-I-1] );
						
		printf("\n\n\nFIN DEL PROGRAMA\n\n\n\n" );
		return 0 ;	
}  
