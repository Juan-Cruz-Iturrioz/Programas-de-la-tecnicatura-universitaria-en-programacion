#include <stdio.h>
#include <string.h>


#define N 10

int main(){

int I,C,K=0;
char ST1[N];
	
	gets(ST1);

	C=strlen(ST1);
	
		for(I=1;I<=C/2;I++){
		if(ST1[I]==ST1[C-(I+1)])
		K=K+1;
		}
	
		
	
	printf("la palabra %s",ST1);
		
	if(K==C/2)
	printf(" es un palindromo");
	else
	printf(" no es un palindromo");
	
	



return 0;}
