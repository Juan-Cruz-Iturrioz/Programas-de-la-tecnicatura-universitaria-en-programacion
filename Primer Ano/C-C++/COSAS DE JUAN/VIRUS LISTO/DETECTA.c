/*   DETECTOR DE SECUENCIA  */
/*   DETECTAR EN QUE ARCHIVO DE LOS ARCHn DE LA CARPETA */
/*   SE ENCUENTRA LA SECUENCIA HEXADECIMAL              */ 
/*   FA   C2   45   00   00   15   6A   78   3F   FE    */




#include <stdio.h>
#include <stdlib.h>



int main( )
{  

FILE * FP ;


char NOM [5] = {"ARCH1"};
int I, N , J=0;

//unsigned short int A , VEC[] = { 0xFAC2 , 0x4500 , 0x0015 , 0x6A78 ,0x3FFE}  ;

char A , VEC[] = {0xFA , 0xC2 , 0x45 , 0x00 , 0x00 , 0x15 , 0x6A , 0x78 ,0x3F, 0xFE};

for (I = 0 ; I < 6 ; I++ )  {

	if(!( FP =fopen( NOM ,"rb") ) ) {
	
	printf("\n\n\tERROE %s ", NOM);
	exit (1);
	} 		
	
		
	
		fread(&A , sizeof(A) , 1 , FP );
		
		while (! feof (FP) ){
			
			
			if ( A == VEC[J] ){
			
			
			if(J == 9){
			
			N = ftell(FP)/sizeof(A);
			
			printf("\n\n\t ESTA EN %s A ORIGEN %d" ,NOM , N-9);
			
			}
		    
			J++;
			
			}
			
			else 
			J = 0;
			
		fread(&A , sizeof(A) , 1 , FP );
		
}

NOM[4]++;		


}	
	fclose(FP);				
	printf("\n\n");	
		
		return 0 ;
}
		
		

