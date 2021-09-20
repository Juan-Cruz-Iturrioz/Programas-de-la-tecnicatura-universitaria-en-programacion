/*   LISTAS SIMPLEMENTE ENLAZADAS   */

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
			void PONER_P(NODO *) ;
			void PONER_F(NODO *) ;
			void INSERT(NODO *) ;
			NODO * MINIMO();
			NODO * MAXIMO();
			NODO * BUSCAR(char *) ;
			void MATAR(NODO *);
			void SACAR(NODO *);
	public :
			LISTA() ;
			~LISTA() ;
			void AGREGAR_P ( char * );
			void AGREGAR_F ( char * );
			void INSERTAR ( char * );
			void MIRAR() ;
			void MIRARCP();
			void RARIM() ;
			void MENOR() ;
			void MAYOR() ;
			void ELIMINAR(char *);
			void ORDENAR1();
			void ORDENAR2();
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


void LISTA::AGREGAR_P( char * S )
{
		NODO * P ;
		P = new NODO(S) ;  
		
		PONER_P(P) ;	
}

void LISTA::PONER_P( NODO * PN) 
{
		PN->SIG = INICIO ;
		INICIO = PN ;	
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


void LISTA::INSERTAR( char * S )
{
		NODO * P ;
		P = new NODO(S) ;  
		
		INSERT(P) ;	
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


void LISTA::MIRARCP()
{
		NODO * P ;
		P = INICIO ;
		
		cout << "\n\n\n\t CONTENIDO DE LA LISTA\n";
		while ( P ) {
				printf("\n\n\t %10p \t %-15s %10p" , P , P->NOM , P->SIG );
				P = P->SIG ;
		}
		getchar();
}



void LISTA::RARIM()
{
		cout << "\n\n\n\t CONTENIDO INVERSO DE LA LISTA\n";
		cout << "\n\n\n\t OTRA QUE ES PARA USTEDES ... JE JE \n";
		getchar();
} 


void LISTA::MENOR()
{
		if (! INICIO)
				return ;
	
		cout << "\n\n  EL MENOR ES ... " << MINIMO()->NOM ;
		getchar();
	
}

NODO * LISTA::MINIMO()
{
		NODO * P , * PMIN ;
		PMIN = P = INICIO ;
		
		while ( P ) {
				if ( strcmp(P->NOM , PMIN->NOM) < 0 )
						PMIN = P ;			
				P = P->SIG ;
		}
		return PMIN ;
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


NODO * LISTA::BUSCAR(char * S)
{
		NODO * P  ;
		P = INICIO ;
		
		while ( P ) {
				if ( ! strcmp(P->NOM , S) )
						return P ;			
				P = P->SIG ;
		}
		return NULL ;
}

void LISTA::ELIMINAR(char * S)
{
		NODO * P ;
		P = BUSCAR(S) ;
	
		if ( P )
				MATAR(P) ;	
}

void LISTA::MATAR ( NODO * PELIM )
{
		NODO * P ;
		P = INICIO ;
		
		if ( ! INICIO || ! PELIM ) 
				return ;
		
		if ( PELIM == INICIO ) {
				/*  ELIMINAR PRIMER NODO  */
				INICIO = PELIM->SIG ;
				delete PELIM ;
				return ;
		}
		/*   ELIMINAR NODO INTERMEDIO  */
		while ( P->SIG != PELIM && P )
				P = P->SIG ;
		if ( P ) {
				//       P->SIG = PELIM->SIG ;
				P->SIG = P->SIG->SIG ;
				delete PELIM ;			
		}
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


void LISTA::ORDENAR2()
{
		NODO * P ;
		LISTA AUXL ;	
	
		while ( INICIO ) {
				P = INICIO ;
				SACAR(P) ;
				AUXL.INSERT(P) ;			
		}
		INICIO = AUXL.INICIO ;
		AUXL.INICIO = NULL ;
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
		
//		L.MENOR();
//		L.MAYOR();

//		cout << "\n\n   NOMBRE A ELIMINAR  :  ";
//		cin >> BUF ;
		
//		L.ELIMINAR(BUF) ;

		L.ORDENAR2();

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
	return NOM[I++] ;
	
}



/*		
		*/
//		return "pepe";	


