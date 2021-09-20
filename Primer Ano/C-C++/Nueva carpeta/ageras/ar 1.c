#include <stdio.h>

#define FI 8
#define CO 8

void MI(int[][CO],int);
int main(){

int MAT[FI][CO]={2};
int I,J;
		
	for(I=0;I<FI;I++)
		for(J=0;J<CO;J++)
			MAT[I][J]=1;

MI( MAT[][CO], FI);

return 0;}

void MI(int M [][CO],int F){
int I,J;

	for(I=0;I<F;I++,printf("\n"))
		for(J=0;J<CO;J++)
		printf("\t%6d",M[I][J]);

}

