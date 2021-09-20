#include <stdio.h>

#include<math.h>



float coor (float , float);

int main(){

int J1P=0,J2P=0,J1X,J1Y,J2X,J2Y,I;

float J1XY,J2XY;

	/*for(I=1;I<=2;I++){
	
	printf("J1 RONDO %d INGRESO X :",I);
	scanf("%d",&J1X);
	
	printf("\n\n");
	
	printf("J1 RONDO %d INGRESO Y :",I);
	scanf("%d",&J1Y);
	
	printf("\n\n");
	


	
	printf("J2 RONDO %d INGRESO X : ",I);
	scanf("%d",&J2X);
	
	printf("\n\n");
	
	printf("J2 RONDO %d INGRESO Y : ",I);
	scanf("%d",&J2Y);
	
	printf("\n\n");
	
	
	
		J1XY=coor(J1X,J1Y);
	
		J2XY=coor(J2X,J2Y);*/
	
	J1XY=1;
	J2XY=2;
		if(J1XY==J2XY){
		J1P=J1P+5;
		J2P=J2P+5;
		}
		
		if(J1XY<J2XY)
		J1P=J1P+10;
		
		if(J2XY<J1XY)
		J2P=J2P+10;
		
	//}
	
	
	if(J1P==J2P)
		printf("\n\n empate ");
		
		
		if(J1P<J2P)
		printf("\n\n ganador J1 con %d %d",J1P);
		
		if(J2P<J1P)
		printf("\n\n ganador J2 con %d",J2P);





return 0;}





float cuad (int NUM){

float R;

R=NUM*NUM;

return R;


}

float coor (float X , float Y){

float V,R;

V=0-X*X+0-Y*Y;
R=sqrt(V);

return R;}







