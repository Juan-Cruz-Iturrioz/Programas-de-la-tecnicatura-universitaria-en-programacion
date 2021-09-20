/*  VECTOR DE STRINGS  */


#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

#define NUM   4
#define LARGO 6


int main()
{
		char VS[NUM][LARGO] ;
		int I ;
		
		for ( I = 0 ; I < NUM ; I++ )  {
				printf("\n\n   NOMBRE  =  ");
				gets(VS[I]);			
		}
		
		printf("\n\n\n");
		for ( I = 0 ; I < NUM ; I++ )  
				printf("\n\n\t\t %s" , VS[I] );			

		printf("\n\n\n");
		return 0 ;	
}  	
		
	

