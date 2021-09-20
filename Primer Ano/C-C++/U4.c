#include <stdio.h>

#define CI 4
#define CJ 3

//C de catidad 

int main() {
	
	int I,J,D;
	
	//D de default

		for(I=1;I<=CI;I++,printf("|\n")){
		
		printf("\n\t");
		
				for(J=1,D=1;J<=CJ;J++){
				
					if(J>=2){
					printf("| %d ",I+1);
					D=0;
					}
				
					if(I==2&&J==1){
					printf("| %d ",I+J);
					D=0;
					}
				
					if(D)
					printf("| 5 ");
			
			
				}
		
		}
		
	
	
	
	
		
return 0 ;	}
