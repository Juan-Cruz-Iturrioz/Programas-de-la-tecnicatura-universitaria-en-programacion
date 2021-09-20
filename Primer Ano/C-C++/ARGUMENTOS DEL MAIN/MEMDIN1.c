/*   GESTION DINAMICA DE MEMORIA    */

#include <stdio.h>
#include <stdlib.h>

float FG = 33.5689 ;

int main( )
{  
		float FL = 99.2356 ;
		float * PFD ;		
		
		if ( (PFD = (float *)malloc(sizeof(float))) == NULL ) {
				printf("\n\n  NO HAY MEMORIA");
				exit(1);
		}; 
		
		*PFD = 66.4875 ;
		
		printf("\n\n\n   FG = %10f     &FG = %p" , FG , &FG );
		printf("\n\n\n   FL = %10f     &FL = %p" , FL , &FL );
		printf("\n\n\n   FD = %10f     &FD = %p" , *PFD , PFD );
		
		
		printf("\n\n");	
		return 0 ;
}
		
		

