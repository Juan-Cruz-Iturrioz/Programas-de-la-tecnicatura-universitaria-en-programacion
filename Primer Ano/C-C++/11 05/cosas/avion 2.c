#include <stdio.h>

#include <math.h>


float DIS (int , int , int , int);



int main(){
int V=0,I,X1,Y1,X2,Y2,F=0-1;

float D,DT;

	for(I=1;V==1;I++,printf("\n") ){
	
	
	printf("in CO %d X :",I);
	scanf("%d",&X1);
		
		 printf("\n");
		
	printf("in CO %d  Y :",I);
	scanf("%d",&Y1);
	
		 printf("\n");
	
	I++;
	
	printf("in CO %d  X :",I);
	scanf("%d",&X2);
		
		 printf("\n");
		
	printf("in CO %d  Y :",I);
	scanf("%d",&Y2);
	
		 printf("\n");
		 
		 
	
	//if(X1!=F||Y1!=F||X2!=F||Y2!=F){
	
	
	D=DIS(X1,Y1,X2,Y2);
	
	DT=DT+D;
	
	/*}
	
	else V=1;*/
	
	
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
