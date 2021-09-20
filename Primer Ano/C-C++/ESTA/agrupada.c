
#include<stdio.h>
#include<stdlib.h>

		struct AGRUPADA {
		float VEC[2] ;
		float MARCA ;
		int fi;
		int FI;
		};
		
	
int main (){

srand(1969);

int X = 10;
int Y = 10;
int G = 5;
int I,J,Z;
float  MAR[][10] = { 60 , 62 , 62 , 62 , 62 , 

					63  , 64 , 64 , 64 , 64 , 64 , 64 , 64 , 64 
					, 64 , 64 , 64 , 64 , 64 , 64 , 64 , 64 , 64
					
					, 72 , 73 , 73 , 73 , 73 , 73 , 73 , 74 ,
					
					69 , 70 , 70 , 70 , 70 , 70 , 70 , 70 , 70 , 70 ,
					70 , 70 , 70 , 70 , 70 , 70 , 70 , 70 , 70 , 70 ,
					70 , 70 , 70 , 70 , 70 , 70 , 70 ,
					
					66 , 67 , 67 , 67 , 67 , 67 , 67 , 67 , 67 , 67 ,
					66 , 67 , 67 , 67 , 67 , 67 , 67 , 67 , 67 , 67 ,
					66 , 67 , 67 , 67 , 67 , 67 , 67 , 67 , 67 , 67 ,
					66 , 67 , 67 , 67 , 67 , 67 , 67 , 67 , 67 , 67 ,
					67 , 67 } ; 
 
float MARCA_CLASE , MAX , MIN , MODA;


 /*

printf("\n\tINGRESER LA CONTIRADAD DE FILAS \n\t  FILAS = ");
scanf("%d",&X);
system("cls");

printf("\n\tINGRESER LA CONTIRADAD DE COLUMNAS \n\t  COLUMNAS = ");
scanf("%d",&Y);
system("cls");

printf("\n\tINGRESER LA CONTIRADAD DE GRUPOS \n\t  GRUPOS = ");
scanf("%d",&G);
system("cls");
for( I = 0; I < X; I++)
        for( J = 0; J < Y; J++){
		printf("\n\tINGRESER DEL VARDOL EL FILA %d Y COLUMNAS %d \n\t VARDOL = ",I,J);
		scanf("%f",&MAR[I][J]);
		system("cls");
		}

 */


/* for (I = 0 ; I < X ; I++)
	for(J = 0 ; J < Y ;J++)
	
	MAR[I][J] =(float) (60+rand()%16 ) ;
 */
	
		for (I = 0 ; I < X ; I++)
			for(J = 0 ; J < Y ;J++)
				printf(" %4.2f |",MAR[I][J]);
	
		printf("\n\n\t");
		system("pause");
		system("cls");
	
MAX = 75	;
MIN = MAR[0][0] ;

	for (I = 0 ; I < X ; I++)
		for(J = 0 ; J < Y ;J++){
		
		if (MAR[I][J] < MIN)
			MIN = MAR[I][J] ;
		
		if (MAR[I][J] > MAX)
			MAX = MAR[I][J] ;
	
		}


MARCA_CLASE = (float) (MAX-MIN) / G;

struct AGRUPADA AGR[G];

AGR[0].VEC[0] = MIN;
AGR[0].VEC[1] = MIN + MARCA_CLASE;
AGR[0].fi = 0;
AGR[0].MARCA = MARCA_CLASE;

for (I = 1 ; I < G ; I++){
	
	AGR[I].VEC[0] = AGR[I-1].VEC[1];
	AGR[I].VEC[1] = AGR[I].VEC[0] + MARCA_CLASE;
	AGR[I].fi = 0;
	AGR[I].MARCA = AGR[I-1].MARCA + MARCA_CLASE;
	AGR[I].FI = 0;
	
}


for (Z = 0 ; Z < G ; Z++)
	for (I = 0 ; I < X ; I++)
		for(J = 0 ; J < Y ;J++)   
		
		if ( MAR[I][J] >= AGR[Z].VEC[0]  && MAR[I][J] < AGR[Z].VEC[1] )
		AGR[Z].fi++;
		
				
AGR[0].FI = AGR[0].fi;


for (Z = 1 ; Z < G+1 ; Z++)
	for (I = Z ; I >= 0 ; I--)
		AGR[Z].FI += AGR[I].fi ; 


MAX = AGR[0].fi ;
Z = 0;

for (I = 1 ; I < G ; I++)
	
	if (AGR[I].fi > MAX){

		MAX = AGR[I].fi;
		Z = I;

		}


if (Z == 0)
	MAX = 0;

else
	MAX = AGR[Z-1].fi;

if (Z == G)
	MIN = 0;

else
	MIN = AGR[Z+1].fi;

MODA = 0;
for (I = 0 ; I < G ; I++){
	printf("\n\t [ %-4.2f : %-4.2f ) \t %-4.2f\t%-4d %-4d",AGR[I].VEC[0] , AGR[I].VEC[1] , AGR[I].MARCA , AGR[I].fi , AGR[I].FI ) ;
	MODA += (float) AGR[I].fi * AGR[I].MARCA ;
}
	printf("\n\n\tMEDIA = %4.2f", MODA/(X*Y) );

	MODA = (float) AGR[Z].VEC[0] +( ( AGR[Z].fi - MAX ) / ( AGR[Z].fi - MAX  + AGR[Z].fi - MIN ) ) * MARCA_CLASE ;
	
	printf("\n\n\tMODA = %4.2f" , MODA) ;

	MODA = (float) AGR[Z].VEC[0] +  ( ( ( (  X*Y  /2 ) - MAX ) / AGR[Z].fi) * MARCA_CLASE)  ;
	
	printf ("\n\n\tMEDIANA = %4.2f" , MODA);
	
	
	
	
	
return 0;}


	



