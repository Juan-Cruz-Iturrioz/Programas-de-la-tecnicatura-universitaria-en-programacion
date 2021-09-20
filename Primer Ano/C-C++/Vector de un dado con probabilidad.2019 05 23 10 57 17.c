#include<stdio.h> // EJ 5 PAG 149
#define n 6

void ceros(int[]);
void mostrar(int[]);
int aleatorio();

int main(){
	int pos[6], i, x;
	ceros(pos);
	
	for(i=0;i<1000;i++){
		x=aleatorio();
		pos[x]++;
	}
	
	for(i=0;i<6;i++)
		printf("El valor %d salio %d veces\n\n",i+1,pos[i]);
	
	return 0;
}


int aleatorio(){
	int x;
	srand(4324);
	x=rand()%6;	
	return x;	
}

in
