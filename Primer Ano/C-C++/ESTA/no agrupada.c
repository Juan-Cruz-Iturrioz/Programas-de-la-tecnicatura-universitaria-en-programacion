
#include<stdio.h>
#include<stdlib.h>

		struct NO_AGRUPADA {
		int ix ;
		int fi;
		int FI;
		float fri;
		float FRI;
		};
		
	
int main (){

srand(1969);

int X = 5;
int Y = 10;
int AUX , I , J , K , Z;
int CAN = 0 , MAX = 0 , MODA = 0 ;
float MEDIANA ;
/*
printf("\n\tINGRESER LA CONTIRADAD DE FILAS \n\t  FILAS = ");
scanf("%d",&X);
system("cls");

printf("\n\tINGRESER LA CONTIRADAD DE COLUMNAS \n\t  COLUMNAS = ");
scanf("%d",&Y);
system("cls");
*/

int MAR[X][Y];
/*
for( I = 0; I < X; I++)
        for( J = 0; J < Y; J++){
		printf("\n\tINGRESER DEL VARDOL EL FILA %d Y COLUMNAS %d \n\t VARDOL = ",I,J);
		scanf("%d",&MAR[I][J]);
		system("cls");
		}
*/

// /*

for (I = 0 ; I < X ; I++)
	for(J = 0 ; J < Y ;J++)
	
	MAR[I][J] = (1+rand()%100 ) ;

// */

printf("\n\n\t");

	for( I = 0; I < X; I++ , printf("\n\t") )
    	    for( J = 0; J < Y; J++)
				printf(" %d |",MAR[I][J]);

	printf("\n\n\t");
	
	system("pause");
	
	system("cls");


	for( I=0; I<X; I++)
    	    for( J=0; J<Y; J++)
        	    for( K=0; K<X; K++)
            	    for( Z=0; Z<Y; Z++)
                	    if(MAR[I][J]<MAR[K][Z])
                    	{
                        	AUX=MAR[I][J];
                        	MAR[I][J]=MAR[K][Z];
                        	MAR[K][Z]=AUX;
                    	}
 
	for( I = 0 ; I < X; I++)
		for( J = 0 ; J < Y ; J++)
			if (MAR[I][J] != MAR[I][J+1])
			CAN++;
					

struct NO_AGRUPADA DAT[CAN];   

K = 0;     

	for( I = 0; I < X ; I++)
        for( J = 0; J < Y; J++)
		
			if (MAR[I][J] != MAR[I][J+1]){
			DAT[K].ix = MAR[I][J];
			K++;
			}
				
for( Z = 0 ; Z < CAN ; Z++){
	
	DAT[Z].fi = 0;
	DAT[Z].FI = 0;
	DAT[Z].FRI = 0;		
		
		for( I = 0 ; I < X ; I++ )
    	    for( J = 0 ; J < Y ; J++ )
		
		if( DAT[Z].ix == MAR[I][J] )
		DAT[Z].fi++;
		
		
	DAT[Z].fri =(float) (DAT[Z].fi) / (X*Y);	
	}
	
	DAT[0].FI = DAT[0].fi;
	DAT[0].FRI = DAT[0].fri;

	for(I = 1 ; I < CAN ; I++)
		for( J = I ; J >= 0  ; J--){
		
		DAT[I].FI +=  DAT[J].fi ;
		DAT[I].FRI += DAT[J].fri;
		
		}
			
	
	
	printf("\n\n\t %-10s %-10s %-10s %-10s %-10s \n", "ix" , "fi" , "FI" , "fri" , "FRI");

	for(I = 0 ; I < CAN ; I++){

	printf("\n\t %-10d %-10d %-10d %-10.2f %-10.2f \n" , DAT[I].ix , DAT[I].fi , DAT[I].FI , DAT[I].fri , DAT[I].FRI );

		if (DAT[I].fi > MAX){
		MODA = I;
		MAX = DAT[I].fi;
		}
			
	}

	printf("\n\n\t\t la Moda es\n\n\t %-10d %-10d %-10d %-10.2f %-10.2f" , DAT[MODA].ix , DAT[MODA].fi , DAT[MODA].FI , DAT[MODA].fri , DAT[MODA].FRI);
	
	if( (X*Y)%2 ) {
	MEDIANA = ((X*Y)+1 ) / 2;
	AUX = MEDIANA ;
	}
	else{
	MEDIANA = ((X*Y)+1 ) / 2;
	AUX = (X*Y) / 2 ;
	}
	
	for( I = 0 ; I < CAN ; I++) {
	if(MEDIANA > DAT[I].FI || AUX > DAT[I].FI)
	K = I ;
	}
	
	printf("\n\n\t\t la MEDIANA es\n\n\t %-10d %-10d %-10d %-10.2f %-10.2f" , DAT[K].ix , DAT[K].fi , DAT[K].FI , DAT[K].fri , DAT[K].FRI);
	
	printf("\n\n\n\t\tFIN DEL PROGRAMA\n\n\t" );

	system("pause");

return 0;
}


	



