/*   SOBRECARGA Y POLIMORFISMO   */
/*   SOBRECARGA DE CONSTRUCTORES       */

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std ;

class ALFA {
	private :
			float A ;
	public :
			ALFA() ;   
			ALFA(int) ;   
			ALFA(int,float) ;   
			ALFA(float,int) ;  
			void VER () ;	
};

ALFA::ALFA()
{
		A = 654 ;
}

ALFA::ALFA(int W)
{
		A = W ;
}


ALFA::ALFA(int W , float F)
{
		A = W * F ;
}


ALFA::ALFA(float F , int W )
{
		A = W / F ;
}



void ALFA::VER()
{
		cout << "\n\n    A  =   " << A ;
		getchar();
}





int main( )
{  
		cout << "\n\n\n\n  SIN ARGUMENTOS";
		ALFA X ;
		X.VER() ;
		
		int VALOR ;
		cout << "\n\n\n\n  ARGUMENTOS : entero";
		cout << "\n\n   USUARIO PRETENCIOSO      VALOR  =  ";
		cin >> VALOR ;
		ALFA Y(VALOR) ;
		Y.VER();
		
				
		cout << "\n\n\n\n  ARGUMENTOS : entero , flotante = 7.5";
		ALFA W(VALOR,7.5) ;
		W.VER();
		
		cout << "\n\n\n\n  ARGUMENTOS : flotante = 7.5 , entero";
		ALFA Z(7.5,VALOR) ;
		Z.VER();
	
				
		printf("\n\n fin del programa");
		return 0 ;
}


