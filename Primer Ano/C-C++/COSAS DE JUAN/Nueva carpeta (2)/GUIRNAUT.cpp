/*   GUIRNALDA   */

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>

using namespace std ;

#define borrartodo() system("cls")

class ALUMNO {
	public :
			char NOM[20] ;
			ALUMNO * SIG ;	
			ALUMNO(char *) ;
			~ALUMNO() ;
};


ALUMNO::ALUMNO(char * S)
{
		strcpy ( NOM , S );
		SIG = NULL ;
}

ALUMNO::~ALUMNO()
{
		cout << "\n\n   MATANDO A ... " << NOM ;
		
}


class PARTIDO {
	public :
			char NOM[20] ;
			ALUMNO * PALUM ;
			PARTIDO * SIG ;	
			PARTIDO(char * , ALUMNO *) ;
			~PARTIDO() ;
};


PARTIDO::PARTIDO( char * S , ALUMNO * PRESI )
{
		strcpy ( NOM , S );
		PALUM = PRESI ;
}


PARTIDO::~PARTIDO()
{		
		ALUMNO * P , *AUX;
		cout << "\n\n   MATANDO A ... TODOS LOS ALUMNOS DE " << NOM;
		P = PALUM;
		AUX = P;
		
		while(P){
		
		delete AUX;
		
		P = P->SIG;
		AUX = P;
		}
		
		getchar();
}



class GUIRNALDA {
	private :
			PARTIDO * INICIO ;
			PARTIDO * BUSCAR(char *);
	public :
			GUIRNALDA() ;
			~GUIRNALDA() ;
			void ARREGLATE(char *);
			void MIRAR() ;
			void GANADOR() ;
};


GUIRNALDA::GUIRNALDA()
{
		INICIO = NULL ;
}


GUIRNALDA::~GUIRNALDA()
{
		cout << "\n\n   QUE SE VAYAN TODOS !!!! " ;
		cout << "\n\n   DESTRUYENDO A TODOS LOS PARTIDOS" ;
		PARTIDO * P , *AUX;
		P =INICIO;
		AUX = P;
		
		while(P){
		
		delete AUX;
		
		P = P->SIG;
		AUX = P;
		}
		
		
}

void GUIRNALDA::ARREGLATE(char * S)
{
		/*  PROTOTIPO LOCAL  */
		char * GENERAPARTIDO() ;
		
		char BUF[20] ;
		ALUMNO * PAL , * P ;
		PARTIDO * PPAR ;		
		
		PAL = new ALUMNO(S) ;
		
		strcpy(BUF,GENERAPARTIDO()) ;
	
		PPAR = BUSCAR(BUF) ;
	
		if ( PPAR )  {
				/*   PARTIDO EXISTENTE   */
				P = PPAR->PALUM ;		/*  APUNTO AL PRESIDENTE  */
				while ( P->SIG )
						P = P->SIG ; 	/*  LLEVO P AL ULTIMO ALUMNO  */
				P->SIG = PAL ;
				return ;			
		}
		/*   PARTIDO NUEVO   */
		PPAR = new PARTIDO(BUF,PAL) ;
		PPAR->SIG = INICIO ;
		INICIO = PPAR ;	
}

PARTIDO * GUIRNALDA::BUSCAR(char * S)
{
		PARTIDO * PPAR ;
		PPAR = INICIO ;
	
		while ( PPAR ) {
				if ( !strcmp ( PPAR->NOM , S ) )
						return PPAR ;			
				PPAR = PPAR->SIG ;
		}
		return NULL ;	
}

void GUIRNALDA::MIRAR()
{
		PARTIDO * PPAR ;
		ALUMNO * PAL ;		
		
		fflush(stdin);
		borrartodo() ;
		
		cout << "\n\n\t  CONTENIDO DE LA GUIRNALDA \n\n\n";
		
		PPAR = INICIO ;
		while ( PPAR ) {
				cout << "\n\n\n\n\t  PARTIDO   :    " << PPAR->NOM <<"\n";
			
				PAL = PPAR->PALUM ;
				while ( PAL ) {
						cout << "\n\n\t  " << PAL->NOM ;
						PAL = PAL->SIG ;
				}
						
				getchar() ;
				PPAR = PPAR->SIG ;
		}
}

void GUIRNALDA::GANADOR()
{
		PARTIDO * PPAR ;
		ALUMNO * PAL ;		
		
		fflush(stdin);
		int CAN , MAX = 0 ;
		char GAN[20];
		
		PPAR = INICIO ;
		while ( PPAR ) {
			CAN = 0;
				PAL = PPAR->PALUM ;
				while ( PAL ) {
						CAN++;
						PAL = PAL->SIG ;
				}
				if(CAN > MAX){
				MAX = CAN;
				strcpy(GAN,PPAR->NOM);
				}		
				
				PPAR = PPAR->SIG ;
		}
		
		printf("\n\n\tEL GANADOR ES %s CON %d" , GAN , CAN) ;
}


char * GENERANOM();

int main( )
{  
		char BUF[20] ;
		GUIRNALDA G ;
		
		srand(554);
		
		strcpy(BUF,GENERANOM());
		while ( strcmp ( BUF , "FIN" ) ) {
				G.ARREGLATE(BUF) ;			
			
				strcpy(BUF,GENERANOM());
		}
		
		G.MIRAR() ;
		
		G.GANADOR() ;
		
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
						     "MARTIN","TOBIAS","SAUL","LORENA","LUIS",
							 "ANDRES","KEVIN","LUCRECIA","RAUL",
							 "ENZO","BETO","HERMINDO","FELIPE",
							 "GUILLERMO","TATO","KARINA","AQUILES",
							 "MINERVA","OLGA","LALO","TATIANA",
							 "LILO","STICH","EMA","THELMA",
							 "LOUISE","BONNIE","CLYDE","ROMEO",
							 "JULIETA","VERONICA","JORGE","ALEJANDRO",
							 "ROCIO","FIN"};
	
	return NOM[I++] ;
}


char * GENERAPARTIDO()
{
	static char NOM[][20] = {"ARRIBA","ABAJO","ATRAS","ADELANTE",
						     "IZQUIERDA","DERECHA","CENTRO" };						 
	return NOM[rand()%7] ;
}


