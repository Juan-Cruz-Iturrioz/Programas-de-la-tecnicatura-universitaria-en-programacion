#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define N 10000

int main(){
int  NUM , C , CARA,SECA;

srand(time(0));
 for( NUM = 1, CARA=0, SECA=0  ; NUM <= N ;NUM++  ) {
	C=(rand()%2)+1;

		if(C==2){
		CARA=CARA+1;	
		}
		if(C==1){
		SECA=SECA+1;	
		}
		
}
			printf("Cara son %d\n",CARA);
			printf("Seca son %d\n",SECA);
return 0 ;}
