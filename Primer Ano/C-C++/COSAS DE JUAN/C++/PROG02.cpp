
#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#define N 6
using namespace std;

class PILA {
private:
    int VEC[N];
    int *SP;

public : 
	PILA ();
	void PUSH ( int );
	int PULL ();
	~PILA ();
};

PILA::PILA(){

SP = VEC;

}

PILA :: ~PILA (){

cout << "\n\nFIN\n" ;

}

void PILA::PUSH ( int X ) {

	if( SP == VEC+N){
	
	cout << "\n\n PILE LLENA\n" ;
	getchar();
	return ;
	
	}

	*SP = X;
	SP++;

} 

int PILA::PULL (){

	if ( SP == VEC){
	
	cout << "\n\n PILA VACIA\n";
	getchar();
	return 0;
	}

return *--SP;
}


int main()
{

PILA P;

int VALOR ;
int I ;
	for (  I = 0 ; I < N ; I++){
	
	cout << "\n\n\n VALOR : ";
	cin >> VALOR;
	P.PUSH(VALOR);
	
	}
	
	cout << "\n\n\n CONTENIDO DE LA PILA \n\n" ;
	for ( I = 0 ; I < N ; I++)
		cout << "\n\n\t\t " << P.PULL();
		
		
		printf("\n\n");
return 0;
}


