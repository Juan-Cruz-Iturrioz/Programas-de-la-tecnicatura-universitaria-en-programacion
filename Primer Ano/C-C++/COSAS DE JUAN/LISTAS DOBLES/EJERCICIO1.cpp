/*   LISTAS SIMPLEMENTE ENLAZADAS   */

/*   DETERMINAR EL GANADOR DE LA VOTACION Y SU CANTIDAD DE VOTOS   */

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
			void INSERT(NODO *) ;
			void SACAR(NODO *);
	public :
			LISTA() ;
			~LISTA() ;
			void AGREGAR_F ( char * );
			void MIRAR() ;
			void GANADOR () ;
			void ORDENAR();
};


LISTA::LISTA()
{
		INICIO = NULL ;
}

LISTA::~LISTA()
{
		
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

void LISTA::ORDENAR()
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

void LISTA::GANADOR() {

int CAN = 0, MAX = 0;
char BUS[20] ;
NODO * P , * AUX ;
	P = INICIO ;
	AUX = P;

		while ( P ) {
			
				if ( !( strcmp(P->NOM , AUX->NOM))   ) 
					CAN++;
												
				else{
				
					if (CAN > MAX){
						
						MAX = CAN;
						strcpy (BUS,P->NOM );
					}
			
				CAN = 0 ;
			
				}
			
			AUX = P;
			P = P->SIG ;
}

printf("\n\n\t EL GANADOR ES %s CON %d" , BUS ,MAX )  ;

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
		
	
		L.ORDENAR() ;
		L.MIRAR();
	
		L.GANADOR() ;
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
	static int NUM = 500 + rand()%250;
	
	if ( I++ < NUM )
			return NOM[rand()%20] ;
	return NOM[20] ;
}




