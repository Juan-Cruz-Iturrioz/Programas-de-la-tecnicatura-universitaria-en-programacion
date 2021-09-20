/*  VECTORES DE ESTRUCTURAS */
/*  ESTRUCTURAS ANIDADAS    */
/*  CARGA AUTOMATICA  */
/*  ORDENAMIENTO POR CAMPOS MULTIPLES  */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define NUM 16

struct FECHA {
		int DIA ;
		int MES ;
		int ANIO ;
};

struct ALUMNO {
		char NOM[20] ;
		char SEX ;
		struct FECHA NAC ;	
};

void CARGAR ( struct ALUMNO [] , int );
void MIRAR  ( struct ALUMNO [] , int );
void ORDENAR ( struct ALUMNO [] , int );

int main()
{
		struct ALUMNO VEC[NUM] ;
	
		
		CARGAR ( VEC , NUM );
		MIRAR ( VEC , NUM );
		
		ORDENAR ( VEC , NUM );
		MIRAR ( VEC , NUM );
				
		printf("\n\n\nFIN DEL PROGRAMA\n\n\n\n" );
		return 0 ;	
}  	
		
		
void CARGAR ( struct ALUMNO V[] , int N )
{
		int I ;
		char NOM[][20] = {"FELIPE","ROMUALDO","LORENA","CAROLINA",
						  "EDUARDO","DAIANA","FACUNDO","BRIAN",
						  "MARIO","LUIGI","MATIAS","CHRISTIAN",
						  "ROCIO","ANA","LAURA","ROBERTO"} ;
		char SEX[] = {'M','M','F','F','M','F','M','M',
					  'M','M','M','M','F','F','F','M'};
		for ( I = 0 ; I < N ; I++ ) {
				strcpy ( V[I].NOM , NOM[I] );
				V[I].SEX = SEX[I] ;
				V[I].NAC.DIA = 1 + rand()%30 ; 
				V[I].NAC.MES = 1 + rand()%12 ;
				V[I].NAC.ANIO = 1980 + rand()%21        ;				
		}
}		
		
		
		
void MIRAR ( struct ALUMNO V[] , int N )
{
		int I ;
		printf("\n\t\t %-15s %6s \t  %s \n" , "NOMBRE" , "SEXO" , "NACIMIENTO" );
		for ( I = 0 ; I < N ; I++ ) 
				printf("\n\t\t %-15s %6c \t %02d / %02d / %d " ,
				V[I].NOM , V[I].SEX , V[I].NAC.DIA , V[I].NAC.MES , V[I].NAC.ANIO );				
		printf("\n\n");getchar();
}		


void ORDENAR ( struct ALUMNO V[] , int N )
{
		int I , J ;
		struct ALUMNO AUX ;
		
		for ( I = 0 ; I < N-1 ; I++ )
				for ( J = 0 ; J < N-I-1 ; J++ )
						if ( V[J].SEX > V[J+1].SEX ||
						     V[J].SEX == V[J+1].SEX &&
							 strcmp( V[J].NOM , V[J+1].NOM ) > 0 )  {
								/*  SWAPPING  */
								AUX = V[J] ;
								V[J] = V[J+1] ;
								V[J+1] = AUX ;							
						}
}		
