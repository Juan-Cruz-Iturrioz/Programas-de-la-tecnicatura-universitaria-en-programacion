/*  VECTORES  */
/*  DETERMINACION DE LA POSICION DEL MINIMO   */


#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define NUM 20

void CARGAR ( int [] , int );
void MIRAR ( int [] , int );
int POSMINIMO ( int [] , int );

int main()
{
		int VEC[NUM] , POS ;
		srand(65);
				
		CARGAR ( VEC , NUM );
		MIRAR ( VEC , NUM );
		
		POS=POSMINIMO(VEC,NUM);
		printf("\n\n   EL VALOR MINIMO ES %d" , VEC[POS] );
		printf("\n\n   Y ESTA EN LA POSICION %d" , POS );	
			
				
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


int POSMINIMO ( int V[] , int N )
{
		int I , PM ;
		
		PM = 0 ;		
		for ( I = 1 ; I < N ; I++ ) 
				if ( V[I] < V[PM] ) 
						PM = I ;
		return PM ;
}
