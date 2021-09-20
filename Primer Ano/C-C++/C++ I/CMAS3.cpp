/*   CLASES Y OBJETOS   */
/*   MANEJO DE UNA PILA     OJO !   NO ESTA INICIALIZADO SP    */

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
			void PUSH ( int );
			int PULL() ;	
};

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
		int VALOR ;		
		
		for ( int I = 0 ; I < N+3 ; I++ ) {
				cout << "\n\n\n VALOR  :  " ;
				cin >> VALOR ;   
				P.PUSH(VALOR);
		}
		
		cout << "\n\n\n  CONTENIDO DE LA PILA \n\n" ;
		for ( int I = 0 ; I < N+3 ; I++ ) 
				cout << "\n\n\t\t " << P.PULL();
				
		printf("\n\n");
		return 0 ;
}



