/*  MATRICES  */
/*  COLOCA 8 "REINAS" CADA UNA EN SU COLUMNA   */


#include <stdio.h>


#define FILAS    8
#define COLUMNAS 8

int GENERAR ( int [][COLUMNAS] , int  , int );
void MIRAR   ( int [][COLUMNAS] , int  , int );
int SOLUCION  ( int [][COLUMNAS] , int  , int );

int main()
{

		int MAT[FILAS][COLUMNAS] ;
	

	
				GENERAR ( MAT , FILAS , COLUMNAS );
				  
				MIRAR   ( MAT , FILAS , COLUMNAS );
			
			printf("\n" );
		
			return 0 ;	
}  	
		
	
int GENERAR ( int M[][COLUMNAS] , int F , int C )
{
		int J0 , J1 , J2 , J3 , J4 , J5 , J6 , J7 , J ;				
		
		for ( J0 = 0 ; J0 < C ; J0++ ){
			// limpiador de 1
			for ( J = 0 ; J < C ; J++ ) 
			M[0][J]  =  0 ;
			
			M[0][J0]=1;
		
			for ( J1 = 0 ; J1 < C ; J1++ ){
			
			for ( J = 0 ; J < C ; J++ ) 
			M[1][J]  =  0 ; 
			
				if( J1 != J0 ){
				
				M[1][J1]=1;
				
					for ( J2 = 0 ; J2 < C ; J2++ ){
			
					for ( J = 0 ; J < C ; J++ ) 
						M[2][J]  =  0 ; 
			
						if( J2 != J0 && J2 != J1){
				
						M[2][J2]=1;	
					
							for ( J3 = 0 ; J3 < C ; J3++ ){
			
							for ( J = 0 ; J < C ; J++ ) 
							M[3][J]  =  0 ; 
			
							if( J3 != J0 && J3 != J1 && J3 != J2){
				
							M[3][J3]=1;	
		
								for ( J4 = 0 ; J4 < C ; J4++ ){
			
								for ( J = 0 ; J < C ; J++ ) 
								M[4][J]  =  0 ; 
			
								if( J4 != J0 && J4 != J1 && J4 != J2 && J4 != J3){
				
								M[4][J4]=1;
								
									for ( J5 = 0 ; J5 < C ; J5++ ){
			
									for ( J = 0 ; J < C ; J++ ) 
									M[5][J]  =  0 ; 
			
									if( J5 != J0 && J5 != J1 && J5 != J2 && J5 != J3 && J5 != J4){
				
									M[5][J5]=1;
									
									for ( J6 = 0 ; J6 < C ; J6++ ){
			
									for ( J = 0 ; J < C ; J++ ) 
									M[6][J]  =  0 ; 
			
									if( J6 != J0 && J6 != J1 && J6 != J2 && J6 != J3 && J6 != J4 && J6 != J5){
				
									M[6][J6]=1;
									
										for ( J7 = 0 ; J7 < C ; J7++ ){
			
										for ( J = 0 ; J < C ; J++ ) 
										M[7][J]  =  0 ; 
			
										if( J7 != J0 && J7 != J1 && J7 != J2 && J7 != J3 && J7 != J4 && J7 != J5 && J7 != J6){
				
										M[7][J7]=1;
										
										if(SOLUCION ( M , FILAS , COLUMNAS )){
										return 1;
										
										
										}
		
		
		}}}}}}}}}}}}}}}}
		
		
		
		
				
				
		
											

				
		
void MIRAR ( int M[][COLUMNAS] , int F , int C )
{
		int I , J ;					
		
	
		printf("\n");		
		for ( I = 0 ; I < F ; I++ ) {
				printf("\n\n\n\t      ");
				for ( J = 0 ; J < C ; J++ ) 
						printf("%5d" , M[I][J] );
		}
		printf("\n");

}



int SOLUCION  ( int M [][COLUMNAS] , int F , int C){

int I,J,K,N,R,RA;
	
	for(I=0;I<F;I++)
	
	for(J=0;J<C;J++)
		
		if(M[I][J]==1){
		
		R=I;
	
			for(K=I+1;K<F;K++)
		
			for(N=0;N<C;N++)
	
	
				if(M[K][N]==1){
			
				RA=K;
	
				if(R+J==RA+N)
				return 0;
	
	
				if(R-J==RA-N)
	
				return 0;
				}
	
	}


return 1;}

