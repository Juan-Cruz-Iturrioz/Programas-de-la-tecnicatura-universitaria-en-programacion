/*   PUNTEROS A ESTRUCTURA  */

#include <stdio.h>
#include <stdlib.h>

struct ALFA {
		int A ;
		float F ;
};

int main( )
{  
		struct ALFA * P , X ;
		
		P = &X ;
		
		P->A = 654 ;
		P->F = 32.6598 ;
		
		printf("\n\n  X.A = %d     X.F = %f" , X.A , X.F);
		printf("\n\n  P->A = %d     P->F = %f" , P->A , P->F);
		
		P->A = 2 * P->A ;
		P->F = 2 * P->F ;
		
		printf("\n\n\n\n\n  X.A = %d     X.F = %f" , X.A , X.F);
		printf("\n\n  P->A = %d     P->F = %f" , P->A , P->F);
					
		printf("\n\n");	
		return 0 ;
}
		
		

