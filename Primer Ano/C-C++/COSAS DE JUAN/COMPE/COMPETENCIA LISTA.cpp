/*   COMPETENCIA   */

/*   SE DESARROLLARA UN TORNEO POR DISCIPLINAS.                  */
/*   CADA UNA DE ESTAS TIENE UN DETERMINADO HANDICAP             */ 
/*   POR CADA DISCIPLINA SE DISPONE DE LA LISTA DE COMPETIDORES  */
/*   EN EL ORDEN EN QUE CLASIFICARON                             */
/*   SEGUN LA POSICION OBTENIDA SE ASIGNA EL SIGUIENTE PUNTAJE : */ 
/*   		PRIMERO     10 PUNTOS                                */
/*   		SEGUNDO      9 PUNTOS                                */
/*   		TERCERO      8 PUNTOS                                */
/*   		CUARTO       7 PUNTOS                                */
/*   		QUINTO       6 PUNTOS                                */
/*   		EL RESTO     2 PUNTOS                                */
/*   EL COMPETIDOR (QUE PUEDE ESTAR INSCRIPTO VARIAS VECES EN    */
/*   CADA DISCIPLINA) OBTIENE EL PUNTAJE DE SU POSICION MULTI    */
/*   PLICADO POR EL HANDICAP DE LA DISCIPLINA CONSIDERADA        */
/*   EL GANADOR ES EL QUE SUMA MAYOR PUNTAJE TOTAL               */
/*   LA INSCRIPCION EN CADA PARTICIPACION CUESTA 1000 $ POR      */
/*   EL HANDICAP DE LA DISCIPLINA EN QUE SE INSCRIBE             */

/*   SE PIDE :                                                   */
/*			1. DETERMINAR EL GANADOR Y SU PUNTAJE                */
/*          2. INDICAR EN QUE COMPETENCIAS INTERVINO Y QUE       */
/*             LUGAR(ES) OCUPO EN ESTAS   						 */ 
/*          3. DETERMINAR CUANTO PAGO                            */

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>

using namespace std ;

class COMPETIDOR {
	public :
			COMPETIDOR(char *) ;
			~COMPETIDOR() ;
			char NOM[20] ;
			COMPETIDOR * SIG ;	
};


COMPETIDOR::COMPETIDOR(char * S)
{
		strcpy ( NOM , S );
		SIG = NULL ;
}

COMPETIDOR::~COMPETIDOR()
{
		cout << "\n\n   MATANDO A ... " << NOM ;
		
}




class DISCIPLINA {
	public :
			char NOM[20] ;
			int HANDICAP ;
			COMPETIDOR * PALUM ;
			DISCIPLINA * SIG ;	
			DISCIPLINA(char * , COMPETIDOR *) ;
			~DISCIPLINA() ;
};


DISCIPLINA::DISCIPLINA(char * S , COMPETIDOR * PRIMERO)
{
		strcpy ( NOM , S );
		HANDICAP = 5 + rand()%30 ;
		PALUM = PRIMERO ;
}

DISCIPLINA::~DISCIPLINA()
{
		cout << "\n\n   MATANDO A ... TODOS LOS COMPETIDORES DE " << NOM;
		COMPETIDOR * P , *AUX ;
		
		
		P = PALUM;
		AUX = P;
		
		while(P){
		
		delete AUX;
		
		P = P->SIG;
		AUX = P;
		}
		getchar();
}



class TORNEO {
	private :
			DISCIPLINA * INICIO ;
			DISCIPLINA * BUSCAR(char *);
	public :
			TORNEO() ;
			~TORNEO() ;
			void ARREGLATE(char *);
			void MIRAR() ;
			void GANADOR(); 
			int BUSCAR_GANADOR(char *);
			void BUSCAR_GAR_DATOS(char *);
};


TORNEO::TORNEO()
{
		INICIO = NULL ;
}

TORNEO::~TORNEO()
{
		cout << "\n\n   DESTRUYENDO TODAS LAS DISCIPLINAS " ;
		
		DISCIPLINA * P , *AUX;
		P = INICIO;
		AUX = P;
		
		while(P){
		
		delete AUX;
		
		P = P->SIG;
		AUX = P;
		}
		getchar();
}

void TORNEO::ARREGLATE(char * S)
{
		/*   PROTOTIPO  */
		char * GENERADISCIPLINA();
		
		char BUF[20] ;
		COMPETIDOR * PAL , * P ;
		DISCIPLINA * PPAR ;
		
		PAL = new COMPETIDOR(S) ;
		
		strcpy ( BUF , GENERADISCIPLINA() ) ;
	
		PPAR = BUSCAR(BUF) ;
	
		if ( PPAR ) {
				/*  DISCIPLINA EXISTENTE  */
				P = PPAR->PALUM ;		/*  APUNTO AL PRIMERO  */
				while ( P->SIG )
						P = P->SIG ; 	/*  AVANZO AL ULTIMO COMPETIDOR  */
				P->SIG = PAL ;		
				return ;
		}
		/*  NUEVA DISCIPLINA  */
		PPAR = new DISCIPLINA(BUF,PAL) ;
		PPAR->SIG = INICIO ;
		INICIO = PPAR ;	
}

