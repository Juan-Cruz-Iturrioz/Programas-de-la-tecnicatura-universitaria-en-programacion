#include <stdio.h>
#include <conio.h>

int main(){
	int N,C,A;
	A=0;
	
	for(C=0;C<3;){
	
	printf("in:");
	scanf("%d",&N);
	
	if(N==23645){
	A=1;
	
	}
	else{
	printf("erro \n\n");
	C=C+1;}
	
	if(C==3){
	printf("erro 404");}
	
	if(A){	
	printf("fin");
	C=3;	
	}
	
	
	}
	
	
	
	
return 0 ;}
