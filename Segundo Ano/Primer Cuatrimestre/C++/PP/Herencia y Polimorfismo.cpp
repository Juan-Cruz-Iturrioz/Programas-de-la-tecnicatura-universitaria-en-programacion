#include<iostream>

using namespace std ;

class Numeros{
	protected :
		int NUM1;
		int NUM2;
		int N;
	public :
		Numeros();
		virtual void VER();
};

class Sumar : public Numeros {
	public :
		Sumar();
		void VER();
};

class Resta : public Numeros {
	public :
		Resta();
		void VER();
};


Numeros :: Numeros() {
	cout << "Ingrese primer valor :\n";
    cin >> NUM1;	
	cout << "\nIngrese segunda valor :\n";
    cin >> NUM2;
    system("cls") ;
}

void Numeros :: VER (){
cout <<"N = " << N;
}

Sumar :: Sumar (){
	N = NUM1 + NUM2;
}

void Sumar :: VER (){
cout << "\n Sumar ";
Numeros::VER();
}

Resta :: Resta (){
	N = NUM1 - NUM2;
}

void Resta :: VER (){
cout << "\n Resta ";
Numeros::VER();
}

int main(){

	Sumar S;
	Resta R;
	S.VER();
	R.VER();
	
return 0;}
