#include <stdio.h>

#include <math.h>


int DIS (int , int , int , int);



int main(){

float D1,D2;

int I;

int X[3];
int Y[3];	

	for(I=0;I<3;I++,printf("\n") ){
	
	printf("in X %d :",I+1);
	
	scanf("%d",&X[I]);
	
	printf("in Y %d :",I+1);
	
	scanf("%d",Y[I]);
	
	
	}
	
	
		D1=DIS(X[1],X[2],Y[1],Y[2]);

		D2=DIS(X[2],X[3],Y[2],Y[3]);
		
		printf("la distancia es %d", D1+D2);



return 0;}



int DIS(int X1, int X2 , int Y1, int Y2){

int R1,R2,RT;
float V;
	R1=X1-X2;
	
	R2=Y1-Y2;
	
	RT=(R1*R1)+(R2*R2);
	
	V=sqrt(RT);
	
	return V;
}
