/*   ARGUMENTOS DEL MAIN    */

#include <stdio.h>
#include <stdlib.h>

int main( int argc , char ** argv )
{  
		int I ;
		
		printf("\n\n  CANTIDAD DE ARGUMENTOS = %d" , argc);
		
		printf("\n\n\n   LISTA DE ARGUMENTOS\n\n");
		for ( I = 0 ; I < argc ; I++ )
				printf("\n\n %5d %12p %-20s" , I , *(argv+I) , *(argv+I) );
				
		
		printf("\n\n");	
		return 0 ;
}
		
		

