#include <stdio.h>

#include <math.h>


float DIS (int , int , int , int);



int main(){
int V;
float D1,D2;

int I;

int X[6];


	for(I=0,V=1;I<6;I++,printf("\n") ){
	
	if(I==0||I==2||I==4){
	printf("in X%d :",V);
	scanf("%d",&X[I]);
		}
	
	if(I==1||I==3||I==5){
	printf("in Y%d :",V);
	scanf("%d",&X[I]);
	V++;
	}
	
	
	}
	
	
		D1=DIS(X[0],X[1],X[2],X[3]);

		D2=DIS(X[2],X[3],X[4],X[5]);
		
		printf("la distancia es %2.2f", D1+D2);



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
