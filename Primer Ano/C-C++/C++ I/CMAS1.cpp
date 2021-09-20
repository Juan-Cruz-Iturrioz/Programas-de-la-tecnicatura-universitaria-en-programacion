/*   CLASES Y OBJETOS   */

#include <stdio.h>
#include <stdlib.h>

class ALFA {
	private :
			int A ;
			void DOBLAR() {
					A = 2 * A ;
			};
	public :
			int B ;
			void CARGAR ( int );
			void MIRAR() ;	
};

void ALFA::CARGAR ( int X )
{
		A = X ;
		DOBLAR() ;
}

void ALFA::MIRAR ()
{
		printf("\n\n  A = %d       B = %d" , A , B );
		getchar();
}


int main( )
{  
		ALFA X ;
		
//		X.A= 25 ;    ERROR  :  ALFA::A ES PRIVADO
		
		X.B = 654 ;
		
//		X.DOBLAR() ;	ERROR  :  ALFA::DOBLAR() ES PRIVADO
		
		X.CARGAR(222) ;
		
		X.MIRAR();
		
		printf("\n\n");
		return 0 ;
}



