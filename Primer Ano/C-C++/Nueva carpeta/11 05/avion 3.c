
#include <stdio.h>

#include <math.h>


float DIS (int , int , int , int);



int main(){

float DT;

int X1,Y1,X2,Y2,V=0;

while (X2>=0&&Y2>=0) {
	
	printf("in X %d : ",V+1);
	scanf("%d",&X2);
	
	printf("\n");
	
	printf("in Y %d : ",V+1);
	scanf("%d",&Y2);
	
	printf("\n");
	
	
	
	if(V){
	if(X2>=0&&Y2>=0){
	DT=DT+DIS(X1,Y1,X2,Y2);
	X1=X2;
	Y1=Y2;

	}
	
	}
	
	else{
	X1=X2;
	Y1=Y2;
	}
	V++;
	
	}
	
	printf("la distancia es %2.2f", DT);



return 0;}



float DIS(int X1, int Y1 , int X2, int Y2){

float RT;

	RT=(X2-X1)*(X2-X1)+(Y2-Y1)*(Y2-Y1);
	
	RT=sqrt(RT);
	
	return RT;
}
