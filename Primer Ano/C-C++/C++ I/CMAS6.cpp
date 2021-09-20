/*   CLASES Y OBJETOS   */
/*   DE CONSTRUCTORES Y DESTRUCTORES       */

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std ;

class ALFA {
	public :
			ALFA() ;       							/*  CONSTRUCTOR  */
			~ALFA() ; 								/*  DESTRUCTOR   */
			void FUNCION () ;	
};

ALFA::ALFA()
{
		cout << "\n\n   BRAHMA ES EL CONSTRUCTOR ... " ;
		getchar();
}

ALFA::~ALFA()
{
		cout << "\n\n   SHIVA ES EL DESTRUCTOR ... " ;
		getchar();
}

void ALFA::FUNCION()
{
		cout << "\n\n   VISHNU ES EL PROTECTOR ... " ;
		getchar();
}

void FUNCION();

int main( )
{  
		ALFA X ;
		ALFA VEC[4] ;
	
		X.FUNCION() ;		
		
		FUNCION();
		cout << "\n\n DE NUEVO EN EL MAIN"; getchar();
		
		for ( int I = 0 ; I < 4 ; I++)
			(*(VEC+I)).FUNCION() ;
				
		printf("\n\n fin del programa");
		return 0 ;
}


void FUNCION()
{
		cout << "\n\n DENTRO DE LA FUNCION";getchar();
		
		ALFA Y ;
		Y.FUNCION();
	
		cout << "\n\n POR SALIR DE LA FUNCION";getchar();
}
