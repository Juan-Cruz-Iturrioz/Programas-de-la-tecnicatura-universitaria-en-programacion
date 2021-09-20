/*   OPERADOR &   */

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std ;

int main( )
{  
		int A ;
		int & B = A ;
		
		printf("\n\n   A = %d       B = %d" , A , B );
		
		A = 654 ;
		printf("\n\n   A = %d       B = %d" , A , B );


		B = 65487 ;
		printf("\n\n   A = %d       B = %d" , A , B );


		printf("\n\n   &A = %p       &B = %p" , &A , &B );
	
		printf("\n\n fin del programa");
		return 0 ;
}


