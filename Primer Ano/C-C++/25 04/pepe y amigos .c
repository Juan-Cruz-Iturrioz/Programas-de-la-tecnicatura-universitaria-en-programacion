#include <stdio.h>
#include <conio.h>

#define N 10

int main(){
int DIV1,DIV2,NUM1,C,C2,R1,R2;
C=2;
C2=0;					
		for( NUM1=220;C2<N; NUM1=NUM1+2	){
		   R1=1;
		   
 				for(DIV1=2;DIV1<=(NUM1/2);DIV1=DIV1+1){
				
				if(!(NUM1%DIV1)){
					R1=R1+DIV1;}
				}	
					
					R2=1; 		
					for(DIV2=2;DIV2<=(R1/2);DIV2=DIV2+1
					){
					
					if(!(R1%DIV2)){
					R2=R2+DIV2;}				
				
					}
																	
					if(NUM1==R2&&C==0){
					C=1;
					}
						
					if(NUM1==R1){
					C=1;
					}
																				       		
					if(NUM1==R2&&C==2){
					printf("%d:%-d\n",R1,NUM1);
					C=0;
					C2=C2+1;
					}
					
					if(NUM1==R2&&C==1){
					C=2;
					}
					
					
						
						}
				
								
					
							
					
		

	return 0 ;}
