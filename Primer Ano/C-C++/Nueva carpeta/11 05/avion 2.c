
#include <stdio.h>

#include <math.h>


float DIS (int , int , int , int);



int main(){

float DT=0;

int X1,Y1,X2,Y2,I=0,V=1;

	while (X2>=0&&Y2>=0) {
	
	printf("in X %d :",V);
	scanf("%d",&X1);
	
	printf("\n");
	
	printf("in Y %d :",V);
	scanf("%d",&Y1);
	
	printf("\n");
	
	V++;
	
	if(I){
	
	DT=DT+DIS(X1,Y1,X2,Y2);
	
	X2=X1;
	Y2=Y1;
	}
	
	else{
	X2=X1;
	Y2=Y1;
	I=1;
	}
	
	}
	
	printf("la distancia es %2.2f", DT);



return 0;}



float DIS(int X1, int Y1 , int X2, int Y2){

int R1,R2,RT;
float V;
	R1=X1-X2;
	
	R2=Y1-Y2;
	
	RT=R1*R1+R2*R2;
	
	V=sqrt(RT);
	
	return V;
}
