#include <stdio.h>
#include <conio.h>

int main(){
	int N,C,SP,SN,DIV,R;
	
	SP=0;
	SN=0;
	for(C=1;C<=4;C=C+1){
	
	printf("in: ");
	scanf("%d",&N);
	
	for(DIV=2 ;DIV<=(N/2);DIV=DIV+1){
	
	if(!(N%DIV)){
	R=0;
	}
	
	else{
	R=1;
	}
	
	}
	if(R){
	SP=SP+N;
	}
	else{
	SN=SN+N;
	}
	}
	
	if(SP<SN){
	printf("el mayor es pare" );
	
	}

	else{
	printf("el mayor es inpare");
	}
	
return 0 ;}
