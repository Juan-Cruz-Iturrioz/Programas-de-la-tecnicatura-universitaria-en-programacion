#include <stdio.h>
#include <conio.h>

#define N 3

int main(){
int DIV , NUM , C , R;
C=0;
printf("28");	
for ( NUM = 2  ; C < N ; NUM=NUM+2 ) {
R=1;
//R de resutaro es 1 por que todo numero/numero = 1
for ( DIV = 2 ; DIV <= (NUM/2) ; DIV++ ){
					if ( !(NUM%DIV) )
					{
					R = R + DIV;}
					
					if ( NUM==R )
					{ C= C+1;
					printf("%10d" , R);}}
		

}	return 0 ;}
