/*  VECTORES  */
/*  VALORES MAYORES AL PROMEDIO   */


#include <stdio.h>
#include <conio.h>

#define N 10

int main()
{
		int VEC[N] , I , SUMA , CUENTA ;
		float PROM ;
		
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
					
		/*   CALCULO DEL PROMEDIO   */
		SUMA = 0 ;
		for ( I = 0 ; I < N ; I++ ) 
				SUMA = SUMA + VEC[I] ;
		PROM = (float)SUMA / N ;
		printf("\n\n   EL PROMEDIO ES %f" , PROM);				
						
		/*   VALORES QUE SUPERAN EL PROMEDIO   */
		CUENTA = 0 ;
		for ( I = 0 ; I < N ; I++ ) 
				if ( VEC[I] > PROM )
						CUENTA++ ;
		printf("\n\n   HAY %d VALORES QUE SUPERAN %f" , CUENTA , PROM);			
				
		printf("\n\n\nFIN DEL PROGRAMA\n\n\n\n" );
		return 0 ;	
}  
