/*   ORDENAMIENTO VECTORES Y PUNTEROS   */

#include <stdio.h>
#include <stdlib.h>

#define N 12

int main( )
{  
		int VEC[N] , I , J , * P  ;
		int AUX ;
		
		srand(18);
		
		/*  CARGAR EL VECTOR   */
		for ( P = VEC ; P < VEC+N ; P++ ) 
				*P = rand()%100 ;
				
		/*   IMPRESION DEL VECTOR  */
		printf("\n\n\n\n\t");
		for ( P = VEC ; P < VEC+N ; P++ ) 
				printf("%5d" , *P);
		
		getchar(); 
		
		/*   ORDENAMIENTO   */
		for ( P = VEC , I = 0 ; I < N-1 ; I++ )
				for ( J = 0 ; J < N-I-1 ; J++ )
						if ( *(P+J) > *(P+J+1) ) {
								/*  SWAPPING  */
								AUX = *(P+J) ;
								*(P+J) = *(P+J+1) ;
								*(P+J+1) = AUX ;
						}
		
		/*   IMPRESION DEL VECTOR  */
		printf("\n\n\n\n\t");
		for ( P = VEC ; P < VEC+N ; P++ ) 
				printf("%5d" , *P);
				
		printf("\n\n");	
		return 0 ;
}
		
		

