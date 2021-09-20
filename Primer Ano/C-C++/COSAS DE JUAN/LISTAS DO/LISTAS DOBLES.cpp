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
			NODO * ANT ;	
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
			NODO * FINAL ;
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
			void AGREGAR_F ( char * );
			void INSERTAR ( char * );
			void MIRAR() ;
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
		FINAL = NULL ;
}

LISTA::~LISTA()
{		
		NODO * P , *AUX;
		P = INICIO ;
		AUX = P;
		cout << "\n\n   MATANDO A ... TODOS LOS NODOS" ;
		while ( P ){
		AUX = P;
		P = P->SIG;
		delete AUX;
		
		}
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
		
		PN->SIG = NULL ;
		
		if ( ! INICIO && !FINAL) {
				/*  LISTA VACIA  */
	
				PN->ANT = NULL ;
				INICIO = PN ;
						
		}	
		
		else {	
		/*   LISTA NO VACIA   */	
		PN->ANT = FINAL ;
		FINAL->SIG = PN ;
		}
		
		
		FINAL = PN;
		
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
		
		if ( ! INICIO && !FINAL ) {
				/*  LISTA VACIA  */
				PN->SIG = NULL ;
				PN->ANT = NULL ; 							/* 1 */
				INICIO = PN ; 	
				FINAL = PN ;					/* 2 */
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
								PN->ANT = ANT ;				/* 5 */
								P->ANT = PN;
								ANT->SIG = PN ;
								PN->SIG = P;				/* 6 */
								return ;
						}						
						/*   PRIMER NODO   */
						PN->ANT = NULL ;
						PN->SIG = INICIO ;					/* 7 */
						INICIO->ANT = PN ;
						INICIO = PN ;						/* 8 */
						return ;
				} /*  ELSE  */
		} /* WHILE */
		/*   NUEVO  ULTIMO  NODO   */
		PONER_F(PN) ; 									/* 4 */
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





void LISTA::RARIM()
{
		cout << "\n\n\n\t CONTENIDO INVERSO DE LA LISTA\n";
		NODO * P ;
		P = FINAL ;
		
		while ( P ) {
				cout << "\n\n\t " << P->NOM ;
				P = P->ANT ;
		}
		getchar();
}

void LISTA::ELIMINAR(char * S)
{
		NODO * P ;
		P = BUSCAR(S) ;
	
		if ( P )
				MATAR(P) ;	
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

void LISTA::MATAR ( NODO * PELIM )
{
		
		if ( ! INICIO || ! PELIM ) 
				return ;
		
		if ( PELIM == INICIO && INICIO!= FINAL) {
				/*  ELIMINAR PRIMER NODO  */
				INICIO = PELIM->SIG ;
				delete PELIM ;
				return ;
		}
		
		if ( PELIM == FINAL && INICIO!= FINAL) {
				/*  ELIMINAR FINAL NODO  */
				
				FINAL = PELIM->ANT ;
			 	FINAL->SIG = NULL ;
				delete PELIM ;
				return ;
		}
		
		if ( PELIM == INICIO && PELIM == FINAL) {
				/*  ELIMINAR UNICO NODO  */
				FINAL = NULL;
				INICIO = NULL;
				delete PELIM ;
				return ;
		}
		
		/*   ELIMINAR NODO INTERMEDIO  */
		PELIM->SIG->ANT = PELIM->ANT;
		PELIM->ANT->SIG = PELIM->SIG;
		delete PELIM ;
		
		
}


void LISTA::SACAR ( NODO * PELIM )
{
		
		if ( ! INICIO || ! PELIM ) 
				return ;
		
		if ( PELIM == INICIO && INICIO!= FINAL) {
				/*  ELIMINAR PRIMER NODO  */
				INICIO = PELIM->SIG ;
				
				return ;
		}
		
		if ( PELIM == FINAL && INICIO!= FINAL) {
				/*  ELIMINAR FINAL NODO  */
				
				FINAL = PELIM->ANT ;
			 	FINAL->SIG = NULL ;
				;
				return ;
		}
		
		if ( PELIM == INICIO && PELIM == FINAL) {
				/*  ELIMINAR UNICO NODO  */
				FINAL = NULL;
				INICIO = NULL;
				
				return ;
		}
		
		/*   ELIMINAR NODO INTERMEDIO  */
		PELIM->SIG->ANT = PELIM->ANT;
		PELIM->ANT->SIG = PELIM->SIG;
		
		
		
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

int main( )
{  
		LISTA L ;		
		char BUF[20];
		
		cout << "\n\n    NOMBRE  :  " ;
		cin >> BUF ;
		while ( strcmp(BUF,"FIN") ) {
				L.AGREGAR_F(BUF);
			
				cout << "\n\n    NOMBRE  :  " ;
				cin >> BUF ;
		}
		
		L.MIRAR();
		L.ORDENAR1();
		L.MIRAR();
		printf("\n\n");
		return 0 ;
}



