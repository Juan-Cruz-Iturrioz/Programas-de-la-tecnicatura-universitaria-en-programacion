/*   NUEVOS FLUJOS DE ENTRADA Y SALIDA   */

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std ; 

int main( )
{  
		short int A ;
		cout << "\n\n   ENTERO CORTO        :    ";
		cin >> A ;
		
		int L ;
		cout << "\n\n   ENTERO LARGO        :    ";
		cin >> L ;
		
		char C ;
		cout << "\n\n   CARACTER            :    ";
		cin >> C ;
		
		float F ;
		cout << "\n\n   FLOTANTE            :    ";
		cin >> F ;
				
		char VEC[20] ;
		cout << "\n\n   FRASE               :    ";
		cin >> VEC ;
		
		
		cout << "\n\n\n\n\n   VALORES INGRESADOS\n\n";
		cout << "\n\n   ENTERO CORTO        :    " << A ;
		cout << "\n\n   ENTERO LARGO        :    " << L ;
		cout << "\n\n   CARACTER            :    " << C ;
		cout << "\n\n   FLOTANTE            :    " << F ;
		cout << "\n\n   FRASE INGRESADA     :    " << VEC ;
		getchar();
		
		cout << "\n\n\n\n\n   VALORES INGRESADOS EN OCTAL\n\n" << oct ;
		cout << "\n\n   ENTERO CORTO        :    " << A ;
		cout << "\n\n   ENTERO LARGO        :    " << L ;
		cout << "\n\n   CARACTER            :    " << C ;
		cout << "\n\n   FLOTANTE            :    " << F ;
		cout << "\n\n   FRASE INGRESADA     :    " << VEC ;
		getchar();
			
		cout << "\n\n\n\n\n   VALORES INGRESADOS EN HEXADECIMAL\n\n" << hex;
		cout << "\n\n   ENTERO CORTO        :    " << A ;
		cout << "\n\n   ENTERO LARGO        :    " << L ;
		cout << "\n\n   CARACTER            :    " << C ;
		cout << "\n\n   FLOTANTE            :    " << F ;
		cout << "\n\n   FRASE INGRESADA     :    " << VEC ;
		getchar();
		
		cout << "\n\n\n\n\n   VALORES INGRESADOS EN DECIMAL\n\n" << dec ;
		cout << "\n\n   ENTERO CORTO        :    " << A ;
		cout << "\n\n   ENTERO LARGO        :    " << L ;
		cout << "\n\n   CARACTER            :    " << C ;
		cout << "\n\n   FLOTANTE            :    " << F ;
		cout << "\n\n   FRASE INGRESADA     :    " << VEC ;		
				
		printf("\n\n");
		return 0 ;
}



