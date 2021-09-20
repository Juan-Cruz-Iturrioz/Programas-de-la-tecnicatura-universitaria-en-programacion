#include <stdio.h>
#include <conio.h>

int main(){
	int N,C;
	N=0;
	
	for(C=0;C<1;){
	
	printf("ingresal: ");
	scanf("%d",&N);
	
	if(N>0){
	if(!(N%2)){
	
	printf("es pare\n");}
	
	else{
	printf("es inpare\n ");
	}
	
	}
	else{
	printf("erro 404");
	C=1;
	}
	}
return 0 ;}
