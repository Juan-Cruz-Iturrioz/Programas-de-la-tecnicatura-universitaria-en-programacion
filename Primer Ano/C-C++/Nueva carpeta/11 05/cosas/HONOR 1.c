#include <stdio.h>

#define PUL 2.54

#define PI 3.14

int main(){

float Dp,Dcm,Scm,SC,E,Epor,Rcm,Emin,Dp_Emin,Scm_Emin;

Emin = 1000000;
printf("\n seccion de canio [cm] =");
scanf("%f",&SC);

for(Dp=10;Dp<=30;Dp=Dp+0.5){
	
	Dcm=Dp*PUL;
	
	Rcm=Dcm/2;
	Scm=PI*Rcm*Rcm;
	E = SC - Scm;
	//if(E<0) E = -E;
	E = E < 0 ? -E : E;
	
	if( E < Emin ) {
	
	
		Emin=E;
		Epor = Dp;
		Scm_Emin=Scm;
		
		}
	
	
	
	printf("\n %8.2F %8.2f %8.2f %8.2f %8.2f  %8.2f  %8.2f ", Dp , Dcm , Scm , SC, E,Emin,0.1 );
	
	
	
}

Epor=(SC-Scm_Emin)/SC*100;

printf("\n\n SECCION solicitada = %.2f",SC );

printf("\n\n DIAMETRO SELECCIONADO = %.2f",Dp_Emin);

printf("\n\n SECCION DEL CANIO = %.2f",Scm_Emin );

printf("\n\n ERRO PORCENTUAL = %.2f", Epor);

for(Dp=1;Dp<=10;Dp=Dp+0.25){
	
	Dcm=Dp*PUL;
	
	Rcm=Dcm/2;
	Scm=PI*Rcm*Rcm;
	E = SC - Scm;
	//if(E<0) E = -E;
	E = E < 0 ? E : -E;
	
	if( E < Emin ) {
	
	
		Emin=E;
		Epor = Dp;
		Scm_Emin=Scm;
		
		}
	
	
	
	printf("\n %8.2F %8.2f %8.2f %8.2f %8.2f  %8.2f  %8.2f ", Dp , Dcm , Scm , SC, E,Emin,0.1 );
	
	
	
}

Epor=(SC-Scm_Emin)/SC*100;

printf("\n\n SECCION solicitada = %.2f",SC );

printf("\n\n DIAMETRO SELECCIONADO = %.2f",Dp_Emin);

printf("\n\n SECCION DEL CANIO = %.2f",Scm_Emin );

printf(" ERRO PORCENTUAL = %.2f", Epor);






return 0;}
