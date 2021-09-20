#include <stdio.h>
#include <conio.h>




int main(){
int  NUM , C,R,K ;

printf("in:");
scanf("%d",&NUM);
if(NUM<1000){
C=(NUM/100)*100;
R=((NUM-C)/10)*10;
K=((NUM-C)-R)/1;
printf("%d %d %d",C,R,K);
}
	
	
	
	


			
return 0 ;}
