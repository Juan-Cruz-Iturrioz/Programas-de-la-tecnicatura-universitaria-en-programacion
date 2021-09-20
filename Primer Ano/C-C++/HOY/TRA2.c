#include <stdio.h>
#include <conio.h>

#define N 4

int main(){
int DIV , NUM , C , R;
C=0;

for ( NUM = 2  ; C < N ; NUM=NUM+2 ) {


for ( DIV = 2,R=1 ; DIV <= (NUM/2) ; DIV++ ){

					if ( !(NUM%DIV) )
					{
					R = R + DIV;}
					}
					
					if ( NUM==R )
					{ C= C+1;
					printf("%d " , R);}
		

}	return 0 ;}
