/*   PUNTEROS A PUNTEROS  */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main( )
{  
		int A ;
		int * P ;
		int ** PP ;
							
		A = 654 ;
		P = &A ;
		PP = &P ;		
		
		printf("\n\n\n    %10d  %10d  %10d" , A , *P , **PP );
		printf("\n\n\n    %10p  %10p  %10p" , &A , &P , &PP );
		printf("\n\n\n    %10p  %10p  %10p" , PP , P , *PP );					
						
		**PP = 32187 ;
						
		printf("\n\n\n\n\n    %10d  %10d  %10d" , A , *P , **PP );
														
		printf("\n\n");	
		return 0 ;
}
		

