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
		//getchar();
}



class LISTA {
	private :
			NODO * INICIO ;
			void PONER_P(NODO *) ;
			void PONER_F(NODO *) ;
			void INSERT(NODO *) ;
			NODO* MIRAR_REE(NODO*);
			NODO*RARIM_REE(NODO*) ;
	public :
			LISTA() ;
			~LISTA() ;
			void AGREGAR_P ( char * );
			void AGREGAR_F ( char * );
			void INSERTAR ( char * );
			void MIRAR() ;
			void MIRARCP();
			void RARIM() ;
			void MIRAR_RE();
			void RARIM_RE() ;
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

		NODO * P = INICIO;
		int CAN = 0 , I ,J;
		cout << "\n\n\n\t CONTENIDO INVERSO DE LA LISTA\n";
		
		while(P){
		CAN++;
		P = P->SIG;
		}
		
		for(I = 1 ; I <= CAN ; I++){
		P = INICIO;
		
			for(J = I ; J < CAN ; J++)
			P = P->SIG;
		
	//	cout << "\n\n\t " << P->NOM ;
		printf("\n\n\t %s",P->NOM );
		}
		
		
		
}

void LISTA::MIRAR_RE(){

	if( INICIO ){
	cout << "\n\n\n\t CONTENIDO DE LA LISTA\n";
	MIRAR_REE(INICIO);
	}
	else
	cout << "\n\n\n\t CONTENIDO DE LA LISTA ES VACIA\n";
	
	


}

NODO* LISTA::MIRAR_REE(NODO* P){

if(P){

cout << "\n\n\t " << P->NOM ;
MIRAR_REE( P->SIG )  ;


}

}

void LISTA::RARIM_RE(){

	if( INICIO ){
	cout << "\n\n\n\t CONTENIDO DE LA LISTA\n";
	RARIM_REE(INICIO);
	}
	else
	cout << "\n\n\n\t CONTENIDO DE LA LISTA ES VACIA\n";
	
	


}

NODO* LISTA::RARIM_REE(NODO* P){

if(P){
	

RARIM_REE( P->SIG )  ;
cout << "\n\n\t " << P->NOM ;

}

}



int main( )
{  
		LISTA L ;		
		char BUF[20];
		
		cout << "\n\n    NOMBRE  :  " ;
		cin >> BUF ;
		while ( strcmp(BUF,"FIN") ) {
				L.INSERTAR(BUF) ;
			
				cout << "\n\n    NOMBRE  :  " ;
				cin >> BUF ;
		}
		
		L.RARIM_RE();
		
		printf("\n\n");
		return 0 ;
}



