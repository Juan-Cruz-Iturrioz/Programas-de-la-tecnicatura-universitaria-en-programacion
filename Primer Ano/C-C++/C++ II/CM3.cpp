/*   SOBRECARGA Y POLIMORFISMO   */
/*   SOBRECARGA DE OPERADORES       */

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "complejo.h"

using namespace std ;

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




