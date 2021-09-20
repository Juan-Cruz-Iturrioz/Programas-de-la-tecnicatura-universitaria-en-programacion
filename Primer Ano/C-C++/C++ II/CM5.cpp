/*   CONSTRUCTORES PARAMETRIZADOS CON DEFAULT   */


#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std ;

class ALFA {
	private :
			float A ;
	public :
			ALFA(int = 888) ;   
			void VER () ;	
};


ALFA::ALFA(int W)
{
		A = W ;
}


void ALFA::VER()
{
		cout << "\n\n    A  =   " << A ;
		getchar();
}





int main( )
{  
		int VALOR ;
		cout << "\n\n   VALOR  =  ";
		cin >> VALOR ;
		ALFA Y(VALOR) ;
		Y.VER();


        cout << "\n\n\n\n\n   USUARIO INDECISO  ";		
		ALFA X ;
		X.VER() ;
		
		
	
				
		printf("\n\n fin del programa");
		return 0 ;
}


