/*   LISTAS SIMPLEMENTE ENLAZADAS   */

/*   DEPURAR LA LISTA PARA QUE HAYA UN NOMBRE DE CADA UNO   */

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>

using namespace std ;

class NODO {
	public :
			NODO(char *) ;
			~NODO() ;
			char NOM[20] ;
			NODO * SIG ;	
};


NODO::NODO(char * S)
{
		strcpy ( NOM , S );
}

NODO::~NODO()
{
		cout << "\n\n   MATANDO A ... " << NOM ;
		getchar();
}



class LISTA {
	private :
			NODO * INICIO ;
			void PONER_F(NODO *) ;
	public :
			LISTA() ;
			~LISTA() ;
			void AGREGAR_F ( char * );
			void MIRAR() ;
};


LISTA::LISTA()
{
		INICIO = NULL ;
}

LISTA::~LISTA()
{
		cout << "\n\n   MATANDO A ... TODOS LOS NODOS" ;
		cout << "\n\n   ESTA ES PARA USTEDES" ;
		getchar();
}



void LISTA::AGREGAR_F( char * S )
{
		NODO * P ;
		P = new NODO(S) ;  
		
		PONER_F(P) ;	
}

void LISTA::PONER_F( NODO * PN) 
{
		NODO * P ;
		P = INICIO ;
		
		PN->SIG = NULL ;
		
		if ( ! INICIO ) {
				/*  LISTA VACIA  */
				INICIO = PN ;
				return ;			
		}
		/*   LISTA NO VACIA   */
		while ( P->SIG )
				P = P->SIG ; 		/*  LLEVO P HASTA EL ULTIMO NODO  */		
		P->SIG = PN ;
}




void LISTA::MIRAR()
{
		NODO * P ;
		P = INICIO ;
		
		cout << "\n\n\n\t CONTENIDO DE LA LISTA\n";
		while ( P ) {
				cout << "\n\n\t " << P->NOM ;
				P = P->SIG ;
		}
		getchar();
}




char * GENERANOM();

int main( )
{  
		LISTA L ;		
		char BUF[20];
		
		strcpy ( BUF , GENERANOM());
		while ( strcmp(BUF,"FIN") ) {
				L.AGREGAR_F(BUF) ;
			
				strcpy ( BUF , GENERANOM());
		}
		
		L.MIRAR() ;
		
		printf("\n\n");
		return 0 ;
}


char * GENERANOM()
{
	static int I = 0 ;
	static char NOM[][20] = {"DARIO","CAROLINA","PEPE","LOLA",
						     "PACO","LUIS","MARIA","ANSELMO",
						  	 "ANA","LAURA","PEDRO","ANIBAL",
						     "PABLO","ROMUALDO","ALICIA","MARTA",
						     "MARTIN","TOBIAS","SAUL","LORENA","FIN"};
	static int NUM = 30 + rand()%15 ;
	
	if ( I++ < NUM )
			return NOM[rand()%20] ;
	return NOM[20] ;
}




