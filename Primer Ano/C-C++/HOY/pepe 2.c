#include <stdio.h>
#include <conio.h>

#define N 4

int main(){
int DIV1,DIV2 , NUM1,NUM2,  C , R1,R2;
C=0;

					for(NUM1=2; C<N ;NUM1=NUM1+1){
					R1 = 1;
					
					for ( DIV1 = 1 ; DIV1 <= (NUM1/2) ; DIV1++ )
					
					if(NUM1%DIV1==0){
					R1 = R1 + DIV1;	}
					NUM2 = R1; 
					
					for (DIV2 = 2 ; DIV2 <= (NUM2/2) ; DIV2++ ){
					if(NUM2%DIV2==0)
					R2 = R2 + DIV2;	}
					
					if ( NUM1==R2 )
					{ C= C+1;
					printf("%8d;" , NUM1);
					printf("%-8d;" , NUM2);}	}
		

	return 0 ;}
