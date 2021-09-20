/*   FUNCIONES AMIGAS   */

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std ;

class BETA ;

class ALFA {
	private :
			int A ;
	public :
			ALFA() ; 
			void VER();      							/*  CONSTRUCTOR  */
			friend void FUNCION( ALFA & , BETA & );
};


ALFA::ALFA()
{
		A = 321 ;
}

void ALFA::VER()
{
		cout << "\n\n VER A  =  " << A ;
		getchar();	
}


class BETA {
	private :
			float B ;
	public :
			BETA() ;    
			void VER() ;  							/*  CONSTRUCTOR  */
			friend void FUNCION( ALFA & , BETA & );
};


BETA::BETA()
{
		B = 7.5321 ;
}

void BETA::VER()
{
		cout << "\n\n VER B  =  " << B ;
		getchar();	
}

void FUNCION( ALFA & , BETA & );

int main( )
{  
		ALFA X ;
		BETA Y ;
		
		FUNCION(X,Y) ;
		
		X.VER();
		Y.VER();
				
		printf("\n\n fin del programa");
		return 0 ;
}

void FUNCION( ALFA & W , BETA & Z )
{
		cout << "\n\n  A  =  " << W.A ;
		cout << "\n\n  B  =  " << Z.B ;
		
		W.A = 2 * W.A ;
		Z.B = W.A * Z.B ;
	
		cout << "\n\n\n\n\n  A  =  " << W.A ;
		cout << "\n\n  B  =  " << Z.B ;
		
		getchar();		
}
