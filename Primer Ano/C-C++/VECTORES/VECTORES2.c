/*  VECTORES  */
/*  ASIGNACION DIRECTA  */


#include <stdio.h>
#include <conio.h>


int main()
{
		int VEC[] = { 54 , 21 , 98 , 75 };
		int I ;
				
		printf("\n\n   TAMAÑO DEL VECTOR  = %d BYTES\n\n" , sizeof(VEC) );
		printf("\n\n   CANTIDAD DE VARIABLES  = %d \n\n" , sizeof(VEC)/sizeof(int) );
				
		/*   IMPRESION DEL VECTOR   */
		printf("\n\n\n\n\t\tIMPRESION DEL VECTOR\n\n\t");		
		for ( I = 0 ; I < sizeof(VEC)/sizeof(int) ; I++ ) 
				printf("%5d" , VEC[I] );
					
		printf("\n\n\nFIN DEL PROGRAMA\n\n\n\n" );
		return 0 ;	
}  
