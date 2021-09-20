#include <stdio.h>
#include <conio.h>

int main(){
int  NUM , C,R,K,N ;
R=0;
K=0;

	for(C=1;C<=4;C++){
	
	printf("%d in:",C);
	scanf("%d",&NUM);
	
		if(R<NUM){
		R=NUM;
		K=C;
		}
		
		if(R<NUM){
		N=1;}
		else{
		N=0;
		}
	}				
			printf("in %d es el mayor %d:",K,R);
			if(N){
			printf("es creciente");
			}		


return 0 ;}
