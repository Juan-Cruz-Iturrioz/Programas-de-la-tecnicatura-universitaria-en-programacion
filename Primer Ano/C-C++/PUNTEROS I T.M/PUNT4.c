/*   VECTORES Y PUNTEROS   */

#include <stdio.h>
#include <stdlib.h>

#define N 8

int main( )
{  
		int VEC[N] , I , * P , * PMIN ;
		
		/*  CARGAR EL VECTOR   */
		for ( P = VEC ; P < VEC+N ; P++ ) {
				printf("\n\n   VALOR  =  ");
				scanf("%d" , P);
		}
		
		/*   IMPRESION 1 DEL VECTOR  */
		printf("\n\n\t\t");
		for ( P = VEC ; P < VEC+N ; P++ ) 
				printf("%5d" , *P);
		
		/*   IMPRESION 2 DEL VECTOR  */
		printf("\n\n\t\t");
		for ( P = VEC , I = 0 ; I < N ; I++ ) 
				printf("%5d" , *(P+I) );
		
		getchar(); getchar() ;
		
		/*   BUSQUEDA DEL MINIMO  */
		for ( PMIN = P = VEC ; P < VEC+N ; P++ ) 
				if ( *P < *PMIN )
						PMIN = P ;
						
		printf("\n\n  EL VALOR MINIMO ES %d" , *PMIN );
		printf("\n\n  Y ESTA EN LA POSICION %d" , PMIN-VEC );
				
		printf("\n\n");	
		return 0 ;
}
		
		

