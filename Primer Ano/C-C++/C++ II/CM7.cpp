/*   OPERADOR &   */
/*   PASAJE POR REFERENCIA   */

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std ;

void FUNCION(int);
void FUNCION(int *);
void FUNC(int &);

int main( )
{  
		int VALOR ;
		
		VALOR = 33 ;
		printf("\n\n\n\n   PASAJE POR VALOR" );
		printf("\n\n   VALOR ANTES DE LA FUNCION    =  %d" , VALOR );
		FUNCION(VALOR) ;
		printf("\n\n   VALOR DESPUES DE LA FUNCION  =  %d" , VALOR );
		
		VALOR = 44 ;
		printf("\n\n\n\n   PASAJE POR DIRECCION" );
		printf("\n\n   VALOR ANTES DE LA FUNCION    =  %d" , VALOR );
		FUNCION(&VALOR) ;
		printf("\n\n   VALOR DESPUES DE LA FUNCION  =  %d" , VALOR );
	
		VALOR = 22 ;
		printf("\n\n\n\n   PASAJE POR REFERENCIA" );
		printf("\n\n   VALOR ANTES DE LA FUNCION    =  %d" , VALOR );
		FUNC(VALOR) ;
		printf("\n\n   VALOR DESPUES DE LA FUNCION  =  %d" , VALOR );
	
		printf("\n\n fin del programa");
		return 0 ;
}


void FUNCION(int X)
{
		X = 2 * X ;
}


void FUNCION(int *P)
{
		*P = 2 *(*P) ;   					//    2 ** P   ESTA OK
}


void FUNC(int &X)
{
		X = 2 * X ;
}



