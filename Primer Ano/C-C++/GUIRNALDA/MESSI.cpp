/*   MESSI   */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <iostream>

using namespace std;

class JUGADOR {
		public :
			char NOM[20] ;
			JUGADOR * SIG ;
			JUGADOR(char *);
			~JUGADOR();	
};

JUGADOR::JUGADOR(char * S)
{
		strcpy ( NOM , S ) ;
		SIG = NULL ;
}
JUGADOR::~JUGADOR()
{
		cout << "\n\n   MATANDO A ... " << NOM << "\n\n";
		getchar();
}


class PARTIDO {
		public :
			char NOM[20] ;
			JUGADOR * PALUM ;
			PARTIDO * SIG ;
			PARTIDO ( char * , JUGADOR * ) ;
			~PARTIDO() ;	
};


PARTIDO::PARTIDO ( char * S , JUGADOR * PRESI )
{
		strcpy ( NOM , S ) ;
		PALUM = PRESI ;
}

PARTIDO::~PARTIDO()
{
		cout << "\n\n   MATANDO A ... TODOS LOS JUGADORES\n\n";
		cout << "\n\n   TAREA PARA USTEDES \n\n";
		getchar();
}


class GUIRNALDA {
		private :
			PARTIDO * INICIO ;
			PARTIDO * BUSCAR ( char * );
		public :
			GUIRNALDA() ;
			~GUIRNALDA() ;
			void ARREGLATE(char *);
			void MIRAR();
};

GUIRNALDA::GUIRNALDA()
{
		INICIO = NULL ;
}


GUIRNALDA::~GUIRNALDA()
{
		cout << "\n\n   QUE SE VAYAN TODOS !!! DESTRUYENDO PARTIDOS" ;
		cout << "\n\n   OTRA QUE ES PARA USTEDES " ;
		getchar();
}


PARTIDO * GUIRNALDA::BUSCAR(char * S)
{
		PARTIDO * P ;
		P = INICIO ;
		
		while ( P ) {
				if ( ! strcmp(P->NOM,S) )			
						return P ;			
				P = P->SIG ;			
		}
		return NULL ;
}



void GUIRNALDA::ARREGLATE ( char * S )
{
		char * GENERAEQUIPO() ;				/*  PROTOTIPO  */
		
		JUGADOR * PAL , * P ;
		PARTIDO * PPAR ;
		char BUF[20] ;
	
		PAL = new JUGADOR(S) ;
		
		strcpy ( BUF, GENERAEQUIPO() );
		
		PPAR = BUSCAR(BUF) ;

		if ( PPAR ) {
				/*  PARTIDO EXISTENTE  */
				P = PPAR->PALUM ;
				while ( P->SIG )
						P = P->SIG ;  /* VOY HASTA EL ULTIMO ALUMNO */
				P->SIG = PAL ;
				return ;			
		}		
		/*   PARTIDO NUEVO    */
		PPAR = new PARTIDO(BUF,PAL) ;
		PPAR->SIG = INICIO ;
		INICIO = PPAR ;
}

void GUIRNALDA::MIRAR()
{
		PARTIDO * PPAR ;
		JUGADOR * PAL ;
		
		cout << "\n\n  CONTENIDO DE LA GUIRNALDA\n\n\n";
		PPAR = INICIO ;
		while ( PPAR ) {
					cout << "\n\n\n\n\t\t" << PPAR->NOM << "\n" ;
			
					PAL = PPAR->PALUM ;
					while ( PAL ) {
							cout << "\n\n\t\t" << PAL->NOM ;
			
							PAL = PAL->SIG ;
					}
					getchar();
						
					PPAR = PPAR->SIG ;
		}
}



char * GENERANOM();

int main()
{  
		char BUF[20] ;
		GUIRNALDA G ;
		
		srand(105);
		
		strcpy( BUF , GENERANOM() ) ;
		while ( strcmp (BUF,"FIN") ) {
				G.ARREGLATE(BUF) ;
				
				strcpy( BUF , GENERANOM() ) ;
		}
		
		G.MIRAR() ;		
		
		
		
		printf("\n\n      FIN DEL PROGRAMA");	
		return 0 ;
}


char * GENERANOM()
{
		static char NOM[][20] = {"MARADONA","RONALDO","MESSI",
						  "PELE","MESSI","LABRUNA",
						  "ORTEGA","RIQUELME","ROMA","CARRIZO",
						  "LORENZO","BOBBY MOORE","RONALDINHO","ARMANI",
						  "TARANTINI","RATTIN","ROSSI","ONEGA",
						  "ARTIME","VARACKA","GALLARDO","TEVEZ",
						  "MORETE","ERICO","LABRUNA","MORENO",
						  "PEDERNERA","LOUSTEAU","CAVENAGHI","NAVARRO",
						  "PAVONI","VERON","MESSI","RONALDO",
						  "PERFUMO","MATOSAS","PELE",
						  "CUBILLA","SANTORO","MALBERNAT","BECKENBAUER",
						  "EUSEBIO","PASTORIZA","JAIRZINHO","ROJAS",
						  "MADURGA","PIANETTI","ANDRADA","MARIN",
						  "ROMERO","ALONSO","FRANCESCOLI","DOMINGUEZ",
						  "MAYADA","MORA","MASCHERANO","KRANEVITER",
						  "SOLARI","MATURANA","BOBY MOORE",
						  "HIGUITA","BASILE","FRANCESCOLI",
						  "SARNARI","BILARDO","BATISTUTA","VALENTIM",
						  "CRISTIANO","ZAMORANO","SALAS","ARDILES",
						  "KEMPES","ZANABRIA","OLGUIN","PALACIOS",
						  "MESSI","VERON","FIN"};
		static int I = 0 ;
		return NOM[I++] ;	
}


char * GENERAEQUIPO()
{
		static char NOM[][20] = {"BARCELONA","RIVER","BOCA","JUVENTUS",
						  		 "MILAN","REAL MADRID","DYNAMO",
								 "BOTAFOGO","COLO COLO","PE�AROL",
								 "RACING","INDEPENDIENTE"  };
		return NOM[rand()%12] ;	
}

