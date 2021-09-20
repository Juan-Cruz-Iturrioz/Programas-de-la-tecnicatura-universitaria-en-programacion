#include <stdio.h>
#include <stdlib.h>

#define Nu 18

void BUS(int [],int,char []);

void ord(int [],char[],int);

int main(){

srand(0562);

int Cu[Nu],I,B;
char Ti[Nu],Bu='A';

for(I=0;I<Nu;I++){

Ti[I]='A'+(rand()%3); 
// solo funciona porque A=65 , B=66 , C=67 
Cu[I]= 500+rand()%301;
}

ord(Cu,Ti,Nu);

	BUS(Cu,Nu,Ti);
	
	
	
return 0;}

void ord(int C[],char T[],int N){
	
int I,J,AUX_C;
char AUX_T;

	for(I=0;I<N-1;I++)
	
		for(J=0;J<N-I-1;J++)
			
			if(C[J]>C[J+1]){
			
			AUX_C = C[J];
			C[J] = C[J+1];
			C[J+1] = C[J];
			
			AUX_T = T[J];
			T[J] = T[J+1];
			T[J+1] = AUX_T;
			
			
			}
			
		
}

void BUS(int C[],int N, char T []){
int I;
	
	for(I=0;I<N;I++)
	
	if(C[I]>500)
	
	printf("cuenta %d \t tipo %c \n" ,C[I],T[I]);
	
	
	

	
	
}







