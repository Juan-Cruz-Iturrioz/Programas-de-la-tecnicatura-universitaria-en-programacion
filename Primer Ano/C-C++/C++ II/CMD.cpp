/*   MIEMBROS ESTATICOS DE UNA CLASE   */

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std ;

class ALFA {
	private :
			static int NUM ;
			int ID ;
	public :
			ALFA() ;       							/*  CONSTRUCTOR  */
			~ALFA() ; 								/*  DESTRUCTOR   */
			void SALUDA () ;	
};

int ALFA::NUM ;

ALFA::ALFA()
{
		ID = ++NUM ;
		cout << "\n\n   NACE No. ... " << ID ;
		getchar();
}

ALFA::~ALFA()
{
		cout << "\n\n   MUERE No. ... " << ID ;
		getchar();
}

void ALFA::SALUDA()
{
		cout << "\n\n   HOLA, YO SOY No. ... " << ID ;
		getchar();
}

void FUNCION();

int main( )
{  
		cout << "\n\n    INSTANCIA DE OBJETO LOCAL  " ;
		ALFA X ;
		
		cout << "\n\n    INSTANCIA DE VECTOR LOCAL DE 4 OBJETOS  " ;
		ALFA VEC[4] ;
		
		int NUM , I ;
		cout << "\n\n    INSTANCIA DE VECTOR DINAMICO DE OBJETOS " ;
		ALFA * P ;
		
		cout << "\n\n    CANTIDAD DE OBJETOS  :   " ;
		cin >> NUM ;  
		
		P = new ALFA[NUM] ;
		
		cout << "\n\n    SALUDA EL VECTOR DINAMICO  " ;
		for ( I = 0 ; I < NUM ; I++ )
			(P+I)->SALUDA() ;
		
		cout << "\n\n    VAMOS A LA FUNCION  " ;
		getchar();
		
		FUNCION();
		
		cout << "\n\n    DE NUEVO EN EL MAIN  " ;
		getchar();
		
		cout << "\n\n    MUERE EL VECTOR DINAMICO  " ;
		delete[] P;
		
			
		cout << "\n\n    SALUDA EL OBJETO LOCAL  " ;
		getchar();
		
		X.SALUDA();
				
		cout << "\n\n    SALUDA EL VECTOR LOCAL  " ;
		getchar();	
		
		for ( I = 0 ; I < 4 ; I++ )
			(VEC+I)->SALUDA() ;	
				
		printf("\n\n fin del programa");
		return 0 ;
}

void FUNCION()
{
		cout << "\n\n    DENTRO DE LA FUNCION  " ;
		getchar();
	
		ALFA W ;
		
		W.SALUDA();
		
		cout << "\n\n    POR SALIR DE LA FUNCION  " ;
		getchar();
}
