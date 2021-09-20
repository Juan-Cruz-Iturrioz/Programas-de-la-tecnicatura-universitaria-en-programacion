/*  LA BASE DE DATOS BDARTICULOS ESTA ESTRUCTURADA DE LA SIGUIENTE MANERA */

#include <stdio.h>
#include <stdlib.h>



struct ARTI {
	short int ART ;
	char COD[50];
	char DESC[100];
	char FAB[50];
	short int STOCK ;
};

struct INDICE {
	short int ART ;
	int POS ;	
};

/*

1.  HACER UN PROGRAMA DE LECTURA
2.  MOSTRAR LOS ARTICULOS CUYO STOCK ES MENOR QUE 8
3.  DETERMINAR QUIEN ES EL PROVEEDOR QUE MAS ARTICULOS SUMINISTRA
4.  PERMITIR EL INGRESO DE UN #ART Y BUSCARLO
5.  INDEXAR EL ARCHIVO
6.  ORDENAR EL INDICE
7.  REPETIR EL PUNTO 4 CON UNA BUSQUEDA BINARIA INDEXADA.

*/



int main()
{
	FILE * FP , * IX ;
	struct ARTI X ;
	struct INDICE Y , W ;
	int N , POS  , I , J ;
	short int ART ;
	int MIN , MAX , MED , ENCONTRADO ;
	
	
	if ( !(FP = fopen("BDARTICULOS","rb"))) {
			printf ( "\n\n   ERROR APERTURA DE ARCHIVO");
			exit(1);
	}


	fread ( &X , sizeof(X) , 1 , FP );
	while ( !feof(FP) && getchar()!='Q') {
		printf("\n\n %6d  %-15s %-20s %-15s %6d" , 
		X.ART , X.COD , X.DESC , X.FAB , X.STOCK );	
		fread ( &X , sizeof(X) , 1 , FP );		
	}	

	
	fseek(FP,0L,SEEK_END);
	N = ftell(FP)/sizeof(X) ;
	printf("\n\n  LA BD TIENE %d REGISTROS" , N);
	
	/**************************************/
	/*									  */
	/*   CREACION DEL ARCHIVO DE INDICES  */
	/*                                    */
	/**************************************/
	
	printf("\n\n\n\n    CREANDO ARCHIVO DE INDICES ....... \n");
		
	
	if ( !(IX = fopen("BDIX","w+b"))) {
			printf ( "\n\n   ERROR APERTURA DE ARCHIVO");
			exit(1);
	}
	
	POS = 0 ; 
	fseek ( FP , 0L , SEEK_SET);
	fread ( &X , sizeof(X) , 1 , FP );
	while ( !feof(FP)) {
		Y.ART = X.ART ;
		Y.POS = POS++ ;
		fwrite ( &Y , sizeof(Y) , 1 , IX );	
		
		fread ( &X , sizeof(X) , 1 , FP );		
	}	
	
	fseek(IX,0L,SEEK_END);
	N = ftell(IX)/sizeof(Y) ;
	printf("\n\n  EL ARCHIVO DE INDICES %d REGISTROS" , N);
	
	/*********************************************/
	/*									         */
	/*   LECTURA DEL ARCHIVO DE INDICES          */
	/*                                           */
	/*********************************************/
	
	rewind(IX) ;
	fread ( &Y , sizeof(Y) , 1 , IX );
	while ( !feof(IX) && getchar()!='Q') {
		printf("\n\n\t\t %6d  %16d" , Y.ART , Y.POS );	
		fread ( &Y , sizeof(Y) , 1 , IX );		
	}	
	
	
	/******************************************/
	/*					     				  */
	/*   ORDENAMIENTO DEL ARCHIVO DE INDICES  */
	/*                                        */
	/******************************************/
	
	printf("\n\n\n\n    ORDENANDO ARCHIVO DE INDICES ....... \n");
	
	for ( I = 0 ; I < N-1 ; I++ )
			for ( J = 0 ; J < N-I-1 ; J++ ) {
					fseek ( IX , (long)J*sizeof(Y) , SEEK_SET);
					fread ( &Y , sizeof(Y) , 1 , IX );	
					fread ( &W , sizeof(W) , 1 , IX );	
				
					if ( Y.ART > W.ART ) {
						fseek ( IX , (long)(-2)*sizeof(Y) , SEEK_CUR);	
						fwrite ( &W , sizeof(W) , 1 , IX );	
						fwrite ( &Y , sizeof(Y) , 1 , IX );						
					}						
			}
	
	printf("\n\n\n\n    FIN DE ORDENAMIENTO EN ARCHIVO DE INDICES ....... \n");
	
	/*********************************************/
	/*									         */
	/*   LECTURA DEL ARCHIVO DE INDICES          */
	/*                                           */
	/*********************************************/
	
	rewind(IX) ;
	fread ( &Y , sizeof(Y) , 1 , IX );
	while ( !feof(IX) && getchar()!='Q') {
		printf("\n\n\t\t %6d  %16d" , Y.ART , Y.POS );	
		fread ( &Y , sizeof(Y) , 1 , IX );		
	}	
	
	
	
	
	/*********************************************/
	/*									         */
	/*   BUSQUEDA BINARIA EN ARCHIVO DE INDICES  */
	/*                                           */
	/*********************************************/
	
	printf("\n\n\n    NUMERO DE ARTICULO   :   ");
	scanf("%d" , &ART);
	
	MIN = 0 ;
	MAX = N-1 ;
	ENCONTRADO = 0 ;
	while ( MIN <= MAX && ! ENCONTRADO ) {
			MED = (MIN+MAX)/2 ;
			fseek ( IX , (long)MED*sizeof(Y) , SEEK_SET);
			fread ( &Y , sizeof(Y) , 1 , IX );
			
			if ( Y.ART == ART ) 
					ENCONTRADO = 1 ;
			else
					if ( ART < Y.ART ) 
							MAX = MED-1 ;
					else
							MIN = MED+1 ;
	}
	
	if ( ! ENCONTRADO ) {
			printf("\n\n  EL ARTICULO %d NO SE ENCUENTRA EN EL ARCHIVO" , 
			ART);
			exit(2);
	}
	
		
	/*********************************************/
	/*									         */
	/*   ACCESO INDIRECTO A LA BASE DE DATOS     */
	/*                                           */
	/*********************************************/	

	fseek ( FP , (long)Y.POS*sizeof(X) , SEEK_SET);
	fread ( &X , sizeof(X) , 1 , FP );	
	printf("\n\n %6d  %-15s %-20s %-15s %6d" , 
	X.ART , X.COD , X.DESC , X.FAB , X.STOCK );	
	
	fclose(FP);
	fclose(IX);
	
	
	printf("\n\n   FIN DEL PROGRAMA");
	return 0 ;
}
