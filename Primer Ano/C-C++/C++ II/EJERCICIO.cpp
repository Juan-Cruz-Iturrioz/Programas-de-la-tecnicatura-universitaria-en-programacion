/*   SOBRECARGA Y POLIMORFISMO   */
/*   SOBRECARGA DE OPERADORES       */

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std ;

class COMPLEJO {
	public :
			int RE ;
			int IM ;       
			void VER () ;	
};

void COMPLEJO::VER()
{
		cout << RE ;
		if ( IM < 0 )
				cout << " - " << -IM << "i" ;
		else
				cout << " + " << IM << "i" ;
}

COMPLEJO CUAD(COMPLEJO);
COMPLEJO CUAD(COMPLEJO X)
{
		COMPLEJO W ;
		W.RE = X.RE * X.RE - X.IM * X.IM ;
		W.IM = 2 * X.RE * X.IM ;
		return W ;
}

COMPLEJO operator + ( COMPLEJO , COMPLEJO );


int main( )
{  
		COMPLEJO X , Y , Z ;
		X.RE = 5 ;
		X.IM = -2 ;
		Y.RE = 16 ;
		Y.IM = 8 ;
		
		Z = 5 + X + Y + 7 ;
		
		cout << "\n\n   RESULTADO   =    " ;
		Z.VER();
		getchar();
	
				
		printf("\n\n fin del programa");
		return 0 ;
}


COMPLEJO operator + ( COMPLEJO X , COMPLEJO Y )
{
		COMPLEJO W ;
		W.RE = X.RE + Y.RE ;
		W.IM = X.IM + Y.IM ;
		return W ;
}




