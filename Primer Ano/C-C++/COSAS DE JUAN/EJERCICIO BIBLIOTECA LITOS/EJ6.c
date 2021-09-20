#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct LIBRO {
       int CODIGO ;          	/*  ID DEL LIBRO  */
       char TITULO[30];
       char AUTOR[20];
       char TEMATICA[20];		/*  GENERO DEL LIBRO  */
       char STATUS ;			/*  0 = DISPONIBLE   1 = PRESTADO  */
       int LECTOR ;				/*  CODIGO DE ID DEL USUARIO  */
};


struct USUARIO {
               int LECTOR ;		/*  CODIGO DE ID DEL USUARIO  */
               char NOM[20];
               int TE ;       
};


struct MOVIMIENTO {
                  int LECTOR ;		/*  CODIGO DE ID DEL USUARIO  */
                  int CODIGO ;		/*  CODIGO DE ID DEL LIBRO  */
                  char OPERACION ;  /*  0 = DEVOLUCION    1 = PRESTAMO  */  
};

/*     ARCHIVO USUARIOS    :    BASE DE DATOS DE LOS CLIENTES            */
/*	   ARCHIVO BIBLIOTECA  :    BASE DE DATOS DE LOS LIBROS              */
/*     ARCHIVO MOVIMIENTOS :    REGISTRO DE LAS OPERACIONES REALIZADAS   */


/*   1.   MOSTRAR EN PANTALLA LOS 3 ARCHIVOS  */
/*   2.   INGRESAR EL NOMBRE DE UN CLIENTE E INDICAR QUE LIBROS   */
/*        TIENE EN ESTE MOMENTO                                   */\
/*   3.   MOSTRAR LOS DATOS DE LOS CLIENTES QUE TENGAN MAS DE 2 LIBROS  */
/*   4.   DETERMINAR CUAL ES EL LIBRO DE MAYOR USO (CANTIDAD DE PRESTAMOS) */
/*   5.   CUAL ES EL CLIENTE QUE MAS USA LA BIBLIOTECA  */
/*   6.   INDICAR SI EL GENERO "TERROR" ES MAS POPULAR QUE "NOVELA ROMANTICA" */
/*   7.   MOSTRAR EL HISTORICO DE OPERACIONES DE UN CLIENTE  */


int main(){
    
    
    FILE *FP_BIB , *FP_USU ,*FP_MOV ;
	
	
	int I , CON_TE = 0, CON_NRA = 0 , C_BIB;

	struct LIBRO LIB;
	struct USUARIO USU;
	struct MOVIMIENTO MOV;	

	if( !(FP_BIB = fopen("BIBLIOTECA","rb")  ) ){
		
		printf("\n\n   ERROR APERTURA DE ARCHIVO BIBLIOTECA \n\n");
	
		exit(1) ;
	
	
	}
	
	if( !(FP_USU = fopen("USUARIOS","rb")  ) ){
	
		printf("\n\n   ERROR APERTURA DE ARCHIVO USUARIOS \n\n");
	
		exit(1) ;
	
	}
	
	if( !(FP_MOV = fopen("MOVIMIENTOS","rb")  ) ){
	
		printf("\n\n   ERROR APERTURA DE ARCHIVO MOVIMIENTO \n\n");
	
		exit(1) ;
	
	}
		
		fseek(FP_BIB , 0l , SEEK_END);
		
		C_BIB = ftell(FP_BIB)/sizeof(LIB);
	    
	   
	
	    
	   
	    	for(I = 0 ; I < C_BIB; I++ ){
				
				fseek(FP_BIB, I*sizeof(LIB) , SEEK_SET);
				
				fread(&LIB , sizeof(LIB) , 1 , FP_BIB);	
				
			
				if(  !( strcmp ( LIB.TEMATICA , "TERROR") ) == 0 )
				CON_TE++;
				
				if(  !( strcmp( LIB.TEMATICA , "NOVELA ROMANTICA" ) ) == 0 )
				CON_NRA++;
				
				
				}
			
			if(CON_TE > CON_NRA )
			
			printf("\n\n\t EL TERROR GANA con : %d",CON_TE);
			
			else
			
			printf("\n\n\t EL NOVELA ROMANTICA GANA con : %d",CON_NRA);
			
	   
	   
	    	
		
		
		    
    printf("\n\n\n\n\t\t es es esto todo amigos FIN DEL PROGRAMA\n\n");
    
    fclose(FP_BIB);
    
	fclose(FP_USU);
    
	fclose(FP_MOV);
	
	getchar() ; 

return 0;}
