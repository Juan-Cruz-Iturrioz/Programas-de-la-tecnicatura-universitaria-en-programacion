/*   PUNTEROS A ESTRUCTURA  */
/*   VECTOR DE PUNTEROS A ESTRUCTURAS  */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 7

int PONER ( int * , int ** , int );

int main( )
{  
		int VEC[N] , *SP , DATO , I ;
							
		SP = VEC ;					
		do {
				printf("\n\n   DATO  =  ");
				scanf("%d" , &DATO) ;
		} while ( PONER(VEC,&SP,DATO) ); 					
							
		printf("\n\n\n\n\t\t");
		for ( I = 0 ; I < N ; I++ )
			printf("%6d" , *(VEC + I) );					
														
		printf("\n\n");	
		return 0 ;
}
		
		
int PONER ( int * VEC , int * * PP , int DATO )
{
		//     PP   equivale a   &SP
		//     *PP  equivale a SP
	
		**PP = DATO ;
		(*PP)++ ;
		if ( *PP == VEC+N ) return 0 ;
		return 1 ;
} 		
		

