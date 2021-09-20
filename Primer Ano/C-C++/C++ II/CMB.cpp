/*   VECTORES DINAMICOS        NUEVOS OPERADORES NEW y DELETE   */

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
		int NUM , I ;
		ALFA * P ;
		
		cout << "\n\n    CANTIDAD DE OBJETOS  :   " ;
		cin >> NUM ;  
		
		P = new ALFA[NUM] ;
		
		for ( I = 0 ; I < NUM ; I++ )
			(P+I)->FUNCION() ;
		
		delete[] P;
		
				
		printf("\n\n fin del programa");
		return 0 ;
}


