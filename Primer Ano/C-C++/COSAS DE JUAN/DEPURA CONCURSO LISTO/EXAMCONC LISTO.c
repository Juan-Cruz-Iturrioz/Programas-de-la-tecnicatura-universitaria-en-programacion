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
	FILE * FP , *FPIX  ;
	
	struct ITEM X , Y , Z;
	
	int I , J , CAN = 0 , N  ;
	
	char BOR [20] = {"BORRADO"};
	
	if ( ! ( FP = fopen ("CONCURSO ","rb" ) ) ){
		
		printf("\n\n\t ERROE DE APERTURA DE ARCHIVO CONCURSO");
	
		exit(1);

	}
	
	
	if ( ! ( FPIX = fopen ( BOR ,"w+b" ) ) ){
	
		printf("\n\n\t ERROE DE APERTURA DE ARCHIVO CONCURSO IX");
	
		exit(1);
	
	}	
	
		
	
		fread(&X , sizeof(X), 1 , FP );
			
		fwrite ( &X , sizeof(X) , 1 , FPIX );
		
		while( ! feof (FP) ){
	
			fread(&X , sizeof(X), 1 , FP );
			
			fwrite ( &X , sizeof(X) , 1 , FPIX );
		
		}	
		
		fclose(FP);
		
		if ( ! ( FP = fopen ("CONCURSO LISTO","wb" ) ) ){
	
		printf("\n\n\t ERROE DE APERTURA DE ARCHIVO CONCURSO LISTO");
	
		exit(1);
	
	}	
		
		
		
		fseek( FPIX , 0l , SEEK_END );
		
		N = ftell(FPIX)/sizeof(X);
		
		
		for( I = 0 ; I < N - 1 ; I++)
			for(J = 0 ; J < N - I - 1 ; J++){
			
			fseek(FPIX , J*sizeof(X) , SEEK_SET);
			
			fread ( &X , sizeof(X) , 1 , FPIX);
			
			fread ( &Y , sizeof(Y) , 1 , FPIX );
						
						if ( strcmp(X.NOMBRE , Y.NOMBRE) > 0 ) {
						
							fseek(FPIX, J*sizeof(Y) , SEEK_SET);
							
							fwrite( &Y , sizeof(Y) , 1 , FPIX);
							
							fseek(FPIX, J*sizeof(Y) , SEEK_SET);
							
							
							fseek(FPIX, (J+1)*sizeof(X) , SEEK_SET);
							
							fwrite(&X , sizeof(X) , 1 , FPIX );
							
							fseek(FPIX, (J+1)*sizeof(X) , SEEK_SET);
						}
			}
		
		
		
		for (I = 0 ; I < N ; I++){
		
			fseek(FPIX , I*sizeof(X) , SEEK_SET);
			
			fread(&X , sizeof(X), 1 , FPIX );
				
			CAN = CAN + X.PUNTOS;
			
			fseek(FPIX , (I+1)*sizeof(Y) , SEEK_SET);
			
			fread(&Y , sizeof(Y) , 1 , FPIX );
		
				if ( (strcmp(X.NOMBRE , Y.NOMBRE) ) ){
		
				strcpy(Z.NOMBRE , X.NOMBRE);
		
				Z.PUNTOS = CAN ;
		
				fwrite(&Z , sizeof(Z) , 1 , FP);
			
				CAN = 0;
			
			}
			
		}
	
	strcpy(Z.NOMBRE , X.NOMBRE);
	
	Z.PUNTOS = CAN ;	
	
	fwrite(&Z , sizeof(Z) , 1 , FP);
				
		
	
	fclose(FP);
	
	fclose(FPIX);
	
	remove(BOR);
	
	printf("\n\n\n\tFIN DEL PROGRAMA  \n\n") ;
	return 0 ;
}


