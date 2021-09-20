/*  VECTORES DE ESTRUCTURAS */
/*  ESTRUCTURAS ANIDADAS    */
/*  CARGA MANUAL  */

#include <stdlib.h>
#include <stdio.h>

#define NUM 6

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

int main()
{
		struct ALUMNO VEC[NUM] ;
	
		
		CARGAR ( VEC , NUM );
		MIRAR ( VEC , NUM );
		
				
		printf("\n\n\nFIN DEL PROGRAMA\n\n\n\n" );
		return 0 ;	
}  	
		
		
void CARGAR ( struct ALUMNO V[] , int N )
{
		int I ;
		for ( I = 0 ; I < N ; I++ ) {
				printf("\n\n\t\t  NOMBRE   :   ") ;
				fflush(stdin);
				gets ( V[I].NOM );
				printf("\n\t\t  SEXO     :   ") ;
				V[I].SEX = getchar() ;
				printf("\n\t\t  FECHA DE NACIMIENTO [DD/MM/AAAA]    :    ") ;
				scanf("%d/%d/%d" , &V[I].NAC.DIA , &V[I].NAC.MES , &V[I].NAC.ANIO );				
		}
}		
		
		
		
void MIRAR ( struct ALUMNO V[] , int N )
{
		int I ;
		printf("\n\n\t\t %-15s %6s \t  %s \n\n" , "NOMBRE" , "SEXO" , "NACIMIENTO" );
		for ( I = 0 ; I < N ; I++ ) 
				printf("\n\n\t\t %-15s %6c \t %02d / %02d / %d " ,
				V[I].NOM , V[I].SEX , V[I].NAC.DIA , V[I].NAC.MES , V[I].NAC.ANIO );				
		printf("\n\n");getchar();
}		
