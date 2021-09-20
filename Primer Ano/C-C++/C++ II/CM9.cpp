/*   OBJETOS DINAMICOS        NUEVOS OPERADORES NEW y DELETE   */

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


int main( )
{  
		ALFA * P ;
		
		P = new ALFA ;
		
		P->FUNCION() ;
		
		delete P ;
		
				
		printf("\n\n fin del programa");
		return 0 ;
}


