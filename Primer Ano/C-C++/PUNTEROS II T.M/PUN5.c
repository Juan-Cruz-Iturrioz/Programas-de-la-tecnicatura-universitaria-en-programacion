/*   PUNTEROS A ESTRUCTURA  */
/*   VECTOR DE PUNTEROS A ESTRUCTURAS  */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ALUMNO {
		char NOM[20] ;
		char SEX ;
		int NOTA ;
};

#define N 7

int main( )
{  
		struct ALUMNO VEC[N] , * P ;
		int I , J ;
		struct ALUMNO * VP[N] ;  // VECTOR DE PUNTEROS A ESTRUCTURA ALUMNO
		struct ALUMNO * PAUX ;
		
		/*  INICIALIZACION DEL VECTOR DE PUNTEROS  */
		for ( I = 0 ; I < N ; I++ )
				//        VP[I] = &VEC[I] ;
				*(VP+I) = VEC+I ;
		
		/*   CARGA DE DATOS  */
		for ( P = VEC ; P < VEC+N ; P++ ) {
				printf("\n\n      NOMBRE   :   ");
				fflush(stdin);
				gets(P->NOM);			
				printf("\n      SEXO     :   ");
				P->SEX = getchar();
				printf("\n      NOTA     :   ");
				scanf("%d" , &(P->NOTA) );
		}
		
		/*   IMPRESION DE DATOS  */
		printf("\n\n\n\n   IMPRESION DIRECTA DE LOS DATOS");
		printf("\n\n\t\t %-15s %10s %10s\n" , "NOMBRE" , "SEXO" , "NOTA"); 
		for ( P = VEC ; P < VEC+N ; P++ ) 
				printf("\n\n\t\t %-15s %10c %10d" , 
				P->NOM , P->SEX , P->NOTA );
		getchar() ; getchar() ;
					
		printf("\n\n\n\n   IMPRESION INDIRECTA DE LOS DATOS");
		printf("\n\n\t\t %-15s %10s %10s\n" , "NOMBRE" , "SEXO" , "NOTA"); 
		for ( I = 0 ; I < N ; I++ ) 
				printf("\n\n\t\t %-15s %10c %10d" , 
				(*(VP+I))->NOM , (*(VP+I))->SEX , (*(VP+I))->NOTA );
		getchar() ; 
					
							
		/*    ORDENAR    */			
		for ( P = VEC , I = 0 ; I < N-1 ; I++ )
				for ( J = 0 ; J < N-I-1 ; J++ )
						if ( (*(VP+J))->NOTA < (*(VP+J+1))->NOTA ) {
								/*  SWAPPING  */
								PAUX = *(VP+J) ;
								*(VP+J) = *(VP+J+1) ;
								*(VP+J+1) = PAUX ;						
						}			
					
		printf("\n\n\n\n   IMPRESION INDIRECTA DE LOS DATOS");
		printf("\n\n\t\t %-15s %10s %10s\n" , "NOMBRE" , "SEXO" , "NOTA"); 
		for ( I = 0 ; I < N ; I++ ) 
				printf("\n\n\t\t %-15s %10c %10d" , 
				(*(VP+I))->NOM , (*(VP+I))->SEX , (*(VP+I))->NOTA );
		getchar() ; 		
					
		/*   IMPRESION DE DATOS  */
		printf("\n\n\n\n   IMPRESION DIRECTA DE LOS DATOS");
		printf("\n\n\t\t %-15s %10s %10s\n" , "NOMBRE" , "SEXO" , "NOTA"); 
		for ( P = VEC , I = 0 ; I < N ; I++ ) 
				printf("\n\n\t\t %-15s %10c %10d" , 
				(P+I)->NOM , (P+I)->SEX , (P+I)->NOTA );			
					
							
		printf("\n\n");	
		return 0 ;
}
		
		

