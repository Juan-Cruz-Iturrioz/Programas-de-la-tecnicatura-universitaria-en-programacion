#include<stdio.h>
#include<stdlib.h>
#include <math.h>

void BINOMIAL ();
void BINOMIAL_NEGATIVA();
void GEOMETRICA();
void HIPERGEOMETRICA();

int NCR (int , int );

long long FACTORIAL(int );


int main(){

int SEL , V = 1;
	
	
while(SEL){
	
	if (V)
		printf("\n\tQUE TIPO DE DISTRIBUCIONES DISCRETAS ELIGE ");
	
	else{
		printf("\n\tPOR FAVOR UN ELIGE TIPO DE DISTRIBUCIONES DISCRETAS");
		V=1;
	}
	
	printf("\n\t\t 1 BINOMIAL \n\t\t 2 BINOMIAL NEGATIVA\n\t\t 3 GEOMETRICA \n\t\t 4 HIPERGEOMETRICA \n\t\t 5 CERRA DE PROGRAMA\n\n\t\t  OPCION = ");
	scanf("%d",&SEL);
	system("cls");
	
	switch (SEL) {

		case 1 : BINOMIAL (); ;
			break ;
		
		case 2 : BINOMIAL_NEGATIVA(); ;
		break ;		

		case 3 : GEOMETRICA(); ;
			break ;
		
		case 4 : HIPERGEOMETRICA(); ;
			break ;	

		case 5 : SEL = 0; ;
			break ;	

		default : V = 0 ; SEL = 1 ; ;
			break;
		
	}
	system("cls");
}
	
printf("\n\n\n\t\tFIN DEL PROGRAMA\n\n\t" );

system("pause");

return 0;}

void BINOMIAL (){
int M ,K ;
float P ;

	printf("\n\tINGRESE LA CANTIDAD DE PRUEBAS A REALIZAR\n\t\t M = ");
		scanf("%d",&M);
		
	
	printf("\n\tINGRESE LA PROBABILIDAD QUE DE CADA PRUEBA \n\t\t P = ");
	
	scanf("%f",&P);
	
	
	
		printf("\n\tINGRESE CUATOS EXITOS EL LAS PRUEDAS %d \n\t\t K = " , M);
		scanf("%d",&K);
		
	
		printf("\n\t P( X = %d ) = %G ",K,( NCR(M,K) * pow(P,K) * pow(1-P,M-K) ) );
	
	
	printf("\n\n\t E( X ) = %G ", M*P );
	
	printf("\n\t V( X ) = %G ", M*P*(1-P) );
	
	system("pause");

}
void BINOMIAL_NEGATIVA(){

int M ,K  ;
float P;

	printf("\n\tINGRESE LA CANTIDAD DE EXITOS \n\t\t K = ");
	scanf("%d",&K);
	
	
	printf("\n\tINGRESER LA PROBABILIDAD DE LOS EXIPOS\n\t\t P = ");
	scanf("%f",&P);
	

	printf("\n\tINGRESE CUATAS DE PRUEDAS DESDA LA PROBALIDAD \n\t\t M = ");
	scanf("%d",&M);
	
	
	printf("\n\t P( X = %d ) = %G ",M , ( NCR(M-1,K-1) * pow(P,K) * pow(1-P,M-K) ) );
	
	system("pause");

}
void GEOMETRICA(){

int M ;
float P;

	printf("\n\tINGRESER LA PROBABILIDAD DE UN EXITO\n\t\t P = ");
	scanf("%f",&P);
	

		printf("\n\tINGRESER DE CUATAS PRUEDAS DESDA LA PROBABILIDAD \n\t\t M = ");
		scanf("%d",&M);
		
	
		printf("\n\t P( X = %d ) = %G ",M, P*pow(1-P,M-1) );
		
		system("pause");

}
void HIPERGEOMETRICA(){

int N ,M ,K , Y ;
	
	printf("\n\tINGRESE LA CATIDAD DE ELEMENTOS TOTAL \n\t\tM =  ");
	scanf("%d",&M);
	
	printf("\n\tINGRESE CUANTOS ELEMENTOS TENDRA EL CUNJUTO \n\t\tN =  ");
	scanf("%d",&N);
	
		
	printf("\n\tINGRESE CUANTOS EXTITO DESDA \n\t\tK =  ");
	scanf("%d",&K);
	
	
	printf("\n\tINGRESE CUANTOS EXITOS HAY EL TOTAL \n\t\tY =  ");
	scanf("%d",&Y);

	
	printf("\n\tP ( X = %d ) = %f" , Y , ( NCR(K,Y)*NCR(N-K,M-Y)) / NCR (N,M) ) ;
	
	system("pause");

}


long long FACTORIAL(int N)
{
 	  
	if(N == 0 || N == 1 )
    return 1;
    
    if (N > 0) 
	return N*FACTORIAL(N-1);

}


int NCR (int M , int N){

	return  FACTORIAL(M) / ( FACTORIAL(N)*FACTORIAL(M-N) ) ;
	
}
