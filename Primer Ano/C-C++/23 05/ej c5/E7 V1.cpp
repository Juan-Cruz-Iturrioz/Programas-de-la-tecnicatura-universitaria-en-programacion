#include <stdio.h>
#include <stdlib.h>

#define N_1 5

#define N_2 5

int MIS(int [], int [],int,int);

int main () {

int I,VEN1[N_1],VEN2[N_2];



for(I=0;I<N_1;I++)
	VEN1[I]=N_1+I;

for(I=0;I<N_2;I++)	
	VEN2[I]=N_2+I;




	if(MIS(VEN1,VEN2,N_1,N_2))
		
		printf("SON iguales");
		
		else
		printf("NO son iguales");

	
	

return 0;}
 
int MIS(int V1[],int V2[] ,int C1,int C2){

int K,L=0;

if(C1!=C2)
return 0;

	for(K=0;K<C1;K++){
	if(V1[K]==V2[K])
	L=L+1;
	
	else
	return 0;
	}
	
	
	if(L==C1)
	return 1;
	
	
}