DISCIPLINA * TORNEO::BUSCAR(char * S)
{
		DISCIPLINA * P ;
		P = INICIO ;
		
		while (P) {
				if ( ! strcmp ( P->NOM , S ) )
						return P ;			
				P = P->SIG ;
		}
		return NULL ;
}


void TORNEO::MIRAR()
{
		DISCIPLINA * PPAR ;
		COMPETIDOR * PAL ;
		
		fflush(stdin);
		system("cls");
		cout << "\n\n\n\n\t\t    CONTENIDO DEL TORNEO \n\n" ;
		PPAR = INICIO ;
		while ( PPAR ) {
				cout << "\n\n\n\n\t\t    DISCIPLINA   :   " << PPAR->NOM ;
				cout << "\n\n\t\t    HANDICAP     :   " << PPAR->HANDICAP ;
				cout << "\n\n" ;
			
				PAL = PPAR->PALUM ;
				while ( PAL ) {
						cout << "\n\t\t    " << PAL->NOM ;				
						PAL = PAL->SIG ;
				}
				getchar();
						
				PPAR = PPAR->SIG ;
		}
}


void TORNEO::GANADOR()
{
		DISCIPLINA * PPAR ;
		COMPETIDOR * PAL ;
		int PUN , MAS = 0;
		char BUS[20];
		PPAR = INICIO ;
	
		while ( PPAR ) {
				
			
				PAL = PPAR->PALUM ;
				while ( PAL ) {
						
						PUN = BUSCAR_GANADOR (PAL->NOM);
									
							if (PUN > MAS){
							MAS = PUN;
							strcpy(BUS , PAL->NOM);
							}
							
				PAL = PAL->SIG ;
				}
		
		
				
						
				PPAR = PPAR->SIG ;
		}
		
		
		cout << "\n\t EL GRANARO ES " << BUS << " CON " << MAS ;
		BUSCAR_GAR_DATOS(BUS);
		getchar();
}

int TORNEO::BUSCAR_GANADOR (char BUS[20])
{
		DISCIPLINA * PPAR ;
		COMPETIDOR * PAL ;
		
		int I , PUS = 0;
		
		PPAR = INICIO ;
		while ( PPAR ) {
				
				PAL = PPAR->PALUM ;
				I = 10;
				while ( PAL ) {
						
					if ( ! strcmp(BUS , PAL->NOM) ){
					
					if (I >=6)
					PUS = PUS + I*PPAR->HANDICAP ;
					else 
					PUS = PUS + 2*PPAR->HANDICAP;
					
					}	
									
						PAL = PAL->SIG ;
				I--;
				}
				
						
				PPAR = PPAR->SIG ;
		}

return PUS;

}


void TORNEO::BUSCAR_GAR_DATOS(char BUS[20])
{
		DISCIPLINA * PPAR ;
		COMPETIDOR * PAL ;
		int I , PLATA = 0 , V ;
		
		PPAR = INICIO ;
		while ( PPAR ) {
				
				I = 1;
				V = 1;
				PAL = PPAR->PALUM ;
				
				while ( PAL ) {
						
						if ( !strcmp (PAL->NOM , BUS) ){
						PLATA = PLATA + 1000*PPAR->HANDICAP;
						
						if (V){
						cout << " \n\n\n\t    DISCIPLINA   :   " << PPAR->NOM ;
						V = 0;
						}
						
						cout << "\n\n\t       PUESTO  " << I ; 
						
						}
						
						I++;					
						PAL = PAL->SIG ;
				}
			
						
				PPAR = PPAR->SIG ;
		}

cout << "\n\n\n\t\t LA PLATA QUE LE COSTO ES " << PLATA ;


}
char * GENERANOM();

int main( )
{  
		TORNEO T ;		
		char BUF[20];
		
		srand(60);
		
		strcpy ( BUF , GENERANOM() );
		while ( strcmp(BUF,"FIN") ) {
				T.ARREGLATE(BUF) ; 
			
				strcpy ( BUF , GENERANOM() );
		}
		
//		T.MIRAR() ; 
		
		T.GANADOR() ;
//      T.MAYOR_INVERSION() ;
		
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
						     "MARTIN","TOBIAS","SAUL","LORENA",
							 "ANDRES","KEVIN","LUCRECIA","RAUL",
							 "ENZO","BETO","HERMINDO","FELIPE",
							 "GUILLERMO","TATO","KARINA","AQUILES",
							 "MINERVA","OLGA","LALO","TATIANA",
							 "LILO","STICH","EMA","THELMA",
							 "LOUISE","BONNIE","CLYDE","ROMEO",
							 "JULIETA","VERONICA","JORGE","ALEJANDRO",
							 "ROCIO","LUJAN","LIBORIO","CONAN","FIN"};
	if ( ++I < 250 )
		return NOM[rand()%52] ;
	else
		return NOM[52] ;
}


char * GENERADISCIPLINA()
{
	static char NOM[][20] = {"TRIATLON","PENTATLON","MARTILLO","JABALINA",
						     "GARROCHA","SALTO TRIPLE","SALTO EN LARGO",
							 "MARATON","CARRERA 100 MTS","DISCO","MEDIA MARATON","PESAS" };						 
	return NOM[rand()%12] ;
}


