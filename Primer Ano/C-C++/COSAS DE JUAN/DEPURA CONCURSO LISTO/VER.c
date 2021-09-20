/*  EL ARCHIVO "CONCURSO" ESTA FORMADO POR ESTRUCTURAS ITEM     */
/*  ESTAS TIENEN LOS NOMBRES Y PUNTAJES PARA UN CONCURSO        */
/*  ESTOS NOMBRES APARECEN MAS DE UNA VEZ CON DIFERENTE PUNTAJE */

/*  SE PIDE DEPURAR EL ARCHIVO PARA DEJAR UN SOLO NOMBRE DE CADA UNO */
/*  CON LA SUMA DE SUS PUNTAJES                                      */

/*  DETERMINAR EL NOMBRE DEL GANADOR Y SU PUNTAJE    */



#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


struct ITEM {
	char NOMBRE[20];
	int PUNTOS ;
};


int main()
{
	FILE * FP  ;
	
	struct ITEM X ;

	
	if ( ! ( FP = fopen ("CONCURSO LISTO","rb" ) ) ){
	
		printf("\n\n\t ERROE DE APERTURA DE CONCURSO LISTO");
	
		exit(1);
	
	}	
	
	
		fread(&X , sizeof(X) , 1 , FP);
		
		printf("\n\n\t %-20s %-20s" ,"NOMBRE" , "PUNTOS");
		
		while ( ! ( feof (FP)) ){
		
		printf ("\n\n\t %-20s %-20d" , X.NOMBRE , X.PUNTOS);
		
		fread(&X , sizeof(X) , 1 , FP);
		
		}	
	
	
	fclose(FP);

	printf("\n\n\n\tFIN DEL PROGRAMA  \n\n") ;
	return 0 ;
}


