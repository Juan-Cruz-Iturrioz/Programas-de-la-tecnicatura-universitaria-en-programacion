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
		
}



class LISTA {
	private :
			void INSERT(NODO *) ;
			NODO * INICIO ;
			void PONER_F(NODO *) ;
			void SACAR(NODO *);
			NODO * MAXIMO();
	public :
			LISTA() ;
			~LISTA() ;
			void AGREGAR_F ( char * );
			void MAYOR() ;
			void ORDENAR1();
			void MIRAR() ;
			void DEPURAR();
			
};


LISTA::LISTA()
{
		INICIO = NULL ;
}

LISTA::~LISTA()
{
		
		NODO * P , *AUX;
		P = INICIO ;
		
		cout << "\n\n   MATANDO A ... TODOS LOS NODOS" ;
		
		while ( P ){
			
			AUX = P;
			P = P->SIG;
			delete AUX;
		
		}
		
		getchar();
		
}



void LISTA::INSERT( NODO * PN) 
{
		NODO * P , * ANT ;
		P = INICIO ;
		ANT = NULL ;
		
		if ( ! INICIO ) {
				/*  LISTA VACIA  */
				PN->SIG = NULL ; 							/* 1 */
				INICIO = PN ; 								/* 2 */
				return ;			
		}
		/*   LISTA NO VACIA   */
		while ( P ) {
				if ( strcmp(P->NOM , PN->NOM) < 0 ) {
						/*  BARRIDO  */
						ANT = P ;
						P = P->SIG ;					
				}
				else {
						/*  EUREKA !!  */
						if ( ANT ) {
								/*  NODO INTERMEDIO  */
								PN->SIG = P ;				/* 5 */
								ANT->SIG = PN ;				/* 6 */
								return ;
						}						
						/*   PRIMER NODO   */
						PN->SIG = INICIO ;					/* 7 */
						INICIO = PN ;						/* 8 */
						return ;
				} /*  ELSE  */
		} /* WHILE */
		/*   NUEVO  ULTIMO  NODO   */
		PN->SIG = NULL ; 									/* 3 */
		ANT->SIG = PN ; 									/* 4 */
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

void LISTA::SACAR ( NODO * PELIM )
{
		NODO * P ;
		P = INICIO ;
		
		if ( ! INICIO || ! PELIM ) 
				return ;
		
		if ( PELIM == INICIO ) {
				/*  ELIMINAR PRIMER NODO  */
				INICIO = PELIM->SIG ;
				return ;
		}
		/*   ELIMINAR NODO INTERMEDIO  */
		while ( P->SIG != PELIM && P )
				P = P->SIG ;
		if ( P ) 
				P->SIG = P->SIG->SIG ;
}
void LISTA::MAYOR()
{
		if (! INICIO)
				return ;
	
		cout << "\n\n  EL MAYOR ES ... " << MAXIMO()->NOM ;
		getchar();
	
}

NODO * LISTA::MAXIMO()
{
		NODO * P , * PMAX ;
		PMAX = P = INICIO ;
		
		while ( P ) {
				if ( strcmp(P->NOM , PMAX->NOM) > 0 )
						PMAX = P ;			
				P = P->SIG ;
		}
		return PMAX ;
}

void LISTA::ORDENAR1()
{
		NODO * AUXINI , * P ;
		AUXINI = NULL ;
		
		while ( INICIO ) {
				P = MAXIMO() ;
				SACAR(P) ;
				P->SIG = AUXINI ;
				AUXINI = P ;			
		}
		INICIO = AUXINI ;
}

void LISTA::DEPURAR(){

ORDENAR1();
	NODO * P , * AUX ;
	LISTA AUXL ;
	
	P = INICIO ;
	AUX = P;
	while ( P ) {
		
				if ( ( strcmp(P->NOM , AUX->NOM))   ){
				
				SACAR(AUX) ;
				AUXL.INSERT(AUX);
		
				}
		
		AUX = P;
		P = P->SIG ;
					
		}
		
		SACAR(AUX) ;
		AUXL.INSERT(AUX);
		
		AUX = INICIO;
		
		INICIO = AUXL.INICIO ;
		AUXL.INICIO = AUX ;
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
		L.ORDENAR1();
		L.MIRAR() ;
		L.DEPURAR();
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




