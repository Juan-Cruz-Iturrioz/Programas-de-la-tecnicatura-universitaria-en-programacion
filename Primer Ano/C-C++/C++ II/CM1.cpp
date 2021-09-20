/*   SOBRECARGA Y POLIMORFISMO   */
/*   SOBRECARGA DE FUNCIONES       */

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


int CUAD(int);
float CUAD(float);
COMPLEJO CUAD(COMPLEJO);



int main( )
{  
		int A , B ;
		A = 25 ;
		B = CUAD(A) ;
		cout << "\n\n EL CUADRADO DE " << A << " ES " << B ; 
		getchar();
		
		float F , G ;
		F = 7.3225 ;
		G = CUAD(F) ;
		cout << "\n\n EL CUADRADO DE " << F << " ES " << G ; 
		getchar();
		
		
		COMPLEJO X , Y ;
		X.RE = 5 ;
		X.IM = -2 ;
		Y = CUAD(X) ;
		cout << "\n\n EL CUADRADO DE  " ;
		X.VER(); 
		cout << "  ES  " ;
		Y.VER();
		getchar();
	
				
		printf("\n\n fin del programa");
		return 0 ;
}


int CUAD(int X)
{
		return X * X ;
}


float CUAD(float X)
{
		return X * X ;
}


COMPLEJO CUAD(COMPLEJO X)
{
		COMPLEJO W ;
		W.RE = X.RE * X.RE - X.IM * X.IM ;
		W.IM = 2 * X.RE * X.IM ;
		return W ;
}


