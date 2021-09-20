
#include <stdio.h>

#include <math.h>


float DIS (int , int , int , int);



int main(){

float D1,DT;

int X1,Y1,X2,Y2,I,V=1;


	while (X1>=0&&Y1>=0&&X2>=0&&Y2>=0  ) {
	
	printf("in X %d :",V);
	scanf("%d",&X1);
	
	printf("\n");
	
	printf("in Y %d :",V);
	scanf("%d",&Y1);
	
	V++;
	
	printf("\n");
	
	printf("in X%d :",V);
	scanf("%d",&X2);
	
	printf("\n");
	
	printf("in Y%d :",V);
	scanf("%d",&Y2);
	
	printf("\n");
	D1=DIS(X1,Y1,X2,Y2);
	
	DT=DT+D1;
	
	}
	
	printf("la distancia es %2.2f", D1);



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
