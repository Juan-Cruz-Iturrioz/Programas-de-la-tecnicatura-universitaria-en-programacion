/*   ARCHIVO CABECERA PARA COMPLEJOS   */

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
COMPLEJO operator + ( COMPLEJO X , COMPLEJO Y )
{
		COMPLEJO W ;
		W.RE = X.RE + Y.RE ;
		W.IM = X.IM + Y.IM ;
		return W ;
}




