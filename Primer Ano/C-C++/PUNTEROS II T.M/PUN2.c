/*   PUNTEROS A ESTRUCTURA  */

#include <stdio.h>
#include <stdlib.h>

struct FECHA {
		int DIA ;
		int MES ;
		int ANIO ;
};

struct FECHA CORREGIR ( struct FECHA );

int main( )
{  
		struct FECHA HOY ;
		
		HOY.DIA = 29 ;
		HOY.MES = 2 ;
		HOY.ANIO = 2007 ;
		
		printf("\n\n  FECHA  = %02d : %02d : %d" , 
		HOY.DIA , HOY.MES , HOY.ANIO );
		
		HOY = CORREGIR ( HOY );
		
		printf("\n\n  FECHA  = %02d : %02d : %d" , 
		HOY.DIA , HOY.MES , HOY.ANIO );
							
		printf("\n\n");	
		return 0 ;
}
		
		
struct FECHA CORREGIR ( struct FECHA H)
{
		if ( H.DIA == 29 && H.MES == 2 ) {
				H.DIA = 1 ;
				H.MES = 3 ;
		}
		return H ;
}
