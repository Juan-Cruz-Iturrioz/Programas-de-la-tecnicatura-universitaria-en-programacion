/*   MIEMBROS ESTATICOS DE UNA CLASE   */

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std ;

class ALFA {
	public :
			int A ;
			static int B ;			
};

int ALFA::B ;

int main( )
{  
		ALFA X , Y ;
		
		printf("\n\n\n\n\n  X.A = %d       X.B = %d" , X.A , X.B );
		printf("\n\n\n  Y.A = %d       Y.B = %d" , Y.A , Y.B );
		getchar();
		
		X.A = 321 ;      X.B = 654 ;
		
		printf("\n\n\n\n\n  X.A = %d       X.B = %d" , X.A , X.B );
		printf("\n\n\n  Y.A = %d       Y.B = %d" , Y.A , Y.B );
		getchar();
			
		Y.A = 88888 ;    Y.B = 33333 ;
			
		printf("\n\n\n\n\n  X.A = %d       X.B = %d" , X.A , X.B );
		printf("\n\n\n  Y.A = %d       Y.B = %d" , Y.A , Y.B );	
		getchar();
			
		printf("\n\n fin del programa");
		return 0 ;
}


