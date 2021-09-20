/*   PUNTEROS A ESTRUCTURA  */
/*   TRANSFRENCIA POR REFERENCIA  */

#include <stdio.h>
#include <stdlib.h>

struct FECHA {
		int DIA ;
		int MES ;
		int ANIO ;
};

void CORREGIR ( struct FECHA * );

int main( )
{  
		struct FECHA HOY ;
		
		HOY.DIA = 29 ;
		HOY.MES = 2 ;
		HOY.ANIO = 2007 ;
		
		printf("\n\n  FECHA  = %02d : %02d : %d" , 
		HOY.DIA , HOY.MES , HOY.ANIO );
		
		CORREGIR ( & HOY );
		
		printf("\n\n  FECHA  = %02d : %02d : %d" , 
		HOY.DIA , HOY.MES , HOY.ANIO );
							
		printf("\n\n");	
		return 0 ;
}
		
		
void CORREGIR ( struct FECHA * P )
{
		//    P  EQUIVALE A   &HOY
		//    *P  EQUIVALE A    HOY
		
		if ( P->DIA == 29 && P->MES == 2 ) {
				P->DIA = 1 ;
				P->MES = 3 ;
		}
}
