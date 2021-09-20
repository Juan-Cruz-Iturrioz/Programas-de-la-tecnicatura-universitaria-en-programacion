/*   ARGUMENTOS DEL MAIN    */

#include <stdio.h>
#include <stdlib.h>

int main( int argc , char ** argv , char ** envp )
{  
		printf("\n\n\n   VARIABLES DE ENTORNO \n\n");
		for ( ; *envp ; envp++ )
				printf("\n\n\t\t %s" , *envp );
			
		printf("\n\n");	
		return 0 ;
}
		
		

