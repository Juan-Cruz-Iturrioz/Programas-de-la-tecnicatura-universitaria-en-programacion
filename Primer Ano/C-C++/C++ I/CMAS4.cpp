/*   CLASES Y OBJETOS   */
/*   MANEJO DE UNA PILA    FUNCION PUBLICA DE INICIALIZACION   */
/*   HORROR !!!!   */

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std ;

#define N 6

class PILA {
	private :
			int VEC[N] ;
			int * SP ;
	public :
			void INI() ;
			void PUSH ( int );
			int PULL() ;	
};

void PILA::INI()
{
		SP = VEC ;
}



void PILA::PUSH ( int X )
{
		if ( SP == VEC+N ) {
				cout << "\n\n  PILA LLENA\n" ;
				getchar();
				return ;			
		}   
		*SP = X ;
		SP++ ;		
}

int PILA::PULL ( )
{
		if ( SP == VEC ) {
				cout << "\n\n  PILA VACIA\n" ;
				getchar();
				return 0 ;			
		}
		SP-- ;
		return *SP  ;		
}


int main( )
{  
		PILA P ;
		P.INI() ;
		int VALOR ;		
		
		for ( int I = 0 ; I < N+3 ; I++ ) {
				cout << "\n\n\n VALOR  :  " ;
				cin >> VALOR ;   
				P.PUSH(VALOR);
		}
		
		P.INI() ;		//  TERRORISMO PURO
		
		cout << "\n\n\n  CONTENIDO DE LA PILA \n\n" ;
		for ( int I = 0 ; I < N+3 ; I++ ) 
				cout << "\n\n\t\t " << P.PULL();
				
		printf("\n\n");
		return 0 ;
}



