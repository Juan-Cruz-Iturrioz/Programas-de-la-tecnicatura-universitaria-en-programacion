/*  VECTORES  */
/*  BUSQUEDA SECUENCIAL   */


#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define NUM 20

void CARGAR ( int [] , int );
void MIRAR ( int [] , int );
int BUSCAR1 ( int [] , int , int );
int BUSCAR2 ( int [] , int , int );

int main()
{
		int VEC[NUM] ;
		int X , POS ;
		srand(674);
				
		CARGAR ( VEC , NUM );
		MIRAR ( VEC , NUM );
		
		printf("\n\n   VALOR A BUSCAR  =  ");
		scanf("%d" , &X);
		
		POS = BUSCAR2 ( VEC , NUM , X );
		
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
				V[I] = rand()%100 ;
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


int BUSCAR1 ( int V[] , int N , int X )
{
		int I , PX ;
		
		PX = -1 ;
		for ( I = 0 ; I < N  ; I++ ) 
				if ( V[I] == X ) 
						PX = I ;
		return PX ;
}


int BUSCAR2 ( int V[] , int N , int X )
{
		int I ;
		
		for ( I = 0 ; I < N ; I++ ) 
				if ( V[I] == X ) 
						return I ;
		return -1 ;
}
