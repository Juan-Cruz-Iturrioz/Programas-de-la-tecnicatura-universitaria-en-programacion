#include <stdio.h>
#include <string.h>


#define N 10

int main(){

int I,C,K=0,T;
char ST1[N];
	
	gets(ST1);

	
	C=strlen(ST1);
	T=C/2;
	
		for(I=1;I<=T;I++){
		if(ST1[I-1]==ST1[C-I])
		K=K+1;
		}
	
		
	
	printf("la palabra %s",ST1);
		
	if(K==T)
	printf(" es un palindromo");
	else
	printf(" no es un palindromo");
	
	



return 0;}
