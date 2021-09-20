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
		int A , B , C ;
		A = 25 ;
		B = 12 ;
		C = A + B ;
		cout << "\n\n " << A << "  +  " << B << "  =  " << C ; 
		getchar();
		
		float F , G , H ;
		F = 2.3565 ;
		G = 12.8521 ;
		H = F + G ;
		cout << "\n\n " << F << "  +  " << G << "  =  " << H ; 
		getchar();
		
		
		COMPLEJO X , Y , Z ;
		X.RE = 5 ;
		X.IM = -2 ;
		Y.RE = 16 ;
		Y.IM = 8 ;
		Z = X + Y ;
		cout << "\n\n  " ;
		X.VER(); 
		cout << "   +   " ;
		Y.VER();
		cout << "   =   " ;
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




