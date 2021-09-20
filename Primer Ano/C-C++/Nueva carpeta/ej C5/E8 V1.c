#include <stdio.h>
#include <stdlib.h>

#define Nu 8

int BUS(char [],int,int);

void ord(int [],char[],int);

int main(){

srand(0562);

int Cu[Nu],I,B,Bu;
char Ti[Nu];

for(I=0;I<Nu;I++){

Ti[I]='A'+(rand()%3); 
// solo funciona porque A=65 , B=66 , C=67 
Cu[I]= 10+rand()%91;
}

org(Cu,Ti,Nu);

printf("es bu :");
scant("%d",Bu);


	B=BUS(Ti,Bu,Nu);
	if(B!=-1)
	printf("\n la cuena es %d ",B);
	else
	printd("\n no esta");
	
	
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

int BUS(char T[],int B,int N){
int I;
	
	for(I=0;I<N;I++)
	if(T[I]==B)
	return I;
	
	
	
return -1;}







