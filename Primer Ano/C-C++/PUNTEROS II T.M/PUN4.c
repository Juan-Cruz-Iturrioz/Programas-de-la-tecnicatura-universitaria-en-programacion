/*   PUNTEROS A ESTRUCTURA  */
/*   VECTOR DE ESTRUCTURAS  */

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
		struct ALUMNO AUX ;
		
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
		printf("\n\n\n\n\t\t %-15s %10s %10s\n" , "NOMBRE" , "SEXO" , "NOTA"); 
		for ( P = VEC ; P < VEC+N ; P++ ) 
				printf("\n\n\t\t %-15s %10c %10d" , 
				P->NOM , P->SEX , P->NOTA );
		getchar() ; getchar() ;
					
		/*    ORDENAR    */			
		for ( P = VEC , I = 0 ; I < N-1 ; I++ )
				for ( J = 0 ; J < N-I-1 ; J++ )
						if ( strcmp ( (P+J)->NOM , (P+J+1)->NOM ) > 0 ) {
								/*  SWAPPING  */
								AUX = *(P+J) ;
								*(P+J) = *(P+J+1) ;
								*(P+J+1) = AUX ;						
						}			
					
					
		/*   IMPRESION DE DATOS  */
		printf("\n\n\n\n\n\t\t %-15s %10s %10s\n" , "NOMBRE" , "SEXO" , "NOTA"); 
		for ( P = VEC , I = 0 ; I < N ; I++ ) 
				printf("\n\n\t\t %-15s %10c %10d" , 
				(P+I)->NOM , (P+I)->SEX , (P+I)->NOTA );			
					
							
		printf("\n\n");	
		return 0 ;
}
		
		

