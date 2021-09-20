#include <stdio.h>

#define N 20

int main(){


int I,VEN[N];

for(I=0;I<N;I++){
	
	printf("in EN V :");
	scanf("%d",&VEN[I]);
	printf("\n");
	
	}

		for(I=0;I<N;I++){
	
		printf("%d V = %d \n",I+1,VEN[I]);
	
		}
		
		printf("\n");
		
		for(I=N-1;I>=0;I--){
	
		printf("%d V = %d \n",I+1,VEN[I]);
	
		}

return 0;}
